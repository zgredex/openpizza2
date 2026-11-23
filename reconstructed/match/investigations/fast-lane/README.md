# Fast-lane family queue

`tools/roi_family_queue.py` is a read-only triage layer over the family
registry. It ranks families by ready-to-verify bytes and by missing-source
bytes, subtracts addresses that a fresh audit already proves strict, and
de-duplicates addresses that appear in several overlapping families. It never
claims a match; every address still needs the pinned VC6 SP3 toolchain and
`tools/match_decomp.py --strict --auto-symbols`.

The operating protocol is in [`AGENT_FAST_LANE.md`](AGENT_FAST_LANE.md).

## Refresh once per HEAD

```sh
python3 tools/audit_matches.py --out /tmp/pc2-audit-base --jobs 8
python3 tools/map_vc6_cleanup_families.py --out /tmp/pc2-cleanup.json
python3 tools/mine_feature_families.py \
  --out /tmp/pc2-features.json --report /tmp/pc2-features.md
python3 tools/build_family_registry.py \
  --inventory /tmp/pc2-cleanup.json \
  --features /tmp/pc2-features.json \
  --audit /tmp/pc2-audit-base \
  --out /tmp/pc2-registry.json --report /tmp/pc2-registry.md \
  --specs-out /tmp/pc2-family-specs
python3 tools/roi_family_queue.py \
  --registry /tmp/pc2-registry.json --audit /tmp/pc2-audit-base \
  --out /tmp/pc2-queue.md --json-out /tmp/pc2-queue.json
```

Before a new shape investigation, query
[`reconstructed/match/compiler-fingerprints/`](../../compiler-fingerprints/README.md)
with `tools/lookup_fingerprint.py`. Reuse a proven source pattern before
spending compile attempts.

Read `/tmp/pc2-queue.md`. Lane A is already-sourced work to verify; Lane B is
missing-source work to group by a repeated compiler/source shape. A shared
call target or cleanup target is only a discovery lens, not proof that the
members share a source template.

## Cost rules

- Reuse `tools/run_family_batch.py` with `--cache /tmp/pc2-coff-cache` and a
  fresh `--out` directory per run.
- Keep per-shape attempts bounded; record exact first-difference evidence and
  switch families when a proposal stops changing the fingerprint.
- Run the affected verifier per iteration and the full `verify_all.py` only at
  commits or milestones.
