#!/usr/bin/env python3
"""Compare VC6 x86 C++ unwind graphs and cleanup routines against FastFood2."""

import argparse
from collections import Counter
import json
from pathlib import Path
import struct

from capstone import CS_ARCH_X86, CS_MODE_32, Cs, x86_const as x86

import match_decomp as match


FRAME_HANDLER = 0x54e5f6
MAGIC = 0x19930520


class Coff:
    def __init__(self, path, overrides):
        data, self.sections, symbols = match.parse_coff(path)
        self.symbols = {symbol["name"]: symbol for symbol in symbols if symbol}
        self.relocations = {
            (section["index"], offset): (symbols[index], kind)
            for section in self.sections
            for offset, index, kind in match.section_relocations(data, section)
        }
        self.overrides = overrides

    def read(self, location, size):
        section, offset = location
        return self.sections[section - 1]["raw"][offset:offset + size]

    def resolve(self, location, offset, kind):
        section, start = location
        symbol, actual = self.relocations.get((section, start + offset), (None, None))
        addend, = struct.unpack("<i", self.read((section, start + offset), 4))
        if symbol is None:
            if kind == 0x14:
                return section, start + offset + 4 + addend
            if addend == 0:
                return None
        elif actual == kind:
            if symbol["section"] > 0:
                return symbol["section"], symbol["value"] + addend
            address = self.overrides.get(symbol["name"])
            if address is None:
                address, _ = match.resolve_auto_symbol(symbol["name"])
            if address is not None:
                return address + addend
        raise ValueError(f"cannot resolve COFF operand at section {section}+{start + offset:#x}")


def original_operand(read, location, offset, kind):
    value, = struct.unpack("<I", read(location + offset, 4))
    if kind == 0x14:
        return (location + offset + 4 + value) & 0xffffffff
    return value or None


def handler_field_offset(prefix):
    marker = prefix.find(b"\x6a\xff\x68")
    if marker < 0 or prefix[marker + 7:marker + 13] != b"\x64\xa1\0\0\0\0":
        raise ValueError("entry does not establish the supported VC6 EH frame")
    return marker + 3


def handler_from_prologue(read, resolve, entry):
    return resolve(entry, handler_field_offset(read(entry, 32)), 0x06)


def cleanup_signature(disasm, read, resolve, location):
    if location is None:
        return None
    transfers = []
    frame_offsets = []
    for insn in disasm.disasm(bytes(read(location, 64)), 0):
        frame_offsets.extend(op.mem.disp for op in insn.operands
                             if op.type == x86.X86_OP_MEM and op.mem.base == x86.X86_REG_EBP)
        if insn.id in (x86.X86_INS_CALL, x86.X86_INS_JMP):
            if insn.imm_size != 4 or insn.operands[0].type != x86.X86_OP_IMM:
                break
            target = resolve(location, insn.address + insn.imm_offset, 0x14)
            transfers.append({"instruction": insn.mnemonic, "target": target})
        elif insn.group(x86.X86_GRP_JUMP):
            break
        if insn.id in (x86.X86_INS_JMP, x86.X86_INS_RET):
            return {"transfers": transfers, "frame_offsets": frame_offsets}
    raise ValueError(f"unsupported unwind cleanup at {location}")


def read_unwind(read, resolve, handler):
    if handler is None or read(handler, 10)[0:6:5] != b"\xb8\xe9":
        raise ValueError("unsupported VC6 frame handler stub")
    if resolve(handler, 6, 0x14) != FRAME_HANDLER:
        raise ValueError("handler does not jump to the pinned __CxxFrameHandler")
    info = resolve(handler, 1, 0x06)
    if info is None:
        raise ValueError("frame handler is missing FuncInfo")
    magic, count, _, *tables = struct.unpack("<8I", read(info, 32))
    if magic != MAGIC or not 0 < count <= 4096 or any(tables):
        raise ValueError("expected VC6 FuncInfo containing only an unwind map")
    unwind = resolve(info, 8, 0x06)
    if unwind is None:
        raise ValueError("FuncInfo is missing an unwind map")
    map_bytes = read(unwind, count * 8)
    if len(map_bytes) != count * 8:
        raise ValueError("truncated unwind map")
    disasm = Cs(CS_ARCH_X86, CS_MODE_32)
    disasm.detail = True
    states = []
    for index, (previous, _) in enumerate(struct.iter_unpack("<iI", map_bytes)):
        if not -1 <= previous < index:
            raise ValueError(f"invalid predecessor {previous} for state {index}")
        location = resolve(unwind, index * 8 + 4, 0x06)
        states.append({"previous": previous, "cleanup": cleanup_signature(disasm, read, resolve, location)})
    return {"handler": handler, "func_info": info, "states": states}


def compare(address, obj, entry, symbols):
    image = match.pe_image(match.GAME)
    read = lambda location, size: match.read_va(image, location, size)
    resolve = lambda location, offset, kind: original_operand(read, location, offset, kind)
    original = read_unwind(read, resolve, handler_from_prologue(read, resolve, address))
    coff = Coff(obj, {"___CxxFrameHandler": FRAME_HANDLER, **symbols})
    symbol = coff.symbols.get(entry)
    if symbol is None or symbol["section"] <= 0:
        raise ValueError(f"missing COFF entry {entry}")
    handler = handler_from_prologue(coff.read, coff.resolve, (symbol["section"], symbol["value"]))
    candidate = read_unwind(coff.read, coff.resolve, handler)
    original_states = original["states"]
    candidate_states = candidate["states"]
    differences = Counter()
    for shipped, emitted in zip(original_states, candidate_states):
        if shipped["previous"] != emitted["previous"]:
            differences["predecessor"] += 1
        if (shipped["cleanup"] is None) != (emitted["cleanup"] is None):
            differences["cleanup_presence"] += 1
        if shipped["cleanup"] and emitted["cleanup"]:
            for field in ("transfers", "frame_offsets"):
                if shipped["cleanup"][field] != emitted["cleanup"][field]:
                    differences[field] += 1
    return {
        "original": original,
        "candidate": candidate,
        "state_count_delta": len(candidate_states) - len(original_states),
        "difference_counts": dict(differences),
        "strict_byte_comparison": False,
    }


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--address", type=lambda value: int(value, 0), required=True)
    parser.add_argument("--object", type=Path, required=True)
    parser.add_argument("--entry", required=True)
    parser.add_argument("--symbol", action="append", default=[], help="COFF name=original address")
    parser.add_argument("--out", type=Path, required=True)
    args = parser.parse_args()
    try:
        report = compare(args.address, args.object, args.entry, match.parse_symbols(args.symbol))
        args.out.write_text(json.dumps(report, indent=2) + "\n")
        print(f"Unwind states: {len(report['original']['states'])} original, "
              f"{len(report['candidate']['states'])} emitted. Differences: {report['difference_counts']}")
    except (OSError, ValueError, struct.error) as error:
        parser.exit(1, f"VC6 unwind: {error}\n")
    return int(bool(report["state_count_delta"] or report["difference_counts"]))


if __name__ == "__main__":
    raise SystemExit(main())
