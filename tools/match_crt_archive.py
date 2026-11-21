#!/usr/bin/env python3
"""Identify VC6 CRT library functions by exact bytes and checked relocations."""

from __future__ import annotations

import argparse
from collections import defaultdict
from dataclasses import dataclass
import hashlib
import json
from pathlib import Path
import re
import struct

from match_decomp import (DEFAULT_VC6, GAME, INDEX, function_lengths, image_imports,
                          pe_file_span, pe_image, read_va, relocation_value)


DIR32 = 0x0006
REL32 = 0x0014
MASK32 = 0xFFFFFFFF
STOCK_LIBS = {
    "LIBC.LIB": "76d536155a582d2cc9dafded92cfc1122aa4234a8f1afba252232ff492b2e13b",
    "LIBCMT.LIB": "7922ed5dfd9da6d945a601f28b17e1cd67db97a87d995b579bfcade16e6e5765",
    "LIBCI.LIB": "46db1e51522cd82608ed851d7380d7afbb612ea16e1d1a3957f655044ea8e486",
    "LIBCIMT.LIB": "a78e4d21e853b385b043a1dfd0d65e8a3030eb0d776f4d66c2f76afeee6c115f",
    "LIBCP.LIB": "a89e841ccb409885db2756d255be875f6d8ee5a5e3fdaad3162a393590cdf4d3",
    "LIBCPMT.LIB": "919e3d9c8610a29f7a4a513df25ea2be6500cea742ddd613f5652f24fa4df98c",
}
PLAN_SCHEMA = "pc2.stock_archive_plan.v1"


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
    section_name: str = ".text"
    member_sha256: str | None = None

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
    member_sha256 = hashlib.sha256(data).hexdigest()
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
        section_name = data[header:header + 8].split(b"\0", 1)[0].decode("latin1")
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
                                      code[start:end], tuple(fixups), section_name, member_sha256)


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
            "member_sha256": function.member_sha256, "section": function.symbol.section,
            "section_name": function.section_name, "section_offset": hex(function.symbol.value),
            "method": method, "relocations": list(relocations)}


def compare_relocated(function, address, original, known, known_local, *, stock=False):
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
            if stock and not address <= target + relocation.addend < address + len(function.code):
                return None
        elif function.symbol_slot(symbol) in known_local:
            binding = known_local[function.symbol_slot(symbol)]
            target, basis = binding if stock else (binding, "exact_member_symbol")
        elif symbol.storage == 2 and (not stock or symbol.section == 0):
            target, basis = known.get(symbol.name, (None, "unresolved"))
        else:
            target, basis = None, "unresolved"
        if target is None:
            unresolved.add(symbol.name)
            continue
        value = relocation_value(target, relocation.addend, address + offset, relocation.kind)
        if struct.pack("<I", value) != original[offset:previous_end]:
            return None
        checked.append({"offset": hex(offset), "symbol": symbol.name,
                        "kind": "REL32" if relocation.kind == REL32 else "DIR32",
                        "target": hex(target), "addend": relocation.addend, "basis": basis,
                        "value": hex(value)})
    if function.code[previous_end:] != original[previous_end:]:
        return None
    return sorted(unresolved), checked


def match_inventory(functions, game):
    by_bytes = defaultdict(list)
    by_size = defaultdict(list)
    for address, (_, code) in game.items():
        by_bytes[code].append(address)
        by_size[len(code)].append((address, code))

    exact = defaultdict(list)
    for source in functions:
        if source.relocations:
            continue
        for address in by_bytes.get(source.code, []):
            exact[address].append((source, evidence(source, "exact")))
    return exact, by_size


def relocated_matches(functions, by_size, exact, known, known_local, *, stock=False):
    matches = defaultdict(list, {address: list(variants) for address, variants in exact.items()})
    candidates = defaultdict(list)
    for source in functions:
        if not source.relocations or len(source.relocations) * 4 == len(source.code):
            continue
        for address, code in by_size.get(len(source.code), []):
            comparison = compare_relocated(source, address, code, known, known_local, stock=stock)
            if comparison is None:
                continue
            unresolved, checked = comparison
            variant = evidence(source, "relocated", checked)
            if unresolved:
                variant["unresolved_symbols"] = unresolved
                candidates[address].append(variant)
            else:
                matches[address].append((source, variant))
    return matches, candidates


def ambiguities(matches):
    locations = defaultdict(set)
    for address, variants in matches.items():
        for source, _ in variants:
            locations[source.identity].add(address)
    result = {}
    for address, variants in matches.items():
        identities = {source.identity for source, _ in variants}
        ambiguity = []
        if len(identities) > 1:
            ambiguity.append("multiple_archive_identities")
        if any(len(locations[identity]) > 1 for identity in identities):
            ambiguity.append("same_identity_at_multiple_game_addresses")
        result[address] = ambiguity
    return result


