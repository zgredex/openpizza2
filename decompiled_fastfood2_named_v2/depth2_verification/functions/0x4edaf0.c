// rea decompile_all
// name: Map_RecordPointToGridCell
// address: 0x4edaf0
// body: available
// range: 0x4edaf0-0x4edb6a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall Map_RecordPointToGridCell(void *this,int param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  
                    /* Depth-2 proposal batch 2/4. */
  iVar2 = FUN_004ed5a0(this,*(int *)(param_1 + 8),*(int *)(param_1 + 4),(int *)0x1,0);
  if (iVar2 == 0) {
    iVar2 = FUN_004ed5a0(this,*(int *)(param_1 + 8) - *(int *)((int)this + 0xdc),
                         *(int *)((int)this + 0xe0) + *(int *)(param_1 + 4),(int *)0x1,0);
    if (iVar2 == 0) {
      FUN_0048e0a0();
    }
  }
  *param_3 = **(int **)(iVar2 + 8) / *(int *)((int)this + 0x1c);
  iVar2 = **(int **)(iVar2 + 8);
  iVar1 = *(int *)((int)this + 0x1c);
  *param_2 = iVar2 % iVar1;
  return iVar2 / iVar1;
}

