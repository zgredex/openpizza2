# batch12 part1 worklog

Target: `game/fastfood2.exe`, MSVC 6.0 SP3 (`C2.DLL 12.00.8447`). All
candidates are genuine C++ (`/O2 /TP`, no inline assembly).

Result: **18 / 25 strict matches** (`"strict_match": true`, exact manifest
length, explicit `--entry`, `--strict --auto-symbols`).

## Strict matches

| address | function | bytes | notes |
|---|---:|---:|---|
| 0x4da2a0 | City_ChargePoliceBribes | 89 | loop over six player slots, thiscall `CanAffordWithCurrency` |
| 0x4da700 | Stats_GetPlayerSharePercent | 89 | rating total then `(100 - value) * 100 / total` |
| 0x4da760 | Game_ComputeRatingShare | 89 | same shape as previous with offset 0xc98 |
| 0x502c50 | Building_GetRandomResidentCount | 89 | `Random_RangeFast(0,1)` and resident table |
| 0x50fdf0 | Game_ResetStats | 89 | nine scalar stores then four-stride clear loop |
| 0x527dc0 | UI_GetScrollRatio | 89 | `__int64` arguments and 1000.0 scaling |
| 0x53fc40 | SoundBuffer_ConstructBase | 89 | two vtable stores, dllimport `InitializeCriticalSection` |
| 0x480b40 | Game_IsRatingBelowThreshold | 90 | eight-entry threshold table, `return level > limit` |
| 0x48cbb0 | Sound_RefreshMusicSelection | 90 | caches company id in a local before the call |
| 0x4e2950 | Game_RefreshBuildingCondition | 90 | `volatile` increment pins store before count load |
| 0x501e40 | Game_GetActivityVolumeBand | 90 | single accumulator gives the original register use |
| 0x50fab0 | GamePlan_GetCompanyCategoryMetric | 90 | jump table order 1,2,4,8 |
| 0x512c40 | Recipe_AccumulateQualityDelta | 90 | `abs` intrinsic reproduces `cdq/xor/sub` |
| 0x53a140 | Gfx_BuildBlendTable | 90 | `i * j / 15.0`, `__ftol` call |
| 0x47aac0 | Game_CountObjectsByType | 91 | map at 0x1500, count at 0x1514 |
| 0x47cc70 | Game_CountRecordsByPair | 91 | `char map[0x14]` keeps count at 0x170c |
| 0x4dc9a0 | City_PlaceObjectOnMap | 91 | `SpawnByKind` is a thiscall member (five stack args) |
| 0x510400 | Stats_GetMaxTimelineCount | 91 | `if (count > maximum)` gives `cmp eax,ebx; jle` |

## Unmatched

Best genuine C++ attempts are in `nonmatching/`; the first differing byte of
each is recorded here (matcher command uses the manifest length and the entry
symbol shown).

| address | function | candidate bytes | first diff | evidence |
|---|---:|---:|---|---|
| 0x4aec60 | Glossary_FillCityBuildingList | 89 | 0x1: original 0x55 (`push ebp`), candidate 0x8b | 65 diffs. The original passes the selection flag as branchy `push 1` / `push 0`; the C++ form emits `sete`+`push`. Register allocation also swaps window/entry (`ebp`/`ebx` vs `ebx`/`edi`). |
| 0x4af5c0 | Glossary_FillPeopleNameList | 89 | 0x1: original 0x55, candidate 0x8b | 63 diffs; same shape as 0x4aec60. |
| 0x4d22c0 | Map_ApplyRandomTileVariant | 89 | 0x26: original 0x46 (`mov eax,[esi+0x54]`), candidate 0x56 (`mov edx,...`) | 7 diffs. Also offsets 0x4c-0x50: original pushes the value then loads `ecx=array`; candidate loads `ecx` first. |
| 0x4de300 | Stats_GetMaxObjectMatrixValue | 89 | 0x1: original 0x53 (`push ebx`), candidate 0x8b | 73 diffs. Original copies `this` to `ebx` before loading the parameter into `ecx`; candidate keeps the parameter in `eax` and reorders the loop setup. |
| 0x52e4b0 | Tooltip_Construct | 89 | 0x3: original 0xb9 (`mov ecx,0xa`), candidate 0x8b | 26 diffs. Original materialises the constant 10 in `ecx`, then reuses `ecx` for both parameters. |
| 0x4872b0 | UI_ClearActiveRecordSlots | 91 | 0x6: original 0x55 (`push ebp`), candidate 0x56 (`push esi`) | 76 diffs. Original caches the record base in `ebp` and loads the flag with `xor ecx,ecx; mov cl,[...]; test ecx,ecx`; every natural C form compiles to `cmp byte ptr [...],0`. |
| 0x50d790 | AI_WanderToRandomRoadTile | 91 | 0x1e: original 0x50 (`push eax`), candidate 0x8b (`mov ecx,esi`) | 6 diffs. The first `AdvanceRoute` call only differs in argument/`ecx` setup order. |

## Verification

```sh
python3 tools/match_batch.py reconstructed/match/batch12/part1.json \
  reconstructed/match/batch12/part1 --flags "/O2 /TP" --strict --auto-symbols
# matched 18/25; strict 18/25

sh reconstructed/match/batch12/part1/verify_strict.sh
# strict 18/18
```

`nonmatching/evidence.md` records the raw matcher evidence for the seven
failures.
