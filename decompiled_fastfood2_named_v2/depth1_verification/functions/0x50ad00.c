// rea decompile_all
// name: FUN_0050ad00
// address: 0x50ad00
// body: available
// range: 0x50ad00-0x50ad62 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __fastcall FUN_0050ad00(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (((*(int *)(param_1 + 200) == 0) ||
      (iVar2 = Map_GetObjectNeighborCell
                         (*(void **)(param_1 + 0xc4),*(int *)(param_1 + 200),
                          *(int *)(param_1 + 0x88)), iVar2 == 0)) ||
     (iVar1 = *(int *)(iVar2 + 8), iVar1 == 0)) {
    iVar2 = 0;
  }
  else {
    switch(*(undefined4 *)(*(int *)(param_1 + 200) + 0xc)) {
    case 0x14:
      *(undefined1 *)(iVar1 + 0x2c) = 0;
      return iVar2;
    case 0x15:
      *(undefined1 *)(iVar1 + 0x2d) = 0;
      return iVar2;
    case 0x16:
      *(undefined1 *)(iVar1 + 0x2e) = 0;
      return iVar2;
    case 0x17:
      *(undefined1 *)(iVar1 + 0x2f) = 0;
      return iVar2;
    }
  }
  return iVar2;
}

