# Batch 2: 100 small functions

The manifests select the 100 smallest remaining game functions (8-220 bytes)
after batch 1, excluding CRT/runtime wrappers. Each part is owned by one worker
and writes only under its `partN/` directory.

Rules:

- exact C/C++ only; `tools/match_batch.py` rejects `__asm`/`asm {` by default;
- run `tools/match_decomp.py` per function and keep only `"match": true`;
- put failed C attempts under `partN/nonmatching/`, not in the matched set;
- write `verify_c.sh` and `worklog.md` for the part.
