#!/usr/bin/env python3
"""Generate typed submenu updaters and check them with pinned VC6."""

import argparse
from collections import defaultdict
from concurrent.futures import ThreadPoolExecutor
import json
from pathlib import Path
import re
import struct
import subprocess

from capstone import CS_GRP_CALL
from capstone import x86_const as x
from decomp_fixtures import PE_HASH
import match_decomp as match
from verify_serializer_pilot import read_arguments
from x86_call_abi import decode_reachable


TARGETS = (0x4cec60, 0x4cefe0, 0x4cfc80)
FLAGS = ['/O2', '/TP']
GROUP = 0x532330
EXPORTS = match.ROOT / 'decompiled_fastfood2_named_v2/full_game_verification/functions'
DRAFT = match.ROOT / 'reconstructed/match/batch01/part2/nonmatching/0x4cec60.c'
METHODS = {
    'IDMap_Lookup': ('LookupMap', 'Lookup', 'void *', ('int', 'int *'), 0x4017f0),
    'Game_GetCurrentPlayerCompanyName': ('GameMap', 'GetCurrentPlayerCompanyName', 'int', (), 0x482820),
    'Game_GetPlayerBySlot': ('GameMap', 'GetPlayerBySlot', 'int', ('int',), 0x488be0),
    'Game_FindCompanyIndex': ('PlayerField', 'FindCompanyIndex', 'int', ('int',), 0x4dde70),
    'Game_GetPlayerFieldC20': ('PlayerField', 'GetFieldC20', 'int', (), 0x4e2280),
    'Get_Field2C': ('PlayerField', 'GetField2C', 'int', (), 0x513fd0),
    'City_CollectBranchBuildings': ('Collector', 'CollectBranchBuildings', 'unsigned int *', (), 0x4d5b90),
    'City_CollectBusinessBuildings': ('Collector', 'CollectBusinessBuildings', 'unsigned int *', (), 0x4d5c40),
    'Window_GadgetNotify_Button_SetState': ('UI', 'Button_SetState', 'void', ('int', 'int'), 0x52ff50),
    'UI_QueueControlCommand': ('UI', 'QueueControlCommand', 'void', ('int', 'int', 'int'), 0x5301c0),
    'Array_SetField14ByKey': ('UI', 'SetField14ByKey', 'void', ('int', 'int'), 0x531470),
    'Array_ToggleObjectActive': ('UI', 'ToggleObjectActive', 'void', ('int', 'int'), 0x531620),
    'UI_EnsureChildInitialized': ('UI', 'EnsureChildInitialized', 'void', ('int',), 0x531670),
    'UI_ShowChildByID': ('UI', 'ShowChildByID', 'void', ('int',), 0x5316b0),
    'UI_SetChildVisibleByID': ('UI', 'SetChildVisibleByID', 'void', ('int', 'int'), 0x5316f0),
    'UI_RemoveObjectByKey': ('UI', 'RemoveObjectByKey', 'void', ('int',), 0x531740),
    'UI_SetChildLabelText': ('UI', 'SetChildLabelText', 'void', ('int', 'int', 'char *'), 0x531fb0),
    'UI_Group_ClearAll': ('UI', 'Group_ClearAll', 'void', (), 0x532520),
}
CALL = re.compile(r'\b(' + '|'.join([*METHODS, 'UI_Group_Create']) + r')\s*\(')
DELETE_EXPORT = re.compile(r'\(\*\*\(code \*\*\)\*(\w+)\)\(1\);')
GROUP_DECLARATION = 'extern "C" void __cdecl UI_Group_Create(void *, int, int, ...);'
MENU_SIZE_ARMS = re.compile(r'if \((iVar\d+) < 3\) \{([^{}]+)\}\s*else \{([^{}]+)\}')
KITCHEN_TAB_ARMS = re.compile(r'if \(\(iVar1 == 2\) \|\| \(iVar1 == 7\)\) \{([^{}]+)\}([^{}]+)$')


