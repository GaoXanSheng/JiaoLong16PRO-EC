import json
import os
import re
import subprocess
import sys
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
SDCC = Path(os.environ.get("SDCC_BIN", r"C:\Program Files\SDCC\bin"))
STUB_IHX = ROOT / "build" / "fw" / "firmware64_stub.ihx"
CRC_IMAGE = ROOT / "build" / "fw" / "crc_hook_test_image.ihx"


def run_build():
    proc = subprocess.run([sys.executable, str(ROOT / "tools" / "build.py"), "--firmware"],
                          cwd=ROOT, capture_output=True, text=True,
                          encoding="utf-8", errors="replace")
    if proc.returncode != 0:
        raise RuntimeError(proc.stdout + proc.stderr)


def sdcc_env():
    env = dict(os.environ)
    env["PATH"] = str(SDCC) + os.pathsep + env.get("PATH", "")
    return env


def write_ihx(path, data):
    lines = []
    for addr in range(0, len(data), 16):
        chunk = data[addr:addr + 16]
        record = bytes([len(chunk), (addr >> 8) & 0xFF, addr & 0xFF, 0]) + bytes(chunk)
        lines.append(":" + record.hex().upper() + f"{(-sum(record)) & 0xFF:02X}")
    lines.append(":00000001FF")
    path.write_text("\n".join(lines) + "\n", encoding="ascii")


def read_ihx(path):
    mem = {}
    for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
        line = line.strip()
        if not line.startswith(":"):
            continue
        record = bytes.fromhex(line[1:])
        count = record[0]
        addr = (record[1] << 8) | record[2]
        if record[3] != 0:
            continue
        for i, value in enumerate(record[4:4 + count]):
            mem[addr + i] = value
    return mem


def make_stub_image():
    image = bytearray((ROOT / "build" / "firmware_128k.bin").read_bytes()[:0x10000])
    image[0x1A4C:0x1A4F] = bytes([0x7F, 0x01, 0x22])
    write_ihx(STUB_IHX, image)


def make_crc_image():
    rel = ROOT / "build" / "fw" / "crc_hook_test.rel"
    ihx = ROOT / "build" / "fw" / "crc_hook_test.ihx"
    env = sdcc_env()
    sdas = str(SDCC / "sdas8051.exe")
    sdld = str(SDCC / "sdld.exe")
    proc = subprocess.run([sdas, "-plosgff", str(rel), str(ROOT / "tests" / "sim" / "crc_hook_test.a51")],
                          cwd=ROOT, capture_output=True, text=True, env=env)
    if proc.returncode != 0:
        raise RuntimeError(proc.stdout + proc.stderr)
    proc = subprocess.run([sdld, "-i", str(ihx), "-b", "CSEG=0x7C00", str(rel)],
                          cwd=ROOT, capture_output=True, text=True, env=env)
    if proc.returncode != 0:
        raise RuntimeError(proc.stdout + proc.stderr)
    image = bytearray((ROOT / "build" / "firmware_128k.bin").read_bytes()[:0x10000])
    for addr, value in read_ihx(ihx).items():
        if image[addr] != 0xFF:
            raise RuntimeError(f"harness collision at 0x{addr:04X}")
        image[addr] = value
    write_ihx(CRC_IMAGE, image)


def run_stub(setup):
    commands = ['file "build/fw/firmware64_stub.ihx"'] + setup + [
        "set memory iram 0x00 0x11 0x22 0x33 0x44 0x55 0x66 0x77 0x88",
        "set memory sfr 0x81 0xc0",
        "pc 0xa182",
        "break 0xa185",
        "run",
        "state",
        "dump xram 0x0693 0x0693",
        "dump xram 0x069d 0x06a0",
        "dump xram 0x837a 0x837b",
        "dump xram 0x8998 0x8998",
        "dump xram 0x89a4 0x89d7",
        "dump xram 0x89cd 0x89d1",
        "dump iram 0x00 0x07",
        "quit",
    ]
    proc = subprocess.run([str(SDCC / "s51.exe"), "-q"], cwd=ROOT,
                          input="\n".join(commands) + "\n", capture_output=True,
                          text=True, encoding="utf-8", errors="replace", timeout=120)
    return parse_dump(proc.stdout), proc.stdout


def run_crc():
    commands = [
        'file "build/fw/crc_hook_test_image.ihx"',
        "set memory sfr 0x81 0xc0",
        "pc 0x7c00",
        "break xram w 0xfbff",
        "run",
        "dump xram 0xfc00 0xfc07",
        "quit",
    ]
    proc = subprocess.run([str(SDCC / "s51.exe"), "-q"], cwd=ROOT,
                          input="\n".join(commands) + "\n", capture_output=True,
                          text=True, encoding="utf-8", errors="replace", timeout=120)
    return parse_dump(proc.stdout)


def parse_dump(text):
    mem = {}
    for line in text.splitlines():
        match = re.match(r"^\s*0x([0-9a-fA-F]{2,4})\s+(.*)$", line)
        if not match:
            continue
        addr = int(match.group(1), 16)
        for offset, token in enumerate(match.group(2).split()[:16]):
            if not re.fullmatch(r"[0-9a-fA-F]{2}", token):
                break
            mem[addr + offset] = int(token, 16)
    return mem


