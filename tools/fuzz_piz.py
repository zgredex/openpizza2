#!/usr/bin/env python3
"""Deterministic synthetic-save fuzz oracle for the Pizza Connection 2 .piz format.

The oracle builds a schema-shaped save entirely in Python, parses it with
``tools/piz_payload.py``, re-encodes the parsed model, and requires:

  bytes -> PizSave -> model -> bytes'   (byte equality)
  bytes' -> PizSave -> semantic view    (semantic equality)

The model covers the fixed 0x114..0x7DB preamble, the variable briefing list,
the 2500-entry tile table, the five counted object lists, six player slots,
six minimal company slots, the AI company block, the selected player/company
record, and the six runtime records.  It deliberately does not invent values
for record types whose internal layout is not exposed by PizSave (for example
city/map-object records); those are kept at count zero.  Recipe/menu records
are also not emitted: RecipeTopping_Save lives inside company menu-item
subrecords, which PizSave does not parse or expose.

Examples:
  python3 tools/fuzz_piz.py --seeds 1000
  python3 tools/fuzz_piz.py --seeds 1000 --seed0 5000 --json
"""

from __future__ import annotations

import argparse
import hashlib
import json
import os
import random
import struct
import sys
import tempfile
import time
from dataclasses import dataclass, field
from typing import Iterable

try:
    import piz_payload as piz
except ImportError:  # pragma: no cover - direct script execution fallback
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    import piz_payload as piz


# ---------------------------------------------------------------------------
# Schema-derived constants
# ---------------------------------------------------------------------------

SCHEMA = piz.load_schema()
TOP_LEVEL = {row["section"]: row for row in SCHEMA["top_level"]}
OWNERS = {owner["name"]: owner for owner in SCHEMA["owners"]}

HEADER_SIZE = piz.HEADER_SIZE
DIRECTORY_SIZE = piz.DIRECTORY_SIZE
DIRECTORY_OFFSET = piz.DIRECTORY_OFFSET
START_MARKER = piz.START_MARKER
END_MARKER = piz.END_MARKER
MAGIC = piz.MAGIC
VERSION = piz.VERSION

FIXED_PREFIX_START = 0x114
BRIEFING_START = 0x7DB
FIXED_PREFIX_SIZE = BRIEFING_START - FIXED_PREFIX_START

TILE_COUNT = piz.TILE_TABLE_COUNT
TILE_RECORD_SIZE = piz.TILE_RECORD_SIZE
TILE_TABLE_SIZE = piz.TILE_TABLE_SIZE

ISOMAP_BODY = OWNERS["IsoMap_Save"]["fixed_bytes"]
CHARACTER_BODY = OWNERS["Character_Save"]["fixed_bytes"]
PERSON_BODY = OWNERS["PersonList_Save"]["fixed_bytes"]
CAR_BODY = OWNERS["CarList_Save"]["fixed_bytes"]
PLAYER_BODY = OWNERS["Player_Save"]["fixed_bytes"]
EVENT_BODY = OWNERS["Player_Event_Save"]["fixed_bytes"]
AI_BODY = OWNERS["Player_AIState_Save"]["fixed_bytes"]
MISSION_BODY = OWNERS["Player_MissionState_Save"]["fixed_bytes"]
COMPANY_DIRECT_BODY = OWNERS["CompanyData_Save"]["fixed_bytes"]
AI_COMPANY_BODY = OWNERS["AI_CompanySlots_Save"]["fixed_bytes"]
# AI_CompanySlots_Save writes a u32 record size (0x168), then six records.
AI_COMPANY_RECORD_SIZE = AI_COMPANY_BODY // 6

# CompanyData_Save writes 270 direct bytes followed by nine always-present
# u32 sublist counts/flags.  All nine empty sublists give 270 + 36 = 306.
COMPANY_MIN_BODY = COMPANY_DIRECT_BODY + 9 * 4

SYSTEM_TIME_KEYS = (
    "year", "month", "day_of_week", "day",
    "hour", "minute", "second", "millisecond",
)

# A deliberately cp1252-safe alphabet.  Every character is one byte in the
# save encoding, and decode_text() returns the same character on read-back.
SAFE_ALPHABET = (
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"
    " .,;:-_!?()[]{}'\""
    "éèêëàâäôöûüçñßÄÖÜÉÀÂ®©€£¥°"
)

_TMP_DIR = "/tmp/opencode" if os.path.isdir("/tmp/opencode") else None


def _schema_sum_fixed_prefix() -> int:
    total = 0
    for row in SCHEMA["top_level"]:
        name = row["section"]
        if name in ("header", "directory", "start_marker"):
            continue
        offset = row.get("computed_offset")
        if offset is None or offset >= BRIEFING_START:
            break
        size = row.get("computed_size")
        if size is None:
            break
        total += size
    return total


# Guard against schema drift at import time.  This is intentionally an
# assertion, not a silent fallback: a changed schema should fail loudly.
assert FIXED_PREFIX_SIZE == 1735
assert _schema_sum_fixed_prefix() == FIXED_PREFIX_SIZE
assert TOP_LEVEL["ui_briefing_list"]["computed_offset"] == BRIEFING_START
assert COMPANY_MIN_BODY == 306


# ---------------------------------------------------------------------------
# Model
# ---------------------------------------------------------------------------

@dataclass
class Briefing:
    entry_id: int
    raw: bytes


@dataclass
class IdRecord:
    record_id: int
    body: bytes


@dataclass
class PlayerSlot:
    present: bool
    player: bytes = b""
    character: bytes = b""
    events: list[bytes] = field(default_factory=list)
    ai: bytes | None = None
    mission: bytes | None = None


@dataclass
class CompanySlot:
    present: bool
    body: bytes = b""


@dataclass
class SelectedSlot:
    present: bool
    player_slot: int
    company_id: int
    trailing: int
    raw: bytes


@dataclass
class RuntimeSlot:
    present: bool
    x: int = 0
    y: int = 0
    kind: int = 0
    trailing: int = 0


@dataclass
class SaveModel:
    title: str
    company: str
    city: str
    player_count: int
    player_flags: list[int]
    game_calendar: list[int]
    system_time: dict[str, int]
    fixed_prefix: bytes
    briefings: list[Briefing]
    tile_names: list[str]
    isomaps: list[IdRecord]
    characters: list[IdRecord]
    city_count: int
    city_raw: bytes
    persons: list[IdRecord]
    cars: list[IdRecord]
    players: list[PlayerSlot]
    companies: list[CompanySlot]
    ai_company_body: bytes
    selected: SelectedSlot
    runtime: list[RuntimeSlot]


@dataclass(frozen=True)
class EncodedSave:
    data: bytes
    directory: tuple[int, ...]
    starts: dict[str, int]


@dataclass(frozen=True)
class BoundaryCase:
    name: str
    model: SaveModel
    encoded: EncodedSave

    @property
    def data(self) -> bytes:
        return self.encoded.data

    @property
    def directory(self) -> tuple[int, ...]:
        return self.encoded.directory


