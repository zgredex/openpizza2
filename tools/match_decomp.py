#!/usr/bin/env python3
"""Byte-match a reconstructed C function with the shipped PC2 PE.

The original executable is MSVC 6.0 SP3 (C2.DLL 12.00.8447, linker 6.00.8447).
Compile a candidate with the supplied VC6 tree, resolve COFF relocations to the
original image addresses, and compare the resulting bytes with the PE.
"""

from __future__ import annotations

import argparse
import csv
import hashlib
import json
import os
import re
import struct
import subprocess
import sys
import tempfile
from functools import lru_cache
from pathlib import Path

from symbol_registry import REGISTRY, load_registry

ROOT = Path(__file__).resolve().parents[1]
GAME = ROOT / "game/fastfood2.exe"
INDEX = ROOT / "decompiled_fastfood2_named_v2/full_game_verification/decompile-index.json"
DEFAULT_VC6 = Path(os.environ.get("PC2_VC6", "/tmp/opencode/vc6-sp3-toolchain/VC98"))
SYMBOL_INDEX = ROOT / "decompiled_fastfood2_named_v2/full_game_symbols.json"
DATA_SYMBOLS = ROOT / "decompiled_fastfood2_named_v2/data_symbols.csv"
_SYMBOLS = None
_IMPORTS = None


def current_registry():
    return load_registry(file_sha256(GAME))


def pe_imports():
    """Map imported names to their IAT slot addresses."""
    global _IMPORTS
    if _IMPORTS is not None:
        return _IMPORTS
    data, base, sections = pe_image(GAME)
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    opt = pe + 24
    import_rva, _ = struct.unpack_from("<II", data, opt + 96 + 8)
    result = {}
    if import_rva:
        def read_rva(rva: int, size: int) -> bytes:
            for _, va, vsize, rawptr, rawsize in sections:
                if va <= rva and rva + size <= va + rawsize:
                    offset = rawptr + (rva - va)
                    return data[offset:offset + size]
            raise ValueError(f"RVA {rva:#x} is outside the PE file sections")

        cursor = import_rva
        while True:
            descriptor = read_rva(cursor, 20)
            original, _, _, name_rva, first = struct.unpack("<IIIII", descriptor)
            if not any((original, name_rva, first)):
                break
            thunk_rva = original or first
            index = 0
            while True:
                entry = struct.unpack("<I", read_rva(thunk_rva + index * 4, 4))[0]
                if entry == 0:
                    break
                if not entry & 0x80000000:
                    name = read_rva(entry + 2, 256).split(b"\0")[0].decode("latin1")
                    result.setdefault(name, set()).add(base + first + index * 4)
                index += 1
            cursor += 20
    _IMPORTS = {name: next(iter(addresses)) for name, addresses in result.items()
                if len(addresses) == 1}
    return _IMPORTS


