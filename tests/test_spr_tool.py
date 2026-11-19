#!/usr/bin/env python3
"""Fixture and corpus tests for the .spr decoder."""

import os
import struct
import sys
import unittest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))

from spr_tool import decode_spr  # noqa: E402


def fnv1a(data: bytes) -> int:
    value = 0xCBF29CE484222325
    for byte in data:
        value ^= byte
        value = (value * 0x100000001B3) & 0xFFFFFFFFFFFFFFFF
    return value


def build_sprite(width, height, body, palette, flags=0x07, bpp=8):
    header = bytearray(0x21)
    header[4] = 8
    header[5] = flags
    header[6] = bpp
    struct.pack_into("<H", header, 7, width * (bpp // 8))
    struct.pack_into("<H", header, 9, height)
    struct.pack_into("<H", header, 0x13, width)
    struct.pack_into("<H", header, 0x15, height)
    struct.pack_into("<I", header, 0x19, len(body))
    struct.pack_into("<I", header, 0x1D, 0xFF)
    return bytes(header) + body + (palette if bpp == 8 else b"")


class SprToolTests(unittest.TestCase):
    def test_palette_follows_pixel_stream(self):
        palette = bytearray(0x300)
        palette[0:3] = bytes((10, 20, 30))
        palette[3:6] = bytes((40, 50, 60))
        data = build_sprite(2, 2, bytes((0, 1, 0xFF, 1)), palette)
        header, rgba = decode_spr(data)
        self.assertEqual((header.width, header.height), (2, 2))
        self.assertEqual(rgba[0:4], bytes((30, 20, 10, 255)))
        self.assertEqual(rgba[4:8], bytes((60, 50, 40, 255)))
        self.assertEqual(rgba[8:12], bytes((0, 0, 0, 0)))

    def test_berlin_tree_hash_matches_rust(self):
        path = os.path.join(
            ROOT, "extracted", "isodaten", "sprites", "b_laub_b.spr")
        if not os.path.isfile(path):
            self.skipTest("extracted Berlin tree sprite is not available")
        with open(path, "rb") as handle:
            header, rgba = decode_spr(handle.read())
        self.assertEqual((header.width, header.height, header.bpp), (144, 106, 8))
        self.assertEqual(fnv1a(rgba), 0x8C144B3BF0B94E51)
        self.assertEqual(sum(1 for i in range(0, len(rgba), 4) if rgba[i + 3]), 6619)

    def test_sixteen_bit_sample_hash_matches_rust(self):
        path = os.path.join(ROOT, "extracted", "sprites", "pb07__01.spr")
        if not os.path.isfile(path):
            self.skipTest("extracted 16bpp sample is not available")
        with open(path, "rb") as handle:
            header, rgba = decode_spr(handle.read())
        self.assertEqual((header.width, header.height, header.bpp), (29, 29, 16))
        self.assertEqual(fnv1a(rgba), 0x4B1DA7C6DA626011)
        self.assertEqual(sum(1 for i in range(0, len(rgba), 4) if rgba[i + 3]), 837)


if __name__ == "__main__":
    unittest.main()
