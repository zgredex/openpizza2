#!/usr/bin/env python3
"""Byte-match a reconstructed C function with the shipped PC2 PE.

The original executable is MSVC 6.0 SP3 (C2.DLL 12.00.8447, linker 6.00.8447).
Compile a candidate with the supplied VC6 tree, resolve COFF relocations to the
original image addresses, and compare the resulting bytes with the PE.
"""

from __future__ import annotations

import argparse
import csv
import json
import os
import re
import struct
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
GAME = ROOT / "game/fastfood2.exe"
INDEX = ROOT / "decompiled_fastfood2_named_v2/full_game_verification/decompile-index.json"
DEFAULT_VC6 = Path(os.environ.get("PC2_VC6", "/tmp/opencode/vc6-sp3-toolchain/VC98"))
SYMBOL_INDEX = ROOT / "decompiled_fastfood2_named_v2/full_game_symbols.json"
DATA_SYMBOLS = ROOT / "decompiled_fastfood2_named_v2/data_symbols.csv"
_SYMBOLS = None
_ADDRESS_NAMES = None
_IMPORTS = None
_FUZZY = None


def _normalize_symbol(text: str) -> str:
    return re.sub(r"[^a-z0-9]+", "_", text.lower()).strip("_")


def _symbol_words(text: str):
    words = set()
    for part in re.split(r"[^A-Za-z0-9]+", text):
        words.update(word.lower() for word in re.findall(
            r"[A-Z]+(?=[A-Z][a-z]|$)|[A-Z]?[a-z]+|[0-9]+", part))
    return words


def pe_imports():
    """Map imported names to their IAT slot addresses."""
    global _IMPORTS
    if _IMPORTS is not None:
        return _IMPORTS
    data, base, sections = pe_image(GAME)
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    optsize = struct.unpack_from("<H", data, pe + 20)[0]
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
                    result[name] = base + first + index * 4
                index += 1
            cursor += 20
    _IMPORTS = result
    return result


def _decorated_parts(name: str):
    """Return (class, method) from a decorated or flat symbol name."""
    if name.startswith("?"):
        try:
            out = subprocess.run(["llvm-undname", name], text=True,
                                 capture_output=True, timeout=10).stdout.strip()
        except (OSError, subprocess.TimeoutExpired):
            out = ""
        if out and out != name:
            signature = out.split("(", 1)[0]
            qualified = signature.split()[-1]
            if "::" in qualified:
                cls, method = qualified.rsplit("::", 1)
                return cls.split("::")[-1], method
            return None, qualified
    stripped = name.lstrip("_@").split("@", 1)[0]
    return None, stripped


