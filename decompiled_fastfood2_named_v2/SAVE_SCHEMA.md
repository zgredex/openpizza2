# Pizza Connection 2 save-state schema

Recovered from the named pseudocode export. The **writer is authoritative**: every `CRT_Ostream_Write` contributes an ordered field record. Loaders were matched independently by exact field-sequence comparison.

- Save/serializer functions: **38**
- Functions with direct field blocks: **19**
- Serialized fields: **368**
- Global blocks: **24**
- Fixed-size loop blocks: **2**
- Fixed serialized bytes (fields + globals + loops): **141342**
- Exact Save↔Load field-sequence pairs: **31**

This covers the payload that follows the 0xF0-byte `.piz` header. Strings, counted lists and nested objects add more bytes not included in the direct-field totals.

**Size accounting:** 141,342 fixed payload bytes + 240-byte header + 32-byte directory = **141,614 bytes** before variable-length lists and sub-records. The 125,000-byte tile-name table alone dominates the fixed payload.

## 0xF0..0x110 section directory

The 0x20 bytes at file offset 0xF0 are **not a reserved zero block**. `SaveGame_Serialize` builds eight dwords, seeks back to the start of the payload, writes the directory, then seeks to the end.

| Index | Meaning | Evidence |
|---:|---|---|
| 0 | `after_mapobject_list` | local_20[0], line 112 |
| 1 | `after_isomap_list` | local_20[1], line 88 |
| 2 | `after_character_list` | local_20[2], line 100 |
| 3 | `after_player_slots` | local_20[3], line 152 |
| 4 | `after_car_list` | local_10, line 136 |
| 5 | `after_company_slots` | local_c, line 168 |
| 6 | `after_person_list` | local_8, line 124 |
| 7 | `end_of_payload` | local_4, line 184; also the load-progress denominator |

`Game_LoadSaveGame` reads these 0x20 bytes first and validates section boundaries against them (`Stream_GetReadPosition` compares before each next counted list). Index 4 is unused by the writer.

## Top-level payload order

Offsets are computed exactly through `ui_briefing_list` at **0x7DB**. That list is variable-length, so later sections are data-dependent and their absolute offsets are left blank.
| Section | Offset | Size | Kind | Writer | Notes |
|---|---:|---:|---|---|---|
| `header` | 0x0 | 0xf0 | fixed | `SaveGame_Write` | title/company/city/slots/time/version/magic |
| `directory` | 0xf0 | 0x20 | fixed | `SaveGame_Serialize` | 8-dword section directory, written last |
| `start_marker` | 0x110 | 0x4 | const | `SaveGame_Serialize` | 0x2E |
| `global_game_block` | 0x114 | 0x5b8 | fixed | `SaveGame_Serialize` | DAT_0057bb20 |
| `game_fields_a` | 0x6cc | 0x20 | fixed | `SaveGame_Serialize` | game+0x298..0x2B7 |
| `game_fields_b` | 0x6ec | 0x20 | fixed | `SaveGame_Serialize` | game+0x2B8..0x2D7 |
| `game_scalars` | 0x70c | 0x50 | fixed | `SaveGame_Serialize` | 20 u32 fields game+0x2D8..0x368 and +0x2D90 |
| `ingredient_panel` | 0x75c | 0x4 | nested | `IngredientPanel_Save` |  |
| `city_company_list` | 0x760 | 0x8 | nested | `CityCompanyList_Save` |  |
| `advertising_panel` | 0x768 | 0x8 | nested | `AdvertisingPanel_Save` |  |
| `company_market_share` | 0x770 | 0x5 | nested | `CompanyMarketShare_Save` |  |
| `company_overview` | 0x775 | 0x11 | nested | `CompanyOverview_Save` |  |
| `statistics_balance` | 0x786 | 0x10 | nested | `StatisticsBalance_Save` |  |
| `statistics_branch_balance` | 0x796 | 0xc | nested | `StatisticsBranchBalance_Save` |  |
| `personnel` | 0x7a2 | 0x4 | nested | `Personnel_Save` |  |
| `branch_stats_series_flags` | 0x7a6 | 0x10 | nested | `BranchStats_SeriesFlags_Save` |  |
| `branch_design_color_index` | 0x7b6 | 0x4 | nested | `BranchDesign_ColorIndex_Save` |  |
| `branch_menu_category` | 0x7ba | 0x4 | nested | `BranchMenu_Category_Save` |  |
| `warehouse_product` | 0x7be | 0x4 | nested | `WarehouseProduct_Save` |  |
| `game_calendar` | 0x7c2 | 0x19 | nested | `GameCalendar_Save` |  |
| `ui_briefing_list` | 0x7db |  | nested | `UI_BriefingList_Save` |  |
| `world_tile_name_table` |  | 0x1e848 | fixed | `Game_SaveTileNameTable` | 2500 x 50-byte tile-name records |
| `isomap_list` |  |  | counted | `SaveGame_Serialize` | u32 count; each: u32 id + IsoMap_Save |
| `character_list` |  |  | counted | `SaveGame_Serialize` | u32 count; each: u32 id + Character_Save |
| `city_mapobject_list` |  |  | counted | `SaveGame_Serialize` | u32 count; each: City/MapObjectList_Save |
| `person_list` |  |  | counted | `SaveGame_Serialize` | u32 count; each: u32 id + PersonList_Save |
| `car_list` |  |  | counted | `SaveGame_Serialize` | u32 count; each: u32 id + CarList_Save |
| `player_slots` |  |  | array6 | `SaveGame_Serialize` | 6 x (u32 present + Player_Save) |
| `company_slots` |  |  | array6 | `SaveGame_Serialize` | 6 x (u32 present + CompanyData_Save) |
| `ai_company_slots` |  | 0x870 | nested | `AI_CompanySlots_Save` |  |
| `selected_player_company` |  | 0xc | fixed | `SaveGame_Serialize` | present, player slot, company id |
| `runtime_list` |  |  | nested | `SaveGame_SerializeRuntimeList` |  |
| `end_marker` |  | 0x4 | const | `SaveGame_Serialize` | 0x2A |
| `directory_rewrite` |  | 0x20 | seek+write | `SaveGame_Serialize` | seek to 0x00F0, write 8-dword directory |

## Serializer blocks

