// rea decompile_all
// name: Palette_Convert256
// address: 0x535e50
// body: available
// range: 0x535e50-0x535efe inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Palette_Convert256(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  ushort *puVar4;
  
  if (*(int *)this != 0) {
    iVar3 = 0x100;
    *(bool *)((int)this + 0x208) = param_1 == 1;
    iVar2 = 0;
    puVar4 = (ushort *)((int)this + 4);
    if (param_1 != 0) {
      do {
        iVar1 = *(int *)this;
        iVar2 = iVar2 + 3;
        iVar3 = iVar3 + -1;
        *puVar4 = ((ushort)(*(byte *)(iVar1 + -1 + iVar2) & 0xf8) << 5 |
                  (ushort)(*(byte *)(iVar1 + -2 + iVar2) & 0xf8)) << 3 |
                  (ushort)(*(byte *)(iVar1 + -3 + iVar2) >> 3);
        puVar4 = puVar4 + 1;
      } while (iVar3 != 0);
      return;
    }
    do {
      iVar1 = *(int *)this;
      iVar2 = iVar2 + 3;
      iVar3 = iVar3 + -1;
      *puVar4 = ((ushort)(*(byte *)(iVar1 + -1 + iVar2) & 0xf8) << 5 |
                (ushort)(*(byte *)(iVar1 + -2 + iVar2) & 0xf8)) << 2 |
                (ushort)(*(byte *)(iVar1 + -3 + iVar2) >> 3);
      puVar4 = puVar4 + 1;
    } while (iVar3 != 0);
  }
  return;
}

