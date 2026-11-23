"""Standalone smoke tests: python3 tests_roi_family_queue.py"""
import importlib.util
import json
from pathlib import Path
import tempfile
import unittest

PATH = Path(__file__).parent.parent / "tools" / "roi_family_queue.py"
spec = importlib.util.spec_from_file_location("roi", PATH)
roi = importlib.util.module_from_spec(spec)
spec.loader.exec_module(roi)

class TestFamilyQueue(unittest.TestCase):
    def test_strict_and_overlaps_not_double_counted(self):
        payload = {"schema":"pc2.family_registry.v1", "families":[
            {"cleanup_target":"A", "members":[
                {"address":"0x1000", "length":10, "status":"strict"},
                {"address":"0x2000", "length":20, "status":"candidate"},
                {"address":"0x3000", "length":30, "status":"missing"}]},
            {"cleanup_target":"B", "members":[
                {"address":"0x2000", "length":20, "status":"candidate"},
                {"address":"0x4000", "length":40, "status":"generated"}]}]}
        report = roi.summarize(payload, {0x4000})
        self.assertEqual(report["pending_unique_bytes"], 50)
        self.assertEqual(report["pending_unique_addresses"], 2)
        self.assertEqual(report["strict_indexed_addresses"], 2)
        self.assertEqual(sum(r["unique_unmatched_bytes"] for r in report["ready_lane"]), 50)
        self.assertEqual(sum(r["unique_unmatched_bytes"] for r in report["discovery_lane"]), 50)

    def test_receipts_require_strict_match_true(self):
        with tempfile.TemporaryDirectory() as d:
            root = Path(d) / "functions"
            root.mkdir()
            (root / "a.json").write_text(json.dumps({"address":"0x1000", "strict_match":True}))
            (root / "b.json").write_text(json.dumps({"address":"0x2000", "strict_match":False}))
            self.assertEqual(roi.load_audit(Path(d)), {0x1000})

    def test_schema_rejection(self):
        with self.assertRaises(ValueError):
            roi.summarize({}, set())

if __name__ == "__main__":
    unittest.main()
