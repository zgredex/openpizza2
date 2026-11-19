// rea decompile_all
// name: UI_ShowAmountEntryDialog
// address: 0x4833b0
// body: available
// range: 0x4833b0-0x483527 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall
UI_ShowAmountEntryDialog
          (void *this,char param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7,int param_8)

{
  void *this_00;
  int iVar1;
  void *local_4;
  
                    /* Shows the amount-entry dialog with two fields. */
  if (*(int *)((int)this + 0x268) == 0) {
    local_4 = this;
    this_00 = RequestDialog_Create((int *)&local_4);
    *(void **)((int)this + 0x268) = this_00;
    FUN_0052f9b0(this_00,0x42f,param_3);
    FUN_0052f9b0(*(void **)((int)this + 0x268),0x431,param_4);
    if (param_1 == '\0') {
      FUN_0052fbc0(*(void **)((int)this + 0x268),0x437,param_5);
      FUN_0052fb00(*(void **)((int)this + 0x268),0x437,param_8);
      iVar1 = 0x436;
    }
    else {
      FUN_0052fbc0(*(void **)((int)this + 0x268),0x436,param_5);
      FUN_0052fb00(*(void **)((int)this + 0x268),0x436,param_8);
      iVar1 = 0x437;
    }
    FUN_00531740(*(void **)((int)this + 0x268),iVar1);
    if (param_8 == 0) {
      FUN_00531740(*(void **)((int)this + 0x268),0x42e);
    }
    *(undefined4 *)((int)this + 0x274) = param_2;
    *(undefined4 *)((int)this + 0x278) = param_6;
    *(undefined4 *)((int)this + 0x270) = param_7;
    *(undefined4 *)((int)this + 0x27c) = 0;
    *(undefined4 *)((int)this + 0x280) = 0;
    FUN_00523d60(DAT_0057c5e0,(int)local_4);
    FUN_00532a30(*(void **)((int)this + 0x268),0x434,0x1b);
    FUN_00532a30(*(void **)((int)this + 0x268),0x435,0xd);
    if (param_1 != '\0') {
      FUN_00524fd0(DAT_0057c5e0,*(void **)((int)this + 0x268),0x436);
      return;
    }
    FUN_00524fd0(DAT_0057c5e0,*(void **)((int)this + 0x268),0x437);
  }
  return;
}

