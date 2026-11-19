// rea decompile_all
// name: Branch_GetPriceComparisonRating
// address: 0x478420
// body: available
// range: 0x478420-0x4784db inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall Branch_GetPriceComparisonRating(void *this,int param_1,undefined4 *param_2)

{
  void *this_00;
  void *this_01;
  int iVar1;
  int iVar2;
  
  this_00 = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)((int)this + 0x30));
  this_01 = (void *)Player_FindRecordType2ByKey(this_00,*(int *)((int)this + 0x3c));
  if (this_01 == (void *)0x0) {
    *param_2 = 0;
    return 0;
  }
  if (*(int *)((int)this_01 + 4) == 0) {
    *param_2 = 0;
    return 0;
  }
  *param_2 = 1;
  if (param_1 == -1) {
    iVar1 = GamePlan_ComputeAverageEffect(this_01,*(int *)((int)this + 0x30));
  }
  else {
    iVar1 = GamePlan_ComputeCategoryEffect(this_01,*(int *)((int)this + 0x30),param_1);
  }
  iVar2 = Game_GetPlayerCity((int)this_00);
  iVar1 = (((*(int *)(iVar2 + 0x5c) + *(int *)(iVar2 + 0x44)) * -3 + 100) * iVar1) / 100;
  if (100 < iVar1) {
    return 100;
  }
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  return iVar1;
}

