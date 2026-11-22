#!/usr/bin/env python3
"""Diagnose relocated basic-block differences in a PC2 strict matcher receipt."""

import argparse
from collections import Counter, defaultdict, deque
from pathlib import Path
import json
import struct

from capstone import CS_GRP_BRANCH_RELATIVE, CS_GRP_CALL, CS_GRP_JUMP, CS_GRP_RET
from capstone import x86_const as x86

import match_decomp as match
from x86_call_abi import decode_reachable


def linked_entry(obj, receipt):
    data, sections, symbols = match.parse_coff(obj)
    entry = next((s for s in symbols if s and s["name"] == receipt["entry"] and s["section"] > 0), None)
    if entry is None:
        raise ValueError("receipt entry is missing from COFF")
    section = sections[entry["section"] - 1]
    offset = entry["value"]
    start = int(receipt["address"], 16)
    code = bytearray(section["raw"][offset:])
    fixups = {int(r["offset"], 16): r for r in receipt["relocations"]
              if r["section_index"] == section["index"]}
    unresolved = {}
    for pos, index, kind in match.section_relocations(data, section):
        if pos < offset:
            continue
        site = start + pos - offset
        record = fixups.get(pos)
        if record is None or record["target"] is None:
            unresolved[site] = symbols[index]["name"]
            continue
        addend, = struct.unpack_from("<i", section["raw"], pos)
        if (record["symbol"] != symbols[index]["name"] or int(record["site"], 16) != site
                or record["addend"] != addend or record["kind"] != {0x06: "DIR32", 0x14: "REL32"}.get(kind)):
            raise ValueError(f"receipt does not describe the COFF relocation at {site:#x}")
        value = match.relocation_value(int(record["target"], 16), addend, site, kind)
        struct.pack_into("<I", code, pos - offset, value)
    return code, unresolved


def blocks_for(code, start):
    instructions, leaders, undecodable, indirect = decode_reachable(code, start)
    blocks = {}
    last_end = None
    for insn in instructions:
        if insn.address in leaders or insn.address != last_end:
            block = blocks.setdefault(insn.address, [])
        block.append(insn)
        last_end = insn.address + insn.size
    return blocks, {"undecodable": undecodable, "indirect_jumps": indirect}


def direct_target(insn):
    if insn.group(CS_GRP_BRANCH_RELATIVE) and insn.operands and insn.operands[0].type == x86.X86_OP_IMM:
        return insn.operands[0].imm
    return None


def encoding(insn, addresses, unresolved):
    missing = tuple(unresolved[insn.address + i] for i in range(insn.size) if insn.address + i in unresolved)
    target = direct_target(insn)
    raw = bytes(insn.bytes)
    if target is not None:
        first = insn.imm_offset
        raw = raw[:first] + bytes(insn.imm_size) + raw[first + insn.imm_size:]
        target = addresses.get(target, target)
    return raw, target, missing


def successors(block, blocks):
    last = block[-1]
    if last.group(CS_GRP_RET) or last.mnemonic in ("int3", "ud2", "hlt"):
        return {}
    following = last.address + last.size
    edges = {}
    if last.group(CS_GRP_JUMP):
        target = direct_target(last)
        if target in blocks:
            edges["taken"] = target
    if last.mnemonic not in ("jmp", "ljmp") and following in blocks:
        edges["fallthrough"] = following
    return edges


def call_targets(block):
    return tuple(direct_target(insn) for insn in block if insn.group(CS_GRP_CALL))


def pair_blocks(original, candidate, start, unresolved):
    pairs = {}
    used = set()
    pending = deque()

    def add(left, right, evidence):
        if left in original and right in candidate and left not in pairs and right not in used:
            pairs[left] = (right, evidence)
            used.add(right)
            pending.append((left, right))

    add(start, start, "entry")
    original_local = dict.fromkeys(original, "local")
    candidate_local = dict.fromkeys(candidate, "local")
    left_keys = defaultdict(list)
    right_keys = defaultdict(list)
    for address, block in original.items():
        left_keys[tuple(encoding(i, original_local, {}) for i in block)].append(address)
    for address, block in candidate.items():
        right_keys[tuple(encoding(i, candidate_local, unresolved) for i in block)].append(address)
    for key, left in left_keys.items():
        right = right_keys.get(key, [])
        if len(left) == len(right) == 1:
            add(left[0], right[0], "unique_encoding")
    while pending:
        left, right = pending.popleft()
        a, b = original[left], candidate[right]
        if a[-1].mnemonic == b[-1].mnemonic:
            a_edges, b_edges = successors(a, original), successors(b, candidate)
            for role in sorted(a_edges.keys() & b_edges.keys()):
                next_a, next_b = a_edges[role], b_edges[role]
                if call_targets(original[next_a]) == call_targets(candidate[next_b]):
                    add(next_a, next_b, f"paired_{role}")
    return pairs


