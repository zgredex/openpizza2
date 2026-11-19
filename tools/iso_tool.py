#!/usr/bin/env python3
"""Parser and preview exporter for Pizza Connection 2 .iso maps.

Recovered from IsoMap_DeserializeGrid (0x4eb900) and validated against every
map in game/Isokarten: each parse consumes the file exactly.

Layout:
  0x00 header (0x74 bytes)
  0x74 u32 object-list-1 count
  0x78 u32 object-list-2 count
  object records: 34 bytes each
  tile grid: RLE + tile records
  optional trailing u32 array
"""

from __future__ import annotations

import argparse
import csv
import json
import os
import struct
import sys
import zlib
from dataclasses import asdict, dataclass, field

LIST_RECORD_SIZE = 34
TILE_FIXED_SIZE = 30
NAME_SIZE = 50


@dataclass
class Header:
    version: int
    name_mode: int
    view_w: int
    view_h: int
    tile_px_w: int
    tile_px_h: int
    grid_w: int
    grid_h: int
    pixel_w: int
    pixel_h: int
    u28: int
    u2c: int
    u30: int
    u34: int
    layer_bytes: str
    u48: int
    u4c: int
    background: str
    u6e: int
    u70: int
    list1_count: int
    list2_count: int


@dataclass
class ListRecord:
    index: int
    flags: int
    object_id: int
    type: int
    subtype: int
    key: int
    x: int
    y: int
    anim_block: str
    extra: int


@dataclass
class Tile:
    index: int
    x: int
    y: int
    flags: int
    tile_word: int
    f30: int
    f34: int
    f38: int
    f28: int
    f1c: int
    b2c: int
    b2d: int
    b2e: int
    b2f: int
    layer1_raw: int
    layer1: str | None
    layer2_raw: int
    layer2: str | None


@dataclass
class PathGraph:
    """Runtime street graph rebuilt from the .iso object tables.

    The loader copies list records into 0x28-byte nodes: +0xC/+0x10 are the
    node coordinates and +0x14 is eight linked node indices.  City maps use
    the 3*|dx| + 4*|dy| Object_Compare cost.
    """
    nodes: list[ListRecord]

    @classmethod
    def from_iso(cls, path: str):
        iso = IsoMap(path)
        return cls(iso.lists[0])

    def links(self, index: int):
        raw = bytes.fromhex(self.nodes[index].anim_block)
        return [v for v in struct.unpack("<8h", raw) if 0 <= v < len(self.nodes)]

    def step_cost(self, a: int, b: int):
        na, nb = self.nodes[a], self.nodes[b]
        return 3 * abs(na.x - nb.x) + 4 * abs(na.y - nb.y)

    def shortest_path(self, start: int, end: int):
        """Dijkstra equivalent of Map_FindShortestPath 0x4F14A0.

        Returns (node_count, cost, path).  ``node_count`` is the number of
        path nodes, including both endpoints.
        """
        import heapq
        if not (0 <= start < len(self.nodes) and 0 <= end < len(self.nodes)):
            return 0, None, []
        dist = {start: 0}
        prev = {}
        heap = [(0, start)]
        while heap:
            cost, u = heapq.heappop(heap)
            if cost != dist.get(u):
                continue
            if u == end:
                break
            for v in self.links(u):
                nxt = cost + self.step_cost(u, v)
                if nxt < dist.get(v, 1 << 60):
                    dist[v] = nxt
                    prev[v] = u
                    heapq.heappush(heap, (nxt, v))
        if end not in dist:
            return 0, None, []
        path = [end]
        while path[-1] != start:
            path.append(prev[path[-1]])
        path.reverse()
        return len(path), dist[end], path