| Writer | Address | Fields | Globals | Bytes | Loader | Pair status |
|---|---|---:|---:|---:|---|---|
| `Game_SaveTileNameTable` | `0x4eaaa0` | 0 | 0 | 125000 | `World_LoadNameIndexTable` | exact |
| `Branch_Save` | `0x47b9e0` | 75 | 0 | 6412 | `Branch_Load` | exact |
| `AI_CompanySlots_Save` | `0x4f6e20` | 0 | 0 | 2160 | `AI_CompanySlots_Load` | exact |
| `Character_Save` | `0x4d3ba0` | 23 | 0 | 2082 | `Character_Load` | exact |
| `SaveGame_Serialize` | `0x487b50` | 22 | 1 | 1608 | `Game_LoadSaveGame` | exact |
| `MapObjectList_Save` | `0x4d7090` | 31 | 0 | 1312 | `MapObjectList_Load` | different-load-path |
| `StatsPeriodReport_Save` | `0x401200` | 6 | 0 | 856 | `StatsPeriodReport_Load` | exact |
| `Player_AIState_Save` | `0x501cb0` | 16 | 0 | 554 | `Player_AIState_Load` | exact |
| `CompanyData_Save` | `0x4e1540` | 27 | 0 | 270 | `Company_Load` | exact |
| `PersonList_Save` | `0x5053d0` | 38 | 0 | 229 | `PersonAction_LoadState` | different-load-path |
| `IsoMap_Save` | `0x4ec4f0` | 49 | 0 | 220 | `IsoMap_Load` | different-load-path |
| `Player_MissionState_Save` | `0x4f5ee0` | 8 | 0 | 208 | `Player_MissionState_Load` | exact |
| `Player_Save` | `0x50ea90` | 21 | 0 | 132 | `Player_Load` | exact |
| `MapObject_Save` | `0x4d1fe0` | 17 | 0 | 84 | `MapObject_Load` | different-load-path |
| `ConstructionOrder_Save` | `0x4e5e30` | 8 | 0 | 32 | `ConstructionOrder_Load` | different-load-path |
| `GameCalendar_Save` | `0x4dd4f0` | 10 | 1 | 25 | `GameCalendar_Load` | exact |
| `BuildingValue_Save` | `0x4e43f0` | 5 | 0 | 21 | `BuildingValue_Load` | exact |
| `RecipeTopping_Save` | `0x4d1ba0` | 8 | 0 | 21 | `RecipeTopping_Load` | exact |
| `CompanyOverview_Save` | `0x4b3ce0` | 0 | 3 | 17 | `CompanyOverview_Load` | exact |
| `BranchStats_SeriesFlags_Save` | `0x4919d0` | 0 | 1 | 16 | `BranchStats_SeriesFlags_Load` | exact |
| `StatisticsBalance_Save` | `0x4aa700` | 0 | 4 | 16 | `StatisticsBalance_Load` | exact |
| `StatisticsBranchBalance_Save` | `0x4ac400` | 0 | 3 | 12 | `StatisticsBranchBalance_Load` | exact |
| `AdvertisingPanel_Save` | `0x49ad00` | 0 | 2 | 8 | `AdvertisingPanel_Load` | exact |
| `CityCompanyList_Save` | `0x498130` | 0 | 2 | 8 | `CityCompanyList_Load` | exact |
| `Player_Event_Save` | `0x501a40` | 2 | 0 | 6 | `Player_Event_Load` | exact |
| `CompanyMarketShare_Save` | `0x49b490` | 0 | 2 | 5 | `CompanyMarketShare_Load` | exact |
| `BranchDesign_ColorIndex_Save` | `0x492250` | 0 | 1 | 4 | `BranchDesign_ColorIndex_Load` | exact |
| `BranchMenu_Category_Save` | `0x4900c0` | 0 | 1 | 4 | `BranchMenu_Category_Load` | exact |
| `CarList_Save` | `0x4d3490` | 1 | 0 | 4 | `Car_LoadFromStream` | exact |
| `IngredientPanel_Save` | `0x499590` | 0 | 1 | 4 | `IngredientPanel_Load` | exact |
| `MapSprite_Save` | `0x4ecb30` | 1 | 0 | 4 | `MapActor_ReadFromStream` | different-load-path |
| `Personnel_Save` | `0x4b0d60` | 0 | 1 | 4 | `Personnel_Load` | exact |
| `WarehouseProduct_Save` | `0x4c0d60` | 0 | 1 | 4 | `WarehouseProduct_Load` | exact |
| `Car_Save` | `0x4d3450` | 0 | 0 | 0 | `Car_LoadSpriteRecord` | exact |
| `Person_Save` | `0x5052e0` | 0 | 0 | 0 | `MapObject_ReadRenderRecord` | exact |
| `Sprite_Serialize` | `0x53d160` | 0 | 0 | 0 | `` | save-only |
| `UI_BriefingList_Save` | `0x54b1b0` | 0 | 0 | 0 | `UI_BriefingList_Load` | exact |
| `SaveGame_SerializeRuntimeList` | `0x487940` | 0 | 0 | 0 | `SaveGame_DeserializeRuntimeList` | exact |

## Serialized global state

These globals are written directly by subsystem serializers and are part of the save payload even though they are not object fields.

