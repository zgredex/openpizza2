#!/usr/bin/env python3
"""Python cross-check for the Rust Berlin scene builder.

This is intentionally a small independent implementation of the same rules:
project tiles with the loader cell coordinates, anchor sprites at bottom-centre,
sort by ground line, and composite over the TGA background at `u28`/`u2c`.
It reads the already-extracted sprite files so the test does not depend on a
second PAK decoder.
"""

from __future__ import annotations

import argparse
import json
import os
import struct
import sys
import zlib
from pathlib import Path

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

import iso_tool  # noqa: E402
import spr_tool  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SPRITES = os.path.join(ROOT, "extracted", "isodaten", "sprites")
BACKGROUNDS = os.path.join(ROOT, "extracted", "backgrounds")


def fnv1a(data: bytes) -> int:
    value = 0xCBF29CE484222325
    for byte in data:
        value ^= byte
        value = (value * 0x100000001B3) & 0xFFFFFFFFFFFFFFFF
    return value


def load_tga(path: str):
    data = Path(path).read_bytes()
    id_length = data[0]
    cmap_length = struct.unpack_from("<H", data, 5)[0]
    cmap_depth = data[7]
    width, height = struct.unpack_from("<HH", data, 12)
    descriptor = data[17]
    offset = 18 + id_length
    entry_bytes = cmap_depth // 8
    palette = data[offset : offset + cmap_length * entry_bytes]
    offset += len(palette)
    indices = data[offset : offset + width * height]
    pixels = bytearray(width * height * 4)
    top_origin = bool(descriptor & 0x20)
    for index, value in enumerate(indices):
        source_y = index // width
        y = source_y if top_origin else height - 1 - source_y
        x = index % width
        entry = value * entry_bytes
        target = (y * width + x) * 4
        pixels[target] = palette[entry + 2]
        pixels[target + 1] = palette[entry + 1]
        pixels[target + 2] = palette[entry]
        pixels[target + 3] = 255
    return width, height, pixels


def tile_world(header, tile):
    return (
        (header.grid_h - tile.y + tile.x) * header.view_w // 2,
        (tile.x + tile.y) * header.view_h // 2,
    )


def build_scene(map_path: str, center=None, width=800, height=600):
    iso = iso_tool.IsoMap(map_path)
    header = iso.header
    background_w, background_h, background = load_tga(
        os.path.join(BACKGROUNDS, os.path.splitext(os.path.basename(map_path))[0].lower() + ".tga")
    )
    tiles = [tile for tile in iso.tiles if tile.layer2]
    anchors = [tile_world(header, tile) for tile in tiles]
    if center is None:
        center = (
            (min(x for x, _ in anchors) + max(x for x, _ in anchors)) // 2,
            (min(y for _, y in anchors) + max(y for _, y in anchors)) // 2,
        )
    origin = (header.u28, header.u2c)
    crop_x = center[0] - origin[0] - width // 2
    crop_y = center[1] - origin[1] - height // 2

    background_crop = bytearray(width * height * 4)
    for y in range(height):
        for x in range(width):
            target = (y * width + x) * 4
            sx, sy = crop_x + x, crop_y + y
            if 0 <= sx < background_w and 0 <= sy < background_h:
                source = (sy * background_w + sx) * 4
                background_crop[target : target + 4] = background[source : source + 4]
            else:
                background_crop[target : target + 4] = b"\x12\x14\x18\xff"

    draws = []
    cache = {}
    for tile in tiles:
        name = tile.layer2
        if name not in cache:
            path = os.path.join(SPRITES, name.lower())
            spr_header, rgba = spr_tool.decode_spr(Path(path).read_bytes())
            cache[name] = (spr_header.width, spr_header.height, rgba)
        sw, sh, rgba = cache[name]
        if sw == 0 or sh == 0:
            continue
        world_x, world_y = tile_world(header, tile)
        left = world_x - origin[0] - sw // 2 - crop_x
        top = world_y - origin[1] - sh - crop_y
        x0, y0 = max(0, left), max(0, top)
        x1, y1 = min(width, left + sw), min(height, top + sh)
        if x0 >= x1 or y0 >= y1:
            continue
        draws.append(
            {
                "asset": f"isodaten\\sprites\\{name.lower()}",
                "tile": (tile.x, tile.y),
                "world": (world_x, world_y),
                "left": left,
                "top": top,
                "dest": (x0, y0),
                "source": (x0 - left, y0 - top, x1 - x0, y1 - y0),
                "width": sw,
                "height": sh,
                "pixels": rgba,
            }
        )
    draws.sort(
        key=lambda draw: (
            draw["world"][1],
            draw["world"][0] - draw["width"] // 2,
            draw["asset"],
            draw["tile"][1],
            draw["tile"][0],
        )
    )
    for order, draw in enumerate(draws):
        draw["order"] = order

    pixels = bytearray(background_crop)
    for draw in draws:
        sx, sy, sw, sh = draw["source"]
        dx, dy = draw["dest"]
        source_pixels = draw["pixels"]
        for y in range(sh):
            for x in range(sw):
                source = ((sy + y) * draw["width"] + sx + x) * 4
                alpha = source_pixels[source + 3]
                if alpha == 0:
                    continue
                target = ((dy + y) * width + dx + x) * 4
                if alpha == 255:
                    pixels[target : target + 3] = source_pixels[source : source + 3]
                else:
                    for channel in range(3):
                        pixels[target + channel] = (
                            source_pixels[source + channel] * alpha
                            + pixels[target + channel] * (255 - alpha)
                            + 127
                        ) // 255
    return {
        "header": header,
        "center": center,
        "crop": (crop_x, crop_y, width, height),
        "tiles_present": len(iso.tiles),
        "layers_considered": len(tiles),
        "draws": draws,
        "pixels": bytes(pixels),
    }


