# Simulation and economy model

Static reconstruction from the named pseudocode. This is a working map of the
quarterly/weekly/per-frame pipelines and the confirmed rating, freshness and
service formulas. Fields are structural (`+0xNN`) until proven otherwise.

## Time and update pipeline

### Quarterly: `Game_EndOfQuarter` (`0x4867e0`)

1. For each of six companies: `Stats_AppendPeriodReport`.
2. For each city: `Rating_StoreDailyResults`.
3. Player slot loop (no-op in this build).
4. For each city: `City_ProcessQuarterEnd`.
5. For each company: `Company_ProcessDailyAccounting`.
6. For each company: `Company_RecordDailyStatistics`.
7. `Game_DispatchQuarterlyVisitors`.
8. Queue UI command `0x23` on the active player object.

### Weekly: `Branch_AdvanceWeekStatistics` (`0x47ef30`)

- Writes the week number at `+0x16EC`.
- Per-week customer counts:
  - `+0x1388 + i*4 = weekly customers`
  - `+0x13D0 + i*4 = weekly group count`
  - `+0x1418/+0x1460 + i*4 = occupancy/employee percentages` when the week
    value is non-zero:
    `(1 - used/capacity) * weeklyCustomers`.
- Iterates construction orders, advances funded orders, and pays completed
  orders through `Branch_PayConstructionOrder`.

### Per-frame / world

- `Game_UpdateWorldObjects` (`0x40b900`)
- `Person_UpdateBehavior` (`0x40b400`)
- `Customer_UpdateMovement` (`0x407ea0`)
- `Object_UpdateBranchOps` (`0x406ff0`)

## Rating pipeline

`Branch_RecalculateRatings` (`0x478db0`) builds an object grid and runs:

```text
Company_ComputeTypePercentages
Stats_ComputeBestPairShareAverage
Game_ComputeCategoryDominance
Stats_ComputeOccupancyPercent
Stats_GetAverageValue
Game_ComputeCityScore
Map_ComputeBuildableAverage
Stats_ComputeTypeThreeShare
Game_UpdateActivePlayerCount
Game_ComputeCityConditionScore
Stats_UpdateAverages
Stats_ComputeWeightedTotals
Rating_ComputeBranchScores
```

Then subtracts `+0x1878` from each of the eight group scores and clamps each to
`0..100`.

### Customer-group rating: `Branch_GetCustomerGroupRating` (`0x47a3b0`)

```text
base     = Stats_GetAverage8(this, group)
building = Branch_ComputeBuildingRating(this, group)
menu     = Branch_GetMenuRating(this, group)
score    = base + building + menu
divisor  = 3

if price comparison enabled:
    price = Branch_GetPriceComparisonRating(this, group, &hasPrice)
    if hasPrice:
        score += price
        divisor = 4

result = Rating_ComputeBuildingScore(this, group) + score / divisor
result = clamp(result, 0, 100)
```

### Menu and price ratings

`Branch_GetMenuRating` (`0x478320`):

```text
rating = per-group menu rating, or mean of the 8 group ratings
city   = player's city
rating = ((100 - 3 * (city[0x5C] + city[0x44])) * rating) / 100
rating = clamp(rating, 0, 100)
```

`Branch_GetPriceComparisonRating` (`0x478420`) uses the same city adjustment on
`GamePlan_ComputeAverageEffect` / `GamePlan_ComputeCategoryEffect`.

### Building rating: `Branch_ComputeBuildingRating` (`0x478be0`)

- Uses `Game_ComputeAverageProductQuality` and
  `Stats_ComputeAverageGroupScore`.
- For each group, compares the score against the baseline tables at
  `0x5677F8` / `0x567818` and applies occupancy/quality terms.
- Subtracts `10 * branch[0x187C]` per group.
- For the current player, applies two penalties when the player mission state
  flags `+0x1C8` / `+0xE4` are set: `score * 0x5F / 100` and `score * 0x6E / 100`.
- Applies the same city adjustment and clamps to `0..100`.

### Branch score tables: `Rating_ComputeBranchScores` (`0x478f60`)

For each of the eight customer groups:

```text
if value < baseline[i]: score = (value - baseline[i]) * 3 + 100
else:                  score = 100
score = clamp(score, 0, 100)
```

The baselines/weights come from `balance_tables.json`:

| Address | Values |
|---|---|
| `0x567838` | 0, 10, 20, 30, 90, 80, 40, 50 |
| `0x567858` | 0, 40, 30, 20, 80, 90, 50, 60 |
| `0x567878` | 30, 50, 70, 40, 90, 100, 80, 60 |
| `0x567898` | 25, 20, 35, 15, 45, 50, 40, 30 |
| `0x5678B8` | 75, 60, 45, 30, 15, 0, 0, 100 |
| `0x5678D8` | 15, 30, 50, 35, 20, 25, 40, 45 |
| `0x5678F8` | 7, 5, 5, 6, 8, 8, 7, 6 |

## Market bonus

`Game_GetMarketBonusFactor` (`0x47ab20`):

```text
if game[0x14C4] == 0: return 1.0
x = game[0x14C0] >> 1
if x < 0:
    composite = Rating_GetComposite(game[0x14C4])
    adjustment = composite / 20
    x += adjustment if adjustment < 1 else 0
return (100 + x) * 0.01
```

`1.0` is neutral; lower values are a market penalty.

## Product freshness

`Product_ComputeFreshness` (`0x47acf0`) switches on the double at product
`+0x70` and subtracts a converted time value from a base shelf life:

| Product constant | Base days |
|---:|---:|
| 14.1 | 38 |
| 15.5 | 30 |
| 16.9 | 22 |
| 6.5 | 34 |
| 7.5 | 27 |
| 8.6 | 20 |
| 2.5 | 30 |
| 2.9 | 24 |
| 3.6 | 18 |
| 1.0 | 25 |
| 1.2 | 20 |
| 1.6 | 15 |

## City service level

`City_ComputeServiceLevel` (`0x47c830`):

```text
minDeficit = 24
for i in 0..3:
    v = city[0xA4 + i*4]
    minDeficit = min(minDeficit, v - 6)
if minDeficit < 25:
    return (24 - minDeficit) / cityServiceDivisor[city[0x38]] + 1
return 0
```

`cityServiceDivisor` is the 10-entry table at `0x5675AC`:

```text
15, 12, 8, 65, 75, 85, 70, 95, 100, 90
```

The construction-time base at `0x5675A0` is:

```text
35, 30, 23, 15, 12, 8, 65, 75, 85, 70
```

## Work duration

`Branch_ComputeWorkDuration` (`0x47d340`):

- Collects orders in category 5.
- If no products: returns `0xB4` (180).
- Otherwise computes `Rating_GetComposite(employee)` and converts it to an
  integer duration.

## Balance tables

`decompiled_fastfood2_named_v2/balance_tables.json` contains the extracted
8-group and 10-city tables with addresses, values and using functions.

## Hourly and daily model

`Branch_ProcessHour` (`0x4773A0`) and `Company_ProcessHourlyTick` (`0x4E0200`)
define the hourly economy:

- Every third hour: `Branch_AdvanceWeekStatistics`.
- Staff salaries: hourly share `salary / 24`; the company also pays its share
  through `Game_CanAffordWithCurrency(..., 0x17, salary / 24)`.
- Advertising/marketing: hourly share `budget / 24` (game uses 1/720 of the
  monthly budget in the simulator).
- Negative cash: **0.4% interest per hour** (`* 0.004000000189989805`).
- Branch open/closed schedule: 24 bytes at `+0x1A08`; `Game_GetHourlyValue`
  returns the open flag.
- `Branch_ProcessHour` spawns one walk-in via `Branch_SpawnWalkInCustomer` when
  the branch is open.
- Every third hour it also runs `Branch_AdvanceWeekStatistics`, which calls
  `Branch_SpawnRandomPedestrian` when a type-0x1B source building exists.

### Exact branch-choice path

`Object_Construct` (`0x504610`) initializes each person with:

