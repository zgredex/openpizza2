# Non-leaf reversal — layers 11–21 complete (387/387)

**All remaining peelable layers are complete: 387/387 named, 387 exact name matches, 0 unnamed.** Every layer 11–21 is at 100%. The ledger now contains 1816 non-leaf names.

## Completion verification

Fresh REA export in `layers11_21_verification/`:

```text
layers11_21 total: 387
named in REA export: 387
exact name matches: 387
unnamed: 0
mismatch: 0
per-layer named: {11: 57/57, 12: 74/74, 13: 124/124, 14: 42/42, 15: 28/28, 16: 18/18, 17: 11/11, 18: 17/17, 19: 12/12, 20: 3/3, 21: 1/1}
func_symbols: 1816  unique addresses: 1816  unique names: 1816
```

## Remaining hard residual

After layers 11–21, the iterative peel stops with **655 functions** left. These are not part of the normal depth layers: mostly unnamed support/CRT helpers and the 33 functions in dependency cycles.

## Layer totals

| Layer | Named |
|---|---:|
| 11 | 57/57 |
| 12 | 74/74 |
| 13 | 124/124 |
| 14 | 42/42 |
| 15 | 28/28 |
| 16 | 18/18 |
| 17 | 11/11 |
| 18 | 17/17 |
| 19 | 12/12 |
| 20 | 3/3 |
| 21 | 1/1 |

## Layer 11

| Address | Name |
|---|---|
| `0x53f5b0` | `SoundSample_Delete` |
| `0x5053d0` | `PersonList_Save` |
| `0x4e1540` | `CompanyData_Save` |
| `0x4d7090` | `MapObjectList_Save` |
| `0x4d3490` | `CarList_Save` |
| `0x511be0` | `Recipe_StreamConstruct` |
| `0x5108e0` | `Recipe_LoadFromStream` |
| `0x50eca0` | `Player_Load` |
| `0x4d1da0` | `MapObject_Load` |
| `0x50f4c0` | `Player_AIState_Init` |
| `0x48b420` | `Game_ReassignDestroyedObjectReferences` |
| `0x4029e0` | `ResourceManager_RegisterExtensionAlias` |
| `0x402b80` | `ResourceManager_NormalizeResourcePath` |
| `0x4035d0` | `Profiler_DumpReport` |
| `0x477850` | `Branch_CloseMonth` |
| `0x4784e0` | `Branch_RecomputeMenuPriceRatings` |
| `0x47eed0` | `Branch_SettleDueConstructionOrders` |
| `0x47f5c0` | `Branch_RemoveBuildingObject` |
| `0x480200` | `Branch_InitCityObjects` |
| `0x4f3ec0` | `Map_ConnectCellToStreetGraph` |
| `0x4f5cd0` | `CityView_IsCarSpawnCellFree` |
| `0x4f5fd0` | `Mission_EvaluateGoals` |
| `0x4f6db0` | `Game_CompanyManager_Delete` |
| `0x4f9ee0` | `CityMap_StampObjectPattern` |
| `0x4fad60` | `CityMap_PlaceSceneryProps` |
| `0x4fc5f0` | `Company_RefreshMenuSalesIfDue` |
| `0x4d6770` | `City_PickObjectAtScreenPoint` |
| `0x4db310` | `Parse_ReadIntToken` |
| `0x505f40` | `Object_SetCompanyStylePalette` |
| `0x506010` | `Object_PickWeightedBuildingRecord` |
| `0x50a0b0` | `Object_SetBuildingRecordForAllCompanies` |
| `0x522860` | `UI_EditFieldHandleKey` |
| `0x523930` | `UI_AllocWindowSlot` |
| `0x54e7d0` | `CRT_FindTryBlockRange` |
| `0x54ede0` | `CRT_Fseek` |
| `0x54f1de` | `CRT_ThreadStart` |
| `0x54f2dd` | `CRT_Exit` |
| `0x54fe8b` | `CRT_Close` |
| `0x550717` | `CRT_FlushAllStreams` |
| `0x551165` | `CRT_Output` |
| `0x5519e8` | `CRT_ForceDecimalPoint` |
| `0x55249f` | `CRT_TzsetInit` |
| `0x552fc9` | `CRT_FrameUnwindToState` |
| `0x55323d` | `CRT_BuildCatchObject` |
| `0x52fdd0` | `Window_GadgetNotify` |
| `0x52fef0` | `Window_GetGadgetChecked` |
| `0x5425b0` | `SoundVoice_WriteSilence` |
| `0x548780` | `Sound_UpdateCityAmbience` |
| `0x54d493` | `CRT_Istream_Prefix` |
| `0x5402a0` | `SoundPakManager_AddExtensionMapping` |
| `0x5405e0` | `SoundPakManager_BuildArchivePath` |
| `0x541520` | `SoundStreamBuffer_Construct` |
| `0x524e80` | `Window_ExportDialog` |
| `0x527580` | `Window_LoadSpriteCached` |
| `0x52cba0` | `Dialog_ParseInteger` |
| `0x52e9b0` | `Dialog_Delete` |
| `0x52eca0` | `Dialog_ConstructWithPicture` |

