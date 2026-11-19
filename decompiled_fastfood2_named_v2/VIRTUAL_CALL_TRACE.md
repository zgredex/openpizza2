# Virtual calls reached by one customer visit

Trace method: start from the customer/order roots, walk direct calls in the
named export, and collect `(**code)`, `(code *)` and vtable-slot expressions.
The walk is deliberately conservative: it reaches 673 functions, including CRT
and window cleanup, so only sites exercised by the customer-order branch are
listed below. The quality scorer and order settlement contain no virtual
calls.

## Resolved targets

| Call site | Expression / slot | Target | Inputs | Return / side effects | Evidence |
|---|---|---|---|---|---|
| `Branch_ComputeWorkDuration` `0x47d340:50` | `List` vtable `0x55c2ec` slot 0 | `List_Node_Delete` `0x401420` | `this_00` = list returned by `Branch_CollectOrdersByCategory` `0x47d270` | Frees list nodes; no queue/stock/cash change | `vtable_slot_targets.csv`; `Branch_CollectOrdersByCategory` constructs a `List` |
| `AI_ChooseWalkTarget` `0x4f5310:112` | List vtable slot 0 | `List_Node_Delete` `0x401420` | `this_01` = `Grid_CollectFootprintCells` result | Frees list; no game-state change | `vtable_slot_targets.csv`; function body |
| `Object_FindNearbyCustomer` `0x50b7c0:66` | List vtable slot 0 | `List_Node_Delete` `0x401420` | `this_00` = `Map_CollectObjectsOnFlaggedTiles` result | Frees list; no game-state change | `vtable_slot_targets.csv`; function body |

## Dynamic platform targets

These are real virtual calls in the customer visit, but the target is selected
at runtime from the audio backend. They do not alter queue, stock or cash and
can be compatibility stubs in the Rust rewrite.

| Call site | Slot | Inputs | Observed effect | Status |
|---|---|---|---|---|
| `Sound_HandleEvent` `0x548210:34` | backend `+0x8` slot `0xf4` | sound object, event id `0x32` from production finish | Starts the cooking/finish sound | Target absent from the current vtable CSV; **R** |
| `Sound_SetParam` `0x547300:19` | backend slot `0x7c` | sound object, event id, value | Sets a sound parameter | **R** |
| `Sound_SetParam` `0x547300:21` | backend slot `0x5c` | sound object, event id, value | Sets a sound parameter | **R** |
| `Sound_ProcessEvent` `0x5499f0:103` | backend slot `0x7c` | sound object, event | Movement/ambient sound event | **R** |
| `Sound_ProcessEvent` `0x5499f0:106` | backend slot `0x5c` | sound object, event | Movement/ambient sound event | **R** |

The `Sound_*` wrappers accept a sound object (the game sound manager) and an
event id; the virtual receiver is the backend object stored at `+0x8`. The
caller cannot be modeled from the static export alone because the backend
vtable is chosen when DirectSound is initialized. This is exactly the kind of
compatibility contract the rewrite preparation should record rather than
guess.

## Not reached in this path

- No virtual calls in `0x47d910`, `0x5092b0`, `0x509580`, `0x47d4a0`,
  `0x5139e0` or `0x513760`.
- Window/UI virtual calls appear in the broader call graph but are outside the
  customer-order subgraph; they belong to a separate UI compatibility batch.

## Replay contract

Resolved list cleanup contributes no state. The only observable state changes
in this visit remain the queue, batch quantities and ledger postings. Sound
calls are effects-only and may be stubbed with the recorded event ids.
