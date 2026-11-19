// rea decompile_all
// name: CityInfo_InitQuarterPanel
// address: 0x4c4fa0
// body: available
// range: 0x4c4fa0-0x4c51a4 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl CityInfo_InitQuarterPanel(void *param_1)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  undefined4 local_48 [7];
  int local_2c [8];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
                    /* Fills the city info quarter labels or traffic grid. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558b98;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004013a0(local_48,0);
  local_4 = 0;
  iVar3 = FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  iVar3 = *(int *)(iVar3 + 0x10c0);
  bVar1 = *(byte *)(*(int *)(DAT_0057c670 + 0x94) + 7);
  uVar7 = (uint)*(byte *)(*(int *)(DAT_0057c670 + 0x94) + 8);
  iVar4 = FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  uVar5 = FUN_004dca70(iVar4);
  FUN_0052f9b0(param_1,0x1f56,uVar5);
  if (iVar3 < 1) {
    FUN_00531740(param_1,0x1f44);
    FUN_00531740(param_1,0x1f46);
    FUN_00531740(param_1,0x1f47);
    FUN_0052f9b0(param_1,0x1f45,DAT_00581ae0);
    piVar8 = local_2c;
    for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
      *piVar8 = 0;
      piVar8 = piVar8 + 1;
    }
    iVar3 = 0;
    if (0 < *(int *)(DAT_0057c670 + 0x50)) {
      do {
        iVar4 = FUN_004017f0((void *)(DAT_0057c670 + 0x3c),iVar3,(int *)0x0);
        bVar2 = FUN_0050e540(iVar4);
        if (bVar2) {
          FUN_004014b0(local_48,iVar4);
          iVar4 = *(int *)(iVar4 + 0x30);
          if ((-1 < iVar4) && (iVar4 < 9)) {
            local_2c[iVar4] = local_2c[iVar4] + 1;
          }
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(DAT_0057c670 + 0x50));
    }
    FUN_0048aef0(param_1,0x1f4a,local_2c);
  }
  else {
    iVar3 = (uint)bVar1 + iVar3;
    if (0x18 < iVar3) {
      uVar6 = (iVar3 - 1U) / 0x18;
      iVar3 = iVar3 + uVar6 * -0x18;
      do {
        uVar7 = uVar7 + 1;
        if (3 < (int)uVar7) {
          uVar7 = 0;
        }
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    UI_ShowChildByID(param_1,0x1f44);
    UI_ShowChildByID(param_1,0x1f46);
    UI_ShowChildByID(param_1,0x1f47);
    FUN_0052f080(param_1,0x1f45,(byte *)s__d_Quarter__d_0056af2c,uVar7 + 1);
    FUN_0052f080(param_1,0x1f47,(byte *)s__02d_00_0056af24,iVar3);
  }
  local_4 = 0xffffffff;
  FUN_00401480(local_48);
  ExceptionList = local_c;
  return;
}