- `+0x2C` = random threshold **30..50** (`Random_RangeFast(0x1E, 0x32)`)
- `+0x34` = customer group (0..7)
- `+0x5C` = six zeroed per-size scores (`0x18` bytes)

`PersonList_Save`/`PersonAction_LoadState` persist the six scores at `+0x5C`.

`Object_IsSiteRatingSufficient` (`0x5080F0`):

```text
if branch[0x2C] != 0: reject
rating = Branch_GetCustomerGroupRating(branch, person.group, price_comparison=0)
accept if person[0x2C] <= rating
```

`City_CollectBranchesNearPoint` (`0x4D7ED0`):

```text
dx^2 + 4*dy^2 < 4*radius^2
```

with the branch radius from `Game_GetAdjustedValue(branch[0x74])`.

`Game_PickBestScoredRecord` (`0x4D82B0`):

```text
if one candidate: choose it
else: choose max person[0x5C + branch.size_class*4]
ties favour the later branch in the nearby list
```

`Object_SyncChildState` (`0x5094A0`) updates the score for the branch's size
class after an evaluation:

| Branch group rating | Score change |
|---:|---:|
| ≥ 96 | set 100; every other size −10 |
| 85–95 | +10 |
| 75–84 | +8 |
| 65–74 | +5 |
| 55–64 | +3 |
| 44–54 | 0 |
| 35–43 | −3 |
| 25–34 | −5 |
| 15–24 | −10 |
| < 15 | −20 |

Every one of the six scores is clamped to `-100..100`.

The simulator uses this exact path (`choice_mode="exact"`). The optional
`"logit"` mode is retained only for comparison.

### Exact hourly traffic and queue

`Branch_SpawnWalkInCustomer` (`0x477190`):

- requires an open branch-hour;
- picks a random customer group **0..7** (`Random_RangeFast(0,7)`);
- creates a person at a map cell, computes a path to the branch entrance, and
  adds it to the branch queue list.

`Branch_AdvanceWeekStatistics` (`0x47EF30`) → `Branch_SpawnRandomPedestrian`
(`0x480900`): if a type-0x1B source building exists, spawn one ambient
pedestrian; the function limits the number of such buildings to 30.

`Object_UpdateCustomerQueue` (`0x409D80`) / `Person_UpdateIndoorAction`
(`0x406E90`) manage the interior queue:

- branch queue ID map at `+0x1744`;
- queue/interior capacity at `+0x1758`;
- lost-customer counter at `+0x16E0`;
- party size `(Rating_GetComposite(character) >> 4) + 1` at `customer+0x98`;
- `Customer_ApproachBranchEntrance` and `Person_ProcessMoveEvent` move the
  customer from the street to the entrance and then the queue.

### Exact movement and service cadence

`GameLoop_DispatchScreens` (`0x4052C0`) waits **10 ms** per loop iteration, so
the world tick rate is nominally **100 ticks/second**.

`Object_UpdateWalkStep` (`0x4F21E0`) advances a path node when the sprite
frame sequence completes; the delay comes from the walk animation template.
`Person_ProcessMoveEvent` (`0x50ADF0`) is the state transition on arrival, and
`Customer_UpdateMovement` (`0x407EA0`) drives the store-customer states in the
same tick loop.

`Game_GetTimeByMode` (`0x504A90`):

- mode 4 (entry): branch type 0x0F/0x21 = `0x104 ± 10` ticks; other branches
  use the object-type table;
- mode 6 (service/wait): branch type 0x0F/0x21 = **80 ticks**; other = **30
  ticks**;
- both are **0.3–0.8 seconds**, far below one hour.

### Exact party-size inputs

`Object_UpdateCustomerQueue` looks up `customer+0x50` in the global character
list (`DAT_0057c670 + 0x20`) and passes that `Character` to
`Rating_GetComposite`.

`Character_Construct` (`0x4D3730`) sets:

| Field | Value |
|---|---|
| `+4`, `+8`, `+0xC`, `+0x10` | `Random_RangeFast(0x1E, 0x46)` → **30..70** |
| `+0x38` | `Random_RangeFast(0x12, 0x3C)` → **18..60** |
| `+0x14`, `+0x18` | 0 (flag inputs to `State_HasFlags`) |
| `+0x824` | customer group |

The composite and party-size calculations are the already-decoded
`Rating_GetComposite` and `(composite >> 4) + 1`.

### Exact obstacle-aware path routing

The `.iso` object tables are the runtime street graph. `IsoMap_DeserializeGrid`
(`0x4EB900`) copies each 34-byte file record into a 0x28-byte node:

| Node field | Meaning |
|---|---|
| `+0x04` | sequential node index |
| `+0x08` | map value / sprite key |
| `+0x0C`, `+0x10` | node coordinates |
| `+0x14` | eight neighbour indices |
| `+0x24` | extra byte |

`Map_FindShortestPath` (`0x4F14A0`) runs a shortest-path search over these
links and returns the **number of path nodes** (capped at 400).
`Map_LinkCells` (`0x4F0AB0`) stores up to **eight** neighbours;
`Grid_RebuildStreetNodes` (`0x4F3200`) evaluates all eight neighbours.
`Object_Compare` (`0x4ED500`) charges
`3*|Δfield_0xC| + 4*|Δfield_0x10|` per hop.

`tools/iso_tool.py` now exposes `PathGraph`, which loads the graph and runs the
same Dijkstra/A* cost search:

```python
graph = PathGraph.from_iso("game/Isokarten/Ber.iso")
count, cost, path = graph.shortest_path(0, 100)   # 15 nodes, cost 5184
```

Berlin has **673 connected street nodes**; the graph is used automatically when
a simulator loads a map:

```bash
python3 tools/sim_core.py demo --days 30 --map game/Isokarten/Ber.iso
```

Without a loaded map the simulator falls back to the open 8-neighbour grid
metric (`cell_x=(dx/32+dy/16)/2`, `cell_y=(dy/16-dx/32)/2`).

### Exact per-cell walk duration

Walk animation templates are the `*_sma.ani` character animations. Their first
`gehen1..gehen8` frames all carry delay byte **12** for 37 of 40 customer
animations (police use 18).

`Record_SetVariant` (`0x533B90`) computes the frame delay in milliseconds:

```text
delay_ms = round(1000 / (delay_byte * sequence_scale * animation_scale))
         = round(1000 / 12) = 83 ms
```

`Record_AdvanceFrameSequence` (`0x533C90`) accumulates this delay and advances
one path node when the frame completes.

The simulator therefore models:

```text
walk-ins   = 1 per open branch-hour
pedestrians= 1 per branch every 3 hours when source buildings exist
party size = (Character.composite() >> 4) + 1
travel     = path_cells * 83 ms
queue      = seat-capacity check; all queued parties are served within the hour
```

`travel_hours()` returns 0 for any realistic path; the queue drains each hour.
The **party-size inputs, composite formula, graph node count, obstacle routing
and 83 ms per-cell duration are exact**.

## Rating composite and building weights

`Rating_GetComposite` (`0x4D4000`) combines four components (`+4`, `+8`,
`+0xC`, `+0x10`) with a state field at `+0x38`:

```text
c0 = state < 51 ? v4 - 25 + state : (55 - state)*5 + v4   # clamp 0..100
c1 = state > 55 ? v8 + (55 - state)*3 : v8                # clamp >= 0
c2 = v12
c3 = state > 50 ? v16 + (50 - state)*2 : v16              # clamp >= 0
avg = (c0 + c1 + c2 + c3) >> 2
if flagged: avg = (avg - (total >> 31)) >> 1
result = min(avg, min(c0,c1,c2,c3) * 4)
```

`Rating_ComputeBuildingScore` (`0x47A000`) uses a **56-entry per-group table**
(8 groups × 7 building categories). The extracted values are in
`sim_constants.json` and applied to facility counts:

```text
score[g] = count(0x17)*W[g+0x28]
         + count(0x16)*W[g]
         + (count(0x21)+count(0x0F))*W[g+0x18]*2
         + (staff_value/60 + floor_value)*W[g+8]
         + round(W[g+0x10] * min(4, count(0x1A)/5+1))
         + round(W[g+0x20] * min(4, count(0x1B)/5+1))
         + round(W[g+0x30] * min(4, count(0x1C)/5+1))
```

For group `-1`, the eight group scores are averaged.

`Game_GetPlayerCity` (`0x4DDCC0`) is misnamed: it indexes the **Player array**
at `Game+0x224`, so `+0x5C`/`+0x44` are serialized Player fields, not City
fields. `Stats_GetAverage8` (`0x4787F0`), `Branch_GetMenuRating` (`0x478320`),
`Branch_ComputeBuildingRating` (`0x478BE0`) and
`Branch_GetPriceComparisonRating` (`0x478420`) scale their result by:

```text
(100 - 3*(Player+0x5C + Player+0x44)) * value / 100
```

The simulator exposes `Company.trait_a`, `Company.trait_b` and
`Company.rating_factor = max(0, 100 - 3*(a+b))`; `add_branch` copies it to
`Branch.rating_factor` and `update_ratings` applies it to avg8/menu/price/
building ratings. Default 0/0 -> 100. See `RATING_FACTOR_TRACE.md`.

`Rating_GetFloat` (`0x489070`) gives the expected price per group:

```text
inc = EINKOMMEN*0.02; phase = (11-difficulty)*0.5
g0 inc*3+phase+4; g1 inc*4+phase+5; g2 inc*4+phase+8;
g3 inc*3+phase+8; g4 inc*7+phase+10; g5/g8 inc*10+phase+8;
g6 inc*3+phase+7; g7 phase+12
```

`Game_ComputeSkillRatings` (`0x513760`) writes the price-positioning term:

```text
price > expected -> trunc((price/expected-1)*-50)
price < expected -> trunc((expected/price-1)*50), caps [40,10,20,30,5,0,40,20]
price == expected -> 0
```

The simulator uses `rating_group_expectation()` and
`game_compute_skill_ratings()`; `update_ratings` adds the price term to the
recipe base skill. See `RATING_SKILL_TRACE.md`.

`Game_ComputeFoodStats` (`0x513590`) pairs 83 ingredient combinations
(`DAT_00573264`, in `sim_constants.json -> food_pairs`) into seven category
buckets, then derives eight food stats. `Game_ComputeCompanyRatings`
(`0x5136C0`) forms the base skill from food stats, layout quality and market
factors. The simulator implements `Recipe.food_stats()` and
`Recipe.base_skill_ratings()`; layout quality uses recipe quality as proxy and
market factors use 0.

`Rating_StoreClampedScores` (`0x513270`) maps layout inputs
`a=+0x244, b=+0x248, c=+0x24C, d=+0x258` to eight scores at `+0x264`:

```text
[0.33a+0.70b, 0.70a+0.33b, 0.50b+50c, 0.60a+0.20b+0.20d,
 0.40b+60c, 0.40b+30c+0.30d, 0.33b+30c+0.40d, a+0.40b+d]
```

`Game_ComputeMarketFactors` (`0x5133C0`) builds `+0x284[8]` from
`+0x250/+0x254`, city score thresholds 200/300, mission flag, the 6x8 city
preference matrix, and the `<20` count penalty. `base_skill_ratings` uses:

```text
base[i] = (layout[i] + market[i])//2 + food[i]
```

The layout inputs are now real recipe data: weighted category percentages,
weighted taste/price/quality averages (`Stats_ComputeWeightedAverages`), total
amount (`+0x1D8`), topping count (`+0x5C`), price-competitiveness flag
(`AI_CheckPriceCompetitiveness`), and the city 6x8 food-taste matrix
(`GEMUESE..GEWUERZ`). `a` is built by composing the shipped topping sprites onto an 800x600
palette-index surface and scanning it with the decoded circle geometry;
`d` uses `Recipe_AccumulateQualityDelta` fed by
`Branch.topping_orientations`/`Branch.approach_objects`, generated from the
shipped branch `.iso` floor/kitchen tiles (15 maps). See `RATING_LAYOUT_TRACE.md`.

`Game_ComputeCompanyProductScore` (`0x513B00`) walks all 86 usage counters,
adds `Market_GetPriceDelta` per ingredient, and averages the 10-point recent
ring matches. `Player_TrackRecentEntry` (`0x4DA810`) maintains the six-entry
ring per customer category; type-1 advertising updates it instead of spawning a
customer. See `RATING_PRODUCT_TRACE.md`.

Menu ratings still depend on `Game_ComputeCompanyProductScore`,
`Game_GetSkillRating` and `Market_ComputeValueAdjustment`; those component
inputs remain partially reconstructed.

### Menu product/skill scores

`Game_GetSkillRating` (`0x5139E0`) returns the branch's per-group skill plus a
position component; group `-1` averages both arrays over the eight groups.

`Game_ComputeSkillRatings` (`0x513760`) builds eight skill values from the city
preferences, applies branch-level bonuses (level 1 = `+2×pref`, level 2 =
`+4×pref`), and clamps the categories:

```text
group 0/6 max 40, group 1 max 10, group 2/7 max 20,
group 3 max 30, group 4 max 5, group 5 = 0
```

`Market_GetPriceDelta` (`0x4DB170`):

```text
city level == -1 -> -40
city level ==  0 ->   0
otherwise        -> +40
```

`Market_ComputeValueAdjustment` (`0x4D7640`):

```text
base        = price delta
availability= 10 × matching city price-level entries (6 slots)
+ per-group price adjustment from branch[0xCD]
+ per-group quality adjustment from branch[0xCC]
- 1000 if city_pref / (price_scale[group] * 0.01) < branch price
```

`Game_ComputeCompanyProductScore` (`0x513B00`):

```text
score = average(product market values) + total availability + skill rating
score = clamp(score, 0, 100)
```

Menu rating is then `min(price_rating, (product_score + availability) / 2)`.
The formulas are exact; the city preference values, price levels and branch
adjustment flags are simulator inputs.

## Stock replenishment and market share

### Stock

`Storage_ProduceBatch` (`0x514330`):

- capacity from `Storage_GetCapacity`;
- fills up to `capacity - current_fill`, capped by `capacity / (branch_size + 1)`;
- creates 0x20-byte batches with expiry key `200000`, batch price from
  `BuildingValue_Compute`, product type and sub-index;
- distributes the purchase cost to shops.

`Storage_OrderDelivery` (`0x514510`) triggers a delivery when fill is below
**0x22 = 34%**, requires a supplier building and a free delivery truck.
`Storage_ReceivePendingOrder` (`0x5142C0`) receives one batch and orders the
next delivery. `Storage_DistributeCostToShops` (`0x514100`) splits the cost
equally across up to 20 shop slots; with no shops it charges the company.

`Branch_ProcessCustomerOrder` consumes branch stock batches at `+0x1998`,
oldest/lowest batch first, and charges the weighted ingredient cost.
`Recipe_AppendSalesRecord` (`0x50FF80`) records each sale.

The simulator now uses threshold-triggered deliveries, not a daily reset:

```text
initial stock = capacity
if stock < 34% and supplier and no delivery pending: schedule delivery
delivery after N hours: fill to capacity, add batch, charge company
order: consume oldest batch, cost = batch price × servings
```

### Market share

`Game_ComputeCompanySharePercent` (`0x4DDF10`) divides a company's category value
by the sum across active companies for the current period.
`Game_GetPlayerValueSharePercent` (`0x48CA10`) does the same across the six
player slots.

The simulator now uses **quarter-to-date revenue share**, stores the final share
at quarter end, and falls back to that stored share when the new period is empty.
The old lifetime-revenue share is no longer the primary path.

## Construction and advertising

### Construction queue

`ConstructionOrder_Construct` (`0x4E5D60`) initializes:

- `+4` = record type, `+8` = quality/variant, `+0xC` = **100** (duration),
  `+0x10` = state (0, clamped to 0 when loaded below 3);
