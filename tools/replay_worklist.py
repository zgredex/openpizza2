#!/usr/bin/env python3
"""Rank decompilation work from captured function entries and verified PE ranges."""

from __future__ import annotations

import argparse
from collections import Counter, defaultdict
from fractions import Fraction
import hashlib
import json
from pathlib import Path
import re
import subprocess

import function_batch as packets
from match_decomp import GAME, INDEX, ROOT, file_sha256, pe_image, read_va
from symbol_registry import REGISTRY, load_registry, registry_classes
from verify_linked_image import PINNED_SHA256

CALLGRAPH = INDEX.parents[1] / "callgraph.json"
GUEST_EDGES = {"direct", "indirect", "tail", "return_jump"}
MAX_DETAILS = 12


def read_json(path):
    return json.loads(path.read_text())


def write_json(path, value):
    path.write_text(json.dumps(value, indent=2) + "\n")


def inventory(export):
    result = {}
    for item in export.values():
        body = item.get("body", {})
        ranges = sorted((int(row["start"], 16), int(row["end"], 16) + 1) for row in body.get("ranges", []))
        if not ranges:
            continue
        address = int(item["address"], 16)
        if any(first >= last for first, last in ranges) or any(
                last > first for (_, last), (first, _) in zip(ranges, ranges[1:])):
            raise ValueError(f"invalid indexed body ranges at {address:#x}")
        result[address] = {"name": item["name"], "bytes": sum(last - first for first, last in ranges),
                           "contiguous": ranges[0][0] == address and len(ranges) == 1 and not body.get("non_contiguous")}
    return result


def verified_functions(manifest, image, indexed, expected):
    if any(manifest[key]["sha256"] != expected for key in ("original", "input", "output")):
        raise ValueError("linked manifest SHA-256 differs from the pinned executable")
    schema = manifest["schema"]
    if schema == "pc2.verified_linked_image_batch.v1":
        records = manifest["functions"]
    elif schema == "pc2.verified_linked_image.v1":
        records = [manifest]
    else:
        raise ValueError("unsupported linked manifest schema")
    covered = {}
    for record in records:
        function = record["function"]
        address, length = int(function["start"], 16), function["length"]
        extent = indexed.get(address)
        if (record.get("status", "strict") != "strict" or address in covered or not extent
                or not extent["contiguous"] or extent["bytes"] != length
                or int(function["end_exclusive"], 16) != address + length
                or hashlib.sha256(read_va(image, address, length)).hexdigest() != function["sha256"]):
            raise ValueError(f"invalid or duplicate linked function proof at {address:#x}")
        covered[address] = record.get("provider", "compiled_c")
    return covered


def coverage(addresses, indexed, covered):
    reached = addresses & indexed.keys()
    linked = reached & covered.keys()
    return {"indexed_reached": len(reached), "linked_reached": len(linked),
            "indexed_bytes": sum(indexed[va]["bytes"] for va in reached),
            "linked_bytes": sum(indexed[va]["bytes"] for va in linked),
            "linked_by_provider": dict(Counter(covered[va] for va in sorted(linked))),
            "noncontiguous_reached": sum(not indexed[va]["contiguous"] for va in reached)}


def load_replays(paths, indexed, covered, image_sha256):
    phases, reached = [], defaultdict(set)
    observations, inbound = defaultdict(list), defaultdict(list)
    outgoing, incoming, unknown, unresolved = (defaultdict(set) for _ in range(4))
    for path in paths:
        report = read_json(path)
        if report["format"] != "pc2.capture.v1" or report["run"]["guest_sha256"] != image_sha256:
            raise ValueError(f"capture SHA-256 or schema differs from the pinned executable: {path}")
        for phase in report["phases"]:
            phase_id = len(phases) + 1
            addresses = set()
            unindexed = {}
            for entry in phase["functions"]:
                va = int(entry["address"], 16)
                if entry["count"] <= 0:
                    continue
                addresses.add(va)
                reached[va].add(phase_id)
                if va not in indexed:
                    summary = unindexed.setdefault(va, {"address": hex(va), "symbol": entry.get("symbol"), "count": 0})
                    summary["count"] += entry["count"]
            missing = [edge for edge in phase["edges"] if edge["resolution"] == "no_dispatch"]
            indexed_addresses = addresses & indexed.keys()
            phases.append({"id": phase_id, "report": str(path), "complete": report["complete"],
                           "scenario": report["scenario"], "phase": phase["name"],
                           **coverage(addresses, indexed, covered), "unindexed": list(unindexed.values()),
                           "indexed_addresses": [hex(va) for va in sorted(indexed_addresses)],
                           "linked_addresses": [hex(va) for va in sorted(indexed_addresses & covered.keys())],
                           "noncontiguous_addresses": [hex(va) for va in sorted(indexed_addresses) if not indexed[va]["contiguous"]],
                           "guest_indirect_edge_records": sum(edge["kind"] == "indirect" and edge.get("target_kind") != "hle_import"
                                                               for edge in phase["edges"]),
                           "unresolved_edge_records": len(missing), "unresolved_edge_events": sum(e["count"] for e in missing)})
            for edge in phase["edges"]:
                if not edge["caller"] or edge["count"] <= 0:
                    continue
                caller = int(edge["caller"], 16)
                target = int(edge["target"], 16) if edge["target"] else None
                evidence = dict(edge, phase_id=phase_id, phase=phase["name"],
                                scenario=report["scenario"], report_complete=report["complete"])
                observations[caller].append(evidence)
                if target in indexed and target != caller:
                    inbound[target].append(evidence)
                if edge["resolution"] == "no_dispatch":
                    unresolved[caller].add((edge["site"], edge["target"]))
                if (edge["kind"] not in GUEST_EDGES or edge["resolution"] != "resolved"
                        or edge.get("target_kind") == "hle_import" or target == caller or target is None):
                    continue
                if target in indexed:
                    outgoing[caller].add(target)
                    incoming[target].add(caller)
                else:
                    unknown[caller].add(target)
    return phases, reached, observations, inbound, outgoing, incoming, unknown, unresolved


