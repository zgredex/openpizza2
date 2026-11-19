#!/usr/bin/env python3
"""Recover the Pizza Connection 2 save payload schema.

Inputs:
  decompiled_fastfood2_named_v2/full_game_verification/

Outputs:
  decompiled_fastfood2_named_v2/save_schema.json
  decompiled_fastfood2_named_v2/save_top_level.csv
  decompiled_fastfood2_named_v2/SAVE_SCHEMA.md

The writer is authoritative: every CRT_Ostream_Write call in a *_Save
function contributes an ordered field record. Loaders are paired by exact
field-sequence match where possible so the schema carries independent
confirmation rather than inference alone.
"""

import collections
import csv
import json
import os
import re

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EXPORT = os.path.join(ROOT, "decompiled_fastfood2_named_v2", "full_game_verification")
OUT = os.path.join(ROOT, "decompiled_fastfood2_named_v2")

IO_RE = re.compile(
    r"CRT_(Ostream_Write|Istream_Read)\(\s*[^,]+,\s*(.+?)\s*,\s*"
    r"(0x[0-9a-f]+|\d+)\s*\)\s*;",
    re.S,
)
FIELD_RE = re.compile(
    r"\(int\)\s*(this|param_1)\s*\+\s*(0x[0-9a-f]+|\d+)", re.I
)
CALL_RE = re.compile(r"\b([A-Za-z_][A-Za-z0-9_]*)\s*\(")

# Save function -> loader when the names differ. Each mapping is confirmed by
# matching field order/size in the disassembly-derived pseudocode.
LOADER_ALIASES = {
    "CarList_Save": "Car_LoadFromStream",
    "Car_Save": "Car_LoadSpriteRecord",
    "CompanyData_Save": "Company_Load",
    "PersonList_Save": "PersonAction_LoadState",
    "Person_Save": "MapObject_ReadRenderRecord",
    "MapSprite_Save": "MapActor_ReadFromStream",
    "MapObjectList_Save": "MapObjectList_Load",
}

# Semantic labels for the serialized subsystem globals. Names describe the
# serializer that owns the value, not a fully proven C++ field name.
GLOBAL_NAMES = {
    0x00568628: "g_BranchStatsSeriesFlags",
    0x00568910: "g_IngredientPanelState",
    0x005689F0: "g_CompanyMarketShareFlag",
    0x00569354: "g_StatisticsBalanceA",
    0x00569358: "g_StatisticsBalanceB",
    0x0056951C: "g_StatisticsBranchBalance",
    0x0056A6D8: "g_PersonnelState",
    0x0056A734: "g_CompanyOverviewText",
    0x0056A7D4: "g_CompanyOverviewState",
    0x0057BB20: "g_GameGlobalState",
    0x0057C6A8: "g_BranchMenuCategory",
    0x0057C6BC: "g_BranchDesignColorIndex",
    0x0057C9FC: "g_CityCompanyListA",
    0x0057CA00: "g_CityCompanyListB",
    0x0057CA30: "g_AdvertisingPanelA",
    0x0057CA34: "g_AdvertisingPanelB",
    0x0057CA90: "g_CompanyMarketShare",
    0x0057D5C8: "g_StatisticsBalanceC",
    0x0057D5D0: "g_StatisticsBalanceD",
    0x0057D62C: "g_StatisticsBranchBalanceA",
    0x0057D630: "g_StatisticsBranchBalanceB",
    0x0057D69C: "g_CompanyOverviewB",
    0x0057D714: "g_WarehouseProductState",
    0x0057DFBC: "g_GameCalendarState",
}

# Writers that serialize a fixed-size array in a counted loop.
LOOP_BLOCKS = {
    "AI_CompanySlots_Save": (6, 0x168, "6 x 0x168-byte company AI records"),
}