- `+0x14` = tile field/variant (-1), `+0x18/+0x1C` = cell coordinates,
  `+0x20` = cell index.

`Branch_EnqueueConstructionOrder` (`0x47E0E0`) adds the order to the branch list
at `+0x16F8` and stores the coordinates/index. `Game_UpdateObject2` (`0x4E6020`)
uses `+0x18/+0x1C` as the grid cell and `+0x14` as the tile field when the
duration reaches zero. `Branch_CompleteConstruction` (`0x486F30`) finalizes the
object and places it in the player's city.

#### Exact order price

`Game_ComputePrice` (`0x4E4060`):

```text
price = trunc((100 - 3*(city[0x54] + city[0x3C]))
              * level_base[record[8]] * record[0x70] * 0.01)
level_base = [20, 100, 500, 150, 300, 180]   # levels 1..6
```

`Game_ComputeCityPriceShare` (`0x47F230`) and `Game_ComputeEventValue`
(`0x4E5F40`) split that price into four installments:

```text
progress == 100 -> 0
progress < 1    -> full price
otherwise       -> 25% * price * (1 - progress*0.01)
```

The simulator uses:

```text
cost = construction_order_price(level, record_value, city factors)
weekly: progress++, charge cost/weeks to ledger 3 (construction)
complete: facilities[type]++, quality += quality_gain
```

`AI_Action_BuildNewBranch` (`0x4FCE20`) charges category **3** for a new branch;
the old flat 50,000 charge and category 12 booking were removed.

#### `Market_ComputeWeightedAveragePrice` (`0x48C060`)

The list at branch `+0x1998` (accessed by `Branch_PayConstructionOrder`
`0x47EB30` and `Game_ConsumeObject` `0x47EAB0`) is the **stock/material batch
list**, not the `+0x16F8` construction-order queue. Each 0x20-byte batch has:

- `+0` = quantity (200000 for produced batches),
- `+4` = product record,
- `+0xC` = variant,
- `+0x10` = unit price (float),
- `+0x1C` = active/state flag.

The weighted-average function is:

```text
wavg = sum(market_price[i] * usage[i] * 0.001) / sum(usage[i])
cost = wavg * batch_unit_price * batch_quantity
```

`Branch_ProcessCustomerOrder` (`0x47D4A0`) uses the same `wavg` expression for
ingredient cost, then multiplies by `Game_GetMarketBonusFactor`.

#### Loaded market table and 86 usage counters

`Ingredient_LoadMarketTable` (`0x4E4930`) allocates **86** ingredient records,
reads `Size.tab` (86 × 128 bytes) into each record, then patches every record via
`Game_SetBuildingDesc` (`0x4E4860`):

- `+0xA8` = category byte,
- `+0xAC..+0xB8` = four quantity tiers,
- `+0xC0` = **double price**.

`market_table.json` stores all 86 records with exact prices, tiers and the four
`Size.tab` size layers. `tools/tab_tool.py` decodes both `.tab` files; format
details are in `TAB_FORMAT.md`.

Per-company `+0x64` counters are rebuilt by `PlayerStats_Reset` (`0x50FEC0`):
for every menu ingredient record it adds
`market_record[ingredient].quantity[variant]` into the company array.

The simulator now:

```text
MARKET_PRICES   = 86 exact +0xC0 doubles from market_table.json
product_usage   = sum of recipe ingredient quantities
                  explicit Recipe.ingredients, or derive_recipe_usage()
                  (three prices closest to an equal share of unit cost,
                   weighted by Size.tab tier-0 quantity)
balance_index   = raw wavg / equal-weight reference
```

The equal-weight reference keeps the simulator's currency scale stable while
preserving the exact relative ingredient prices and per-company composition.
`market_weighted_unit_price()` and `weighted_order_cost()` remain exact.

The simulator implements `market_weighted_unit_price()` and
`weighted_order_cost()` exactly; `weighted_market_price()` aggregates the active
companies' 86 product counters, and `process_order()` applies it to every batch
consumption.

### Advertising optimizer

`GamePlan_Optimize` (`0x4FE5F0`) sets:

| Plan field | Value |
|---|---|
| type 1 city | budget 10,000; requires level≥3 and ≥3 branches |
| type 2 poster | budget 5,000 |
| type 3 restaurant | budget 3,500 |
| media `+0x10` | 0 or 1..12; 0 = no-media baseline, kept unless a media gain is ≥1 |
| flags `+0x14` | greedy bits 1/2/4/8, each accepted only if gain is ≥1 |
| category `+0x18` | most-used ingredient index +1 |
| target `+0x1C` | best competitor slot or −1 |

`GamePlan_ComputeCategoryEffect` uses the 13-row table at `0x5730AC`
(media 1..12; media 0 uses the base 40): `(weight + 8) * 5`, then
competitor/own metric bands (45/55, or target average ±5), flags, company
percent modifier and the city term.

```text
city_term = 100 - 3*(City+0x64 + City+0x4C) = 100 - 3*(VOLK[6]+VOLK[0])
effect = trunc(city_term * (trunc(percent*(effect-40)/100) + 40) / 100)
        clamped 0..100
average = sum(effect[category 0..7]) >> 3
```

`Company_GetPercentModifier` (`0x50F7F0`): type 1 -> budget*100/10000,
type 2 -> budget*100/5000, otherwise 100. With optimizer budgets this is 100
for every plan type. Berlin: VOLK[0]=8, VOLK[6]=17 -> city_term 25.

`GamePlan_GetCompanyCategoryMetric` (`0x50FAB0`) selects the metric per flag:

| Flag | Metric |
|---:|---|
| 1 | `Branch_GetPriceRating` |
| 2 | `Branch_GetMenuRating` |
| 4 | `Branch_ComputeBuildingRating` |
| 8 | `Stats_GetAverage8` |

Own-metric averaging is type-specific: type 1 (city) averages the metric over
all owner branches; types 2/3 use the selected target branch. Competitor metrics
average over the target company's branches.

Target selection loops every other company and keeps the highest average
effect; the simulator now stores the selected target company id.

The simulator implements `optimize_advertising_plan()` and
`Simulator.optimize_advertising()`, using the media-0 baseline, all 12 media
rows, four flag bits, exact integer gain thresholds, the percent modifier and
the city term. The chosen media/flags/target/percent are stored on the
`AdvertisingPlan` and re-used by `_update_advertising`.

### Advertising plans

`Branch_AddAdvertisingPlan` (`0x5001F0`) creates a `GamePlan` and runs
`GamePlan_Optimize`. The plan budget (`+0x20`) is a **daily** amount:

```text
hourly charge = daily_budget / 24          # float32 1/24 at 0x55C588
ledger: type 1 -> 15, type 2 -> 16, type 3 -> 17
```

There is **no affordability check** on the hourly path. Ordinary creation costs
nothing; the only ledger-23 charge is a rival-billboard takeover,
`10 * old_budget` (`0x50027C`–`0x5002A4`). `weeks_left`/duration is not used:
plans have no time expiry.

`Company_AllocateMenuSales` (`0x4FE870`) funds type 1/2 plans from
`(net4 >> 5) + trunc(cash*0.05)`, deactivating a plan when its average category
effect is `< 41`. Type 3 stays fixed at 3500 and active. `GamePlan_Optimize`
first deactivates all non-type-3 plans.

Live effect value (`GamePlan_ComputeEffectValue` `0x50FBA0`) is V-shaped:

```text
avg < 40  -> 40 - avg
avg >= 40 -> trunc((avg - 40) * 1.8)
range 0..108, no clamp
```

Type application (`Company_ProcessHourlyTick` `0x4E0200`):

| Type | Application |
|---:|---|
| 1 | `Value_Approach(branch_value+0x10, target=effect, step=effect/36)` on **every** company branch; every 3rd hour spawn attempts for categories with effect > 60, pct `2.5*(effect-60)` |
| 2 | `Value_Approach` on the one branch; `Branch_GetPriceComparisonRating` uses the plan's category/average effect as the price-comparison component |
| 3 | no approach; `City_CollectBranchesNearPoint` adds the advertised branch as a candidate only when the category effect is `>= 51` |