@lru_cache(maxsize=None)
def resolve_auto_symbol(name: str):
    """Resolve only independently named targets, with their evidence source."""
    global _SYMBOLS
    registered = current_registry().get(name)
    if registered:
        return int(registered["address"], 16), "symbol_registry"
    if _SYMBOLS is None:
        raw = json.loads(SYMBOL_INDEX.read_text()) if SYMBOL_INDEX.is_file() else {}
        _SYMBOLS = {}
        for address, symbol in raw.items():
            _SYMBOLS.setdefault(symbol, set()).add(int(address, 16))
        if DATA_SYMBOLS.is_file():
            with DATA_SYMBOLS.open() as table:
                for row in csv.DictReader(table):
                    try:
                        address = int(row["address"], 16)
                    except (KeyError, TypeError, ValueError):
                        continue
                    if row.get("name"):
                        _SYMBOLS.setdefault(row["name"], set()).add(address)
    if name in _SYMBOLS:
        addresses = _SYMBOLS[name]
        return (next(iter(addresses)), "exact_symbol") if len(addresses) == 1 else (None, None)

    aliases = []
    if name.startswith("?"):
        try:
            demangled = subprocess.run(["llvm-undname", name], text=True,
                                       capture_output=True, timeout=10, check=True)
            _, _, out = demangled.stdout.strip().partition("\n")
        except (OSError, subprocess.SubprocessError):
            out = ""
        data = re.fullmatch(r"\?((?:DAT|STR)_([0-9a-fA-F]{8}))@@3.+", name)
        if data and re.search(rf"\b{data[1]}$", out):
            return int(data[2], 16), "address_label"
        function = re.search(r"\b([A-Za-z_~]\w*(?:::[A-Za-z_~]\w*)*)\(", out)
        if function and ("::" in function[1] or name.startswith(f"?{function[1]}@@Y")):
            aliases.append(function[1].replace("::", "_"))
    elif name.startswith(("_", "@")):
        aliases.append(re.sub(r"@\d+$", "", name[1:]))
    addresses = {address for alias in aliases for address in _SYMBOLS.get(alias, ())}
    if addresses:
        return (next(iter(addresses)), "decorated_alias") if len(addresses) == 1 else (None, None)
    match = re.fullmatch(r"_?(?:DAT|STR)_([0-9a-fA-F]{8})", name)
    if match:
        return int(match.group(1), 16), "address_label"
    for prefix in ("__imp__", "_imp__"):
        if name.startswith(prefix):
            imported = name[len(prefix):].lstrip("_").split("@", 1)[0]
            if imported in pe_imports():
                return pe_imports()[imported], "pe_iat"
    if name == "__except_list":
        # The VC6 EH model encodes the FS:[0] chain head as absolute zero.
        return 0, "vc6_eh_intrinsic"
    return None, None


def pe_image(path: Path):
    data = path.read_bytes()
    if data[:2] != b"MZ":
        raise ValueError("not a PE image")
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    if data[pe:pe + 4] != b"PE\0\0":
        raise ValueError("bad PE signature")
    machine, nsec, _, _, _, optsize, _ = struct.unpack_from("<HHIIIHH", data, pe + 4)
    opt = pe + 24
    magic = struct.unpack_from("<H", data, opt)[0]
    if magic != 0x10B:
        raise ValueError("not PE32")
    image_base = struct.unpack_from("<I", data, opt + 28)[0]
    sections = []
    sec = opt + optsize
    for i in range(nsec):
        name = data[sec:sec + 8].split(b"\0")[0].decode("latin1")
        vsize, va, rawsize, rawptr = struct.unpack_from("<IIII", data, sec + 8)
        sections.append((name, va, vsize, rawptr, rawsize))
        sec += 40
    return data, image_base, sections


def pe_file_span(image, address: int, size: int):
    data, base, sections = image
    for name, va, vsize, rawptr, rawsize in sections:
        start = base + va
        if size >= 0 and start <= address and address + size <= start + min(vsize or rawsize, rawsize):
            offset = rawptr + (address - start)
            if offset + size <= len(data):
                return offset, name
    raise ValueError(f"address {address:#x} is outside the PE file sections")


def read_va(image, address: int, size: int):
    offset, _ = pe_file_span(image, address, size)
    return image[0][offset:offset + size]


@lru_cache(maxsize=1)
def function_lengths():
    lengths = {}
    if INDEX.is_file():
        index = json.loads(INDEX.read_text())
        for item in index.get("functions", []):
            try:
                address = int(item.get("address", "0x0"), 16)
            except (TypeError, ValueError):
                continue
            ranges = item.get("body", {}).get("ranges", [])
            if len(ranges) == 1 and not item["body"].get("non_contiguous"):
                bounds = ranges[0]
                if isinstance(bounds, dict):
                    bounds = (bounds["start"], bounds["end"])
                start, end = (int(value, 16) if isinstance(value, str) else int(value)
                              for value in bounds)
                if start == address and end >= start:
                    lengths[address] = end - start + 1
    return lengths


