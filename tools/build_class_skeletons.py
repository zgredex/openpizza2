#!/usr/bin/env python3
"""Recover vtables and class skeletons from the named Pizza Connection 2 export.

Inputs:
  game/fastfood2.exe
  decompiled_fastfood2_named_v2/full_game_verification/
  decompiled_fastfood2_named_v2/full_game_symbols.json

Outputs:
  decompiled_fastfood2_named_v2/vtables_full.csv
  decompiled_fastfood2_named_v2/class_skeletons.json
  decompiled_fastfood2_named_v2/vtable_annotations.json
  decompiled_fastfood2_named_v2/VTABLES_AND_CLASSES.md
  decompiled_fastfood2_named_v2/class_skeletons/<Class>.md
"""

import collections
import csv
import json
import os
import re
import struct

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EXE = os.path.join(ROOT, "game", "fastfood2.exe")
EXPORT = os.path.join(ROOT, "decompiled_fastfood2_named_v2", "full_game_verification")
SYMBOLS = os.path.join(ROOT, "decompiled_fastfood2_named_v2", "full_game_symbols.json")
OUT = os.path.join(ROOT, "decompiled_fastfood2_named_v2")

# PE layout for this executable.
TEXT_VA, TEXT_END, TEXT_OFF = 0x401000, 0x555ABC, 0x1000
RD_VA, RD_END, RD_OFF = 0x55C000, 0x562758, 0x15C000

CLASS_NAMES = {
    0x55C2E0: "StatsPeriodReport", 0x55C2E8: "NamedLockable", 0x55C2EC: "List",
    0x55C2F0: "ResourceManager", 0x55C2F4: "FileObject", 0x55C2F8: "UI_ListEntry",
    0x55C308: "TimerClass", 0x55C30C: "Branch", 0x55C44C: "GameWorld",
    0x55C4E8: "RecipeTopping", 0x55C4EC: "MapObject", 0x55C4F8: "Car",
    0x55C4FC: "Character", 0x55C500: "City", 0x55C564: "GameClock",
    0x55C568: "Company", 0x55C5A0: "FurnitureType", 0x55C5A4: "BuildingValue",
    0x55C5B8: "Ingredient", 0x55C5BC: "ConstructionOrder", 0x55C5D0: "Game",
    0x55C5D4: "IsoMap", 0x55C5E8: "PlayerMissionState", 0x55C618: "GameCompanyManager",
    0x55C660: "Player_Event", 0x55C664: "PlayerAIState", 0x55C668: "WorldObject",
    0x55C684: "Player", 0x55C688: "GamePlan", 0x55C698: "Recipe",
    0x55C700: "Storage", 0x55C704: "UI_ImageElement", 0x55C720: "UI_Child",
    0x55C73C: "UI_Viewport", 0x55C758: "UI_LabelElement", 0x55C774: "Array",
    0x55C778: "UI_Manager", 0x55C788: "UI_ContextMenu", 0x55C78C: "UI_Slider",
    0x55C7B0: "MovieWindow", 0x55C7CC: "UI_TextElement", 0x55C7E8: "UI_ButtonElement",
    0x55C804: "UI_Tooltip", 0x55C808: "Dialog", 0x55C80C: "SpriteFile",
    0x55C810: "Gfx_RectList", 0x55C814: "Window", 0x55C818: "Renderer",
    0x55C828: "SpriteBase", 0x55C82C: "Sprite", 0x55C830: "SoundDevice",
    0x55C840: "SoundBufferBase", 0x55C850: "SoundSample", 0x55C860: "DirectSoundBuffer",
    0x55C864: "SoundPakManagerBase", 0x55C874: "SoundBuffer",
    0x55C8B0: "SoundStreamBuffer", 0x55C8C8: "SoundStreamBuffer3D",
    0x55C8E0: "SoundVoice", 0x55C8F0: "SoundMixerThread",
    0x55C8F4: "ComInterface_55C8F4", 0x55C8F8: "ComIDirectSoundBuffer",
    0x55C9F4: "ComInterface_55C9F4", 0x55C9F8: "ComIDirectSound",
    0x55CA08: "ComIDirectSound3DListener", 0x55CB04: "ListContainer",
    0x55CB14: "SoundBufferAux", 0x55CB3C: "DebugConsole",
    0x55CB40: "UI_BriefingList", 0x55CB44: "EmployeeAvatar",
    0x55CC2C: "CRT_Ifstream", 0x55CC54: "CRT_Filebuf", 0x55CC84: "CRT_Ofstream",
    0x55CC94: "CRT_Istream", 0x55CCA4: "CRT_Ostream", 0x55CCC0: "CRT_Ios",
    0x55CCC8: "CRT_Streambuf",
}



