#!/usr/bin/env python3
import argparse
import hashlib
import json
import re
import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
from toolchain import env_with_path, require

BUILD = ROOT / "build"
ANALYSIS = BUILD / "analysis"
C_BUILD = BUILD / "c"
FW_BUILD = BUILD / "fw"
ORIGINAL = ROOT / "firmware" / "eFlashBK.bin"
FIRMWARE = BUILD / "firmware_128k.bin"
C_BLOB_BASE = 0xE600
BAT_CALL_FILE = 0x0A182
BAT_CALL_ORIGINAL = bytes([0x12, 0x40, 0xF9])
BAT_TASK_SYMBOL = "_bat_status_task"
CRC_BLOB_BASE = 0x7B00
CRC_PATCH_FILE = 0x203A
CRC_PATCH_ORIGINAL = bytes([0x78, 0xAF, 0xE6])
CRC_ENTRY_SYMBOL = "_crc_entry"
IMAGE_SIZE = 0x20000
VERSION = (ROOT / "VERSION").read_text(encoding="utf-8").strip() if (ROOT / "VERSION").exists() else "dev"

ASM_UNITS = [
    ("src/boot/vectors.a51", "vectors"),
    ("src/fixed/region0.a51", "region0"),
    ("src/banks/bank0.a51", "bank0"),
    ("src/banks/bank1.a51", "bank1"),
    ("src/banks/bank2.a51", "bank2"),
]

LINK_UNITS = ["main64", "bank1", "bank2"]

INCLUDE_DIRS = ["port/generated/common", "include", "include/generated"]


class BuildError(Exception):
    pass


def run(cmd):
    proc = subprocess.run([str(c) for c in cmd], cwd=ROOT, capture_output=True, text=True,
                          encoding="utf-8", errors="replace", env=env_with_path())
    return proc.returncode, (proc.stdout or "") + (proc.stderr or "")


def need_tool(name):
    try:
        return require(name)
    except FileNotFoundError as exc:
        raise BuildError(str(exc))


