// rea decompile_all
// name: UI_LayoutChildElements
// address: 0x529160
// body: available
// range: 0x529160-0x529275 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall UI_LayoutChildElements(int param_1)

{
  int iVar1;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  *(int *)(param_1 + 100) = *(int *)(param_1 + 0x4f0) + *(int *)(param_1 + 0x38);
  *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x4f4) + *(int *)(param_1 + 0x3c);
  Sprite_GetSize(*(void **)(param_1 + 0x1ec),&local_4,&local_8);
  Sprite_GetSize(*(void **)(param_1 + 0x230),&local_c,&local_10);
  iVar1 = *(int *)(param_1 + 100);
  if (*(int *)(param_1 + 0xc0) == 0) {
    *(int *)(param_1 + 0x74) = local_4 + iVar1;
    *(int *)(param_1 + 0x78) = *(int *)(param_1 + 0x68);
    *(int *)(param_1 + 0x6c) = *(int *)(param_1 + 0xb4) + iVar1;
    *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x68) + local_10;
    Sprite_GetSize(*(void **)(param_1 + 0x274),&local_c,&local_10);
    *(int *)(param_1 + 0x7c) = (*(int *)(param_1 + 0xb4) - local_c) + *(int *)(param_1 + 100);
    *(undefined4 *)(param_1 + 0x80) = *(undefined4 *)(param_1 + 0x68);
    return;
  }
  *(int *)(param_1 + 0x74) = iVar1;
  *(int *)(param_1 + 0x78) = local_8 + *(int *)(param_1 + 0x68);
  *(int *)(param_1 + 0x6c) = iVar1 + local_c;
  *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0xb4) + *(int *)(param_1 + 0x68);
  Sprite_GetSize(*(void **)(param_1 + 0x274),&local_c,&local_10);
  *(undefined4 *)(param_1 + 0x7c) = *(undefined4 *)(param_1 + 100);
  *(int *)(param_1 + 0x80) = (*(int *)(param_1 + 0xb4) - local_10) + *(int *)(param_1 + 0x68);
  return;
}

