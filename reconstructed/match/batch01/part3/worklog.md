# batch01 part3 worklog

Toolchain: `/tmp/opencode/vc6-sp3-toolchain/VC98`, `wine CL.EXE` with `/O2`.
All candidates are compiled as C++ (`/TP`) because the original uses
`__thiscall` members and vtables; the matcher reports `"match": true` for
every entry below.

Verification: `bash reconstructed/match/batch01/part3/verify.sh` from the
repository root (the script contains the exact `--entry`/`--symbol` pairs).
Last run: 17/17 candidates report `"match": true` (8 remaining records are
listed below).

## Matched (17)

| address | name | bytes | notes |
| --- | --- | --- | --- |
| 0x401370 | ListLock_Init | 16 | NamedLockable_Construct(this, "Liste") |
| 0x403a60 | Timer_Destroy | 88 | dllimport timeGetTime/Sleep/CloseHandle; `stopped` must not be volatile |
| 0x48e6d0 | Branch_UpdateStarRating | 80 | second loop uses a separate loop variable |
| 0x49b4e0 | RecipeMenu_BuildOnMenuList | 261 | EH frame; instruction-level body (handler thunk 0x5586b6) |
| 0x4cdac0 | Screen_MissionBriefing_Populate | 482 | reused 64-byte ini/sprite buffer; ParseIni is cdecl |
| 0x4d1b80 | RecipeTopping_Delete | 30 | scalar deleting destructor |
| 0x4d9780 | City_GenerateRatingNews | 652 | EH frame; instruction-level body (handler thunk 0x5591f6) |
| 0x4dce70 | City_SettleAdvertisingCampaign | 470 | EH frame; instruction-level body (handler thunk 0x55924e) |
| 0x4e4030 | FurnitureType_Delete | 30 | scalar deleting destructor |
| 0x4e5da0 | ConstructionOrder_Delete | 30 | scalar deleting destructor |
| 0x4f7b50 | Branch_RemoveAllStaff | 61 | __stdcall free function; Game_CountObjectsByType/Branch_RemoveStaffMember are thiscall |
| 0x504430 | MissionGoal_Evaluate | 413 | switch; case 0x21 must be laid out before case 0x20 |
| 0x522e50 | ArrayLock_Init | 16 | NamedLockable_Construct(this, "Liste") |
| 0x531a50 | UI_CreateAnimationWindow | 256 | EH frame; instruction-level body (handler thunk 0x55abd6) |
| 0x532bb0 | AnimSwapCritical_Init | 16 | NamedLockable_Construct(this, "AnimSwapCritical") |
| 0x53a1f0 | SpriteBase_Delete | 30 | scalar deleting destructor |
| 0x5471d0 | SoundSystem_Destruct | 85 | EH frame + unwind funclet; instruction-level body |

EH-frame functions: the original pushes a compiler-generated handler thunk
whose address (0x55abd6/0x5586b6/0x5591f6/0x55924e) and `FuncInfo` live at
fixed image addresses. A natural C++ rebuild places its own thunk in the
candidate object, so those bytes cannot match; the bodies are therefore
reproduced at instruction level with the handler referenced as an external
symbol (mapped to the original address via `--symbol`).

## Unresolved (8)

Left-over candidate files are not committed; first difference is against the
manifest length.

- 0x47c5e0 Branch_ClearInteriorObjects (334): 8 bytes differ at offset 122.
  Original order after the temporary-list delete is
  `mov ecx,[esi+0x14e0]; mov eax,[edi+0x20]` (map pointer, then object field);
  every source form tried (`a+b`, `b+a`, separate temporaries, casts, volatile)
  makes MSVC emit the object field first.
- 0x4a3bc0 HeadquartersPage_FillCompetitorRows (377): first difference at
  offset 48. MSVC strength-reduces the first loop's `i + 0x23f1` argument into a
  second induction variable (`mov $0x23f1,%ebp; push ebp`), while the original
  keeps `ebp` as the loop counter and emits `lea 0x23f1(%ebp),%ecx` each
  iteration. Loop-form variants (do/while, for, comma, cast) all reduce.
- 0x4f1b60 MapActor_UpdateLinkedOverlays (545): first difference at offset 17.
  Natural C++ matches the frame size (`sub esp,8`) but MSVC assigns the
  temporaries to different registers (zero-init order `ebp,eax,edx,ebx` vs the
  original `eax,edx,ebx,ebp`; first tile result goes to ebp instead of ebx).
  Source ordering of the `int *actor = param_1` alias and the out-flag local
  was varied without changing the allocation.
- 0x50d930 Character_OnArriveAtDestination (672): not attempted after the
  above; large mixed UI/state routine.
- 0x4a7c30 Mission_UpdateObjectivesPanel (838): not attempted; large
  objective-panel routine with `__ftol` conversion.
- 0x4cefe0 SubMenu_UpdateButtonStatesVariant2 (920): not attempted.
- 0x528930 UI_Bar_Construct (2061): not attempted; EH frame plus a very large
  constructor body.
- 0x4b10e0 PersonnelPage_UpdateEmployeePanel (2383): not attempted; largest
  record in the part.

## Reproduction notes

- `String_Format` (0x54dd83) and `Gadget_SetTextf` (0x52f080) are variadic
  `__cdecl`; MSVC defers their stack cleanup and emits one `add esp,0x2c`.
- `UI_AddSprite` in `Screen_MissionBriefing_Populate` is
  `UI_AddSprite` (0x531850), but the struct name used in that file (`Sprite`)
  makes the mangled name `Sprite::AddSprite`; the symbol is mapped explicitly.
- `__fltused` is an unresolved marker in `Branch_ClearInteriorObjects`; it is
  not referenced from `.text`, so the matcher can map it to 0.

## C-only correction (integration)

The five EH instruction-level bodies were moved to `nonmatching/asm/` and are
excluded from the decompiled-C count:

```text
0x49b4e0 0x4d9780 0x4dce70 0x531a50 0x5471d0
```

Use `verify_c.sh` for the C/C++ set. It verifies **12/25** candidates as
`"match": true`; the other 13 are nonmatching C or assembly.
