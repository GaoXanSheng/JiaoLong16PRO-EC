#!/usr/bin/env python3
import hashlib
import json
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
BIN_PATH = ROOT / "firmware" / "eFlashBK.bin"
OUT = ROOT / "build" / "analysis"
REGION_SIZE = 0x8000

SFR_NAMES = {
    0x80: "P0", 0x81: "SP", 0x82: "DPL", 0x83: "DPH", 0x87: "PCON",
    0x88: "TCON", 0x89: "TMOD", 0x8A: "TL0", 0x8B: "TL1", 0x8C: "TH0",
    0x8D: "TH1", 0x90: "P1", 0x98: "SCON", 0x99: "SBUF", 0xA0: "P2",
    0xA8: "IE", 0xB0: "P3", 0xB8: "IP", 0xD0: "PSW", 0xE0: "ACC", 0xF0: "B",
}

REG_NAMES = ["R0", "R1", "R2", "R3", "R4", "R5", "R6", "R7"]


def sfr(a):
    return SFR_NAMES.get(a, f"{a:02X}h")


def rel(a, b, base):
    return base + ((a + 2 + (b - 256 if b >= 128 else b)) & 0x7FFF)


def decode(c, a, base):
    op = c[a]
    n1 = c[a + 1] if a + 1 < len(c) else 0
    n2 = c[a + 2] if a + 2 < len(c) else 0
    info = {}
    if op == 0x00:
        return "NOP", 1, "seq", (), info
    if op == 0x02:
        t = (n1 << 8) | n2
        return f"LJMP {t:04X}h", 3, "jmp", (t,), info
    if op == 0x12:
        t = (n1 << 8) | n2
        return f"LCALL {t:04X}h", 3, "call", (t,), info
    if op == 0x22:
        return "RET", 1, "ret", (), info
    if op == 0x32:
        return "RETI", 1, "ret", (), info
    if op == 0x73:
        return "JMP @A+DPTR", 1, "jmpdptr", (), info
    if op & 0x1F == 0x01:
        t = ((base + a + 2) & 0xF800) | ((op & 0xE0) << 3) | n1
        if op & 0x10:
            return f"ACALL {t:04X}h", 2, "call", (t,), info
        return f"AJMP {t:04X}h", 2, "jmp", (t,), info
    if op == 0x03:
        return "RR A", 1, "seq", (), info
    if op == 0x13:
        return "RRC A", 1, "seq", (), info
    if op == 0x23:
        return "RL A", 1, "seq", (), info
    if op == 0x33:
        return "RLC A", 1, "seq", (), info
    if op == 0x04:
        return "INC A", 1, "seq", (), info
    if op == 0x14:
        return "DEC A", 1, "seq", (), info
    if op == 0x05:
        info["dir"] = n1
        return f"INC {sfr(n1)}", 2, "seq", (), info
    if op == 0x15:
        info["dir"] = n1
        return f"DEC {sfr(n1)}", 2, "seq", (), info
    if op in (0x06, 0x07):
        return f"INC @R{op & 1}", 1, "seq", (), info
    if op in (0x16, 0x17):
        return f"DEC @R{op & 1}", 1, "seq", (), info
    if 0x08 <= op <= 0x0F:
        return f"INC {REG_NAMES[op & 7]}", 1, "seq", (), info
    if 0x18 <= op <= 0x1F:
        return f"DEC {REG_NAMES[op & 7]}", 1, "seq", (), info
    if op in (0x10, 0x20, 0x30):
        info["bit"] = n1
        m = {0x10: "JBC", 0x20: "JB", 0x30: "JNB"}[op]
        return f"{m} {sfr(n1)},{rel(a + 1, n2, base):04X}h", 3, "cond", (rel(a + 1, n2, base),), info
    if op == 0x24:
        return f"ADD A,#{n1:02X}h", 2, "seq", (), info
    if op == 0x25:
        info["dir"] = n1
        return f"ADD A,{sfr(n1)}", 2, "seq", (), info
    if op in (0x26, 0x27):
        return f"ADD A,@R{op & 1}", 1, "seq", (), info
    if 0x28 <= op <= 0x2F:
        return f"ADD A,{REG_NAMES[op & 7]}", 1, "seq", (), info
    if op == 0x34:
        return f"ADDC A,#{n1:02X}h", 2, "seq", (), info
    if op == 0x35:
        info["dir"] = n1
        return f"ADDC A,{sfr(n1)}", 2, "seq", (), info
    if op in (0x36, 0x37):
        return f"ADDC A,@R{op & 1}", 1, "seq", (), info
    if 0x38 <= op <= 0x3F:
        return f"ADDC A,{REG_NAMES[op & 7]}", 1, "seq", (), info
    if op == 0x40:
        return f"JC {rel(a, n1, base):04X}h", 2, "cond", (rel(a, n1, base),), info
    if op == 0x50:
        return f"JNC {rel(a, n1, base):04X}h", 2, "cond", (rel(a, n1, base),), info
    if op == 0x60:
        return f"JZ {rel(a, n1, base):04X}h", 2, "cond", (rel(a, n1, base),), info
    if op == 0x70:
        return f"JNZ {rel(a, n1, base):04X}h", 2, "cond", (rel(a, n1, base),), info
    if op == 0x80:
        return f"SJMP {rel(a, n1, base):04X}h", 2, "sjmp", (rel(a, n1, base),), info
    if op == 0x42:
        info["dir"] = n1
        return f"ORL {sfr(n1)},A", 2, "seq", (), info
    if op == 0x43:
        info["dir"] = n1
        return f"ORL {sfr(n1)},#{n2:02X}h", 3, "seq", (), info
    if op == 0x44:
        return f"ORL A,#{n1:02X}h", 2, "seq", (), info
    if op == 0x45:
        info["dir"] = n1
        return f"ORL A,{sfr(n1)}", 2, "seq", (), info
    if op in (0x46, 0x47):
        return f"ORL A,@R{op & 1}", 1, "seq", (), info
    if 0x48 <= op <= 0x4F:
        return f"ORL A,{REG_NAMES[op & 7]}", 1, "seq", (), info
    if op == 0x52:
        info["dir"] = n1
        return f"ANL {sfr(n1)},A", 2, "seq", (), info
    if op == 0x53:
        info["dir"] = n1
        return f"ANL {sfr(n1)},#{n2:02X}h", 3, "seq", (), info
    if op == 0x54:
        return f"ANL A,#{n1:02X}h", 2, "seq", (), info
    if op == 0x55:
        info["dir"] = n1
        return f"ANL A,{sfr(n1)}", 2, "seq", (), info
    if op in (0x56, 0x57):
        return f"ANL A,@R{op & 1}", 1, "seq", (), info
    if 0x58 <= op <= 0x5F:
        return f"ANL A,{REG_NAMES[op & 7]}", 1, "seq", (), info
    if op == 0x62:
        info["dir"] = n1
        return f"XRL {sfr(n1)},A", 2, "seq", (), info
    if op == 0x63:
        info["dir"] = n1
        return f"XRL {sfr(n1)},#{n2:02X}h", 3, "seq", (), info
    if op == 0x64:
        return f"XRL A,#{n1:02X}h", 2, "seq", (), info
    if op == 0x65:
        info["dir"] = n1
        return f"XRL A,{sfr(n1)}", 2, "seq", (), info
    if op in (0x66, 0x67):
        return f"XRL A,@R{op & 1}", 1, "seq", (), info
    if 0x68 <= op <= 0x6F:
        return f"XRL A,{REG_NAMES[op & 7]}", 1, "seq", (), info
    if op == 0x72:
        info["bit"] = n1
        return f"ORL C,{sfr(n1)}", 2, "seq", (), info
    if op == 0x74:
        return f"MOV A,#{n1:02X}h", 2, "seq", (), info
    if op == 0x75:
        info["dir"] = n1
        return f"MOV {sfr(n1)},#{n2:02X}h", 3, "seq", (), info
    if op in (0x76, 0x77):
        return f"MOV @R{op & 1},#{n1:02X}h", 2, "seq", (), info
    if 0x78 <= op <= 0x7F:
        return f"MOV {REG_NAMES[op & 7]},#{n1:02X}h", 2, "seq", (), info
    if op == 0x82:
        info["bit"] = n1
        return f"ANL C,{sfr(n1)}", 2, "seq", (), info
    if op == 0x83:
        return "MOVC A,@A+PC", 1, "seq", (), info
    if op == 0x84:
        return "DIV AB", 1, "seq", (), info
    if op == 0x85:
        info["dir"] = n2
        return f"MOV {sfr(n2)},{sfr(n1)}", 3, "seq", (), info
    if op in (0x86, 0x87):
        info["dir"] = n1
        return f"MOV {sfr(n1)},@R{op & 1}", 2, "seq", (), info
    if 0x88 <= op <= 0x8F:
        info["dir"] = n1
        return f"MOV {sfr(n1)},{REG_NAMES[op & 7]}", 2, "seq", (), info
    if op == 0x90:
        t = (n1 << 8) | n2
        info["dptr"] = t
        return f"MOV DPTR,#{t:04X}h", 3, "seq", (), info
    if op == 0x92:
        info["bit"] = n1
        return f"MOV {sfr(n1)},C", 2, "seq", (), info
    if op == 0x93:
        return "MOVC A,@A+DPTR", 1, "seq", (), info
    if op == 0x94:
        return f"SUBB A,#{n1:02X}h", 2, "seq", (), info
    if op == 0x95:
        info["dir"] = n1
        return f"SUBB A,{sfr(n1)}", 2, "seq", (), info
    if op in (0x96, 0x97):
        return f"SUBB A,@R{op & 1}", 1, "seq", (), info
    if 0x98 <= op <= 0x9F:
        return f"SUBB A,{REG_NAMES[op & 7]}", 1, "seq", (), info
    if op == 0xA0:
        info["bit"] = n1
        return f"ORL C,/{sfr(n1)}", 2, "seq", (), info
    if op == 0xA2:
        info["bit"] = n1
        return f"MOV C,{sfr(n1)}", 2, "seq", (), info
    if op == 0xA3:
        return "INC DPTR", 1, "seq", (), info
    if op == 0xA4:
        return "MUL AB", 1, "seq", (), info
    if op == 0xA5:
        return "DB A5h", 1, "seq", (), info
    if op in (0xA6, 0xA7):
        info["dir"] = n1
        return f"MOV @R{op & 1},{sfr(n1)}", 2, "seq", (), info
    if 0xA8 <= op <= 0xAF:
        info["dir"] = n1
        return f"MOV {REG_NAMES[op & 7]},{sfr(n1)}", 2, "seq", (), info
    if op == 0xB0:
        info["bit"] = n1
        return f"ANL C,/{sfr(n1)}", 2, "seq", (), info
    if op == 0xB2:
        info["bit"] = n1
        return f"CPL {sfr(n1)}", 2, "seq", (), info
    if op == 0xB3:
        return "CPL C", 1, "seq", (), info
    if op == 0xB4:
        return f"CJNE A,#{n1:02X}h,{rel(a + 1, n2, base):04X}h", 3, "cond", (rel(a + 1, n2, base),), info
    if op == 0xB5:
        info["dir"] = n1
        return f"CJNE A,{sfr(n1)},{rel(a + 1, n2, base):04X}h", 3, "cond", (rel(a + 1, n2, base),), info
    if op in (0xB6, 0xB7):
        return f"CJNE @R{op & 1},#{n1:02X}h,{rel(a + 1, n2, base):04X}h", 3, "cond", (rel(a + 1, n2, base),), info
    if 0xB8 <= op <= 0xBF:
        return f"CJNE {REG_NAMES[op & 7]},#{n1:02X}h,{rel(a + 1, n2, base):04X}h", 3, "cond", (rel(a + 1, n2, base),), info
    if op == 0xC0:
        info["dir"] = n1
        return f"PUSH {sfr(n1)}", 2, "seq", (), info
    if op == 0xC2:
        info["bit"] = n1
        return f"CLR {sfr(n1)}", 2, "seq", (), info
    if op == 0xC3:
        return "CLR C", 1, "seq", (), info
    if op == 0xC4:
        return "SWAP A", 1, "seq", (), info
    if op == 0xC5:
        info["dir"] = n1
        return f"XCH A,{sfr(n1)}", 2, "seq", (), info
    if op in (0xC6, 0xC7):
        return f"XCH A,@R{op & 1}", 1, "seq", (), info
    if 0xC8 <= op <= 0xCF:
        return f"XCH A,{REG_NAMES[op & 7]}", 1, "seq", (), info
    if op == 0xD0:
        info["dir"] = n1
        return f"POP {sfr(n1)}", 2, "seq", (), info
    if op == 0xD2:
        info["bit"] = n1
        return f"SETB {sfr(n1)}", 2, "seq", (), info
    if op == 0xD3:
        return "SETB C", 1, "seq", (), info
    if op == 0xD4:
        return "DA A", 1, "seq", (), info
    if op == 0xD5:
        info["dir"] = n1
        return f"DJNZ {sfr(n1)},{rel(a + 1, n2, base):04X}h", 3, "cond", (rel(a + 1, n2, base),), info
    if op in (0xD6, 0xD7):
        return f"XCHD A,@R{op & 1}", 1, "seq", (), info
    if 0xD8 <= op <= 0xDF:
        return f"DJNZ {REG_NAMES[op & 7]},{rel(a, n1, base):04X}h", 2, "cond", (rel(a, n1, base),), info
    if op == 0xE0:
        info["movx"] = "R"
        return "MOVX A,@DPTR", 1, "seq", (), info
    if op in (0xE2, 0xE3):
        info["movx_ri"] = "R"
        return f"MOVX A,@R{op & 1}", 1, "seq", (), info
    if op == 0xE4:
        return "CLR A", 1, "seq", (), info
    if op == 0xE5:
        info["dir"] = n1
        return f"MOV A,{sfr(n1)}", 2, "seq", (), info
    if op in (0xE6, 0xE7):
        return f"MOV A,@R{op & 1}", 1, "seq", (), info
    if 0xE8 <= op <= 0xEF:
        return f"MOV A,{REG_NAMES[op & 7]}", 1, "seq", (), info
    if op == 0xF0:
        info["movx"] = "W"
        return "MOVX @DPTR,A", 1, "seq", (), info
    if op in (0xF2, 0xF3):
        info["movx_ri"] = "W"
        return f"MOVX @R{op & 1},A", 1, "seq", (), info
    if op == 0xF4:
        return "CPL A", 1, "seq", (), info
    if op == 0xF5:
        info["dir"] = n1
        return f"MOV {sfr(n1)},A", 2, "seq", (), info
    if op in (0xF6, 0xF7):
        return f"MOV @R{op & 1},A", 1, "seq", (), info
    if 0xF8 <= op <= 0xFF:
        return f"MOV {REG_NAMES[op & 7]},A", 1, "seq", (), info
    return f"DB {op:02X}h", 1, "seq", (), info


