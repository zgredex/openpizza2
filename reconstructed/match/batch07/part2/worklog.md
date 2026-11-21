# batch07 part2 worklog

Batch 7 part 2 (`reconstructed/match/batch07/part2.json`, 25 functions).
Toolchain: `/tmp/opencode/vc6-sp3-toolchain/VC98` (CL 12.00.8168 front end,
C2.DLL 12.00.8447), matcher `tools/match_decomp.py` with `--strict
--auto-symbols`, default `/O2 /TP`; 0x54dcd4 is size-optimized and needs
`/O1 /TP`.

**Result: 25 of 25 functions report `"strict_match": true`.** Run
`sh reconstructed/match/batch07/part2/verify_strict.sh` to re-check every
match; it passes each manifest length and the exact entry symbol.

## Matches

| address | name | form / flags |
|---|---|---|
| 0x4e34e0 | Player_GetFirstRecordType1 | C free `__fastcall`, keyed record scan, `/O2 /TP` |
| 0x4eac80 | Game_RegisterWorldObject | C++ member, `List::Add` vs `IDMap::InsertGrow`, `/O2 /TP` |
| 0x4ffa60 | Game_GetDateStage | C++ member, date threshold to stage 1/4, `/O2 /TP` |
| 0x508fb0 | Building_MapSubtypeToState | C `__stdcall`, four-case jump table, `/O2 /TP` |
| 0x512700 | Array_AreBothCountsPositive | C++ member, two masked counter checks, `/O2 /TP` |
| 0x520b10 | UI_Child_Destroy | C free `__fastcall`, vtable restore + two frees, `/O2 /TP` |
| 0x520f80 | UI_DetachChild | C free `__fastcall`, parent effect list removal, `/O2 /TP` |
| 0x527cc0 | UI_SetModalHandler | C++ member, modal fields + virtual layout call, `/O2 /TP` |
| 0x52e8b0 | Tooltip_SetBackgroundImage | C++ member, release + load image, `/O2 /TP` |
| 0x52f800 | Gadget_SetButtonState | C++ member, `GadgetNotify` state 1/0, `/O2 /TP` |
| 0x52ff50 | Window_GadgetNotify_Button_SetState | C++ member, notification type 1, `/O2 /TP` |
| 0x531fb0 | UI_SetChildLabelText | C++ member, `BinarySearch8` + label text, `/O2 /TP` |
| 0x533a70 | Record_ClearFlags48 | C++ member, 0x48-byte record flag clears, `/O2 /TP` |
| 0x535e20 | Palette_WriteToStream | C++ member, default stub + `fwrite`, `/O2 /TP` |
| 0x542ad0 | Sound_QueryBufferFlag | C `__fastcall` char, COM status query, `/O2 /TP` |
| 0x54bb00 | UI_ComposeOverlayWindowFromRecord | C++ member wrapper, staged fields, `/O2 /TP` |
| 0x54dcd4 | Stream_AttachBuffer | C++ member, free old buffer + attach, `/O1 /TP` |
| 0x401930 | Map_LookupLinear | C++ member, linear key search, `/O2 /TP` |
| 0x403150 | Game_FormatObjectNameRandom | C++ member, `Random_Mod` + sprintf-like format, `/O2 /TP` |
| 0x49bd50 | Player_AddRecipeToMenu | C cdecl, current player recipe lookup, `/O2 /TP` |
| 0x4ac3c0 | StatisticsBranchBalance_Load | C cdecl, three stream reads, `/O2 /TP` |
| 0x4ac400 | StatisticsBranchBalance_Save | C cdecl, three stream writes, `/O2 /TP` |
| 0x4b3ca0 | CompanyOverview_Load | C cdecl, 4 + 4 + 9 byte reads, `/O2 /TP` |
| 0x4b3ce0 | CompanyOverview_Save | C cdecl, 4 + 4 + 9 byte writes, `/O2 /TP` |
| 0x4bd450 | UI_SelectPreviousObjectOfType | C cdecl, previous-object selection, `/O2 /TP` |

## Notes

* `0x4e34e0` and `0x401930` only match with a `while (i < count)` loop.  A
  `do/while` makes the SP5 front end rotate the loop and emit the body twice
  (80/64 bytes instead of 48/49).  For 0x401930 the keys pointer must also be
  recomputed from `this` inside the loop (`*(int *)((char *)this + 4)`), which
  lets VC6 hoist it into `edx` once and keep `count` in `esi`.
* `0x508fb0` is a `switch` with absolute jump-table entries.  The table sits
  exactly at `start + length`; the matcher's extra-extent check now compares
  the candidate table bytes with the original table (relocations normalised),
  so the match is strict.  The source must initialise `result = -1` and use
  case order 3, 2, 0, 1 so the bodies land at 0x13/0x1b/0x23/0x2b.
* `0x512700` needs the two guards combined with `||` (not two `if`s), which
  makes VC6 emit `test`/`jle` for both counters instead of a `setge` bool.
* `0x520b10` / `0x520f80` are free `__fastcall` functions with the object in
  `ecx`; `Mem_Free` is a cdecl CRT wrapper, so `add esp,4` matches the original
  cleanup.
* `0x527cc0` uses a real C++ virtual call through a four-slot vtable
  (`ModalWindow::SetLayout` at offset 0xc); `0x542ad0` and `0x53a110` use the
  COM-style explicit `vtbl` struct because there the interface pointer is
  pushed as an argument while `ecx` holds the vtable.
* `0x52f800` / `0x52ff50` need the `state != 0` branch as the fall-through
  path; `if (state == 0)` first swaps the `je`/`jne` and fails at offset 8.
* `0x531fb0` calls the shipped free function `BinarySearch8` (0x531330).  Its
  flat symbol has no class prefix, so `--auto-symbols` cannot derive it; the
  candidate declares it as `UI::BinarySearch8` (same thiscall shape) and the
  verify script supplies
  `--symbol '?BinarySearch8@UI@@QAEHHD@Z=0x531330'`.
* `0x54bb00` is the reverse-engineering case of the batch: the original
  evaluates the seven arguments right-to-left but loads all five record fields
  into `ebx`/`esi`/`edi`/`eax`/`edx` before pushing anything, and `ecx` is
  never reloaded, so it is a member function calling another member
  (`ecx = this`).  Plain source gets lazy load/push interleaving (38 byte
  differences).  Staging the five fields in a local `int field[5]` in
  right-to-left order and then passing `field[4], field[3], ...` reproduces
  the original register allocation exactly.
* `0x54dcd4` matches only with `/O1`: the original uses
  `cmp [esi+4],0` / `cmp [esi+0x10],0`, `pop ecx` after `Mem_Free`, and
  parameter loads after the guarded block, all size-optimizer shapes.
* The Load/Save wrappers call `CRT::Istream_Read` / `CRT::Ostream_Write`
  (thiscall, stream in `ecx`, destination/source and size on the stack), which
  is why the call sites have no `add esp` after them.
* `0x4bd450` loads the game pointer once after the lookup call:
  `if (object) { Game *game = (Game *)DAT_0057c670; ... }`.  Repeating the
  global in each store makes VC6 reload it before the last store.

## Reproduce

```sh
sh reconstructed/match/batch07/part2/verify_strict.sh
```
