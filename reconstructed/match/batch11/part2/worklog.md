# batch11 part2 worklog

Target: `game/fastfood2.exe`, MSVC 6.0 SP3 (`C2.DLL 12.00.8447`).
All candidates are genuine C++ compiled with `/O2 /TP`, except `0x54dd83`
(string formatting) which needs `/O1 /TP` to match the shipped CRT-style
object. No inline assembly.

Result: **18 / 25 strict matches** (`"strict_match": true`) with
`tools/match_decomp.py --strict --auto-symbols`, including explicit `--entry`
for every checked function in `verify_strict.sh`.

## Strict matches

| address | function | bytes | notes |
|---|---:|---:|---|
| 0x513c40 | Branch_GetRecipePriceParts | 80 | building value * `*(float *)0x55c320`, `__ftol`, then `Get_Float44` |
| 0x531620 | Array_ToggleObjectActive | 80 | non-zero path first (`active != 0` -> `EnsureInit`) |
| 0x533aa0 | Record_SelectVariant | 80 | returns `int`; `neg/sbb/neg` bool materialization |
| 0x4db170 | Market_GetPriceDelta | 81 | returns -40 (`0xffffffd8`) for -1, else 0x28 |
| 0x4810e0 | Game_FreeSubmapObjects | 82 | `4f2b60`-style list, virtual `Destroy(1)` |
| 0x4e2ca0 | AI_SumPlanSteps | 82 | `AI_CountPlanSteps(record, param, 0, -1)` |
| 0x4eaaa0 | Game_SaveTileNameTable | 82 | inlined `strcpy` of 2500 x 0x32-byte names |
| 0x4eae00 | UI_SetWindowOffsets | 82 | two immediate-store presets |
| 0x5141c0 | StaffList_AddId | 82 | 0x14-entry 0xc-byte table |
| 0x534370 | Record_GetTwoFloats48 | 82 | two `(int)double` reads at +8/+0x10 |
| 0x54ae60 | UI_AdvanceBriefing | 82 | advanced flag at 0x10, id at 8 |
| 0x54dd83 | String_Format | 82 | `/O1 /TP`; 0x20-byte VC6 `FILE`-shaped local, `_cnt` decrement |
| 0x47fb70 | Branch_RefreshConstructionButtons | 83 | state 7 path and four helper calls |
| 0x48d3a0 | Game_GetStartingCapital | 83 | switch table, matches the golden reference |
| 0x492270 | UI_FillObjectWithPaletteColor | 83 | palette entry `*(uint *)(0x56869c + color*4)` |
| 0x4d6ba0 | Game_CountObjectsByType2 | 83 | byte type at +0x824, `0xffffffff` wildcard |
| 0x4f1d90 | Enum_MapDirection | 83 | `__stdcall`, explicit `case 0` keeps `cmp eax,7` + 8-entry signed table |
| 0x531570 | Array_GetRectByKey | 83 | child size from 0x28/0x30 and 0x2c/0x34 |

`0x54dd83` is checked with `/O1 /TP` in `verify_strict.sh`; all other
functions use `/O2 /TP`.

## Unmatched

Best genuine C++ attempts are under `nonmatching/`; see
`nonmatching/NOTES.md` for byte-level first diffs.

| address | function | first diff | remaining | reason |
|---|---:|---|---:|---|
| 0x5349e0 | RecordList_ReadSlot98 | offset 7: 0x7c 0x39 vs 0x7c 0x3a | 39 | copy path recomputes the sub-record address (`lea`/load twice) instead of keeping it in a register; zero path uses immediate stores instead of `xor eax,eax` |
| 0x4030f0 | Game_FormatObjectName | offset 22: 0x78 vs 0x76 | 3 | base pointer is kept in `esi`, original in `ecx` (`mov esi,[esi+4]` vs `mov ecx,[esi+4]`); every other byte matches |
| 0x477c20 | Stats_FindRecordByType | offset 1: 0x55 vs 0x8b | 71 | allocator swaps `type`/map between `edi`/`ebx` and loads the parameter before the pushed registers |
| 0x52f7a0 | Gadget_SetButtonTextLayout | offset 7: 0x20 vs 0x1c | 8 | short pairs are stored in ascending offsets; original stores `y,x` then `height,width` |
| 0x49fa70 | RecipeMenu_NextRecipe | offset 14: 0x42 vs 0x40 | 25 | original reloads the recipe count into `edx` after the store and compares registers; candidate compares `eax` with the memory field |
| 0x535cf0 | PaletteList_Free | offset 0: 0x57 vs 0x56 | 17 | original keeps `this` in `edi` and the palette in `esi`; this compiler assigns `esi`/`edi` the other way round |
| 0x401280 | NamedLockable_Construct | offset 30: 0x8d vs 0x75 | 21 | `lea ebp,[ebx+0x1c]` is scheduled after `strlen` instead of between the name compare and branch |

## Verification

```sh
sh reconstructed/match/batch11/part2/verify_strict.sh
# strict 18/18
```

The script passes the manifest length, the exact entry symbol, the
per-function flags (including `/O1 /TP` for 0x54dd83) and requires
`strict_match`.

## Tooling notes

- No explicit `--symbol` entries were needed; PE imports, decorated C++
  methods, `DAT_` globals and `__ftol`/CRT helpers resolve automatically.
- `0x4f1d90`: the original jump table lives in `.text` directly after the
  function (`0x4f1de4`); it contains 8 entries with entry 0 pointing at the
  default body, which requires an explicit `case 0`.
- `0x54dd83`: matching confirms the shipped string-formatting object was
  compiled with `/O1`; the frame pointer, `dec DWORD PTR [ebp-0x1c]` and
  `pop ecx; pop ecx` call cleanup all appear with that flag.