def function_length(address: int):
    length = function_lengths().get(address)
    if length is None:
        raise ValueError("no function length; pass --length")
    return length


def parse_coff(path: Path):
    data = path.read_bytes()
    if data[:2] != b"L\x01":
        raise ValueError("candidate is not an i386 COFF object")
    _, nsec, _, symptr, nsyms, optsize, _ = struct.unpack_from("<HHIIIHH", data, 0)
    sections = []
    cursor = 0x14 + optsize
    for index in range(nsec):
        name = data[cursor:cursor + 8].split(b"\0")[0].decode("latin1")
        vsize, va, rawsize, rawptr, relptr, lnptr, nrel, nln, chars = struct.unpack_from(
            "<IIIIIIHHI", data, cursor + 8)
        sections.append({
            "name": name, "index": index + 1, "va": va,
            "raw": bytearray(data[rawptr:rawptr + rawsize]),
            "relptr": relptr, "nrel": nrel,
        })
        cursor += 40
    strtab = symptr + nsyms * 18
    if symptr + nsyms * 18 > len(data):
        raise ValueError("truncated COFF symbol table")
    symbols = [None] * nsyms
    index = 0
    while index < nsyms:
        entry = data[symptr + index * 18:symptr + (index + 1) * 18]
        raw_name = entry[:8]
        if raw_name[:4] == b"\0\0\0\0":
            offset = struct.unpack_from("<I", raw_name, 4)[0]
            end = data.find(b"\0", strtab + offset)
            name = data[strtab + offset:end].decode("latin1")
        else:
            name = raw_name.split(b"\0")[0].decode("latin1")
        value, section, typ, storage, naux = struct.unpack_from("<IhHBB", entry, 8)
        if index + naux >= nsyms:
            raise ValueError("truncated COFF auxiliary symbol")
        symbols[index] = {"name": name, "value": value, "section": section,
                          "type": typ, "storage": storage, "naux": naux}
        index += 1 + naux
    return data, sections, symbols


def section_relocations(object_bytes: bytes, section):
    result = []
    for index in range(section["nrel"]):
        va, symbol_index, typ = struct.unpack_from(
            "<IIH", object_bytes, section["relptr"] + index * 10)
        result.append((va, symbol_index, typ))
    return result


def relocation_value(target, addend, site, kind):
    if kind == 0x14:
        target -= site + 4
    elif kind != 0x06:
        raise ValueError(f"unsupported COFF relocation type {kind:#x}")
    return (target + addend) & 0xFFFFFFFF


def relocation_target(symbol, bases, symbols, auto_symbols):
    section = symbol["section"]
    if section > 0:
        if section in bases:
            base, origin = bases[section]
            return base + symbol["value"], origin
        return None, None
    if symbol["name"] in symbols:
        return symbols[symbol["name"]], "explicit_symbol"
    if auto_symbols:
        return resolve_auto_symbol(symbol["name"])
    return None, None


