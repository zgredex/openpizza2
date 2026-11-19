#!/usr/bin/env python3
"""Generate the exact Screen_BuildingProject (0x42DDF0) control table."""

from __future__ import annotations

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
from ldf_tool import read_ldf  # noqa: E402

SOURCE = ROOT / "decompiled_fastfood2_named_v2/functions_readable/0x42ddf0.c"
EXE = ROOT / "game/fastfood2.exe"
LDF = ROOT / "game/language.ldf"
OUT_C = ROOT / "reconstructed/screen/building_project_layout.c"
OUT_H = ROOT / "reconstructed/screen/building_project_layout.h"

ASSET_NAMES = [
    "bewertung__00.spr", "bewertung__01.spr", "bewertung__02.spr",
    "bewertung__03.spr", "bewertung__04.spr", "bewertung__05.spr",
    "bewertung__06.spr", "bewertung__07.spr", "bewertung__08.spr",
    "bewertung__09.spr", "bewertung__10.spr", "bewertung__11.spr",
    "bewertung__12.spr", "bewertung__13.spr", "bewertung__14.spr",
    "bewertung__15.spr", "bewertung__16.spr", "hilfebuttonsnip_00.spr",
    "pb22_00.spr", "pb24_00.spr", "pb25_00.spr", "pb28_00.spr",
    "pb30_00.spr", "pb32_00.spr", "slhor01_00.spr", "textpb01__00.spr",
    "textpb05__00.spr", "trennzeile.spr",
]
ASSETS = {name: index for index, name in enumerate(ASSET_NAMES)}
FONTS = {
    "timesfont.fnt": 0,
    "verdana7.fnt": 1,
    "verdana8.fnt": 2,
    "verdana10.fnt": 3,
}

TEXT = 0
SPRITE = 1
SLIDER = 2
BUTTON = 3


def read_cstr(va: int) -> str:
    raw = EXE.read_bytes()[va - 0x400000 : va - 0x400000 + 256].split(b"\0", 1)[0]
    return raw.decode("cp1252")


def token_string(token: str, ldf: list[str]) -> str:
    match = re.match(r"g_Text_(\d+)_", token)
    if match:
        return ldf[int(match.group(1))]
    match = re.search(r"_([0-9a-fA-F]{8})$", token)
    if match:
        return read_cstr(int(match.group(1), 16))
    raise SystemExit(f"cannot resolve text token {token}")


def token_asset(token: str) -> str:
    match = re.search(r"_([0-9a-fA-F]{8})$", token)
    if not match:
        raise SystemExit(f"cannot resolve asset token {token}")
    return read_cstr(int(match.group(1), 16)).lower()


def c_string(text: str) -> str:
    out = []
    for ch in text:
        code = ord(ch)
        if ch == "\\":
            out.append("\\\\")
        elif ch == '"':
            out.append('\\"')
        elif ch == "\n":
            out.append("\\n")
        elif ch == "\t":
            out.append("\\t")
        elif 0x20 <= code < 0x7F:
            out.append(ch)
        else:
            out.append(f"\\u{code:04x}")
    return '"' + "".join(out) + '"'


