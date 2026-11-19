// rea decompile_all
// name: Renderer_DrawPendingSprite
// address: 0x51eb50
// body: available
// range: 0x51eb50-0x51ebee inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall Renderer_DrawPendingSprite(void *this,int param_1,LPRECT param_2)

{
  int xLeft;
  int local_8;
  int local_4;
  
  if (*(void **)((int)this + 4) == (void *)0x0) {
    return 0;
  }
  if (*(int *)((int)this + 0x18) != 0) {
    Sprite_GetSize(*(void **)((int)this + 4),&local_4,&local_8);
    xLeft = *(int *)((int)this + 0xc);
    if (xLeft == -9999) {
      return 0;
    }
    SetRect(param_2,xLeft,*(int *)((int)this + 0x10),local_4 + xLeft,
            local_8 + *(int *)((int)this + 0x10));
    Sprite_Draw(*(void **)((int)this + 4),param_1,*(uint **)((int)this + 0xc),
                *(int *)((int)this + 0x10));
    *(undefined4 *)((int)this + 0x18) = 0;
  }
  if ((*(int *)this == 0) && (*(undefined4 **)((int)this + 4) != (undefined4 *)0x0)) {
    (**(code **)**(undefined4 **)((int)this + 4))(1);
    *(undefined4 *)((int)this + 4) = 0;
  }
  return 1;
}