def locate_linked_section(image, section, relocations, coff_symbols, known_bases,
                          symbols, auto_symbols, anchors=(), anchor_origin="explicit_section_anchor"):
    """Locate a section uniquely using independent bytes and resolved targets."""
    raw = bytes(section["raw"])
    pattern = bytearray(raw)
    masked = set()
    for offset, index, kind in relocations:
        if offset + 4 > len(raw) or kind not in (0x06, 0x14):
            return None
        symbol = coff_symbols[index]
        addend = struct.unpack_from("<i", raw, offset)[0]
        target, _ = relocation_target(symbol, known_bases, symbols, auto_symbols)
        if kind == 0x06 and target is not None:
            struct.pack_into("<I", pattern, offset, relocation_value(target, addend, 0, kind))
        elif kind == 0x14 and symbol["section"] == section["index"]:
            value = relocation_value(symbol["value"], addend, offset, kind)
            struct.pack_into("<I", pattern, offset, value)
        else:
            masked.update(range(offset, offset + 4))
    fixed = [index for index in range(len(raw)) if index not in masked]

    def consistent(address, linked):
        if any(linked[index] != pattern[index] for index in fixed):
            return False
        bases = {**known_bases, section["index"]: (address, "section_candidate")}
        for offset, index, kind in relocations:
            symbol = coff_symbols[index]
            target, _ = relocation_target(symbol, bases, symbols, auto_symbols)
            if target is None:
                # Final verification requires this target to resolve independently.
                continue
            addend = struct.unpack_from("<i", raw, offset)[0]
            actual = struct.unpack_from("<I", linked, offset)[0]
            if actual != relocation_value(target, addend, address + offset, kind):
                return False
        return True

    if anchors:
        options = {target - value for value, target in anchors}
        if len(options) != 1:
            return None
        address = options.pop()
        try:
            linked = read_va(image, address, len(raw))
        except ValueError:
            return None
        return (address, anchor_origin) if consistent(address, linked) else None

    if len(fixed) < 8:
        return None
    # Choose the longest contiguous fixed run, then enumerate every occurrence.
    runs = []
    start = previous = fixed[0]
    for index in fixed[1:]:
        if index != previous + 1:
            runs.append((start, previous + 1))
            start = index
        previous = index
    runs.append((start, previous + 1))
    start, end = max(runs, key=lambda run: run[1] - run[0])
    needle = bytes(pattern[start:end])
    found = None
    data, image_base, sections = image
    for _, va, virtual_size, raw_ptr, raw_size in sections:
        size = min(virtual_size or raw_size, raw_size)
        body = data[raw_ptr:raw_ptr + size]
        offset = body.find(needle, start)
        while offset != -1:
            candidate = offset - start
            if candidate + len(raw) <= len(body):
                address = image_base + va + candidate
                if consistent(address, body[candidate:candidate + len(raw)]):
                    if found is not None:
                        return None
                    found = address
            offset = body.find(needle, offset + 1)
    return (found, "unique_section_signature") if found is not None else None


def compile_candidate(source: Path, vc6: Path, obj: Path, flags: list[str], *, environment=None):
    cl = vc6 / "BIN" / "CL.EXE"
    if not cl.is_file():
        raise ValueError(f"VC6 CL.EXE not found at {cl}")
    def wine_path(path: Path) -> str:
        return "Z:" + str(path).replace("/", "\\")
    command = ["wine", str(cl), "/nologo", "/c", *flags,
               f"/Fo{wine_path(obj)}", wine_path(source)]
    env = dict(os.environ if environment is None else environment, WINEDEBUG="-all")
    result = subprocess.run(command, cwd=ROOT, env=env, text=True,
                            capture_output=True, timeout=120)
    if result.returncode:
        raise ValueError(f"compile failed:\n{result.stdout}\n{result.stderr}")


