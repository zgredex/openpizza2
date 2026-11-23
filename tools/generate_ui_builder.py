#!/usr/bin/env python3
"""Regenerate scratch C++ for the shipped straight-line UI builder family."""

import argparse
from functools import lru_cache
import json
from pathlib import Path
import re

from decomp_fixtures import PE_HASH
from match_decomp import (DEFAULT_VC6, GAME, ROOT, SYMBOL_INDEX, compile_candidate, file_sha256,
                          function_length, match_object, match_provenance, parse_coff, pe_image,
                          read_va, write_function_audit)
from x86_call_abi import decode_reachable


EXPORTS = ROOT / "decompiled_fastfood2_named_v2/full_game_verification/functions"
MAX_EXTENT = 65536
METHODS = {
    "Window_CreatePictureWindow": (0x523c90, "int", "char *, void *"),
    "UI_CreateWindow": (0x523bb0, "int", "int, int, char *, void *"),
    "UI_FindWindowByID": (0x528040, "UI *", "int, int *"),
    "UI_AddSprite": (0x531850, "void", "int, int, int, char *"),
    "UI_AddImage": (0x52f5b0, "void", "int, int, int, char *, int, int"),
    "UI_AddTextButton": (0x52f690, "int", "int, int, int, char *, char *, int, char *"),
    "Gadget_SetButtonColors": (0x52f750, "void", "int, int, int, int"),
    "Gadget_SetButtonTextLayout": (0x52f7a0, "void", "int, int, short, short, short, short"),
    "UI_AddText": (0x52f850, "int", "int, int, int, char *, char *"),
    "UI_CreateBitmapGadget": (0x531c60, "int", "int, int, int, int, int, int"),
    "UI_AddAnimation": (0x531a50, "int", "int, int, int, char *"),
    "Window_GadgetNotify_Text_SetTextColor": (0x52f910, "void", "int, int"),
    "Window_GadgetNotify_Text_SetLayout": (0x52f9d0, "void", "int, int, short, short, int"),
    "UI_AddInputField": (0x52fa40, "int", "int, int, int, char *, char *, int"),
    "Window_GadgetNotify_Input_SetNormalColor": (0x52fb40, "void", "int, unsigned int"),
    "Window_GadgetNotify_Input_SetEditingColor": (0x52fb60, "void", "int, unsigned int"),
    "Window_GadgetNotify_Input_SetFocusColor": (0x52fb80, "void", "int, unsigned int"),
    "Window_GadgetNotify_Input_SetSelectionColor": (0x52fba0, "void", "int, unsigned int"),
    "UI_CreateSlider": (0x52fc00, "int", "int, int, int, int, char *, int, int"),
    "IDMap_Lookup": (0x4017f0, "int", "int, int *"),
    "Window_GadgetNotify_Slider_SetGradientColors": (0x52fcc0, "void", "int, int *"),
}
GLOBALS = {"DAT_0057c5e0": "UI *"}
RECEIVERS = {
    "(void *)(DAT_0057c670 + 4)": ("((IDMap *)((char *)DAT_0057c670 + 4))",
                                   ("DAT_0057c670", "void *DAT_0057c670")),
    "&DAT_0057c590": ("((IDMap *)&DAT_0057c590)", ("DAT_0057c590", "char DAT_0057c590")),
}
LOCAL_GRADIENT = {"local_10": 0, "local_c": 1, "local_8": 2, "local_4": 3,
                  "local_50": 0, "local_4c": 1, "local_48": 2, "local_44": 3}
NUMBER = r"-?(?:0x[0-9a-f]+|[0-9]+)"
CALL = re.compile(r"(?:(iVar1|this)\s*=\s*(?:\(void \*\))?)?(\w+)\s*\((.*)\)\s*;")


@lru_cache(maxsize=1)
def native_symbols():
    return json.loads(SYMBOL_INDEX.read_text())


def native_methods():
    names = native_symbols()
    # Require the independently named function at each recorded ABI address.
    addresses = {address: names.get(hex(address)) for address, _, _ in METHODS.values()}
    return {addresses[address]: (name, address, return_type, parameters)
            for name, (address, return_type, parameters) in METHODS.items() if addresses[address]}


def callback_address(symbol):
    label = re.fullmatch(r"LAB_([0-9a-f]{8})", symbol)
    if label:
        return int(label[1], 16)
    addresses = [int(va, 16) for va, name in native_symbols().items() if name == symbol]
    return addresses[0] if len(addresses) == 1 else None


