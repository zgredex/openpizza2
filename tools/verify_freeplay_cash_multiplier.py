#!/usr/bin/env python3
"""Verify the free-play cash-multiplier dependency packet.

Checks the base-minus-offset instruction bytes, the recovered profile layout,
the raw scanner output and the 9-case Unicorn fixture.
"""

from __future__ import annotations

import hashlib
import json
import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BASE = os.path.join(ROOT, "decompiled_fastfood2_named_v2")
EXE = os.path.join(ROOT, "game", "fastfood2.exe")
PACKET = os.path.join(BASE, "typed_packets", "freeplay_cash_multiplier.json")
RAW = os.path.join(BASE, "typed_packets",
                   "freeplay_cash_multiplier.scan.json")
FIXTURE = os.path.join(BASE, "typed_packets", "fixtures",
                       "freeplay_cash_multiplier.result.json")
HEADER = os.path.join(ROOT, "reconstructed", "freeplay",
                      "freeplay_profiles.h")
sys.path.insert(0, os.path.join(ROOT, "tools"))
from dependency_packet import scan  # noqa: E402


def sha256(path: str) -> str:
    digest = hashlib.sha256()
    with open(path, "rb") as handle:
        for chunk in iter(lambda: handle.read(1 << 20), b""):
            digest.update(chunk)
    return digest.hexdigest()


def bytes_at(image: bytes, address: int, length: int) -> str:
    offset = address - 0x400000
    return image[offset:offset + length].hex(" ")


def main() -> int:
    failures: list[str] = []
    packet = json.load(open(PACKET, encoding="utf-8"))
    raw = json.load(open(RAW, encoding="utf-8"))
    fixture = json.load(open(FIXTURE, encoding="utf-8"))
    image = open(EXE, "rb").read()

    if sha256(EXE) != packet["executable"]["sha256"]:
        failures.append("executable sha256 does not match packet")
    if sha256(EXE) != raw["executable_sha256"]:
        failures.append("executable sha256 does not match raw scan")

    expected = {
        0x406B90: "89 48 d0",          # mov [eax-0x30],ecx
        0x4CBEB7: "8b 50 e8",          # mov edx,[eax-0x18]
        0x4CD4AE: "89 51 e8",          # mov [ecx-0x18],edx
        0x4CBEBD: "89 51 fc",          # mov [ecx-4],edx
        0x4CBEC3: "89 11",             # mov [ecx],edx
        0x4CBEC8: "89 51 38",          # mov [ecx+0x38],edx
        0x48203D: "8b 0d d8 bc 57 00",  # mov ecx,[0x57bcd8]
        0x482089: "8b 80 d8 bc 57 00",  # mov eax,[eax+0x57bcd8]
        0x4CC8DC: "89 30",             # mov [eax],esi
        0x4CC8E3: "c7 00 46 00 00 00",  # mov [eax],0x46
        0x4CC938: "c7 00 de 03 00 00",  # mov [eax],0x3de
        0x4CC989: "c7 00 fa ff ff ff",  # mov [eax],0xfffffffa
        0x4CC9DA: "c7 00 06 00 00 00",  # mov [eax],0x6
    }
    for address, expected_bytes in expected.items():
        actual = bytes_at(image, address, len(expected_bytes.split()))
        if actual != expected_bytes:
            failures.append(
                f"0x{address:x}: bytes {actual} != {expected_bytes}")

    scan_sites = {}
    for scan_entry in raw["scans"]:
        for site in scan_entry["sites"]:
            scan_sites[site["address"]] = site
    live_sites = {site["address"]: site
                  for site in scan({0x57B97C, 0x57BCD8}, 0x480)}
    for address in ("0x406b90", "0x4cbeb7", "0x4cd4ae"):
        if address not in live_sites:
            failures.append(f"live scanner missing {address}")
    for address in ("0x406b90", "0x4cbeb7", "0x4cd4ae"):
        if address not in scan_sites:
            failures.append(f"raw scan missing {address}")
        elif scan_sites[address]["resolved_address"] != "0x57b97c":
            failures.append(
                f"raw scan {address} resolves to "
                f"{scan_sites[address]['resolved_address']}")

    profile_sites = {
        "0x4cbebd": "0x57bcd8",
        "0x4cbec3": "0x57bcdc",
        "0x4cbec8": "0x57bd14",
        "0x40520f": "0x57bd98",
        "0x405220": "0x57bd9c",
        "0x40525c": "0x57bdd4",
        "0x481efe": "0x57bd14",
        "0x481f01": "0x57bcd8",
        "0x482089": "0x57bcd8",
        "0x4cb494": "0x57bdd4",
        "0x4cc8cb": "0x57bcd8",
        "0x4cc91d": "0x57bcd8",
        "0x4cc973": "0x57bcdc",
        "0x4cc9c4": "0x57bcdc",
        "0x4ff9fc": "0x57bcd8",
    }
    for address, resolved in profile_sites.items():
        site = scan_sites.get(address)
        if site is None:
            failures.append(f"raw scan missing profile site {address}")
        elif site["resolved_address"] != resolved:
            failures.append(
                f"profile site {address} resolves to "
                f"{site['resolved_address']} != {resolved}")

    if fixture.get("case_count") != 9 or fixture.get("matches") != 9:
        failures.append("fixture is not 9/9")
    if fixture.get("first_mismatch") is not None:
        failures.append("fixture reports a mismatch")
    by_id = {case["id"]: case for case in fixture.get("cases", [])}
    if by_id.get("init_defaults", {}).get("actual", {}).get(
            "p0_multiplier") != 100:
        failures.append("initializer fixture does not show multiplier 100")
    if by_id.get("cash_32bit_product_wrap", {}).get(
            "actual", {}).get("starting_cash") != 0:
        failures.append("32-bit wrap fixture mismatch")

    header = open(HEADER, encoding="utf-8").read()
    for needle in ("sizeof(FreePlayProfile) == FREEPLAY_PROFILE_STRIDE",
                   "offsetof(FreePlayProfile, cash_multiplier)",
                   "offsetof(FreePlayProfile, active)",
                   "FREEPLAY_PROFILE_COUNT == 6"):
        if needle not in header:
            failures.append(f"header missing static assert: {needle}")
    for needle in ("freeplay_compute_starting_cash",
                   "freeplay_profile_apply_defaults"):
        if needle not in header:
            failures.append(f"header missing declaration: {needle}")

    if failures:
        for failure in failures:
            print(f"FAIL {failure}")
        return 1
    print(
        "Free-play cash multiplier evidence: 3 multiplier sites, "
        "15 profile sites, 2 static-assert offsets, fixture 9/9")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
