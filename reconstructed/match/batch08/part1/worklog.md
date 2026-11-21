# batch08 part1 worklog

Batch 8 part 1 (`reconstructed/match/batch08/part1.json`, 25 functions).
Toolchain: `/tmp/opencode/vc6-sp3-toolchain/VC98` (CL 12.00.8168 front end,
C2.DLL 12.00.8447), matcher `tools/match_decomp.py`, default `/O2`
(`/O2 /TP` for the C++ member functions).

**Result: 23 of 25 functions report `"strict_match": true`.** Run
`sh reconstructed/match/batch08/part1/verify_strict.sh` to re-check every
match; it passes each manifest length and the exact entry symbol and uses
`--strict --auto-symbols`. The two remaining records are kept in
`part1/nonmatching/` and are not matches.

## Matches

| address | name | form / notes |
|---|---|---|
| 0x539340 | Color_Convert555To565 | thiscall member, 555→565 pixel loop, `/O2 /TP` |
| 0x53d100 | Sprite_GetHotspot | thiscall member, hotspot flag branch, `/O2 /TP` |
| 0x545660 | Sound_Get3DBufferParams | fastcall 3D buffer fill + vtable slot 0xc, `/O2 /TP` |
| 0x4962a0 | CompareScreen_UpdateMenuRatingBars | cdecl loop with `Branch::GetMenuRating` + `Rating_UpdateBarByKey`, `/O2 /TP` |
| 0x4d2aa0 | Game_FindObjectByClass | thiscall linear map search, `/O2 /TP` |
| 0x4d2e80 | Building_GetSpriteVariant | fastcall switch, grouped sprite ids; jump table follows the body, `/O2` |
| 0x4d3560 | MapObject_PlaceAtPoint | thiscall `Record::SetDoubles48` call, `/O2 /TP` |
| 0x523de0 | UI_RefreshAndCenter | thiscall lock/render/surface-copy, `/O2 /TP` |
| 0x528760 | Window_ReleaseResources | fastcall reference release + free, `/O2 /TP` |
| 0x4034d0 | Random_RangeFast | cdecl `rand()` scale and clamp, `/O2` |
| 0x4043e0 | GameMain | cdecl screen loop shutdown; volatile stop flag forces the store before the thread load, `/O2` |
| 0x404420 | SetScreenRects | cdecl two `SetRect` IAT calls, `--symbol __imp__SetRect@20=0x55c280`, `/O2` |
| 0x477360 | Game_FindMapRecordByTypeE | fastcall map search for type 0xe, `/O2 /TP` |
| 0x480a70 | Game_SetObjectValue100 | thiscall float price + affordability, `/O2 /TP` |
| 0x4d31b0 | UI_GetCenteredRectForRecord | thiscall `IDMap::Lookup` + `UI::GetRecordCenteredRect`, `/O2 /TP` |
| 0x4ffa90 | Company_ScheduleDeadline | thiscall date + slot store + recent-entry push, `/O2 /TP` |
| 0x5019d0 | Player_Event_StreamConstruct | thiscall vtable constructor with optional load, `/O2 /TP` |
| 0x526f60 | UI_FindFontByName | thiscall font-list walk, `--symbol _FUN_005570c0=0x5570c0`, `/O2 /TP` |
| 0x527ad0 | Object_GetChildOrigin | thiscall child origin copy, `/O2 /TP` |
| 0x5288b0 | UI_GetOuterRect | thiscall border expansion, `/O2 /TP` |
| 0x47ebc0 | Game_FindRecordByField10 | thiscall map search on field 0x10, `/O2 /TP` |
| 0x4c6f50 | CharacterSelect_DrawPortrait | thiscall `UI::ComposeOverlayWindow` call with seven args, `/O2 /TP` |
| 0x4dcb30 | Game_IncrementPlayerCounterC20 | thiscall counter + selected period copy, `/O2 /TP` |

## Nonmatching

| address | length | first diff | diagnosis |
|---|---|---|---|
| 0x5479c0 | 52 | +0x0c: original `74` (`je`), candidate `76` (`jbe`) | `Sound_SetEnabledFlag`. The original hoists `DAT_00575091` into DL and keeps the parameter in AL. Only the `enable > 0` source shape reproduces that allocation/hoist, but VC6 then emits `jbe`; every equality form that emits `je` reloads the global in each arm or swaps AL/DL. Candidate in `nonmatching/`. |
| 0x514690 | 53 | +0x2c: original `30`, candidate `06` (SIB) | `Language_CopyStringIds`. Every instruction matches except the load SIB: original `[eax+esi-4]` (index in EAX, table in ESI), VC6 emits `[esi+eax-4]` for all equivalent int/char/pointer/array source forms tried. Candidate in `nonmatching/`. |

## Notes

* `0x4d2e80` keeps its `switch` jump table in `.text` immediately after the
  function; strict mode compares those extra bytes against the original
  table/padding, so the grouped case order matters. The `0x828..0x833` group
  (the only `result = 3; break;` group) must be written last in the source so
  VC6 lays the case blocks out 0, 1, 2, 3, default.
* `0x4043e0` needs `DAT_0057c480` declared `volatile`: otherwise VC6 hoists
  the `DAT_0057c5b0` load above the `= 1` store. With the volatile store the
  original `push esi; ...; mov [0x57c480],1; mov esi,[0x57c5b0]` order is
  reproduced.
* `0x4d2aa0`, `0x477360` and `0x47ebc0` use a `while` loop with the count in
  a local. A `do { } while` form made VC6 peel the first iteration.
* `0x477360` needs the inner record class named `Game` so
  `?MapRecordToGlobal@Game@@QAEHH@Z` demangles to `Game_MapRecordToGlobal`
  for `--auto-symbols`; the outer holder is `GameRoot`.
* External IAT calls (`SetRect`) and the unnamed helper at 0x5570c0 are not
  in `full_game_symbols.json`; the verify script supplies their addresses
  explicitly.

## Reproduce

```sh
sh reconstructed/match/batch08/part1/verify_strict.sh
```