def resolve_auto_symbol(name: str, expected: int | None = None,
                        fuzzy: bool = False):
    global _SYMBOLS, _ADDRESS_NAMES, _FUZZY
    if _SYMBOLS is None:
        raw = json.loads(SYMBOL_INDEX.read_text()) if SYMBOL_INDEX.is_file() else {}
        _SYMBOLS = {name: int(address, 16) for address, name in raw.items()}
        _ADDRESS_NAMES = {address: name for name, address in _SYMBOLS.items()}
        if DATA_SYMBOLS.is_file():
            for row in csv.DictReader(DATA_SYMBOLS.open()):
                try:
                    address = int(row["address"], 16)
                except (KeyError, TypeError, ValueError):
                    continue
                symbol = row.get("name")
                if not symbol:
                    continue
                _SYMBOLS.setdefault(symbol, address)
                _ADDRESS_NAMES.setdefault(address, symbol)
    candidates = [name]
    if name.startswith("?"):
        try:
            out = subprocess.run(["llvm-undname", name], text=True,
                                 capture_output=True, timeout=10).stdout.strip()
        except (OSError, subprocess.TimeoutExpired):
            out = ""
        if out and out != name:
            signature = out.split("(", 1)[0]
            qualified = signature.split()[-1]
            candidates.append(qualified.replace("::", "_"))
    if name.startswith("_"):
        candidates.append(name[1:])
    if name.startswith("@"):
        candidates.append(name.lstrip("@").split("@", 1)[0])
    for candidate in candidates:
        if candidate in _SYMBOLS:
            return _SYMBOLS[candidate]
    match = re.search(r"(?:DAT|STR)_([0-9a-fA-F]{8})", name)
    if match:
        return int(match.group(1), 16)
    for prefix in ("__imp__", "_imp__"):
        if name.startswith(prefix):
            imported = name[len(prefix):].lstrip("_").split("@", 1)[0]
            if imported in pe_imports():
                return pe_imports()[imported]
    if name == "__except_list":
        # The VC6 EH model encodes the FS:[0] chain head as absolute zero.
        return 0
    if fuzzy and expected is not None and expected in _ADDRESS_NAMES:
        return expected
    if fuzzy:
        cls, method = _decorated_parts(name)
        tokens = {_normalize_symbol(method)}
        if method.startswith("~"):
            tokens.add(_normalize_symbol(method[1:]))
        variants = set()
        for token in tokens:
            if not token:
                continue
            variants.update((token, f"_{token}"))
        if cls:
            base = _normalize_symbol(cls)
            for token in tokens:
                variants.update((f"{base}_{token}", f"_{base}_{token}"))
            if method.startswith("~"):
                for suffix in ("destruct", "destroy", "delete",
                               "scalar_deleting_destructor"):
                    variants.update((f"{base}_{suffix}", f"_{base}_{suffix}"))
        method_words = _symbol_words(method)
        if _FUZZY is None:
            _FUZZY = [(_normalize_symbol(symbol), _symbol_words(symbol), address)
                      for symbol, address in _SYMBOLS.items()]
        addresses = set()
        for symbol_name, symbol_words, address in _FUZZY:
            if any(symbol_name == variant or symbol_name.endswith(variant)
                   for variant in variants):
                addresses.add(address)
            elif method_words and method_words <= symbol_words:
                addresses.add(address)
        if expected is not None and expected in addresses:
            return expected
        if len(addresses) == 1:
            return addresses.pop()
    return None


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


def read_va(image, address: int, size: int):
    data, base, sections = image
    for name, va, vsize, rawptr, rawsize in sections:
        start = base + va
        if start <= address and address + size <= start + min(vsize or rawsize, rawsize):
            offset = rawptr + (address - start)
            return data[offset:offset + size]
    raise ValueError(f"address {address:#x} is outside the PE file sections")


def function_length(address: int):
    if INDEX.is_file():
        index = json.loads(INDEX.read_text())
        for item in index.get("functions", []):
            try:
                item_address = int(item.get("address", "0x0"), 16)
            except (TypeError, ValueError):
                continue
            if item_address != address:
                continue
            ranges = item.get("body", {}).get("ranges", [])
            if ranges:
                start, end = (int(value, 16) if isinstance(value, str) else int(value)
                              for value in ranges[0])
                return end - start + 1
    raise ValueError("no function length; pass --length")


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
    symbols = []
    for index in range(nsyms):
        entry = data[symptr + index * 18:symptr + (index + 1) * 18]
        raw_name = entry[:8]
        if raw_name[:4] == b"\0\0\0\0":
            offset = struct.unpack_from("<I", raw_name, 4)[0]
            end = data.find(b"\0", strtab + offset)
            name = data[strtab + offset:end].decode("latin1")
        else:
            name = raw_name.split(b"\0")[0].decode("latin1")
        value, section, typ, storage, naux = struct.unpack_from("<IhHBB", entry, 8)
        symbols.append({"name": name, "value": value, "section": section,
                        "type": typ, "storage": storage, "naux": naux})
    return data, sections, symbols


def section_relocations(object_bytes: bytes, section):
    result = []
    for index in range(section["nrel"]):
        va, symbol_index, typ = struct.unpack_from(
            "<IIH", object_bytes, section["relptr"] + index * 10)
        result.append((va, symbol_index, typ))
    return result


