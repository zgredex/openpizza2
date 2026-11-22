#!/usr/bin/env python3
"""Compile reconstructed PC2 functions and compare them with the shipped PE."""

import argparse
import hashlib
import json
import shutil
import struct
import subprocess
import sys
import tempfile
from pathlib import Path

from decomp_fixtures import ABI_SOURCE, GAME, PE_HASH, ROOT, SCRATCH, routines, words


STACK = 0x00200000
STACK_SIZE = 0x10000
ENTRY_SP = STACK + STACK_SIZE - 0x104
RETURN = 0x00100000
RETURN_VALUE = RETURN + 0x100
PAGE = 0x1000
LIMIT = 10_000
TIMEOUT_US = 250_000


def sha256(data):
    return hashlib.sha256(data).hexdigest()


def run_command(argv, environment=None):
    process = subprocess.run(argv, cwd=ROOT, text=True, capture_output=True, timeout=30, env=environment)
    if process.returncode:
        raise ValueError(f"{' '.join(map(str, argv))}\n{process.stderr.strip()}")
    return process.stdout


def compile_candidate(routine, source, directory, cc, ld, *, environment=None, language="c"):
    if language == "c++":
        if routine.adapter:
            raise ValueError("C ABI adapters are unavailable for C++ candidates")
        language_flags = ["-x", "c++", "-std=c++17", "-fno-exceptions", "-fno-rtti",
                          "-D__fastcall=__attribute__((fastcall))"]
    else:
        language_flags = ["-std=c11", "-Werror=implicit-function-declaration"]
    files = [source]
    if routine.adapter:
        files.append(ROOT / ABI_SOURCE)
    objects = []
    for index, path in enumerate(files):
        obj = directory / f"{index}.o"
        run_command([cc, "-m32", "-march=i386", *language_flags, "-O2", "-ffreestanding",
                     "-fno-pic", "-fno-pie", "-fno-stack-protector", "-fwrapv",
                     "-fexcess-precision=standard", "-ffunction-sections", "-fdata-sections",
                     "-I", str((ROOT / routine.source).parent),
                     "-c", str(path), "-o", str(obj)], environment)
        objects.append(str(obj))
    elf = directory / "candidate.elf"
    symbols = [f"--defsym={name}={address:#x}" for name, address in routine.symbols.items()]
    run_command([ld, "-m", "elf_i386", "-Ttext=0x01001000", "--gc-sections", "--fatal-warnings",
                 f"--entry={routine.entry}", *symbols, *objects, "-o", str(elf)], environment)
    return elf.read_bytes()


def parse_elf(data):
    if data[:7] != b"\x7fELF\x01\x01\x01" or struct.unpack_from("<HH", data, 16) != (2, 3):
        raise ValueError("candidate is not an i386 ELF executable")
    entry, phoff = struct.unpack_from("<II", data, 24)
    phsize, count = struct.unpack_from("<HH", data, 42)
    segments = []
    for index in range(count):
        kind, offset, va, _, size, memory, flags, _ = struct.unpack_from(
            "<8I", data, phoff + phsize * index)
        if kind == 1 and memory:
            if offset + size > len(data) or size > memory:
                raise ValueError("truncated candidate load segment")
            segments.append((va, data[offset:offset + size], memory, flags))
    if not any(va <= entry < va + size and flags & 1 for va, _, size, flags in segments):
        raise ValueError("candidate entry is outside executable segments")
    return entry, segments


def load_original():
    import pefile

    data = GAME.read_bytes()
    digest = sha256(data)
    if digest != PE_HASH:
        raise ValueError(f"unsupported executable hash {digest}; expected {PE_HASH}")
    return pefile.PE(data=data, fast_load=True)