def match_records(matches, candidates, game, revoked=()):
    by_address = ambiguities(matches)
    for address in revoked:
        by_address[address].append("revoked_stock_identity")
    records = [{"address": hex(address), "game_name": game[address][0],
                "length": len(game[address][1]), "ambiguity": by_address[address],
                "variants": [variant for _, variant in variants]}
               for address, variants in sorted(matches.items())]
    unresolved_records = [{"address": hex(address), "variants": variants}
                          for address, variants in sorted(candidates.items())]
    return records, unresolved_records


def match_functions(functions, game, explicit):
    exact, by_size = match_inventory(functions, game)
    exact_symbols, exact_local = defaultdict(set), defaultdict(set)
    for address, variants in exact.items():
        for source, _ in variants:
            exact_local[source.symbol_slot(source.symbol)].add(address)
            if source.symbol.storage == 2:
                exact_symbols[source.symbol.name].add(address)
    known, known_local = {}, {slot: next(iter(addresses)) for slot, addresses in exact_local.items()
                              if len(addresses) == 1}
    for symbol, addresses in exact_symbols.items():
        if len(addresses) == 1:
            address = next(iter(addresses))
            if len({source.identity for source, _ in exact[address]}) == 1:
                known[symbol] = (address, "unique_exact_symbol")
    for symbol, address in explicit.items():
        if symbol in known and known[symbol][0] != address:
            raise ValueError(f"explicit address conflicts with exact match for {symbol}")
        known[symbol] = (address, "explicit")
    matches, candidates = relocated_matches(functions, by_size, exact, known, known_local)
    return len(exact), *match_records(matches, candidates, game)


def stock_imports(functions, imports):
    result = {}
    for function in functions:
        for relocation in function.relocations:
            symbol = relocation.symbol
            if symbol.section or symbol.storage != 2 or not symbol.name.startswith("__imp_"):
                continue
            raw = re.sub(r"@\d+$", "", symbol.name.removeprefix("__imp_"))
            names = {raw, raw[1:]} if raw.startswith(("_", "@")) else {raw}
            addresses = {address for name in names for address in imports.get(name, ())}
            if len(addresses) == 1:
                result[symbol.name] = next(iter(addresses)), "pe_iat"
    return result


def stock_bindings(matches, suppressed=()):
    public_locations, member_locations = defaultdict(set), defaultdict(set)
    for address, variants in matches.items():
        for source, _ in variants:
            if source.symbol.storage == 2:
                public_locations[source.symbol.name].add(address)
            member_locations[source.symbol_slot(source.symbol)].add(address)

    public, member = {}, {}
    for address, ambiguity in ambiguities(matches).items():
        if ambiguity or address in suppressed:
            continue
        for source, receipt in matches[address]:
            slot = source.symbol_slot(source.symbol)
            if len(member_locations[slot]) == 1:
                member.setdefault(slot, (address, receipt))
            name = source.symbol.name
            if source.symbol.storage == 2 and len(public_locations[name]) == 1:
                public.setdefault(name, (address, receipt))
    return public, member


def revoked_locations(matches, public, member):
    return {address for address, variants in matches.items()
            if any(source.symbol.name in public or source.symbol_slot(source.symbol) in member
                   for source, _ in variants)}


def stock_matches(functions, game, iat):
    """Grow only from independently proven earlier rounds and revoke ambiguous seeds."""
    exact, by_size = match_inventory(functions, game)
    imports = stock_imports(functions, iat)
    banned_public, banned_member = set(), set()
    while True:
        public, member, rounds = {}, {}, []
        while True:
            known = {**imports, **{name: (proof["address"], proof["basis"]) for name, proof in public.items()}}
            known_local = {slot: (proof["address"], proof["basis"]) for slot, proof in member.items()}
            matches, pending = relocated_matches(functions, by_size, exact, known, known_local, stock=True)
            public_next, member_next = stock_bindings(matches, revoked_locations(matches, banned_public, banned_member))
            unsafe_public = {name for name, proof in public.items()
                             if name not in public_next or public_next[name][0] != proof["address"]}
            unsafe_member = {slot for slot, proof in member.items()
                             if slot not in member_next or member_next[slot][0] != proof["address"]}
            if unsafe_public or unsafe_member:
                banned_public.update(unsafe_public)
                banned_member.update(unsafe_member)
                break

            step = len(rounds) + 1
            add_public = {name: {"address": address,
                                 "basis": "unique_exact_symbol" if receipt["method"] == "exact" else "verified_stock_symbol",
                                 "round": step, "witness": receipt}
                          for name, (address, receipt) in public_next.items()
                          if name not in (public.keys() | imports.keys() | banned_public)}
            add_member = {slot: {"address": address,
                                 "basis": "exact_member_symbol" if receipt["method"] == "exact" else "verified_member_symbol",
                                 "round": step, "witness": receipt}
                          for slot, (address, receipt) in member_next.items()
                          if slot not in (member.keys() | banned_member)}
            if not add_public and not add_member:
                return len(exact), matches, pending, public, member, imports, rounds, {
                    "public": sorted(banned_public), "member": [list(slot) for slot in sorted(banned_member)]}
            rounds.append({"round": step, "public": len(add_public), "member": len(add_member)})
            public.update(add_public)
            member.update(add_member)


