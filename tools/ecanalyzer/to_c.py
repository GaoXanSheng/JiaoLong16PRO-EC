#!/usr/bin/env python3
import csv
import importlib.util
import re
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
OUT = ROOT / "port" / "generated"

spec = importlib.util.spec_from_file_location("ecanalyzer", ROOT / "tools" / "ecanalyzer" / "ecanalyzer.py")
ec = importlib.util.module_from_spec(spec)
spec.loader.exec_module(ec)

NAME2ADDR = {v: k for k, v in ec.SFR_NAMES.items()}
NAME2ADDR["A"] = 0xE0
SPECIAL = {
    0xE0: "A",
    0xF0: "B",
    0xD0: "PSW",
    0x82: "DPL",
    0x83: "DPH",
    0x81: "SP",
}

SUPPORTED = True
CUR_KIND = "fixed"
CUR_ADDRS = set()


def fname(addr, kind=None):
    kind = kind or CUR_KIND
    if kind == "bank1":
        return f"g_{addr:04X}"
    if kind == "bank2":
        return f"h_{addr:04X}"
    return f"f_{addr:04X}"


def dir_addr(op):
    op = op.strip()
    if op.endswith("h"):
        return int(op[:-1], 16)
    if op in NAME2ADDR:
        return NAME2ADDR[op]
    return None


def dir_expr(addr):
    if addr == 0xE0:
        return "A"
    if addr == 0xF0:
        return "B"
    if addr == 0xD0:
        return "PSW"
    if addr == 0x82:
        return "DPL"
    if addr == 0x83:
        return "DPH"
    if addr == 0x81:
        return "SP"
    if addr < 0x08:
        return f"RB({addr})"
    if addr < 0x80:
        return f"DIR(0x{addr:02X})"
    return f"SFR_{addr:02X}"


def bit_get(b):
    if b < 0x80:
        return f"BIT_RAM(0x{b:02X})"
    if 0xE0 <= b <= 0xE7:
        return f"((A >> {b - 0xE0}) & 1)"
    if 0xF0 <= b <= 0xF7:
        return f"((B >> {b - 0xF0}) & 1)"
    if b == 0xD7:
        return "C"
    if 0xD0 <= b <= 0xD7:
        return f"((PSW >> {b - 0xD0}) & 1)"
    base = b & 0xF8
    return f"((SFR_{base:02X} >> {b & 7}) & 1)"


def bit_set(b, val):
    if b < 0x80:
        return f"BIT_SET(0x{b:02X}, {val});"
    if 0xE0 <= b <= 0xE7:
        sh = b - 0xE0
        return f"A = (A & ~(1 << {sh})) | ((({val}) & 1) << {sh});"
    if 0xF0 <= b <= 0xF7:
        sh = b - 0xF0
        return f"B = (B & ~(1 << {sh})) | ((({val}) & 1) << {sh});"
    if b == 0xD7:
        return f"C = ({val}) & 1;"
    if 0xD0 <= b <= 0xD7:
        sh = b - 0xD0
        return f"PSW = (PSW & ~(1 << {sh})) | ((({val}) & 1) << {sh});"
    base = b & 0xF8
    sh = b & 7
    return f"SFR_{base:02X} = (SFR_{base:02X} & ~(1 << {sh})) | ((({val}) & 1) << {sh});"


def target(text):
    m = re.search(r"([0-9A-F]{4})h$", text)
    return int(m.group(1), 16) if m else None


def op2(text):
    parts = text.split(" ", 1)[1]
    return [p.strip() for p in parts.split(",")]


