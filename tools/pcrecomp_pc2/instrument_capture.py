#!/usr/bin/env python3
"""Prepare a separate instrumented copy of the pinned PC2 lift and HLE spine."""

import argparse
import re
from pathlib import Path


SITE = re.compile(r"/\* 0x([0-9A-F]{8}):")
DIRECT = re.compile(r"\b(RECOMP_CALL(?:_SS)?)\((sub_([0-9A-F]{8}))\)")
INDIRECT = re.compile(r"\b(RECOMP_ICALL(?:_SS)?|RECOMP_ITAIL|RECOMP_RET_JUMP)\(")
INDIRECT_KIND = {
    "RECOMP_ICALL": "PC2_EDGE_INDIRECT",
    "RECOMP_ICALL_SS": "PC2_EDGE_INDIRECT",
    "RECOMP_ITAIL": "PC2_EDGE_TAIL",
    "RECOMP_RET_JUMP": "PC2_EDGE_RETURN_JUMP",
}


def instrument_generated(source):
    lines = []
    switch_site = "0"
    for line in source.splitlines(keepends=True):
        if "RECOMP_ENTER(" in line:
            switch_site = "0"
            line = line.replace("RECOMP_ENTER(", "PC2_CAPTURE_ENTER(")
        if "RECOMP_CALL" in line or "RECOMP_ICALL" in line or "RECOMP_ITAIL" in line or "RECOMP_RET_JUMP" in line:
            code, separator, comment = line.partition("/*")
            match = SITE.search(separator + comment)
            site = f"0x{match[1]}u" if match else "0"
            if "default: RECOMP_ITAIL(_jt)" in code:
                site = switch_site
                switch_site = "0"
            code = DIRECT.sub(
                lambda m: f"PC2_CAPTURE_CALL({site}, 0x{m[3]}u, {m[1]}, {m[2]})",
                code,
            )
            if "RECOMP_CALL(" in code or "RECOMP_CALL_SS(" in code:
                raise ValueError(f"Unrecognized generated direct call: {line.strip()}")
            code = INDIRECT.sub(
                lambda m: f"PC2_CAPTURE_INDIRECT({site}, {INDIRECT_KIND[m[1]]}, {m[1]}, ",
                code,
            )
            line = code + separator + comment
        elif "uint32_t _jt =" in line:
            match = SITE.search(line)
            switch_site = f"0x{match[1]}u" if match else "0"
        lines.append(line)
    return replace_exactly(
        "".join(lines), '#include "recomp_types.h"\n',
        '#include "recomp_types.h"\n#include "capture.h"\n'
        '#undef RECOMP_RESOLVE_SITE\n'
        '#define RECOMP_RESOLVE_SITE(va) pc2_capture_resolve(va)\n',
    )


def replace_exactly(source, needle, replacement, count=1):
    if source.count(needle) != count:
        raise ValueError(f"Pinned pcrecomp source changed around {needle!r}")
    return source.replace(needle, replacement)


def instrument_host(source):
    source = replace_exactly(source, '#include "win32hle.h"\n',
                             '#include "win32hle.h"\n#include "capture.h"\n')
    source = replace_exactly(source, "g_shim_n++; added++;",
                             "pc2_capture_import(g_shim[g_shim_n].va, shims->name);\n"
                             "        g_shim_n++; added++;")
    source = replace_exactly(source, "    return g_shim[g_shim_n++].va;",
                             "    pc2_capture_import(g_shim[g_shim_n].va, name);\n"
                             "    return g_shim[g_shim_n++].va;")
    source = replace_exactly(source, "g_shim[i].fn();",
                             "pc2_capture_invoke_shim(g_shim[i].va, g_shim[i].fn);", count=2)
    return replace_exactly(
        source, '    if (!f) hle_fatal("no lifted function at 0x%08X", va);',
        '    pc2_capture_host_call(va, f != NULL, nargs);\n'
        '    if (!f) hle_fatal("no lifted function at 0x%08X", va);',
    )


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("generated", type=Path)
    parser.add_argument("host", type=Path)
    parser.add_argument("output", type=Path)
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=True)
    generated = sorted(args.generated.glob("recomp_*.c"))
    if not generated or not (args.generated / "recomp_dispatch.c").is_file():
        parser.error("the generated lift is missing")
    sources = generated + [args.generated / "recomp_funcs.h", args.host]
    expected = {source.name for source in sources}
    for stale in args.output.glob("recomp_*.c"):
        if stale.name not in expected:
            stale.unlink()

    script_time = Path(__file__).stat().st_mtime_ns
    updated = 0
    for source in sources:
        output = args.output / source.name
        if output.exists() and output.stat().st_mtime_ns >= max(script_time, source.stat().st_mtime_ns):
            continue
        contents = source.read_text()
        if source == args.host:
            contents = instrument_host(contents)
        elif source.suffix == ".c" and source.name != "recomp_dispatch.c":
            contents = instrument_generated(contents)
        pending = output.with_suffix(output.suffix + ".tmp")
        pending.write_text(contents)
        pending.replace(output)
        updated += 1
    print(f"capture instrumentation: {updated} file(s) updated")


if __name__ == "__main__":
    main()
