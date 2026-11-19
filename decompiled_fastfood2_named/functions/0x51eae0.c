// rea decompile_all
// name: FUN_0051eae0
// address: 0x51eae0
// body: available
// range: 0x51eae0-0x51eb4e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_0051eae0(undefined4 *param_1)

{
  int local_8;
  int local_4;
  
  CS_Enter(*(int *)(param_1[2] + 0x1c8));
  if ((param_1[6] != 0) && ((void *)param_1[1] != (void *)0x0)) {
    FUN_0053d090((void *)param_1[1],&local_4,&local_8);
    FUN_00526d30((void *)param_1[2],param_1[3],param_1[4],local_4 + param_1[3],local_8 + param_1[4])
    ;
  }
  param_1[5] = 0;
  *param_1 = 0;
  CS_Leave(*(int *)(param_1[2] + 0x1c8));
  return;
}

