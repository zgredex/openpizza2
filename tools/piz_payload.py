#!/usr/bin/env python3
"""Schema-driven Pizza Connection 2 .piz payload reader/editor.

Uses decompiled_fastfood2_named_v2/save_schema.json:
  - 0xF0 header
  - 0x20 section directory at 0xF0 (written last)
  - fixed preamble through the variable briefing list at 0x7DB
  - 2,500 x 50-byte tile-name table
  - directory-bounded iso-map / character / city / person / car / player /
    company regions

The tool intentionally edits only fixed-size fields. Variable-length briefing
strings are parsed and dumped but not rewritten yet, because changing their
length requires rebuilding the whole payload and directory.

Examples:
  python3 tools/piz_payload.py info save_000.piz
  python3 tools/piz_payload.py dump save_000.piz
  python3 tools/piz_payload.py sections save_000.piz
  python3 tools/piz_payload.py verify save_000.piz
  python3 tools/piz_payload.py get save_000.piz header.title
  python3 tools/piz_payload.py set save_000.piz game.scalar[0] 12345 --out new.piz
  python3 tools/piz_payload.py synth /tmp/test.piz
"""

from __future__ import annotations

import argparse
import json
import os
import re
import struct
import sys
from dataclasses import asdict, dataclass, field

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SCHEMA_PATH = os.path.join(ROOT, "decompiled_fastfood2_named_v2", "save_schema.json")

HEADER_SIZE = 0xF0
DIRECTORY_SIZE = 0x20
DIRECTORY_OFFSET = HEADER_SIZE
START_MARKER = 0x2E
END_MARKER = 0x2A
MAGIC = 0x13738317
VERSION = 0x11

DIRECTORY_NAMES = [
    "after_mapobject_list",
    "after_isomap_list",
    "after_character_list",
    "after_player_slots",
    "after_car_list",
    "after_company_slots",
    "after_person_list",
    "end_of_payload",
]

TILE_TABLE_COUNT = 2500
TILE_RECORD_SIZE = 50
TILE_TABLE_SIZE = TILE_TABLE_COUNT * TILE_RECORD_SIZE


def decode_text(raw: bytes) -> str:
    raw = raw.split(b"\0", 1)[0]
    try:
        return raw.decode("cp1252")
    except UnicodeDecodeError:
        return raw.decode("latin-1")


def encode_text(text: str, size: int) -> bytes:
    raw = text.encode("cp1252", "replace")[: size - 1]
    return raw + b"\0" * (size - len(raw))


@dataclass
class SaveHeader:
    title: str
    company: str
    city: str
    player_count: int
    player_flags: list[int]
    game_calendar: list[int]
    system_time: dict[str, int]
    version: int
    magic: int
    magic_ok: bool


@dataclass
class Section:
    name: str
    start: int
    end: int
    kind: str
    writer: str
    note: str = ""

    @property
    def size(self) -> int:
        return self.end - self.start


@dataclass
class BriefingEntry:
    index: int
    entry_id: int
    length: int
    text: str


