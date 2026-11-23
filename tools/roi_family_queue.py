#!/usr/bin/env python3
"""Read-only, audit-aware OpenPizza2 family ROI queue.

It NEVER claims new strict matches. It identifies candidate bytes and missing bytes,
subtracts globally audited strict addresses and de-duplicates repeated addresses.
Use a fresh tools/audit_matches.py snapshot for authoritative statuses.

Usage:
    python3 tools/roi_family_queue.py \
        --registry /tmp/pc2-registry/registry.json \
        --audit /tmp/pc2-audit \
        --out /tmp/pc2-queue.md --json-out /tmp/pc2-queue.json
"""

import argparse
from collections import defaultdict
import json
from pathlib import Path


def addr(value):
    return int(value, 0) if isinstance(value, str) else int(value)


def load_audit(directory):
    confirmed = set()
    if directory is None:
        return confirmed
    for path in sorted((directory / "functions").glob("*.json")):
        try:
            row = json.loads(path.read_text(encoding="utf-8"))
            if isinstance(row, dict) and row.get("strict_match") is True:
                confirmed.add(addr(row["address"]))
        except (OSError, KeyError, ValueError, TypeError, json.JSONDecodeError) as error:
            print(f"warning: ignored {path}: {error}")
    return confirmed


def summarize(payload, audit_strict):
    if payload.get("schema") != "pc2.family_registry.v1":
        raise ValueError("expected pc2.family_registry.v1")
    families = payload.get("families", [])
    if not isinstance(families, list):
        raise ValueError("registry families must be a list")

    # Families overlap. An address is always counted once in global potential.
    # The registry can be stale between pushes; audited strict matches override it.
    by_addr = defaultdict(list)
    for family_no, family in enumerate(families):
        for member in family.get("members", []):
            a = addr(member["address"])
            n = int(member["length"])
            if n <= 0:
                continue
            by_addr[a].append((family_no, n, member))
    known_strict = set(audit_strict)
    for a, mentions in by_addr.items():
        if any(m.get("status") == "strict" for _, _, m in mentions):
            known_strict.add(a)
    canonical = {}
    for a, mentions in by_addr.items():
        sizes = {n for _, n, _ in mentions}
        if len(sizes) > 1:
            print(f"warning: conflicting indexed lengths at {a:#x}: {sorted(sizes)}")
        canonical[a] = max(sizes)

    def category(m):
        if m.get("status") in {"candidate", "generated"}:
            return "ready"
        if m.get("status") == "source_only":
            return "source_only"
        return "missing"

    rows = []
    for i, f in enumerate(families):
        addr_members = {}
        for m in f.get("members", []):
            a = addr(m["address"])
            if a in known_strict:
                continue
            # This member may appear duplicated within one family. Prefer ready.
            old = addr_members.get(a)
            order = {"ready": 2, "source_only": 1, "missing": 0}
            if old is None or order[category(m)] > order[category(old)]:
                addr_members[a] = m
        buckets = {"ready": 0, "source_only": 0, "missing": 0}
        counts = {"ready": 0, "source_only": 0, "missing": 0}
        for a, m in addr_members.items():
            kind = category(m)
            buckets[kind] += canonical[a]
            counts[kind] += 1
        rows.append({
            "family": f.get("cleanup_name") or f.get("cleanup_target") or f"family-{i}",
            "key": f.get("cleanup_target") or f"family-{i}",
            "unmatched_bytes": sum(buckets.values()),
            "ready_bytes": buckets["ready"],
            "source_only_bytes": buckets["source_only"],
            "missing_bytes": buckets["missing"],
            "unmatched_functions": len(addr_members),
            "ready_functions": counts["ready"],
            "missing_functions": counts["missing"],
            "addresses": set(addr_members),
        })

    pending = set(canonical) - known_strict
    union_bytes = sum(canonical[a] for a in pending)

    # Two distinct views: ready-to-verify work and generator discovery.
    ready_order = sorted(rows, key=lambda r: (-r["ready_bytes"], -r["unmatched_bytes"], r["key"]))
    discovery_order = sorted(rows, key=lambda r: (-r["missing_bytes"], -r["unmatched_bytes"], r["key"]))

    def assign(rows_in):
        seen = set()
        answer = []
        for r in rows_in:
            unique = r["addresses"] - seen
            # Rows intentionally contain only aggregate ready categories.
            # The marginal figure is always unique unmatched bytes, not a promise of success.
            answer.append({k: v for k, v in r.items() if k != "addresses"} | {
                "unique_unmatched_bytes": sum(canonical[a] for a in unique),
                "overlap_addresses_seen_before": len(r["addresses"] & seen),
            })
            seen.update(r["addresses"])
        return answer

    return {
        "schema": "pc2.roi_family_queue.v1",
        "registry_sha256": payload.get("executable_sha256"),
        "strict_indexed_addresses": len(set(canonical) & known_strict),
        "pending_unique_addresses": len(pending),
        "pending_unique_bytes": union_bytes,
        "total_family_rows": len(rows),
        "ready_lane": assign(ready_order),
        "discovery_lane": assign(discovery_order),
    }


