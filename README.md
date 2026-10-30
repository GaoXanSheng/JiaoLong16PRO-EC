# ECForge —— 蛟龙 16 Pro EC 固件重建工程

笔记本 EC（Embedded Controller）固件 `eFlashBK.bin`（128 KiB）的逆向重建工程。工程代号 **ECForge**（EC + Forge，把原始镜像重新锻造出来），仓库名沿用 `JiaoLong16PRO-EC`。工程目标：

1. 把整份固件还原成可编译的 8051 汇编，并能从源码重建出与原镜像逐字节一致的结果。
2. 把业务逻辑写成可编译进镜像的语义 C，逐步替换原始汇编。
3. 保留一份指令级 C 翻译，用于逐函数阅读和调试。

## 当前状态

| 项目 | 状态 |
|---|---|
| 汇编重建 | 已验证：131072/131072 字节一致 |
| 参考镜像 | `firmware/eFlashBK.bin`，SHA256 `cda99cf6f3889ea2886294fe5f91a474ef6fa82b0640f6a9058b3dd1d1b883fe` |
| 反汇编覆盖 | 代码字节占比 region0 42.35%、region1 50.56%、region2 19.31%、region3 2.17% |
| 函数识别 | 1164 个函数，1559 条跨区域调用边 |
| 寄存器 | XDATA 673 个、位地址 38 个、SFR 45 个，见 `include/generated/ec_regs.h` |
| C 翻译 | 14 个文件可编译，但**不能链接成镜像**：CSEG 268,877 字节，超过 65,536 字节代码空间。`ec_jump.c` 峰值约 32 GB 内存，内存不足时会被 OOM 终止 |
| 电池业务逻辑 | 已按汇编语义重写，11 个仿真场景通过 |
| C 固件集成 | 电池任务和 CRC 更新已编入 `build/firmware_128k.bin`：`0xE600` / `0x7B00`，补丁 `0xA182` / `0x203A` |
| 构建环境 | Linux（Ubuntu + SDCC 4.5.0）已完整验证；Windows 入口保留 |
| 实机验证 | 未执行，本机没有目标硬件 |

## 环境

- SDCC 4.5.0（mcs51）：
  - Linux：`sudo apt install sdcc sdcc-ucsim`，可执行文件在 `/usr/bin`。
  - Windows：安装 SDCC 4.5.0，默认在 `C:\Program Files\SDCC\bin`。
  - 两种环境都可以用 `SDCC_BIN` 指定工具目录。
- Python 3.10+。
- `tools/toolchain.py` 统一处理平台差异：Windows 自动补 `.exe` 后缀，Linux 直接使用命令名；8051 模拟器在 Windows 是 `s51.exe`，Ubuntu 是 `ucsim_51`（`sdcc-ucsim` 包）。

## 构建

Linux / macOS：

```bash
# 汇编 + 链接 + 与参考镜像逐字节校验
python3 tools/build.py

# 编译 C 翻译树（仅编译校验）
python3 tools/build.py --c

# 重新分析镜像，生成 build/analysis 报告
python3 tools/build.py --analyze

# 重新分析并从镜像生成汇编源，再构建校验
python3 tools/build.py --regen

# regen + C 编译
python3 tools/build.py --all

# 清理 build 输出，保留 ghidra-project
python3 tools/build.py --clean

# 镜像校验 + 电池逻辑仿真 + 固件内 C 函数
python3 -m unittest discover -s tests -v
```

`tools/build.sh` 是同一入口的 shell 封装；Windows 下用 `tools\build.bat`，或把命令里的 `python3 tools/build.py` 换成 `python tools\build.py`。

默认构建只使用 `src/` 下已提交的 `.a51` 和 `linker/*.lk`，不依赖 `build/analysis`；`--regen` 才会重新分析并重写汇编源。

构建产物：

| 路径 | 内容 |
|---|---|
| `build/rebuilt_128k.bin` | 纯汇编重建的 128 KiB 镜像，与参考镜像逐字节一致 |
| `build/firmware_128k.bin` | C 模块编入后的 128 KiB 镜像，刷写用 |
| `build/build_report.md` / `.json` | 纯汇编构建的步骤、SHA256、逐字节比对 |
| `build/firmware_report.md` / `.json` | 每个覆盖函数的入口、代码段、补丁、差异字节 |
| `build/analysis/` | 函数表、反汇编、调用图、寄存器访问、分析报告 |
| `build/c/` | C 翻译的 `.rel` 与编译日志 |
| `build/ghidra-project/` | 交互分析用的 Ghidra 工程（可选，不参与构建） |

## 目录

| 路径 | 内容 | 性质 |
|---|---|---|
| `firmware/eFlashBK.bin` | 原始 128 KiB 镜像，唯一真值 | 输入 |
| `src/boot/vectors.a51` | 中断向量表，`0x0000-0x002A` | 生成 |
| `src/fixed/region0.a51` | 固定区，`0x002B-0x7FFF` | 生成 |
| `src/banks/bank0.a51` | 窗口区 bank0，逻辑 `0x8000-0xFFFF` | 生成 |
| `src/banks/bank1.a51` | 窗口区 bank1 | 生成 |
| `src/banks/bank2.a51` | 窗口区 bank2 | 生成 |
| `port/generated/` | 指令级 C 翻译，按区域分目录 | 生成 |
| `port/src/` | C 工程骨架：`main.c`、驱动、模块，含 `ec_battery.c`、`ec_crc.c` | 手写 |
| `src/glue/bat_dispatch.a51` | 电池 C 模块的入口包装和分发器胶水 | 手写 |
| `src/glue/crc_hook.a51` | CRC C 函数的寄存器 ABI 包装 | 手写 |
| `include/` | 头文件；`include/generated/ec_regs.h` 为生成 | 混合 |
| `linker/` | ASlink 命令文件：`main64.lk`、`bank1.lk`、`bank2.lk` | 手写 |
| `tools/build.py` | 统一构建入口（跨平台） | 手写 |
| `tools/build.sh` / `tools/build.bat` | Linux/macOS 与 Windows 的构建封装 | 手写 |
| `tools/toolchain.py` | SDCC 与模拟器的跨平台定位 | 手写 |
| `tools/simrun.py` | 模拟器调用封装，规避 ucsim 输出交错 | 手写 |
| `tools/ecanalyzer/` | 分析、代码生成流水线 | 手写 |
| `tools/winFT/` | EC flash 读写工具（Windows 专用） | 第三方 |
| `tests/` | 构建校验测试 | 手写 |
| `build/` | 构建与分析输出，可整体删除重建 | 输出 |
| `docs/` | 架构说明与业务逻辑清单 | 手写 |