# Vtable slots that point at real function entries Ghidra never promoted to
# procedures (indirect-only code). Names are structural unless the behavior is
# unambiguous. Verified against raw disassembly at each address.
SLOT_TARGET_NAMES = {
    0x504980: "WorldObject_Delete",
    0x51FA60: "UI_Child_ForwardToVFunc4",
    0x520FB0: "UI_Child_InvokeCallback",
    0x520FF0: "UI_Child_ReturnTrue",
    0x52AC40: "UI_Slider_ReturnTrue",
    0x521B00: "UI_Viewport_GetTypeId",
    0x52B9E0: "MovieWindow_IsPlaying",
    0x53EF60: "RefCount_AddRef",
    0x53EFE0: "SoundBufferBase_Delete",
    0x541750: "SoundStreamBuffer_vfunc4_ForwardQuery",
    0x544700: "COM_E_NOTIMPL_Ret4",
    0x544710: "COM_E_NOTIMPL_Ret12",
    0x544720: "COM_E_NOTIMPL_Ret8",
    0x544730: "ComIDirectSoundBuffer_vfunc58_GetError",
    0x546F90: "ComIDirectSound_AdjustorThunk0",
    0x546FA0: "ComIDirectSound_AdjustorThunk1",
    0x546FB0: "ComInterface_55C8F4_AdjustorThunk0",
    0x546FC0: "ComInterface_55C9F4_AdjustorThunk0",
    0x54CC6E: "CRT_Ifstream_ScalarDeletingDestructor",
    0x54CF92: "CRT_Filebuf_vfunc3",
    0x54D115: "CRT_Ofstream_ScalarDeletingDestructor",
    0x54D3E3: "CRT_Istream_ScalarDeletingDestructor",
    0x54D7BE: "CRT_Ostream_ScalarDeletingDestructor",
    0x54DB51: "CRT_Streambuf_SetBuffer",
    0x54DD04: "CRT_Streambuf_ReturnMinusOne",
    0x54DD0A: "CRT_Streambuf_ForwardToVFunc3",
    0x54FB1E: "_purecall",
}

# Allocation sizes observed at Game_LoadSaveGame load sites. Field offsets at
# or beyond these bounds are impossible and are discarded.
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

# Classes whose function prefix differs from the class name.
STEM_ALIASES = {
    "PlayerAIState": "Player_AIState",
    "PlayerMissionState": "Player_MissionState",
    "GameCompanyManager": "Game_CompanyManager",
}


def read_binary():
    with open(EXE, "rb") as f:
        data = f.read()
    return data


def load_export():
    with open(os.path.join(EXPORT, "decompile-index.json")) as f:
        index = json.load(f)["functions"]
    by_addr = {f["address"]: f for f in index}
    return index, by_addr


def read_function(by_addr, addr):
    f = by_addr.get(addr)
    if not f or f.get("status") != "written":
        return ""
    path = os.path.join(EXPORT, f["relative_path"])
    try:
        with open(path, errors="replace") as fh:
            return fh.read()
    except OSError:
        return ""


