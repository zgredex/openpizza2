// rea decompile_all
// name: Game_ComputeObjectDetails
// address: 0x5092b0
// body: available
// range: 0x5092b0-0x509491 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall
Game_ComputeObjectDetails
          (void *this,int param_1,undefined4 *param_2,int param_3,int *param_4,int *param_5,
          int *param_6,int *param_7)

{
  int iVar1;
  void *this_00;
  int iVar2;
  undefined4 *puVar3;
  int extraout_EDX;
  int iVar4;
  int unaff_EDI;
  void *this_01;
  longlong lVar5;
  uint local_14;
  int local_10;
  void *local_c;
  int local_8;
  int local_4;
  
  iVar1 = *(int *)(param_1 + 0x2c);
  iVar2 = *(int *)(param_1 + 8);
  Game_GetPlayerBySlot(DAT_0057c670,iVar2);
  iVar1 = Game_GetPlayerSubmapValue(DAT_0057c670,iVar2,iVar1);
  iVar4 = 0;
  local_4 = iVar1;
  this_00 = (void *)IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)((int)this + 0x28),
                                 (int *)0x0);
  this_01 = (void *)*param_2;
  local_c = this_01;
  iVar2 = Game_GetSkillRating(this_01,iVar1,(float)param_2[1],*(int *)((int)this + 0x34));
  if (param_4 != (int *)0x0) {
    *param_4 = iVar2;
  }
  local_8 = Player_ComputeProductQualityScore
                      (iVar1,extraout_EDX,this_01,*(int *)((int)this + 0x34),unaff_EDI);
  if (param_5 != (int *)0x0) {
    *param_5 = local_8;
  }
  puVar3 = (undefined4 *)0x0;
  param_4 = (int *)0x0;
  param_2 = (undefined4 *)0x0;
  param_1 = 0;
  iVar1 = 0xa8;
  do {
    if (0 < *(int *)((int)this_01 + iVar1 + -0x44)) {
      iVar2 = *(int *)(iVar1 + (int)DAT_0057c670);
      Market_ComputeValueAdjustment
                (this_00,'\0',*(uint *)((int)this + 0x34),iVar2,&local_14,&local_10);
      if (iVar1 != 0xa8) {
        iVar2 = Market_GetPriceModifier
                          (this_00,*(int *)((int)this + 0x34),(uint)*(byte *)(iVar2 + 0xa8));
        param_4 = (int *)((int)param_4 + iVar2);
        iVar4 = iVar4 + local_14;
        param_1 = param_1 + 1;
      }
      puVar3 = (undefined4 *)((int)param_2 + local_10);
      this_01 = local_c;
      param_2 = puVar3;
    }
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0x200);
  if (param_1 < 1) {
    iVar1 = -0x28;
  }
  else {
    iVar1 = (int)puVar3 + iVar4 / param_1 + (int)param_4 / param_1;
  }
  if (param_6 != (int *)0x0) {
    *param_6 = iVar1;
  }
  lVar5 = __ftol();
  iVar1 = (int)lVar5;
  if (iVar1 < 0x65) {
    if (iVar1 < 0) {
      iVar1 = 0;
    }
  }
  else {
    iVar1 = 100;
  }
  if (param_7 != (int *)0x0) {
    *param_7 = iVar1;
  }
  return;
}

