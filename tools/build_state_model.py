#!/usr/bin/env python3
"""Merge vtable/class field observations with the save-state schema.

Outputs:
  decompiled_fastfood2_named_v2/state_model.json
  decompiled_fastfood2_named_v2/STATE_MODEL.md
"""

import json
import os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BASE = os.path.join(ROOT, "decompiled_fastfood2_named_v2")

# Class -> save writer. These links are established by the loader path in
# Game_LoadSaveGame and by matching field order/size.
CLASS_WRITER = {
    "StatsPeriodReport": "StatsPeriodReport_Save",
    "Branch": "Branch_Save",
    "RecipeTopping": "RecipeTopping_Save",
    "MapObject": "MapObject_Save",
    "Car": "CarList_Save",
    "Character": "Character_Save",
    "City": "MapObjectList_Save",
    "GameClock": "GameCalendar_Save",
    "Company": "CompanyData_Save",
    "BuildingValue": "BuildingValue_Save",
    "ConstructionOrder": "ConstructionOrder_Save",
    "Game": "SaveGame_Serialize",
    "IsoMap": "IsoMap_Save",
    "PlayerMissionState": "Player_MissionState_Save",
    "Player_Event": "Player_Event_Save",
    "PlayerAIState": "Player_AIState_Save",
    "WorldObject": "PersonList_Save",
    "Player": "Player_Save",
    "UI_BriefingList": "UI_BriefingList_Save",
}

# Allocation sizes observed at the load site in Game_LoadSaveGame.
CLASS_SIZE = {
    "IsoMap": 0x10178,
    "Character": 0x828,
    "City": 0x1158,
    "WorldObject": 0x16C,
    "Car": 0x14,
    "Player": 0xB0,
    "Company": 0x1F0,
    "Game": 0x2F890,
}


def main():
    with open(os.path.join(BASE, "class_skeletons.json")) as f:
        classes = json.load(f)
    with open(os.path.join(BASE, "save_schema.json")) as f:
        schema = json.load(f)
    owners = {o["name"]: o for o in schema["owners"]}

    rows = []
    for cls in classes:
        name = cls["class"]
        writer = CLASS_WRITER.get(name)
        if not writer or writer not in owners:
            continue
        owner = owners[writer]
        observed = {int(k, 16): v for k, v in cls["fields"].items()}
        serialized = {f["offset"]: f for f in owner["fields"]}
        serialized_order = {f["offset"]: i for i, f in enumerate(owner["fields"])}
        both = sorted(set(observed) & set(serialized))
        union = sorted(set(observed) | set(serialized))
        rows.append({
            "class": name,
            "vtable": cls["vtable"],
            "writer": writer,
            "class_size": CLASS_SIZE.get(name),
            "observed_field_count": len(observed),
            "serialized_field_count": len(serialized),
            "persisted_and_observed": len(both),
            "observed_not_persisted": sorted(set(observed) - set(serialized)),
            "persisted_not_observed": sorted(set(serialized) - set(observed)),
            "coverage_of_observed": (
                round(100.0 * len(both) / len(observed), 1) if observed else None
            ),
            "coverage_of_union": (
                round(100.0 * len(both) / len(union), 1) if union else None
            ),
            "observed_fields": [
                {"offset": f"0x{o:x}", **observed[o]} for o in sorted(observed)
            ],
            "serialized_fields": [
                {"offset": f"0x{o:x}", "size": serialized[o]["size"],
                 "type_hint": serialized[o]["type_hint"],
                 "order": serialized_order[o]}
                for o in sorted(serialized, key=lambda x: serialized_order[x])
            ],
        })

    totals = {
        "classes_mapped": len(rows),
        "observed_fields": sum(r["observed_field_count"] for r in rows),
        "serialized_fields": sum(r["serialized_field_count"] for r in rows),
        "persisted_and_observed": sum(r["persisted_and_observed"] for r in rows),
        "serialized_global_blocks": len(schema["global_state"]),
    }

    model = {
        "target": schema["target"],
        "counts": totals,
        "classes": rows,
        "serialized_globals": schema["global_state"],
        "notes": [
            "Observed fields come from constructor/destructor/serializer/vtable "
            "method accesses; serialized fields come from writer order.",
            "A field can be observed but not serialized because it is derived, "
            "transient, or stored in a nested object/global block.",
            "City is serialized by MapObjectList_Save/MapObjectList_Load; the "
            "writer name is legacy.",
            "WorldObject is the base vtable used by Person records, serialized "
            "through PersonList_Save/PersonAction_LoadState.",
        ],
    }

    with open(os.path.join(BASE, "state_model.json"), "w") as f:
        json.dump(model, f, indent=1)

    write_markdown(model)
    print(f"classes={len(rows)} observed={totals['observed_fields']} "
          f"serialized={totals['serialized_fields']} "
          f"both={totals['persisted_and_observed']}")


