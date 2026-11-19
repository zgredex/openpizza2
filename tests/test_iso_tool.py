#!/usr/bin/env python3
"""End-to-end tests for the .iso map parser."""

import json
import os
import subprocess
import sys
import tempfile
import unittest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TOOL = os.path.join(ROOT, "tools", "iso_tool.py")
sys.path.insert(0, os.path.join(ROOT, "tools"))
MAPS = os.path.join(ROOT, "game", "Isokarten")


def run(*args):
    return subprocess.run([sys.executable, TOOL, *args],
                          capture_output=True, text=True, cwd=ROOT)


class IsoToolTests(unittest.TestCase):
    def test_scan_all_maps(self):
        r = run("scan", MAPS)
        self.assertEqual(r.returncode, 0, r.stdout + r.stderr)
        self.assertIn("25 OK, 0 failed", r.stdout)

    def test_berlin_header_and_tiles(self):
        path = os.path.join(MAPS, "Ber.iso")
        r = run("info", path, "--json")
        data = json.loads(r.stdout)
        self.assertEqual(data["grid"], "164x164")
        self.assertEqual(data["list1"], 673)
        self.assertEqual(data["list2"], 970)
        self.assertEqual(data["tiles_present"], 2166)
        self.assertEqual(data["background"], "berlin_a.tga")
        self.assertEqual(data["problems"], [])

    def test_branch_map(self):
        path = os.path.join(MAPS, "Iso_Filiale_roh_gross.iso")
        r = run("info", path, "--json")
        data = json.loads(r.stdout)
        self.assertEqual(data["grid"], "280x280")
        self.assertEqual(data["tiles_present"], 4094)
        self.assertEqual(data["problems"], [])

    def test_tiles_and_lists_json(self):
        path = os.path.join(MAPS, "Ber.iso")
        r = run("tiles", path, "--json", "--limit", "5")
        tiles = json.loads(r.stdout)
        self.assertEqual(len(tiles), 5)
        self.assertTrue(all("layer1" in t and "layer2" in t for t in tiles))
        r = run("lists", path, "--json", "--limit", "3")
        lists = json.loads(r.stdout)
        self.assertEqual(len(lists), 2)
        self.assertEqual(len(lists[0]), 3)
        self.assertEqual(lists[0][0]["object_id"], 1)

    def test_path_graph(self):
        from iso_tool import PathGraph
        graph = PathGraph.from_iso(os.path.join(MAPS, "Ber.iso"))
        self.assertEqual(len(graph.nodes), 673)
        count, cost, path = graph.shortest_path(0, 100)
        self.assertEqual(count, 15)
        self.assertEqual(cost, 5184)
        self.assertEqual(len(path), 15)
        for u, v in zip(path, path[1:]):
            self.assertEqual(graph.step_cost(u, v),
                             3 * abs(graph.nodes[u].x - graph.nodes[v].x)
                             + 4 * abs(graph.nodes[u].y - graph.nodes[v].y))

    def test_preview_png(self):
        path = os.path.join(MAPS, "Ber.iso")
        with tempfile.TemporaryDirectory() as tmp:
            out = os.path.join(tmp, "ber.png")
            r = run("preview", path, out, "--scale", "2")
            self.assertEqual(r.returncode, 0, r.stderr)
            with open(out, "rb") as fh:
                raw = fh.read()
            self.assertTrue(raw.startswith(b"\x89PNG\r\n\x1a\n"))
            self.assertGreater(len(raw), 1000)

    def test_csv_export(self):
        path = os.path.join(MAPS, "Lon.iso")
        with tempfile.TemporaryDirectory() as tmp:
            out = os.path.join(tmp, "lon.csv")
            r = run("csv", path, out)
            self.assertEqual(r.returncode, 0, r.stderr)
            with open(out) as fh:
                lines = fh.read().splitlines()
            self.assertEqual(len(lines), 1745)  # header + 1744 tiles
            self.assertTrue(lines[0].startswith("index,x,y"))


if __name__ == "__main__":
    unittest.main(verbosity=2)