def subsystem(name):
    if name == "Company" or not name.startswith("Com"):
        if name.startswith("CRT_"):
            return "COM/CRT"
        if name.startswith("Sound") or name.startswith("DirectSound"):
            return "Sound"
        if name.startswith("UI_") or name in {
            "Dialog", "Window", "MovieWindow", "Tooltip", "Array", "Gfx_RectList",
            "Renderer", "Sprite", "SpriteBase", "SpriteFile", "ListContainer",
        }:
            return "UI/Rendering"
        return "Game"
    return "COM/CRT"


def type_size(type_text):
    t = "".join(type_text.split()).lower().replace("*", "")
    if t in {"undefined1", "byte", "char", "bool", "uchar"}:
        return 1
    if t in {"undefined2", "ushort", "short", "word", "wchar_t"}:
        return 2
    if t in {"undefined4", "uint", "int", "dword", "undefined*", "code*",
             "void*", "undefined**", "code**"}:
        return 4
    if t in {"double", "longlong", "undefined8", "ulonglong"}:
        return 8
    if t in {"undefined3", "undefined6"}:
        return int(t[-1])
    return 0


def extract_fields(by_addr, func_addrs):
    ptr_pat = re.compile(
        r"\*\(([^)]+)\)\s*\(\s*(?:\(int\)|\(uint\))?\s*(this|param_1)\s*\+\s*(0x[0-9a-f]+|\d+)"
    )
    io_pat = re.compile(
        r"CRT_(?:Istream_Read|Ostream_Write)\([^,]+,\s*\(int\)(this|param_1)\s*\+\s*"
        r"(0x[0-9a-f]+|\d+)\s*,\s*(0x[0-9a-f]+|\d+)\)"
    )
    idx_pat = re.compile(r"\b(this|param_1)\[((?:0x)?[0-9a-fA-F]+)\]")
    per = collections.defaultdict(
        lambda: collections.defaultdict(lambda: {"hits": set(), "samples": set()})
    )
    for addr in func_addrs:
        name = by_addr.get(addr, {}).get("name", addr)
        text = read_function(by_addr, addr)
        for line in text.splitlines():
            for m in ptr_pat.finditer(line):
                off = int(m.group(3), 0)
                if off:
                    size = type_size(m.group(1))
                    per[off][size]["hits"].add(addr)
                    per[off][size]["samples"].add(name)
            for m in io_pat.finditer(line):
                off = int(m.group(2), 0)
                raw = int(m.group(3), 0) if m.group(3) else 0
                size = raw if raw in (1, 2, 4, 8) else 0
                if off:
                    per[off][size]["hits"].add(addr)
                    per[off][size]["samples"].add(name)
            for m in idx_pat.finditer(line):
                try:
                    index = int(m.group(2), 0)
                except ValueError:
                    continue
                off = index * 4
                if off:
                    per[off][4]["hits"].add(addr)
                    per[off][4]["samples"].add(name)
    result = {}
    for off, sizes in sorted(per.items()):
        size = max(sizes, key=lambda s: (len(sizes[s]["hits"]), s))
        hit_addrs = {a for v in sizes.values() for a in v["hits"]}
        samples = sorted({s for v in sizes.values() for s in v["samples"]})
        result[f"0x{off:x}"] = {
            "size": size,
            "hits": len(hit_addrs),
            "functions": samples[:6],
        }
    return result


