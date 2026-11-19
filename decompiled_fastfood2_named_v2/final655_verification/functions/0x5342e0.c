// rea decompile_all
// name: FUN_005342e0
// address: 0x5342e0
// body: available
// range: 0x5342e0-0x53431f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_005342e0(void *this,int param_1,int param_2,int param_3)

{
  int *piVar1;
  
  if ((-1 < param_1) && (param_1 < *(int *)((int)this + 0x48))) {
    piVar1 = (int *)(*(int *)((int)this + 0x4c) + param_1 * 0x48);
    if (*piVar1 != -1) {
      *(double *)(piVar1 + 2) = (double)param_2;
      *(double *)(*(int *)((int)this + 0x4c) + 0x10 + param_1 * 0x48) = (double)param_3;
      return 1;
    }
  }
  return 0;
}

