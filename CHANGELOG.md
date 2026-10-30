# 变更记录

## 0.4.0 - 2026-10-30

- 新增 `0x203A` 校验更新函数的语义 C 实现：`port/src/modules/ec_crc.c`，状态字节在 IRAM `0xAF`。
- 新增 `src/glue/crc_hook.a51`：按活动寄存器组决定是否保存 bank0，完成 R7 输入/输出映射。
- `--firmware` 增加第二个覆盖：CRC 代码段链接到 region0 `0x7B00`，`0x203A` 改为 `LJMP 0x7B00`。
- 新增 CRC 固件内 s51 测试，4 组向量与汇编模型一致。
- 集成报告改为覆盖列表，记录每个函数的原始入口、补丁、代码段和入口地址。

## 0.3.0 - 2026-10-30

- 新增 `tools/build.py --firmware`：把 `port/src/modules/ec_battery.c` 编成 8051 代码段，链接到空闲区 `0xE600-0xE80F`（入口包装 `0xE600`，C 任务 `0xE78F`），改写任务调用点 `0xA182`，输出可刷写的 `build/firmware_128k.bin`。
- 新增 `src/glue/bat_dispatch.a51`：保存/恢复 bank0 的入口包装，以及电池 C 模块到原始命令分发器 `0x1A4C` 的寄存器胶水。
- 实测全量 C 翻译无法成为固件：CSEG 268,877 字节，超过 8051 的 65,536 字节代码空间；保留为阅读参考。
- 新增 `tests/test_firmware.py`：校验 C 代码段和调用点之外没有改动，并在 s51 中从固件调用点执行型号选择与初始化序列。
- 刷写脚本改为写 `build/firmware_128k.bin`。

## 0.2.0 - 2026-10-30

- 按汇编语义重写电池管理模块，修正初始化序列、通知描述符、充电设定、刷新阈值等偏差。
- 新增 8051 仿真测试：SDCC 编译 + s51 执行，覆盖 11 个电池场景并校验命令序列。
- 新增 `docs/BUSINESS.md`：启动流程、命令邮箱、电池域映射、其他业务域候选。
- `ec_command` 参数改为 `cmd/arg` 命名，与邮箱寄存器对应。

## 0.1.0 - 2026-10-30

- 目录重构为 `firmware/`、`src/`、`port/`、`include/`、`linker/`、`tools/`、`tests/`、`build/`。
- 原始镜像移入 `firmware/eFlashBK.bin`，生成物与构建产物不再和源码混放。
- 新增 `tools/build.py` 统一构建入口：汇编、链接、128 KiB 逐字节校验。
- 链接参数落到 `linker/*.lk`，构建不再在命令行拼接 `-b`。
- 生成脚本改用新路径；`build/smoke/` 存放流水线的小样产物。
- 新增 `tests/test_build.py`，校验参考镜像哈希和重建一致性。
- 新增 `VERSION`、`.editorconfig`。
