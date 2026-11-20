#!/usr/bin/env python3
"""Add bring-up trace points to pcrecomp's generated C.

The generated C is not committed. This script is idempotent and is run by
build.sh after the lift. It adds entry/return prints for the startup path and
a pending-screen change print for GameLoop_DispatchScreens.
"""

from __future__ import annotations

import pathlib
import re
import sys

TARGETS = [
    ("sub_004CE9D0", "Movie_Play", True),
    ("sub_004EA440", "Map_LoadIsodata", True),
    ("sub_004043E0", "GameMain", True),
    ("sub_00476920", "Screen_MainMenu", True),
    ("sub_00402290", "Resource_Open", True),
    ("sub_00523FE0", "UI_ProcessChildEvent", True),
    ("sub_005287A0", "UI_DrawChildAt", True),
    ("sub_0051EB50", "Renderer_DrawPendingSprite", True),
    ("sub_005243C0", "Window_RenderFrame", True),
    ("sub_00523E20", "UI_RenderScene", True),
    ("sub_00539980", "Gfx_BlitClipped16", True),
    ("sub_00526100", "Window_UpdateTooltip", True),
    ("sub_0051FDA0", "Screen_AnimateTileWipe", True),
    ("sub_0051FB00", "Screen_BeginTileWipeTransition", True),
    ("sub_00523D60", "Window_ShowWindowById", True),
    ("sub_00532890", "UI_SetWindowVisible", True),
    ("sub_00539F90", "Renderer_InitForWindow", True),
    ("sub_00474DF0", "Screen_MissionBriefing", True),
    ("sub_00472DA0", "Screen_FreePlaySetup", True),
    ("sub_00404AF0", "Game_RunSession", True),
    ("sub_0046DBD0", "Screen_CharacterSelect", True),
]


def repair_broken_entries(text: str) -> str:
    """Repair trace strings written by an older non-idempotent patcher."""
    text = re.sub(r'(\[trace\] [A-Za-z0-9_]+ enter)\n"\);',
                  lambda m: m.group(1) + '\\n");', text)
    text = re.sub(r'(\[trace\] Resource_Open enter path=%s)\n",',
                  lambda m: m.group(1) + '\\n",', text)
    return text


def add_includes(text: str) -> str:
    if "#include <stdio.h>" not in text:
        text = text.replace("#define RECOMP_GENERATED_CODE\n",
                            "#define RECOMP_GENERATED_CODE\n#include <stdio.h>\n", 1)
    if "#include <stdlib.h>" not in text:
        text = text.replace("#include <stdio.h>\n",
                            "#include <stdio.h>\n#include <stdlib.h>\n", 1)
    return text


def patch_function(text: str, name: str, label: str) -> tuple[str, bool]:
    pattern = re.compile(r"^void " + re.escape(name) + r"\(void\) \{\n.*?^\}\n",
                         re.S | re.M)
    match = pattern.search(text)
    if not match:
        return text, False
    body = match.group(0)
    if f"[trace] {label}" in body:
        return text, False

    if label == "Resource_Open":
        entry = ('    if (getenv("PC2_TRACE_RESOURCES")) '
                 'fprintf(stderr, "[trace] Resource_Open enter path=%s\\n", '
                 '(char *)(uintptr_t)ADDR(MEM32(esp + 4)));\n')
        ret = ('if (getenv("PC2_TRACE_RESOURCES")) '
               'fprintf(stderr, "[trace] Resource_Open return eax=%08X\\n", eax); return;')
    else:
        entry = f'    fprintf(stderr, "[trace] {label} enter\\n");\n'
        ret = f'fprintf(stderr, "[trace] {label} return\\n"); return;'

    body = re.sub(r"(    RECOMP_ENTER\(0x[0-9A-Fa-f]+u\);\n)",
                  lambda m: m.group(1) + entry, body, count=1)
    body = body.replace("return;", ret)
    return text[:match.start()] + body + text[match.end():], True


def patch_pending(text: str) -> tuple[str, bool]:
    if "[trace] GameLoop pending" in text:
        return text, False
    needle = "L_00405377:\n"
    if needle not in text:
        return text, False
    insert = (needle +
              '    { static int pc2_last_pending = -1; '
              'int pc2_pending = (int)MEM32(0x56386C); '
              'if (pc2_pending != pc2_last_pending) { '
              'fprintf(stderr, "[trace] GameLoop pending=%d\\n", pc2_pending); '
              'pc2_last_pending = pc2_pending; } }\n')
    return text.replace(needle, insert, 1), True


def main() -> int:
    gen = pathlib.Path(sys.argv[1] if len(sys.argv) > 1 else "gen")
    if not gen.is_dir():
        print(f"missing generated directory: {gen}", file=sys.stderr)
        return 1

    changed_files = 0
    for path in sorted(gen.glob("recomp_*.c")):
        text = path.read_text()
        repaired = repair_broken_entries(text)
        changed = repaired != text
        text = repaired
        for name, label, _ in TARGETS:
            text, did = patch_function(text, name, label)
            changed |= did
        text, did = patch_pending(text)
        changed |= did
        if changed:
            path.write_text(add_includes(text))
            changed_files += 1

    print(f"trace points: {changed_files} generated file(s) updated")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
