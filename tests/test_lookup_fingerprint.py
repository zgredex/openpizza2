"""Tests for tools/lookup_fingerprint.py."""
import importlib.util
import pathlib
import sys
import unittest

ROOT = pathlib.Path(__file__).resolve().parents[1]
MODULE = ROOT / "tools" / "lookup_fingerprint.py"
spec = importlib.util.spec_from_file_location("fingerprints", MODULE)
mod = importlib.util.module_from_spec(spec)
sys.modules[spec.name] = mod
spec.loader.exec_module(mod)


def payload():
    return {
        "schema": "pc2.compiler_fingerprints.v1",
        "entries": [
            {
                "id": "eh-frame",
                "title": "missing EH frame",
                "symptom": "candidate starts with push esi",
                "cause": "extern C calls are not throw sites",
                "source_pattern": "use C++ linkage",
                "counter_pattern": "extern C body",
                "tags": ["eh", "destructor"],
                "evidence": [{"address": "0x53fcc0", "file": "a"}],
            },
            {
                "id": "list-order",
                "title": "store order",
                "symptom": "four byte shift",
                "cause": "head stored before free",
                "source_pattern": "free before store",
                "counter_pattern": "store before free",
                "tags": ["schedule"],
                "evidence": [{"address": "0x5408b0", "file": "b"}],
            },
        ],
    }


class FingerprintTests(unittest.TestCase):
    def test_text_search_is_case_insensitive_and_anded(self):
        _, entries = mod.load_from_payload(payload())
        hits = mod.search(entries, ["EXTERN C", "linkage"])
        self.assertEqual([entry["id"] for entry in hits], ["eh-frame"])

    def test_tag_search_requires_every_tag(self):
        _, entries = mod.load_from_payload(payload())
        self.assertEqual([e["id"] for e in mod.search(entries, tags=["eh"])], ["eh-frame"])
        self.assertEqual(mod.search(entries, tags=["eh", "schedule"]), [])

    def test_address_matches_evidence(self):
        _, entries = mod.load_from_payload(payload())
        self.assertEqual([e["id"] for e in mod.search(entries, address=0x5408B0)],
                         ["list-order"])

    def test_render_includes_fix_and_evidence(self):
        _, entries = mod.load_from_payload(payload())
        text = mod.render(entries[0])
        self.assertIn("use C++ linkage", text)
        self.assertIn("0x53fcc0", text)

    def test_schema_rejection(self):
        with self.assertRaises(ValueError):
            mod.load_from_payload({})

    def test_checked_in_index_parses(self):
        payload, entries = mod.load(mod.DEFAULT_INDEX)
        self.assertEqual(payload["schema"], "pc2.compiler_fingerprints.v1")
        ids = {entry["id"] for entry in entries}
        self.assertIn("state-release-cpp-linkage", ids)
        self.assertIn("destructor-chain-inline-ancestors", ids)


if __name__ == "__main__":
    unittest.main()
