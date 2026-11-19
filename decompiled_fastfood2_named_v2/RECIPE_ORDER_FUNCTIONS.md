# Recipe pricing → scoring → selection → settlement

Function cards for the production-worker purchase path. Each card records the
original address, callers, inputs, return value, state read/written, and the
current controlled test. The integration trace is
[CUSTOMER_VISIT_TRACE.md](CUSTOMER_VISIT_TRACE.md).

## 1. `Branch_ComputeRecipePrice` — `0x513bf0`

**Callers**

- `Action_AddBestRecipeToBranchMenu` `0x509580` (passes `-999` for the percent)
- `Branch_RecomputeMenuPriceRatings` `0x4784e0`
- `CityBuildingListPage_Update` `0x4962e0`
- `CompareScreen_UpdateRows` `0x496680`
- `CompanyBranches_InitBranchRows` `0x4b98e0`

**Inputs**

| Input | Source |
|---|---|
| recipe base unit price | `Get_Float44(recipe)` |
| price percent | argument, or branch `+0x14a8` when argument is `-999` |
| building value | `Branch_GetBuildingValue(branch)` |
| price offset | branch `+0x14ac` |

**Return value**

`float10` menu price:

```text
price = recipe_base * (price_percent * 0.01 * building_value) + price_offset
```

**State**

Reads recipe float 44, branch `+0x14a8`, `+0x14ac` and the building value.
No writes.

**Controlled tests**

- `crates/sim/src/lib.rs::tests::recipe_price_0x513bf0_matches_python_contract`
  checks `(10,100,1,+10) = 20`, `(10,50,1,+10) = 15`,
  `(12,100,1,0) = 12`, `(12,200,2,+3) = 51`.
- The same values are asserted by
  `tests/test_sim_core.py::test_recipe_price_formula` for the Python model.

**Status:** formula and caller path are **static**; the four callers above are
from cross-reference strings in the pseudocode export. Exact rounding mode of
the original x87 `float10` path still needs a runtime check at a non-integer
price.

## 2. `Game_ComputeObjectDetails` — `0x5092b0`

**Callers**

- `Action_AddBestRecipeToBranchMenu` `0x509580` (candidate scoring)

**Inputs**

| Input | Meaning |
|---|---|
| `this` | production/order context |
| `param_1` | order record; caller identity fields at `+0x08` and `+0x2c` |
| `param_2` | candidate pair: recipe pointer at `[0]`, menu price at `[1]` |
| optional pointers | skill, quality, market detail and score outputs |

**Return value**

The candidate score is returned in EAX (`0x509580` stores it in the candidate's
second slot) and through the last optional output pointer. Skill/quality/detail
outputs are optional.

**Disassembly resolution of `extraout_EDX` / `unaff_EDI`**

The Ghidra placeholders are not real function inputs. The bounded disassembly
at `0x5092b0` establishes:

```text
Game_GetSkillRating(recipe, branch, price, category)
Player_ComputeProductQualityScore(branch, recipe, category)
```

- `recipe` comes from `param_2[0]`, `price` from `param_2[1]`, `branch` from
  the earlier `Game_GetPlayerSubmapValue` call.
- The score path accumulates market value adjustments and price modifiers into
  the optional raw-score output.
- The **returned** value is a separate quality/building score:
  `clamp(0..100, trunc((branch+0x14c0 + 100) * quality * 0.01))`, with
  `+0x14c0` used only when `+0x14c4 != 0`.
- `0x509580` passes all optional output pointers as null and ranks candidates by
  the returned EAX score.

**Controlled tests**

- `candidate_score_0x5092b0_matches_disassembly` checks the returned formula:
  `(55,0)=55`, `(55,20)=66`, `(70,15)=80`, `(100,100)=100`, `(0,50)=0`.
- `scoring_selection_settlement_0x5092b0_0x509580_0x47d4a0` connects score,
  rank selection and settlement.

**Status:** returned-score formula and register roles are **S** from
disassembly. Whether `Player_ComputeProductQualityScore` consumes recipe price
internally is still **R**; the caller passes no candidate price to that
function. The raw market/price score is **I** until its optional outputs are
tested against a runtime fixture.

## 3. `Action_AddBestRecipeToBranchMenu` — `0x509580`

The name is misleading: this function builds a candidate list, prices and
scores it, selects one, then processes a customer order.

**Caller**

- `Object_UpdateProductionWorker` `0x40a380` (state `0x10`)

**Inputs**

| Input | Meaning |
|---|---|
| `this` | branch object |
| `param_1` | order record; if null, `this+0xf4` is used |

**Return value**

The selected order's `Branch_ProcessCustomerOrder` result: servings on success,
`0` on failure.

**State**

