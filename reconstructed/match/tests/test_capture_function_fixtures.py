"""Check capture-derived routing and guarded bootless function verification."""

import json
from pathlib import Path
import sys
import tempfile
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[3] / "tools" / "pcrecomp_pc2"))
import function_fixtures as fixtures
from instrument_capture import instrument_generated


class CaptureFixtureTests(unittest.TestCase):
    def test_instrumentation_wraps_both_entries_and_captures_the_cpu_operand(self):
        generated = ('#include "recomp_types.h"\n'
                     'void a(void) {\n    RECOMP_ENTER(0x00539F20u);\n'
                     '    CPUID(eax, ebx, ecx, edx); /* 0x00539F68: cpuid */\n}\n'
                     'void b(void) {\n    RECOMP_ENTER(0x0052A3A0u);\n}\n'
                     'void c(void) {\n    RECOMP_ENTER(0x0052A3A1u);\n}\n')
        converted = instrument_generated(generated)
        self.assertEqual(converted.count("PC2_CAPTURE_FIXTURE_SCOPE"), 2)
        self.assertIn("pc2_fixture.before[1] = edx;", converted)

    def test_extract_caches_deduplicated_snapshots_and_rejects_tampering(self):
        surface = fixtures.SNAPSHOT.pack(fixtures.SURFACE, 0x12340000, 0, 0,
                                         7, 0x800000, 1, 0, 0, 1, 0, 0, 0, 0)
        clamp = fixtures.SNAPSHOT.pack(fixtures.CLAMP, 0x22340000, 150, 2,
                                       0, 7, 100, 0, 1, 100, 7, 100, 0, 1)
        callback = fixtures.SNAPSHOT.pack(fixtures.CLAMP, 0x32340000, 150, 2,
                                          0, 7, 100, 1, 1, 100, 7, 100, 1, 1)
        with tempfile.TemporaryDirectory() as temporary:
            directory = Path(temporary)
            snapshots = directory / "function-fixtures.bin"
            snapshots.write_bytes(surface * 2 + clamp + callback)
            run = {"guest_sha256": fixtures.PE_HASH,
                   "function_fixtures": {"format": "pc2.function_snapshots.v1",
                                         "sha256": fixtures.sha256(snapshots.read_bytes())}}
            (directory / "run.json").write_text(json.dumps(run))
            (directory / "report.json").write_text(json.dumps({"run": run, "complete": True,
                                                             "format": "pc2.capture.v1", "scenario": "test"}))
            fixture, hit = fixtures.extract(directory, directory / "cache")
            self.assertFalse(hit)
            self.assertEqual(fixture["skipped"], {"clamp text callback": 1})
            self.assertEqual([row["name"] for row in fixture["cases"]], ["Surface_ResetFlags", "UI_SetClampedValue"])
            self.assertEqual(fixture["cases"][0]["cpuid_edx"], 0x800000)
            self.assertEqual(fixture["cases"][1]["after"]["0x94"], 100)
            self.assertEqual(fixtures.extract(directory, directory / "cache"), (fixture, True))
            snapshots.write_bytes(surface)
            with self.assertRaisesRegex(ValueError, "SHA-256"):
                fixtures.extract(directory, directory / "cache")

    def test_bootless_original_and_intentional_regressions(self):
        try:
            import unicorn
            import pefile
        except ImportError as error:
            self.skipTest(str(error))
        fixture = fixtures.reference_cases()
        good = fixtures.verify(fixture, repeat=3)
        self.assertEqual(good["passed"], {"Surface_ResetFlags": 3, "UI_SetClampedValue": 9})
        self.assertFalse(good["failures"])
        bad = fixtures.verify(fixture, regression=True)
        self.assertEqual({row["function"] for row in bad["failures"]}, {"Surface_ResetFlags", "UI_SetClampedValue"})
        self.assertFalse(bad["passed"])

    def test_compiled_probe_cache_and_verdict_routing(self):
        try:
            import unicorn
            import pefile
        except ImportError as error:
            self.skipTest(str(error))
        fixture = fixtures.reference_cases()
        fixture["cases"] = [row for row in fixture["cases"] if row["address"] == hex(fixtures.SURFACE)]
        expected = fixture["cases"][0]["after"]["0x74"]
        with tempfile.TemporaryDirectory() as temporary:
            directory = Path(temporary)
            source = directory / "probe.c"
            cache = directory / "cache"
            form = 'void __attribute__((thiscall)) pc2_candidate(unsigned char *p) { *(unsigned *)(p + 0x74) = %d; }\n'
            source.write_text(form % expected)
            cold = fixtures.verify(fixture, source=source, repeat=3, cache=cache)
            warm = fixtures.verify(fixture, source=source, repeat=3, cache=cache)
            self.assertEqual(cold["candidate"]["cache"], "miss")
            self.assertEqual(warm["candidate"]["cache"], "hit")
            self.assertEqual(cold["candidate"]["sha256"], warm["candidate"]["sha256"])
            self.assertEqual(warm["route"], "strict_match")
            source.write_text(form % (expected ^ 1))
            rejected = fixtures.verify(fixture, source=source, cache=cache)
            self.assertEqual(rejected["candidate"]["cache"], "miss")
            self.assertEqual(rejected["route"], "inspect_mismatch")
            self.assertEqual(rejected["failures"][0]["fields"]["0x74"]["expected"], expected)


if __name__ == "__main__":
    unittest.main()
