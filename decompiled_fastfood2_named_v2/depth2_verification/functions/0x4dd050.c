// rea decompile_all
// name: FUN_004dd050
// address: 0x4dd050
// body: available
// range: 0x4dd050-0x4dd087 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004dd050(void *this,void *param_1)

{
  int iVar1;
  void *this_00;
  int iVar2;
  
  iVar1 = *(int *)((int)this + 0xfc0);
  iVar2 = 0;
  if (0 < iVar1) {
    do {
      this_00 = (void *)FUN_004017f0((void *)((int)this + 0xfac),iVar2,(int *)0x0);
      Game_RemoveRecordFromLocalMap(this_00,param_1);
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  return;
}

