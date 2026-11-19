// rea decompile_all
// name: FUN_00485ae0
// address: 0x485ae0
// body: available
// range: 0x485ae0-0x485ba4 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00485ae0(void *this,void *param_1,int param_2)

{
  int iVar1;
  
  FUN_00401320(*(int *)((int)this + 0x240));
  if (*(undefined4 **)((int)this + 0x300) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)((int)this + 0x300))(1);
    *(undefined4 *)((int)this + 0x300) = 0;
  }
  if (param_2 == 1) {
    if (*(char *)(*(int *)((int)this + 0x9c) + 0x16f5) != '\0') {
      iVar1 = *(int *)(*(int *)((int)this + 0x9c) + 0x38);
      if (-1 < iVar1) {
        if (iVar1 < 2) {
          FUN_004858d0(this,s_BAUHINTERGRUND_MITTEL_tga_00567cdc);
          goto LAB_00485b69;
        }
        if (iVar1 == 2) {
          FUN_004858d0(this,s_BAUHINTERGRUND_GROSS_tga_00567cf8);
          goto LAB_00485b69;
        }
      }
      FUN_004858d0(this,(char *)0x1);
    }
  }
  else {
    Game_ReleaseConstructionSpriteLists(DAT_0057c5cc);
  }
LAB_00485b69:
  *(int *)((int)this + 0x33c) = param_2;
  *(void **)((int)this + 0x2fc) = param_1;
  FUN_004ed0a0(param_1);
  *(undefined4 *)(*(int *)((int)this + 0x2fc) + 0xf4) = 1;
  FUN_00401340(*(int *)((int)this + 0x240));
  FUN_0048b600(this);
  return;
}

