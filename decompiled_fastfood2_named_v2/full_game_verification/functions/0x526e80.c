// rea decompile_all
// name: UI_SetBackgroundSurfaceEnabled
// address: 0x526e80
// body: available
// range: 0x526e80-0x526f15 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall UI_SetBackgroundSurfaceEnabled(void *this,int param_1)

{
  DWORD DVar1;
  int iVar2;
  undefined4 uVar3;
  
  DVar1 = WaitForSingleObject(DAT_0057c0d8,0);
  if (DVar1 != 0) {
    CS_Enter(*(int *)((int)this + 0x1c8));
    *(int *)((int)this + 0x284) = param_1;
    if (param_1 != 0) {
      if ((*(int *)(DAT_0057c5c8 + 0x98) == 0) && (*(int *)((int)this + 0x8358) == 0)) {
        iVar2 = Object_GetRootType(DAT_0057c5c8);
        if (iVar2 == 2) {
          if (*(int *)(DAT_0057c5c8 + 0x40) == 0) {
            uVar3 = 0;
          }
          else {
            uVar3 = *(undefined4 *)(*(int *)(DAT_0057c5c8 + 0x40) + 8);
          }
          *(undefined4 *)((int)this + 0x1c0) = uVar3;
        }
        Sprite_ClearBuffers(*(int **)((int)this + 0x1c0));
      }
      UI_MarkFullRectDirty(this);
    }
    CS_Leave(*(int *)((int)this + 0x1c8));
  }
  return;
}

