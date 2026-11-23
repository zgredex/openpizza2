# batch17 part3 worklog

Target: `game/fastfood2.exe`, MSVC 6.0 SP3 (`C2.DLL 12.00.8447`).
All accepted candidates are genuine C++ (`/O2 /TP`, no inline assembly) and
report `"strict_match": true` from `tools/match_decomp.py --strict
--auto-symbols` with the manifest length and the exact `--entry` symbol.

Result: **14 / 25 strict matches**. The other 11 records are kept under
`nonmatching/` when a C candidate was produced; the three unmatched C++ EH
constructors (`0x527950`, `0x4d50a0`, `0x52fa40`) and the Bink-import frame
advance (`0x52bbc0`) are explained below.

## Strict matches

| address | function | bytes | notes |
|---|---|---:|---|
| 0x4859c0 | GameView_SetupZoomedViewport | 182 | `Object::GetId` is a `__stdcall` free call on the UI singleton; `Game::ResizeZoomSurfaces` is a thiscall |
| 0x4e0920 | Stats_SumRecordFloatsByType | 182 | `0.0f` loaded from `DAT_0055c2e4`; single value uses a named temporary to get `fld value / fadd total` |
| 0x527e20 | Window_SetCursorPosition | 182 | assign `point.x`, `point.y` before the cached cursor fields |
| 0x547ba0 | Sound_ApplyVolumesForPlaybackMode | 182 | `switch`; `SetVolumeSetting` returns `char` (`test al,al`); duplicated `if (primaryBuffer)` tail |
| 0x4805d0 | Stats_ResetAverages | 183 | `rep stos` loops, table index buffers |
| 0x488c00 | Game_RunSimulationFrame | 183 | field `0x254` is volatile; keeps the guard store before the second lock load |
| 0x48b8a0 | Map_ScrollToClamped | 183 | declaration order of the four bounds is load-bearing; reversed `>=` comparisons |
| 0x52ad60 | UI_BuildListItem | 183 | `strcpy` intrinsic; `if (fieldC0 != 0)` polarity |
| 0x5405e0 | SoundPakManager_BuildArchivePath | 183 | `strcpy`/`strcat` intrinsics; `CRT_Strlwr` map alias |
| 0x47e5e0 | Game_GetSizeName | 184 | local `char *names[8]`; argument order `names[size]`, `names[variant+3]`; extra `"ROH"` pointer |
| 0x4fdb20 | AI_TryTakeOverRivalBranch | 184 | third argument (city) in EDX-slot; `goto takeover` shares one tail |
| 0x47d150 | Map_FindNearestCompanyBuilding | 185 | `if (key != target)` first keeps the remove branch inline; assign distance before best |
| 0x47e520 | Game_IsBuildingOpenAtHour | 185 | `unsigned` locals; explicit quotient/remainder keeps the reciprocal multiply; remainder statement first |
| 0x4d3e30 | Person_RemoveFromStaff | 185 | inline `Lookup` argument; `int key` local; duplicated field-0x78 store in both branches merges |

## Nonmatching

| address | bytes | diff | first difference / blocker |
|---|---:|---:|---|
| 0x4f9c90 | 182 | 121 | offset 9: prologue `mov ecx,[global]` vs early `push esi`; `list` zero lives in EBP instead of EDI |
| 0x527950 | 182 | 0 | body byte-identical; strict gate reports unverified circular `.text$x`/`.xdata$x` sections |
| 0x483150 | 183 | 136 | offset 25: original branchy `push 1`/`push 0` boolean; C++ emits `sete` |
| 0x4fc3b0 | 183 | 146 | offset 4: original delays `push ebx/edi` past the early return; candidate uses a shared epilogue |
| 0x50ac30 | 183 | 8 | only the four switch-case scratch registers differ (`eax/ecx/edx/eax` vs `edx/eax/ecx/edx`) |
| 0x491c80 | 184 | 165 | offset 0: original establishes the index counter before the zero loop; candidate strength-reduces it to a countdown |
| 0x4e2110 | 184 | 119 | person/record land in EDI/ESI instead of ESI/EDI |
| 0x4e3ab0 | 184 | 63 | offset 14: one-byte jump displacement after `mov eax`/`mov edx` scratch differences |
| 0x4d50a0 | 185 | n/a | `new Object(...)` EH frame; same circular `.text$x`/`.xdata$x` limitation |
| 0x52bbc0 | 186 | n/a | needs `__declspec(dllimport)` Bink calls; IAT names resolve only with explicit symbols (not added) |
| 0x52fa40 | 186 | n/a | `new UI_TextLabel(...)` EH frame; same circular section limitation |

## EH tooling note

Any candidate that uses a C++ `new` expression emits `.text$x` and `.xdata$x`
COMDATs that reference each other through the function's handler table. The
current strict matcher reports both as unverified even when the function body
is byte-identical (`0x527950` has `difference_count: 0`). The same limitation
reproduces on previously committed EH records (for example
`batch12/part3/0x539ea0`). Supplying the four local EH labels as explicit
symbols clears the section errors in a diagnostic run, but those labels are
derived from the checked bytes and therefore are not independent evidence.

## Verification

```sh
bash reconstructed/match/batch17/part3/verify_strict.sh
# strict 14 / 14
```
