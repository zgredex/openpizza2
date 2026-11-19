// rea decompile_all
// name: FUN_00490b00
// address: 0x490b00
// body: available
// range: 0x490b00-0x490bc5 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_00490b00(void *param_1)

{
  *(undefined4 *)(DAT_0057c5e0 + 0x831c) = 1;
  DAT_0057c6ac = *(undefined4 *)(DAT_0057c670 + 0x354);
  UI_SetPosition(param_1,&LAB_004900e0,0);
  FUN_00532330(param_1,0,6,0x3f4);
  FUN_0052ff50(param_1,*(int *)(&DAT_00568408 + DAT_0057c6a8 * 4),1);
  FUN_00532330(param_1,1,0xc,0x596);
  FUN_004909b0(param_1);
  return;
}