## Layer 12

| Address | Name |
|---|---|
| `0x50fc20` | `Recipe_Construct` |
| `0x4025e0` | `Resource_OpenNativeHandle` |
| `0x478320` | `Branch_GetMenuRating` |
| `0x4783c0` | `Branch_GetPriceRating` |
| `0x47f5f0` | `Branch_RemoveAllBuildings` |
| `0x4858d0` | `Game_LoadBackgroundImage` |
| `0x4f5d40` | `CityView_ReserveCarCell` |
| `0x4f6b80` | `Mission_TickGoalDeadline` |
| `0x4fab10` | `CityMap_PlaceBuildingBlocks` |
| `0x4facb0` | `CityMap_PlaceHouseBlocks` |
| `0x4fb060` | `CityMap_PlaceLargeComplexes` |
| `0x4db430` | `CityDefinition_ParseIni` |
| `0x4de760` | `Company_ProcessDailyAccounting` |
| `0x4d1cb0` | `MapObject_Construct` |
| `0x506330` | `Object_InitCompanyBuildingGraphics` |
| `0x50c8a0` | `Object_LinkWithFacingObject` |
| `0x50e8e0` | `Player_Construct` |
| `0x511ff0` | `Recipe_AddCategoryIngredients` |
| `0x5239d0` | `UI_CreateFixedWindow` |
| `0x54f167` | `CRT_BeginThread` |
| `0x550655` | `CRT_Fflush` |
| `0x55099b` | `CRT_Sopen` |
| `0x552a61` | `CRT_LoctoTime64` |
| `0x52f910` | `Window_GadgetNotify_Text_SetTextColor` |
| `0x52f930` | `Window_GadgetNotify_Text_GetFont` |
| `0x52f950` | `Window_GadgetNotify_Text_GetLineCount` |
| `0x52f970` | `Window_GadgetNotify_Text_GetHeight` |
| `0x52f990` | `Window_GadgetNotify_Text_ResetScroll` |
| `0x52f9b0` | `Window_GadgetNotify_Text_SetText` |
| `0x52f9d0` | `Window_GadgetNotify_Text_SetLayout` |
| `0x52fa20` | `Window_GadgetNotify_Text_SetMode` |
| `0x52fb00` | `Window_GadgetNotify_Input_SetFilter` |
| `0x52fb20` | `Window_GadgetNotify_Input_GetFilter` |
| `0x52fb40` | `Window_GadgetNotify_Input_SetNormalColor` |
| `0x52fb60` | `Window_GadgetNotify_Input_SetEditingColor` |
| `0x52fb80` | `Window_GadgetNotify_Input_SetFocusColor` |
| `0x52fba0` | `Window_GadgetNotify_Input_SetSelectionColor` |
| `0x52fbc0` | `Window_GadgetNotify_Input_SetText` |
| `0x52fbe0` | `Window_GadgetNotify_Input_GetText` |
| `0x52fcc0` | `Window_GadgetNotify_Slider_SetGradientColors` |
| `0x52fce0` | `Window_GadgetNotify_Slider_SetChangeNotify` |
| `0x52fd00` | `Window_GadgetNotify_Slider_SetRange` |
| `0x52fd70` | `Window_GadgetNotify_Slider_SetValue` |
| `0x52fd90` | `Window_GadgetNotify_Slider_GetValue` |
| `0x52fdb0` | `Window_GadgetNotify_Slider_AttachValueText` |
| `0x52ff50` | `Window_GadgetNotify_Button_SetState` |
| `0x54bb30` | `MapBadgeAnim_Construct` |
| `0x54ce1e` | `CRT_Filebuf_Close` |
| `0x54dded` | `CRT_InitFloatCvtTable` |
| `0x52ff80` | `UI_DisableButton` |
| `0x531910` | `UI_SetButtonSpriteByName` |
| `0x531960` | `UI_SetButtonColorVariant` |
| `0x531980` | `UI_GetButtonSprite` |
| `0x5319a0` | `UI_GetButtonSpriteRecord` |
| `0x531b50` | `UI_ClearButtonRecordAnimation` |
| `0x531b70` | `UI_SetButtonRecordVariant` |
| `0x531b90` | `UI_GetButtonContext` |
| `0x531c40` | `UI_StartButtonMovie` |
| `0x531cf0` | `UI_GetWindowObject` |
| `0x536350` | `FullscreenImage_LoadTGA` |
| `0x536ab0` | `FullscreenImage_LoadPCX` |
| `0x539860` | `Renderer_FlipPrimarySurface` |
| `0x540040` | `SoundPakManager_OpenStream` |
| `0x5401b0` | `SoundPakStream_Read` |
| `0x523ad0` | `Window_CreateSimpleWindow` |
| `0x523c90` | `Window_CreatePictureWindow` |
| `0x52ac50` | `UI_RefreshButtonSprites` |
| `0x52eb70` | `Dialog_ConstructWithSprite` |
| `0x52f080` | `Gadget_SetTextf` |
| `0x52f0d0` | `Gadget_GetSpriteFrames` |
| `0x52f750` | `Gadget_SetButtonColors` |
| `0x52f7a0` | `Gadget_SetButtonTextLayout` |
| `0x52f800` | `Gadget_SetButtonState` |
| `0x52f830` | `Gadget_SetText` |

