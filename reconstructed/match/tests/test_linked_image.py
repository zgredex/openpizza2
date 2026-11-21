"""Verify scratch image relinking and capture preflight without VC6 or the host."""

from pathlib import Path
import json
import struct
import sys
import tempfile
import unittest
from unittest.mock import patch

from test_independent_relocations import coff_object

sys.path.insert(0, str(Path(__file__).resolve().parents[3] / "tools"))
from pcrecomp_pc2 import capture
import match_decomp
import verify_linked_image as linker
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

    def test_audit_plan_checks_saved_hash_priorities_and_overlap(self):
        base = 0x401000
        image = (b"\xc3" * 4, base, [(".text", 0, 4, 0, 4)])
        compiler = {"CL.EXE": "fake"}
        with tempfile.TemporaryDirectory() as scratch:
            root = Path(scratch)
            records = root / "functions"
            records.mkdir()
            source = root / "source.c"
            source.write_text("void f(void) {}\n")

            def write_record(address, name, length=1, strict=True):
                (records / name).write_text(json.dumps({
                    "address": hex(address), "length": length, "strict_match": strict,
                    "source": source.name, "source_sha256": digest(source.read_bytes()),
                    "executable_sha256": "guest", "compiler": {"sha256": compiler},
                    "linked_sections": ["primary"], "entry": "_f", "flags": ["/O2"],
                    "symbol_overrides": {},
                }))

            write_record(base + 1, "a.json")
            write_record(base + 2, "b.json")
            write_record(base + 2, "c.json")
            write_record(base + 3, "d.json", strict=False)
            lengths = {base: 2, base + 1: 1, base + 2: 1}
            with (patch.object(linker, "ROOT", root),
                  patch.object(linker, "function_lengths", return_value=lengths)):
                items, excluded, count, deferred = linker.batch_plan(root, image, "guest", compiler, [base + 2], 1)
                self.assertEqual([(entry.address, entry.audit_record) for entry in items], [(base + 2, "b.json")])
                self.assertEqual((count, deferred), (4, 1))
                self.assertEqual([row["reason"] for row in excluded], ["duplicate VA", "audit was not strict"])
                with self.assertRaisesRegex(ValueError, "audit executable SHA-256 differs"):
                    linker.batch_plan(root, image, "changed", compiler, [], None)
                write_record(base, "overlap.json", length=2)
                with self.assertRaisesRegex(ValueError, "overlapping planned address"):
                    linker.batch_plan(root, image, "guest", compiler, [], None)
                source.write_text("changed\n")
                with self.assertRaisesRegex(ValueError, "audited source.*changed"):
                    linker.batch_plan(root, image, "guest", compiler, [], None)

    def test_cache_hit_is_reverified_and_drift_fails_closed(self):
        original = b"\xc3"
        base = 0x401000
        image = (original, base, [(".text", 0, 1, 0, 1)])

        def object_for(raw):
            return coff_object([(b".text", raw, [])], [(b"_f", 0, 1, 0x20, 2, 0)])

        def compile_fixture(source, vc6, obj, flags, *, environment):
            self.assertEqual(environment, {"PATH": "test"})
            obj.write_bytes(object_for(original))

        with tempfile.TemporaryDirectory() as scratch:
            root = Path(scratch)
            source = root / "self-contained.c"
            source.write_text("void f(void) {}\n")
            cache = root / "objects"
            cache.mkdir()
            recipe = linker.Recipe(base, 1, 0, source, digest(source.read_bytes()), "_f", ("/O2",), {})
            args = (recipe, root, root, original, cache, "toolchain-environment", {"PATH": "test"})
            with (patch.object(linker, "compile_candidate", side_effect=compile_fixture) as compile_call,
                  patch.object(match_decomp, "pe_image", return_value=image)):
                self.assertEqual(linker.verify_recipe(*args)[1]["cache"], "miss")
                self.assertEqual(linker.verify_recipe(*args)[1]["cache"], "hit")
                compile_call.assert_called_once()
                next(cache.glob("*.obj")).write_bytes(object_for(b"\x90"))
                with self.assertRaisesRegex(ValueError, "strict match failed"):
                    linker.verify_recipe(*args)
                compile_call.assert_called_once()
            self.assertIsNone(linker.cache_path(cache, "identity", source, b'#include "other.h"', ("/O2",)))
            self.assertIsNone(linker.cache_path(cache, "identity", source, source.read_bytes(), ("/FIforced.h",)))

    def test_image_assembly_rejects_overlap_even_when_bytes_match(self):
        self.assertEqual(linker.assemble_image(b"xyz", [(2, b"z"), (0, b"x")]), b"xyz")
        with self.assertRaisesRegex(ValueError, "write ranges overlap"):
            linker.assemble_image(b"xyz", [(0, b"xy"), (1, b"yz")])

    def test_capture_reports_only_linked_entries_in_captured_phases(self):
        report = {"run": {"guest_sha256": "guest"}, "complete": False,
                  "phases": [{"name": "menu", "functions": [{"address": "0x401000", "count": 2},
                                                                {"address": "0x403000", "count": 7}]}]}
        manifest = {"output": {"sha256": "guest"}, "schema": "pc2.verified_linked_image_batch.v1",
                    "functions": [{"function": {"start": "0x401000"}}, {"function": {"start": "0x402000"}}]}
        result = capture.linked_reachability(report, manifest)
        self.assertEqual(result, {"scenario_complete": False, "linked": 2,
                                  "reached": [{"address": "0x00401000", "entries": 2, "phases": {"menu": 2}}],
                                  "not_seen": ["0x00402000"]})
        manifest["output"]["sha256"] = "changed"
        with self.assertRaisesRegex(ValueError, "differs from the captured image"):
            capture.linked_reachability(report, manifest)

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
