// rea decompile_all
// name: FUN_004acb90
// address: 0x4acb90
// body: available
// range: 0x4acb90-0x4acdb4 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004acb90(void *param_1,int *param_2,int *param_3,int param_4)

{
  int *piVar1;
  int *piVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int local_c;
  int local_8;
  int local_4;
  
  piVar1 = param_3;
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  iVar9 = (int)param_2 - (int)param_3;
  iVar8 = param_4 - (int)param_3;
  param_3 = (int *)0x9;
  piVar2 = piVar1;
  do {
    iVar5 = *(int *)(iVar9 + (int)piVar2);
    if (local_c < iVar5) {
      local_c = iVar5;
    }
    if (local_8 < *piVar2) {
      local_8 = *piVar2;
    }
    iVar5 = *(int *)(iVar8 + (int)piVar2);
    if (local_4 < iVar5) {
      local_4 = iVar5;
    }
    piVar2 = piVar2 + 1;
    param_3 = (int *)((int)param_3 + -1);
  } while (param_3 != (int *)0x0);
  iVar5 = (int)piVar1 - (int)param_2;
  iVar9 = (int)&DAT_00569630 - (int)param_2;
  iVar6 = param_4 - (int)param_2;
  iVar8 = 0x8a2;
  while( true ) {
    pvVar3 = (void *)FUN_00531cf0(param_1,*(int *)(iVar9 + (int)param_2));
    FUN_00521380((int)pvVar3);
    if (local_c != 0) {
      iVar4 = (*param_2 * 100) / local_c;
      if (iVar4 < 0x4c) {
        uVar7 = ((iVar4 < 0x1a) - 1 & 0xff00) + 0xff;
      }
      else {
        uVar7 = 0xa000;
      }
      FUN_005219a0(pvVar3,0,0,(iVar4 * 0x24) / 100,0xf,uVar7);
    }
    FUN_00521b30((int)pvVar3);
    pvVar3 = (void *)FUN_00531cf0(param_1,iVar8 + -10);
    FUN_00521380((int)pvVar3);
    if (local_8 != 0) {
      iVar4 = (*(int *)(iVar5 + (int)param_2) * 100) / local_8;
      if (iVar4 < 0x4c) {
        uVar7 = ((iVar4 < 0x1a) - 1 & 0xff00) + 0xff;
      }
      else {
        uVar7 = 0xa000;
      }
      FUN_005219a0(pvVar3,0,0,(iVar4 * 0x24) / 100,0xf,uVar7);
    }
    FUN_00521b30((int)pvVar3);
    pvVar3 = (void *)FUN_00531cf0(param_1,iVar8);
    FUN_00521380((int)pvVar3);
    if (local_4 != 0) {
      iVar4 = (*(int *)(iVar6 + (int)param_2) * 100) / local_4;
      if (iVar4 < 0x4c) {
        uVar7 = ((iVar4 < 0x1a) - 1 & 0xff00) + 0xff;
      }
      else {
        uVar7 = 0xa000;
      }
      FUN_005219a0(pvVar3,0,0,(iVar4 * 0x5e) / 100,0xf,uVar7);
    }
    FUN_00521b30((int)pvVar3);
    param_2 = param_2 + 1;
    if (8 < iVar8 + -0x8a1) break;
    iVar8 = iVar8 + 1;
  }
  return;
}

