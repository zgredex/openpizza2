# batch14 part4 worklog

Target: `game/fastfood2.exe`, MSVC 6.0 SP3 (`C2.DLL` 12.00.8447).
Every accepted file is genuine C/C++ with no inline assembly and reports
`"strict_match": true` from `tools/match_decomp.py` with the manifest length,
an exact `--entry`, and `--strict --auto-symbols`.

Result: **5 / 25 strict matches**. The part is **not complete**: eleven
records have documented non-matching C attempts and nine records were not
attempted before work stopped. It is therefore left uncommitted.

## Strict matches

| address | function | bytes | flags | notes |
|---|---:|---:|---|---|
| 0x51fa80 | UI_EnsureBackBufferWindow | 124 | `/O2 /GX /TP` | `new Window(...)`; `Window` size must be 0x11c for the EH frame |
| 0x4dc6a0 | Calendar_InterpolateMonthlyValue | 125 | `/O2 /TP` | byte loads stored into `int` locals; combined `/12` magic |
| 0x4ddfb0 | Game_FindTopScoringCompany | 125 | `/O2 /TP` | `result` assigned before `best`; score compared on the left |
| 0x54c5b0 | Sound_DestroyObject | 126 | `/O2 /TP` | virtual `Release(1)` via vtable slot 0 |
| 0x4a5360 | UI_RemoveProfileStatElements | 127 | `/O2 /TP` | ten `RemoveObjectByKey` calls |

## Non-matching attempts (`nonmatching/`)

| address | function | diffs | first diff | summary |
|---|---:|---:|---|---|
| 0x4de280 | Stats_SumRecordFloatMatrix | 53 | offset 52: original `7e`, candidate `7f` | early return in the original reloads the `float total` local; VC6 folds it to the 0.0 constant here |
| 0x4de4f0 | Stats_SumGroupScores | 53 | offset 52: original `7e`, candidate `7f` | same float-local early-return shape as 0x4de280 |
| 0x47ea30 | Branch_UpdateConstructionQueue | 107 | offset 0: original `53`, candidate `51` | total stays in `ebp`; candidate spills it and hoists the map address |
| 0x4cb520 | ListDialog_FillRows | 52 | offset 24: original `02`, candidate `06` | `baseA`/`baseB` register assignment differs (`edi`/`ebx` vs `eax`/`ecx`) |
| 0x4fe570 | Company_OptimizeMenuPricing | 84 | offset 5: original `56`, candidate `55` | company pointer gets `esi` in the original, `ebp` in the candidate |
| 0x521dd0 | UI_RenderDrawCommand | 71 | offset 9: original `f1`, candidate `f9` | `this` is in `esi` in the original and `edi` in the candidate |
| 0x4013a0 | List_Construct | 10 | offset 111: original `5b`, candidate `c7` | only the `pop ebx` position before the final `limit` store differs |
| 0x483c90 | Game_FindFreeObjectByOwner | 104 | offset 0: original `83`, candidate `81` | original spills map pointer and count to the stack; candidate keeps them in registers |
| 0x4ee640 | Map_GetObjectNeighborCell | 85 | offset 16: original `8d`, candidate `8b` | original computes the entry address with `lea` before loading `+8` |
| 0x4f13d0 | List_RemoveObject | 113 | offset 1: original `55`, candidate `56` | original keeps `found` in `ebx` and the constant 1 in `ebp`; candidate uses `bl`/`edi` |
| 0x502430 | Game_GetStatBandByIndex | 1 | offset 8: original `6f`, candidate `6c` | default block should reload the parameter; compiler reuses `eax`, so the jump-table base shifts by one word |

## Not attempted

Stopped before writing candidates (no files):

- `0x5410b0 Sound_SetBufferVolume`
- `0x4850a0 Game_SetViewMode`
- `0x4db260 Array_MoveActiveSlotToRandom`
- `0x4e2860 Game_FindAssignedSubrecord`
- `0x53f5d0 SoundSample_Destruct`
- `0x4eab80 World_FindNameIndex`
- `0x544840 SoundBuffer_GetFrequency`
- `0x4d3600 Gfx_BlitShiftedRect`
- `0x4de470 Stats_SumForPlayer`

## Verification

```sh
sh reconstructed/match/batch14/part4/verify_strict.sh
# strict 5/5
```

The script checks each accepted file with its manifest length, exact entry
symbol and flags (including `/GX` for 0x51fa80). Known non-matching records are
only in `nonmatching/`. No object or PDB artifacts are kept.