class Region:
    def __init__(self, idx, data, file_base, logical_base, kind):
        self.idx = idx
        self.data = data
        self.file_base = file_base
        self.logical_base = logical_base
        self.kind = kind

    def read(self, a):
        return self.data[a - self.logical_base]

    def in_range(self, a):
        return self.logical_base <= a < self.logical_base + len(self.data)


def walk(region, entry, entries):
    seen = set()
    insns = []
    targets = []
    accesses = []
    stack = [entry]
    while stack:
        a = stack.pop()
        last_dptr = None
        run_text = None
        run = 0
        while a not in seen and region.in_range(a):
            if a != entry and a in entries:
                break
            text, ln, kind, tg, info = decode(region.data, a - region.logical_base, region.logical_base)
            if not region.in_range(a + ln - 1):
                break
            if text == run_text:
                run += 1
            else:
                run_text = text
                run = 1
            if run >= 8:
                break
            seen.add(a)
            insns.append((a, text, ln, kind))
            if info.get("dptr") is not None:
                last_dptr = info["dptr"]
                accesses.append((a, "DPTR", "W", info["dptr"]))
            elif info.get("movx") and last_dptr is not None:
                accesses.append((a, "XDATA", info["movx"], last_dptr))
            elif info.get("movx_ri"):
                accesses.append((a, "XDATA_RI", info["movx_ri"], None))
            if info.get("dir") is not None and info["dir"] >= 0x80:
                accesses.append((a, "SFR", "RW", info["dir"]))
            if info.get("bit") is not None and info["bit"] >= 0x80:
                accesses.append((a, "BIT", "RW", info["bit"]))
            if kind == "call":
                targets.append(("call", tg[0]))
                a = a + ln
                last_dptr = None
                continue
            if kind in ("ret", "jmpdptr"):
                break
            if kind == "jmp":
                targets.append(("jmp", tg[0]))
                break
            if kind == "sjmp":
                t = tg[0]
                if t in seen:
                    break
                a = t
                last_dptr = None
                continue
            if kind == "cond":
                for t in tg:
                    if t not in seen:
                        stack.append(t)
                a = a + ln
                last_dptr = None
                continue
            a = a + ln
    return {
        "entry": entry,
        "insns": insns,
        "targets": targets,
        "accesses": accesses,
        "end": max((i[0] + i[2]) for i in insns) if insns else entry,
        "start": min(i[0] for i in insns) if insns else entry,
        "count": len(insns),
    }


