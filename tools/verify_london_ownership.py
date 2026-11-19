#!/usr/bin/env python3
"""Verify the London ownership evidence packet against the shipped executable.

The packet claims one-byte reads/writes of branch +0x16F4, a set of callers and
callees, and a complete classification of every +0x16F4 instruction site in
foodfood2.exe.  This script re-derives those claims from the original bytes and
objdump output so the packet cannot silently drift.
"""

from __future__ import annotations

import hashlib
import json
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BASE = os.path.join(ROOT, "decompiled_fastfood2_named_v2")
EXE = os.path.join(ROOT, "game", "fastfood2.exe")
PACKET = os.path.join(BASE, "typed_packets", "london_ownership.routines.json")
BATCH = os.path.join(BASE, "typed_packets", "london_ownership.json")
DEPS = os.path.join(BASE, "typed_packets", "london_ownership.dependencies.md")
FIXTURE = os.path.join(BASE, "typed_packets", "fixtures",
                       "london_ownership.result.json")


def sha256(path: str) -> str:
    digest = hashlib.sha256()
    with open(path, "rb") as handle:
        for chunk in iter(lambda: handle.read(1 << 20), b""):
            digest.update(chunk)
    return digest.hexdigest()


def load_objdump_sites() -> dict[str, str]:
    proc = subprocess.run(
        ["objdump", "-d", "-M", "intel", EXE],
        cwd=ROOT, text=True, capture_output=True, check=True)
    sites: dict[str, str] = {}
    for line in proc.stdout.splitlines():
        match = re.match(r"\s*([0-9a-f]+):\s+(?:[0-9a-f]{2} )+\s*(.*)$", line)
        if not match:
            continue
        address = int(match.group(1), 16)
        instruction = match.group(2).strip()
        if "0x16f4" in instruction.lower():
            sites[f"0x{address:x}"] = instruction
    return sites


def load_named_ranges() -> list[tuple[int, int, str]]:
    ranges = []
    directory = os.path.join(BASE, "functions_readable")
    for name in os.listdir(directory):
        if not name.endswith(".c"):
            continue
        with open(os.path.join(directory, name), errors="ignore") as handle:
            head = handle.read(600)
        address = re.search(r"^// address: (0x[0-9a-f]+)$", head, re.M)
        span = re.search(r"^// range: 0x[0-9a-f]+-(0x[0-9a-f]+)", head, re.M)
        label = re.search(r"^// name: (.+)$", head, re.M)
        if address and span and label:
            ranges.append((int(address.group(1), 16),
                           int(span.group(1), 16), label.group(1)))
    return ranges


def routine_name_for(address: int, ranges) -> str:
    for start, end, name in ranges:
        if start <= address <= end:
            return name
    return "UNNAMED"


def check_site(site: dict, instruction: str, named: str,
               routine: str | None, failures: list[str]) -> None:
    address = site["address"].lower()
    width = site.get("width")
    access = site.get("access")
    lowered = instruction.lower()
    if "0x16f4" not in lowered:
        failures.append(f"{address}: instruction does not mention +0x16F4")
        return
    if width == 1:
        if access in ("save-stream-read", "save-stream-write"):
            if not lowered.startswith("lea"):
                failures.append(f"{address}: stream site is not a lea")
        elif "byte ptr" not in lowered:
            failures.append(f"{address}: expected BYTE PTR for width 1")
    elif width == 4:
        if "dword ptr" not in lowered and not lowered.startswith("lea"):
            failures.append(f"{address}: expected DWORD PTR or lea for width 4")
    else:
        failures.append(f"{address}: unsupported width {width}")
    if routine is not None and named != routine:
        failures.append(
            f"{address}: routine {routine} does not enclose named {named}")


def main() -> int:
    failures: list[str] = []
    packet = json.load(open(PACKET, encoding="utf-8"))
    batch = json.load(open(BATCH, encoding="utf-8"))
    fixture = json.load(open(FIXTURE, encoding="utf-8"))

    if sha256(EXE) != packet["executable"]["sha256"]:
        failures.append("executable sha256 does not match packet")
    if sha256(EXE) != batch["target"]["sha256"]:
        failures.append("executable sha256 does not match generated batch")

    sites = load_objdump_sites()
    ranges = load_named_ranges()
    classified: set[str] = set()

    for routine in packet["routines"]:
        address = routine["address"].lower()
        record = batch["records"].get(address)
        if record is None:
            failures.append(f"{address}: missing from generated batch")
            continue
        callers = sorted(item["name"] for item in record.get("callers", []))
        callees = sorted(item["name"] for item in record.get("callees", []))
        if sorted(routine["callers"]) != callers:
            failures.append(f"{address}: caller list differs from batch")
        if sorted(routine["calls"]) != callees:
            failures.append(f"{address}: callee list differs from batch")
        if not routine["instruction_sites"]:
            failures.append(f"{address}: no instruction sites recorded")
        for site in routine["instruction_sites"]:
            key = site["address"].lower()
            if key in classified:
                failures.append(f"{key}: classified twice")
            classified.add(key)
            if key not in sites:
                failures.append(f"{key}: not found in objdump")
                continue
            check_site(site, sites[key], routine_name_for(int(key, 16), ranges),
                       routine["name"], failures)
            if int(key, 16) not in range(int(address, 16),
                                         int(record["body"]["ranges"][0]["end"], 16) + 1):
                failures.append(f"{key}: outside declared routine range")

    for site in packet["unresolved_sites"] + packet["excluded_sites"]:
        key = site["address"].lower()
        if key in classified:
            failures.append(f"{key}: classified twice")
        classified.add(key)
        if key not in sites:
            failures.append(f"{key}: not found in objdump")
            continue
        check_site(site, sites[key], routine_name_for(int(key, 16), ranges),
                   None, failures)

    missing = sorted(set(sites) - classified, key=lambda x: int(x, 16))
    extra = sorted(classified - set(sites), key=lambda x: int(x, 16))
    if missing:
        failures.append("unclassified +0x16F4 sites: " + ", ".join(missing))
    if extra:
        failures.append("packet sites absent from executable: " + ", ".join(extra))

    if fixture.get("case_count") != 9 or fixture.get("matches") != 9:
        failures.append("fixture is not 9/9")
    if fixture.get("first_mismatch") is not None:
        failures.append("fixture reports a mismatch")

    deps = open(DEPS, encoding="utf-8").read().lower()
    for routine in packet["routines"]:
        if routine["address"].lower() not in deps:
            failures.append(
                f"{routine['name']}: address missing from dependencies.md")
        for site in routine["instruction_sites"]:
            if site["address"].lower() not in deps:
                failures.append(
                    f"{site['address']}: site missing from dependencies.md")

    if failures:
        for failure in failures:
            print(f"FAIL {failure}")
        return 1

    print(
        f"London ownership evidence: {len(packet['routines'])} routines, "
        f"{len(classified)} +0x16F4 sites classified "
        f"({len(packet['unresolved_sites'])} unresolved, "
        f"{len(packet['excluded_sites'])} excluded), fixture 9/9")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
