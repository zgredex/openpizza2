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
import audit_symbol_targets
from audit_symbol_targets import rank_blockers, reverse_dependencies
import match_decomp
import verify_linked_image as linker
from verify_linked_image import digest, write_outputs


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
            with patch.object(match_decomp, "pe_image", return_value=image):
                good = match_decomp.match_object(base, obj, symbols, len(raw), "_entry", strict=True)
                self.assertEqual(good["linked_spans"][0]["hex_bytes"], linked.hex())
                self.assertEqual(good["linked_spans"][0]["file_offset"], "0x6")
                self.assertEqual(linker.direct_calls(good),
                                 [{"instruction": "0x401005", "target": "0x4020ed", "symbol": "_callee"}])
                for broken in ({**symbols, "_callee": callee_va + 1}, {"_global": global_va}):
                    failure = match_decomp.match_object(base, obj, broken, len(raw), "_entry", strict=True)
                    self.assertFalse(failure["strict_match"])
                    self.assertEqual(failure["linked_spans"], [])

    def test_inline_table_uses_coff_fixups_and_plain_padding_is_omitted(self):
        base = 0x401000
        raw = b"\xa1\0\0\0\0\xc3" + bytes(4)
        linked = b"\xa1" + struct.pack("<I", base + 6) + b"\xc3" + struct.pack("<I", base)
        image = (linked, base, [(".text", 0, len(linked), 0, len(linked))])
        body = coff_object([(b".text", raw, [(1, 1, 0x06), (6, 0, 0x06)])],
                           [(b"_entry", 0, 1, 0x20, 2, 0), (b"_table", 6, 1, 0, 3, 0)])
        with tempfile.TemporaryDirectory() as scratch, patch.object(match_decomp, "pe_image", return_value=image):
            obj = Path(scratch) / "test.obj"
            obj.write_bytes(body)
            result = match_decomp.match_object(base, obj, {}, 6, "_entry", strict=True)
            self.assertTrue(result["strict_match"])
            self.assertEqual([s["kind"] for s in result["linked_spans"]], ["primary", "inline_tail"])
            self.assertEqual(result["linked_spans"][1]["hex_bytes"], linked[6:].hex())
            self.assertEqual(result["linked_spans"][1]["fixup_sites"], [hex(base + 6)])
            padding = coff_object([(b".text", linked[:6] + b"\x90" * 4, [])],
                                  [(b"_entry", 0, 1, 0x20, 2, 0)])
            obj.write_bytes(padding)
            stripped = match_decomp.match_object(base, obj, {}, 6, "_entry", strict=True)
            self.assertTrue(stripped["strict_match"])
            self.assertEqual([s["kind"] for s in stripped["linked_spans"]], ["primary"])

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

            def write_record(address, name, length=1, strict=True, flags=("/O2",)):
                (records / name).write_text(json.dumps({
                    "address": hex(address), "length": length, "strict_match": strict,
                    "source": source.name, "source_sha256": digest(source.read_bytes()),
                    "executable_sha256": "guest", "compiler": {"sha256": compiler},
                    "linked_sections": ["primary"], "entry": "_f", "flags": flags,
                    "symbol_overrides": {},
                }))

            write_record(base + 1, "a.json")
            write_record(base + 2, "b.json", flags=("/Od",))
            write_record(base + 2, "c.json")
            write_record(base + 3, "d.json", strict=False)
            lengths = {base: 2, base + 1: 1, base + 2: 1}
            with (patch.object(linker, "ROOT", root),
                  patch.object(linker, "function_lengths", return_value=lengths)):
                items, excluded, count, deferred = linker.batch_plan(root, image, "guest", compiler, [base + 2], 1)
                self.assertEqual([(entry.address, entry.audit_record) for entry in items], [(base + 2, "b.json")])
                self.assertEqual(items[0].flags, ("/Od",))
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

    def test_assessment_retains_blocked_object_and_rechecks_it_without_compiling(self):
        base, target = 0x401000, 0x402000
        original = b"\xe8" + struct.pack("<i", target - base - 5) + b"\xc3"
        image = (original, base, [(".text", 0, len(original), 0, len(original))])
        obj_data = coff_object([(b".text", b"\xe8\0\0\0\0\xc3", [(1, 1, 0x14)])],
                               [(b"_f", 0, 1, 0x20, 2, 0), (b"_missing", 0, 0, 0x20, 2, 0)])

        def compile_fixture(source, vc6, output, flags, *, environment):
            output.write_bytes(obj_data)

        with tempfile.TemporaryDirectory() as scratch:
            root = Path(scratch)
            source = root / "candidate.c"
            source.write_text("void f(void) {}\n")
            cache = root / "cache"
            cache.mkdir()
            recipe = linker.Recipe(base, len(original), 0, source, digest(source.read_bytes()), "_f", ("/O2",), {})
            args = (recipe, root, root, original, cache, "identity")
            with (patch.object(linker, "compile_candidate", side_effect=compile_fixture) as compile_call,
                  patch.object(match_decomp, "pe_image", return_value=image)):
                with patch.object(match_decomp, "resolve_auto_symbol", return_value=(None, None)):
                    spans, before = linker.verify_recipe(*args, assess=True)
                    self.assertIsNone(spans)
                    self.assertEqual((before["status"], before["cache"]), ("blocked", "miss"))
                    self.assertEqual(next(cache.glob("*.obj")).read_bytes(), obj_data)
                    with self.assertRaisesRegex(ValueError, "strict match failed"):
                        linker.verify_recipe(*args, cache_only=True)
                with patch.object(match_decomp, "resolve_auto_symbol", return_value=(target, "exact_symbol")):
                    spans, after = linker.verify_recipe(*args, cache_only=True, assess=True)
                    self.assertEqual(spans[0]["hex_bytes"], original.hex())
                    self.assertEqual((after["status"], after["cache"]), ("strict", "hit"))
                    self.assertEqual(before["object"]["sha256"], after["object"]["sha256"])
                compile_call.assert_called_once()

    def test_cache_only_batch_assessment_reports_each_missing_object(self):
        with tempfile.TemporaryDirectory() as scratch:
            root = Path(scratch)
            source = root / "source.c"
            source.write_text("void f(void) {}\n")
            recipes = [linker.Recipe(0x401000 + i, 1, i, source, digest(source.read_bytes()), "_f", ("/O2",), {})
                       for i in range(2)]
            with patch.object(linker, "compile_candidate") as compile_call:
                results = linker.verify_batch(recipes, 2, root, root, bytes(2), root, "identity", {},
                                              cache_only=True, assess=True)
                compile_call.assert_not_called()
            path = root / "report.json"
            self.assertEqual(linker.write_assessment(path, results, root, "image", True), 1)
            report = json.loads(path.read_text())
            self.assertEqual(report["summary"]["statuses"], {"cache_missing": 2})
            self.assertEqual([row["address"] for row in report["candidates"]], ["0x401000", "0x401001"])

    def test_image_assembly_rejects_overlap_even_when_bytes_match(self):
        self.assertEqual(linker.assemble_image(b"xyz", [(2, b"z"), (0, b"x")]), b"xyz")
        with self.assertRaisesRegex(ValueError, "write ranges overlap"):
            linker.assemble_image(b"xyz", [(0, b"xy"), (1, b"yz")])

    def test_shared_span_is_written_once_and_conflicts_are_rejected(self):
        shared = {"start": "0x405000", "file_offset": "0x10", "length": 2,
                  "kind": "secondary", "hex_bytes": "1234"}
        self.assertEqual(linker.merged_spans([("a", [shared]), ("b", [shared])]),
                         [{**shared, "owners": ["a", "b"]}])
        for conflict in ({**shared, "hex_bytes": "1235"}, {**shared, "kind": "primary"}):
            with self.assertRaisesRegex(ValueError, "conflicting linked spans"):
                linker.merged_spans([("a", [shared]), ("b", [conflict])])
        for overlap in ({**shared, "start": "0x405001", "file_offset": "0x20"},
                        {**shared, "start": "0x406000", "file_offset": "0x11"}):
            with self.assertRaisesRegex(ValueError, "partially overlapping linked spans"):
                linker.merged_spans([("a", [shared]), ("b", [overlap])])

    def test_stock_and_compiled_at_same_va_keep_one_verified_owner(self):
        body = {"start": "0x401000", "length": 1, "file_offset": "0x1000", "hex_bytes": "c3"}
        function = {"function": {"start": body["start"]}, "linked_spans": [body]}
        archive = {**function, "archive_proof": {"member": "fixture.obj"}}
        writes = []
        added, deduplicated = linker.append_stock_functions([function], writes, [archive])
        self.assertEqual((added, writes), ([], []))
        self.assertEqual(deduplicated, [{"address": body["start"], "owner": "compiled_source",
                                          "archive_proof": archive["archive_proof"]}])
        conflicting = {**archive, "linked_spans": [{**body, "hex_bytes": "90"}]}
        with self.assertRaisesRegex(ValueError, "archive and compiled function conflict"):
            linker.append_stock_functions([function], [], [conflicting])

    def test_reverse_dependencies_distinguish_explicit_and_blocked_facts(self):
        with tempfile.TemporaryDirectory() as tmp:
            directory = Path(tmp)
            source = directory / "a.c"
            for address, origin in [(0x401000, "symbol_registry"), (0x402000, "explicit_symbol"), (0x403000, None)]:
                row = {"address": hex(address), "source": str(source), "strict_match": bool(origin),
                       "executable_sha256": "image", "relocations": [
                           {"symbol": "?A", "verified": bool(origin), "origin": origin}],
                       "linked_sections": [{"address": "0x405000"}] if origin else [],
                       "blocked_sections": [{"symbols": ["?A"], "expected_addresses": ["0x405000"]}] if not origin else []}
                (directory / f"{address:x}.json").write_text(json.dumps(row))
            impact = reverse_dependencies(directory, set(), set(), set(), {"?A"}, False, "image")
            self.assertEqual(impact["addresses"], ["0x401000", "0x403000"])
            self.assertEqual(impact["strict_addresses"], ["0x401000"])
            self.assertEqual(impact["blocked_addresses"], ["0x403000"])
            reverse = reverse_dependencies(directory, {"?A"}, {0x405000}, {source}, set(), False, "image")
            self.assertEqual(reverse["addresses"], ["0x401000", "0x402000", "0x403000"])
            self.assertEqual({d["kind"] for d in reverse["records"][0]["references"]},
                             {"symbol", "source", "section_address"})

    def test_blocker_ranking_counts_only_distinct_still_blocked_bodies(self):
        with tempfile.TemporaryDirectory() as scratch:
            root = Path(scratch)

            def make_row(filename, address, names, extra_issue=None, strict=False, registry=None):
                fixups = [{"symbol": name, "target": None, "verified": False, "section": ".text", "offset": hex(i)}
                          for i, name in enumerate(names)]
                issues = [f".text relocation at {fixup['offset']}: unresolved symbol {fixup['symbol']}" for fixup in fixups]
                if extra_issue:
                    issues.append(extra_issue)
                (root / filename).write_text(json.dumps({"address": address, "executable_sha256": "image",
                                                         "match": True, "strict_match": strict,
                                                         "relocations": fixups, "strict_issues": issues,
                                                         "symbol_registry_sha256": registry}))

            make_row("a.json", "0x401000", ["?A", "?A"])
            make_row("b.json", "0x402000", ["?A", "?B"])
            make_row("c.json", "0x403000", ["?B"], "unverified .rdata section")
            make_row("d.json", "0x404000", ["?B"])
            make_row("e.json", "0x404000", [], strict=True)
            result = rank_blockers(root, "image")
            self.assertEqual(result["body_only_addresses"], 3)
            self.assertEqual([(row["symbol"], row["sole_blockers"], row["affected"]) for row in result["symbols"]],
                             [("?A", 1, 2), ("?B", 0, 2)])
            make_row("f.json", "0x402000", ["?B"], registry="current")
            with patch.object(audit_symbol_targets, "file_sha256", return_value="current"):
                updated = rank_blockers(root, "image")
            self.assertEqual([(row["symbol"], row["sole_blockers"], row["affected"]) for row in updated["symbols"]],
                             [("?B", 1, 2), ("?A", 1, 1)])

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
