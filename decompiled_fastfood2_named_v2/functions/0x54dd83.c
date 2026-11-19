// rea decompile_all
// name: String_Format
// address: 0x54dd83
// body: available
// range: 0x54dd83-0x54ddd4 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __cdecl String_Format(undefined1 *param_1,byte *param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 *local_24;
  int local_20;
  undefined1 *local_1c;
  undefined4 local_18;
  
                    /* Formats a string into a caller buffer via CRT; 172 call sites. */
  local_1c = param_1;
  local_24 = param_1;
  local_18 = 0x42;
  local_20 = 0x7fffffff;
  iVar1 = FUN_00551165((int *)&local_24,param_2,&param_3);
  local_20 = local_20 + -1;
  if (local_20 < 0) {
    FUN_0055104d(0,(int *)&local_24);
  }
  else {
    *local_24 = 0;
  }
  return iVar1;
}

