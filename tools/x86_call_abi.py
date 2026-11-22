#!/usr/bin/env python3
"""Summarize reachable x86 call-site ABI signals without emitting source or literals."""

from __future__ import annotations

import argparse
from collections import Counter, defaultdict
import json
from pathlib import Path

from decomp_fixtures import PE_HASH
from match_decomp import GAME, INDEX, SYMBOL_INDEX, file_sha256, function_lengths, pe_image, read_va

MAX_TARGETS = 8
MAX_CODE_BYTES = 65536
WINDOW = 32
GENERAL_REGISTERS = {"eax", "ebx", "ecx", "edx", "esi", "edi", "ebp"}


def decode_reachable(code, start):
    import capstone as cs
    from capstone import x86_const as x

    decoder = cs.Cs(cs.CS_ARCH_X86, cs.CS_MODE_32)
    decoder.detail = True
    pending, instructions, leaders = [start], {}, {start}
    undecodable = set()
    indirect_jumps = 0
    end = start + len(code)
    while pending:
        address = pending.pop()
        while start <= address < end and address not in instructions and address not in undecodable:
            offset = address - start
            insn = next(iter(decoder.disasm(code[offset:offset + 15], address, count=1)), None)
            if insn is None:
                undecodable.add(address)
                break
            instructions[address] = insn
            following = address + insn.size
            if insn.group(cs.CS_GRP_JUMP) or insn.id in {x.X86_INS_LOOP, x.X86_INS_LOOPE, x.X86_INS_LOOPNE}:
                target = insn.operands[0] if insn.operands else None
                if target is not None and target.type == x.X86_OP_IMM:
                    if start <= target.imm < end:
                        pending.append(target.imm)
                        leaders.add(target.imm)
                else:
                    indirect_jumps += 1
                if insn.mnemonic in {"jmp", "ljmp"}:
                    break
                leaders.add(following)
            if insn.group(cs.CS_GRP_RET) or insn.group(cs.CS_GRP_IRET) or insn.mnemonic in {"int3", "ud2", "hlt"}:
                break
            address = following
    return [instructions[va] for va in sorted(instructions)], leaders, len(undecodable), indirect_jumps


def operand_kind(operand):
    from capstone import x86_const as x

    kinds = {x.X86_OP_IMM: "immediate", x.X86_OP_REG: "register", x.X86_OP_MEM: "memory"}
    return kinds.get(operand.type, "unknown")


def destination_register(insn):
    from capstone import x86_const as x

    if not insn.operands or insn.operands[0].type != x.X86_OP_REG:
        return None
    reg = insn.operands[0].reg
    if reg not in insn.regs_access()[1]:
        return None
    return insn.reg_name(reg)


def register_source(insn):
    from capstone import x86_const as x

    if len(insn.operands) < 2:
        return "other"
    first, second = insn.operands[:2]
    if insn.mnemonic in {"xor", "sub"} and first.type == second.type == x.X86_OP_REG and first.reg == second.reg:
        return "zero"
    if insn.mnemonic in {"mov", "and"} and second.type == x.X86_OP_IMM and second.imm == 0:
        return "zero"
    if insn.mnemonic == "lea":
        return "effective_address"
    return operand_kind(second) if insn.mnemonic in {"mov", "movzx", "movsx"} else "other"


def stack_adjustment(insn, mnemonic):
    from capstone import x86_const as x

    if (insn.mnemonic == mnemonic and len(insn.operands) == 2 and insn.operands[0].type == x.X86_OP_REG
            and insn.operands[0].reg == x.X86_REG_ESP and insn.operands[1].type == x.X86_OP_IMM):
        return insn.operands[1].imm
    return None


def local_staging(instructions, index, leaders):
    import capstone as cs
    from capstone import x86_const as x

    pending = instructions[index].address
    pushes = Counter()
    registers = {}
    stack_stores = 0
    stop = max(-1, index - WINDOW - 1)
    for position in range(index - 1, stop, -1):
        insn = instructions[position]
        if (pending in leaders or insn.address + insn.size != pending or insn.group(cs.CS_GRP_CALL)
                or insn.group(cs.CS_GRP_JUMP) or insn.group(cs.CS_GRP_RET) or insn.mnemonic == "pop"
                or any(stack_adjustment(insn, mnemonic) is not None for mnemonic in ("sub", "add", "and"))):
            break
        pending = insn.address
        reg = destination_register(insn)
        if reg in {"ecx", "edx"}:
            registers.setdefault(reg, register_source(insn))
        if insn.mnemonic == "push" and insn.operands:
            pushes[operand_kind(insn.operands[0])] += 1
        if insn.mnemonic == "mov" and len(insn.operands) == 2:
            destination = insn.operands[0]
            if destination.type == x.X86_OP_MEM and destination.mem.base == x.X86_REG_ESP:
                stack_stores += 1
    return pushes, registers, stack_stores