class IsoMap:
    def __init__(self, path: str):
        self.path = os.path.abspath(path)
        with open(path, "rb") as fh:
            self.data = fh.read()
        self.problems: list[str] = []
        self.header = self._parse_header()
        self.lists = self._parse_lists()
        self.tiles, self.grid_start, self.grid_end = self._parse_grid()
        self.trailing, self.pos = self._parse_trailing()
        if self.pos != len(self.data):
            self.problems.append(
                f"parsed 0x{self.pos:x}, file size 0x{len(self.data):x}")

    def _u32(self, pos):
        return struct.unpack_from("<I", self.data, pos)[0]

    def _parse_header(self) -> Header:
        d = self.data
        if len(d) < 0x7C:
            raise ValueError("file shorter than header")
        vals = struct.unpack_from("<14I", d, 0)
        layer = d[0x38:0x48]
        bg = d[0x50:0x6E].split(b"\0", 1)[0].decode("latin1")
        u6e = struct.unpack_from("<H", d, 0x6E)[0]
        u70 = self._u32(0x70)
        c1 = self._u32(0x74)
        c2 = self._u32(0x78)
        expect = 0x7C + (c1 + c2) * LIST_RECORD_SIZE
        if expect > len(d):
            raise ValueError("object list extends past file")
        return Header(
            version=vals[0], name_mode=vals[1],
            view_w=vals[2], view_h=vals[3],
            tile_px_w=vals[4], tile_px_h=vals[5],
            grid_w=vals[6], grid_h=vals[7],
            pixel_w=vals[8], pixel_h=vals[9],
            u28=vals[10], u2c=vals[11], u30=vals[12], u34=vals[13],
            layer_bytes=layer.hex(), u48=self._u32(0x48), u4c=self._u32(0x4C),
            background=bg, u6e=u6e, u70=u70,
            list1_count=c1, list2_count=c2,
        )

    def _parse_lists(self):
        out = [[], []]
        pos = 0x7C
        for li, count in enumerate((self.header.list1_count,
                                    self.header.list2_count)):
            for i in range(count):
                r = self.data[pos:pos + LIST_RECORD_SIZE]
                if len(r) != LIST_RECORD_SIZE:
                    self.problems.append(f"list{li} record {i} truncated")
                    break
                out[li].append(ListRecord(
                    index=i,
                    flags=r[0],
                    object_id=struct.unpack_from("<H", r, 1)[0],
                    type=r[3],
                    subtype=r[4],
                    key=struct.unpack_from("<I", r, 5)[0],
                    x=struct.unpack_from("<I", r, 9)[0],
                    y=struct.unpack_from("<I", r, 13)[0],
                    anim_block=r[17:33].hex(),
                    extra=r[33],
                ))
                pos += LIST_RECORD_SIZE
        return out

    def _parse_grid(self):
        h = self.header
        total = h.grid_w * h.grid_h
        pos = 0x7C + (h.list1_count + h.list2_count) * LIST_RECORD_SIZE
        start = pos
        tiles = []
        i = 0
        while i < total:
            if pos + 4 > len(self.data):
                self.problems.append("grid flag past EOF")
                break
            flag = self._u32(pos); pos += 4
            if flag == 1:
                if pos + 4 > len(self.data):
                    self.problems.append("grid run past EOF")
                    break
                run = self._u32(pos); pos += 4
                if run == 0:
                    self.problems.append(f"zero-length run at tile {i}")
                i += run
                continue
            if pos + TILE_FIXED_SIZE > len(self.data):
                self.problems.append("tile fixed part past EOF")
                break
            fixed = self.data[pos:pos + TILE_FIXED_SIZE]; pos += TILE_FIXED_SIZE
            flags, tile_word = struct.unpack_from("<IH", fixed, 0)
            f30, f34, f38, f28, f1c = struct.unpack_from("<IIIII", fixed, 6)
            b2c, b2d, b2e, b2f = fixed[26:30]
            layers = []
            for _ in range(2):
                if pos + 4 > len(self.data):
                    self.problems.append("layer id past EOF")
                    raw = 0xFFFFFFFF
                    name = None
                else:
                    raw = self._u32(pos); pos += 4
                    name = None
                    if h.name_mode == 0 and raw < 0x80000000:
                        if pos + NAME_SIZE > len(self.data):
                            self.problems.append("layer name past EOF")
                        else:
                            name = self.data[pos:pos + NAME_SIZE].split(
                                b"\0", 1)[0].decode("latin1")
                            pos += NAME_SIZE
                layers.append((raw, name))
            x = i % h.grid_w if h.grid_w else 0
            y = i // h.grid_w if h.grid_w else 0
            tiles.append(Tile(
                index=i, x=x, y=y, flags=flags, tile_word=tile_word,
                f30=f30, f34=f34, f38=f38, f28=f28, f1c=f1c,
                b2c=b2c, b2d=b2d, b2e=b2e, b2f=b2f,
                layer1_raw=layers[0][0], layer1=layers[0][1],
                layer2_raw=layers[1][0], layer2=layers[1][1],
            ))
            i += 1
        if i != total:
            self.problems.append(f"grid ended at {i}, expected {total}")
        return tiles, start, pos

    def _parse_trailing(self):
        pos = self.grid_end
        if pos + 4 > len(self.data):
            return {"flag": None, "values": []}, pos
        flag = self._u32(pos); pos += 4
        values = []
        if flag == 1:
            if pos + 4 > len(self.data):
                self.problems.append("trailing count past EOF")
                return {"flag": flag, "values": values}, pos
            count = self._u32(pos); pos += 4
            if pos + (count + 1) * 4 > len(self.data):
                self.problems.append("trailing array past EOF")
                return {"flag": flag, "values": values}, pos
            values = [self._u32(pos + i * 4) for i in range(count + 1)]
            pos += (count + 1) * 4
        return {"flag": flag, "values": values}, pos

    def summary(self):
        empty = self.header.grid_w * self.header.grid_h - len(self.tiles)
        named = sum(1 for t in self.tiles if t.layer1 or t.layer2)
        return {
            "path": self.path,
            "size": len(self.data),
            "background": self.header.background,
            "grid": f"{self.header.grid_w}x{self.header.grid_h}",
            "view": f"{self.header.view_w}x{self.header.view_h}",
            "tile_pixels": f"{self.header.tile_px_w}x{self.header.tile_px_h}",
            "list1": self.header.list1_count,
            "list2": self.header.list2_count,
            "tiles_present": len(self.tiles),
            "tiles_empty": empty,
            "tiles_with_names": named,
            "trailing_array": len(self.trailing["values"]),
            "parsed_end": f"0x{self.pos:x}",
            "problems": self.problems,
        }

    def to_json(self, tile_limit=None, list_limit=None):
        tiles = self.tiles if tile_limit is None else self.tiles[:tile_limit]
        lists = [l if list_limit is None else l[:list_limit]
                 for l in self.lists]
        return {
            "header": asdict(self.header),
            "summary": self.summary(),
            "lists": [[asdict(r) for r in l] for l in lists],
            "tiles": [asdict(t) for t in tiles],
            "trailing": self.trailing,
        }

    def write_csv(self, path):
        with open(path, "w", newline="") as fh:
            w = csv.writer(fh)
            w.writerow(["index", "x", "y", "flags", "tile_word",
                        "layer1_raw", "layer1", "layer2_raw", "layer2",
                        "f30", "f34", "f38", "f28", "f1c",
                        "b2c", "b2d", "b2e", "b2f"])
            for t in self.tiles:
                w.writerow([t.index, t.x, t.y, t.flags, t.tile_word,
                            f"0x{t.layer1_raw:08x}", t.layer1 or "",
                            f"0x{t.layer2_raw:08x}", t.layer2 or "",
                            t.f30, t.f34, t.f38, t.f28, t.f1c,
                            t.b2c, t.b2d, t.b2e, t.b2f])

    def write_preview(self, path, scale=4):
        """Write a simple PNG map preview: empty, ground, object, both."""
        h = self.header
        w, hgt = h.grid_w, h.grid_h
        if not w or not hgt:
            raise ValueError("zero grid")
        img_w, img_h = w * scale, hgt * scale
        pixels = bytearray(img_w * img_h * 3)
        # background dark blue-gray
        for i in range(len(pixels) // 3):
            pixels[i * 3:i * 3 + 3] = b"\x18\x20\x28"
        for t in self.tiles:
            a = bool(t.layer1)
            b = bool(t.layer2)
            if a and b:
                color = b"\xff\x80\x20"
            elif b:
                color = b"\xff\xc8\x40"
            elif a:
                color = b"\x40\xc0\x60"
            else:
                color = b"\x80\x80\x80"
            for yy in range(scale):
                base = ((t.y * scale + yy) * img_w + t.x * scale) * 3
                for xx in range(scale):
                    pixels[base + xx * 3:base + xx * 3 + 3] = color
        write_png(path, img_w, img_h, pixels)


def write_png(path, width, height, rgb):
    def chunk(tag, data):
        return (struct.pack(">I", len(data)) + tag + data +
                struct.pack(">I", zlib.crc32(tag + data) & 0xFFFFFFFF))
    raw = bytearray()
    stride = width * 3
    for y in range(height):
        raw.append(0)
        raw.extend(rgb[y * stride:(y + 1) * stride])
    png = (b"\x89PNG\r\n\x1a\n" +
           chunk(b"IHDR", struct.pack(">IIBBBBB", width, height, 8, 2, 0, 0, 0)) +
           chunk(b"IDAT", zlib.compress(bytes(raw), 9)) +
           chunk(b"IEND", b""))
    with open(path, "wb") as fh:
        fh.write(png)


def cmd_info(args):
    m = IsoMap(args.iso)
    s = m.summary()
    if args.json:
        print(json.dumps(s, indent=2))
    else:
        for k, v in s.items():
            if k == "problems":
                continue
            print(f"{k:20s} {v}")
        if s["problems"]:
            print("problems: " + "; ".join(s["problems"]))
    return 0 if not s["problems"] else 2


def cmd_header(args):
    print(json.dumps(asdict(IsoMap(args.iso).header), indent=2))
    return 0


def cmd_lists(args):
    m = IsoMap(args.iso)
    data = [[asdict(r) for r in l[:args.limit]] for l in m.lists]
    if args.json:
        print(json.dumps(data, indent=2))
    else:
        for li, rows in enumerate(data):
            print(f"list {li}: {m.header.list1_count if li == 0 else m.header.list2_count} records")
            for r in rows:
                print(f"  id={r['object_id']:4d} type={r['type']} "
                      f"key=0x{r['key']:x} x={r['x']} y={r['y']} "
                      f"anim={r['anim_block']}")
    return 0


def cmd_tiles(args):
    m = IsoMap(args.iso)
    rows = m.tiles if args.limit is None else m.tiles[:args.limit]
    if args.json:
        print(json.dumps([asdict(t) for t in rows], indent=2))
    else:
        for t in rows:
            print(f"{t.index:6d} ({t.x:3d},{t.y:3d}) "
                  f"L1={t.layer1 or '-'} L2={t.layer2 or '-'}")
    return 0


def cmd_json(args):
    m = IsoMap(args.iso)
    print(json.dumps(m.to_json(args.limit, args.list_limit), indent=2))
    return 0


def cmd_csv(args):
    m = IsoMap(args.iso)
    m.write_csv(args.out)
    print(f"wrote {args.out}: {len(m.tiles)} tiles")
    return 0


def cmd_preview(args):
    m = IsoMap(args.iso)
    m.write_preview(args.out, args.scale)
    print(f"wrote {args.out}: {m.header.grid_w * args.scale}x"
          f"{m.header.grid_h * args.scale} PNG")
    return 0


def cmd_verify(args):
    m = IsoMap(args.iso)
    if m.problems:
        for p in m.problems:
            print(f"FAIL {p}")
        return 2
    print(f"OK {os.path.basename(m.path)}: {len(m.data):,} bytes, "
          f"grid {m.header.grid_w}x{m.header.grid_h}, "
          f"lists {m.header.list1_count}+{m.header.list2_count}, "
          f"tiles {len(m.tiles)}")
    return 0


def cmd_scan(args):
    ok = 0
    bad = 0
    for name in sorted(os.listdir(args.directory)):
        if not name.lower().endswith(".iso"):
            continue
        path = os.path.join(args.directory, name)
        try:
            m = IsoMap(path)
            if m.problems:
                print(f"FAIL {name}: {'; '.join(m.problems)}")
                bad += 1
            else:
                print(f"OK   {name:32s} {len(m.data):7d} B  "
                      f"grid {m.header.grid_w}x{m.header.grid_h}  "
                      f"lists {m.header.list1_count}+{m.header.list2_count}  "
                      f"tiles {len(m.tiles)}")
                ok += 1
        except Exception as exc:
            print(f"FAIL {name}: {exc}")
            bad += 1
    print(f"summary: {ok} OK, {bad} failed")
    return 0 if bad == 0 else 2


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    sub = ap.add_subparsers(dest="command", required=True)

    p = sub.add_parser("info", help="map summary")
    p.add_argument("iso"); p.add_argument("--json", action="store_true")
    p.set_defaults(func=cmd_info)

    p = sub.add_parser("header", help="print header fields")
    p.add_argument("iso"); p.set_defaults(func=cmd_header)

    p = sub.add_parser("lists", help="dump object tables")
    p.add_argument("iso"); p.add_argument("--json", action="store_true")
    p.add_argument("--limit", type=int, default=20)
    p.set_defaults(func=cmd_lists)

    p = sub.add_parser("tiles", help="dump non-empty tiles")
    p.add_argument("iso"); p.add_argument("--json", action="store_true")
    p.add_argument("--limit", type=int, default=30)
    p.set_defaults(func=cmd_tiles)

    p = sub.add_parser("json", help="full JSON dump")
    p.add_argument("iso"); p.add_argument("--limit", type=int, default=100)
    p.add_argument("--list-limit", type=int, default=50)
    p.set_defaults(func=cmd_json)

    p = sub.add_parser("csv", help="export tiles as CSV")
    p.add_argument("iso"); p.add_argument("out")
    p.set_defaults(func=cmd_csv)

    p = sub.add_parser("preview", help="export a PNG occupancy preview")
    p.add_argument("iso"); p.add_argument("out")
    p.add_argument("--scale", type=int, default=4)
    p.set_defaults(func=cmd_preview)

    p = sub.add_parser("verify", help="validate exact file consumption")
    p.add_argument("iso"); p.set_defaults(func=cmd_verify)

    p = sub.add_parser("scan", help="verify every .iso in a directory")
    p.add_argument("directory"); p.set_defaults(func=cmd_scan)

    args = ap.parse_args(argv)
    return args.func(args)


if __name__ == "__main__":
    raise SystemExit(main())
