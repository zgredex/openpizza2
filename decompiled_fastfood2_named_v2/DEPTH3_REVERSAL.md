# Non-leaf reversal — depth 3 complete (131/131)

Depth 1 and depth 2 are complete. **The frozen depth-3 set is also complete: 131/131 named, 0 unnamed.** The ledger now contains 918 non-leaf names.

## Completion verification

Fresh REA export in `depth3_verification/`, checked against the frozen 131-address depth-3 set:

```text
initial depth3: 131
named in REA export: 131
unnamed: 0
func_symbols: 918  unique addresses: 918  unique names: 918
initial depth3 in ledger: 131
```

## Named in this wave

| Address | Name | In-degree | Evidence |
|---|---|---:|---|
| `0x4d5dd0` | `Game_ComputeTradeOffers` | 11 | Computes trade/offer candidates for a player and city. |
| `0x4e6300` | `Game_SetModeByte` | 8 | Stores a mode byte and queues a UI command when active. |
| `0x505260` | `UI_DestroyChildObject` | 6 | Destroys a child object and unregisters its records. |
| `0x521740` | `UI_DrawChildSprite` | 6 | Draws the child sprite with a computed color. |
| `0x5344e0` | `Record_DrawSprite48` | 5 | Draws a sprite from a stride-0x48 record. |
| `0x531bb0` | `Movie_CreatePlayer` | 5 | Creates a Bink/movie player window. |
| `0x50b090` | `UI_HitTestChildPoint` | 5 | Hit-tests a point against a child sprite. |
| `0x47e470` | `Game_GetHourlyValue` | 4 | Returns an hourly array value with wrap-around. |
| `0x4ede90` | `UI_DrawObjectSprite` | 4 | Computes and blits an object sprite. |
| `0x4c70b0` | `UI_SetMultipleLabels` | 4 | Sets text on a list of UI object ids. |

## Status

- Four parallel reviewers are analyzing batches of 33 and writing `depth3_proposals_1..4.csv`.
- Durable ledger: `func_symbols.csv`.
- Next: merge proposals, annotate in REA, then verify with a fresh export.