class PizSave:
    def __init__(self, path: str):
        self.path = os.path.abspath(path)
        with open(path, "rb") as fh:
            self.data = bytearray(fh.read())
        self.schema = load_schema()
        self.header = self._parse_header()
        self.directory = self._parse_directory()
        self.sections: list[Section] = []
        self.briefing: list[BriefingEntry] = []
        self.tile_names: list[str] = []
        self.counts: dict[str, int] = {}
        self.problems: list[str] = []
        self._parse_layout()

    # ---------- header / directory ----------
    def _parse_header(self) -> SaveHeader:
        if len(self.data) < HEADER_SIZE:
            raise ValueError(f"{self.path}: shorter than 0xF0 header")
        d = self.data
        st = struct.unpack_from("<8H", d, 0xD8)
        version, magic = struct.unpack_from("<II", d, 0xE8)
        return SaveHeader(
            title=decode_text(d[0x00:0x40]),
            company=decode_text(d[0x40:0x80]),
            city=decode_text(d[0x80:0xC0]),
            player_count=d[0xC0],
            player_flags=list(d[0xC1:0xC8]),
            game_calendar=list(struct.unpack_from("<IIII", d, 0xC8)),
            system_time=dict(zip(
                ["year", "month", "day_of_week", "day", "hour", "minute",
                 "second", "millisecond"], st)),
            version=version,
            magic=magic,
            magic_ok=magic == MAGIC,
        )

    def _parse_directory(self) -> list[int]:
        if len(self.data) < DIRECTORY_OFFSET + DIRECTORY_SIZE:
            raise ValueError(f"{self.path}: shorter than directory")
        return list(struct.unpack_from("<8I", self.data, DIRECTORY_OFFSET))

    def _u32(self, offset: int) -> int:
        if offset + 4 > len(self.data):
            raise ValueError(f"read past end at 0x{offset:x}")
        return struct.unpack_from("<I", self.data, offset)[0]

    # ---------- layout ----------
    def _parse_layout(self) -> None:
        d = self.directory
        if len(self.data) < 0x120:
            self.problems.append("file too short for payload")
            return

        # Fixed preamble from the generated schema.
        cursor = 0x110
        for row in self.schema["top_level"]:
            name = row["section"]
            if name in ("header", "directory"):
                continue
            if name == "start_marker":
                self.sections.append(Section(
                    "start_marker", 0x110, 0x114, "const",
                    "SaveGame_Serialize", "0x2E"))
                cursor = 0x114
                continue
            if name == "ui_briefing_list":
                break
            size = row.get("computed_size")
            if size is None:
                break
            self.sections.append(Section(name, cursor, cursor + size,
                                         row["kind"], row["writer"],
                                         row.get("notes", "")))
            cursor += size

        # UI briefing list: u32 count, then u32 id + u32 length + bytes.
        self.briefing_start = cursor
        if cursor + 4 > len(self.data):
            self.problems.append("briefing list header out of range")
            return
        count = self._u32(cursor)
        cursor += 4
        for i in range(count):
            if cursor + 8 > len(self.data):
                self.problems.append(f"briefing entry {i} header out of range")
                return
            entry_id, length = struct.unpack_from("<II", self.data, cursor)
            cursor += 8
            if cursor + length > len(self.data):
                self.problems.append(f"briefing entry {i} body out of range")
                return
            text = decode_text(self.data[cursor:cursor + length])
            cursor += length
            self.briefing.append(BriefingEntry(i, entry_id, length, text))
        self.briefing_end = cursor
        self.sections.append(Section(
            "ui_briefing_list", self.briefing_start, cursor, "variable",
            "UI_BriefingList_Save",
            f"{count} entries, {cursor - self.briefing_start} bytes"))

        # Tile-name table: 2500 records of 50 bytes.
        self.tile_start = cursor
        self.tile_end = cursor + TILE_TABLE_SIZE
        if self.tile_end > len(self.data):
            self.problems.append("tile-name table out of range")
            return
        for i in range(TILE_TABLE_COUNT):
            raw = self.data[self.tile_start + i * TILE_RECORD_SIZE:
                            self.tile_start + (i + 1) * TILE_RECORD_SIZE]
            self.tile_names.append(decode_text(raw))
        self.sections.append(Section(
            "world_tile_name_table", self.tile_start, self.tile_end, "fixed",
            "Game_SaveTileNameTable", "2500 x 50-byte tile names"))
        cursor = self.tile_end

        # Directory-bounded regions. d[7] is the payload end.
        regions = [
            ("isomap_list", cursor, d[1], "counted", "IsoMap_Save"),
            ("character_list", d[1], d[2], "counted", "Character_Save"),
            ("city_mapobject_list", d[2], d[0], "counted", "MapObjectList_Save"),
            ("person_list", d[0], d[6], "counted", "PersonList_Save"),
            ("car_list", d[6], d[4], "counted", "CarList_Save"),
            ("player_slots", d[4], d[3], "array6", "Player_Save"),
            ("company_slots", d[3], d[5], "array6", "CompanyData_Save"),
            ("ai_company_slots_and_tail", d[5], d[7], "variable",
             "AI_CompanySlots_Save"),
        ]
        for name, start, end, kind, writer in regions:
            if start <= end <= len(self.data):
                self.sections.append(Section(name, start, end, kind, writer))
            else:
                self.problems.append(
                    f"bad region {name}: 0x{start:x}-0x{end:x}")

        # Counts at list starts.
        try:
            self.counts["isomaps"] = self._u32(cursor)
            self.counts["characters"] = self._u32(d[1])
            self.counts["cities"] = self._u32(d[2])
            self.counts["persons"] = self._u32(d[0])
            self.counts["cars"] = self._u32(d[6])
        except ValueError:
            pass

        self.end_marker = None
        if d[7] >= 4 and d[7] <= len(self.data):
            self.end_marker = self._u32(d[7] - 4)
        self._check_integrity()

    def _check_integrity(self) -> None:
        if not self.header.magic_ok:
            self.problems.append("header magic mismatch")
        if self._u32(0x110) != START_MARKER:
            self.problems.append("start marker is not 0x2E")
        if self.end_marker != END_MARKER:
            self.problems.append(
                f"end marker is {self.end_marker!r}, expected 0x2A")
        order = [self.directory[i] for i in
                 (1, 2, 0, 6, 4, 3, 5, 7)]
        if order != sorted(order):
            self.problems.append("directory offsets are not monotonic")
        if self.directory[7] != len(self.data):
            self.problems.append(
                f"directory end 0x{self.directory[7]:x} != file size "
                f"0x{len(self.data):x}")
        if self.tile_start and self.briefing_start > self.tile_start:
            self.problems.append("briefing list starts after tile table")

    # ---------- fixed record lists ----------
    def _owner(self, name: str) -> dict:
        return next(o for o in self.schema["owners"] if o["name"] == name)

    def _decode_sequential(self, pos: int, owner: dict):
        values = {}
        for f in owner["fields"]:
            size = f["size"]
            raw = self.data[pos:pos + size]
            if len(raw) != size:
                raise ValueError(f"record read past end at 0x{pos:x}")
            if size in (1, 2, 4, 8):
                fmt = {1: "<B", 2: "<H", 4: "<I", 8: "<Q"}[size]
                values[f"0x{f['offset']:x}"] = struct.unpack(fmt, raw)[0]
            else:
                values[f"0x{f['offset']:x}"] = raw.hex()
            pos += size
        return values, pos

    def parse_characters(self, limit=None) -> dict:
        start, end = self.directory[1], self.directory[2]
        owner = self._owner("Character_Save")
        rec_size = 4 + owner["fixed_bytes"]
        result = {"start": f"0x{start:x}", "end": f"0x{end:x}",
                  "count": None, "record_size": rec_size,
                  "records": [], "errors": []}
        if start + 4 > end:
            result["errors"].append("region too small")
            return result
        count = self._u32(start)
        result["count"] = count
        expected = 4 + count * rec_size
        if expected != end - start:
            result["errors"].append(
                f"size mismatch: 4+{count}*{rec_size}=0x{expected:x}, "
                f"region=0x{end - start:x}")
            return result
        pos = start + 4
        for i in range(count):
            if limit is not None and i >= limit:
                break
            rec_id = self._u32(pos)
            pos += 4
            fields, pos = self._decode_sequential(pos, owner)
            result["records"].append({"index": i, "id": rec_id,
                                      "fields": fields})
        return result

    def parse_companies(self, limit=None) -> dict:
        """Parse the six company slots.

        Each present slot is CompanyData_Save's 270-byte fixed prefix followed
        by the company index, GamePlan_SaveRecord list (44 bytes each), the
        recipe list, the nested Branch_Save list (u32 id + 6412-byte fixed body
        + variable tail), StatsPeriodReport records (856 bytes), Storage
        records (303-byte body), the pair list (u32 id + 8 bytes) and the
        0x1A0-byte record list.
        """
        start, end = self.directory[3], self.directory[5]
        owner = self._owner("CompanyData_Save")
        rec_size = owner["fixed_bytes"]
        branch_size = 6412
        result = {"start": f"0x{start:x}", "end": f"0x{end:x}",
                  "count": 0, "record_size": rec_size,
                  "branch_record_size": branch_size,
                  "slots": [], "errors": []}
        pos = start
        for slot in range(6):
            if pos + 4 > end:
                result["errors"].append(f"slot {slot} header past region")
                break
            present = self._u32(pos)
            pos += 4
            if present == 0:
                result["slots"].append({"slot": slot, "present": 0})
                continue
            if limit is not None and result["count"] >= limit:
                break
            if pos + rec_size + 16 > end:
                result["errors"].append(f"slot {slot} company body past region")
                break
            try:
                fields, pos = self._decode_sequential(pos, owner)
                company_index = self._u32(pos)
                pos += 4
                plan_count = self._u32(pos)
                pos += 4
                plans = []
                for plan_index in range(plan_count):
                    if pos + 44 > end:
                        raise ValueError(f"plan {plan_index} past region")
                    plans.append({
                        "active": self._u32(pos + 0),
                        "type": self._u32(pos + 4),
                        "media_type": self._u32(pos + 8),
                        "flags": self._u32(pos + 12),
                        "ingredient_index": self._u32(pos + 16),
                        "target_company": self._u32(pos + 20),
                        "budget": self._u32(pos + 24),
                        "target_billboard": self._u32(pos + 28),
                        "branch_id": self._u32(pos + 32),
                        "unused": self._u32(pos + 36),
                        "effect": self._u32(pos + 40),
                    })
                    pos += 44
                recipe_count = self._u32(pos)
                pos += 4
                recipes = []
                for recipe_index in range(recipe_count):
                    if pos + 4 + 713 > end:
                        raise ValueError(f"recipe {recipe_index} past region")
                    recipe_id = self._u32(pos)
                    pos += 4
                    recipe_name = decode_text(self.data[pos:pos + 64]).rstrip("\0")
                    topping_count = self._u32(pos + 68)
                    toppings = []
                    for topping_index in range(topping_count):
                        base = pos + 72 + topping_index * 21
                        toppings.append({
                            "ingredient": self.data[base + 0],
                            "category": self.data[base + 1],
                            "tier": self.data[base + 2],
                            "x": struct.unpack_from("<i", self.data, base + 4)[0],
                            "y": struct.unpack_from("<i", self.data, base + 8)[0],
                            "variant": self.data[base + 12],
                            "flag": self.data[base + 13],
                        })
                    pos += 72 + topping_count * 21 + 629
                    linked = self._u32(pos)
                    pos += 4
                    if linked:
                        linked_count = self._u32(pos)
                        pos += 4 + linked_count * 28
                    pos += 8
                    if pos > end:
                        raise ValueError(f"recipe {recipe_index} past region")
                    recipes.append({"id": recipe_id, "name": recipe_name,
                                    "topping_count": topping_count,
                                    "toppings": toppings})
                featured = self._u32(pos)
                pos += 4
                if featured:
                    raise ValueError("featured recipe flag not supported")
                branch_count = self._u32(pos)
                pos += 4
                branches = []
                for branch_index in range(branch_count):
                    if pos + 4 + branch_size > end:
                        raise ValueError(f"branch {branch_index} past region")
                    branch_id = self._u32(pos)
                    branch_name = decode_text(self.data[pos + 4:pos + 36]).rstrip("\0")
                    branch_style = self._u32(pos + 4 + 36)
                    branch_flags = self._u32(pos + 4 + 40)
                    branch_company = self._u32(pos + 4 + 44)
                    pos += 4 + branch_size
                    has_asset = self._u32(pos)
                    pos += 4
                    if has_asset:
                        pos += 4
                    pos += 4  # removed ID-map entry
                    stats_reports = self._u32(pos)
                    pos += 4 + stats_reports * 856
                    pos += 4  # array index
                    supplies = self._u32(pos)
                    pos += 4 + supplies * 8
                    constructions = self._u32(pos)
                    pos += 4 + constructions * (4 + 32)
                    for _ in range(3):
                        count = self._u32(pos)
                        pos += 4 + count * 4
                    count = self._u32(pos)
                    pos += 4 + count * (4 + 0x20)
                    count = self._u32(pos)
                    pos += 4 + count * 0x30
                    constructions = self._u32(pos)
                    pos += 4 + constructions * (4 + 32)
                    if pos > end:
                        raise ValueError(f"branch {branch_index} past region")
                    branches.append({"id": branch_id,
                                     "name": branch_name,
                                     "style": branch_style,
                                     "flags": branch_flags,
                                     "company_slot": branch_company,
                                     "record_size": branch_size})
                stats_reports = self._u32(pos)
                pos += 4
                reports = []
                for report_index in range(stats_reports):
                    if pos + 856 > end:
                        raise ValueError(f"report {report_index} past region")
                    income = list(struct.unpack_from("<26f", self.data, pos))
                    expense = list(struct.unpack_from("<25f", self.data, pos + 104))
                    reports.append({"income": income, "expense": expense})
                    pos += 856
                storage_count = self._u32(pos)
                pos += 4
                storage = []
                for storage_index in range(storage_count):
                    if pos + 4 + 303 > end:
                        raise ValueError(f"storage {storage_index} past region")
                    storage.append({
                        "id": self._u32(pos),
                        "name": decode_text(self.data[pos + 4:pos + 36]).rstrip("\0"),
                    })
                    pos += 4 + 303
                pair_count = self._u32(pos)
                pos += 4
                pairs = []
                for pair_index in range(pair_count):
                    if pos + 12 > end:
                        raise ValueError(f"pair {pair_index} past region")
                    pair_id = self._u32(pos)
                    pair_type = self._u32(pos + 4)
                    pair_state = self._u32(pos + 8)
                    pos += 12
                    pairs.append({"id": pair_id, "type": pair_type,
                                  "state": pair_state})
                big_count = self._u32(pos)
                pos += 4
                if pos + big_count * 0x1a0 > end:
                    raise ValueError("0x1A0 record list past region")
                pos += big_count * 0x1a0
            except ValueError as exc:
                result["errors"].append(f"slot {slot}: {exc}")
                break
            name = decode_text(bytes.fromhex(fields["0x8"])).rstrip("\0")
            cash_bits = fields["0x108"]
            cash = struct.unpack("<d", struct.pack("<Q", cash_bits))[0]
            result["slots"].append({
                "slot": slot,
                "present": 1,
                "name": name,
                "company_slot": fields["0x48"],
                "cash": cash,
                "company_index": company_index,
                "plan_count": plan_count,
                "plans": plans,
                "recipe_count": recipe_count,
                "recipes": recipes,
                "branch_count": branch_count,
                "branches": branches,
                "report_count": stats_reports,
                "reports": reports,
                "storage_count": storage_count,
                "storage": storage,
                "pair_count": pair_count,
                "pairs": pairs,
                "big_count": big_count,
                "nested_counts": [company_index, plan_count, recipe_count,
                                  featured, branch_count, stats_reports,
                                  storage_count, pair_count, big_count],
                "fields": fields,
            })
            result["count"] += 1
        if pos != end and not result["errors"]:
            result["errors"].append(
                f"company region has {end - pos} trailing bytes")
        return result

    def parse_players(self, limit=None) -> dict:
        start, end = self.directory[4], self.directory[3]
        player = self._owner("Player_Save")
        char = self._owner("Character_Save")
        event = self._owner("Player_Event_Save")
        ai = self._owner("Player_AIState_Save")
        mission = self._owner("Player_MissionState_Save")
        result = {"start": f"0x{start:x}", "end": f"0x{end:x}",
                  "slots": [], "errors": []}
        pos = start
        for slot in range(6):
            if pos + 4 > end:
                result["errors"].append(f"slot {slot} header past region")
                break
            present = self._u32(pos)
            pos += 4
            if present == 0:
                result["slots"].append({"slot": slot, "present": 0})
                continue
            if limit is not None and slot >= limit:
                break
            try:
                fields, pos = self._decode_sequential(pos, player)
                char_fields, pos = self._decode_sequential(pos, char)
                if pos + 4 > end:
                    raise ValueError("event count past region")
                event_count = self._u32(pos)
                pos += 4
                events = []
                for _ in range(event_count):
                    ev_fields, pos = self._decode_sequential(pos, event)
                    events.append(ev_fields)
                if pos + 4 > end:
                    raise ValueError("AI flag past region")
                has_ai = self._u32(pos)
                pos += 4
                ai_fields = None
                if has_ai:
                    ai_fields, pos = self._decode_sequential(pos, ai)
                if pos + 4 > end:
                    raise ValueError("mission flag past region")
                has_mission = self._u32(pos)
                pos += 4
                mission_fields = None
                if has_mission:
                    mission_fields, pos = self._decode_sequential(pos, mission)
                result["slots"].append({
                    "slot": slot, "present": 1,
                    "fields": fields,
                    "character": char_fields,
                    "events": events,
                    "ai": ai_fields,
                    "mission": mission_fields,
                })
            except ValueError as exc:
                result["errors"].append(f"slot {slot}: {exc}")
                break
        if pos != end:
            result["errors"].append(
                f"parsed to 0x{pos:x}, expected region end 0x{end:x}")
        return result

    # ---------- dump ----------
    def global_values(self) -> list[dict]:
        names = {g["address"]: g["suggested_name"]
                 for g in self.schema["global_state"]}
        rows = []
        for owner in self.schema["owners"]:
            if not owner["global_writes"]:
                continue
            if owner["name"] == "SaveGame_Serialize":
                start = 0x114
            else:
                top = next((r for r in self.schema["top_level"]
                            if r["writer"] == owner["name"]
                            and r.get("computed_offset") is not None
                            and r["kind"] in ("nested", "fixed")), None)
                if top is None:
                    continue
                start = top["computed_offset"]
            cursor = start
            for g in owner["global_writes"]:
                addr = g.get("global_address")
                size = g["size"]
                raw = self.data[cursor:cursor + size]
                value = None
                if size in (1, 2, 4):
                    fmt = {1: "<B", 2: "<H", 4: "<I"}[size]
                    value = struct.unpack(fmt, raw)[0]
                rows.append({
                    "address": f"0x{addr:08x}" if addr else None,
                    "name": names.get(f"0x{addr:08x}" if addr else "", ""),
                    "writer": owner["name"],
                    "file_offset": f"0x{cursor:x}",
                    "size": size,
                    "value": value,
                    "hex": raw.hex(),
                })
                cursor += size
        return rows

    def dump(self, full: bool = False) -> dict:
        rows = []
        for row in self.schema["top_level"]:
            name = row["section"]
            if name in ("header", "directory", "start_marker",
                        "ui_briefing_list", "world_tile_name_table"):
                continue
            off = row.get("computed_offset")
            size = row.get("computed_size")
            if off is None or size is None:
                continue
            values = None
            if size <= 64:
                values = {
                    "hex": self.data[off:off + size].hex(),
                    "u32": list(struct.unpack_from(
                        f"<{size // 4}I", self.data, off)) if size % 4 == 0 else None,
                }
            rows.append({"section": name, "offset": f"0x{off:x}", "size": size,
                         "writer": row["writer"], "values": values})

        header = asdict(self.header)
        header["magic"] = f"0x{self.header.magic:08x}"
        return {
            "path": self.path,
            "file_size": len(self.data),
            "header": header,
            "directory": [
                {"index": i, "name": DIRECTORY_NAMES[i],
                 "offset": f"0x{value:x}", "value": value}
                for i, value in enumerate(self.directory)
            ],
            "sections": [asdict(s) for s in self.sections],
            "counts": self.counts,
            "briefing_entries": [asdict(e) for e in self.briefing],
            "tile_names": self.tile_names if full else self.tile_names[:20],
            "tile_name_count": len(self.tile_names),
            "end_marker": f"0x{self.end_marker:x}" if self.end_marker is not None else None,
            "fixed_sections": rows,
            "serialized_globals": self.global_values(),
            "lists": {
                "characters": self.parse_characters(
                    limit=None if full else 5),
                "players": self.parse_players(
                    limit=None if full else 6),
            },
            "problems": self.problems,
        }

    def format_info(self) -> str:
        h = self.header
        st = h.system_time
        stamp = (f"{st['year']:04d}-{st['month']:02d}-{st['day']:02d} "
                 f"{st['hour']:02d}:{st['minute']:02d}:{st['second']:02d}")
        lines = [
            f"path:        {self.path}",
            f"title:       {h.title}",
            f"company:     {h.company}",
            f"city:        {h.city}",
            f"companies:   {h.player_count}  flags={h.player_flags}",
            f"game date:   {h.game_calendar}",
            f"system time: {stamp}",
            f"version:     0x{h.version:x}",
            f"magic:       0x{h.magic:08x} {'OK' if h.magic_ok else 'MISMATCH'}",
            f"file size:   {len(self.data):,} bytes",
            f"payload end: 0x{self.directory[7]:x}",
            f"tile names:  {len(self.tile_names)}",
            f"briefing:    {len(self.briefing)} entries",
            "counts:      " + ", ".join(f"{k}={v}" for k, v in self.counts.items()),
        ]
        if self.problems:
            lines.append("problems:    " + "; ".join(self.problems))
        return "\n".join(lines)

    def section_table(self) -> str:
        lines = ["section                     start      end        size  kind"]
        for s in self.sections:
            lines.append(f"{s.name:27s} 0x{s.start:08x} 0x{s.end:08x} "
                         f"{s.size:8d}  {s.kind}")
        return "\n".join(lines)

    # ---------- field access ----------
    def get_path(self, path: str):
        m = re.fullmatch(r"header\.game_calendar\[(\d+)\]", path)
        if m:
            return self.header.game_calendar[int(m.group(1))]
        m = re.fullmatch(r"header\.system_time\.(\w+)", path)
        if m:
            return self.header.system_time[m.group(1)]
        m = re.fullmatch(r"header\.(\w+)", path)
        if m:
            return getattr(self.header, m.group(1))
        m = re.fullmatch(r"directory\[(\d+)\]", path)
        if m:
            return self.directory[int(m.group(1))]
        m = re.fullmatch(r"tile\[(\d+)\]", path)
        if m:
            return self.tile_names[int(m.group(1))]
        m = re.fullmatch(r"briefing\[(\d+)\]\.(\w+)", path)
        if m:
            entry = self.briefing[int(m.group(1))]
            return getattr(entry, m.group(2))
        m = re.fullmatch(r"count\.(\w+)", path)
        if m:
            return self.counts[m.group(1)]
        m = re.fullmatch(r"game\.scalar\[(\d+)\]", path)
        if m:
            return self._u32(0x70C + int(m.group(1)) * 4)
        m = re.fullmatch(r"global\.(\w+)", path)
        if m:
            row = next((r for r in self.global_values()
                        if r["name"] == m.group(1)), None)
            if row is None:
                raise KeyError(f"unknown global: {m.group(1)}")
            return row["value"] if row["value"] is not None else row["hex"]
        m = re.fullmatch(r"raw\[(0x[0-9a-fA-F]+|\d+)\]:(\d+)", path)
        if m:
            off = int(m.group(1), 0)
            size = int(m.group(2), 0)
            return self.data[off:off + size].hex()
        raise KeyError(f"unknown path: {path}")

    def set_path(self, path: str, value: str) -> None:
        m = re.fullmatch(r"header\.(title|company|city)", path)
        if m:
            key = m.group(1)
            setattr(self.header, key, value)
            off = {"title": 0x00, "company": 0x40, "city": 0x80}[key]
            self.data[off:off + 64] = encode_text(value, 64)
            return
        m = re.fullmatch(r"header\.game_calendar\[(\d+)\]", path)
        if m:
            idx = int(m.group(1))
            self.header.game_calendar[idx] = int(value, 0)
            struct.pack_into("<IIII", self.data, 0xC8,
                             *self.header.game_calendar)
            return
        m = re.fullmatch(r"header\.player_count", path)
        if m:
            self.header.player_count = int(value, 0) & 0xFF
            self.data[0xC0] = self.header.player_count
            return
        m = re.fullmatch(r"tile\[(\d+)\]", path)
        if m:
            idx = int(m.group(1))
            if not 0 <= idx < TILE_TABLE_COUNT:
                raise ValueError("tile index out of range")
            self.tile_names[idx] = value
            off = self.tile_start + idx * TILE_RECORD_SIZE
            self.data[off:off + TILE_RECORD_SIZE] = encode_text(
                value, TILE_RECORD_SIZE)
            return
        m = re.fullmatch(r"game\.scalar\[(\d+)\]", path)
        if m:
            idx = int(m.group(1))
            if not 0 <= idx < 20:
                raise ValueError("scalar index out of range")
            struct.pack_into("<I", self.data, 0x70C + idx * 4, int(value, 0))
            return
        m = re.fullmatch(r"global\.(\w+)", path)
        if m:
            row = next((r for r in self.global_values()
                        if r["name"] == m.group(1)), None)
            if row is None:
                raise KeyError(f"unknown global: {m.group(1)}")
            off = int(row["file_offset"], 0)
            size = row["size"]
            if size in (1, 2, 4):
                struct.pack_into({1: "<B", 2: "<H", 4: "<I"}[size],
                                 self.data, off, int(value, 0))
            else:
                raw = bytes.fromhex(value)
                if len(raw) != size:
                    raise ValueError(f"expected {size} bytes, got {len(raw)}")
                self.data[off:off + size] = raw
            return
        m = re.fullmatch(r"raw\[(0x[0-9a-fA-F]+|\d+)\]:(\d+)", path)
        if m:
            off = int(m.group(1), 0)
            size = int(m.group(2), 0)
            raw = bytes.fromhex(value)
            if len(raw) != size:
                raise ValueError(f"expected {size} bytes, got {len(raw)}")
            self.data[off:off + size] = raw
            return
        raise KeyError(f"not editable: {path}")

    def save(self, out_path: str) -> None:
        with open(out_path, "wb") as fh:
            fh.write(self.data)


