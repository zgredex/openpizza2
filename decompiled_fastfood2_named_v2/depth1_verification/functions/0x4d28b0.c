// rea decompile_all
// name: FUN_004d28b0
// address: 0x4d28b0
// body: available
// range: 0x4d28b0-0x4d28ef inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_004d28b0(int param_1)

{
  void *this;
  int iVar1;
  
  this = (void *)FUN_00528040(DAT_0057c5e0,*(int *)(DAT_0057c670 + 0x2dac),(int *)0x0);
  if (this != (void *)0x0) {
    iVar1 = Array_GetRecordByKeyPtr(this,*(int *)(param_1 + 0x54));
    if (iVar1 != 0) {
      FUN_005311a0(this,*(int *)(param_1 + 0x54));
    }
  }
  return;
}

