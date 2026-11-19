#!/usr/bin/env python3
"""Cross-check the Python scene builder against the Rust draw list."""

import json
import os
import subprocess
import sys
import tempfile
import unittest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TOOL = os.path.join(ROOT, "tools", "scene_tool.py")
MAP = os.path.join(ROOT, "game", "Isokarten", "Ber.iso")
RUST_DRAWS = os.path.join(
    ROOT, "decompiled_fastfood2_named_v2", "samples", "berlin_draws.json")


class SceneToolTests(unittest.TestCase):
    def test_berlin_draw_list_matches_rust(self):
        if not os.path.isfile(MAP) or not os.path.isfile(RUST_DRAWS):
            self.skipTest("Berlin map or Rust draw list is not available")
        with tempfile.TemporaryDirectory() as directory:
            output = os.path.join(directory, "crop.png")
            draws = os.path.join(directory, "draws.json")
            result = subprocess.run(
                [sys.executable, TOOL, MAP, "--output", output, "--json", draws],
                cwd=ROOT, text=True, capture_output=True)
            self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
            self.assertIn(
                "tiles=2166 layers=1861 draws=125 "
                "rgba_fnv=8bde36a26c5c0ff0",
                result.stdout,
            )
            with open(draws) as handle:
                python_draws = json.load(handle)
            with open(RUST_DRAWS) as handle:
                rust_draws = json.load(handle)
        self.assertEqual(python_draws["draws"], 125)
        self.assertEqual(python_draws["ordered_draws"], rust_draws["ordered_draws"])
        self.assertEqual(python_draws["crop"], rust_draws["crop"])
        self.assertEqual(python_draws["grid"], rust_draws["grid"])
        self.assertEqual(python_draws["view"], rust_draws["view"])


if __name__ == "__main__":
    unittest.main()