def extract(address, pseudocode, methods, *, null_return="window"):
    text = re.sub(r"//[^\n]*|/\*.*?\*/", "", pseudocode, flags=re.S).strip()
    signature = re.fullmatch(r"void \*\s*__cdecl\s+(\w+)\(int \*param_1\)\s*\{(.*)\}\s*", text, re.S)
    if not signature:
        raise ValueError("unsupported decompiled UI builder signature")
    name, body = signature.groups()
    body = re.sub(
        r"if \(iVar1 == 0\) \{\s*iVar1 = 0;\s*pcVar2 = (s_\w+);\s*\}\s*else \{\s*pcVar2 = (s_\w+);\s*\}\s*String_Format\(local_40,\s*\(byte \*\)pcVar2,\s*iVar1\);",
        r"if (iVar1 != 0) { String_Format(local_40, \2, iVar1); } else { String_Format(local_40, \1, iVar1); }",
        body)
    statements = [re.sub(r"\s+", " ", token.strip()) for token in re.findall(r"[^;{}]+[;{]|}", body)]
    if re.sub(r"[^;{}]+[;{]|}", "", body).strip():
        raise ValueError("unparsed pseudocode")
    declarations = {}
    used = {}
    other_used = {}
    calls = []
    externs = {}
    callbacks = {}
    lines = []
    blocks = ["function"]

    def argument(value, parameter):
        if re.fullmatch(NUMBER, value):
            # The shipped layout method copies the low words of those slots.
            if parameter == "short" and 0x8000 <= int(value, 0) <= 0xffff:
                return str(int(value, 0) - 0x10000)
            return value
        if value in {"iVar1", "(int *)0x0"}:
            return value
        if value == "local_40" and parameter == "char *":
            return value
        if value == "DAT_0057bb40" and parameter == "int":
            externs["DAT_0057bb40"] = "int DAT_0057bb40"
            return "DAT_0057bb40"
        if re.fullmatch(r"\*\(int \*\)\(DAT_0057c670 \+ 0x2f4\)", value):
            externs["DAT_0057c670"] = "void *DAT_0057c670"
            return "*(int *)((char *)DAT_0057c670 + 0x2f4)"
        if re.fullmatch(r"&local_[0-9a-f]+", value) and value[1:] in LOCAL_GRADIENT and "gradient" in declarations:
            return "gradient"
        ptr = re.fullmatch(r"(?:s_\w+_|&DAT_)([0-9a-f]{8})", value)
        load = re.fullmatch(r"(DAT_[0-9a-f]{8})", value)
        if ptr:
            symbol = f"STR_{ptr[1]}"
            externs[symbol] = f"char {symbol}[]"
            return symbol
        if load:
            externs[load[1]] = f"char *{load[1]}"
            return load[1]
        if parameter == "void *" and re.fullmatch(r"&?[A-Za-z_]\w*", value):
            symbol = value.removeprefix("&")
            target = callback_address(symbol)
            if target is not None:
                externs[symbol] = f"void {symbol}()"
                callbacks["_" + symbol] = target
                return f"(void *){symbol}"
        raise ValueError(f"unsupported argument {value!r}")

    for statement in statements:
        call = CALL.fullmatch(statement)
        assignment = re.fullmatch(rf"(local_[0-9a-f]+) = ({NUMBER});", statement)
        pointer_local = re.fullmatch(r"char \*(\w+);", statement)
        if pointer_local:
            declarations[pointer_local[1]] = f"char *{pointer_local[1]};"
            continue
        if statement in {"int iVar1;", "void *this;"}:
            symbol, declaration = ("iVar1", "int iVar1;") if statement[0] == "i" else ("window", "UI *window;")
            declarations[symbol] = declaration
            continue
        if statement.startswith("undefined4 ") and statement[11:-1] in LOCAL_GRADIENT:
            declarations["gradient"] = "int gradient[4];"
            continue
        local_buffer = re.fullmatch(r"char (local_[0-9a-f]+) \[(\d+)\];", statement)
        if local_buffer:
            declarations[local_buffer[1]] = f"char {local_buffer[1]}[{local_buffer[2]}];"
            continue
        format_call = re.fullmatch(r"String_Format\((.*)\)\s*;", statement)
        if format_call:
            values = [value.strip() for value in format_call[1].split(",")]
            if len(values) == 3 and values[0] in declarations:
                ptr = re.fullmatch(r"(?:\(byte \*\))?s_\w+_([0-9a-f]{8})", values[1])
                variable = re.fullmatch(r"\(byte \*\)(\w+)", values[1])
                externs["String_Format"] = "int String_Format(char *, const char *, ...)"
                if ptr:
                    externs[f"STR_{ptr[1]}"] = f"char STR_{ptr[1]}[]"
                    source_arg = f"STR_{ptr[1]}"
                elif variable and variable[1] in declarations:
                    source_arg = variable[1]
                else:
                    raise ValueError(f"unsupported format label {values[1]!r}")
                if 0x54dd83 not in calls:
                    calls.append(0x54dd83)
                statement = f"String_Format({values[0]}, {source_arg}, {values[2]});"
            else:
                raise ValueError(f"unsupported String_Format call {statement!r}")
        elif call and call[2] in methods:
            destination, native, arguments = call.groups()
            method, target, result, parameters = methods[native]
            receiver, *values = [value.strip() for value in arguments.split(",")]
            if receiver == "this":
                receiver = "window"
            elif receiver in GLOBALS:
                externs[receiver] = f"{GLOBALS[receiver]}{receiver}"
            elif receiver in RECEIVERS:
                receiver, (symbol, declaration) = RECEIVERS[receiver]
                externs[symbol] = declaration
            else:
                raise ValueError(f"unsupported receiver {receiver!r}")
            types = [parameter.strip() for parameter in parameters.split(",")]
            if len(values) != len(types):
                raise ValueError(f"wrong argument count for {native}")
            name_in_cpp = method.removeprefix("UI_").removeprefix("Window_Create")
            if native == "IDMap_Lookup":
                name_in_cpp = "Lookup"
                other_used[name_in_cpp] = (target, result, parameters)
            else:
                used[name_in_cpp] = (target, result, parameters)
            calls.append(target)
            prefix = f"{'window' if destination == 'this' else destination} = " if destination else ""
            rendered = ", ".join(argument(value, parameter) for value, parameter in zip(values, types))
            statement = f"{prefix}{receiver}->{name_in_cpp}({rendered});"
        elif statement == "if (this == (void *)0x0) {":
            statement = "if (window == 0) {"
        elif statement == "return (void *)0x0;":
            statement = f"return {null_return if blocks[-1] == 'if (window == 0) {' else '0'};"
        elif statement == "return this;":
            statement = "return window;"
        elif re.fullmatch(r"pcVar2 = iVar1 == 0 \? (s_\w+) : (s_\w+);", statement):
            ternary = re.fullmatch(r"pcVar2 = iVar1 == 0 \? (s_\w+) : (s_\w+);", statement)
            left = re.fullmatch(r"s_\w+_([0-9a-f]{8})", ternary[1])
            right = re.fullmatch(r"s_\w+_([0-9a-f]{8})", ternary[2])
            if not left or not right or "pcVar2" not in declarations:
                raise ValueError(f"unsupported ternary label {statement!r}")
            externs[f"STR_{left[1]}"] = f"char STR_{left[1]}[]"
            externs[f"STR_{right[1]}"] = f"char STR_{right[1]}[]"
            statement = f"pcVar2 = iVar1 == 0 ? STR_{left[1]} : STR_{right[1]};"
        elif assignment and assignment[1] in LOCAL_GRADIENT and "gradient" in declarations:
            statement = f"gradient[{LOCAL_GRADIENT[assignment[1]]}] = {assignment[2]};"
        elif statement not in {"if (iVar1 != 0) {", "else {", "*param_1 = iVar1;", "}"}:
            raise ValueError(f"unsupported UI builder statement {statement!r}")
        if statement == "}":
            if len(blocks) == 1:
                raise ValueError("unexpected closing block")
            blocks.pop()
        lines.append("    " * len(blocks) + statement)
        if statement.endswith("{"):
            blocks.append(statement)
    if len(blocks) != 1 or not calls:
        raise ValueError("unbalanced or empty UI builder body")
    forward = ["struct UI {"]
    forward.extend(f"    {result} {method}({parameters});" for method, (_, result, parameters) in used.items())
    forward.append("};")
    if other_used:
        forward.append("struct IDMap {")
        forward.extend(f"    {result} {method}({parameters});" for method, (_, result, parameters) in other_used.items())
        forward.append("};")
    forward.extend(f'extern "C" {value};' for value in externs.values())
    source = [f"/* Generated from checked-in UI builder pseudocode at {address:#x}. */", *forward, "",
              f'extern "C" UI *__cdecl {name}(int *param_1) {{',
              *("    " + declaration for declaration in declarations.values()), *lines, "}", ""]
    return {"entry": "_" + name, "source": "\n".join(source), "calls": calls, "methods": used,
            "callbacks": callbacks}


