// rea decompile_all
// name: UI_PrintSignedValue
// address: 0x4a6680
// body: available
// range: 0x4a6680-0x4a66c0 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl UI_PrintSignedValue(void *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
                    /* Prints a signed integer with black/red/green coloring. */
  if (param_3 < 1) {
    if (param_3 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0xff;
    }
  }
  else {
    uVar1 = 0xa000;
  }
  Window_GadgetNotify_Text_SetTextColor(param_1,param_2,uVar1);
  Gadget_SetTextf(param_1,param_2,&DAT_005686f4,param_3);
  return;
}