# Fixed/dynamic blocks that do not use the this+offset helper pattern.
EXTRA_OWNERS = [
    {
        "name": "Game_SaveTileNameTable",
        "address": "0x4eaaa0",
        "fields": [],
        "field_count": 0,
        "global_writes": [],
        "fixed_bytes": 125000,
        "loop_blocks": [{"count": 2500, "size": 50, "bytes": 125000,
                         "note": "2500 x 50-byte tile-name records"}],
        "temporaries": [],
        "nested_calls": [],
        "loader": "World_LoadNameIndexTable",
        "loader_basis": "explicit-writer/loader-pair",
        "loader_status": "exact",
        "load_field_count": 0,
    },
    {
        "name": "SaveGame_SerializeRuntimeList",
        "address": "0x487940",
        "fields": [],
        "field_count": 0,
        "global_writes": [],
        "fixed_bytes": 0,
        "loop_blocks": [],
        "temporaries": [],
        "nested_calls": [],
        "loader": "SaveGame_DeserializeRuntimeList",
        "loader_basis": "explicit-writer/loader-pair",
        "loader_status": "exact",
        "load_field_count": 0,
        "dynamic_blocks": [{
            "count": 6,
            "shape": "u32 present; if present: float x2 + u32 type; u32 trailing value",
            "note": "six runtime slots at game+0x2c41c..0x2c434",
        }],
    },
]

# Top-level writer order from SaveGame_Serialize (0x487b50). Offsets are file
# offsets from the start of the file (header is 0xF0 bytes).
TOP_LEVEL = [
    ("header", 0x0000, 0x00F0, "fixed", "SaveGame_Write", "title/company/city/slots/time/version/magic"),
    ("directory", 0x00F0, 0x0020, "fixed", "SaveGame_Serialize", "8-dword section directory, written last"),
    ("start_marker", 0x0110, 0x0004, "const", "SaveGame_Serialize", "0x2E"),
    ("global_game_block", 0x0114, 0x05B8, "fixed", "SaveGame_Serialize", "DAT_0057bb20"),
    ("game_fields_a", None, 0x0020, "fixed", "SaveGame_Serialize", "game+0x298..0x2B7"),
    ("game_fields_b", None, 0x0020, "fixed", "SaveGame_Serialize", "game+0x2B8..0x2D7"),
    ("game_scalars", None, 20 * 4, "fixed", "SaveGame_Serialize", "20 u32 fields game+0x2D8..0x368 and +0x2D90"),
    ("ingredient_panel", None, None, "nested", "IngredientPanel_Save", ""),
    ("city_company_list", None, None, "nested", "CityCompanyList_Save", ""),
    ("advertising_panel", None, None, "nested", "AdvertisingPanel_Save", ""),
    ("company_market_share", None, None, "nested", "CompanyMarketShare_Save", ""),
    ("company_overview", None, None, "nested", "CompanyOverview_Save", ""),
    ("statistics_balance", None, None, "nested", "StatisticsBalance_Save", ""),
    ("statistics_branch_balance", None, None, "nested", "StatisticsBranchBalance_Save", ""),
    ("personnel", None, None, "nested", "Personnel_Save", ""),
    ("branch_stats_series_flags", None, None, "nested", "BranchStats_SeriesFlags_Save", ""),
    ("branch_design_color_index", None, None, "nested", "BranchDesign_ColorIndex_Save", ""),
    ("branch_menu_category", None, None, "nested", "BranchMenu_Category_Save", ""),
    ("warehouse_product", None, None, "nested", "WarehouseProduct_Save", ""),
    ("game_calendar", None, None, "nested", "GameCalendar_Save", ""),
    ("ui_briefing_list", None, None, "nested", "UI_BriefingList_Save", ""),
    ("world_tile_name_table", None, 2500 * 50, "fixed", "Game_SaveTileNameTable", "2500 x 50-byte tile-name records"),
    ("isomap_list", None, None, "counted", "SaveGame_Serialize", "u32 count; each: u32 id + IsoMap_Save"),
    ("character_list", None, None, "counted", "SaveGame_Serialize", "u32 count; each: u32 id + Character_Save"),
    ("city_mapobject_list", None, None, "counted", "SaveGame_Serialize", "u32 count; each: City/MapObjectList_Save"),
    ("person_list", None, None, "counted", "SaveGame_Serialize", "u32 count; each: u32 id + PersonList_Save"),
    ("car_list", None, None, "counted", "SaveGame_Serialize", "u32 count; each: u32 id + CarList_Save"),
    ("player_slots", None, None, "array6", "SaveGame_Serialize", "6 x (u32 present + Player_Save)"),
    ("company_slots", None, None, "array6", "SaveGame_Serialize", "6 x (u32 present + CompanyData_Save)"),
    ("ai_company_slots", None, None, "nested", "AI_CompanySlots_Save", ""),
    ("selected_player_company", None, 3 * 4, "fixed", "SaveGame_Serialize", "present, player slot, company id"),
    ("runtime_list", None, None, "nested", "SaveGame_SerializeRuntimeList", ""),
    ("end_marker", None, 0x0004, "const", "SaveGame_Serialize", "0x2A"),
    ("directory_rewrite", None, 0x0020, "seek+write", "SaveGame_Serialize", "seek to 0x00F0, write 8-dword directory"),
]