def verify_calls(image, address, length, candidate):
    import capstone as cs
    from capstone import x86_const as x

    code = read_va(image, address, length)
    instructions, _, undecodable, indirect = decode_reachable(code, address)
    calls = [insn for insn in instructions if insn.group(cs.CS_GRP_CALL)]
    external_jump = any(insn.group(cs.CS_GRP_JUMP) and insn.operands
                        and insn.operands[0].type == x.X86_OP_IMM
                        and not address <= insn.operands[0].imm < address + length
                        for insn in instructions)
    if undecodable or indirect or external_jump or any(
            insn.id != x.X86_INS_CALL or insn.operands[0].type != x.X86_OP_IMM for insn in calls):
        raise ValueError("builder has unsupported reachable control flow")
    if [insn.operands[0].imm for insn in calls] != candidate["calls"]:
        raise ValueError("pseudocode calls differ from shipped direct-call targets or order")
    cleanup = {}
    for target, _, parameters in candidate["methods"].values():
        target_instructions, _, _, _ = decode_reachable(read_va(image, target, function_length(target)), target)
        exits = {insn.operands[0].imm if insn.operands else 0 for insn in target_instructions if insn.id == x.X86_INS_RET}
        expected = 4 * len(parameters.split(","))
        if exits != {expected}:
            raise ValueError(f"callee {target:#x} cleanup {exits} differs from the {expected}-byte declared ABI")
        cleanup[hex(target)] = expected
    pushed_addresses = {operand.imm for insn in instructions if insn.id == x.X86_INS_PUSH
                        for operand in insn.operands if operand.type == x.X86_OP_IMM}
    for symbol, callback in candidate["callbacks"].items():
        if not symbol.startswith("_") or callback_address(symbol[1:]) != callback:
            raise ValueError(f"callback mapping for {symbol} is not unique in the available symbol evidence")
        if callback not in pushed_addresses:
            raise ValueError(f"callback {symbol} at {callback:#x} is not pushed by the original builder")
    return {"call_sites": len(calls), "callee_cleanup_bytes": cleanup}


