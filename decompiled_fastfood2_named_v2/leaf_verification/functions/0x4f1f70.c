// rea decompile_all
// name: Object_UpdateState
// address: 0x4f1f70
// body: available
// range: 0x4f1f70-0x4f2015 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Object_UpdateState(void *this,int param_1)

{
  int *piVar1;
  int iVar2;
  
                    /* Updates object state from param_1 and cached fields. */
  iVar2 = *(int *)(param_1 + 0x30);
  if (*(int *)(param_1 + 4) == -1) {
    if ((((iVar2 != -1) && (iVar2 = *(int *)((int)this + 0x4c) + iVar2 * 0xc, iVar2 != 0)) &&
        (iVar2 = *(int *)(iVar2 + 8), iVar2 != 0)) && (0 < *(int *)(iVar2 + 0x30))) {
      *(int *)(iVar2 + 0x30) = *(int *)(iVar2 + 0x30) + -1;
    }
    if (((*(int *)(param_1 + 0x34) != -1) &&
        (iVar2 = *(int *)((int)this + 0x4c) + *(int *)(param_1 + 0x34) * 0xc, iVar2 != 0)) &&
       ((iVar2 = *(int *)(iVar2 + 8), iVar2 != 0 && (0 < *(int *)(iVar2 + 0x30))))) {
      *(int *)(iVar2 + 0x30) = *(int *)(iVar2 + 0x30) + -1;
      *(undefined4 *)(param_1 + 0x30) = 0xffffffff;
      *(undefined4 *)(param_1 + 0x34) = 0xffffffff;
      return;
    }
  }
  else {
    if (iVar2 != -1) {
      piVar1 = (int *)(*(int *)(*(int *)((int)this + 0x4c) + 8 + iVar2 * 0xc) + 0x34);
      *piVar1 = *piVar1 + -1;
    }
    if (*(int *)(param_1 + 0x34) != -1) {
      piVar1 = (int *)(*(int *)(*(int *)((int)this + 0x4c) + 8 + *(int *)(param_1 + 0x34) * 0xc) +
                      0x34);
      *piVar1 = *piVar1 + -1;
    }
  }
  *(undefined4 *)(param_1 + 0x30) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x34) = 0xffffffff;
  return;
}