| Address | Size | Suggested name | Writer |
|---|---:|---|---|
| `0x00568628` | 16 | `g_BranchStatsSeriesFlags` | BranchStats_SeriesFlags_Save |
| `0x00568910` | 4 | `g_IngredientPanelState` | IngredientPanel_Save |
| `0x005689f0` | 1 | `g_CompanyMarketShareFlag` | CompanyMarketShare_Save |
| `0x00569354` | 4 | `g_StatisticsBalanceA` | StatisticsBalance_Save |
| `0x00569358` | 4 | `g_StatisticsBalanceB` | StatisticsBalance_Save |
| `0x0056951c` | 4 | `g_StatisticsBranchBalance` | StatisticsBranchBalance_Save |
| `0x0056a6d8` | 4 | `g_PersonnelState` | Personnel_Save |
| `0x0056a734` | 9 | `g_CompanyOverviewText` | CompanyOverview_Save |
| `0x0056a7d4` | 4 | `g_CompanyOverviewState` | CompanyOverview_Save |
| `0x0057bb20` | 1464 | `g_GameGlobalState` | SaveGame_Serialize |
| `0x0057c6a8` | 4 | `g_BranchMenuCategory` | BranchMenu_Category_Save |
| `0x0057c6bc` | 4 | `g_BranchDesignColorIndex` | BranchDesign_ColorIndex_Save |
| `0x0057c9fc` | 4 | `g_CityCompanyListA` | CityCompanyList_Save |
| `0x0057ca00` | 4 | `g_CityCompanyListB` | CityCompanyList_Save |
| `0x0057ca30` | 4 | `g_AdvertisingPanelA` | AdvertisingPanel_Save |
| `0x0057ca34` | 4 | `g_AdvertisingPanelB` | AdvertisingPanel_Save |
| `0x0057ca90` | 4 | `g_CompanyMarketShare` | CompanyMarketShare_Save |
| `0x0057d5c8` | 4 | `g_StatisticsBalanceC` | StatisticsBalance_Save |
| `0x0057d5d0` | 4 | `g_StatisticsBalanceD` | StatisticsBalance_Save |
| `0x0057d62c` | 4 | `g_StatisticsBranchBalanceA` | StatisticsBranchBalance_Save |
| `0x0057d630` | 4 | `g_StatisticsBranchBalanceB` | StatisticsBranchBalance_Save |
| `0x0057d69c` | 4 | `g_CompanyOverviewB` | CompanyOverview_Save |
| `0x0057d714` | 4 | `g_WarehouseProductState` | WarehouseProduct_Save |
| `0x0057dfbc` | 4 | `g_GameCalendarState` | GameCalendar_Save |

## Per-writer field layouts

### AI_CompanySlots_Save

- Address: `0x4f6e20`
- Fields: 0
- Direct bytes: 2160
- Loader: `AI_CompanySlots_Load` (exact)

| Count | Record size | Bytes | Note |
|---:|---:|---:|---|
| 6 | 0x168 | 2160 | 6 x 0x168-byte company AI records |

| # | Offset | Size | Type hint |
|---:|---:|---:|---|

### AdvertisingPanel_Save

- Address: `0x49ad00`
- Fields: 0
- Direct bytes: 8
- Loader: `AdvertisingPanel_Load` (exact)

| Global address | Size | Type hint |
|---|---:|---|
| `0x57ca30` | 4 | u32/i32/float |
| `0x57ca34` | 4 | u32/i32/float |

| # | Offset | Size | Type hint |
|---:|---:|---:|---|

### BranchDesign_ColorIndex_Save

- Address: `0x492250`
- Fields: 0
- Direct bytes: 4
- Loader: `BranchDesign_ColorIndex_Load` (exact)

| Global address | Size | Type hint |
|---|---:|---|
| `0x57c6bc` | 4 | u32/i32/float |

| # | Offset | Size | Type hint |
|---:|---:|---:|---|

### BranchMenu_Category_Save

- Address: `0x4900c0`
- Fields: 0
- Direct bytes: 4
- Loader: `BranchMenu_Category_Load` (exact)

| Global address | Size | Type hint |
|---|---:|---|
| `0x57c6a8` | 4 | u32/i32/float |

| # | Offset | Size | Type hint |
|---:|---:|---:|---|

### BranchStats_SeriesFlags_Save

- Address: `0x4919d0`
- Fields: 0
- Direct bytes: 16
- Loader: `BranchStats_SeriesFlags_Load` (exact)

| Global address | Size | Type hint |
|---|---:|---|
| `0x568628` | 16 | bytes[16] |

| # | Offset | Size | Type hint |
|---:|---:|---:|---|

### Branch_Save

- Address: `0x47b9e0`
- Fields: 75
- Direct bytes: 6412
- Loader: `Branch_Load` (exact)

- Nested serializers: `StatsPeriodReport_Save`, `ConstructionOrder_Save`

| # | Offset | Size | Type hint |
|---:|---:|---:|---|
| 0 | `0x4` | 32 | bytes[32] |
| 1 | `0x2c` | 4 | u32/i32/float |
| 2 | `0x24` | 4 | u32/i32/float |
| 3 | `0x28` | 4 | u32/i32/float |
| 4 | `0x30` | 4 | u32/i32/float |
| 5 | `0x34` | 4 | u32/i32/float |
| 6 | `0x3c` | 4 | u32/i32/float |
| 7 | `0x40` | 4 | u32/i32/float |
| 8 | `0x44` | 324 | bytes[324] |
| 9 | `0x188` | 324 | bytes[324] |
| 10 | `0x554` | 3600 | bytes[3600] |
| 11 | `0x1364` | 36 | bytes[36] |
| 12 | `0x2cc` | 324 | bytes[324] |
| 13 | `0x410` | 324 | bytes[324] |
| 14 | `0x1388` | 72 | bytes[72] |
| 15 | `0x13d0` | 72 | bytes[72] |
| 16 | `0x1418` | 72 | bytes[72] |
| 17 | `0x1460` | 72 | bytes[72] |
| 18 | `0x14a8` | 4 | u32/i32/float |
| 19 | `0x14ac` | 4 | u32/i32/float |
| 20 | `0x14c8` | 4 | u32/i32/float |
| 21 | `0x14cc` | 4 | u32/i32/float |
| 22 | `0x14d0` | 4 | u32/i32/float |
| 23 | `0x14d4` | 4 | u32/i32/float |
| 24 | `0x14c0` | 4 | u32/i32/float |
| 25 | `0x14d8` | 4 | u32/i32/float |
| 26 | `0x16f5` | 1 | u8/bool |
| 27 | `0x16f4` | 1 | u8/bool |
| 28 | `0x14b0` | 4 | u32/i32/float |
| 29 | `0x1714` | 4 | u32/i32/float |
| 30 | `0x1718` | 4 | u32/i32/float |
| 31 | `0x171c` | 4 | u32/i32/float |
| 32 | `0x1720` | 4 | u32/i32/float |
| 33 | `0x1724` | 4 | u32/i32/float |
| 34 | `0x151c` | 416 | bytes[416] |
| 35 | `0x16bc` | 52 | bytes[52] |
| 36 | `0x177c` | 32 | bytes[32] |
| 37 | `0x179c` | 32 | bytes[32] |
| 38 | `0x17bc` | 32 | bytes[32] |
| 39 | `0x17dc` | 32 | bytes[32] |
| 40 | `0x17fc` | 32 | bytes[32] |
| 41 | `0x181c` | 32 | bytes[32] |
| 42 | `0x183c` | 20 | bytes[20] |
| 43 | `0x1850` | 4 | u32/i32/float |
| 44 | `0x1854` | 4 | u32/i32/float |
| 45 | `0x1858` | 4 | u32/i32/float |
| 46 | `0x185c` | 4 | u32/i32/float |
| 47 | `0x1860` | 4 | u32/i32/float |
| 48 | `0x1864` | 4 | u32/i32/float |
| 49 | `0x1868` | 4 | u32/i32/float |
| 50 | `0x186c` | 4 | u32/i32/float |
| 51 | `0x1870` | 4 | u32/i32/float |
| 52 | `0x1874` | 4 | u32/i32/float |
| 53 | `0x1878` | 4 | u32/i32/float |
| 54 | `0x38` | 4 | u32/i32/float |
| 55 | `0x1898` | 64 | bytes[64] |
| 56 | `0x18d8` | 192 | bytes[192] |
| 57 | `0x187c` | 4 | u32/i32/float |
| 58 | `0x19fc` | 4 | u32/i32/float |
| 59 | `0x1a00` | 4 | u32/i32/float |
| 60 | `0x1a04` | 4 | u32/i32/float |
| 61 | `0x1880` | 4 | u32/i32/float |
| 62 | `0x19b4` | 16 | bytes[16] |
| 63 | `0x14b4` | 4 | u32/i32/float |
| 64 | `0x1a20` | 1 | u8/bool |
| 65 | `0x1a21` | 1 | u8/bool |
| 66 | `0x1884` | 16 | bytes[16] |
| 67 | `0x1a2c` | 4 | u32/i32/float |
| 68 | `0x1a30` | 4 | u32/i32/float |
| 69 | `0x1a34` | 4 | u32/i32/float |
| 70 | `0x1a38` | 4 | u32/i32/float |
| 71 | `0x1a24` | 4 | u32/i32/float |
| 72 | `0x14b8` | 4 | u32/i32/float |
| 73 | `0x14bc` | 4 | u32/i32/float |
| 74 | `0x1894` | 4 | u32/i32/float |

