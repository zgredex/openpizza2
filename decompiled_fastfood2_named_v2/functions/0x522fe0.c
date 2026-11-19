// rea decompile_all
// name: FUN_00522fe0
// address: 0x522fe0
// body: available
// range: 0x522fe0-0x523045 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_00522fe0(void *this,int param_1)

{
  int iVar1;
  
  if ((param_1 < 0) || (*(int *)((int)this + 0xc) <= param_1)) {
    return 0;
  }
  CS_Enter(0x584180);
  *(int *)((int)this + 8) = *(int *)((int)this + 8) + -1;
  *(int *)((int)this + 0x10) = *(int *)((int)this + 0x10) + -1;
  iVar1 = (*(int *)((int)this + 0xc) - param_1) + -1;
  if (0 < iVar1) {
    FUN_0054e230((undefined4 *)(*(int *)((int)this + 4) + param_1 * 4),
                 (undefined4 *)(*(int *)((int)this + 4) + 4 + param_1 * 4),iVar1 * 4);
  }
  CS_Leave(0x584180);
  return 1;
}

