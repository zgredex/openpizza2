# Code-understanding ledger

This file tracks a measurable, evidence-backed reading of the shipped
`fastfood2.exe`. It is not a claim that every line is understood yet.

## What "100%" means here

A subsystem counts as understood only when all four layers are present:

1. **Control flow** — every function in the subsystem is identified and its
   callers/callees are known.
2. **Names** — functions and referenced globals have semantic names, not
   `FUN_*` / `DAT_*`.
3. **State layout** — the fields read or written by the subsystem are mapped to
   the save/game structs.
4. **Behavior** — at least one static (REA) and one dynamic (Unicorn or live
   replay) observation agrees with the stated behavior.

The mechanical coverage score is printed by `tools/symbol_coverage.py`. Names
only count when `decompiled_fastfood2_named_v2/data_symbols.csv` has an
evidence string for the address.

## Baseline (2026-11-19)

| Metric | Value |
|---|---:|
| Decompiled function files | 3919 |
| Named functions | 3857 (98.42%) |
| Unique data addresses referenced | 2450 |
| Named data addresses | 16 (0.65%) |
| Data references resolved | 6331 / 15268 (41.47%) |

The 16 names cover 41.47% of all global references because the language/UI/game
singletons dominate the call sites. The long tail is large; add names only with
evidence.

## Verified: London mission goals

`Mission_EvaluateGoals` (`0x4f5fd0`) switches on the three goal ids copied from
the city definition. The city description table starts at language index 1111
(`g_MissionGoalTextAnchor` → `g_MissionGoalTexts`):

| Goal | Description | Shipped test | Evidence |
|---:|---|---|---|
| 0 | Build a Level 3 HQ | `Game_GetPlayerFieldC20(player) > 2` | `0x4f607c`; HQ completion path increments C20 in `0x4d8d50` case `0x1c` |
| 1 | Place a rat in a competing restaurant | mission-state `+0x14 > 0` | `0x4f608f`; `Object_UpdateBranchOpenClose` action 3 calls `Array_SetSlot(mission_state, 1, 1)` at `0x408a70` |
| 2 | Buy a restaurant | `Game_CountRecordsWithFlag16F4(player) != 0` | `0x4f609f`; leased/owned branch record flag `+0x16f4` |

Dynamic check (`tools/emulate_mission_goals.py`, 9/9 cases):

```text
goals [0,1,2] progress1=0 c20=0 flags=0 -> completed [0,0,0]
goals [0,1,2] progress1=1 c20=0 flags=0 -> completed [0,1,0]
goals [0,1,2] progress1=0 c20=2 flags=0 -> completed [0,0,0]
goals [0,1,2] progress1=0 c20=3 flags=0 -> completed [1,0,0]
goals [0,1,2] progress1=0 c20=3 flags=1 -> completed [1,0,1]
goals [0,1,2] progress1=1 c20=3 flags=1 -> completed [1,1,1]
```

The `array` probe also shows that calling `Array_SetSlot(mission, 1, 1)`
writes `mission+0x14 = 1` (the exact field goal 1 reads).

## Playable mapping

The window uses the verified meaning, not the earlier branch-count guess:

* lease the London storefront → goal 2;
* `H` three times in the city → goal 0;
* `R` in the city (rival exists) → goal 1;
* all three complete → `MISSION COMPLETE` banner.

## Next naming batches

1. UI/handles: `0x57c5c8` (renderer/surface), `0x57c5cc` (world/map object),
   `0x57c1e0` (debug console), `0x57c5e0` (done), `0x57c5d8` (done).
2. Mission/state: `0x57bb20` (`g_IsFreePlay`, medium confidence), `0x57bb24`,
   `0x57bb28`, `0x57bb2c`, `0x57bb30`, `0x57bb38`, `0x57bb3c`.
3. Text tables: `0x582e4c` (empty string), `0x582d68`, `0x583544`, etc.
4. City/player structs: promote observed offsets into named class skeletons.

Do not rename a global without a code path or runtime probe that pins its
meaning; a wrong name is worse than `DAT_`.