def main() -> None:
    source = SOURCE.read_text()
    ldf = read_ldf(str(LDF))
    layouts: dict[int, tuple[int, int]] = {}
    for match in re.finditer(
        r"Window_GadgetNotify_Text_SetLayout\(this,([^,]+),(\d+),([^,]+),([^,]+),([^)]+)\);",
        source,
    ):
        layouts[int(match.group(1), 0)] = (int(match.group(2)),
                                           int(match.group(3), 0))
    button_widths: dict[int, int] = {}
    for match in re.finditer(
        r"Gadget_SetButtonTextLayout\(this,([^,]+),(\d+),([^,]+),", source
    ):
        button_widths[int(match.group(1), 0)] = int(match.group(3), 0)

    controls: list[dict] = []
    call_re = re.compile(
        r"(UI_AddText|UI_AddImage|UI_AddSprite|UI_CreateSlider|UI_AddTextButton)\(this,([^;]+)\);"
    )
    for match in call_re.finditer(source):
        kind_name = match.group(1)
        args = [part.strip() for part in match.group(2).split(",")]
        control_id = int(args[0], 0)
        x = int(args[1], 0)
        y = int(args[2], 0)
        base = {
            "id": control_id, "x": x, "y": y, "kind": TEXT, "asset": 0,
            "font": 0, "align": 0, "width": 0, "text": "",
        }
        if kind_name == "UI_AddText":
            align, width = layouts.get(control_id, (0, 0))
            base.update(font=FONTS[token_asset(args[3])], align=align,
                        width=width, text=token_string(args[4], ldf))
        elif kind_name in ("UI_AddImage", "UI_AddSprite"):
            base.update(kind=SPRITE, asset=ASSETS[token_asset(args[3])])
        elif kind_name == "UI_CreateSlider":
            base.update(kind=SLIDER, asset=ASSETS[token_asset(args[4])],
                        width=int(args[3], 0))
        elif kind_name == "UI_AddTextButton":
            base.update(kind=BUTTON, font=FONTS[token_asset(args[3])], align=2,
                        width=button_widths.get(control_id, 0),
                        text=token_string(args[4], ldf),
                        asset=ASSETS[token_asset(args[6])])
        controls.append(base)

    if len(controls) != 172:
        raise SystemExit(f"expected 172 controls, got {len(controls)}")

    OUT_H.write_text(
        """#ifndef PC2_RECONSTRUCTED_BUILDING_PROJECT_LAYOUT_H
#define PC2_RECONSTRUCTED_BUILDING_PROJECT_LAYOUT_H

#include <stddef.h>
#include <stdint.h>

#define BUILDING_PROJECT_ASSET_COUNT 28
#define BUILDING_PROJECT_FONT_TIMES 0
#define BUILDING_PROJECT_FONT_VERDANA7 1
#define BUILDING_PROJECT_FONT_VERDANA8 2
#define BUILDING_PROJECT_FONT_VERDANA10 3
#define BUILDING_PROJECT_FONT_COUNT 4
#define BUILDING_PROJECT_KIND_TEXT 0
#define BUILDING_PROJECT_KIND_SPRITE 1
#define BUILDING_PROJECT_KIND_SLIDER 2
#define BUILDING_PROJECT_KIND_BUTTON 3
#define BUILDING_PROJECT_WINDOW_X 561
#define BUILDING_PROJECT_WINDOW_Y 218

typedef struct BuildingProjectControl {
    int32_t id;
    int16_t x;
    int16_t y;
    uint8_t kind;
    uint8_t asset;
    uint8_t font;
    uint8_t align;
    uint16_t width;
    const char *text;
} BuildingProjectControl;

extern const BuildingProjectControl kBuildingProjectControls[];
extern const size_t kBuildingProjectControlCount;
extern const char *const kBuildingProjectAssetNames[BUILDING_PROJECT_ASSET_COUNT];

#endif
"""
    )
    lines = ['#include "building_project_layout.h"', "",
             "const BuildingProjectControl kBuildingProjectControls[] = {"]
    for control in controls:
        lines.append(
            "    {%d, %d, %d, %d, %d, %d, %d, %d, %s},"
            % (control["id"], control["x"], control["y"], control["kind"],
               control["asset"], control["font"], control["align"],
               control["width"], c_string(control["text"]))
        )
    lines += ["};", "",
              "const size_t kBuildingProjectControlCount = "
              "sizeof(kBuildingProjectControls) / sizeof(kBuildingProjectControls[0]);",
              "", "const char *const kBuildingProjectAssetNames[BUILDING_PROJECT_ASSET_COUNT] = {"]
    for name in ASSET_NAMES:
        lines.append(f'    "{name}",')
    lines += ["};", ""]
    OUT_C.write_text("\n".join(lines))
    print(f"generated {len(controls)} controls")


if __name__ == "__main__":
    main()
