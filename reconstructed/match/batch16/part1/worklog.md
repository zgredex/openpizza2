# batch16 part1 worklog

Scope: 25 functions from `reconstructed/match/batch16/part1.json`.
Toolchain: the pinned VC6 SP3 tree (`~/.local/share/pc2/vc6-sp3-toolchain/VC98`,
C2.DLL 12.00.8447). Every accepted function is genuine C/C++ and passes
`tools/match_decomp.py --strict --auto-symbols` with the manifest length and
the exact candidate entry symbol.

## Result: 17 / 25 strict matches

Reproduce with:

```sh
sh reconstructed/match/batch16/part1/verify_strict.sh
```

Matches (all `/O2 /TP`):

| address | function | entry |
| --- | --- | --- |
| 0x5136c0 | Game_ComputeCompanyRatings | `?ComputeCompanyRatings@Game@@QAEXH@Z` |
| 0x5265a0 | UI_ClearDestroyedObjectReferences | `?ClearDestroyedObjectReferences@UI@@QAEXH@Z` |
| 0x5387d0 | Renderer_ReleaseTargets | `?ReleaseTargets@Renderer@@QAEXXZ` |
| 0x4fd0f0 | Player_BuildHeadquarters | `_Player_BuildHeadquarters@20` |
| 0x533af0 | Record_ApplyVariantState | `?ApplyVariantState@Record@@QAEHHHE@Z` |
| 0x4e0df0 | Stats_GetFilteredFloatDelta | `?GetFilteredFloatDelta@Stats@@QAEMHH@Z` |
| 0x4e6420 | Filename_ToUpperStripExt | `?Filename_ToUpperStripExt@@YAXPAD@Z` |
| 0x526e80 | UI_SetBackgroundSurfaceEnabled | `?SetBackgroundSurfaceEnabled@UI@@QAEXH@Z` |
| 0x409b10 | AdCampaign_GoToNearestOwnBuilding | `_AdCampaign_GoToNearestOwnBuilding@8` |
| 0x52a3a0 | UI_SetClampedValue | `?SetClampedValue@UI@@QAEXHH@Z` |
| 0x48a090 | Game_CountFilteredObjects2 | `?CountFilteredObjects2@Game@@QAEHHHHH@Z` |
| 0x48ea50 | Game_ReturnToPlayScreen | `?Game_ReturnToPlayScreen@@YAXXZ` |
| 0x4e2b70 | City_GetTopProductCategory | `?GetTopProductCategory@City@@QAEHXZ` |
| 0x540510 | SoundPakManager_FindExtensionEntry | `?FindExtensionEntry@SoundPakManager@@QAEHPAD@Z` |
| 0x48bef0 | Game_OpenObjectView | `?OpenObjectView@Game@@QAEXH@Z` |
| 0x4e3780 | Player_ComputeNetStatTotal | `?ComputeNetStatTotal@Player@@QAEMXZ` |
| 0x535d70 | Palette_Init | `?Initialize@Palette@@QAEPAV1@HPAHH@Z` |

No explicit `--symbol` mappings were required; all external calls resolve
through `--auto-symbols` (decorated aliases, PE IAT slots, or address labels
such as `DAT_004e2c10` used as the `qsort` comparator pointer).

Notes:

- 0x4e2b70 calls `CRT_QSort` through the `CRT::QSort` alias and passes the
  comparator at 0x4e2c10 as an address-label constant. The seven-int global
  accumulator at 0x57dfc0 is declared as `DAT_0057dfc0[7]`.
- 0x48ea50 uses a volatile copy/assignment sequence for the mode/previous-mode
  pair; the original re-reads the global between the two statements.
- 0x5136c0 and 0x4e3780 only reproduce their exact register allocation when the
  loop bodies index member arrays/pointers rather than raw char* arithmetic.

## Non-matching evidence

The closest genuine C/C++ attempts are kept in `nonmatching/` with their full
`match_decomp.py --strict --auto-symbols` reports.

| address | function | first diff (offset: original vs candidate) | differing bytes |
| --- | --- | --- | --- |
| 0x4e1e40 | Game_FindFreeStaffRecord | 0x48: 0x44 vs 0x54 | 5 |
| 0x4d8be0 | Game_FindNearestTransportBuilding | 0x66: 0x8e vs 0x4c | 18 |
| 0x4e1fe0 | AI_FindTargetWithMinA8 | 0x09: 0x55 vs 0x53 | 27 |
| 0x49a040 | Game_IsCompanyNameTaken | 0x09: 0x90 vs 0x88 | 118 |
| 0x4d6c10 | City_RemovePersonAndMaintainPopulation | 0x05: 0xd9 vs 0x5c | 115 |

Three manifest entries could not be attempted as genuine C because their
shipped bodies require compiler-generated C++ EH frames:

- 0x5317b0 UI_CreateMovieWindow (`new` + constructor in a try region and a
  `.text$x` handler at 0x55ab6b).
- 0x513c90 Storage_Construct (constructor with a member subobject and an EH
  frame; handler 0x55a4fb).
- 0x4a1940 SaveGame_Scan (`operator new` + constructor in a try region; handler
  0x55887b).

The five candidates in the table above were written as genuine C/C++ and differ
only in VC6 register allocation / basic-block scheduling.
