// rea decompile_all
// name: Renderer_ConstructRoot
// address: 0x537c40
// body: available
// range: 0x537c40-0x537d53 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall
Renderer_ConstructRoot(void *this,undefined4 param_1,int param_2,int *param_3)

{
  undefined4 *puVar1;
  HWND hWnd;
  tagRECT *lpRect;
  tagRECT local_10;
  
                    /* Constructs the root Renderer, surface state, and desktop fallback dimensions.
                        */
  *(undefined ***)this = &PTR_FUN_0055c818;
  *(undefined1 *)((int)this + 0x30) = 0;
  *(undefined4 *)((int)this + 0x98) = 0;
  FUN_00539f20((int)this);
  puVar1 = operator_new(0x14);
  *(undefined4 **)((int)this + 0x40) = puVar1;
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  *(undefined4 *)((int)this + 0x80) = 1;
  *(undefined4 *)(*(int *)((int)this + 0x40) + 8) = 0;
  *(undefined1 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  **(undefined4 **)((int)this + 0x40) = 0;
  *(undefined4 *)(*(int *)((int)this + 0x40) + 4) = 0;
  *(undefined4 *)((int)this + 0x44) = param_1;
  *(undefined4 *)((int)this + 0x50) = 0;
  *(int *)((int)this + 0x4c) = param_2;
  *(undefined4 *)((int)this + 0x48) = 0;
  *(undefined4 *)((int)this + 0x54) = 0;
  *(undefined4 *)((int)this + 0x58) = 1;
  *(undefined4 *)((int)this + 0x5c) = 0;
  *(undefined4 *)((int)this + 0x60) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x78) = 0;
  *(undefined4 *)((int)this + 0x7c) = 0;
  *(undefined4 *)((int)this + 0x84) = 0;
  *(undefined4 *)((int)this + 0x88) = 0;
  *(undefined4 *)((int)this + 0x8c) = 0;
  *(undefined4 *)((int)this + 0x90) = 0;
  *(undefined4 *)((int)this + 0x94) = 0;
  if (param_2 != 2) {
    *param_3 = 0;
    FUN_00537e00(this,param_3,1);
    if (*param_3 != 0) {
      return this;
    }
    lpRect = &local_10;
    hWnd = GetDesktopWindow();
    GetWindowRect(hWnd,lpRect);
    *(short *)((int)this + 0x1c) = (short)(local_10.bottom - local_10.top);
    *(short *)((int)this + 0x1a) = (short)(local_10.right - local_10.left);
    SetRect((LPRECT)((int)this + 100),0,0,local_10.right - local_10.left & 0xffff,
            local_10.bottom - local_10.top & 0xffff);
    FUN_005396e0((int)this);
  }
  *(undefined1 *)((int)this + 0x30) = 1;
  return this;
}

