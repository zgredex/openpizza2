#!/usr/bin/env python3
"""Generate the exact Screen_EndResults (0x46F9C0) control table."""

from __future__ import annotations

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
from ldf_tool import read_ldf  # noqa: E402

SOURCE = ROOT / "decompiled_fastfood2_named_v2/functions_readable/0x46f9c0.c"
EXE = ROOT / "game/fastfood2.exe"
LDF = ROOT / "game/language.ldf"
OUT_C = ROOT / "reconstructed/screen/end_results_layout.c"
OUT_H = ROOT / "reconstructed/screen/end_results_layout.h"

ASSET_NAMES = [
    "fotodummy00.spr", "fotorahmen00.spr", "logos__01.spr", "logos__02.spr",
    "logos__05.spr", "logos__06.spr", "logos__07.spr", "logos__08.spr",
    "playlog_3_02_01.spr", "skbewertung_00.spr", "skbilanz_00.spr",
    "skfiliale_00.spr", "skperso_00.spr", "skrezept_00.spr",
    "skstern_00.spr", "sksyndicate_00.spr", "skwerbung_00.spr",
    "textpb01__00.spr", "textpbtranspgelb_00.spr",
    "textpbtranspgruen_00.spr",
]
ASSETS = {name: index for index, name in enumerate(ASSET_NAMES)}
FONTS = {
    "timesfont.fnt": 0,
    "times14.fnt": 1,
    "verdana7.fnt": 2,
    "verdana8.fnt": 3,
}

TEXT = 0
SPRITE = 1
BUTTON = 2


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
        r"(UI_AddText|UI_AddImage|UI_AddSprite|UI_AddTextButton)\(this,([^;]+)\);"
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
        elif kind_name == "UI_AddTextButton":
            base.update(kind=BUTTON, font=FONTS[token_asset(args[3])], align=2,
                        width=button_widths.get(control_id, 0),
                        text=token_string(args[4], ldf),
                        asset=ASSETS[token_asset(args[6])])
        controls.append(base)

    if len(controls) != 208:
        raise SystemExit(f"expected 208 controls, got {len(controls)}")

    OUT_H.write_text(
        """#ifndef PC2_RECONSTRUCTED_END_RESULTS_LAYOUT_H
#define PC2_RECONSTRUCTED_END_RESULTS_LAYOUT_H

#include <stddef.h>
#include <stdint.h>

#define END_RESULTS_ASSET_COUNT 20
#define END_RESULTS_FONT_TIMES 0
#define END_RESULTS_FONT_TIMES14 1
#define END_RESULTS_FONT_VERDANA7 2
#define END_RESULTS_FONT_VERDANA8 3
#define END_RESULTS_FONT_COUNT 4
#define END_RESULTS_KIND_TEXT 0
#define END_RESULTS_KIND_SPRITE 1
#define END_RESULTS_KIND_BUTTON 2

typedef struct EndResultsControl {
    int32_t id;
    int16_t x;
    int16_t y;
    uint8_t kind;
    uint8_t asset;
    uint8_t font;
    uint8_t align;
    uint16_t width;
    const char *text;
} EndResultsControl;

extern const EndResultsControl kEndResultsControls[];
extern const size_t kEndResultsControlCount;
extern const char *const kEndResultsAssetNames[END_RESULTS_ASSET_COUNT];

#endif
"""
    )
    lines = ['#include "end_results_layout.h"', "",
             "const EndResultsControl kEndResultsControls[] = {"]
    for control in controls:
        lines.append(
            "    {%d, %d, %d, %d, %d, %d, %d, %d, %s},"
            % (control["id"], control["x"], control["y"], control["kind"],
               control["asset"], control["font"], control["align"],
               control["width"], c_string(control["text"]))
        )
    lines += ["};", "",
              "const size_t kEndResultsControlCount = "
              "sizeof(kEndResultsControls) / sizeof(kEndResultsControls[0]);",
              "", "const char *const kEndResultsAssetNames[END_RESULTS_ASSET_COUNT] = {"]
    for name in ASSET_NAMES:
        lines.append(f'    "{name}",')
    lines += ["};", ""]
    OUT_C.write_text("\n".join(lines))
    print(f"generated {len(controls)} controls")


if __name__ == "__main__":
    main()