@dataclass(frozen=True)
class FuzzLimits:
    max_characters: int = 8
    max_isomaps: int = 4
    max_persons: int = 8
    max_cars: int = 8
    max_briefings: int = 16
    max_events: int = 4
    max_briefing_bytes: int = 4096


class FuzzMismatch(AssertionError):
    """Raised when one stage of the round-trip oracle fails."""

    def __init__(self, label: str, stage: str, detail: str):
        self.label = label
        self.stage = stage
        self.detail = detail
        self.seed: int | None = None
        super().__init__(f"{label} [{stage}]: {detail}")


# ---------------------------------------------------------------------------
# Small deterministic helpers
# ---------------------------------------------------------------------------

def _u32(data: bytes, offset: int) -> int:
    if offset < 0 or offset + 4 > len(data):
        raise ValueError(f"u32 read out of range at 0x{offset:x}")
    return struct.unpack_from("<I", data, offset)[0]


def _need(condition: bool, message: str) -> None:
    if not condition:
        raise ValueError(message)


def _sha256_hex(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def _first_difference(a: bytes, b: bytes) -> int:
    limit = min(len(a), len(b))
    for i in range(limit):
        if a[i] != b[i]:
            return i
    return limit if len(a) != len(b) else -1


def _first_different_key(a: dict, b: dict) -> str:
    for key in sorted(set(a) | set(b)):
        if a.get(key) != b.get(key):
            return key
    return "<none>"


def _fill_text(text: str, size: int) -> bytes:
    raw = text.encode("cp1252", "strict")
    if len(raw) > size - 1:
        raise ValueError(f"text too long for {size}-byte field: {len(raw)} bytes")
    return raw + b"\0" * (size - len(raw))


def random_text(rng: random.Random, length: int) -> str:
    return "".join(rng.choice(SAFE_ALPHABET) for _ in range(length))


def _pattern_bytes(length: int, salt: int = 0) -> bytes:
    return bytes(((i * 37 + salt * 101 + 11) & 0xFF) for i in range(length))


def _pattern_text(length: int, salt: int = 0) -> str:
    return "".join(
        SAFE_ALPHABET[(i * 7 + salt * 13 + 3) % len(SAFE_ALPHABET)]
        for i in range(length)
    )


def _maybe_zero(rng: random.Random, length: int, zero_p: float = 0.15) -> bytes:
    if rng.random() < zero_p:
        return b"\0" * length
    return rng.randbytes(length)


def _company_direct_random(rng: random.Random) -> bytes:
    direct = bytearray(rng.randbytes(COMPANY_DIRECT_BODY))
    name_len = rng.choice([0, 3, 7, 15, 31, 63])
    direct[0:64] = _fill_text(random_text(rng, name_len), 64)
    return bytes(direct)


def _company_body_random(rng: random.Random) -> bytes:
    return _company_direct_random(rng) + b"\0" * (COMPANY_MIN_BODY - COMPANY_DIRECT_BODY)


def _company_body_pattern(salt: int) -> bytes:
    direct = bytearray(_pattern_bytes(COMPANY_DIRECT_BODY, salt))
    direct[0:64] = _fill_text(_pattern_text(31, salt), 64)
    return bytes(direct) + b"\0" * (COMPANY_MIN_BODY - COMPANY_DIRECT_BODY)


# ---------------------------------------------------------------------------
# Model construction
# ---------------------------------------------------------------------------

def _system_time(year: int = 0, month: int = 0, day_of_week: int = 0,
                 day: int = 0, hour: int = 0, minute: int = 0,
                 second: int = 0, millisecond: int = 0) -> dict[str, int]:
    return {
        "year": year, "month": month, "day_of_week": day_of_week,
        "day": day, "hour": hour, "minute": minute,
        "second": second, "millisecond": millisecond,
    }


def empty_model() -> SaveModel:
    """A minimal schema-shaped save with zero counts and zero strings."""
    return SaveModel(
        title="",
        company="",
        city="",
        player_count=0,
        player_flags=[0] * 7,
        game_calendar=[0, 0, 0, 0],
        system_time=_system_time(),
        fixed_prefix=b"\0" * FIXED_PREFIX_SIZE,
        briefings=[],
        tile_names=[""] * TILE_COUNT,
        isomaps=[],
        characters=[],
        city_count=0,
        city_raw=b"",
        persons=[],
        cars=[],
        players=[PlayerSlot(False) for _ in range(6)],
        companies=[CompanySlot(False) for _ in range(6)],
        ai_company_body=b"\0" * AI_COMPANY_BODY,
        selected=SelectedSlot(False, 0, 0, 0, struct.pack("<II", 0, 0)),
        runtime=[
            RuntimeSlot(False, 0, 0, 0, 0) for _ in range(6)
        ],
    )


def _clamp_count(rng: random.Random, values: Iterable[int], maximum: int) -> int:
    return min(rng.choice(list(values)), maximum)


def random_model(rng: random.Random, limits: FuzzLimits | None = None) -> SaveModel:
    """Build a deterministic, randomized but schema-shaped save model.

    All choices come from the supplied ``random.Random`` instance, so a given
    seed always produces identical bytes.
    """
    limits = limits or FuzzLimits()
    model = empty_model()

    model.title = random_text(rng, rng.choice([0, 1, 3, 7, 15, 31, 47, 63]))
    model.company = random_text(rng, rng.choice([0, 1, 5, 15, 31, 63]))
    model.city = random_text(rng, rng.choice([0, 1, 5, 15, 31, 47, 63]))
    if rng.random() < 0.08:
        model.title = random_text(rng, 63)
    if rng.random() < 0.05:
        model.city = random_text(rng, 63)

    # Exercise player slots 1..6, as requested.  Company slots mirror the
    # same present set so the save is internally coherent.
    player_slots = rng.randint(1, 6)
    present_slots = sorted(rng.sample(range(6), player_slots))
    model.player_count = player_slots
    model.player_flags = [1 if i in present_slots else 0 for i in range(6)] + [0]

    model.game_calendar = [rng.getrandbits(32) for _ in range(4)]
    model.system_time = _system_time(
        year=rng.randint(1990, 2035),
        month=rng.randint(1, 12),
        day_of_week=rng.randint(0, 6),
        day=rng.randint(1, 28),
        hour=rng.randint(0, 23),
        minute=rng.randint(0, 59),
        second=rng.randint(0, 59),
        millisecond=rng.randint(0, 999),
    )

    model.fixed_prefix = _maybe_zero(rng, FIXED_PREFIX_SIZE, zero_p=0.10)

    briefing_count = rng.randint(0, min(4, limits.max_briefings))
    for i in range(briefing_count):
        length = rng.choice([0, 1, 2, 3, 7, 15, 31, 63, 64, 127, 255])
        if rng.random() < 0.10:
            length = rng.randint(0, min(1024, limits.max_briefing_bytes))
        length = min(length, limits.max_briefing_bytes)
        raw = random_text(rng, length).encode("cp1252")
        entry_id = i if rng.random() < 0.5 else rng.getrandbits(32)
        model.briefings.append(Briefing(entry_id, raw))

    # A varied but fully populated tile table.  Every entry is encoded as a
    # 50-byte NUL-padded record; selected entries cover min/max lengths.
    model.tile_names = [f"t{i:04d}" for i in range(TILE_COUNT)]
    override_count = rng.randint(4, 32)
    for j, index in enumerate(rng.sample(range(TILE_COUNT), override_count)):
        if j == 0:
            length = TILE_RECORD_SIZE - 1
        elif j == 1:
            length = 0
        else:
            length = rng.choice([0, 1, 2, 7, 15, 31, TILE_RECORD_SIZE - 1])
        model.tile_names[index] = random_text(rng, length)

    character_count = _clamp_count(
        rng, [0, 0, 1, 2, 3, 4, limits.max_characters], limits.max_characters)
    for i in range(character_count):
        model.characters.append(
            IdRecord(rng.getrandbits(32), _maybe_zero(rng, CHARACTER_BODY)))

    isomap_count = _clamp_count(
        rng, [0, 0, 1, 2, limits.max_isomaps], limits.max_isomaps)
    for i in range(isomap_count):
        model.isomaps.append(
            IdRecord(rng.getrandbits(32), _maybe_zero(rng, ISOMAP_BODY)))

    person_count = _clamp_count(
        rng, [0, 0, 1, 2, 3, limits.max_persons], limits.max_persons)
    for i in range(person_count):
        model.persons.append(
            IdRecord(rng.getrandbits(32), _maybe_zero(rng, PERSON_BODY)))

    car_count = _clamp_count(
        rng, [0, 0, 1, 2, 3, limits.max_cars], limits.max_cars)
    for i in range(car_count):
        model.cars.append(
            IdRecord(rng.getrandbits(32), _maybe_zero(rng, CAR_BODY)))

    for slot in range(6):
        if slot not in present_slots:
            continue
        events = [
            _maybe_zero(rng, EVENT_BODY)
            for _ in range(rng.randint(0, limits.max_events))
        ]
        ai = _maybe_zero(rng, AI_BODY) if rng.random() < 0.45 else None
        mission = (
            _maybe_zero(rng, MISSION_BODY) if rng.random() < 0.35 else None
        )
        model.players[slot] = PlayerSlot(
            True,
            player=_maybe_zero(rng, PLAYER_BODY),
            character=_maybe_zero(rng, CHARACTER_BODY),
            events=events,
            ai=ai,
            mission=mission,
        )
        model.companies[slot] = CompanySlot(True, _company_body_random(rng))

    model.ai_company_body = _maybe_zero(rng, AI_COMPANY_BODY, zero_p=0.10)

    if rng.random() < 0.75:
        slot = rng.choice(present_slots)
        company_id = rng.getrandbits(32)
        trailing = rng.getrandbits(32)
        model.selected = SelectedSlot(
            True, slot, company_id, trailing,
            struct.pack("<IIII", 1, slot, company_id, trailing))
    # else: keep the default absent 8-byte selected record.

    runtime = []
    for _ in range(6):
        if rng.random() < 0.30:
            runtime.append(RuntimeSlot(
                True,
                rng.getrandbits(32), rng.getrandbits(32),
                rng.getrandbits(32), rng.getrandbits(32)))
        else:
            runtime.append(RuntimeSlot(False, 0, 0, 0, 0))
    model.runtime = runtime

    return model


# ---------------------------------------------------------------------------
# Encoding
# ---------------------------------------------------------------------------

def encode_header(model: SaveModel) -> bytes:
    _need(len(model.game_calendar) == 4, "game_calendar must have four values")
    _need(len(model.player_flags) == 7, "player_flags must have seven bytes")
    _need(0 <= model.player_count <= 0xFF, "player_count out of byte range")
    missing = [k for k in SYSTEM_TIME_KEYS if k not in model.system_time]
    _need(not missing, f"system_time missing keys: {missing}")

    header = bytearray(HEADER_SIZE)
    header[0x00:0x40] = _fill_text(model.title, 64)
    header[0x40:0x80] = _fill_text(model.company, 64)
    header[0x80:0xC0] = _fill_text(model.city, 64)
    header[0xC0] = model.player_count
    header[0xC1:0xC8] = bytes(model.player_flags)
    struct.pack_into("<IIII", header, 0xC8, *model.game_calendar)
    struct.pack_into("<8H", header, 0xD8,
                     *[model.system_time[k] for k in SYSTEM_TIME_KEYS])
    struct.pack_into("<II", header, 0xE8, VERSION, MAGIC)
    return bytes(header)


def _encode_briefings(briefings: list[Briefing]) -> bytes:
    out = bytearray(struct.pack("<I", len(briefings)))
    for entry in briefings:
        if len(entry.raw) > 0xFFFFFFFF:
            raise ValueError("briefing too long")
        out += struct.pack("<II", entry.entry_id, len(entry.raw))
        out += entry.raw
    return bytes(out)


def _encode_tiles(names: list[str]) -> bytes:
    _need(len(names) == TILE_COUNT, f"expected {TILE_COUNT} tile names")
    out = bytearray()
    for name in names:
        out += _fill_text(name, TILE_RECORD_SIZE)
    return bytes(out)


def _encode_counted(records: list[IdRecord], body_size: int) -> bytes:
    out = bytearray(struct.pack("<I", len(records)))
    for record in records:
        _need(len(record.body) == body_size,
              f"record body is {len(record.body)}, expected {body_size}")
        out += struct.pack("<I", record.record_id)
        out += record.body
    return bytes(out)


def _encode_players(players: list[PlayerSlot]) -> bytes:
    _need(len(players) == 6, "expected six player slots")
    out = bytearray()
    for slot in players:
        if not slot.present:
            out += struct.pack("<I", 0)
            continue
        _need(len(slot.player) == PLAYER_BODY, "bad Player_Save body")
        _need(len(slot.character) == CHARACTER_BODY, "bad Character_Save body")
        out += struct.pack("<I", 1)
        out += slot.player
        out += slot.character
        out += struct.pack("<I", len(slot.events))
        for event in slot.events:
            _need(len(event) == EVENT_BODY, "bad Player_Event_Save body")
            out += event
        out += struct.pack("<I", 1 if slot.ai is not None else 0)
        if slot.ai is not None:
            _need(len(slot.ai) == AI_BODY, "bad Player_AIState_Save body")
            out += slot.ai
        out += struct.pack("<I", 1 if slot.mission is not None else 0)
        if slot.mission is not None:
            _need(len(slot.mission) == MISSION_BODY,
                  "bad Player_MissionState_Save body")
            out += slot.mission
    return bytes(out)


def _encode_companies(companies: list[CompanySlot]) -> bytes:
    _need(len(companies) == 6, "expected six company slots")
    out = bytearray()
    for slot in companies:
        if not slot.present:
            out += struct.pack("<I", 0)
            continue
        _need(len(slot.body) == COMPANY_MIN_BODY,
              f"company body is {len(slot.body)}, expected {COMPANY_MIN_BODY}")
        out += struct.pack("<I", 1)
        out += slot.body
    return bytes(out)


def _encode_runtime(runtime: list[RuntimeSlot]) -> bytes:
    _need(len(runtime) == 6, "expected six runtime slots")
    out = bytearray()
    for slot in runtime:
        if slot.present:
            out += struct.pack("<IIIII", 1, slot.x, slot.y, slot.kind,
                               slot.trailing)
        else:
            out += struct.pack("<II", 0, slot.trailing)
    return bytes(out)


def encode_save(model: SaveModel) -> EncodedSave:
    """Serialize a model into the exact .piz section graph.

    The returned object also exposes the eight directory offsets and the
    starting file offset of every section, which the tests use for framing
    invariants.
    """
    if len(model.fixed_prefix) != FIXED_PREFIX_SIZE:
        raise ValueError(
            f"fixed prefix is {len(model.fixed_prefix)} bytes, "
            f"expected {FIXED_PREFIX_SIZE}")

    body = bytearray(HEADER_SIZE + DIRECTORY_SIZE)
    body[0:HEADER_SIZE] = encode_header(model)
    starts: dict[str, int] = {
        "header": 0,
        "directory": DIRECTORY_OFFSET,
        "start_marker": HEADER_SIZE + DIRECTORY_SIZE,
        "fixed_prefix": FIXED_PREFIX_START,
    }

    body += struct.pack("<I", START_MARKER)
    body += model.fixed_prefix

    starts["briefings"] = len(body)
    body += _encode_briefings(model.briefings)

    starts["tiles"] = len(body)
    body += _encode_tiles(model.tile_names)

    directory = [0] * 8

    starts["isomaps"] = len(body)
    body += _encode_counted(model.isomaps, ISOMAP_BODY)
    directory[1] = len(body)

    starts["characters"] = len(body)
    body += _encode_counted(model.characters, CHARACTER_BODY)
    directory[2] = len(body)

    starts["city_mapobjects"] = len(body)
    body += struct.pack("<I", model.city_count)
    body += model.city_raw
    directory[0] = len(body)

    starts["persons"] = len(body)
    body += _encode_counted(model.persons, PERSON_BODY)
    directory[6] = len(body)

    starts["cars"] = len(body)
    body += _encode_counted(model.cars, CAR_BODY)
    directory[4] = len(body)

    starts["players"] = len(body)
    body += _encode_players(model.players)
    directory[3] = len(body)

    starts["companies"] = len(body)
    body += _encode_companies(model.companies)
    directory[5] = len(body)

    starts["ai_companies"] = len(body)
    _need(len(model.ai_company_body) == AI_COMPANY_BODY,
          "bad AI_CompanySlots_Save body")
    body += struct.pack("<I", AI_COMPANY_RECORD_SIZE)
    body += model.ai_company_body

    starts["selected"] = len(body)
    selected = model.selected
    if selected.present:
        _need(len(selected.raw) == 16,
              "present selected record must be 16 bytes")
        _need(selected.player_slot <= 0xFFFFFFFF, "player slot out of range")
        _need(selected.company_id <= 0xFFFFFFFF, "company id out of range")
        _need(selected.trailing <= 0xFFFFFFFF, "selected trailing out of range")
        _need(selected.raw[:16] == struct.pack(
            "<IIII", 1, selected.player_slot, selected.company_id,
            selected.trailing), "selected raw bytes disagree with fields")
    else:
        _need(len(selected.raw) in (8, 12),
              "absent selected record must be 8 or 12 bytes")
        _need(selected.player_slot == 0 and selected.company_id == 0,
              "absent selected record has non-zero fields")
    body += selected.raw

    starts["runtime"] = len(body)
    body += _encode_runtime(model.runtime)

    starts["end_marker"] = len(body)
    body += struct.pack("<I", END_MARKER)
    directory[7] = len(body)

    if directory[7] != len(body):
        raise AssertionError("internal directory length mismatch")
    struct.pack_into("<8I", body, DIRECTORY_OFFSET, *directory)

    return EncodedSave(bytes(body), tuple(directory), starts)


# ---------------------------------------------------------------------------
# Decoding / semantic snapshots
# ---------------------------------------------------------------------------

def decode_fields(body: bytes, owner_name: str) -> dict[str, int | str]:
    """Decode a direct serializer body using the schema field order.

    This mirrors piz_payload.PizSave._decode_sequential exactly, including its
    key spelling and its overwrite behavior for repeated object offsets.
    """
    owner = OWNERS[owner_name]
    expected = sum(f["size"] for f in owner["fields"])
    _need(len(body) == expected,
          f"{owner_name} body is {len(body)} bytes, expected {expected}")
    values: dict[str, int | str] = {}
    pos = 0
    for field_row in owner["fields"]:
        size = field_row["size"]
        raw = body[pos:pos + size]
        _need(len(raw) == size, f"{owner_name} field read past end")
        key = f"0x{field_row['offset']:x}"
        if size in (1, 2, 4, 8):
            fmt = {1: "<B", 2: "<H", 4: "<I", 8: "<Q"}[size]
            values[key] = struct.unpack(fmt, raw)[0]
        else:
            values[key] = raw.hex()
        pos += size
    return values


def _parse_briefings(data: bytes, start: int, expected_end: int) -> list[Briefing]:
    count = _u32(data, start)
    pos = start + 4
    out: list[Briefing] = []
    for _ in range(count):
        _need(pos + 8 <= len(data), "briefing header past end")
        entry_id, length = struct.unpack_from("<II", data, pos)
        pos += 8
        _need(pos + length <= len(data), "briefing body past end")
        out.append(Briefing(entry_id, data[pos:pos + length]))
        pos += length
    _need(pos == expected_end,
          f"briefing list ends at 0x{pos:x}, expected 0x{expected_end:x}")
    return out


def _parse_counted(data: bytes, start: int, end: int,
                   body_size: int, name: str) -> list[IdRecord]:
    _need(start + 4 <= end, f"{name} region too small")
    count = _u32(data, start)
    expected = 4 + count * (4 + body_size)
    _need(expected == end - start,
          f"{name} size mismatch: 4+{count}*{4 + body_size}="
          f"0x{expected:x}, region=0x{end - start:x}")
    pos = start + 4
    out: list[IdRecord] = []
    for _ in range(count):
        record_id = _u32(data, pos)
        pos += 4
        out.append(IdRecord(record_id, data[pos:pos + body_size]))
        pos += body_size
    _need(pos == end, f"{name} parser did not reach region end")
    return out


def _parse_players(data: bytes, start: int, end: int) -> list[PlayerSlot]:
    pos = start
    slots: list[PlayerSlot] = []
    for slot_index in range(6):
        _need(pos + 4 <= end, f"player slot {slot_index} header past end")
        present = _u32(data, pos)
        pos += 4
        _need(present in (0, 1),
              f"player slot {slot_index} present flag is {present}")
        if present == 0:
            slots.append(PlayerSlot(False))
            continue
        _need(pos + PLAYER_BODY + CHARACTER_BODY + 4 <= end,
              f"player slot {slot_index} body past end")
        player = data[pos:pos + PLAYER_BODY]
        pos += PLAYER_BODY
        character = data[pos:pos + CHARACTER_BODY]
        pos += CHARACTER_BODY
        event_count = _u32(data, pos)
        pos += 4
        _need(event_count <= (end - pos) // EVENT_BODY,
              f"player slot {slot_index} event count out of range")
        events = []
        for _ in range(event_count):
            events.append(data[pos:pos + EVENT_BODY])
            pos += EVENT_BODY
        _need(pos + 4 <= end, f"player slot {slot_index} AI flag past end")
        has_ai = _u32(data, pos)
        pos += 4
        _need(has_ai in (0, 1),
              f"player slot {slot_index} AI flag is {has_ai}")
        ai = None
        if has_ai:
            _need(pos + AI_BODY <= end, "AI body past end")
            ai = data[pos:pos + AI_BODY]
            pos += AI_BODY
        _need(pos + 4 <= end, f"player slot {slot_index} mission flag past end")
        has_mission = _u32(data, pos)
        pos += 4
        _need(has_mission in (0, 1),
              f"player slot {slot_index} mission flag is {has_mission}")
        mission = None
        if has_mission:
            _need(pos + MISSION_BODY <= end, "mission body past end")
            mission = data[pos:pos + MISSION_BODY]
            pos += MISSION_BODY
        slots.append(PlayerSlot(True, player, character, events, ai, mission))
    _need(pos == end,
          f"player slots end at 0x{pos:x}, expected 0x{end:x}")
    return slots


def _parse_companies(data: bytes, start: int, end: int) -> list[CompanySlot]:
    # This oracle only synthesizes companies with empty nested sublists.
    # Their writer-valid body is 270 direct bytes plus nine zero dwords.
    pos = start
    slots: list[CompanySlot] = []
    for slot_index in range(6):
        _need(pos + 4 <= end, f"company slot {slot_index} header past end")
        present = _u32(data, pos)
        pos += 4
        _need(present in (0, 1),
              f"company slot {slot_index} present flag is {present}")
        if present == 0:
            slots.append(CompanySlot(False))
            continue
        _need(pos + COMPANY_MIN_BODY <= end,
              f"company slot {slot_index} body past end")
        slots.append(CompanySlot(True, data[pos:pos + COMPANY_MIN_BODY]))
        pos += COMPANY_MIN_BODY
    _need(pos == end,
          f"company slots end at 0x{pos:x}, expected 0x{end:x}")
    return slots


def _try_runtime(data: bytes, start: int, end: int):
    """Parse exactly six runtime records followed by the end marker.

    Returns (slots, position_after_slots) if the tail is valid, else None.
    """
    pos = start
    slots: list[RuntimeSlot] = []
    for _ in range(6):
        if pos + 4 > end:
            return None
        present = _u32(data, pos)
        pos += 4
        if present == 1:
            if pos + 16 > end:
                return None
            x, y, kind, trailing = struct.unpack_from("<IIII", data, pos)
            pos += 16
            slots.append(RuntimeSlot(True, x, y, kind, trailing))
        elif present == 0:
            if pos + 4 > end:
                return None
            trailing = _u32(data, pos)
            pos += 4
            slots.append(RuntimeSlot(False, 0, 0, 0, trailing))
        else:
            return None
    if pos != end - 4:
        return None
    if _u32(data, end - 4) != END_MARKER:
        return None
    return slots, pos


def _parse_selected_and_runtime(data: bytes, start: int, end: int):
    _need(start + 4 <= end, "selected record past end")
    present = _u32(data, start)
    if present == 1:
        candidates = (16,)
    elif present == 0:
        # The current writer emits 8 bytes when no player/company is selected.
        # Older generated samples (synthetic_full.piz) used 12 zero bytes.
        candidates = (8, 12)
    else:
        raise ValueError(f"selected present flag is {present}")

    for raw_length in candidates:
        if start + raw_length > end:
            continue
        attempt = _try_runtime(data, start + raw_length, end)
        if attempt is None:
            continue
        runtime, runtime_end = attempt
        raw = data[start:start + raw_length]
        if present == 0:
            trailing = _u32(raw, 4) if raw_length >= 8 else 0
            selected = SelectedSlot(False, 0, 0, trailing, raw)
        else:
            _, player_slot, company_id, trailing = struct.unpack("<IIII", raw)
            selected = SelectedSlot(
                True, player_slot, company_id, trailing, raw)
        return selected, runtime, runtime_end

    raise ValueError("cannot locate the selected/runtime tail")


def decode_save(save: piz.PizSave) -> SaveModel:
    """Extract a complete save model from a parsed PizSave instance."""
    data = bytes(save.data)
    _need(len(data) >= HEADER_SIZE + DIRECTORY_SIZE, "file shorter than header")
    _need(getattr(save, "briefing_start", None) == BRIEFING_START,
          f"briefing list starts at 0x{getattr(save, 'briefing_start', -1):x}, "
          f"expected 0x{BRIEFING_START:x}")

    fixed_prefix = data[FIXED_PREFIX_START:save.briefing_start]
    _need(len(fixed_prefix) == FIXED_PREFIX_SIZE, "fixed prefix length mismatch")

    briefings = _parse_briefings(data, save.briefing_start, save.tile_start)
    _need(len(save.tile_names) == TILE_COUNT, "tile table count mismatch")
    _need(save.tile_end - save.tile_start == TILE_TABLE_SIZE,
          "tile table size mismatch")

    d = list(save.directory)
    isomaps = _parse_counted(
        data, save.tile_end, d[1], ISOMAP_BODY, "isomap_list")
    characters = _parse_counted(
        data, d[1], d[2], CHARACTER_BODY, "character_list")
    _need(d[2] + 4 <= d[0], "city/map-object region too small")
    city_count = _u32(data, d[2])
    city_raw = data[d[2] + 4:d[0]]
    persons = _parse_counted(
        data, d[0], d[6], PERSON_BODY, "person_list")
    cars = _parse_counted(
        data, d[6], d[4], CAR_BODY, "car_list")
    players = _parse_players(data, d[4], d[3])
    companies = _parse_companies(data, d[3], d[5])

    pos = d[5]
    _need(pos + 4 <= d[7], "AI company size prefix past end")
    ai_size = _u32(data, pos)
    _need(ai_size == AI_COMPANY_RECORD_SIZE,
          f"AI company record size is 0x{ai_size:x}, "
          f"expected 0x{AI_COMPANY_RECORD_SIZE:x}")
    ai_size *= 6
    pos += 4
    _need(pos + ai_size <= d[7], "AI company body past end")
    ai_company_body = data[pos:pos + ai_size]
    pos += ai_size

    selected, runtime, pos = _parse_selected_and_runtime(data, pos, d[7])
    _need(pos == d[7] - 4,
          f"runtime ends at 0x{pos:x}, expected 0x{d[7] - 4:x}")
    _need(_u32(data, d[7] - 4) == END_MARKER, "end marker is not 0x2A")

    header = save.header
    model = SaveModel(
        title=header.title,
        company=header.company,
        city=header.city,
        player_count=header.player_count,
        player_flags=list(header.player_flags),
        game_calendar=list(header.game_calendar),
        system_time=dict(header.system_time),
        fixed_prefix=fixed_prefix,
        briefings=briefings,
        tile_names=list(save.tile_names),
        isomaps=isomaps,
        characters=characters,
        city_count=city_count,
        city_raw=city_raw,
        persons=persons,
        cars=cars,
        players=players,
        companies=companies,
        ai_company_body=ai_company_body,
        selected=selected,
        runtime=runtime,
    )
    return model


def _header_dict(header) -> dict:
    return {
        "title": header.title,
        "company": header.company,
        "city": header.city,
        "player_count": header.player_count,
        "player_flags": list(header.player_flags),
        "game_calendar": list(header.game_calendar),
        "system_time": dict(header.system_time),
        "version": header.version,
        "magic": header.magic,
        "magic_ok": header.magic_ok,
    }


def _expected_player(slot_index: int, slot: PlayerSlot) -> dict:
    if not slot.present:
        return {"slot": slot_index, "present": 0}
    return {
        "slot": slot_index,
        "present": 1,
        "fields": decode_fields(slot.player, "Player_Save"),
        "character": decode_fields(slot.character, "Character_Save"),
        "events": [
            decode_fields(event, "Player_Event_Save")
            for event in slot.events
        ],
        "ai": (
            decode_fields(slot.ai, "Player_AIState_Save")
            if slot.ai is not None else None
        ),
        "mission": (
            decode_fields(slot.mission, "Player_MissionState_Save")
            if slot.mission is not None else None
        ),
    }


def model_view(model: SaveModel) -> dict:
    """A canonical, JSON-friendly view derived only from a SaveModel."""
    return {
        "header": {
            "title": model.title,
            "company": model.company,
            "city": model.city,
            "player_count": model.player_count,
            "player_flags": list(model.player_flags),
            "game_calendar": list(model.game_calendar),
            "system_time": dict(model.system_time),
            "version": VERSION,
            "magic": MAGIC,
            "magic_ok": True,
        },
        "briefings": [
            {
                "index": i,
                "entry_id": entry.entry_id,
                "length": len(entry.raw),
                "text": piz.decode_text(entry.raw),
            }
            for i, entry in enumerate(model.briefings)
        ],
        "tile_names": tuple(model.tile_names),
        "counts": {
            "isomaps": len(model.isomaps),
            "characters": len(model.characters),
            "cities": model.city_count,
            "persons": len(model.persons),
            "cars": len(model.cars),
        },
        "characters": {
            "count": len(model.characters),
            "records": [
                {
                    "index": i,
                    "id": record.record_id,
                    "fields": decode_fields(record.body, "Character_Save"),
                }
                for i, record in enumerate(model.characters)
            ],
            "errors": [],
        },
        "players": {
            "slots": [
                _expected_player(i, slot)
                for i, slot in enumerate(model.players)
            ],
            "errors": [],
        },
        "isomaps": [
            {
                "index": i,
                "id": record.record_id,
                "fields": decode_fields(record.body, "IsoMap_Save"),
            }
            for i, record in enumerate(model.isomaps)
        ],
        "persons": [
            {
                "index": i,
                "id": record.record_id,
                "fields": decode_fields(record.body, "PersonList_Save"),
            }
            for i, record in enumerate(model.persons)
        ],
        "cars": [
            {
                "index": i,
                "id": record.record_id,
                "fields": decode_fields(record.body, "CarList_Save"),
            }
            for i, record in enumerate(model.cars)
        ],
        "city_mapobjects": {
            "count": model.city_count,
            "raw_sha256": _sha256_hex(model.city_raw),
        },
        "companies": [
            {
                "slot": i,
                "present": 1 if slot.present else 0,
                "fields": (
                    decode_fields(slot.body[:COMPANY_DIRECT_BODY],
                                  "CompanyData_Save")
                    if slot.present else None
                ),
                "trailing_zero": (
                    slot.body[COMPANY_DIRECT_BODY:] ==
                    b"\0" * (COMPANY_MIN_BODY - COMPANY_DIRECT_BODY)
                    if slot.present else None
                ),
            }
            for i, slot in enumerate(model.companies)
        ],
        "ai_company_body_sha256": _sha256_hex(model.ai_company_body),
        "selected": {
            "present": 1 if model.selected.present else 0,
            "player_slot": model.selected.player_slot,
            "company_id": model.selected.company_id,
            "trailing": model.selected.trailing,
            "raw_length": len(model.selected.raw),
            "raw_sha256": _sha256_hex(model.selected.raw),
        },
        "runtime": [
            {
                "slot": i,
                "present": 1 if slot.present else 0,
                "x": slot.x,
                "y": slot.y,
                "kind": slot.kind,
                "trailing": slot.trailing,
            }
            for i, slot in enumerate(model.runtime)
        ],
        "fixed_prefix_sha256": _sha256_hex(model.fixed_prefix),
        "end_marker": END_MARKER,
    }


def expected_view(model: SaveModel, directory: Iterable[int]) -> dict:
    view = model_view(model)
    view["directory"] = tuple(directory)
    view["problems"] = []
    return view


def semantic_view(save: piz.PizSave, parsed_model: SaveModel) -> dict:
    """Model view with every value PizSave exposes replaced by its reading."""
    view = model_view(parsed_model)
    view["header"] = _header_dict(save.header)
    view["directory"] = tuple(save.directory)
    view["briefings"] = [
        {
            "index": entry.index,
            "entry_id": entry.entry_id,
            "length": entry.length,
            "text": entry.text,
        }
        for entry in save.briefing
    ]
    view["tile_names"] = tuple(save.tile_names)
    view["counts"] = dict(save.counts)

    characters = save.parse_characters()
    view["characters"] = {
        "count": characters["count"],
        "records": characters["records"],
        "errors": characters["errors"],
    }
    players = save.parse_players()
    view["players"] = {
        "slots": players["slots"],
        "errors": players["errors"],
    }
    view["problems"] = list(save.problems)
    return view


# ---------------------------------------------------------------------------
# Round-trip oracle
# ---------------------------------------------------------------------------

def _parse_bytes(data: bytes) -> piz.PizSave:
    fd, path = tempfile.mkstemp(
        prefix="piz_fuzz_", suffix=".piz", dir=_TMP_DIR)
    try:
        with os.fdopen(fd, "wb") as fh:
            fh.write(data)
        return piz.PizSave(path)
    finally:
        try:
            os.unlink(path)
        except OSError:
            pass


def _semantic_digest(view: dict) -> str:
    blob = json.dumps(
        view, sort_keys=True, separators=(",", ":"),
        ensure_ascii=False).encode("utf-8")
    return _sha256_hex(blob)


def _check_roundtrip(data: bytes, *, expected_model: SaveModel | None = None,
                     expected_directory: Iterable[int] | None = None,
                     label: str = "bytes") -> dict:
    save = _parse_bytes(data)
    if save.problems:
        raise FuzzMismatch(
            label, "parse", "PizSave problems: " + "; ".join(save.problems))
    parsed = decode_save(save)

    reencoded = encode_save(parsed)
    if reencoded.data != data:
        offset = _first_difference(data, reencoded.data)
        raise FuzzMismatch(
            label, "encode",
            f"byte mismatch at 0x{offset:x}: "
            f"original={len(data)} bytes, re-encoded={len(reencoded.data)} bytes")

    save2 = _parse_bytes(reencoded.data)
    if save2.problems:
        raise FuzzMismatch(
            label, "reparse",
            "PizSave problems after re-encode: " + "; ".join(save2.problems))
    parsed2 = decode_save(save2)

    view = semantic_view(save, parsed)
    view2 = semantic_view(save2, parsed2)
    if view != view2:
        key = _first_different_key(view, view2)
        raise FuzzMismatch(
            label, "semantic-reparse",
            f"semantic view differs after re-parse at {key!r}")

    if expected_model is not None:
        directory = (
            tuple(expected_directory)
            if expected_directory is not None
            else encode_save(expected_model).directory
        )
        expected = expected_view(expected_model, directory)
        if expected != view:
            key = _first_different_key(expected, view)
            raise FuzzMismatch(
                label, "semantic-model",
                f"parser view differs from generated model at {key!r}")

    return {
        "size": len(data),
        "sha256": _sha256_hex(data),
        "semantic_sha256": _semantic_digest(view),
        "briefings": len(parsed.briefings),
        "characters": len(parsed.characters),
        "players_present": sum(1 for slot in parsed.players if slot.present),
    }


def fuzz_roundtrip(seed: int, limits: FuzzLimits | None = None) -> dict:
    """Run one deterministic seeds -> bytes -> parse -> encode round-trip.

    Raises FuzzMismatch with the failing stage on any discrepancy.  On success
    returns a small dictionary describing the generated save.
    """
    model = random_model(random.Random(seed), limits)
    encoded = encode_save(model)
    try:
        result = _check_roundtrip(
            encoded.data,
            expected_model=model,
            expected_directory=encoded.directory,
            label=f"seed {seed}",
        )
    except FuzzMismatch as exc:
        exc.seed = seed
        raise
    result["seed"] = seed
    return result


def verify_bytes(data: bytes, *, expected_model: SaveModel | None = None,
                 expected_directory: Iterable[int] | None = None,
                 label: str = "bytes") -> dict:
    """Public oracle entry point for already-generated save bytes."""
    return _check_roundtrip(
        data,
        expected_model=expected_model,
        expected_directory=expected_directory,
        label=label,
    )


# ---------------------------------------------------------------------------
# Boundary corpus
# ---------------------------------------------------------------------------

def _boundary_empty() -> SaveModel:
    return empty_model()


def _boundary_max_counts() -> SaveModel:
    model = empty_model()
    model.title = "Max counts"
    model.company = "Max Company"
    model.city = "Max City"
    model.player_count = 6
    model.player_flags = [1, 1, 1, 1, 1, 1, 0]
    model.game_calendar = [1, 2, 3, 4]
    model.system_time = _system_time(2026, 11, 18, 12, 34, 56, 789)
    model.fixed_prefix = _pattern_bytes(FIXED_PREFIX_SIZE, 1)

    model.players = [
        PlayerSlot(
            True,
            player=_pattern_bytes(PLAYER_BODY, 10 + i),
            character=_pattern_bytes(CHARACTER_BODY, 20 + i),
            events=[
                _pattern_bytes(EVENT_BODY, 30 + i * 10 + j)
                for j in range(4)
            ],
            ai=_pattern_bytes(AI_BODY, 40 + i),
            mission=_pattern_bytes(MISSION_BODY, 50 + i),
        )
        for i in range(6)
    ]
    model.companies = [
        CompanySlot(True, _company_body_pattern(60 + i))
        for i in range(6)
    ]
    model.characters = [
        IdRecord(1000 + i, _pattern_bytes(CHARACTER_BODY, 70 + i))
        for i in range(8)
    ]
    model.isomaps = [
        IdRecord(2000 + i, _pattern_bytes(ISOMAP_BODY, 80 + i))
        for i in range(4)
    ]
    model.persons = [
        IdRecord(3000 + i, _pattern_bytes(PERSON_BODY, 90 + i))
        for i in range(8)
    ]
    model.cars = [
        IdRecord(4000 + i, _pattern_bytes(CAR_BODY, 100 + i))
        for i in range(8)
    ]
    model.briefings = [
        Briefing(i, _pattern_text(64, 110 + i).encode("cp1252"))
        for i in range(16)
    ]
    model.tile_names = [f"t{i:04d}" for i in range(TILE_COUNT)]
    model.ai_company_body = _pattern_bytes(AI_COMPANY_BODY, 120)
    model.selected = SelectedSlot(
        True, 0, 0x12345678, 0x9ABCDEF0,
        struct.pack("<IIII", 1, 0, 0x12345678, 0x9ABCDEF0))
    model.runtime = [
        RuntimeSlot(True, i, i + 1, i + 2, 0x100 + i) for i in range(6)
    ]
    return model


def _boundary_zero_globals() -> SaveModel:
    model = empty_model()
    model.title = "Zero globals"
    model.company = "Zero Company"
    model.city = "Zero City"
    model.player_count = 1
    model.player_flags = [1, 0, 0, 0, 0, 0, 0]
    model.players[0] = PlayerSlot(
        True, b"\0" * PLAYER_BODY, b"\0" * CHARACTER_BODY, [], None, None)
    model.companies[0] = CompanySlot(True, b"\0" * COMPANY_MIN_BODY)
    # fixed_prefix, tile names, AI body, selected and runtime stay all-zero.
    return model


def _boundary_max_strings() -> SaveModel:
    model = empty_model()
    model.title = "T" * 63
    model.company = "C" * 63
    model.city = "X" * 63
    model.player_count = 1
    model.player_flags = [1, 0, 0, 0, 0, 0, 0]
    model.players[0] = PlayerSlot(
        True, b"\0" * PLAYER_BODY, b"\0" * CHARACTER_BODY, [], None, None)
    model.briefings = [
        Briefing(i, b"B" * 4096) for i in range(4)
    ]
    model.tile_names = ["Z" * (TILE_RECORD_SIZE - 1)] * TILE_COUNT
    return model


def _boundary_cp1252() -> SaveModel:
    model = empty_model()
    model.title = "Café Ünïcode €"
    model.company = "Crème brûlée & Co.®"
    model.city = "Zürich"
    model.player_count = 1
    model.player_flags = [1, 0, 0, 0, 0, 0, 0]
    model.players[0] = PlayerSlot(
        True, b"\0" * PLAYER_BODY, b"\0" * CHARACTER_BODY, [], None, None)
    model.briefings = [
        Briefing(0, "Été à Noël — € 5".encode("cp1252")),
        Briefing(1, "garçon, s'il vous plaît".encode("cp1252")),
    ]
    for index, text in enumerate([
        "é" * 49,
        "€" * 49,
        "Ça va? " * 7,
        "ß" * 49,
    ]):
        model.tile_names[index * 101] = text[:TILE_RECORD_SIZE - 1]
    return model


def _boundary_all_slots() -> SaveModel:
    model = empty_model()
    model.title = "All slots"
    model.company = "All Slots Inc."
    model.city = "Slotsville"
    model.player_count = 6
    model.player_flags = [1, 1, 1, 1, 1, 1, 0]
    model.players = [
        PlayerSlot(
            True, b"\0" * PLAYER_BODY, b"\0" * CHARACTER_BODY, [], None, None)
        for _ in range(6)
    ]
    model.companies = [
        CompanySlot(True, b"\0" * COMPANY_MIN_BODY) for _ in range(6)
    ]
    model.briefings = [
        Briefing(0, b"first"),
        Briefing(1, b"second"),
    ]
    model.selected = SelectedSlot(
        True, 5, 0xDEADBEEF, 0, struct.pack("<IIII", 1, 5, 0xDEADBEEF, 0))
    model.runtime = [
        RuntimeSlot(True, i, i, i, i) for i in range(6)
    ]
    return model


_BOUNDARY_BUILDERS = (
    ("empty", _boundary_empty),
    ("max_counts", _boundary_max_counts),
    ("zero_globals", _boundary_zero_globals),
    ("max_strings", _boundary_max_strings),
    ("cp1252_strings", _boundary_cp1252),
    ("all_slots", _boundary_all_slots),
)

_BOUNDARY_CACHE: tuple[BoundaryCase, ...] | None = None


def boundary_corpus() -> tuple[BoundaryCase, ...]:
    """Return the deterministic boundary corpus, encoding each case once."""
    global _BOUNDARY_CACHE
    if _BOUNDARY_CACHE is None:
        cases = []
        for name, builder in _BOUNDARY_BUILDERS:
            model = builder()
            cases.append(BoundaryCase(name, model, encode_save(model)))
        _BOUNDARY_CACHE = tuple(cases)
    return _BOUNDARY_CACHE


# ---------------------------------------------------------------------------
# Runner
# ---------------------------------------------------------------------------

def run(seed_count: int = 100, seed0: int = 0,
        include_boundary: bool = True) -> dict:
    """Run a deterministic corpus and return a machine-readable summary."""
    if seed_count < 0:
        raise ValueError("seed_count must be non-negative")
    started = time.perf_counter()
    sizes: list[int] = []
    mismatches: list[dict] = []
    passed = 0
    failed = 0
    hasher = hashlib.sha256()

    boundary_cases = boundary_corpus() if include_boundary else ()
    for case in boundary_cases:
        data = case.encoded.data
        sizes.append(len(data))
        hasher.update(b"boundary:")
        hasher.update(case.name.encode("utf-8"))
        hasher.update(struct.pack("<Q", 0))
        hasher.update(hashlib.sha256(data).digest())
        try:
            _check_roundtrip(
                data,
                expected_model=case.model,
                expected_directory=case.encoded.directory,
                label=f"boundary {case.name}",
            )
            passed += 1
        except Exception as exc:  # noqa: BLE001 - report every failing case
            failed += 1
            mismatches.append({
                "label": f"boundary {case.name}",
                "seed": None,
                "error": f"{type(exc).__name__}: {exc}",
            })

    for seed in range(seed0, seed0 + seed_count):
        try:
            model = random_model(random.Random(seed), FuzzLimits())
            encoded = encode_save(model)
            data = encoded.data
            sizes.append(len(data))
            hasher.update(b"seed:")
            hasher.update(struct.pack("<Q", seed))
            hasher.update(hashlib.sha256(data).digest())
            _check_roundtrip(
                data,
                expected_model=model,
                expected_directory=encoded.directory,
                label=f"seed {seed}",
            )
            passed += 1
        except Exception as exc:  # noqa: BLE001 - report every failing case
            failed += 1
            mismatches.append({
                "label": f"seed {seed}",
                "seed": seed,
                "error": f"{type(exc).__name__}: {exc}",
            })

    cases = len(boundary_cases) + seed_count
    corpus_hash = hasher.hexdigest()
    return {
        "seed_count": seed_count,
        "seed0": seed0,
        "boundary_count": len(boundary_cases),
        "include_boundary": include_boundary,
        "cases": cases,
        "passed": passed,
        "failed": failed,
        "mismatch_count": len(mismatches),
        "mismatches": mismatches,
        "bytes_min": min(sizes) if sizes else 0,
        "bytes_max": max(sizes) if sizes else 0,
        "bytes_total": sum(sizes),
        "corpus_hash": corpus_hash,
        "corpus_sha256": corpus_hash,
        "runtime_seconds": round(time.perf_counter() - started, 3),
    }


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def format_summary(summary: dict) -> str:
    lines = [
        f"fuzz_piz: seeds={summary['seed_count']} "
        f"seed0={summary['seed0']} boundary={summary['boundary_count']}",
        f"cases: {summary['cases']}  passed: {summary['passed']}  "
        f"failed: {summary['failed']}",
        f"bytes: min={summary['bytes_min']:,} max={summary['bytes_max']:,} "
        f"total={summary['bytes_total']:,}",
        f"corpus sha256: {summary['corpus_sha256']}",
        f"runtime: {summary['runtime_seconds']:.3f}s",
    ]
    for mismatch in summary["mismatches"]:
        lines.append(f"FAIL {mismatch['label']}: {mismatch['error']}")
    return "\n".join(lines)


def main(argv=None) -> int:
    parser = argparse.ArgumentParser(
        description="Deterministic synthetic-save fuzz oracle for .piz files")
    parser.add_argument("--seeds", type=int, default=100,
                        help="number of deterministic seeds (default: 100)")
    parser.add_argument("--seed0", type=int, default=0,
                        help="first seed (default: 0)")
    parser.add_argument("--no-boundary", action="store_true",
                        help="skip the boundary corpus")
    parser.add_argument("--json", action="store_true",
                        help="print the summary as JSON")
    args = parser.parse_args(argv)

    summary = run(
        seed_count=args.seeds,
        seed0=args.seed0,
        include_boundary=not args.no_boundary,
    )
    if args.json:
        print(json.dumps(summary, indent=2, sort_keys=True))
    else:
        print(format_summary(summary))
    return 0 if summary["failed"] == 0 else 1


if __name__ == "__main__":
    raise SystemExit(main())