def write_markdown(model):
    out = [
        "# Pizza Connection 2 state model",
        "",
        "Merged view of **vtable/class field observations** and the **save-state "
        "schema**. This separates persistent state from derived/transient fields, "
        "which is the core requirement for a modern engine or save editor.",
        "",
        f"- Classes mapped to save writers: **{model['counts']['classes_mapped']}**",
        f"- Observed field offsets: **{model['counts']['observed_fields']}**",
        f"- Serialized field offsets: **{model['counts']['serialized_fields']}**",
        f"- Fields both observed and serialized: **{model['counts']['persisted_and_observed']}**",
        f"- Serialized global blocks: **{model['counts']['serialized_global_blocks']}**",
        "",
        "## Coverage by class",
        "",
        "| Class | Size | Writer | Observed | Serialized | Both | Observed-only | Serialized-only |",
        "|---|---:|---|---:|---:|---:|---:|---:|",
    ]
    for r in sorted(model["classes"], key=lambda x: -x["observed_field_count"]):
        size = f"0x{r['class_size']:x}" if r["class_size"] else ""
        out.append(
            f"| `{r['class']}` | {size} | `{r['writer']}` | "
            f"{r['observed_field_count']} | {r['serialized_field_count']} | "
            f"{r['persisted_and_observed']} | "
            f"{len(r['observed_not_persisted'])} | "
            f"{len(r['persisted_not_observed'])} |"
        )

    out += [
        "",
        "## Serialized globals",
        "",
        "| Address | Size | Name | Writer |",
        "|---|---:|---|---|",
    ]
    for g in model["serialized_globals"]:
        out.append(f"| `{g['address']}` | {g['size']} | `{g['suggested_name']}` | "
                   f"{', '.join(g['writers'])} |")

    out += [
        "",
        "## Interpretation",
        "",
        "- Fields with `observed-only` are candidates for transient/derived state, "
        "runtime caches, or state stored in a nested object.",
        "- Fields with `serialized-only` are real persistent fields whose access "
        "was not seen by the constructor/field scanner; they are high-value for "
        "struct reconstruction.",
        "- `Game` has the largest observed model but only 22 direct serialized "
        "fields at the top level; the rest is in `g_GameGlobalState` (1,464 "
        "bytes) and nested subsystem serializers.",
        "- `Company` is the clearest example of serialized-only coverage: its "
        "`CompanyData_Save` block yields 27 persistent fields, many not seen by "
        "the generic field scanner.",
        "- `City` is serialized by the legacy-named `MapObjectList_Save`; its 30 "
        "observed fields and 31 writer fields overlap only partially, indicating "
        "either a level of indirection or a writer that also serializes a "
        "contained map-object list.",
        "",
        "## Field details",
        "",
    ]
    for r in sorted(model["classes"], key=lambda x: x["class"]):
        out += [f"### {r['class']}", "",
                f"- Vtable: `{r['vtable']}`",
                f"- Writer: `{r['writer']}`",
                f"- Size: " + (f"`0x{r['class_size']:x}`" if r["class_size"] else "unknown"),
                f"- Observed / serialized / both: {r['observed_field_count']} / "
                f"{r['serialized_field_count']} / {r['persisted_and_observed']}",
                ""]
        if r["persisted_not_observed"]:
            out.append("- Serialized-only offsets: " +
                       ", ".join(f"`0x{o:x}`" for o in r["persisted_not_observed"]))
            out.append("")
        if r["observed_not_persisted"]:
            out.append("- Observed-only offsets: " +
                       ", ".join(f"`0x{o:x}`" for o in r["observed_not_persisted"][:40]) +
                       (" ..." if len(r["observed_not_persisted"]) > 40 else ""))
            out.append("")

    with open(os.path.join(BASE, "STATE_MODEL.md"), "w") as f:
        f.write("\n".join(out) + "\n")


if __name__ == "__main__":
    main()