`Value_Approach` suppresses the same-hour 4/hour decay when it moves; inactive
values decay 4/hour toward 0 (or rise 2/hour when negative).

The simulator creates one type-1 plan per company (`Company_ConstructDefault`
`0x4DD6B0`) and one type-2 plan per branch (`Player_AddBranchPlan` `0x4DDB80`),
then runs `allocate_menu_sales()` once per day:

```text
net4 = sum(last 4 quarterly period profits)
pool = (trunc(net4) >> 5) + trunc(cash * 0.05)
types 1/2: optimize media/flags/target, avg < 41 -> inactive
score = avg * branch_count (type 1) or avg (type 2)
allocate by max score: share = score*pool/total, capped 10000/5000
type 3: fixed 3500, stays active
```

It implements the exact hourly billing/slots, daily budget, V-shaped effect
value, type-1/type-2 approach, type-1 spawn, type-2 rating component, type-3
candidate pull, `<41` deactivation and no-expiry behavior.

`Game_GetAdjustedValue` (`0x4E4490`) widens the catchment radius:

```text
v0 = trunc(ad_value) + bonus + base_value
f  = max(0, 100 - trunc((100 - City[0xD40+owner]) / 3))
v0 = trunc(v0 * sqrt(f * 0.01))
v0 = v0 * (100 + 3*(City[0x64]+City[0x4C])) / 100
if base_value > 0 and v0 < 60: v0 = 60
return min(v0, 500)
```

Berlin: ad value 100 -> 175 radius points; 108 -> 189.

City advertising contest (`City_SettleAdvertisingCampaign` `0x4DCE70`):
`start_city_ad_campaign()` sets target category, pot `5000*(participants-1)` and
countdown `12/(participants-1)+3`; settlement awards income slot 24 to the
highest recipe skill for the category and increments `campaign_wins`.

### Trade-offer price

`Game_ComputeTradeOffers` (`0x4D5DD0`) is a City method (`this` = City; callers
pass the city returned by `IDMap_Lookup(Game+4, Game+0x2F4)`). Raw assembly
recovers the constants the decompiler dropped:

```text
base = nearbyA*0.1 + nearbyB*0.25 + 1
if special_nearby: base *= 1.75
type 2: base = 0, value = 0, type_base = 6000
otherwise: value = ((usage_count+6)*building_value)//20
           type_base = 5000/4000/3000 for type 1/3/4
price = value - trunc(base * -5000)
price = trunc(price * city[0x94])                 # KAUFPREIS*0.02
price += trunc(price * (1+(60-city_factor)*0.005))
price += trunc(type_base * city[0x94])
sell = trunc(type_base * city[0x94])
if current player and type in 1/3/4:
    price = trunc(price * mission_factor)
    sell = trunc(type_base * mission_factor)
```

`Math_RoundFloat` (`0x54F140`) sets x87 rounding to truncate toward zero, so
every `round` above is `int()`. `city_factor` is `City+0xCC8[slot]`, six ints
that default to **60** (neutral) in `City_ConstructFromName`.

Special-ID rent branch (type 1/3):

```text
type 1: ids 0x84C..0x857 -> table [300, 600, 1200], index (id-0x84C)>>2
type 3: ids 0x840..0x84B -> table [200, 400,  800], index (id-0x840)>>2
if object+0x4C == 0: no rent is offered (param_3 stays 0)
rent = trunc(table[index] * base)
rent = trunc(rent * city[0x8C])                   # MIETEN*0.02
rent += trunc(rent * (1+(60-city_factor)*0.005))
mission: free=0, half=trunc(rent*0.5), bonus=trunc(rent*1.5)
special mission fields on player[0xA8]: free +0x10C, half +0xFC, bonus +0x1E0
non-special fields: type 1 +0xC0/+0x120/+0x1A4; type 3/4 +0x15C/+0x14C/+0x230
type 2 always uses factor 1.0 (sell = type_base)
```

`City+0x8C` and `City+0x94` are not runtime leftovers: `CityDefinition_ParseIni`
(`0x4DB430`) writes the INI floats into a 0xC18-byte struct at offsets 0x88/0x90,
and `City_ConstructFromName` (`0x4D44E0`) copies that struct to `City+4`.
MIETEN/GEDULT/KAUFPREIS/EINKOMMEN/QUALITAET/KOMFORT become City+A0 floats via
`int * 0.02` (50 = neutral). Berlin: MIETEN 65 -> 1.3, KAUFPREIS 70 -> 1.4.

The simulator exposes `trade_offer_price()` (returning `buy` and `sell`) and
`special_trade_offer()`, and loads the factors from the shipped city INIs via
`CityProfile.rent_trade_factor` / `purchase_trade_factor`. Security uses the
type-2 form: `buy = trunc(6000 * KAUFPREIS*0.02)`.

### Delivery vehicles and batch price

`BuildingValue_Compute` (`0x4E2410`) computes a batch price from:

```text
base_price = Branch.supplier_base_price (supplier building[0x94])
local = product_multiplier (default 1.5)
local = (owned_count * product_scale + 1) * local
price = base_price * local * (1 - (city[0x54] + city[0x3C]) * 0.03)
city[0x54]/[0x3C] are supplied by CityProfile KAUFPREIS/EINKOMMEN
```

Mission discounts at player `+0x114/+0x1F8` multiply by 0.5/1.5.

### Vehicle convoy and delivery conflict

`Storage_OrderDelivery` (`0x514510`) starts a convoy only when:

```text
fill percent < 34%
no active vehicle targeting the supplier
supplier building is idle
storage supplier id != -1
```

`City_SpawnDeliveryVehicles` (`0x4DC1A0`):

- creates `Get_Field2C(storage) + 1` vehicles (**1..3**);
- names them `Sup_*`, attaches them to the supplier;
- initial delay for vehicle `i` = `Random_RangeFast(4,7) * i + 1` ticks;
- target field `+0x100` = storage/supplier, state `0x34`.

`Person_UpdateBehavior` case `0xC`:

```text
state 0x34: decrement vehicle[0x98]; at zero set destination mode 9 to +0x100
arrival:    Person_OnEnterBuilding type 0xC -> Storage_ProduceBatch(storage)
return:     destination mode 10 to +0xCC
```

`Storage_ProduceBatch` caps production by both
`capacity - pending_batches` and `capacity / (branch_size+1)`, so multiple
vehicles cannot overfill storage.

The simulator now models `VehicleConvoy` directly:

```text
vehicles = min(3, storage_level + 1)
delays   = (4..7)*i + 1
arrival  = delay + path_cells
conflict = existing convoy blocks a second order
settle   = each arrival calls receive_delivery; capacity caps the batch
```

The simulator:

- computes batch cost with the exact `BuildingValue_Compute` structure;
- uses supplier base price and city price/tax factors as inputs;
- processes the whole convoy **within the same hour** because 1–22 ticks ≪ 1 hour;
- keeps the configurable `delivery_delay` path for testing longer routes.

## Company AI

`CompanyAI.weekly` runs every seven days for non-player companies.

### Action-type selection

`AI_SelectActionForType` (`0x502B80`):

| Strategy type | Action |
|---:|---|
| 0 | random |
| 1 | expansion |
| 2 | strategy |
| 3 | 50% random / 50% expansion |
| 4 | 50% expansion / 50% strategy |
| 5 | 50% strategy / 50% random |
| 6 | 1/3 random / 1/3 expansion / 1/3 strategy |

### Decoded action/step tables

Tables `DAT_005726DC..DAT_005727CC` are 4 personalities × 4 choices:

```text
random actions     0,3,6,9 / 1,4,7,10 / 2,5,8,11 / 48,6,12,24
random steps       48,6,12,24 / 48,12,48,12 / 48,8,12,24 / 12,15,18,21
expansion actions  12,15,18,21 / 13,16,19,22 / 14,17,20,23 / 24,12,48,48
expansion steps    24,12,48,48 / 24,24,48,80 / 24,12,48,48 / 24,27,30,33
strategy actions   24,27,30,33 / 25,28,31,34 / 26,29,32,35 / 24,24,48,48
strategy steps     24,24,48,48 / 48,36,48,48 / 24,48,48,48 / 1,2,3,4
```

`48` is the **no-action sentinel**. `AI_InitActionPlan` (`0x502CE0`) stores the
selected action at `+0x48` and its step budget at `+0x4C`.

### Plan score and target selection

`AI_ComputePlanScores` (`0x4F7B90`) is per branch:

```text
for year = current_year-1 down to branch.first_stat_year:
    score = sum(income categories) - sum(expense categories)
    scores.append(score)            # newest year first
    total += score
```

The simulator tracks branch `year_income`, `year_expenses` and
`yearly_profit`; `Branch.plan_scores()` exposes the same newest-first list.
`CompanyAI.select_best_plan_target()` selects the branch with the lowest average
yearly profit; the rating filter is kept for strategy actions.

`AI_SelectBestPlan` (`0x4F9A20`) is the **city map layout** selector, not the
company target scorer. `Game_AssignPlanStepWeight` (`0x5012D0`) supplies the
step weights used by the simulator's action scoring:

```text
4=80, 5=20, 6=branches*20, 7=0, 8=100, 10=200, 11=40,
12=200/20, 9/13/15=20, 14=branches*5, 16/17=50, 18=10, 19..23=30
```

### Multi-step action queue

`Company_PushRecentEntry` (`0x500F40`) and `Company_ExecuteAction` (`0x5016C0`):

- up to **10** entries, newest first;
- duplicate `(action,target)` moves to the front instead of duplicating;
- default TTL = **5** ticks;
- execution result removes the entry, retries while TTL remains, or removes on expiry.

New branches use the exact setup sequence from `Player_CreateBranch`
(`0x4F7420`), pushed so they execute in this order:

```text
12 assign suppliers
 7 validate menu
 8 customer visit
10 open branch
```

`Company_ExecuteAction` action codes:

| Code | Action |
|---:|---|
| 5 | buy/rent branch |
| 7 | validate menu |
| 8 | customer visit |
| 9 | style |
| 10 | open branch |
| 11 | city tick |
| 12 | assign suppliers |
| 13 | guards |
| 16 | annoy rival |
| 17 | gangsters |
| 19 | optimize pricing |
| 20 | security |
| 21 | advancement |
| 22 | build branch |
| 23 | advertising |

The simulator implements **5, 7, 8, 10, 11, 12, 13, 16, 17, 19, 20, 21, 22
and 23**:

| Code | Simulator effect |
|---:|---|
| 11 | `City_TickBranches`: coverage charge, stalled-order cleanup, one flagged branch (2→0x10→0x20→4), 24h sales refresh; no supplier work |
| 12 | assign suppliers/storage: buy category 0 or rent category 2, expansion 1000/2000 × cost multiplier, set storage flag 8 |
| 13 | guards: `city_score/40+1` per branch, +2/+4 reserve at level 5/6; no direct ledger charge |
| 16 | annoy rival: 30-day cooldown, 50% success, −3 quality, −20% stock |
| 17 | gangsters: maintain protection staff, cost to ledger 24 |
| 20 | security: type-2 offer `trunc(6000 * City[0x94])`, `City[0x94]=KAUFPREIS*0.02` (Berlin 1.4 -> 8400) |
| 21 | advancement: avg yearly plan score ×17%, 5000 to ledger 20 |

### Action 12 — `AI_Action_AssignSuppliers` (`0x4FD190`)

Action 12 loops every branch through `AI_EnsureBranchStorage` (`0x4FD310`):

```text
no storage:
  buy (nearest house)  -> charge category 0, forced
  rent (cheapest shop) -> charge category 2, forced
  storage level = 1
storage exists:
  target = min(branchCount >> 2, 2)
  if level < target: cost = (1000 at level 0, 2000 at level 1) * mult
                     charge category 2 only if affordable
set branch flags |= 8 (supplier/storage assigned)
```

Prices come from the type-3 trade offer: rent uses the 0x840 special table
(Berlin 520), buy uses the non-special type-3 buy price (Berlin 19,600). The
supplier building choice has no contract fee; the sim exposes
`storage_mode`, `storage_rent_price`, `storage_buy_price`, `cost_multiplier`.

### Action 11 — `City_TickBranches` (`0x4FC630`)

Action 11 is a branch-maintenance dispatcher, **not** the supplier action
(supplier/storage is action 12, `AI_Action_AssignSuppliers` `0x4FD190`).

```text
A. all visible branches: City_EnsurePedestrianCoverage 0x4FD520
   if no exterminator service:
       cash <= 30000 -> tier 1, charge ledger 5: 1000
       cash >  30000 -> tier 2, charge ledger 5: 10000
B. all branches with no free type-0x1E slot:
   Game_GetBestObject(b,1,0x22) 0x47F2E0
   cancel orders with progress < 34:
       progress 0  -> charge full order price
       progress>0  -> charge price*(1-0.01*p)*0.25
   ledger 5
C. one branch, ascending, flags priority 2 -> 0x10 -> 0x20 -> 4:
   2    Branch_ValidateMenuAndRecalculate 0x4F7C30 (+ auto-tune)
   0x10 Company_OpenBranchAtSite 0x4FC0F0 menu-product creation
   0x20 Branch_AutoTunePrice 0x4FF6E0
   4    Customer_VisitBranch 0x4FB660 rebuild: refund paid orders
        (income 21), clear orders, recalc ratings; AI skips fee 9
D. Company_RefreshMenuSalesIfDue 0x4FC5F0 every 24h:
   reset recipe sales, optionally prune sales < mean/2 when policy bit set
```

The simulator exposes `sim.last_city_tick_decisions` for the per-call steps.
Calibration: cash 20,000 → 1,000; 40,000 → 10,000; progress-0 order 12,000
→ 12,000; 20% order 12,000 → 2,400; flags `0x24` run the price path, not
rebuild; a 500-paid order refunds 500 to ledger 21 on rebuild.

### Mission plan ids 24–35

`AI_InitActionPlan` (`0x502CE0`) is the **mission-goal planner**, not
`Company_ExecuteAction`. Ids 24–35 are stored as one mission-plan action id at
`+0x48` with a step budget at `+0x4C`.

`MissionGoal_Evaluate` (`0x504430`) checks these ids:

| Id | Condition |
|---:|---|
| 24 (`0x18`) | required input/building exists |
| 27 (`0x1B`) | any building rating above 0x50 |
| 28 (`0x1C`) | any building-category rating above 0x50 |
| 30 (`0x1E`) | any object stat above 0x50 |
| 32 (`0x20`) | all input/rating/category/stat checks above 0x32 |
| 33 (`0x21`) | all building-category ratings above 0x32 |

`MissionGoal_ApplyCompletionEffects` (`0x5032C0`):

| Id | Effect |
|---:|---|
| 24 | increment counter, invalidate/refresh ratings |
| 26/27 | set city company score arrays `+0xD40`/`+0xC98` to 100 |
| 30 | add a random building/facility |
| 31 | branch renovation level +1 (cap 5) |
| 32 | reset company advancement score, city factor 60 |
| 34 | record player stat |
| 35 | reward `(common_type*5+5)*20000` |

The simulator now has `MissionPlan`, `start_mission_plan()`,
`mission_condition()`, `apply_mission_reward()` and `tick_mission_plans()`.
Plans decrement their step budget weekly; unmet plans expire, satisfied plans
apply their reward and are removed.

### Implemented behaviour

```text
price: rating < competitor-5 -> *0.98; rating > competitor+5 -> *1.01
ads:   cash<0 -> stop; rating<70 and cash>60000 -> city advertising
build: cash > max(150000, construction price) and branches<4
       -> create unopened branch, charge Game_ComputePrice to ledger 3,
          enqueue supplier/menu/visit/open steps
```

