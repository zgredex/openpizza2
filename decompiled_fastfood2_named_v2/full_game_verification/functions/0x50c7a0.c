// rea decompile_all
// name: MapObject_IsTargetFacingMe
// address: 0x50c7a0
// body: available
// range: 0x50c7a0-0x50c89a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall MapObject_IsTargetFacingMe(void *this,undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  void *this_00;
  uint uVar5;
  uint *puVar6;
  float local_8;
  int local_4;
  
  iVar2 = MapObject_ComputeBlitRect((int)this);
  iVar3 = MapObject_ComputeBlitRect(param_2);
  iVar3 = IsMenuId34EOr350(*(int *)(*(int *)(iVar3 + 8) + 4));
  iVar2 = IsMenuId34EOr350(*(int *)(*(int *)(iVar2 + 8) + 4));
  if (iVar2 == iVar3) {
    piVar1 = *(int **)(param_2 + 200);
    if (piVar1 == (int *)0x0) {
      iVar2 = -1;
      this_00 = (void *)0x0;
    }
    else {
      iVar2 = *piVar1;
      this_00 = (void *)piVar1[0x16];
    }
    Record_GetTwoFloats48(this_00,iVar2,&local_8,&local_4);
    local_8 = (float)((int)local_8 + *(int *)(*(int *)((int)this + 0xc4) + 0xf8));
    local_4 = local_4 + *(int *)(*(int *)((int)this + 0xc4) + 0xfc);
    uVar4 = UI_ComputeObjectDirection(this,local_8,local_4);
    if (*(int *)((int)this + 200) == 0) {
      uVar5 = 0xffffffff;
    }
    else {
      uVar5 = *(uint *)(*(int *)((int)this + 200) + 0xc);
    }
    uVar5 = uVar5 & 0x80000007;
    if ((int)uVar5 < 0) {
      uVar5 = (uVar5 - 1 | 0xfffffff8) + 1;
    }
    iVar2 = 0;
    puVar6 = (uint *)(&DAT_00572bac + uVar5 * 0x14);
    do {
      if (*puVar6 == uVar4) {
        return 1;
      }
      iVar2 = iVar2 + 1;
      puVar6 = puVar6 + 1;
    } while (iVar2 < 5);
  }
  return 0;
}

