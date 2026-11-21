# Strict byte-match audit

A normal `"match": true` compares instruction bytes with linker-resolved fields
normalized from the original PE. That is necessary for EH thunks and calls.
Explicit `--symbol` maps are now checked even without `--strict`, so a supplied
wrong target cannot pass. `--strict` additionally adds:

- exact candidate function extent (up to 15 bytes of `0x00`/`0x90`/`0xCC`
  alignment padding);
- every `DIR32`/`REL32` target and addend checked against the original PE;
- an independent symbol map (`--symbol` or `--auto-symbols`), not the original
  relocation bytes;
- rejection of unverified `.text$x` unwind sections.

`tools/match_batch.py --strict --auto-symbols` applies the gate to a whole part.
The regression test is:

```sh
python3 reconstructed/match/tests/test_relocation_guard.py
```

It compiles `0x532510` and supplies the wrong `Array::Destroy` address. The
default matcher rejects the wrong target because the explicit symbol map is
checked; strict mode rejects it as well. The correct target passes both.

## Current strict counts

```text
batch01 part1   6 / 9  C matches
batch01 part2  10 / 15 C matches
batch01 part3  11 / 12 C matches
batch01 part4  10 / 17 C matches
batch02 part1  12 / 25 C matches
batch02 part2  20 / 25 C matches
batch02 part3  21 / 25 C matches
batch02 part4  18 / 25 C matches
total         108 / 153 C matches
```

The remaining strict failures are mostly missing independent symbol maps for
calls/globals and unverified `.text$x` unwind data, not byte differences. The
C-only codegen count remains 53/100 for batch 1 and 100/100 for batch 2.