def calls(instructions):
    return [(i, insn.operands[0].imm if insn.id == x.X86_INS_CALL and insn.operands[0].type == x.X86_OP_IMM else None)
            for i, insn in enumerate(instructions) if insn.group(CS_GRP_CALL)]


def original_code(image, address):
    extent = match.function_length(address)
    instructions, _, undecodable, indirect_jump = decode_reachable(match.read_va(image, address, extent), address)
    if undecodable or indirect_jump:
        raise ValueError(f'unsupported control-flow edges at {address:#x}')
    return instructions


def group_arguments(instructions, edges):
    site = next((i for i, (_, target) in enumerate(edges) if target == GROUP), None)
    if site is None or site == 0 or edges[site - 1][1] != METHODS['UI_Group_ClearAll'][-1]:
        raise ValueError('Group_Create must follow Group_ClearAll')
    call_index = edges[site][0]
    pushes = [insn.operands[0] for insn in instructions[edges[site - 1][0] + 1:call_index] if insn.id == x.X86_INS_PUSH]
    pushes.reverse()
    if not pushes or pushes[0].type != x.X86_OP_REG or any(op.type != x.X86_OP_IMM for op in pushes[1:]):
        raise ValueError('Group_Create arguments are no longer constant after its receiver')
    group, count, *children = [op.imm for op in pushes[1:]]
    after = instructions[call_index + 1]
    if (count != len(children) or count == 0 or after.id != x.X86_INS_ADD
            or after.operands[0].type != x.X86_OP_REG or after.operands[0].reg != x.X86_REG_ESP
            or after.operands[1].type != x.X86_OP_IMM or after.operands[1].imm != 4 * len(pushes)):
        raise ValueError('Group_Create variadic count or caller cleanup differs')
    return [group, count, *children]


def virtual_delete_sites(instructions, edges):
    sites = []
    for index, target in edges:
        if target is not None:
            continue
        load, push, receiver, call = instructions[index - 3:index + 1]
        operand = call.operands[0]
        if (load.id != x.X86_INS_MOV or load.operands[0].type != x.X86_OP_REG
                or load.operands[1].type != x.X86_OP_MEM or load.operands[1].mem.disp != 0
                or push.id != x.X86_INS_PUSH or push.operands[0].type != x.X86_OP_IMM or push.operands[0].imm != 1
                or receiver.id != x.X86_INS_MOV or receiver.operands[0].type != x.X86_OP_REG
                or receiver.operands[0].reg != x.X86_REG_ECX or receiver.operands[1].type != x.X86_OP_REG
                or load.operands[1].mem.base != receiver.operands[1].reg or operand.type != x.X86_OP_MEM
                or operand.mem.base != load.operands[0].reg or operand.mem.disp != 0):
            raise ValueError(f'unmodeled indirect call at {call.address:#x}')
        sites.append(hex(call.address))
    return sites


def verify_delete_target(image):
    for name in ('City_CollectBranchBuildings', 'City_CollectBusinessBuildings'):
        if not any(target == 0x4013a0 for _, target in calls(original_code(image, METHODS[name][-1]))):
            raise ValueError(f'{name} does not call the original list constructor')
    if not any(insn.id == x.X86_INS_MOV and len(insn.operands) == 2 and insn.operands[0].type == x.X86_OP_MEM
               and insn.operands[1].type == x.X86_OP_IMM and insn.operands[1].imm == 0x55c2ec
               for insn in original_code(image, 0x4013a0)):
        raise ValueError('original list constructor no longer sets the cited vtable')
    target, = struct.unpack('<I', match.read_va(image, 0x55c2ec, 4))
    if target != 0x401420:
        raise ValueError('original list vtable slot zero differs')
    delete_calls = calls(original_code(image, target))
    if not {0x401480, 0x54dd78} <= {target for _, target in delete_calls}:
        raise ValueError('list deleting destructor no longer calls cleanup and deallocation')
    return target


def menu_run_order(body):
    # The shipped code places the group-visible path at the earlier address.
    result, count = MENU_SIZE_ARMS.subn(lambda arm: f'if ({arm[1]} >= 3) {{{arm[3]}}}\n  else {{{arm[2]}}}', body)
    if count != 1:
        raise ValueError('cannot identify the original submenu branch pair')
    return result


