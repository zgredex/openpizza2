// rea decompile_all
// name: Array_SearchSet
// address: 0x4f5fa0
// body: available
// range: 0x4f5fa0-0x4f5fbe inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Array_SearchSet(void *this,int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 3;
  piVar2 = this;
  do {
    piVar2 = piVar2 + 1;
    if (*piVar2 == param_1) {
      piVar1 = (int *)((int)this + param_1 * 4 + 0x10);
      *piVar1 = *piVar1 + 1;
    }
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

