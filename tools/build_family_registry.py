#!/usr/bin/env python3
"""Join the VC6 cleanup inventory with tracked sources and matcher metadata.

The output is a family registry: every cleanup family, its members, current
strict status, available source candidates, and a ready-to-run batch spec for
members whose entry, flags and source are known.
"""

import argparse
from collections import defaultdict
import json
from pathlib import Path
import re

from match_decomp import GAME, ROOT, function_lengths, file_sha256


ADDRESS_FILE = re.compile(r"(?:^|/)0x([0-9a-fA-F]+)\.(?:c|cpp)$")


def load_inventory(path):
    payload = json.loads(path.read_text())
    if payload.get("schema") != "pc2.vc6_cleanup_families.v1":
        raise ValueError("expected a pc2.vc6_cleanup_families.v1 inventory")
    return payload


def load_features(path):
    payload = json.loads(path.read_text())
    if payload.get("schema") != "pc2.feature_families.v1":
        raise ValueError("expected a pc2.feature_families.v1 feature inventory")
    families = []
    for family in payload["families"]:
        families.append({
            "cleanup_target": "call:" + family["key"],
            "cleanup_name": family["key"],
            "functions": family["functions"],
            "indexed_bytes": family["indexed_bytes"],
            "members": family["members"],
        })
    return families


def load_ui_scan(path):
    payload = json.loads(path.read_text())
    if payload.get("schema") != "pc2.ui_builder_batch.v1":
        raise ValueError("expected a pc2.ui_builder_batch.v1 report")
    root = path.parent
    ready = {}
    for row in payload.get("functions", []):
        if row.get("status") not in {"ready", "strict"}:
            continue
        address = int(row["address"], 0)
        source = row.get("source")
        if source and (root / source).is_file():
            resolved = (root / source).resolve()
            try:
                source = str(resolved.relative_to(ROOT))
            except ValueError:
                source = str(resolved)
        ready[address] = {
            "entry": row.get("entry"),
            "length": row.get("length"),
            "source": source,
        }
    return ready


def scan_sources():
    sources = defaultdict(list)
    for path in (ROOT / "reconstructed" / "match").rglob("0x*.c*"):
        match = ADDRESS_FILE.search(str(path))
        if not match:
            continue
        address = int(match.group(1), 16)
        sources[address].append(str(path.relative_to(ROOT)))
    for address, paths in sources.items():
        paths.sort(key=lambda value: ("nonmatching" in value, value.count("/"), value))
    return sources


def scan_metadata(audit):
    records = {}
    def add(record, origin):
        if not isinstance(record, dict) or "address" not in record:
            return
        try:
            address = int(record["address"], 0)
        except (TypeError, ValueError):
            return
        current = records.get(address)
        row = {
            "address": address,
            "entry": record.get("entry"),
            "flags": record.get("flags"),
            "strict": record.get("strict_match") is True,
            "source": record.get("source"),
            "symbols": record.get("symbol_overrides") or {},
            "origin": origin,
        }
        if not row["entry"]:
            return
        if current is None or (row["strict"] and not current["strict"]):
            records[address] = row
    if audit:
        for path in sorted(audit.glob("functions/*.json")):
            add(json.loads(path.read_text()), str(path.relative_to(ROOT)) if path.is_relative_to(ROOT) else str(path))
    for path in (ROOT / "reconstructed" / "match").rglob("0x*.json"):
        try:
            add(json.loads(path.read_text()), str(path.relative_to(ROOT)))
        except (OSError, json.JSONDecodeError):
            continue
    return records


