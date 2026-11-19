// rea decompile_all
// name: FUN_004067d0
// address: 0x4067d0
// body: available
// range: 0x4067d0-0x406904 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_004067d0(undefined4 param_1)

{
  void *this;
  undefined4 *puVar1;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00557d1b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if (DAT_0057c5e0 != (undefined4 *)0x0) {
    ExceptionList = &pvStack_c;
    (**(code **)*DAT_0057c5e0)(1,param_1);
  }
  this = operator_new(0x83e8);
  uStack_4 = 0;
  if (this == (void *)0x0) {
    DAT_0057c5e0 = (undefined4 *)0x0;
  }
  else {
    DAT_0057c5e0 = FUN_00523100(this,DAT_0057c5c8,DAT_0057c5d0,DAT_0057c5d8,800,600,0);
  }
  uStack_4 = 0xffffffff;
  FUN_00527940(DAT_0057c5e0,Screenshot_SaveTGA);
  FUN_005281f0(DAT_0057c5e0,&LAB_00405640);
  FUN_00523800(DAT_0057c5e0,s_rklick_00563c44);
  FUN_005237e0(DAT_0057c5e0,0xc0c0c0,0xffff00);
  puVar1 = (undefined4 *)FUN_00526590((int)DAT_0057c5e0);
  FUN_005272a0(DAT_0057c5e0,&DAT_00563c40);
  FUN_005272d0(DAT_0057c5e0,0,0x20);
  *puVar1 = s_default_font_00563b80;
  puVar1[4] = 0xffffff;
  puVar1[5] = 0x800000;
  puVar1[6] = 0x80;
  puVar1[1] = 0x808080;
  puVar1[2] = 0xffffff;
  puVar1[3] = 0xff0000;
  puVar1[9] = s_Abbruch_00563c38;
  puVar1[10] = &DAT_00563c34;
  ExceptionList = pvStack_c;
  return;
}

