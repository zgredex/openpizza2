// rea decompile_all
// name: FUN_0048d3a0
// address: 0x48d3a0
// body: available
// range: 0x48d3a0-0x48d3f2 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_0048d3a0(void)

{
  switch(DAT_0057bb24) {
  case 0:
    return 1000000;
  case 1:
    return 500000;
  case 2:
    return 200000;
  case 3:
    return 100000;
  case 4:
    return 75000;
  case 5:
    return 50000;
  case 6:
    return 40000;
  case 7:
    return 30000;
  case 8:
    return 25000;
  case 9:
    return 22000;
  default:
    return 20000;
  }
}

