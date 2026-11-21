#!/usr/bin/env python3
"""Identify VC6 CRT library functions by exact bytes and checked relocations."""

from __future__ import annotations

import argparse
from collections import defaultdict
from dataclasses import dataclass
import hashlib
import json
from pathlib import Path
import struct

from match_decomp import DEFAULT_VC6, GAME, INDEX, pe_image, read_va


DIR32 = 0x0006
REL32 = 0x0014
MASK32 = 0xFFFFFFFF


@dataclass(frozen=True)
class Symbol:
    name: str
    value: int
    section: int
    function: bool
    storage: int
    size: int


@dataclass(frozen=True)
class Relocation:
    offset: int
    symbol: Symbol
    kind: int
    addend: int


@dataclass(frozen=True)
class LibraryFunction:
    archive: str
    member: str
    member_offset: int
    symbol: Symbol
    code: bytes
    relocations: tuple[Relocation, ...]

    @property
    def identity(self):
        return (self.member.replace("\\", "/").rsplit("/", 1)[-1].lower(), self.symbol.name)

    def symbol_slot(self, symbol):
        return self.archive, self.member_offset, symbol.section, symbol.value


def checked_slice(data, offset, size):
    if offset < 0 or size < 0 or offset + size > len(data):
        raise ValueError(f"truncated record at {offset:#x} ({size} bytes)")
    return data[offset:offset + size]


def archive_members(data):
    if not data.startswith(b"!<arch>\n"):
        raise ValueError("expected a COFF archive")
    long_names = b""
    offset = 8
    while offset < len(data):
        header = checked_slice(data, offset, 60)
        if header[58:] != b"`\n" or not header[48:58].strip().isdigit():
            raise ValueError(f"invalid archive member header at {offset:#x}")
        member = checked_slice(data, offset + 60, int(header[48:58]))
        raw_name = header[:16].rstrip(b" ")
        if raw_name == b"//":
            long_names = member
        elif raw_name != b"/":
            if raw_name.startswith(b"/") and raw_name[1:].isdigit():
                start = int(raw_name[1:])
                ends = [end for delimiter in (b"\0", b"/\n")
                        if (end := long_names.find(delimiter, start)) > start]
                if not ends:
                    raise ValueError(f"bad long-member name offset {start}")
                raw_name = long_names[start:min(ends)]
            else:
                raw_name = raw_name.removesuffix(b"/")
            yield offset, raw_name.decode("latin1"), member
        offset += 60 + len(member) + (len(member) & 1)
    if offset != len(data):
        raise ValueError("missing archive alignment byte")


def coff_functions(archive, member, member_offset, data):
    if not data.startswith(b"L\x01"):
        return  # Short import objects and archive metadata are not i386 code.
    _, section_count, _, symbol_ptr, symbol_count, optional_size, _ = struct.unpack(
        "<HHIIIHH", checked_slice(data, 0, 20))
    if optional_size or not symbol_count:
        return
    checked_slice(data, 20, section_count * 40)
    header_end = 20 + section_count * 40
    if symbol_ptr < header_end:
        raise ValueError("COFF symbol table overlaps section headers")
    symbol_table = checked_slice(data, symbol_ptr, symbol_count * 18)
    string_ptr = symbol_ptr + symbol_count * 18
    string_size, = struct.unpack("<I", checked_slice(data, string_ptr, 4))
    if string_size < 4:
        raise ValueError("invalid COFF string table size")
    strings = checked_slice(data, string_ptr, string_size)
    symbols = {}
    index = 0
    while index < symbol_count:
        entry = symbol_table[index * 18:(index + 1) * 18]
        value, section, kind, storage, auxiliary = struct.unpack_from("<IhHBB", entry, 8)
        if index + auxiliary >= symbol_count:
            raise ValueError("COFF auxiliary symbol extends beyond symbol table")
        if entry.startswith(b"\0" * 4):
            start, = struct.unpack_from("<I", entry, 4)
            end = strings.find(b"\0", start)
            if start < 4 or end <= start:
                raise ValueError("invalid COFF symbol name offset")
            name = strings[start:end]
        else:
            name = entry[:8].split(b"\0", 1)[0]
        function = kind & 0x30 == 0x20 and storage in (2, 3)
        size = 0
        if function and storage == 2 and auxiliary and section > 0:
            size, = struct.unpack_from("<I", symbol_table, (index + 1) * 18 + 4)
        symbols[index] = Symbol(name.decode("latin1"), value, section, function, storage, size)
        index += 1 + auxiliary

    for section in range(1, section_count + 1):
        header = 20 + (section - 1) * 40
        raw_size, raw_ptr, reloc_ptr = struct.unpack_from("<III", data, header + 16)
        reloc_count, _, flags = struct.unpack_from("<HHI", data, header + 32)
        if not flags & 0x20 or flags & 0x01000000 or not raw_size:
            continue
        entries = [symbol for symbol in symbols.values() if symbol.section == section]
        functions = [symbol for symbol in entries if symbol.function]
        if not functions:
            continue
        boundaries = {symbol.value for symbol in entries if symbol.function or symbol.storage == 2}
        if raw_ptr < header_end or (reloc_count and reloc_ptr < header_end):
            raise ValueError("COFF code or relocation table overlaps section headers")
        code = checked_slice(data, raw_ptr, raw_size)
        relocs = sorted(struct.iter_unpack("<IIH", checked_slice(data, reloc_ptr, reloc_count * 10)))
        for offset, target, kind in relocs:
            if (offset >= raw_size or target not in symbols
                    or (kind in (DIR32, REL32) and offset + 4 > raw_size)
                    or (symbols[target].section == section and symbols[target].value > raw_size)):
                raise ValueError("invalid COFF relocation location or target")
        for symbol in functions:
            start = symbol.value
            # A single entry at zero consumes its code section. Shared sections
            # require a function-definition auxiliary size, with no trimming.
            size = symbol.size or (raw_size if boundaries == {0} else 0)
            end = start + size
            if not size or end > raw_size or any(start < point < end for point in boundaries):
                continue
            fixups = []
            previous_end = start
            for offset, target, kind in relocs:
                if offset >= end or offset + 4 <= start:
                    continue
                if offset < previous_end or offset + 4 > end or kind not in (DIR32, REL32):
                    break
                addend, = struct.unpack_from("<i", code, offset)
                fixups.append(Relocation(offset - start, symbols[target], kind, addend))
                previous_end = offset + 4
            else:
                yield LibraryFunction(archive, member, member_offset, symbol,
                                      code[start:end], tuple(fixups))


