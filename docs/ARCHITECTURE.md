# 架构与重建方法

## 1. 镜像布局

`firmware/eFlashBK.bin` 是 8051 代码空间快照，共 128 KiB。8051 只有 64 KiB 代码空间，所以文件按四个 32 KiB 区域存放：低 32 KiB 固定映射，高 32 KiB 是三个 bank 共用的窗口。

| 区域 | 文件偏移 | 逻辑地址 | 名称 | 源码 |
|---|---|---|---|---|
| region 0 | `0x00000-0x07FFF` | `0x0000-0x7FFF` | fixed | `src/boot/vectors.a51`、`src/fixed/region0.a51` |
| region 1 | `0x08000-0x0FFFF` | `0x8000-0xFFFF` | bank0 | `src/banks/bank0.a51` |
| region 2 | `0x10000-0x17FFF` | `0x8000-0xFFFF` | bank1 | `src/banks/bank1.a51` |
| region 3 | `0x18000-0x1FFFF` | `0x8000-0xFFFF` | bank2 | `src/banks/bank2.a51` |

- 向量表占 `0x0000-0x002A`，复位向量是 `LJMP 0x0070`。各中断向量跳到 `0x05xx` 的处理函数，`0x28xx` 是另一组入口。
- 固定区代码从 `0x002B` 开始连续布局。
- 分析过程中在已追踪代码里没有发现 bank 切换写操作，据此推断 region 1（bank0）常驻，region 2/3 的入口由硬件或引导阶段选择。这是静态分析结论，没有在实机上确认。

## 2. 命名约定

| 前缀 | 含义 |
|---|---|
| `f_XXXX` | 固定区（region 0）函数，XXXX 是 16 位逻辑地址 |
| `f_XXXX`（bank0 地址） | region 1 函数，逻辑地址 0x8000 以上 |
| `g_XXXX` | region 2（bank1）函数 |
| `h_XXXX` | region 3（bank2）函数 |
| `L_XXXX` | 汇编内部的跳转标签 |
| `Xdddd` | XDATA 地址宏，如 `X0693` |
| `SFR_XX` | 直接地址 0x80-0xFF 的 SFR 访问 |

`include/generated/ec_regs.h` 由 `pipeline.py` 根据实际访问生成，不是手写头文件。

## 3. 汇编重建与校验

`rebuild.py` 对每个区域做三件事：

1. 从 `build/analysis/functions.csv` 取函数入口，用 `ecanalyzer.walk` 沿控制流解码指令。
2. 已知函数逐条输出 `mov`/`ljmp`/`.db` 等汇编；相对跳转的目标如果落在已解码指令上，替换成 `L_XXXX` 标签，其余保持原始字节。
3. 未识别或数据区按原始字节输出 `.db`，每 16 字节一组，保证任何位置都有字节填充。

链接配置在 `linker/`，由 `sdld -f` 读取：

| 命令文件 | 输入 | 基址 |
|---|---|---|
| `linker/main64.lk` | vectors + region0 + bank0 | `VECTORS=0x0000`、`REGION0=0x002B`、`BANK0=0x8000` |
| `linker/bank1.lk` | bank1 | `BANK1=0x8000` |
| `linker/bank2.lk` | bank2 | `BANK2=0x8000` |

`tools/build.py` 把三份 Intel HEX 按区域偏移拼成 128 KiB，再和 `firmware/eFlashBK.bin` 逐字节比较，报告写入 `build/build_report.md`。

`tools/build.py --firmware` 在此之后把语义 C 函数编译、链接到空闲区并改写原始入口，输出 `build/firmware_128k.bin`。当前覆盖：电池任务链接到 bank0 `0xE600`（入口包装 `0xE600`，C 任务 `0xE78F`，改写 `0xA182` 的 `LCALL 0x40F9`），CRC 更新链接到 region0 `0x7B00`（入口包装 `0x7B00`，C 函数 `0x7B3A`，改写 `0x203A` 的 `MOV R0,#0xAF`）。这是 C 代码进入固件的正式路径。