def sha256(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def read_ihx(path):
    mem = {}
    for line in Path(path).read_text(encoding="utf-8", errors="replace").splitlines():
        line = line.strip()
        if not line.startswith(":"):
            continue
        raw = bytes.fromhex(line[1:])
        count = raw[0]
        addr = (raw[1] << 8) | raw[2]
        if raw[3] != 0:
            continue
        for i, value in enumerate(raw[4:4 + count]):
            mem[addr + i] = value
    return mem


def load_image():
    image = bytearray(b"\xff" * IMAGE_SIZE)
    for addr, value in read_ihx(BUILD / "main64.ihx").items():
        if 0 <= addr < 0x10000:
            image[addr] = value
    for name, base in (("bank1.ihx", 0x10000), ("bank2.ihx", 0x18000)):
        for addr, value in read_ihx(BUILD / name).items():
            offset = base + (addr - 0x8000)
            if base <= offset < base + 0x8000:
                image[offset] = value
    return image


def assemble():
    sdas = need_tool("sdas8051")
    sdld = need_tool("sdld")
    BUILD.mkdir(parents=True, exist_ok=True)
    steps = []
    for src, name in ASM_UNITS:
        rel = BUILD / f"{name}.rel"
        code, out = run([sdas, "-plosgff", rel, ROOT / src])
        steps.append({"cmd": f"sdas8051 {src}", "code": code, "out": out.strip()[-500:]})
        if code != 0:
            raise BuildError(f"汇编失败: {src}\n{out}")
    for name in LINK_UNITS:
        cmd = [sdld, "-f", ROOT / "linker" / f"{name}.lk"]
        code, out = run(cmd)
        steps.append({"cmd": f"sdld {name}.lk", "code": code, "out": out.strip()[-500:]})
        if code != 0:
            raise BuildError(f"链接失败: {name}.lk\n{out}")
    return steps


def verify(steps):
    if len(ORIGINAL.read_bytes()) != IMAGE_SIZE:
        raise BuildError(f"{ORIGINAL.name} 大小不是 {IMAGE_SIZE} 字节")
    image = load_image()
    original = ORIGINAL.read_bytes()
    mismatches = [i for i in range(IMAGE_SIZE) if image[i] != original[i]]
    (BUILD / "rebuilt_128k.bin").write_bytes(bytes(image))
    return {
        "version": VERSION,
        "steps": steps,
        "artifacts": {p.name: p.stat().st_size for p in BUILD.glob("*.ihx")
                      if p.name in ("main64.ihx", "bank1.ihx", "bank2.ihx")},
        "verify": {
            "original": ORIGINAL.relative_to(ROOT).as_posix(),
            "original_sha256": hashlib.sha256(original).hexdigest(),
            "rebuilt_sha256": hashlib.sha256(bytes(image)).hexdigest(),
            "identical": not mismatches,
            "mismatch_bytes": len(mismatches),
            "first": [{"offset": f"0x{i:05X}", "want": f"0x{original[i]:02X}",
                       "got": f"0x{image[i]:02X}"} for i in mismatches[:10]],
        },
    }


def write_report(result):
    BUILD.mkdir(parents=True, exist_ok=True)
    (BUILD / "build_report.json").write_text(json.dumps(result, indent=2), encoding="utf-8")
    v = result["verify"]
    lines = ["# 构建报告", "", f"- 版本: {VERSION}", ""]
    lines.append("| 步骤 | exit |")
    lines.append("|---|---|")
    for step in result["steps"]:
        lines.append(f"| {step['cmd']} | {step['code']} |")
    lines.append("")
    lines.append("| 产物 | 字节 |")
    lines.append("|---|---|")
    for name, size in sorted(result["artifacts"].items()):
        lines.append(f"| {name} | {size} |")
    lines.append("")
    lines.append("## 逐字节校验")
    lines.append("")
    lines.append(f"- 原始镜像 `{v['original']}` SHA256: `{v['original_sha256']}`")
    lines.append(f"- 重建镜像 SHA256: `{v['rebuilt_sha256']}`")
    if v["identical"]:
        lines.append(f"- 结果: 一致，{IMAGE_SIZE}/{IMAGE_SIZE} 字节")
    else:
        lines.append(f"- 结果: 不一致，差异 {v['mismatch_bytes']} 字节")
        for item in v["first"]:
            lines.append(f"  - {item['offset']}: 原始 {item['want']}，重建 {item['got']}")
    (BUILD / "build_report.md").write_text("\n".join(lines) + "\n", encoding="utf-8")


def build_asm():
    result = verify(assemble())
    write_report(result)
    v = result["verify"]
    state = "一致" if v["identical"] else f"不一致，差异 {v['mismatch_bytes']} 字节"
    print(f"汇编重建: {state} -> {BUILD / 'rebuilt_128k.bin'}")
    print(f"报告: {BUILD / 'build_report.md'}")
    return 0 if v["identical"] else 2


def c_sources():
    return sorted((ROOT / "port" / "src").rglob("*.c")) + sorted((ROOT / "port" / "generated").rglob("*.c"))


def build_c():
    sdcc = need_tool("sdcc")
    C_BUILD.mkdir(parents=True, exist_ok=True)
    log = []
    errors = 0
    warnings = 0
    for src in c_sources():
        rel = C_BUILD / f"{src.stem}.rel"
        cmd = [sdcc, "-mmcs51", "--model-small", "--std-c99"]
        for inc in INCLUDE_DIRS:
            cmd += ["-I", ROOT / inc]
        cmd += ["-c", src, "-o", rel]
        code, out = run(cmd)
        warnings += len(re.findall(r"warning \d+:", out))
        errors += len(re.findall(r"error \d+:", out))
        log.append(f"=== {src.relative_to(ROOT)} (exit {code}) ===")
        log.append(out.rstrip())
        if code != 0:
            errors += 1
            if code < 0:
                log.append(f"[signal {-code}] 编译进程被信号终止，常见原因是内存不足"
                           f"（ec_jump.c 峰值约 32 GB）")
    (C_BUILD / "compile.log").write_text("\n".join(log) + "\n", encoding="utf-8")
    print(f"C 翻译编译: {len(c_sources())} 个文件，错误 {errors}，警告 {warnings}")
    print(f"日志: {C_BUILD / 'compile.log'}")
    return 0 if errors == 0 else 1


def rel_symbol(rel_path, symbol):
    for line in Path(rel_path).read_text(encoding="utf-8", errors="replace").splitlines():
        parts = line.split()
        if len(parts) >= 3 and parts[0] == "S" and parts[1] == symbol and parts[2].startswith("Def"):
            return int(parts[2][3:], 16)
    raise BuildError(f"{rel_path.name} 缺少符号 {symbol}")


def rel_area_size(rel_path, area):
    for line in Path(rel_path).read_text(encoding="utf-8", errors="replace").splitlines():
        parts = line.split()
        if len(parts) >= 4 and parts[0] == "A" and parts[1] == area:
            return int(parts[3], 16)
    raise BuildError(f"{rel_path.name} 缺少段 {area}")


def build_firmware():
    code = build_asm()
    if code != 0:
        return code
    sdcc = need_tool("sdcc")
    sdas = need_tool("sdas8051")
    sdld = need_tool("sdld")
    FW_BUILD.mkdir(parents=True, exist_ok=True)
    bat_rel = FW_BUILD / "battery.rel"
    glue_rel = FW_BUILD / "bat_dispatch.rel"
    blob_ihx = FW_BUILD / "battery_blob.ihx"
    steps = []
    cmd = [sdcc, "-mmcs51", "--model-small", "--std-c99", "-I", ROOT / "include",
           "-c", ROOT / "port" / "src" / "modules" / "ec_battery.c", "-o", bat_rel]
    rc, out = run(cmd)
    steps.append({"cmd": "sdcc ec_battery.c", "code": rc, "out": out.strip()[-500:]})
    if rc != 0:
        raise BuildError(f"电池模块编译失败\n{out}")
    rc, out = run([sdas, "-plosgff", glue_rel, ROOT / "src" / "glue" / "bat_dispatch.a51"])
    steps.append({"cmd": "sdas8051 bat_dispatch.a51", "code": rc, "out": out.strip()[-500:]})
    if rc != 0:
        raise BuildError(f"调度胶水汇编失败\n{out}")
    cmd = [sdld, "-i", "-m", blob_ihx, "-b", f"CSEG=0x{C_BLOB_BASE:04X}", glue_rel, bat_rel]
    rc, out = run(cmd)
    steps.append({"cmd": "sdld battery_blob.ihx", "code": rc, "out": out.strip()[-500:]})
    if rc != 0:
        raise BuildError(f"C 代码段链接失败\n{out}")

    glue_size = rel_area_size(glue_rel, "CSEG")
    entry_offset = rel_symbol(glue_rel, "_bat_task_entry")
    entry_addr = C_BLOB_BASE + entry_offset
    task_offset = glue_size + rel_symbol(bat_rel, BAT_TASK_SYMBOL)
    task_addr = C_BLOB_BASE + task_offset
    blob = read_ihx(blob_ihx)
    if not blob:
        raise BuildError("C 代码段为空")
    if min(blob) < C_BLOB_BASE or max(blob) >= 0x10000:
        raise BuildError(f"C 代码段越界: 0x{min(blob):04X}-0x{max(blob):04X}")
    if not (C_BLOB_BASE <= entry_addr <= max(blob)):
        raise BuildError(f"任务入口 0x{entry_addr:04X} 不在代码段内")

    crc_rel = FW_BUILD / "crc.rel"
    crc_glue_rel = FW_BUILD / "crc_hook.rel"
    crc_blob_ihx = FW_BUILD / "crc_blob.ihx"
    rc, out = run([sdcc, "-mmcs51", "--model-small", "--std-c99", "-I", ROOT / "include",
                   "-c", ROOT / "port" / "src" / "modules" / "ec_crc.c", "-o", crc_rel])
    steps.append({"cmd": "sdcc ec_crc.c", "code": rc, "out": out.strip()[-500:]})
    if rc != 0:
        raise BuildError(f"C 校验模块编译失败\n{out}")
    rc, out = run([sdas, "-plosgff", crc_glue_rel, ROOT / "src" / "glue" / "crc_hook.a51"])
    steps.append({"cmd": "sdas8051 crc_hook.a51", "code": rc, "out": out.strip()[-500:]})
    if rc != 0:
        raise BuildError(f"校验胶水汇编失败\n{out}")
    cmd = [sdld, "-i", "-m", crc_blob_ihx, "-b", f"CSEG=0x{CRC_BLOB_BASE:04X}", crc_glue_rel, crc_rel]
    rc, out = run(cmd)
    steps.append({"cmd": "sdld crc_blob.ihx", "code": rc, "out": out.strip()[-500:]})
    if rc != 0:
        raise BuildError(f"C 校验代码段链接失败\n{out}")

    crc_glue_size = rel_area_size(crc_glue_rel, "CSEG")
    crc_entry_addr = CRC_BLOB_BASE + rel_symbol(crc_glue_rel, CRC_ENTRY_SYMBOL)
    crc_func_addr = CRC_BLOB_BASE + crc_glue_size + rel_symbol(crc_rel, "_crc_update")
    crc_blob = read_ihx(crc_blob_ihx)
    if not crc_blob:
        raise BuildError("C 校验代码段为空")
    if min(crc_blob) < CRC_BLOB_BASE or max(crc_blob) >= 0x8000:
        raise BuildError(f"C 校验代码段越界: 0x{min(crc_blob):04X}-0x{max(crc_blob):04X}")

    image = bytearray(ORIGINAL.read_bytes())
    for addr, value in blob.items():
        offset = 0x08000 + (addr - 0x8000)
        if image[offset] != 0xFF:
            raise BuildError(f"C 代码段覆盖了非空闲字节: 0x{offset:05X} = 0x{image[offset]:02X}")
        image[offset] = value
    for addr, value in crc_blob.items():
        if image[addr] != 0xFF:
            raise BuildError(f"C 校验代码段覆盖了非空闲字节: 0x{addr:05X} = 0x{image[addr]:02X}")
        image[addr] = value

    if image[BAT_CALL_FILE:BAT_CALL_FILE + 3] != BAT_CALL_ORIGINAL:
        raise BuildError(f"调用点 0x{BAT_CALL_FILE:05X} 不是预期指令: {image[BAT_CALL_FILE:BAT_CALL_FILE + 3].hex()}")
    image[BAT_CALL_FILE] = 0x12
    image[BAT_CALL_FILE + 1] = (entry_addr >> 8) & 0xFF
    image[BAT_CALL_FILE + 2] = entry_addr & 0xFF

    if image[CRC_PATCH_FILE:CRC_PATCH_FILE + 3] != CRC_PATCH_ORIGINAL:
        raise BuildError(f"校验函数入口 0x{CRC_PATCH_FILE:05X} 不是预期指令: "
                         f"{image[CRC_PATCH_FILE:CRC_PATCH_FILE + 3].hex()}")
    image[CRC_PATCH_FILE] = 0x02
    image[CRC_PATCH_FILE + 1] = (crc_entry_addr >> 8) & 0xFF
    image[CRC_PATCH_FILE + 2] = crc_entry_addr & 0xFF

    FIRMWARE.write_bytes(bytes(image))

    original = ORIGINAL.read_bytes()
    diffs = [i for i in range(len(image)) if image[i] != original[i]]
    blob_start = 0x08000 + (C_BLOB_BASE - 0x8000)
    blob_end = blob_start + (max(blob) - C_BLOB_BASE) + 1
    crc_start = CRC_BLOB_BASE
    crc_end = CRC_BLOB_BASE + (max(crc_blob) - CRC_BLOB_BASE) + 1
    allowed = [
        (blob_start, blob_end),
        (BAT_CALL_FILE, BAT_CALL_FILE + 3),
        (crc_start, crc_end),
        (CRC_PATCH_FILE, CRC_PATCH_FILE + 3),
    ]
    outside = [i for i in diffs if not any(a <= i < b for a, b in allowed)]
    if outside:
        raise BuildError(f"集成镜像在替换区之外发生变化: {outside[:10]}")

    overrides = [
        {
            "name": "battery",
            "source": "port/src/modules/ec_battery.c",
            "patch": f"0x{BAT_CALL_FILE:05X}",
            "patch_before": BAT_CALL_ORIGINAL.hex(),
            "patch_after": bytes(image[BAT_CALL_FILE:BAT_CALL_FILE + 3]).hex(),
            "entry": f"0x{entry_addr:04X}",
            "function": f"0x{task_addr:04X}",
            "blob": f"0x{C_BLOB_BASE:04X}-0x{max(blob):04X}",
        },
        {
            "name": "crc",
            "source": "port/src/modules/ec_crc.c",
            "patch": f"0x{CRC_PATCH_FILE:05X}",
            "patch_before": CRC_PATCH_ORIGINAL.hex(),
            "patch_after": bytes(image[CRC_PATCH_FILE:CRC_PATCH_FILE + 3]).hex(),
            "entry": f"0x{crc_entry_addr:04X}",
            "function": f"0x{crc_func_addr:04X}",
            "blob": f"0x{CRC_BLOB_BASE:04X}-0x{max(crc_blob):04X}",
        },
    ]

    result = {
        "version": VERSION,
        "steps": steps,
        "image": FIRMWARE.relative_to(ROOT).as_posix(),
        "image_sha256": hashlib.sha256(bytes(image)).hexdigest(),
        "base_sha256": hashlib.sha256(original).hexdigest(),
        "c_source": "port/src/modules/ec_battery.c",
        "blob_base": f"0x{C_BLOB_BASE:04X}",
        "blob_end": f"0x{max(blob):04X}",
        "blob_bytes": len(blob),
        "entry_symbol": "_bat_task_entry",
        "entry_address": f"0x{entry_addr:04X}",
        "task_symbol": BAT_TASK_SYMBOL,
        "task_address": f"0x{task_addr:04X}",
        "call_site": f"0x{BAT_CALL_FILE:05X}",
        "call_before": BAT_CALL_ORIGINAL.hex(),
        "call_after": bytes(image[BAT_CALL_FILE:BAT_CALL_FILE + 3]).hex(),
        "crc_source": "port/src/modules/ec_crc.c",
        "crc_blob_base": f"0x{CRC_BLOB_BASE:04X}",
        "crc_blob_end": f"0x{max(crc_blob):04X}",
        "crc_entry_symbol": CRC_ENTRY_SYMBOL,
        "crc_entry_address": f"0x{crc_entry_addr:04X}",
        "crc_function_address": f"0x{crc_func_addr:04X}",
        "crc_patch_site": f"0x{CRC_PATCH_FILE:05X}",
        "crc_patch_before": CRC_PATCH_ORIGINAL.hex(),
        "crc_patch_after": bytes(image[CRC_PATCH_FILE:CRC_PATCH_FILE + 3]).hex(),
        "overrides": overrides,
        "diff_bytes": len(diffs),
    }
    (BUILD / "firmware_report.json").write_text(json.dumps(result, indent=2), encoding="utf-8")
    lines = ["# C 固件集成报告", "", f"- 版本: {VERSION}", ""]
    lines.append("| 覆盖 | C 源文件 | 原始入口 | 补丁 | 代码段 |")
    lines.append("|---|---|---|---|---|")
    for item in overrides:
        lines.append(f"| {item['name']} | `{item['source']}` | `{item['patch']}` | "
                     f"`{item['patch_before']}` -> `{item['patch_after']}` | `{item['blob']}` |")
    lines.append("")
    lines.append(f"| 项目 | 值 |")
    lines.append("|---|---|")
    lines.append(f"| 电池入口 | `{result['entry_symbol']}` @ `{result['entry_address']}` |")
    lines.append(f"| 电池 C 任务 | `{result['task_symbol']}` @ `{result['task_address']}` |")
    lines.append(f"| 校验入口 | `{result['crc_entry_symbol']}` @ `{result['crc_entry_address']}` |")
    lines.append(f"| 校验 C 函数 | `crc_update` @ `{result['crc_function_address']}` |")
    lines.append(f"| 差异字节 | {result['diff_bytes']}（全部位于替换区和补丁点） |")
    lines.append("")
    lines.append(f"- 基础镜像 SHA256: `{result['base_sha256']}`")
    lines.append(f"- 集成镜像 SHA256: `{result['image_sha256']}`")
    lines.append(f"- 输出: `{result['image']}`")
    (BUILD / "firmware_report.md").write_text("\n".join(lines) + "\n", encoding="utf-8")
    print(f"C 固件: {FIRMWARE} ({len(image)} 字节, 差异 {len(diffs)})")
    print(f"电池: 入口 0x{entry_addr:04X}, C 任务 0x{task_addr:04X}, 补丁 0x{BAT_CALL_FILE:05X}")
    print(f"校验: 入口 0x{crc_entry_addr:04X}, C 函数 0x{crc_func_addr:04X}, 补丁 0x{CRC_PATCH_FILE:05X}")
    print(f"报告: {BUILD / 'firmware_report.md'}")
    return 0


def analyze():
    steps = [
        ("ecanalyzer.py", ROOT / "tools" / "ecanalyzer" / "ecanalyzer.py"),
        ("pipeline.py", ROOT / "tools" / "ecanalyzer" / "pipeline.py"),
    ]
    for name, script in steps:
        code, out = run([sys.executable, script])
        if code != 0:
            raise BuildError(f"{name} 失败\n{out}")
        print(f"分析 {name}: ok")
    print(f"分析输出: {ANALYSIS}")


def regen():
    analyze()
    rebuild = ROOT / "tools" / "ecanalyzer" / "rebuild.py"
    code, out = run([sys.executable, rebuild])
    if code != 0:
        raise BuildError(f"rebuild.py 失败\n{out}")
    print("汇编源已从镜像重新生成")


def clean():
    if BUILD.exists():
        for entry in BUILD.iterdir():
            if entry.name == "ghidra-project":
                continue
            if entry.is_dir():
                shutil.rmtree(entry)
            else:
                entry.unlink()
    for cache in ROOT.rglob("__pycache__"):
        shutil.rmtree(cache)
    print(f"已清理构建输出: {BUILD}（保留 ghidra-project）")


def main():
    parser = argparse.ArgumentParser(description="EC 固件重建工程构建入口")
    parser.add_argument("--version", action="version", version=f"EC rebuild {VERSION}")
    parser.add_argument("--c", action="store_true", help="编译 C 翻译树（仅编译校验，不链接）")
    parser.add_argument("--firmware", action="store_true",
                        help="把电池 C 模块编入 128K 镜像，输出 build/firmware_128k.bin")
    parser.add_argument("--analyze", action="store_true", help="重新分析 firmware/eFlashBK.bin 并生成报告")
    parser.add_argument("--regen", action="store_true", help="重新分析并从镜像生成汇编源")
    parser.add_argument("--all", action="store_true", help="regen + C 编译")
    parser.add_argument("--clean", action="store_true", help="删除 build 输出（保留 ghidra-project）")
    args = parser.parse_args()

    if args.all:
        args.regen = True
        args.c = True

    try:
        if args.clean:
            clean()
        if args.regen:
            regen()
        if args.analyze and not args.regen:
            analyze()
        if args.firmware:
            return build_firmware()
        build_needed = not (args.analyze or args.c or args.clean) or args.regen
        if build_needed:
            code = build_asm()
            if code != 0:
                return code
        if args.c:
            return build_c()
    except BuildError as exc:
        print(f"构建失败: {exc}", file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