# ---------- schema ----------
def load_schema() -> dict:
    with open(SCHEMA_PATH) as fh:
        return json.load(fh)


# ---------- synthetic save ----------
def build_synthetic(title: str, company: str, city: str, briefings=None,
                    one_character=False, one_player=False,
                    rich_player=False) -> bytes:
    briefings = briefings or []
    schema = load_schema()
    fixed = {}
    for row in schema["top_level"]:
        fixed[row["section"]] = row

    body = bytearray()
    body += b"\0" * DIRECTORY_SIZE
    body += struct.pack("<I", START_MARKER)

    def add_section(name: str) -> None:
        size = fixed[name].get("computed_size")
        if size is None:
            raise ValueError(f"section {name} has no fixed size")
        body.extend(b"\0" * size)

    for name in [
        "global_game_block", "game_fields_a", "game_fields_b",
        "game_scalars", "ingredient_panel", "city_company_list",
        "advertising_panel", "company_market_share", "company_overview",
        "statistics_balance", "statistics_branch_balance", "personnel",
        "branch_stats_series_flags", "branch_design_color_index",
        "branch_menu_category", "warehouse_product", "game_calendar",
    ]:
        add_section(name)

    # UI briefing list.
    body += struct.pack("<I", len(briefings))
    for i, text in enumerate(briefings):
        raw = text.encode("cp1252", "replace")
        body += struct.pack("<II", i, len(raw))
        body += raw
    # Tile names.
    body += b"\0" * TILE_TABLE_SIZE

    body += struct.pack("<I", 0)
    after_isomaps = len(body)
    if one_character:
        body += struct.pack("<II", 1, 1)
        body += b"\0" * 2082
    else:
        body += struct.pack("<I", 0)
    after_chars = len(body)
    body += struct.pack("<I", 0)
    after_cities = len(body)
    body += struct.pack("<I", 0)
    after_persons = len(body)
    body += struct.pack("<I", 0)
    after_cars = len(body)
    if one_player:
        body += struct.pack("<I", 1)
        body += b"\0" * 132          # Player_Save direct fields
        body += b"\0" * 2082         # Character_Save
        if rich_player:
            body += struct.pack("<I", 1) + b"\0" * 6   # one event
            body += struct.pack("<I", 1) + b"\0" * 554  # AI state
            body += struct.pack("<I", 1) + b"\0" * 208  # mission state
        else:
            body += struct.pack("<I", 0)  # event count
            body += struct.pack("<I", 0)  # no AI state
            body += struct.pack("<I", 0)  # no mission state
        body += b"\0" * (5 * 4)
    else:
        body += b"\0" * (6 * 4)
    after_players = len(body)
    body += b"\0" * (6 * 4)
    after_companies = len(body)
    # AI company slots: size prefix + 6 records.
    body += struct.pack("<I", 0x168)
    body += b"\0" * (6 * 0x168)
    # selected player/company: present, player slot, company id.
    body += b"\0" * 12
    # Runtime list: 6 x (present u32 + trailing u32).
    body += b"\0" * (6 * 8)
    body += struct.pack("<I", END_MARKER)
    after_end = len(body)

    directory = [HEADER_SIZE + x for x in [
        after_cities, after_isomaps, after_chars, after_players,
        after_cars, after_companies, after_persons, after_end,
    ]]
    struct.pack_into("<8I", body, 0, *directory)

    header = bytearray(HEADER_SIZE)
    header[0x00:0x40] = encode_text(title, 64)
    header[0x40:0x80] = encode_text(company, 64)
    header[0x80:0xC0] = encode_text(city, 64)
    header[0xC0] = 1
    header[0xC1:0xC8] = bytes([1, 0, 0, 0, 0, 0, 0])
    struct.pack_into("<IIII", header, 0xC8, 1, 2, 3, 4)
    struct.pack_into("<8H", header, 0xD8, 2026, 11, 3, 18, 10, 0, 0, 0)
    struct.pack_into("<II", header, 0xE8, VERSION, MAGIC)
    return bytes(header + body)


