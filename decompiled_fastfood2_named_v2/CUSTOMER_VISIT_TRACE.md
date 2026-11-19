# One customer visit: state table and worked traces

Scope: one small branch (`branch_type = 0x0F`, the shipped
`Iso_Filiale_einf_klein.iso` template), one customer group (`group 0`), one
recipe, party size 1, and the default open-hour path. Values are for the
shipped executable `game/fastfood2.exe` (SHA-256
`18cfd32e0ac5d6d98162ec016e058a2b51808d9ca49ebee933ce3166ff9922fd`).

Confidence labels:

- **S** — directly read from the retained pseudocode.
- **I** — inferred from decoded field layout or the Python contract; exact
  branch/constant still needs runtime confirmation.
- **R** — requires an original-game runtime observation.

Timer conventions: `Game_GetTimeByMode` writes the countdown at object `+0x44`
and its reset copy at `+0x48`. The loop is nominally 100 ticks/second
(`GameLoop_DispatchScreens`, 10 ms per iteration), so 80 ticks = 0.8 s and 180
ticks = 1.8 s. Walk frames use the animation delay of 12, about 83 ms per path
cell.

## Fields used by the trace

| Field | Meaning | Evidence |
|---|---|---|
| branch `+0x1744` | queue/interior list | **S** `Branch_Load`/`Branch_Save` `0x47b000`/`0x47b9e0`; `Screen_AddRecordToList` `0x47d230` |
| branch `+0x1758` | number of entries in `+0x1744`; `Branch_Save` loops this count | **S** `0x47b9e0` |
| branch `+0x16e0` | lost/abandoned customer counter | **S** `Object_UpdateCustomerQueue` `0x409d80` |
| branch `+0x16d4` | recipe/order-attempt failure counter | **S** `Action_AddBestRecipeToBranchMenu` `0x509580` |
| branch `+0x1a24` | "no ingredients" retry flag | **S** `Object_UpdateProductionWorker` `0x40a380` |
| branch `+0x1728` | production order queue | **S** `0x40a380`; `Branch_Save` |
| customer `+0x38` | object state | **S** all state machines |
| customer `+0x94` | current action countdown | **S** `0x409d80`, `0x40a380`, `0x409350` |
| customer `+0x98` | party size, `(Rating_GetComposite >> 4) + 1` | **S** `Object_UpdateCustomerQueue` `0x409d80` |
| customer `+0x164` | customer record id used in the branch queue list | **S** `Screen_AddRecordToList` `0x47d230` |
| batch `+0` | available units | **S** `Branch_ProcessCustomerOrder` `0x47d4a0` |
| batch `+4` | batch age/order key used to choose the oldest batch | **S** `0x47d4a0` |
| batch `+0x10` | unit cost | **S** `0x47d4a0` |

The queue-capacity field is **not proven**. `SIMULATION.md` records
`branch+0x1758` as “queue/interior capacity”, but `Branch_Save` reads it as the
number of entries in `+0x1744`. The Python model uses a 40-seat constant. The
full-queue trace below therefore marks the capacity comparison **I/R**.

## State table

