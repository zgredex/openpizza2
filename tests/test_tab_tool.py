#!/usr/bin/env python3
"""Tests for the `.tab` decoder."""

import json
import os
import subprocess
import sys
import tempfile
import unittest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TOOL = os.path.join(ROOT, "tools", "tab_tool.py")
DATA = os.path.join(ROOT, "extracted", "daten")
SIZE = os.path.join(DATA, "size.tab")
INGREDIENTS = os.path.join(DATA, "ingredients.tab")


def run(*args):
    return subprocess.run([sys.executable, TOOL, *args],
                          capture_output=True, text=True, cwd=ROOT)


class TabToolTests(unittest.TestCase):
    def test_size_info(self):
        r = run("info", SIZE, "--kind", "size")
        self.assertEqual(r.returncode, 0, r.stderr)
        data = json.loads(r.stdout)
        self.assertEqual(data["count"], 86)
        self.assertEqual(data["size"], 11008)
        self.assertEqual(data["record_size"], 128)

    def test_size_records(self):
        r = run("size-json", SIZE, tempfile.mktemp(suffix=".json"))
        self.assertEqual(r.returncode, 0, r.stderr)
        path = r.stdout.split("wrote ")[1].split(":")[0]
        with open(path) as fh:
            data = json.load(fh)
        os.unlink(path)
        self.assertEqual(len(data["records"]), 86)
        first = data["records"][0]["sizes"]
        self.assertEqual(len(first), 4)
        self.assertEqual(len(first[0]), 8)
        self.assertEqual((first[0][0]["w"], first[0][0]["h"]), (139, 140))
        self.assertEqual((first[3][7]["w"], first[3][7]["h"]), (138, 141))

    def test_size_csv(self):
        with tempfile.TemporaryDirectory() as tmp:
            out = os.path.join(tmp, "size.csv")
            r = run("size-csv", SIZE, out)
            self.assertEqual(r.returncode, 0, r.stderr)
            with open(out) as fh:
                lines = fh.read().splitlines()
            self.assertEqual(len(lines), 1 + 86 * 4 * 8)
            self.assertEqual(lines[0], "index,layer,slot,width,height")

    def test_ingredients_info(self):
        r = run("info", INGREDIENTS, "--kind", "ingredients")
        self.assertEqual(r.returncode, 0, r.stderr)
        data = json.loads(r.stdout)
        self.assertEqual(data["blocks"], 35776)
        self.assertEqual(data["size"], 4579328)
        self.assertEqual(data["block_size"], 128)
        self.assertEqual(data["bases"], 13)
        self.assertEqual(data["positions"], 32)

    def test_ingredient_block(self):
        r = run("block", INGREDIENTS, "--index", "0", "--json")
        self.assertEqual(r.returncode, 0, r.stderr)
        block = json.loads(r.stdout)
        self.assertEqual(block["base"], 0)
        self.assertEqual(block["layer"], 0)
        self.assertEqual(block["pairs"][:4],
                         [{"x": 197, "y": 22}, {"x": 198, "y": 22},
                          {"x": 151, "y": 27}, {"x": 103, "y": 43}])
        r = run("block", INGREDIENTS, "--index", "35775", "--json")
        self.assertEqual(r.returncode, 0, r.stderr)
        self.assertEqual(json.loads(r.stdout)["index"], 35775)


if __name__ == "__main__":
    unittest.main(verbosity=2)