def describe(insn):
    if insn is None:
        return None
    return {"address": hex(insn.address), "hex": bytes(insn.bytes).hex(),
            "instruction": f"{insn.mnemonic} {insn.op_str}".strip()}


def classify(left, right, a, b):
    if not left or not right:
        return "instruction_count"
    if a[0][2] or b[0][2]:
        return "unresolved_relocation"
    if a[0] in b[1:7] and b[0] in a[1:7]:
        return "instruction_order"
    if left.group(CS_GRP_JUMP) or right.group(CS_GRP_JUMP):
        return "branch_layout"
    if left.group(CS_GRP_CALL) or right.group(CS_GRP_CALL):
        return "call_sequence"
    if left.mnemonic == right.mnemonic:
        for l, r in zip(left.operands, right.operands):
            if l.type == r.type == x86.X86_OP_MEM and l.mem.base == r.mem.base:
                if l.size != r.size and l.mem.disp == r.mem.disp and l.mem.index == r.mem.index:
                    return "memory_width"
                if l.mem.base in (x86.X86_REG_ESP, x86.X86_REG_EBP) and l.mem.disp != r.mem.disp:
                    return "stack_slot"
        return "operand_or_encoding"
    return "instruction_shape"


def compare(obj, receipt):
    if receipt["object_sha256"] != match.file_sha256(obj):
        raise ValueError("object hash does not match the receipt")
    if receipt["executable_sha256"] != match.file_sha256(match.GAME):
        raise ValueError("original PE hash does not match the receipt")
    start = int(receipt["address"], 16)
    shipped_code = match.read_va(match.pe_image(match.GAME), start, receipt["length"])
    linked, unresolved = linked_entry(obj, receipt)
    original, original_decode = blocks_for(shipped_code, start)
    candidate, candidate_decode = blocks_for(linked, start)
    pairs = pair_blocks(original, candidate, start, unresolved)
    original_addresses = {address: ("original", address) for address in original}
    candidate_addresses = {address: ("unpaired", address) for address in candidate}
    candidate_addresses.update({right: ("original", left) for left, (right, _) in pairs.items()})
    rows = []
    for left, (right, evidence) in sorted(pairs.items()):
        a, b = original[left], candidate[right]
        original_keys = [encoding(i, original_addresses, {}) for i in a]
        candidate_keys = [encoding(i, candidate_addresses, unresolved) for i in b]
        prefix = next((i for i, (k, v) in enumerate(zip(original_keys, candidate_keys)) if k != v),
                      min(len(a), len(b)))
        difference = None
        if prefix < max(len(a), len(b)):
            first_a = a[prefix] if prefix < len(a) else None
            first_b = b[prefix] if prefix < len(b) else None
            difference = {"kind": classify(first_a, first_b, original_keys[prefix:], candidate_keys[prefix:]),
                          "original": describe(first_a), "candidate": describe(first_b)}
        rows.append({"original": hex(left), "candidate": hex(right), "pairing": evidence,
                     "matching_prefix_instructions": prefix, "first_difference": difference})
    kinds = Counter(row["first_difference"]["kind"] for row in rows if row["first_difference"])
    return {
        "address": hex(start),
        "object_sha256": receipt["object_sha256"],
        "executable_sha256": receipt["executable_sha256"],
        "strict_match_from_receipt": receipt["strict_match"],
        "original_decode": original_decode,
        "candidate_decode": candidate_decode,
        "paired_blocks": len(rows),
        "equal_paired_blocks": len(rows) - sum(kinds.values()),
        "difference_kinds": dict(kinds),
        "unpaired_original": [hex(a) for a in sorted(original.keys() - pairs.keys())],
        "unpaired_candidate": [hex(a) for a in sorted(candidate.keys() - {r for r, _ in pairs.values()})],
        "unresolved_relocations": {hex(a): symbol for a, symbol in sorted(unresolved.items())},
        "blocks": rows,
    }


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--object", type=Path, required=True)
    parser.add_argument("--receipt", type=Path, required=True)
    parser.add_argument("--out", type=Path, required=True)
    args = parser.parse_args()
    try:
        report = compare(args.object, json.loads(args.receipt.read_text()))
        args.out.write_text(json.dumps(report, indent=2) + "\n")
    except (OSError, KeyError, ValueError, struct.error) as error:
        parser.exit(1, f"block comparison: {error}\n")
    print(f"{report['address']}: {report['equal_paired_blocks']}/{report['paired_blocks']} equal paired blocks, "
          f"{len(report['unpaired_original'])}/{len(report['unpaired_candidate'])} unpaired")


if __name__ == "__main__":
    main()