### BuildingValue_Save

- Address: `0x4e43f0`
- Fields: 5
- Direct bytes: 21
- Loader: `BuildingValue_Load` (exact)

| # | Offset | Size | Type hint |
|---:|---:|---:|---|
| 0 | `0xc` | 4 | u32/i32/float |
| 1 | `0x8` | 4 | u32/i32/float |
| 2 | `0x10` | 8 | u64/double |
| 3 | `0x18` | 4 | u32/i32/float |
| 4 | `0x1c` | 1 | u8/bool |

### CarList_Save

- Address: `0x4d3490`
- Fields: 1
- Direct bytes: 4
- Loader: `Car_LoadFromStream` (exact)

- Nested serializers: `Car_Save`

| # | Offset | Size | Type hint |
|---:|---:|---:|---|
| 0 | `0xc` | 4 | u32/i32/float |

### Character_Save

- Address: `0x4d3ba0`
- Fields: 23
- Direct bytes: 2082
- Loader: `Character_Load` (exact)

| # | Offset | Size | Type hint |
|---:|---:|---:|---|
| 0 | `0x4` | 4 | u32/i32/float |
| 1 | `0x8` | 4 | u32/i32/float |
| 2 | `0xc` | 4 | u32/i32/float |
| 3 | `0x10` | 4 | u32/i32/float |
| 4 | `0x24` | 4 | u32/i32/float |
| 5 | `0x28` | 4 | u32/i32/float |
| 6 | `0x2c` | 4 | u32/i32/float |
| 7 | `0x30` | 4 | u32/i32/float |
| 8 | `0x34` | 4 | u32/i32/float |
| 9 | `0x38` | 4 | u32/i32/float |
| 10 | `0x3c` | 4 | u32/i32/float |
| 11 | `0x44` | 2000 | bytes[2000] |
| 12 | `0x814` | 4 | u32/i32/float |
| 13 | `0x818` | 4 | u32/i32/float |
| 14 | `0x81c` | 4 | u32/i32/float |
| 15 | `0x820` | 4 | u32/i32/float |
| 16 | `0x824` | 1 | u8/bool |
| 17 | `0x40` | 4 | u32/i32/float |
| 18 | `0x825` | 1 | u8/bool |
| 19 | `0x14` | 4 | u32/i32/float |
| 20 | `0x18` | 4 | u32/i32/float |
| 21 | `0x1c` | 4 | u32/i32/float |
| 22 | `0x20` | 4 | u32/i32/float |

### CityCompanyList_Save

- Address: `0x498130`
- Fields: 0
- Direct bytes: 8
- Loader: `CityCompanyList_Load` (exact)

| Global address | Size | Type hint |
|---|---:|---|
| `0x57c9fc` | 4 | u32/i32/float |
| `0x57ca00` | 4 | u32/i32/float |

| # | Offset | Size | Type hint |
|---:|---:|---:|---|

### CompanyData_Save

- Address: `0x4e1540`
- Fields: 27
- Direct bytes: 270
- Loader: `Company_Load` (exact)

- Nested serializers: `Branch_Save`, `StatsPeriodReport_Save`

| # | Offset | Size | Type hint |
|---:|---:|---:|---|
| 0 | `0x8` | 64 | bytes[64] |
| 1 | `0x48` | 4 | u32/i32/float |
| 2 | `0x4c` | 4 | u32/i32/float |
| 3 | `0x5c` | 2 | u16 |
| 4 | `0x50` | 4 | u32/i32/float |
| 5 | `0x54` | 4 | u32/i32/float |
| 6 | `0x1dc` | 4 | u32/i32/float |
| 7 | `0x108` | 8 | u64/double |
| 8 | `0x1e4` | 4 | u32/i32/float |
| 9 | `0x1e0` | 4 | u32/i32/float |
| 10 | `0x64` | 4 | u32/i32/float |
| 11 | `0x68` | 4 | u32/i32/float |
| 12 | `0x6c` | 4 | u32/i32/float |
| 13 | `0x70` | 36 | bytes[36] |
| 14 | `0x94` | 24 | bytes[24] |
| 15 | `0xac` | 6 | bytes[6] |
| 16 | `0xcc` | 24 | bytes[24] |
| 17 | `0xb4` | 24 | bytes[24] |
| 18 | `0xf0` | 4 | u32/i32/float |
| 19 | `0xf4` | 4 | u32/i32/float |
| 20 | `0xf8` | 4 | u32/i32/float |
| 21 | `0xe4` | 10 | bytes[10] |
| 22 | `0x60` | 4 | u32/i32/float |
| 23 | `0x58` | 4 | u32/i32/float |
| 24 | `0x1e8` | 4 | u32/i32/float |
| 25 | `0xfc` | 4 | u32/i32/float |
| 26 | `0x100` | 4 | u32/i32/float |

