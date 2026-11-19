// rea decompile_all
// name: Player_HasRecordWithField30
// address: 0x4da6b0
// body: available
// range: 0x4da6b0-0x4da6ff inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint Player_HasRecordWithField30(int param_1,int param_2)

{
  void *this;
  int iVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = Game_GetPlayerBySlot(DAT_0057c670,param_2);
  iVar1 = *(int *)(uVar2 + 0x194);
  iVar3 = 0;
  if (0 < iVar1) {
    this = (void *)(uVar2 + 0x180);
    do {
      uVar2 = IDMap_Lookup(this,iVar3,(int *)0x0);
      if (*(int *)(uVar2 + 0x30) == param_1) {
        return CONCAT31((int3)(uVar2 >> 8),1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  return uVar2 & 0xffffff00;
}