# ---------- commands ----------
def cmd_info(args):
    save = PizSave(args.piz)
    print(save.format_info())
    return 0 if not save.problems else 2


def cmd_sections(args):
    print(PizSave(args.piz).section_table())
    return 0


def cmd_dump(args):
    save = PizSave(args.piz)
    data = save.dump(full=args.full)
    if args.json:
        print(json.dumps(data, indent=2))
    else:
        print(save.format_info())
        print()
        print(save.section_table())
        print()
        print("directory: " + " ".join(f"{x:#x}" for x in save.directory))
        print("counts:    " + str(save.counts))
        if save.problems:
            print("problems:  " + "; ".join(save.problems))
    return 0 if not save.problems else 2


def cmd_characters(args):
    save = PizSave(args.piz)
    data = save.parse_characters(limit=args.limit)
    if args.json:
        print(json.dumps(data, indent=2))
        return 0
    print(f"characters: count={data['count']} record={data['record_size']} "
          f"records={len(data['records'])}")
    for r in data["records"]:
        print(f"  [{r['index']}] id={r['id']} fields={len(r['fields'])}")
    if data["errors"]:
        print("errors: " + "; ".join(data["errors"]))
    return 0 if not data["errors"] else 2


def cmd_players(args):
    save = PizSave(args.piz)
    data = save.parse_players()
    if args.json:
        print(json.dumps(data, indent=2))
        return 0
    for slot in data["slots"]:
        print(f"slot {slot['slot']}: present={slot['present']} "
              f"events={len(slot.get('events', []))} "
              f"ai={slot.get('ai') is not None} "
              f"mission={slot.get('mission') is not None}")
    if data["errors"]:
        print("errors: " + "; ".join(data["errors"]))
    return 0 if not data["errors"] else 2


