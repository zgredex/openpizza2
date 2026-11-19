#!/usr/bin/env python3
"""Generate the exact Screen_FreePlaySetup (0x472DA0) control table."""

from __future__ import annotations

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
from ldf_tool import read_ldf  # noqa: E402

SOURCE = ROOT / "decompiled_fastfood2_named_v2/functions_readable/0x472da0.c"
EXE = ROOT / "game/fastfood2.exe"
LDF = ROOT / "game/language.ldf"
OUT_C = ROOT / "reconstructed/screen/free_play_layout.c"
OUT_H = ROOT / "reconstructed/screen/free_play_layout.h"

ASSETS = {
    "pb22_00.spr": 0,
    "pb24_00.spr": 1,
    "pb26_00.spr": 2,
    "pb27_00.spr": 3,
    "pb14_00.spr": 4,
    "sl02_00.spr": 5,
    "fotorahmen00.spr": 6,
    "fotodummy00.spr": 7,
    "logofenster.spr": 8,
    "playlog_2_01_00.spr": 9,
    "playlog_3_02_01.spr": 10,
    "playlog_3_03_01.spr": 11,
    "textpb05__00.spr": 12,
    "textpbtranspgelb_00.spr": 13,
    "textpbtranspgruen_00.spr": 14,
}
FONTS = {
    "timesfont.fnt": 0,
    "times14.fnt": 1,
    "verdana10.fnt": 2,
    "verdana7.fnt": 3,
    "verdana8.fnt": 4,
}

TEXT = 0
SPRITE = 1
SLIDER = 2
BITMAP = 3
BUTTON = 4


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
        r"(UI_AddText|UI_AddImage|UI_AddSprite|UI_CreateSlider|UI_CreateBitmapGadget|UI_AddTextButton)\(this,([^;]+)\);"
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

    if len(controls) != 157:
        raise SystemExit(f"expected 157 controls, got {len(controls)}")

    OUT_H.write_text(
        """#ifndef PC2_RECONSTRUCTED_FREE_PLAY_LAYOUT_H
#define PC2_RECONSTRUCTED_FREE_PLAY_LAYOUT_H

#include <stddef.h>
#include <stdint.h>

#define FREE_PLAY_ASSET_PB22 0
#define FREE_PLAY_ASSET_PB24 1
#define FREE_PLAY_ASSET_PB26 2
#define FREE_PLAY_ASSET_PB27 3
#define FREE_PLAY_ASSET_PB14 4
#define FREE_PLAY_ASSET_SLIDER 5
#define FREE_PLAY_ASSET_PHOTO_FRAME 6
#define FREE_PLAY_ASSET_PHOTO_DUMMY 7
#define FREE_PLAY_ASSET_LOGO 8
#define FREE_PLAY_ASSET_PLAYLOG 9
#define FREE_PLAY_ASSET_PLAYLOG2 10
#define FREE_PLAY_ASSET_PLAYLOG3 11
#define FREE_PLAY_ASSET_BUTTON 12
#define FREE_PLAY_ASSET_BUTTON_YELLOW 13
#define FREE_PLAY_ASSET_BUTTON_GREEN 14
#define FREE_PLAY_ASSET_COUNT 15

#define FREE_PLAY_FONT_TIMES 0
#define FREE_PLAY_FONT_TIMES14 1
#define FREE_PLAY_FONT_VERDANA10 2
#define FREE_PLAY_FONT_VERDANA7 3
#define FREE_PLAY_FONT_VERDANA8 4
#define FREE_PLAY_FONT_COUNT 5

#define FREE_PLAY_KIND_TEXT 0
#define FREE_PLAY_KIND_SPRITE 1
#define FREE_PLAY_KIND_SLIDER 2
#define FREE_PLAY_KIND_BITMAP 3
#define FREE_PLAY_KIND_BUTTON 4

typedef struct FreePlayControl {
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
} FreePlayControl;

extern const FreePlayControl kFreePlayControls[];
extern const size_t kFreePlayControlCount;

#endif
"""
    )

    lines = [
        '#include "free_play_layout.h"',
        "",
        "const FreePlayControl kFreePlayControls[] = {",
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
        "const size_t kFreePlayControlCount = "
        "sizeof(kFreePlayControls) / sizeof(kFreePlayControls[0]);"
    )
    lines.append("")
    OUT_C.write_text("\n".join(lines))
    print(f"generated {len(controls)} controls")


if __name__ == "__main__":
    main()