def rank_groups(uncovered, indexed, covered, reached, observed, incoming, static, unknown, unresolved, size):
    observed_pairs, static_pairs = defaultdict(set), defaultdict(set)
    for graph, pairs in ((observed, observed_pairs), (static, static_pairs)):
        for source in uncovered:
            for target in graph.get(source, set()) & uncovered:
                if source != target and (graph is observed or reached[source] & reached[target]):
                    pairs[source].add(target)
                    pairs[target].add(source)

    def join(values, table):
        return set().union(*(table.get(va, set()) for va in values))

    groups, remaining = [], set(uncovered)
    for seed in sorted(uncovered, key=lambda va: (-len(reached[va]), -len(incoming.get(va, ())), va)):
        if seed not in remaining:
            continue
        members = {seed}
        remaining.remove(seed)
        while len(members) < size:
            neighbors = (join(members, observed_pairs) | join(members, static_pairs)) & remaining
            if not neighbors:
                break
            neighbor = min(neighbors, key=lambda va: (-len(observed_pairs[va] & members),
                                                       -len(static_pairs[va] & members), -len(reached[va]), va))
            members.add(neighbor)
            remaining.remove(neighbor)
        observed_deps = join(members, observed) - members
        static_deps = join(members, static) - members
        dependencies = observed_deps | static_deps
        ready = dependencies & covered.keys()
        missing = dependencies - ready
        unknown_targets = join(members, unknown)
        uncertain_sites = {(va, *edge) for va in members for edge in unresolved.get(va, ())}
        callers = join(members, incoming) - members
        all_phases = join(members, reached)
        phase_reuse = len(all_phases)
        code_bytes = sum(indexed[va]["bytes"] for va in members)
        split = sorted(va for va in members if not indexed[va]["contiguous"])
        total = len(dependencies) + len(unknown_targets) + len(uncertain_sites)
        score = Fraction(len(ready), total) if total else Fraction(1)
        groups.append({"addresses": [hex(va) for va in sorted(members)], "code_bytes": code_bytes,
                       "phases": sorted(all_phases), "observed_callers": len(callers),
                       "readiness": {"verified_dependencies": len(ready), "total_known_or_unresolved": total,
                                     "noncontiguous_addresses": [hex(va) for va in split]},
                       "dependencies": {"verified": [hex(va) for va in sorted(ready)],
                                        "uncovered_indexed": [hex(va) for va in sorted(missing)],
                                        "observed": [hex(va) for va in sorted(observed_deps)],
                                        "static": [hex(va) for va in sorted(static_deps)],
                                        "unindexed_observed": [hex(va) for va in sorted(unknown_targets)],
                                        "unresolved_sites": len(uncertain_sites)},
                       "sort_key": (bool(split), -phase_reuse, -score, -len(callers), -code_bytes, seed)})
    groups.sort(key=lambda group: group.pop("sort_key"))
    return groups


def archived_inputs():
    result = subprocess.run(["git", "ls-files", "-z", "--", "reconstructed/match"],
                            cwd=ROOT, check=True, capture_output=True, text=True)
    tracked = {Path(name) for name in result.stdout.split("\0") if name}
    drafts = defaultdict(list)
    for path in sorted(tracked):
        if (path.suffix.lower() in {".c", ".cc", ".cpp", ".cxx"}
                and re.fullmatch(r"0x[0-9a-fA-F]+", path.stem)):
            if "asm" in path.parts:
                continue
            entry = {"path": str(path)}
            attempt = path.with_suffix(".json")
            if attempt in tracked:
                evidence = read_json(ROOT / attempt)
                entry.update(archived_evidence=str(attempt), first_difference=evidence.get("first_difference"),
                             difference_count=evidence.get("difference_count"))
            drafts[int(path.stem, 16)].append(entry)
    return drafts