def png_bytes(width: int, height: int, rgba: bytes) -> bytes:
    raw = b"".join(
        b"\x00" + rgba[y * width * 4 : (y + 1) * width * 4] for y in range(height)
    )

    def chunk(tag: bytes, data: bytes) -> bytes:
        body = tag + data
        return (
            struct.pack(">I", len(data))
            + body
            + struct.pack(">I", zlib.crc32(body) & 0xFFFFFFFF)
        )

    return (
        b"\x89PNG\r\n\x1a\n"
        + chunk(b"IHDR", struct.pack(">IIBBBBB", width, height, 8, 6, 0, 0, 0))
        + chunk(b"IDAT", zlib.compress(raw, 9))
        + chunk(b"IEND", b"")
    )


def draw_list(scene):
    header = scene["header"]
    return {
        "map": "game/Isokarten/Ber.iso",
        "background": "backgrounds\\ber.tga",
        "background_size": [4096, 2048],
        "background_origin": [header.u28, header.u2c],
        "crop": {
            "center": list(scene["center"]),
            "origin": list(scene["crop"][:2]),
            "size": list(scene["crop"][2:]),
        },
        "grid": [header.grid_w, header.grid_h],
        "view": [header.view_w, header.view_h],
        "tiles_present": scene["tiles_present"],
        "layers_considered": scene["layers_considered"],
        "draws": len(scene["draws"]),
        "missing": [],
        "ambiguous": [],
        "ordered_draws": [
            {
                "order": draw["order"],
                "asset": draw["asset"],
                "tile": list(draw["tile"]),
                "layer": 2,
                "world": list(draw["world"]),
                "source": list(draw["source"]),
                "dest": [
                    draw["dest"][0],
                    draw["dest"][1],
                    draw["source"][2],
                    draw["source"][3],
                ],
            }
            for draw in scene["draws"]
        ],
    }


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("map")
    parser.add_argument("--center")
    parser.add_argument("--width", type=int, default=800)
    parser.add_argument("--height", type=int, default=600)
    parser.add_argument("--output")
    parser.add_argument("--json")
    args = parser.parse_args()
    center = None
    if args.center:
        center = tuple(int(value) for value in args.center.split(","))
    scene = build_scene(args.map, center, args.width, args.height)
    if args.output:
        Path(args.output).write_bytes(png_bytes(args.width, args.height, scene["pixels"]))
    if args.json:
        Path(args.json).write_text(json.dumps(draw_list(scene), indent=2) + "\n")
    print(
        f"tiles={scene['tiles_present']} layers={scene['layers_considered']} "
        f"draws={len(scene['draws'])} rgba_fnv={fnv1a(scene['pixels']):016x}"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
