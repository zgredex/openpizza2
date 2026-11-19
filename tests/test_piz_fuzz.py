#!/usr/bin/env python3
"""Tests for the deterministic .piz synthetic-save fuzz oracle."""

import os
import struct
import sys
import tempfile
import time
import unittest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TOOLS = os.path.join(ROOT, "tools")
if TOOLS not in sys.path:
    sys.path.insert(0, TOOLS)

import fuzz_piz  # noqa: E402
from piz_payload import PizSave  # noqa: E402


SAMPLE_FULL = os.path.join(
    ROOT, "decompiled_fastfood2_named_v2", "samples", "synthetic_full.piz")


class PizFuzzTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.path = os.path.join(self.tmp.name, "fuzz_case.piz")

    def tearDown(self):
        self.tmp.cleanup()

    def parse(self, data):
        with open(self.path, "wb") as fh:
            fh.write(data)
        return PizSave(self.path)

    def test_200_deterministic_seeds_under_60s(self):
        started = time.perf_counter()
        summary = fuzz_piz.run(seed_count=200, include_boundary=False)
        elapsed = time.perf_counter() - started
        self.assertEqual(summary["failed"], 0, summary["mismatches"])
        self.assertEqual(summary["passed"], 200)
        self.assertEqual(summary["cases"], 200)
        self.assertEqual(summary["seed_count"], 200)
        self.assertEqual(summary["boundary_count"], 0)
        self.assertGreater(summary["bytes_min"], 0)
        self.assertGreaterEqual(summary["bytes_max"], summary["bytes_min"])
        self.assertEqual(len(summary["corpus_sha256"]), 64)
        self.assertLess(elapsed, 60.0)

    def test_seed_determinism(self):
        first = fuzz_piz.fuzz_roundtrip(4242)
        second = fuzz_piz.fuzz_roundtrip(4242)
        other = fuzz_piz.fuzz_roundtrip(4243)
        self.assertEqual(first, second)
        self.assertEqual(first["sha256"], second["sha256"])
        self.assertNotEqual(first["sha256"], other["sha256"])

    def test_boundary_corpus_roundtrips(self):
        cases = fuzz_piz.boundary_corpus()
        names = {case.name for case in cases}
        self.assertTrue(
            {"empty", "max_counts", "zero_globals", "max_strings"} <= names)
        for case in cases:
            with self.subTest(case=case.name):
                result = fuzz_piz.verify_bytes(
                    case.encoded.data,
                    expected_model=case.model,
                    expected_directory=case.encoded.directory,
                    label=f"boundary {case.name}",
                )
                self.assertEqual(result["size"], len(case.encoded.data))

    def test_size_and_directory_framing(self):
        cases = {case.name: case for case in fuzz_piz.boundary_corpus()}
        for name in ("empty", "max_counts", "max_strings"):
            case = cases[name]
            data = case.encoded.data
            save = self.parse(data)
            with self.subTest(case=name):
                self.assertEqual(save.problems, [])
                self.assertEqual(len(data), save.directory[7])
                self.assertEqual(
                    data[fuzz_piz.DIRECTORY_OFFSET:
                         fuzz_piz.DIRECTORY_OFFSET + fuzz_piz.DIRECTORY_SIZE],
                    struct.pack("<8I", *save.directory),
                )
                self.assertEqual(
                    data[0x110:0x114], struct.pack("<I", fuzz_piz.START_MARKER))
                self.assertEqual(save.briefing_start, fuzz_piz.BRIEFING_START)
                self.assertEqual(
                    len(data[fuzz_piz.FIXED_PREFIX_START:
                             save.briefing_start]),
                    fuzz_piz.FIXED_PREFIX_SIZE,
                )
                self.assertEqual(fuzz_piz.FIXED_PREFIX_SIZE, 1735)
                self.assertEqual(save.tile_start, save.briefing_end)
                self.assertEqual(
                    save.tile_end - save.tile_start, fuzz_piz.TILE_TABLE_SIZE)
                self.assertEqual(
                    struct.unpack_from("<I", data, len(data) - 4)[0],
                    fuzz_piz.END_MARKER,
                )
                self.assertEqual(
                    struct.unpack_from("<I", data, 0xE8)[0], fuzz_piz.VERSION)
                self.assertEqual(
                    struct.unpack_from("<I", data, 0xEC)[0], fuzz_piz.MAGIC)
                order = [save.directory[i] for i in (1, 2, 0, 6, 4, 3, 5, 7)]
                self.assertEqual(order, sorted(order))
                self.assertEqual(save.directory[7], len(data))

        empty = cases["empty"].encoded.data
        self.assertEqual(len(empty), 129307)
        empty_save = self.parse(empty)
        self.assertEqual(empty_save.counts, {
            "isomaps": 0, "characters": 0, "cities": 0, "persons": 0, "cars": 0})
        self.assertEqual(len(empty_save.briefing), 0)
        self.assertTrue(all(name == "" for name in empty_save.tile_names))
        self.assertTrue(all(
            slot["present"] == 0 for slot in empty_save.parse_players()["slots"]))

        max_save = self.parse(cases["max_counts"].encoded.data)
        self.assertEqual(max_save.counts["characters"], 8)
        self.assertEqual(max_save.counts["isomaps"], 4)
        self.assertEqual(max_save.counts["persons"], 8)
        self.assertEqual(max_save.counts["cars"], 8)
        self.assertEqual(len(max_save.briefing), 16)
        self.assertEqual(
            sum(slot["present"] for slot in max_save.parse_players()["slots"]),
            6,
        )

    def test_zero_globals_and_max_length_strings(self):
        cases = {case.name: case for case in fuzz_piz.boundary_corpus()}

        zero = self.parse(cases["zero_globals"].encoded.data)
        self.assertEqual(
            cases["zero_globals"].encoded.data[
                fuzz_piz.FIXED_PREFIX_START:fuzz_piz.BRIEFING_START],
            b"\0" * fuzz_piz.FIXED_PREFIX_SIZE,
        )
        for row in zero.global_values():
            if row["value"] is not None:
                self.assertEqual(row["value"], 0, row)
            else:
                self.assertEqual(row["hex"], "00" * row["size"], row)

        maximum = self.parse(cases["max_strings"].encoded.data)
        self.assertEqual(len(maximum.header.title), 63)
        self.assertEqual(len(maximum.header.company), 63)
        self.assertEqual(len(maximum.header.city), 63)
        self.assertEqual(len(maximum.briefing), 4)
        self.assertTrue(all(entry.length == 4096 for entry in maximum.briefing))
        self.assertEqual(len(maximum.tile_names), 2500)
        self.assertTrue(all(len(name) == 49 for name in maximum.tile_names))

    def test_run_summary_hash_is_stable(self):
        first = fuzz_piz.run(seed_count=10, include_boundary=True)
        second = fuzz_piz.run(seed_count=10, include_boundary=True)
        self.assertEqual(first["mismatches"], [])
        self.assertEqual(first["failed"], 0)
        self.assertEqual(first["cases"], 16)
        self.assertEqual(first["corpus_sha256"], second["corpus_sha256"])
        self.assertEqual(first["bytes_min"], second["bytes_min"])
        self.assertEqual(first["bytes_max"], second["bytes_max"])
        self.assertIn("runtime_seconds", first)

    @unittest.skipUnless(
        os.path.exists(SAMPLE_FULL), "synthetic_full.piz sample missing")
    def test_synthetic_full_sample_roundtrip(self):
        with open(SAMPLE_FULL, "rb") as fh:
            data = fh.read()
        self.assertEqual(len(data), 134442)
        result = fuzz_piz.verify_bytes(data, label="synthetic_full")
        self.assertEqual(result["size"], 134442)


if __name__ == "__main__":
    unittest.main(verbosity=2)
