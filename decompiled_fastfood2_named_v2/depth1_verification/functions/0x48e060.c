// rea decompile_all
// name: Game_HasIdleOtherPlayer
// address: 0x48e060
// body: available
// range: 0x48e060-0x48e097 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __fastcall Game_HasIdleOtherPlayer(void *param_1)

{
  int iVar1;
  uint3 uVar2;
  int iVar3;
  
                    /* Depth-1 proposal batch 3/4. */
  iVar3 = 0;
  while( true ) {
    iVar1 = FUN_00488be0(param_1,iVar3);
    uVar2 = (uint3)((uint)iVar1 >> 8);
    if (((iVar1 != *(int *)((int)param_1 + *(int *)((int)param_1 + 0x2ec) * 4 + 0x200)) &&
        (iVar1 != 0)) && (*(int *)(iVar1 + 0x50) == 0)) break;
    iVar3 = iVar3 + 1;
    if (5 < iVar3) {
      return (uint)uVar2 << 8;
    }
  }
  return CONCAT31(uVar2,1);
}

