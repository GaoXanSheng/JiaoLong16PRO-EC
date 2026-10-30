import hashlib
import json
import subprocess
import sys
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
REFERENCE_SHA256 = "cda99cf6f3889ea2886294fe5f91a474ef6fa82b0640f6a9058b3dd1d1b883fe"


class FirmwareRebuildTest(unittest.TestCase):
    def test_reference_image_unchanged(self):
        data = (ROOT / "firmware" / "eFlashBK.bin").read_bytes()
        self.assertEqual(len(data), 0x20000)
        self.assertEqual(hashlib.sha256(data).hexdigest(), REFERENCE_SHA256)

    def test_rebuild_matches_reference(self):
        proc = subprocess.run([sys.executable, str(ROOT / "tools" / "build.py")],
                              cwd=ROOT, capture_output=True, text=True,
                              encoding="utf-8", errors="replace")
        self.assertEqual(proc.returncode, 0, proc.stdout + proc.stderr)
        report = json.loads((ROOT / "build" / "build_report.json").read_text(encoding="utf-8"))
        verify = report["verify"]
        self.assertEqual(verify["mismatch_bytes"], 0)
        self.assertTrue(verify["identical"])
        self.assertEqual(verify["original_sha256"], verify["rebuilt_sha256"])


if __name__ == "__main__":
    unittest.main()