## Layer 13

| Address | Name |
|---|---|
| `0x4d6cb0` | `MapObjectList_Load` |
| `0x4dd270` | `GameClock_Construct` |
| `0x49c520` | `CompanyRanking_SelectCompanyButton` |
| `0x49c5d0` | `CompanyRanking_SelectLastCompanyButton` |
| `0x49cf10` | `CompanyRating_UpdateScoreText` |
| `0x49e160` | `RecipeInfo_FillNutritionRows` |
| `0x49e830` | `RecipePreview_FillNutritionRows` |
| `0x49f240` | `RecipeMenu_SetCurrentRecipe` |
| `0x49f3b0` | `RecipeMenu_RefreshPortionPreview` |
| `0x49f640` | `UI_RecordList_SetVisibleRange` |
| `0x4a0540` | `GammaOptions_DrawPreview` |
| `0x4a09d0` | `SaveGameMenu_UpdateSlotRows` |
| `0x4a1170` | `SoundOptions_Init` |
| `0x4a1a10` | `LoadGameMenu_UpdateSlotRows` |
| `0x4a21f0` | `AutosaveOptions_Init` |
| `0x4a46c0` | `CompanyOverview_UpdateCityInfo` |
| `0x4a47e0` | `CompanyOverview_UpdateBuildingRows` |
| `0x4a5070` | `TradeOffer_UpdatePanel` |
| `0x48ac00` | `CustomerGroups_DrawProductSalesGrid` |
| `0x48aef0` | `CustomerGroups_DrawTrafficGrid` |
| `0x48b1b0` | `CustomerGroups_DrawCountRow` |
| `0x48b600` | `Map_DrawMinimap` |
| `0x48fad0` | `FinanceScreen_UpdateStatement` |
| `0x490100` | `FurnitureMenu_SetItemSprite` |
| `0x4901b0` | `FurnitureMenu_SetWallFloorSprite` |
| `0x490bd0` | `FurnitureMenu_ShowItemDetails` |
| `0x4919f0` | `Chart_DrawRatingMatrix` |
| `0x492270` | `UI_FillObjectWithPaletteColor` |
| `0x4922d0` | `RenovationScreen_UpdateCost` |
| `0x496680` | `CompareScreen_UpdateRows` |
| `0x498180` | `BranchList_UpdateRows` |
| `0x4982b0` | `BranchList_UpdateSummary` |
| `0x49ad30` | `AdvertisingScreen_UpdateGroupPrices` |
| `0x49c300` | `RankingScreen_UpdateRows` |
| `0x4a5bb0` | `FinancePage_UpdateBalanceSheet` |
| `0x4a6680` | `UI_PrintSignedValue` |
| `0x4a6750` | `UI_DrawAwardMedals` |
| `0x4aa970` | `StatisticsBalance_UpdateBranchProfitColumn` |
| `0x4ab600` | `StatisticsBalance_UpdateHeader` |
| `0x4ac5e0` | `StatisticsBranchBalance_UpdateBranchProfits` |
| `0x4acb90` | `StatisticsBranchBalance_DrawProfitBars` |
| `0x4ad4e0` | `StatisticsBranchBalance_DrawDailyChart` |
| `0x4ae180` | `Glossary_ShowCompanyBuildingDetail` |
| `0x4aec60` | `Glossary_FillCityBuildingList` |
| `0x4aeda0` | `Glossary_ShowCityBuildingDetail` |
| `0x4af2f0` | `Glossary_ShowIngredientDetail` |
| `0x4af5c0` | `Glossary_FillPeopleNameList` |
| `0x4b0020` | `StatisticsBackdrop_UpdateCompanyValues` |
| `0x4b02d0` | `StatisticsBackdrop_RestoreCategorySelection` |
| `0x4b0300` | `StatisticsBackdrop_DrawCompanyBarChart` |
| `0x4b0d80` | `Personnel_DrawEmployeeAbilityChart` |
| `0x4b3d80` | `CompanyOverview_UpdateCompanyRows` |
| `0x4b4280` | `CompanyOverview_BuildCompanyList` |
| `0x4b4630` | `CompanyOverview_DrawQuarterChart` |
| `0x4b5a40` | `BranchScreen_SelectBranchRecord` |
| `0x4bade0` | `BranchPage_UpdateInfoPanel` |
| `0x40cee0` | `SubMenu_BuildBranchBalance` |
| `0x41d610` | `SubMenu_BuildRecipeCheck` |
| `0x420490` | `SubMenu_BuildPizzaContest` |
| `0x42b220` | `SubMenu_BuildTownBalance` |
| `0x447310` | `SubMenu_BuildCompetitorBranchInfo` |
| `0x458f50` | `SubMenu_BuildConstructionInfo` |
| `0x468bd0` | `SubMenu_BuildStadiumInfo` |
| `0x47fb40` | `Branch_EndConstructionMode` |
| `0x47fbd0` | `Branch_StepStarRating` |
| `0x483150` | `IngredientDialog_FillRows` |
| `0x483530` | `CityOverviewDialog_FillRows` |
| `0x488a10` | `Game_UpdateDateLabels` |
| `0x48a5a0` | `Chart_DrawCustomerGroups` |
| `0x48a970` | `Chart_DrawCustomerPortraits` |
| `0x4f6d30` | `Game_CompanyManager_Construct` |
| `0x4fb170` | `CityMap_GenerateLayout` |
| `0x502910` | `Game_AnyBuildingCategoryRatingAbove` |
| `0x4d5650` | `City_InitBuildings` |
| `0x4bd230` | `GuardMenu_FillSummary` |
| `0x4bf120` | `Submenu_SetObjectPicture` |
| `0x4bf730` | `SyndicateMenu_FillStaffCounts` |
| `0x4c0390` | `ConstructionMenu_FillTimeLeft` |
| `0x4c1ae0` | `DeliveryMenu_FillProductRows` |
| `0x4c26c0` | `SupplierMenu_FillClientRows` |
| `0x4c5280` | `PestMenu_FillPricesAndCounts` |
| `0x4c6f90` | `CharacterSelect_FillAttributes` |
| `0x4c7040` | `CharacterSelect_SetPhotoSprite` |
| `0x4c7090` | `FreePlaySetup_SetDifficultyText` |
| `0x4c70f0` | `UI_SetOnlineHelpText` |
| `0x4c7d80` | `SubStartMenu_FillOptions` |
| `0x4c8320` | `EndResultGraph_DrawChart` |
| `0x4c90e0` | `EndResultPoints_FillOverview` |
| `0x4c9390` | `EndResultPoints_FillBuildingTable` |
| `0x4c9610` | `EndResultPoints_FillMissionTable` |
| `0x4c98d0` | `EndResultPoints_FillPersonnelTable` |
| `0x4c9b50` | `EndResults_FillBalancePage` |
| `0x4c9dd0` | `EndResults_FillAdvertisingPage` |
| `0x4ca070` | `EndResults_FillRecipePage` |
| `0x4ca310` | `EndResults_FillSyndicatePage` |
| `0x4ca5e0` | `EndResults_FillRatingPage` |
| `0x4cb520` | `ListDialog_FillRows` |
| `0x4cb6e0` | `FreePlaySetup_FillCityTable` |
| `0x4cb7a0` | `FreePlaySetup_FillStartCapitalText` |
| `0x4cb7e0` | `FreePlaySetup_FillGameLengthText` |
| `0x4cb8b0` | `UI_SetPlayerLogoSprite` |
| `0x4cb900` | `FreePlaySetup_ShowMapPreview` |
| `0x4cbb10` | `FreePlaySetup_FillHighScoreTable` |
| `0x4cd8e0` | `MapList_AddIniRecord` |
| `0x4cde40` | `SubStartMenuA_FillSaveGameRows` |
| `0x4ce3c0` | `FreePlaySubmenu_FillSaveGameRows` |
| `0x4ce720` | `Movie_PlayGameOverMovie` |
| `0x4d2600` | `Game_UpdateObjectMapMarker` |
| `0x4d3680` | `MapActor_RelocateToRandomTile` |
| `0x504610` | `Object_Construct` |
| `0x508d50` | `Object_ApplyDeferredType` |
| `0x50b7c0` | `Object_FindNearbyCustomer` |
| `0x50fab0` | `GamePlan_GetCompanyCategoryMetric` |
| `0x510c90` | `Recipe_CreateGenerated` |
| `0x5520f9` | `CRT_OpenFile` |
| `0x542720` | `SoundVoiceThread_Construct` |
| `0x54b970` | `UI_ComposeOverlayWindow` |
| `0x54bcc0` | `MapBadgeAnim_SetWindow` |
| `0x54cdc7` | `CRT_Filebuf_Destroy` |
| `0x54d686` | `CRT_Ostream_Suffix` |
| `0x54d950` | `CRT_Filebuf_Open` |
| `0x53f320` | `SoundSample_ParseWavFormat` |
| `0x53f8e0` | `SoundSample_ReadADPCM` |
| `0x5243c0` | `Window_RenderFrame` |

