// rea decompile_all
// name: FUN_0048e000
// address: 0x48e000
// body: available
// range: 0x48e000-0x48e05d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_0048e000(void *this,int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1[param_3] + param_2 * 4);
  if (iVar1 != 0) {
    iVar3 = 0;
    while( true ) {
      iVar2 = Game_GetPlayerBySlot(this,iVar3);
      if (((iVar2 != 0) && (*(int *)(iVar2 + 0x48) != param_3)) &&
         (iVar1 < *(int *)(*param_1 + param_2 * 4))) break;
      iVar3 = iVar3 + 1;
      param_1 = param_1 + 1;
      if (5 < iVar3) {
        return 1;
      }
    }
  }
  return 0;
}

