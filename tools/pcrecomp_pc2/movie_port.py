#!/usr/bin/env python3
"""Replace Movie_Play with the native Bink/FFmpeg player.

The movie's window/UI lifecycle is intentionally not reimplemented; the
native player decodes movie.pak entries and presents them through the host
Vulkan window. This removes the game's Bink DLL calls and the win32hle Bink
module from the active path.
"""

from __future__ import annotations

import pathlib
import re
import sys

FUNCTION = "sub_004CE9D0"
NATIVE = "pc2_native_movie_play"
INCLUDE = '#include "pc2_native_movie.h"\n'


def main() -> int:
    if len(sys.argv) != 2:
        print("usage: movie_port.py <generated-c-dir>", file=sys.stderr)
        return 2
    root = pathlib.Path(sys.argv[1])
    pattern = re.compile(r"^void " + FUNCTION + r"\(void\) \{\n.*?^\}\n",
                         re.S | re.M)
    found = False
    changed = 0
    for path in sorted(root.glob("recomp_*.c")):
        text = path.read_text()
        match = pattern.search(text)
        if not match:
            continue
        found = True
        if NATIVE + "();" in match.group(0):
            continue
        replacement = f"void {FUNCTION}(void) {{\n    {NATIVE}();\n}}\n"
        text = text[:match.start()] + replacement + text[match.end():]
        if INCLUDE not in text:
            text = text.replace("#define RECOMP_GENERATED_CODE\n",
                                "#define RECOMP_GENERATED_CODE\n" + INCLUDE, 1)
        path.write_text(text)
        changed += 1
    if not found:
        print("movie_port: missing " + FUNCTION, file=sys.stderr)
        return 1
    print(f"movie_port: native Movie_Play, {changed} file(s) updated")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