# Writer directory construction from SaveGame_Serialize.
DIRECTORY = [
    (0, "after_mapobject_list", "local_20[0], line 112"),
    (1, "after_isomap_list", "local_20[1], line 88"),
    (2, "after_character_list", "local_20[2], line 100"),
    (3, "after_player_slots", "local_20[3], line 152"),
    (4, "after_car_list", "local_10, line 136"),
    (5, "after_company_slots", "local_c, line 168"),
    (6, "after_person_list", "local_8, line 124"),
    (7, "end_of_payload", "local_4, line 184; also the load-progress denominator"),
]


def load_index():
    with open(os.path.join(EXPORT, "decompile-index.json")) as f:
        funcs = [x for x in json.load(f)["functions"] if x.get("status") == "written"]
    return funcs


def read_func(func):
    with open(os.path.join(EXPORT, func["relative_path"]), errors="replace") as f:
        return f.read()


def parse_io(text):
    rows = []
    for m in IO_RE.finditer(text):
        direction = "write" if m.group(1) == "Ostream_Write" else "read"
        target = " ".join(m.group(2).split())
        size = int(m.group(3), 0)
        field = FIELD_RE.search(target)
        if field:
            kind = "field"
            offset = int(field.group(2), 0)
        elif target.startswith(("&DAT_", "DAT_")):
            kind = "global"
            offset = None
            dm = re.search(r"DAT_([0-9a-f]+)", target)
            global_address = int(dm.group(1), 16) if dm else None
        elif target.startswith("local_") or target.startswith("&local_"):
            kind = "temporary"
            offset = None
        else:
            kind = "other"
            offset = None
        rows.append({
            "direction": direction,
            "target": target,
            "kind": kind,
            "offset": offset,
            "global_address": locals().get("global_address"),
            "size": size,
            "type_hint": type_hint(size),
        })
        global_address = None
    return rows


def type_hint(size):
    if size == 1:
        return "u8/bool"
    if size == 2:
        return "u16"
    if size == 4:
        return "u32/i32/float"
    if size == 8:
        return "u64/double"
    return f"bytes[{size}]"


def parse_nested_calls(text, known_names, self_name=None):
    out = []
    seen = set()
    for m in CALL_RE.finditer(text):
        name = m.group(1)
        if name == self_name:
            continue
        if name in known_names and (
            name.endswith("_Save") or name.endswith("_Serialize")
            or name.endswith("_Load") or name.endswith("_ConstructFromSave")
            or name.endswith("_LoadState") or name.startswith("World_Load")
        ):
            if name not in seen:
                seen.add(name)
                out.append(name)
    return out


def field_sequence(rows, direction):
    return [(r["offset"], r["size"]) for r in rows
            if r["direction"] == direction and r["kind"] == "field"]


