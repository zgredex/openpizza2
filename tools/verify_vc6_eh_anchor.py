#!/usr/bin/env python3
"""Infer a VC6 EH handler anchor from neighboring functions and verify its COFF."""

import argparse
import json
from pathlib import Path
import struct
import subprocess
from tempfile import TemporaryDirectory

from compare_vc6_unwind import Coff, FRAME_HANDLER, MAGIC, handler_field_offset, original_operand, read_unwind
from decomp_fixtures import PE_HASH
import match_decomp as match


def original_stub(read, resolve, address):
    if not address or read(address, 10)[0:6:5] != b"\xb8\xe9":
        return None
    if resolve(address, 6, 0x14) != FRAME_HANDLER:
        return None
    info = resolve(address, 1, 0x06)
    if info and read(info, 4) == struct.pack("<I", MAGIC):
        return info
    return None


def find_bracket(image, target, read, resolve):
    functions = []
    for address, length in sorted(match.function_lengths().items()):
        # Read other functions' original operands only. The disputed target's
        # handler operand will be used later by the strict verifier.
        if address == target:
            continue
        try:
            offset = handler_field_offset(read(address, min(length, 32)))
            handler = resolve(address, offset, 0x06)
            if original_stub(read, resolve, handler) is not None:
                functions.append((address, handler))
        except (ValueError, struct.error):
            continue
    if any(a[1] >= b[1] for a, b in zip(functions, functions[1:])):
        raise ValueError("original neighboring VC6 handler addresses are not strictly monotonic")
    earlier = next((item for item in reversed(functions) if item[0] < target), None)
    later = next((item for item in functions if item[0] > target), None)
    if earlier is None or later is None:
        raise ValueError("target has no enclosing pair of indexed VC6 handlers")
    start, end = earlier[1] + 10, later[1]
    if start >= end or match.pe_file_span(image, start, end - start)[1] != ".text":
        raise ValueError("handler search interval is empty or outside .text")
    return earlier, later, len(functions)


def unwind_shape(unwind):
    # Frame offsets are diagnostics. Requiring them at the lookup stage
    # would hide cases where only a cleanup stack slot differs.
    return [(entry["previous"], entry["cleanup"]["transfers"] if entry["cleanup"] is not None else None)
            for entry in unwind["states"]]


def infer_anchor(image, address, obj, entry, symbols):
    length = match.function_length(address)

    def read(location, size):
        return match.read_va(image, location, size)

    def resolve(location, offset, kind):
        return original_operand(read, location, offset, kind)

    handler_field_offset(read(address, min(length, 32)))
    earlier, later, witness_count = find_bracket(image, address, read, resolve)
    coff = Coff(obj, {"___CxxFrameHandler": FRAME_HANDLER, **symbols})
    symbol = coff.symbols.get(entry)
    if symbol is None or symbol["section"] <= 0:
        raise ValueError(f"missing emitted entry {entry}")
    entry_location = symbol["section"], symbol["value"]
    slot = handler_field_offset(coff.read(entry_location, 32))
    record = coff.relocations.get((entry_location[0], entry_location[1] + slot))
    if record is None:
        raise ValueError("emitted EH prologue lacks a handler relocation")
    label, kind = record
    if kind != 0x06 or label["section"] <= 0 or not label["name"].startswith("$L"):
        raise ValueError("emitted handler is not a supported local VC6 label")
    if label["name"] in symbols or coff.sections[label["section"] - 1]["name"] != ".text$x":
        raise ValueError("handler label already has an override or is outside .text$x")
    handler = coff.resolve(entry_location, slot, kind)
    emitted = read_unwind(coff.read, coff.resolve, handler)
    first, end = earlier[1] + 10, later[1]
    region = read(first, end - first)
    considered, plausible = [], []
    for offset in range(len(region) - 9):
        if region[offset:offset + 6:5] != b"\xb8\xe9":
            continue
        original_handler = first + offset
        try:
            if original_stub(read, resolve, original_handler) is None:
                continue
            original = read_unwind(read, resolve, original_handler)
        except (ValueError, struct.error):
            continue
        considered.append(hex(original_handler))
        if unwind_shape(original) == unwind_shape(emitted):
            plausible.append(original)
    evidence = {
        "label": label["name"], "neighbors": [{"function": hex(a), "handler": hex(h)} for a, h in (earlier, later)],
        "monotonic_witnesses": witness_count, "scanned_handlers": considered,
        "compatible_handlers": [hex(row["handler"]) for row in plausible],
        "emitted_unwind": emitted,
    }
    if len(plausible) != 1:
        return evidence, {}
    original = plausible[0]
    evidence["original_unwind"] = original
    addend, = struct.unpack("<i", coff.read((entry_location[0], entry_location[1] + slot), 4))
    return evidence, {label["name"]: original["handler"] - addend}


def verify(address, obj, entry, symbols):
    if match.file_sha256(match.GAME) != PE_HASH:
        raise ValueError("automatic EH anchors require the pinned executable")
    image = match.pe_image(match.GAME)
    evidence, inferred = infer_anchor(image, address, obj, entry, symbols)
    length = match.function_length(address)
    baseline = match.match_object(address, obj, symbols, length, entry, True, True, True)
    result = match.match_object(address, obj, {**symbols, **inferred}, length, entry, True, True, True)
    result.update(executable_sha256=PE_HASH, baseline_strict_match=baseline["strict_match"],
                  inferred_anchors={name: hex(va) for name, va in inferred.items()}, eh_anchor_evidence=evidence)
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("address", type=lambda value: int(value, 0))
    parser.add_argument("--entry", required=True)
    source = parser.add_mutually_exclusive_group(required=True)
    source.add_argument("--source", type=Path, help="compile a candidate with pinned VC6")
    source.add_argument("--object", type=Path, help="reuse a previously compiled object")
    parser.add_argument("--symbol", action="append", default=[], metavar="NAME=VA")
    parser.add_argument("--flags", default="/O2 /GX /TP")
    parser.add_argument("--out", type=Path, required=True)
    args = parser.parse_args()
    try:
        symbols = match.parse_symbols(args.symbol)
        flags = args.flags.split()
        with TemporaryDirectory(prefix="pc2-eh-anchor-") as directory:
            obj = args.object
            if args.source:
                obj = Path(directory) / "candidate.obj"
                match.compile_candidate(args.source.resolve(), match.DEFAULT_VC6.resolve(), obj, flags)
            result = verify(args.address, obj, args.entry, symbols)
            if args.source:
                anchors = {name: int(va, 16) for name, va in result["inferred_anchors"].items()}
                result.update(match.match_provenance(args.source, match.DEFAULT_VC6, flags,
                                                     {**symbols, **anchors}, True, True, True))
                match.write_function_audit(result)
        args.out.write_text(json.dumps(result, indent=2) + "\n")
    except (OSError, ValueError, struct.error, subprocess.TimeoutExpired) as error:
        parser.exit(1, f"VC6 EH anchor: {error}\n")
    print(f"{result['address']}: anchors={result['inferred_anchors']}, "
          f"strict={result['strict_match']}, baseline={result['baseline_strict_match']}")
    return int(not result["inferred_anchors"] or not result["strict_match"])


if __name__ == "__main__":
    raise SystemExit(main())
