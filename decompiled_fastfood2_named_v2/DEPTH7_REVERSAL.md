# Non-leaf reversal — depth 7 complete (67/67)

Depth 1–6 are complete. **The frozen depth-7 set is complete: 67/67 named, 67 exact name matches, 0 unnamed.** The ledger now contains 1089 non-leaf names.

## Completion verification

Fresh REA export in `depth7_verification/`, checked against the frozen 67-address depth-7 set:

```text
initial depth7: 67
named in REA export: 67
exact name matches: 67
unnamed: 0
mismatch: 0
func_symbols: 1089  unique addresses: 1089  unique names: 1089
```

## Corrections to earlier waves

Depth-7 evidence exposed two earlier misinterpretations. Both REA annotations, the CSV ledger, and the depth reports are corrected:

| Address | Old name | Corrected name | Evidence |
|---|---|---|---|
| `0x478be0` | `Game_UpdateDailyStats` | `Branch_ComputeBuildingRating` | Iterates eight category scores, returns a 0–100 rating; called by `Game_AnyBuildingRatingAbove`. |
| `0x478db0` | `Game_ResetLargeState` | `Branch_RecalculateRatings` | Rebuilds the branch rating cache and clamps eight category scores to 0–100. |

## Named in this wave

| Address | Name |
|---|---|
| `0x4013a0` | `List_Construct` |
| `0x401040` | `Stats_Report_Construct` |
| `0x4010f0` | `Stats_Report_ConstructEmpty` |
| `0x402fe0` | `FileObject_Destroy` |
| `0x403480` | `UI_ListEntry_Destroy` |
| `0x47c5b0` | `Branch_RemoveConstructionOrder` |
| `0x47e0e0` | `Branch_EnqueueConstructionOrder` |
| `0x47e220` | `Branch_Destroy` |
| `0x47ee50` | `Branch_InvalidateRatingCache` |
| `0x47f210` | `Branch_UpdateActiveConstruction` |
| `0x47fb70` | `Branch_RefreshConstructionButtons` |
| `0x47fd20` | `Branch_ClearConstructionSites` |
| `0x477aa0` | `Branch_GenerateUniqueName` |
| `0x4f8bf0` | `Game_UpdateCompanyAdvancementScore` |
| `0x4fc7d0` | `Game_TryBuyCompletedHouse` |
| `0x501b70` | `Player_AIState_Destroy` |
| `0x502890` | `Game_AnyBuildingRatingAbove` |
| `0x50e9e0` | `Player_Destroy` |
| `0x510c10` | `Recipe_Destroy` |
| `0x513fe0` | `Storage_Destroy` |
| `0x513ff0` | `Storage_SettlePendingOrders` |
| `0x514100` | `Storage_DistributeCostToShops` |
| `0x520b10` | `UI_Child_Destroy` |
| `0x522e80` | `Array_Construct` |
| `0x522f20` | `Array_Destroy` |
| `0x528700` | `UI_ContextMenu_Destroy` |
| `0x52e530` | `UI_Tooltip_Destroy` |
| `0x4d2200` | `MapObject_Destroy` |
| `0x4d31f0` | `Car_Construct` |
| `0x4d3280` | `Car_Destroy` |
| `0x4d4120` | `Person_SetMotivation` |
| `0x4d4130` | `Person_SetSkill` |
| `0x4d4140` | `Person_SetSpeed` |
| `0x4d4150` | `Person_SetHealth` |
| `0x4d4160` | `Person_SetPerformance` |
| `0x4d73c0` | `City_Destroy` |
| `0x4d8220` | `Game_FindBestQualityBuilding` |
| `0x4da300` | `Game_ChargeQuarterlyBribes` |
| `0x4e1990` | `Company_Destroy` |
| `0x4e3660` | `Game_UpgradeProductionLevel` |
| `0x4e42f0` | `BuildingValue_Construct` |
| `0x4e4340` | `BuildingValue_ConstructDefault` |
| `0x4e4770` | `Ingredient_Construct` |
| `0x4e9e30` | `Game_Destroy` |
| `0x4eb350` | `IsoMap_Destroy` |
| `0x534d60` | `Gfx_RectList_Construct` |
| `0x534dd0` | `Gfx_RectList_Destroy` |
| `0x537350` | `Window_Destroy` |
| `0x537c40` | `Renderer_ConstructRoot` |
| `0x537d80` | `Renderer_ConstructChild` |
| `0x538a80` | `Renderer_Destroy` |
| `0x53fc10` | `DirectSoundBuffer_Delete` |
| `0x5427e0` | `SoundMixerThread_Destroy` |
| `0x54a8e0` | `UI_BriefingList_Destroy` |
| `0x54aaa0` | `UI_AddBriefingEntry` |
| `0x54b640` | `EmployeeAvatar_Destroy` |
| `0x54d85d` | `CRT_Ios_Construct` |
| `0x54d8d7` | `CRT_Ios_Destroy` |
| `0x54dac6` | `CRT_Streambuf_Construct` |
| `0x54db21` | `CRT_Streambuf_Destroy` |
| `0x54f2b0` | `CRT_CInit` |
| `0x551ae6` | `CRT_Cftoe` |
| `0x551c09` | `CRT_Cftof` |
| `0x551d05` | `CRT_Cftog` |
| `0x553710` | `CRT_LCMapStringA` |
| `0x553e48` | `CRT_SetArgv` |
| `0x55423c` | `CRT_NMsgWrite` |
