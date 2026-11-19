# Non-leaf reversal — depth 8 complete (73/73)

Depth 1–7 are complete. **The frozen depth-8 set is complete: 73/73 named, 73 exact name matches, 0 unnamed.** In addition, a targeted CRT/support sweep named 26 high-fanout helpers; all 26 exact-match in the export. The ledger now contains 1188 non-leaf names.

## Completion verification

Fresh REA export in `depth8_verification/`:

```text
depth8 total 73  named 73  exact 73  unnamed 0  mismatch 0
support total 26  named 26  exact 26  unnamed 0  mismatch 0
func_symbols 1188  unique addresses 1188  unique names 1188
```

## Impact

The support sweep reduced the unnamed game-function backlog from 1,226 to **655** and expanded the next peelable layer from 41 to **162**:

```text
9:162  10:79  11:57  12:74  13:124  14:42  15:28
16:18  17:11  18:17  19:12  20:3   21:1
remaining: 655
```

## Depth-8 functions

| Address | Name |
|---|---|
| `0x402ef0` | `FileObject_Delete` |
| `0x50fdd0` | `Recipe_Delete` |
| `0x476fe0` | `Branch_Delete` |
| `0x4d3240` | `Car_Delete` |
| `0x4e9d70` | `Game_Delete` |
| `0x537d60` | `Renderer_Delete` |
| `0x52e510` | `UI_Tooltip_Delete` |
| `0x403350` | `UI_ListEntry_Delete` |
| `0x513d30` | `Storage_Delete` |
| `0x4d1d80` | `MapObject_Delete` |
| `0x4eade0` | `IsoMap_Delete` |
| `0x5427c0` | `SoundMixerThread_Delete` |
| `0x536140` | `Window_Delete` |
| `0x54a8c0` | `UI_BriefingList_Delete` |
| `0x54db05` | `CRT_Streambuf_Delete` |
| `0x54d8bb` | `CRT_Ios_Delete` |
| `0x50e9c0` | `Player_Delete` |
| `0x534db0` | `Gfx_RectList_Delete` |
| `0x501b50` | `Player_AIState_Delete` |
| `0x522ed0` | `Array_Delete` |
| `0x520af0` | `UI_Child_Delete` |
| `0x4dd8d0` | `Company_Delete` |
| `0x4d47e0` | `City_Delete` |
| `0x54b620` | `EmployeeAvatar_Delete` |
| `0x5286e0` | `UI_ContextMenu_Delete` |
| `0x403d60` | `MissionBriefing_InitList` |
| `0x4cb390` | `MissionMap_InitList` |
| `0x54b460` | `EmployeeAvatar_Construct` |
| `0x489880` | `Game_BuildCompetitorBuildingList` |
| `0x4d59c0` | `City_CollectBuildingsByType` |
| `0x539ea0` | `Renderer_CreateChild` |
| `0x4ddd20` | `Company_InvalidateAllBranchRatings` |
| `0x4f2b60` | `Grid_CollectFootprintCells` |
| `0x50e2a0` | `Person_SetAtWork` |
| `0x4e2410` | `BuildingValue_Compute` |
| `0x50bf50` | `Person_FindFreeNeighborCell` |
| `0x4d5b90` | `City_CollectBranchBuildings` |
| `0x4d5c40` | `City_CollectBusinessBuildings` |
| `0x48c340` | `City_CollectVacantLots` |
| `0x47d270` | `Branch_CollectOrdersByCategory` |
| `0x488b30` | `Ingredient_CollectByCategory` |
| `0x4d8470` | `City_FindFreePlotsNearPoint` |
| `0x532510` | `UI_Group_DestroyMemberList` |
| `0x554203` | `CRT_FFMessageBanner` |
| `0x54cd91` | `CRT_FileBuf_Construct` |
| `0x5140e0` | `Storage_ChargePurchaseCost` |
| `0x4e4930` | `Ingredient_LoadMarketTable` |
| `0x544ba0` | `SoundSystem_Destroy` |
| `0x4e1bc0` | `Company_CollectUnprofitableBranches` |
| `0x52b230` | `MovieWindow_Destroy` |
| `0x50dbf0` | `Object_FindOpposingTarget` |
| `0x507b90` | `Map_PickRandomLinkedCellInSteps` |
| `0x4dd130` | `Map_CollectBillboardDistances` |
| `0x48a3b0` | `Game_FindNextFreeObjectOfType` |
| `0x48a2d0` | `Game_FindPreviousFreeObjectOfType` |
| `0x4d43a0` | `BuildingValue_ApplyUpgrade` |
| `0x529280` | `UI_Slider_Destroy` |
| `0x4d5ab0` | `Map_CollectObjectsOnFlaggedTiles` |
| `0x47c2b0` | `Object_AttachBuildingValue` |
| `0x50ff80` | `Recipe_AppendSalesRecord` |
| `0x480c40` | `Branch_PickRandomActiveCounter` |
| `0x512750` | `Recipe_FindIngredientsByCategory` |
| `0x4d6af0` | `Game_CollectObjectsByType` |
| `0x54d40e` | `CRT_Istream_Construct` |
| `0x52bd70` | `UI_TextElement_Destroy` |
| `0x52d6b0` | `UI_ButtonElement_Destroy` |
| `0x54d7e9` | `CRT_Ostream_Construct` |
| `0x4e0170` | `Stats_AppendPeriodReport` |
| `0x51f230` | `UI_ImageElement_Destroy` |
| `0x4d2a00` | `BuildingValue_CreateDefault` |
| `0x47e8c0` | `Branch_CancelConstructionAt` |
| `0x5221e0` | `UI_LabelElement_Destroy` |
| `0x54a880` | `UI_BriefingList_Construct` |

## CRT/support sweep

| Address | Name |
|---|---|
| `0x54cc2b` | `CRT_Ostream_Write` |
| `0x54cbc1` | `CRT_Istream_Read` |
| `0x55395d` | `CRT_Lock` |
| `0x54dea3` | `CRT_Atexit` |
| `0x551005` | `CRT_FreeInternal` |
| `0x552398` | `CRT_GetThreadData` |
| `0x553606` | `CRT_GetErrnoPtr` |
| `0x54f084` | `CRT_Vsprintf` |
| `0x55360f` | `CRT_GetDosErrnoPtr` |
| `0x552b23` | `CRT_Mbtowc` |
| `0x54dfe0` | `CRT_Fopen` |
| `0x54e978` | `CRT_FreadLocked` |
| `0x54fb27` | `CRT_FwriteLocked` |
| `0x553593` | `CRT_MapWin32Error` |
| `0x5545ef` | `CRT_LockFileHandle` |
| `0x5503fe` | `CRT_LseekLocked` |
| `0x5506b2` | `CRT_FlushStream` |
| `0x5545ad` | `CRT_GetOsHandle` |
| `0x550399` | `CRT_Lseek` |
| `0x54ff6b` | `CRT_Write` |
| `0x55015b` | `CRT_Read` |
| `0x5518a6` | `CRT_StreamPutc` |
| `0x54dee4` | `CRT_Fclose` |
| `0x550877` | `CRT_LockFile` |
| `0x54f775` | `CRT_Strupr` |
| `0x55104d` | `CRT_FlushStreamBuffer` |
