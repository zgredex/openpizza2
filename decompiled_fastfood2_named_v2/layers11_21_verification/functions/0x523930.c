// rea decompile_all
// name: UI_AllocWindowSlot
// address: 0x523930
// body: available
// range: 0x523930-0x5239cb inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall UI_AllocWindowSlot(void *this,undefined4 *param_1)

{
  int *piVar1;
  undefined4 unaff_EDI;
  int iVar2;
  
                    /* Reserves a free slot in the UI manager's window array. */
  *(undefined4 *)((int)this + 0x83b8) = 1;
  FUN_00401320(*(int *)((int)this + 0x1c8));
  iVar2 = 0;
  *param_1 = *(undefined4 *)((int)this + 0x83e0);
  *(int *)((int)this + 0x83e0) = *(int *)((int)this + 0x83e0) + 1;
  if (0 < *(int *)((int)this + 0x23c)) {
    piVar1 = (int *)((int)this + 0x14);
    do {
      if (*piVar1 == 0) {
        FUN_00401340(*(int *)((int)this + 0x1c8));
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 1;
    } while (iVar2 < *(int *)((int)this + 0x23c));
  }
  FUN_00401340(*(int *)((int)this + 0x1c8));
  if (iVar2 == 100) {
    FUN_00526f20(this,3,(byte *)s_To_many_windows_created__Please_d_005740b0,unaff_EDI);
    return -1;
  }
  *(int *)((int)this + 0x23c) = *(int *)((int)this + 0x23c) + 1;
  return iVar2;
}