def build(inventory, sources, metadata, features=None, ui_ready=None):
    lengths = function_lengths()
    families = []
    all_families = list(inventory["families"]) + (features or [])
    for family in all_families:
        members = []
        strict_functions = strict_bytes = 0
        candidate_functions = candidate_bytes = 0
        generated_functions = generated_bytes = 0
        missing_functions = missing_bytes = 0
        for member in family["members"]:
            address = int(member["address"], 0)
            generated = (ui_ready or {}).get(address)
            source = (sources.get(address) or [None])[0]
            if generated and generated.get("source"):
                source = generated["source"]
            meta = metadata.get(address, {})
            entry = generated.get("entry") if generated else meta.get("entry")
            flags = ["/O2", "/TP"] if generated else meta.get("flags")
            length = member.get("length") or lengths.get(address, 0)
            strict = bool(meta.get("strict"))
            status = ("strict" if strict else "generated" if generated else
                      "candidate" if source and entry and flags else
                      "source_only" if source else "missing")
            if status == "strict":
                strict_functions += 1
                strict_bytes += length
            elif status == "generated":
                generated_functions += 1
                generated_bytes += length
            elif status == "candidate":
                candidate_functions += 1
                candidate_bytes += length
            else:
                missing_functions += 1
                missing_bytes += length
            members.append({
                "address": hex(address),
                "name": member.get("name"),
                "length": length,
                "status": status,
                "source": source,
                "entry": entry,
                "flags": flags,
                "symbols": meta.get("symbols") or {},
            })
        members.sort(key=lambda row: int(row["address"], 0))
        families.append({
            "cleanup_target": family["cleanup_target"],
            "cleanup_name": family.get("cleanup_name"),
            "functions": family["functions"],
            "indexed_bytes": family["indexed_bytes"],
            "strict_functions": strict_functions,
            "strict_bytes": strict_bytes,
            "candidate_functions": candidate_functions,
            "candidate_bytes": candidate_bytes,
            "generated_functions": generated_functions,
            "generated_bytes": generated_bytes,
            "missing_functions": missing_functions,
            "missing_bytes": missing_bytes,
            "members": members,
        })
    families.sort(key=lambda row: (-(row["strict_bytes"] + row["generated_bytes"] + row["candidate_bytes"]), -row["indexed_bytes"], row["cleanup_target"]))
    return {
        "schema": "pc2.family_registry.v1",
        "executable_sha256": file_sha256(GAME),
        "families": families,
    }


def write_specs(registry, directory):
    directory.mkdir(parents=True, exist_ok=True)
    written = 0
    for family in registry["families"]:
        recipes = []
        for member in family["members"]:
            if member["status"] == "generated":
                continue
            if not (member["source"] and member["entry"] and member["flags"]):
                continue
            recipe = {
                "address": member["address"],
                "name": member["name"],
                "length": member["length"],
                "entry": member["entry"],
                "source": member["source"],
                "flags": member["flags"],
            }
            if member["symbols"]:
                recipe["symbols"] = member["symbols"]
            recipes.append(recipe)
        if not recipes:
            continue
        name = family["cleanup_target"].replace("0x", "").replace(":", "-")
        payload = {"schema": "pc2.family_batch.v1",
                   "family": f"{family['cleanup_name'] or 'cleanup'}-{family['cleanup_target']}",
                   "recipes": recipes}
        (directory / f"family-{name}.json").write_text(json.dumps(payload, indent=2) + "\n")
        written += 1
    return written


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--inventory", required=True, type=Path)
    parser.add_argument("--features", type=Path, help="optional pc2.feature_families.v1 inventory")
    parser.add_argument("--ui-scan", type=Path, help="optional pc2.ui_builder_batch.v1 report")
    parser.add_argument("--audit", type=Path, help="directory containing functions/*.json")
    parser.add_argument("--out", required=True, type=Path)
    parser.add_argument("--report", type=Path)
    parser.add_argument("--specs-out", type=Path)
    args = parser.parse_args()
    try:
        inventory = load_inventory(args.inventory)
        features = load_features(args.features) if args.features else []
        ui_ready = load_ui_scan(args.ui_scan) if args.ui_scan else {}
        registry = build(inventory, scan_sources(), scan_metadata(args.audit), features, ui_ready)
        args.out.parent.mkdir(parents=True, exist_ok=True)
        args.out.write_text(json.dumps(registry, indent=2) + "\n")
        if args.specs_out:
            written = write_specs(registry, args.specs_out)
        else:
            written = 0
        if args.report:
            lines = [
                "# Cleanup family registry",
                "",
                "| cleanup | name | functions | bytes | strict | generated | candidate | missing |",
                "|---|---|---:|---:|---:|---:|---:|---:|",
            ]
            for family in registry["families"]:
                lines.append(
                    f"| {family['cleanup_target']} | {family['cleanup_name'] or ''} | "
                    f"{family['functions']} | {family['indexed_bytes']:,} | "
                    f"{family['strict_functions']}/{family['strict_bytes']:,} | "
                    f"{family['generated_functions']}/{family['generated_bytes']:,} | "
                    f"{family['candidate_functions']}/{family['candidate_bytes']:,} | "
                    f"{family['missing_functions']}/{family['missing_bytes']:,} |")
            args.report.write_text("\n".join(lines) + "\n")
        print(f"{len(registry['families'])} families, {written} specs written")
        for family in registry["families"][:12]:
            print(f"  {family['cleanup_target']} {family['cleanup_name'] or '':24s} "
                  f"{family['functions']:3d} fns {family['indexed_bytes']:7,d} B  "
                  f"strict {family['strict_functions']:3d}  generated {family['generated_functions']:3d}  candidate {family['candidate_functions']:3d}")
    except (OSError, ValueError, KeyError) as error:
        parser.exit(1, f"family registry: {error}\n")


if __name__ == "__main__":
    raise SystemExit(main())
