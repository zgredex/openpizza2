// rea decompile_all
// name: Mission_ApplySettings
// address: 0x4dc080
// body: available
// range: 0x4dc080-0x4dc0e5 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall Mission_ApplySettings(int param_1)

{
  DAT_0057bb24 = *(undefined4 *)(param_1 + 0x344);
  DAT_0057bb28 = *(undefined4 *)(param_1 + 0x48);
  DAT_0057bb2c = *(undefined4 *)(param_1 + 0x34c);
  DAT_0057bb30 = *(undefined4 *)(param_1 + 0x35c);
  DAT_0057bb34._0_1_ = 1;
  DAT_0057bb38 = *(undefined4 *)(param_1 + 0x360);
  DAT_0057bb3c._0_1_ = 1;
  DAT_0057bb48 = *(undefined4 *)(param_1 + 0x350);
  DAT_0057bb4c = *(undefined4 *)(param_1 + 0x354);
  DAT_0057bb50 = *(undefined4 *)(param_1 + 0x358);
  return;
}

