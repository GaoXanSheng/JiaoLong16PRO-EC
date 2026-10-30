# C 翻译层

这个目录存放指令级 C 翻译和手写业务模块。`generated/` 不是固件源码；`src/modules/` 里的语义实现通过 `--firmware` 编入镜像。

## 组成

| 路径 | 内容 | 性质 |
|---|---|---|
| `generated/` | 1164 个函数的逐指令翻译，`ec_globals.h`、`ec_stubs.c`、`ec_jump*.c` | 生成，禁止手改 |
| `src/main.c` | 复位入口，调用 `f_0000` | 手写，仅翻译层 |
| `src/drivers/ec_battery_port.c` | 电池模块到 `ec_command_run` 的旧桥接 | 手写，仅翻译层 |
| `src/modules/ec_battery.c` | 电池型号选择、状态、初始化序列 | 手写，已编入固件 |
| `src/modules/ec_crc.c` | 校验更新，状态字节在 IRAM `0xAF` | 手写，已编入固件 |
| `src/modules/ec_command.c` | 命令执行封装 | 手写，仅翻译层 |

## 覆盖函数

```bat
python tools\build.py --firmware
```

| 覆盖 | 原始入口 | C 源 | 实际入口 | 代码段 | 镜像补丁 |
|---|---|---|---|---|---|
| battery | `0x40F9`（调用点 `0xA182`） | `ec_battery.c` | `0xE600` | `0xE600-0xE80F` | `12 40 F9` -> `12 E6 00` |
| crc | `0x203A` | `ec_crc.c` | `0x7B00` | `0x7B00-0x7B7C` | `78 AF E6` -> `02 7B 00` |

构建过程：

1. 先重建纯汇编镜像并逐字节校验。
2. SDCC 编译 `ec_battery.c`（479 字节，`DSEG=0`）和 `ec_crc.c`（43 字节，`DSEG=0`）。
3. 汇编两个入口包装：
   - `bat_dispatch.a51`：保存/恢复 bank0，分发调用设置 `R5=0x8C`、`R3=0x12`、`R7=0`。
   - `crc_hook.a51`：活动寄存器组为 0 时直接调用；否则保存/恢复 bank0，R7 与 DPL 互转。
4. battery 代码段链接到 bank0 `0xE600`，crc 代码段链接到 region0 `0x7B00`。
5. 改写 `0xA182` 和 `0x203A` 两个入口。
6. 输出 `build/firmware_128k.bin`，差异只在两个代码段和两个补丁点。

`build/firmware_report.md` 按覆盖列表记录原始入口、补丁、代码段、入口地址和差异字节。

## 验证

电池模块有 SDCC + s51 仿真测试，覆盖 11 个场景：

```bat
python -m unittest tests.test_battery_sim -v
```

`tests/test_firmware.py` 把集成镜像的前 64 KiB 载入 s51：

- 从 `0xA182` 执行电池 C 任务（分发器临时替换为返回成功的桩），校验型号、同步寄存器、邮箱、初始化序列和 bank0 恢复。
- 从 `0x7C00` 的测试桩调用 `0x203A`，用 4 组输入校验 CRC 的返回值和 IRAM `0xAF` 状态。

## 全量翻译为什么不能链接

`ec_globals.h` 用全局变量模拟 8051 寄存器和内存，1164 个函数展开后实测：

```
CSEG 268,877 字节            (8051 代码空间 65,536)
Could not get 214 bytes in internal RAM for area DSEG
Insufficient ROM/EPROM/FLASH memory
```

代码体积是原固件的 7 倍，超过 8051 代码空间 4 倍。即使把影子 RAM 全部移到 XDATA，也放不进 64 KiB，更不用说 128 KiB 分 bank 的布局。这个翻译只能用于阅读，不能作为固件。

## 编译

```bat
python tools\build.py --c
```

产物在 `build/c/`，完整日志为 `build/c/compile.log`。当前结果：14 个文件，0 错误，150 警告。

## 使用方式

- 读某个函数时，在 `generated/` 里按地址定位，配合 `build/analysis/disassembly_region*.asm` 对照。
- 新增覆盖函数：在 `src/modules/` 写语义 C，在 `src/glue/` 写寄存器 ABI 包装，在 `tools/build.py` 增加代码段和补丁登记；不要改生成文件。
- 重新生成翻译：先跑 `python tools/ecanalyzer/to_c.py`（依赖 `build/analysis/functions.csv`）。
