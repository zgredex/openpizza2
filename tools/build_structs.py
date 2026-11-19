#!/usr/bin/env python3
"""Generate typed C struct skeletons from the merged state model.

Outputs:
  decompiled_fastfood2_named_v2/game_structs.h
  decompiled_fastfood2_named_v2/structs_model.json
  decompiled_fastfood2_named_v2/STRUCTS.md
"""

from __future__ import annotations

import json
import os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BASE = os.path.join(ROOT, "decompiled_fastfood2_named_v2")

CLASS_SIZES = {
    "Game": 0x2F890,
    "Company": 0x1F0,
    "Player": 0xB0,
    "City": 0x1158,
    "WorldObject": 0x16C,
    "Character": 0x828,
    "IsoMap": 0x10178,
    "Car": 0x14,
}

# Highest-value structs for a modern engine / save editor.
TOP_CLASSES = [
    "Game", "GameWorld", "Company", "Branch", "Player", "PlayerAIState",
    "PlayerMissionState", "Player_Event", "City", "IsoMap", "MapObject",
    "WorldObject", "Character", "Recipe", "Ingredient", "GameClock",
    "GamePlan", "Storage", "StatsPeriodReport", "RecipeTopping",
    "BuildingValue", "ConstructionOrder", "Car", "UI_BriefingList",
    "UI_Manager", "Dialog", "Window", "Renderer",
]


def c_type(offset: int, size: int) -> str:
    if size == 1:
        return f"uint8_t field_0x{offset:x}"
    if size == 2:
        return f"uint16_t field_0x{offset:x}"
    if size == 4:
        return f"uint32_t field_0x{offset:x}"
    if size == 8:
        return f"uint64_t field_0x{offset:x}"
    return f"uint8_t field_0x{offset:x}[{size}]"


def build():
    classes = {c["class"]: c for c in
               json.load(open(os.path.join(BASE, "class_skeletons.json")))}
    model = json.load(open(os.path.join(BASE, "state_model.json")))
    model_by = {c["class"]: c for c in model["classes"]}

    structs = []
    for name in TOP_CLASSES:
        cls = classes.get(name)
        if not cls:
            continue
        observed = {}
        for off, info in cls["fields"].items():
            o = int(off, 16)
            observed[o] = {
                "size": info.get("size", 0),
                "hits": info.get("hits", 0),
                "functions": info.get("functions", []),
            }
        serialized = {}
        order = {}
        if name in model_by:
            for i, f in enumerate(model_by[name]["serialized_fields"]):
                o = int(f["offset"], 16)
                serialized[o] = {
                    "size": f["size"],
                    "type_hint": f["type_hint"],
                }
                order[o] = i

        size = CLASS_SIZES.get(name)
        if size is None:
            max_end = max((o + max(observed.get(o, {}).get("size", 0),
                                   serialized.get(o, {}).get("size", 0))
                           for o in set(observed) | set(serialized)),
                          default=4)
            size = max(4, (max_end + 3) & ~3)

        offsets = sorted(o for o in set(observed) | set(serialized) if o < size)
        fields = []
        cursor = 0
        for o in offsets:
            if o < cursor:
                continue
            obs = observed.get(o, {})
            ser = serialized.get(o, {})
            fsize = max(obs.get("size", 0), ser.get("size", 0))
            nxt = next((x for x in offsets if x > o), size)
            if fsize == 0:
                fsize = max(1, nxt - o)
            if o > cursor:
                fields.append({"offset": cursor, "size": o - cursor,
                               "kind": "padding", "decl": None})
            extent = min(fsize, nxt - o) if nxt > o else fsize
            if extent <= 0:
                extent = fsize
            comment = []
            if o in order:
                comment.append(f"save#{order[o]}")
                hint = serialized[o]["type_hint"]
                if hint:
                    comment.append(hint)
            if obs.get("functions"):
                comment.append("obs: " + ", ".join(obs["functions"][:3]))
            if o not in observed and o in serialized:
                comment.append("serialized-only")
            if o in observed and o not in serialized:
                comment.append("observed-only")
            fields.append({
                "offset": o,
                "size": extent,
                "kind": "field",
                "decl": c_type(o, extent),
                "comment": "; ".join(comment),
                "serialized_order": order.get(o),
            })
            cursor = o + extent
        if cursor < size:
            fields.append({"offset": cursor, "size": size - cursor,
                           "kind": "padding", "decl": None})
        structs.append({
            "class": name,
            "vtable": cls["vtable"],
            "size": size,
            "fields": fields,
            "serialized_count": len(serialized),
            "observed_count": len(observed),
        })

        if len(fields) == 0:
            structs[-1]["empty"] = True

    with open(os.path.join(BASE, "structs_model.json"), "w") as f:
        json.dump({"target": model["target"], "structs": structs}, f, indent=1)

    write_header(structs)
    write_markdown(structs)
    print(f"structs={len(structs)} fields="
          f"{sum(1 for s in structs for f in s['fields'] if f['kind']=='field')} "
          f"serialized={sum(s['serialized_count'] for s in structs)}")