def read_archives(paths, expected=None, *, stock=False):
    functions, inputs = [], []
    remaining = set(STOCK_LIBS.values()) if stock else None
    for archive in dict.fromkeys(path.resolve() for path in paths):
        data = archive.read_bytes()
        sha256 = hashlib.sha256(data).hexdigest()
        if expected is not None and expected.get(str(archive)) != sha256:
            raise ValueError(f"archive SHA-256 changed: {archive}")
        if remaining is not None:
            if sha256 not in remaining:
                raise ValueError(f"wrong or duplicate pinned VC6 archive: {archive}")
            remaining.remove(sha256)
        inputs.append({"path": str(archive), "sha256": sha256})
        for offset, member, contents in archive_members(data):
            try:
                functions.extend(coff_functions(str(archive), member, offset, contents))
            except ValueError as error:
                raise ValueError(f"{archive.name} member {member}: {error}") from error
    if remaining:
        raise ValueError("stock scan requires all six pinned VC6 archives")
    return functions, inputs


def stock_plan(image, game, functions, archives, index_pin):
    exact, matches, pending, public, member, imports, rounds, banned = stock_matches(
        functions, game, image_imports(image, all_slots=True))
    revoked_names = set(banned["public"])
    revoked_slots = {tuple(slot) for slot in banned["member"]}
    revoked_addresses = revoked_locations(matches, revoked_names, revoked_slots)
    records, unresolved = match_records(matches, pending, game, revoked_addresses)
    placed = []
    for record in records:
        if record["ambiguity"]:
            continue
        address = int(record["address"], 16)
        source, witness = matches[address][0]
        linked = bytearray(source.code)
        if len(source.relocations) != len(witness["relocations"]):
            raise ValueError(f"incomplete archive fixup proof at {address:#x}")
        for relocation, checked in zip(source.relocations, witness["relocations"]):
            value = relocation_value(int(checked["target"], 16), relocation.addend,
                                     address + relocation.offset, relocation.kind)
            struct.pack_into("<I", linked, relocation.offset, value)
        if linked != game[address][1]:
            raise ValueError(f"independently linked archive body differs at {address:#x}")
        length = len(linked)
        offset, section = pe_file_span(image, address, length)
        sha256 = hashlib.sha256(linked).hexdigest()
        span = {"kind": "primary", "section": source.section_name, "section_index": source.symbol.section,
                "placement": "stock_archive", "pe_section": section,
                "start": hex(address), "end_exclusive": hex(address + length), "length": length,
                "source_section_offset": hex(source.symbol.value), "file_offset": hex(offset),
                "file_end_exclusive": hex(offset + length), "hex_bytes": linked.hex(), "sha256": sha256,
                "fixup_sites": [hex(address + relocation.offset) for relocation in source.relocations]}
        placed.append({"address": hex(address), "status": "strict", "provider": "stock_archive",
                       "function": {"entry": source.symbol.name, "start": hex(address),
                                    "end_exclusive": hex(address + length), "length": length,
                                    "file_offset": hex(offset), "file_end_exclusive": hex(offset + length),
                                    "sha256": sha256}, "archive_proof": witness, "linked_spans": [span]})
    plan = {"schema": PLAN_SCHEMA, "executable_sha256": hashlib.sha256(image[0]).hexdigest(),
            "archives": archives, "index": index_pin, "functions": placed,
            "symbols": {name: {**proof, "address": hex(proof["address"])} for name, proof in sorted(public.items())},
            "member_symbols": [{"slot": list(slot), **proof, "address": hex(proof["address"])}
                               for slot, proof in sorted(member.items())],
            "imports": {name: hex(address) for name, (address, _) in sorted(imports.items())},
            "rounds": rounds, "revoked": banned}
    return exact, records, unresolved, plan


