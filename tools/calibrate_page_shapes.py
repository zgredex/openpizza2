#!/usr/bin/env python3
"""Compare bounded VC6 C++ source shapes using two invented page builders."""

import argparse
from itertools import product
import json
from pathlib import Path
import subprocess

from match_decomp import (DEFAULT_VC6, compile_candidate, compiler_provenance,
                          file_sha256, parse_coff, section_relocations)
from x86_call_abi import summarize


GRID = """struct ProbeGrid {
    void Add(int row, unsigned channel, unsigned key, int tag, unsigned reserved);
    void Finish(unsigned reserved, unsigned key);
};

extern "C" unsigned __cdecl calibrate_page(ProbeGrid *page, unsigned channel, unsigned key) {
%s
    return channel + key;
}
"""
BADGE = """struct ProbeBadge {
    void Set(unsigned serial, unsigned neutral);
    void Seal(unsigned neutral);
};

extern "C" unsigned __cdecl calibrate_page(ProbeBadge *page, unsigned serial) {
%s
    return serial ^ 7u;
}
"""
GRID_CALLS = """    page->Add(0, channel, key, 17, @);
    page->Add(1, channel, key, 23, @);
    page->Add(2, channel, key, 31, @);
    page->Finish(@, key);"""
BADGE_CALLS = """    page->Set(serial, @);
    page->Seal(@);"""
SOURCES = {
    ("grid", "literal"): GRID % GRID_CALLS.replace("@", "0u"),
    ("grid", "const_local"): GRID % ("    const unsigned neutral = 0u;\n" + GRID_CALLS.replace("@", "neutral")),
    ("grid", "zero_expression"): GRID % ("    const unsigned neutral = key & 0u;\n" + GRID_CALLS.replace("@", "neutral")),
    ("grid", "loop"): GRID % """    static const int tags[3] = {17, 23, 31};
    for (int row = 0; row < 3; ++row) {
        page->Add(row, channel, key, tags[row], 0u);
    }
    page->Finish(0u, key);""",
    ("badge", "literal"): BADGE % BADGE_CALLS.replace("@", "0u"),
    ("badge", "const_local"): BADGE % ("    const unsigned neutral = 0u;\n" + BADGE_CALLS.replace("@", "neutral")),
}
OPTIMIZATIONS = ("/Od", "/O2")
SCHEMA = "pc2.synthetic_page_shape_calibration.v1"


def object_evidence(path):
    data, sections, symbols = parse_coff(path)
    entries = [sym for sym in symbols if sym and sym["name"] == "_calibrate_page" and sym["section"] > 0]
    if len(entries) != 1:
        raise ValueError("expected one defined _calibrate_page symbol")
    entry = entries[0]
    section = sections[entry["section"] - 1]
    end = min((sym["value"] for sym in symbols if sym and sym["section"] == entry["section"]
               and sym["type"] & 0x20 and sym["value"] > entry["value"]), default=len(section["raw"]))
    start = entry["value"]
    if not section["name"].startswith(".text") or not 0 <= start < end <= len(section["raw"]):
        raise ValueError("invalid synthetic function extent")
    rel32 = {offset - start: symbols[index]["name"]
             for offset, index, kind in section_relocations(data, section)
             if start <= offset < end and kind == 0x14 and symbols[index]}
    raw = section["raw"][start:end]
    summary = summarize(raw, 0, relocations=rel32)
    summary.update(object_sha256=file_sha256(path), section=section["name"], section_offset=start,
                   rel32_relocations=len(rel32))
    return summary, raw[:summary["reachable_span_bytes"]], rel32


def literal_comparisons(rows, evidence):
    baselines = {(row["family"], tuple(row["flags"])): row
                 for row in rows if "code" in row and row["shape"] == "literal"}
    comparisons = []
    for row in rows:
        if row["shape"] == "literal" or "code" not in row:
            continue
        baseline = baselines.get((row["family"], tuple(row["flags"])))
        if baseline is None:
            continue
        current, raw, rel32 = evidence[row["object"]]
        original, baseline_raw, baseline_rel32 = evidence[baseline["object"]]
        first_difference = next((offset for offset, pair in enumerate(zip(raw, baseline_raw)) if pair[0] != pair[1]),
                                min(len(raw), len(baseline_raw)) if len(raw) != len(baseline_raw) else None)
        comparisons.append({"family": row["family"], "shape": row["shape"], "flags": row["flags"],
                            "delta_reachable_span_bytes": len(raw) - len(baseline_raw),
                            "reachable_span_bytes_equal": first_difference is None,
                            "first_different_offset": first_difference, "rel32_sites_and_names_equal": rel32 == baseline_rel32,
                            "equal_call_staging": current["staging"] == original["staging"],
                            "equal_zero_writes": current["zero_writes"] == original["zero_writes"]})
    return comparisons