def emit(region, addr, text, ln, out):
    global SUPPORTED
    if text in ("NOP",):
        return
    if text in ("RET", "RETI"):
        out.append("return;")
        return
    if text == "JMP @A+DPTR":
        jump = {"fixed": "ec_jump", "bank0": "ec_jump", "bank1": "ec_jump_bank1", "bank2": "ec_jump_bank2"}[CUR_KIND]
        out.append(f"{jump}((unsigned int)DPTR + A);")
        out.append("return;")
        return
    if text in ("MOVC A,@A+PC",):
        out.append(f"A = CD(0x{(addr + ln):04X} + A);")
        return
    if text.startswith("PUSH "):
        out.append(f"STACK[++SP] = {dir_expr(dir_addr(text.split()[1]))};")
        return
    if text.startswith("POP "):
        out.append(f"{dir_expr(dir_addr(text.split()[1]))} = STACK[SP--];")
        return
    if text.startswith("DB "):
        out.append("EC_UNSUPPORTED();")
        return
    m = re.match(r"^(AJMP|ACALL|LJMP|LCALL) ([0-9A-F]{4})h$", text)
    if m:
        t = int(m.group(2), 16)
        if m.group(1) in ("AJMP", "LJMP"):
            out.append(f"{fname(t)}();")
            out.append("return;")
        else:
            out.append(f"{fname(t)}();")
        return
    m = re.match(r"^(JZ|JNZ|JC|JNC) ([0-9A-F]{4})h$", text)
    if m:
        t = int(m.group(2), 16)
        cond = {"JZ": "A == 0", "JNZ": "A != 0", "JC": "C != 0", "JNC": "C == 0"}[m.group(1)]
        if t in CUR_ADDRS:
            out.append(f"if ({cond}) goto L_{t:04X};")
        else:
            out.append(f"if ({cond}) {{ {fname(t)}(); return; }}")
        return
    m = re.match(r"^(JBC|JB|JNB) (.+),([0-9A-F]{4})h$", text)
    if m:
        b = dir_addr(m.group(2))
        t = int(m.group(3), 16)
        g = bit_get(b)
        if m.group(1) == "JB":
            out.append(f"if ({g}) goto L_{t:04X};" if t in CUR_ADDRS else f"if ({g}) {{ {fname(t)}(); return; }}")
        elif m.group(1) == "JNB":
            out.append(f"if (!{g}) goto L_{t:04X};" if t in CUR_ADDRS else f"if (!{g}) {{ {fname(t)}(); return; }}")
        else:
            out.append(f"if ({g}) {{ {bit_set(b, '0')} goto L_{t:04X}; }}" if t in CUR_ADDRS
                       else f"if ({g}) {{ {bit_set(b, '0')} {fname(t)}(); return; }}")
        return
    m = re.match(r"^SJMP ([0-9A-F]{4})h$", text)
    if m:
        t = int(m.group(1), 16)
        if t in CUR_ADDRS:
            out.append(f"goto L_{t:04X};")
        else:
            out.append(f"{fname(t)}();")
            out.append("return;")
        return
    m = re.match(r"^(CJNE) (.+),(.+),([0-9A-F]{4})h$", text)
    if m:
        left, right, t = m.group(2), m.group(3), int(m.group(4), 16)
        lv = dir_expr(dir_addr(left)) if left[0].isdigit() or left.endswith("h") else left
        if left.startswith("@"):
            lv = f"XD(((unsigned int)SFR_A0 << 8) | {left.upper()[2:]})"
        if left.upper().startswith("R") and len(left) == 2:
            lv = left.upper()
        if left == "A":
            lv = "A"
        rv = right
        if right.endswith("h"):
            rv = "0x" + right.lstrip("#")[:-1]
        if t in CUR_ADDRS:
            out.append(f"if ({lv} != {rv}) {{ C = ({lv} < {rv}); goto L_{t:04X}; }}")
        else:
            out.append(f"if ({lv} != {rv}) {{ C = ({lv} < {rv}); {fname(t)}(); return; }}")
        return
    m = re.match(r"^DJNZ (.+),([0-9A-F]{4})h$", text)
    if m:
        op, t = m.group(1), int(m.group(2), 16)
        if op.upper().startswith("R") and len(op) == 2:
            var = op.upper()
        else:
            var = dir_expr(dir_addr(op))
        if t in CUR_ADDRS:
            out.append(f"if (--{var}) goto L_{t:04X};")
        else:
            out.append(f"if (--{var}) {{ {fname(t)}(); return; }}")
        return
    if text.startswith("MOV DPTR,#"):
        out.append(f"DPTR = 0x{text.split('#')[1][:-1]};")
        return
    if text == "MOVX A,@DPTR":
        out.append("A = XD(DPTR);")
        return
    if text == "MOVX @DPTR,A":
        out.append("XD(DPTR) = A;")
        return
    m = re.match(r"^MOVX A,@R([01])$", text)
    if m:
        out.append(f"A = XD(((unsigned int)SFR_A0 << 8) | R{m.group(1)});")
        return
    m = re.match(r"^MOVX @R([01]),A$", text)
    if m:
        out.append(f"XD(((unsigned int)SFR_A0 << 8) | R{m.group(1)}) = A;")
        return
    if text == "MOVC A,@A+DPTR":
        out.append("A = CD(DPTR + A);")
        return
    if text == "INC DPTR":
        out.append("DPTR++;")
        return
    if text in ("INC A",):
        out.append("A++;")
        return
    if text in ("DEC A",):
        out.append("A--;")
        return
    if text == "CLR A":
        out.append("A = 0;")
        return
    if text == "CPL A":
        out.append("A = ~A;")
        return
    if text == "SWAP A":
        out.append("A = (A << 4) | (A >> 4);")
        return
    if text == "RR A":
        out.append("A = (A >> 1) | (A << 7);")
        return
    if text == "RL A":
        out.append("A = (A << 1) | (A >> 7);")
        return
    if text == "RRC A":
        out.append("tmp = (A & 1); A = (A >> 1) | (C << 7); C = tmp;")
        return
    if text == "RLC A":
        out.append("tmp = (A >> 7); A = (A << 1) | C; C = tmp;")
        return
    if text == "CLR C":
        out.append("C = 0;")
        return
    if text == "SETB C":
        out.append("C = 1;")
        return
    if text == "CPL C":
        out.append("C = !C;")
        return
    if text == "MUL AB":
        out.append("tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;")
        return
    if text == "DIV AB":
        out.append("if (B == 0) { C = 0; } else { tmp = A % B; A = A / B; B = tmp; C = 0; }")
        return
    if text == "DA A":
        out.append("A = da_a(A);")
        return
    m = re.match(r"^(SETB|CLR|CPL) (.+)$", text)
    if m:
        b = dir_addr(m.group(2))
        g = bit_get(b)
        if m.group(1) == "SETB":
            out.append(bit_set(b, "1"))
        elif m.group(1) == "CLR":
            out.append(bit_set(b, "0"))
        else:
            out.append(bit_set(b, f"!{g}"))
        return
    m = re.match(r"^MOV C,(.+)$", text)
    if m:
        out.append(f"C = {bit_get(dir_addr(m.group(1)))};")
        return
    m = re.match(r"^MOV (.+),C$", text)
    if m:
        out.append(bit_set(dir_addr(m.group(1)), "C"))
        return
    m = re.match(r"^MOV (A|B|DPTR),(.+)$", text)
    if m:
        dst, src = m.group(1), m.group(2)
        if src.startswith("#"):
            out.append(f"{dst} = 0x{src[1:-1]};")
            return
        if src.startswith("@"):
            out.append(f"{dst} = XD(((unsigned int)SFR_A0 << 8) | R{src[2]});")
            return
        if re.fullmatch(r"R[0-7]", src):
            out.append(f"{dst} = {src};")
            return
        out.append(f"{dst} = {dir_expr(dir_addr(src))};")
        return
    m = re.match(r"^MOV (R[0-7]),(.+)$", text)
    if m:
        dst, src = m.group(1), m.group(2)
        if src.startswith("#"):
            out.append(f"{dst} = 0x{src[1:-1]};")
        elif src.startswith("@"):
            out.append(f"{dst} = XD(((unsigned int)SFR_A0 << 8) | R{src[2]});")
        else:
            out.append(f"{dst} = {dir_expr(dir_addr(src))};")
        return
    m = re.match(r"^MOV (@R[01]),(.+)$", text)
    if m:
        dst, src = m.group(1), m.group(2)
        if src.startswith("#"):
            val = f"0x{src[1:-1]}"
        elif src.startswith("R") and len(src) == 2 and src[1].isdigit():
            val = src
        else:
            val = dir_expr(dir_addr(src))
        out.append(f"XD(((unsigned int)SFR_A0 << 8) | R{dst[2]}) = {val};")
        return
    m = re.match(r"^MOV (.+),(.+)$", text)
    if m:
        dst, src = m.group(1), m.group(2)
        da = dir_addr(dst)
        de = dir_expr(da)
        if src.startswith("#"):
            out.append(f"{de} = 0x{src[1:-1]};")
        elif src.startswith("@"):
            out.append(f"{de} = XD(((unsigned int)SFR_A0 << 8) | R{src[2]});")
        elif re.fullmatch(r"R[0-7]", src):
            out.append(f"{de} = {src};")
        else:
            out.append(f"{de} = {dir_expr(dir_addr(src))};")
        return
    m = re.match(r"^(ADD|ADDC|SUBB) A,(.+)$", text)
    if m:
        kind, src = m.group(1), m.group(2)
        if src.startswith("#"):
            val = f"0x{src[1:-1]}"
        elif src.startswith("@"):
            val = f"XD(((unsigned int)SFR_A0 << 8) | R{src[2]})"
        elif re.fullmatch(r"R[0-7]", src):
            val = src
        else:
            val = f"({dir_expr(dir_addr(src))})"
        if kind == "ADD":
            out.append(f"ADD8({val});")
        elif kind == "ADDC":
            out.append(f"ADDC8({val});")
        else:
            out.append(f"SUBB8({val});")
        return
    m = re.match(r"^(ANL|ORL|XRL) A,(.+)$", text)
    if m:
        kind, src = m.group(1), m.group(2)
        if src.startswith("#"):
            val = f"0x{src[1:-1]}"
        elif src.startswith("@"):
            val = f"XD(((unsigned int)SFR_A0 << 8) | R{src[2]})"
        elif re.fullmatch(r"R[0-7]", src):
            val = src
        else:
            val = dir_expr(dir_addr(src))
        op = {"ANL": "&=", "ORL": "|=", "XRL": "^="}[kind]
        out.append(f"A {op} {val};")
        return
    m = re.match(r"^(ANL|ORL|XRL) (.+),(.+)$", text)
    if m:
        kind, dst, src = m.group(1), m.group(2), m.group(3)
        if dst == "C":
            b = dir_addr(src.lstrip("/"))
            g = bit_get(b)
            val = f"({g})" if not src.startswith("/") else f"(!{g})"
            out.append(f"C = C {'||' if kind == 'ORL' else '&&'} {val};")
            return
        de = dir_expr(dir_addr(dst))
        val = f"0x{src[1:-1]}" if src.startswith("#") else "A"
        op = {"ANL": "&=", "ORL": "|=", "XRL": "^="}[kind]
        out.append(f"{de} {op} {val};")
        return
    if text.startswith("ORL C,") or text.startswith("ANL C,"):
        kind, rest = text.split(" ", 2)[0], text.split(",", 1)[1]
        b = dir_addr(rest.lstrip("/"))
        pos = not rest.startswith("/")
        g = bit_get(b)
        val = f"({g})" if pos else f"(!{g})"
        if kind == "ORL":
            out.append(f"C = C || {val};")
        else:
            out.append(f"C = C && {val};")
        return
    m = re.match(r"^(INC|DEC) (.+)$", text)
    if m:
        kind, op = m.group(1), m.group(2)
        if op.startswith("@"):
            var = f"XD(((unsigned int)SFR_A0 << 8) | R{op[2]})"
        elif re.fullmatch(r"R[0-7]", op):
            var = op
        else:
            var = dir_expr(dir_addr(op))
        out.append(f"{var}{'++' if kind == 'INC' else '--'};")
        return
    m = re.match(r"^(XCH) A,(.+)$", text)
    if m:
        src = m.group(2)
        var = f"XD(((unsigned int)SFR_A0 << 8) | R{src[2]})" if src.startswith("@") else (src if re.fullmatch(r"R[0-7]", src) else dir_expr(dir_addr(src)))
        out.append(f"tmp = A; A = {var}; {var} = tmp;")
        return
    m = re.match(r"^XCHD A,(.+)$", text)
    if m:
        var = f"XD(((unsigned int)SFR_A0 << 8) | R{m.group(1)[2]})"
        out.append(f"tmp = A & 0x0F; A = (A & 0xF0) | ({var} & 0x0F); {var} = ({var} & 0xF0) | tmp;")
        return
    if text.startswith("AJMP") or text.startswith("LJMP"):
        t = target(text)
        out.append(f"f_{t:04X}();")
        out.append("return;")
        return
    out.append("EC_UNSUPPORTED();")