def build():
    data = read_binary()
    rd = data[RD_OFF:RD_OFF + (RD_END - RD_VA)]

    def u32(va):
        return struct.unpack_from("<I", rd, va - RD_VA)[0]

    def is_text(v):
        return TEXT_VA <= v < TEXT_END

    index, by_addr = load_export()
    with open(SYMBOLS) as f:
        symbols = json.load(f)

    refs = collections.defaultdict(set)
    ptrnames = collections.defaultdict(set)
    for f in index:
        if f.get("status") != "written":
            continue
        text = read_function(by_addr, f["address"])
        for m in re.finditer(r"&(PTR_[A-Za-z0-9_]+_(0055[0-9a-f]{4}))", text):
            vt = int(m.group(2), 16)
            refs[vt].add((f["address"], f["name"]))
            ptrnames[vt].add(m.group(1))

    # 0x55ccfc is the printf float-conversion function table, not a vtable.
    starts = sorted(v for v in refs if v != 0x55CCFC)
    rows = []

    for i, vt in enumerate(starts):
        next_vt = starts[i + 1] if i + 1 < len(starts) else None
        slots = []
        a = vt
        while is_text(u32(a)):
            slots.append(u32(a))
            a += 4
            if next_vt is not None and a >= next_vt:
                break
            if len(slots) > 200:
                break

        cls = CLASS_NAMES.get(vt, f"Class_{vt:x}")
        ctors = sorted(
            ((ad, n) for ad, n in refs[vt]
             if re.search(r"(Construct|StreamConstruct|_Load$|_Open$|_Create)", n)),
            key=lambda item: item[0],
        )

        base = ""
        for ad, name in ctors:
            text = read_function(by_addr, ad)
            for line in text.splitlines():
                m = re.search(r"\b([A-Za-z_][A-Za-z0-9_]*_Construct(?:Base)?)\s*\(", line)
                if not m:
                    continue
                cand = m.group(1)
                if cand.startswith(cls + "_") or cand == cls:
                    continue
                exact_this = (
                    re.search(r"_Construct(?:Base)?\s*\(\s*this\b", line)
                    or re.search(r"_Construct(?:Base)?\s*\(\s*\(int\)this\s*[,)]", line)
                )
                if exact_this:
                    base = cand[:-10] if cand.endswith("_Construct") else cand.replace("_ConstructBase", "")
                    break
            if base:
                break

        dtor_refs = sorted(
            ((ad, n) for ad, n in refs[vt]
             if re.search(r"(Destroy|Destruct|_Delete$|ScalarDeletingDestructor)", n)),
            key=lambda item: item[0],
        )
        field_addrs = {ad for ad, _ in ctors + dtor_refs}
        field_addrs |= {hex(v) for v in slots if v in by_addr}

        cls_norm = cls.replace("_", "").lower()
        # A function belongs to the longest class-name prefix that matches it.
        # This stops Player_AIState_* from contributing to Player, and
        # CompanyMenu_* from contributing to Company.
        class_norms = {c: c.replace("_", "").lower()
                       for c in CLASS_NAMES.values()}
        related = []
        for f in index:
            if f.get("status") != "written":
                continue
            n = f["name"]
            n_norm = n.replace("_", "").lower()
            stem = STEM_ALIASES.get(cls, cls)
            if not (n.startswith(stem + "_") or n.startswith(cls + "_")):
                continue
            owners = [(len(cn), c) for c, cn in class_norms.items()
                      if n_norm.startswith(cn)]
            owner = max(owners)[1] if owners else None
            if owner != cls:
                continue
            if not re.search(r"(_Load|_Save|_StreamConstruct|_Construct|_Destruct|_Init|_Reset)", n):
                continue
            if f["address"] in field_addrs:
                continue
            score = 0 if n.startswith(cls + "_") else 1
            related.append((score, f["address"]))
        related.sort()
        for _, ad in related[:24]:
            field_addrs.add(ad)

        fields = extract_fields(by_addr, sorted(field_addrs))
        if cls in CLASS_SIZES:
            fields = {k: v for k, v in fields.items()
                      if int(k, 16) < CLASS_SIZES[cls]}
        if cls.startswith(("ComInterface", "ComIDirectSound")):
            fields = {}
        slot_rows = []
        for j, v in enumerate(slots):
            raw = symbols.get(hex(v), f"sub_{v:x}")
            known = f"0x{v:x}" in by_addr
            if known:
                name, status = raw, "procedure"
            else:
                name = SLOT_TARGET_NAMES.get(v, f"{cls}_vfunc{j}")
                status = "undiscovered-function"
            slot_rows.append({
                "index": j,
                "address": hex(v),
                "name": name,
                "raw_name": raw,
                "target_status": status,
            })
        def pick_constructor():
            if not ctors or all(s["name"] == "_purecall" for s in slot_rows):
                return ""
            norm = cls.replace("_", "").lower()

            def score(item):
                name = item[1].replace("_", "").lower()
                if name.startswith(norm):
                    return 0
                if norm.startswith(name):
                    return 1
                if "Construct" in item[1]:
                    return 2
                return 3

            return sorted(ctors, key=lambda item: (score(item), item[0]))[0][1]

        def pick_destructor():
            names = [s["name"] for s in slot_rows]
            if not names:
                return ""
            if all(n == "_purecall" for n in names):
                return ""
            if re.search(r"(Delete|Destruct|Destroy|ScalarDeleting)", names[0]):
                return names[0]
            for n in names[1:]:
                if re.search(r"(Delete|Destruct|Destroy|ScalarDeleting)", n):
                    return n
            if cls.startswith("Com"):
                return ""
            return names[0]

        constructor = pick_constructor()
        destructor = pick_destructor()
        notes = []
        if not fields and cls == "SpriteBase":
            notes.append("vptr-only base class; no data members observed")
        if not fields and cls in {"CRT_Ifstream", "CRT_Ofstream", "CRT_Istream",
                                  "CRT_Ostream"}:
            notes.append("no own fields; stream state lives in the CRT_Ios/CRT_Streambuf base")
        if cls.startswith(("ComInterface", "ComIDirectSound")):
            notes.append("COM interface vtable; field offsets from the outer constructor suppressed")
        if vt == 0x55C44C:
            notes.append("renamed GameState -> GameWorld; slot0 and pointer symbol are GameWorld_Delete")
        if vt == 0x55C660:
            notes.append("Player_Event ctor/save/load; slot0 symbol retains legacy AwardNode_Delete name")
        if vt == 0x55C2EC:
            notes.append("slot0 symbol List_Node_Delete is a legacy name; List_Construct initializes this container vtable")
        if constructor and not constructor.replace("_", "").lower().startswith(cls.replace("_", "").lower()):
            notes.append(f"constructor symbol is {constructor} (base/sibling name)")
        if slot_rows and destructor and slot_rows[0]["name"] != destructor:
            notes.append(f"slot0 is {slot_rows[0]['name']}; destructor is slot "
                         f"{next(s['index'] for s in slot_rows if s['name'] == destructor)}")
        if all(s["name"] == "_purecall" for s in slot_rows):
            notes.append("abstract COM interface: all slots are pure-virtual stubs")

        rows.append({
            "vtable": hex(vt),
            "class": cls,
            "subsystem": subsystem(cls),
            "constructor": constructor,
            "constructors": [n for _, n in ctors],
            "destructor": destructor,
            "naming_notes": notes,
            "slot_count": len(slots),
            "base_guess": base,
            "base_basis": "constructor-call" if base else "",
            "slots": slot_rows,
            "fields": fields,
            "related_functions": [by_addr[a]["name"] for _, a in related[:24]],
            "references": sorted({n for _, n in refs[vt]}),
            "pointer_symbols": sorted(ptrnames[vt]),
        })

    inferred_bases = {
        "CRT_Filebuf": ("CRT_Streambuf",
                        "slots 4,5,6,9,10 identical; slots 7,8 overridden"),
        "SoundBuffer": ("SoundBufferBase",
                        "slots 0-2 identical; adds slots 4,5"),
        "SoundStreamBuffer3D": ("SoundStreamBuffer",
                                "slots 0-2,4,5 identical; only slot 3 differs"),
    }
    by_class = {r["class"]: r for r in rows}
    for child, (parent, why) in inferred_bases.items():
        row = by_class.get(child)
        if row and not row["base_guess"]:
            row["base_guess"] = parent
            row["base_basis"] = "shared-vtable-prefix"
            row["naming_notes"].append(f"base inferred: {parent} ({why})")
    for row in rows:
        names = [s["name"] for s in row["slots"][:3]]
        if names[:3] == ["RefCount_AddRef", "RefCount_Release", "COM_QueryInterfaceGuid"]:
            row["com_refcounted"] = True
            row["naming_notes"].append("slots 0-2 implement COM AddRef/Release/QueryInterface")
        else:
            row["com_refcounted"] = False

    rows.sort(key=lambda r: int(r["vtable"], 16))
    with open(os.path.join(OUT, "class_skeletons.json"), "w") as f:
        json.dump(rows, f, indent=1)
    with open(os.path.join(OUT, "vtable_annotations.json"), "w") as f:
        json.dump({r["vtable"]: "vtable_" + r["class"] for r in rows}, f, indent=1)

    with open(os.path.join(OUT, "vtables_full.csv"), "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["vtable", "class", "subsystem", "constructor", "destructor",
                    "slot_count", "base_guess", "base_basis", "naming_notes",
                    "slot_names", "references"])
        for r in rows:
            w.writerow([
                r["vtable"], r["class"], r["subsystem"], r["constructor"],
                r["destructor"], r["slot_count"], r["base_guess"],
                r.get("base_basis", ""), "; ".join(r.get("naming_notes", [])),
                "; ".join(s["name"] for s in r["slots"]),
                "; ".join(r["references"]),
            ])

    with open(os.path.join(OUT, "vtable_slot_targets.csv"), "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["vtable", "class", "slot", "target", "target_status",
                    "name", "raw_name"])
        for r in rows:
            for s in r["slots"]:
                w.writerow([r["vtable"], r["class"], s["index"], s["address"],
                            s["target_status"], s["name"], s["raw_name"]])

    functions = {}
    for r in rows:
        for s in r["slots"]:
            if s["target_status"] == "undiscovered-function":
                entry = functions.setdefault(
                    s["address"], {"name": s["name"], "used_by": []}
                )
                entry["used_by"].append({
                    "vtable": r["vtable"],
                    "class": r["class"],
                    "slot": s["index"],
                })
    with open(os.path.join(OUT, "vtable_slot_functions.json"), "w") as f:
        json.dump(functions, f, indent=1, sort_keys=True)

    combined = dict(symbols)
    for addr, info in functions.items():
        combined[addr] = info["name"]
    for r in rows:
        combined[r["vtable"]] = "vtable_" + r["class"]
    combined = dict(sorted(combined.items(), key=lambda kv: int(kv[0], 16)))
    with open(os.path.join(OUT, "all_symbols_with_vtables.json"), "w") as f:
        json.dump(combined, f, indent=1)

    write_markdown(rows)
    return rows


