#!/usr/bin/env python3
"""Compile, cache, strict-verify and score a family of VC6 source candidates.

The input is a small JSON family spec. Sources can be tracked batch files or
investigation drafts. Verification is the same strict matcher used by the
batch scripts, so a row is only `strict` when the complete relocated primary
and secondary sections agree with the pinned PE.
"""

import argparse
from collections import Counter
import json
from pathlib import Path

from coff_cache import cache_environment, cache_identity, hash_bytes
from match_decomp import DEFAULT_VC6, GAME, ROOT, compiler_provenance, pe_image, resolve_auto_symbol
from verify_linked_image import PINNED_SHA256, Recipe, file_offset, verify_batch

SCHEMA = "pc2.family_batch.v1"
REPORT_SCHEMA = "pc2.family_batch.report.v1"


def load_config(path):
    payload = json.loads(path.read_text())
    if payload.get("schema") != SCHEMA:
        raise ValueError(f"expected schema {SCHEMA}")
    family = payload.get("family")
    if not isinstance(family, str) or not family:
        raise ValueError("family needs a name")
    rows = payload.get("recipes")
    if not isinstance(rows, list) or not 1 <= len(rows) <= 512:
        raise ValueError("recipes needs one to 512 entries")
    recipes = []
    seen = set()
    names = {}
    for row in rows:
        address = int(row["address"], 0)
        if address in seen:
            raise ValueError(f"duplicate address {address:#x}")
        seen.add(address)
        length = int(row["length"])
        if length <= 0:
            raise ValueError(f"non-positive length at {address:#x}")
        entry = row["entry"]
        flags = tuple(row.get("flags", ["/O2", "/TP"]))
        source = (ROOT / row["source"]).resolve()
        if not source.is_relative_to(ROOT) or not source.is_file():
            raise ValueError(f"source is missing or outside the checkout: {row['source']}")
        source_bytes = source.read_bytes()
        symbols = {name: int(value, 0) for name, value in row.get("symbols", {}).items()}
        recipes.append(Recipe(address, length, file_offset(pe_image(GAME), address, length),
                              source, hash_bytes(source_bytes), entry, flags, symbols))
        names[address] = row.get("name") or entry
    return family, recipes, names


def compact_evidence(evidence):
    keys = ("status", "difference_count", "first_difference", "strict_issues",
            "relocation_issues", "blocked_sections", "link_plan_issues", "cache",
            "cache_key", "object", "error")
    return {key: evidence[key] for key in keys if key in evidence}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--config", required=True, type=Path)
    parser.add_argument("--out", required=True, type=Path)
    parser.add_argument("--cache", type=Path, help="COFF cache directory")
    parser.add_argument("--jobs", type=int, choices=range(1, 9), default=4, metavar="N")
    parser.add_argument("--cache-only", action="store_true", help="fail on a cache miss")
    parser.add_argument("--vc6", type=Path, default=DEFAULT_VC6)
    args = parser.parse_args()
    try:
        if compiler_provenance(args.vc6.resolve())["sha256"] is None:
            raise ValueError("VC6 compiler inputs are incomplete")
        if hash_bytes(GAME.read_bytes()) != PINNED_SHA256:
            raise ValueError("original PE does not match the pinned hash")
        family, recipes, names = load_config(args.config)
        out = args.out.resolve()
        out.mkdir(parents=True, exist_ok=True)
        objects = out / "objects"
        objects.mkdir()
        cache_dir = None
        identity = None
        environment = cache_environment()
        if args.cache is not None:
            cache_dir = (args.cache / "coff").resolve()
            cache_dir.mkdir(parents=True, exist_ok=True)
            identity = cache_identity(args.vc6.resolve(), ROOT, environment)
            if identity is None:
                raise ValueError("VC6/Wine environment is outside the COFF cache contract")
        image = pe_image(GAME)
        resolve_auto_symbol("__except_list")
        results = verify_batch(recipes, args.jobs, args.vc6.resolve(), objects, image[0],
                               cache_dir, identity, environment,
                               cache_only=args.cache_only, assess=True)
        functions = []
        for (spans, evidence) in results:
            address = int(evidence["address"], 0)
            row = {"address": hex(address), "name": names.get(address), "length": next(
                recipe.length for recipe in recipes if recipe.address == address)}
            row.update(compact_evidence(evidence))
            if spans:
                row["spans"] = [{key: span[key] for key in ("kind", "section", "start", "length")}
                                for span in spans]
            functions.append(row)
        statuses = Counter(row["status"] for row in functions)
        strict = [row for row in functions if row["status"] == "strict"]
        report = {
            "schema": REPORT_SCHEMA,
            "family": family,
            "executable_sha256": PINNED_SHA256,
            "compiler": compiler_provenance(args.vc6.resolve()),
            "statuses": dict(sorted(statuses.items())),
            "candidate_bytes": sum(row["length"] for row in functions),
            "strict_bytes": sum(row["length"] for row in strict),
            "cache_hits": sum(row.get("cache") == "hit" for row in functions),
            "functions": sorted(functions, key=lambda row: int(row["address"], 0)),
        }
        (out / "report.json").write_text(json.dumps(report, indent=2) + "\n")
        print(f"{family}: {len(strict)}/{len(functions)} strict, "
              f"{report['strict_bytes']:,}/{report['candidate_bytes']:,} bytes, "
              f"{report['cache_hits']} cache hits, statuses {dict(statuses)}")
        for row in report["functions"]:
            if row["status"] == "strict":
                detail = "strict"
            else:
                first = row.get("first_difference")
                detail = row["status"]
                if first:
                    detail += f" offset={first['offset']:#x} {first['original']:#04x}->{first['candidate']:#04x}"
                if row.get("difference_count") is not None:
                    detail += f" diff={row['difference_count']}"
                if row.get("error"):
                    detail += f" error={row['error']}"
            print(f"  {row['address']} {row['length']:>5}  {row['name']}: {detail}")
        return 0 if not (set(statuses) & {"error", "cache_missing", "unsupported"}) else 1
    except (OSError, ValueError, KeyError, TypeError) as error:
        parser.exit(2, f"family batch: {error}\n")


if __name__ == "__main__":
    raise SystemExit(main())
