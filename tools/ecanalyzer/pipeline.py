#!/usr/bin/env python3
import csv
import importlib.util
import json
import subprocess
import sys
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools"))
from toolchain import env_with_path, tool

ANALYSIS = ROOT / "build" / "analysis"
BUILD = ROOT / "build"

spec = importlib.util.spec_from_file_location("ecanalyzer", ROOT / "tools" / "ecanalyzer" / "ecanalyzer.py")
ec = importlib.util.module_from_spec(spec)
spec.loader.exec_module(ec)


def load():
    data = (ROOT / "firmware" / "eFlashBK.bin").read_bytes()
    regions = [
        ec.Region(0, data[0x00000:0x08000], 0x00000, 0x0000, "fixed"),
        ec.Region(1, data[0x08000:0x10000], 0x08000, 0x8000, "bank0"),
        ec.Region(2, data[0x10000:0x18000], 0x10000, 0x8000, "bank1"),
        ec.Region(3, data[0x18000:0x20000], 0x18000, 0x8000, "bank2"),
    ]
    entries = defaultdict(set)
    names = {}
    with open(ANALYSIS / "functions.csv", encoding="utf-8") as fh:
        for row in csv.DictReader(fh):
            r = int(row["region"])
            a = int(row["address"], 16)
            entries[r].add(a)
            names[(r, a)] = row["name"]
    return data, regions, entries, names


def instruction_maps(regions, entries):
    maps = {}
    for idx, region in enumerate(regions):
        m = {}
        for e in sorted(entries[idx]):
            f = ec.walk(region, e, entries[idx])
            for a, text, ln, kind in f["insns"]:
                m.setdefault(a, (text, ln))
        maps[idx] = m
    return maps


def full_listing(regions, maps):
    reports = []
    for idx, region in enumerate(regions):
        m = maps[idx]
        lines = [f"; region {idx} {region.kind} logical 0x{region.logical_base:04X}-0x{region.logical_base + 0x7FFF:04X}"]
        code = 0
        data_bytes = 0
        ff_bytes = 0
        a = region.logical_base
        end = region.logical_base + 0x8000
        while a < end:
            if a in m:
                text, ln = m[a]
                raw = region.data[a - region.logical_base:a - region.logical_base + ln].hex(" ")
                lines.append(f"{a:04X}: {raw:<11} {text}")
                code += ln
                a += ln
                continue
            start = a
            chunk = []
            while a < end and a not in m and len(chunk) < 16:
                chunk.append(region.read(a))
                a += 1
            if all(b == 0xFF for b in chunk):
                ff_bytes += len(chunk)
            else:
                data_bytes += len(chunk)
            lines.append(f"{start:04X}: DB " + ",".join(f"{b:02X}h" for b in chunk))
        reports.append({
            "region": idx,
            "kind": region.kind,
            "code_bytes": code,
            "data_bytes": data_bytes,
            "ff_bytes": ff_bytes,
            "coverage_pct": round(code / 0x8000 * 100, 2),
        })
        (ANALYSIS / f"full_region{idx}.asm").write_text("\n".join(lines) + "\n", encoding="utf-8")
    return reports