| # | State / transition | Address and guard | Timer | Next state | Queue | Stock / cash | Confidence |
|---|---|---|---|---|---|---|---|
| 1 | Hour start, spawn walk-in | `Branch_ProcessHour 0x4773a0`; open-hour byte `Game_GetHourlyValue(branch,0) != 0`; calls `Branch_SpawnWalkInCustomer 0x477190` | one spawn per open branch-hour | traveling customer | unchanged | unchanged | **S** |
| 2 | Choose group and route | `0x477190`; `Random_RangeFast(0,7)` group; `AI_ComputePath` must return a path; creates record and planted-person tile | path setup | walk to entrance | record is appended to the branch’s pending list (`+0x19e0`), not yet the interior queue | unchanged | unchanged | **S** |
| 3 | Approach entrance | `Customer_ApproachBranchEntrance 0x409bb0`; neighbor route record exists | walk-frame delay: 83 ms per cell | object state `8` (walking) | unchanged | unchanged | **S** movement; **I** 83 ms from animation template |
| 4 | Arrival / queue handoff | `Person_ProcessMoveEvent 0x50adf0`, customer type `0x13` branch; `Person_CanContinuePath` result chooses detach/truncate | `Game_GetTimeByMode(customer,7)` = 10 ticks (0.1 s) | object state `6`; `SetChildField2C(0x10)`; UI state `0x12` | customer becomes eligible for the interior queue; `+0x1744` add occurs through `Screen_AddRecordToList 0x47d230` | unchanged | **S** for state/timer; **I** for exact queue insertion point |
| 5 | Queue admission | `Object_UpdateCustomerQueue 0x409d80`; seat/party check is not a single named function in the retained export | no timer on admission; rejection is immediate | accepted: queue state; rejected: lost path | accepted: party added to `+0x1744`; rejected: `+0x16e0 += 1` | unchanged | **I/R** capacity comparison; **S** lost counter |
| 6 | Queue wait / walk to slot | `Object_UpdateCustomerQueue` cases `0xc`/`0xf`; customer `+0x10c` target lookup; branch object state `0xb` gate | queue entry transition uses mode `4`: `0x104 ± 10` ticks (2.50–2.70 s) for branch `0x0F`; service mode `6` = 80 ticks (0.8 s) | state `0x10` or `0x11`/`0x18` depending on target | customer moved from queue list into service slot | unchanged | **S** for timers; **I** for exact queue-slot mapping |
| 7 | Production worker picks recipe | `Object_UpdateProductionWorker 0x40a380` state `0x10` (and visible); branch order queue nonempty; calls `Action_AddBestRecipeToBranchMenu 0x509580` | no timer until recipe selected | worker state `0xE` on success; UI state `10` on failure | queue unchanged at selection time | see settlement below | **S** |
| 8 | Price and recipe scoring | `Action_AddBestRecipeToBranchMenu 0x509580`; price from `Branch_ComputeRecipePrice 0x513bf0`; score from `Game_ComputeObjectDetails 0x5092b0` | none | sorted candidate list, then selected recipe | none | none | **S** formula; **R** exact score weighting |
| 9 | Settlement / stock consumption | `Branch_ProcessCustomerOrder 0x47d4a0`; `local_1a8 = available_units / recipe_units`; returns 0 when zero | none | success: return servings; failure: return 0 | unchanged | success: batch qty decreases; cash postings occur; failure: no stock/cash change | **S** control flow; **I/R** exact cash ledger split |
| 10 | Cooking | `Object_UpdateProductionWorker 0x40a380` state `0xE`; decrements `customer+0x94`; on zero looks up target state | `Branch_ComputeWorkDuration 0x47d340`: 180 ticks (1.8 s) when no prepared order; otherwise composite-based | worker UI variant 10; state `8`/serve; `Screen_AddRecordToList` when target state `0xb` | queue holds waiting customer | unchanged after settlement | **S**; exact 180-tick path **S** when `local_c < 1` |
| 11 | Service / eating | `Person_SitAndEatPizza 0x409350` states `0x1b`, `0x23`, `0x24`; `Object_UpdateCustomerQueue` state `0x10` also uses `+0x94` | service mode `6` = 80 ticks (0.8 s) | `0x18` walk-out, then `0x1f` remove child; queue state advances | queue entry removed after service | unchanged | **S** state/timer; **I** seat/eat event order |
| 12 | Departure | `Person_SitAndEatPizza` state `0x1b` expiry → `Object_SetState(0x18)`; `Person_ProcessMoveEvent` → state `6`/`7`; `Person_LeaveBuildingAndReset 0x5087c0` | walk-out uses animation delay; no order timer | customer leaves building / is removed from tracking | queue empty | unchanged | **S** exit calls; **I** full path duration |

## Worked trace A — successful order

Starting state: open branch, one recipe priced **12.00**, unit cost **4.00**,
rating **50**, stock **400**, cash **10000**, queue **0 seats**, party size
**1**.

| Step | Function/condition | Queue | Stock | Cash | Timer/next |
|---|---|---:|---:|---:|---|
| A1 | `Branch_ProcessHour 0x4773a0` sees open hour; `Branch_SpawnWalkInCustomer 0x477190` creates group 0 and path | 0 | 400 | 10000.00 | travel begins; 83 ms/cell |
| A2 | `Customer_ApproachBranchEntrance 0x409bb0` reaches entrance | 0 | 400 | 10000.00 | state 8 → move event |
| A3 | `Person_ProcessMoveEvent 0x50adf0` type `0x13`; mode 7 | 1 | 400 | 10000.00 | 10 ticks; queue state |
| A4 | `Object_UpdateCustomerQueue 0x409d80` admits party 1 | 1 | 400 | 10000.00 | mode 4: 250–270 ticks |
| A5 | `Object_UpdateProductionWorker 0x40a380` calls `Action_AddBestRecipeToBranchMenu 0x509580`; price = `12.00`; one recipe selected | 1 | 400 | 10000.00 | cooking job queued |
| A6 | `Branch_ProcessCustomerOrder 0x47d4a0`: one batch, oldest batch `+4=4.00`; consumes 1; market factor `0.0948688219` | 1 | **399** | **10013.420525** | sale record: revenue **13.80**, market cost **0.379475**; worker timer **180 ticks** |
| A7 | Cooking state `0xE` expires | 1 | 399 | 10013.420525 | service handoff; mode 6 = **80 ticks** |
| A8 | Service/eat state expires | 0 | 399 | 10013.420525 | state 0x18 walk-out |
| A9 | Departure `Person_LeaveBuildingAndReset 0x5087c0` | 0 | 399 | 10013.420525 | removed from tracking |

Reconciliation: `cash_after - cash_before = 13.80 - 0.3794752876 =
13.4205247124`, matching the Python contract test
`tests/test_sim_core.py::test_one_sale_python_contract`. The **stock-cost 4.00
was already paid when the batch was delivered**, so it is not charged again at
the sale; `Branch_ProcessCustomerOrder` separates batch consumption from the
market-cost posting.

