#!/usr/bin/env python3
"""Cross-check the Rust .ani decoder on the shipped tree sway."""

import os
import sys
import unittest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))

from ani_tool import decode_ani, fnv1a  # noqa: E402

ANI = os.path.join(
    ROOT, "extracted", "isodaten", "anims", "b_allee_a-b_allee_a.ani")


class AniToolTests(unittest.TestCase):
    def test_tree_sway_frames(self):
        if not os.path.isfile(ANI):
            self.skipTest("tree sway animation is not available")
        with open(ANI, "rb") as handle:
            count, frames = decode_ani(handle.read())
        self.assertEqual(count, 12)
        self.assertEqual(len(frames), 12)
        self.assertEqual(frames[0][:2], (44, 72))
        self.assertEqual(fnv1a(frames[0][2]), 0x6CD5E532690455F0)
        self.assertEqual(fnv1a(frames[1][2]), 0xAA33F95E8FC718B5)
        self.assertNotEqual(frames[0][2], frames[1][2])


if __name__ == "__main__":
    unittest.main()
