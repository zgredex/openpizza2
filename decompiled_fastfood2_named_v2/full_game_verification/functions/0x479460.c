// rea decompile_all
// name: Map_CheckTileEdgeMatch
// address: 0x479460
// body: available
// range: 0x479460-0x47952b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall
Map_CheckTileEdgeMatch(void *this,int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = Grid_GetCell(*(void **)((int)this + 0x14e0),*(int *)(param_3 + 0x18),
                       *(int *)(param_3 + 0x1c));
  iVar2 = City_IndexOfListValue
                    (DAT_0057c670,*(int *)(*(int *)(iVar2 + 8) + 0x10),*(int *)(param_3 + 4),
                     *(int *)(param_3 + 8));
  if (iVar2 != -1) {
    iVar1 = param_4 + (param_1 * 0x50 + param_2) * 8;
    if (((*(short *)(iVar1 + 0x14) == 2) && (*(short *)(iVar1 + 0x294) == 2)) && (iVar2 == 1)) {
      return 1;
    }
    if (((*(short *)(iVar1 + -4) == 2) && (*(short *)(iVar1 + 0x27c) == 2)) && (iVar2 == 3)) {
      return 1;
    }
    if (((*(short *)(iVar1 + 0x504) == 2) && (*(short *)(iVar1 + 0x50c) == 2)) && (iVar2 == 0)) {
      return 1;
    }
    if (((*(short *)(iVar1 + -0x27c) == 2) && (*(short *)(iVar1 + -0x274) == 2)) && (iVar2 == 2)) {
      return 1;
    }
  }
  return 0;
}