## 生成物与手写文件

生成物不要手改，下次重生成会覆盖：

| 生成物 | 生成脚本 |
|---|---|
| `src/boot/vectors.a51`、`include/generated/ec_regs.h`、`build/smoke/` | `tools/ecanalyzer/pipeline.py` |
| `src/fixed/region0.a51`、`src/banks/*.a51` | `tools/ecanalyzer/rebuild.py` |
| `port/generated/` 全部 `.c`、`ec_globals.h`、`translation_report.json` | `tools/ecanalyzer/to_c.py` |
| `build/analysis/` | `tools/ecanalyzer/ecanalyzer.py` |

手写内容：`port/src/`、`include/` 下除 `generated/` 外的头文件、`linker/`、`tools/`、`tests/`、`docs/`。

## 流水线

```
firmware/eFlashBK.bin
   ├─ ecanalyzer.py   函数识别、反汇编、寄存器统计  -> build/analysis/
   ├─ pipeline.py     生成头文件、向量表、小样并校验 -> src/boot/, include/generated/, build/smoke/
   ├─ rebuild.py      生成全镜像汇编并链接校验       -> src/fixed/, src/banks/
   └─ to_c.py         指令级 C 翻译                  -> port/generated/

port/src/modules/*.c + src/glue/*.a51
   └─ tools/build.py --firmware  链接到空闲区，改写原始入口 -> build/firmware_128k.bin
```

生成顺序固定为 `ecanalyzer.py` → `pipeline.py` → `rebuild.py`，`to_c.py` 依赖 `build/analysis/functions.csv`。`tools/build.py --regen` 已包含前三步。

## 架构与地址模型

见 [docs/ARCHITECTURE.md](docs/ARCHITECTURE.md)。要点：

- 低 32 KiB 固定区，高 32 KiB 是三个 bank 共享的窗口，文件里按 32 KiB 连续存放。
- 函数命名：固定区 `f_XXXX`、bank1 `g_XXXX`、bank2 `h_XXXX`，后缀是 16 位逻辑地址。
- 汇编重建为逐字节一致服务：已知代码按指令还原，数据区和未识别区用 `.db` 兜底，所以改代码会破坏绝对地址布局。

## 已知限制

- 全量 C 翻译是指令级转写，不是可维护的重新实现。实测链接结果：CSEG 268,877 字节，超过 8051 的 65,536 字节代码空间，另有 214 字节内部 RAM 分配失败。它不能成为固件，只能作为阅读参考。
- `--c` 只是编译校验：`port/generated/common/ec_jump.c` 单文件编译峰值约 32 GB 内存，内存不足的环境会被 OOM 终止（其余 13 个文件正常）。固件构建和测试不依赖这一步。
- `--firmware` 目前只覆盖电池任务和 CRC 更新；其余 1160 多个函数仍是原始汇编。全 C 需要继续逐函数重写。
- C 代码段固定使用寄存器组 0；入口包装 `_bat_task_entry` 会保存/恢复 bank0。栈沿用现有的 `SP=0xC0`，模拟器实测最深到 `0xCE`；中断并发没有实机验证。
- bank1/bank2 的入口机制未确认，这两个区域的函数识别是探索性结果。
- 没有实机验证：重建镜像与原镜像一致，但功能行为未测试。
- 生成脚本读取固定路径 `firmware/eFlashBK.bin`，换镜像需要同步改脚本里的区域定义。
- Ubuntu 的模拟器命令名是 `ucsim_51`，且命令回显与 dump 输出分属不同线程，一次性喂完整脚本会把输出拼坏；`tools/simrun.py` 逐条喂命令规避，测试因此比 Windows 慢几秒。
- `tools/winFT/` 是 Windows 专用刷写工具，Linux 下刷写需要 Windows 机器、虚拟机或等价工具。

## 刷写

`tools/winFT/` 可以读写 EC flash。`备份.bat` 先备份；`刷入.bat` 写入 `build/firmware_128k.bin`（C 模块编入后的镜像），镜像不存在时会提示先运行 `python3 tools/build.py --firmware`。写坏 EC 固件可能导致整机不上电，务必先备份并保留原镜像用于回滚。刷写工具依赖 Windows，Linux 环境请使用 Windows 机器或虚拟机。

## 文档

- [docs/ARCHITECTURE.md](docs/ARCHITECTURE.md)：地址模型、重建方法、工具链细节
- [docs/BUSINESS.md](docs/BUSINESS.md)：启动流程、命令邮箱、电池域映射、其他业务域候选
- [port/README.md](port/README.md)：C 翻译的范围与限制
- `build/analysis/report.md`：镜像自动分析报告（生成）
- `build/analysis/verification_plan.md`：实机验证方案（生成）