def run_case(pe, routine, case, candidate=None, *, patches=(), cpuid_edx=None,
             read_ranges=None, original_extent=None):
    import unicorn as u
    from unicorn import x86_const as x

    uc = u.Uc(u.UC_ARCH_X86, u.UC_MODE_32)
    header = pe.OPTIONAL_HEADER
    uc.mem_map(header.ImageBase, header.SizeOfImage, u.UC_PROT_ALL)
    uc.mem_write(header.ImageBase, pe.get_memory_mapped_image())
    for address, data in patches:
        uc.mem_write(address, data)
    uc.mem_map(STACK, STACK_SIZE, u.UC_PROT_READ | u.UC_PROT_WRITE)
    uc.mem_map(SCRATCH, 0x10000, u.UC_PROT_READ | u.UC_PROT_WRITE)
    uc.mem_map(RETURN, PAGE, u.UC_PROT_ALL)
    if candidate is None:
        entry = routine.address
    else:
        entry, segments = candidate
        for address, data, size, flags in segments:
            start = address & -PAGE
            end = (address + size + PAGE - 1) & -PAGE
            permissions = ((u.UC_PROT_READ if flags & 4 else 0)
                           | (u.UC_PROT_WRITE if flags & 2 else 0)
                           | (u.UC_PROT_EXEC if flags & 1 else 0))
            uc.mem_map(start, end - start, permissions)
            if data:
                uc.mem_write(address, data)
    stack = words(RETURN, *case.args)
    uc.mem_write(ENTRY_SP, stack)
    for address, data in case.memory:
        uc.mem_write(address, data)
    uc.reg_write(x.UC_X86_REG_ESP, ENTRY_SP)
    uc.reg_write(x.UC_X86_REG_ECX, case.ecx)
    uc.reg_write(x.UC_X86_REG_FPCW, 0x037f)
    saved_registers = (x.UC_X86_REG_EBX, x.UC_X86_REG_ESI, x.UC_X86_REG_EDI, x.UC_X86_REG_EBP)
    saved_values = [0x12340000 + register for register in saved_registers]
    for register, value in zip(saved_registers, saved_values):
        uc.reg_write(register, value)

    calls = []
    unexpected_writes = []
    unexpected_reads = []
    unexpected_original_execution = []

    def watch_write(_uc, _access, address, size, _value, _data):
        end = address + size
        # Permit local stack traffic and the function's own argument slots.
        if STACK <= address and end <= ENTRY_SP + len(stack):
            return
        if not any(start <= address and end <= start + length for start, length in routine.writable):
            unexpected_writes.append(f"{address:#010x}+{size}")
            uc.emu_stop()

    def watch_read(_uc, _access, address, size, _value, _data):
        end = address + size
        if STACK <= address and end <= ENTRY_SP + len(stack):
            return
        if not any(start <= address and end <= start + length for start, length in read_ranges):
            unexpected_reads.append(f"{address:#010x}+{size}")
            uc.emu_stop()

    def watch_call(engine, address, _size, arg_count):
        sp = engine.reg_read(x.UC_X86_REG_ESP)
        args = engine.mem_read(sp + 4, 4 * arg_count) if arg_count else b""
        calls.append({"address": f"{address:#010x}", "ecx": f"{engine.reg_read(x.UC_X86_REG_ECX):#010x}",
                      "arguments": [f"{a:#010x}" for (a,) in struct.iter_unpack("<I", args)]})

    def guard_original_code(engine, address, _size, _data):
        if candidate is None and routine.address <= address < routine.address + original_extent:
            return
        if not any(start <= address <= end for start, (_, end) in routine.calls.items()):
            unexpected_original_execution.append(address)
            engine.emu_stop()

    write_hook = uc.hook_add(u.UC_HOOK_MEM_WRITE, watch_write)
    if read_ranges is not None:
        uc.hook_add(u.UC_HOOK_MEM_READ, watch_read)
    if cpuid_edx is not None:
        def captured_cpuid(engine, _data):
            engine.reg_write(x.UC_X86_REG_EDX, cpuid_edx)
            return 1

        uc.hook_add(u.UC_HOOK_INSN, captured_cpuid, None, 1, 0, x.UC_X86_INS_CPUID)
    if candidate is not None or original_extent is not None:
        uc.hook_add(u.UC_HOOK_CODE, guard_original_code, begin=header.ImageBase,
                    end=header.ImageBase + header.SizeOfImage - 1)
    for address, (count, _) in routine.calls.items():
        uc.hook_add(u.UC_HOOK_CODE, watch_call, count, begin=address, end=address)
    try:
        uc.emu_start(entry, RETURN, timeout=TIMEOUT_US, count=LIMIT)
    except u.UcError as error:
        raise ValueError(f"{error} at {uc.reg_read(x.UC_X86_REG_EIP):#010x}") from error
    if unexpected_writes:
        raise ValueError(f"unexpected memory write at {unexpected_writes[0]}")
    if unexpected_reads:
        raise ValueError(f"unexpected memory read at {unexpected_reads[0]}")
    if unexpected_original_execution:
        raise ValueError(f"candidate entered undeclared original code at {unexpected_original_execution[0]:#010x}")
    if uc.reg_read(x.UC_X86_REG_EIP) != RETURN:
        raise ValueError("did not return within the instruction/time budget")
    if uc.reg_read(x.UC_X86_REG_ESP) != ENTRY_SP + 4 + routine.stack_cleanup:
        raise ValueError("stack cleanup disagrees with the declared ABI")
    if [uc.reg_read(register) for register in saved_registers] != saved_values:
        raise ValueError("callee-saved registers were clobbered")
    if uc.mem_read(ENTRY_SP, 4) != words(RETURN):
        raise ValueError("return address was modified")

    result = {}
    if routine.result == "eax":
        eax = uc.reg_read(x.UC_X86_REG_EAX)
        if case.expected_eax is not None and eax != case.expected_eax:
            raise ValueError(f"EAX {eax} disagrees with reviewed fixture value {case.expected_eax}")
        result["EAX"] = f"{eax:#010x}"
    elif routine.result == "x87":
        uc.hook_del(write_hook)
        # Store the x87 return value in memory as 80 bits without rounding.
        instruction = b"\xdb\x3d" + words(RETURN_VALUE)
        uc.mem_write(RETURN, instruction)
        uc.emu_start(RETURN, RETURN + len(instruction), count=1)
        result["ST0"] = bytes(uc.mem_read(RETURN_VALUE, 10)).hex()
    for name, address, size in routine.observations:
        result[name] = bytes(uc.mem_read(address, size)).hex()
    if routine.calls:
        result["calls"] = calls
    return result


