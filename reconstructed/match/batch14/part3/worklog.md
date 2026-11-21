# batch14 part3 worklog

Target: `game/fastfood2.exe`, MSVC 6.0 SP3 (`C2.DLL` 12.00.8447).
Every accepted file is genuine C/C++ with no inline assembly and reports
`"strict_match": true` from `tools/match_decomp.py` with the manifest length,
an exact `--entry`, and `--strict --auto-symbols`.

Result: **18 / 25 strict matches**. The part is **not complete**: five records
have documented non-matching C attempts and two records were not attempted
before work stopped. It is therefore left uncommitted.

## Strict matches

| address | function | bytes | flags | notes |
|---|---:|---:|---|---|
| 0x505260 | UI_DestroyChildObject | 120 | `/O2 /TP` | list member at +0xc4 is a pointer |
| 0x5104f0 | Stats_AverageActiveCategories | 120 | `/O2 /TP` | single sum variable, separate loop |
| 0x548350 | Sound_UpdateVolumeByCitySize | 120 | `/O2 /TP` | COM-style `__stdcall` call through vtable +0x7c |
| 0x4817c0 | System_QueryMemoryInfo | 121 | `/O2 /TP` | `memset` after the null checks; dllimport IAT auto-resolved |
| 0x502810 | Game_IsInputIndexUsed | 121 | `/O2 /TP` | inner counter uses `j <= 7` |
| 0x502890 | Game_AnyBuildingRatingAbove | 121 | `/O2 /TP` | loop template |
| 0x502910 | Game_AnyBuildingCategoryRatingAbove | 121 | `/O2 /TP` | loop template |
| 0x502990 | Game_IsObjectStatAbove | 121 | `/O2 /TP` | loop template |
| 0x5314f0 | Array_GetBoundsByKey | 121 | `/O2 /TP` | repeated pair loads (aliasing prevents caching) |
| 0x47a3b0 | Branch_GetCustomerGroupRating | 122 | `/O2 /TP` | `flag` local reuses the dead parameter slot |
| 0x489e20 | Game_AnyBuildingReachesCellList | 122 | `/O2 /TP` | count is `IDMap::count` at +0x8c |
| 0x4e4670 | Value_Approach | 122 | `/O2 /TP` | positive branch first; `next > target` |
| 0x47c730 | Game_ClearPendingMapObjects | 123 | `/O2 /TP` | pending counter cleared only after the loop |
| 0x48cb30 | Map_RefreshObjectSprites | 123 | `/O2 /TP` | window id staged in a local |
| 0x4ff9e0 | Building_ResetInventory | 123 | `/O2 /TP` | block pointer declared before use |
| 0x502a10 | Game_AllBuildingCategoryRatingsAbove | 123 | `/O2 /TP` | loop template, returns 1 by default |
| 0x522d40 | UI_SetTextFit | 123 | `/O2 /TP` | `Font::GetCharWidth(char)` keeps `mov cl` |
| 0x4c4e30 | Window_UpdatePolicePage | 124 | `/O2 /TP` | free `__cdecl`; string/data symbols auto-resolved |

## Non-matching attempts (`nonmatching/`)

| address | function | diffs | first diff | summary |
|---|---:|---:|---|---|
| 0x4f7c30 | Branch_ValidateMenuAndRecalculate | 65 | offset 8: original `e9`, candidate `d9` | compiler assigns `this` to `ebx` instead of `ebp`; `all` spills differently |
| 0x47f100 | Game_CheckObjectUpgrade | 5 | offset 33: original `98`, candidate `a8` | only the `mapObject`/`aged` callee-saved registers are swapped (`ebx`/`ebp`) |
| 0x4de120 | Stats_GetMaxCityMatrixValue | 99 | offset 4: original `57`, candidate `33` | `maximum` gets `edi` in the original, `ebx` in every natural C shape |
| 0x4edaf0 | Map_RecordPointToGridCell | 29 | offset 92: original `8b`, candidate `99` | original preloads `param_2` into `ecx`; candidate computes a third `idiv` |
| 0x48c2c0 | Game_ApplyPercentChange | 103 | offset 4: original `55`, candidate `53` | loop counter gets `ebp` in the original, `ebx` in the candidate |

## Not attempted

Stopped before writing candidates (no files):

- `0x54a8e0 UI_BriefingList_Destroy` (SEH destructor with a compiler-generated
  vtable; requires the anchored-vtable/EH path).
- `0x550920 _strlen` (stock CRT implementation).

## Verification

```sh
sh reconstructed/match/batch14/part3/verify_strict.sh
# strict 18/18
```

The script checks each accepted file with its manifest length, exact entry
symbol and flags. Known non-matching records are only in `nonmatching/`.
No object or PDB artifacts are kept.