def register_map(regions, entries, names):
    access = defaultdict(lambda: {"read": 0, "write": 0, "bits": Counter(), "funcs": set(), "consts": Counter()})
    bit_map = defaultdict(lambda: {"set": 0, "clear": 0, "test": 0, "funcs": set()})
    sfr_map = defaultdict(lambda: {"count": 0, "funcs": set()})
    with open(ANALYSIS / "register_access.csv", encoding="utf-8") as fh:
        for row in csv.DictReader(fh):
            region = int(row["region"])
            func = row["function"]
            space = row["space"]
            op = row["op"]
            target = row["target"]
            if space == "XDATA" and target:
                a = int(target, 16)
                rec = access[a]
                if op == "R":
                    rec["read"] += 1
                else:
                    rec["write"] += 1
                rec["funcs"].add((region, int(func, 16)))
            elif space == "BIT" and target:
                a = int(target, 16)
                bit_map[a]["funcs"].add((region, int(func, 16)))
            elif space == "SFR" and target:
                sfr_map[int(target, 16)]["count"] += 1
                sfr_map[int(target, 16)]["funcs"].add((region, int(func, 16)))

    for region in regions:
        pass

    for idx, region in enumerate(regions):
        for e in sorted(entries[idx]):
            f = ec.walk(region, e, entries[idx])
            ins = f["insns"]
            for i, (a, text, ln, kind) in enumerate(ins):
                if text == "MOVX @DPTR,A" and i >= 2:
                    if ins[i - 2][1].startswith("MOV DPTR,#") and ins[i - 1][1].startswith("MOV A,#"):
                        d = int(ins[i - 2][1].split("#")[1].rstrip("h"), 16)
                        v = int(ins[i - 1][1].split("#")[1].rstrip("h"), 16)
                        access[d]["consts"][v] += 1
                if text.startswith(("SETB", "CLR", "JB", "JNB", "JBC")) and len(text.split()) > 1:
                    try:
                        b = int(text.split()[1].split(",")[0].rstrip("h"), 16)
                    except ValueError:
                        continue
                    if b >= 0x80:
                        if text.startswith("SETB"):
                            bit_map[b]["set"] += 1
                        elif text.startswith("CLR"):
                            bit_map[b]["clear"] += 1
                        else:
                            bit_map[b]["test"] += 1
                        bit_map[b]["funcs"].add((idx, e))

    def fname(region, addr):
        return names.get((region, addr), f"0x{addr:04X}")

    lines = ["# 硬件寄存器还原", ""]
    lines.append("## XDATA 访问表")
    lines.append("")
    lines.append("| 地址 | 读 | 写 | 写入常量 | 访问函数 | 建议定义 |")
    lines.append("|---|---|---|---|---|---|")
    for addr in sorted(access):
        rec = access[addr]
        consts = ", ".join(f"0x{v:02X}" for v, c in rec["consts"].most_common(6))
        funcs = ", ".join(fname(r, a) for r, a in list(rec["funcs"])[:4])
        lines.append(f"| 0x{addr:04X} | {rec['read']} | {rec['write']} | {consts} | {funcs} | `X{addr:04X}` |")
    lines.append("")
    lines.append("## 位访问")
    lines.append("")
    lines.append("| 位地址 | SETB | CLR | 测试 | 访问函数 |")
    lines.append("|---|---|---|---|---|")
    for addr in sorted(bit_map):
        rec = bit_map[addr]
        funcs = ", ".join(fname(r, a) for r, a in list(rec["funcs"])[:4])
        lines.append(f"| 0x{addr:02X} | {rec['set']} | {rec['clear']} | {rec['test']} | {funcs} |")
    lines.append("")
    lines.append("## SFR 访问")
    lines.append("")
    lines.append("| SFR | 次数 | 标准名 |")
    lines.append("|---|---|---|")
    for addr in sorted(sfr_map):
        lines.append(f"| 0x{addr:02X} | {sfr_map[addr]['count']} | {ec.sfr(addr)} |")
    (ANALYSIS / "registers.md").write_text("\n".join(lines) + "\n", encoding="utf-8")

    hdr = ["#ifndef EC_REGS_H", "#define EC_REGS_H", ""]
    for addr in sorted(access):
        hdr.append(f"#define X{addr:04X} (*(volatile unsigned char __xdata *)0x{addr:04X})")
    hdr.append("")
    for addr in sorted(sfr_map):
        if addr >= 0x80:
            hdr.append(f"__sfr __at (0x{addr:02X}) SFR_{addr:02X};")
    hdr.append("")
    hdr.append("#endif")
    regs_path = ROOT / "include" / "generated" / "ec_regs.h"
    regs_path.parent.mkdir(parents=True, exist_ok=True)
    regs_path.write_text("\n".join(hdr) + "\n", encoding="utf-8")

    return {"xdata": len(access), "bits": len(bit_map), "sfr": len(sfr_map)}