def read_game(image, index_path, expected=None):
    contents = index_path.read_bytes()
    sha256 = hashlib.sha256(contents).hexdigest()
    if expected is not None and expected != sha256:
        raise ValueError("archive plan decompile index SHA-256 changed")
    index = json.loads(contents)
    executable_sha256 = hashlib.sha256(image[0]).hexdigest()
    if index.get("target_sha256", executable_sha256) != executable_sha256:
        raise ValueError("decompile index SHA-256 does not match the executable")
    return {address: (name, code) for address, name, code in game_functions(image, index)}, {
        "path": str(index_path.resolve()), "sha256": sha256}


def load_stock_plan(path, image):
    saved = json.loads(path.read_text())
    if saved["schema"] != PLAN_SCHEMA or saved["executable_sha256"] != hashlib.sha256(image[0]).hexdigest():
        raise ValueError("archive plan schema or executable SHA-256 differs")
    game, index = read_game(image, Path(saved["index"]["path"]), saved["index"]["sha256"])
    archives = {item["path"]: item["sha256"] for item in saved["archives"]}
    if len(archives) != len(saved["archives"]) or not archives:
        raise ValueError("archive plan needs distinct source archives")
    functions, inputs = read_archives(map(Path, archives), archives, stock=True)
    _, _, _, rebuilt = stock_plan(image, game, functions, inputs, index)
    if rebuilt != saved:
        raise ValueError("archive plan does not reproduce from its original archive bytes")
    lengths = function_lengths()
    for item in rebuilt["functions"]:
        function = item["function"]
        address = int(function["start"], 16)
        if lengths.get(address) != function["length"]:
            raise ValueError(f"archive plan differs from the pinned function extent at {address:#x}")
    return rebuilt


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
    parser.add_argument("--stock", action="store_true", help="scan six default archives and propagate independently verified targets")
    parser.add_argument("--plan-out", type=Path, help="write an independently linked plan (requires --stock)")
    args = parser.parse_args()
    if args.plan_out and not args.stock:
        parser.error("--plan-out requires --stock")
    if args.stock and args.symbol:
        parser.error("automatic stock plans use independently verified targets")
    if args.plan_out and args.json_out and args.plan_out.resolve() == args.json_out.resolve():
        parser.error("report and plan paths must differ")
    names = STOCK_LIBS if args.stock else ("LIBC.LIB", "LIBCMT.LIB")
    archives = args.archives or [DEFAULT_VC6 / "LIB" / name for name in names]

    try:
        sources = [args.exe, args.index, *archives]
        for output in (args.json_out, args.plan_out):
            if output and any(output.resolve() == source.resolve()
                              or (output.is_file() and source.is_file() and output.samefile(source))
                              for source in sources):
                raise ValueError(f"output would replace an input: {output}")
        explicit = {}
        for symbol, address in args.symbol:
            if symbol in explicit and explicit[symbol] != address:
                raise ValueError(f"conflicting explicit addresses for {symbol}")
            explicit[symbol] = address
        image = pe_image(args.exe)
        executable_sha256 = hashlib.sha256(image[0]).hexdigest()
        game, index = read_game(image, args.index)
        functions, archive_inputs = read_archives(archives, stock=args.stock)
        if args.stock:
            exact, matches, candidates, plan = stock_plan(image, game, functions, archive_inputs, index)
            if args.plan_out:
                with args.plan_out.open("x") as stream:
                    json.dump(plan, stream, indent=2)
                    stream.write("\n")
        else:
            exact, matches, candidates = match_functions(functions, game, explicit)
        ambiguous = sum(bool(match["ambiguity"]) for match in matches)
        if args.json_out:
            report = {"executable_sha256": executable_sha256,
                      "archives": archive_inputs, "game_function_count": len(game),
                      "archive_function_variants": len(functions), "raw_exact_locations": exact,
                      "verified_locations": len(matches), "ambiguous_locations": ambiguous,
                      "matches": matches, "unresolved_candidates": candidates}
            if args.stock:
                report["stock"] = {"planned_functions": len(plan["functions"]), "public_symbols": len(plan["symbols"]),
                                   "rounds": plan["rounds"], "revoked": plan["revoked"], "iat_symbols": len(plan["imports"])}
            args.json_out.write_text(json.dumps(report, indent=2) + "\n")
    except (OSError, ValueError, KeyError, TypeError, struct.error) as error:
        parser.exit(1, f"CRT archive matching failed: {error}\n")
    print(f"CRT archive: {len(matches)} byte-verified locations ({exact} raw exact, "
          f"{ambiguous} with ambiguous identity) across {len(game)} game functions; "
          f"{len(candidates)} locations also have unresolved candidates")
    if args.stock:
        print(f"stock plan: {len(plan['functions'])} unambiguous functions, {len(plan['symbols'])} public symbols, "
              f"{len(plan['rounds'])} proof rounds")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