def game_functions(image, index):
    for function in index["functions"]:
        body = function.get("body", {})
        ranges = body.get("ranges", [])
        if len(ranges) != 1 or body.get("non_contiguous"):
            continue
        start = int(ranges[0]["start"], 16)
        end = int(ranges[0]["end"], 16)
        if start == int(function["address"], 16) and end >= start:
            yield start, function["name"], read_va(image, start, end - start + 1)


def evidence(function, method, relocations=()):
    return {"archive": function.archive, "member": function.member,
            "member_offset": hex(function.member_offset), "symbol": function.symbol.name,
            "section": function.symbol.section, "section_offset": hex(function.symbol.value),
            "method": method, "relocations": list(relocations)}


def compare_relocated(function, address, original, known, known_local):
    unresolved = set()
    checked = []
    previous_end = 0
    for relocation in function.relocations:
        offset = relocation.offset
        if function.code[previous_end:offset] != original[previous_end:offset]:
            return None
        previous_end = offset + 4
        symbol = relocation.symbol
        if symbol.section == function.symbol.section:
            target = address + symbol.value - function.symbol.value
            basis = "same_section"
        elif function.symbol_slot(symbol) in known_local:
            target = known_local[function.symbol_slot(symbol)]
            basis = "exact_member_symbol"
        elif symbol.storage == 2:
            target, basis = known.get(symbol.name, (None, "unresolved"))
        else:
            target, basis = None, "unresolved"
        if target is None:
            unresolved.add(symbol.name)
            continue
        value = target + relocation.addend
        if relocation.kind == REL32:
            value -= address + offset + 4
        if struct.pack("<I", value & MASK32) != original[offset:previous_end]:
            return None
        checked.append({"offset": hex(offset), "symbol": symbol.name,
                        "kind": "REL32" if relocation.kind == REL32 else "DIR32",
                        "target": hex(target), "addend": relocation.addend, "basis": basis})
    if function.code[previous_end:] != original[previous_end:]:
        return None
    return sorted(unresolved), checked


