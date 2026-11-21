#!/usr/bin/env python3
"""Relink one strict COFF candidate into a byte-identical scratch PC2 image."""

from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path
import struct
import tempfile

from match_decomp import (DEFAULT_VC6, GAME, function_length, match, parse_coff,
                          parse_symbols, pe_image, relocation_target, relocation_value,
                          section_relocations)


def digest(data):
    return hashlib.sha256(data).hexdigest()


def link_body(obj, address, length, entry, symbols):
    object_bytes, sections, coff_symbols = parse_coff(obj)
    entries = [symbol for symbol in coff_symbols if symbol and symbol["name"] == entry]
    if len(entries) != 1 or not 0 < entries[0]["section"] <= len(sections):
        raise ValueError(f"expected one defined COFF entry for {entry}")
    entry_symbol = entries[0]
    index = entry_symbol["section"]
    section = sections[index - 1]
    raw = section["raw"]
    code_section = section["name"] == ".text" or section["name"].startswith(".text$")
    if (entry_symbol["value"] != 0 or not code_section
            or len(raw) < length or any(byte not in (0, 0x90, 0xCC) for byte in raw[length:])):
        raise ValueError("candidate must occupy one code section apart from trailing padding")
    if any(symbol and symbol is not entry_symbol and symbol["section"] == index
           and symbol["type"] == 0x20 for symbol in coff_symbols):
        raise ValueError("candidate section contains another function")

    code = bytearray(raw[:length])
    bases = {index: (address, "candidate_entry")}
    calls = []
    previous_end = 0
    for offset, symbol_index, kind in sorted(section_relocations(object_bytes, section)):
        if offset < previous_end or offset + 4 > length:
            raise ValueError("COFF fixup crosses or overlaps the selected function extent")
        previous_end = offset + 4
        symbol = coff_symbols[symbol_index] if symbol_index < len(coff_symbols) else None
        if symbol is None:
            raise ValueError("COFF fixup has an invalid symbol index")
        if symbol["section"] > 0 and (symbol["section"] != index or symbol["value"] >= length):
            raise ValueError(f"COFF target {symbol['name']} is outside the single function extent")
        target, _ = relocation_target(symbol, bases, symbols, auto_symbols=True)
        if target is None:
            raise ValueError(f"unresolved COFF target {symbol['name']}")
        addend, = struct.unpack_from("<i", raw, offset)
        value = relocation_value(target, addend, address + offset, kind)
        struct.pack_into("<I", code, offset, value)
        if kind == 0x14 and offset > 0 and raw[offset - 1] == 0xE8:
            calls.append({"instruction": hex(address + offset - 1),
                          "target": hex((target + addend) & 0xffffffff), "symbol": symbol["name"]})
    return bytes(code), calls


def verified_image(image, address, code):
    original, base, sections = image
    for name, rva, virtual_size, raw_ptr, raw_size in sections:
        relative = address - base - rva
        size = min(virtual_size or raw_size, raw_size)
        if name == ".text" and 0 <= relative and relative + len(code) <= size:
            offset = raw_ptr + relative
            patched = original[:offset] + code + original[offset + len(code):]
            if patched != original:
                raise ValueError("independently linked replacement differs from the original PE")
            return patched, offset
    raise ValueError("the whole function extent must be file-backed in PE .text")


def write_outputs(outputs):
    created = []
    try:
        for path, data in outputs:
            with path.open("xb") as stream:
                created.append(path)
                stream.write(data)
    except OSError:
        for path in created:
            path.unlink(missing_ok=True)
        raise


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("address", type=lambda val: int(val, 0))
    parser.add_argument("source", type=Path)
    parser.add_argument("--length", type=lambda val: int(val, 0), help="assert the indexed full extent")
    parser.add_argument("--entry", required=True, help="exact COFF entry symbol")
    parser.add_argument("--flags", default="/O2")
    parser.add_argument("--symbol", action="append", default=[], metavar="NAME=0xADDRESS")
    parser.add_argument("--vc6", type=Path, default=DEFAULT_VC6)
    parser.add_argument("--image", type=Path, help="input PE copy identical to game/fastfood2.exe")
    parser.add_argument("--out", required=True, type=Path, help="new scratch executable")
    parser.add_argument("--manifest", type=Path, help="new JSON path (default: OUT.manifest.json)")
    args = parser.parse_args()
    try:
        source = args.source.resolve(strict=True)
        out = args.out.absolute()
        manifest_path = (args.manifest or out.with_name(out.name + ".manifest.json")).absolute()
        if out.resolve() == manifest_path.resolve():
            raise ValueError("scratch executable and manifest require distinct output paths")
        for path in (out, manifest_path):
            if path.exists() or path.is_symlink():
                raise ValueError(f"output already exists: {path}")
            if not path.parent.is_dir():
                raise ValueError(f"output directory does not exist: {path.parent}")
        length = function_length(args.address)
        if args.length is not None and args.length != length:
            raise ValueError(f"requested extent {args.length} differs from indexed extent {length}")
        input_path = args.image.resolve(strict=True) if args.image is not None else GAME
        original = pe_image(GAME)
        image = pe_image(input_path) if input_path != GAME else original
        if image[0] != original[0]:
            raise ValueError("--image must be byte-identical to the canonical executable")
        symbols = parse_symbols(args.symbol)
        with tempfile.TemporaryDirectory(prefix="pc2-verified-image-") as scratch:
            obj = Path(scratch) / "candidate.obj"
            audit = match(args.address, source, obj, args.vc6, args.flags.split(), symbols,
                          length, args.entry, strict=True, auto_symbols=True)
            if not audit["strict_match"]:
                issues = audit.get("relocation_issues", []) + audit.get("strict_issues", [])
                reason = (audit.get("error") or (issues[0] if issues else audit.get("first_difference"))
                          or f"candidate extent {audit.get('candidate_length')} of {length} bytes")
                raise ValueError(f"strict match failed at {args.address:#x}: {reason}")
            if len(audit["linked_sections"]) != 1:
                raise ValueError("this verifier currently requires a single linked function section")
            code, calls = link_body(obj, args.address, length, args.entry, symbols)
            patched, offset = verified_image(image, args.address, code)
            output_digest = digest(patched)
            if output_digest != audit["executable_sha256"]:
                raise ValueError("canonical executable changed during verification")
            manifest = {
                "schema": "pc2.verified_linked_image.v1",
                "original": {"path": str(GAME), "sha256": audit["executable_sha256"]},
                "input": {"path": str(input_path), "sha256": output_digest},
                "output": {"path": str(out), "sha256": output_digest},
                "source": {"path": str(source), "sha256": audit["source_sha256"]},
                "object": {"name": obj.name, "sha256": digest(obj.read_bytes())},
                "compiler": audit["compiler"], "flags": audit["flags"],
                "symbol_registry_sha256": audit["symbol_registry_sha256"],
                "symbol_overrides": audit["symbol_overrides"],
                "function": {"entry": args.entry, "start": hex(args.address),
                             "end_exclusive": hex(args.address + length), "length": length,
                             "file_offset": hex(offset), "sha256": digest(code)},
                "relocations": audit["relocations"], "call_targets": calls,
            }
        encoded = (json.dumps(manifest, indent=2) + "\n").encode()
        write_outputs([(out, patched), (manifest_path, encoded)])
    except (OSError, ValueError, struct.error) as error:
        parser.exit(1, f"linked image: {error}\n")
    print(f"{args.address:#x} verified {length} bytes, {len(calls)} direct call fixups, image SHA-256 {output_digest}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