def updater_shape(body, name):
    if name == 'SubMenu_UpdateButtonStatesVariant2':
        # The second count is added to the first before the temporary is deleted.
        body = body.replace('iVar5 = puVar4[5];', 'iVar3 += (int)puVar4[5];').replace('0 < iVar3 + iVar5', '0 < iVar3')
        hidden = re.compile(r'if \(\(\*\(int \*\)\(DAT_0057c670 \+ 0x218\) == 0\) \|\|\s*'
                            r'\(\*\(int \*\)\(\*\(int \*\)\(DAT_0057c670 \+ 0x218\) \+ 4\) != 0x1c\)\)'
                            r' \{([^{}]+)\}')
        arm = hidden.search(body)
        if arm is None:
            raise ValueError('cannot identify the menu-mode-2 hidden child group')
        return (body[:arm.start()] + 'if (*(int *)(DAT_0057c670 + 0x218) != 0 &&\n'
                '      *(int *)(*(int *)(DAT_0057c670 + 0x218) + 4) == 0x1c) goto activeGroup;'
                + arm[1] + '\nactiveGroup:' + body[arm.end():])
    if name == 'RecipeKitchen_UpdateTabButtons':
        body = body.replace('int iVar2;', 'int iVar2;\n  volatile int companyCount;')
        body = body.replace('iVar2 = *(int *)(iVar2 + 0xc20 + iVar3 * 4);',
                            'companyCount = *(int *)(iVar2 + 0xc20 + iVar3 * 4);')
        body = body.replace(' + 0x50);', ' + 0x50) + 1;').replace('0 < iVar3 + 1', '0 < iVar3')
        return body.replace('(uint)(0 < iVar2)', '(uint)(0 < companyCount)')
    return body


def translate(pseudocode, name, grouping):
    clean = re.sub(r'//[^\n]*|/\*.*?\*/', '', pseudocode, flags=re.S).strip()
    signature = re.fullmatch(r'void\s+__cdecl\s+(\w+)\(void \*param_1\)\s*\{(.*)\}', clean, re.S)
    if not signature or signature[1] != name:
        raise ValueError('unsupported updater signature')
    body = re.sub(r'\b(?:uint|undefined4)\b', 'unsigned int', updater_shape(signature[2], name))
    body = re.sub(r'\bthis\b', 'secondaryWindow', body)
    body, delete_count = DELETE_EXPORT.subn(r'delete reinterpret_cast<CollectedList *>(\1);', body)
    if delete_count:
        body = menu_run_order(body)
    else:
        arm = KITCHEN_TAB_ARMS.search(body)
        if arm is None:
            raise ValueError('cannot identify the original kitchen show/remove branches')
        body = (body[:arm.start()] + 'if ((iVar1 != 2) && (iVar1 != 7)) {'
                + arm[2].rstrip() + '\n  }\n' + arm[1])
    owner_members, expected_calls, parts, cursor = defaultdict(list), [], [], 0
    while found := CALL.search(body, cursor):
        native = found[1]
        args, end = read_arguments(body, found.end())
        receiver, *values = args
        if native == 'UI_Group_Create':
            if receiver != 'param_1' or list(map(lambda value: int(value, 0), values)) != grouping[:len(values)]:
                raise ValueError('exported Group_Create prefix differs from the original stack')
            generated = f'UI_Group_Create(param_1, {", ".join(hex(value) for value in grouping)})'
            target = GROUP
        else:
            owner, method, result, params, target = METHODS[native]
            if len(values) != len(params):
                raise ValueError(f'wrong stack argument count for {native}')
            signature = f'{result} {method}({", ".join(params)});'
            if signature not in owner_members[owner]:
                owner_members[owner].append(signature)
            converted = ', '.join(f'({type_name})({value})' for type_name, value in zip(params, values))
            generated = f'(({owner} *)({receiver}))->{method}({converted})'
            if result == 'void *' and native == 'IDMap_Lookup':
                generated = '(int)' + generated
        parts.extend((body[cursor:found.start()], generated))
        expected_calls.append(target)
        cursor = end
    parts.append(body[cursor:])
    lines = ['extern "C" unsigned int DAT_0057c670;', GROUP_DECLARATION]
    if 'DAT_0057ca2c' in body:
        lines.append('extern "C" unsigned int DAT_0057ca2c;')
    if delete_count:
        lines.append('struct CollectedList { virtual ~CollectedList(); };')
    lines.extend(f'struct {owner} {{ {" ".join(members)} }};' for owner, members in owner_members.items())
    lines.extend((f'extern "C" void __cdecl {name}(void *param_1)', '{' + ''.join(parts) + '}'))
    return '\n'.join(lines) + '\n', expected_calls, delete_count


