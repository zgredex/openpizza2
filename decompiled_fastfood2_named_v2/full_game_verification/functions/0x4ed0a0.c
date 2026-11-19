// rea decompile_all
// name: Map_UpdateObjectScreenBounds
// address: 0x4ed0a0
// body: available
// range: 0x4ed0a0-0x4ed30e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall Map_UpdateObjectScreenBounds(void *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  tagRECT local_10;
  
  piVar1 = (int *)Grid_GetCell(param_1,(*(int *)((int)param_1 + 0x1c) >> 1) -
                                       (*(int *)((int)param_1 + 0x14) >> 1),
                               (*(int *)((int)param_1 + 0x20) >> 1) +
                               (*(int *)((int)param_1 + 0x18) >> 1));
  *(int *)((int)param_1 + 0x2c) = *piVar1 + (*(int *)((int)param_1 + 0xc) >> 1);
  puVar2 = (undefined4 *)
           Grid_GetCell(param_1,(*(int *)((int)param_1 + 0x1c) >> 1) +
                                (*(int *)((int)param_1 + 0x14) >> 1),
                        (*(int *)((int)param_1 + 0x20) >> 1) - (*(int *)((int)param_1 + 0x18) >> 1))
  ;
  *(undefined4 *)((int)param_1 + 0x34) = *puVar2;
  iVar3 = Grid_GetCell(param_1,(*(int *)((int)param_1 + 0x1c) >> 1) -
                               (*(int *)((int)param_1 + 0x14) >> 1),
                       (*(int *)((int)param_1 + 0x20) >> 1) - (*(int *)((int)param_1 + 0x18) >> 1));
  *(int *)((int)param_1 + 0x30) = *(int *)(iVar3 + 4) + *(int *)((int)param_1 + 0x10);
  iVar3 = Grid_GetCell(param_1,(*(int *)((int)param_1 + 0x1c) >> 1) +
                               (*(int *)((int)param_1 + 0x14) >> 1),
                       (*(int *)((int)param_1 + 0x20) >> 1) + (*(int *)((int)param_1 + 0x18) >> 1));
  *(undefined4 *)((int)param_1 + 0x38) = *(undefined4 *)(iVar3 + 4);
  if (*(int *)((int)param_1 + 0xc) == 0x10) {
    iVar3 = DAT_00571958;
    iVar4 = DAT_0057195c;
  }
  else {
    iVar3 = DAT_00571950;
    iVar4 = DAT_00571954;
  }
  SetRect(&local_10,0,0,iVar3,iVar4);
  _DAT_0058073c = *(undefined4 *)((int)param_1 + 0x2c);
  _DAT_00580740 = *(undefined4 *)((int)param_1 + 0x30);
  _DAT_00580744 = *(undefined4 *)((int)param_1 + 0x34);
  _DAT_00580748 = *(undefined4 *)((int)param_1 + 0x38);
  iVar3 = *(int *)((int)param_1 + 0x70);
  if (iVar3 == 0) {
    if (*(int *)((int)param_1 + 0x74) == 0) {
      *(int *)((int)param_1 + 0x34) =
           *(int *)((int)param_1 + 0x34) +
           ((*(int *)((int)param_1 + 0xc) >> 1) - local_10.right) + local_10.left;
      *(int *)((int)param_1 + 0x38) =
           *(int *)((int)param_1 + 0x38) +
           (*(int *)((int)param_1 + 0x10) - local_10.bottom) + local_10.top;
      goto LAB_004ed2a1;
    }
    Sprite_GetSize(*(void **)((int)param_1 + 0x74),&local_20,&local_18);
    Sprite_GetHotspot(*(void **)((int)param_1 + 0x74),&local_1c,&local_14);
    local_20 = local_20 + local_1c;
    local_18 = local_18 + local_14;
  }
  else {
    local_20 = *(int *)(iVar3 + 4) + 0x200;
    local_18 = *(int *)(iVar3 + 8) + 0x100;
  }
  local_20 = *(int *)((int)param_1 + 0x2c) + *(int *)((int)param_1 + 0xc) * DAT_00571960 * -2 +
             local_20;
  iVar3 = local_18 + *(int *)((int)param_1 + 0x10) * DAT_00571964 * -2 +
          *(int *)((int)param_1 + 0x30);
  if (local_20 < *(int *)((int)param_1 + 0x34)) {
    *(int *)((int)param_1 + 0x34) = local_20;
  }
  if (iVar3 < *(int *)((int)param_1 + 0x38)) {
    *(int *)((int)param_1 + 0x38) = iVar3;
  }
  *(int *)((int)param_1 + 0x10160) = *(int *)((int)param_1 + 0x34);
  *(int *)((int)param_1 + 0x10164) = *(int *)((int)param_1 + 0x38);
  *(int *)((int)param_1 + 0x34) = (*(int *)((int)param_1 + 0x34) - local_10.right) + local_10.left;
  *(int *)((int)param_1 + 0x38) = (*(int *)((int)param_1 + 0x38) - local_10.bottom) + local_10.top;
LAB_004ed2a1:
  iVar3 = *(int *)((int)param_1 + 0x2c);
  if (*(int *)((int)param_1 + 0x34) < iVar3) {
    *(int *)((int)param_1 + 0x34) = iVar3;
  }
  iVar4 = *(int *)((int)param_1 + 0x30);
  if (*(int *)((int)param_1 + 0x38) < iVar4) {
    *(int *)((int)param_1 + 0x38) = iVar4;
  }
  iVar5 = *(int *)((int)param_1 + 0x34) - *(int *)((int)param_1 + 0x10168);
  if (iVar5 < *(int *)((int)param_1 + 0x24)) {
    *(int *)((int)param_1 + 0x24) = iVar5;
  }
  iVar5 = *(int *)((int)param_1 + 0x10170) + *(int *)((int)param_1 + 0x38);
  if (iVar5 < *(int *)((int)param_1 + 0x28)) {
    *(int *)((int)param_1 + 0x28) = iVar5;
  }
  iVar3 = *(int *)((int)param_1 + 0x1016c) + iVar3;
  if (*(int *)((int)param_1 + 0x24) < iVar3) {
    *(int *)((int)param_1 + 0x24) = iVar3;
  }
  iVar4 = iVar4 - *(int *)((int)param_1 + 0x10174);
  if (*(int *)((int)param_1 + 0x28) < iVar4) {
    *(int *)((int)param_1 + 0x28) = iVar4;
  }
  return;
}

