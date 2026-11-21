# batch15 part1 worklog

Scope: 25 functions from `reconstructed/match/batch15/part1.json`.
Toolchain: `/tmp/opencode/vc6-sp3-toolchain/VC98` (MSVC 6.0 SP3, C2.DLL
12.00.8447). Every accepted function is genuine C/C++ and passes
`tools/match_decomp.py --strict --auto-symbols` with the manifest length and
the exact candidate entry symbol.

## Result: 16 / 25 strict matches

Reproduce with:

```sh
sh reconstructed/match/batch15/part1/verify_strict.sh
```

Matches:

| address | function | flags | entry |
| --- | --- | --- | --- |
| 0x4f9c10 | City_FindMatchingCity | /O2 /TP | `_City_FindMatchingCity@4` |
| 0x4fcc30 | Object_AdjustShortPercent | /O2 /TP | `?AdjustShortPercent@Object@@QAEXHF@Z` |
| 0x523d60 | Window_ShowWindowById | /O2 /TP | `?ShowWindowById@UI@@QAEXH@Z` |
| 0x525af0 | UI_ProcessCommandQueue | /O2 /TP | `?ProcessCommandQueue@UI@@QAEXXZ` |
| 0x5271d0 | UI_ReleaseRefCount | /O2 /TP | `?ReleaseRefCount@UI@@QAEXH@Z` |
| 0x54b1b0 | UI_BriefingList_Save | /O2 /TP | `?Save@UI@@QAEXPAUStream@@@Z` |
| 0x4d2d80 | Map_ClearObjectFlags | /O2 /TP | `?ClearObjectFlags@Map@@QAEXPAUMapObject@@I@Z` |
| 0x4e5eb0 | ConstructionOrder_Load | /O2 /TP | `?Load@ConstructionOrder@@QAEXPAUStream@@@Z` |
| 0x4ed780 | UI_AlignSpriteToRect | /O2 /TP | `?AlignSpriteToRect@UI@@QAEXPAHPAX00@Z` |
| 0x4f9d50 | Building_GetLevelFromType | /O2 /TP | `_Building_GetLevelFromType@4` |
| 0x507d90 | Person_AdvanceRoute | /O2 /TP | `?AdvanceRoute@Person@@QAEHH@Z` |
| 0x5272f0 | UI_ShowTooltip | /O2 /TP | `?ShowTooltip@UI@@QAEXPAXHH@Z` |
| 0x480ab0 | MapObject_RemoveAndRefund | /O2 /TP | `?RemoveAndRefund@Branch@@QAEXPAUMapObject@@@Z` |
| 0x488b30 | Ingredient_CollectByCategory | /O2 /TP /GX | `?CollectByCategory@Ingredient@@QAEPAUList@@D@Z` |
| 0x521a50 | UI_DrawRectOutline | /O2 /TP | `?DrawRectOutline@UI@@QAEXHHHHI@Z` |
| 0x4b43f0 | CompanyOverview_SortCompanyIndices | /O2 /TP | `_CompanyOverview_SortCompanyIndices` |

`0x4b43f0` needs the three internal comparison thunks, which have no names in
either shipped symbol map:

```text
--symbol _Compare0=0x4b4480
--symbol _Compare1=0x4b4510
--symbol _Compare2=0x4b45b0
```

These addresses are the immediates pushed by the original `qsort` call sites.

`0x488b30` intentionally requires `/GX`: the shipped function has a C++ EH
frame and a `.xdata$x` unwind record. The strict gate validates both.

## Non-matching evidence

The following are the closest genuine C/C++ attempts. Sources and full
`match_decomp.py` reports are in `nonmatching/`.

| address | function | first diff (offset: original vs candidate) | differing bytes |
| --- | --- | --- | --- |
| 0x505340 | MapObject_ReadRenderRecord | 0x20: 0xc9 vs 0xd2 | 16 |
| 0x501f00 | Stats_GetCityShareRank | 0x45: 0x2f vs 0x37 | 13 |
| 0x528820 | UI_UpdateHoveredRow | 0x00: 0x8b vs 0x53 | 121 |
| 0x540f60 | List_DestroyObjects | 0x06: 0x47 vs 0x77 | 115 |
| 0x4f0bd0 | Object_FindRecordAtOffset | 0x2e: 0x34 vs 0x4a | 36 |
| 0x546f00 | List_Insert | 0x79: 0x51 vs 0x41 | 3 |
| 0x4e2080 | Company_AddStaffMember | 0x20: 0x47 vs 0x4f | 10 |
| 0x526d30 | Rect_Union | 0x01: 0x81 vs 0x8d | 109 |

The first seven differ only by register allocation or compiler block ordering;
the shipped code and the candidate implement the same operations. `0x526d30`
also has a different prologue shape because the compiler folded a rectangle
base pointer into the first compare.

## Not attempted

`0x54e170` (`_strstr`) is the hand-written VC6 CRT assembly implementation. It
uses word-at-a-time scanning and tail-jumps into `_strchr`; it is not
reproducible by genuine C and was intentionally left without a candidate.

## Cleanliness

No generated `.obj`/`.pdb` files are written into the repository; the matcher
compiles candidates in temporary directories.