def inspect_existing(out):
    report = json.loads((out / "report.json").read_text())
    if report.get("schema") != SCHEMA or len(report["attempts"]) > len(SOURCES) * len(OPTIMIZATIONS):
        raise ValueError("invalid prior calibration report")
    evidence = {}
    for row in report["attempts"]:
        key = row["family"], row["shape"]
        if key not in SOURCES:
            raise ValueError("inspection requires a known synthetic variant")
        family, shape = key
        source = out / f"{family}-{shape}.cpp"
        if source.read_text() != SOURCES[key] or file_sha256(source) != row["source_sha256"]:
            raise ValueError("inspection requires the generated synthetic sources")
        if "code" not in row:
            continue
        optimization, language = row["flags"]
        if optimization not in OPTIMIZATIONS or language != "/TP":
            raise ValueError("invalid calibration flags in prior report")
        obj = out / f"{source.stem}-{optimization[1:]}.obj"
        if row["object"] != obj.name or row["code"]["object_sha256"] != file_sha256(obj):
            raise ValueError("object name or digest differs from prior calibration report")
        evidence[obj.name] = object_evidence(obj)
        row["code"] = evidence[obj.name][0]
    report["literal_comparisons"] = literal_comparisons(report["attempts"], evidence)
    return report


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--out", type=Path, required=True, help="fresh output directory or existing run to inspect")
    mode = parser.add_mutually_exclusive_group()
    mode.add_argument("--compile", action="store_true", help="compile synthetic sources with pinned VC6 via Wine")
    mode.add_argument("--inspect", action="store_true", help="reinspect verified outputs in an earlier run")
    parser.add_argument("--vc6", type=Path, default=DEFAULT_VC6)
    maximum = len(SOURCES) * len(OPTIMIZATIONS)
    parser.add_argument("--limit", type=int, choices=range(1, maximum + 1), default=maximum)
    args = parser.parse_args()
    out = args.out.resolve()
    try:
        if args.inspect:
            report = inspect_existing(out)
            with (out / "inspection.json").open("x") as stream:
                stream.write(json.dumps(report, indent=2) + "\n")
            print(f"reinspected {len(report['attempts'])} variants: {out / 'inspection.json'}")
            return 0
        if args.compile:
            import capstone
            compiler = compiler_provenance(args.vc6)
        out.mkdir(parents=True)
    except (ImportError, OSError, KeyError, TypeError, ValueError) as error:
        parser.exit(1, f"page calibration: {error}\n")
    rows = []
    evidence = {}
    for family_shape, optimization in list(product(SOURCES, OPTIMIZATIONS))[:args.limit]:
        family, shape = family_shape
        source = out / f"{family}-{shape}.cpp"
        if not source.exists():
            source.write_text(SOURCES[family_shape], encoding="utf-8")
        flags = [optimization, "/TP"]
        row = {"family": family, "shape": shape, "held_out": family == "badge", "flags": flags,
               "source": source.name, "source_sha256": file_sha256(source)}
        if args.compile:
            obj = out / f"{source.stem}-{optimization[1:]}.obj"
            try:
                compile_candidate(source, args.vc6.resolve(), obj, flags)
                evidence[obj.name] = object_evidence(obj)
                row.update(object=obj.name, code=evidence[obj.name][0])
            except (OSError, ValueError, subprocess.TimeoutExpired) as error:
                row["error"] = str(error)[-1200:]
        rows.append(row)
    report = {"schema": SCHEMA, "synthetic_inputs": True,
              "attempts": rows, "literal_comparisons": literal_comparisons(rows, evidence)}
    if args.compile:
        report.update(compiler=compiler, capstone_version=capstone.__version__)
    (out / "report.json").write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    compiled = sum("code" in row for row in rows)
    print(f"{len(rows)} synthetic variants, {compiled} compiled: {out / 'report.json'}")
    return int(args.compile and compiled != len(rows))


if __name__ == "__main__":
    raise SystemExit(main())
