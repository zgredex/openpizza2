// rea decompile_all
// name: FUN_004d9a10
// address: 0x4d9a10
// body: available
// range: 0x4d9a10-0x4d9bf3 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004d9a10(void *this,int param_1,void *param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  
  iVar3 = param_4;
  iVar5 = *(int *)((int)param_2 + 0x30);
  iVar6 = 0;
  if (param_4 != -1) {
    iVar4 = FUN_00488be0(DAT_0057c670,param_4);
    iVar4 = FUN_004ddcc0(iVar4);
    param_4 = *(int *)(iVar4 + 0x54) + *(int *)(iVar4 + 0x3c);
  }
  if (-1 < param_3) {
    Game_AdjustPlayerPercentByKey(*(void **)((int)DAT_0057c670 + 0x90),iVar5);
  }
  if (param_1 == 0) {
    iVar4 = Game_GetConstructionPriority((int)param_2);
    iVar6 = 1;
  }
  else if (param_1 == 1) {
    iVar4 = Game_GetBuildingConditionCode(param_2);
    iVar6 = 0;
  }
  else if (param_1 == 2) {
    iVar4 = Stats_HasCurrentSales((int)param_2);
    iVar6 = 2;
  }
  else {
    iVar4 = param_3;
  }
  *(int *)((int)this + iVar6 * 0xc + 0xd88) = *(int *)((int)this + iVar6 * 0xc + 0xd88) + 1;
  if (-1 < param_3) {
    iVar1 = iVar6 * 3 + 0x363;
    *(int *)((int)this + iVar1 * 4) = *(int *)((int)this + iVar1 * 4) + 1;
  }
  if (iVar4 == 0) {
    if ((param_3 == 2) && (iVar3 != -1)) {
      piVar2 = (int *)((int)this + (param_1 + iVar3 * 4) * 4 + 0xc38);
      iVar5 = (*piVar2 * 0x12) / 10;
      *piVar2 = iVar5;
      if (100 < iVar5) {
        *piVar2 = 100;
      }
    }
    if (param_2 != *(void **)((int)DAT_0057c670 + 0x9c)) {
      return;
    }
    uVar7 = 0xc;
  }
  else {
    *(int *)((int)this + iVar6 * 0xc + 0xd90) = *(int *)((int)this + iVar6 * 0xc + 0xd90) + 1;
    iVar6 = FUN_00482820((int)DAT_0057c670);
    if (iVar5 == iVar6) {
      piVar2 = (int *)((int)this + iVar4 * 8 + 0xd50);
      *piVar2 = *piVar2 + 1;
    }
    *(int *)((int)this + iVar4 * 8 + 0xd54) = *(int *)((int)this + iVar4 * 8 + 0xd54) + 1;
    iVar5 = FUN_00488be0(DAT_0057c670,iVar5);
    FUN_004e3f50(iVar5);
    if ((param_3 == 2) && (iVar3 != -1)) {
      iVar5 = param_1 + iVar3 * 4;
      piVar2 = (int *)((int)this + iVar5 * 4 + 0xc38);
      iVar5 = param_4 * 3 + (*(int *)((int)this + iVar5 * 4 + 0xc38) * 5) / 10;
      *piVar2 = iVar5;
      if (iVar5 < 0) {
        *piVar2 = 0;
      }
    }
    if (param_2 != *(void **)((int)DAT_0057c670 + 0x9c)) {
      return;
    }
    uVar7 = 0xb;
  }
  Sound_ProcessEvent(DAT_0057ba0c,10,uVar7,'\x01');
  return;
}

