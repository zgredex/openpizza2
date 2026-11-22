#!/usr/bin/env python3
"""Scan and strictly verify the recurring UI page builders in the pinned PC2 PE."""

import argparse
from collections import Counter
from concurrent.futures import ThreadPoolExecutor
import json
from pathlib import Path
import struct
import subprocess

import generate_ui_builder as builder
from match_decomp import compiler_provenance, function_lengths, resolve_auto_symbol
from verify_linked_image import assemble_image, merged_spans, write_outputs

SIGNALS = {0x52F850, 0x531850, 0x52FC00, 0x531C60}
FLAGS = ["/O2", "/TP"]


def scan(image, methods):
    from capstone import Cs, CS_ARCH_X86, CS_MODE_32

    decoder = Cs(CS_ARCH_X86, CS_MODE_32)
    for address, length in sorted(function_lengths().items()):
        if not 900 <= length <= builder.MAX_EXTENT:
            continue
        calls = Counter(int(operand, 16) for _, _, mnemonic, operand
                        in decoder.disasm_lite(builder.read_va(image, address, length), address)
                        if mnemonic == "call" and operand.startswith("0x"))
        hits = sum(calls[target] for target in SIGNALS)
        if len(calls.keys() & SIGNALS) < 2 or hits < 18 or hits * 3 < sum(calls.values()):
            continue
        export = builder.EXPORTS / f"{address:#x}.c"
        row = {"address": hex(address), "length": length}
        try:
            candidate = builder.extract(address, export.read_text(), methods)
            row.update(builder.verify_calls(image, address, length, candidate),
                       pseudocode_sha256=builder.file_sha256(export))
        except (OSError, ValueError) as error:
            yield {**row, "status": "unsupported", "error": str(error)}, None
            continue
        yield row, candidate


def load_previous(directories, compiler):
    reusable = {}
    for directory in directories:
        if not directory.is_dir():
            raise ValueError(f"prior verification directory does not exist: {directory}")
        for path in sorted(directory.glob("0x*.match.json")):
            receipt = json.loads(path.read_text())
            if not receipt.get("strict_match"):
                continue
            if receipt["executable_sha256"] != builder.PE_HASH or receipt["compiler"]["sha256"] != compiler:
                continue
            obj = path.with_name(path.name.removesuffix(".match.json") + ".obj")
            if receipt["flags"] == FLAGS and builder.file_sha256(obj) == receipt["object_sha256"]:
                reusable[int(receipt["address"], 16), receipt["source_sha256"]] = obj
    return reusable


def verify_one(out, job, vc6, previous, scan_only):
    row, candidate = job
    if candidate is None:
        return row
    address = int(row["address"], 16)
    source = out / f"{address:#x}.cpp"
    source.write_text(candidate["source"], encoding="utf-8")
    source_hash = builder.file_sha256(source)
    row.update(source=source.name, source_sha256=source_hash, entry=candidate["entry"])
    if scan_only:
        return {**row, "status": "ready"}
    try:
        cached = previous.get((address, source_hash))
        if cached:
            source.with_suffix(".obj").write_bytes(cached.read_bytes())
            result = builder.verify_object(address, row["length"], source, candidate, vc6, FLAGS)
        else:
            result = builder.verify(address, row["length"], source, candidate, vc6, FLAGS)
        receipt = source.with_suffix(".match.json")
        receipt.write_text(json.dumps(result, indent=2) + "\n")
        status = "strict" if result["strict_match"] else "mismatch"
        return {**row, "status": status, "receipt": receipt.name, "object_reused": bool(cached),
                "first_difference": result["first_difference"], "difference_count": result["difference_count"],
                "strict_issues": result["strict_issues"], "relocation_issues": result["relocation_issues"]}
    except (OSError, ValueError, struct.error, subprocess.TimeoutExpired) as error:
        return {**row, "status": "error", "error": str(error)}


def link_verified(out, rows, original):
    functions = []
    for row in rows:
        receipt = json.loads((out / row["receipt"]).read_text())
        spans = receipt["linked_spans"]
        if not spans or spans[0]["start"] != row["address"] or spans[0]["length"] != row["length"]:
            raise ValueError(f"missing complete primary link span for {row['address']}")
        primary = spans[0]
        functions.append({"status": "strict", "linked_spans": spans,
                          "function": {"start": primary["start"], "end_exclusive": primary["end_exclusive"],
                                       "length": primary["length"], "sha256": primary["sha256"]}})
    spans = merged_spans([(item["function"]["start"], item["linked_spans"]) for item in functions])
    linked = assemble_image(original, [(int(span["file_offset"], 16), bytes.fromhex(span["hex_bytes"]))
                                       for span in spans])
    executable = out / "linked.exe"
    guest = {"path": str(builder.GAME), "sha256": builder.PE_HASH}
    manifest = {"schema": "pc2.verified_linked_image_batch.v1", "functions": functions,
                "original": guest, "input": guest,
                "output": {"path": str(executable), "sha256": builder.PE_HASH}}
    path = executable.with_suffix(".exe.manifest.json")
    write_outputs([(executable, linked), (path, (json.dumps(manifest, indent=2) + "\n").encode())])
    return path.name


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--out", required=True, type=Path, help="fresh directory for generated sources and receipts")
    parser.add_argument("--jobs", type=int, choices=range(1, 9), default=4, metavar="N")
    parser.add_argument("--vc6", type=Path, default=builder.DEFAULT_VC6)
    parser.add_argument("--reuse", type=Path, action="append", default=[],
                        help="prior batch directory containing COFF objects and strict receipts")
    parser.add_argument("--scan-only", action="store_true")
    args = parser.parse_args()
    try:
        if builder.file_sha256(builder.GAME) != builder.PE_HASH:
            raise ValueError("original PE does not match the pinned hash")
        out = args.out.resolve()
        image = builder.pe_image(builder.GAME)
        vc6 = args.vc6.resolve()
        previous = {} if args.scan_only else load_previous(args.reuse, compiler_provenance(vc6)["sha256"])
        out.mkdir(parents=True)
        jobs = list(scan(image, builder.native_methods()))
        print(f"{sum(candidate is not None for _, candidate in jobs)}/{len(jobs)} builders ready", flush=True)
        if not args.scan_only:
            resolve_auto_symbol("__except_list")
        with ThreadPoolExecutor(max_workers=args.jobs) as pool:
            rows = list(pool.map(lambda row: verify_one(out, row, vc6, previous, args.scan_only), jobs))
        strict = [row for row in rows if row["status"] == "strict"]
        totals = dict(Counter(row["status"] for row in rows))
        report = {"schema": "pc2.ui_builder_batch.v1", "executable_sha256": builder.PE_HASH,
                  "flags": FLAGS, "statuses": totals, "candidate_bytes": sum(row["length"] for row in rows),
                  "strict_bytes": sum(row["length"] for row in strict),
                  "objects_reused": sum(row.get("object_reused", False) for row in rows), "functions": rows}
        if strict:
            report["linked_manifest"] = link_verified(out, strict, image[0])
        (out / "report.json").write_text(json.dumps(report, indent=2) + "\n")
        print(f"{totals}, {report['strict_bytes']:,}/{report['candidate_bytes']:,} strict bytes, "
              f"{report['objects_reused']} objects reused")
        return int(bool(set(totals) & {"unsupported", "error", "mismatch"}))
    except (ImportError, OSError, ValueError, KeyError) as error:
        parser.exit(2, f"UI builder batch: {error}\n")


if __name__ == "__main__":
    raise SystemExit(main())
