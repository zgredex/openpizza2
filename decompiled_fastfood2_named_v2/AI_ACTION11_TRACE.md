# Company AI action 11 — exact decode (`City_TickBranches`)

**Target:** `game/fastfood2.exe`
**SHA-256:** `18cfd32e0ac5d6d98162ec016e058a2b51808d9ca49ebee933ce3166ff9922fd`
**Action id:** decimal `11` = `0x0B` in `Company_ExecuteAction` (`0x5016C0`)
**Primary function:** `City_TickBranches` (`0x4FC630`)

This report closes the action-11 chain from the dispatcher down through every direct
callee, including the two paths (coverage and stalled-construction cleanup) that run
for every branch and the four flag-gated per-branch paths.

> **Main finding.** Action 11 is a per-company **branch-maintenance dispatcher**
> that includes price, rating and staff paths. It is **not** the supplier action:
>
> * all branches: pest-control / pedestrian coverage + stalled-construction cleanup;
> * at most **one** branch: one of `flag 2` menu/staff validation, `flag 0x10` menu
>   product creation, `flag 0x20` price auto-tune, or `flag 4` branch rebuild;
> * the acting company: a 24-hour menu-sales refresh.
>
> Supplier/storage/contract work is **action 12** (`AI_Action_AssignSuppliers`,
> `0x4FD190`). The simulator's action-11 supplier flip is therefore a control-flow
> error, not a calibration error. Details in §12 and §14.

Notation: `0x4FC630/0x4FC6BA` means function `0x4FC630`, instruction `0x4FC6BA`.
Decompiled sources are under
`decompiled_fastfood2_named_v2/full_game_verification/functions/0x<addr>.c`.
The symbol names used below are from `decompiled_fastfood2_named_v2/full_game_symbols.json`;
the raw bytes are authoritative and every formula below was checked against the
disassembly.

---

## 1. Dispatcher proof — action 11 → `0x4FC630`

`Company_ExecuteAction` reads the action code at `0x50170F`:

```asm
50170f  mov edx, [esi + eax*8 + 0x80]   ; action code, company slot stride 0x168
...
50177a  dec eax
50177b  cmp eax, 0x16                  ; action-1 <= 0x16
501784  jmp [eax*4 + 0x501900]         ; 23-entry jump table
```

The table at `0x501900` (verified by dumping `.text`):

| Action | Table entry | Target | Callee |
|---:|---|---:|---|
| 10 (`0x0A`) | `0x501924` | `0x5017CE` | `Company_OpenBranchAtSite` `0x4FC0F0` |
| **11 (`0x0B`)** | **`0x501928`** | **`0x5017D9`** | **`City_TickBranches` `0x4FC630`** |
| 12 (`0x0C`) | `0x50192C` | `0x5017E3` | `AI_Action_AssignSuppliers` `0x4FD190` |

The action-11 block is:

```asm
5017d9  push edi                     ; company index (uVar4, not the action id)
5017da  mov  ecx, esi                ; company manager / 0x168-stride slot array
5017dc  call 0x4fc630
5017e1  jmp  0x50184a
```

`City_TickBranches(this, companyIndex)` therefore receives the company index, **not**
the queue target (`slot+0x74`). The target is used only by the queue-removal step.

Return value: `City_TickBranches` always returns `1` (`0x4FC713`).
`Company_ExecuteAction` then dispatches result `1` through the second table at
`0x50195C`; index 1 → `0x501892`:

```asm
501892  ...
50189f  call 0x501040                ; UI_RemoveListEntryByType
```

`UI_RemoveListEntryByType` (`0x501040`) scans the 10-entry queue at
`slot+0x74`, stride `0x10`, and removes the first entry whose
`entry+0xC == action` and `entry+0 == target` (`0x501079`, `0x50107E`).
Thus **one queued action-11 entry is consumed per invocation**, even if no branch
had a pending flag.

Plan weight: `Game_AssignPlanStepWeight` (`0x5012D0`) maps action 11 through
table `0x50152C` to `0x501422`, which writes `0x28` (=40) into `plan+4`;
the simulator's `plan_step_weight` 40 is correct.

Queue mechanics: `Company_PushRecentEntry` (`0x500F40`) keeps 10 entries of
`0x10` bytes, default TTL 5 (`0x500F40/0x500F55`, `0x500F95`), and shifts the
old first nine entries down by `0x90` bytes (`0x500F95`). `City_TickBranches`
returns 1, so the TTL is irrelevant for action 11 (result-3 is the only TTL
decrement path; `0x5018CA`).

---

## 2. Function map

| Address | Symbol | Role in action 11 |
|---:|---|---|
| `0x5016C0` | `Company_ExecuteAction` | dispatch, profiler, queue removal |
| **`0x4FC630`** | **`City_TickBranches`** | **action-11 body** |
| `0x4FD520` | `City_EnsurePedestrianCoverage` | every tick, all branches |
| `0x4D5250` | `Branch_HireExterminator` | coverage charge + service object |
| `0x47F2E0` | `Game_GetBestObject` | stalled-construction cleanup |
| `0x47F230` | `Game_ComputeCityPriceShare` | cleanup value |
| `0x4E4060` | `Game_ComputePrice` | object/order base price |
| `0x4D2AE0` | `Game_CountFreeBuildingsByType` | building-slot tests |
| `0x47FED0` | `Game_CountFreeResidentialBuildings` | residential test (types `0x1A/0x1B/0x1C`) |
| `0x48A130` | `Game_CountFilteredObjects` | duplicate-service test |
| `0x4F7C30` | `Branch_ValidateMenuAndRecalculate` | flag 2 |
| `0x47AAC0` | `Game_CountObjectsByType` | staff counts |
| `0x4F7B50` | `Branch_RemoveAllStaff` | fire all staff |
| `0x4F8D40` | `Branch_AssignEntranceAndCustomerSlots` | staff/customer-slot layout |
| `0x47EC70` | `Game_ToggleObjectFlag2` | re-arm/clear staff flag |
| `0x4805D0` | `Stats_ResetAverages` | reset staff averages |
| `0x4FC0F0` | `Company_OpenBranchAtSite` | flag `0x10` menu-product creation |
| `0x510C90` | `Recipe_CreateGenerated` | product creation |
| `0x4E0E90` | `Game_SelectLeastUsedCategory` | product category choice |
| `0x4DDDE0` | `Game_CountActiveCompanies` | **actually active recipe count** |
| `0x4DDE30` | `Game_GetActiveCompanyById` | **actually active recipe by index** |
| `0x4E3460` | `Recipe_SetOnMenu` | add/remove product |
| `0x477BD0` | `Branch_SetAssignedEmployee` | set `branch+0x14DC` = recipe, clear flag 0x20 |
| `0x4FF6E0` | `Branch_AutoTunePrice` | flag `0x20` |
| `0x47A3B0` | `Branch_GetCustomerGroupRating` | auto-tune rating |
| `0x478320` | `Branch_GetMenuRating` | menu-rating cache |
| `0x4784E0` | `Branch_RecomputeMenuPriceRatings` | price competitiveness |
| `0x478DB0` | `Branch_RecalculateRatings` | flag 4 rating rebuild |
| `0x4FB660` | `Customer_VisitBranch` | flag 4 branch rebuild (misnamed; see §6.4) |
| `0x4FB170` | `CityMap_GenerateLayout` | map/interior layout generation |
| `0x4FB600` | `Stats_SumRecordCounts` | pending-object cost sums |
| `0x4FBEE0` | `Map_CommitPendingObjectEdits` | commit construction orders |
| `0x47C5E0` | `Branch_ClearInteriorObjects` | clear orders + refund |
| `0x477C80` | `Stats_AddRecordValue` | income/refund booking |
| `0x477E40` | `Game_CanAfford` | expense booking |
| `0x4FC5F0` | `Company_RefreshMenuSalesIfDue` | 24-hour gate |
| `0x4FC470` | `Game_RecomputeCompanyMenuSales` | per-recipe sales + pruning |
| `0x4E1B80` | `Game_ResetRecordTurnCounters` | zero recipe sales |
| `0x5100B0` | `Stats_SumMaskedMapFloats` | sum sales records |
| `0x4E1BC0` | `Company_CollectUnprofitableBranches` | **actually low-selling recipes** |
| `0x489B10` | `Game_GetDateField0C` | current clock hour |
| `0x486590` | `Game_EndOfHour` | increments clock `+0xC` once per hour |
| `0x501040` | `UI_RemoveListEntryByType` | consume queue entry |

