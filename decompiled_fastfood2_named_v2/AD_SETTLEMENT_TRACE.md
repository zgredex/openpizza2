# Advertising plan lifecycle & settlement — exact decode

Target: `game/fastfood2.exe`
SHA-256: `18cfd32e0ac5d6d98162ec016e058a2b51808d9ca49ebee933ce3166ff9922fd`
PE image base `0x400000`, `.text` VA `0x401000`. All addresses below are virtual addresses (VA). Raw bytes were read through the PE section table; disassembly is `objdump -d -M intel`.

Scope: the three `GamePlan` advertising types (1/2/3), their hourly billing and effect application, the per-frame zeppelin controller, and the separate city advertising-campaign settlement (`City_SettleAdvertisingCampaign`). No files were modified except this one.

---

## 0. Executive summary (what the current simulator gets wrong)

1. **Billing period is one day, not one month.** `plan+0x20` is a *daily* budget. The game charges `budget * 1/24` once per game hour (`Company_ProcessHourlyTick`, `0x4E0200`). There is **no** `/30` anywhere. `tools/sim_core.py:2048` (`monthly_cost / 24.0 / 30.0`) is 30× too cheap per hour.
2. **The ledger category is type-dependent.** Type 1 → expense slot **15**, type 2 → **16**, type 3 → **17** (`0x4E0555`, `0x4E0531`, `0x4E049C`). `sim_core.py:2049` always uses 16.
3. **35,000 is a conditional billboard-takeover fee, not a plan-creation cost.** Normal plan creation (unowned/own billboard, and the human poster start handler) charges nothing. When an AI company takes over a billboard that already carries a rival type-3 plan, `Branch_AddAdvertisingPlan` calls `Game_CanAffordWithCurrency(my_company, 0x17, old_budget*10, require_funds=1, -1)`; if the cash is sufficient, the function **deducts** `old_budget*10` and books it to expense slot **23**. For a 3,500 plan that is 35,000. `sim_core.py:2009`/`:2020` charge a flat 35,000 on every `optimize_advertising`, which is the wrong condition (and the wrong amount if the old budget is not 3,500). The `#35000$` literal at `0x566A40` is UI text; the code constant `0x88B8` at `0x4D2BEA` is a map-object market value (type 4).
4. **Plans do not expire after four weeks.** There is no timer. Removal happens only on branch deletion, company dissolution, or billboard takeover. `AdvertisingPlan.weeks_left` (`sim_core.py:710`) is never read.
5. **The marketing effect is not `min(1, average_effect/100)`.** The game stores a raw effect value in `[0, 108]` (V-shaped, `×1.8` above 40), feeds it to a lagged `Value_Approach` on the branch value record (types 1/2), and uses the *category* effect directly for the type-2 price-comparison rating and the type-3 billboard customer pull. `sim_core.py:2051` is the wrong kind of quantity and is applied instantly.
6. **Types 1 and 2 are missing from the simulator.** Every company gets a type-1 plan automatically (`Company_ConstructDefault` `0x4DD6B0`), every branch gets a type-2 plan (`Player_AddBranchPlan` `0x4DDB80`). The simulator only ever creates one type-3 plan per branch (`optimize_advertising`, `0x4FE5F0` semantics).
7. **The city advertising campaign is a separate system** (`0x4DCE70`): a city-run recipe-skill contest that *credits* ledger income slot 24 and resets. It is not a `GamePlan` charge. (The scheduler that re-arms it was not located; see §11.)

---

## 1. Function map and call order

### 1.1 Core advertising functions

| Address | Name | Role |
|---|---|---|
| `0x50FB70` | `GamePlan_SetActiveEffect` | sets `plan+0x04` active flag and recomputes `plan+0x28` effect value |
| `0x50FBA0` | `GamePlan_ComputeEffectValue` | V-shaped effect value: `40-avg` or `trunc((avg-40)*1.8)` |
| `0x50F840` | `GamePlan_ComputeAverageEffect` | sum of 8 category effects, `>> 3` |
| `0x50F870` | `GamePlan_ComputeCategoryEffect` | per-category effect, media/flags/percent/city clamp |
| `0x50FAB0` | `GamePlan_GetCompanyCategoryMetric` | metric for flag bit 1/2/4/8 |
| `0x50F7F0` | `Company_GetPercentModifier` | budget → percent (`type1: b*100/10000`, `type2: b*100/5000`, `type3: 100`) |
| `0x50F630` | `GamePlan_Construct` | 0x30-byte plan, defaults `+0x08=2`, `+0x20=0`, `+0x28=0` |
| `0x50FB40` | `Game_SetDifficulty` | sets `+0x08` and `+0x20` (1→10000, 2→5000, 3→3500) |
| `0x4FE5F0` | `GamePlan_Optimize` | deactivates non-type-3, sets budget/media/flags/target/ingredient index |
| `0x4FE870` | `Company_AllocateMenuSales` | budget pool split (recomputed per optimize action) and activation/deactivation |
| `0x4E0200` | `Company_ProcessHourlyTick` | hourly charge, effect refresh and application |
| `0x4E3AB0` | `Company_DeactivatePlanEntry` | deactivate; removes type-3 records |
| `0x5001F0` | `Branch_AddAdvertisingPlan` | AI takeover/creation of a type-3 plan on a billboard |
| `0x4C3C90` | poster page window proc (inside `0x4C3C70` blob) | human start/stop of a type-3 plan |
| `0x4C3A40` | `PosterAdvertisingPage_Update` | builds/updates the type-3 preview plan, fixed 3500 |
| `0x4C39F0` | `GamePlan_UpdateEffectBars` | 8 UI category bars, `Math_PiecewiseLinear` |
| `0x4DCE70` | `City_SettleAdvertisingCampaign` | city contest settlement, credits income slot 24 |
| `0x4DCE00` | `Game_InitCompanyAIStrategy` | initializes city contest: dish, pot, countdown |
| `0x4F26F0` | `CityAds_UpdateCampaign` | zeppelin animation/respawn; no billing |
| `0x4EAD00` | `Game_TickWorldObjects` | per-frame caller of the zeppelin controller |

### 1.2 Hourly call order

`Game_EndOfHour 0x486590` (called from `Game_WindowProc 0x4058D0`) reads the clock hour `uVar6 = byte[clock+7]` and then:

1. `City_TickSimulation(city, hour)` for every city (`0x486590`, lines 41–51).
   - This decrements the city advertising-campaign countdown and may call `City_SettleAdvertisingCampaign` (`0x4D8D50`, lines 47–54).
2. Mission state tick for six slots.
3. `Company_ProcessHourlyTick(company, hour)` for six company slots (`0x486590`, lines 61–69).
   - Within one company: for each plan with `plan+4 != 0`, `GamePlan_SetActiveEffect(plan,1,company_slot)`, then charge and apply.
   - Then `Branch_ProcessHour(pvVar3,hour)` and `Game_DecayCityDateBonus(branch_value_object)` for every branch (`0x4E0200`, lines 197–206).

So **city settlement happens before hourly company billing** in the same hour.

### 1.3 Daily / weekly / quarterly

- Hour `uVar6 == 0` → `Game_EndOfQuarter 0x4867E0` (despite the name, it is reached at hour 0, i.e. the daily boundary). It calls `Company_ProcessDailyAccounting 0x4DE760`.
- `Company_ProcessDailyAccounting` contains **no** advertising-plan charge and no ledger 15/16/17 write. Its `Game_CanAffordWithCurrency` calls are ledger 3 (`0x4DE83B`) and `Game_CanAfford` ledger 10 (`0x4DE8F8`), plus city/branch stats.
- There is no weekly or quarterly advertising billing event. All plan billing is hourly.
- `Company_OptimizeMenuPricing 0x4FE570` (the simulator calls this action 19 “optimize_pricing”) is event-driven from `Company_ExecuteAction 0x5016C0` (called at `0x4F7213` when the AI slot `+0x114 == 1`). It runs `AI_BuyUndervaluedBuildings` → `GamePlan_Optimize` for every plan → `Company_AllocateMenuSales`. It is not tied to a wall-clock hour/day by the advertising code itself.

### 1.4 Per-frame zeppelin

`Game_RenderFrame 0x485140` → `Game_TickWorldObjects 0x4EAD00` → `CityAds_UpdateCampaign 0x4F26F0` for each city object. This animates the type-1 city-advertising zeppelin and respawns it when it leaves the screen. **No ledger writes, no plan changes.**

---

## 2. Plan object layout (`GamePlan_Construct 0x50F630` + callers)

