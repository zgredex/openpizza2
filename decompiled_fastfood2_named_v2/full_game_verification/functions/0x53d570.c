// rea decompile_all
// name: Sprite_Draw
// address: 0x53d570
// body: available
// range: 0x53d570-0x53d5fe inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Sprite_Draw(void *this,int param_1,uint *param_2,int param_3)

{
  uint *puVar1;
  
  if (*(char *)((int)this + 0x39) == '\0') {
    Sprite_RealizeLazy(this);
  }
  puVar1 = *(uint **)((int)this + 0x30);
  if (puVar1 == (uint *)0x0) {
    Sprite_BlitAlphaRLEAlt
              (this,param_1,*(uint **)((int)this + 0x2c),*(int *)((int)this + 0x28),param_2,param_3,
               (byte *)0xffffffff,-1);
    return;
  }
  if (*(char *)((int)this + 0x37) == '\0') {
    Sprite_BlitAlphaRLEAlt
              (this,param_1,puVar1,*(int *)((int)this + 0x28),param_2,param_3,(byte *)0xffffffff,-1)
    ;
    return;
  }
  Sprite_BlitAlphaRLEAlt
            (this,param_1,puVar1,*(int *)((int)this + 0x28),param_2,param_3,
             (byte *)(int)*(short *)((int)this + 8),(int)*(short *)((int)this + 6));
  return;
}