---

## 3. Top-level control flow

`City_TickBranches` (`0x4FC630`), exact order:

```text
count = Company[company].branchCount;                 // 0x4FC642/0x4FC646, +0x15C
City_EnsurePedestrianCoverage(this, company);         // 0x4FC652

for i = 0 .. count-1:                                 // 0x4FC65D..0x4FC69A
    b = Game_GetPlayerSubrecord(this, company, i, 1);
    if b != 0
       and b.site != 0                                // b+0x16F0
       and Game_CountFreeBuildingsByType(b.site,0x1E) == 0:
        Game_GetBestObject(b, 1, 0x22, &discard);     // 0x4FC68E

for i = 0 .. count-1:                                 // 0x4FC6A4..0x4FC6D4
    b = Game_GetPlayerSubrecord(this, company, i, 1);
    if b != 0 and b.state(+0x2C) == 0:
        if b.flags(+0x28) & 0x02: Branch_ValidateMenuAndRecalculate(b); break;
        if b.flags(+0x28) & 0x10: Company_OpenBranchAtSite(this,company,b); break;
        if b.flags(+0x28) & 0x20: Branch_AutoTunePrice(b); break;
        if b.flags(+0x28) & 0x04: Customer_VisitBranch(company,b,-1,-1,-1,-1); break;

Company_RefreshMenuSalesIfDue(this, company);         // 0x4FC70B
return 1;                                             // 0x4FC713
```

Key exact properties:

* **Iteration order:** ascending branch index `0..count-1` in every branch loop
  (`0x4FC65D`, `0x4FC6A4`, `0x4FD555`).
* **Only one per-branch action per call.** The second loop jumps to the common
  tail (`0x4FC708`) immediately after any of the four calls; it never continues to
  the next branch after executing one.
* **Flag priority:** `2`, then `0x10`, then `0x20`, then `4` — in that instruction
  order (`0x4FC6BD`, `0x4FC6C2`, `0x4FC6C7`, `0x4FC6CC`). A branch with
  `flags=0x24` therefore runs the price tune, not the rebuild.
* **Busy gate:** only `branch+0x2C == 0` is eligible (`0x4FC6B3`/`0x4FC6B6`).
  `Customer_VisitBranch` itself additionally accepts state 3.
* **Hidden/disabled gate:** `Game_GetPlayerSubrecord(...,param3=1)` returns 0 when
  `branch+0x16F5 != 0` (`0x500E80`). Such branches are skipped in both loops and in
  `City_EnsurePedestrianCoverage`.
* **No per-action cooldown.** The branch flags persist until their owning routine
  clears them; the queue entry is removed anyway, so another action-11 entry must be
  queued to revisit the branch.

---

## 4. Step A — pedestrian coverage / pest control

`City_EnsurePedestrianCoverage` (`0x4FD520`) runs **before** the branch loops and
iterates all visible branches ascending (`0x4FD555`, count reloaded at `0x4FD5F4`).

For each branch `b`:

1. `site = IDMap_Lookup(global+4, b+0x34)` (`0x4FD57B`).
2. `freeResidential = Game_CountFreeResidentialBuildings(b)` (`0x4FD584`);
   that function counts free buildings of types `0x1A`, `0x1B`, `0x1C`
   (`0x47FED0/0x47FEDC`, `0x47FEE6`, `0x47FEF0`).
3. If `freeResidential <= 0` → skip.
4. `freeService = Game_CountFreeBuildingsByType(b.site, 0x20)` (`0x4FD595/0x4FD599`).
   If `freeService > 0` → skip.
5. Cash tier: `fld qword [Company+0x108]; fcomp qword [0x55C640]`
   (`0x4FD5A2`), where `0x55C640` is the IEEE-754 double `30000.0`
   (bytes `00 00 00 00 00 4C DD 40`).
   * `<= 30000.0` → tier **1**
   * `> 30000.0` → tier **2**
   The comparison is `<=` for tier 1 (`test ah,0x41; jne 0x4FD5D0`).
6. Duplicate test:
   * tier 1: `Game_CountFilteredObjects(global, 1, 0x20, site, -1)`
     (`0x4FD5D6`/`0x4FD5D8`), skip if `> 0`;
   * tier 2: `Game_CountFilteredObjects(global, 2, 0x20, site, -1)`
     (`0x4FD5C0`/`0x4FD5C2`), skip if `> 0`.
7. `Branch_HireExterminator(site, tier, branch)` (`0x4FD5E6`).

`Game_CountFilteredObjects` (`0x48A130`) matches object `+0x30 == 0x20`,
service level `+0xA4 == 1/2`, free `+0x104 == 0`, association `+0x110 == -1`, and
when a site is supplied compares object `+0xF8` with the site’s
`Array_GetRecord28(site+0xC4,1,site+0x54)` (`0x48A130/0x48A1A0`).

`Branch_HireExterminator` (`0x4D5250`) creates a type-`0x20` service object
(`Object_Construct` at `0x4D5299`, push `0x20` at `0x4D5295`), copies the name
from `DAT_00580AF8`, registers it (`0x482790`), attaches it to the branch site
(`0x507E20`), sets its service tier via `0x50E850` (`param_1` = tier), and then:

* tier 1: `Game_CanAfford(branch, 5, 1000.0, false, -1)` at `0x4D5310`;
  float `1000.0` = `0x447A0000` pushed at `0x4D5307`; bool `0` at `0x4D5305`.
  The charge is **forced** (no affordability check).
* tier 2: `Game_CanAfford(branch, 5, 10000.0, true, -1)` at `0x4D5336`;
  float `10000.0` = `0x461C4000` pushed at `0x4D532D`; bool `1` at `0x4D532B`.
  Because tier 2 requires `Company+0x108 > 30000.0`, the 10000 check normally
  succeeds.

Iteration/gating summary: no RNG, no cooldown, ascending branch order, at most one
new service object per branch per tick, and only when the branch’s site has free
residential buildings, no free type-`0x20` building, and no existing tier-1/tier-2
service object in that city.

---

## 5. Step B — stalled-construction cleanup

For each visible branch with a site (`0x4FC66E`) and
`Game_CountFreeBuildingsByType(site,0x1E) == 0` (`0x4FC678/0x4FC67A`),
`City_TickBranches` calls:

```text
Game_GetBestObject(branch, 1, 0x22, &discard)        // 0x4FC68E
```

`Game_GetBestObject` (`0x47F2E0`) iterates the **construction-order list**
`branch+0x16F8`, count `branch+0x170C` (`0x47F2F7`), ascending:

1. For each order with progress `order+0xC < 0x22` (34) (`0x47F315`):
   `sum += Game_ComputeCityPriceShare(branch, order, 0)` (`0x47F31F`).
2. If the commit flag is non-zero (action 11 passes 1 at `0x4FC68C`):
   `Game_CanAfford(branch, 5, sum, false, -1)` (`0x47F377`, push 5 at `0x47F373`).
   This is a **forced expense** category 5.
3. Then, for every order with progress `< 34`:
   * progress `== 0` → `Game_UpdateObject2(order, branch+0x14E0)` (`0x47F3AC`)
     and set `clearedAny = true`;
   * progress `!= 0` → `Game_SetModeByte(order, 100)` (`0x47F3BD`, push `0x64`).
4. If `clearedAny`, `Game_AdjustPlayerObjectPercent(player, branch+0x30, 5)`
   (`0x47F3E7`, push 5 at `0x47F3DE`).
5. Return 1.

`Game_ComputeCityPriceShare` (`0x47F230`) computes:

```text
price = Game_ComputePrice(order->record, playerCity)      // 0x4E4060
p = order+0xC                                            // progress 0..100
if p == 100:            return 0
if p < 1:               return price                     // full price for progress 0
otherwise:              return price * (1 - 0.01*p) * 0.25
```

Constants: `0.01` at `0x55C430`, `0.25` at `0x55C434`; `100` test at
`0x47F27F`. `Game_ComputePrice` (`0x4E4060`) is the already-decoded construction
formula:

```text
trunc((100 - 3*(city[0x54] + city[0x3C]))
      * level_base[record[8]] * record[0x70] * 0.01)
level_base = [20, 100, 500, 150, 300, 180]
```

(`SIMULATION.md` §“Exact order price” and `0x4E4060`.)

Interpretation: the branch removes construction orders that are less than 34%
complete when its site has no free type-`0x1E` building slot. Progress-0 orders are
charged at full value; 1–33% orders at 25% of the depreciated value. The charge is
category 5 (Miscellaneous).

---

## 6. Step C — the four flag-gated per-branch paths

### 6.1 `flag 2` — menu/staff validation

`Branch_ValidateMenuAndRecalculate` (`0x4F7C30`):

```text
all = Game_CountObjectsByType(b, -1)      // 0x4F7C3E
t0  = Game_CountObjectsByType(b, 0)       // 0x4F7C4B
t3  = Game_CountObjectsByType(b, 3)       // 0x4F7C56
t2  = Game_CountObjectsByType(b, 2)       // 0x4F7C61
if ((t0 == 0 || t2+t3 == 0) && all > 0)
     Branch_RemoveAllStaff(b);            // 0x4F7C7B
else if (all == 0)
     Branch_AssignEntranceAndCustomerSlots(company, b, 0);  // 0x4F7C8F
Branch_AutoTunePrice(b);                  // 0x4F7C97
return 1;                                 // 0x4F7C9F
```

`Game_CountObjectsByType` (`0x47AAC0`) counts branch staff records in the
`branch+0x1500` map (count `branch+0x1514`) by the byte at `record+0x824`.

`Branch_RemoveAllStaff` (`0x4F7B50`) iterates **downwards** from
`count-1` to 0 (`0x4F7B50/0x4F7B5D`) and calls `Branch_RemoveStaffMember` for every
non-zero entry. No cash/ledger entry is made.

`Branch_AssignEntranceAndCustomerSlots` (`0x4F8D40`) is the staff/customer-slot
layout pass. It is a three-pass loop over staff categories `0`, `2`, `3`; it picks
an entrance side from the 8 neighbour flags, assigns people to buildings with
`City_AssignPersonToBuilding` (`0x4F7DD0`; first call `0x4F9372`), removes extras with
`Branch_RemoveStaffMember`, and finishes with:

* `Game_ToggleObjectFlag2(b)` (`0x4F9695`),
* `Stats_ResetAverages(b)` (`0x4F969C`).

`Game_ToggleObjectFlag2` (`0x47EC70`) sets branch `+0x28 |= 2` when type 0, type 2
or type 3 staff are missing (`0x47ED0F`), and clears bit 2 only when all three
categories exist (`0x47ECFA`). Thus flag 2 is the “staff composition invalid”
latch.

No RNG and no ledger in this path.

### 6.2 `flag 0x10` — menu product creation

Despite the symbol, `Company_OpenBranchAtSite` (`0x4FC0F0`) does **not** create a
branch; it creates a menu product and assigns it to the branch.

Let `assignedRecipe = *(branch+0x14DC)` (`0x4FC11F`). The two paths are:

**A. No assigned recipe (`assignedRecipe == 0`)**

1. `Recipe_CreateGenerated(recipe, branch+0x30, 5, 2, branch+0x34, -1)`
   (`0x4FC159`; args pushed at `0x4FC14C..0x4FC157`).
2. `Company_GenerateNameFromTopProduct` (`0x513A90`, `0x4FC177`).
3. `recipe+0x308 = 5` (`0x4FC180`).
4. `List_Add(company+0x110, recipe)` (`0x4FC196`).
5. `Branch_SetAssignedEmployee(branch, recipe)` (`0x4FC19E` → `0x477BD0`),
   which writes `branch+0x14DC = recipe`, invalidates all branch ratings, and calls
   `Game_ClearObjectFlag20`.
6. Return **4**.

**B. Assigned recipe exists**

1. `category = Game_SelectLeastUsedCategory(company, 2)` (`0x4FC1AC`).
   If `category == -1` → clear bit `0x10` (`0x4FC1DB/0x4FC1E0`) and return 1.
2. `cap = min(company.branchCount(+0x15C) + 16, 20)` (`0x4FC1BA..0x4FC1C8`).
3. If `Game_CountActiveCompanies(company) >= cap` → clear bit `0x10`
   (`0x4FC1DB`) and return 1.
4. `Recipe_CreateGenerated(recipe, branch+0x30, category, 2, branch+0x34, -1)`
   (`0x4FC226`).
5. `recipe+0x308 = category` (`0x4FC255`).
6. `List_Add(company+0x110, recipe)` (`0x4FC267`).
7. `Recipe_SetOnMenu(company, recipe, 1)` (`0x4FC271`).
8. Return **4**.

`Game_CountActiveCompanies` and `Game_GetActiveCompanyById` are misnamed: they
iterate the **recipe list** at `Company+0x110`, count `Company+0x124`, and test
`recipe+0x1DC == 1` (`0x4DDDE0/0x4DDDF0`, `0x4DDE30/0x4DDE40`). So the cap is
“active menu products < branchCount+16, capped at 20”.

There is no ledger entry in this path. Note that the success path returns 4 and does
**not** clear bit `0x10`; only the two failure cases clear it. If the bit stays set,
the next action-11 invocation adds another product until the cap is reached.

### 6.3 `flag 0x20` — price auto-tune (prior decode, exact constants)

`Branch_AutoTunePrice` (`0x4FF6E0`):

```text
pricePercent = branch+0x14A8
offset       = branch+0x14AC

if pricePercent < 50 or pricePercent > 150:              // 0x4FF6FD
    pricePercent = Random_RangeFast(50, 150)             // 0x4FF714
    branch+0x14A8 = pricePercent                         // 0x4FF71C
    branch+0x1714 = 0                                    // 0x4FF722, invalidate menu ratings
```

Weights (`0x4FF72C..0x4FF780`):

* `Array_Copy68(branch, local)` (`0x47C3C0`) copies **0x68 dwords = 416 bytes**
  from `branch+0x151C`.
* The matrix is 8 records of 52 (`0x34`) bytes; the 8 `int16` weights of each
  record start at record offset `+6` (`0x4FF75A`: `lea esi,[esp+0x46]`).
* `local_1C0[8] = site+0x4C[8]` (`rep movsd` at `0x4FF758`), then
  `local_1C0[j] += matrix[g][j]` for `g=0..7` (`0x4FF76E`).
* `target = (sum(local_1C0) * 4) / 5` (`0x4FF797..0x4FF7B4`, magic divide by 5).

Search (`0x4FF7C2..0x4FF8A7`):

```text
step = 16; direction = 0
loop:
    weighted = 0
    for g in 0..7:
        r = Branch_GetCustomerGroupRating(branch, g, 0)    // 0x4FF7CF
        if r >= 50:      weighted += weight[g]
        elif r > 30:     weighted += (r-30)*weight[g] / 20 // signed trunc
        // r <= 30 contributes 0
    if target < weighted:
        if direction == -1: step >>= 1
        direction = 1; delta = +step
    else:
        if target <= weighted: return 1
        if direction == 1: step >>= 1
        direction = -1; delta = -step
    offset += delta
    if offset < 0 or offset > 99:
        branch+0x14AC = 10
        branch+0x1714 = 0
        return 1
    branch+0x14AC = offset                              // 0x4FF85D
    branch+0x1714 = 0                                   // 0x4FF86A
    if step < 2: return 1
```

Exact constants: `0x32`=50, `0x96`=150 (`0x4FF6FD/0x4FF706`), `0x10`=16
(`0x4FF7A9`), `0x63`=99 (`0x4FF858`), `0x0A`=10 reset (`0x4FF888`),
bands 50/30 and divisor 20 (`0x4FF7D4`, `0x4FF7DD`, `0x4FF7E2..0x4FF7F7`).
Initial values from `Branch_Construct`: `+0x14A8=100` at `0x476C38`,
`+0x14AC=10` at `0x476C42`, flags/state 0 at `0x476D4E`/`0x476D51`.

`Branch_GetCustomerGroupRating` (`0x47A3B0`) returns, for `param_2=0`:

```text
avg8      = Stats_GetAverage8(branch, g)
building  = Branch_ComputeBuildingRating(branch, g)
menu      = Branch_GetMenuRating(branch, g)
score     = Rating_ComputeBuildingScore(branch, g)
rating    = clamp0_100(score + (avg8 + building + menu) / 3)
```

(`0x47A3B0/0x47A3C5..0x47A410`; `param_2=0` at `0x4FF7CF` means no price-comparison
term and divisor 3.)

`Branch_ComputeBuildingRating` (`0x478BE0`) lazily calls
`Branch_RecalculateRatings` when `branch+0x1718 == 0`
(`0x478BEF`/`0x478BF1`), so the first auto-tune after a layout change can also
rebuild the full rating stack.

`Branch_GetMenuRating` (`0x478320`) lazily calls
`Branch_RecomputeMenuPriceRatings` when `branch+0x1714 == 0` (`0x478320/0x47832A`),
then applies the city factor:

```text
menu = clamp0_100( avg(branch+0x177C[8]) * ((city[0x5C]+city[0x44]) * -3 + 100) / 100 )
```

(`0x478320/0x47834E..0x478360` for the average; city multiplier at
`0x47837F..0x4783A9` (`city[0x5C]+city[0x44]`, `*3`, `100-`, `*rating`,
magic `/100`); exact multiplier is the same `-3*(city[0x5C]+city[0x44])+100` used by
`Branch_ComputeBuildingRating` `0x478BE0` and the simulator's `city_adjust`).

`Branch_RecomputeMenuPriceRatings` (`0x4784E0`) is where competitor pricing enters:

* fixed category order `[4,7,9,5,10,3,6,8]` (`0x4784E0/0x4784EC..0x478514`);
* expected price per group from `Rating_GetFloat(site, 0..7)`
  (`0x4784E0/0x47856E..0x47860F`);
* average `Branch_ComputeRecipePrice` over the branch’s assigned recipe
  (`branch+0x14DC`) and the active recipe list (`0x4784E0/0x478693..0x4786B2`);
* price rating at `branch+0x179C`:
  `100` if `avg <= expected`, else `100 - (int)((avg-expected)*10.0)`, clamped
  (`0x478740..0x478774`, constant `10.0` at `0x55C328`);
* menu rating at `branch+0x177C` is the min of the price rating and the
  product-score/availability combination (`0x478774..0x4787E1`);
* it sets `branch+0x1714 = 1` (`0x478618`), i.e. the cache is valid.

So price tuning is competitive **indirectly**: raising the additive offset lowers
the menu rating through the menu price rating, which lowers the weighted group
coverage. `Branch_AutoTunePrice` itself asks for `price_comparison=False`.

### 6.4 `flag 4` — branch rebuild / renovation (`Customer_VisitBranch`)

The symbol is misleading: the function does not model a customer. It rebuilds the
branch layout, commits construction orders, recalculates ratings, and (for the
human player only) books a renovation fee.

Entry gates (`0x4FB660`):

1. `branch+0x2C` must be 0 or 3, else return 1
   (`0x4FB677`, `0x4FB680`).
2. `site+0x38 != 0` → return 3 (`0x4FB689/0x4FB694`).
3. `site+0x8C > 0` → `Game_MarkAllObjectsDirty(branch,3)`, return 1
   (`0x4FB6A6/0x4FB6AE`).
4. If `branch+0x170C > 0` (construction orders exist):
   * if `(branch+0x28 & 4) == 0` and `branch+0x170C > 6` → return 1
     (`0x4FB6D3/0x4FB6D9`);
   * otherwise `Branch_ClearInteriorObjects(branch,0)` (`0x4FB6E2`) and
     `MapObject_SettlePendingAmount(branch)` (`0x4FB6EC`).

`Branch_ClearInteriorObjects` (`0x47C5E0`) removes every construction order from
`branch+0x16F8` (always index 0 until the count is zero; `IDMap_Lookup(...,0,0)`
at `0x47C61E`/`0x47C628`, loop test at `0x47C6B6`),
sums `Game_ComputeEventValue` (`0x4E5F40`) into a float, and then:

* `Stats_AddRecordValue(branch, 0x15, sum, -1)` (`0x47C6DE`; push 0x15 at
  `0x47C6DA`) — income category **21** (Miscellaneous), paid to player cash
  (`Stats_AddRecordValue` `0x477C80/0x477C9C..0x477CA4`);
* `Branch_RemoveAllBuildings` (`0x47F5F0`), `branch+0x1718 = 0`, set flag 4,
  `Game_CheckObjectUpgrade` (`0x47C71B`, `0x47C720`).

Then the layout parameters (`0x4FB6F1..0x4FB7BC`):

* `arg3` is `-1` from action 11:
  * if `companySlot+0x134 < 0x13880` (80000) → `branch+0x24 = 0`,
    `arg3 = 0` (`0x4FB70C`, `0x4FB71B`);
  * else `Map_UpdateVisibleTiles(branch)`, `arg3 = branch+0x24`
    (`0x4FB727`, `0x4FB72F`).
  * `arg3 == 4` is special: `bVar3 = 1`, `arg3 = 0` (`0x4FB73B..0x4FB74E`).
* `arg4 == -1` → `arg4 = 2` (`0x4FB77F`).
* `arg5 = -1` (unchanged).
* `arg6 == -1` → two CRT `_rand() & 1` seeds (`0x4FB7AD`, `0x4FB7B4`; `_rand`
  is `0x54F0E2`).

Then `CityMap_GenerateLayout(branch, ...)` (`0x4FB7CD`, function `0x4FB170`).
On failure it calls `IDMap_FreeValuesAndDestroy` and returns the failure code
(`0x4FB7D9..0x4FB7F1`).

After layout:

* `Stats_SumRecordCounts(pendingMap, &subset, &total)` (`0x4FB805`, function
  `0x4FB600`) computes `total = Σ record+4` and
  `subset = Σ record+4 where record+0x1C != 0`.
* If `bVar3` (the `arg3==4` case): `Map_CommitPendingObjectEdits(map,0)`
  (`0x4FB817`), `branch+0x24 = 4` (`0x4FB823`), success.
* Else if `companySlot+0x114 == 0` (human): charge category 4 with affordability
  check on `total` (`0x4FB858`, `0x4FB85C`); if that fails, charge category 4 on
  `subset` (`0x4FB88D`). If either succeeds, `Map_CommitPendingObjectEdits` with
  `1`/`0` (`0x4FB86A`, `0x4FB8B4`).
* Else (AI company, `companySlot+0x114 != 0`): call
  `Game_CanAfford(branch, 4, total, true, -1)` (`0x4FB85C/0x4FB876`) but **ignore
  the return**, then `Map_CommitPendingObjectEdits(map,1)` and force success
  (`0x4FB86A`). An unaffordable AI rebuild therefore commits without a charge.
* `Array_ClearStride34` (`0x4FB8BB`).

If commit failed (`uVar2 == 0`), it prints briefing id `0x29` and returns 2
(`0x4FB8EA`, `0x4FB8F2`).

On success (`0x4FB906..0x4FB919`):

* `Game_CheckObjectUpgrade` (`0x47F100`) — may re-set flag 4 if
  `agedAdjacentBuildings < 4` or `playersByByte(5) < 1` (`0x47F138`, `0x47F13D`,
  `0x47F16B`);
* `Grid_RebuildStreetNodes` (`0x4F3200`, `0x4FB912`);
* `Branch_RecalculateRatings` (`0x478DB0`, `0x4FB919`).

Rating rebuild (`Branch_RecalculateRatings` `0x478DB0`) calls, in order:
`Map_BuildObjectGrid` (`0x4FBAE0`), `Company_ComputeTypePercentages` (`0x479120`),
`Stats_ComputeBestPairShareAverage` (`0x4791E0`), `Game_ComputeCategoryDominance`
(`0x479290`), `Stats_ComputeOccupancyPercent` (`0x4793B0`), `Stats_GetAverageValue`
(`0x4795E0`), `Game_ComputeCityScore` (`0x479620`), `Map_ComputeBuildableAverage`
(`0x479960`), `Stats_ComputeTypeThreeShare` (`0x479A40`),
`Game_UpdateActivePlayerCount` (`0x479AB0`), `Game_ComputeCityConditionScore`
(`0x479AE0`), `NoOp_Stub` (`0x48E0A0`), `Stats_UpdateAverages` (`0x479CA0`),
`Stats_ComputeWeightedTotals` (`0x478EB0`), `Rating_ComputeBranchScores`
(`0x478F60`). It sets `branch+0x1718 = 1` (`0x478DD1`), then for the 8 scores at
`branch+0x17FC..0x1818`:

```text
v = score[i] - branch+0x1878
if v < 0: v = 0
if v > 100: v = 100
score[i] = v
```

(`0x478E70..0x478E9E`; 8 iterations, baseline `branch+0x1878`.)

Then the **AI/human split** at `0x4FB924`:

* if `companySlot+0x114 != 0` **or** `branch+0x30 != currentPlayerCompanyName`:
  `Game_UpdateMusicTheme` (`0x4FCCB0`, `0x4FBA60`), `Branch_AutoTunePrice`
  (`0x4FBA6D`), return 1. **This is the AI path and the normal action-11 path:
  no renovation fee is booked.**
* else (human branch, `companySlot+0x114 == 0`): renovation fee.

Human renovation fee (`0x4FB948..0x4FBA03`), with action-11 arguments
`arg3 = style` (0 if cash <80000, otherwise `branch+0x24`), `arg4 = 2`,
`arg5 = -1`:

```text
units  = arg5 + 5 + arg3*4        // = 4 + 4*style
amount = units * 250              // 0xFA; 0x4FB96A..0x4FB961
if arg4 == 0: amount = units * 200          // 0x4FB974..0x4FB98C
if arg4 == 2: amount = (units * 2500) / 8   // 0x4FB990..0x4FB9A3
if missionState+0xD4 != 0: amount = 0
else if missionState+0x1B8 != 0: amount = amount*15/10
Game_CanAfford(branch, 9, amount, false, -1)     // 0x4FBA03
if missionState+0xD4 != 0: decrement +0xD4; return 1
if missionState+0x1B8 == 0: return 1
decrement +0x1B8; return 1
```

`companySlot+0x114` is the “AI-controlled” flag: `Branch_ApplyProductSales`
(`0x4FE420/0x4FE438`) uses `==0` for the human-only 750/350 charges, and
`Game_TryBuyCompletedHouse` (`0x4FC7D0/0x4FC7D7`) uses `!=0` for the AI path.
The identical fee formula and `+0xD4`/`+0x1B8` modifiers appear in
`RenovationScreen_UpdateCost` (`0x4922D0/0x4922D0..0x4922DC`), which identifies
this charge as a **renovation cost**, not a customer bill.

For action 11 (AI company) the observed ledger effect of this path is therefore:

* category **4** for the pending layout objects (affordability check, return
  ignored);
* income category **21** refund from `Branch_ClearInteriorObjects`;
* **no category 9**.

### 6.5 Marketing / customer-queue boundary

Action 11 contains **no advertising campaign, ad-plan, or marketing-budget code**.
Advertising is action 23 (`AI_UpdateAdvertisingCampaigns` `0x4FECC0`, dispatched at
`0x501838`). The only marketing-adjacent side effect in the action-11 tree is the
`Game_AdjustPlayerObjectPercent(player, branch+0x30, 5)` call inside the cleanup
pass (`0x47F3E7`), which increments a player object percentage for type 5; it is
not an ad plan and books no ledger entry.

Customer-queue simulation is hourly and lives in `City_TickSimulation`, called from
`Game_EndOfHour` (`0x486590/0x486616`); it is not part of action 11. The only
queue-like work in action 11 is:

* `Branch_AssignEntranceAndCustomerSlots` (`0x4F8D40`), which selects the entrance
  side and places staff/customer slots (geometry and staff counts, no customers);
* the AI action queue itself (`slot+0x74`, 10 entries), consumed by
  `UI_RemoveListEntryByType` (`0x501040`).

### 6.6 Branch flag provenance (for calibration)

| Flag | Set | Cleared | Meaning |
|---:|---|---|---|
| `2` | `Game_ToggleObjectFlag2` `0x47ED0F` when type 0/2/3 staff missing | `0x47ECFA` when all present | staff composition invalid |
| `0x10` | not located in scanned code; initialized 0 in `Branch_Construct` `0x476D4E` | `Company_OpenBranchAtSite` `0x4FC1DB/0x4FC1E0` | menu-product setup pending |
| `0x20` | `Game_ClearObjectFlag20` `0x47EE44` when `branch+0x14DC==0` and player has no active recipes | `0x47EE2B` when assigned recipe exists or active recipes exist | empty-branch price setup |
| `4` | `Branch_ClearInteriorObjects` `0x47C71B`; `Game_CheckObjectUpgrade` `0x47F16B` | `Game_CheckObjectUpgrade` `0x47F14F` | rebuild/upgrade pending |
| `8` | `AI_EnsureBranchStorage` `0x4FD310` | not action 11 | supplier/storage done |

`branch+0x14DC` is the **assigned/primary recipe pointer**:
`Branch_SetAssignedEmployee` sets it (`0x477BD0/0x477BD8`),
`Branch_ClearAssignedEmployee` clears it (`0x477B80/0x477B88`).

---

## 7. Step D — 24-hour menu-sales refresh

`Company_RefreshMenuSalesIfDue` (`0x4FC5F0`) runs unconditionally at the end of
`City_TickBranches` (`0x4FC70B`):

```asm
4fc5f0  ...
4fc5fa  call 0x489b10              ; Game_GetDateField0C
4fc609  mov edi,[slot+0x44]        ; last refresh hour
4fc611  cmp eax,edi
4fc613  jl  0x4fc622               ; current < last -> skip
4fc615  add eax,0x18               ; +24
4fc619  mov [slot+0x44],eax
4fc61d  call 0x4fc470              ; Game_RecomputeCompanyMenuSales
```

`Game_GetDateField0C` returns `clock+0xC` (`0x489B10/0x489B16`).
`Game_EndOfHour` increments that field once per simulated hour
(`0x4865C8..0x4865CC`, `+0xC += 1`), so `0x18` = **24 hours = 1 day**, not 24 days.
The comparison is `current >= slot+0x44`; a freshly initialised slot whose
`+0x44` is still 0 therefore recomputes on the first action-11 call.

`Game_RecomputeCompanyMenuSales` (`0x4FC470`):

1. `Game_ResetRecordTurnCounters(company)` (`0x4FC48B` → `0x4E1B80`), which zeroes
   `recipe+0x30C` for every recipe in `Company+0x110` (count `+0x124`).
2. `bucket = clock+0x0A` (ushort, `0x4FC4A2`), clamped to `99` (`0x4FC4B7`).
3. For every active recipe `i` (`Game_CountActiveCompanies` / `GetActiveCompanyById`,
   `0x4FC4A6`/`0x4FC4B2`):
   `Stats_SumMaskedMapFloats(recipe, bucket-1, 0, -1)` (`0x4FC4CD`), `__ftol`
   (`0x4FC4D2`), `recipe+0x30C += value` (`0x4FC4DD`).
   `bucket-1 == -1` when the clock field is 0; `-1` matches every record in
   `Stats_SumMaskedMapFloats` (`0x5100B0`; `param_2 == -1` match at `0x510111`).
4. If `companySlot+0x12A & 0x10` (`0x4FC4F5`):
   * `Company_CollectUnprofitableBranches(company)` (`0x4FC500` → `0x4E1BC0`),
     which computes the mean of `recipe+0x30C`, sorts descending, and returns
     recipes with `sales < mean/2` (`0x4E1C7C` mean, `0x4E1C87` `sar 1`,
     compare at `0x4E1CFA`);
   * for each returned recipe: if `Game_IsRecordLinked(company, recipe)`
     (`0x4FC51F`), `Recipe_SetOnMenu(company, recipe, 0)` (`0x4FC52D`).
5. Return 1.

So this is a per-company **menu product pruning** maintenance step: recompute
per-product sales daily; if the policy bit is set, drop products selling below half
the company average. No cash/ledger entry.

---

## 8. Consolidated constants and thresholds

| Constant | Value | Site |
|---|---:|---|
| service tier cash threshold | `30000.0` double at `0x55C640` | `0x4FD5A2` |
| tier-1 pest control cost | `1000.0` (`0x447A0000`) | `0x4D5307` |
| tier-2 pest control cost | `10000.0` (`0x461C4000`) | `0x4D532D` |
| free-building type tested for pest control | `0x20` (32) | `0x4FD595`, `0x4FD5D6` |
| residential types | `0x1A`, `0x1B`, `0x1C` | `0x47FED0` |
| cleanup building type | `0x1E` (30) | `0x4FC678` |
| cleanup progress threshold | `0x22` (34) | `0x47F315` |
| cleanup write-off | `0.25`; `0.01` | `0x55C434`, `0x55C430` |
| cleanup mode byte | `100` | `0x47F3BD` |
| branch rebuild cash threshold | `0x13880` = `80000` | `0x4FB70C` |
| auto-tune percent range | `50..150` inclusive | `0x4FF6FD`, `0x4FF714` |
| auto-tune step | `16` | `0x4FF7A9` |
| auto-tune offset clamp | `0..99`; reset `10` | `0x4FF858`, `0x4FF888` |
| auto-tune target | `sum(weights)*4/5` | `0x4FF797` |
| rating bands | `>=50` full; `>30` `(r-30)/20` | `0x4FF7D4`, `0x4FF7DD` |
| menu-product cap | `min(branchCount+16, 20)` | `0x4FC1BA..0x4FC1C8` |
| menu-sales cooldown | `0x18` = 24 hours | `0x4FC615` |
| sales-prune threshold | `mean/2` | `0x4E1C7C`, `0x4E1C87`, `0x4E1CFA` |
| renovation fee rate | `250`; `200`; `2500/8` | `0x4FB96A`, `0x4FB97B`, `0x4FB990` |
| renovation units | `arg5+5+arg3*4` | `0x4FB955` |
| renovation fee multipliers | `0` if +0xD4; `1.5` if +0x1B8 | `0x4FB9C3`, `0x4FB9D7` |
| ledger expense base | `stats+0x78+4*cat` | `0x477E95`; cash `0x477EBA` |
| ledger income base | `stats+0x10+4*cat` | `0x477D2E`; cash `0x477D6A` |

---

## 9. RNG calls and ranges reachable from action 11

| Function | Call site | Range / behavior | When |
|---|---:|---|---|
| `Random_RangeFast(50,150)` | `0x4FF714` | `_rand()*(101)/0x7FFF + 50`, clamped 150 (inclusive 50..150) | price percent `<50` or `>150` |
| `_rand() & 1` | `0x4FB7AD` | 0/1 | `Customer_VisitBranch`, first layout seed (`arg6==-1`) |
| `_rand() & 1` | `0x4FB7B4` | 0/1 | second layout seed |
| `Random_Mod(10)` | `0x4FB32E` | `_rand()%10` (fixed) | `CityMap_GenerateLayout` street-plan count |
| `Random_Mod(n)` | `0x4FB36E` | `_rand()%n`; `n` is a dynamic list/endpoint count (the `push ecx` at `0x4FB36D`) | layout variant |
| `_rand()` | `0x4FB3D6` | full 0..32767 | layout variant bit |
| `Random_Mod(n)` | `0x4FB412` | dynamic list/endpoint count | layout pattern choice |
| `Random_Mod(n)` | `0x4FB454` | dynamic list/endpoint count | layout pattern choice |
| `Random_Mod(n)` | `0x4FB496` | dynamic list/endpoint count | layout pattern choice |
| `Random_Mod(3)` | `0x4FB4BC` | 0..2 (fixed `push 3` at `0x4FB4BA`) | layout pattern choice |
| `_rand()` | `0x4FB4EA` | full 0..32767 | layout variant bit |
| `Random_Mod(n)` | `0x4FB526` | dynamic list/endpoint count | layout pattern choice |
| `Random_Mod(n)` | `0x4FB568` | dynamic list/endpoint count | layout pattern choice |

Implementations:

* `Random_RangeFast` `0x4034D0`: `min + (_rand()*(max-min+1))/0x7FFF`,
  clamped to `max`.
* `Random_Mod` `0x4034B0`: `_rand() % n` (0 when `n==0`).
* `_rand` `0x54F0E2`: LCG `state = state*0x343FD + 0x269EC3`,
  return `(state >> 16) & 0x7FFF`.

No RNG in coverage, cleanup, menu/staff validation, menu-product creation, or the
24-hour sales refresh. `Game_GetBestObject`, `Branch_AutoTunePrice`’s rating path,
and the menu-sales path are deterministic.

---

## 10. Ledger and cash effects (action 11 only)

`Game_CanAfford` (`0x477E40`) is the expense booking primitive:

```text
if bool check and player.cash(+0x108) - amount < 0: return false
record = Stats_FindRecordByType(branch, -1)
if record:
    record.expense[category] += amount       // +0x78 + 4*cat, 0x477E95
    player.cash(+0x108) -= amount            // 0x477EBA
return true
```

It always uses the **expense** array `+0x78`; category names from
`LEDGER_VERIFICATION.json`: `4`=Furnishings, `5`=Miscellaneous, `9`=Miscellaneous
(in the UI, 5+9 are combined).

Cash views used along this tree (do not conflate them):

* `Company+0x108` (double): company cash; written by `Company_AddLedgerAmount`
  (`0x4E0C40/0x4E0D0C`) and `Game_CanAffordWithCurrency`
  (`0x4E0B60/0x4E0B89`, `0x4E0BBC`), and read as the 30000.0 tier test
  (`0x4FD5A2`).
* `Player+0x108` (double): player cash; debited by `Game_CanAfford`
  (`0x477E40/0x477EBA`) and credited by `Stats_AddRecordValue`
  (`0x477C80/0x477D6A`).
* outer company-slot `+0x134` (int): company/AI capital field used by the 80000
  style test (`0x4FB70C`) and by `AI_Action_BuyOrRentBranch`
  (`0x4F7EEF`, `0x4F7F2E`).

`Stats_AddRecordValue` (`0x477C80`) is the income/refund primitive:

```text
record.income[category] += amount            // +0x10 + 4*cat
player.cash(+0x108) += amount                // capped at 999999999.0
```

| Category | Direction | Amount | Call site | AI action 11? |
|---:|---|---:|---|---|
| 5 | expense | `1000.0` | `Branch_HireExterminator` `0x4D5310` | yes, tier 1 |
| 5 | expense | `10000.0` (affordability check) | `0x4D5336` | yes, tier 2 |
| 5 | expense | `Σ 25%` (or full for progress 0) of cleared construction orders | `Game_GetBestObject` `0x47F377` | yes |
| 4 | expense | `Σ pendingRecord[+4]` (total; fallback subset) | `Customer_VisitBranch` `0x4FB858`/`0x4FB88D` | yes (AI charges total if affordable; commit regardless) |
| 9 | expense | renovation fee `4+4*style` × rate, multipliers `0`/`1.5` | `0x4FBA03` | **no** — AI path at `0x4FB92D` skips it |
| 21 | income | refund `Σ Game_ComputeEventValue` of removed construction orders | `Branch_ClearInteriorObjects` `0x47C6DE` | yes |

No supplier, storage, ingredient, wage, marketing, or rent booking occurs anywhere
in the action-11 call tree.

---

## 11. Simulator action-11 implementation

`tools/sim_core.py`:

* `execute_action` dispatches action 11 to `_city_tick` at lines **1494–1495**.
* `_city_tick` lines **1581–1589**:

```python
for b in company.branches:
    b.update_ratings()
    if not b.supplier and company.cash > 0:
        b.supplier = True
    if b.opened:
        self._price_action(sim, company, b)
return ("city_tick", company.id)
```

* `_price_action` lines **1553–1568**:
  computes `rating`, `competitor` ratings and `comp_avg` (1556–1560) but never uses
  `comp_avg`; weights are `[int(round(x*100)) for x in sim.group_shares]` (1562);
  calls `branch.auto_tune_price(weights)` (1563); reports up/down/hold.
* `auto_tune_price` lines **1173–1223** implements the prior decode:
  target `sum*4//5` (1188), step 16 (1190), bands 50/30 with divisor 20
  (1194–1202), halving on direction change (1203–1214), reset 10 on out-of-range
  (1216–1218).
* `update_ratings` lines **1230–1250** is a separate reconstruction of the rating
  stack.
* `plan_step_weight` returns 40 for action 11 at lines **1404–1405**.
* tests: `test_ai_city_tick` at `tests/test_sim_core.py:1260–1268` asserts
  `b.supplier` becomes true; `test_ai_pricing` at `1215–1228` exercises action
  **19**, not action 11.

---

## 12. Discrepancy list (game vs simulator action 11)

Each item is a behavioral difference; the simulator’s action 11 is substantially
larger in scope than the game’s and also performs work that belongs to action 12.

1. **Iteration scope.** Game: two global passes over all visible branches plus at
   most **one** flag-selected branch action (`0x4FC65D`, `0x4FC6A4`, break at
   `0x4FC708`). Sim: `for b in company.branches` and every branch is processed
   (`tools/sim_core.py:1583`).
2. **Supplier flip (wrong action).** Game action 11 never calls
   `AI_Action_AssignSuppliers` (`0x4FD190`) or `AI_EnsureBranchStorage`
   (`0x4FD310`); action 12 owns both (`0x5017E3` dispatch; callgraph shows only
   `0x5016C0 → 0x4FD190`). Sim sets `b.supplier = True` at
   `tools/sim_core.py:1585–1586`, and `tests/test_sim_core.py:1268` asserts it.
   This is the single largest semantic error.
3. **Rating updates every tick.** Game: `Branch_RecalculateRatings` (`0x478DB0`)
   only inside the flag-4 rebuild path (`0x4FB919`), plus lazy cache invalidation
   (`branch+0x1714` / `+0x1718`). Sim: `b.update_ratings()` for every branch on
   every action 11 (`tools/sim_core.py:1584`).
4. **Price tuning every opened branch.** Game: only the first eligible branch with
   `flags & 0x20` and `state==0` (`0x4FC6C7`), after flags 2 and 0x10. Sim:
   every `b.opened` branch (`tools/sim_core.py:1587–1588`).
5. **`opened` gate is not the game gate.** Game uses `branch+0x2C == 0`
   (`0x4FC6B3`) and `branch+0x28` flags; “opened” does not exist in this path.
   Sim gates on `b.opened` (`tools/sim_core.py:1587`).
6. **Price weights source.** Game: `site+0x4C[8]` + 8×8 `int16` matrix at
   `branch+0x151C` (record stride `0x34`, values at `+6`), `0x4FF72C..0x4FF780`.
   Sim: `sim.group_shares * 100` (`tools/sim_core.py:1562`).
7. **Unused competitor average.** Game computes average competitor recipe price
   inside `Branch_RecomputeMenuPriceRatings` (`0x4784E0`) and turns it into the
   `+0x179C` price rating. Sim computes `comp_avg` at
   `tools/sim_core.py:1559–1560` but never uses it (dead variable), so its
   `auto_tune_price` never sees competitor prices.
8. **Price-percent RNG.** Game randomizes `+0x14A8` with `Random_RangeFast(50,150)`
   when outside `[50,150]` (`0x4FF714`). Sim calls `auto_tune_price` without a
   `percent_rng` from `_price_action`, so an out-of-range percent becomes `100`
   (`tools/sim_core.py:1182–1185`), not a random 50..150.
9. **Missing coverage/exterminator.** No analog of
   `City_EnsurePedestrianCoverage` (`0x4FD520`) or
   `Branch_HireExterminator` (`0x4D5250`); sim never books 1000/10000 category 5.
10. **Missing stalled-construction cleanup.** No analog of the
    `Game_GetBestObject` pass (`0x4FC678`/`0x47F2E0`); no progress-<34 order
    cancellation, no 25%/full-price category-5 charge, no
    `Game_AdjustPlayerObjectPercent(...,5)` side effect.
11. **Missing menu-product creation.** No analog of
    `Company_OpenBranchAtSite` (`0x4FC0F0`), `Game_SelectLeastUsedCategory`
    (`0x4E0E90`), `Recipe_CreateGenerated` (`0x510C90`), or the
    `min(branchCount+16,20)` cap.
12. **Missing staff maintenance.** No analog of
    `Branch_RemoveAllStaff` (`0x4F7B50`) or
    `Branch_AssignEntranceAndCustomerSlots` (`0x4F8D40`); no type 0/2/3 staff
    validation or customer-slot placement.
13. **Missing 24-hour menu-sales refresh.** No analog of
    `Company_RefreshMenuSalesIfDue` (`0x4FC5F0`) or
    `Game_RecomputeCompanyMenuSales` (`0x4FC470`); no per-recipe sales
    accumulation, no `mean/2` pruning, no 24-hour gate.
14. **Missing ledger effects.** Sim action 11 has no `charge`/`earn` calls, so its
    ledger is always zero. Game action 11 can book category 5 (1000/10000/cleanup),
    category 4 (rebuild objects), and income category 21 (refund); see §10.
15. **Missing flag priority and busy/hidden gates.** Game tests flags in the order
    `2 → 0x10 → 0x20 → 4`, requires `+0x2C==0`, and skips `+0x16F5 != 0`; sim has
    none of these (`tools/sim_core.py:1581–1589`).
16. **Missing rebuild/renovation path.** No analog of `Customer_VisitBranch`
    (`0x4FB660`): no 80000 cash threshold (`0x4FB70C`), no style selection
    `branch+0x24`, no layout RNG, no category-4 commit, no
    `Branch_RecalculateRatings`, no `+0xD4`/`+0x1B8` renovation modifiers.
17. **Rating model.** Sim `update_ratings` (`1230–1250`) uses
    `coverage = min(1, staff/max(1,capacity/5))`, `expected = 12 +
    (city_prefs[g]-50)*0.02`, and its own building formula. Game rating entries are
    `Branch_GetCustomerGroupRating` (`0x47A3B0`),
    `Branch_GetMenuRating` (`0x478320`), `Branch_RecomputeMenuPriceRatings`
    (`0x4784E0`), and `Branch_RecalculateRatings` (`0x478DB0`). Even where the
    structure matches (`clamp0_100`, `/3` or `/4`), the sub-formulas are different;
    this report only guarantees the action-11 control-flow equivalence, not
    bit-exact rating values.
18. **Success/queue semantics match.** Game returns 1 and removes the action-11
    queue entry (`0x4FC713` → `0x501892` → `0x501040`); sim returns success and
    `execute_next_action` removes the entry (`tools/sim_core.py:1478–1480`). This
    part is correct.
19. **Plan weight matches.** Game 40 (`0x501422`); sim 40
    (`tools/sim_core.py:1404–1405`).

---

## 13. Calibration examples

All examples use the exact constants above. They are arithmetic checks, not
captured game runs.

### 13.1 Coverage / exterminator

State: branch site has `Game_CountFreeResidentialBuildings > 0`, no free type-`0x20`
building, no existing tier service object.

| Company `+0x108` | Tier | Charge | Ledger | Cash after |
|---:|---:|---:|---|---:|
| `25,000.0` | 1 | `1,000.0` forced | expense 5 | `24,000.0` |
| `30,000.0` | 1 | `1,000.0` forced | expense 5 | `29,000.0` |
| `30,000.5` | 2 | `10,000.0` checked | expense 5 | `20,000.5` |
| `45,000.0` | 2 | `10,000.0` checked | expense 5 | `35,000.0` |

If a free type-`0x20` building or an existing tier-1/tier-2 service object exists,
no hire and no charge.

### 13.2 Stalled-construction cleanup

For a construction order with `Game_ComputePrice = 12,000`:

| Progress `order+0xC` | `Game_ComputeCityPriceShare` | Charged category 5? |
|---:|---:|---|
| `0` | `12,000` (full price) | yes |
| `1` | `12,000 * (1-0.01) * 0.25 = 2,970` | yes |
| `20` | `12,000 * 0.80 * 0.25 = 2,400` | yes |
| `33` | `12,000 * 0.67 * 0.25 = 2,010` | yes |
| `34` | — (not selected, `0x47F315`) | no |
| `100` | `0` (`0x47F27F`) | no |

Amount = sum over all selected orders; if any selected order had progress 0, the
player object percent for type 5 is increased by 5 (`0x47F3E7`).

### 13.3 Flag priority / one branch per call

Branches (ascending index), all visible:

| Branch | `+0x2C` | `+0x28` | Action |
|---:|---:|---:|---|
| 0 | 2 (busy) | `0x02` | skipped |
| 1 | 0 | `0x24` (`0x20|0x04`) | `Branch_AutoTunePrice`; loop breaks |
| 2 | 0 | `0x0A` (`0x02|0x08`) | untouched this call |

Next action-11 call: branch 0 still skipped; branch 2 runs the flag-2 path. Branch
1’s flag `0x04` is not reached while `0x20` remains set.

### 13.4 Auto-tune search

Weights `w = [120,100,80,60,40,20,10,10]`, `sum=440`, `target = 440*4/5 = 352`.
Ratings `[60,55,51,50,45,35,30,70]`:

```text
120 + 100 + 80 + 60
+ (45-30)*40/20 = 30
+ (35-30)*20/20 = 5
+ 0                                (rating 30 is not >30)
+ 10
= 405
```

`405 > 352` → raise offset by 16 (step starts at 16). If the next recomputed
weighted sum is `340 < 352`, the direction flips, step halves to 8, and offset drops
by 8. Offset `95` raised by 16 → `111 > 99` → offset reset to `10`, cache
`+0x1714 = 0` (`0x4FF888`). Initial offset from `Branch_Construct` is already 10
(`0x476C42`).

### 13.5 Renovation fee (human branch only)

`arg5=-1`, `arg4=2`, so `units = 4 + 4*style` and
`amount = units*2500/8`:

| `branch+0x24` style | units | base fee | `+0x1B8 != 0` (×1.5) | `+0xD4 != 0` |
|---:|---:|---:|---:|---:|
| 0 | 4 | `1,250` | `1,875` | `0` |
| 1 | 8 | `2,500` | `3,750` | `0` |
| 2 | 12 | `3,750` | `5,625` | `0` |
| 3 | 16 | `5,000` | `7,500` | `0` |

Cash `79,999` forces style 0 and `branch+0x24=0` (`0x4FB70C`/`0x4FB71B`); cash
`80,000` keeps the stored style (`0x4FB717` is `jge 0x4FB727`). For an AI company
(`companySlot+0x114 != 0`) this entire table is skipped (`0x4FB92D`).

### 13.6 Menu-sales refresh

* Current hour `100`, `slot+0x44 = 90` → recompute, set `slot+0x44 = 124`.
* Next action 11 at hour `123` → no recompute.
* At hour `124` → recompute, set `148`.
* Clock `+0x0A == 0` → `Stats_SumMaskedMapFloats(recipe, -1, 0, -1)` sums every
  sales record (`0x5100B0` matches `param_2 == -1`).
* Sales `[100, 90, 20, 10]`: mean `55`, mean/2 `27`; recipes with `20` and `10`
  are removed from the menu if `companySlot+0x12A & 0x10` (`0x4FC4F5`), through
  `Recipe_SetOnMenu(company, recipe, 0)` (`0x4FC52D`).

### 13.7 Observed simulator divergence

Running the shipped simulator (no edits) with `seed=41, city_traffic=0`, one branch
`quality=55`, `supplier=False`, `price_offset=0`:

```text
before: supplier=False price_offset=0  price_percent=100 opened=True
after : supplier=True  price_offset=10 price_percent=100 opened=True
ledger: all zero
cash:   100000
```

(`tools/sim_core.py:1581–1589`). In the game, the same state has no pending branch
flag, so action 11 would **not** flip the supplier and would **not** change
`+0x14AC`; it would only run coverage/cleanup checks and the 24-hour refresh.
This is the shortest reproduction of discrepancy items 1–2 and 4–8.

---

## 14. Appendix — where “supplier checks/contracts” actually live (action 12)

This is outside action 11, included only to close the premise.

### 14.1 `AI_Action_AssignSuppliers` `0x4FD190`

* loops branches `0..branchCount-1` (`0x4FD1B4`), calls
  `AI_EnsureBranchStorage(company, companyIndex, branch)` (`0x4FD1D1`);
* switch on `branch+0x24` with empty cases 0..3 (`0x4FD1D6`);
* gets the player by `companySlot+0x40` (`0x4FD249`/`0x4FD253`), first storage
  in `player+0x180` (`0x4FD25C`/`0x4FD266`);
* reads the site from `storage+0x28` (`0x4FD273`), loops 4 supplier entries with
  `Array_GetStride60(site, i)` (`0x4FD290`), calls
  `BuildingValue_Compute(player, site, entry)` (`0x4FD29D`), keeps the first
  maximum, and calls `Storage_SetSupplierBuilding(storage, bestIndex)`
  (`0x4FD2E6`).
* no ledger entry in this function.

### 14.2 `AI_EnsureBranchStorage` `0x4FD310` (the only supplier-side cash)

* If `player+0x194 < 1` (no storage, `0x4FD339`): choose nearest house
  (`AI_FindNearestHouse` `0x4F89D0`, `0x4FD42F`) or cheapest shop
  (`AI_FindCheapestShop` `0x4F88C0`, `0x4FD44C`), `Player_BuildStorage`
  (`0x4F7710`, `0x4FD48C`), then branch on `param_1` at `0x4FD4A5`:
  * buy (nearest house): `Game_CanAffordWithCurrency(player, 0, buyPrice,
    false, -1)` (`0x4FD4EC`, category **0**, forced);
  * rent (cheapest shop): `Game_CanAffordWithCurrency(player, 2, rentPrice,
    false, -1)` (`0x4FD4EC`, category **2**, forced).
* If storage exists: if `storageLevel < min(player.branchCount>>2, 2)` and the
  storage building is free, cost `Stats_GetCombinedValue(3, storageLevel)`,
  `Game_CanAffordWithCurrency(player, 2, cost, true, -1)` (category **2**,
  affordability checked) (`0x4FD3C9`).
* Sets `branch+0x28 |= 8` (`0x4FD4FC`/`0x4FD4FF`).

No supplier **contract** fee exists in either function; the contract cost is the
storage rent/buy or the expansion charge above. The simulator’s `branch.supplier`
boolean corresponds to the `flag 8` “storage assigned” state, not to action 11.

---

## 15. Evidence and limitations

* All addresses are VA (image base `0x401000`), from
  `objdump -d -M intel game/fastfood2.exe`; jump tables were read from `.text`
  (`0x501900`, `0x50195C`, `0x50152C`).
* Decompiled bodies used for cross-checks:
  `0x4fc630.c`, `0x4fd520.c`, `0x4d5250.c`, `0x47f2e0.c`, `0x47f230.c`,
  `0x4f7c30.c`, `0x4f7b50.c`, `0x4f8d40.c`, `0x47ec70.c`, `0x4fc0f0.c`,
  `0x4ff6e0.c`, `0x47a3b0.c`, `0x478320.c`, `0x4784e0.c`, `0x478db0.c`,
  `0x4fb660.c`, `0x4fb170.c`, `0x4fc5f0.c`, `0x4fc470.c`, `0x47c5e0.c`,
  `0x477e40.c`, `0x477c80.c`.
* Float operands dropped by the decompiler were recovered from raw IEEE-754
  constants: `30000.0` at `0x55C640`, `0.01` at `0x55C430`, `0.25` at `0x55C434`,
  `10.0` at `0x55C328`, and the `1000.0`/`10000.0` immediate pushes at
  `0x4D5307`/`0x4D532D`.
* Names such as `Customer_VisitBranch`, `Game_CountActiveCompanies`,
  `Company_OpenBranchAtSite`, and `Company_CollectUnprofitableBranches` are the
  shipped symbol-table names but are semantically misleading; the report gives the
  observed behavior and the relevant offsets. In particular:
  * `Customer_VisitBranch` = branch layout/rebuild routine;
  * `Game_CountActiveCompanies` / `GetActiveCompanyById` = active **recipe**
    counters;
  * `Company_OpenBranchAtSite` = menu-product creation;
  * `Company_CollectUnprofitableBranches` = low-selling **recipes**.
* The action-11 path is AI-only (`companySlot+0x114 != 0`); the category-9
  renovation fee is human-only. The simulator runs action 11 for AI companies, so
  the fee is normally not observable there, but the rest of the control flow is.
* Static decode, no live game execution. Rating sub-formulas are cited by function
  and key constants, but the report does not claim bit-exact equality of the whole
  rating stack; the simulator’s rating model is a separate reconstruction.