def cmd_companies(args):
    save = PizSave(args.piz)
    data = save.parse_companies(limit=args.limit)
    if args.json:
        print(json.dumps(data, indent=2))
        return 0
    print(f"companies: count={data['count']} record={data['record_size']} "
          f"branch_record={data['branch_record_size']}")
    for slot in data["slots"]:
        if not slot["present"]:
            print(f"slot {slot['slot']}: present=0")
            continue
        branch_ids = [b["id"] for b in slot["branches"]]
        recipe_names = [r["name"] for r in slot["recipes"]]
        storage_ids = [s["id"] for s in slot["storage"]]
        print(f"slot {slot['slot']}: present=1 name={slot['name']!r} "
              f"cash={slot['cash']:.2f} plans={slot['plan_count']} "
              f"recipes={recipe_names} branches={branch_ids} "
              f"reports={slot['report_count']} storage={storage_ids} "
              f"pairs={len(slot['pairs'])} big={slot['big_count']} "
              f"nested={slot['nested_counts']}")
    if data["errors"]:
        print("errors: " + "; ".join(data["errors"]))
    return 0 if not data["errors"] else 2


def cmd_globals(args):
    save = PizSave(args.piz)
    rows = save.global_values()
    if args.json:
        print(json.dumps(rows, indent=2))
        return 0
    print(f"{'address':12s} {'offset':10s} {'size':4s} {'value':>12s}  name")
    for r in rows:
        value = "" if r["value"] is None else str(r["value"])
        print(f"{r['address'] or '':12s} {r['file_offset']:10s} {r['size']:4d} "
              f"{value:>12s}  {r['name']}")
    return 0