### CompanyMarketShare_Save

- Address: `0x49b490`
- Fields: 0
- Direct bytes: 5
- Loader: `CompanyMarketShare_Load` (exact)

| Global address | Size | Type hint |
|---|---:|---|
| `0x57ca90` | 4 | u32/i32/float |
| `0x5689f0` | 1 | u8/bool |

| # | Offset | Size | Type hint |
|---:|---:|---:|---|

### CompanyOverview_Save

- Address: `0x4b3ce0`
- Fields: 0
- Direct bytes: 17
- Loader: `CompanyOverview_Load` (exact)

| Global address | Size | Type hint |
|---|---:|---|
| `0x56a7d4` | 4 | u32/i32/float |
| `0x57d69c` | 4 | u32/i32/float |
| `0x56a734` | 9 | bytes[9] |

| # | Offset | Size | Type hint |
|---:|---:|---:|---|

### ConstructionOrder_Save

- Address: `0x4e5e30`
- Fields: 8
- Direct bytes: 32
- Loader: `ConstructionOrder_Load` (different-load-path)

| # | Offset | Size | Type hint |
|---:|---:|---:|---|
| 0 | `0x4` | 4 | u32/i32/float |
| 1 | `0x8` | 4 | u32/i32/float |
| 2 | `0xc` | 4 | u32/i32/float |
| 3 | `0x10` | 4 | u32/i32/float |
| 4 | `0x14` | 4 | u32/i32/float |
| 5 | `0x18` | 4 | u32/i32/float |
| 6 | `0x1c` | 4 | u32/i32/float |
| 7 | `0x20` | 4 | u32/i32/float |

### GameCalendar_Save

- Address: `0x4dd4f0`
- Fields: 10
- Direct bytes: 25
- Loader: `GameCalendar_Load` (exact)

| Global address | Size | Type hint |
|---|---:|---|
| `0x57dfbc` | 4 | u32/i32/float |

| # | Offset | Size | Type hint |
|---:|---:|---:|---|
| 0 | `0x7` | 1 | u8/bool |
| 1 | `0x6` | 1 | u8/bool |
| 2 | `0x8` | 1 | u8/bool |
| 3 | `0x4` | 2 | u16 |
| 4 | `0xa` | 2 | u16 |
| 5 | `0xc` | 4 | u32/i32/float |
| 6 | `0x19` | 1 | u8/bool |
| 7 | `0x18` | 1 | u8/bool |
| 8 | `0x14` | 4 | u32/i32/float |
| 9 | `0x10` | 4 | u32/i32/float |

### Game_SaveTileNameTable

- Address: `0x4eaaa0`
- Fields: 0
- Direct bytes: 125000
- Loader: `World_LoadNameIndexTable` (exact)

| Count | Record size | Bytes | Note |
|---:|---:|---:|---|
| 2500 | 0x32 | 125000 | 2500 x 50-byte tile-name records |

| # | Offset | Size | Type hint |
|---:|---:|---:|---|

### IngredientPanel_Save

- Address: `0x499590`
- Fields: 0
- Direct bytes: 4
- Loader: `IngredientPanel_Load` (exact)

| Global address | Size | Type hint |
|---|---:|---|
| `0x568910` | 4 | u32/i32/float |

| # | Offset | Size | Type hint |
|---:|---:|---:|---|

### IsoMap_Save

- Address: `0x4ec4f0`
- Fields: 49
- Direct bytes: 220
- Loader: `IsoMap_Load` (different-load-path)

| # | Offset | Size | Type hint |
|---:|---:|---:|---|
| 0 | `0xc` | 4 | u32/i32/float |
| 1 | `0x10` | 4 | u32/i32/float |
| 2 | `0x14` | 4 | u32/i32/float |
| 3 | `0x18` | 4 | u32/i32/float |
| 4 | `0x1c` | 4 | u32/i32/float |
| 5 | `0x20` | 4 | u32/i32/float |
| 6 | `0x24` | 4 | u32/i32/float |
| 7 | `0x28` | 4 | u32/i32/float |
| 8 | `0x2c` | 4 | u32/i32/float |
| 9 | `0x30` | 4 | u32/i32/float |
| 10 | `0x34` | 4 | u32/i32/float |
| 11 | `0x38` | 4 | u32/i32/float |
| 12 | `0x3c` | 16 | bytes[16] |
| 13 | `0x60` | 4 | u32/i32/float |
| 14 | `0x6c` | 4 | u32/i32/float |
| 15 | `0x7c` | 30 | bytes[30] |
| 16 | `0xba` | 2 | u16 |
| 17 | `0xf0` | 4 | u32/i32/float |
| 18 | `0xa8` | 4 | u32/i32/float |
| 19 | `0x9c` | 1 | u8/bool |
| 20 | `0x9c` | 2 | u16 |
| 21 | `0x9c` | 1 | u8/bool |
| 22 | `0x9c` | 4 | u32/i32/float |
| 23 | `0x9c` | 4 | u32/i32/float |
| 24 | `0x9c` | 4 | u32/i32/float |
| 25 | `0x9c` | 16 | bytes[16] |
| 26 | `0x9c` | 1 | u8/bool |
| 27 | `0xa0` | 1 | u8/bool |
| 28 | `0xa0` | 2 | u16 |
| 29 | `0xa0` | 1 | u8/bool |
| 30 | `0xa0` | 4 | u32/i32/float |
| 31 | `0xa0` | 4 | u32/i32/float |
| 32 | `0xa0` | 4 | u32/i32/float |
| 33 | `0xa0` | 16 | bytes[16] |
| 34 | `0xa0` | 1 | u8/bool |
| 35 | `0x4c` | 4 | u32/i32/float |
| 36 | `0x4c` | 2 | u16 |
| 37 | `0x4c` | 4 | u32/i32/float |
| 38 | `0x4c` | 4 | u32/i32/float |
| 39 | `0x4c` | 4 | u32/i32/float |
| 40 | `0x4c` | 4 | u32/i32/float |
| 41 | `0x4c` | 4 | u32/i32/float |
| 42 | `0x4c` | 1 | u8/bool |
| 43 | `0x4c` | 1 | u8/bool |
| 44 | `0x4c` | 1 | u8/bool |
| 45 | `0x4c` | 1 | u8/bool |
| 46 | `0x4c` | 4 | u32/i32/float |
| 47 | `0x4c` | 4 | u32/i32/float |
| 48 | `0x118` | 4 | u32/i32/float |

