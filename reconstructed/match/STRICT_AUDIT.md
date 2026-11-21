# Strict byte-match audit

A normal `"match": true` compares instruction bytes with linker-resolved fields
masked for code generation comparison.
Explicit `--symbol` maps are now checked even without `--strict`, so a supplied
wrong target cannot pass. `--strict` additionally adds:

- exact candidate function extent (up to 15 bytes of `0x00`/`0x90`/`0xCC`
  alignment padding);
- every `DIR32`/`REL32` target and addend checked against the original PE;
- an independent symbol map (`--symbol` or `--auto-symbols`), not the original
  relocation bytes;
- automated resolution of PE import IAT slots, decorated C++ names, and data
  symbols from `data_symbols.csv`;
- masked byte-pattern location and relocation verification of `.text$x`,
  `.xdata$x`, and anchored data COMDATs (vtables) instead of rejecting them.

`tools/match_batch.py --strict --auto-symbols` applies the gate to a whole part.
The regression test is:

```sh
python3 reconstructed/match/tests/test_relocation_guard.py
```

It compiles `0x532510` and supplies the wrong `Array::Destroy` address. The
default matcher rejects the wrong target because the explicit symbol map is
checked; strict mode rejects it as well. The correct target passes both.

## Current verification

The full audit ran all 58 tracked verifiers and confirmed **1,020 of 1,180**
distinct committed C/C++ candidates under the independent relocation gate.
The other 160 matched the normalized function bodies and lacked complete
strict evidence. The audit recorded zero tool errors and zero body mismatches.
The verified set includes all six `runtime01` candidates. Pending worktree
candidates and stock CRT archive identifications are outside this count.
The strict matches cover **26.03%** of exported bodies (1,020 of 3,919) and
approximately **4.44%** of estimated inventory code bytes (54,878 of 1,236,452).

## Historical strict counts

This table predates the independent relocation gate. Use
`python3 tools/audit_matches.py --out /tmp/pc2-tracked-audit` to measure the
observed strict results under the current gate, or pass tracked verifier paths
to measure a subset.

```text
batch01 part1   9 / 9  C matches
batch01 part2  15 / 15 C matches
batch01 part3  12 / 12 C matches
batch01 part4  15 / 17 C matches
batch02 part1  24 / 25 C matches
batch02 part2  24 / 25 C matches
batch02 part3  22 / 25 C matches
batch02 part4  18 / 25 C matches
batch03 part1  25 / 25 C matches
batch03 part2  25 / 25 C matches
batch03 part3  25 / 25 C matches
batch03 part4  25 / 25 C matches
batch04 part1  25 / 25 C matches
batch04 part2  25 / 25 C matches
batch04 part3  25 / 25 C matches
batch04 part4  25 / 25 C matches
batch05 part1  25 / 25 C matches
batch05 part2  25 / 25 C matches
batch05 part3  25 / 25 C matches
batch05 part4  25 / 25 C matches
batch06 part1  25 / 25 C matches
batch06 part2  24 / 25 C matches
batch06 part3  25 / 25 C matches
batch06 part4  24 / 25 C matches
batch07 part1  24 / 25 C matches
batch07 part2  25 / 25 C matches
batch07 part3  25 / 25 C matches
batch07 part4  24 / 25 C matches
batch08 part1  23 / 25 C matches
batch08 part2  24 / 25 C matches
batch08 part3  23 / 25 C matches
batch08 part4  22 / 25 C matches
batch09 part1  22 / 25 C matches
batch09 part2  21 / 25 C matches
batch09 part3  22 / 25 C matches
batch09 part4  23 / 25 C matches
batch10 part1  24 / 25 C matches
batch10 part2  22 / 25 C matches
batch10 part3  22 / 25 C matches
batch10 part4  23 / 25 C matches
batch11 part1  21 / 25 C matches
batch11 part2  18 / 25 C matches
batch11 part3  23 / 25 C matches
batch12 part1  18 / 25 C matches
batch12 part2  20 / 25 C matches
batch12 part3  23 / 25 C matches
batch13 part1  12 / 25 C matches
batch13 part2  16 / 25 C matches
batch13 part3  16 / 25 C matches
batch13 part4  13 / 25 C matches
batch14 part1  15 / 25 C matches
batch14 part2   6 / 25 C matches
batch14 part3  18 / 25 C matches
batch14 part4   5 / 25 C matches
batch15 part1  16 / 25 C matches
batch15 part3  10 / 25 C matches
batch15 part4   4 / 25 C matches
total        1160 / 1174 C matches
```

Batches 11-15 were paused mid-run. The totals above include only committed
part directories. The following verified work is still uncommitted in the
worktree: batch11 part4 (17 strict), batch12 part4 (10 strict), and batch15
part2 (2 strict). If those are committed later the totals become
1203 C matches, of which 1189 are strict.

This is an increase from 875 strict matches after the checker learned to
resolve IAT imports, decorated/data symbols, EH funclets, and anchored data
COMDATs. No new C candidates were required for the increase.

The remaining strict failures are mostly unnamed static helpers or data
objects that have no entry in either symbol map, not byte differences. The
C-only codegen count remains 53/100 for batch 1 and 100/100 for batch 2.
Batches 3-10 use the strict gate for every accepted function.

## Reproduce

```sh
# Batch 1: per-part scripts already carry the entry/flags/symbol maps.
PC2_STRICT=1 PC2_AUTO_SYMBOLS=1 sh reconstructed/match/batch01/part1/verify.sh
PC2_STRICT=1 PC2_AUTO_SYMBOLS=1 bash reconstructed/match/batch01/part2/verify_matches.sh
PC2_STRICT=1 PC2_AUTO_SYMBOLS=1 bash reconstructed/match/batch01/part3/verify_c.sh
PC2_STRICT=1 PC2_AUTO_SYMBOLS=1 python3 reconstructed/match/batch01/part4/verify.py

# Auto-symbol and unwind regressions.
python3 reconstructed/match/tests/test_auto_symbols.py
python3 reconstructed/match/tests/test_relocation_guard.py

# Batch 9: per-function flags (some C, one /O1).
sh reconstructed/match/batch09/part1/verify_strict.sh
sh reconstructed/match/batch09/part2/verify_strict.sh
sh reconstructed/match/batch09/part3/verify_strict.sh
sh reconstructed/match/batch09/part4/verify_strict.sh

# Batch 2: manifests plus auto symbol resolution.
for p in 1 2 3 4; do
  python3 tools/match_batch.py reconstructed/match/batch02/part$p.json \
    reconstructed/match/batch02/part$p --flags "/O2 /TP" \
    --strict --auto-symbols
done
```
