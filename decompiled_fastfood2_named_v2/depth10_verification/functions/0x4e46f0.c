// rea decompile_all
// name: FUN_004e46f0
// address: 0x4e46f0
// body: available
// range: 0x4e46f0-0x4e4757 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Ghidra Listing reports a terminal call at 0x4e4753 to 0x4e45e0 FUN_004e45e0 (external=false, thunk=false, hasNoReturn=false); fallthrough is excluded by Ghidra's flow model. The reason for the terminal flow is not established by this observation.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_004e46f0(int param_1)

{
  double dVar1;
  
  if (*(char *)(param_1 + 0x1c) == '\0') {
    if (*(double *)(param_1 + 0x10) <= 0.0) {
      if ((0.0 <= *(double *)(param_1 + 0x10)) ||
         (dVar1 = *(double *)(param_1 + 0x10) + 2.0, *(double *)(param_1 + 0x10) = dVar1,
         dVar1 <= 0.0)) goto LAB_004e4750;
    }
    else {
      dVar1 = *(double *)(param_1 + 0x10) - 4.0;
      *(double *)(param_1 + 0x10) = dVar1;
      if (0.0 <= dVar1) goto LAB_004e4750;
    }
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
LAB_004e4750:
  *(undefined1 *)(param_1 + 0x1c) = 0;
  FUN_004e45e0(param_1);
  return;
}

