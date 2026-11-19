// rea decompile_all
// name: Sprite_ConvertRGB555to565
// address: 0x53d4b0
// body: available
// range: 0x53d4b0-0x53d56c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Sprite_ConvertRGB555to565(void *this,void *param_1)

{
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  
                    /* Converts raw 16bpp pixels from RGB555 to RGB565; skipped for alpha/RLE
                       sprites. */
  if ((*(char *)((int)this + 5) == '\x0f') || (*(char *)((int)this + 5) == '\x10')) {
    puVar2 = *(ushort **)((int)this + 0x2c);
    if ((*(byte *)((int)this + 4) & 1) == 0) {
      FUN_00539340(param_1,puVar2,*(int *)((int)this + 0x18) >> 1);
      if (*(char *)((int)param_1 + 0x18) == '\0') {
        return;
      }
    }
    else {
      if (*(char *)((int)param_1 + 0x18) != '\x01') {
        return;
      }
      if ((*(byte *)((int)this + 4) & 0x10) != 0) {
        return;
      }
      iVar3 = 0;
      if (0 < (int)(*(uint *)((int)this + 0x18) & 0xfffffffe)) {
        do {
          uVar1 = *puVar2;
          if ((uint)uVar1 == *(uint *)((int)this + 0x1c)) {
            iVar3 = iVar3 + 1;
            *puVar2 = (uVar1 & 0xffe0) << 1 | uVar1 & 0x1f;
            puVar2 = puVar2 + 1;
          }
          else {
            *puVar2 = (uVar1 & 0xffe0) << 1 | uVar1 & 0x1f;
          }
          iVar3 = iVar3 + 1;
          puVar2 = puVar2 + 1;
        } while (iVar3 < *(int *)((int)this + 0x18) >> 1);
      }
    }
    *(uint *)((int)this + 0x1c) =
         (*(uint *)((int)this + 0x1c) & 0x7fe0) << 1 | *(uint *)((int)this + 0x1c) & 0x1f;
  }
  return;
}