Reads active companies and player/submap branch data. For each candidate it
creates a 0x30-byte record:

```text
[0] recipe/company key
[1] menu price
[2] order/context value
[3] score
[4] current worker/order value
```

It sorts candidates by score descending. With fewer than four candidates it
chooses uniformly. With four or more, a 1..100 roll selects rank 0 for 51–100,
rank 1 for 21–50, rank 2 for 6–20, and a uniform candidate for 1–5. On no
candidate it increments branch `+0x16da`; on a null order result it increments
`+0x16d4`; on success it updates stats, mission events and the advisor tip.

**Tests**

- `price_from_recipe_drives_next_sale_0x513bf0` feeds a computed price into the
  Rust sale path.
- `candidate_rank_0x509580_matches_bands` checks the 51/21/6 bands and uniform
  fallback.
- `scoring_selection_settlement_0x5092b0_0x509580_0x47d4a0` runs two scored
  candidates through selection and one sale.
- One-recipe selection is exercised by the successful replay in
  `CUSTOMER_VISIT_TRACE.md`.

**Status:** selection control flow and price input are **static**; the score
weighting and exact random-band behavior need runtime traces with a controlled
menu.

## 4. `Branch_ProcessCustomerOrder` — `0x47d4a0`

**Caller**

- `Action_AddBestRecipeToBranchMenu` `0x509580` (only named caller in the
  exported function set)

**Inputs**

| Input | Meaning |
|---|---|
| `this` | branch |
| `param_1` | order record; `[0]` recipe pointer, `[1]` menu price, `[2]` requested units/context, `[4]` customer record key |
| `param_2` | mode flag used for the prepared/queue path |

**Return value**

`local_1a8`: number of servings actually produced, or `0` on failure. A zero
return is the missing-ingredient/empty-stock path.

**State read**

- customer object via `IDMap_Lookup(DAT_0057c670+0x3c, param_1[4])`;
- recipe usage counters at recipe `+100..+0x258` (86 integers);
- branch batch map at `+0x1998`, batch count at `+0x19ac`;
- branch/company/market records;
- branch type and customer group for the tip.

**State written**

- batch `+0` quantity, oldest batch `+4` key and unit cost `+0x10`;
- branch/company sales and ingredient/market ledger postings through
  `Game_CanAfford`;
- order record: `[7]` revenue, `[5]` servings, `[8]` prepared/queue value,
  `[6]` revenue minus cost, `[9]` tax/constant, `[10]` branch field,
  `[0xb]` customer group;
- `Recipe_AppendSalesRecord` appends the transaction.

**Exact control points**

1. If `param_1 == null`, return `0`.
2. If the customer branch type is `0x0B`, serving quantum is 200; otherwise
   100.
3. Sum recipe usage (`iVar13`) and available batch units (`iVar9`).
4. If `iVar9 < usage * quantum`, set servings to `iVar9 / usage`; otherwise use
   the quantum.
5. If servings is `0`, return `0` before any batch, stock or cash write.
6. Choose the oldest batch (`batch[+4]` smallest) with nonzero units, subtract
   `min(remaining, batch units)`, and accumulate unit-cost × quantity ×
   weighted market factor.
7. Apply `Game_GetMarketBonusFactor`, post the cost/revenue through
   `Game_CanAfford` (ledger `0x13` for the cost path, `0x0c`/`0x12` for the
   ingredient path), then write the sale record and append it.

**Controlled tests**

- `one_sale_matches_python_case`: stock 400→399, revenue 13.80, stock cost 4.00,
  market cost 0.3794752876, cash +13.4205247124.
- `shortage_0x47d4a0_posts_nothing`: stock 0, open step returns `StockOut`,
  cash stays 10000, sales stay 0, lost counter becomes 1.
- `tests/test_sim_core.py::test_one_sale_python_contract` is the Python
  reference for the same fixture.

**Status:** batch selection, early-return guard and returned serving count are
**static**. The exact ledger split inside `Game_CanAfford` and the two-call
accounting are **I/R**; the Python fixture fixes the net cash delta.

## Replay order

The tests connect the cards in this order:

```text
candidate_score(quality, offset)  /  candidate_rank bands
        ↓
recipe_price(12,100,1,0) = 12
        ↓
BranchSim::set_price_from_recipe(...)
        ↓
BranchSim::step()
        ↓
one_sale_matches_python_case  /  shortage_0x47d4a0_posts_nothing
```

The remaining blocker before a fully original-faithful replay is the
table-driven `Game_ComputeObjectDetails` fixture and a runtime cash-ledger
capture. The successful and shortage traces are already frozen in
`crates/sim/src/lib.rs` and `CUSTOMER_VISIT_TRACE.md`.
