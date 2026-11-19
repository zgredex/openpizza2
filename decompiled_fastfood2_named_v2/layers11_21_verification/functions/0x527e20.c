// rea decompile_all
// name: Window_SetCursorPosition
// address: 0x527e20
// body: available
// range: 0x527e20-0x527ed5 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Window_SetCursorPosition(void *this,int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  tagPOINT local_8;
  
                    /* Moves the OS cursor and optionally dispatches a mouse-move. */
  local_8.x = param_1;
  *(int *)((int)this + 0x248) = param_1;
  local_8.y = param_2;
  *(int *)((int)this + 0x24c) = param_2;
  ClientToScreen(*(HWND *)((int)this + 0x8320),&local_8);
  SetCursorPos(local_8.x,local_8.y);
  if ((param_3 != 0) &&
     (uVar1 = *(uint *)((int)this + 0x32b4), uVar1 != *(uint *)((int)this + 0x32b8))) {
    do {
      if (*(int *)((int)this + uVar1 * 0xc + 0x2b4) == 0x200) {
        *(undefined4 *)((int)this + uVar1 * 0xc + 0x2b4) = 0;
      }
      uVar1 = uVar1 + 1 & 0x3ff;
    } while (uVar1 != *(uint *)((int)this + 0x32b8));
  }
  if (param_4 != 0) {
    Window_DispatchMouseEvent(this,0x200,*(int *)((int)this + 0x248),*(int *)((int)this + 0x24c),0);
  }
  return;
}