def latest_audits(paths, image_sha256):
    latest = {}
    current_registry = file_sha256(REGISTRY)
    for priority, audit in enumerate(paths):
        directory = audit / "functions" if (audit / "functions").is_dir() else audit
        receipts = sorted(directory.glob("*.json"))
        if not receipts:
            raise ValueError(f"no per-function audit receipts at {directory}")
        for path in receipts:
            row = read_json(path)
            if row["executable_sha256"] != image_sha256:
                raise ValueError(f"audit SHA-256 differs from the pinned executable: {path}")
            address = int(row["address"], 16)
            sort = (row.get("symbol_registry_sha256") == current_registry, priority, path.stat().st_mtime_ns, str(path))
            if address in latest and latest[address][0] >= sort:
                continue
            source = row.get("source")
            result = {key: row.get(key) for key in ("source", "source_sha256", "match", "strict_match", "entry", "flags",
                                                   "symbol_registry_sha256", "first_difference", "difference_count", "error")}
            result.update(receipt=str(path), source_current=bool(source and row.get("source_sha256")
                          and file_sha256((ROOT / source).resolve()) == row["source_sha256"]),
                          strict_issues=row.get("strict_issues", [])[:MAX_DETAILS],
                          relocation_issues=row.get("relocation_issues", [])[:MAX_DETAILS])
            latest[address] = sort, result
    return {address: value for address, (_, value) in latest.items()}


def edge_order(edge):
    return (edge["resolution"] != "no_dispatch", edge.get("target_kind") == "hle_import",
            edge["kind"] not in {"indirect", "tail", "return_jump"}, -edge["count"], edge["phase_id"],
            edge["site"] or "", edge["target"] or "")