因为数据都保留了原始字节，即使指令还原有偏差，只要地址不变，镜像仍然一致；反过来说明镜像一致不能证明指令语义全部还原正确。

改动 `.a51` 里的指令会改变后续地址，除非同时保持长度和跳转目标，否则会和 `functions.csv`、`.db` 填充一起错位。修改固件应优先按函数整体替换，并重新校验。

## 4. C 翻译模型

`to_c.py` 把每条指令翻译成 C 语句，不还原高层结构。核心约定在 `port/generated/common/ec_globals.h`：

- `A`、`B`、`C`、`PSW`、`SP`、`DPTR` 是普通全局变量，模拟寄存器。
- `RBANKS[4][8]` 表示四组工作寄存器，`RB(n)` 根据 `PSW` 的 RS1/RS0 选 bank。
- `DIR(a)` 访问内部 RAM，`XD(a)` 访问 XDATA，`CD(a)` 访问 code 空间。
- `ADD8`、`ADDC8`、`SUBB8`、`da_a` 等宏/函数实现进位和十进制调整语义。

这种写法适合逐函数对照阅读，不适合当工程 C 使用：

- 全局变量占用内部 RAM，`STACK[256]` 加 `RBANKS` 后超过 256 字节，链接必然失败。
- 每个函数都通过读写全局变量传递状态，编译器无法优化，也不能跨函数追踪类型。
- 函数边界沿用反汇编结果，调用关系是地址调用，不是 C 调用。

`port/src/` 里的 `main.c`、`ec_battery.c`、`ec_command.c`、`ec_battery_port.c` 是手写骨架，用来验证“按功能模块重写”的接口形态；它们依赖生成代码里的 `f_XXXX` 函数。

## 5. 流水线脚本

| 脚本 | 作用 | 主要输出 |
|---|---|---|
| `tools/ecanalyzer/ecanalyzer.py` | 函数识别、控制流遍历、反汇编、寄存器访问统计 | `build/analysis/` 下全部基础数据 |
| `tools/ecanalyzer/pipeline.py` | 汇总报告、生成头文件与工程小样、编译校验 | `include/generated/ec_regs.h`、`src/boot/vectors.a51`、`build/smoke/`、`build/analysis/*.md` |
| `tools/ecanalyzer/rebuild.py` | 生成 4 个区域汇编并完成全镜像比对 | `src/fixed/region0.a51`、`src/banks/*.a51`、`build/rebuild_report.*` |
| `tools/ecanalyzer/to_c.py` | 指令级 C 翻译 | `port/generated/` |
| `tools/build.py` | 统一构建入口，封装上面三步和 SDCC 调用 | `build/rebuilt_128k.bin`、`build/build_report.*` |
| `tools/build.py --firmware` | 把电池 C 模块编入 128 KiB 镜像 | `build/firmware_128k.bin`、`build/firmware_report.*` |
| `tools/ecanalyzer/run_ghidra.bat` | 把区域和函数表导入 Ghidra，供交互分析 | `build/ghidra-project/` |

Ghidra 脚本依赖 Ghidra 12.2 和 `ApplyEcFunctions.java`、`PrintEcStats.java`，不是构建必需步骤。

## 6. 分析数据

| 文件 | 内容 |
|---|---|
| `build/analysis/functions.csv` | 函数表：区域、逻辑地址、文件偏移、大小、指令数、调用数、可信度 |
| `build/analysis/disassembly_region0-3.asm` | 按函数组织的反汇编 |
| `build/analysis/full_region0-3.asm` | 按地址顺序的全区域清单 |
| `build/analysis/register_access.csv` | 每条 SFR/XDATA/位访问记录 |
| `build/analysis/memory_map.json` | 地址模型、统计、热点、间接跳转、调用边 |
| `build/analysis/callgraph/callgraph.dot` | 调用图，可用 Graphviz 渲染 |
| `build/analysis/regions/*.bin` | 拆分后的区域镜像 |
