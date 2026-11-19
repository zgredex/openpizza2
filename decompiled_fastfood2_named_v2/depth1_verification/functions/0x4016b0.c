// rea decompile_all
// name: IDMap_RemoveRecursive
// address: 0x4016b0
// body: available
// range: 0x4016b0-0x401787 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall IDMap_RemoveRecursive(void *this,int param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  
                    /* Recursively removes an ID-map entry above 99999. */
  if (99999 < param_1) {
    FUN_00401320(0x579af0);
    iVar2 = 0;
    if (0 < *(int *)((int)this + 0xc)) {
      piVar3 = *(int **)((int)this + 8);
      do {
        if (*piVar3 == param_1) {
          IDMap_RemoveRecursive(this,iVar2);
          FUN_00401340(0x579af0);
          return 1;
        }
        iVar2 = iVar2 + 1;
        piVar3 = piVar3 + 1;
      } while (iVar2 < *(int *)((int)this + 0xc));
    }
    FUN_00401340(0x579af0);
    return 0;
  }
  if ((param_1 < 0) || (*(int *)((int)this + 0x10) <= param_1)) {
    return 0;
  }
  FUN_00401320(0x579af0);
  *(int *)((int)this + 0x14) = *(int *)((int)this + 0x14) + -1;
  *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + -1;
  iVar2 = (*(int *)((int)this + 0x10) - param_1) + -1;
  if (0 < iVar2) {
    uVar1 = iVar2 * 4;
    FUN_0054e230((undefined4 *)(*(int *)((int)this + 8) + param_1 * 4),
                 (undefined4 *)(*(int *)((int)this + 8) + 4 + param_1 * 4),uVar1);
    FUN_0054e230((undefined4 *)(*(int *)((int)this + 4) + param_1 * 4),
                 (undefined4 *)(*(int *)((int)this + 4) + 4 + param_1 * 4),uVar1);
  }
  FUN_00401340(0x579af0);
  return 1;
}

