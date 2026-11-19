#!/usr/bin/env python3
"""Generate the exact Screen_StatisticsBalance (0x430FD0) control table.

Parses the decompiled constructor, resolves language.ldf and inline strings,
and emits reconstructed/screen/statistics_balance_layout.{c,h}.
"""

from __future__ import annotations

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
from ldf_tool import read_ldf  # noqa: E402

SOURCE = ROOT / "decompiled_fastfood2_named_v2/functions_readable/0x430fd0.c"
EXE = ROOT / "game/fastfood2.exe"
LDF = ROOT / "game/language.ldf"
OUT_C = ROOT / "reconstructed/screen/statistics_balance_layout.c"
OUT_H = ROOT / "reconstructed/screen/statistics_balance_layout.h"

ASSETS = {
    "tab09.spr": 0,
    "tabpb01__00.spr": 1,
    "sl01_00.spr": 2,
    "trennzeile.spr": 3,
    "pb33_00.spr": 4,
    "pb22_00.spr": 5,
    "pb24_00.spr": 6,
    "textpb05__00.spr": 7,
    "hilfebuttonsnip_00.spr": 8,
    "statistikbilanzback.spr": 9,
}
FONTS = {
    "timesfont.fnt": 0,
    "verdana7.fnt": 1,
    "verdana8.fnt": 2,
    "vedana11.fnt": 3,
    "verdana10.fnt": 4,
    "verdana14.fnt": 5,
}

KIND_TEXT = 0
KIND_SPRITE = 1
KIND_IMAGE = 2
KIND_SLIDER = 3
KIND_BUTTON = 4


def read_cstr(data: bytes, va: int) -> str:
    raw = data[va - 0x400000 : va - 0x400000 + 256].split(b"\0", 1)[0]
    return raw.decode("cp1252")


def token_string(token: str, ldf: list[str], exe: bytes) -> str:
    match = re.match(r"g_Text_(\d+)_", token)
    if match:
        return ldf[int(match.group(1))]
    match = re.search(r"_([0-9a-fA-F]{8})$", token)
    if match:
        return read_cstr(exe, int(match.group(1), 16))
    raise SystemExit(f"cannot resolve text token {token}")