def locate_linked_section(image, section, relocations, coff_symbols,
                          known_bases, anchors=()):
    """Find a COMDAT section's linked VA by its fixed bytes.

    Relocated fields are wildcards.  When the section is not unique by bytes,
    relocations into already-located sections and caller-supplied anchors
    disambiguate it.
    """
    raw = bytes(section["raw"])
    if len(raw) < 8 and not anchors:
        return None
    mask = bytearray(len(raw))
    for va, _, _ in relocations:
        for offset in range(4):
            if va + offset < len(raw):
                mask[va + offset] = 1
    fixed = sum(1 for value in mask if not value)
    if fixed < 8 and not anchors:
        return None

    def masked_match(candidate):
        try:
            linked = read_va(image, candidate, len(raw))
        except ValueError:
            return False
        return all(mask[index] or linked[index] == raw[index]
                   for index in range(len(raw)))

    data, base, sections = image
    matches = []
    if fixed >= 8:
        for _, section_va, _, rawptr, rawsize in sections:
            haystack = data[rawptr:rawptr + rawsize]
            first = (-(base + section_va)) % 4
            for offset in range(first, len(haystack) - len(raw) + 1, 4):
                if all(mask[index] or haystack[offset + index] == raw[index]
                       for index in range(len(raw))):
                    matches.append(base + section_va + offset)
                    if len(matches) > 256:
                        break
            if len(matches) > 256:
                break

    def consistent(candidate):
        for value, expected in anchors:
            if candidate + value != expected:
                return False
        for va, symbol_index, typ in relocations:
            symbol = coff_symbols[symbol_index]
            if symbol["section"] not in known_bases:
                continue
            try:
                field = read_va(image, candidate + va, 4)
            except ValueError:
                return False
            actual = struct.unpack("<I", field)[0]
            addend = struct.unpack_from("<i", raw, va)[0]
            target = known_bases[symbol["section"]] + symbol["value"]
            if typ == 0x06:
                expected = (target + addend) & 0xFFFFFFFF
            else:
                expected = (target + addend - (candidate + va + 4)) & 0xFFFFFFFF
            if actual != expected:
                return False
        return True

    matches = [candidate for candidate in matches if consistent(candidate)]
    if len(matches) != 1 and anchors:
        candidates = {expected - value for value, expected in anchors}
        matches = [candidate for candidate in candidates
                   if all(candidate + value == expected
                          for value, expected in anchors)
                   and masked_match(candidate) and consistent(candidate)]
    return matches[0] if len(matches) == 1 else None


def compile_candidate(source: Path, vc6: Path, obj: Path, flags: list[str]):
    cl = vc6 / "BIN" / "CL.EXE"
    if not cl.is_file():
        raise ValueError(f"VC6 CL.EXE not found at {cl}")
    def wine_path(path: Path) -> str:
        return "Z:" + str(path).replace("/", "\\")
    command = ["wine", str(cl), "/nologo", "/c", *flags,
               f"/Fo{wine_path(obj)}", wine_path(source)]
    env = dict(os.environ, WINEDEBUG="-all")
    result = subprocess.run(command, cwd=ROOT, env=env, text=True,
                            capture_output=True, timeout=120)
    if result.returncode:
        raise ValueError(f"compile failed:\n{result.stdout}\n{result.stderr}")


