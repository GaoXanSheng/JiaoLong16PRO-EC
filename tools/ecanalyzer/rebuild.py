#!/usr/bin/env python3
import bisect
import csv
import importlib.util
import json
import re
import subprocess
import sys
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools"))
from toolchain import env_with_path, tool

BUILD = ROOT / "build"
ANALYSIS = BUILD / "analysis"

spec = importlib.util.spec_from_file_location("ecanalyzer", ROOT / "tools" / "ecanalyzer" / "ecanalyzer.py")
ec = importlib.util.module_from_spec(spec)
spec.loader.exec_module(ec)

SFR_MAP = {
    "P0": 0x80, "SP": 0x81, "DPL": 0x82, "DPH": 0x83, "PCON": 0x87,
    "TCON": 0x88, "TMOD": 0x89, "TL0": 0x8A, "TL1": 0x8B, "TH0": 0x8C,
    "TH1": 0x8D, "P1": 0x90, "SCON": 0x98, "SBUF": 0x99, "P2": 0xA0,
    "IE": 0xA8, "P3": 0xB0, "IP": 0xB8, "PSW": 0xD0, "ACC": 0xE0, "B": 0xF0,
}


def asm_text(text):
    if text.startswith("DB "):
        return ".db 0x" + text.split()[1].rstrip("h").lstrip("0") or "0"
    t = re.sub(r"\b([0-9A-F]{1,4})h\b", lambda m: "0x" + m.group(1), text)
    for name, addr in sorted(SFR_MAP.items(), key=lambda kv: -len(kv[0])):
        t = re.sub(r"\b" + name + r"\b", f"0x{addr:02X}", t)
    return t


def load_data():
    data = (ROOT / "firmware" / "eFlashBK.bin").read_bytes()
    regions = [
        ec.Region(0, data[0x00000:0x08000], 0x00000, 0x0000, "fixed"),
        ec.Region(1, data[0x08000:0x10000], 0x08000, 0x8000, "bank0"),
        ec.Region(2, data[0x10000:0x18000], 0x10000, 0x8000, "bank1"),
        ec.Region(3, data[0x18000:0x20000], 0x18000, 0x8000, "bank2"),
    ]
    entries = defaultdict(set)
    with open(ANALYSIS / "functions.csv", encoding="utf-8") as fh:
        for row in csv.DictReader(fh):
            entries[int(row["region"])].add(int(row["address"], 16))
    return data, regions, entries


def instruction_map(region, entries):
    m = {}
    for e in sorted(entries):
        f = ec.walk(region, e, entries)
        for a, text, ln, kind in f["insns"]:
            m.setdefault(a, (text, ln))
    return m


REL = ("SJMP", "JZ", "JNZ", "JC", "JNC", "JB", "JNB", "JBC", "DJNZ", "CJNE")


def rel_target(text):
    m = re.match(r"^(\w+)", text)
    if not m or m.group(1) not in REL:
        return None
    mm = re.search(r"([0-9A-F]{1,4})h$", text)
    if not mm:
        return None
    return int(mm.group(1), 16)


def with_label(text, target):
    mm = re.search(r"[0-9A-F]{1,4}h$", text)
    return text[:mm.start()] + f"L_{target:04X}"


def emit_region(region, m, start, path, module, area):
    end = region.logical_base + 0x8000
    layout = {}
    covered = {}
    a = start
    while a < end:
        if a in m:
            text, ln = m[a]
            layout[a] = (text, ln)
            for i in range(a, min(a + ln, end)):
                covered[i] = a
            a += ln
        else:
            a += 1

    labels = {}
    raw = set()
    for a, (text, ln) in layout.items():
        t = rel_target(text)
        if t is None:
            continue
        if t in layout or (region.logical_base <= t < end and t not in covered):
            labels[t] = f"L_{t:04X}"
        else:
            raw.add(a)

    lines = [f".module {module}", f".area {area} (ABS)", f".org 0x{start:04X}"]
    a = start
    while a < end:
        if a in labels:
            lines.append(labels[a] + ":")
        if a in layout:
            text, ln = layout[a]
            if a in raw or text.startswith("DB "):
                chunk = region.data[a - region.logical_base:a - region.logical_base + ln]
                lines.append(".db " + ",".join(f"0x{b:02X}" for b in chunk))
            else:
                t = rel_target(text)
                if t is not None:
                    text = with_label(text, t)
                lines.append(asm_text(text))
            a += ln
            continue
        chunk = []
        while a < end and a not in layout and len(chunk) < 16:
            if chunk and a in labels:
                break
            chunk.append(region.read(a))
            a += 1
        lines.append(".db " + ",".join(f"0x{b:02X}" for b in chunk))
    path.write_text("\n".join(lines) + "\n", encoding="utf-8")
    return len(lines)


def run(cmd, cwd=None):
    p = subprocess.run([str(c) for c in cmd], cwd=cwd, capture_output=True, text=True,
                       env=env_with_path())
    return p.returncode, (p.stdout or "") + (p.stderr or "")


