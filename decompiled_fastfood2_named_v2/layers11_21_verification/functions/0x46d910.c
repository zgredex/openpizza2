// rea decompile_all
// name: FUN_0046d910
// address: 0x46d910
// body: available
// range: 0x46d910-0x46dbc9 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl FUN_0046d910(int *param_1)

{
  int iVar1;
  void *this;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0x256,0,s_STADTUEBERL01_spr_0056714c,&LAB_004c6e10);
  *param_1 = iVar1;
  this = (void *)FUN_00528040(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  iVar1 = FUN_0052fc00(this,1000,0xb8,0x41,0x4b,s_SL01_00_spr_0056448c,0,1);
  if (iVar1 != 0) {
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,1000,&local_10);
  }
  iVar1 = FUN_0052f850(this,0x3e9,0x17,3,s_TIMESFONT_fnt_00563ea8,DAT_00581680);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x3e9,0);
    Window_GadgetNotify_Text_SetLayout(this,0x3e9,2,0xa0,0,0);
  }
  iVar1 = FUN_0052f850(this,0x3ea,0x13,0x22,s_VERDANA8_fnt_00563e98,DAT_00582038);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x3ea,0);
    Window_GadgetNotify_Text_SetLayout(this,0x3ea,2,0xa0,0,0);
  }
  FUN_0052f5b0(this,0x3eb,0x27,0x33,s_TABPB02__00_spr_0056713c,1,0);
  FUN_0052f5b0(this,0x3ec,0x27,0x48,s_TABPB02__00_spr_0056713c,1,0);
  FUN_0052f5b0(this,0x3ed,0x27,0x72,s_TABPB02__00_spr_0056713c,1,0);
  FUN_0052f5b0(this,0x3ee,0x27,0x5d,s_TABPB02__00_spr_0056713c,1,0);
  FUN_0052f5b0(this,0x3ef,0x27,0x87,s_TABPB02__00_spr_0056713c,1,0);
  iVar1 = FUN_0052f850(this,0x3f0,0x2c,0x36,s_VERDANA8_fnt_00563e98,s__Blablablabla_0056712c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x3f0,0);
    Window_GadgetNotify_Text_SetLayout(this,0x3f0,0,0x78,0,0);
  }
  iVar1 = FUN_0052f850(this,0x3f1,0x2c,0x4b,s_VERDANA8_fnt_00563e98,s__Blablablabla_0056712c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x3f1,0);
    Window_GadgetNotify_Text_SetLayout(this,0x3f1,0,0x78,0,0);
  }
  iVar1 = FUN_0052f850(this,0x3f2,0x2c,0x60,s_VERDANA8_fnt_00563e98,s__Blablablabla_0056712c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x3f2,0);
    Window_GadgetNotify_Text_SetLayout(this,0x3f2,0,0x78,0,0);
  }
  iVar1 = FUN_0052f850(this,0x3f3,0x2c,0x75,s_VERDANA8_fnt_00563e98,s__Blablablabla_0056712c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x3f3,0);
    Window_GadgetNotify_Text_SetLayout(this,0x3f3,0,0x78,0,0);
  }
  iVar1 = FUN_0052f850(this,0x3f4,0x2c,0x8a,s_VERDANA8_fnt_00563e98,s__Blablablabla_0056712c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x3f4,0);
    Window_GadgetNotify_Text_SetLayout(this,0x3f4,0,0x78,0,0);
  }
  return this;
}