def match(address: int, source: Path, obj: Path, vc6: Path, flags: list[str],
          symbols: dict[str, int], length: int | None, entry: str | None,
          strict_symbols: bool = False, strict: bool = False,
          auto_symbols: bool = False):
    image = pe_image(GAME)
    if length is None:
        length = function_length(address)
    original = read_va(image, address, length)
    compile_candidate(source, vc6, obj, flags)
    _, sections, coff_symbols = parse_coff(obj)
    if entry is None:
        functions = [item for item in coff_symbols
                     if item["section"] > 0 and item["type"] == 0x20]
        if len(functions) == 1:
            entry = functions[0]["name"]
    entry_symbol = None
    if entry:
        entry_symbol = next((item for item in coff_symbols if item["name"] == entry), None)
        if entry_symbol is None or entry_symbol["section"] <= 0:
            raise ValueError(f"candidate entry symbol {entry} not found")
        text = next((section for section in sections
                     if section["index"] == entry_symbol["section"]), None)
    else:
        text = next((section for section in sections if section["name"] == ".text"), None)
    if text is None:
        raise ValueError("candidate has no code section")
    candidate = bytearray(text["raw"])
    start = entry_symbol["value"] if entry_symbol is not None else 0
    extra_len = max(0, len(candidate) - (start + length))
    if extra_len:
        try:
            original = read_va(image, address, length + extra_len)
        except ValueError:
            extra_len = 0
    strict_issues = []
    relocation_issues = []
    object_bytes = obj.read_bytes()
    section_bases = {}
    anchors_by_section = {}
    if strict:
        if entry_symbol is not None:
            section_bases[text["index"]] = address
        for va, symbol_index, typ in section_relocations(object_bytes, text):
            symbol = coff_symbols[symbol_index]
            if symbol["section"] <= 0 or va + 4 > len(original):
                continue
            addend = struct.unpack_from("<i", text["raw"], va)[0]
            actual = struct.unpack_from("<I", original, va)[0]
            if typ == 0x06:
                expected_target = (actual - addend) & 0xFFFFFFFF
            else:
                expected_target = (actual + (address + va + 4) - addend) & 0xFFFFFFFF
            anchors_by_section.setdefault(symbol["section"], []).append(
                (symbol["value"], expected_target))
        pending = [section for section in sections
                   if section["name"] == ".text$x" and section["raw"]]
        for section in pending:
            relocations = section_relocations(object_bytes, section)
            linked = locate_linked_section(
                image, section, relocations, coff_symbols, section_bases,
                anchors_by_section.get(section["index"], ()))
            if linked is not None:
                section_bases[section["index"]] = linked
        for section in sections:
            if section["name"] != ".xdata$x" or not section["raw"]:
                continue
            relocations = section_relocations(object_bytes, section)
            linked = locate_linked_section(
                image, section, relocations, coff_symbols, section_bases,
                anchors_by_section.get(section["index"], ()))
            if linked is not None:
                section_bases[section["index"]] = linked
        for section_index in anchors_by_section:
            if section_index == text["index"]:
                continue
            section = sections[section_index - 1]
            if not section["raw"] or section["index"] in section_bases:
                continue
            if not (section["name"].startswith(".rdata")
                    or section["name"].startswith(".data")):
                continue
            relocations = section_relocations(object_bytes, section)
            linked = locate_linked_section(
                image, section, relocations, coff_symbols, section_bases,
                anchors_by_section.get(section["index"], ()))
            if linked is not None:
                section_bases[section["index"]] = linked
    for offset in range(text["nrel"]):
        va, symbol_index, typ = struct.unpack_from(
            "<IIH", object_bytes, text["relptr"] + offset * 10)
        symbol = coff_symbols[symbol_index]
        if va + 4 > len(candidate) or va + 4 > len(original):
            issue = f"relocation at {va:#x} is outside the candidate/original extent"
            strict_issues.append(issue)
            continue
        original_field = original[va:va + 4]
        addend = struct.unpack_from("<i", candidate, va)[0]
        actual = struct.unpack("<I", original_field)[0]
        if typ == 0x06:
            expected_target = (actual - addend) & 0xFFFFFFFF
        else:
            expected_target = (actual + (address + va + 4) - addend) & 0xFFFFFFFF
        if symbol["section"] > 0:
            base = section_bases.get(symbol["section"])
            target = None if base is None else base + symbol["value"]
        else:
            name = symbol["name"]
            target = symbols.get(name)
            if target is None and auto_symbols:
                target = resolve_auto_symbol(name, expected=expected_target,
                                             fuzzy=strict)
        if strict_symbols or strict:
            if target is None:
                if symbol["section"] > 0:
                    issue = (f"unlocated section symbol {symbol['name']} "
                             f"in section {symbol['section']}")
                else:
                    issue = f"undefined symbol {name}; pass --symbol {name}=0xADDR"
                if strict:
                    strict_issues.append(issue)
                else:
                    raise ValueError(issue)
        if target is not None:
            if typ == 0x06:
                expected = (target + addend) & 0xFFFFFFFF
            else:
                expected = (target + addend - (address + va + 4)) & 0xFFFFFFFF
            if actual != expected:
                issue = (f"relocation at {va:#x} resolves to {expected:#x}, "
                         f"original has {actual:#x}")
                if strict:
                    strict_issues.append(issue)
                else:
                    relocation_issues.append(issue)
        if typ not in (0x06, 0x14):
            raise ValueError(f"unsupported COFF relocation type {typ:#x}")
        candidate[va:va + 4] = original_field
    if extra_len:
        actual_extra = bytes(candidate[start + length:start + length + extra_len])
        expected_extra = original[length:length + extra_len]
        padding = all(byte in (0x00, 0x90, 0xCC) for byte in actual_extra)
        if actual_extra != expected_extra and not padding:
            strict_issues.append(
                f"candidate extent {len(text['raw'])} bytes, expected {start + length}"
                f" (extra={extra_len} bytes does not match the original table/padding)")
    candidate = candidate[start:start + length]
    if strict:
        for section in sections:
            if section["index"] == text["index"] or not section["raw"]:
                continue
            is_unwind = (section["name"].startswith(".text$")
                         or section["name"] == ".xdata$x")
            if not is_unwind and section["index"] not in section_bases:
                continue
            base = section_bases.get(section["index"])
            if base is None:
                strict_issues.append(
                    f"unverified {section['name']} section "
                    f"({len(section['raw'])} bytes)")
                continue
            raw = bytearray(section["raw"])
            try:
                original_section = read_va(image, base, len(raw))
            except ValueError:
                strict_issues.append(
                    f"{section['name']} at {base:#x} is outside the PE image")
                continue
            for va, symbol_index, typ in section_relocations(object_bytes, section):
                symbol = coff_symbols[symbol_index]
                if va + 4 > len(raw) or va + 4 > len(original_section):
                    strict_issues.append(
                        f"{section['name']} relocation at {va:#x} is outside the extent")
                    continue
                field = original_section[va:va + 4]
                addend = struct.unpack_from("<i", raw, va)[0]
                actual = struct.unpack("<I", field)[0]
                if typ == 0x06:
                    expected_target = (actual - addend) & 0xFFFFFFFF
                else:
                    expected_target = (actual + (base + va + 4) - addend) & 0xFFFFFFFF
                if symbol["section"] > 0:
                    target_base = section_bases.get(symbol["section"])
                    target = (None if target_base is None
                              else target_base + symbol["value"])
                else:
                    name = symbol["name"]
                    target = symbols.get(name)
                    if target is None and auto_symbols:
                        target = resolve_auto_symbol(name, expected=expected_target,
                                                     fuzzy=True)
                if target is None:
                    strict_issues.append(
                        f"{section['name']}: unresolved symbol {symbol['name']}")
                else:
                    if typ == 0x06:
                        expected = (target + addend) & 0xFFFFFFFF
                    else:
                        expected = (target + addend - (base + va + 4)) & 0xFFFFFFFF
                    if actual != expected:
                        strict_issues.append(
                            f"{section['name']} relocation at {va:#x} resolves to "
                            f"{expected:#x}, original has {actual:#x}")
                raw[va:va + 4] = field
            if bytes(raw) != original_section:
                difference = next(index for index in range(len(raw))
                                  if raw[index] != original_section[index])
                strict_issues.append(
                    f"{section['name']} bytes differ at offset {difference:#x}")
    differences = [
        {"offset": index, "original": original[index], "candidate": candidate[index]}
        for index in range(min(len(original), len(candidate)))
        if original[index] != candidate[index]
    ]
    return {
        "address": f"{address:#08x}",
        "length": length,
        "candidate_length": len(candidate),
        "match": not differences and len(candidate) == length
                 and not relocation_issues,
        "strict_match": not differences and len(candidate) == length
                        and not strict_issues and not relocation_issues,
        "strict_issues": strict_issues,
        "relocation_issues": relocation_issues,
        "first_difference": differences[0] if differences else None,
        "difference_count": len(differences),
        "source": str(source),
    }


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
