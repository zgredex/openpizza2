// rea decompile_all
// name: FUN_004cb900
// address: 0x4cb900
// body: available
// range: 0x4cb900-0x4cb94d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004cb900(void *param_1)

{
  undefined *puVar1;
  char local_40 [64];
  
  puVar1 = FUN_004cda50(&DAT_0057de38,DAT_0057bb40);
  String_Format(local_40,(byte *)s_maps__s_spr_0056b330,puVar1);
  FUN_00531910(param_1,0x4e4,local_40);
  FUN_00549e80(DAT_0057ba0c,DAT_0057bb40);
  return;
}