def match_object(address: int, obj: Path, symbols: dict[str, int],
                 length: int | None = None, entry: str | None = None,
                 strict_symbols: bool = False, strict: bool = False,
                 auto_symbols: bool = False):
    """Compare an already compiled COFF object with the shipped code."""
    image = pe_image(GAME)
    if length is None:
        length = function_length(address)
    if length <= 0:
        raise ValueError("function extent must be positive")
    original = read_va(image, address, length)
    object_bytes, sections, coff_symbols = parse_coff(obj)
    if entry is None:
        functions = [item for item in coff_symbols
                     if item is not None and item["section"] > 0 and item["type"] == 0x20]
        if len(functions) == 1:
            entry = functions[0]["name"]
    entry_symbol = None
    if entry:
        entry_symbol = next((item for item in coff_symbols
                             if item is not None and item["name"] == entry), None)
        if entry_symbol is None or entry_symbol["section"] <= 0:
            raise ValueError(f"candidate entry symbol {entry} not found")
        primary = next((section for section in sections
                        if section["index"] == entry_symbol["section"]), None)
    else:
        primary = next((section for section in sections if section["name"] == ".text"), None)
    if primary is None:
        raise ValueError("candidate has no code section")

    raw = bytearray(primary["raw"])
    start = entry_symbol["value"] if entry_symbol is not None else 0
    if not 0 <= start < len(raw):
        raise ValueError("candidate entry starts outside its section")
    extra_len = max(0, len(raw) - (start + length))
    strict_issues = []
    relocation_issues = []
    fixups = []
    linked_spans = []
    plan_issues = []
    blocked_sections = []
    if extra_len:
        try:
            original = read_va(image, address, length + extra_len)
        except ValueError:
            strict_issues.append("candidate extent extends past the original PE section")
            extra_len = 0

    section_bases = {primary["index"]: (address - start, "candidate_entry")}
    relocations = {section["index"]: section_relocations(object_bytes, section)
                   for section in sections if section["raw"]}
    if any(index >= len(coff_symbols) or coff_symbols[index] is None
           for records in relocations.values() for _, index, _ in records):
        raise ValueError("COFF relocation targets an invalid symbol index")
    pending = {}
    registered = current_registry() if auto_symbols else {}
    registry_anchors = {}
    if strict:
        # Follow candidate section references. A relocation's original value
        # never participates in deciding where its target section is linked.
        pending = {section["index"]: section for section in sections
                   if section["index"] != primary["index"] and section["raw"]
                   and section["name"].startswith((".text$", ".xdata$"))}
        visited = {primary["index"], *pending}
        frontier = list(visited)
        while frontier:
            index = frontier.pop()
            for offset, symbol_index, _ in relocations[index]:
                if index == primary["index"] and offset < start:
                    continue
                target = coff_symbols[symbol_index]["section"]
                if target <= 0 or target in visited:
                    continue
                visited.add(target)
                if target > len(sections) or not sections[target - 1]["raw"]:
                    continue
                pending[target] = sections[target - 1]
                frontier.append(target)
        anchors = {}
        for symbol in coff_symbols:
            if symbol is None or symbol["section"] not in pending:
                continue
            index, name = symbol["section"], symbol["name"]
            if name in symbols:
                anchors.setdefault(index, []).append((symbol["value"], symbols[name]))
            elif name in registered:
                anchors.setdefault(index, []).append((symbol["value"], int(registered[name]["address"], 16)))
                registry_anchors.setdefault(index, []).append(name)
        remaining = dict(pending)
        while remaining:
            located = []
            for index, section in remaining.items():
                found = locate_linked_section(
                    image, section, relocations[index], coff_symbols, section_bases,
                    symbols, auto_symbols, anchors.get(index, ()),
                    "registry_section_anchor" if index in registry_anchors else "explicit_section_anchor")
                if found is not None:
                    section_bases[index] = found
                    located.append(index)
            if not located:
                break
            for index in located:
                del remaining[index]
        for section in remaining.values():
            strict_issues.append(
                f"unverified {section['name']} section ({len(section['raw'])} bytes)")
            index = section["index"]
            blocked_sections.append({"section": section["name"], "index": index,
                                     "symbols": sorted(symbol["name"] for symbol in coff_symbols
                                                       if symbol and symbol["section"] == index),
                                     "expected_addresses": sorted(hex(target - value)
                                                                  for value, target in anchors.get(index, ()))})

    def check_relocations(section, candidate, independently_linked, linked, base, skip_prefix=0):
        name = section["name"]
        previous_end = skip_prefix
        for offset, symbol_index, kind in sorted(relocations[section["index"]]):
            if offset + 4 <= skip_prefix:
                continue
            if offset < previous_end or offset + 4 > len(candidate) or offset - skip_prefix + 4 > len(linked):
                strict_issues.append(f"{name} relocation at {offset:#x} crosses the extent or overlaps")
                continue
            previous_end = offset + 4
            if kind not in (0x06, 0x14):
                raise ValueError(f"unsupported COFF relocation type {kind:#x}")
            symbol = coff_symbols[symbol_index]
            field_start = offset - skip_prefix
            actual, = struct.unpack_from("<I", linked, field_start)
            addend, = struct.unpack_from("<i", candidate, offset)
            site = base + offset
            target, origin = relocation_target(symbol, section_bases, symbols, auto_symbols)
            expected = None if target is None else relocation_value(target, addend, site, kind)
            fixups.append({"section": name, "section_index": section["index"], "site": hex(site),
                           "offset": hex(offset), "symbol": symbol["name"],
                           "target_section_index": symbol["section"] if symbol["section"] > 0 else None,
                           "kind": "DIR32" if kind == 0x06 else "REL32", "addend": addend,
                           "original": hex(actual), "expected": None if expected is None else hex(expected),
                           "target": None if target is None else hex(target), "origin": origin,
                           "verified": expected is not None and actual == expected})
            if origin == "symbol_registry":
                fixups[-1]["evidence"] = registered[symbol["name"]]["evidence"]
            if expected is None:
                if strict or strict_symbols:
                    strict_issues.append(
                        f"{name} relocation at {offset:#x}: unresolved symbol {symbol['name']}")
            elif expected != actual:
                relocation_issues.append(
                    f"{name} relocation at {offset:#x} resolves to {expected:#x}, original has {actual:#x}")
            if expected is not None:
                struct.pack_into("<I", independently_linked, offset, expected)
            # Only the diagnostic comparison masks linker fields with original bytes.
            candidate[offset:offset + 4] = linked[field_start:field_start + 4]

    def add_span(kind, section, address, section_offset, code, origin):
        offset, pe_section = pe_file_span(image, address, len(code))
        if code != image[0][offset:offset + len(code)]:
            plan_issues.append(f"{kind} span at {address:#x} differs independently from the PE")
            return
        sites = []
        for fixup in fixups:
            if fixup["section_index"] != section["index"]:
                continue
            site = int(fixup["site"], 16)
            if site < address + len(code) and site + 4 > address:
                if not address <= site or site + 4 > address + len(code):
                    plan_issues.append(f"fixup at {site:#x} straddles a linked span boundary")
                sites.append(fixup["site"])
        linked_spans.append({"kind": kind, "section": section["name"], "section_index": section["index"],
                             "placement": origin, "pe_section": pe_section, "start": hex(address),
                             "end_exclusive": hex(address + len(code)), "length": len(code),
                             "source_section_offset": hex(section_offset), "file_offset": hex(offset),
                             "file_end_exclusive": hex(offset + len(code)),
                             "hex_bytes": code.hex(), "sha256": hashlib.sha256(code).hexdigest(),
                             "fixup_sites": sites})

    independently_linked = bytearray(raw)
    check_relocations(primary, raw, independently_linked, original, address - start, start)
    candidate = raw[start:start + length]

    secondary = []
    for index, section in pending.items():
        if index not in section_bases:
            continue
        base, _ = section_bases[index]
        section_raw = bytearray(section["raw"])
        section_code = bytearray(section_raw)
        linked = read_va(image, base, len(section_raw))
        check_relocations(section, section_raw, section_code, linked, base)
        secondary.append((section, base, section_code, section_bases[index][1]))
        if bytes(section_raw) != linked:
            difference = next(offset for offset, (compiled, original_byte) in
                              enumerate(zip(section_raw, linked)) if compiled != original_byte)
            strict_issues.append(f"{section['name']} bytes differ at offset {difference:#x}")

    include_tail = False
    if extra_len:
        actual_extra = raw[start + length:start + length + extra_len]
        expected_extra = original[length:length + extra_len]
        padding = all(byte in (0x00, 0x90, 0xCC) for byte in actual_extra)
        tail_start = address + length
        tail_end = tail_start + extra_len
        targeted = any(
            (r["section_index"] == primary["index"] and tail_start <= int(r["site"], 16) < tail_end)
            or (r["target_section_index"] == primary["index"] and r["target"] is not None
                and tail_start <= int(r["target"], 16) + r["addend"] < tail_end)
            for r in fixups)
        include_tail = not padding or targeted
        if actual_extra != expected_extra and include_tail:
            strict_issues.append(
                f"candidate extent {len(raw)} bytes, expected {start + length}"
                f" (extra={extra_len} bytes does not match the original table/padding)")

    differences = [
        {"offset": index, "original": original[index], "candidate": candidate[index]}
        for index in range(len(candidate))
        if original[index] != candidate[index]
    ]
    matched = not differences and len(candidate) == length and not relocation_issues
    is_strict = bool(strict and matched and not strict_issues)
    if is_strict:
        link_end = start + length + (extra_len if include_tail else 0)
        if any(symbol and symbol is not entry_symbol and symbol["section"] == primary["index"]
               and symbol["type"] == 0x20 and start <= symbol["value"] < link_end
               for symbol in coff_symbols):
            plan_issues.append("primary span includes a second function symbol")
        add_span("primary", primary, address, start, independently_linked[start:start + length],
                 "candidate_entry")
        if include_tail:
            add_span("inline_tail", primary, address + length, start + length,
                     independently_linked[start + length:link_end], "contiguous_inline_tail")
        for section, base, code, origin in secondary:
            add_span("secondary", section, base, 0, code, origin)
        occupied = [(span["section_index"], int(span["start"], 16), int(span["end_exclusive"], 16))
                    for span in linked_spans]
        for fixup in fixups:
            index = fixup["target_section_index"]
            if index is not None:
                target = (int(fixup["target"], 16) + fixup["addend"]) & 0xFFFFFFFF
                if not any(index == other and first <= target < end for other, first, end in occupied):
                    plan_issues.append(f"local target {fixup['symbol']} at {target:#x} falls outside verified spans")
    return {
        "address": f"{address:#08x}",
        "entry": entry,
        "length": length,
        "candidate_length": len(candidate),
        "match": matched and (not strict_symbols or not strict_issues),
        "strict_match": is_strict,
        "strict_issues": strict_issues,
        "relocation_issues": relocation_issues,
        "relocations": fixups,
        "object_sha256": hashlib.sha256(object_bytes).hexdigest(),
        "linked_spans": linked_spans if not plan_issues else [],
        "link_plan_issues": plan_issues,
        "blocked_sections": blocked_sections,
        "linked_sections": [
            {"section": sections[index - 1]["name"], "index": index, "address": hex(base),
             "origin": origin, **({"anchors": [
                 {"symbol": name, "evidence": registered[name]["evidence"]}
                 for name in registry_anchors[index]]} if index in registry_anchors else {})}
            for index, (base, origin) in sorted(section_bases.items())
        ],
        "first_difference": differences[0] if differences else None,
        "difference_count": len(differences),
    }


