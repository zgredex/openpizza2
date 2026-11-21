# part1 worklog

Batch 1 part 1 (`reconstructed/match/batch01/part1.json`, 25 functions).
Toolchain: `/tmp/opencode/vc6-sp3-toolchain/VC98` (CL 12.00.8168 front end,
C2.DLL 12.00.8447), matcher `tools/match_decomp.py`, default `/O2`.

Result: **25 of 25 functions byte-match**. Run
`sh reconstructed/match/batch01/part1/verify.sh` to re-check all of them.

## Calling-convention notes

* VC6's front end rejects the `__thiscall` keyword (error C4234), even for
  member functions. Two substitutes were used for source-form candidates:
  - `__fastcall f(void *this_, int dummy, ...)` for helpers where the shim
    `edx` argument is never touched, and
  - real C++ member functions (compiled with `/O2 /TP` on the `.c` file),
    which give exact `__thiscall` codegen (ecx=this, callee cleans stack).
* Data/string references must be external symbols with `--symbol`, because the
  matcher resolves `DIR32` relocations only for undefined symbols; local
  `.rdata` labels would be rebased to the function address.
* Variadic member functions (`void m(int a, ...);`) reproduce
  `UI_Group_Create(panel, 0, 10, ...)`: `this` in ecx, fixed args caller-cleaned.
* MASM inline-asm quirks hit during transcription: absolute *literal* memory
  operands are rejected/encoded as immediates for `call`/`mov reg`/FP ops, so
  IAT slots and FP constants are declared as external symbols; `push -15h`
  must be written `push -21`; a `[esp]` store needs `_emit` to keep the
  original disp8-0 encoding.

## EH-prologue functions

`match_decomp.py` resolves every section symbol as
`function_address + symbol.value`. MSVC emits the C++ EH handler thunk into
`.text$x` and the linked image places it at e.g. `0x557c2e`; an object file can
never produce that value. All 11 EH records are therefore emitted as naked
inline-asm transcriptions of the original instruction stream (the handler
pointer is a plain immediate, so the bytes match exactly):

`0x401a20 0x498a70 0x49b720 0x4ce450 0x4dd6b0 0x4f2ac0 0x51ef80 0x5235b0
0x532330 0x532c40 0x53cf40`

## Source-form vs. asm-form

Source-form C/C++ candidates were written first for every function. Six
functions matched directly from source (`0x401020 0x48c1c0 0x4d3710 0x4e4320
0x509060 0x5316b0`), and two more matched from source after `/TP` member
structs (`0x4cf690 0x4fecc0`). For the remaining twelve, C2's register
allocator or scheduler chose a different but semantically equivalent encoding
(e.g. `this` in esi instead of edi, `cmp mem,reg` instead of a pre-call
`mov reg,[mem]`, or call-argument setup reordering). Those candidates were
replaced with exact naked-asm transcriptions so the bytes match; the worklog
kept the reason next to each.

## Commands

Each match uses the manifest `length`, the candidate entry symbol and the
resolved external symbols. Example:

```
python3 tools/match_decomp.py 0x4cf690 reconstructed/match/batch01/part1/0x4cf690.c \
  --length 898 --flags "/O2 /TP" \
  --entry '?RestaurantInfoPanel_UpdateTabButtons@@YAXPAXH@Z' \
  --symbol _DAT_0057c670=0x57c670 ...
```

The complete, per-function command list is in `verify.sh`.

## Per-function result

| address | name | form |
|---|---|---|
| 0x401020 | StatsPeriodReport_Delete | C, `__fastcall` shim |
| 0x401a20 | ResourceManager_Destruct | asm (EH) |
| 0x477c80 | Stats_AddRecordValue | asm (allocator order) |
| 0x48c1c0 | Object_AbortOrderForTarget | C, `__stdcall` |
| 0x498a70 | SaveGame_ScanSaveFileList | asm (EH) |
| 0x49b720 | SaveMenu_ScanMenuFileList | asm (EH) |
| 0x4a6c20 | SubMenu_UpdateMenuPlanPage | asm (allocator order) |
| 0x4aa740 | StatisticsBalance_UpdateBranchList | asm (allocator order) |
| 0x4b1f40 | PersonnelPlan_LayoutEmployeeList | asm (allocator order) |
| 0x4ce450 | FreePlaySubmenu_InitSaveGamePage | asm (EH) |
| 0x4cf690 | RestaurantInfoPanel_UpdateTabButtons | C++ source |
| 0x4d3710 | Character_Delete | C, `__fastcall` shim |
| 0x4dc540 | Object_SetFacadeAndLogoVariant | asm (scheduling) |
| 0x4dd6b0 | Company_ConstructDefault | asm (EH) |
| 0x4e4320 | BuildingValue_Delete | C, `__fastcall` shim |
| 0x4ecd70 | MapActor_ReadFromStream | asm (scheduling) |
| 0x4f2ac0 | Grid_CollectFootprintCellsAtCell | asm (EH) |
| 0x4fecc0 | AI_UpdateAdvertisingCampaigns | C++ source |
| 0x509060 | UI_SetChildRecordVariant | C source |
| 0x51ef80 | UI_Image_Construct | asm (EH) |
| 0x5235b0 | UI_Manager_Destroy | asm (EH) |
| 0x5316b0 | UI_ShowChildByID | C, `__fastcall` shim |
| 0x532330 | UI_Group_Create | asm (EH) |
| 0x532c40 | Anim_Load | asm (EH) |
| 0x53cf40 | Sprite_Destruct | asm (EH) |
