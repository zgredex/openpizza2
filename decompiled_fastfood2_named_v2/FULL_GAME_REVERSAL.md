# Full game function map — complete (3,029 / 3,029)

**Every game function is named. 3,029/3,029 exact name matches, 0 unnamed, 0 mismatches.**

## Final verification

Fresh REA export in `full_game_verification/`:

```text
game functions: 3029
named in export: 3029
exact name matches: 3029
unnamed: 0
mismatch: 0
cascade exact: 596 / 596
blockers exact: 59 / 59
```

The complete durable mapping is `full_game_symbols.json` (3,029 entries), applied to REA with **0 failures**.

## 14-layer cascade

| Layer | Named |
|---|---:|
| 1 | 69/69 |
| 2 | 92/92 |
| 3 | 118/118 |
| 4 | 118/118 |
| 5 | 37/37 |
| 6 | 55/55 |
| 7 | 29/29 |
| 8 | 26/26 |
| 9 | 18/18 |
| 10 | 13/13 |
| 11 | 11/11 |
| 12 | 5/5 |
| 13 | 3/3 |
| 14 | 2/2 |

All 596 dependent functions and all 59 blocker functions verified by exact name.

## Coverage notes

- `func_symbols.csv`: **2,471 non-leaf names**
- `leaf_symbols.csv`: **480 leaf names**
- 78 additional game functions were already named in earlier layer exports
- Total: **3,029 / 3,029 game functions**
- 885 unnamed functions remain outside the game range (CRT/compiler support above `0x555590`, thunks, and non-game library code)

## Typed packet coverage

Two typed batches are checked in. `typed_packets/free_play_start.json` has 10
records and 40 ordered trace steps; it includes the callback at `0x4cc640`,
which is not a named procedure. `typed_packets/clock_worker.json` has 11
records and 40 trace steps; it recovers the worker at `0x4dd300`, follows
`0xfffe79f7` to `0x405ae0`, follows `0xfffe79de` through the command table to
`0x405aa9`/`Game_EndOfHour`, resolves controls `0x411..0x415` to city-view pest
animations, and identifies `0x55c090` as `WaitForSingleObject`. Both packets are
keyed by executable SHA-256 and PE address and record recovered signatures,
dispatch targets, fields read/written, event order, fixtures and unresolved
questions. `tools/verify_typed_packet.py` regenerates both files, checks all
80 instruction-byte prefixes against the PE image and runs 15 mutation cases.
Human traces: `TYPED_FREE_PLAY_START.md` and `TYPED_CLOCK_WORKER.md`.
Bounded Unicorn fixtures execute `Game_GetStartingCapital` (12/12 cases) and
the `Game_WindowProc` command mapping (2/2 cases).

## What this means

The **function-level map is complete**. Every function in the main game range has a semantic name, and the full call graph is named.

The next phase is data reconstruction: globals, structs, enums, vtables, save/map/resource formats, and behavioral validation. The typed-packet layer records which parts of that reconstruction are established and which remain unresolved.
