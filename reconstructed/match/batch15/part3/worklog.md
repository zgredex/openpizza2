# batch15 part3 worklog

25 manifest records attempted for genuine byte-identical C/C++ with
MSVC 6.0 SP3 (`/tmp/opencode/vc6-sp3-toolchain/VC98`). Accepted files compile
with `/O2 /TP`, pass the manifest length and exact entry symbol, and report
`"strict_match": true` from `tools/match_decomp.py --strict --auto-symbols`.

## Result

```text
strict matches: 10 / 25
```

Matched: 0x4f5e50, 0x4f5ee0, 0x547de0, 0x489bc0, 0x4eda60, 0x4fc560,
0x4ddc10, 0x541130, 0x54b230, 0x4a52d0.

| address | length | entry symbol | notes |
| --- | ---: | --- | --- |
| 0x4f5e50 | 138 | `?MissionState_Load@Player@@QAEXPAX@Z` | eight `CRT_Istream_Read` blocks |
| 0x4f5ee0 | 138 | `?MissionState_Save@Player@@QAEXPAX@Z` | eight `CRT_Ostream_Write` blocks |
| 0x547de0 | 138 | `?StopPlaybackMode@Sound@@QAEXXZ` | `switch` on the playback mode; `CriticalSection` methods |
| 0x489bc0 | 139 | `?CommitObjectPlacement@Game@@QAEHHH@Z` | virtual `FootprintCells::Destroy(1)` call |
| 0x4eda60 | 139 | `?ScreenToTileCoords@Map@@QAEXPAH00@Z` | `while` over `Map_ComputeBlitRect` |
| 0x4fc560 | 139 | `?Game_PurgeUnusedCompanyRecipes@@YIXPAD@Z` | `bool Game_IsRecordLinked` return is required for `test al,al` |
| 0x4ddc10 | 140 | `?RemoveBranch@Player@@QAEXPAX@Z` | three `IDMap` call sites |
| 0x541130 | 140 | `?SetVolumeLogarithmic@Sound@@QAEHH@Z` | intrinsic `log10`; `<= -10000` clamp form |
| 0x54b230 | 141 | `?BriefingList_Load@UI@@QAEXPAX@Z` | `key`/`size` locals must live for the whole function (12-byte frame) |
| 0x4a52d0 | 142 | `_TradeOffer_Page_Init` | ten `UI_ShowChildByID` calls |

## Non-matching (kept under `nonmatching/`)

| address | length | first diff | diffs | finding |
| --- | ---: | ---: | ---: | --- |
| 0x5003e0 | 138 | 0x30 | 31 | original keeps the account double on the x87 stack (`fcom`/`fadd st,st(2)`); candidate reloads it |
| 0x53f790 | 138 | 0x03 | 121 | original delays `push edi` until after the stream-mode compare |
| 0x483530 | 139 | 0x01 | 107 | original keeps `this` in edi and the row index in esi; candidate swaps them |
| 0x47edc0 | 140 | 0x26 | 62 | original materialises both boolean locals with `setne`/`setg` |
| 0x4db1d0 | 140 | 0x05 | 98 | original keeps the count in ebx and `this` in edi before the category branch |
| 0x4e27d0 | 140 | 0x4d | 3 | only the register pair of the target/object comparison is swapped (ecx/edx) |
| 0x4e3df0 | 141 | 0x43 | 3 | only the order-pointer/player-id register pair is swapped (eax/ecx vs ecx/edx) |
| 0x4f3e10 | 141 | 0x00 | 112 | original keeps no frame pointer for the cell parameter; candidate uses ebp |
| 0x509e20 | 141 | 0x0e | 109 | original returns inline on the null record; candidate jumps to a shared epilogue |
| 0x48b570 | 142 | 0x5c | 6 | original selects the slot in eax (`mov ecx,eax; inc eax`); candidate uses ecx for the new slot |
| 0x4a09d0 | 142 | 0x06 | 110 | original keeps the clamped start in ebp and the window in ebx; candidate spills the start |

Not attempted: 0x541f30 (`SoundTrack_Destruct`, EH unwind destructor), and the
save-menu siblings 0x4a1a10, 0x4cde40, 0x4ce3c0. The sibling shape is the same
as 0x4a09d0, which did not reproduce the original register allocation.

## Notes

- Zero-argument thiscall callees are written as C++ members, so the decorated
  entry names and auto symbol resolution match the shipped map.
- `log10` is declared `extern "C" double __cdecl log10(double);` so `/O2`
  expands it to the same `fyl2x` sequence without an explicit include path.
- No explicit `--symbol` maps were needed in this part.

## Reproduce

```sh
bash reconstructed/match/batch15/part3/verify_strict.sh
```
