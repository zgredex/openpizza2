# batch13 part2 worklog

Target: `game/fastfood2.exe`, MSVC 6.0 SP3 (`C2.DLL 12.00.8447`), all
candidates genuine C++ (`/O2 /TP`), no inline assembly.

Result: **16 / 25 strict matches** (`"strict_match": true`) with
`tools/match_batch.py --strict --auto-symbols` and with `verify_strict.sh`
(which also passes the exact `--entry` for every function).

## Strict matches

| address | function | bytes | notes |
|---|---:|---:|---|
| 0x5418c0 | Stream_RequestBlock | 103 | `position/initialCount` at `+0x10/+0x14`; `end >= position` keeps truncation fall-through |
| 0x4a1450 | SaveGame_AnyExist | 104 | second `CRT_FindClose` really passes `-1` (matches the PE) |
| 0x4e46f0 | Game_DecayCityDateBonus | 104 | x87 add needs a `double next` local to get `fld value; fadd const` |
| 0x532a30 | UI_AddUniquePair | 104 | `IDMap`-style `Array` needs a `0x10`-byte body |
| 0x4055d0 | Game_ShutdownSubsystems | 105 | virtual `Destroy(1)` via a `virtual` declaration |
| 0x47a430 | Stats_SumPlayerGrid | 105 | grid is `int[8][100]` (`grid[column][row]`) |
| 0x47c830 | City_ComputeServiceLevel | 105 | `if (minimum > 0x18) return 0;` reproduces `jle` to the division |
| 0x4e3b70 | Player_RestorePlanTargetAnimations | 105 | calls go through the looked-up `target`, not the global |
| 0x50e230 | Game_UpdateBuildingStates | 105 | list pointer reloaded after each record |
| 0x5322a0 | UI_GetWindowRect | 105 | source pointer `this+0x38`; `if (source->left != -999)` |
| 0x534060 | Record_GetBounds48 | 105 | entry short recomputed for each of the four tables |
| 0x488d20 | Game_ResumeSimulation | 106 | `GetCurrentThreadId` as `extern "C"` dllimport |
| 0x4c0ff0 | StorageMenu_Init | 106 | duplicate `SetText` calls cross-jump to one call |
| 0x4e1d40 | Game_CountActiveObjectsByType | 106 | two-level IDMap lookup |
| 0x4e3660 | Game_UpgradeProductionLevel | 106 | `(int)service == ...`; x87 `fild/fstp` for the float argument |
| 0x4fe300 | Company_DispatchWorkerToBranch | 106 | plain `for` loop avoids the peeled rotation |

## Unmatched

All failed candidates are under `nonmatching/`; the table gives the first
differing byte (`original`, `candidate`).

| address | function | bytes | first diff | cause |
|---|---:|---:|---|---|
| 0x534bc0 | Record_AssignVariant | 103 | 0: `53`/`55` | variant index in `ebp` instead of `ebx` |
| 0x4d23b0 | Game_CenterViewOnObject | 104 | 60: `44`/`54` | `Rect_Center`/`ScrollToClamped` pointer temps use `eax/ecx` vs `edx/eax` |
| 0x50b090 | UI_HitTestChildPoint | 104 | 8: `8b`/`89` | an extra local store of `this` after the stack local is already set by `push ecx` |
| 0x48d4c0 | UI_ShowPauseDialog | 105 | 42: `54`/`ce` | parameter load order before the two `SetText` calls |
| 0x4d4000 | Rating_GetComposite | 105 | 6: `f9`/`d9` | `this` in `ebx` instead of `edi` (all other bytes match) |
| 0x4dce00 | Game_InitCompanyAIStrategy | 106 | 55: `b8`/`8d` | `empty*5000` scheduled before the `12/empty` idiv |
| 0x4de1a0 | Game_SumStatGridAll | 106 | 5: `33`/`56` | accumulator/init ordering: original zeroes `ebx` between prolog pushes |
| 0x4de210 | Stats_SumMatrixCells | 106 | 4: `53`/`55` | accumulator allocated to `ebp` instead of `ebx` |
| 0x53d090 | Sprite_GetSize | 106 | 5: `74`/`8a` | flags byte hoisted before the `field30` test; branch B uses `dl` instead of `al` |

The unmatched sources are the best genuine C++ attempts; every function was
compiled and compared, and no inline assembly was used.
