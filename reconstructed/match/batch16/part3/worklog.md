# batch16 part3 worklog

Scope: 25 functions from `reconstructed/match/batch16/part3.json`.
Toolchain: `~/.local/share/pc2/vc6-sp3-toolchain/VC98` (MSVC 6.0 SP3, C2.DLL
12.00.8447); `reconstructed/match/runtime01/verify_strict.sh` reports 6/6.
Every accepted function is genuine C/C++ and passes
`tools/match_decomp.py --strict --auto-symbols` with the manifest length and
the exact candidate entry symbol.

## Result: 7 / 25 strict matches

Reproduce with:

```sh
sh reconstructed/match/batch16/part3/verify_strict.sh
```

Matches:

| address | function | flags | entry |
| --- | --- | --- | --- |
| 0x47ff10 | Game_GetConstructionPriority | /O2 /TP | `?GetConstructionPriority@Game@@QAEHXZ` |
| 0x478320 | Branch_GetMenuRating | /O2 /TP | `?GetMenuRating@Branch@@QAEHH@Z` |
| 0x48c7b0 | Game_GetRatingPercent | /O2 /TP | `?GetRatingPercent@Game@@QAEHHH@Z` |
| 0x4c3070 | FurnitureMenu_InitChairPage | /O2 /TP | `_FurnitureMenu_InitChairPage` |
| 0x4e0880 | Game_FindDailyStatRecord | /O2 /TP | `?FindDailyStatRecord@Game@@QAEHHIH@Z` |
| 0x4edbf0 | Map_DrawRecordLinkSprites | /O2 /TP | `?DrawRecordLinkSprites@Map@@QAEXHPAX@Z` |
| 0x51eb50 | Renderer_DrawPendingSprite | /O2 /TP | `?DrawPendingSprite@Renderer@@QAEHHPAH@Z` |

Notes:

- `0x47ff10` resolves the `CountFreeBuildingsByType` call through the decorated
  alias path: the candidate class is named `Game`, so
  `?CountFreeBuildingsByType@Game@@QAEHH@Z` demangles to
  `Game_CountFreeBuildingsByType`, which the shipped symbol map places at
  `0x4d2ae0`. No explicit `--symbol` is required.
- `0x51eb50` calls the imported `SetRect` through its IAT slot and makes the
  release call through the sprite vtable; both gates are satisfied by
  `--auto-symbols` (PE IAT) and the original indirect call (no relocation).
- `0x4c3070` mixes thiscall helpers with cdecl `UI_Group_Create` and
  `UI_Group_Rating_UpdateBarByKey`; the candidate keeps the shipped argument
  and call order.

## Non-matching evidence

The following are genuine C/C++ attempts. Sources and full
`match_decomp.py` reports are in `nonmatching/`.

| address | function | first diff (offset: original vs candidate) | differing bytes |
| --- | --- | --- | --- |
| 0x4793b0 | Stats_ComputeOccupancyPercent | 0x02: 0x0c vs 0x08 | 112 |
| 0x49c5d0 | CompanyRanking_SelectLastCompanyButton | 0x3c: 0x0d vs 0x44 | 58 |
| 0x4cb480 | FreePlaySetup_RefreshPlayerProfiles | 0x03: 0x8b vs 0x57 | 108 |
| 0x4dcb70 | Random_SwapOneOfFour | 0x01: 0x8b vs 0x56 | 113 |
| 0x4e2a90 | AI_GetTopActionIndices | 0x08: 0x53 vs 0x55 | 106 |
| 0x4ef110 | Object_InsertSortedByScreenY | 0x0c: 0xd2 vs 0xed | 105 |
| 0x4f7b90 | AI_ComputePlanScores | 0x05: 0x8b vs 0x53 | 106 |
| 0x4fc990 | UI_ShiftRowData | 0x04: 0x55 vs 0x53 | 95 |
| 0x531330 | BinarySearch8 | 0x03: 0x8b vs 0x56 | 149 |
| 0x534790 | Record_GetScreenOffset | 0x04: 0x53 vs 0x56 | 130 |
| 0x54adc0 | UI_OpenBriefing | 0x00: 0x56 vs 0x57 | 117 |

All first differences are register-allocation, block-layout, or FP-stack
scheduling differences; the shipped code and each candidate perform the same
operations. `0x4e2a90` also exercises the qsort comparator at `0x4e2b40`; that
address is the immediate pushed by the original call site at `0x4e2af7`, and
the attempt records the explicit mapping used for the check.

## Not attempted

No candidate was produced for these manifest entries:

- `0x409bb0` Customer_ApproachBranchEntrance
- `0x480d80` Game_ApplyOwnerWideObjectEvent
- `0x490100` FurnitureMenu_SetItemSprite
- `0x492390` RenovationScreen_UpdatePage
- `0x49c520` CompanyRanking_SelectCompanyButton
- `0x4f1ab0` Object_TryStepToTile
- `0x53a060` Sprite_ClearBuffers

## Cleanliness

Only sources under `reconstructed/match/batch16/part3/` and their strict
verifier are tracked. Generated COFF objects and toolchain files are not
committed.