| Offset | Type | Meaning | Default |
|---|---|---|---|
| `+0x00` | ptr | vtable (`PTR_GamePlan_Delete_0055C688`) | — |
| `+0x04` | int | active flag | 0 |
| `+0x08` | int | type/difficulty: 1 city, 2 branch/poster, 3 restaurant/billboard | 2 |
| `+0x0C` | int | branch record id (`branch+0x3C`) or IDMap index | -1 |
| `+0x10` | int | media type 0..12 (0 = no media, base 40) | 0 |
| `+0x14` | int | flags bitmask 1/2/4/8 (price/menu/building/staff) | 0 |
| `+0x18` | int | advertised ingredient index + 1 (set by `GamePlan_Optimize`) | 0 |
| `+0x1C` | int | target company slot (0 is treated as “none”, see §4.5) | -1 |
| `+0x20` | int | daily budget | 0 → 10000/5000/3500 |
| `+0x24` | int | unused by this analysis | 0 |
| `+0x28` | int | effect value 0..108 | 0 |
| `+0x2C` | int | target billboard record `record+0x24` for type 3 | -1 |

Plan lists live in `company+0x12C` (IDMap), count `company+0x140`. `company+0x48` is the company slot/id. `Game_FindPlanByTarget 0x4E3510` matches `plan+0x08 == 3 && plan+0x2C == record+0x24`.

---

## 3. Lifecycle

### 3.1 Creation

**Type 1 — one per company, automatic.**
`Company_ConstructDefault 0x4DD6B0` lines 104–111:
```
plan = GamePlan_Construct(operator_new(0x30))
Game_SetDifficulty(plan,1)        // +0x08=1, +0x20=10000
List_Add(company+0x12C, plan)
```
`Game_SetDifficulty 0x50FB40`: `+0x08=1`, `+0x20=10000` (`0x50FB44`, `0x50FB64`). The plan starts inactive (`+0x04=0`). `GamePlan_Optimize` returns 0 for a type-1 plan (before choosing media/flags/target) if the company level is `<3` or it has fewer than 3 branches (`0x4FE64C`–`0x4FE67F`); the plan is deactivated at entry, though `Company_AllocateMenuSales` may later process it with the default media/flags.

**Type 2 — one per branch, automatic.**
`Player_AddBranchPlan 0x4DDB80`:
```
i = List_Add(company+0x148, branch)
plan = GamePlan_Construct(...)
Game_SetDifficulty(plan,2)        // +0x08=2, +0x20=5000
plan+0x0C = i                     // branch index
List_Add(company+0x12C, plan)
```
`Game_SetDifficulty` type 2: `+0x20=5000` (`0x50FB5A`).

**Type 3 — per billboard, AI or human.**
- AI: `AI_BuyUndervaluedBuildings 0x500070` calls `Branch_AddAdvertisingPlan 0x5001F0` for map object type `0x1B` (billboard, `0x5001F0` line 58 path).
- Human: the poster page window proc at `0x4C3C90`. The “start” branch at `0x4C4446`:
  ```
  plan = DAT_0057DA14                     // preview built by 0x4C3A40
  plan+0x20 = 3500                        // 0x4C4455
  GamePlan_SetActiveEffect(plan,1,player_slot)   // 0x4C4470
  plan+0x0C = DAT_0057DA18                // branch id, 0x4C4480
  List_Add(company+0x12C, plan)           // 0x4C44A2
  Game_PlaceObjectInPlayerCity(owner,billboard,player_slot)
  billboard_value+0x08 = 0x4B             // state 75, 0x4C44D1
  UI_QueueControlCommand(..., -0x1868E, 0x23, 1)
  ```
  The preview is built by `PosterAdvertisingPage_Update 0x4C3A40`:
  ```
  if Game_FindPlanByTarget(company,billboard) == 0:
      plan = GamePlan_Construct(...)
      Game_SetDifficulty(plan,3)          // +0x08=3, +0x20=3500
      plan+0x2C = billboard+0x24
      plan+0x0C = nearest_object+0x3C
  ```
  It is **not** added to the company list until the start handler runs.

- AI takeover/creation `Branch_AddAdvertisingPlan 0x5001F0`:
  ```
  owner = billboard+0x08
  if owner != -1:
      if owner == my_slot: return 1
      if owner != current_player_company: return 0
      old = Game_FindPlanByTarget(owner_company, billboard)
      if !Game_CanAffordWithCurrency(my_company, 0x17,
                                     old.budget * 10.0, REQUIRE_FUNDS=1, -1):
          return 0
      Object_AdjustShortPercent(game, my_slot, 0x14)   // +20 short, clamped 0..100
      Company_DeactivatePlanEntry(owner_company, old, 0)  // type 3 → removed
  plan = Game_FindPlanByTarget(my_company,billboard)
  if !plan:
      plan = GamePlan_Construct(...)
      Game_SetDifficulty(plan,3)          // 3500
      plan+0x2C = billboard+0x24
      plan+0x0C = branch_id
  GamePlan_Optimize(game, my_slot, plan)
  plan+0x20 = 3500                        // 0x50034A, redundant with SetDifficulty
  GamePlan_SetActiveEffect(plan,1,my_slot)
  List_Add(my_company+0x12C, plan)
  Game_PlaceObjectInPlayerCity(my_player,billboard,my_slot)
  Object_SetFacadeAndLogoVariant(...,1,...)
  billboard_value+0x08 = 0x4B             // 0x50038D
  ```

### 3.2 Setup / takeover cost

**Normal GamePlan creation has no setup charge.** (Map-object construction/acquisition is a separate system and was not analyzed here; the billboard record used by the plan is an existing object.) The human poster start handler (`0x4C4446`–`0x4C4525`) performs **no** cash check and **no** charge.

The only advertising-plan charge at creation time is the **billboard-takeover fee** in `Branch_AddAdvertisingPlan 0x5001F0` lines 46–52 / assembly `0x50027C`–`0x5002A4`. It applies only when the billboard's owner is the **current (human) player**, not another AI (`0x500250`–`0x50025D`), and the taking-over AI company has enough cash:
```
mov edx,[eax+0x20]        ; old plan's budget (e.g. 3500)
fild [esp+0x30]
fmul DWORD PTR ds:0x55C328 ; 10.0
push 0xFFFF ; record id
push 1      ; require sufficient cash
push amount
push 0x17   ; expense slot 23
call Game_CanAffordWithCurrency 0x4E0B60
```
`0x55C328` = raw `00 00 20 41` = **10.0f**.

`Game_CanAffordWithCurrency 0x4E0B60` is **not** a dry run. `param_3 != 0` only adds an early-out when cash is insufficient (`0x4E0B81`–`0x4E0B9A`); if the cash is sufficient, it proceeds to:
```
0x4E0BAE: fld amount
0x4E0BB2: fsubr QWORD PTR [company+0x108]     ; cash -= amount
0x4E0BBC: fstp QWORD PTR [company+0x108]
0x4E0BC2: fld amount
0x4E0BC6: fadd DWORD PTR [record+index*4+0x78] ; expense[23] += amount
0x4E0BCA: fstp DWORD PTR [record+index*4+0x78]
```
So a takeover of a 3,500 plan costs **35,000**, booked to expense slot **23** (`misc_admin`), paid by the taking-over company. If the old plan budget is 5,000, the fee is 50,000; the fee is `10 × old_budget`, not a flat constant.

The UI literal `#35000$` at `0x566A40`, referenced by `SubMenu_BuildPosterAdvertisingStatus 0x466B10` line 275, is display text consistent with the 3,500 × 10 takeover case. The only code constant `0x88B8` (35000) in the executable is `Object_SetMarketValueByType 0x4D2B90` case 4 (`0x4D2BEA`), an *object market value*, not an ad plan cost.

### 3.3 Budget handling

`plan+0x20` is a **daily** budget.

- Type 1 cap `10000` (`Game_SetDifficulty` stores it at `0x50FB64`; `Company_AllocateMenuSales` at `0x4FE917`).
- Type 2 cap `5000` (`0x50FB5A`; `0x4FE90A`).
- Type 3 fixed `3500` (`0x50FB50`; `0x50034A`; `0x4C4455`).
- Human type-1 page slider range `0..10000` (`Window_UpdateConstructionOrderPage 0x4A81F0` line 61).
- Human type-2 page slider range `0..5000` (`AdvertisingScreen_UpdatePlan 0x497180` line 60).
- Human type-3 page shows fixed `3500` (`PosterAdvertisingPage_Update 0x4C3A40` line 75).

**Dynamic reallocation (`Company_AllocateMenuSales 0x4FE870`).** Called from `Company_OptimizeMenuPricing 0x4FE570` after every `GamePlan_Optimize`. It computes a pool from company income/cash:

```
net4 = Player_ComputeNetStatTotal(company)          // 0x4E3780, 4 periods, income - cost
pool = (trunc_toward_zero(net4) >> 5)               // arithmetic shift = floor(/32)
     + trunc_toward_zero(cash * 0.05)               // 0x55C648 = 0.05 (f64)
```
Assembly: `0x4FE897` call `0x4E3780`, `0x4FE89C` call `0x54F140` (trunc), `0x4FE8A1`–`0x4FE8B2` `fmul [0x55C648]` + `fild`/`__ftol`, `0x4FE8AF` `sar ebx,5`, `0x4FE8B7` `add ebx,eax`. If `pool < 1`, the allocation loop returns without activating anything.

For each type 1/2 plan:
```
effect = GamePlan_ComputeAverageEffect(plan, owner_slot)   // 0x50F840
if effect < 41:                                            // cmp eax,0x29 ; jge keep
    deactivate (SetActiveEffect(plan,0,owner)); mark fixed
else:
    score = effect * scale
    scale = company.branch_count (type 1) or 1 (type 2)
    cap   = 10000 (type 1) or 5000 (type 2)
total_score += score
```
Assembly: `0x4FE8FA`–`0x4FE966`. Note that `plan+0x20` is first overwritten with the cap (`0x4FE924`), then the `≥41` test runs (`0x4FE92A`), so the deactivation threshold always uses `percent = 100`; the actual funded share can be lower and changes the effect afterwards.

Allocation loop (`0x4FE98A`–`0x4FEA56`):
```
while pool >= 1:
    pick the not-fixed plan with the MAXIMUM score        // 0x4FE9A0-0x4FE9C2
    mark it fixed
    if type == 1: mark every other type-1 plan with score <= selected score fixed
    if total_score < 1: stop
    share = score * pool / total_score                    // signed idiv, 0x4FEA20-0x4FEA28
    if share > cap: share = cap
    plan+0x20 = share
    SetActiveEffect(plan, share > 0, owner)               // 0x4FEA46
    pool -= share; total_score -= score
    if pool < 1: stop
```
Consequences:
- Type 1/2 budgets are **not static**; they are a share of `net4/32 + cash*0.05`.
- Type 1 funds only the highest-scoring type-1 plan; normally there is exactly one.
- Type 3 sets `fixed=1` at `0x4FE8FA` and jumps over both the budget write and the allocation loop, so it **keeps 3500** and stays active.
- `GamePlan_Optimize` deactivates all non-type-3 plans first (`0x4FE61A`–`0x4FE62D`), so this allocation is what reactivates types 1/2 each cycle.

### 3.4 Activation and effect refresh

`GamePlan_SetActiveEffect 0x50FB70`:
```
if active == 0:
    plan+0x04 = 0
    return                       // plan+0x28 is NOT cleared
plan+0x04 = active
plan+0x28 = GamePlan_ComputeEffectValue(plan, owner_slot)
```
Assembly `0x50FB78`–`0x50FB98`.

`Company_ProcessHourlyTick` calls `GamePlan_SetActiveEffect(plan,1,company_slot)` for every plan with `+0x04 != 0` **before** charging (`0x4E0454`–`0x4E045C`). So the effect value is refreshed every hour from the current branch ratings.

`Company_DeactivatePlanEntry 0x4E3AB0` calls `SetActiveEffect(plan,0,...)` at `0x4E3B37` (line 37) and leaves `+0x28` stale.

### 3.5 Hourly charge

`Company_ProcessHourlyTick 0x4E0200` lines 98–140 / assembly `0x4E0419`–`0x4E0566`.

Common constant: `0x55C588` raw `AB AA 2A 3D` = **0.0416666679084301f** = 1/24 (`0x4E0373`, `0x4E0491`, `0x4E0526`, `0x4E054C`). The product is a float32; for 3500 it is `145.83333767950535` per hour (`3500 × 0.0416666679084301`).

**Type 1** (`plan+0x08 == 1`), `0x4E0542`–`0x4E055C`:
```
Game_CanAffordWithCurrency(company, 0x0F, plan+0x20 * 1/24, 0, -1)
local_24 = company.branch_count
```
Ledger **15**, charged to the company object (`ecx=edi`).

**Type 2** (`plan+0x08 == 2`), `0x4E04B0`–`0x4E0540`:
```
budget = plan+0x20
if company is the human player's company:
    if mission+0xEC >= 1:            // “free advertising” hours
        budget = 0; mission+0xEC -= 1
    else if mission+0x1D0 > 0:       // “+50% advertising” hours
        budget = budget * 15 / 10; mission+0x1D0 -= 1
branch = IDMap_Lookup(company+0x148, plan+0x0C)
Game_CanAfford(branch, 0x10, budget * 1/24, 0, -1)
local_24 = 1
```
`budget * 15 / 10` is compiled as `(budget*3)*5 / 10` with magic `0x66666667` / `sar 2` (`0x4E04E6`–`0x4E0502`). Ledger **16**, charged to the branch's stats record. Note that `SetActiveEffect` (and therefore the effect value/percent) ran earlier in the same hour from the unmodified `plan+0x20`; the ×1.5 only increases the charge, not the effect.

**Type 3** (`plan+0x08 == 3`), `0x4E0477`–`0x4E04AB`:
```
branch = IDMap_Lookup(company+0x148, plan+0x0C)
Game_CanAfford(branch, 0x11, plan+0x20 * 1/24, 0, -1)
local_24 = 2
```
Ledger **17**, charged to the branch's stats record.