### MapObjectList_Save

- Address: `0x4d7090`
- Fields: 31
- Direct bytes: 1312
- Loader: `MapObjectList_Load` (different-load-path)

- Nested serializers: `MapObject_Save`

| # | Offset | Size | Type hint |
|---:|---:|---:|---|
| 0 | `0xc1c` | 4 | u32/i32/float |
| 1 | `0x4` | 32 | bytes[32] |
| 2 | `0x44` | 4 | u32/i32/float |
| 3 | `0xc20` | 24 | bytes[24] |
| 4 | `0x4` | 24 | bytes[24] |
| 5 | `0xdc4` | 4 | u32/i32/float |
| 6 | `0xdc8` | 480 | bytes[480] |
| 7 | `0xc38` | 96 | bytes[96] |
| 8 | `0xc98` | 24 | bytes[24] |
| 9 | `0xcc8` | 24 | bytes[24] |
| 10 | `0xd40` | 24 | bytes[24] |
| 11 | `0xd58` | 48 | bytes[48] |
| 12 | `0xd88` | 36 | bytes[36] |
| 13 | `0xce0` | 96 | bytes[96] |
| 14 | `0xcb0` | 24 | bytes[24] |
| 15 | `0xfe4` | 192 | bytes[192] |
| 16 | `0x10ac` | 4 | u32/i32/float |
| 17 | `0x10b0` | 4 | u32/i32/float |
| 18 | `0x10b4` | 4 | u32/i32/float |
| 19 | `0x10b8` | 4 | u32/i32/float |
| 20 | `0x10c4` | 4 | u32/i32/float |
| 21 | `0x10d0` | 120 | bytes[120] |
| 22 | `0x10c0` | 4 | u32/i32/float |
| 23 | `0x10bc` | 4 | u32/i32/float |
| 24 | `0x10cc` | 4 | u32/i32/float |
| 25 | `0x10c8` | 4 | u32/i32/float |
| 26 | `0x1148` | 4 | u32/i32/float |
| 27 | `0x114c` | 4 | u32/i32/float |
| 28 | `0x1150` | 4 | u32/i32/float |
| 29 | `0x1154` | 4 | u32/i32/float |
| 30 | `0x10a4` | 4 | u32/i32/float |

### MapObject_Save

- Address: `0x4d1fe0`
- Fields: 17
- Direct bytes: 84
- Loader: `MapObject_Load` (different-load-path)

- Nested serializers: `BuildingValue_Save`

| # | Offset | Size | Type hint |
|---:|---:|---:|---|
| 0 | `0x4` | 4 | u32/i32/float |
| 1 | `0x8` | 4 | u32/i32/float |
| 2 | `0x4c` | 4 | u32/i32/float |
| 3 | `0x50` | 4 | u32/i32/float |
| 4 | `0x2c` | 4 | u32/i32/float |
| 5 | `0x30` | 4 | u32/i32/float |
| 6 | `0x34` | 4 | u32/i32/float |
| 7 | `0x38` | 4 | u32/i32/float |
| 8 | `0xc` | 4 | u32/i32/float |
| 9 | `0x3c` | 4 | u32/i32/float |
| 10 | `0x94` | 4 | u32/i32/float |
| 11 | `0x10` | 16 | bytes[16] |
| 12 | `0x20` | 4 | u32/i32/float |
| 13 | `0x24` | 4 | u32/i32/float |
| 14 | `0x40` | 8 | u64/double |
| 15 | `0x48` | 4 | u32/i32/float |
| 16 | `0x54` | 4 | u32/i32/float |

### MapSprite_Save

- Address: `0x4ecb30`
- Fields: 1
- Direct bytes: 4
- Loader: `MapActor_ReadFromStream` (different-load-path)

| # | Offset | Size | Type hint |
|---:|---:|---:|---|
| 0 | `0x1` | 4 | u32/i32/float |

### PersonList_Save

- Address: `0x5053d0`
- Fields: 38
- Direct bytes: 229
- Loader: `PersonAction_LoadState` (different-load-path)

- Nested serializers: `Person_Save`

| # | Offset | Size | Type hint |
|---:|---:|---:|---|
| 0 | `0x4` | 32 | bytes[32] |
| 1 | `0x24` | 4 | u32/i32/float |
| 2 | `0x28` | 4 | u32/i32/float |
| 3 | `0x30` | 4 | u32/i32/float |
| 4 | `0x34` | 4 | u32/i32/float |
| 5 | `0x38` | 4 | u32/i32/float |
| 6 | `0x3c` | 4 | u32/i32/float |
| 7 | `0x40` | 2 | u16 |
| 8 | `0x44` | 4 | u32/i32/float |
| 9 | `0x48` | 4 | u32/i32/float |
| 10 | `0x4c` | 4 | u32/i32/float |
| 11 | `0x50` | 4 | u32/i32/float |
| 12 | `0x54` | 4 | u32/i32/float |
| 13 | `0x58` | 4 | u32/i32/float |
| 14 | `0x5c` | 24 | bytes[24] |
| 15 | `0x74` | 4 | u32/i32/float |
| 16 | `0x78` | 4 | u32/i32/float |
| 17 | `0x7c` | 4 | u32/i32/float |
| 18 | `0x80` | 1 | u8/bool |
| 19 | `0x81` | 1 | u8/bool |
| 20 | `0x84` | 4 | u32/i32/float |
| 21 | `0x88` | 4 | u32/i32/float |
| 22 | `0x8c` | 4 | u32/i32/float |
| 23 | `0x90` | 4 | u32/i32/float |
| 24 | `0x10c` | 4 | u32/i32/float |
| 25 | `0x94` | 4 | u32/i32/float |
| 26 | `0x98` | 4 | u32/i32/float |
| 27 | `0x9c` | 4 | u32/i32/float |
| 28 | `0x14c` | 24 | bytes[24] |
| 29 | `0xa0` | 4 | u32/i32/float |
| 30 | `0xa4` | 4 | u32/i32/float |
| 31 | `0xa8` | 4 | u32/i32/float |
| 32 | `0x110` | 4 | u32/i32/float |
| 33 | `0x104` | 1 | u8/bool |
| 34 | `0x108` | 4 | u32/i32/float |
| 35 | `0xac` | 24 | bytes[24] |
| 36 | `0x2c` | 4 | u32/i32/float |
| 37 | `0x128` | 4 | u32/i32/float |

