# Non-leaf reversal — depth 4 complete (55/55)

Depth 1–3 are complete. **The frozen depth-4 set is also complete: 55/55 named, 0 unnamed.** The ledger now contains 973 non-leaf names.

## Completion verification

Fresh REA export in `depth4_verification/`, checked against the frozen 55-address depth-4 set:

```text
initial depth4: 55
named in REA export: 55
unnamed: 0
func_symbols: 973  unique addresses: 973  unique names: 973
initial depth4 in ledger: 55
```

## Named in this wave

| Address | Name | In-degree | Evidence |
|---|---|---:|---|
| `0x50e890` | `Object_SetState` | 57 | Stores state +0x38 and cleans up states 0x1f/0x2e. |
| `0x5311a0` | `UI_RemoveObject` | 24 | Removes a UI object by key and unregisters it. |
| `0x4d2960` | `Game_RemoveObjectFromList` | 10 | Removes an object from the game list and clears fields. |
| `0x535740` | `Font_DrawTextLine` | 8 | Lays out/draws a text line using font widths. |
| `0x54bf70` | `Sound_UpdateListener` | 7 | Updates 3D sound listener parameters. |
| `0x4d28f0` | `Game_AddObjectToList` | 5 | Adds an object to the game list and binds its owner. |
| `0x4ee370` | `Map_RenderObject` | 4 | Renders one map object into the surface list. |
| `0x52ef20` | `UI_SetWindowBounds` | 4 | Updates UI window bounds and child layout. |
| `0x4e6170` | `Game_UpdateObject` | 3 | Updates a game object from its current state. |
| `0x54aec0` | `UI_AddBriefingButton` | 3 | Creates a briefing button and its label. |
| `0x4fc990` | `UI_ShiftRowData` | 3 | Shifts row data for a UI/player table. |
| `0x521b90` | `UI_DetachObject` | 3 | Detaches a UI object from its parent and clears state. |
| `0x4ee840` | `Map_RenderObjectList` | 2 | Renders a list of map objects. |
| `0x4e6020` | `Game_UpdateObject2` | 2 | Second game-object state update path. |
| `0x50d310` | `Game_ComputeObjectValue` | 2 | Computes object value by state and player data. |

## Status

- Durable ledger: `func_symbols.csv`.
- Next: finish the remaining depth-4 candidates, then verify with a fresh export.