def write_markdown(rows):
    out = []
    counts = collections.Counter(r["subsystem"] for r in rows)
    total_slots = sum(r["slot_count"] for r in rows)
    procedures = sum(1 for r in rows for s in r["slots"]
                     if s["target_status"] == "procedure")
    undiscovered = total_slots - procedures
    out += [
        "# Vtables and class skeletons",
        "",
        "Recovered from `game/fastfood2.exe` using PE `.rdata` code-pointer runs, "
        "constructor vtable writes, named exports, and exact field-access extraction.",
        "",
        f"- **{len(rows)} vtables**",
        f"- **{total_slots} virtual slots**",
        f"- **{procedures} slots backed by analyzed procedures**",
        f"- **{undiscovered} slots backed by {len({s['address'] for r in rows for s in r['slots'] if s['target_status'] != 'procedure'})} indirect-only function entries**",
        f"- **{sum(len(r['fields']) for r in rows)} observed field offsets**",
        "",
        "Ghidra only promoted directly-called code to procedures. Vtable-only "
        "targets are real function entries but require raw-disassembly analysis; "
        "they are named structurally here and listed in `vtable_slot_targets.csv`.",
        "",
        "| Subsystem | Vtables |",
        "|---|---:|",
    ]
    for k in ("Game", "UI/Rendering", "Sound", "COM/CRT"):
        out.append(f"| {k} | {counts[k]} |")

    for subsystem_name in ("Game", "UI/Rendering", "Sound", "COM/CRT"):
        out += ["", f"## {subsystem_name} vtables", "",
                "| Vtable | Class | Ctor | Dtor | Slots | Base | Fields |",
                "|---|---|---|---|---:|---|---:|"]
        for r in rows:
            if r["subsystem"] != subsystem_name:
                continue
            out.append(
                f"| `{r['vtable']}` | `{r['class']}` | `{r['constructor']}` | "
                f"`{r['destructor']}` | {r['slot_count']} | "
                f"`{r['base_guess']}` | {len(r['fields'])} |"
            )

    out += ["", "`*` = indirect-only function entry not promoted by Ghidra.", ""]
    out += ["", "## Undiscovered vtable targets", "",
            "These addresses are valid function entries reachable only through "
            "vtables, so they are absent from the procedure inventory. They were "
            "verified by raw disassembly (`ret`/padding boundaries) and named by "
            "observed behavior or structural slot role.", "",
            "| Address | Name | Used by |", "|---|---|---|"]
    used = collections.defaultdict(list)
    for r in rows:
        for s in r["slots"]:
            if s["target_status"] != "procedure":
                used[s["address"]].append(f"{r['class']}[{s['index']}]")
    for addr in sorted(used, key=lambda a: int(a, 16)):
        name = next(s["name"] for r in rows for s in r["slots"]
                    if s["address"] == addr and s["target_status"] != "procedure")
        refs = ", ".join(used[addr][:6]) + (" ..." if len(used[addr]) > 6 else "")
        out.append(f"| `{addr}` | `{name}` | {refs} |")
    out += [
        "", "## Excluded code-pointer tables", "",
        "A raw scan found 57 maximal code-pointer runs in `.rdata`. Every run is "
        "either covered by one of the 77 class vtables above or is one of the "
        "following non-class tables:", "",
        "| Address | Kind | Reason for exclusion |",
        "|---|---|---|",
        "| `0x55ccfc` | CRT float/printf dispatch table | two conversion routines, not a C++ vtable |",
        "| `0x55cd0c`, `0x55cd10` | CRT helper pointer tables | isolated CRT function pointers with adjacent non-code data |",
        "| `0x55cd18` | CRT `type_info` RTTI vtable | one destructor slot; referenced only by 8 `.data` type descriptors, never by a constructor |",
        "| `0x55ce1c`-`0x55ceb0` | CRT dispatch tables | scanf/printf/validation routine pairs, not object vtables |",
        "| 15 isolated pointers (`0x55d1d8`, `0x561ba4`, `0x561c18`, `0x561df0`, "
        "`0x561e84`, `0x561f24`, `0x561f58`, `0x562084`, `0x56208c`, `0x5620f4`, "
        "`0x562100`, `0x562394`, `0x562434`, `0x5625a4`, `0x562710`) | embedded "
        "function pointers | no code xref and no vtable-shaped run; data fields, not class vtables |",
        "",
    ]
    out += ["", "## Class skeletons", ""]
    for r in rows:
        if r["subsystem"] == "COM/CRT":
            continue
        out += [
            f"### {r['class']}",
            "",
            f"- Vtable: `{r['vtable']}`",
            f"- Constructor: `{r['constructor']}`",
            f"- Destructor: `{r['destructor']}`",
            f"- Base guess: `{r['base_guess']}`",
            f"- Slots: {r['slot_count']}",
            f"- Naming notes: {'; '.join(r.get('naming_notes', [])) or '-'}",
            "",
            "| # | Method |",
            "|---:|---|",
        ]
        for s in r["slots"]:
            mark = "" if s["target_status"] == "procedure" else " *"
            out.append(f"| {s['index']} | `{s['name']}`{mark} |")
        out += ["", "| Offset | Size | Hits | Observed in |", "|---|---:|---:|---|"]
        for off, f in r["fields"].items():
            funcs = ", ".join(f["functions"])
            out.append(f"| `{off}` | {f['size']} | {f['hits']} | {funcs} |")
        out.append("")

    out += [
        "", "## Deliverables", "",
        "- `vtables_full.csv` - one row per vtable with class, ctor/dtor, base, slots and notes",
        "- `vtable_slot_targets.csv` - one row per virtual slot with target status and inferred name",
        "- `class_skeletons.json` - full machine-readable skeletons, slots and observed field offsets",
        "- `class_skeletons/<Class>.md` - 65 per-class skeleton files (game, UI, sound, rendering)",
        "- `vtable_annotations.json` - 77 vtable data labels applied in REA",
        "- `vtable_slot_functions.json` - 75 indirect-only function entries with all slot uses",
        "- `all_symbols_with_vtables.json` - 3,029 procedures + 75 slot functions + 77 vtable labels",
        "- `VTABLE_CLASS_VERIFICATION.json` - counts, readback results, hashes and limitations",
        "- `vtables_classes_rea-evidence.json` - importable REA Evidence bundle",
        "- `tools/build_class_skeletons.py` - reproducible generator",
        "",
    ]
    with open(os.path.join(OUT, "VTABLES_AND_CLASSES.md"), "w") as f:
        f.write("\n".join(out) + "\n")

    class_dir = os.path.join(OUT, "class_skeletons")
    os.makedirs(class_dir, exist_ok=True)
    for r in rows:
        if r["subsystem"] == "COM/CRT":
            continue
        lines = [
            f"# {r['class']}",
            "",
            f"- Vtable: `{r['vtable']}`",
            f"- Constructor: `{r['constructor']}`",
            f"- Destructor: `{r['destructor']}`",
            f"- Base guess: `{r['base_guess']}`",
            f"- Slots: {r['slot_count']}",
            f"- Naming notes: {'; '.join(r.get('naming_notes', [])) or '-'}",
            "",
            "## Virtual methods",
            "",
            "| # | Method |",
            "|---:|---|",
        ]
        lines += [f"| {s['index']} | `{s['name']}`" +
                  ("" if s["target_status"] == "procedure" else " *") + " |"
                  for s in r["slots"]]
        lines += ["", "`*` = indirect-only function entry not promoted by Ghidra.", ""]
        lines += ["", "## Observed fields", "",
                  "| Offset | Size | Hits | Observed in |", "|---|---:|---:|---|"]
        for off, f in r["fields"].items():
            lines.append(f"| `{off}` | {f['size']} | {f['hits']} | " +
                         ", ".join(f["functions"]) + " |")
        lines += ["", "## Vtable references", ""]
        lines += [f"- `{n}`" for n in r["references"]]
        with open(os.path.join(class_dir, r["class"] + ".md"), "w") as f:
            f.write("\n".join(lines) + "\n")
    expected = {r["class"] + ".md" for r in rows if r["subsystem"] != "COM/CRT"}
    for name in os.listdir(class_dir):
        if name.endswith(".md") and name not in expected:
            os.remove(os.path.join(class_dir, name))


if __name__ == "__main__":
    recovered = build()
    print(f"vtables={len(recovered)} slots={sum(r['slot_count'] for r in recovered)} "
          f"fields={sum(len(r['fields']) for r in recovered)}")
