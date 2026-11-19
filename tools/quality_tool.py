#!/usr/bin/env python3
"""Reference quality-score evaluator for the recovered 0x47d910 tables."""

from __future__ import annotations

import argparse
import json
import os
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BASE = os.path.join(ROOT, "decompiled_fastfood2_named_v2")


def load_tables():
    path = os.path.join(BASE, "PRODUCT_QUALITY_TABLES.json")
    with open(path) as fh:
        fixture = json.load(fh)
    tables = fixture["tables"]

    def matrix(address):
        return tables[address]

    return {
        "batch_threshold": matrix("0x567938")[0],
        "helper_threshold": matrix("0x567958")[0],
        "record_penalty": matrix("0x567978"),
        "staff_penalty": matrix("0x567a38"),
    }


def f32(value):
    return struct.unpack("<f", struct.pack("<f", float(value)))[0]


def round_original(value):
    """0x403850: add/subtract 0.5, then truncate toward zero."""
    if value >= 0.0:
        return int(value + 0.5)
    return int(value - 0.5)


def combined_score(case):
    helper = int(case["helper_47c9a0_low"])
    company = int(case["helper_47cb70_signed"])
    if not 0 <= helper <= 100:
        raise ValueError("helper_47c9a0_low must be 0..100")
    product = f32(f32(helper) * f32(0.01))
    product = f32(product * f32(company))
    return round_original(product)


def score(case, tables):
    category = int(case["category"])
    average = int(case["batch_average"])
    low = int(case["helper_47ca80_low"])
    if not 0 <= low <= 2:
        raise ValueError("helper_47ca80_low must be 0..2")
    combined = combined_score(case)
    staff_bucket = int(case["staff_average_bucket"])

    threshold = tables["batch_threshold"][category]
    value = 100
    if average < threshold:
        multiplier = 4 if average < 0 else 2
        value += multiplier * (average - threshold)

    helper_threshold = tables["helper_threshold"][category]
    if low < helper_threshold:
        value += 10 * (low - helper_threshold)

    if combined < 0:
        penalty = 100
    elif combined < 6:
        penalty = tables["record_penalty"][category][combined]
    else:
        penalty = tables["record_penalty"][category][5]
    value -= penalty

    if staff_bucket < 0 or staff_bucket > 8:
        staff_penalty = tables["staff_penalty"][category][8]
    else:
        staff_penalty = tables["staff_penalty"][category][staff_bucket]
    return value - staff_penalty


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--fixture", default=os.path.join(
        BASE, "PRODUCT_QUALITY_REPLAY.json"))
    args = parser.parse_args()
    with open(args.fixture) as fh:
        fixture = json.load(fh)
    tables = load_tables()
    failed = False
    for case in fixture["cases"]:
        actual = score(case, tables)
        expected = case["expected_return"]
        ok = actual == expected
        failed |= not ok
        print(f"{case['name']:28s} expected={expected:3d} actual={actual:3d} {'OK' if ok else 'FAIL'}")
    branch = fixture["branch_staff_fixture"]
    actual = score(branch, tables)
    expected = branch["expected_return"]
    ok = actual == expected
    failed |= not ok
    print(f"{branch['name']:28s} expected={expected:3d} actual={actual:3d} {'OK' if ok else 'FAIL'}")

    for mutation in fixture.get("mutations", []):
        case = dict(branch)
        case[mutation["field"]] = mutation["value"]
        actual = score(case, tables)
        expected = mutation["expected_return"]
        ok = actual == expected
        failed |= not ok
        print(f"mutation {mutation['field']}={mutation['value']}: "
              f"expected={expected:3d} actual={actual:3d} {'OK' if ok else 'FAIL'}")
    return 1 if failed else 0


if __name__ == "__main__":
    raise SystemExit(main())
