"""Check replay-state coverage and ranking from small captured fixtures."""

import hashlib
import json
from pathlib import Path
import sys
import tempfile
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[3] / "tools"))
import replay_worklist as worklist


def entry(address, *ranges, split=False):
    return {"address": address, "name": address, "body": {"non_contiguous": split,
            "ranges": [{"start": hex(start), "end": hex(end)} for start, end in ranges]}}


class ReplayWorklistTests(unittest.TestCase):
    def test_coverage_keeps_split_bodies_and_rejects_wrong_manifest_proof(self):
        image = (b"\xc3" * 16, 0x401000, [(".text", 0, 16, 0, 16)])
        indexed = worklist.inventory({"contiguous": entry("0x401000", (0x401000, 0x401000)),
                                      "split": entry("0x401004", (0x401004, 0x401005), (0x40100a, 0x40100c), split=True),
                                      "external": entry("EXTERNAL:0x1")})
        manifest = {"schema": "pc2.verified_linked_image_batch.v1", "original": {"sha256": "pinned"},
                    "input": {"sha256": "pinned"}, "output": {"sha256": "pinned"}, "functions": [
                        {"provider": "stock_archive", "function": {"start": "0x401000", "length": 1,
                         "end_exclusive": "0x401001", "sha256": hashlib.sha256(b"\xc3").hexdigest()}}]}
        linked = worklist.verified_functions(manifest, image, indexed, "pinned")
        self.assertEqual(worklist.coverage({0x401000, 0x401004, 0x401008}, indexed, linked),
                         {"indexed_reached": 2, "linked_reached": 1, "indexed_bytes": 6,
                          "linked_bytes": 1, "linked_by_provider": {"stock_archive": 1}, "noncontiguous_reached": 1})
        manifest["functions"][0]["function"]["sha256"] = "wrong"
        with self.assertRaisesRegex(ValueError, "invalid or duplicate linked function"):
            worklist.verified_functions(manifest, image, indexed, "pinned")

    def test_capture_edges_inform_dependencies_without_claiming_unseen_coverage(self):
        start, seen_callee, unseen_callee = 0x401000, 0x401010, 0x401020
        indexed = {va: {"bytes": 4, "contiguous": True} for va in (start, seen_callee, unseen_callee)}

        def edge(target, kind, resolution="resolved", **detail):
            return {"caller": hex(start), "site": hex(start + 1), "target": hex(target), "kind": kind,
                    "resolution": resolution, "count": 3, **detail}

        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "report.json"
            data = {"format": "pc2.capture.v1", "scenario": "fixture", "complete": False,
                    "run": {"guest_sha256": "pinned"}, "phases": [{"name": "phase", "functions": [
                        {"address": hex(va), "count": 1} for va in (start, seen_callee, 0x401030)], "edges": [
                        edge(seen_callee, "indirect"), edge(unseen_callee, "direct"),
                        edge(0x7f004704, "indirect", target_kind="hle_import"),
                        edge(0xDEAD0000, "return_jump", "return_sentinel"), edge(0x401050, "indirect", "no_dispatch")]}]}
            path.write_text(json.dumps(data))
            phases, reached, observed, inbound, deps, callers, unknown, unresolved = worklist.load_replays(
                [path], indexed, {seen_callee: "compiled_c"}, "pinned")
            self.assertEqual(phases[0]["linked_addresses"], [hex(seen_callee)])
            self.assertEqual(phases[0]["indexed_reached"], 2)
            self.assertEqual(len(phases[0]["unindexed"]), 1)
            self.assertEqual(phases[0]["unresolved_edge_events"], 3)
            self.assertEqual(phases[0]["guest_indirect_edge_records"], 2)
            self.assertNotIn(unseen_callee, reached)
            self.assertIn("return_sentinel", {record["resolution"] for record in observed[start]})
            self.assertEqual(inbound[seen_callee][0]["kind"], "indirect")
            self.assertEqual(deps[start], {seen_callee, unseen_callee})
            self.assertFalse(unknown)
            self.assertEqual(len(unresolved[start]), 1)
            with self.assertRaisesRegex(ValueError, "capture SHA-256"):
                worklist.load_replays([path], indexed, {}, "different")

    def test_groups_keep_observed_neighbors_and_readiness_separate(self):
        a, b, c, d = (0x401000 + i * 0x10 for i in range(4))
        indexed = {address: {"bytes": 4, "contiguous": True} for address in (a, b, c, d)}
        groups = worklist.rank_groups({a, b, c}, indexed, {d: "compiled_c"},
                                      {a: {1, 2}, b: {2}, c: {3}}, {a: {b, d}}, {b: {a}},
                                      {a: {c}}, {}, {}, 2)
        self.assertEqual(groups[0]["addresses"], [hex(a), hex(b)])
        self.assertEqual(groups[0]["phases"], [1, 2])
        self.assertEqual(groups[0]["dependencies"]["verified"], [hex(d)])
        self.assertEqual(groups[0]["dependencies"]["uncovered_indexed"], [hex(c)])
        self.assertEqual(groups[0]["code_bytes"], 8)


if __name__ == "__main__":
    unittest.main()
