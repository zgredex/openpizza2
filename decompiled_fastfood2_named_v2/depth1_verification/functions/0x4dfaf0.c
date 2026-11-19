// rea decompile_all
// name: FUN_004dfaf0
// address: 0x4dfaf0
// body: available
// range: 0x4dfaf0-0x4dfcc2 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004dfaf0(void *this,int *param_1)

{
  ushort uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  void *this_00;
  int *piVar6;
  int iVar7;
  int local_18;
  int local_10;
  int local_c;
  
  piVar3 = param_1;
  uVar1 = *(ushort *)(*(int *)((int)DAT_0057c670 + 0x94) + 10);
  local_18 = 0;
  iVar2 = *(int *)((int)this + 0x124);
  local_c = 0;
  iVar7 = 1;
  *(int *)(*param_1 + 0x9c) = iVar2;
  iVar4 = Game_CountActiveCompanies((int)this);
  iVar5 = *param_1;
  param_1 = (int *)0x0;
  *(int *)(iVar5 + 0xa0) = iVar4;
  do {
    iVar5 = FUN_00488be0(DAT_0057c670,(int)param_1);
    if (iVar5 != 0) {
      iVar5 = Game_CountActiveCompanies(iVar5);
      if (iVar4 < iVar5) {
        iVar7 = 0;
      }
    }
    param_1 = (int *)((int)param_1 + 1);
  } while ((int)param_1 < 6);
  iVar4 = 0;
  piVar6 = (int *)0x0;
  local_10 = 0;
  param_1 = (int *)0x0;
  *(int *)(*piVar3 + 0x170) = (iVar2 + iVar7 * 10) * 500;
  iVar2 = *(int *)((int)this + 0x124);
  iVar5 = 0;
  if (0 < iVar2) {
    do {
      this_00 = (void *)FUN_004017f0((void *)((int)this + 0x110),iVar4,(int *)0x0);
      iVar5 = AI_CountPlanSteps(this_00,uVar1 - 1,0,-1);
      local_10 = local_10 + iVar5;
      if (local_18 < iVar5) {
        local_18 = iVar5;
      }
      iVar5 = 0;
      do {
        iVar7 = Game_MapInputIndex(this_00,iVar5);
        if (local_c < iVar7) {
          local_c = iVar7;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < 8);
      iVar5 = Game_MapInputIndex(this_00,iVar4);
      piVar6 = (int *)((int)param_1 + iVar5);
      iVar4 = iVar4 + 1;
      param_1 = piVar6;
    } while (iVar4 < iVar2);
    iVar5 = local_18;
  }
  if (iVar2 != 0) {
    piVar6 = (int *)((int)piVar6 / iVar2);
  }
  *(int *)(*piVar3 + 0xa4) = local_10;
  *(int *)(*piVar3 + 0xa8) = iVar5;
  *(int **)(*piVar3 + 0xac) = piVar6;
  *(int *)(*piVar3 + 0xb0) = local_c;
  *(int *)(*piVar3 + 0x174) = local_10 / 5 + iVar5;
  *(int *)(*piVar3 + 0x178) = (int)piVar6 * 400;
  iVar2 = *(int *)((int)this + 0x54);
  iVar5 = *(int *)((int)this + 0x58);
  *(int *)(*piVar3 + 0xb4) = iVar2;
  *(int *)(*piVar3 + 0xb8) = iVar5;
  *(int *)(*piVar3 + 0x17c) = (iVar2 + iVar5) * 1000;
  return;
}

