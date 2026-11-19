// rea decompile_all
// name: Game_ComputeCompanyProductScore
// address: 0x513b00
// body: available
// range: 0x513b00-0x513be7 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall Game_ComputeCompanyProductScore(void *this,int param_1,uint param_2,float param_3)

{
  void *this_00;
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint local_8;
  int local_4;
  
  iVar2 = 0;
  this_00 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(param_1 + 0x34),(int *)0x0);
  uVar4 = param_2;
  if (param_2 == 8) {
    uVar4 = 5;
  }
  iVar1 = Game_GetSkillRating(this,param_1,param_3,uVar4);
  param_1 = 0;
  param_2 = 0;
  iVar3 = 0xa8;
  do {
    if (0 < *(int *)((int)this + iVar3 + -0x44)) {
      Market_ComputeValueAdjustment
                (this_00,'\0',uVar4,*(int *)(iVar3 + DAT_0057c670),&local_8,&local_4);
      if (iVar3 != 0xa8) {
        iVar2 = iVar2 + local_8;
        param_1 = param_1 + 1;
      }
      param_2 = param_2 + local_4;
    }
    iVar3 = iVar3 + 4;
  } while (iVar3 < 0x200);
  if (param_1 < 1) {
    iVar2 = -0x28;
  }
  else {
    iVar2 = iVar2 / param_1 + param_2;
  }
  iVar2 = iVar2 + iVar1;
  if (iVar2 < 0) {
    return 0;
  }
  if (100 < iVar2) {
    iVar2 = 100;
  }
  return iVar2;
}