## Layer 14

| Address | Name |
|---|---|
| `0x49f500` | `RecipeMenu_ShowSelectedRecipe` |
| `0x49f580` | `RecipeMenu_RefreshSelectedRecipe` |
| `0x49f5f0` | `RecipeMenu_ChooseRecipe` |
| `0x4a0680` | `GammaOptions_Init` |
| `0x4a0a70` | `SaveGameMenu_Init` |
| `0x48b8a0` | `Map_ScrollToClamped` |
| `0x48cb30` | `Map_RefreshObjectSprites` |
| `0x4902a0` | `FurnitureMenu_RefreshSlots` |
| `0x491c80` | `Chart_DrawGroupMatrix` |
| `0x4a53e0` | `UI_DrawNeighborhoodCustomerIcons` |
| `0x481010` | `Branch_SetName` |
| `0x485ae0` | `Game_ShowBranchScene` |
| `0x488cc0` | `Game_SuspendSimulation` |
| `0x488d20` | `Game_ResumeSimulation` |
| `0x4fc0f0` | `Company_OpenBranchAtSite` |
| `0x4fc290` | `Company_OpenBranchInHomeCity` |
| `0x4d4800` | `City_Construct` |
| `0x4d50a0` | `City_CreateBranchObject` |
| `0x4d5160` | `City_CreateExplosionEffect` |
| `0x4d8c80` | `City_CreateObjectsOfType` |
| `0x4d9c00` | `City_SendPoliceUnits` |
| `0x4dc1a0` | `City_SpawnDeliveryVehicles` |
| `0x4e3c00` | `Company_CreateAIStrategy` |
| `0x4bd340` | `GuardMenu_Fill` |
| `0x4bf400` | `SchoolMenu_FillLocalStructure` |
| `0x4c6f50` | `CharacterSelect_DrawPortrait` |
| `0x4c86a0` | `EndResultGraph_SelectCategory` |
| `0x4ca880` | `EndResults_RefreshScreen` |
| `0x4cb860` | `UI_SetImageFromTemplate` |
| `0x4cd960` | `MapList_LoadAllMapDefinitions` |
| `0x4d3730` | `Character_Construct` |
| `0x508c20` | `Object_RebindRenderList` |
| `0x50f870` | `GamePlan_ComputeCategoryEffect` |
| `0x54dfaf` | `CRT_Fsopen` |
| `0x54bb00` | `UI_ComposeOverlayWindowFromRecord` |
| `0x54cc99` | `CRT_Ifstream_Construct` |
| `0x54cdab` | `CRT_Filebuf_Delete` |
| `0x54d140` | `CRT_Ofstream_Construct` |
| `0x53f460` | `SoundSample_Construct` |
| `0x53f650` | `SoundSample_ReadPCM` |
| `0x524990` | `Window_DispatchMouseEvent` |
| `0x526100` | `Window_UpdateTooltip` |

