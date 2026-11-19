#!/usr/bin/env python3
"""Generate the exact Screen_CharacterSelect (0x46DBD0) control table."""

from __future__ import annotations

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
from ldf_tool import read_ldf  # noqa: E402

SOURCE = ROOT / "decompiled_fastfood2_named_v2/functions_readable/0x46dbd0.c"
EXE = ROOT / "game/fastfood2.exe"
LDF = ROOT / "game/language.ldf"
OUT_C = ROOT / "reconstructed/screen/character_select_layout.c"
OUT_H = ROOT / "reconstructed/screen/character_select_layout.h"

ASSETS = {
    "pb22_00.spr": 0,
    "pb24_00.spr": 1,
    "pb26_00.spr": 2,
    "pb27_00.spr": 3,
    "sl02_00.spr": 4,
    "fotorahmen00.spr": 5,
    "fotodummy00.spr": 6,
    "textpbtranspgelb_00.spr": 7,
    "textpbtranspgruen_00.spr": 8,
    "geschlecht_m_00.spr": 9,
    "geschlecht_w_00.spr": 10,
    "playlog_2_01_00.spr": 11,
    "logofenster.spr": 12,
    "leuchtfeld_00_00.spr": 13,
}
FONTS = {
    "timesfont.fnt": 0,
    "verdana10.fnt": 1,
    "verdana8.fnt": 2,
    "times14.fnt": 3,
}

TEXT = 0
SPRITE = 1
SLIDER = 2
BITMAP = 3
INPUT = 4
BUTTON = 5


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
        layouts[int(match.group(1), 0)] = (
            int(match.group(2)),
            int(match.group(3), 0),
        )
    button_widths: dict[int, int] = {}
    for match in re.finditer(
        r"Gadget_SetButtonTextLayout\(this,([^,]+),(\d+),([^,]+),", source
    ):
        button_widths[int(match.group(1), 0)] = int(match.group(3), 0)

    controls: list[dict] = []
    call_re = re.compile(
        r"(UI_AddText|UI_AddImage|UI_AddSprite|UI_CreateSlider|UI_CreateBitmapGadget|UI_AddInputField|UI_AddTextButton)\(this,([^;]+)\);"
    )
    for match in call_re.finditer(source):
        kind_name = match.group(1)
        args = [part.strip() for part in match.group(2).split(",")]
        control_id = int(args[0], 0)
        x = int(args[1], 0)
        y = int(args[2], 0)
        base = {
            "id": control_id,
            "x": x,
            "y": y,
            "kind": TEXT,
            "asset": 0,
            "font": 0,
            "align": 0,
            "width": 0,
            "height": 0,
            "text": "",
        }
        if kind_name == "UI_AddText":
            align, width = layouts.get(control_id, (0, 0))
            base.update(
                kind=TEXT,
                font=FONTS[token_asset(args[3])],
                align=align,
                width=width,
                text=token_string(args[4], ldf),
            )
        elif kind_name in ("UI_AddImage", "UI_AddSprite"):
            base.update(kind=SPRITE, asset=ASSETS[token_asset(args[3])])
        elif kind_name == "UI_CreateSlider":
            base.update(
                kind=SLIDER,
                asset=ASSETS[token_asset(args[4])],
                width=int(args[3], 0),
            )
        elif kind_name == "UI_CreateBitmapGadget":
            base.update(
                kind=BITMAP,
                width=int(args[3], 0),
                height=int(args[4], 0),
            )
        elif kind_name == "UI_AddInputField":
            base.update(
                kind=INPUT,
                font=FONTS[token_asset(args[3])],
                width=int(args[5], 0),
                text=token_string(args[4], ldf),
            )
        elif kind_name == "UI_AddTextButton":
            base.update(
                kind=BUTTON,
                font=FONTS[token_asset(args[3])],
                align=2,
                width=button_widths.get(control_id, 0),
                text=token_string(args[4], ldf),
                asset=ASSETS[token_asset(args[6])],
            )
        controls.append(base)

    if len(controls) != 66:
        raise SystemExit(f"expected 66 controls, got {len(controls)}")

    OUT_H.write_text(
        """#ifndef PC2_RECONSTRUCTED_CHARACTER_SELECT_LAYOUT_H
#define PC2_RECONSTRUCTED_CHARACTER_SELECT_LAYOUT_H

#include <stddef.h>
#include <stdint.h>

#define CHARACTER_SELECT_ASSET_PB22 0
#define CHARACTER_SELECT_ASSET_PB24 1
#define CHARACTER_SELECT_ASSET_PB26 2
#define CHARACTER_SELECT_ASSET_PB27 3
#define CHARACTER_SELECT_ASSET_SLIDER 4
#define CHARACTER_SELECT_ASSET_PHOTO_FRAME 5
#define CHARACTER_SELECT_ASSET_PHOTO_DUMMY 6
#define CHARACTER_SELECT_ASSET_BUTTON_YELLOW 7
#define CHARACTER_SELECT_ASSET_BUTTON_GREEN 8
#define CHARACTER_SELECT_ASSET_GENDER_M 9
#define CHARACTER_SELECT_ASSET_GENDER_W 10
#define CHARACTER_SELECT_ASSET_PLAYLOG 11
#define CHARACTER_SELECT_ASSET_LOGO 12
#define CHARACTER_SELECT_ASSET_LIGHT 13
#define CHARACTER_SELECT_ASSET_COUNT 14

#define CHARACTER_SELECT_FONT_TIMES 0
#define CHARACTER_SELECT_FONT_VERDANA10 1
#define CHARACTER_SELECT_FONT_VERDANA8 2
#define CHARACTER_SELECT_FONT_TIMES14 3
#define CHARACTER_SELECT_FONT_COUNT 4

#define CHARACTER_SELECT_KIND_TEXT 0
#define CHARACTER_SELECT_KIND_SPRITE 1
#define CHARACTER_SELECT_KIND_SLIDER 2
#define CHARACTER_SELECT_KIND_BITMAP 3
#define CHARACTER_SELECT_KIND_INPUT 4
#define CHARACTER_SELECT_KIND_BUTTON 5

typedef struct CharacterSelectControl {
    int32_t id;
    int16_t x;
    int16_t y;
    uint8_t kind;
    uint8_t asset;
    uint8_t font;
    uint8_t align;
    uint16_t width;
    uint16_t height;
    const char *text;
} CharacterSelectControl;

extern const CharacterSelectControl kCharacterSelectControls[];
extern const size_t kCharacterSelectControlCount;

#endif
"""
    )

    lines = [
        '#include "character_select_layout.h"',
        "",
        "const CharacterSelectControl kCharacterSelectControls[] = {",
    ]
    for control in controls:
        lines.append(
            "    {%d, %d, %d, %d, %d, %d, %d, %d, %d, %s},"
            % (
                control["id"],
                control["x"],
                control["y"],
                control["kind"],
                control["asset"],
                control["font"],
                control["align"],
                control["width"],
                control["height"],
                c_string(control["text"]),
            )
        )
    lines.append("};")
    lines.append("")
    lines.append(
        "const size_t kCharacterSelectControlCount = "
        "sizeof(kCharacterSelectControls) / sizeof(kCharacterSelectControls[0]);"
    )
    lines.append("")
    OUT_C.write_text("\n".join(lines))
    print(f"generated {len(controls)} controls")


if __name__ == "__main__":
    main()
