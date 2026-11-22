#!/usr/bin/env python3
"""Discover and verify contiguous functions that call the PC2 save streams."""

import argparse
from collections import Counter
from concurrent.futures import ThreadPoolExecutor
import json
from pathlib import Path
import struct
import subprocess

import verify_serializer_pilot as serializer
from replay_worklist import archived_inputs
from verify_ui_builder_batch import link_verified, load_previous

STREAM_CALLS = {0x54CBC1, 0x54CC2B}


def discover(image):
    from capstone import Cs, CS_ARCH_X86, CS_MODE_32

    decoder = Cs(CS_ARCH_X86, CS_MODE_32)
    tracked = archived_inputs()
    for address, length in sorted(serializer.match.function_lengths().items()):
        if address in tracked or not (serializer.EXPORTS / f"{address:#x}.c").is_file():
            continue
        code = serializer.match.read_va(image, address, length)
        if any(mnemonic == "call" and operand.startswith("0x") and int(operand, 16) in STREAM_CALLS
               for _, _, mnemonic, operand in decoder.disasm_lite(code, address)):
            yield address


def build(address, output, image, names, vc6, previous, verify):
    row = {"address": hex(address), "name": names.get(hex(address)),
           "length": serializer.match.function_length(address)}
    try:
        text, methods, row = serializer.gen_candidate(address, image, names)
    except (OSError, ValueError, KeyError) as error:
        return {**row, "status": "unsupported", "reason": str(error)}
    source = output / f"{address:#x}.cpp"
    source.write_text(text)
    source_hash = serializer.match.file_sha256(source)
    row.update(status="ready", source_sha256=source_hash, source=source.name)
    if not verify:
        return row
    try:
        obj = source.with_suffix(".obj")
        cached = previous.get((address, source_hash))
        if cached:
            obj.write_bytes(cached.read_bytes())
        else:
            serializer.match.compile_candidate(source, vc6, obj, serializer.FLAGS)
        result = serializer.check_object(address, obj, methods, source, vc6, row["length"])
        receipt = source.with_suffix(".match.json")
        receipt.write_text(json.dumps(result, indent=2) + "\n")
        row.update(status="strict" if result["strict_match"] else "mismatch", receipt=receipt.name,
                   object_reused=bool(cached), first_difference=result["first_difference"],
                   difference_count=result["difference_count"], strict_issues=result["strict_issues"],
                   relocation_issues=result["relocation_issues"])
    except (OSError, ValueError, struct.error, subprocess.TimeoutExpired) as error:
        row.update(status="error", reason=str(error))
    return row


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--out", required=True, type=Path, help="fresh scratch directory")
    parser.add_argument("--address", action="append", type=lambda value: int(value, 0), default=[])
    parser.add_argument("--reuse", action="append", type=Path, default=[],
                        help="prior directory with strict receipts and their COFF objects")
    parser.add_argument("--jobs", type=int, choices=range(1, 9), default=4)
    parser.add_argument("--verify", action="store_true")
    args = parser.parse_args()
    match = serializer.match
    try:
        if match.file_sha256(match.GAME) != serializer.PE_HASH:
            raise ValueError("canonical executable differs from the pin")
        image = match.pe_image(match.GAME)
        discovered = list(discover(image))
        if set(args.address) - set(discovered):
            raise ValueError("some selected addresses are outside the stream-call inventory")
        addresses = list(dict.fromkeys(args.address)) if args.address else discovered
        names = json.loads(match.SYMBOL_INDEX.read_text())
        vc6 = match.DEFAULT_VC6.resolve()
        previous = load_previous(args.reuse, match.compiler_provenance(vc6)["sha256"]) if args.verify else {}
        if args.verify:
            match.resolve_auto_symbol("__except_list")
        out = args.out.resolve()
        out.mkdir(parents=True)
        with ThreadPoolExecutor(max_workers=args.jobs) as pool:
            rows = list(pool.map(lambda va: build(va, out, image, names, vc6, previous, args.verify), addresses))
        strict = [row for row in rows if row["status"] == "strict"]
        statuses = dict(Counter(row["status"] for row in rows))
        report = {"schema": "pc2.serializer_batch.v1", "executable_sha256": serializer.PE_HASH,
                  "flags": serializer.FLAGS, "statuses": statuses, "functions": rows,
                  "candidate_bytes": sum(row["length"] for row in rows),
                  "strict_bytes": sum(row["length"] for row in strict),
                  "objects_reused": sum(row.get("object_reused", False) for row in rows)}
        if strict:
            report["linked_manifest"] = link_verified(out, strict, image[0])
        (out / "report.json").write_text(json.dumps(report, indent=2) + "\n")
        print(f"{statuses}, {report['strict_bytes']:,}/{report['candidate_bytes']:,} strict bytes, "
              f"{report['objects_reused']} objects reused")
        return int("error" in statuses)
    except (ImportError, KeyError, OSError, ValueError) as error:
        parser.exit(2, f"serializer batch: {error}\n")


if __name__ == "__main__":
    raise SystemExit(main())