def token_asset(token: str, exe: bytes) -> str:
    match = re.search(r"_([0-9a-fA-F]{8})$", token)
    if not match:
        raise SystemExit(f"cannot resolve asset token {token}")
    return read_cstr(exe, int(match.group(1), 16))


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
    exe = EXE.read_bytes()
    ldf = read_ldf(str(LDF))

    layouts: dict[int, tuple[int, int]] = {}
    for match in re.finditer(
        r"Window_GadgetNotify_Text_SetLayout\(this,([^,]+),(\d+),([^,]+),([^,]+),([^)]+)\);",
        source,
    ):
        control_id = int(match.group(1), 0)
        layouts[control_id] = (int(match.group(2)), int(match.group(3), 0))

    elements: list[dict] = []
    call_re = re.compile(
        r"(UI_AddText|UI_AddImage|UI_AddSprite|UI_CreateSlider|UI_AddTextButton)\(this,([^;]+)\);"
    )
    for match in call_re.finditer(source):
        kind_name = match.group(1)
        args = [part.strip() for part in match.group(2).split(",")]
        control_id = int(args[0], 0)
        x = int(args[1], 0)
        y = int(args[2], 0)
        if kind_name == "UI_AddText":
            font = token_asset(args[3], exe).lower()
            text = token_string(args[4], ldf, exe)
            align, width = layouts.get(control_id, (0, 0))
            elements.append(
                {
                    "id": control_id,
                    "x": x,
                    "y": y,
                    "kind": KIND_TEXT,
                    "asset": 0,
                    "font": FONTS[font],
                    "align": align,
                    "width": width,
                    "text": text,
                }
            )
        elif kind_name == "UI_AddSprite":
            asset = token_asset(args[3], exe).lower()
            elements.append(
                {
                    "id": control_id,
                    "x": x,
                    "y": y,
                    "kind": KIND_SPRITE,
                    "asset": ASSETS[asset],
                    "font": 0,
                    "align": 0,
                    "width": 0,
                    "text": "",
                }
            )
        elif kind_name == "UI_AddImage":
            asset = token_asset(args[3], exe).lower()
            elements.append(
                {
                    "id": control_id,
                    "x": x,
                    "y": y,
                    "kind": KIND_IMAGE,
                    "asset": ASSETS[asset],
                    "font": 0,
                    "align": 0,
                    "width": 0,
                    "text": "",
                }
            )
        elif kind_name == "UI_CreateSlider":
            length = int(args[3], 0)
            asset = token_asset(args[4], exe).lower()
            elements.append(
                {
                    "id": control_id,
                    "x": x,
                    "y": y,
                    "kind": KIND_SLIDER,
                    "asset": ASSETS[asset],
                    "font": 0,
                    "align": 0,
                    "width": length,
                    "text": "",
                }
            )
        elif kind_name == "UI_AddTextButton":
            font = token_asset(args[3], exe).lower()
            text = token_string(args[4], ldf, exe)
            asset = token_asset(args[6], exe).lower()
            elements.append(
                {
                    "id": control_id,
                    "x": x,
                    "y": y,
                    "kind": KIND_BUTTON,
                    "asset": ASSETS[asset],
                    "font": FONTS[font],
                    "align": 2,
                    "width": 0x93,
                    "text": text,
                }
            )

    if len(elements) != 162:
        raise SystemExit(f"expected 162 controls, got {len(elements)}")

    OUT_H.write_text(
        """#ifndef PC2_RECONSTRUCTED_STATISTICS_BALANCE_LAYOUT_H
#define PC2_RECONSTRUCTED_STATISTICS_BALANCE_LAYOUT_H

#include <stddef.h>
#include <stdint.h>

#define BALANCE_ASSET_TAB09 0
#define BALANCE_ASSET_TABPB01 1
#define BALANCE_ASSET_SLIDER 2
#define BALANCE_ASSET_SEPARATOR 3
#define BALANCE_ASSET_PB33 4
#define BALANCE_ASSET_PB22 5
#define BALANCE_ASSET_PB24 6
#define BALANCE_ASSET_BUTTON 7
#define BALANCE_ASSET_HELP 8
#define BALANCE_ASSET_BACKGROUND 9
#define BALANCE_ASSET_COUNT 10

#define BALANCE_KIND_TEXT 0
#define BALANCE_KIND_SPRITE 1
#define BALANCE_KIND_IMAGE 2
#define BALANCE_KIND_SLIDER 3
#define BALANCE_KIND_BUTTON 4

typedef struct BalanceControl {
    int32_t id;
    int16_t x;
    int16_t y;
    uint8_t kind;
    uint8_t asset;
    uint8_t font;
    uint8_t align;   /* 0 left, 1 right, 2 centre */
    uint16_t width;
    const char *text;
} BalanceControl;

extern const BalanceControl kBalanceControls[];
extern const size_t kBalanceControlCount;

#endif
"""
    )

    lines = [
        '#include "statistics_balance_layout.h"',
        "",
        "const BalanceControl kBalanceControls[] = {",
    ]
    for element in elements:
        lines.append(
            "    {%d, %d, %d, %d, %d, %d, %d, %d, %s},"
            % (
                element["id"],
                element["x"],
                element["y"],
                element["kind"],
                element["asset"],
                element["font"],
                element["align"],
                element["width"],
                c_string(element["text"]),
            )
        )
    lines.append("};")
    lines.append("")
    lines.append(
        "const size_t kBalanceControlCount = "
        "sizeof(kBalanceControls) / sizeof(kBalanceControls[0]);"
    )
    lines.append("")
    OUT_C.write_text("\n".join(lines))
    print(f"generated {len(elements)} controls")


if __name__ == "__main__":
    main()
