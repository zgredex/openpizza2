// rea decompile_all
// name: UI_RemoveWindowByID
// address: 0x527f80
// body: available
// range: 0x527f80-0x52803f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall UI_RemoveWindowByID(void *this,int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  void *local_4;
  
  local_4 = this;
  CS_Enter(*(int *)((int)this + 0x1c8));
  iVar3 = UI_FindWindowByID(this,param_1,(int *)&local_4);
  if (iVar3 != 0) {
    if (local_4 != (void *)(*(int *)((int)this + 0x23c) + -1)) {
      puVar1 = (undefined4 *)((int)this + (int)local_4 * 4 + 0x14);
      uVar2 = *puVar1;
      _memmove(puVar1,(undefined4 *)((int)this + (int)local_4 * 4 + 0x18),
               (((int)local_4 + 1) * 0x3fffffff + *(int *)((int)this + 0x23c)) * 4);
      *(undefined4 *)((int)this + *(int *)((int)this + 0x23c) * 4 + 0x10) = uVar2;
      iVar3 = 0;
      if (0 < *(int *)((int)this + 0x23c)) {
        piVar4 = (int *)((int)this + 0x14);
        do {
          if (*piVar4 != 0) {
            Sound_StopBuffer(*piVar4);
          }
          iVar3 = iVar3 + 1;
          piVar4 = piVar4 + 1;
        } while (iVar3 < *(int *)((int)this + 0x23c));
      }
      *(undefined4 *)((int)this + 0x83b8) = 1;
      CS_Leave(*(int *)((int)this + 0x1c8));
      return;
    }
  }
  CS_Leave(*(int *)((int)this + 0x1c8));
  return;
}