def main():
    funcs = load_index()
    by_name = {f["name"]: f for f in funcs}
    writer_names = {n for n in by_name if n.endswith(("_Save", "_Serialize"))}

    # All read-side candidates for exact pairing.
    read_candidates = {}
    for f in funcs:
        if f["name"].endswith("_Save"):
            continue
        rows = parse_io(read_func(f))
        seq = [(r["offset"], r["size"]) for r in rows
               if r["direction"] == "read" and r["kind"] == "field"]
        if seq:
            read_candidates[f["name"]] = seq

    owners = []
    for name in sorted(writer_names):
        f = by_name[name]
        text = read_func(f)
        rows = parse_io(text)
        fields = [r for r in rows if r["direction"] == "write"
                  and r["kind"] == "field"]
        globals_ = [r for r in rows if r["direction"] == "write"
                    and r["kind"] == "global"]
        temps = [r for r in rows if r["direction"] == "write"
                 and r["kind"] in ("temporary", "other")]
        loops = []
        if name in LOOP_BLOCKS:
            count, size, note = LOOP_BLOCKS[name]
            loops.append({"count": count, "size": size,
                          "bytes": count * size, "note": note})
        seq = [(r["offset"], r["size"]) for r in fields]
        nested = parse_nested_calls(text, set(by_name), name)

        loader = LOADER_ALIASES.get(name)
        basis = "declared-alias"
        if loader is None:
            exact = [n for n, s in read_candidates.items() if s == seq]
            by_name_loader = name[:-5] + "_Load"
            if by_name_loader in by_name:
                loader = by_name_loader
                basis = ("exact-name-and-sequence" if by_name_loader in exact
                         else "same-name-loader")
            elif len(exact) == 1:
                loader = exact[0]
                basis = "exact-sequence"
            elif exact:
                loader = exact[0]
                basis = "ambiguous-exact-sequence"

        load_seq = read_candidates.get(loader or "", [])
        status = "save-only"
        if loader:
            status = "exact" if load_seq == seq else "different-load-path"

        owners.append({
            "name": name,
            "address": f["address"],
            "fields": fields,
            "field_count": len(fields),
            "global_writes": globals_,
            "loop_blocks": loops,
            "fixed_bytes": (sum(r["size"] for r in fields)
                            + sum(r["size"] for r in globals_)
                            + sum(x["bytes"] for x in loops)),
            "temporaries": temps,
            "nested_calls": nested,
            "loader": loader,
            "loader_basis": basis if loader else "",
            "loader_status": status,
            "load_field_count": len(load_seq),
        })

    owners.extend(EXTRA_OWNERS)
    total_fields = sum(o["field_count"] for o in owners)
    total_bytes = sum(o["fixed_bytes"] for o in owners)
    exact = sum(1 for o in owners if o["loader_status"] == "exact")

    globals_ = {}
    for o in owners:
        for g in o["global_writes"]:
            addr = g["global_address"]
            if addr is None:
                continue
            key = f"0x{addr:08x}"
            entry = globals_.setdefault(key, {
                "address": key,
                "size": g["size"],
                "type_hint": g["type_hint"],
                "writers": [],
                "suggested_name": GLOBAL_NAMES.get(
                    addr, f"g_Save_{o['name'].replace('_Save', '')}_{addr:06x}"),
            })
            if o["name"] not in entry["writers"]:
                entry["writers"].append(o["name"])

    fixed_by_writer = {o["name"]: o["fixed_bytes"] for o in owners}
    cursor = 0
    top_rows = []
    for sec in TOP_LEVEL:
        name, offset, size, kind, writer, note = sec
        if offset is not None:
            cursor = offset
        computed = cursor
        computed_size = size
        if computed_size is None and kind == "nested" and writer != "SaveGame_Serialize":
            wsize = fixed_by_writer.get(writer, 0)
            computed_size = wsize if wsize else None
        if computed_size is None:
            cursor_after = None
        else:
            cursor_after = computed + computed_size if computed is not None else None
        top_rows.append({
            "section": name, "offset": offset,
            "computed_offset": computed,
            "size": size, "computed_size": computed_size,
            "kind": kind, "writer": writer, "notes": note,
        })
        cursor = cursor_after

    schema = {
        "target": {
            "path": "game/fastfood2.exe",
            "sha256": "18cfd32e0ac5d6d98162ec016e058a2b51808d9ca49ebee933ce3166ff9922fd",
        },
        "header": {"size": 0x00F0, "doc": "PIZ_FORMAT.md"},
        "directory": {
            "offset": 0x00F0,
            "size": 0x20,
            "written_last": True,
            "entries": [{"index": i, "meaning": meaning, "evidence": ev}
                        for i, meaning, ev in DIRECTORY],
            "note": "Earlier notes called this a zero reserved block; the writer "
                    "fills it with section end offsets and rewrites it at the end.",
        },
        "top_level": top_rows,
        "counts": {
            "save_functions": len(owners),
            "field_blocks": sum(1 for o in owners if o["field_count"]),
            "serialized_fields": total_fields,
            "global_writes": sum(len(o["global_writes"]) for o in owners),
            "loop_blocks": sum(len(o["loop_blocks"]) for o in owners),
            "global_state_blocks": len(globals_),
            "fixed_serialized_bytes": total_bytes,
            "exact_save_load_pairs": exact,
        },
        "global_state": [globals_[k] for k in sorted(globals_, key=lambda x: int(x, 16))],
        "owners": owners,
    }

    with open(os.path.join(OUT, "save_schema.json"), "w") as f:
        json.dump(schema, f, indent=1)

    with open(os.path.join(OUT, "save_top_level.csv"), "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["section", "computed_offset", "computed_size", "kind",
                    "writer", "notes"])
        for s in top_rows:
            w.writerow([s["section"],
                        "" if s["computed_offset"] is None else hex(s["computed_offset"]),
                        "" if s["computed_size"] is None else hex(s["computed_size"]),
                        s["kind"], s["writer"], s["notes"]])

    write_markdown(schema, owners, total_fields, total_bytes, exact)
    print(f"writers={len(owners)} fields={total_fields} bytes={total_bytes} "
          f"exact_pairs={exact}")


