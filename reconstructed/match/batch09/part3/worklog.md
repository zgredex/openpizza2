# batch09 part3 worklog

25 manifest records, reconstructed as genuine C/C++ with MSVC 6.0 SP3
(`/tmp/opencode/vc6-sp3-toolchain/VC98`, `/O2`; `/TP` where member functions
are needed). Every accepted file reports `"strict_match": true` from
`tools/match_decomp.py` with the manifest length, exact entry symbol,
`--strict --auto-symbols`, and an explicit `--symbol` only for C++ member
callees that the auto resolver cannot undecorate.

## Result

```text
strict matches: 22 / 25
```

Matched: 0x47e180, 0x47e1d0, 0x480ba0, 0x48f860, 0x4d34e0, 0x4e0f40,
0x4f57a0, 0x4f5c20, 0x4f7e80, 0x507b40, 0x5090e0, 0x50e6b0, 0x510340,
0x51fb00, 0x525b70, 0x532aa0, 0x534d60, 0x53e140, 0x53e190, 0x541ca0,
0x548070, 0x54b160.

## Non-matching (kept under `nonmatching/`)

- `0x4d31f0 Car_Construct`: candidate is also 66 bytes but the compiler
  schedules the first call differently (`mov DAT_0057c670,%eax` /
  `mov 4(%esp),%edx` before the prologue instead of
  `push %esi; mov %ecx,%esi; mov 8(%esp),%ecx; push $0`). First difference is
  offset 0 (`0x56` vs `0x8b`); 43 differing bytes.
- `0x4ef0c0 Record_GetScreenSortY`: compiled candidate extent is 80 bytes
  against the 67-byte manifest extent, and the parameter/saved-pointer
  registers are swapped relative to the original. First difference is offset 1
  (`0x56` vs `0x8b`); 54 differing bytes.
- `0x505e60 UI_SetChildTracking`: the original contains a live-only
  `cmp $1,%eax` against its first argument with no conditional branch
  (a dead compare that VC6 does not emit from the reconstructed C++ source),
  and the remaining register allocation differs. First difference is offset 0
  (`0x57` vs `0x8b`).

## Verify

```sh
sh reconstructed/match/batch09/part3/verify_strict.sh
```

The script checks the 22 accepted files and prints the three known
non-matching records.
