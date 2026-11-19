# Non-leaf reversal — depth 2 complete (295/295)

Depth 1 is complete (480/480). **The frozen depth-2 set is also complete: 295/295 named, 0 unnamed.** The ledger now contains 787 non-leaf names.

## Completion verification

Fresh REA export in `depth2_verification/`, checked against the frozen 295-address depth-2 set:

```text
initial depth2: 295
named in REA export: 295
unnamed: 0
func_symbols: 787  unique addresses: 787  unique names: 787
initial depth2 in ledger: 295
```

## Named in this wave

| Address | Name | In-degree | Evidence |
|---|---|---:|---|
| `0x531740` | `UI_RemoveObjectByKey` | 93 | Removes a UI object found by key and marks the list dirty. |
| `0x5301c0` | `UI_QueueControlCommand` | 62 | Queues a UI control command with four parameters. |
| `0x54ea8f` | `CRT_QSort` | 22 | Generic CRT quicksort over fixed-size records. |
| `0x5499f0` | `Sound_ProcessEvent` | 19 | Dispatches a sound event by type and parameter. |
| `0x531f50` | `UI_SetObjectTextByKey` | 16 | Sets text of a UI object found by key. |
| `0x532a30` | `UI_AddUniquePair` | 15 | Adds a unique key/value pair to a UI list. |
| `0x5271d0` | `UI_ReleaseRefCount` | 14 | Decrements a UI object reference count and releases it. |
| `0x548210` | `Sound_HandleEvent` | 14 | Handles a sound event for the active sound object. |
| `0x530f80` | `UI_EnsureObjectArray` | 11 | Grows/initializes the UI object array. |
| `0x531400` | `UI_SetObjectRangeByKey` | 10 | Sets min/max range on a UI object found by key. |
| `0x48c040` | `Game_SetMessageField34` | 7 | Thin wrapper forwarding (this+0x304, param_1, param_2) to MessageList_SetField34, which stores the value at record+0x34. |
| `0x5480c0` | `Sound_PlaySfxByIndex` | 5 | When sound is enabled and index < 0x25, formats 'Sfx_%s.wav' (or 'Sfx_%s_%s.wav' for index 0xb) from the 0x575190 table and plays it through Sound_PlayChannel(this,name,1). |
| `0x4f5bb0` | `UI_DrawCenteredSelectionRect` | 5 | Computes a centered rect with UI_ComputeCenteredRect, offsets it by -0x1e on both axes around owner +0x24/+0x28 and submits the 5-dword rect list to Gfx_BlitRectList(DAT_0058072c,...). |
| `0x4d3930` | `Game_GetRecordField814Value` | 5 | Calls Game_GetRecordByField814 and returns the dword at record+4, i.e. the value stored alongside the +0x814 key. |
| `0x541660` | `SoundBuffer_DestroyInterfaces` | 4 | Intermediate sound-buffer destructor (vtable 0x55c8c8): releases the +0x5c and +0x48 objects through vtable+8, frees the +0x38 node list and chains through 0x5408b0/0x540f60 to 0x55c840. |
| `0x500f40` | `Company_PushRecentEntry` | 4 | In the 0x168-stride company row at +param_1, searches ten 0x10-byte entries at +0x74 for (+0xc,+0)==(param_2,param_3); on a hit removes it, then shifts 0x90 bytes with memmove and writes the new entry at the front. |
| `0x47fed0` | `Game_CountFreeResidentialBuildings` | 4 | Sums Game_CountFreeBuildingsByType for object types 0x1a, 0x1b and 0x1c on the player's +0x16f0 building table. |
| `0x5377d0` | `Surface_ConfigureFromOwner` | 4 | Reads width/height/pitch from owner fields +4/+8/+0x18 and calls Surface_Configure on the target surface with those dimensions. |
| `0x533af0` | `Record_ApplyVariantState` | 3 | Validates a stride-0x48 record and its 0x98-stride variant table entry (param_2<0x10, entry != -1), clears +0x3c..+0x40, calls Record_SetVariant and stores param_3 at +0x3d. |
| `0x4e21d0` | `Game_UnlinkBuildingObject` | 3 | Looks up the global map object by id, clears its +0x10c/+0x110 fields to -1, then finds the entry whose +0 equals that id in the this+0x1b8 map and removes it via IDMap_RemoveByKey. |
| `0x527a10` | `UI_RefreshChildSprite` | 3 | If the element index is 0 or the cached sprite +0x8314 is null it calls UI_ClearChildExtent, otherwise UI_SetElementSprite with the cached sprite and param_2/param_3 position. |
| `0x53b8f0` | `Sprite_BlitRLEOpaque` | 2 | RLE sprite blit into a 3-byte-per-pixel surface: clips against surface rect +4..+0x10, uses color key +0x1c and four skip-token modes (param_6) with optional horizontal stretch (param_7). |
| `0x521790` | `UI_DrawLine` | 2 | Rasterizes a line between two points by repeated UI_RenderDrawCommand calls, with dedicated horizontal and vertical loops and a Bresenham error term for diagonal lines. |
| `0x4d8320` | `Game_ComputeAreaAttraction` | 2 | Resets +0x98 counters, bumps the eight linked objects' counters for active buildings, then sums nearby records' +0x98 inside radius param_2^2*4 (y weighted 4x) or player+0x48>>3 for type 0x20. |
| `0x47ca80` | `Game_ComputeAverageCategoryValue` | 2 | Averages Game_GetRecordByte14 over records in the +0x16f8 map whose Game_GetPlayerByte8 equals param_3, clamps the mean to 0..2 and rounds it with Math_RoundFloat. |
| `0x50d810` | `UI_UpdateValueBar` | 2 | Computes a cost via Object_GetLevelProperty (type 0xd) or Economy_GetModifier(player slot,type,2), subtracts it from +0xa8, clamps at 0 and calls UI_SetChildHeightFromValue. |
| `0x50d220` | `Object_IsWithinServiceRange` | 2 | Compares this object's position (+0x200 sprite via Record_GetTwoFloats48) with object param_2; always true for types 0xd/0x17/0x1d and for type 0x1e only if squared distance with y*4 is below 0xe10. |
| `0x539f90` | `Renderer_InitForWindow` | 2 | Stores the window client rect into +0x84/+0x8c via GetClientRect/ClientToScreen, creates/acquires surfaces through the +0x40 vtable chain and sets the initialized flag +0x94 before Renderer_CopyStateToChildren. |
| `0x4ddf10` | `Game_ComputeCompanySharePercent` | 2 | Sums Stats_SumValuesByCategory for every active company with the current turn value (+0x94[10]) and returns the supplied record's value divided by that total times 100. |
| `0x47fe10` | `Game_ShowBuildingOverlay` | 2 | When param_1==1 sets flag +0x1a20 and calls UI_SetChildHeightFromValue for every player building whose State_Is1A1B1C is true. |
| `0x509170` | `Record_DoublePositionValue` | 2 | Reads the 8-byte point at stride-0x48 record+0x28, doubles it and writes it back through UI_SetListEntryPosition; an invalid index writes zero. |
| `0x4e3820` | `Game_ComputePlayerSalary` | 2 | Returns a wage from base 20000 (+0x68==1, Game_GetPlayerFieldC20>4) or 40000 (==2, >5), multiplied by (10 - city+0x58 - city+0x40)*10/100, else -1. |
| `0x47aba0` | `Game_GetMarketBonus` | 2 | Returns (this+0x14d0 + this+0x14c0)>>2, padding the result by Rating_GetComposite(+0x14c4)/20 while it is negative; zero when +0x14c4 is null. |
| `0x4d29d0` | `Game_RemoveRecordFromLocalMap` | 2 | Removes the key stored at record+0x164 from the this+0x78 map via IDMap_RemoveByKey and clears the record's +0x168 field with Set_Field168. |
| `0x4df780` | `Game_ComputeCompanyRankStats` | 1 | Aggregates per-company totals and maxima (Stats_SumFilteredFloats, Game_GetAdjustedValue, Game_SumStatGrid/Row8), compares all six companies and writes weighted rank values to +0x160..+0x16c. |
| `0x51e650` | `UI_LoadStringTable` | 1 | Copies 47 fixed UI string-id ranges from the language table into the global UI blocks DAT_00582fxx..DAT_005840xx via Language_CopyStringIds. |
| `0x47db30` | `Game_CollectObjectsAtPoint` | 1 | Under CS +0x244 iterates the player's building list, skips State_Is2DOr2E objects, maps each record's bounds to screen with Record_GetBounds48 and appends {1,object} to the list when the point is inside. |
| `0x4dfaf0` | `Game_ComputeCompanyOverviewStats` | 1 | Fills a stats block (+0x9c..+0xb8, +0x170..+0x17c) with building counts, max/total AI_CountPlanSteps, per-index averages from Game_MapInputIndex and weighted scores across companies. |
| `0x47c8a0` | `Game_ComputeAverageProductQuality` | 1 | Averages product byte +0x14 per category 1..4 across the +0x16f8 map (category 3 requires byte!=0), then returns Math_RoundFloat((sum of means)*12.5). |
| `0x5343d0` | `RecordList_DrawVariantSprite` | 1 | Under CS 0x5842a0 validates a stride-0x48 record and its +0x32 variant index, loads four shorts from the +0x20/+0x24/+0x28/+0x2c tables into +6..+0xc and calls the sprite blitter 0x53a780. |
| `0x4f1e10` | `Object_TryNeighborPlacement` | 1 | Maps the target point to a map cell with Map_ComputeBlitRect, walks to a neighbor via Grid_GetNeighborCell and tests Object_CanAssignSlot; returns whether a free slot was found. |
| `0x541790` | `SoundStreamBuffer_Destruct` | 1 | Derived sound-stream destructor: releases the +0xac interface (vtable 0x55c8b0), then +0x5c/+0x48 objects, frees the +0x38 list and chains through the baseline destructor. |
| `0x4d3080` | `UI_IsSpriteVisibleInView` | 1 | Builds the object's sprite rect from UI_AlignSpriteToRect, Sprite_GetHotspot and Sprite_GetSize plus owner +0x24/+0x28, then tests it against UI_GetViewRect expanded by 0x23. |
| `0x406a90` | `Settings_InitDefaults` | 1 | Clears the 0x59-dword global options block DAT_0057b8a8, loads settings via Settings_LoadFromRegistry, and on failure fills defaults including random ranges, 0xfa, -1 sentinels and 100% values. |
| `0x479460` | `Map_CheckTileEdgeMatch` | 1 | Resolves the neighboring grid cell, maps its object-list index and returns 1 when the two adjacent edge words (0x280-stride pairs at +0x14/+0x294, -4/+0x27c, +0x504/+0x50c, -0x27c/-0x274) equal 2 for the matching direction. |
| `0x4e46f0` | `Game_DecayCityDateBonus` | 1 | Moves the double at +0x10 toward zero (-4 or +2, clamped) while flag +0x1c is clear, then calls Game_ComputeCityDateBonus. |
| `0x4e33a0` | `Game_BuildStatusTextByIndex` | 1 | Resolves index <0x14 via map +0x148, 0x14..0x27 via map +0x180 (+0x34 object) and >0x27 via +0x1d8, then forwards the +0x16f0 object to Game_BuildCompanyStatusText. |
| `0x4d8be0` | `Game_FindNearestTransportBuilding` | 1 | Scans the player's +0xfac records of type +4==2 with a valid +0x54 tile, computes Map_FindShortestPath from the source tile and returns the record with the smallest distance. |
| `0x54d20a` | `CRT_FileBufClose` | 1 | Stream close helper: locks the stream (+0x30/+0x34), calls stream vtable +0x10 with mode 2, sets fail flag 2 via Thread_SetField8Locked on -1 and unlocks, returning this. |
| `0x47fe70` | `Game_HideBuildingOverlay` | 1 | When param_1==1 clears flag +0x1a20 and calls Object_SetChildShort for every player building whose State_Is1A1B1C is true and which has a child at +0xc8. |
| `0x4e28e0` | `Game_ResetBuildingUtilization` | 1 | Increments +0x6c and for every +0x1b8 record of type 0x1d sets the global object's +0xa8 to 100 and calls Object_GetPlayerValue(object,-1). |
| `0x47ffb0` | `Game_GetBuildingConditionCode` | 1 | Scans the +0x1500 map and returns 5 when Rating_AdjustB(object)<0x14, 4 when object+0xc<0x14, otherwise 0. |
| `0x535cf0` | `PaletteList_Free` | 1 | Frees every palette pointer in the array at +0 (count +8) through Palette_Free, then frees the array and the secondary buffer at +4. |
| `0x480d20` | `Game_HasBuildingWithSameType` | 1 | Scans the player's +0x16f0 buildings and returns 1 when another object's +0x8c equals param_1+0x20. |
| `0x54ca80` | `Thread_ReleaseNodeValues` | 1 | Frees every value in the IDMap at owner+0x50 (count +0x64), then resets the container via List_Node_Reset. |
| `0x5105c0` | `Object_DeleteAllInMap` | 1 | Calls vtable slot 0 with argument 1 (deleting destructor) on every object in the IDMap at +0x48, then resets the list via List_Node_Reset. |
| `0x50d8f0` | `Object_SyncScreenY` | 1 | Resolves the object's map record (+0x16) and writes its second coordinate (Y) from Record_GetTwoFloats48 into +0x98. |
| `0x403bb0` | `Timer_RemoveById` | 1 | Walks the timer list at +0xc for a node whose +0x10 equals param_1 and unlinks it via Timer_RemoveEntry. |
| `0x4fcc00` | `Game_AdjustPlayerPercentByKey` | 1 | Scans the six stride-0x168 slots starting at +0x40 for the slot id param_1 and calls Object_AdjustShortPercent(this,index,5). |
| `0x53d650` | `Surface_BlitRLEEnsureFormat` | 1 | Lazily converts the surface via 0x53cea0 when +0x39 is clear, then calls Surface_BlitRLESkipToRGB with the object's +0x2c pixel buffer. |
| `0x52ff30` | `Array_GetRecordField40` | 1 | Binary-searches the key with Array_GetRecordByKey and returns the dword at record+0x40, or -1 when not found. |
| `0x4d2a90` | `Game_RemoveLocalEntryRecursive` | 1 | Thin wrapper removing key param_1 from the this+0x78 ID map via IDMap_RemoveRecursive. |
| `0x4a1af0` | `SaveGameList_Destroy` | 1 | Destroys the global save-slot list DAT_0057cfc8 through IDMap_DestroyAllObjects (virtual destructors on all entries plus the map itself). |
| `0x544300` | `Sound_SetAllVoicesVolume` | 0 | Under CS +0xa0 converts param_3 to 0..10000 using +0x84 and iterates the voice list: Sound_SetBufferVolume for node types 0/1, or stores +0x78/+0x9c and applies the volume on the buffer for type 2. |
| `0x48cd40` | `Game_IsBuildingAssignedToOtherCompany` | 0 | Resolves index <0x14 via +0x148, <0x28 via +0x180 or +0x1d8 of player param_2, skips the local player and tests Game_IsValueAssignedToCompany(current player, object+0x16f0/0x34). |
| `0x4d2aa0` | `Game_FindObjectByClass` | 0 | Linear scan of the +0x8c objects returning the first whose +0x30 class equals param_1, or 0. |
| `0x540890` | `SoundBuffer_DeleteObject` | 0 | Deleting destructor: calls SoundBuffer_Destruct and frees the object with Mem_Free when bit 0 of param_1 is set. |
| `0x4dc720` | `Game_PlaceObjectInPlayerCity` | 6 | Calls MapObject_SetCityFromPlayer(object, this+0xfa8, slot), sets field +0xf4 of the object at this+0xfa8 to 1, and clears object+0x38 when slot is -1. |
| `0x50b100` | `UI_ComputeObjectDirection` | 5 | Subtracts the camera offsets at this+0xc4+0xf8/0xfc from Record_GetTwoFloats48 coordinates, then atan2 and &7 produce an 8-way direction. |
| `0x486e20` | `Game_CountRecordsForSelectedPlayer` | 5 | Selects player -1 (this+0x2ec slot) or Game_GetPlayerBySlot and forwards to Game_CountRecordsByField34. |
| `0x533c90` | `Record_AdvanceFrameSequence` | 4 | Walks a stride-0x48 record through its 0x98-byte variant table using +0x32/+0x36, calls Record_SetVariant/Record_ClearFlags48 and accumulates the cell step. |
| `0x5219a0` | `Sprite_FillRectColor` | 4 | Clips a rectangle to Sprite_GetSize, converts the color with Color_RGBTo16FromDword, then fills rows via Memory_FillWords16. |
| `0x47ccd0` | `Game_CountRecordsByByteC` | 4 | Iterates IDMap this+0x16f8 and counts records whose Game_GetRecordByteC equals the argument. |
| `0x4ffeb0` | `Game_AdjustPlayerObjectPercent` | 4 | Resolves the player by slot, checks this+slot*0x168+0x114, then applies Object_AdjustShortPercent with the player index and percent. |
| `0x523900` | `UI_ReplaceActiveObject` | 4 | Releases this+0x1c4 via Movie_ReleasePlayer, stores the new object, sets this+0x83b8=1 and calls UI_MarkFullRectDirty. |
| `0x526e80` | `UI_SetBackgroundSurfaceEnabled` | 3 | Under lock, stores the enable flag at +0x284; on enable it derives a surface from the type-2 game object and Gfx_FillSurfaceColor, then redraws. |
| `0x53d600` | `Sprite_BlitWithDefaultAlpha` | 3 | Ensures the sprite is prepared (this+0x39), substitutes DAT_00585518 for a -1 alpha, and calls Sprite_BlitAlphaRLE. |
| `0x4030f0` | `Game_FormatObjectName` | 3 | Chooses a name variant using Random_Mod on this+0x10/0x12 and writes the "%s %s" composite into the object name buffer. |
| `0x4f1750` | `AI_ComputeWeightedPath` | 2 | Dijkstra-style expansion over up to 12000 records: 8 linked neighbors (+0x14), Object_DistanceWeighted edge costs, then reconstructs the path into a pointer list. |
| `0x4d32f0` | `MapSprite_InitializeRecord` | 2 | Allocates a 0x7c map-sprite record, initializes its +0x14 record list, binds sprite entries from global arrays 0x2c0cc/0x2c180, allocates two stride-0x48 records and appends it to the active list. |
| `0x4da390` | `Game_AdjustPlayerRankingScores` | 2 | For six players, adds or subtracts rating points by comparing player counters with Game_GetMostAdvancedCompany and adds city +0x48/+0x60, clamped 0..100. |
| `0x50b370` | `Object_HasNearbyType20Object` | 2 | Scans the map records around this object and returns 1 when another type/subtype 0x20 object lies within the squared-distance radius. |
| `0x524fd0` | `UI_SelectObjectRecord` | 2 | Validates the object and Array_GetRecordByKey result, releases the previous target, then stores +0x82c8/+0x82d4 and the active +0x224/+0x22c pair. |
| `0x4e6340` | `Game_DrawMapObjectSprite` | 2 | Resolves the sprite through SparseMap_Lookup48, aligns it with UI_AlignSpriteToRect, then Gfx_BlitRectList blits its hotspot-adjusted rectangle. |
| `0x47c730` | `Game_ClearPendingMapObjects` | 2 | Drains IDMap this+0x19e0: clears map tile fields, removes the key, deletes each object via its vtable slot 0, and resets this+0x1718. |
| `0x54d2dc` | `Stream_GetReadPosition` | 2 | Locks the stream mutex and invokes vtable slot +0xc with (0,1,1); SaveGame_Read compares the returned offset against stored section positions. |
| `0x4dbf50` | `Game_GetPlayerSupplyScore` | 2 | Base +0xc98[slot] plus 3*(city+0x48+0x60) minus active type 0x1e and 0x1d counts, clamped to 0..100. |
| `0x4de670` | `Game_GetMaxMatrixValue` | 2 | Returns Matrix_Max4x9 for a supplied matrix, otherwise scans all 4x9 Game_SumPlayerMatrixValues entries for the maximum. |
| `0x4edb70` | `Object_ClearRecordFirstBytes` | 2 | Object_GetBufferPair yields a count and buffer; clears byte 0 of each stride-0x28 subrecord. |
| `0x4d32e0` | `MapSprite_ReleaseRecordList` | 2 | Frees the buffer at this+0x14 that 0x54b390 allocates as a 60-entry record-index list; called by the map-sprite destructor 0x4d3280. |
| `0x538f60` | `Surface_LockAndMark` | 2 | Calls Surface_Lock(this,1) and sets this+0x2c=1 only when the lock succeeds. |
| `0x4df480` | `Stats_ComputePlayerAggregateStats` | 1 | Aggregates Stats_SumFilteredRecordFloats20/Stats_SumFilteredFloats over this+0x148 for up to 6 players and stores totals, maxima and ratios at +0x60..+0x19c. |
| `0x548af0` | `Sound_UpdateProximityGain` | 1 | Sums 0.333*(1-dist/range) against nearby world objects, then calls vtable +0x7c with the gain or +0x68 to stop the sound. |
| `0x4d4170` | `Rating_DecayAndUpdateIndicators` | 1 | Moves four signed counters toward zero, then sets UI child states 0x24/0x26/0xffff from Rating_HasNegative/Rating_HasPositive and +0x10/+0xc thresholds. |
| `0x513100` | `Stats_ComputeWeightedAverages` | 1 | Accumulates +0xac[subtype] weights scaled by byte +0xc8 and chars +0xcc/+0xcd into +0x24c/+0x250/+0x254, then averages and rounds. |
| `0x47dd00` | `Game_CollectBuildingHitsAtPoint` | 1 | Scans IDMap this+0x16f8, aligns each sprite rectangle, and appends an 8-byte {3,record} entry to the hit list when the point is inside. |
| `0x47e750` | `Game_PickFreeConstructionPlot` | 1 | Scans IDMap this+0x1998 for entries with +0x1c==0 not already owned by a type-3/subtype-4 building, then returns a Random_Range pick. |
| `0x4893a0` | `Input_HandleMapClickAtCell` | 1 | For input code 9 stores the click origin; for code 10, when movement is under 10 px, advances the animation frame at the clicked map cell under lock. |
| `0x4de360` | `Stats_GetMaxDailyFilteredSum` | 1 | For up to 100 days and 9 columns, takes the maximum of Stats_SumFilteredFloats totals across the player records. |
| `0x4e9d90` | `Game_ReleaseConstructionSpriteLists` | 1 | Releases 0x29 pairs of cached sprite lists at +0x2c314 and eight single lists at +0x2c3bc..+0x2c3d4 via List_ReleaseSharedBuffers. |
| `0x47c9a0` | `Game_GetAverageRecordValueByByte8` | 1 | Averages record +0xc over IDMap this+0x16f8 entries whose Game_GetPlayerByte8 matches, clamps 0..100 and rounds. |
| `0x549e80` | `Sound_PlayBuildingSpecialSfx` | 1 | Maps indices 0..9 to Sfx_City_Building_Special_* globals, formats the resource name and calls Sound_PlayChannel. |
| `0x47cb70` | `Game_GetAverageCompanyValueByByte8` | 1 | Averages the company +0x70 double looked up in global +0x74 by record+4 for records whose Game_GetPlayerByte8 matches, rounded via Math_RoundFloat. |
| `0x4803c0` | `Game_RemoveMapObjectAtPoint` | 1 | Removes the object from IDMap this+0x19e0, clears its tile field, computes the cell rectangle and blits the dirty rect via Gfx_BlitRectList. |
| `0x50d440` | `Object_PlayStateSound` | 1 | Switches on object type +0x30 and player score, selecting Sound_PlayEffectByIndex(0x28) or Sound_PlayTrackIfSelected(0x20/0x23/0x29). |
| `0x54d272` | `Stream_GetWritePosition` | 1 | Locks the stream mutex and invokes vtable slot +0xc with (0,1,2); SaveGame_Serialize stores the result as a section offset. |
| `0x4d82b0` | `Game_PickBestScoredRecord` | 1 | Scans the IDMap in param_2 and returns the entry maximizing this+0x5c[type], where type comes from Game_GetPlayerSubmapValue(+8,+0x2c). |
| `0x4e29b0` | `Game_AdvanceProductionCounter` | 1 | Increments +0x64 and for each +0x1b8 record with +4==0x17 sets map +0xa8=100 and calls Object_GetPlayerValue. |
| `0x4d4480` | `Rating_StoreDailyResults` | 1 | Writes Rating_GetComposite, Rating_ClampAdjusted, Rating_AdjustA, +0xc and Rating_AdjustB into five per-day arrays indexed by the date day. |
| `0x480070` | `Game_CountObjectsType1DSub19` | 1 | Scans this+0x16f0 records and counts those with +0x30==0x1d and +0xa4==0x19. |
| `0x4e2c40` | `AI_GetMaxPlanSteps` | 1 | Iterates the player plan IDMap at +0x110 and returns the maximum AI_CountPlanSteps result. |
| `0x4e2ca0` | `AI_SumPlanSteps` | 1 | Iterates the player plan IDMap at +0x110 and sums AI_CountPlanSteps results. |
| `0x477360` | `Game_FindMapRecordByTypeE` | 1 | Scans this+0x16f0 and returns the first Game_MapRecordToGlobal record whose +0x30 equals 0x0e. |
| `0x4ea400` | `Game_BlitScaledObjectSprite` | 1 | Blits the object sprite at +0x2f884 scaled by +0x2f880/+0x2f888 through Gfx_BlitRLEScaled. |
| `0x4ead50` | `Game_HideAllLinkedElements` | 1 | For every entry in IDMap +0x2c3f8 (count +0x2c40c) calls Object_HideLinkedElements. |
| `0x4e63f0` | `Game_ComputeRecordCompanyPrice` | 1 | Looks up the company referenced by this+4 in the global company map and returns Game_ComputePrice for the requested argument. |
| `0x531f80` | `UI_ReleaseChildBufferByKey` | 1 | BinarySearch8 resolves the child key and Buffer_ReleaseField0C releases its buffer at +0xc. |
| `0x483fa0` | `Game_MapPlayerStatusToAnimation` | 1 | Maps Game_GetPlayerByte8: 5->0x20, 7->0x16, otherwise 0x0b when a player is selected in the UI. |
| `0x4800c0` | `Game_CountFreeBuildingsTypeD` | 1 | Wraps Game_CountFreeBuildingsByType(this+0x16f0,0x0d); sibling wrapper 0x480060 does the same for type 0x17. |
| `0x546090` | `Sound_CreateAndEnqueueBuffer` | 0 | Locks +0xa0, allocates a 0xb4 SoundBuffer, constructs and initializes it (vtable 0x55c8b0), then links the new node into the list at +0x54. |
| `0x52ad60` | `UI_BuildListItem` | 0 | Fills a list-item struct: selects type 0x6d..0x70 from two flags, copies +0xb4, the +0x1ac name via UI_FindStringRecord and +0xd4..+0xdc. |
| `0x54d0b1` | `Stream_TryAttachBuffer` | 0 | When +0x4c is -1 or +0x14 is zero, attaches [param_1,param_1+param_2) under the stream lock (sets fail flag +8 when args are invalid); otherwise returns null. |
| `0x54dca7` | `Stream_AllocateAttachedBuffer` | 0 | Allocates a 0x200-byte buffer and attaches it as owned via Stream_AttachBuffer(...,1). |
| `0x545b00` | `List_ContainerDestroy` | 0 | Calls List_ContainerDestruct and frees the container when the delete flag is set. |

## Status

- Frozen depth-2 candidate set: **295**.
- Five parallel reviewers are analyzing batches of 59 and writing `depth2_proposals_1..5.csv`.
- Durable ledger: `func_symbols.csv`.

## Next

Merge proposals, annotate in REA batches with budget resets, then verify with a fresh export.
