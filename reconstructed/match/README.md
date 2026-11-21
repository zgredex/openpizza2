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

## Progress

```text
batch 1    53 / 100 C-only   (strict 51)
batch 2   100 / 100 C-only   (strict 88)
batch 3   100 / 100 strict
batch 4   100 / 100 strict
batch 5   100 / 100 strict
batch 6    98 / 100 strict
batch 7    98 / 100 strict
batch 8    92 / 100 strict
batch 9    88 / 100 strict
batch 10   91 / 100 strict
total     920 C-only / 906 strict of 953
```

Batches 5-9 are the next 500 smallest remaining functions and use the strict
extent/relocation gate. Nonmatching genuine C/C++ attempts are kept under each
part's `nonmatching/` directory with first-diff evidence.

The strict gate resolves PE import IAT slots, decorated C++ and data symbols
from the shipped symbol maps, and locates/validates `.text$x`, `.xdata$x`, and
anchored vtable COMDATs by masked byte search. Regressions:

```sh
python3 reconstructed/match/tests/test_relocation_guard.py
python3 reconstructed/match/tests/test_auto_symbols.py
```

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

## Stock CRT archive identification

```sh
python3 tools/match_crt_archive.py --json-out /tmp/pc2-crt-archive-report.json
python3 reconstructed/match/tests/test_crt_archive.py
```

The scanner defaults to `LIBC.LIB` and `LIBCMT.LIB` under `PC2_VC6` (or the SP3
tree above). To use other copies, pass the archive paths as positional
arguments. Wine and the compiler are unnecessary for this scan.

The report groups archive variants by PE address. Exact comparisons use
complete, contiguous game function bodies and COFF code sections with one
entry, or a function-definition auxiliary size. Relocated comparisons require
every i386 `DIR32` and `REL32` field to resolve with its addend. The scanner
uses same-section placement, unique exact anchors, or explicit external
addresses provided as `--symbol NAME=0xADDRESS`. An unresolved symbol remains
a candidate. Distinct archive identities with the same bytes are marked
ambiguous. These results measure equivalence to stock objects independently
of the C reconstruction counts and do not identify original compiler flags.

With the pinned SP3 archives and shipped executable, 43 PE locations have
verified bytes, including 33 with a single identity. `intrncvt.obj` contributes
three raw matches at `0x555896` (`__CopyMan`), `0x5558b1` (`__FillZeroMan`), and
`0x5558bd` (`__IsZeroMan`). The JSON records input hashes and relocation
evidence. Generate the report locally with the command above.