def ihx_to_bin(path):
    mem = {}
    lo = None
    hi = None
    for line in Path(path).read_text().splitlines():
        line = line.strip()
        if not line.startswith(":"):
            continue
        b = bytes.fromhex(line[1:])
        n = b[0]
        addr = (b[1] << 8) | b[2]
        typ = b[3]
        payload = b[4:4 + n]
        if typ == 0:
            for i, v in enumerate(payload):
                mem[addr + i] = v
            lo = addr if lo is None else min(lo, addr)
            hi = (addr + n - 1) if hi is None else max(hi, addr + n - 1)
    out = bytearray(b"\xff" * (hi - lo + 1))
    for a, v in mem.items():
        out[a - lo] = v
    return bytes(out), lo


def assemble(sources, out_ihx, link_name):
    steps = []
    for src in sources:
        rel = BUILD / (src.stem + ".rel")
        code, out = run([str(tool("sdas8051")), "-plosgff", str(rel), str(src)])
        steps.append({"cmd": src.name, "code": code, "out": out.strip()[-300:]})
        if code != 0:
            return None, steps
    cmd = [str(tool("sdld")), "-f", str(ROOT / "linker" / f"{link_name}.lk")]
    code, out = run(cmd, cwd=ROOT)
    steps.append({"cmd": "sdld " + out_ihx.name, "code": code, "out": out.strip()[-300:]})
    if code != 0:
        return None, steps
    return out_ihx, steps


def main():
    BUILD.mkdir(exist_ok=True)
    data, regions, entries = load_data()
    maps = [instruction_map(regions[i], entries[i]) for i in range(4)]

    Boot = ROOT / "src" / "boot"
    Fixed = ROOT / "src" / "fixed"
    Banks = ROOT / "src" / "banks"
    counts = {}
    counts["vectors"] = len((Boot / "vectors.a51").read_text(encoding="utf-8").splitlines())
    counts["region0"] = emit_region(regions[0], maps[0], 0x2B, Fixed / "region0.a51", "REGION0", "REGION0")
    counts["bank0"] = emit_region(regions[1], maps[1], 0x8000, Banks / "bank0.a51", "BANK0", "BANK0")
    counts["bank1"] = emit_region(regions[2], maps[2], 0x8000, Banks / "bank1.a51", "BANK1", "BANK1")
    counts["bank2"] = emit_region(regions[3], maps[3], 0x8000, Banks / "bank2.a51", "BANK2", "BANK2")

    ihx0, steps0 = assemble(
        [Boot / "vectors.a51", Fixed / "region0.a51", Banks / "bank0.a51"],
        BUILD / "main64.ihx", "main64")
    ihx1, steps1 = assemble([Banks / "bank1.a51"], BUILD / "bank1.ihx", "bank1")
    ihx2, steps2 = assemble([Banks / "bank2.a51"], BUILD / "bank2.ihx", "bank2")

    result = {"files": counts, "steps": steps0 + steps1 + steps2, "diff": {}}
    if not (ihx0 and ihx1 and ihx2):
        (BUILD / "rebuild_report.json").write_text(json.dumps(result, indent=2), encoding="utf-8")
        print(json.dumps(result, indent=2))
        return

    main64, base0 = ihx_to_bin(ihx0)
    bank1, base1 = ihx_to_bin(ihx1)
    bank2, base2 = ihx_to_bin(ihx2)

    image = bytearray(b"\xff" * 0x20000)
    image[base0:base0 + len(main64)] = main64
    image[0x10000 + (base1 - 0x8000):0x10000 + (base1 - 0x8000) + len(bank1)] = bank1
    image[0x18000 + (base2 - 0x8000):0x18000 + (base2 - 0x8000) + len(bank2)] = bank2
    (BUILD / "rebuilt_128k.bin").write_bytes(bytes(image))

    mism = [i for i in range(0x20000) if image[i] != data[i]]
    regions_mism = defaultdict(int)
    for i in mism:
        regions_mism[i // 0x8000] += 1
    result["diff"] = {
        "identical": len(mism) == 0,
        "mismatch_bytes": len(mism),
        "by_region": {str(k): v for k, v in sorted(regions_mism.items())},
        "first": [{"file_offset": f"0x{i:05X}", "want": f"0x{data[i]:02X}",
                   "got": f"0x{image[i]:02X}"} for i in mism[:20]],
    }
    (BUILD / "rebuild_report.json").write_text(json.dumps(result, indent=2), encoding="utf-8")

    lines = ["# 全镜像重建报告", ""]
    lines.append("| 文件 | 行数 |")
    lines.append("|---|---|")
    for k, v in counts.items():
        lines.append(f"| {k} | {v} |")
    lines.append("")
    lines.append("| 步骤 | exit |")
    lines.append("|---|---|")
    for s in result["steps"]:
        lines.append(f"| {s['cmd']} | {s['code']} |")
    lines.append("")
    if result["diff"]["identical"]:
        lines.append("重镜像与原始固件逐字节一致：131072/131072。")
    else:
        lines.append(f"差异字节 {len(mism)} 个。")
        for m in result["diff"]["first"]:
            lines.append(f"- {m['file_offset']}: 原始 {m['want']}，重建 {m['got']}")
    (BUILD / "rebuild_report.md").write_text("\n".join(lines) + "\n", encoding="utf-8")
    print(json.dumps({"files": counts, "steps": result["steps"], "diff": result["diff"]}, indent=2))


if __name__ == "__main__":
    main()
