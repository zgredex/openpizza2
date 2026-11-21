# batch11 part1 worklog

Target: `game/fastfood2.exe`, MSVC 6.0 SP3 (`C2.DLL 12.00.8447`).
All candidates are genuine C++ compiled with `/O2 /TP`; no inline assembly.

Result: **21 / 25 strict matches** (`"strict_match": true`) with
`tools/match_decomp.py --strict --auto-symbols`, including explicit `--entry`
for every checked function in `verify_strict.sh`.

## Strict matches

| address | function | bytes | notes |
|---|---:|---:|---|
| 0x4e43f0 | BuildingValue_Save | 78 | `CRT_Ostream_Write` via a `CRT` member helper |
| 0x4e4440 | BuildingValue_Load | 78 | `CRT_Istream_Read` |
| 0x4f1450 | Building_HasAdjacentTile | 78 | `Array_GetRecord28`, short sign extension |
| 0x47a4a0 | Matrix_Max100x8 | 79 | `__fastcall`; `int rows` (not unsigned) keeps `jle` and the countdown loop |
| 0x481050 | MapObject_RemoveFromMap | 79 | virtual `Destroy(1)` through the vtable |
| 0x48b960 | Game_FindIdleObjectByClass | 79 | four-term idle predicate |
| 0x4da6b0 | Player_HasRecordWithField30 | 79 | `__stdcall` (ret 8), `for` loop |
| 0x4e4770 | Ingredient_Construct | 80 | vtable store + 12-argument `SetBuildingDesc`, `1.99` double |
| 0x4f29d0 | IsMenuIdRange | 80 | `__stdcall` (ret 4), manifest compare order |
| 0x4f5c80 | Map_GetFirstLinkedCell | 79 | `NoOp_Stub((char *)0x571dc0)` |
| 0x50bba0 | Game_HasObjectWithSourceId | 80 | `__fastcall`, `for` loop, global map reload |
| 0x509240 | UI_SetChildHeightFromValue | 79 | `__ftol` clamp, short stores |
| 0x511fa0 | Math_TruncateDouble | 79 | `__stdcall` (ret 8), float clamp then `__ftol` |
| 0x513bf0 | Branch_ComputeRecipePrice | 78 | float constant via `*(float *)0x55c348`; separate `float` result keeps `fiadd` before `pop` |
| 0x521740 | UI_DrawChildSprite | 78 | three-entry color array |
| 0x521b40 | UI_Sprite_BeginAnimation | 78 | `started` flag at 0x4c, range at 0x70/0x74 |
| 0x5315d0 | UI_CenterChildVertically | 78 | child fields 0x28/0x30, parent 0x18/0x20 |
| 0x539930 | Rect_ScaleAndOffset | 79 | four signed divisions by the tile width |
| 0x47f420 | Game_MarkAllObjectsDirty | 80 | stage guard, dirty byte at 0x81 |
| 0x498ef0 | RecipeMenu_ShowRecipeFileChooser | 80 | 4-arg confirmation / 6-arg list dialog |
| 0x49c4d0 | RecipeMenu_ShowMenuFileChooser | 80 | reversed dialog paths |

## Unmatched

Best genuine C++ attempts are under `nonmatching/`; see
`nonmatching/NOTES.md` for byte-level first diffs.

| address | function | first diff | remaining | reason |
|---|---:|---|---:|---|
| 0x505ef0 | MapObject_GetScreenPosition | offset 12: 0x3b vs 0x35 | 29 | original has a dead `cmp eax,1` on the mode argument (arg1) before the stores; every genuine shape either drops it or emits a real branch |
| 0x4da7c0 | Game_RecordPlayerStat | offset 60: 0x78 vs 0x70 | 4 | only the two adjacent store orderings differ (`[eax-8]=old` before `[eax-4]=local` in the original) |
| 0x52cba0 | Dialog_ParseInteger | offset 1: 0x4c vs 0x54 | 54 | original keeps `text` in `ecx` and `start` in `edx`; this compiler swaps the two throughout (member/thiscall and parameter-order variants do not change it) |
| 0x4a4190 | Game_GetPlayerSlotByOrdinal | offset 7: 0x56 vs 0x33 | 30 | original has a single signed pointer back-edge (`cmp esi,0x57d264; jl`) with no top guard; `do`/`while`/`for` shapes all give a top test or inverted loop |

## Verification

```sh
sh reconstructed/match/batch11/part1/verify_strict.sh
# strict 21/21
```

The script passes the manifest length, the exact decorated/data entry symbol,
the per-function `/O2 /TP` flags, and requires `strict_match`.

## Tooling notes

- No explicit `--symbol` entries were needed: PE import IAT slots, decorated
  C++ methods, data symbols and the `__imp__InitializeCriticalSection@4`-style
  imports all resolve from the shipped maps.
- `0x4da7c0` needs the global game pointer: callers use
  `DAT_0057c670`, not the current `this`; the remaining 4 bytes are pure store
  scheduling.
- Switch tables emitted after a body must equal the original image bytes; the
  strict extent check caught the initial `Matrix_Max100x8` extra tail.