def verify(address, length, source, candidate, vc6, flags):
    compile_candidate(source, vc6, source.with_suffix(".obj"), flags)
    return verify_object(address, length, source, candidate, vc6, flags)


def verify_object(address, length, source, candidate, vc6, flags):
    """Check a sibling COFF object after the caller establishes its build provenance."""
    if file_sha256(GAME) != PE_HASH:
        raise ValueError("UI builder verification requires the pinned executable")
    verify_calls(pe_image(GAME), address, length, candidate)
    obj = source.with_suffix(".obj")
    _, _, symbols = parse_coff(obj)
    overrides = candidate["callbacks"].copy()
    pending = candidate["methods"].copy()
    for symbol in symbols:
        if symbol is None or symbol["section"] != 0:
            continue
        member = re.fullmatch(r"\?(\w+)@UI@@QA[A-Z].*", symbol["name"])
        if member and member[1] in pending:
            overrides[symbol["name"]] = pending.pop(member[1])[0]
    if pending:
        raise ValueError(f"expected member relocations absent: {', '.join(pending)}")
    result = match_object(address, obj, overrides, length, candidate["entry"], True, True, True)
    result.update(match_provenance(source, vc6, flags, overrides, True, True, True))
    write_function_audit(result)
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--address", action="append", type=lambda value: int(value, 0), required=True)
    parser.add_argument("--out", type=Path, required=True, help="fresh scratch directory")
    parser.add_argument("--verify", action="store_true", help="compile once per builder and run the strict matcher")
    parser.add_argument("--vc6", type=Path, default=DEFAULT_VC6)
    parser.add_argument("--flags", default="/O2 /TP")
    parser.add_argument("--null-return", choices=("window", "0"), default="window")
    args = parser.parse_args()
    out = args.out.resolve()
    rows = []
    try:
        addresses = list(dict.fromkeys(args.address))
        if len(addresses) > 8 or file_sha256(GAME) != PE_HASH:
            raise ValueError("requires pinned executable and at most eight builders")
        out.mkdir(parents=True)
        image = pe_image(GAME)
        methods = native_methods()
        for address in addresses:
            export = EXPORTS / f"{address:#x}.c"
            length = function_length(address)
            if not 0 < length <= MAX_EXTENT:
                raise ValueError(f"unsupported builder extent {length} bytes")
            candidate = extract(address, export.read_text(), methods, null_return=args.null_return)
            evidence = verify_calls(image, address, length, candidate)
            source = out / f"{address:#x}.cpp"
            source.write_text(candidate["source"], encoding="utf-8")
            row = {"address": hex(address), "length": length, "pseudocode_sha256": file_sha256(export),
                   "source_sha256": file_sha256(source), "entry": candidate["entry"], **evidence}
            if args.verify:
                result = verify(address, length, source, candidate, args.vc6.resolve(), args.flags.split())
                source.with_suffix(".match.json").write_text(json.dumps(result, indent=2) + "\n")
                row.update({key: result.get(key) for key in ("strict_match", "first_difference", "difference_count")})
            rows.append(row)
            print(f"{row['address']}: {row['call_sites']} call sites, " +
                  (f"strict={row['strict_match']}" if args.verify else "generated"), flush=True)
    except (ImportError, OSError, ValueError) as error:
        parser.exit(1, f"UI builder: {error}\n")
    report = {"executable_sha256": PE_HASH, "builders": rows}
    (out / "report.json").write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    return int(args.verify and any(not row["strict_match"] for row in rows))


if __name__ == "__main__":
    raise SystemExit(main())