@lru_cache(maxsize=None)
def file_sha256(path: Path):
    return hashlib.sha256(path.read_bytes()).hexdigest() if path.is_file() else None


def compiler_provenance(vc6):
    vc6 = vc6.resolve()
    return {"path": str(vc6), "sha256": {name: file_sha256(vc6 / "BIN" / name)
                                        for name in ("CL.EXE", "C1.DLL", "C1XX.DLL", "C2.DLL")}}


def match_provenance(source, vc6, flags, symbols, strict, auto_symbols, strict_symbols=False):
    return {
        "source": str(source),
        "source_sha256": file_sha256(source.resolve()),
        "executable_sha256": file_sha256(GAME),
        "compiler": compiler_provenance(vc6),
        "flags": flags,
        "strict_requested": strict,
        "strict_symbols": strict_symbols,
        "auto_symbols": auto_symbols,
        "symbol_registry_sha256": file_sha256(REGISTRY) if auto_symbols else None,
        "symbol_overrides": {name: hex(target) for name, target in sorted(symbols.items())},
    }


def write_function_audit(result):
    destination = os.environ.get("PC2_MATCH_AUDIT_DIR")
    if not destination:
        return
    directory = Path(destination)
    directory.mkdir(parents=True, exist_ok=True)
    recipe = {key: result.get(key) for key in
              ("address", "source", "source_sha256", "executable_sha256", "entry", "length",
               "compiler", "flags", "strict_requested", "strict_symbols", "auto_symbols",
               "symbol_registry_sha256", "symbol_overrides")}
    key = hashlib.sha256(json.dumps(recipe, sort_keys=True).encode()).hexdigest()[:16]
    temp = None
    try:
        with tempfile.NamedTemporaryFile(mode="w", dir=directory, prefix=".audit-", delete=False) as file:
            temp = Path(file.name)
            json.dump(result, file, indent=2)
            file.write("\n")
        temp.replace(directory / f"{result['address']}-{key}.json")
    finally:
        if temp is not None:
            temp.unlink(missing_ok=True)