def adapt_draft(draft, grouping):
    draft = re.sub(r'extern "C" void __cdecl UI_Group_Create\([^;]+;', GROUP_DECLARATION, draft)
    draft = draft.replace('  virtual void f(int);', '  virtual ~VObj();')
    draft = draft.replace('((VObj *)puVar3)->f(1);', 'delete (VObj *)puVar3;')
    draft = draft.replace('  int GetField2C();', '  int GetField2C();\n  int GetFieldC20();')
    wrong = '((GameMap *)DAT_0057c670)->GetPlayerBySlot(*(int *)((char *)DAT_0057c670 + 0x200 + '
    index = '*(int *)((char *)DAT_0057c670 + 0x2ec) * 4))'
    if draft.count(wrong + index) != 1:
        raise ValueError('tracked draft player field adaptation is no longer unique')
    draft = draft.replace(wrong + index, '((PlayerField *)*(int *)((char *)DAT_0057c670 + 0x200 + '
                          + index + '->GetFieldC20()')
    draft = draft.replace('iVar4 = *(int *)((char *)puVar3 + 0x14);', 'iVar2 += *(int *)((char *)puVar3 + 0x14);')
    draft = draft.replace('0 < iVar2 + iVar4', '0 < iVar2')
    draft = re.sub(r'UI_Group_Create\(param_1,[^;]+;',
                   f'UI_Group_Create(param_1, {", ".join(hex(value) for value in grouping)});', draft)
    return menu_run_order(draft).replace('void __cdecl SubMenu_UpdateButtonStatesVariant1(',
                                         'extern "C" void __cdecl SubMenu_UpdateButtonStatesVariant1(')


def extract(address, image, names):
    source_export = EXPORTS / f'{address:#x}.c'
    name = names[hex(address)]
    instructions = original_code(image, address)
    edges = calls(instructions)
    groups = group_arguments(instructions, edges)
    direct = [target for _, target in edges if target is not None]
    original_virtual = virtual_delete_sites(instructions, edges)
    source, expected, deletes = translate(source_export.read_text(), name, groups)
    if direct != expected or len(original_virtual) != deletes:
        raise ValueError('exported direct-call order or deleting-destructor count differs from PE')
    if address == TARGETS[0]:
        source = adapt_draft(DRAFT.read_text(), groups)
    evidence = {'address': hex(address), 'name': name, 'length': match.function_length(address),
                'direct_calls': len(direct), 'delete_sites': original_virtual, 'group_arguments': groups,
                'pseudocode_sha256': match.file_sha256(source_export)}
    if deletes:
        evidence['list_deleting_destructor'] = hex(verify_delete_target(image))
    return source, direct, evidence


