#!/usr/bin/env python3
"""End-to-end tests for the .piz payload tool and generated structs."""

import json
import os
import subprocess
import sys
import tempfile
import unittest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TOOL = os.path.join(ROOT, "tools", "piz_payload.py")
HEADER = os.path.join(ROOT, "decompiled_fastfood2_named_v2", "game_structs.h")


def run(*args):
    return subprocess.run([sys.executable, TOOL, *args],
                          capture_output=True, text=True, cwd=ROOT)


class PizPayloadTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.path = os.path.join(self.tmp.name, "test.piz")

    def tearDown(self):
        self.tmp.cleanup()

    def synth(self, *extra):
        r = run("synth", self.path, *extra)
        self.assertEqual(r.returncode, 0, r.stderr)

    def test_empty_save_roundtrip(self):
        self.synth()
        r = run("verify", self.path)
        self.assertEqual(r.returncode, 0, r.stdout + r.stderr)
        r = run("sections", self.path)
        self.assertIn("ui_briefing_list", r.stdout)
        self.assertIn("world_tile_name_table", r.stdout)
        self.assertIn("125000", r.stdout)

    def test_briefing_parse(self):
        self.synth("--briefing", "Welcome to London.", "--briefing", "Build a pizzeria.")
        r = run("get", self.path, "briefing[1].text")
        self.assertEqual(r.stdout.strip(), "Build a pizzeria.")
        r = run("dump", self.path, "--json")
        data = json.loads(r.stdout)
        self.assertEqual(len(data["briefing_entries"]), 2)
        self.assertEqual(data["problems"], [])

    def test_character_and_player_parse(self):
        self.synth("--one-character", "--one-player", "--rich-player")
        r = run("characters", self.path, "--json")
        data = json.loads(r.stdout)
        self.assertEqual(data["count"], 1)
        self.assertEqual(len(data["records"]), 1)
        self.assertEqual(data["errors"], [])
        r = run("players", self.path, "--json")
        data = json.loads(r.stdout)
        self.assertEqual(data["slots"][0]["present"], 1)
        self.assertEqual(len(data["slots"][0]["events"]), 1)
        self.assertIsNotNone(data["slots"][0]["ai"])
        self.assertIsNotNone(data["slots"][0]["mission"])
        self.assertEqual(data["errors"], [])

    def test_fixed_field_edits(self):
        self.synth()
        for path, value, expected in [
            ("header.title", "Edited Save", "Edited Save"),
            ("header.game_calendar[0]", "77", 77),
            ("game.scalar[3]", "123456", 123456),
            ("tile[7]", "Rome", "Rome"),
            ("global.g_CompanyMarketShare", "999", 999),
        ]:
            r = run("set", self.path, path, str(value))
            self.assertEqual(r.returncode, 0, r.stderr)
            r = run("get", self.path, path)
            self.assertEqual(r.stdout.strip(), str(expected))
        r = run("verify", self.path)
        self.assertEqual(r.returncode, 0, r.stdout + r.stderr)

    def test_globals_all_present(self):
        self.synth()
        r = run("globals", self.path, "--json")
        rows = json.loads(r.stdout)
        self.assertEqual(len(rows), 24)
        for row in rows:
            self.assertIsNotNone(row["file_offset"])
            self.assertTrue(row["name"].startswith("g_"))

    @unittest.skipUnless(os.path.exists(HEADER), "game_structs.h missing")
    def test_struct_header_compiles(self):
        src = os.path.join(self.tmp.name, "test_structs.c")
        with open(src, "w") as f:
            f.write('#include "decompiled_fastfood2_named_v2/game_structs.h"\n'
                    "#include <stddef.h>\n"
                    "_Static_assert(sizeof(Game) == 0x2f890, \"Game size\");\n"
                    "_Static_assert(sizeof(Company) == 0x1f0, \"Company size\");\n"
                    "_Static_assert(sizeof(Player) == 0xb0, \"Player size\");\n"
                    "_Static_assert(offsetof(Player, field_0x84) == 0x84, \"Player field\");\n"
                    "int main(void) { return 0; }\n")
        r = subprocess.run(["gcc", "-std=c11", "-fsyntax-only", "-I", ROOT, src],
                           capture_output=True, text=True)
        self.assertEqual(r.returncode, 0, r.stderr)


if __name__ == "__main__":
    unittest.main(verbosity=2)
