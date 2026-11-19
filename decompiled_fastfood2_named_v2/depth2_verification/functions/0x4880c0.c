// rea decompile_all
// name: FUN_004880c0
// address: 0x4880c0
// body: available
// range: 0x4880c0-0x488104 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


longlong __cdecl FUN_004880c0(int *param_1,int param_2)

{
  int iVar1;
  longlong lVar2;
  
  iVar1 = Stream_GetReadPosition(param_1);
  if (param_2 < 1) {
    iVar1 = 0x14;
  }
  else {
    iVar1 = (iVar1 * 0x50) / param_2 + 0x14;
  }
  FUN_0052fd70(DAT_0057c5f4,0x3f7,iVar1,0);
  lVar2 = FUN_00525a10(DAT_0057c5e0,0);
  return lVar2;
}