def project_files(data, regions, maps):
    vectors = data[:0x2B]
    lines = [".module VECTORS", ".area VECTORS (ABS)", ".org 0x0000"]
    for i in range(0, len(vectors), 8):
        chunk = vectors[i:i + 8]
        lines.append(".db " + ",".join(f"0x{b:02X}" for b in chunk))
    (ROOT / "src" / "boot" / "vectors.a51").write_text("\n".join(lines) + "\n", encoding="utf-8")

    raw = data[0x79D8:0x79E4]
    lines = [".module F79D8", ".area F79D8 (ABS)", ".org 0x79D8",
             "mov a,r4", "movx @dptr,a", "inc dptr",
             "mov a,r5", "movx @dptr,a", "inc dptr",
             "mov a,r6", "movx @dptr,a", "inc dptr",
             "mov a,r7", "movx @dptr,a", "ret"]
    smoke = BUILD / "smoke"
    smoke.mkdir(parents=True, exist_ok=True)
    (smoke / "f_79d8.a51").write_text("\n".join(lines) + "\n", encoding="utf-8")

    c = ["#include \"ec_regs.h\"", "",
         "unsigned char ec_probe_0693(void)", "{", "    return X0693;", "}", "",
         "void ec_store_0693(unsigned char v)", "{", "    X0693 = v;", "}", ""]
    (smoke / "ec_demo.c").write_text("\n".join(c), encoding="utf-8")

    return {"vector_bytes": len(vectors), "function_bytes": len(raw)}


def run(cmd, cwd=None):
    p = subprocess.run(cmd, cwd=cwd, capture_output=True, text=True, env=env_with_path())
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
    if lo is None:
        return b"", 0
    out = bytearray(b"\xff" * (hi - lo + 1))
    for a, v in mem.items():
        out[a - lo] = v
    return bytes(out), lo


def build_and_diff(data):
    BUILD.mkdir(parents=True, exist_ok=True)
    sdcc = tool("sdcc")
    sdas = tool("sdas8051")
    sdld = tool("sdld")
    result = {"sdcc": str(sdcc), "steps": [], "diff": []}
    if not sdcc.exists():
        result["blocked"] = "sdcc not found"
        return result

    for src, rel in (("src/boot/vectors.a51", "vectors.rel"), ("build/smoke/f_79d8.a51", "f79d8.rel")):
        code, out = run([str(sdas), "-plosgff", str(BUILD / rel), str(ROOT / src)])
        result["steps"].append({"cmd": f"sdas8051 {src}", "code": code, "out": out.strip()[-400:]})
        if code != 0:
            return result

    code, out = run([str(sdld), "-i", "-b", "VECTORS=0x0000", "-b", "F79D8=0x79D8",
                     str(BUILD / "linked.ihx"), str(BUILD / "vectors.rel"), str(BUILD / "f79d8.rel")])
    result["steps"].append({"cmd": "sdld", "code": code, "out": out.strip()[-400:]})
    if code != 0:
        return result

    blob, base = ihx_to_bin(BUILD / "linked.ihx")
    (BUILD / "linked.bin").write_bytes(blob)
    result["linked_base"] = f"0x{base:04X}"
    result["linked_size"] = len(blob)

    for start, size, label in ((0x0000, 0x2B, "vectors"), (0x79D8, 12, "f_79d8")):
        off = start - base
        got = blob[off:off + size]
        want = data[start:start + size]
        mism = [i for i in range(size) if i >= len(got) or got[i] != want[i]]
        result["diff"].append({
            "range": f"0x{start:04X}-0x{start + size - 1:04X}",
            "label": label,
            "bytes": size,
            "identical": len(mism) == 0,
            "mismatches": len(mism),
            "first": [{"offset": f"0x{start + i:04X}",
                       "want": f"0x{want[i]:02X}",
                       "got": f"0x{got[i]:02X}"} for i in mism[:8]],
        })

    code, out = run([str(sdcc), "-mmcs51", "--model-small", "--std-c99", "-I", str(ROOT / "include" / "generated"),
                     "-c", str(BUILD / "smoke" / "ec_demo.c"), "-o", str(BUILD / "ec_demo.rel")])
    result["steps"].append({"cmd": "sdcc ec_demo.c", "code": code, "out": out.strip()[-400:]})
    return result


