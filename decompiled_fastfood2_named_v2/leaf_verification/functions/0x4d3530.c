// rea decompile_all
// name: Record_GetFlag3E48
// address: 0x4d3530
// body: available
// range: 0x4d3530-0x4d3556 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined1 __fastcall Record_GetFlag3E48(int param_1)

{
  int *piVar1;
  int iVar2;
  
                    /* Leaf reversal proposal batch 2. */
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 != (int *)0x0) {
    iVar2 = *piVar1;
    if ((-1 < iVar2) && (iVar2 < *(int *)(piVar1[0x16] + 0x48))) {
      return *(undefined1 *)(*(int *)(piVar1[0x16] + 0x4c) + 0x3e + iVar2 * 0x48);
    }
  }
  return 0;
}

