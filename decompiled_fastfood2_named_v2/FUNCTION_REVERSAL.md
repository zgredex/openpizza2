# Non-leaf reversal — depth 1 complete (480/480)

Leaf phase is complete (480/480). **The frozen initial depth-1 set is also complete: 480/480 named, 0 unnamed.** The ledger additionally contains 12 newly unlocked non-leaf names, for 492 rows total.

## Completion verification

Fresh REA export in `depth1_verification/`, checked against the frozen initial depth-1 addresses:

```text
initial depth1: 480
named in REA export: 480
unnamed: 0
func_symbols rows: 492  unique addresses: 492  unique names: 492
```

The next phase is depth 2: functions whose callees are now fully named after this wave.

## Named in this wave

| Address | Name | In-degree | Evidence |
|---|---|---:|---|
| `0x50e850` | `Object_SetFieldA4Locked` | 40 | Stores +0xa4 under the global game lock. |
| `0x4d2a60` | `Game_MapRecordToGlobal` | 39 | Maps a record through this+0x78 into the global +0x3c map. |
| `0x401440` | `List_Node_Reset` | 33 | Frees both buffers, clears counters, sets the 100000 limit. |
| `0x534370` | `Record_GetTwoFloats48` | 31 | Converts two floats from a stride-0x48 record to ints. |
| `0x4e2280` | `Game_GetPlayerFieldC20` | 31 | Looks up player record and returns +0xc20+index*4. |
| `0x507550` | `UI_SetChildState` | 30 | Maps a state value to child+8 constants. |
| `0x47aac0` | `Game_CountObjectsByType` | 30 | Counts map objects whose +0x824 byte matches a type. |
| `0x489820` | `Game_GetPlayerSubmapValue` | 28 | Looks up a player slot then a value in its +0x148 map. |
| `0x5090e0` | `UI_DetachChildRecord` | 26 | Clears child record references and resets state. |
| `0x531470` | `Array_SetField14ByKey` | 25 | Binary-searches a key and writes +0x14. |
| `0x4d3910` | `Game_GetRecordByField814` | 21 | Looks up +0x814 in the global +0x3c map. |
| `0x547e70` | `Sound_SelectCurrentTrack` | 19 | Selects the current sound track from game state. |
| `0x4ddde0` | `Game_CountActiveCompanies` | 19 | Counts map records with +0x1dc == 1. |
| `0x4ed780` | `UI_AlignSpriteToRect` | 17 | Aligns sprite size/position against a target rect. |
| `0x4d4000` | `Rating_GetComposite` | 17 | Averages the four rating adjustment helpers. |
| `0x4016b0` | `IDMap_RemoveRecursive` | 16 | Recursively removes an ID-map entry above 99999. |
| `0x477fe0` | `Stats_SumFilteredFloats` | 16 | Sums filtered float records from a map. |
| `0x4787f0` | `Stats_GetAverage8` | 16 | Returns one of eight values or their average. |
| `0x403850` | `Math_RoundFloat` | 16 | Rounds a float to an integer. |
| `0x5314a0` | `Array_GetPairByKey` | 16 | Binary-searches a key and returns +0x38/+0x3c. |
| `0x4e5df0` | `Game_GetPlayerByte8` | 16 | Looks up a player record and returns byte +8. |
| `0x534e20` | `Gfx_BlitRectList` | 15 | Blits a list of rectangles/sprites into a surface. |
| `0x4034b0` | `Random_Mod` | 15 | Returns rand() % param. |
| `0x521b30` | `UI_ClipChildRect` | 15 | Clips the child rectangle at +0x28. |
| `0x504a90` | `Game_GetTimeByMode` | 13 | Maps mode/type to time constants. |
| `0x4ed5a0` | `Map_ComputeBlitRect` | 13 | Computes a clipped blit rectangle. |
| `0x4dde30` | `Game_GetActiveCompanyById` | 13 | Returns the nth active company record. |
| `0x541250` | `List_FreeAll` | 13 | Frees all nodes in a linked list. |
| `0x539840` | `Color_RGBTo16FromDword` | 13 | Packs dword RGB into RGB555/565. |
| `0x521380` | `UI_RealizeSprite` | 13 | Realizes the sprite at +0x60 with color key -1. |
| `0x4d2ae0` | `Game_CountFreeBuildingsByType` | 26 | Counts non-menu map objects matching type. |
| `0x401790` | `IDMap_RemoveByKey` | 16 | Finds an ID-map key and removes its entry. |
| `0x4e1d40` | `Game_CountActiveObjectsByType` | 12 | Counts active map objects, optionally filtered by type. |
| `0x486e00` | `Window_UnlockState` | 12 | Clears state and leaves the window lock. |
| `0x503250` | `UI_AppendCommandIfActive` | 12 | Appends a command when the object is active and selected. |
| `0x4ed330` | `Map_SetTileFieldWithDefault` | 12 | Sets a tile field, defaulting from the object table. |
| `0x478090` | `Stats_SumFilteredFloats2` | 11 | Sums a second filtered float record set. |
| `0x4d2360` | `Game_GetObjectBottom` | 11 | Returns object y + height/2 + height. |
| `0x531620` | `Array_ToggleObjectActive` | 11 | Toggles object active state via init/clear helpers. |
| `0x4d2320` | `Game_GetObjectCenterY` | 11 | Returns object y + height/2. |
| `0x4f3ad0` | `Array_GetRandomRecord28` | 11 | Returns a random stride-0x28 record. |
| `0x5104d0` | `Game_MapInputIndex` | 11 | Maps input index 8 to 5 and dispatches. |
| `0x539280` | `Surface_Configure` | 10 | Initializes surface dimensions, pitch and bounds. |
| `0x505e60` | `UI_SetChildTracking` | 10 | Attaches a tracking object and updates child coordinates. |
| `0x5277d0` | `UI_DecrementRowCounter` | 10 | Decrements a row counter in the UI object table. |
| `0x5508c9` | `CS_LeaveObject` | 10 | Leaves an object lock or CRT lock-table slot. |
| `0x521ae0` | `UI_GetChildSize` | 10 | Returns size of child sprite at +0x60. |
| `0x4f50d0` | `AI_ComputePath` | 9 | Computes an AI movement path across the grid. |
| `0x48a130` | `Game_CountFilteredObjects` | 9 | Counts map objects matching type/state filters. |
| `0x4f3e10` | `Grid_GetNeighborCell` | 9 | Returns neighboring grid cell for a direction. |
| `0x5086e0` | `UI_ShiftChildRect` | 9 | Offsets child rectangle and updates blit list. |
| `0x4f0850` | `Object_GetBufferPair` | 9 | Returns one of two buffer pointer pairs. |
| `0x5313d0` | `Array_GetRecordByKey` | 9 | Binary-searches a key and returns record pointer. |
| `0x403020` | `IDMap_GetRandomName` | 8 | Picks a random string from a name table. |
| `0x50fec0` | `PlayerStats_Reset` | 8 | Clears 7-field and 86-field player stat blocks. |
| `0x50b6d0` | `Object_GetPlayerValue` | 8 | Returns player field selected by object state. |
| `0x4e09e0` | `Stats_SumFilteredFloats3` | 8 | Sums a third filtered float record set. |
| `0x47cc10` | `Game_CountPlayersByByte` | 8 | Counts player records whose byte value matches. |
| `0x5101d0` | `AI_CountPlanSteps` | 7 | Counts steps/phases in an AI plan. |
| `0x548e00` | `Sound_PlaySpeechStatement` | 7 | Formats and plays Speech_Statements_%02d.wav. |
| `0x52ff20` | `Array_GetRecordByKeyPtr` | 19 | Wrapper returning the record pointer for a key. |
| `0x540f60` | `List_DestroyObjects` | 7 | Calls each node cleanup/destructor and unlinks it. |
| `0x4e4490` | `Game_GetAdjustedValue` | 7 | Adjusts a value by current player/company state. |
| `0x4fcc30` | `Object_AdjustShortPercent` | 7 | Adds delta to per-index short, clamped 0..100. |
| `0x5340d0` | `Record_GetScreenRect48` | 7 | Reads bounds arrays into screen coordinates. |
| `0x486910` | `Game_CountObjectsByState` | 7 | Counts map objects filtered by +0x30 state. |
| `0x4d8090` | `Game_GetMostAdvancedCompany` | 7 | Finds maximum in the 0xdac company array. |
| `0x4e2330` | `Game_FindRecordByField34` | 7 | Searches map records for field +0x34. |
| `0x4d7e90` | `Array_FindIndexByPtr` | 7 | Finds pointer in map, returns index. |
| `0x4dde70` | `Game_FindCompanyIndex` | 7 | Finds company pointer in map, returns index. |
| `0x500e80` | `Game_GetPlayerSubrecord` | 7 | Looks up player subrecord with optional validity check. |
| `0x521bc0` | `UI_CreateWindowFromRect` | 6 | Creates a UI window/object from rectangle coordinates. |
| `0x5408b0` | `SoundBuffer_Destruct` | 7 | Sound buffer destructor: cleans child list and frees buffers. |
| `0x4e4060` | `Game_ComputePrice` | 6 | Computes a price/value from player and market state. |
| `0x547340` | `Sound_PlayChannel` | 6 | Plays/starts a sound on channel 1 or 2. |
| `0x4e1e40` | `Game_FindFreeStaffRecord` | 6 | Finds a free staff record matching filters. |
| `0x4d6390` | `Stats_GetCombinedValue` | 6 | Combines two statistic values via a switch. |
| `0x4d8780` | `Game_CountRecordsByOwner` | 6 | Counts records by owner/type fields. |
| `0x48a200` | `Game_CountFreeSlots` | 6 | Counts unowned/unassigned map objects. |
| `0x531570` | `Array_GetRectByKey` | 6 | Returns width/height from a record found by key. |
| `0x509240` | `UI_SetChildHeightFromValue` | 6 | Maps a value to child height, clamped 0x88..0x99. |
| `0x509bf0` | `UI_RemoveLastChild` | 6 | Removes the last child element. |
| `0x535e10` | `Palette_Free` | 6 | Frees a palette buffer. |
| `0x4eacb0` | `Game_RemoveIDMapEntry` | 6 | Removes an entry from the game ID map. |
| `0x5338c0` | `RecordList_FindFreeSlot` | 5 | Finds/allocates a free slot in a stride-0x48 record list. |
| `0x4f9a20` | `AI_SelectBestPlan` | 5 | Evaluates candidate AI plans and selects the best. |
| `0x4015b0` | `IDMap_InsertGrow` | 5 | Grows ID-map arrays and inserts a new entry. |
| `0x522f40` | `Array_InsertGrow` | 5 | Grows a pointer array and inserts an element. |
| `0x525bc0` | `UI_QueueCommand` | 5 | Pushes a command into the 1024-entry UI ring buffer. |
| `0x4db030` | `Game_ComputeCompanyValue` | 5 | Sums six company counters and a base value. |
| `0x54b3d0` | `Array_Grow` | 5 | Reallocates and copies a growable array. |
| `0x4f7b90` | `AI_ComputePlanScores` | 5 | Computes candidate plan scores from player stats. |
| `0x48a090` | `Game_CountFilteredObjects2` | 5 | Counts map objects matching owner/state/type filters. |
| `0x480060` | `Game_UpdateFreeBuildingCount` | 6 | Updates free-building count for type 0x17. |

## Why this order

Bottom-up naming lets each new function be understood from already-named dependencies. Depth-1 covers list/record accessors, object state updates, UI geometry and game-state counters. Once these are named, depth-2 functions become tractable.

## Next candidates

| Address | In-degree | Bytes |
|---|---:|---:|
| `0x480060` | 6 | 1574 |
| `0x5338c0` | 5 | 4613 |
| `0x4f9a20` | 5 | 3900 |
| `0x4015b0` | 5 | 3752 |
| `0x522f40` | 5 | 2836 |
| `0x525bc0` | 5 | 2824 |
| `0x4db030` | 5 | 2809 |
| `0x54b3d0` | 5 | 2483 |
| `0x4f7b90` | 5 | 2482 |
| `0x48a090` | 5 | 2303 |

## Status

- REA annotations applied in batches with evidence-budget resets.
- Durable names: `func_symbols.csv`.
- Verification export for leaves: `leaf_verification/`.
- Next: continue the depth-1 list, then move to depth 2.