def cmd_verify(args):
    save = PizSave(args.piz)
    if save.problems:
        for p in save.problems:
            print(f"FAIL {p}")
        return 2
    print(f"OK {save.path}: {len(save.data):,} bytes, "
          f"{len(save.briefing)} briefing entries, "
          f"{len(save.tile_names)} tile names")
    return 0


def cmd_get(args):
    save = PizSave(args.piz)
    print(save.get_path(args.path))
    return 0


def cmd_set(args):
    save = PizSave(args.piz)
    save.set_path(args.path, args.value)
    save.save(args.out or args.piz)
    print(f"updated {args.path} -> {args.out or args.piz}")
    return 0


def cmd_synth(args):
    raw = build_synthetic(args.title, args.company, args.city, args.briefing,
                          args.one_character, args.one_player, args.rich_player)
    with open(args.out, "wb") as fh:
        fh.write(raw)
    print(f"wrote synthetic full-payload save: {args.out} ({len(raw):,} bytes)")
    return 0


def cmd_list(args):
    paths = []
    for root, _dirs, files in os.walk(args.directory):
        for name in files:
            if name.lower().endswith(".piz"):
                paths.append(os.path.join(root, name))
    paths.sort()
    if not paths:
        print(f"no .piz files under {args.directory}", file=sys.stderr)
        return 1
    for p in paths:
        try:
            save = PizSave(p)
            h = save.header
            status = "OK" if not save.problems else "BAD"
            print(f"{status:3s} {h.title[:30]:30s} {h.company[:20]:20s} "
                  f"{h.city[:15]:15s} {len(save.data):9d} B")
        except ValueError as exc:
            print(f"BAD {p}: {exc}")
    return 0


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    sub = ap.add_subparsers(dest="command", required=True)

    p = sub.add_parser("info", help="header, directory and counts")
    p.add_argument("piz")
    p.set_defaults(func=cmd_info)

    p = sub.add_parser("sections", help="list section boundaries")
    p.add_argument("piz")
    p.set_defaults(func=cmd_sections)

    p = sub.add_parser("dump", help="dump header, sections and fixed values")
    p.add_argument("piz")
    p.add_argument("--json", action="store_true")
    p.add_argument("--full", action="store_true", help="include all tile names")
    p.set_defaults(func=cmd_dump)

    p = sub.add_parser("characters", help="parse the character list")
    p.add_argument("piz")
    p.add_argument("--json", action="store_true")
    p.add_argument("--limit", type=int, default=None)
    p.set_defaults(func=cmd_characters)

    p = sub.add_parser("companies", help="parse the six company slots")
    p.add_argument("piz")
    p.add_argument("--json", action="store_true")
    p.add_argument("--limit", type=int, default=None)
    p.set_defaults(func=cmd_companies)

    p = sub.add_parser("players", help="parse the six player slots")
    p.add_argument("piz")
    p.add_argument("--json", action="store_true")
    p.set_defaults(func=cmd_players)

    p = sub.add_parser("globals", help="list serialized subsystem globals")
    p.add_argument("piz")
    p.add_argument("--json", action="store_true")
    p.set_defaults(func=cmd_globals)

    p = sub.add_parser("verify", help="validate magic, markers and directory")
    p.add_argument("piz")
    p.set_defaults(func=cmd_verify)

    p = sub.add_parser("get", help="read a field path")
    p.add_argument("piz")
    p.add_argument("path")
    p.set_defaults(func=cmd_get)

    p = sub.add_parser("set", help="write a fixed-size field path")
    p.add_argument("piz")
    p.add_argument("path")
    p.add_argument("value")
    p.add_argument("--out", help="write to a new file instead of in place")
    p.set_defaults(func=cmd_set)

    p = sub.add_parser("synth", help="generate a full-payload test save")
    p.add_argument("out")
    p.add_argument("--title", default="Synthetic save")
    p.add_argument("--company", default="Test Pizza Inc.")
    p.add_argument("--city", default="London")
    p.add_argument("--briefing", action="append", default=[],
                   help="add a briefing string (repeatable)")
    p.add_argument("--one-character", action="store_true",
                   help="add one zeroed character record")
    p.add_argument("--one-player", action="store_true",
                   help="add one zeroed player slot")
    p.add_argument("--rich-player", action="store_true",
                   help="also add one event, AI state and mission state")
    p.set_defaults(func=cmd_synth)

    p = sub.add_parser("list", help="scan a directory for .piz saves")
    p.add_argument("directory")
    p.set_defaults(func=cmd_list)

    args = ap.parse_args(argv)
    return args.func(args)


if __name__ == "__main__":
    raise SystemExit(main())
