// rea decompile_all
// name: AI_Annoy_SendThugsToHeadquarters
// address: 0x4ff200
// body: available
// range: 0x4ff200-0x4ff388 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall AI_Annoy_SendThugsToHeadquarters(void *this,void *param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined3 extraout_var;
  int *piVar4;
  void *this_00;
  undefined4 uVar5;
  int iVar6;
  
                    /* Sends hired thugs to a rival branch or headquarters. */
  uVar2 = _rand();
  iVar3 = FUN_004e1d40(param_1,0x1f);
  if (iVar3 < 2) {
    Player_AcquireBranch(this,param_1,4.34403e-44);
    return 1;
  }
  bVar1 = FUN_004ff650();
  if (CONCAT31(extraout_var,bVar1) == 0) {
    return 2;
  }
  iVar3 = AI_OpenBranchesInCity(this,param_1,param_2);
  if (iVar3 != 0) {
    piVar4 = FUN_004e1e40(param_1,0x1f);
    if (piVar4 == (int *)0x0) {
      return 3;
    }
    this_00 = (void *)FUN_004017f0((void *)((int)DAT_0057c670 + 0x3c),*piVar4,(int *)0x0);
    if (this_00 == (void *)0x0) {
      return 3;
    }
    if ((uVar2 & 1) == 0) {
      iVar3 = AI_HireBranchWorker(param_1,param_2);
      if (iVar3 == 0) {
        return 3;
      }
      iVar3 = AI_HireBranchWorker(param_1,param_2);
      if (iVar3 == 0) {
        return 3;
      }
      uVar5 = FUN_004e0b60(param_1,0x17,100000.0,'\x01',0xffffffff);
      if ((char)uVar5 != '\0') {
        Person_SendToBranchWithCarryMode(this_00,param_2,0x11);
      }
      FUN_004fcc30(this,*(int *)((int)param_1 + 0x4c),-0x14);
      return 1;
    }
    iVar3 = FUN_00488be0(DAT_0057c670,*(int *)(param_2 + 0x30));
    iVar3 = *(int *)(iVar3 + 0x1d8);
    if (iVar3 != 0) {
      iVar6 = AI_SendGangsterForProtection(param_1,iVar3);
      if (iVar6 == 0) {
        return 3;
      }
      iVar6 = AI_SendGangsterForProtection(param_1,iVar3);
      if (iVar6 == 0) {
        return 3;
      }
      Courier_StartHeadquartersBombing(this_00,iVar3);
      FUN_004fcc30(this,*(int *)((int)param_1 + 0x4c),-0x14);
    }
  }
  return 1;
}