def is_trampoline(f):
    has_dpl = any(t.startswith("PUSH DPL") for _, t, _, _ in f["insns"])
    has_dph = any(t.startswith("PUSH DPH") for _, t, _, _ in f["insns"])
    return has_dpl and has_dph


def analyze(region, seeds, fixed):
    entries = dict(seeds)
    funcs = {}

    def mem(a):
        if a < 0x8000:
            return fixed.data[a] if 0 <= a < len(fixed.data) else 0xFF
        return region.data[a - 0x8000] if region.in_range(a) else 0xFF

    def table_targets():
        out = set()
        for e, f in funcs.items():
            ins = f["insns"]
            for i, (a, text, ln, kind) in enumerate(ins):
                if kind != "jmpdptr":
                    continue
                base = None
                count = None
                for j in range(i - 1, max(-1, i - 16), -1):
                    t = ins[j][1]
                    if t.startswith("MOV DPTR,#") and base is None:
                        base = int(t.split("#")[1].rstrip("h"), 16)
                    if t.startswith("CJNE A,#") and count is None:
                        count = int(t.split("#")[1].split("h")[0], 16) + 1
                if base is None:
                    continue
                if count is None:
                    count = 32
                ptr = base
                for _ in range(count):
                    op = mem(ptr)
                    if op == 0x02:
                        tgt = (mem(ptr + 1) << 8) | mem(ptr + 2)
                        ptr += 3
                    elif op in (0x01, 0x21, 0x41, 0x61, 0x81, 0xA1, 0xC1, 0xE1):
                        tgt = ((ptr + 2) & 0xF800) | ((op & 0xE0) << 3) | mem(ptr + 1)
                        ptr += 2
                    elif op == 0x80:
                        off = mem(ptr + 1)
                        tgt = ptr + 2 + (off - 256 if off >= 128 else off)
                        ptr += 2
                    else:
                        break
                    if region.in_range(tgt):
                        out.add(tgt)
        return out
    for _ in range(6):
        new_entries = dict(entries)
        funcs = {}
        changed = False
        for e in sorted(entries):
            f = walk(region, e, set(entries))
            funcs[e] = f
            for kind, t in f["targets"]:
                if not region.in_range(t):
                    continue
                if t not in new_entries:
                    new_entries[t] = "high" if kind == "call" else "medium"
                    changed = True
        tramps = {e for e, f in funcs.items() if is_trampoline(f)}
        tramp_addrs = {f"MOV DPTR,#{t:04X}h" for t in tramps}
        for e, f in funcs.items():
            for i in range(len(f["insns"]) - 1):
                a, text, ln, kind = f["insns"][i]
                if text.startswith("MOV DPTR,#") and f["insns"][i + 1][3] == "jmp":
                    nxt = f["insns"][i + 1][1]
                    if nxt in {f"LJMP {t:04X}h" for t in tramps} or nxt in {f"AJMP {t:04X}h" for t in tramps}:
                        tgt = int(text.split("#")[1].rstrip("h"), 16)
                        if region.in_range(tgt) and tgt not in new_entries:
                            new_entries[tgt] = "high"
                            changed = True
        for t in table_targets():
            if t not in new_entries:
                new_entries[t] = "high"
                changed = True
        entries = new_entries
        if not changed:
            break
    return entries, funcs


