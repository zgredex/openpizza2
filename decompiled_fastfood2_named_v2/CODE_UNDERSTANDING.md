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
| Named functions | 3919 (100.0%) |
| Unique data addresses referenced | 3611 |
| Named data addresses | 3611 (100.0%) |
| Data references resolved | 16556 / 16556 (100.0%) |

The 62 previously unnamed functions are the MSVC CRT block at
`0x555605-0x557b98` (floating-point control, 64-bit helpers, locale/codepage,
string/environment helpers). They are named in `symbols.csv` and were renamed
in REA; for example `0x555605` is `CRT_ControlFP` and decompiles to
`CRT_ControlWordFromFPFlags` / `CRT_FPFlagsFromControlWord`.

Unicorn checks for the named CRT behavior (`tools/emulate_crt_helpers.py`,
8/8): control-word mapping round-trip, `strcspn`, `strpbrk`, `strnlen`, and
32-bit add-with-carry. The executable is mapped at its preferred base and each
helper is called at its original entry, so these are behavior checks on the
shipped bytes, not reimplementations.

## Data-name confidence tiers

`data_symbols.csv` has 3611 entries:

| Confidence | Count | Meaning |
|---|---:|---|
| high | 3046 | semantic name, type and decompiled reader/writer set audited |
| medium | 565 | owning function and role observed; type/readers still pending |
| low | 0 | address-only alias removed |

The first audit pass promoted 451 medium rows (12 settings globals plus 439
type/reader-audited globals). Settings globals were verified with Unicorn by
calling `Settings_InitDefaults` (`0x406a90`) with the registry loader stubbed to
fail; the probe reads back 17 globals, including autosave interval `5`, slot
count `4`, language index `3`, and free-play length `0xb`.

The ingredient pass promoted 87 entries. `Language_CopyStringIds` fills
`0x583544..0x58369c` with 86 consecutive `language.ldf` strings, indices
487..572 (Tomatoes..Garlic), and `Ingredient_LoadMarketTable` passes entry `i`
to `Game_SetBuildingDesc` for ingredient object `i`. Unicorn calls
`Game_SetBuildingDesc` with the Olives descriptor and reads back the name at
object `+0x88` and the numeric fields at `+0xa8..+0xc8`.

Promotion rules used in this pass:

- 24 serialized globals named from `save_schema.json` writers;
- 115 literal strings named from their pooled bytes;
- 14 BSS objects named from `InitializeCriticalSection`, `CreateEventA`,
  `SetRect`, `NamedLockable_Construct` or another constructor;
- 658 BSS globals named from the first-use function and role
  (`Flag`, `Array`, `Const`, `<call>Result`, `<call>Arg`);
- 42 read-only entries classified as GUID, function table or string pointer;
- 387 remaining read-only entries named from their first-use role.

2367 of the high-confidence names come from `Language_MapStrings`
(`0x5146d0`), which assigns specific `language.ldf` entries to globals; those
are named `g_Text_<index>_<slug>`.

The 1103 medium entries are deliberately not presented as fully understood.
They have an observed owner and role, but their byte-level type and full reader
set still need auditing before promotion to high confidence.

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
