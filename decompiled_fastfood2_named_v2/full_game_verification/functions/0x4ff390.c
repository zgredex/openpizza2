// rea decompile_all
// name: AI_OpenBranchesInCity
// address: 0x4ff390
// body: available
// range: 0x4ff390-0x4ff4b6 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall AI_OpenBranchesInCity(void *this,void *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined3 extraout_var;
  
                    /* Opens a population-limited number of AI branches. */
  iVar5 = *(int *)((int)param_1 + 0x4c);
  iVar2 = AI_CountAvailableTargets(param_1,0x1d);
  iVar3 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(param_2 + 0x30));
  iVar3 = *(int *)(iVar3 + 100);
  iVar4 = Game_UpdateFreeBuildingCount(param_2);
  iVar5 = ((*(short *)((int)this + iVar5 * 0x168 + 0x130) + 0x32) * iVar4 * iVar3) / 100;
  if (iVar5 == 0) {
    return 1;
  }
  iVar3 = Game_CountFilteredObjects
                    (DAT_0057c670,0x10,0x1d,*(int *)(param_2 + 0x16f0),*(int *)((int)param_1 + 0x48)
                    );
  if (iVar3 != 0) {
    return 1;
  }
  iVar3 = 0;
  if ((((0 < iVar2) && (iVar5 = iVar5 / *(int *)((int)param_1 + 0x6c), iVar5 <= iVar2)) &&
      (bVar1 = Math_CompareRounded(), CONCAT31(extraout_var,bVar1) != 0)) && (0 < iVar5)) {
    do {
      iVar2 = AI_HireBranchWorker(param_1,param_2);
      if (iVar2 == 0) {
        if (iVar3 == 0) {
          return 0;
        }
        break;
      }
      iVar3 = 1;
      iVar5 = iVar5 + -1;
      *(int *)((int)param_1 + 0x74) = *(int *)((int)param_1 + 0x74) + 1;
    } while (0 < iVar5);
    iVar5 = *(int *)(param_2 + 0x30);
    iVar2 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670);
    if (iVar5 == iVar2) {
      Sound_SetTimeout(DAT_0057ba0c);
    }
  }
  return iVar3;
}