## Layer 15

| Address | Name |
|---|---|
| `0x49b8d0` | `SaveMenu_WriteMenuFile` |
| `0x498930` | `SaveMenu_WritePreview` |
| `0x4eb4f0` | `IsoMap_Load` |
| `0x49ba50` | `Recipe_ImportFile` |
| `0x498bd0` | `SaveMenu_Load` |
| `0x49fa20` | `RecipeMenu_PrevRecipe` |
| `0x49fa70` | `RecipeMenu_NextRecipe` |
| `0x48b570` | `Game_AutoSaveTick` |
| `0x4a5420` | `BauenPage_ResetBuildingSlots` |
| `0x480900` | `Branch_SpawnRandomPedestrian` |
| `0x488db0` | `Game_ShowBranchInteriorDefaultZoom` |
| `0x4d4940` | `City_SpawnPerson` |
| `0x4d7ed0` | `City_CollectBranchesNearPoint` |
| `0x4d9de0` | `City_SendPoliceToDistrictWithSiren` |
| `0x4d9ef0` | `City_SendPoliceToDistrict` |
| `0x4da000` | `City_TrySendPoliceToDistrict` |
| `0x4c03c0` | `ConstructionMenu_Fill` |
| `0x4c86f0` | `EndResultGraph_Fill` |
| `0x4d23b0` | `Game_CenterViewOnObject` |
| `0x508070` | `Object_ScrollViewToObject` |
| `0x50f840` | `GamePlan_ComputeAverageEffect` |
| `0x514510` | `Storage_OrderDelivery` |
| `0x5424b0` | `SoundVoice_WriteSamples` |
| `0x540a30` | `SoundBuffer_FillFromSample` |
| `0x541930` | `SoundStream_LoadNextSample` |
| `0x524970` | `Window_NotifyMouseMove` |
| `0x525fd0` | `Window_DispatchWindowMessage` |
| `0x527e20` | `Window_SetCursorPosition` |

