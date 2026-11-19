// rea decompile_all
// name: Game_LoadBackgroundImage
// address: 0x4858d0
// body: available
// range: 0x4858d0-0x4859b6 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Game_LoadBackgroundImage(void *this,char *param_1)

{
  void *this_00;
  undefined4 *puVar1;
  int iVar2;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
                    /* Loads or clears the fullscreen background image and re-clips the UI. */
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0055821b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvStack_10 = this;
  FUN_00401320(*(int *)((int)this + 0x240));
  if (*(undefined4 **)((int)this + 0x300) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)((int)this + 0x300))(1);
    *(undefined4 *)((int)this + 0x300) = 0;
  }
  if (param_1 != (char *)0x0) {
    this_00 = operator_new(0x11c);
    uStack_4 = 0;
    if (this_00 == (void *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = FUN_00535fc0(this_00,param_1,DAT_0057c5c8,DAT_0057c5d8,&pvStack_10,(undefined *)0x0);
    }
    uStack_4 = 0xffffffff;
    *(undefined4 **)((int)this + 0x300) = puVar1;
    if (pvStack_10 != (void *)0x0) {
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(1);
      }
      *(undefined4 *)((int)this + 0x300) = 0;
    }
  }
  iVar2 = Window_GetGadgetChecked(DAT_0057c674,0x2a);
  if (iVar2 != 0) {
    FUN_00521b30(iVar2);
  }
  FUN_00401340(*(int *)((int)this + 0x240));
  ExceptionList = pvStack_c;
  return;
}

