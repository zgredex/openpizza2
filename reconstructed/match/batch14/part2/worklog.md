# batch14 part2 worklog

Target: `game/fastfood2.exe`, MSVC 6.0 SP3 (`C2.DLL 12.00.8447`).
All accepted candidates are genuine C/C++ built with `/O2 /TP`, no inline
assembly.

Status: **6 / 25 strict matches** (`"strict_match": true` with
`tools/match_decomp.py ... --strict --auto-symbols` and the manifest length).
This part is **not complete**: two manifest records are recorded under
`nonmatching/` and seventeen are not implemented yet, so the directory is left
uncommitted.

## Strict matches

| address | function | bytes | notes |
|---|---:|---:|---|
| 0x489950 | Game_CountPlayerRecordsByField34 | 117 | keep `*(game+0xc1c)` inline in the inner loop; that keeps the argument in `ebp` and the count in `ebx` |
| 0x49c450 | RecipeMenu_ShowRecipeChooser | 117 | `switch (count)` reproduces the outlined `-1` block and the shared hoisted `push 0` |
| 0x4ad2d0 | Stats_SumByStorageMode | 117 | jump table at 0x4ad348; default returns `*(float *)&param_2`; case 3-5 returns `DAT_0055c4bc` |
| 0x4d1ba0 | RecipeTopping_Save | 117 | CRT stream method is `CRT_Ostream::Write`; eight fixed-size writes |
| 0x4d1c20 | RecipeTopping_Load | 117 | `CRT_Istream::Read`; same offsets as Save |
| 0x4e5e30 | ConstructionOrder_Save | 117 | eight 4-byte writes at +4..+0x20 |

## Nonmatching attempts (kept under `nonmatching/`)

| address | function | diffs | first difference |
|---|---:|---:|---|
| 0x4ed480 | Map_ComputeObjectDistance | 74 | 0x18: original `0xc2` (`ret 0x14`) vs candidate `0xd0`; the two early `1000000` returns and the abs/divide schedule differ |
| 0x4f55e0 | Grid_CollectType351 | 33 | 0x02: original `0x51` (`push ecx`) vs candidate `0x41` (`inc ecx`); prologue/register allocation differs |

## Not implemented yet

`0x4fc720 Game_CompanyManager_Destructor`, `0x5287a0 UI_DrawChildAt`,
`0x5356c0 Font_MeasureRange`, `0x5425b0 SoundVoice_WriteSilence`,
`0x47eab0 Game_ConsumeObject`, `0x49d6f0 RecipeEdit_UpdateRatingBars`,
`0x4dbff0 Game_GetPlayerQuarterStat`, `0x4e0e90 Game_SelectLeastUsedCategory`,
`0x4e21d0 Game_UnlinkBuildingObject`, `0x51f230 UI_ImageElement_Destroy`,
`0x47ab20 Game_GetMarketBonusFactor`, `0x482890 Game_CloseSelectionDialog`,
`0x4f08e0 Map_UnlinkCells`, `0x4782a0 Stats_GetAverageSpend`,
`0x479c20 City_HasRoomForBuilding`, `0x48cfa0 Game_ClearSelectedObject`,
`0x4e2750 Game_CountObjectsForOwner`.

## Verification

```sh
sh reconstructed/match/batch14/part2/verify_strict.sh
# strict 6/6

python3 tools/match_batch.py reconstructed/match/batch14/part2.json \
  reconstructed/match/batch14/part2 --flags "/O2 /TP" \
  --strict --auto-symbols
```