def check_object(address, obj, direct, evidence, source, vc6):
    data, sections, symbols = match.parse_coff(obj)
    entry_name = '_' + evidence['name']
    entry = next((symbol for symbol in symbols if symbol and symbol['name'] == entry_name), None)
    if not entry or entry['section'] <= 0:
        raise ValueError('cannot find the generated COFF entry')
    section = sections[entry['section'] - 1]
    names = {f'?{method}@{owner}@@': target for owner, method, _, _, target in METHODS.values()}
    overrides = {symbol['name']: target for symbol in symbols if symbol and symbol['section'] == 0
                 for prefix, target in names.items() if symbol['name'].startswith(prefix)}
    overrides['_UI_Group_Create'] = GROUP
    relocations = {}
    for pos, index, kind in match.section_relocations(data, section):
        if kind == 0x14 and symbols[index]['name'] in overrides:
            addend, = struct.unpack_from('<i', section['raw'], pos)
            relocations[pos - entry['value']] = overrides[symbols[index]['name']] + addend
    instructions, _, undecodable, indirect_jump = decode_reachable(section['raw'][entry['value']:], 0)
    if undecodable or indirect_jump:
        raise ValueError('unsupported emitted control-flow edges')
    candidate_calls = calls(instructions)
    candidate_direct = [relocations.get(instructions[index].address + instructions[index].imm_offset)
                        for index, target in candidate_calls if target is not None]
    candidate_deletes = virtual_delete_sites(instructions, candidate_calls)
    result = match.match_object(address, obj, overrides, evidence['length'], entry_name, True, True, True)
    result.update(match.match_provenance(source, vc6, FLAGS, overrides, True, True, True))
    result.update(ordered_direct_calls_match=candidate_direct == direct,
                  candidate_direct_calls=len(candidate_direct),
                  candidate_indirect_calls=len(candidate_deletes),
                  candidate_delete_sites=candidate_deletes)
    return result


def run(address, image, names, output, verify, vc6):
    row = {'address': hex(address), 'name': names[hex(address)], 'length': match.function_length(address)}
    try:
        text, direct, row = extract(address, image, names)
        source = output / f'{address:#x}.cpp'
        source.write_text(text)
        row.update(status='generated', source_sha256=match.file_sha256(source))
        if verify:
            obj = source.with_suffix('.obj')
            match.compile_candidate(source, vc6, obj, FLAGS)
            result = check_object(address, obj, direct, row, source, vc6)
            receipt = source.with_suffix('.match.json')
            receipt.write_text(json.dumps(result, indent=2) + '\n')
            row.update(status='strict' if result['strict_match'] else 'miss', receipt=receipt.name,
                       **{key: result.get(key) for key in ('first_difference', 'difference_count', 'ordered_direct_calls_match',
                                                           'candidate_direct_calls', 'candidate_indirect_calls')})
    except (OSError, ValueError, struct.error, subprocess.TimeoutExpired) as error:
        row.update(status='error', error=str(error))
    return row


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--verify', action='store_true')
    parser.add_argument('--jobs', type=int, choices=range(1, 4), default=1)
    parser.add_argument('--address', action='append', type=lambda value: int(value, 0), choices=TARGETS)
    args = parser.parse_args()
    if match.file_sha256(match.GAME) != PE_HASH:
        parser.exit(1, 'UI updater pilot requires the pinned executable\n')
    image = match.pe_image(match.GAME)
    names = json.loads(match.SYMBOL_INDEX.read_text())
    for native, (_, _, _, parameters, address) in METHODS.items():
        returns = {insn.operands[0].imm if insn.operands else 0 for insn in original_code(image, address) if insn.id == x.X86_INS_RET}
        if names.get(hex(address)) != native or returns != {4 * len(parameters)}:
            parser.exit(1, f'ABI verification failed for {native} at {address:#x}\n')
    output = args.out.resolve()
    output.mkdir(parents=True)
    vc6 = match.DEFAULT_VC6.resolve()
    with ThreadPoolExecutor(max_workers=args.jobs) as pool:
        rows = list(pool.map(lambda address: run(address, image, names, output, args.verify, vc6),
                             dict.fromkeys(args.address or TARGETS)))
    for row in rows:
        print(row['address'], row['status'], row['length'], row.get('error', '').splitlines()[:1])
    report = {'executable_sha256': PE_HASH, 'flags': FLAGS, 'functions': rows,
              'strict_bytes': sum(row['length'] for row in rows if row['status'] == 'strict')}
    (output / 'report.json').write_text(json.dumps(report, indent=2) + '\n')
    return int(any(row['status'] == 'error' for row in rows))


if __name__ == '__main__':
    raise SystemExit(main())
