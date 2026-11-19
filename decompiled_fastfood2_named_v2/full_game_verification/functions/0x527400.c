// rea decompile_all
// name: StringList_Find
// address: 0x527400
// body: available
// range: 0x527400-0x52757e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall StringList_Find(void *this,byte *param_1,int *param_2)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  bool bVar9;
  
  iVar5 = *(int *)((int)this + 0x82f8);
  if ((iVar5 == 0) || (*(int *)((int)this + 0x82fc) == 0)) {
    *param_2 = 0;
    return 0;
  }
  iVar6 = 0;
  iVar4 = *(int *)((int)this + 0x82fc) + -1;
  iVar2 = iVar4;
  while (1 < iVar4) {
    iVar8 = iVar6 + iVar2 >> 1;
    pbVar3 = (byte *)(iVar5 + iVar8 * 0x48);
    pbVar7 = param_1;
    do {
      bVar1 = *pbVar3;
      bVar9 = bVar1 < *pbVar7;
      if (bVar1 != *pbVar7) {
LAB_00527462:
        iVar4 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        goto LAB_00527467;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar9 = bVar1 < pbVar7[1];
      if (bVar1 != pbVar7[1]) goto LAB_00527462;
      pbVar3 = pbVar3 + 2;
      pbVar7 = pbVar7 + 2;
    } while (bVar1 != 0);
    iVar4 = 0;
LAB_00527467:
    if (iVar4 == 0) {
      *param_2 = iVar8;
      return 1;
    }
    if (iVar4 == -1) {
      iVar6 = iVar8;
      iVar8 = iVar2;
    }
    iVar2 = iVar8;
    iVar4 = iVar8 - iVar6;
  }
  pbVar3 = (byte *)(iVar5 + iVar6 * 0x48);
  pbVar7 = param_1;
  do {
    bVar1 = *pbVar3;
    bVar9 = bVar1 < *pbVar7;
    if (bVar1 != *pbVar7) {
LAB_005274c4:
      iVar4 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
      goto LAB_005274c9;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar3[1];
    bVar9 = bVar1 < pbVar7[1];
    if (bVar1 != pbVar7[1]) goto LAB_005274c4;
    pbVar3 = pbVar3 + 2;
    pbVar7 = pbVar7 + 2;
  } while (bVar1 != 0);
  iVar4 = 0;
LAB_005274c9:
  if (iVar4 == 0) {
    *param_2 = iVar6;
    return 1;
  }
  pbVar3 = (byte *)(iVar5 + iVar2 * 0x48);
  do {
    bVar1 = *pbVar3;
    bVar9 = bVar1 < *param_1;
    if (bVar1 != *param_1) {
LAB_00527513:
      iVar5 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
      goto LAB_00527518;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar3[1];
    bVar9 = bVar1 < param_1[1];
    if (bVar1 != param_1[1]) goto LAB_00527513;
    pbVar3 = pbVar3 + 2;
    param_1 = param_1 + 2;
  } while (bVar1 != 0);
  iVar5 = 0;
LAB_00527518:
  if (iVar5 == 0) {
    *param_2 = iVar2;
    return 1;
  }
  if (iVar5 == -1) {
    *param_2 = iVar2 + 1;
    return 0;
  }
  if (iVar4 == -1) {
    *param_2 = iVar6 + 1;
    return 0;
  }
  *param_2 = iVar6;
  return 0;
}

