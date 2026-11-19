// rea decompile_all
// name: Game_GetPlayerSupplyScore
// address: 0x4dbf50
// body: available
// range: 0x4dbf50-0x4dbfbb inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall Game_GetPlayerSupplyScore(void *this,int param_1)

{
  void *this_00;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)((int)this + param_1 * 4 + 0xc98);
  this_00 = (void *)Game_GetPlayerBySlot(DAT_0057c670,param_1);
  iVar1 = Game_CountActiveObjectsByType(this_00,0x1e);
  iVar2 = Game_CountActiveObjectsByType(this_00,0x1d);
  iVar3 = Game_GetPlayerCity((int)this_00);
  iVar4 = iVar4 + ((*(int *)(iVar3 + 0x60) + *(int *)(iVar3 + 0x48)) * 3 - (iVar1 + iVar2));
  if (100 < iVar4) {
    return 100;
  }
  if (iVar4 < 0) {
    return 0;
  }
  return iVar4;
}

