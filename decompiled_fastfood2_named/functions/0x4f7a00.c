// rea decompile_all
// name: FUN_004f7a00
// address: 0x4f7a00
// body: available
// range: 0x4f7a00-0x4f7a46 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_004f7a00(int param_1,undefined4 *param_2)

{
  void *this;
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = param_2;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  this = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(param_1 + 0x34),(int *)0x0);
  if ((this != (void *)0x0) && (*(int *)(param_1 + 0x16f0) != 0)) {
    FUN_004d7d60(this,*(int *)(param_1 + 0x16f0),param_2);
  }
  return;
}