def verify_routine(pe, routine, source, cc, ld):
    result = {"address": f"{routine.address:#08x}", "name": routine.name,
              "source": str(source), "source_sha256": sha256(source.read_bytes()),
              "compiled": False, "behavior_verified": False, "byte_matched": None,
              "cases": len(routine.cases), "passed": 0, "first_difference": None}
    try:
        with tempfile.TemporaryDirectory(prefix="pc2-decomp-") as directory:
            elf = compile_candidate(routine, source, Path(directory), cc, ld)
        candidate = parse_elf(elf)
    except (ValueError, subprocess.TimeoutExpired, struct.error) as error:
        result["first_difference"] = {"stage": "compile", "message": str(error)}
        return result
    result["compiled"] = True
    result["compiled_sha256"] = sha256(elf)
    for case in routine.cases:
        try:
            original = run_case(pe, routine, case)
        except ValueError as error:
            result["first_difference"] = {"case": case.name, "stage": "original", "message": str(error)}
            break
        try:
            rebuilt = run_case(pe, routine, case, candidate)
        except ValueError as error:
            result["first_difference"] = {"case": case.name, "stage": "candidate", "message": str(error)}
            break
        for key in original:
            if original[key] != rebuilt[key]:
                result["first_difference"] = {"case": case.name, "field": key,
                                              "original": original[key], "candidate": rebuilt[key]}
                break
        if result["first_difference"]:
            break
        result["passed"] += 1
    result["behavior_verified"] = result["passed"] == result["cases"]
    return result


def write_json(data, output):
    text = json.dumps(data, indent=2) + "\n"
    if output is None:
        print(text, end="")
    else:
        output.write_text(text, encoding="utf-8")


def selected_routines(args):
    known = {routine.address: routine for routine in routines()}
    unknown = sorted(set(args.address) - known.keys())
    if unknown:
        raise ValueError("no reviewed fixture for " + ", ".join(hex(address) for address in unknown))
    return [known[address] for address in dict.fromkeys(args.address)] if args.address else list(known.values())


