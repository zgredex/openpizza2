# Pizza Connection 2 state model

Merged view of **vtable/class field observations** and the **save-state schema**. This separates persistent state from derived/transient fields, which is the core requirement for a modern engine or save editor.

- Classes mapped to save writers: **19**
- Observed field offsets: **668**
- Serialized field offsets: **340**
- Fields both observed and serialized: **318**
- Serialized global blocks: **24**

## Coverage by class

| Class | Size | Writer | Observed | Serialized | Both | Observed-only | Serialized-only |
|---|---:|---|---:|---:|---:|---:|---:|
| `Game` | 0x2f890 | `SaveGame_Serialize` | 271 | 22 | 22 | 249 | 0 |
| `Branch` |  | `Branch_Save` | 98 | 75 | 75 | 23 | 0 |
| `Company` | 0x1f0 | `CompanyData_Save` | 39 | 27 | 27 | 12 | 0 |
| `IsoMap` | 0x10178 | `IsoMap_Save` | 39 | 23 | 23 | 16 | 0 |
| `WorldObject` | 0x16c | `PersonList_Save` | 39 | 38 | 31 | 8 | 7 |
| `Character` | 0x828 | `Character_Save` | 27 | 23 | 23 | 4 | 0 |
| `City` | 0x1158 | `MapObjectList_Save` | 25 | 30 | 15 | 10 | 15 |
| `Player` | 0xb0 | `Player_Save` | 25 | 21 | 21 | 4 | 0 |
| `MapObject` |  | `MapObject_Save` | 24 | 17 | 17 | 7 | 0 |
| `PlayerAIState` |  | `Player_AIState_Save` | 19 | 16 | 16 | 3 | 0 |
| `GameClock` |  | `GameCalendar_Save` | 13 | 10 | 10 | 3 | 0 |
| `RecipeTopping` |  | `RecipeTopping_Save` | 9 | 8 | 8 | 1 | 0 |
| `ConstructionOrder` |  | `ConstructionOrder_Save` | 8 | 8 | 8 | 0 | 0 |
| `PlayerMissionState` |  | `Player_MissionState_Save` | 8 | 8 | 8 | 0 | 0 |
| `StatsPeriodReport` |  | `StatsPeriodReport_Save` | 6 | 6 | 6 | 0 | 0 |
| `BuildingValue` |  | `BuildingValue_Save` | 6 | 5 | 5 | 1 | 0 |
| `UI_BriefingList` |  | `UI_BriefingList_Save` | 6 | 0 | 0 | 6 | 0 |
| `Car` | 0x14 | `CarList_Save` | 4 | 1 | 1 | 3 | 0 |
| `Player_Event` |  | `Player_Event_Save` | 2 | 2 | 2 | 0 | 0 |

## Serialized globals

| Address | Size | Name | Writer |
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

## Interpretation

- Fields with `observed-only` are candidates for transient/derived state, runtime caches, or state stored in a nested object.
- Fields with `serialized-only` are real persistent fields whose access was not seen by the constructor/field scanner; they are high-value for struct reconstruction.
- `Game` has the largest observed model but only 22 direct serialized fields at the top level; the rest is in `g_GameGlobalState` (1,464 bytes) and nested subsystem serializers.
- `Company` is the clearest example of serialized-only coverage: its `CompanyData_Save` block yields 27 persistent fields, many not seen by the generic field scanner.
- `City` is serialized by the legacy-named `MapObjectList_Save`; its 30 observed fields and 31 writer fields overlap only partially, indicating either a level of indirection or a writer that also serializes a contained map-object list.

## Field details

### Branch

- Vtable: `0x55c30c`
- Writer: `Branch_Save`
- Size: unknown
- Observed / serialized / both: 98 / 75 / 75

- Observed-only offsets: `0x14c4`, `0x14dc`, `0x14e0`, `0x14f8`, `0x1514`, `0x16f0`, `0x170c`, `0x173c`, `0x1758`, `0x1774`, `0x1881`, `0x1882`, `0x1883`, `0x1888`, `0x188c`, `0x1890`, `0x19ac`, `0x19b8`, `0x19bc`, `0x19c0`, `0x19d8`, `0x19f4`, `0x1a28`

### BuildingValue

- Vtable: `0x55c5a4`
- Writer: `BuildingValue_Save`
- Size: unknown
- Observed / serialized / both: 6 / 5 / 5

- Observed-only offsets: `0x14`

### Car

- Vtable: `0x55c4f8`
- Writer: `CarList_Save`
- Size: `0x14`
- Observed / serialized / both: 4 / 1 / 1

- Observed-only offsets: `0x4`, `0x8`, `0x10`

### Character

- Vtable: `0x55c4fc`
- Writer: `Character_Save`
- Size: `0x828`
- Observed / serialized / both: 27 / 23 / 23

- Observed-only offsets: `0x1d4`, `0x364`, `0x4f4`, `0x684`

### City

- Vtable: `0x55c500`
- Writer: `MapObjectList_Save`
- Size: `0x1158`
- Observed / serialized / both: 25 / 30 / 15