**Confidence:** stock 400→399 and the order formula are **S/I** from
`0x47d4a0`; the +13.4205247 net is **I** from the Python ledger contract and
needs a cash-ledger runtime check because `Game_CanAfford` posts two ledger
categories at `0x47d8xx`.

## Worked trace B — full queue

Controlled boundary: queue already contains **38 seats**, capacity **40**,
arriving party size **3**.

| Step | Function/condition | Queue | Stock | Cash | Timer/next |
|---|---|---:|---:|---:|---|
| B1 | `Branch_ProcessHour 0x4773a0` open; spawn group 0, party 3 | 38 | 400 | 10000.00 | travel begins |
| B2 | `Customer_ApproachBranchEntrance 0x409bb0` reaches entrance | 38 | 400 | 10000.00 | state 8 |
| B3 | Queue admission check `38 + 3 > 40` | 38 | 400 | 10000.00 | reject; no queue state |
| B4 | Rejection path increments branch `+0x16e0`; customer walks away | 38 | 400 | 10000.00 | no production worker call |

Boundary control: party **2** gives `38 + 2 = 40`, accepted; party **3**
overflows. This comparison is the Python model’s exact structure, but the
original capacity field/constant was not located in a named function, so the
comparison is **I/R**. The lost counter `+0x16e0` is **S**.

## Worked trace C — missing ingredients

Starting state: open branch, one recipe, **stock 0** (or fewer than one
recipe’s ingredient units), cash 10000, queue 1 waiting customer.

| Step | Function/condition | Queue | Stock | Cash | Timer/next |
|---|---|---:|---:|---:|---|
| C1 | Queue/worker request reaches state `0x10`; `Object_UpdateProductionWorker 0x40a380` calls `Action_AddBestRecipeToBranchMenu 0x509580` | 1 | 0 | 10000.00 | none yet |
| C2 | `0x509580` chooses a candidate and calls `Branch_ProcessCustomerOrder 0x47d4a0` | 1 | 0 | 10000.00 | none |
| C3 | `0x47d4a0`: total recipe usage > 0; available batch units `iVar9 = 0`; `local_1a8 = iVar9 / iVar13 = 0`; returns **0 before** batch/cash loop | 1 | **0** | **10000.00** | no settlement |
| C4 | `0x509580` sees null result; increments branch `+0x16d4`; frees candidate | 1 | 0 | 10000.00 | worker receives failure |
| C5 | `0x40a380` prints `"Keine Zutaten"`, sets branch `+0x1a24 = 1`, UI state `10`, `Game_GetTimeByMode(…,7)` | 1 | 0 | 10000.00 | **10 ticks (0.1 s)** retry gate |

No stock batch is consumed and no cash posting is reached. The queue is
unchanged; the waiting customer is not served. The `+0x16d4` and `+0x1a24`
writes and the early return are **S**; the exact retry behavior after the
10-tick gate is **I/R**.

## Price path and what it changes

`Branch_ComputeRecipePrice 0x513bf0`:

```text
price = recipe_unit_price * (price_percent * 0.01 * building_value) + price_offset
```

`0x509580` calls it with `param_3 = -999`, so it uses branch `+0x14a8`
(price percent) and `+0x14ac` (offset). The price is stored on the candidate and
passed to `Game_ComputeObjectDetails 0x5092b0`; the candidate list is sorted by
the returned score. Disassembly resolves the score return as
`clamp(0..100, trunc((branch+0x14c0 + 100) * quality * 0.01))`; the raw
market/price score is only written to optional output pointers, and `0x509580`
passes those as null. Therefore the selected rank is quality-based in this
caller: a price change’s effect on **which** recipe wins through the candidate
price is **R/unproven**, while its effect on the selected recipe’s revenue is
the exact `(100 + tip) * servings * price * 0.01` formula. Selection bands:
roll 51–100 → rank 0, 21–50 → rank 1, 6–20 → rank 2, 1–5 → uniform.

## Virtual dispatch in the visit

[VIRTUAL_CALL_TRACE.md](VIRTUAL_CALL_TRACE.md) records the indirect calls
reached by this path. List cleanup resolves to `List_Node_Delete 0x401420`
(vtable `0x55c2ec` slot 0) from the work-duration and walk-target helpers.
Sound wrappers reach runtime-selected DirectSound backend slots and are
effects-only. The quality scorer and order settlement have no virtual calls.

## Still needed from the original

- A paused branch capture with a known customer group, party size and queue
  occupancy.
- Observation of the queue-capacity field and the exact rejection branch.
- A cash-ledger capture showing the two `Game_CanAfford` postings in
  `0x47d4a0`.
- Whether `Player_ComputeProductQualityScore`/`Game_ComputeObjectDetails`
  consumes recipe price internally; the caller passes no candidate price to
  that function. Tie/rank random draws also need a controlled multi-recipe
  runtime capture.
- One controlled sale with before/after cash and batch quantity.

These are runtime evidence gaps. The state table now drives the Rust `World`
visit model and deterministic replay ([CLOCK_TRACE.md](CLOCK_TRACE.md)), but
the admission, timing and settlement values still need original runtime
confirmation.
