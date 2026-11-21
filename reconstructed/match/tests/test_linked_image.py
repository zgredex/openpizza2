"""Verify scratch image relinking and capture preflight without VC6 or the host."""

from pathlib import Path
import struct
import sys
import tempfile
import unittest
from unittest.mock import patch

from test_independent_relocations import coff_object

sys.path.insert(0, str(Path(__file__).resolve().parents[3] / "tools"))
from pcrecomp_pc2 import capture
from verify_linked_image import digest, link_body, verified_image, write_outputs


class LinkedImageTests(unittest.TestCase):
    def test_link_evaluates_dir32_and_rel32_from_object_with_addends(self):
        base, global_va, callee_va = 0x401000, 0x405070, 0x4020F0
        raw = b"\x68" + struct.pack("<i", 20) + b"\xe8" + struct.pack("<i", -3) + b"\xc3"
        linked = b"\x68\x84\x50\x40\x00\xe8\xe3\x10\x00\x00\xc3"
        original = b"prefix" + linked + b"rest"
        image = (original, base, [(".text", 0, len(raw), 6, len(raw))])
        body = coff_object([(b".text", raw, [(1, 1, 0x06), (6, 2, 0x14)])],
                           [(b"_entry", 0, 1, 0x20, 2, 0), (b"_global", 0, 0, 0, 2, 0),
                            (b"_callee", 0, 0, 0x20, 2, 0)])
        with tempfile.TemporaryDirectory() as scratch:
            obj = Path(scratch) / "test.obj"
            obj.write_bytes(body)
            symbols = {"_global": global_va, "_callee": callee_va}
            code, calls = link_body(obj, base, len(raw), "_entry", symbols)
            self.assertEqual(code, linked)
            self.assertEqual(verified_image(image, base, code), (original, 6))
            self.assertEqual(calls, [{"instruction": "0x401005", "target": "0x4020ed", "symbol": "_callee"}])
            wrong, _ = link_body(obj, base, len(raw), "_entry", {**symbols, "_callee": callee_va + 1})
            with self.assertRaisesRegex(ValueError, "differs from the original PE"):
                verified_image(image, base, wrong)
            with self.assertRaisesRegex(ValueError, "unresolved COFF target _callee"):
                link_body(obj, base, len(raw), "_entry", {"_global": global_va})

    def test_outputs_keep_existing_files_and_roll_back_partial_pair(self):
        with tempfile.TemporaryDirectory() as scratch:
            existing, new = Path(scratch) / "canonical", Path(scratch) / "scratch"
            existing.write_bytes(b"original")
            with self.assertRaises(FileExistsError):
                write_outputs([(new, b"new"), (existing, b"overwrite")])
            self.assertEqual(existing.read_bytes(), b"original")
            self.assertFalse(new.exists())

    def test_capture_reuses_canonical_hash_and_rejects_different_image(self):
        pinned = digest(b"pinned image")
        with (tempfile.TemporaryDirectory() as scratch, patch.object(capture, "ROOT", Path(scratch)),
              patch.object(capture, "GUEST_SHA256", pinned)):
            canonical = capture.ROOT / "game" / "fastfood2.exe"
            canonical.parent.mkdir()
            canonical.write_bytes(b"pinned image")
            copy = capture.ROOT / "copy.exe"
            copy.write_bytes(canonical.read_bytes())
            self.assertEqual(capture.capture_image(None), (canonical, pinned))
            self.assertEqual(capture.capture_image(copy), (copy, pinned))
            copy.write_bytes(b"changed image")
            with self.assertRaisesRegex(ValueError, "--image SHA-256.*differs"):
                capture.capture_image(copy)
            canonical.write_bytes(copy.read_bytes())
            with self.assertRaisesRegex(ValueError, "canonical image SHA-256.*pinned"):
                capture.capture_image(copy)


if __name__ == "__main__":
    unittest.main()