## Layer 16

| Address | Name |
|---|---|
| `0x4a6fc0` | `BuildingMarket_ShowSelectedBuildingInfo` |
| `0x478420` | `Branch_GetPriceComparisonRating` |
| `0x47e6a0` | `Branch_ApplyBuildingStyleVariant` |
| `0x47ef30` | `Branch_AdvanceWeekStatistics` |
| `0x488de0` | `Game_EnterBranchInterior` |
| `0x4d4a20` | `City_InitPopulation` |
| `0x4d6c10` | `City_RemovePersonAndMaintainPopulation` |
| `0x4dc330` | `City_ResetPoliceDistrictSlot` |
| `0x4c6780` | `UI_WarpCursorToControl` |
| `0x50fba0` | `GamePlan_ComputeEffectValue` |
| `0x5142c0` | `Storage_ReceivePendingOrder` |
| `0x514450` | `Storage_SetSupplierBuilding` |
| `0x541ae0` | `SoundVoice_Open` |
| `0x544d90` | `Sound_LoadSample2D` |
| `0x545290` | `Sound_LoadSample3D` |
| `0x5456a0` | `Sound_LoadSample3DEx` |
| `0x532890` | `UI_SetWindowVisible` |
| `0x525a10` | `Window_ProcessMessageQueue` |