`Game_CanAfford 0x477E40` (charge path, `param_3=0`):
- `record = Stats_FindRecordByType(branch, -1)` (the branch's current stats record).
- `record[+0x78 + ledger*4] += amount` (float32).
- `player.cash (double at +0x108) -= amount` (float32), unconditionally.

`Game_CanAffordWithCurrency 0x4E0B60` (charge path):
- `record = Game_FindRecordByField4(company, stats_record_id)`.
- `record[+0x78 + slot*4] += amount`.
- `company.cash -= amount`.

There is **no affordability check** on the hourly path (`param_3=0`), so the company can go negative. This matches `Company_ProcessHourlyTick`'s later debt handling (`0x4E022E`–`0x4E026C`).

### 3.6 Effect application timing

Covered in detail in §5. In short:

- Type 1: `Value_Approach(branch_value+0x10, target=plan+0x28, step=plan+0x28/36)` for **every** branch (`0x4E05C0`–`0x4E0629`), plus customer spawn attempts only when `hour % 3 == 0` (`0x4E062B`–`0x4E06DD`).
- Type 2: `Value_Approach(branch_value+0x10, target=plan+0x28, step=plan+0x28/36)` for the one branch (`0x4E0566`–`0x4E05B2`).
- Type 3: no `Value_Approach`; effect is consumed by `City_CollectBranchesNearPoint 0x4D7ED0` via `GamePlan_ComputeCategoryEffect`.

### 3.7 Expiry / removal

There is **no time-based expiry**.

| Event | Function | Effect on plans |
|---|---|---|
| Branch removed | `Player_RemoveBranch 0x4DDC10` lines 23–32 | removes every plan whose `+0x0C == branch+0x3C`, via `Company_DeactivatePlanEntry(company, plan, 1)` |
| Company dissolved | `Company_Dissolve 0x4E3900` lines 34–41 | `Company_DeactivatePlanEntry(company, plan, 0)` for every plan: type 3 removed, types 1/2 only deactivated (the company is then deleted) |
| Billboard taken over | `Branch_AddAdvertisingPlan 0x5001F0` lines 47–54 | `Company_DeactivatePlanEntry(old_owner, old_plan, 0)`; type 3 is removed |

`Company_DeactivatePlanEntry 0x4E3AB0`:
```
if plan+0x04 != 0:
    ...
    GamePlan_SetActiveEffect(plan,0,company_slot)
if (param_2 != 0) || (plan+0x08 == 3):
    IDMap_RemoveByKey(company+0x12C, plan)
    delete plan
```
So **type 3 is always removed on deactivation**; types 1/2 survive unless `param_2 != 0` (branch removal).

---

## 4. Exact formulas and constants

### 4.1 `GamePlan_ComputeCategoryEffect 0x50F870`

Assembly references: `0x50F870`–`0x50FAA8`.

```
int ComputeCategoryEffect(plan, owner_slot, category):
    company = Game_GetPlayerBySlot(owner_slot)          // 0x50F882
    if company.branch_count (+0x15C) == 0: return 0     // 0x50F88D-0x50F89E

    bar = 40                                            // [esp+0x20] = 0x28
    if plan+0x10 != 0:                                  // 0x50F8A1
        idx = plan+0x10 * 8 + category                  // 0x50F8B4 lea edx,[ecx+eax*8]
        bar = (DAT_005730AC[idx] + 8) * 5               // 0x50F8B7 mov eax,[edx*4+0x5730ac]
                                                        // 0x50F8BE add eax,8
                                                        // 0x50F8C1 lea eax,[eax+eax*4]  (=*5)

    lower = 45; upper = 55                              // 0x50F90C / 0x50F916
    target = 0
    if plan+0x1C >= 1:                                  // <1 treated as no target
        target = Game_GetPlayerBySlot(plan+0x1C)
        if target.branch_count > 0:
            sum = 0
            for i in 0..target.branch_count-1:
                sum += GamePlan_GetCompanyCategoryMetric(plan, flag, target.branch[i],
                                                         category, flag)
            avg = sum / target.branch_count             // idiv, 0x50F960
            lower = avg - 5
            upper = avg + 5

    for bit in [1,2,4,8]:                               // 0x50F8FF loop, *2 until <0x10
        if !(plan+0x14 & bit): continue
        if plan+0x08 == 2 || plan+0x08 == 3:
            branch = IDMap_Lookup(company+0x148, plan+0x0C)     // 0x50F9C5
            own = GamePlan_GetCompanyCategoryMetric(plan, bit, branch, category, bit)
        else:
            sum = 0
            for i in 0..company.branch_count-1:
                branch = IDMap_Lookup(company+0x148, i)
                sum += GamePlan_GetCompanyCategoryMetric(plan, bit, branch, category, bit)
            own = sum / company.branch_count
        if own < lower:
            bar -= (lower - own) >> 2                   // 0x50F9F6-0x50FA01
        if own > upper:
            bar += (own - upper) >> 1                   // 0x50FA0D-0x50FA17

    pct = Company_GetPercentModifier(plan, -1)          // 0x50FA36, reads plan+0x20
    v = pct * (bar - 40) / 100 + 40                     // 0x50FA3D-0x50FA56, trunc toward zero
    city = Game_GetPlayerCity(owner_slot)               // 0x50FA5C
    v = (100 - 3*(city+0x64 + city+0x4C)) * v / 100     // 0x50FA61-0x50FA86, trunc toward zero
    if v < 0: v = 0                                     // 0x50FA89-0x50FA8D
    if v > 100: v = 100                                 // 0x50FA97-0x50FA9C
    return v
```

The `/100` is the `0x51EB851F` magic with `sar edx,5` and sign fixup (`0x50FA47`–`0x50FA56`, `0x50FA69`–`0x50FA86`). The `>>` operations are arithmetic shifts.

**City factor.** `city+0x64` and `city+0x4C` are the same two fields the simulator calls `VOLK[6]` and `VOLK[0]`: for Berlin `VOLK = [8,12,14,15,17,11,17,6]`, `17+8 = 25`, factor `100 - 3*25 = 25`.

**Flag → metric** (`GamePlan_GetCompanyCategoryMetric 0x50FAB0`):

| bit | metric | function |
|---|---|---|
| 1 | price rating | `Branch_GetPriceRating 0x4783C0` |
| 2 | menu rating | `Branch_GetMenuRating 0x478320` |
| 4 | building rating | `Branch_ComputeBuildingRating 0x478BE0` |
| 8 | average-8 | `Stats_GetAverage8 0x4787F0` |

The UI labels (`SubMenu_BuildPosterAdvertisingStatus 0x466B10`: `#Gutes Personal`, `#Schöne Einrichtung`, `#Schmackhafte Rezepte`, `#Günstige Preise`) and the button order `0x43A→bit8`, `0x43B→bit4`, `0x43C→bit2`, `0x43D→bit1` (`0x4C3A40` lines 55–58) are consistent with bit 8 = staff, 4 = furnishings, 2 = menu, 1 = price; the metric functions are the definitive part.

### 4.2 `GamePlan_ComputeAverageEffect 0x50F840`

```
sum = 0
for category in 0..7:
    sum += GamePlan_ComputeCategoryEffect(plan, owner_slot, category)
return sum >> 3          // arithmetic shift, 0x50F864 sar eax,3
```
Each term is 0..100, so this is `floor(sum/8)`.

### 4.3 `GamePlan_ComputeEffectValue 0x50FBA0`

Assembly `0x50FBA0`–`0x50FBD1`:
```
avg = GamePlan_ComputeAverageEffect(plan, owner_slot)
if avg < 40:
    return 40 - avg                       // 0x50FBCA-0x50FBD1
return trunc_toward_zero((avg - 40) * 1.8) // 0x50FBB1-0x50FBC2
```
- `0x55C690` raw `CD CC CC CC CC CC FC 3F` = **1.8** (f64).
- `0x54F140` is the CRT `__ftol`; it sets the x87 control word rounding bits to `11` (round toward zero) and executes `fistp` (`0x54F146`–`0x54F159`). It is **not** `Math_RoundFloat 0x403850`, which adds ±0.5 (`0x403865`, `0x403870`).
- No output clamp. Range: `avg=0 → 40`, `avg=39 → 1`, `avg=40 → 0`, `avg=41 → 1`, `avg=100 → 108`.
- The curve is **V-shaped**, not monotone. Callers treat the positive result as the marketing target; a low-rated branch (avg 0) gets a *larger* target (40) than a neutral branch (avg 40, target 0). This looks like a game bug; do not “correct” it if bit-exactness is the goal.

### 4.4 `Company_GetPercentModifier 0x50F7F0`

```
if param == -1: param = plan+0x20
if plan+0x08 == 1: return (param * 100) / 10000    // idiv trunc
if plan+0x08 == 2: return (param * 100) / 5000
return 100
```
Assembly `0x50F7F0`–`0x50F834`. This reads the **current** `plan+0x20`, so a budget reallocation changes the category effect next hour.

### 4.5 Target-slot quirk

`ComputeCategoryEffect` treats `plan+0x1C < 1` as “no target” (`0x50F8C8`–`0x50F8E1`). `GamePlan_Optimize` can store target slot `0` (`param_2[7]=iVar5` with `iVar5` from 0), but that value is then ignored by the effect computation. The simulator's `target_company` logic includes company 0, so it differs for that edge case.

### 4.6 Media table

`DAT_005730AC` is indexed `[media*8 + category]`, media 1..12 (`0x50F8B4`–`0x50F8B7`). The int table at `0x5730AC` is:

```
row 1  [ 6,  1, -2, -4,  2, -2, -6, -2]
row 2  [ 5,  0,  3,  5, -5, -6,  6, -4]
row 3  [ 4,  2,  0,  1, -2, -5,  0,  2]
row 4  [-6, -2,  6, -6,  6,  2,  2, -3]
row 5  [ 2,  4, -6, -3,  5,  1, -5,  0]
row 6  [ 3,  5, -4, -2,  0, -3, -4,  5]
row 7  [ 0, -4,  5,  2, -3,  4,  4, -6]
row 8  [-3, -5, -5,  4, -6,  6,  5,  3]
row 9  [ 1,  3,  2,  0,  4,  0, -2, -5]
row 10 [-2, -3,  1,  3,  1,  3,  3,  1]
row 11 [-5, -6,  4, -5,  3,  5,  1,  6]
row 12 [-4,  6, -3,  6, -4, -4, -3,  4]
```
Row 0 is not used: media 0 forces `bar = 40` (`0x50F8AC`–`0x50F8C8`). The two ints before row 1 at `0x5730AC` are `[50,100]` adjacent data, not part of the media table.

### 4.7 Recovered constants

| VA | Raw bytes | Value | Used at |
|---|---|---|---|
| `0x55C690` | `CD CC CC CC CC CC FC 3F` | `1.8` f64 | `0x50FBBC` effect value |
| `0x55C588` | `AB AA 2A 3D` | `0.0416666679084301` f32 = 1/24 | `0x4E0373`, `0x4E0491`, `0x4E0526`, `0x4E054C` |
| `0x55C578` | `1C C7 71 1C C7 71 9C 3F` | `0.027777777777777776` f64 = 1/36 | `0x4E059F`, `0x4E060F` |
| `0x55C580` | `00 00 00 00 00 00 24 C0` | `-10.0` f64 | `0x4E057B`, `0x4E05EB` |
| `0x55C328` | `00 00 20 41` | `10.0` f32 | `0x500292` takeover check |
| `0x55C648` | `9A 99 99 99 99 99 A9 3F` | `0.05` f64 | `0x4FE8A7` budget pool |
| `0x55C590` | `00 00 00 E0 4D 62 70 3F` | `0.004000000189989805` f64 | `0x4E024B` debt interest |
| `0x55C300` | `00 00 00 00 00 00 E0 3F` | `0.5` f64 | `Math_RoundFloat 0x403865/0x403870` |
| `0x55C2E4` | `00 00 00 00` | `0.0` f32 | zero compares |
| `0x51EB851F` | immediate | signed `/100` magic (`sar 5` + sign fixup) | `0x50FA47`, `0x50FA69`, `0x4E4592` |
| `0x66666667` | immediate | signed `/10` magic (`sar 2` + sign fixup) | `0x4E04EC`, `0x4E066A` |

---

## 5. How the active effect is applied

### 5.1 The value record is the branch/billboard attraction value

The branch field `branch+0x16F0` points at a map/record header; `record+0x74` is a **value record** with:
- `+0x08` int base value,
- `+0x0C` int owner slot,
- `+0x10` double animated value (this is what advertising moves),
- `+0x18` int city-event bonus,
- `+0x1C` byte dirty flag.

`Value_Approach 0x4E4670`:
```
if target > 0:
    if current >= target: return
    current += step
    if target < current: current = target
else if target < 0:
    if current <= target: return
    current += step           // moves toward 0, not away
...
dirty = 1
```
`Game_DecayCityDateBonus 0x4E46F0` runs after `Branch_ProcessHour` in the same hourly tick:
```
if dirty == 0:
    if current > 0: current = max(0, current - 4.0)
    elif current < 0: current = min(0, current + 2.0)
dirty = 0
Game_ComputeCityDateBonus(...)   // adds city-event bonus to +0x18
```
Because `Value_Approach` sets the dirty flag whenever it moves, an active plan's hourly boost **suppresses the 4/hour decay** that hour. If the current value is already at or above a positive target, `Value_Approach` returns without setting the flag, so the same-hour decay runs and the value falls by 4/hour. When the plan is deactivated, the value decays by 4/hour until 0 (or rises by 2/hour if negative).

`Game_GetAdjustedValue 0x4E4490` converts the value record to the customer-proximity radius. The decompiler drops the x87 `fsqrt`; the assembly (`0x4E4498`–`0x4E45A6`) is:

```
v0 = trunc(value+0x10) + value+0x18 + value+0x08      // 0x4E4498-0x4E44B5
if owner is the human player:
    if mission+0xC4 == 0 and mission+0x1AC != 0: v0 = 120   // 0x4E44F9-0x4E4503
    elif mission+0xC4 != 0: v0 = v0 * 15 / 10               // 0x4E44E4-0x4E44F5
if owner != -1:
    map = IDMap_Lookup(game+4, game+0x2F4)                   // 0x4E4515-0x4E4521 (current city)
    x = city[0xD40 + owner*4]                                // 0x4E4526-0x4E452E
    f = max(0, 100 - trunc((100 - x) / 3))                   // 0x4E4529-0x4E4559
    v0 = trunc(v0 * sqrt(f * 0.01))                          // 0x4E456D-0x4E457F, 0x55C418 = 0.01
    city = Game_GetPlayerCity(owner)
    v0 = v0 * (100 + 3*(city+0x64 + city+0x4C)) / 100        // 0x4E4584-0x4E45A6; Berlin ×1.75
if value+0x08 > 0 and v0 < 60: v0 = 60                       // 0x4E45A8-0x4E45B4
return min(v0, 500)                                          // 0x4E45C2-0x4E45D4
```
So the marketing double is first compressed by `sqrt(f/100)` (a diminishing-returns curve, `0x55C418 = 0.01`), then multiplied by `100 + 3*(City+0x64+City+0x4C)` (175% in Berlin), then clamped to `[60,500]` when the base value is positive. This is the radius used by `City_CollectBranchesNearPoint`; it is not a 0..1 multiplier.

`City_CollectBranchesNearPoint 0x4D7ED0` uses this radius:
```
for each object in city+0xFAC:
    if object type is 0x0F (branch) or 0x1B (billboard):
        r = Game_GetAdjustedValue(object+0x74)
        if (dx^2 + 4*dy^2) < r*r*4:
            if type == 0x1B:
                owner = Game_GetPlayerBySlot(object+0x08)
                plan = Game_FindPlanByTarget(owner, object)
                if plan+0x04 == 0: continue
                if GamePlan_ComputeCategoryEffect(plan, owner+0x48, customer_category) < 51:
                    continue
                branch = IDMap_Lookup(owner+0x148, plan+0x0C)
                add branch+0x16F0 to candidate list
            else:
                add object to candidate list
```
Assembly `0x4D7F5D`–`0x4D804F`. Threshold `0x33 = 51`.

So the effect chain is:

- **Type 1**: hourly `Value_Approach` on **all** company branches, target `plan+0x28`, step `plan+0x28/36`. This increases each branch's `Game_GetAdjustedValue` radius (and thus customer catchment). Plus every 3rd hour, customer spawn attempts.
- **Type 2**: hourly `Value_Approach` on the single branch `plan+0x0C`; additionally `Branch_GetPriceComparisonRating 0x478420` uses the plan's average/category effect as a fourth component of `Branch_GetCustomerGroupRating 0x47A3B0` (up to 25 rating points).
- **Type 3**: no `Value_Approach`. The billboard object is placed in the city; `City_CollectBranchesNearPoint` checks the plan's category effect ≥ 51 and, if so, adds the **advertised branch** to the customer's candidate list even if that branch is not itself within radius. This is the “billboard pulls customers to the restaurant” mechanic.

### 5.2 Type 1 customer spawn

`Company_ProcessHourlyTick`, `0x4E062B`–`0x4E06DD`:
```
if hour % 3 == 0 and plan+0x18 > 0:
    for category in 0..7:
        effect = GamePlan_ComputeCategoryEffect(plan, company_slot, category)
        if effect > 60 and local_24 > 0:
            pct = ((effect*5 - 300) * 5) / 10        // = (5*effect-300)/2 = 2.5*(effect-60)
            for i in 0..local_24-1:
                if Random_RangeFast(1,100) < pct:
                    city = IDMap_Lookup(game+4, game+0x2F4)
                    Player_TrackRecentEntry(city, category, plan+0x18 - 1)
```
Assembly:
- `0x4E062B` hour modulus 3.
- `0x4E063E` `plan+0x18 > 0`.
- `0x4E0656` `GamePlan_ComputeCategoryEffect`.
- `0x4E065B` `cmp eax,0x3C` (effect > 60).
- `0x4E0660` `lea eax,[eax+eax*4-0x12C]` = `5e-300`.
- `0x4E0667` `lea ecx,[eax+eax*4]` = `25e-1500`.
- `0x4E066A` magic `0x66666667`, `sar edx,2` = `/10` → `2.5e-150`.
- `0x4E069B` `cmp eax,ecx; jge skip` → spawn if random < pct.
- `Random_RangeFast 0x4034D0` returns an inclusive value in `[min,max]`; the roll is `1..100`, so `pct=100` gives a 99% spawn (roll 100 fails), not 100%.
- `local_24` is the company branch count for type 1 (`0x4E0557`: `local_24 = company+0x15C`).

`plan+0x18` is set by `GamePlan_Optimize 0x4FE5F0`:
```
weights[0x56] = 0
for each recipe record (company+0x110, count company+0x124) with byte+0x1DC != 0:
    for i in 0..0x55:
        if recipe+0x64 + i*4 > 0:
            weights[i] += trunc(game+0xA8[i]->+0xC0) * usage
find max weight index; if max > 0: plan+0x18 = index + 1
```
Assembly `0x4FE6F1`–`0x4FE750`. So `plan+0x18 - 1` is the **most valuable ingredient index**, not a customer count.

`Player_TrackRecentEntry 0x4DA810` (the name is Ghidra's; the call site passes the current city object from `game+4`/`game+0x2F4`) shifts that ingredient into a per-category 6-entry “recent choice” ring on that city object (`this+category*0x18+0xFE4`, `+0xFF8`).

### 5.3 Type 2 rating contribution

`Branch_GetPriceComparisonRating 0x478420`:
```
plan = Player_FindRecordType2ByKey(owner_company, branch+0x3C)  // plan+8==2 && plan+0xC==branchId
if !plan or plan+4 == 0: *used=0; return 0
*used = 1
if category == -1:
    v = GamePlan_ComputeAverageEffect(plan, owner_slot)
else:
    v = GamePlan_ComputeCategoryEffect(plan, owner_slot, category)
city = Game_GetPlayerCity(owner_company)
v = (100 - 3*(city+0x5C + city+0x44)) * v / 100     // second city factor
return clamp(v, 0, 100)
```
`Branch_GetCustomerGroupRating 0x47A3B0`:
```
score = avg8 + building + menu
div = 3
if price_comparison:
    price = Branch_GetPriceComparisonRating(...)
    if used:
        score += price
        div = 4
return clamp(building_score + score/div, 0, 100)
```
So an active type-2 plan adds a fourth component worth up to ~25 points of the customer group rating. Note the **second city factor** `(City+0x5C + City+0x44)` is distinct from `(City+0x64 + City+0x4C)` used inside `ComputeCategoryEffect`; its exact field semantics were not established in this pass.

### 5.4 Clamps

- Per category: `ComputeCategoryEffect` clamps the final value to `[0,100]` (`0x50FA89`–`0x50FAA1`).
- Average: no clamp, but it is `sum >> 3` of eight 0..100 values.
- Effect value: no clamp, range 0..108.
- `Value_Approach`: target not clamped; movement clamps exactly to the target.
- `Game_GetAdjustedValue`: `[60,500]` when base value `+0x08 > 0`; otherwise max 500.
- Type-3 customer pull: category effect must be `>= 51`.
- Type-1 customer spawn: category effect must be `> 60`.

### 5.5 Dead warning branch

`Company_ProcessHourlyTick` sets `bVar11 = true` if a type-1 or type-2 plan has `plan+0x28 < -10.0` (`0x4E057B` for type 2, `0x4E05EB` for type 1; the type-3 arm has no such check). `GamePlan_ComputeEffectValue` never returns a negative value, and `SetActiveEffect` refreshes `+0x28` before this check, so this warning is unreachable with values produced by `0x50FBA0` (only a loaded/corrupt save could reach it).

---

## 6. Ledger categories used at each step

The game has two separate float ledgers per company/branch:

- **Expense ledger** at record `+0x78`, 25 floats (indices 0..24). `Game_CanAfford` / `Game_CanAffordWithCurrency` write here.
- **Income ledger** at record `+0x10`, 26 floats (indices 0..25). `Company_AddLedgerAmount 0x4E0C40` writes here and adds cash.

Evidence: `Stats_SumFilteredFloats4 0x4E0AA0` sums `+0x78`; `Stats_SumFilteredFloats 0x477FE0` sums `+0x10`; `StatisticsBalance_UpdateReport 0x4AAB00` lines 68–75 computes `+0x10 - +0x78` for profit.

| Step | Function/instruction | Ledger slot | Array | Amount |
|---|---|---|---|---|
| Type 1 hourly | `0x4E0555` `push 0x0F`; `0x4E0B60` | **15** | expense `+0x78` | `plan+0x20 / 24` |
| Type 2 hourly | `0x4E0531` `push 0x10`; `0x477E40` | **16** | expense `+0x78` (branch record) | `budget / 24`, budget may be 0 or ×1.5 |
| Type 3 hourly | `0x4E049C` `push 0x11`; `0x477E40` | **17** | expense `+0x78` (branch record) | `plan+0x20 / 24` |
| City contest prize | `0x4DCF29` `push 0x18`; `0x4E0C40`; income write `0x4E0D3B` | **24** | **income** `+0x10` | `city+0x1150` |
| Takeover fee | `0x50029B` `push 0x17`; `0x4E0B60` | 23 | expense `+0x78` | 10 × old budget (35,000 for 3,500) |
| Simulator setup cost | `sim_core.py:2020` | 23 | — | charged unconditionally, not only on takeover |

Notes:
- `tools/sim_core.py` keeps one `ledger` array for both `charge` and `earn`; the game keeps expense (`+0x78`) and income (`+0x10`) separately. For the ad system, plan charges are expense 15/16/17 and the city prize is income 24; they do not collide numerically, but a single array is not a faithful model of the report.
- `Game_CanAffordWithCurrency` with `param_3=1` (`0x500285`) checks cash first, then **still charges** if sufficient (`0x4E0BAE`–`0x4E0BCA`).
- Ledger slot 25 appears in the hourly tick for a different mechanic (per-player franchise/license income via `Company_AddLedgerAmount(this,0x19,...)`, `0x4E0392`); it is an income category and not advertising.
- `Company_AddLedgerAmount` adds to cash (`0x4E0C40` lines 38–44), so slot 24 is a **credit**, not a charge. The name “advertising_campaign” in the expense-name list is misleading; it is the contest prize line.

---

## 7. City advertising campaign (`City_SettleAdvertisingCampaign 0x4DCE70`)

This is a separate city-wide contest, not a `GamePlan` type.

### 7.1 Initialization (`Game_InitCompanyAIStrategy 0x4DCE00`)

```
count = -1
for slot 0..5:
    p = Game_GetPlayerBySlot(slot)
    if p and p+0x50 == 0: count += 1
city+0x1148 = Random_RangeFast(0,7)          // target dish/ingredient category
city+0x1150 = count * 5000                   // pot
interval = 12 / count + 3                    // signed idiv
city+0x114C = interval                       // countdown
city+0x1154 = interval                       // initial countdown for progress
```
Assembly `0x4DCE0A`–`0x4DCE61`:
- `0x4DCE2C` `Random_RangeFast(0,7)`.
- `0x4DCE37` `eax=12`, `0x4DCE3D` `idiv edi` (edi = count = participants-1).
- `0x4DCE3F`–`0x4DCE4F`: `count*5*5*5*5*8 = 5000*count`.
- `0x4DCE58` `add eax,3`; store at `+0x114C` and `+0x1154`.

If only one participant is present (`count == 0`), `idiv` divides by zero; if none, `count == -1` gives `12/-1+3 = -9`. Callers must guarantee at least two participants. **No direct call site for `0x4DCE00` was found in the analyzed callgraph or raw `call` scan**; it is likely invoked through a script/vtable, so the repeat cadence after a settlement is not established.

### 7.2 Countdown and settlement

`City_TickSimulation 0x4D8D50` lines 47–54 runs once per game hour per city:
```
if city+0x114C > 0:
    city+0x114C -= 1
    if city+0x114C == 0:
        City_SettleAdvertisingCampaign(city)
        UI_QueueControlCommand(..., -0x1860D, 0x23, 0)
```
So the contest lasts `12/(participants-1)+3` hours.

`City_SettleAdvertisingCampaign 0x4DCE70`:
```
winner_slot = -1; best = 0
for slot 0..5:
    p = Game_GetPlayerBySlot(slot)
    if p and (p+0x50 == 0 or p == selected_player):
        if p+0x1D4 != 0:
            Recipe_RecomputeAllStats(p+0x1D4, p+0x48)
            score = Game_MapInputIndex(p+0x1D4, city+0x1148)
        else: score = 0
        if score > best: best = score; winner_slot = p+0x48
winner = Game_GetPlayerBySlot(winner_slot)
winner+0x54 += 1                              // campaign wins counter
Company_AddLedgerAmount(winner, 0x18, (float)city+0x1150, -1, 0)  // CREDIT
if winner == selected_player:
    UI_AppendCommandIfActive(...,0x13,-1)
    MissionGoal_HandleEvent(...,0x13,-1,-1)
create Player_Event, List_Add(city+0x8C, event)
UI_Briefing_Printf(... winner name ...)
city+0x1148 = 0; city+0x114C = 0; city+0x1150 = 0; city+0x1154 = 0
for slot 0..5: player+0x50 = -1
```
Assembly:
- Winner max selection `0x4DCEAB`–`0x4DCEF8`; strict `>` so first max wins.
- Score: `0x4DCED4` `Recipe_RecomputeAllStats`, `0x4DCEE6` `Game_MapInputIndex 0x5104D0`.
- `0x4DCF16` `winner+0x54++`.
- `0x4DCF20` `fild [city+0x1150]`; `0x4DCF29` `push 0x18`; `0x4DCF2B` `call Company_AddLedgerAmount`.
- Reset at `0x4DCFFA` (`+0x1148`), `0x4DD000` (`+0x114C`), `0x4DD006` (`+0x1150`), `0x4DD00C` (`+0x1154`).

`Game_MapInputIndex 0x5104D0` maps dish index `8→5` and calls `Index_Map8To5 0x513980`, which returns the recipe's skill rating at `recipe+0x2C4+index*4` clamped `[0,100]`.

**This is a recipe-quality contest, not an advertising-spend contest.** The prize is `5000 × (participants-1)`, paid as income slot 24; the winner's `+0x54` counter increments. The pot is city-funded; no player is charged here.

### 7.3 Relation to the zeppelin

`CityAds_UpdateCampaign 0x4F26F0` is only the visual controller:
- Iterates city objects at `city+0xBC` with `Object_UpdateWalkStep` (`0x4F26F0` lines 37–43).
- For city type `0x40`, for each of 6 player slots, checks the player's zeppelin record id at `world+0x2C41C+slot*4` (`0x4F26F0` lines 45–51).
- When the zeppelin leaves the city rect, `Record_ClearFlags48`, sets variant `-1`, finds the owner, and calls `Map_SpawnAdvertisingZeppelin` only if `Player_GetFirstRecordType1(owner)` exists and `plan+4 != 0` (`0x4F26F0` lines 77–91; `Player_GetFirstRecordType1 0x4E34E0`).
- `Map_SpawnAdvertisingZeppelin 0x4DC760` picks a random screen edge and sets the record rect/variant.
- No ledger, no plan mutation. Type-1 only.

---

## 8. UI effect bars (`GamePlan_UpdateEffectBars 0x4C39F0`)

```
for category in 0..7:
    v = GamePlan_ComputeCategoryEffect(DAT_0057DA14, company+0x48, category)
    v = Math_PiecewiseLinear(v)
    Rating_UpdateBarByKey(window, 0x509, category, v, DAT_00582858)
```
Assembly `0x4C39F0`–`0x4C3A38`; the plan pointer is the global `DAT_0057DA14` (the poster-page preview plan), not `param_2`.

`Math_PiecewiseLinear 0x50FBE0`:
```
if v < 50: return v * 18 / 25        // 0..35
return (v - 50) * 32 / 25 + 36       // 36..100
```
`Rating_UpdateBarByKey 0x4A80E0` clamps the value to 0..100 and maps it to one of 17 bar children (`(v*16+50)/100`).

Berlin media 0: category 10 → bar `10*18/25 = 7`.
Berlin media 1: `[17,11,7,5,12,7,2,7]` → `[12,7,5,3,8,5,1,5]`.

---

## 9. Precise diff against `tools/sim_core.py`

### 9.1 `_update_advertising` (lines 2037–2051)

Current:
```python
def _update_advertising(self):
    for b in self.branches:
        effect = 0
        company = self.companies[b.company_id]
        for plan in list(b.ad_plans):
            target_company = next(
                (c for c in self.companies if c.id == plan.target), None)
            effect = max(effect, plan_average_effect(
                plan.plan_type, plan.media_type, plan.flags, company,
                b, target_company, self.city.ad_city_term,
                plan.percent))
            monthly = plan.monthly_cost / 24.0 / 30.0
            self.companies[b.company_id].charge(16, monthly)
            b.record_expense(monthly)
        b.marketing = min(1.0, effect / 100.0)
```

Exact problems:

| Line | Current | Game |
|---|---|---|
| 2044–2047 | one `effect` per branch, `max` over plans | type-dependent: type 1 applies to all branches; type 2 to one branch; type 3 to a billboard target |
| 2048 | `monthly_cost / 24.0 / 30.0` | `plan_budget / 24.0` (float32 1/24 constant); no `/30` |
| 2049 | always `charge(16, ...)` | type 1 → 15, type 2 → 16, type 3 → 17 |
| 2049 | charges every plan every hour | game charges only `plan+4 != 0`; type 2 may be 0 or ×1.5 under mission bonuses |
| 2050 | `b.record_expense(monthly)` | branch expense record is `+0x78`; the game also adds to the branch stats record, not just a scalar |
| 2051 | `marketing = min(1, effect/100)` instantly | game stores raw effect value 0..108, ramps via `Value_Approach` at `effect/36` per hour, suppresses decay while active, and decays 4/h when inactive |
| 2044 | `plan.percent` fixed at creation | game reads `plan+0x20` each hour via `Company_GetPercentModifier`, so budget reallocation changes the effect |
| 2044 | includes target company 0 | game treats `plan+0x1C < 1` as no target |
| — | no type-1 customer spawn | game spawns every 3 hours if category effect >60, with pct `2.5*(effect-60)` |
| — | no type-2 price-comparison rating | game `Branch_GetPriceComparisonRating 0x478420` adds up to ~25 points |
| — | no type-3 billboard pull | game `City_CollectBranchesNearPoint 0x4D7ED0` requires category effect ≥51 |

### 9.2 `optimize_advertising` (lines 1999–2012)

Current:
```python
self.add_advertising(
    branch, media_type=plan["media_type"],
    category=plan["category"],
    monthly_cost=plan["budget"], setup_cost=35000, weeks=4,
    plan_type=plan["plan_type"], flags=plan["flags"],
    target=plan["target"], percent=plan["percent"])
```

| Line | Current | Game |
|---|---|---|
| 2009 | `monthly_cost=plan["budget"]` | budget is **daily**, not monthly |
| 2009 | `setup_cost=35000` | only a conditional rival-billboard takeover fee (`10 × old_budget`, slot 23); normal creation costs nothing |
| 2009 | `weeks=4` | no duration; plans persist |
| 2009 | one plan per branch, type 3 | game has automatic type 1 (company) and type 2 (branch); type 3 only for billboards |
| 2011 | `percent=plan["percent"]` | game recomputes percent from current budget each hour |

### 9.3 `add_advertising` (lines 2014–2022)

Current:
```python
def add_advertising(self, branch, media_type=1, category=0,
                    monthly_cost=3500.0, setup_cost=35000.0, weeks=4,
                    plan_type=3, flags=0, target=-1, percent=100):
    plan = AdvertisingPlan(media_type, category, monthly_cost,
                           setup_cost, weeks, plan_type, flags,
                           target, percent)
    self.companies[branch.company_id].charge(23, setup_cost)
    branch.ad_plans.append(plan)
    return plan
```
- Line 2020: `charge(23, setup_cost)` has a game equivalent **only in the rival-billboard takeover path** (`0x50029B`, amount `10 × old_budget`, not a flat 35,000). It must not run on ordinary plan creation; the human start handler charges nothing. Move it to a `takeover_cost` field/event.
- `AdvertisingPlan` (lines 704–714) should not carry `setup_cost`/`weeks_left`; add `daily_budget`, `active`, `effect_value`, `ingredient_index`, `target_record`, and a separate `takeover_fee` if the AI takeover is modeled.

### 9.4 `tick_hour` legacy company-level advertising (lines 2183–2194)

```python
if c.marketing_budget:
    hourly_ad = c.marketing_budget / 24.0 / 30.0
    c.charge(16, hourly_ad)
    ...
for b in c.branches:
    b.marketing = min(1.0, c.marketing_budget / 5000.0)
```
This is a second, conflicting advertising model:
- Same `/24/30` error.
- Always ledger 16.
- Its `b.marketing` assignment is immediately overwritten by `_update_advertising` (line 2195 calls it after line 2194).
- Has no game counterpart (`marketing_budget` is a simulator-only field, `sim_core.py:1258`).
Either delete it or redirect it to the type-1 plan budget; do not keep both.

### 9.5 `plan_average_effect` / `advertising_effect`

- `plan_average_effect` (lines 861–893) reproduces `ComputeCategoryEffect` + `ComputeAverageEffect` reasonably: per-category media, flags, target-company average bounds, percent, city term, clamp. It does **not** implement `ComputeEffectValue` (the V-shaped 1.8 conversion) or the `plan+0x1C < 1` quirk.
- `advertising_effect` (lines 823–844) defaults `city_term=100`; for Berlin it must be 25. It also uses the `competitor` metric for both bounds when no `competitor_metric` is supplied, whereas the game uses the target company's branch average (or 45/55 if none).
- `company_percent_modifier` (lines 814–820) is correct.
- `AD_WEIGHTS` (lines 717–732) matches rows 1..12; row 0 is unused in the game (media 0 = 40).

### 9.6 Missing structures / events

- No automatic type-1 plan per company (`Company_ConstructDefault 0x4DD6B0`).
- No automatic type-2 plan per branch (`Player_AddBranchPlan 0x4DDB80`).
- No `Company_AllocateMenuSales` pool `(net4>>5) + cash*0.05`, no score/cap/share, no deactivation at average effect <41.
- No `GamePlan_Optimize` `plan+0x18` ingredient index (most valuable ingredient).
- No removal on branch deletion / company dissolution / billboard takeover.
- No city contest settlement (`0x4DCE70`) and no income slot 24.
- No `Value_Approach` lag/decay or `Game_GetAdjustedValue` radius.
- No type-1 customer spawn, no type-2 rating component, no type-3 billboard threshold.

### 9.7 Suggested minimal correction (not applied)

If the goal is only to fix billing while keeping the current architecture:

1. Rename `monthly_cost` → `daily_budget`; in `_update_advertising` charge `plan.daily_budget / 24.0` per hour.
2. Pick the ledger by `plan.plan_type`: `{1:15, 2:16, 3:17}[plan.plan_type]`.
3. Remove the unconditional 35,000 `charge(23, setup_cost)` and `weeks=4`; keep plans until an explicit removal trigger. If the AI takeover is modeled, charge `10 × old_budget` to slot 23 only on that event.
4. Replace `marketing = min(1, effect/100)` with a stored `effect_value = 40-avg if avg<40 else int((avg-40)*1.8)` and a lagged value `marketing += effect_value/36` (cap at effect_value; decay 4/h when inactive).
5. For type 3, compute the category effect for the customer's group and only add the branch when it is ≥51; do not treat it as a general marketing multiplier.
6. Remove or redirect the legacy `marketing_budget` path in `tick_hour`.

---

## 10. Berlin type-3 calibration (budget 3500, media 0/1, flags 0)

Berlin `ber.ini`: `VOLK = [8,12,14,15,17,11,17,6]`, `MIETEN=65`, `KAUFPREIS=70`.
`ad_city_term = 100 - 3*(VOLK[6] + VOLK[0]) = 100 - 3*(17+8) = 25`.
Type 3 → `Company_GetPercentModifier` returns 100 (`0x50F7F0`).
Flags 0 → no metric adjustments and no target block.

| media | per-category effect (cat 0..7) | sum | avg (`>>3`) | effect value (`0x50FBA0`) | hourly charge | daily total |
|---|---|---|---|---|---|---|
| 0 | `[10,10,10,10,10,10,10,10]` | 80 | 10 | `40-10 = 30` | `3500*0.0416666679 = 145.8333377` | 3500.0001 |
| 1 | `[17,11,7,5,12,7,2,7]` | 68 | 8 | `40-8 = 32` | `145.8333377` | 3500.0001 |

Details:
- media 0: `bar=40`, `pct=100`, `25*40/100 = 10` per category.
- media 1 weights `[6,1,-2,-4,2,-2,-6,-2]` → `(w+8)*5 = [70,45,30,20,50,30,10,30]` → `25*bar/100 = [17,11,7,5,12,7,2,7]`.
- The float32 1/24 constant gives `145.83333767950535` per hour; after 24 charges `3500.0001043`. A Python `/24` implementation gives `145.8333333`; use the float32 constant if bit-exact cash drift matters.
- Ledger **17**, charged to the branch's stats record (`Game_CanAfford`), company cash deducted.
- If an AI company takes this plan's billboard from the human, the takeover fee is `10 × 3500 = 35,000` (expense slot 23, `0x500292`); ordinary creation and the human start handler charge 0.
- Effect value is stored at `plan+0x28` but **type 3 does not call `Value_Approach`**. The only demand path is `City_CollectBranchesNearPoint 0x4D7ED0`, which requires `GamePlan_ComputeCategoryEffect(...) >= 51`. For Berlin the maximum category effect is 17 (media 1) or 10 (media 0), both **below 51**. Therefore a Berlin type-3 plan with media 0/1 and flags 0 is **invisible to the customer-pull logic**: it charges 3500/day and produces no billboard attraction. This is a calibration fact, not a simulator choice.
- If the same plan were type 1/2 (hypothetical, for comparison): effect 30/32, below the type-1 spawn threshold 60, so no customer spawns; `Value_Approach` would still raise the branch value by 30/36 = 0.833/h or 32/36 = 0.889/h toward 30/32.
- Effect bars: media 0 → all `7`; media 1 → `[12,7,5,3,8,5,1,5]` (`Math_PiecewiseLinear 0x50FBE0`).

A type-3 plan becomes meaningful only when `100 - 3*(City+0x64+City+0x4C) >= 51` (i.e. when the two city fields sum to ≤16), because the 51 threshold is applied *after* the city factor.

---

## 11. Unresolved / limitations

1. **`Game_InitCompanyAIStrategy 0x4DCE00` call site.** No direct `call 0x4DCE00` appears in the raw call scan or callgraph. The repeat cadence of the city contest after a settlement is therefore not established. The fields are initialized as decoded, but the scheduler that re-arms them is outside this analysis.
2. **`City+0x5C` and `City+0x44`.** `Branch_GetMenuRating 0x478320` and `Branch_GetPriceComparisonRating 0x478420` apply `100 - 3*(City+0x5C + City+0x44)`. `City+0x5C` is consistent with `VOLK[4]` if the array starts at `City+0x4C`; `City+0x44` is an earlier header field whose name was not established. The type-2 rating calibration therefore stops at the category effect.
3. **First zeppelin spawn.** `Map_SpawnAdvertisingZeppelin 0x4DC760` is only called from `CityAds_UpdateCampaign 0x4F26F0`; the initial spawn when a type-1 plan starts was not located. The per-frame controller only respawns an existing record.
4. **Exact consumer of the value record `+0x10` double.** `Game_GetAdjustedValue 0x4E4490` and `City_CollectBranchesNearPoint 0x4D7ED0` use it for the customer radius; a direct branch-rating consumer was not separately traced. The radius use is sufficient to establish the demand effect.
5. **`player+0x50` semantics in the city contest.** It is reset to `-1` at settlement and counted as `==0` during initialization; the exact UI meaning (“entered”, “alive”, “campaign slot”) was not decoded.
6. **35,000 is not a flat setup cost.** The takeover path charges `10 × old_budget` (35,000 for 3,500) to expense slot 23 when the AI company can afford it and the billboard is owned by the current player. Ordinary creation and the human poster start handler charge nothing. The only code constant 35,000 is `Object_SetMarketValueByType` case 4 (`0x4D2BEA`); the `#35000$` literal at `0x566A40` is UI text consistent with the 3,500 × 10 takeover case.

---

## 12. Evidence index (primary files)

- `decompiled_fastfood2_named_v2/full_game_verification/functions/0x50fb70.c` — `GamePlan_SetActiveEffect`
- `.../0x50fba0.c` — `GamePlan_ComputeEffectValue`
- `.../0x50f840.c` — `GamePlan_ComputeAverageEffect`
- `.../0x50f870.c` — `GamePlan_ComputeCategoryEffect`
- `.../0x50fab0.c` — `GamePlan_GetCompanyCategoryMetric`
- `.../0x50f7f0.c` — `Company_GetPercentModifier`
- `.../0x50f630.c` — `GamePlan_Construct`
- `.../0x50fb40.c` — `Game_SetDifficulty`
- `.../0x4fe5f0.c` — `GamePlan_Optimize`
- `.../0x4fe870.c` — `Company_AllocateMenuSales`
- `.../0x4e0200.c` — `Company_ProcessHourlyTick`
- `.../0x4e3ab0.c` — `Company_DeactivatePlanEntry`
- `.../0x5001f0.c` — `Branch_AddAdvertisingPlan`
- `.../0x4c3a40.c` — `PosterAdvertisingPage_Update`
- `.../0x4c39f0.c` — `GamePlan_UpdateEffectBars`
- `.../0x4dce70.c` — `City_SettleAdvertisingCampaign`
- `.../0x4dce00.c` — `Game_InitCompanyAIStrategy`
- `.../0x4f26f0.c` — `CityAds_UpdateCampaign`
- `.../0x4ead00.c` — `Game_TickWorldObjects`
- `.../0x4d8d50.c` — `City_TickSimulation`
- `.../0x486590.c` — `Game_EndOfHour`
- `.../0x4867e0.c` — `Game_EndOfQuarter`
- `.../0x478420.c` — `Branch_GetPriceComparisonRating`
- `.../0x47a3b0.c` — `Branch_GetCustomerGroupRating`
- `.../0x4d7ed0.c` — `City_CollectBranchesNearPoint`
- `.../0x4e4670.c` — `Value_Approach`
- `.../0x4e46f0.c` — `Game_DecayCityDateBonus`
- `.../0x4e4490.c` — `Game_GetAdjustedValue`
- `.../0x4e0c40.c` — `Company_AddLedgerAmount`
- `.../0x4e0b60.c` — `Game_CanAffordWithCurrency`
- `.../0x477e40.c` — `Game_CanAfford`
- `.../0x54f140.c` — `__ftol` (round-toward-zero control word)
- `.../0x403850.c` — `Math_RoundFloat` (adds ±0.5)
- `.../0x5104d0.c`, `.../0x513980.c` — city contest score
- `.../0x50fbe0.c` — `Math_PiecewiseLinear`
- `.../0x4a80e0.c` — `Rating_UpdateBarByKey`

Additional raw evidence:
- `objdump -d -M intel game/fastfood2.exe` at the addresses cited in §4.7 and §5–§7.
- `decompiled_fastfood2_named_v2/sim_constants.json` lines 113–122 for the ledger-name mapping (15/16/17/24), consistent with the immediate pushes in §6.
- `tests/test_sim_core.py` lines 1057–1062 currently assert the same ledger names; those assertions are correct, but the charge path they test is not the game's array/period.