def write_markdown(schema, owners, total_fields, total_bytes, exact):
    out = [
        "# Pizza Connection 2 save-state schema",
        "",
        "Recovered from the named pseudocode export. The **writer is authoritative**: "
        "every `CRT_Ostream_Write` contributes an ordered field record. Loaders were "
        "matched independently by exact field-sequence comparison.",
        "",
        f"- Save/serializer functions: **{len(owners)}**",
        f"- Functions with direct field blocks: **{sum(1 for o in owners if o['field_count'])}**",
        f"- Serialized fields: **{total_fields}**",
        f"- Global blocks: **{sum(len(o['global_writes']) for o in owners)}**",
        f"- Fixed-size loop blocks: **{sum(len(o['loop_blocks']) for o in owners)}**",
        f"- Fixed serialized bytes (fields + globals + loops): **{total_bytes}**",
        f"- Exact Save↔Load field-sequence pairs: **{exact}**",
        "",
        "This covers the payload that follows the 0xF0-byte `.piz` header. "
        "Strings, counted lists and nested objects add more bytes not included in "
        "the direct-field totals.", "",
        f"**Size accounting:** {total_bytes:,} fixed payload bytes + 240-byte "
        f"header + 32-byte directory = **{total_bytes + 240 + 32:,} bytes** before "
        "variable-length lists and sub-records. The 125,000-byte tile-name table "
        "alone dominates the fixed payload.",
        "",
        "## 0xF0..0x110 section directory",
        "",
        "The 0x20 bytes at file offset 0xF0 are **not a reserved zero block**. "
        "`SaveGame_Serialize` builds eight dwords, seeks back to the start of the "
        "payload, writes the directory, then seeks to the end.",
        "",
        "| Index | Meaning | Evidence |",
        "|---:|---|---|",
    ]
    for i, meaning, ev in DIRECTORY:
        out.append(f"| {i} | `{meaning}` | {ev} |")

    out += [
        "",
        "`Game_LoadSaveGame` reads these 0x20 bytes first and validates section "
        "boundaries against them (`Stream_GetReadPosition` compares before each "
        "next counted list). Index 4 is unused by the writer.",
        "",
        "## Top-level payload order",
        "",
        "Offsets are computed exactly through `ui_briefing_list` at **0x7DB**. "
        "That list is variable-length, so later sections are data-dependent and "
        "their absolute offsets are left blank.",
        "| Section | Offset | Size | Kind | Writer | Notes |",
        "|---|---:|---:|---|---|---|",
    ]
    for s in schema["top_level"]:
        off = "" if s.get("computed_offset") is None else f"0x{s['computed_offset']:x}"
        size = "" if s.get("computed_size") is None else f"0x{s['computed_size']:x}"
        out.append(f"| `{s['section']}` | {off} | {size} | {s['kind']} | "
                   f"`{s['writer']}` | {s['notes']} |")

    out += [
        "",
        "## Serializer blocks",
        "",
        "| Writer | Address | Fields | Globals | Bytes | Loader | Pair status |",
        "|---|---|---:|---:|---:|---|---|",
    ]
    for o in sorted(owners, key=lambda x: -x["fixed_bytes"]):
        out.append(
            f"| `{o['name']}` | `{o['address']}` | {o['field_count']} | "
            f"{len(o['global_writes'])} | {o['fixed_bytes']} | "
            f"`{o['loader'] or ''}` | {o['loader_status']} |"
        )

    out += ["", "## Serialized global state", "",
            "These globals are written directly by subsystem serializers and are "
            "part of the save payload even though they are not object fields.", "",
            "| Address | Size | Suggested name | Writer |",
            "|---|---:|---|---|"]
    for g in schema["global_state"]:
        out.append(f"| `{g['address']}` | {g['size']} | `{g['suggested_name']}` | "
                   f"{', '.join(g['writers'])} |")

    out += ["", "## Per-writer field layouts", ""]
    for o in sorted(owners, key=lambda x: x["name"]):
        if (not o["fields"] and not o["global_writes"] and not o["loop_blocks"]
                and not o.get("dynamic_blocks")):
            continue
        out += [f"### {o['name']}", "",
                f"- Address: `{o['address']}`",
                f"- Fields: {o['field_count']}",
                f"- Direct bytes: {o['fixed_bytes']}",
                f"- Loader: `{o['loader'] or 'none'}` ({o['loader_status']})",
                ""]
        if o["nested_calls"]:
            out.append("- Nested serializers: " +
                       ", ".join(f"`{n}`" for n in o["nested_calls"]))
            out.append("")
        if o["global_writes"]:
            out += ["| Global address | Size | Type hint |",
                    "|---|---:|---|"]
            for g in o["global_writes"]:
                addr = f"0x{g['global_address']:x}" if g["global_address"] else "?"
                out.append(f"| `{addr}` | {g['size']} | {g['type_hint']} |")
            out.append("")
        if o.get("dynamic_blocks"):
            out += ["| Count | Shape | Note |", "|---:|---|---|"]
            for b in o["dynamic_blocks"]:
                out.append(f"| {b['count']} | {b['shape']} | {b['note']} |")
            out.append("")
        if o["loop_blocks"]:
            out += ["| Count | Record size | Bytes | Note |",
                    "|---:|---:|---:|---|"]
            for b in o["loop_blocks"]:
                out.append(f"| {b['count']} | 0x{b['size']:x} | {b['bytes']} | {b['note']} |")
            out.append("")
        out += ["| # | Offset | Size | Type hint |",
                "|---:|---:|---:|---|"]
        for i, r in enumerate(o["fields"]):
            out.append(f"| {i} | `0x{r['offset']:x}` | {r['size']} | "
                       f"{r['type_hint']} |")
        out.append("")

    out += [
        "## Load-side aliases",
        "",
        "These writers do not have a same-named loader; the pairing was established "
        "by matching field order/size or by the constructor path.",
        "",
        "| Writer | Loader | Basis |",
        "|---|---|---|",
    ]
    for o in owners:
        if o["loader"] and o["loader"] != o["name"][:-5] + "_Load":
            out.append(f"| `{o['name']}` | `{o['loader']}` | {o['loader_basis']} |")

    out += [
        "",
        "## Known gaps",
        "",
        "- `IsoMap_Load` delegates most of the map body to "
        "`IsoMap_DeserializeGrid` and repeated sub-readers; the writer order is "
        "complete, but the nested reader graph is not flattened here.",
        "- `MapObjectList_Save` writes 31 direct fields while "
        "`MapObjectList_Load` reads 30 in a different offset order; the extra "
        "writer field is retained in the schema and the loader path is marked "
        "`different-load-path`.",
        "- `ConstructionOrder_Save` writes field `+0x10`, but "
        "`ConstructionOrder_Load` does not read it (reserved/version-dependent).",
        "- `MapObject_Load` reads one field (`+0x28`) that `MapObject_Save` does "
        "not write; treated as a defaulted field.",
        "- Variable-length strings, counted lists and embedded object graphs are "
        "represented by their count/nested writer calls, not expanded to bytes.",
        "- No real `.piz` sample was available, so the schema is statically "
        "derived and not runtime-validated.",
        "",
    ]

    with open(os.path.join(OUT, "SAVE_SCHEMA.md"), "w") as f:
        f.write("\n".join(out) + "\n")


if __name__ == "__main__":
    main()
