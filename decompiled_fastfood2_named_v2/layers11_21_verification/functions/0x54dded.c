// rea decompile_all
// name: CRT_InitFloatCvtTable
// address: 0x54dded
// body: available
// range: 0x54dded-0x54de24 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void CRT_InitFloatCvtTable(void)

{
                    /* Installs the CRT floating-point conversion function table. */
  PTR_FUN_00576a1c = &LAB_00551a42;
  PTR_FUN_00576a18 = __cfltcvt;
  PTR_FUN_00576a20 = __fassign;
  PTR_FUN_00576a24 = CRT_ForceDecimalPoint;
  PTR_FUN_00576a28 = &LAB_00551a90;
  PTR_FUN_00576a2c = __cfltcvt;
  return;
}