- Serialized-only offsets: `0x4`, `0x44`, `0xc20`, `0xc38`, `0xc98`, `0xcb0`, `0xcc8`, `0xce0`, `0xd40`, `0xd58`, `0xd88`, `0xdc8`, `0xfe4`, `0x10c0`, `0x10d0`

- Observed-only offsets: `0x14`, `0x1c`, `0x20`, `0x24`, `0x28`, `0x48`, `0xfa8`, `0xfc0`, `0xfdc`, `0x10a8`

### Company

- Vtable: `0x55c568`
- Writer: `CompanyData_Save`
- Size: `0x1f0`
- Observed / serialized / both: 39 / 27 / 27

- Observed-only offsets: `0xb0`, `0xe8`, `0xec`, `0x10c`, `0x124`, `0x15c`, `0x178`, `0x194`, `0x1b0`, `0x1cc`, `0x1d4`, `0x1d8`

### ConstructionOrder

- Vtable: `0x55c5bc`
- Writer: `ConstructionOrder_Save`
- Size: unknown
- Observed / serialized / both: 8 / 8 / 8

### Game

- Vtable: `0x55c5d0`
- Writer: `SaveGame_Serialize`
- Size: `0x2f890`
- Observed / serialized / both: 271 / 22 / 22

- Observed-only offsets: `0x4`, `0x8`, `0xc`, `0x10`, `0x14`, `0x18`, `0x1c`, `0x20`, `0x31`, `0x33`, `0x34`, `0x6c`, `0x90`, `0x94`, `0x9c`, `0xa8`, `0xc0`, `0xc6`, `0xc8`, `0xd0`, `0xd4`, `0x124`, `0x1cc`, `0x200`, `0x224`, `0x240`, `0x244`, `0x248`, `0x24c`, `0x250`, `0x254`, `0x258`, `0x25c`, `0x260`, `0x300`, `0x81c`, `0x820`, `0x1148`, `0x114c`, `0x1150` ...

### GameClock

- Vtable: `0x55c564`
- Writer: `GameCalendar_Save`
- Size: unknown
- Observed / serialized / both: 13 / 10 / 10

- Observed-only offsets: `0x1c`, `0x20`, `0x24`

### IsoMap

- Vtable: `0x55c5d4`
- Writer: `IsoMap_Save`
- Size: `0x10178`
- Observed / serialized / both: 39 / 23 / 23

- Observed-only offsets: `0x4`, `0x8`, `0x50`, `0x54`, `0x64`, `0x70`, `0x74`, `0x78`, `0xb0`, `0xe8`, `0xec`, `0xf4`, `0x110`, `0x114`, `0x138`, `0x1015c`

### MapObject

- Vtable: `0x55c4ec`
- Writer: `MapObject_Save`
- Size: unknown
- Observed / serialized / both: 24 / 17 / 17

- Observed-only offsets: `0x28`, `0x44`, `0x6c`, `0x74`, `0x8c`, `0xc4`, `0xc8`

### Player

- Vtable: `0x55c684`
- Writer: `Player_Save`
- Size: `0xb0`
- Observed / serialized / both: 25 / 21 / 21

- Observed-only offsets: `0x4`, `0xa0`, `0xa8`, `0xac`

### PlayerAIState

- Vtable: `0x55c664`
- Writer: `Player_AIState_Save`
- Size: unknown
- Observed / serialized / both: 19 / 16 / 16

- Observed-only offsets: `0x7c`, `0xa8`, `0xac`

### PlayerMissionState

- Vtable: `0x55c5e8`
- Writer: `Player_MissionState_Save`
- Size: unknown
- Observed / serialized / both: 8 / 8 / 8

### Player_Event

- Vtable: `0x55c660`
- Writer: `Player_Event_Save`
- Size: unknown
- Observed / serialized / both: 2 / 2 / 2

### RecipeTopping

- Vtable: `0x55c4e8`
- Writer: `RecipeTopping_Save`
- Size: unknown
- Observed / serialized / both: 9 / 8 / 8

- Observed-only offsets: `0x18`

### StatsPeriodReport

- Vtable: `0x55c2e0`
- Writer: `StatsPeriodReport_Save`
- Size: unknown
- Observed / serialized / both: 6 / 6 / 6

### UI_BriefingList

- Vtable: `0x55cb40`
- Writer: `UI_BriefingList_Save`
- Size: unknown
- Observed / serialized / both: 6 / 0 / 0

- Observed-only offsets: `0x18`, `0x20`, `0x24`, `0x28`, `0x30`, `0x34`

### WorldObject

- Vtable: `0x55c668`
- Writer: `PersonList_Save`
- Size: `0x16c`
- Observed / serialized / both: 39 / 38 / 31

- Serialized-only offsets: `0x4`, `0x44`, `0x48`, `0x5c`, `0xac`, `0x128`, `0x14c`

- Observed-only offsets: `0xc4`, `0xcc`, `0xd0`, `0xf4`, `0xf8`, `0x100`, `0x164`, `0x168`

