# batch18 part4 worklog

Scope: 25 functions from `reconstructed/match/batch18/part4.json`.
Toolchain: `~/.local/share/pc2/vc6-sp3-toolchain/VC98` (MSVC 6.0 SP3,
C2.DLL 12.00.8447). Every accepted function is genuine C/C++ and passes
`tools/match_decomp.py --strict --auto-symbols` with the manifest length,
the `/O2 /TP` flags, and the exact candidate entry symbol.

## Result: 5 / 25 strict matches

Reproduce with:

```sh
sh reconstructed/match/batch18/part4/verify_strict.sh
```

Strict matches:

| address | function | flags | entry |
| --- | --- | --- | --- |
| 0x499c40 | IngredientPanel_ShowSpritePreview | /O2 /TP | `_IngredientPanel_ShowSpritePreview` |
| 0x49d970 | RecipeEditor_ShowIngredientCursorSprite | /O2 /TP | `_RecipeEditor_ShowIngredientCursorSprite` |
| 0x4a1170 | SoundOptions_Init | /O2 /TP | `_SoundOptions_Init` |
| 0x4caca0 | UI_ShowPanel | /O2 /TP | `_UI_ShowPanel` |
| 0x5094a0 | Object_SyncChildState | /O2 /TP | `?SyncChildState@Object@@QAEXPAXH@Z` |

## Non-matching evidence

Genuine C/C++ attempts that do not reproduce the shipped bytes are in
`nonmatching/` with the entry symbol, first differing byte offset, and the
matcher relocation/strict issues recorded in the matching `.json` file.

| address | function | entry | first diff (offset: original vs candidate) |
| --- | --- | --- | --- |
| 0x4016b0 | IDMap_RemoveRecursive | `?RemoveRecursive@IDMap@@QAEHH@Z` | 16: 81 vs 85 |
| 0x409c60 | AdCampaign_GoToNextQueuedBuilding | `?GoToNextQueuedBuilding@AdCampaign@@QAEHPAXPAD@Z` | 73: 103 vs 100 |
| 0x479960 | Map_ComputeBuildableAverage | `?ComputeBuildableAverage@Map@@QAEXPAD@Z` | 9: 51 vs 86 |
| 0x47c9a0 | Game_GetAverageRecordValueByByte8 | `?GetAverageRecordValueByByte8@Map@@QAEED@Z` | 27: 178 vs 170 |
| 0x480c40 | Branch_PickRandomActiveCounter | `_Branch_PickRandomActiveCounter` | 0: 106 vs 131 |
| 0x48b420 | Game_ReassignDestroyedObjectReferences | `?ReassignDestroyedObjectReferences@Game@@QAEXPAX@Z` | 45: 160 vs 166 |
| 0x48c6d0 | Game_RedirectPersonDestination | `?RedirectPersonDestination@Game@@QAEXPAX@Z` | 20: 20 vs 16 |
| 0x4aecc0 | Stats_BuildObjectProductMatrix | `_Stats_BuildObjectProductMatrix` | 46: 93 vs 82 |
| 0x4bf5c0 | Stats_BuildCompetitorMatrix | `_Stats_BuildCompetitorMatrix` | 46: 95 vs 83 |
| 0x4d4940 | City_SpawnPerson | `?SpawnPerson@City@@QAEPAUCharacter@@H@Z` | 0: 100 vs 83 |
| 0x4d5cf0 | Map_CountNearbyObjects | `?CountNearbyObjects@Map@@QAEXPAXPAH11@Z` | 82: 120 vs 122 |
| 0x4da550 | City_SpawnResidentInPreferredCity | `?SpawnResidentInPreferredCity@City@@QAEXXZ` | 21: 186 vs 176 |
| 0x4dec10 | Company_RecordDailyStatistics | `?RecordDailyStatistics@Company@@QAEXXZ` | 197: 68 vs 76 |
| 0x509c10 | Building_PruneStaleListRow | `?PruneStaleListRow@Building@@QAEXXZ` | 14: 157 vs 133 |
| 0x50d810 | UI_UpdateValueBar | `?UpdateValueBar@UI@@QAEXPAXH@Z` | 79: 135 vs 151 |
| 0x512620 | Recipe_RecomputeAllStats | `?RecomputeAllStats@Recipe@@QAEXH@Z` | 9: 141 vs 51 |
| 0x523bb0 | UI_CreateWindow | `_UI_CreateWindow` | 0: 106 vs 83 |
| 0x52c320 | UI_DrawTextControl | `?DrawTextControl@UI@@QAEXXZ` | 3: 139 vs 87 |
| 0x534880 | RecordList_BlitRecordSprite | `?BlitRecordSprite@RecordList@@QAE_NHHH@Z` | 4: 86 vs 83 |
| 0x54c910 | Sound_DestroyAllChannels | `?DestroyAllChannels@SoundManager@@QAEXXZ` | 60: 142 vs 134 |

## Notes

- No inline assembly, no generated C, and no explicit symbol overrides were
  used; every relocation target is resolved by `--auto-symbols` from the
  shipped symbol maps, data symbols, address labels, or the registry.
- The closest failures are one-instruction tail or block-layout
  differences (for example `0x4d8140` differs only in the final
  conditional return and `0x4dec10` only in the register used for the
  `List::Add` argument after the inlined `memset`).
- The functions with an `fs:[0]` prologue are C++ constructors and
  destructors with unwind records; the EH model was not reproduced and
  their attempts stop at the first prologue byte.