The opponent AI is enabled by default; the player slot is not automated.

## Ledger categories

`StatsPeriodReport` stores **two arrays**, not one shared ledger:

- income: `+0x10 + category*4` (26 floats)
- expense: `+0x78 + category*4` (25 floats)

`Game_CanAfford` / `Game_CanAffordWithCurrency` write the expense array;
revenue records write the income array.

The finance screen labels were resolved through
`SubMenu_BuildBranchBalance` (`0x40CEE0`) and `Language_MapStrings` (`0x5146D0`).

### Expense rows

| Categories | Label |
|---|---|
| `0 + 14` | Stocks |
| `1` | Rent/Expenses |
| `2` | Construction |
| `4` | Furnishings |
| `5 + 9` | Miscellaneous |
| `11` | Training/Cure |
| `12` | Ingredients |
| `19` | Manager |

Additional expense slots used by call sites:

| # | Simulator meaning |
|---:|---|
| 3 | expansion / branch build |
| 6/7/8 | cook / service / errand wages |
| 10 | police/city |
| 15/16/17 | city / poster / restaurant advertising |
| 18 | delivery ingredients |
| 20 | quarterly bribes |
| 21 | police bribes |
| 24 | advertising campaign |

Call-site-only slots:

| # | Meaning | Evidence |
|---:|---|---|
| 3 | expansion / new branch | `AI_Action_BuildNewBranch` |
| 6/7/8 | cook / service / errand wages | `Branch_ProcessHour` |
| 9 | service fees | `Branch_ApplyProductSales`, branch open, customer visit |
| 10 | city operations/tax | `Company_ProcessDailyAccounting`, production upgrade |
| 11 | personnel | `PersonnelPlan_WindowProc` |
| 13 | training expense | `Branch_ProcessHour` |
| 16/17 | ad campaign types | `Company_ProcessHourlyTick` |
| 18 | delivery ingredients | `Branch_ProcessCustomerOrder` |
| 20 | quarterly bribes | `Game_ChargeQuarterlyBribes` |
| 21 | police bribes | `City_ChargePoliceBribes` |
| 23 | misc/admin | AI hires, gangsters, advertising plan, hourly tick |
| 24 | advertising campaign | `City_SettleAdvertisingCampaign` |

### Income rows

| Categories | Label |
|---|---|
| `0..7` | Turnover |
| `21` | Miscellaneous |
| `22` | Delivery service |
| `23` | Manager |

`Branch_ProcessCustomerOrder` books sales into turnover and ingredient cost into
category 12. The simulator now uses `earn(0, revenue)` and `charge(12, cost)`.

## Recipe composition and pricing

`Recipe_StreamConstruct` (`0x511BE0`) creates topping records of 0x1C bytes:

- `+4` ingredient index (`market_record+0xD0 - 1`)
- `+5` ingredient category
- `+6` quantity tier (0..3)
- `+8/+0xC` placement coordinates from `Ingredients.tab`

It returns `market_record[+0xAC + tier*4] * units`, and subtracts that from the
recipe ingredient budget at `+0x314`.

`Recipe_Construct` (`0x50FC20`) initializes an empty recipe, or adds **7 random
toppings** when generated (ingredient 0..85, tier 0..3, random placement).
`Recipe_LoadFromStream` (`0x5108E0`) restores the same topping list and the 86
usage counters. Stream layout:

```text
name[0x40], unit_cost f32, topping_count u32
topping[21]: ingredient,category,tier, x:i32, y:i32, variant,flag, reserved[8]
usage[86]: i32
+0x1BC[0x1C], +0x1D8[4], +0x1DC[1], optional version<0x2B byte,
+0x1E0[0x60], +0x240[0x1C], +0x264[0x80],
sales_count u32 + records[0x1C], +0x308, +0x30C
```

Stream size is `713 + 21*topping_count` (+1 when version < 0x2B): the default
7 toppings give 860 bytes, and a 3-record menu is 4 + 3*860 = 2584 bytes.
`test_recipe_stream_fuzz` round-trips 300 random recipes (0..12 toppings,
random placement/reserved bytes, both save versions) and
`test_menu_stream_fuzz` round-trips 100 random 1..6-record menus.

The simulator implements `Recipe.to_stream`, `from_stream`, `load_menu` and
`menu_to_stream`, with round-trip tests for both current and old save versions.
No shipped recipe/menu stream exists in the repository, so real-data validation
is blocked. The simulator now stores explicit `RecipeTopping` records and
computes `usage_counters()` from them.

`PlayerStats_Reset` (`0x50FEC0`) rebuilds the company's 86 counters by adding
`market_record[ingredient].quantity[tier]` for every recipe topping.

`Branch_ComputeRecipePrice` (`0x513BF0`):

```text
price = recipe_base * price_percent * 0.01 * building_value + price_offset
```

`Branch_AutoTunePrice` (`0x4FF6E0`) binary-searches `price_offset` (start step 16,
halve on direction change) against target demand = 80% of city group weights;
offset is clamped to 0..99, otherwise reset to 10.

The simulator stores `Recipe.ingredients`, `Recipe.base_price`,
`Branch.price_percent`, `Branch.price_offset`, and `Branch.building_value`.

## Order economics — `Branch_ProcessCustomerOrder` (`0x47D4A0`)

```text
servings     = min(order size, available stock)
tip          = max(0, (group_rating - customer_threshold) >> 1)
revenue      = (100 + tip) * servings * menu_price * 0.01
ingredient   = sum(batch_price * batch_qty * weighted_price / weight_sum)
market_cost  = ingredient * market_bonus
profit       = revenue - market_cost
```

The game applies `Game_CanAfford(branch, 0x13, ingredient_cost)` for
ingredients and books revenue through categories 0x0C/0x12. The simulator uses
the same revenue shape with a per-recipe unit cost.

## Accounting and ledger

`Game_CanAfford` (`0x477E40`) and `Game_CanAffordWithCurrency` (`0x4E0B60`)
debit the owning company's cash double at `+0x108` and add the amount to the
branch expense array at `+0x78 + category*4`. `Company_AddLedgerAmount`
(`0x4E0C40`) adds directly to company cash/period values.

`Branch_CloseMonth` (`0x477850`) charges monthly rent from branch `+0x14B0`,
rolls weekly/monthly statistics and resets counters.

## Headless simulator

`tools/sim_core.py` implements the model; `sim_constants.json` holds extracted
and reconstructed constants. `load_city_ini()` reads the real
`extracted/daten/<city>.ini` files: population scales traffic, MIETEN scales
rent, EINKOMMEN scales wages, QUALITAET scales branch quality, and VOLK supplies
the eight group shares.

```bash
python3 tools/sim_core.py demo --days 360
python3 tools/sim_core.py demo --days 360 --city extracted/daten/lon.ini
python3 tools/sim_core.py demo --days 90 --json
python3 tools/sim_core.py sweep --days 90
python3 tools/sim_core.py sweep --days 90 --json
```

Default scenario: one city, two companies, two branches, eight customer groups.
It produces quarterly revenue, cash, market share and ratings.

All ten shipped city INIs are cross-checked by an independent parse
(`test_all_city_ini_factors`). Derived trade values:

| City | MIETEN | KAUFPREIS | ad term | security | type-1 rent 0/1/2 |
|---|---:|---:|---:|---:|---|
| Berlin | 65 | 70 | 25 | 8400 | 780/1560/3120 |
| London | 70 | 55 | 28 | 6600 | 840/1680/3360 |
| Madrid | 50 | 45 | 13 | 5400 | 600/1200/2400 |
| Moscow | 10 | 20 | 10 | 2400 | 120/240/480 |
| Paris | 60 | 65 | 19 | 7800 | 720/1440/2880 |
| Rio de Janeiro | 45 | 50 | 10 | 6000 | 540/1080/2160 |
| Roma | 55 | 50 | 28 | 6000 | 660/1320/2640 |
| Sydney | 40 | 35 | 37 | 4200 | 480/960/1920 |
| Tokyo | 100 | 100 | 40 | 12000 | 1200/2400/4800 |
| New York | 90 | 100 | 37 | 12000 | 1080/2160/4320 |