def write_packet(directory, ordinal, group, export, indexed, observations, inbound, audits, drafts, image_sha256,
                 paths, names, registry, classes):
    readiness = group["readiness"]
    lines = [f"# Replay work packet {ordinal}", "",
             f"{group['code_bytes']} indexed bytes across {len(group['phases'])} captured phases.",
             f"{readiness['verified_dependencies']} of {readiness['total_known_or_unresolved']} recorded external dependencies are linked.", ""]
    records = {}
    for address in group["addresses"]:
        va = int(address, 16)
        record = packets.base_record(address, export, paths, names, False)
        if record is None:
            raise ValueError(f"packet address is missing from the indexed export: {address}")
        edges = sorted(observations.get(va, ()), key=edge_order)
        incoming = sorted(inbound.get(va, ()), key=edge_order)
        record["abi_context"] = packets.abi_context(record, registry, classes)
        record["observed_edges"] = edges[:MAX_DETAILS]
        record["observed_edge_records"] = len(edges)
        record["observed_incoming"] = incoming[:MAX_DETAILS]
        record["observed_incoming_records"] = len(incoming)
        record["drafts"] = drafts.get(va, [])[:MAX_DETAILS]
        record["latest_audit"] = audits.get(va)
        record["contiguous_extent"] = indexed[va]["contiguous"]
        record["packet_key"] = f"{image_sha256}:{address}"
        for key in ("callers", "callees"):
            record[key] = record[key][:MAX_DETAILS]
        records[address] = record
        lines.extend([f"## {record['name']} `{address}`", "", f"- Exported body `{record['body']['pseudocode_path']}`"])
        if not record["contiguous_extent"]:
            lines.append("- Split body requires a noncontiguous extent recipe.")
        for draft in record["drafts"]:
            lines.append(f"- Archived draft `{draft['path']}`")
        if audit := record["latest_audit"]:
            lines.append(f"- Latest audit `{audit['receipt']}`")
            if audit["first_difference"]:
                lines.append(f"- First difference `{audit['first_difference']}`")
            elif issues := audit["strict_issues"] + audit["relocation_issues"]:
                lines.append(f"- First recorded blocker `{issues[0]}`")
        for edge in record["observed_edges"][:4]:
            lines.append(f"- {edge['kind']} from `{edge['site']}` to `{edge['target']}` in `{edge['phase']}` ({edge['resolution']})")
        for edge in record["observed_incoming"][:2]:
            lines.append(f"- Reached from `{edge['site']}` by `{edge['kind']}` in `{edge['phase']}` ({edge['resolution']})")
        lines.append("")
    stem = f"packet-{ordinal:02d}"
    write_json(directory / f"{stem}.json", {"schema": "pc2.function_batch.v1",
               "target": {"path": str(GAME.relative_to(ROOT)), "sha256": image_sha256},
               "batch": stem, "method": "replay_worklist", "group": group, "records": records})
    (directory / f"{stem}.md").write_text("\n".join(lines) + "\n")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--manifest", required=True, type=Path)
    parser.add_argument("--capture-report", required=True, action="append", type=Path)
    parser.add_argument("--audit", default=[], action="append", type=Path)
    parser.add_argument("--packets", type=int, default=3, choices=range(0, 11), metavar="N")
    parser.add_argument("--group-size", type=int, default=4, choices=range(1, 9), metavar="N")
    parser.add_argument("--out", required=True, type=Path, help="fresh output directory")
    args = parser.parse_args()
    try:
        image = pe_image(GAME)
        image_sha256 = hashlib.sha256(image[0]).hexdigest()
        if image_sha256 != PINNED_SHA256:
            raise ValueError("canonical executable SHA-256 differs from the pinned image")
        index = read_json(INDEX)
        if index["target_sha256"] != image_sha256:
            raise ValueError("decompile index differs from the pinned executable")
        export = {item["address"].lower(): item for item in index["functions"]}
        indexed = inventory(export)
        covered = verified_functions(read_json(args.manifest), image, indexed, image_sha256)
        static_graph = read_json(CALLGRAPH)
        if static_graph["target_sha256"] != image_sha256:
            raise ValueError("static call graph differs from the pinned executable")
        by_hex = {hex(va): va for va in indexed}
        static = {by_hex[va]: {by_hex[target] for target in record["calls"] if target in by_hex}
                  for va, record in static_graph["nodes"].items() if va in by_hex}
        captures = list(dict.fromkeys(path.resolve() for path in args.capture_report))
        phases, reached, observations, inbound, outgoing, incoming, unknown, unresolved = load_replays(
            captures, indexed, covered, image_sha256)
        uncovered = reached.keys() & indexed.keys() - covered.keys()
        groups = rank_groups(uncovered, indexed, covered, reached, outgoing, incoming, static, unknown, unresolved, args.group_size)
        audit_paths = list(dict.fromkeys(path.resolve() for path in args.audit))
        audits = latest_audits(audit_paths, image_sha256)
        args.out.mkdir(parents=True)
        names, paths = defaultdict(list), {}
        for address, record in export.items():
            names[record["name"]].append(address)
            path = packets.function_path(address)
            if Path(path).is_file():
                paths[address] = path
        if args.packets:
            drafts = archived_inputs()
            registry, classes = load_registry(image_sha256), registry_classes(image_sha256)
            for ordinal, group in enumerate(groups[:args.packets], 1):
                write_packet(args.out, ordinal, group, export, indexed, observations, inbound, audits, drafts, image_sha256,
                             paths, names, registry, classes)
        total = coverage(reached.keys(), indexed, covered)
        total["unindexed_reached"] = len(reached.keys() - indexed.keys())
        worklist = {"schema": "pc2.replay_worklist.v1", "executable_sha256": image_sha256,
                    "manifest": str(args.manifest.resolve()), "audits": [str(path) for path in audit_paths],
                    "union": total, "phases": phases, "uncovered": [hex(va) for va in sorted(uncovered)], "groups": groups}
        write_json(args.out / "worklist.json", worklist)
        lines = ["# Replay worklist", "", "Coverage counts indexed entries in saved capture phases.", "",
                 "| Phase | Linked entries | Linked bytes | Unindexed entries | Unresolved edges |",
                 "|---|---:|---:|---:|---:|"]
        for phase in phases:
            lines.append(f"| {phase['phase']} | {phase['linked_reached']}/{phase['indexed_reached']} | "
                         f"{phase['linked_bytes']}/{phase['indexed_bytes']} | {len(phase['unindexed'])} | {phase['unresolved_edge_records']} |")
        lines.extend(["", f"{len(uncovered)} uncovered indexed functions across {len(groups)} ranked groups.", ""])
        for ordinal, group in enumerate(groups[:args.packets], 1):
            lines.append(f"- [Packet {ordinal}](packet-{ordinal:02d}.md) contains "
                         f"{', '.join(group['addresses'])} across {len(group['phases'])} phases.")
        (args.out / "README.md").write_text("\n".join(lines) + "\n")
    except (OSError, ValueError, KeyError, TypeError, subprocess.CalledProcessError) as error:
        parser.exit(1, f"replay worklist: {error}\n")
    print(f"{len(phases)} phases, {total['linked_reached']}/{total['indexed_reached']} indexed entries, "
          f"{len(uncovered)} uncovered, {min(args.packets, len(groups))} packets: {args.out / 'worklist.json'}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