def summarize(code, address, names=None, relocations=None, callee_limit=16):
    import capstone as cs
    from capstone import x86_const as x

    instructions, leaders, undecodable, indirect_jumps = decode_reachable(code, address)
    names = names or {}
    relocations = relocations or {}
    callees = Counter()
    staging_by_callee = defaultdict(Counter)
    calls = Counter()
    histograms = defaultdict(Counter)
    zero_writes = Counter()
    for index, insn in enumerate(instructions):
        reg = destination_register(insn)
        if reg in GENERAL_REGISTERS and register_source(insn) == "zero":
            zero_writes[reg] += 1
        if not insn.group(cs.CS_GRP_CALL):
            continue
        kind = "direct" if insn.id == x.X86_INS_CALL and insn.operands[0].type == x.X86_OP_IMM else "indirect"
        calls[kind] += 1
        if kind == "direct":
            target = insn.operands[0].imm & 0xFFFFFFFF
            label = relocations.get(insn.address + insn.imm_offset) or names.get(target) or hex(target)
        else:
            label = "<indirect>"
        callees[label] += 1
        pushes, registers, stores = local_staging(instructions, index, leaders)
        following = instructions[index + 1] if index + 1 < len(instructions) else None
        cleanup = (stack_adjustment(following, "add") if following and
                   following.address == insn.address + insn.size and following.address not in leaders else None)
        pushed = sum(pushes.values())
        ecx = registers.get("ecx", "unobserved")
        edx = registers.get("edx", "unobserved")
        cleanup = cleanup if cleanup is not None else "unobserved"
        histograms["local_push_count"][pushed] += 1
        histograms["push_operand_kinds"].update(pushes)
        histograms["local_stack_stores"][stores] += 1
        histograms["ecx_last_write"][ecx] += 1
        histograms["edx_last_write"][edx] += 1
        histograms["following_stack_add"][cleanup] += 1
        staging_by_callee[label][pushed, stores, ecx, edx, cleanup] += 1
    ranked = sorted(callees.items(), key=lambda item: (-item[1], item[0]))
    top_callees = []
    for name, count in ranked[:callee_limit]:
        (pushed, stores, ecx, edx, cleanup), occurrences = staging_by_callee[name].most_common(1)[0]
        top_callees.append({"name": name, "count": count,
                            "most_common_staging": {"local_pushes": pushed, "local_stack_stores": stores,
                                                    "ecx_last_write": ecx, "edx_last_write": edx,
                                                    "following_stack_add": cleanup, "occurrences": occurrences}})
    decoded_span = max((insn.address + insn.size - address for insn in instructions), default=0)
    return {"extent_bytes": len(code), "reachable_span_bytes": decoded_span,
            "decoded_instructions": len(instructions), "undecodable_entries": undecodable,
            "unfollowed_indirect_jumps": indirect_jumps, "calls": dict(calls), "zero_writes": dict(zero_writes),
            "top_callees": top_callees,
            "omitted_callees": max(0, len(ranked) - callee_limit),
            "staging": {name: {str(key): value for key, value in counts.items()} for name, counts in histograms.items()}}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--address", required=True, action="append", type=lambda value: int(value, 0))
    parser.add_argument("--json-out", type=Path)
    args = parser.parse_args()
    try:
        import capstone

        addresses = list(dict.fromkeys(args.address))
        if len(addresses) > MAX_TARGETS:
            raise ValueError(f"at most {MAX_TARGETS} addresses per invocation")
        if file_sha256(GAME) != PE_HASH:
            raise ValueError("game executable does not match the pinned PE")
        names = {int(key, 16): value for key, value in json.loads(SYMBOL_INDEX.read_text()).items()}
        image = pe_image(GAME)
        lengths = function_lengths()
        summaries = []
        for address in addresses:
            size = lengths.get(address)
            if size is None:
                raise ValueError(f"no contiguous indexed function at {address:#x}")
            if not 0 < size <= MAX_CODE_BYTES:
                raise ValueError(f"function extent at {address:#x} must be between 1 and {MAX_CODE_BYTES} bytes")
            summaries.append({"address": hex(address), "name": names.get(address),
                              **summarize(read_va(image, address, size), address, names)})
        report = {"schema": "pc2.x86_call_abi_summary.v1", "executable_sha256": PE_HASH,
                  "index_sha256": file_sha256(INDEX), "symbol_index_sha256": file_sha256(SYMBOL_INDEX),
                  "capstone_version": capstone.__version__,
                  "staging_window_instructions": WINDOW, "functions": summaries}
        encoded = json.dumps(report, indent=2) + "\n"
        if args.json_out:
            with args.json_out.open("x") as stream:
                stream.write(encoded)
            print(f"summarized {len(summaries)} function(s): {args.json_out}")
        else:
            print(encoded, end="")
    except (ImportError, OSError, ValueError, TypeError) as error:
        parser.exit(1, f"call ABI summary: {error}\n")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