### Personnel_Save

- Address: `0x4b0d60`
- Fields: 0
- Direct bytes: 4
- Loader: `Personnel_Load` (exact)

| Global address | Size | Type hint |
|---|---:|---|
| `0x56a6d8` | 4 | u32/i32/float |

| # | Offset | Size | Type hint |
|---:|---:|---:|---|

### Player_AIState_Save

- Address: `0x501cb0`
- Fields: 16
- Direct bytes: 554
- Loader: `Player_AIState_Load` (exact)

| # | Offset | Size | Type hint |
|---:|---:|---:|---|
| 0 | `0x4` | 1 | u8/bool |
| 1 | `0xc` | 52 | bytes[52] |
| 2 | `0x44` | 4 | u32/i32/float |
| 3 | `0x40` | 4 | u32/i32/float |
| 4 | `0x48` | 4 | u32/i32/float |
| 5 | `0x4c` | 4 | u32/i32/float |
| 6 | `0x50` | 4 | u32/i32/float |
| 7 | `0x54` | 4 | u32/i32/float |
| 8 | `0x58` | 4 | u32/i32/float |
| 9 | `0x5c` | 4 | u32/i32/float |
| 10 | `0x60` | 1 | u8/bool |
| 11 | `0x64` | 4 | u32/i32/float |
| 12 | `0x84` | 4 | u32/i32/float |
| 13 | `0x8` | 4 | u32/i32/float |
| 14 | `0x88` | 228 | bytes[228] |
| 15 | `0x16c` | 228 | bytes[228] |

### Player_Event_Save

- Address: `0x501a40`
- Fields: 2
- Direct bytes: 6
- Loader: `Player_Event_Load` (exact)

| # | Offset | Size | Type hint |
|---:|---:|---:|---|
| 0 | `0x4` | 4 | u32/i32/float |
| 1 | `0x8` | 2 | u16 |

### Player_MissionState_Save

- Address: `0x4f5ee0`
- Fields: 8
- Direct bytes: 208
- Loader: `Player_MissionState_Load` (exact)

| # | Offset | Size | Type hint |
|---:|---:|---:|---|
| 0 | `0x4` | 12 | bytes[12] |
| 1 | `0x10` | 176 | bytes[176] |
| 2 | `0xc0` | 4 | u32/i32/float |
| 3 | `0xc4` | 3 | bytes[3] |
| 4 | `0xc8` | 4 | u32/i32/float |
| 5 | `0xcc` | 1 | u8/bool |
| 6 | `0xd0` | 4 | u32/i32/float |
| 7 | `0xd4` | 4 | u32/i32/float |

### Player_Save

- Address: `0x50ea90`
- Fields: 21
- Direct bytes: 132
- Loader: `Player_Load` (exact)

- Nested serializers: `Character_Save`, `Player_Event_Save`, `Player_AIState_Save`, `Player_MissionState_Save`

| # | Offset | Size | Type hint |
|---:|---:|---:|---|
| 0 | `0x84` | 4 | u32/i32/float |
| 1 | `0x88` | 4 | u32/i32/float |
| 2 | `0x8` | 4 | u32/i32/float |
| 3 | `0xc` | 32 | bytes[32] |
| 4 | `0x2c` | 4 | u32/i32/float |
| 5 | `0x30` | 4 | u32/i32/float |
| 6 | `0x3c` | 4 | u32/i32/float |
| 7 | `0x40` | 4 | u32/i32/float |
| 8 | `0x44` | 4 | u32/i32/float |
| 9 | `0x48` | 4 | u32/i32/float |
| 10 | `0x4c` | 4 | u32/i32/float |
| 11 | `0x50` | 4 | u32/i32/float |
| 12 | `0x54` | 4 | u32/i32/float |
| 13 | `0x58` | 4 | u32/i32/float |
| 14 | `0x5c` | 4 | u32/i32/float |
| 15 | `0x60` | 4 | u32/i32/float |
| 16 | `0x64` | 4 | u32/i32/float |
| 17 | `0x68` | 4 | u32/i32/float |
| 18 | `0x6c` | 24 | bytes[24] |
| 19 | `0x34` | 4 | u32/i32/float |
| 20 | `0x38` | 4 | u32/i32/float |

### RecipeTopping_Save

- Address: `0x4d1ba0`
- Fields: 8
- Direct bytes: 21
- Loader: `RecipeTopping_Load` (exact)

| # | Offset | Size | Type hint |
|---:|---:|---:|---|
| 0 | `0x4` | 1 | u8/bool |
| 1 | `0x5` | 1 | u8/bool |
| 2 | `0x6` | 1 | u8/bool |
| 3 | `0x8` | 4 | u32/i32/float |
| 4 | `0xc` | 4 | u32/i32/float |
| 5 | `0x10` | 1 | u8/bool |
| 6 | `0x11` | 1 | u8/bool |
| 7 | `0x14` | 8 | u64/double |

### SaveGame_Serialize

- Address: `0x487b50`
- Fields: 22
- Direct bytes: 1608
- Loader: `Game_LoadSaveGame` (exact)