def match_functions(functions, game, explicit):
    by_bytes = defaultdict(list)
    by_size = defaultdict(list)
    for address, (_, code) in game.items():
        by_bytes[code].append(address)
        by_size[len(code)].append((address, code))

    matches = defaultdict(list)
    exact_symbols = defaultdict(set)
    exact_local = defaultdict(set)
    for source in functions:
        if source.relocations:
            continue
        for address in by_bytes.get(source.code, []):
            matches[address].append((source.identity, evidence(source, "exact")))
            exact_local[source.symbol_slot(source.symbol)].add(address)
            if source.symbol.storage == 2:
                exact_symbols[source.symbol.name].add(address)

    exact_count = len(matches)
    known = {}
    known_local = {slot: next(iter(addresses)) for slot, addresses in exact_local.items()
                   if len(addresses) == 1}
    for symbol, addresses in exact_symbols.items():
        if len(addresses) == 1:
            address = next(iter(addresses))
            if len({identity for identity, _ in matches[address]}) == 1:
                known[symbol] = (address, "unique_exact_symbol")
    for symbol, address in explicit.items():
        if symbol in known and known[symbol][0] != address:
            raise ValueError(f"explicit address conflicts with exact match for {symbol}")
        known[symbol] = (address, "explicit")

    candidates = defaultdict(list)
    for source in functions:
        if not source.relocations or len(source.relocations) * 4 == len(source.code):
            continue
        for address, code in by_size.get(len(source.code), []):
            comparison = compare_relocated(source, address, code, known, known_local)
            if comparison is None:
                continue
            unresolved, checked = comparison
            variant = evidence(source, "relocated", checked)
            if unresolved:
                variant["unresolved_symbols"] = unresolved
                candidates[address].append(variant)
            else:
                matches[address].append((source.identity, variant))

    locations = defaultdict(set)
    for address, variants in matches.items():
        for identity, _ in variants:
            locations[identity].add(address)
    records = []
    for address, variants in sorted(matches.items()):
        identities = {identity for identity, _ in variants}
        ambiguity = []
        if len(identities) > 1:
            ambiguity.append("multiple_archive_identities")
        if any(len(locations[identity]) > 1 for identity in identities):
            ambiguity.append("same_identity_at_multiple_game_addresses")
        records.append({"address": hex(address), "game_name": game[address][0],
                        "length": len(game[address][1]), "ambiguity": ambiguity,
                        "variants": [variant for _, variant in variants]})
    unresolved_records = [{"address": hex(address), "variants": variants}
                          for address, variants in sorted(candidates.items())]
    return exact_count, records, unresolved_records


def parse_symbol(spec):
    name, sep, raw = spec.rpartition("=")
    try:
        address = int(raw, 0)
    except ValueError:
        address = -1
    if not sep or not name or not 0 <= address <= MASK32:
        raise argparse.ArgumentTypeError(f"expected SYMBOL=0xADDRESS: {spec}")
    return name, address


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("archives", nargs="*", type=Path)
    parser.add_argument("--exe", type=Path, default=GAME)
    parser.add_argument("--index", type=Path, default=INDEX)
    parser.add_argument("--symbol", action="append", type=parse_symbol, default=[])
    parser.add_argument("--json-out", type=Path)
    args = parser.parse_args()
    archives = args.archives or [DEFAULT_VC6 / "LIB" / name for name in ("LIBC.LIB", "LIBCMT.LIB")]

    try:
        explicit = {}
        for symbol, address in args.symbol:
            if symbol in explicit and explicit[symbol] != address:
                raise ValueError(f"conflicting explicit addresses for {symbol}")
            explicit[symbol] = address
        image = pe_image(args.exe)
        executable_sha256 = hashlib.sha256(image[0]).hexdigest()
        index = json.loads(args.index.read_text())
        if index.get("target_sha256", executable_sha256) != executable_sha256:
            raise ValueError("decompile index SHA-256 does not match the executable")
        game = {address: (name, code) for address, name, code in
                game_functions(image, index)}
        functions = []
        archive_inputs = []
        for archive in dict.fromkeys(path.resolve() for path in archives):
            data = archive.read_bytes()
            archive_inputs.append({"path": str(archive), "sha256": hashlib.sha256(data).hexdigest()})
            for offset, member, contents in archive_members(data):
                try:
                    functions.extend(coff_functions(str(archive), member, offset, contents))
                except ValueError as error:
                    raise ValueError(f"{archive.name} member {member}: {error}") from error
        exact, matches, candidates = match_functions(functions, game, explicit)
        ambiguous = sum(bool(match["ambiguity"]) for match in matches)
        if args.json_out:
            report = {"executable_sha256": executable_sha256,
                      "archives": archive_inputs, "game_function_count": len(game),
                      "archive_function_variants": len(functions), "raw_exact_locations": exact,
                      "verified_locations": len(matches), "ambiguous_locations": ambiguous,
                      "matches": matches, "unresolved_candidates": candidates}
            args.json_out.write_text(json.dumps(report, indent=2) + "\n")
    except (OSError, ValueError, KeyError, TypeError, struct.error) as error:
        parser.exit(1, f"CRT archive matching failed: {error}\n")
    print(f"CRT archive: {len(matches)} byte-verified locations ({exact} raw exact, "
          f"{ambiguous} with ambiguous identity) across {len(game)} game functions; "
          f"{len(candidates)} locations also have unresolved candidates")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