def write_header(structs):
    lines = [
        "/* Pizza Connection 2 - typed state structs (skeleton)",
        " * Generated from class_skeletons.json + state_model.json.",
        " * Fields are placed at exact observed offsets; padding is explicit.",
        " * Names are structural (field_0xNN); comments carry save order and",
        " * observing functions. This is an analysis skeleton, not original source.",
        " */",
        "#ifndef PIZZA2_GAME_STRUCTS_H",
        "#define PIZZA2_GAME_STRUCTS_H",
        "",
        "#include <stdint.h>",
        "",
        "#pragma pack(push, 1)",
        "",
    ]
    for s in structs:
        lines.append(f"/* {s['class']} - {s['size']} bytes, "
                     f"vtable {s['vtable']} */")
        lines.append(f"typedef struct {s['class']} {{")
        for f in s["fields"]:
            if f["kind"] == "padding":
                lines.append(f"    uint8_t pad_0x{f['offset']:x}[{f['size']}];")
            else:
                comment = f"  /* {f['comment']} */" if f["comment"] else ""
                lines.append(f"    {f['decl']};{comment}")
        lines.append(f"}} {s['class']};")
        lines.append("")
    lines += [
        "#pragma pack(pop)",
        "",
        "#endif /* PIZZA2_GAME_STRUCTS_H */",
        "",
    ]
    with open(os.path.join(BASE, "game_structs.h"), "w") as f:
        f.write("\n".join(lines))


def write_markdown(structs):
    out = [
        "# Typed state structs",
        "",
        "Generated from the vtable field model and save schema. Field offsets are "
        "exact; C types are inferred from serialized sizes. Names are structural "
        "until semantics are proven.",
        "",
        "| Struct | Size | Fields | Serialized | Header |",
        "|---|---:|---:|---:|---|",
    ]
    for s in structs:
        nfields = sum(1 for f in s["fields"] if f["kind"] == "field")
        out.append(f"| `{s['class']}` | 0x{s['size']:x} | {nfields} | "
                   f"{s['serialized_count']} | `game_structs.h` |")

    out += ["", "## Field layouts", ""]
    for s in structs:
        nfields = sum(1 for f in s["fields"] if f["kind"] == "field")
        out += [f"### {s['class']}", "",
                f"- Size: `0x{s['size']:x}`",
                f"- Vtable: `{s['vtable']}`",
                f"- Fields: {nfields}",
                f"- Serialized fields: {s['serialized_count']}",
                ""]
        out += ["| Offset | Size | C declaration | Notes |",
                "|---:|---:|---|---|"]
        for f in s["fields"]:
            if f["kind"] == "padding":
                continue
            out.append(f"| `0x{f['offset']:x}` | {f['size']} | "
                       f"`{f['decl']}` | {f['comment']} |")
        out.append("")
    with open(os.path.join(BASE, "STRUCTS.md"), "w") as f:
        f.write("\n".join(out) + "\n")


if __name__ == "__main__":
    build()