def match(address: int, source: Path, obj: Path, vc6: Path, flags: list[str],
          symbols: dict[str, int], length: int | None, entry: str | None,
          strict_symbols: bool = False, strict: bool = False,
          auto_symbols: bool = False):
    provenance = match_provenance(source, vc6, flags, symbols, strict, auto_symbols, strict_symbols)
    try:
        compile_candidate(source, vc6, obj, flags)
        result = match_object(address, obj, symbols, length, entry, strict_symbols, strict, auto_symbols)
    except (ValueError, OSError, struct.error, subprocess.TimeoutExpired) as error:
        result = {"address": f"{address:#08x}", "length": length, "entry": entry,
                  "match": False, "strict_match": False, "error": str(error)}
    result.update(provenance)
    write_function_audit(result)
    return result


def parse_symbols(values):
    result = {}
    for value in values:
        name, address = value.split("=", 1)
        result[name] = int(address, 0)
    return result


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("address", help="original function address")
    parser.add_argument("source", type=Path, help="candidate C source")
    parser.add_argument("--length", type=lambda value: int(value, 0))
    parser.add_argument("--entry", help="candidate function symbol")
    parser.add_argument("--symbol", action="append", default=[],
                        help="external symbol NAME=0xADDR (strict check)")
    parser.add_argument("--strict-symbols", action="store_true",
                        help="require supplied symbols to match original relocations")
    parser.add_argument("--strict", action="store_true",
                        help="also require exact function extent and no unverified unwind data")
    parser.add_argument("--auto-symbols", action="store_true",
                        help="resolve undefined symbols from the shipped symbol map")
    parser.add_argument("--vc6", type=Path, default=DEFAULT_VC6)
    parser.add_argument("--flags", default="/O2")
    parser.add_argument("--json-out", type=Path)
    args = parser.parse_args()
    strict = args.strict or os.environ.get("PC2_STRICT") == "1"
    auto_symbols = args.auto_symbols or os.environ.get("PC2_AUTO_SYMBOLS") == "1"
    address = int(args.address, 0)
    with tempfile.TemporaryDirectory(prefix="pc2-match-") as directory:
        obj = Path(directory) / "candidate.obj"
        try:
            result = match(address, args.source, obj, args.vc6,
                           args.flags.split(), parse_symbols(args.symbol),
                           args.length, args.entry, args.strict_symbols, strict,
                           auto_symbols)
        except (ValueError, OSError, subprocess.TimeoutExpired) as error:
            result = {"address": f"{address:#08x}", "match": False, "error": str(error)}
    text = json.dumps(result, indent=2)
    if args.json_out:
        args.json_out.write_text(text + "\n")
    print(text)
    required = "strict_match" if strict else "match"
    return 0 if result.get(required) else 1


if __name__ == "__main__":
    raise SystemExit(main())