## Layer 17

| Address | Name |
|---|---|
| `0x47b000` | `Branch_Load` |
| `0x47a3b0` | `Branch_GetCustomerGroupRating` |
| `0x482740` | `City_Register` |
| `0x4880c0` | `Game_UpdateLoadProgress` |
| `0x4d6c00` | `City_RemovePersonEntry` |
| `0x50fb70` | `GamePlan_SetActiveEffect` |
| `0x541d50` | `SoundVoice_Construct` |
| `0x5420d0` | `SoundVoice_ServiceStream` |
| `0x523d60` | `Window_ShowWindowById` |
| `0x523f10` | `Window_HideWindowById` |
| `0x526700` | `Window_DestroyChild` |

## Layer 18

| Address | Name |
|---|---|
| `0x48cae0` | `Game_SetObjectInfoWindowVisible` |
| `0x4052a0` | `Screen_CloseSubStartMenu` |
| `0x406a60` | `UI_CloseLoadingScreen` |
| `0x477000` | `Branch_ConstructFromStream` |
| `0x482860` | `UI_DestroyWindowAt` |
| `0x4830e0` | `Game_DestroyEventWindow` |
| `0x4850a0` | `Game_SetViewMode` |
| `0x4fe870` | `Company_AllocateMenuSales` |
| `0x4ff6e0` | `Branch_AutoTunePrice` |
| `0x501f90` | `Game_GetBestBuildingRatingBand` |
| `0x502a10` | `Game_AllBuildingCategoryRatingsAbove` |
| `0x4d8140` | `Game_FindBestCompositeRatedBranch` |
| `0x4dfe40` | `Stats_ComputeCompanyRatingStats` |
| `0x4ce9d0` | `Movie_Play` |
| `0x5080f0` | `Object_IsSiteRatingSufficient` |
| `0x5428c0` | `SoundVoiceThread_Run` |
| `0x545100` | `Sound_CreateVoice` |

## Layer 19

| Address | Name |
|---|---|
| `0x4e0f90` | `Company_Load` |
| `0x49d970` | `RecipeEditor_ShowIngredientCursorSprite` |
| `0x4a21a0` | `Game_HandleQueryEndSession` |
| `0x48c160` | `Game_SelectPlayer` |
| `0x499c40` | `IngredientPanel_ShowSpritePreview` |
| `0x482880` | `Game_DestroyRootWindow` |
| `0x482890` | `Game_CloseSelectionDialog` |
| `0x483c40` | `Game_DestroyCachedScreens` |
| `0x487310` | `Game_ShutdownWorld` |
| `0x502430` | `Game_GetStatBandByIndex` |
| `0x502a90` | `AI_SelectStrategyAction` |
| `0x4dec10` | `Company_RecordDailyStatistics` |

## Layer 20

| Address | Name |
|---|---|
| `0x502b80` | `AI_SelectActionForType` |
| `0x4ddab0` | `Company_Construct` |
| `0x4c67f0` | `IngredientMenu_HandleInput` |

## Layer 21

| Address | Name |
|---|---|
| `0x502ce0` | `AI_InitActionPlan` |
