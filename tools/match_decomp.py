#!/usr/bin/env python3
"""Byte-match a reconstructed C function with the shipped PC2 PE.

The original executable is MSVC 6.0 SP3 (C2.DLL 12.00.8447, linker 6.00.8447).
Compile a candidate with the supplied VC6 tree, resolve COFF relocations to the
original image addresses, and compare the resulting bytes with the PE.
"""

from __future__ import annotations

import argparse
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
_SYMBOLS = None


def resolve_auto_symbol(name: str):
    global _SYMBOLS
    if _SYMBOLS is None:
        raw = json.loads(SYMBOL_INDEX.read_text()) if SYMBOL_INDEX.is_file() else {}
        _SYMBOLS = {name: int(address, 16) for address, name in raw.items()}
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
    for offset in range(text["nrel"]):
        va, symbol_index, typ = struct.unpack_from(
            "<IIH", object_bytes, text["relptr"] + offset * 10)
        symbol = coff_symbols[symbol_index]
        if va + 4 > len(candidate) or va + 4 > len(original):
            issue = f"relocation at {va:#x} is outside the candidate/original extent"
            strict_issues.append(issue)
            continue
        original_field = original[va:va + 4]
        if symbol["section"] > 0:
            target = address + symbol["value"]
        else:
            name = symbol["name"]
            target = symbols.get(name)
            if target is None and auto_symbols:
                target = resolve_auto_symbol(name)
        if strict_symbols or strict:
            if target is None:
                issue = f"undefined symbol {name}; pass --symbol {name}=0xADDR"
                if strict:
                    strict_issues.append(issue)
                else:
                    raise ValueError(issue)
        if target is not None:
            addend = struct.unpack_from("<i", candidate, va)[0]
            if typ == 0x06:
                expected = (target + addend) & 0xFFFFFFFF
            else:
                expected = (target + addend - (address + va + 4)) & 0xFFFFFFFF
            actual = struct.unpack("<I", original_field)[0]
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
    for section in sections:
        if strict and section["name"].startswith(".text$") and len(section["raw"]):
            strict_issues.append(
                f"unverified unwind section {section['name']} ({len(section['raw'])} bytes)")
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