`test_city_trade_calibration` checks monotonic rent vs MIETEN, the neutral
50 -> 1.0 mapping, and `test_city_sweep_conservation` runs all ten cities for
7 days. `samples/sim_cities_30.json` records ten 30-day runs + six scenario
sweeps per city; all conserve cash (max diff 1.9e-8).

Validation: `tests/test_sim_core.py` — **160/160 pass**:

- ratings stay in 0..100
- city adjustment, freshness, market bonus, service level
- order revenue/cost accounting
- cash conservation: `cash == start + revenue - costs`
- deterministic seed
- higher quality raises ratings and does not reduce served customers
- quarter/year rollover
- stock refill
- city INI parsing and scaling
- exact choice: threshold/radius filtering, max-score tie behavior,
  and all score-update bands
- exact hourly spawn: one walk-in per open branch-hour and one pedestrian
  every three hours
- customer conservation: served + lost + queued + traveling = spawned
- queue capacity loss
- world tick rate and same-hour arrival
- all queued parties drained within the hour
- scenario sweep revenue/rating direction

Exact vs reconstructed:

| Piece | Status |
|---|---|
| menu/price city adjustment | exact structure |
| customer-group rating | exact structure |
| market bonus | exact |
| freshness table | exact |
| service level | exact |
| order revenue/tip | exact structure |
| rent, salary, interest | exact rates where extracted |
| branch threshold/radius/score choice | exact |
| score-update bands | exact |
| hourly walk-in/pedestrian arrivals | exact |
| branch queue capacity/loss | exact structure |
| party-size formula and seat-capacity check | exact structure |
| movement cadence and 30/80-tick service | exact |
| party-size Character inputs (30..70, 18..60) | exact |
| 8-neighbour path-node count | exact grid metric |
| `PathGraph` obstacle-aware routing | exact on `.iso` graph |
| walk frame delay 12 -> 83 ms | exact |
| building weights / rating composite | exact |
| menu product/skill formulas | exact structure |
| city preference / price-level inputs | reconstructed |
| construction order price | exact structure |
| weighted-average batch price | exact |
| stock/delivery cadence | exact structure |
| quarterly market share | exact structure |

## Coverage matrix

| Subsystem | Status | Evidence |
|---|---|---|
| Hour/day/week/month/quarter pipeline | mapped | `Branch_ProcessHour`, `Branch_AdvanceWeekStatistics`, `Branch_CloseMonth`, `Game_EndOfQuarter` |
| Customer-group rating | exact structure | `Branch_GetCustomerGroupRating` |
| Menu/price rating + city adjustment | exact structure | `Branch_GetMenuRating`, `GetPriceRating`, `GetPriceComparisonRating` |
| Building score table | exact | `Rating_ComputeBuildingScore` 56-entry table |
| Rating composite | exact | `Rating_GetComposite`, `Rating_ClampAdjusted` |
| Menu product/skill formulas | exact structure | `Game_ComputeCompanyProductScore`, `Game_GetSkillRating`, `Market_ComputeValueAdjustment` |
| City preference / price-level inputs | reconstructed | simulator defaults |
| Market bonus | exact | `Game_GetMarketBonusFactor` |
| Freshness | exact table | `Product_ComputeFreshness` |
| Service level | exact | `City_ComputeServiceLevel` |
| Order revenue/tip/ingredient cost | exact structure | `Branch_ProcessCustomerOrder`, `Market_ComputeWeightedAveragePrice` |
| Rent, salary, interest | exact rates | `Branch_CloseMonth`, `Company_ProcessHourlyTick` |
| Ledger/accounting | exact primitive + finance labels | `Game_CanAfford`, `SubMenu_BuildBranchBalance`, `Language_MapStrings` |
| Stock capacity/delivery trigger | exact structure | `Storage_ProduceBatch`, `Storage_OrderDelivery` |
| Delivery timing / vehicle spawn | exact structure | `City_SpawnDeliveryVehicles`, `Person_UpdateBehavior` state 0x34 |
| Vehicle count / conflict / capacity | exact structure | `Storage_OrderDelivery`, `Storage_ProduceBatch` |
| Batch price formula | exact structure | `BuildingValue_Compute` |
| Quarterly market share | exact structure | `Game_ComputeCompanySharePercent` |
| City INI demographics/factors | exact parse | `daten/<city>.ini` |
| Customer branch choice | exact structure | `Object_IsSiteRatingSufficient`, `City_CollectBranchesNearPoint`, `Game_PickBestScoredRecord`, `Object_SyncChildState` |
| Hourly walk-in/pedestrian spawn | exact | `Branch_SpawnWalkInCustomer`, `Branch_SpawnRandomPedestrian` |
| Party-size formula / seat capacity | exact structure | `Object_UpdateCustomerQueue` (`customer+0x98`, `branch+0x1758`) |
| Party-size Character inputs | exact | `Character_Construct`, `Rating_GetComposite` |
| 8-neighbour path-node count | exact grid metric | `Map_FindShortestPath`, `Map_LinkCells`, `Grid_RebuildStreetNodes` |
| Obstacle-aware routing | exact on `.iso` graph | `PathGraph`, `Object_Compare` |
| Walk frame duration | exact | `Record_SetVariant`, `*_sma.ani` delay byte 12 |
| Customer movement/queue/interior | not simulated | `Customer_UpdateMovement`, `Object_UpdateCustomerQueue` |
| Construction order price | exact structure | `Game_ComputePrice`, `Game_ComputeCityPriceShare` |
| Weighted-average batch price | exact | `Market_ComputeWeightedAveragePrice` |
| 86-entry market table | exact | `Ingredient_LoadMarketTable`, `Size.tab`, `Game_SetBuildingDesc` |
| Advertising effects/cost | exact structure | `Branch_AddAdvertisingPlan`, `GamePlan_ComputeCategoryEffect` |
| Advertising/market share | partial | `GamePlan` effects, market functions |
| AI action selection | exact | `AI_SelectActionForType` strategy types |
| AI action/step tables | exact | `DAT_005726DC..DAT_005727CC` |
| AI plan scoring | exact | `AI_ComputePlanScores` yearly branch P&L |
| AI target scoring | exact structure | lowest yearly-profit branch |
| AI plan queue | exact | `Company_PushRecentEntry`, `Company_ExecuteAction` |
| AI multi-step execution | exact structure | all `Company_ExecuteAction` codes 5–23 implemented |
| Mission plan ids 24–35 | execution structure | `AI_InitActionPlan`, `MissionGoal_Evaluate`, `ApplyCompletionEffects` |
| Ledger category mapping | exact displayed rows; call-site slots documented | `FinanceScreen_UpdateStatement`, `SubMenu_BuildBranchBalance` |

The headless model is complete for the **economic loop**: time, ratings, demand,
orders, revenue/cost, rent, salary, interest and quarterly reporting. Spatial
customer movement, interior service and full AI remain separate layers.

## Open questions

- Exact customer-group index order (eight groups) is not proven here.
- The building-weight table and menu product/skill formulas are decoded; the
  city preference values, price levels and branch adjustment flags are simulator
  inputs.
- Customer arrival counts/groups, party-size inputs/formula, queue capacity,
  world tick rate, service timers, obstacle-aware `.iso` routing and walk
  frame duration are decoded.
- Ambient city population spawning (`City_TickSimulation`) is not fully coupled
  into the customer stream.
- `Market_ComputeWeightedAveragePrice` (`0x48C060`) is decoded; the market
  price table and per-company 86 usage counters remain simulator inputs.
- The 25 ledger slots are named, but some expenditure/revenue semantics are
  inferred from layout order and call sites.
- Day/week call wiring above `Game_EndOfQuarter` and
  `Branch_AdvanceWeekStatistics` still needs a complete call-graph pass.