def show_queue(report_path):
    results = {}
    if report_path:
        report = json.loads(report_path.read_text(encoding="utf-8"))
        if report.get("schema") != "pc2.decomp_verification.v1" or report.get("target_sha256") != PE_HASH:
            raise ValueError("report does not match the target executable")
        results = {row["address"]: row for row in report["routines"]}
    for routine in routines():
        address = f"{routine.address:#08x}"
        state = "registered"
        result = results.get(address)
        if result:
            source = (ROOT / routine.source).resolve()
            if Path(result["source"]) != source or result["source_sha256"] != sha256(source.read_bytes()):
                state = "recheck"
            elif result["behavior_verified"]:
                state = f"behavior {result['passed']}/{result['cases']}"
            else:
                state = "compiled, differed" if result["compiled"] else "build failed"
        print(f"{address}  {routine.source_group:<7}  {routine.name:<28}  {state:<18}  {routine.source}")


def self_test(pe, cc, ld):
    routine = routines()[0]
    with tempfile.TemporaryDirectory(prefix="pc2-decomp-mutation-") as directory:
        source = Path(directory) / "bad_clamp.c"
        source.write_text("void clamp_0_100(int *value) {\n"
                          "    if (*value > 100) *value = 99;\n"
                          "    if (*value < 0) *value = 0;\n}\n", encoding="utf-8")
        result = verify_routine(pe, routine, source, cc, ld)
        difference = result["first_difference"] or {}
        if difference.get("case") != "value_101_5" or difference.get("field") != "value_and_guards":
            raise ValueError(f"mutation did not fail at the expected boundary: {difference}")
        print(f"Rejected mutated clamp: {difference}")

        source.write_text("void clamp_0_100(int *value) {\n"
                          "    typedef void (__attribute__((stdcall)) *Clamp)(int *);\n"
                          "    ((Clamp)0x477100)(value);\n}\n", encoding="utf-8")
        result = verify_routine(pe, routine, source, cc, ld)
        difference = result["first_difference"] or {}
        if difference.get("message") != "candidate entered undeclared original code at 0x00477100":
            raise ValueError(f"original-call bypass was not rejected: {difference}")
        print(f"Rejected original-call bypass: {difference['message']}")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    check = commands.add_parser("check", help="compile and verify reviewed routines")
    check.add_argument("address", nargs="*", type=lambda value: int(value, 16))
    check.add_argument("--source", type=Path, help="alternate candidate for one address")
    check.add_argument("--json-out", type=Path)
    test = commands.add_parser("self-test", help="verify that a wrong compiled candidate is rejected")
    for command in (check, test):
        command.add_argument("--cc", default="gcc")
        command.add_argument("--ld", default="ld")
    queue = commands.add_parser("queue", help="list registered function addresses and source ownership")
    queue.add_argument("--report", type=Path, help="annotate the queue with results from the last check")
    commands.add_parser("toolchain", help="print PE linker hints and local compiler availability")
    args = parser.parse_args()
    try:
        if args.command == "queue":
            show_queue(args.report)
            return 0
        pe = load_original()
        if args.command == "toolchain":
            rich = pe.parse_rich_header()
            values = rich["values"] if rich else []
            write_json({"target_sha256": PE_HASH,
                        "linker": [pe.OPTIONAL_HEADER.MajorLinkerVersion, pe.OPTIONAL_HEADER.MinorLinkerVersion],
                        "rich_entries": [{"product": tag >> 16, "build": tag & 0xffff, "count": count}
                                         for tag, count in zip(values[::2], values[1::2])],
                        "available": {name: shutil.which(name) for name in ("cl", "clang-cl", "gcc", "ld", "wine")},
                        "matching_toolchain_verified": False}, None)
            return 0
        if args.command == "self-test":
            self_test(pe, args.cc, args.ld)
            return 0
        selected = selected_routines(args)
        if args.source is not None and len(selected) != 1:
            raise ValueError("--source requires exactly one selected routine")
        results = [verify_routine(pe, routine, (args.source or ROOT / routine.source).resolve(),
                                  args.cc, args.ld) for routine in selected]
        for result in results:
            print(f"{result['address']} {result['name']}: {result['passed']}/{result['cases']} cases")
            if result["first_difference"]:
                print(f"  {json.dumps(result['first_difference'])}")
        if args.json_out:
            write_json({"schema": "pc2.decomp_verification.v1", "target_sha256": PE_HASH,
                        "routines": results}, args.json_out)
        return 0 if all(row["behavior_verified"] for row in results) else 1
    except (OSError, ValueError, ImportError, subprocess.TimeoutExpired) as error:
        print(f"decomp verifier: {error}", file=sys.stderr)
        return 2


if __name__ == "__main__":
    sys.exit(main())