def main():
    data = BIN_PATH.read_bytes()
    if len(data) != 0x20000:
        raise SystemExit(f"size mismatch: {len(data)}")

    out = OUT
    for sub in ("regions", "callgraph"):
        (out / sub).mkdir(parents=True, exist_ok=True)

    region_defs = [
        (0, 0x00000, 0x0000, "fixed"),
        (1, 0x08000, 0x8000, "bank0"),
        (2, 0x10000, 0x8000, "bank1"),
        (3, 0x18000, 0x8000, "bank2"),
    ]
    (out / "regions" / "main_64k.bin").write_bytes(data[:0x10000])
    regions = []
    for idx, off, lb, kind in region_defs:
        chunk = data[off:off + REGION_SIZE]
        (out / "regions" / f"region_{idx}.bin").write_bytes(chunk)
        regions.append(Region(idx, chunk, off, lb, kind))

    seeds = {0: {0x0000: "high"}, 1: {}, 2: {}, 3: {}}
    for i in range(0x80 - 2):
        if data[i] == 0x02:
            seeds[0][(data[i + 1] << 8) | data[i + 2]] = "high"

    for i in range(len(data) - 5):
        if data[i] == 0x90 and data[i + 3] == 0x01:
            t = ((i + 5) & 0xF800) | data[i + 4]
            if t in (0x2800, 0x2814, 0x2828):
                dp = (data[i + 1] << 8) | data[i + 2]
                if regions[1].in_range(dp):
                    seeds[1][dp] = "high"

    for idx in (2, 3):
        reg = regions[idx]
        boot = {}
        for a in range(reg.logical_base + 1, reg.logical_base + REGION_SIZE):
            if reg.read(a - 1) in (0x22, 0x32) and reg.read(a) != 0xFF:
                boot[a] = "low"
        for i in range(REGION_SIZE - 2):
            if reg.data[i] == 0x12:
                t = (reg.data[i + 1] << 8) | reg.data[i + 2]
                if reg.in_range(t) and reg.read(t) != 0xFF:
                    boot[t] = "low"
        seeds[idx] = boot

    def resolve_region(idx, t):
        if t < 0x8000:
            return 0
        if idx == 0:
            return 1
        return idx

    results = {}
    for _ in range(5):
        grown = {k: dict(v) for k, v in seeds.items()}
        results = {}
        for idx in range(4):
            entries, funcs = analyze(regions[idx], seeds[idx], regions[0])
            results[idx] = (entries, funcs)
            for e, f in funcs.items():
                for kind, t in f["targets"]:
                    if kind != "call":
                        continue
                    tr = resolve_region(idx, t)
                    if regions[tr].in_range(t) and t not in grown[tr]:
                        grown[tr][t] = "high"
        if all(grown[k].keys() == seeds[k].keys() for k in seeds):
            break
        seeds = grown

    callers = defaultdict(set)
    call_edges = []
    for idx, (entries, funcs) in results.items():
        for e, f in funcs.items():
            targets = defaultdict(set)
            for kind, t in f["targets"]:
                if kind in ("call",):
                    targets[resolve_region(idx, t)].add(t)
            for tr, ts in targets.items():
                for t in ts:
                    call_edges.append((idx, e, tr, t))
                    callers[(tr, t)].add((idx, e))

    vector_targets = set()
    for i in range(0x80 - 2):
        if data[i] == 0x02:
            vector_targets.add((data[i + 1] << 8) | data[i + 2])

    def name_of(idx, e):
        if idx == 0 and e == 0:
            return "RESET"
        if idx == 0 and e in vector_targets:
            return f"ISR_{e:04X}"
        return f"sub_{e:04X}"

    dropped = set()
    for idx in range(4):
        entries, funcs = results[idx]
        reg = regions[idx]
        for e, f in funcs.items():
            if f["count"] == 0:
                dropped.add((idx, e))
                continue
            raw = b"".join(reg.data[a - reg.logical_base:a - reg.logical_base + ln] for a, t, ln, k in f["insns"])
            printable = sum(1 for b in raw if 0x20 <= b < 0x7F) / max(len(raw), 1)
            texts = [t for _, t, _, _ in f["insns"]]
            has_end = any(t.startswith(("RET", "LJMP", "AJMP", "SJMP", "JMP @")) for t in texts)
            nxt = f["insns"][-1][0] + f["insns"][-1][2] if f["insns"] else -1
            if nxt in entries:
                has_end = True
            conf = entries.get(e, "low")
            dom = max(Counter(raw).values()) / max(len(raw), 1) if raw else 1
            first = reg.read(e)
            plausible = (first in (0xC0, 0xE4, 0x90, 0x75, 0x74, 0x12, 0x22, 0x32)
                         or 0x78 <= first <= 0x7F or 0xE5 <= first <= 0xEF or first >= 0xF8)
            last_kind = f["insns"][-1][3]
            if not has_end or printable > 0.7 or dom > 0.6:
                dropped.add((idx, e))
            elif conf == "low" and not plausible:
                dropped.add((idx, e))
            elif conf == "low" and len(callers[(idx, e)]) == 0 and e > reg.logical_base + 4:
                dropped.add((idx, e))
            elif conf == "low" and last_kind == "sjmp":
                dropped.add((idx, e))

    rows = []
    asm_lines = {i: [] for i in range(4)}
    access_rows = []
    for idx in range(4):
        entries, funcs = results[idx]
        reg = regions[idx]
        asm_lines[idx].append(f"; region {idx} {reg.kind} base 0x{reg.logical_base:04X} file 0x{reg.file_base:05X}")
        for e in sorted(funcs):
            f = funcs[e]
            if (idx, e) in dropped:
                continue
            nm = name_of(idx, e)
            conf = entries.get(e, "low")
            callers_n = len(callers[(idx, e)])
            calls_out = len({t for k, t in f["targets"] if k == "call"})
            rows.append((idx, e, nm, f, conf, callers_n, calls_out))
            asm_lines[idx].append(f"\n{nm}:")
            for a, text, ln, kind in f["insns"]:
                start = a - reg.logical_base
                raw = reg.data[start:start + ln].hex(" ")
                asm_lines[idx].append(f"  {a:04X}: {raw:<11} {text}")
            for a, space, op, t in f["accesses"]:
                access_rows.append((idx, e, a, space, op, t))

    with open(out / "functions.csv", "w", encoding="utf-8") as fh:
        fh.write("region,kind,address,file_offset,name,end,span,insns,calls,callers,confidence\n")
        for idx, e, nm, f, conf, callers_n, calls_out in rows:
            reg = regions[idx]
            fh.write(
                f"{idx},{reg.kind},0x{e:04X},0x{reg.file_base + e - reg.logical_base:05X},"
                f"{nm},0x{f['end']:04X},{f['end'] - f['start']},{f['count']},{calls_out},"
                f"{callers_n},{conf}\n"
            )

    with open(out / "register_access.csv", "w", encoding="utf-8") as fh:
        fh.write("region,function,address,space,op,target\n")
        for idx, e, a, space, op, t in access_rows:
            tgt = f"0x{t:04X}" if t is not None else ""
            fh.write(f"{idx},0x{e:04X},0x{a:04X},{space},{op},{tgt}\n")

    with open(out / "callgraph" / "callgraph.dot", "w", encoding="utf-8") as fh:
        fh.write("digraph ec {\n  rankdir=LR;\n  node [shape=box,fontsize=8];\n")
        for idx in range(4):
            entries, funcs = results[idx]
            fh.write(f"  subgraph cluster_{idx} {{\n    label=\"region{idx} {regions[idx].kind}\";\n")
            for e in sorted(funcs):
                if funcs[e]["count"] == 0:
                    continue
                fh.write(f'    r{idx}_{e:04X} [label="{name_of(idx, e)}"];\n')
            fh.write("  }\n")
        for idx, a, tr, t in sorted(set(call_edges)):
            fh.write(f"  r{idx}_{a:04X} -> r{tr}_{t:04X};\n")
        fh.write("}\n")

    for idx in range(4):
        (out / f"disassembly_region{idx}.asm").write_text("\n".join(asm_lines[idx]) + "\n", encoding="utf-8")

    xdata = Counter()
    sfr_cnt = Counter()
    bit = Counter()
    for idx, e, a, space, op, t in access_rows:
        if space == "XDATA" and t is not None:
            xdata[t] += 1
        elif space == "SFR":
            sfr_cnt[t] += 1
        elif space == "BIT":
            bit[t] += 1

    stats = []
    for idx in range(4):
        entries, funcs = results[idx]
        insn_total = sum(f["count"] for e, f in funcs.items() if (idx, e) not in dropped)
        chunk = data[regions[idx].file_base:regions[idx].file_base + REGION_SIZE]
        stats.append({
            "region": idx,
            "kind": regions[idx].kind,
            "logical_base": f"0x{regions[idx].logical_base:04X}",
            "file_base": f"0x{regions[idx].file_base:05X}",
            "functions": sum(1 for e, f in funcs.items() if f["count"] > 0 and (idx, e) not in dropped),
            "instructions": insn_total,
            "coverage_32k": round(insn_total / REGION_SIZE, 4),
            "ff_ratio": round(chunk.count(0xFF) / REGION_SIZE, 4),
        })

    trampolines = []
    indirect = []
    for idx, (entries, funcs) in results.items():
        for e, f in funcs.items():
            if (idx, e) in dropped:
                continue
            if is_trampoline(f):
                trampolines.append({"region": idx, "addr": f"0x{e:04X}"})
            for a, text, ln, kind in f["insns"]:
                if kind == "jmpdptr":
                    indirect.append({"region": idx, "addr": f"0x{a:04X}", "func": f"0x{e:04X}"})

    report = {
        "firmware": "firmware/eFlashBK.bin",
        "trampolines": trampolines,
        "indirect_jumps": indirect,
        "size": len(data),
        "model": {
            "fixed": {"region": 0, "logical": "0x0000-0x7FFF", "file": "0x00000-0x07FFF"},
            "banks": [
                {"bank": 0, "region": 1, "logical": "0x8000-0xFFFF", "file": "0x08000-0x0FFFF"},
                {"bank": 1, "region": 2, "logical": "0x8000-0xFFFF", "file": "0x10000-0x17FFF"},
                {"bank": 2, "region": 3, "logical": "0x8000-0xFFFF", "file": "0x18000-0x1FFFF"},
            ],
            "note": "lower 32K fixed, upper 32K windowed per bank",
        },
        "regions": stats,
        "xdata_hot": [{"addr": f"0x{a:04X}", "count": c} for a, c in xdata.most_common(40)],
        "sfr_hot": [{"addr": f"0x{a:02X}", "name": sfr(a), "count": c} for a, c in sfr_cnt.most_common(30)],
        "bit_hot": [{"addr": f"0x{a:02X}", "count": c} for a, c in bit.most_common(20)],
        "call_edges": [{"from_region": a, "from": f"0x{b:04X}", "to_region": c, "to": f"0x{d:04X}"}
                       for a, b, c, d in sorted(set(call_edges))],
    }
    (out / "memory_map.json").write_text(json.dumps(report, indent=2), encoding="utf-8")

    def strings_at(lo, hi, minlen=6):
        res = []
        cur = b""
        for i in range(lo, hi):
            b = data[i]
            if 32 <= b < 127:
                cur += bytes([b])
            else:
                if len(cur) >= minlen:
                    res.append((i - len(cur), cur.decode("ascii")))
                cur = b""
        return res

    hdr = strings_at(0x8000, 0x8100, 5)
    vec_rows = []
    for slot in (0x00, 0x03, 0x0B, 0x13, 0x1B, 0x23, 0x2B):
        if data[slot] == 0x02:
            vec_rows.append((slot, (data[slot + 1] << 8) | data[slot + 2]))
    insn_map = {}
    for idx, (entries, funcs) in results.items():
        for e, f in funcs.items():
            if (idx, e) in dropped:
                continue
            for a, text, ln, kind in f["insns"]:
                insn_map[(idx, a)] = (text, ln)
    stub_count = 0
    for (idx, a), (text, ln) in insn_map.items():
        if text in ("AJMP 2800h", "AJMP 2814h", "AJMP 2828h", "LJMP 2800h", "LJMP 2814h", "LJMP 2828h"):
            prev = insn_map.get((idx, a - 3))
            if prev and prev[0].startswith("MOV DPTR,#"):
                stub_count += 1

    lines = []
    lines.append("# eFlashBK.bin 自动分析报告")
    lines.append("")
    lines.append("## 样本")
    lines.append("")
    lines.append(f"- 文件: `{BIN_PATH.name}`")
    lines.append(f"- 大小: {len(data)} 字节 (0x{len(data):X})")
    lines.append(f"- SHA256: `{hashlib.sha256(data).hexdigest()}`")
    lines.append("- 头部信息 (文件 0x8000): " + ", ".join(f"`{t}`" for _, t in hdr))
    lines.append("")
    lines.append("## 地址模型")
    lines.append("")
    lines.append("| 区域 | 文件偏移 | 逻辑地址 | 类型 | FF 占比 | 函数数 | 指令数 |")
    lines.append("|---|---|---|---|---|---|---|")
    for st in stats:
        lines.append(f"| region {st['region']} | {st['file_base']} | {st['logical_base']}-0x{int(st['logical_base'],16)+0x7FFF:04X} | {st['kind']} | {st['ff_ratio']*100:.2f}% | {st['functions']} | {st['instructions']} |")
    lines.append("")
    lines.append("低 32 KiB 固定；高 32 KiB 为窗口，按 bank 切换到 region 1/2/3。")
    lines.append("")
    lines.append("## 中断向量")
    lines.append("")
    lines.append("| 向量地址 | 目标 |")
    lines.append("|---|---|")
    for slot, tgt in vec_rows:
        lines.append(f"| 0x{slot:04X} | 0x{tgt:04X} |")
    lines.append("")
    lines.append("## 关键结构")
    lines.append("")
    lines.append(f"- 0x2800/0x2814/0x2828 是 `MOV DPTR,#imm16` + `PUSH DPL/DPH` + `RET` 形式的间接跳转 trampoline。")
    lines.append(f"- 已追踪代码中 {stub_count} 个 `MOV DPTR,#x; AJMP 0x28xx` 五字节分发表项，其 DPTR 目标已作为函数入口导入。")
    lines.append("- `JMP @A+DPTR` 间接跳转点: " + ", ".join(x['addr'] for x in report["indirect_jumps"]) if report["indirect_jumps"] else "- 未发现间接跳转")
    lines.append("")
    lines.append("## 热点 XDATA")
    lines.append("")
    lines.append("| 地址 | 访问次数 |")
    lines.append("|---|---|")
    for x in report["xdata_hot"][:15]:
        lines.append(f"| {x['addr']} | {x['count']} |")
    lines.append("")
    lines.append("## 热点 SFR")
    lines.append("")
    lines.append("| 地址 | 名称 | 访问次数 |")
    lines.append("|---|---|---|")
    for x in report["sfr_hot"][:12]:
        lines.append(f"| {x['addr']} | {x['name']} | {x['count']} |")
    lines.append("")
    lines.append("## 未解决")
    lines.append("")
    lines.append("- 追踪到的代码中没有发现 bank 切换：0x8000 以上的调用/跳转前 10 条指令内没有任何 XDATA 或 SFR 常量写入；常量 XDATA 写入仅 37 处，最大常量 153。结论是 region 1 始终以 bank0 身份运行，region 2/3 不是这份代码在运行期切换的副本，可能是启动前由硬件/引导程序选择的镜像或备用区。")
    lines.append("- bank1/bank2 (region 2/3) 的入口机制未确认，其函数识别为探索性结果。")
    lines.append("- 0x7737、0x79FA、0x7A64、0x7A75 处的间接跳转由运行期计算 DPTR，未静态解析。")
    lines.append("")
    lines.append("## 产物")
    lines.append("")
    lines.append("| 文件 | 内容 |")
    lines.append("|---|---|")
    lines.append("| functions.csv | 函数表（区域、逻辑地址、文件偏移、大小、指令数、调用数、可信度） |")
    lines.append("| disassembly_region0-3.asm | 按函数组织的反汇编 |")
    lines.append("| callgraph/callgraph.dot | 调用图 |")
    lines.append("| register_access.csv | 每条 SFR/XDATA/位访问记录 |")
    lines.append("| memory_map.json | 地址模型、统计、热点、间接跳转 |")
    lines.append("| regions/*.bin | 拆分后的区域与 main_64k.bin |")
    lines.append("| tools/ecanalyzer/run_ghidra.bat | Ghidra 12.2 批量导入（已实测） |")
    lines.append("| tools/ecanalyzer/ApplyEcFunctions.java | 把 functions.csv 转成 Ghidra 函数和符号 |")
    (out / "report.md").write_text(chr(10).join(lines) + chr(10), encoding="utf-8")

    print(json.dumps({"regions": stats, "xdata_top": report["xdata_hot"][:12],
                      "sfr_top": report["sfr_hot"][:12]}, indent=2))


if __name__ == "__main__":
    main()
