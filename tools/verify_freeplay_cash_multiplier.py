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
        0x4051B5: "89 46 f8",          # gender -> profile+0x20
        0x4051CC: "89 46 fc",          # hair -> profile+0x24
        0x4051DE: "89 06",             # eyes -> profile+0x28
        0x4051E9: "89 46 04",          # mouth -> profile+0x2C
        0x405206: "89 46 08",          # head -> profile+0x30
        0x405209: "89 4e 0c",          # logo -> profile+0x34
        0x40520C: "89 56 10",          # color -> profile+0x38
        0x48200C: "8b 0a",             # color index
        0x48201C: "89 81 dc 01 00 00",  # Company+0x1DC color
        0x482029: "8b 42 fc",          # logo index
        0x48202C: "89 81 e0 01 00 00",  # Company+0x1E0 logo
        0x4822E5: "8b 52 e8",          # profile+0x20 -> Character+0x24
        0x4822EB: "8b 91 a4 00 00 00",  # profile+0x24 -> Character+0x28
        0x4822F4: "8b 91 a8 00 00 00",  # profile+0x28 -> Character+0x2C
        0x4822FD: "8b 91 ac 00 00 00",  # profile+0x2C -> Character+0x30
        0x482306: "8b 89 b0 00 00 00",  # profile+0x30 -> Character+0x34
        0x4C7B7C: "a3 0c bd 57 00",    # logo -> profile+0x34
        0x4C7B81: "89 0d 10 bd 57 00",  # color -> profile+0x38
        0x4C7B9D: "a3 38 b9 57 00",    # gender -> settings 0x57B938
        0x4C7B3B: "68 58 bc 57 00",    # player name destination
        0x4C7B77: "68 98 bc 57 00",    # enterprise name destination
        0x4CBD4F: "68 58 bc 57 00",    # player name read
        0x4CBD60: "68 98 bc 57 00",    # enterprise name read
        0x4CBD81: "be 58 bc 57 00",    # 0xC0-byte preview copy
        0x4821B4: "8b 41 cc",          # profile+0x04 (characteristic adjust)
        0x482144: "8b 48 d0",          # profile+0x08 -> Player+0x3C
        0x482153: "8b 48 d4",          # profile+0x0C -> Player+0x40
        0x482160: "8b 48 d8",          # profile+0x10 -> Player+0x44
        0x48216D: "8b 48 dc",          # profile+0x14 -> Player+0x48
        0x48217A: "8b 48 e0",          # profile+0x18 -> Player+0x4C
        0x482187: "8b 40 e4",          # profile+0x1C -> Player+0x50
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
        "0x4051b5": "0x57bdb8",
        "0x4051cc": "0x57bdbc",
        "0x4051de": "0x57bdc0",
        "0x4051e9": "0x57bdc4",
        "0x405206": "0x57bdc8",
        "0x405209": "0x57bdcc",
        "0x40520c": "0x57bdd0",
    }
    for address, resolved in profile_sites.items():
        site = scan_sites.get(address)
        if site is None:
            failures.append(f"raw scan missing profile site {address}")
        elif site["resolved_address"] != resolved:
            failures.append(
                f"profile site {address} resolves to "
                f"{site['resolved_address']} != {resolved}")

    if fixture.get("case_count") != 11 or fixture.get("matches") != 11:
        failures.append("fixture is not 11/11")
    if fixture.get("first_mismatch") is not None:
        failures.append("fixture reports a mismatch")
    by_id = {case["id"]: case for case in fixture.get("cases", [])}
    if by_id.get("init_defaults", {}).get("actual", {}).get(
            "p0_multiplier") != 100:
        failures.append("initializer fixture does not show multiplier 100")
    if by_id.get("cash_32bit_product_wrap", {}).get(
            "actual", {}).get("starting_cash") != 0:
        failures.append("32-bit wrap fixture mismatch")
    appearance = by_id.get("appearance_copy", {}).get("actual", {})
    if (appearance.get("gender"), appearance.get("hair"),
        appearance.get("eyes"), appearance.get("mouth"),
        appearance.get("head")) != (1, 2, 3, 4, 5):
        failures.append("appearance-copy fixture mismatch")
    logo_color = by_id.get("logo_color_mapping", {}).get("actual", {})
    if (logo_color.get("company_color"), logo_color.get("company_logo")) != \
            (0xA600, 5):
        failures.append("logo/color mapping fixture mismatch")

    header = open(HEADER, encoding="utf-8").read()
    for needle in ("sizeof(FreePlayProfile) == FREEPLAY_PROFILE_STRIDE",
                   "offsetof(FreePlayProfile, player_name)",
                   "offsetof(FreePlayProfile, company_name)",
                   "offsetof(FreePlayProfile, cash_multiplier)",
                   "offsetof(FreePlayProfile, characteristic_adjust)",
                   "offsetof(FreePlayProfile, buyer)",
                   "offsetof(FreePlayProfile, gangsters)",
                   "offsetof(FreePlayProfile, specialist)",
                   "offsetof(FreePlayProfile, politicians)",
                   "offsetof(FreePlayProfile, seller)",
                   "offsetof(FreePlayProfile, guard)",
                   "offsetof(FreePlayProfile, gender)",
                   "offsetof(FreePlayProfile, hair)",
                   "offsetof(FreePlayProfile, eyes)",
                   "offsetof(FreePlayProfile, mouth)",
                   "offsetof(FreePlayProfile, head)",
                   "offsetof(FreePlayProfile, logo)",
                   "offsetof(FreePlayProfile, color)",
                   "offsetof(FreePlayProfile, active)",
                   "sizeof(FreePlayCharacterAppearance) == 0x828",
                   "offsetof(FreePlayCharacterAppearance, gender)",
                   "offsetof(FreePlayCharacterAppearance, head)",
                   "FREEPLAY_PROFILE_COUNT == 6"):
        if needle not in header:
            failures.append(f"header missing static assert: {needle}")
    for needle in ("freeplay_compute_starting_cash",
                   "freeplay_profile_apply_defaults",
                   "freeplay_adjust_characteristic",
                   "freeplay_profile_copy_appearance"):
        if needle not in header:
            failures.append(f"header missing declaration: {needle}")

    expected_fields = {
        "0x00": "player_name",
        "0x40": "company_name",
        "0x80": "cash_multiplier",
        "0x84": "characteristic_adjust",
        "0x88": "buyer",
        "0x8C": "gangsters",
        "0x90": "specialist",
        "0x94": "politicians",
        "0x98": "seller",
        "0x9C": "guard",
        "0xA0": "gender",
        "0xA4": "hair",
        "0xA8": "eyes",
        "0xAC": "mouth",
        "0xB0": "head",
        "0xB4": "logo",
        "0xB8": "color",
        "0xBC": "active",
    }
    actual_fields = {field["offset"]: field["name"]
                     for field in packet["globals"][1]["fields"]}
    if actual_fields != expected_fields:
        failures.append("profile field map differs from recovered layout")

    if failures:
        for failure in failures:
            print(f"FAIL {failure}")
        return 1
    print(
        "Free-play cash multiplier evidence: 3 multiplier sites, "
        "22 profile sites, complete six-record 0xC0 layout, fixture 11/11")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