def override_ranges(report):
    ranges = []
    for item in report["overrides"]:
        lo_text, hi_text = item["blob"].split("-")
        lo = int(lo_text, 16)
        hi = int(hi_text, 16)
        if item["name"] == "battery":
            start = 0x08000 + (lo - 0x8000)
            ranges.append((start, start + (hi - lo) + 1))
        else:
            ranges.append((lo, hi + 1))
        patch = int(item["patch"], 16)
        ranges.append((patch, patch + 3))
    return ranges


class FirmwareIntegrationTest(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        run_build()
        cls.report = json.loads((ROOT / "build" / "firmware_report.json").read_text(encoding="utf-8"))

    def test_c_modules_are_linked_into_image(self):
        image = ROOT / self.report["image"]
        self.assertEqual(image.stat().st_size, 0x20000)
        self.assertGreater(self.report["diff_bytes"], 0)
        self.assertEqual([item["name"] for item in self.report["overrides"]], ["battery", "crc"])

        original = (ROOT / "firmware" / "eFlashBK.bin").read_bytes()
        patched = image.read_bytes()
        diffs = [i for i in range(len(original)) if original[i] != patched[i]]
        self.assertEqual(len(diffs), self.report["diff_bytes"])
        ranges = override_ranges(self.report)
        outside = [i for i in diffs if not any(a <= i < b for a, b in ranges)]
        self.assertEqual(outside, [])

        crc_entry = int(self.report["crc_entry_address"], 16)
        self.assertEqual(self.report["crc_patch_after"], "02" + f"{crc_entry:04X}".lower())
        self.assertEqual(self.report["call_after"],
                         "12" + self.report["entry_address"][2:].lower())

    @unittest.skipUnless((SDCC / "s51.exe").exists(), "s51 simulator not found")
    def test_model_select_runs_in_firmware_context(self):
        make_stub_image()
        setup = [
            "set memory xram 0x83c0 0x00",
            "set memory xram 0x83c3 0x00",
            "set memory xram 0x8998 0x01",
            "set memory xram 0x847c 0x10",
            "set memory xram 0x89a4 0x8b",
            "set memory xram 0x89a5 0x28",
            "set memory xram 0x89cb 0xd4",
            "set memory xram 0x89cc 0x05",
            "set memory xram 0x83f0 0x01",
            "set memory xram 0x898a 0x00",
            "set memory xram 0x89a6 0xaa",
            "set memory xram 0x89a7 0x00",
        ]
        mem, _ = run_stub(setup)
        self.assertEqual(mem[0x89A6], 0x14)
        self.assertEqual(mem[0x89A7], 0x08)
        self.assertEqual([mem[0x069D], mem[0x069E], mem[0x069F], mem[0x06A0]],
                         [0x3B, 0x89, 0xA6, 0x00])
        self.assertEqual([mem[i] for i in range(8)],
                         [0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88])

    @unittest.skipUnless((SDCC / "s51.exe").exists(), "s51 simulator not found")
    def test_init_sequence_runs_in_firmware_context(self):
        make_stub_image()
        setup = [
            "set memory xram 0x83c0 0x00",
            "set memory xram 0x83c3 0x00",
            "set memory xram 0x8998 0x00",
            "set memory xram 0x0693 0xee",
            "set memory xram 0x1603 0x08",
            "set memory xram 0x89cd 0xaa",
            "set memory xram 0x89ce 0xaa",
            "set memory xram 0x89d0 0xaa",
            "set memory xram 0x89d1 0xaa",
            "set memory xram 0x89cb 0xd4",
            "set memory xram 0x89cc 0x05",
            "set memory xram 0x89a4 0xaa",
            "set memory xram 0x89a5 0xaa",
            "set memory xram 0x89a6 0x00",
            "set memory xram 0x89a7 0x00",
            "set memory xram 0x847c 0x10",
            "set memory xram 0x83f0 0x01",
            "set memory xram 0x898a 0x14",
        ]
        mem, out = run_stub(setup)
        self.assertEqual(mem[0x0693], 0x00)
        self.assertEqual(mem[0x8998], 0x01)
        self.assertEqual(mem[0x89D6], 0x00)
        self.assertEqual([mem[0x837A], mem[0x837B]], [0x00, 0x0B])
        self.assertEqual([mem[0x89CD], mem[0x89CE], mem[0x89D0], mem[0x89D1]],
                         [0x00, 0x0F, 0x00, 0x0F])
        self.assertEqual([mem[0x89D2], mem[0x89D3]], [0xD4, 0x05])
        self.assertEqual([mem[0x89A6], mem[0x89A7]], [0x14, 0x08])
        self.assertEqual([mem[0x069D], mem[0x069E], mem[0x069F], mem[0x06A0]],
                         [0x3B, 0x89, 0xA6, 0x00])
        self.assertEqual([mem[i] for i in range(8)],
                         [0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88])
        match = re.search(r"Most value of stack pointer=\s*0x([0-9a-fA-F]+)", out)
        self.assertIsNotNone(match)
        self.assertLessEqual(int(match.group(1), 16), 0xFF)

    @unittest.skipUnless((SDCC / "s51.exe").exists(), "s51 simulator not found")
    def test_crc_override_runs_in_firmware_context(self):
        make_crc_image()
        mem = run_crc()
        self.assertEqual([mem[0xFC00 + i] for i in range(8)],
                         [0x68, 0x81, 0x6C, 0x86, 0x68, 0x08, 0x4A, 0x72])


if __name__ == "__main__":
    unittest.main()
