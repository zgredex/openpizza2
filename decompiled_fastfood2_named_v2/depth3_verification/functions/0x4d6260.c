// rea decompile_all
// name: Building_ComputeOperatingRevenue
// address: 0x4d6260
// body: available
// range: 0x4d6260-0x4d6383 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


longlong __thiscall Building_ComputeOperatingRevenue(void *this,int param_1,int param_2)

{
  longlong lVar1;
  int local_114;
  int local_110;
  double local_10c;
  int local_104;
  undefined4 local_100 [64];
  
                    /* Depth-3 proposal batch 1. */
  FUN_004d5cf0(this,param_1,&local_104,&local_110,&local_114);
  local_10c = (double)local_110 * 0.25 + (double)local_104 * 0.1 + 1.0;
  if (local_114 != 0) {
    local_10c = local_10c * 1.75;
  }
  FUN_0048cdd0(DAT_0057c670,param_1,local_100);
  __ftol();
  if (param_2 != 0) {
    if (param_2 == 1) {
      lVar1 = __ftol();
      return lVar1;
    }
    if (param_2 == 2) {
      lVar1 = __ftol();
      return lVar1;
    }
  }
  lVar1 = __ftol();
  return lVar1;
}

