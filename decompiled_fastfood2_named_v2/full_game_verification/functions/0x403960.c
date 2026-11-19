// rea decompile_all
// name: File_ReadHeaderDwords
// address: 0x403960
// body: available
// range: 0x403960-0x4039b6 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __cdecl File_ReadHeaderDwords(LPCSTR param_1,undefined4 *param_2,undefined4 *param_3)

{
  FILE *pFVar1;
  char local_40 [28];
  undefined4 local_24;
  undefined4 local_20;
  
  pFVar1 = (FILE *)CRT_Fopen(param_1,&DAT_00563184);
  if (pFVar1 == (FILE *)0x0) {
    return 0;
  }
  CRT_FreadLocked(local_40,1,0x40,(int *)pFVar1);
  CRT_Fclose(pFVar1);
  *param_2 = local_24;
  *param_3 = local_20;
  return 1;
}

