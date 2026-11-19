// rea decompile_all
// name: FUN_0047d910
// address: 0x47d910
// body: available
// range: 0x47d910-0x47db0c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __fastcall FUN_0047d910(int param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int extraout_EDX;
  int iVar5;
  int iVar6;
  int iVar7;
  ulonglong uVar8;
  longlong lVar9;
  int local_c;
  
  iVar6 = 0;
  iVar5 = 0;
  iVar7 = 0;
  local_c = 100;
  if (*(int *)(param_1 + 0x19ac) < 1) {
LAB_0047d986:
    iVar7 = 0;
LAB_0047d988:
    if (iVar7 < *(int *)(&DAT_00567938 + param_4 * 4)) {
      param_2 = (iVar7 - *(int *)(&DAT_00567938 + param_4 * 4)) * 2 + 100;
      local_c = param_2;
    }
  }
  else {
    do {
      iVar1 = IDMap_Lookup((void *)(param_1 + 0x1998),iVar7,(int *)0x0);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 0x1c) != 0)) {
        iVar6 = iVar6 + 1;
        iVar5 = iVar5 + *(int *)(iVar1 + 4);
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < *(int *)(param_1 + 0x19ac));
    param_2 = extraout_EDX;
    if (iVar6 == 0) goto LAB_0047d986;
    iVar7 = iVar5 / iVar6;
    param_2 = iVar5 % iVar6;
    if (-1 < iVar7) goto LAB_0047d988;
    local_c = (iVar7 - *(int *)(&DAT_00567938 + param_4 * 4)) * 4 + 100;
  }
  uVar8 = FUN_0047ca80(param_1,param_2,'\x05');
  iVar5 = (int)(uVar8 >> 0x20);
  uVar2 = (uint)uVar8 & 0xff;
  *(uint *)(param_1 + 0x1870) = uVar2;
  if ((int)uVar2 < *(int *)(&DAT_00567958 + param_4 * 4)) {
    iVar5 = local_c + (uVar2 - *(int *)(&DAT_00567958 + param_4 * 4)) * 10;
  }
  uVar8 = FUN_0047c9a0(param_1,iVar5,'\x05');
  uVar2 = (uint)uVar8 & 0xff;
  lVar9 = FUN_0047cb70(param_1,(uint)(uVar8 >> 0x20),'\x05');
  lVar9 = FUN_00403850((float)uVar2 * 0.01 * (float)(int)lVar9);
  iVar5 = (int)lVar9;
  if (iVar5 < 0) {
    if (5 < iVar5) goto LAB_0047da2f;
    iVar5 = 100;
  }
  else if (iVar5 < 6) {
    iVar5 = *(int *)(&DAT_00567978 + (iVar5 + param_4 * 6) * 4);
  }
  else {
LAB_0047da2f:
    iVar5 = *(int *)(&DAT_0056798c + param_4 * 0x18);
  }
  iVar6 = 0;
  iVar5 = uVar2 - iVar5;
  iVar7 = 0;
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x1514)) {
    do {
      piVar3 = (int *)IDMap_Lookup((void *)(param_1 + 0x1500),iVar1,(int *)0x0);
      iVar4 = *piVar3;
      if ((iVar4 != 0) && (*(char *)(iVar4 + 0x824) == '\0')) {
        iVar6 = iVar6 + 1;
        iVar4 = Rating_ClampAdjusted(iVar4);
        iVar7 = iVar7 + iVar4;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x1514));
    if (0 < iVar6) {
      iVar6 = (iVar7 / iVar6) / 0xc;
      if (iVar6 < 0) {
        return iVar5 - *(int *)(&DAT_00567a38 + param_5 * 0x24);
      }
      if (8 < iVar6) {
        return iVar5 - *(int *)(&DAT_00567a58 + param_5 * 0x24);
      }
      goto LAB_0047daca;
    }
  }
  iVar6 = 0;
LAB_0047daca:
  return iVar5 - *(int *)(&DAT_00567a38 + (iVar6 + param_5 * 9) * 4);
}