def verification_plan():
    lines = [
        "# 实机验证方案",
        "",
        "本机没有连接 EC 调试器或目标主板，实机步骤未执行。",
        "",
        "1. 在 Windows 上用 `tools/winFT/WinFT.exe` 先 `/B` 备份当前 EC flash，确认备份 SHA256 与 `firmware/eFlashBK.bin` 的差异。",
        "2. 修改后的镜像先用 `sdcc` 构建，比较 `build/linked.bin` 与原始镜像在改动函数范围内的字节。",
        "3. 用编程器或 EC 调试接口写入，保留原始镜像用于回滚。",
        "4. 上电后按功能验证：风扇转速曲线、充电电流、温度读数、ACPI EC 命令响应。",
        "5. 若设备无法启动，用备份镜像回写。",
        "",
        "风险：写错 bank 或破坏 OEM 信息块会导致整机不上电；OEM 信息块位于文件 0x8000-0x80FF，改动前先备份。",
    ]
    (ANALYSIS / "verification_plan.md").write_text("\n".join(lines) + "\n", encoding="utf-8")


def main():
    data, regions, entries, names = load()
    maps = instruction_maps(regions, entries)
    stats = full_listing(regions, maps)
    regs = register_map(regions, entries, names)
    proj = project_files(data, regions, maps)
    build = build_and_diff(data)
    verification_plan()

    report = {
        "disassembly": stats,
        "registers": regs,
        "project": proj,
        "build": build,
    }
    (ANALYSIS / "pipeline_report.json").write_text(json.dumps(report, indent=2), encoding="utf-8")

    lines = ["# 流水线执行报告", ""]
    lines.append("## 1-2 反汇编覆盖")
    lines.append("")
    lines.append("| 区域 | 代码字节 | 数据字节 | FF 字节 | 代码占比 |")
    lines.append("|---|---|---|---|---|")
    for s in stats:
        lines.append(f"| region {s['region']} | {s['code_bytes']} | {s['data_bytes']} | {s['ff_bytes']} | {s['coverage_pct']}% |")
    lines.append("")
    lines.append("## 3 寄存器")
    lines.append("")
    lines.append(f"- XDATA 地址 {regs['xdata']} 个，位地址 {regs['bits']} 个，SFR {regs['sfr']} 个")
    lines.append("- 明细: `build/analysis/registers.md`，C 头文件: `include/generated/ec_regs.h`")
    lines.append("")
    funcs = 0
    edges = 0
    with open(ANALYSIS / "functions.csv", encoding="utf-8") as fh:
        funcs = sum(1 for _ in fh) - 1
    mm = json.loads((ANALYSIS / "memory_map.json").read_text(encoding="utf-8"))
    edges = len(mm.get("call_edges", []))
    lines.append("## 4 函数与调用关系")
    lines.append("")
    lines.append(f"- 函数 {funcs} 个，跨区域调用边 {edges} 条")
    lines.append("- `build/analysis/functions.csv`、`build/analysis/callgraph/callgraph.dot`")
    lines.append("")
    lines.append("## 5 工程文件")
    lines.append("")
    lines.append(f"- `src/boot/vectors.a51` {proj['vector_bytes']} 字节向量表")
    lines.append(f"- `build/smoke/f_79d8.a51` 重建 0x79D8 函数 {proj['function_bytes']} 字节")
    lines.append("- `build/smoke/ec_demo.c` C 模块")
    lines.append("")
    lines.append("## 6 编译")
    lines.append("")
    for step in build.get("steps", []):
        lines.append(f"- `{step['cmd']}` exit={step['code']}")
    if build.get("blocked"):
        lines.append(f"- 阻塞: {build['blocked']}")
    lines.append("")
    lines.append("## 7 二进制差异")
    lines.append("")
    lines.append("| 范围 | 标签 | 字节 | 结果 |")
    lines.append("|---|---|---|---|")
    for d in build.get("diff", []):
        lines.append(f"| {d['range']} | {d['label']} | {d['bytes']} | {'一致' if d['identical'] else str(d['mismatches']) + ' 处不同'} |")
    lines.append("")
    lines.append("## 8 实机验证")
    lines.append("")
    lines.append("- 未执行：本机没有目标硬件。方案见 `build/analysis/verification_plan.md`。")
    (ANALYSIS / "pipeline_report.md").write_text("\n".join(lines) + "\n", encoding="utf-8")

    print(json.dumps({"disassembly": stats, "registers": regs, "build_steps": build.get("steps"),
                      "diff": build.get("diff"), "blocked": build.get("blocked")}, indent=2))


if __name__ == "__main__":
    main()
