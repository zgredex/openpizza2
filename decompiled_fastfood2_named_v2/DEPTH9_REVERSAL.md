# Non-leaf reversal — depth 9 complete (162/162)

Depth 1–8 are complete. **The frozen depth-9 set is complete: 162/162 named, 162 exact name matches, 0 unnamed.** The ledger now contains 1350 non-leaf names.

## Completion verification

Fresh REA export in `depth9_verification/`:

```text
initial depth9: 162
named in REA export: 162
exact name matches: 162
unnamed: 0
mismatch: 0
func_symbols: 1350  unique addresses: 1350  unique names: 1350
```

## Next peelable layers

After depth 9 the strict local-callee peel continues with:

```text
10:79  11:57  12:74  13:124  14:42  15:28
16:18  17:11  18:17  19:12  20:3   21:1
remaining: 655
```

## Named in this wave

| Address | Name |
|---|---|
| `0x52d690` | `UI_ButtonElement_Delete` |
| `0x52b210` | `MovieWindow_Delete` |
| `0x529140` | `UI_Slider_Delete` |
| `0x52bd50` | `UI_TextElement_Delete` |
| `0x51f210` | `UI_ImageElement_Delete` |
| `0x5221c0` | `UI_LabelElement_Delete` |
| `0x544ab0` | `SoundSystem_Delete` |
| `0x4bd490` | `UI_SelectNextObjectOfType` |
| `0x4bd450` | `UI_SelectPreviousObjectOfType` |
| `0x552754` | `CRT_IsIndst` |
| `0x552b98` | `CRT_Filbuf` |
| `0x5531c5` | `CRT_CallCatchBlockFinally` |
| `0x5534dc` | `CRT_Terminate` |
| `0x5539d3` | `CRT_Calloc` |
| `0x553a60` | `CRT_XcptFilter` |
| `0x553d8f` | `CRT_SetEnvp` |
| `0x554095` | `CRT_GetEnvStrings` |
| `0x55438f` | `CRT_AllocOsfHandle` |
| `0x5544b2` | `CRT_SetOsfHandle` |
| `0x55452e` | `CRT_FreeOsfHandle` |
| `0x554670` | `CRT_Flush` |
| `0x5554ae` | `CRT_WctombLocked` |
| `0x536160` | `FullscreenImage_LoadBmp` |
| `0x53a1c0` | `Gfx_BlendTable_RegisterAtexit` |
| `0x53c6f0` | `Sprite_CriticalSection_RegisterAtexit` |
| `0x53f0a0` | `Sound_SetLastError` |
| `0x53fcc0` | `SoundPakManager_Destruct` |
| `0x53fda0` | `SoundPakManager_AddArchive` |
| `0x540260` | `SoundStream_Close` |
| `0x54a660` | `DebugConsole_Printf` |
| `0x54a980` | `UI_Briefing_AddMessage` |
| `0x54aa10` | `UI_Briefing_AddPinnedMessage` |
| `0x54b1b0` | `UI_BriefingList_Save` |
| `0x54b230` | `UI_BriefingList_Load` |
| `0x54cfd6` | `CRT_Filebuf_Sync` |
| `0x54e0cc` | `CRT_Atoi` |
| `0x54ec7f` | `CRT_FtellLocked` |
| `0x54ee99` | `CRT_Strlwr` |
| `0x54f0d5` | `CRT_Srand` |
| `0x54f3a4` | `CRT_LockExit` |
| `0x54f3d0` | `CRT_FindFirst` |
| `0x54f49d` | `CRT_FindNext` |
| `0x54f565` | `CRT_FindClose` |
| `0x54f5e9` | `CRT_Unlink` |
| `0x54f918` | `CRT_Tolower_L` |
| `0x54fa52` | `CRT_Toupper_L` |
| `0x54fb56` | `CRT_Fwrite` |
| `0x54fc60` | `CRT_Fputc` |
| `0x54fe01` | `CRT_AmsgExit` |
| `0x54fe25` | `CRT_TypeInfoDtor` |
| `0x54ffd0` | `CRT_WriteCore` |
| `0x5501c0` | `CRT_ReadCore` |
| `0x55062d` | `CRT_Isspace_L` |
| `0x5508a6` | `CRT_LockFile2` |
| `0x550c6a` | `CRT_SetMode` |
| `0x5518db` | `CRT_WriteMultiChar` |
| `0x55190c` | `CRT_WriteString` |
| `0x551e0e` | `CRT_Realloc` |
| `0x551f46` | `CRT_Msize` |
| `0x551fc9` | `CRT_HeapAlloc` |
| `0x5520cf` | `CRT_ReleaseStreamBuffer` |
| `0x5523ff` | `CRT_FreeThreadData` |
| `0x498100` | `CityCompanyList_Load` |
| `0x498130` | `CityCompanyList_Save` |
| `0x499570` | `IngredientPanel_Load` |
| `0x499590` | `IngredientPanel_Save` |
| `0x49acd0` | `AdvertisingPanel_Load` |
| `0x49ad00` | `AdvertisingPanel_Save` |
| `0x49b460` | `CompanyMarketShare_Load` |
| `0x49b490` | `CompanyMarketShare_Save` |
| `0x4aa6c0` | `StatisticsBalance_Load` |
| `0x4aa700` | `StatisticsBalance_Save` |
| `0x4ac3c0` | `StatisticsBranchBalance_Load` |
| `0x4ac400` | `StatisticsBranchBalance_Save` |
| `0x4b0d40` | `Personnel_Load` |
| `0x4b0d60` | `Personnel_Save` |
| `0x4b3ca0` | `CompanyOverview_Load` |
| `0x4b3ce0` | `CompanyOverview_Save` |
| `0x4c0d40` | `WarehouseProduct_Load` |
| `0x4c0d60` | `WarehouseProduct_Save` |
| `0x49b880` | `SaveMenu_MenuFileExists` |
| `0x4a19e0` | `File_Exists` |
| `0x50f6b0` | `GamePlan_SaveRecord` |
| `0x50f750` | `GamePlan_LoadRecord` |
| `0x511e60` | `Recipe_CollectCategoryCandidates` |
| `0x512f10` | `Recipe_RecomputeLayoutQuality` |
| `0x513d50` | `Storage_LoadRecord` |
| `0x513e50` | `Storage_SaveRecord` |
| `0x514330` | `Storage_ProduceBatch` |
| `0x520e80` | `Dialog_WriteChildRecord` |
| `0x522e60` | `Atexit_RegisterListCritSectDtor` |
| `0x5273c0` | `SpriteCache_MakeKey` |
| `0x528570` | `ContextMenu_Construct` |
| `0x52a440` | `UI_Bar_BuildGradientFill` |
| `0x52e4b0` | `Tooltip_Construct` |
| `0x52ee10` | `Dialog_InitBase` |
| `0x5324c0` | `UI_Group_RemoveAt` |
| `0x532520` | `UI_Group_ClearAll` |
| `0x532bc0` | `Atexit_RegisterAnimSwapCritSectDtor` |
| `0x532c00` | `Atexit_RegisterAnimCritSectDtor` |
| `0x535180` | `Font_Load` |
| `0x535e20` | `Palette_WriteToStream` |
| `0x4eab00` | `World_LoadNameIndexTable` |
| `0x4eab80` | `World_FindNameIndex` |
| `0x4ec4f0` | `IsoMap_Save` |
| `0x4ecb30` | `MapSprite_Save` |
| `0x4f2e50` | `IsoMap_MarkPlayerFootprints` |
| `0x4f4400` | `IsoMap_RenderViewport` |
| `0x4f5310` | `AI_ChooseWalkTarget` |
| `0x4f5e50` | `Player_MissionState_Load` |
| `0x4f5ee0` | `Player_MissionState_Save` |
| `0x4f6dd0` | `AI_CompanySlots_Load` |
| `0x4f6e20` | `AI_CompanySlots_Save` |
| `0x4f8240` | `AI_FindBestBranchSite` |
| `0x4f8510` | `AI_FindBranchPlotNearOwn` |
| `0x4f8710` | `AI_PickInitialBranchPlot` |
| `0x4f88c0` | `AI_FindCheapestShop` |
| `0x4f89d0` | `AI_FindNearestHouse` |
| `0x501a40` | `Player_Event_Save` |
| `0x501a70` | `Player_Event_Load` |
| `0x501b80` | `Player_AIState_Load` |
| `0x501cb0` | `Player_AIState_Save` |
| `0x4cb3a0` | `MissionMap_RegisterCleanup` |
| `0x4d1ba0` | `RecipeTopping_Save` |
| `0x4d1c20` | `RecipeTopping_Load` |
| `0x4d3a50` | `Character_Load` |
| `0x4d3ba0` | `Character_Save` |
| `0x4d5940` | `Map_BuildOccupiedCellList` |
| `0x4d8650` | `City_InitOfferSlots` |
| `0x4dcd00` | `Person_RefreshShopChoices` |
| `0x4dd4f0` | `GameCalendar_Save` |
| `0x4dd590` | `GameCalendar_Load` |
| `0x4ddd60` | `Company_RemoveRecipe` |
| `0x4decf0` | `Stats_Report_FillCompanyOverview` |
| `0x4e3460` | `Recipe_SetOnMenu` |
| `0x4e43f0` | `BuildingValue_Save` |
| `0x4e4440` | `BuildingValue_Load` |
| `0x4e5e30` | `ConstructionOrder_Save` |
| `0x4e5eb0` | `ConstructionOrder_Load` |
| `0x4e6420` | `Filename_ToUpperStripExt` |
| `0x4ea230` | `Game_ResizeZoomSurfaces` |
| `0x4eaaa0` | `Game_SaveTileNameTable` |
| `0x401190` | `StatsPeriodReport_Load` |
| `0x401200` | `StatsPeriodReport_Save` |
| `0x401380` | `CRT_RegisterListLockCleanup` |
| `0x403510` | `Debug_WarningMessageBox` |
| `0x403960` | `File_ReadHeaderDwords` |
| `0x403d70` | `CRT_RegisterMissionListCleanup` |
| `0x477b80` | `Branch_ClearAssignedEmployee` |
| `0x477bd0` | `Branch_SetAssignedEmployee` |
| `0x47d340` | `Branch_ComputeWorkDuration` |
| `0x47ea30` | `Branch_UpdateConstructionQueue` |
| `0x47fd90` | `Branch_GetBuildingValue` |
| `0x481140` | `Branch_GetCachedBillboards` |
| `0x48c6d0` | `Game_RedirectPersonDestination` |
| `0x4900a0` | `BranchMenu_Category_Load` |
| `0x4900c0` | `BranchMenu_Category_Save` |
| `0x4919b0` | `BranchStats_SeriesFlags_Load` |
| `0x4919d0` | `BranchStats_SeriesFlags_Save` |
| `0x492230` | `BranchDesign_ColorIndex_Load` |
| `0x492250` | `BranchDesign_ColorIndex_Save` |
| `0x495500` | `Game_RebuildObjectTypeLists` |
