# Byte-matched PC2 reconstruction

The shipped `game/fastfood2.exe` is MSVC 6.0 SP3: `C2.DLL` 12.00.8447 and
`LINK.EXE` 6.00.8447. The SP3 command-line tree is kept outside the repository
under `/tmp/opencode/vc6-sp3-toolchain/VC98`; set `PC2_VC6` to another tree if
needed.

A candidate is done only when `tools/match_decomp.py` reports `"match": true`.
It compiles with `/O2`, resolves COFF `DIR32`/`REL32` relocations to the original
image addresses, and compares the function bytes with the PE.

Example:

```sh
python3 tools/match_decomp.py 0x48d3a0 /tmp/candidate.c \
  --length 0x80 --entry _pc2_get_capital \
  --symbol _game_difficulty=0x57bb24
```

Batch 1 is 100 functions from `decompiled_fastfood2_named_v2/final655_batches.json`
(split into four 25-function parts under `batch01/`). Each worker owns one part
and writes candidates only under `batch01/partN/`. Keep worklogs in
`batch01/partN/worklog.md`; commit only matched C and tests. Never commit the
VC6 tree or the game image.

## Batch runner

`tools/match_batch.py` runs a part manifest and writes a JSON report:

```sh
python3 tools/match_batch.py reconstructed/match/batch01/part1.json \
  reconstructed/match/batch01/part1 --symbols reconstructed/match/batch01/part1/symbols.json \
  --json-out /tmp/pc2-part1.json
```

## Golden smoke test

`reconstructed/match/golden/0x48d3a0.c` reproduces `Game_GetStartingCapital`
byte-for-byte with the SP3 compiler:

```sh
python3 tools/match_decomp.py 0x48d3a0 reconstructed/match/golden/0x48d3a0.c \
  --length 0x80 --entry _pc2_get_starting_capital \
  --symbol _game_difficulty=0x57bb24
```

## Strict audit

Explicit `--symbol` maps are checked by default. `--strict` also checks the
full function extent, all relocation targets/addends, and rejects unverified
unwind sections; `--auto-symbols` resolves undefined symbols from
`full_game_symbols.json`. The wrong-target regression is:

```sh
python3 reconstructed/match/tests/test_relocation_guard.py
```

See `STRICT_AUDIT.md` for the separate strict count.
