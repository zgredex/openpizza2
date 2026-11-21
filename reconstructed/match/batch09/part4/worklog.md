# batch09 part4 worklog

25 manifest records, reconstructed as genuine C/C++ with MSVC 6.0 SP3
(`/tmp/opencode/vc6-sp3-toolchain/VC98`, `/O2`; `/TP` where member functions
are needed). Every accepted file reports `"strict_match": true` from
`tools/match_decomp.py` with the manifest length, exact entry symbol,
`--strict --auto-symbols`, and explicit `--symbol` entries only for C++ member
callees that the auto resolver cannot undecorate.

## Result

```text
strict matches: 23 / 25
```

Matched: 0x404760, 0x47a540, 0x480070, 0x486910, 0x4880c0, 0x4c7040,
0x4cb8b0, 0x4d1b30, 0x4d3940, 0x4de670, 0x4eeef0, 0x4f6dd0, 0x501980,
0x501df0, 0x502180, 0x5021d0, 0x5102f0, 0x520f30, 0x52f750, 0x53d040,
0x541290, 0x548430, 0x548db0.

## Non-matching (kept under `nonmatching/`)

- `0x54f000 _strcmp`: the decompile index records only the first 67 bytes
  (0x54f000-0x54f042), but the CRT routine continues at 0x54f044 and 0x54f04c
  and its internal branches target those blocks. A truthful C implementation
  emits the complete routine, so the strict extent check can never accept it
  for the truncated manifest extent. No byte comparison is attempted by the
  verify script.
- `0x4edee0 Map_BlitAlignedObjectSprite`: candidate is 68 bytes but VC6
  loads the surface parameter into `%eax` before the prologue and moves it to
  `%edi`, whereas the original does `push %esi; push %edi;
  mov 0x10(%esp),%edi; mov %ecx,%esi; test %edi,%edi`. First difference is
  offset 0 (`0x56` vs `0x8b`); the subsequent argument setup also differs.

## Verify

```sh
sh reconstructed/match/batch09/part4/verify_strict.sh
```

The script checks the 23 accepted files and prints the two known non-matching
records.
