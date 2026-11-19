#!/usr/bin/env python3
"""Generate the exact Screen_BuildOfficeDesk (0x4258C0) control table."""

from __future__ import annotations

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
from ldf_tool import read_ldf  # noqa: E402

SOURCE = ROOT / "decompiled_fastfood2_named_v2/functions_readable/0x4258c0.c"
EXE = ROOT / "game/fastfood2.exe"
LDF = ROOT / "game/language.ldf"
OUT_C = ROOT / "reconstructed/screen/office_desk_layout.c"
OUT_H = ROOT / "reconstructed/screen/office_desk_layout.h"

ASSETS = {
    "mauerbogen.spr": 0,
    "pb22_00.spr": 1,
    "pb24_00.spr": 2,
    "hpb__00.spr": 3,
    "hpb__01.spr": 4,
    "hpb__02.spr": 5,
    "hpb__03.spr": 6,
    "hpb__04.spr": 7,
    "rb01_00.spr": 8,
    "rb02_00.spr": 9,
    "rb03_00.spr": 10,
    "rb04_00.spr": 11,
    "rb05_00.spr": 12,
    "citybut01_00.spr": 13,
    "piloesch01_00.spr": 14,
    "redo01_00.spr": 15,
    "undo01_00.spr": 16,
    "ring.spr": 17,
    "uhr.spr": 18,
    "loch_00.spr": 19,
    "hilfebuttonsnip_00.spr": 20,
    "playlog_8_01_02.spr": 21,
    "star_01.spr": 22,
}
FONTS = {
    "timesfont.fnt": 0,
    "times14.fnt": 1,
    "verdana7.fnt": 2,
    "verdana8.fnt": 3,
    "verdana10.fnt": 4,
}

TEXT = 0
SPRITE = 1
ANIMATION = 2
BITMAP = 3


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

    controls: list[dict] = []
    call_re = re.compile(
        r"(UI_AddText|UI_AddImage|UI_AddSprite|UI_CreateAnimationWindow|UI_CreateBitmapGadget)\(this,([^;]+)\);"
    )
    for match in call_re.finditer(source):
        kind_name = match.group(1)
        args = [part.strip() for part in match.group(2).split(",")]
        control_id = int(args[0], 0)
        x = int(args[1], 0)
        y = int(args[2], 0)
        if kind_name == "UI_AddText":
            font = token_asset(args[3])
            text = token_string(args[4], ldf)
            align, width = layouts.get(control_id, (0, 0))
            controls.append(
                {
                    "id": control_id,
                    "x": x,
                    "y": y,
                    "kind": TEXT,
                    "asset": 0,
                    "font": FONTS[font],
                    "align": align,
                    "width": width,
                    "height": 0,
                    "text": text,
                }
            )
        elif kind_name in ("UI_AddSprite", "UI_AddImage"):
            asset = token_asset(args[3])
            controls.append(
                {
                    "id": control_id,
                    "x": x,
                    "y": y,
                    "kind": SPRITE,
                    "asset": ASSETS[asset],
                    "font": 0,
                    "align": 0,
                    "width": 0,
                    "height": 0,
                    "text": "",
                }
            )
        elif kind_name == "UI_CreateAnimationWindow":
            asset = token_asset(args[3])
            controls.append(
                {
                    "id": control_id,
                    "x": x,
                    "y": y,
                    "kind": ANIMATION,
                    "asset": 0,
                    "font": 0,
                    "align": 0,
                    "width": 0,
                    "height": 0,
                    "text": asset,
                }
            )
        elif kind_name == "UI_CreateBitmapGadget":
            controls.append(
                {
                    "id": control_id,
                    "x": x,
                    "y": y,
                    "kind": BITMAP,
                    "asset": 0,
                    "font": 0,
                    "align": 0,
                    "width": int(args[3], 0),
                    "height": int(args[4], 0),
                    "text": "",
                }
            )

    if len(controls) != 42:
        raise SystemExit(f"expected 42 controls, got {len(controls)}")

    OUT_H.write_text(
        """#ifndef PC2_RECONSTRUCTED_OFFICE_DESK_LAYOUT_H
#define PC2_RECONSTRUCTED_OFFICE_DESK_LAYOUT_H

#include <stddef.h>
#include <stdint.h>

#define OFFICE_ASSET_MAUERBOGEN 0
#define OFFICE_ASSET_PB22 1
#define OFFICE_ASSET_PB24 2
#define OFFICE_ASSET_HPB00 3
#define OFFICE_ASSET_HPB01 4
#define OFFICE_ASSET_HPB02 5
#define OFFICE_ASSET_HPB03 6
#define OFFICE_ASSET_HPB04 7
#define OFFICE_ASSET_RB01 8
#define OFFICE_ASSET_RB02 9
#define OFFICE_ASSET_RB03 10
#define OFFICE_ASSET_RB04 11
#define OFFICE_ASSET_RB05 12
#define OFFICE_ASSET_CITYBUT 13
#define OFFICE_ASSET_PILOESCH 14
#define OFFICE_ASSET_REDO 15
#define OFFICE_ASSET_UNDO 16
#define OFFICE_ASSET_RING 17
#define OFFICE_ASSET_UHR 18
#define OFFICE_ASSET_LOCH 19
#define OFFICE_ASSET_HELP 20
#define OFFICE_ASSET_PLAYLOG 21
#define OFFICE_ASSET_STAR 22
#define OFFICE_ASSET_COUNT 23

#define OFFICE_FONT_TIMES 0
#define OFFICE_FONT_TIMES14 1
#define OFFICE_FONT_VERDANA7 2
#define OFFICE_FONT_VERDANA8 3
#define OFFICE_FONT_VERDANA10 4
#define OFFICE_FONT_COUNT 5

#define OFFICE_KIND_TEXT 0
#define OFFICE_KIND_SPRITE 1
#define OFFICE_KIND_ANIMATION 2
#define OFFICE_KIND_BITMAP 3

typedef struct OfficeDeskControl {
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
} OfficeDeskControl;

extern const OfficeDeskControl kOfficeDeskControls[];
extern const size_t kOfficeDeskControlCount;

#endif
"""
    )

    lines = [
        '#include "office_desk_layout.h"',
        "",
        "const OfficeDeskControl kOfficeDeskControls[] = {",
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
        "const size_t kOfficeDeskControlCount = "
        "sizeof(kOfficeDeskControls) / sizeof(kOfficeDeskControls[0]);"
    )
    lines.append("")
    OUT_C.write_text("\n".join(lines))
    print(f"generated {len(controls)} controls")


if __name__ == "__main__":
    main()