- Nested serializers: `IngredientPanel_Save`, `CityCompanyList_Save`, `AdvertisingPanel_Save`, `CompanyMarketShare_Save`, `CompanyOverview_Save`, `StatisticsBalance_Save`, `StatisticsBranchBalance_Save`, `Personnel_Save`, `BranchStats_SeriesFlags_Save`, `BranchDesign_ColorIndex_Save`, `BranchMenu_Category_Save`, `WarehouseProduct_Save`, `GameCalendar_Save`, `UI_BriefingList_Save`, `IsoMap_Save`, `Character_Save`, `MapObjectList_Save`, `PersonList_Save`, `CarList_Save`, `Player_Save`, `CompanyData_Save`, `AI_CompanySlots_Save`

| Global address | Size | Type hint |
|---|---:|---|
| `0x57bb20` | 1464 | bytes[1464] |

| # | Offset | Size | Type hint |
|---:|---:|---:|---|
| 0 | `0x298` | 32 | bytes[32] |
| 1 | `0x2b8` | 32 | bytes[32] |
| 2 | `0x2d8` | 4 | u32/i32/float |
| 3 | `0x2dc` | 4 | u32/i32/float |
| 4 | `0x2ec` | 4 | u32/i32/float |
| 5 | `0x2f0` | 4 | u32/i32/float |
| 6 | `0x2f4` | 4 | u32/i32/float |
| 7 | `0x2e8` | 4 | u32/i32/float |
| 8 | `0x2f8` | 4 | u32/i32/float |
| 9 | `0x33c` | 4 | u32/i32/float |
| 10 | `0x348` | 4 | u32/i32/float |
| 11 | `0x34c` | 4 | u32/i32/float |
| 12 | `0x350` | 4 | u32/i32/float |
| 13 | `0x344` | 4 | u32/i32/float |
| 14 | `0x354` | 4 | u32/i32/float |
| 15 | `0x340` | 4 | u32/i32/float |
| 16 | `0x364` | 4 | u32/i32/float |
| 17 | `0x368` | 4 | u32/i32/float |
| 18 | `0x360` | 4 | u32/i32/float |
| 19 | `0x358` | 4 | u32/i32/float |
| 20 | `0x35c` | 4 | u32/i32/float |
| 21 | `0x2d90` | 4 | u32/i32/float |

### SaveGame_SerializeRuntimeList

- Address: `0x487940`
- Fields: 0
- Direct bytes: 0
- Loader: `SaveGame_DeserializeRuntimeList` (exact)

| Count | Shape | Note |
|---:|---|---|
| 6 | u32 present; if present: float x2 + u32 type; u32 trailing value | six runtime slots at game+0x2c41c..0x2c434 |

| # | Offset | Size | Type hint |
|---:|---:|---:|---|

### StatisticsBalance_Save

- Address: `0x4aa700`
- Fields: 0
- Direct bytes: 16
- Loader: `StatisticsBalance_Load` (exact)

| Global address | Size | Type hint |
|---|---:|---|
| `0x569354` | 4 | u32/i32/float |
| `0x57d5c8` | 4 | u32/i32/float |
| `0x57d5d0` | 4 | u32/i32/float |
| `0x569358` | 4 | u32/i32/float |

| # | Offset | Size | Type hint |
|---:|---:|---:|---|

### StatisticsBranchBalance_Save

- Address: `0x4ac400`
- Fields: 0
- Direct bytes: 12
- Loader: `StatisticsBranchBalance_Load` (exact)

| Global address | Size | Type hint |
|---|---:|---|
| `0x56951c` | 4 | u32/i32/float |
| `0x57d62c` | 4 | u32/i32/float |
| `0x57d630` | 4 | u32/i32/float |

| # | Offset | Size | Type hint |
|---:|---:|---:|---|

### StatsPeriodReport_Save

- Address: `0x401200`
- Fields: 6
- Direct bytes: 856
- Loader: `StatsPeriodReport_Load` (exact)

| # | Offset | Size | Type hint |
|---:|---:|---:|---|
| 0 | `0x10` | 104 | bytes[104] |
| 1 | `0x78` | 100 | bytes[100] |
| 2 | `0xdc` | 640 | bytes[640] |
| 3 | `0x4` | 4 | u32/i32/float |
| 4 | `0xc` | 4 | u32/i32/float |
| 5 | `0x8` | 4 | u32/i32/float |

### WarehouseProduct_Save

- Address: `0x4c0d60`
- Fields: 0
- Direct bytes: 4
- Loader: `WarehouseProduct_Load` (exact)

| Global address | Size | Type hint |
|---|---:|---|
| `0x57d714` | 4 | u32/i32/float |

| # | Offset | Size | Type hint |
|---:|---:|---:|---|

## Load-side aliases

These writers do not have a same-named loader; the pairing was established by matching field order/size or by the constructor path.

| Writer | Loader | Basis |
|---|---|---|
| `CarList_Save` | `Car_LoadFromStream` | declared-alias |
| `Car_Save` | `Car_LoadSpriteRecord` | declared-alias |
| `CompanyData_Save` | `Company_Load` | declared-alias |
| `MapSprite_Save` | `MapActor_ReadFromStream` | declared-alias |
| `PersonList_Save` | `PersonAction_LoadState` | declared-alias |
| `Person_Save` | `MapObject_ReadRenderRecord` | declared-alias |
| `SaveGame_Serialize` | `Game_LoadSaveGame` | exact-sequence |
| `Game_SaveTileNameTable` | `World_LoadNameIndexTable` | explicit-writer/loader-pair |
| `SaveGame_SerializeRuntimeList` | `SaveGame_DeserializeRuntimeList` | explicit-writer/loader-pair |

## Known gaps

- `IsoMap_Load` delegates most of the map body to `IsoMap_DeserializeGrid` and repeated sub-readers; the writer order is complete, but the nested reader graph is not flattened here.
- `MapObjectList_Save` writes 31 direct fields while `MapObjectList_Load` reads 30 in a different offset order; the extra writer field is retained in the schema and the loader path is marked `different-load-path`.
- `ConstructionOrder_Save` writes field `+0x10`, but `ConstructionOrder_Load` does not read it (reserved/version-dependent).
- `MapObject_Load` reads one field (`+0x28`) that `MapObject_Save` does not write; treated as a defaulted field.
- Variable-length strings, counted lists and embedded object graphs are represented by their count/nested writer calls, not expanded to bytes.
- No real `.piz` sample was available, so the schema is statically derived and not runtime-validated.