def translate(region, entry, f):
    global SUPPORTED, CUR_KIND
    SUPPORTED = True
    CUR_KIND = region.kind
    body = []
    texts = [t for a, t, ln, k in f["insns"]]
    if (len(f["insns"]) <= 12 and f["insns"] and f["insns"][-1][3] == "ret"
            and "PUSH DPL" in texts and "PUSH DPH" in texts):
        return ["ec_jump((unsigned int)DPTR);", "return;"]
    global CUR_ADDRS
    addrs = {a for a, text, ln, kind in f["insns"]}
    CUR_ADDRS = addrs
    labels = set()
    for a, text, ln, kind in f["insns"]:
        if re.match(r"^(JZ|JNZ|JC|JNC|JB|JNB|JBC|SJMP|DJNZ|CJNE) ", text):
            t = target(text)
            if t is not None and t in addrs:
                labels.add(t)
    for a, text, ln, kind in f["insns"]:
        if a in labels:
            body.append(f"L_{a:04X}:")
        try:
            emit(region, a, text, ln, body)
        except Exception:
            print("FAIL", hex(a), text)
            raise
    if SUPPORTED:
        return body
    return None


def main():
    data = (ROOT / "firmware" / "eFlashBK.bin").read_bytes()
    regions = [
        ec.Region(0, data[0x00000:0x08000], 0x00000, 0x0000, "fixed"),
        ec.Region(1, data[0x08000:0x10000], 0x08000, 0x8000, "bank0"),
        ec.Region(2, data[0x10000:0x18000], 0x10000, 0x8000, "bank1"),
        ec.Region(3, data[0x18000:0x20000], 0x18000, 0x8000, "bank2"),
    ]
    entries = defaultdict(set)
    names = {}
    with open(ROOT / "build" / "analysis" / "functions.csv", encoding="utf-8") as fh:
        for row in csv.DictReader(fh):
            r = int(row["region"])
            a = int(row["address"], 16)
            entries[r].add(a)
            names[(r, a)] = row["name"]

    OUT.mkdir(parents=True, exist_ok=True)
    for sub in ("common", "fixed", "bank0", "bank1", "bank2"):
        (OUT / sub).mkdir(parents=True, exist_ok=True)
    funcs = {}
    skipped = []
    for idx, region in enumerate(regions):
        funcs[idx] = {}
        for e in sorted(entries[idx]):
            f = ec.walk(region, e, entries[idx])
            body = translate(region, e, f)
            if body is None:
                skipped.append((idx, e, names[(idx, e)]))
            else:
                funcs[idx][e] = body

    defined_names = set()
    for idx, fl in funcs.items():
        for e in fl:
            defined_names.add(fname(e, regions[idx].kind))
    call_names = set()
    for fl in funcs.values():
        for body in fl.values():
            for line in body:
                for m in re.finditer(r"([fgh]_[0-9A-F]{4})\(", line):
                    call_names.add(m.group(1))

    sfr = set()
    for idx, fl in funcs.items():
        for e, body in fl.items():
            for line in body:
                for m in re.finditer(r"SFR_([0-9A-F]{2})", line):
                    sfr.add(int(m.group(1), 16))
    for idx, region in enumerate(regions):
        for e in sorted(entries[idx]):
            f = ec.walk(region, e, entries[idx])
            for a, text, ln, kind in f["insns"]:
                for m in re.finditer(r"((?:[0-9A-F]{2})h)", text):
                    addr = int(m.group(1)[:-1], 16)
                    if 0x80 <= addr <= 0xFF:
                        sfr.add(addr)
                for m in re.finditer(r"((?:SFR_)?([0-9A-F]{2})h)", text):
                    pass

    hdr = [
        "#ifndef EC_GLOBALS_H",
        "#define EC_GLOBALS_H",
        "",
        
        "",
        "extern unsigned char A, B, C, PSW, SP;",
        "extern unsigned int DPTR;",
        "extern unsigned char RBANKS[4][8];",
        "#define RB(n) (RBANKS[((PSW >> 3) & 3)][n])",
        "extern unsigned char tmp;",
        "extern unsigned int tmp16;",
        "extern unsigned char STACK[256];",
        "",
        "void ec_jump(unsigned int addr);",
        "",
        "#define DPL (*(unsigned char *)((unsigned char *)&DPTR))",
        "#define DPH (*(unsigned char *)(((unsigned char *)&DPTR) + 1))",
        "#define DIR(a) (*(volatile unsigned char __idata *)(a))",
        "#define XD(a) (*(volatile unsigned char __xdata *)(a))",
        "#define CD(a) (*(const unsigned char __code *)(a))",
        "#define BIT_RAM(b) ((*(volatile unsigned char __idata *)(0x20 + ((b) >> 3)) >> ((b) & 7)) & 1)",
        "#define BIT_SET(b, v) do { volatile unsigned char __idata *p_ = (volatile unsigned char __idata *)(0x20 + ((b) >> 3)); if (v) *p_ |= (1 << ((b) & 7)); else *p_ &= ~(1 << ((b) & 7)); } while (0)",
        "#define ADD8(x) do { tmp16 = (unsigned int)A + (x); C = (tmp16 > 0xFF); A = (unsigned char)tmp16; } while (0)",
        "#define ADDC8(x) do { tmp16 = (unsigned int)A + (x) + C; C = (tmp16 > 0xFF); A = (unsigned char)tmp16; } while (0)",
        "#define SUBB8(x) do { tmp16 = (unsigned int)A - (x) - C; C = ((unsigned int)A < (unsigned int)(x) + C); A = (unsigned char)tmp16; } while (0)",
        "#define EC_UNSUPPORTED() do { } while (0)",
        "",
        "unsigned char da_a(unsigned char v);",
        "",
    ]
    sfr.add(0xA0)
    for a in sorted(sfr):
        if a not in (0xE0, 0xF0, 0xD0, 0x82, 0x83, 0x81):
            hdr.append(f"__sfr __at (0x{a:02X}) SFR_{a:02X};")
    hdr.append("")
    hdr.append("void ec_jump_bank1(unsigned int addr);")
    hdr.append("void ec_jump_bank2(unsigned int addr);")
    for e in sorted(defined_names | call_names):
        hdr.append(f"void {e}(void);")
    hdr.append("")
    hdr.append("#endif")
    (OUT / "common" / "ec_globals.h").write_text("\n".join(hdr) + "\n", encoding="utf-8")

    (OUT / "common" / "ec_globals.c").write_text(
        "#include \"ec_globals.h\"\n\n"
        "unsigned char A, B, C, PSW, SP;\n"
        "unsigned int DPTR;\n"
        "unsigned char RBANKS[4][8];\n"
        "unsigned char tmp;\n"
        "unsigned int tmp16;\n"
        "unsigned char STACK[256];\n\n"
        "unsigned char da_a(unsigned char v)\n{\n"
        "    unsigned char lo = v & 0x0F;\n"
        "    unsigned char hi = v >> 4;\n"
        "    if (lo > 9) { lo += 6; hi++; }\n"
        "    if (hi > 9) hi += 6;\n"
        "    return (hi << 4) | (lo & 0x0F);\n}\n", encoding="utf-8")

    mapping = {"fixed": "fixed/region0", "bank0": "bank0/bank0", "bank1": "bank1/bank1", "bank2": "bank2/bank2"}
    for idx, region in enumerate(regions):
        lines = ["#include \"ec_globals.h\"", ""]
        for e in sorted(funcs[idx]):
            lines.append(f"void {fname(e, region.kind)}(void)")
            lines.append("{")
            for stmt in funcs[idx][e]:
                lines.append("    " + re.sub(r"\bR\[([0-7])\]", r"RB(\1)", re.sub(r"\bR([0-7])\b", r"R[\1]", stmt)))
            lines.append("}")
            lines.append("")
        (OUT / f"{mapping[region.kind]}.c").write_text("\n".join(lines) + "\n", encoding="utf-8")

    stubs = sorted(call_names - defined_names)
    (OUT / "common" / "ec_stubs.c").write_text(
        "#include " + chr(34) + "ec_globals.h" + chr(34) + chr(10) + chr(10) +
        chr(10).join(f"void {n}(void) {{ }}" for n in stubs) + chr(10), encoding="utf-8")

    def write_dispatch(name, kinds):
        rows = ["#include \"ec_globals.h\"", "", f"void {name}(unsigned int addr)", "{", "    switch (addr) {"]
        for idx, region in enumerate(regions):
            if region.kind not in kinds:
                continue
            for e in sorted(funcs[idx]):
                rows.append(f"    case 0x{e:04X}: {fname(e, region.kind)}(); break;")
        rows += ["    default: break;", "    }", "}"]
        (OUT / "common" / f"{name}.c").write_text("\n".join(rows) + "\n", encoding="utf-8")

    write_dispatch("ec_jump", ("fixed", "bank0"))
    write_dispatch("ec_jump_bank1", ("bank1",))
    write_dispatch("ec_jump_bank2", ("bank2",))
    summary = {
        "translated": {mapping[regions[i].kind]: len(funcs[i]) for i in funcs},
        "skipped": len(skipped),
        "skipped_list": [{"region": i, "addr": f"0x{e:04X}", "name": n} for i, e, n in skipped[:50]],
    }
    (OUT / "translation_report.json").write_text(__import__("json").dumps(summary, indent=2), encoding="utf-8")
    print(__import__("json").dumps(summary, indent=2))


if __name__ == "__main__":
    main()