def render(report, top):
    lines = [
        "# OpenPizza2 coverage-aware family queue", "",
        "This is a **triage estimate**, not strict-match evidence. Bytes refer to indexed",
        "function extents, not linker/secondary sections or confirmed future gains.",
        "A single address may occur in several family groups; do not add row totals.", "",
        f"- Unique pending indexed bytes: **{report['pending_unique_bytes']:,}**",
        f"- Unique pending addresses: **{report['pending_unique_addresses']:,}**",
        f"- Already strict indexed addresses: **{report['strict_indexed_addresses']:,}**", "",
    ]
    for title, key, condition in (
        ("Lane A — ready candidates to verify", "ready_lane", lambda r: r["ready_bytes"] > 0),
        ("Lane B — missing-source families to investigate", "discovery_lane", lambda r: r["missing_bytes"] > 0),
    ):
        lines += [f"## {title}", "",
                  "| Family | Pending B | Ready B | Missing B | Marginal unique B | Functions |",
                  "|---|---:|---:|---:|---:|---:|"]
        rows = [row for row in report[key] if condition(row)][:top]
        for r in rows:
            lines.append(f"| `{r['key']}` | {r['unmatched_bytes']:,} | {r['ready_bytes']:,} | "
                         f"{r['missing_bytes']:,} | {r['unique_unmatched_bytes']:,} | "
                         f"{r['unmatched_functions']} |")
        lines += ["", "Marginal unique bytes depend on sorting in this lane and must not be added across lanes.", ""]
    lines += [
        "## Next-step gate", "",
        "Choose families by actual repeated instruction shapes, not only shared calls.",
        "Pilot simple + typical + held-out member; scale only after a clean held-out strict match.",
        "After each batch, rerun affected verifiers and refresh the audit/registry.",
    ]
    return "\n".join(lines) + "\n"


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--registry", required=True, type=Path)
    ap.add_argument("--audit", type=Path)
    ap.add_argument("--out", type=Path, required=True)
    ap.add_argument("--json-out", type=Path)
    ap.add_argument("--top", type=int, default=15)
    args = ap.parse_args()
    try:
        payload = json.loads(args.registry.read_text(encoding="utf-8"))
        result = summarize(payload, load_audit(args.audit))
        args.out.parent.mkdir(parents=True, exist_ok=True)
        args.out.write_text(render(result, args.top), encoding="utf-8")
        if args.json_out:
            args.json_out.parent.mkdir(parents=True, exist_ok=True)
            args.json_out.write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
        print(f"{result['pending_unique_bytes']:,} pending indexed B across "
              f"{result['pending_unique_addresses']} unique addresses; see {args.out}")
    except (OSError, ValueError, TypeError, KeyError, json.JSONDecodeError) as exc:
        ap.exit(2, f"queue error: {exc}\n")


if __name__ == "__main__":
    main()
