// rea decompile_all
// name: FUN_0042caa0
// address: 0x42caa0
// body: available
// range: 0x42caa0-0x42d551 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl FUN_0042caa0(int *param_1)

{
  int iVar1;
  void *this;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004a6f50);
  *param_1 = iVar1;
  this = (void *)FUN_00528040(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  FUN_00531850(this,0x429,0x27,0x14c,s_TRENNZEILE_spr_00563eb8);
  FUN_00531850(this,0x436,0x2b,0x34,s_RAHMEN04_spr_005654a0);
  FUN_00531850(this,0x437,0x95,0x15a,s_ZUTATICONS_00_spr_0056548c);
  FUN_00531850(this,0x438,0x35,0x15b,s_ZUTATICONS_01_spr_00565478);
  FUN_00531850(this,0x439,0x56,0x15b,s_ZUTATICONS_02_spr_00565464);
  FUN_00531850(this,0x43a,0x76,0x15b,s_ZUTATICONS_03_spr_00565450);
  FUN_00531850(this,0x43b,0xb4,0x15a,s_ZUTATICONS_04_spr_0056543c);
  FUN_00531850(this,0x43c,0xcf,0x15a,s_ZUTATICONS_05_spr_00565428);
  FUN_00531850(this,0x43d,0x95,0x15a,s_ZUTATICONS_06_spr_00565414);
  FUN_00531850(this,0x43e,0x35,0x15b,s_ZUTATICONS_07_spr_00565400);
  FUN_00531850(this,0x43f,0x56,0x15b,s_ZUTATICONS_08_spr_005653ec);
  FUN_00531850(this,0x440,0x76,0x15b,s_ZUTATICONS_09_spr_005653d8);
  FUN_00531850(this,0x441,0xb5,0x15a,s_ZUTATICONS_10_spr_005653c4);
  FUN_00531850(this,0x442,0xcf,0x15b,s_ZUTATICONS_11_spr_005653b0);
  FUN_00531850(this,0x443,0x95,0x15a,s_ZUTATICONS_12_spr_0056539c);
  FUN_00531850(this,0x444,0x35,0x15b,s_ZUTATICONS_13_spr_00565388);
  FUN_00531850(this,0x445,0x56,0x15b,s_ZUTATICONS_14_spr_00565374);
  FUN_00531850(this,0x446,0x76,0x15b,s_ZUTATICONS_15_spr_00565360);
  FUN_00531850(this,0x447,0xb5,0x15a,s_ZUTATICONS_16_spr_0056534c);
  FUN_00531850(this,0x448,0xcf,0x15b,s_ZUTATICONS_17_spr_00565338);
  iVar1 = FUN_0052fc00(this,0x42f,0x33,0x142,0x50,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xaa00;
    local_c = 0xffff;
    local_8 = 0xff;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x42f,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x431,0x33,0x127,0x50,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xaa00;
    local_c = 0xffff;
    local_8 = 0xff;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x431,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x432,0x33,0x10b,0x50,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xaa00;
    local_c = 0xffff;
    local_8 = 0xff;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x432,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x433,0x97,0x142,0x50,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xaa00;
    local_c = 0xffff;
    local_8 = 0xff;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x433,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x434,0x97,0x127,0x50,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xaa00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x434,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x435,0x97,0x10b,0x50,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xaa00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x435,&local_10);
  }
  iVar1 = FUN_0052f850(this,0x449,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_005826d4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x449,0);
    Window_GadgetNotify_Text_SetLayout(this,0x449,2,0xbe,0,0);
  }
  iVar1 = FUN_0052f850(this,0x44a,0x4e,0x33,s_VEDANA11_fnt_00564090,&DAT_00565334);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x44a,0);
    Window_GadgetNotify_Text_SetLayout(this,0x44a,0,0,0,0);
  }
  iVar1 = FUN_0052f850(this,1099,0x6c,0x33,s_VERDANA10_fnt_00563e64,DAT_005827e0);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,1099,0);
    Window_GadgetNotify_Text_SetLayout(this,1099,0,0x7d,0,0);
  }
  iVar1 = FUN_0052f850(this,0x44c,0x2f,0xf7,s_VERDANA8_fnt_00563e98,DAT_0058292c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x44c,0);
    Window_GadgetNotify_Text_SetLayout(this,0x44c,2,0x50,0,0);
  }
  iVar1 = FUN_0052f850(this,0x44d,0x92,0xf7,s_VERDANA8_fnt_00563e98,DAT_00580bbc);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x44d,0);
    Window_GadgetNotify_Text_SetLayout(this,0x44d,2,0x50,0,0);
  }
  iVar1 = FUN_0052f850(this,0x44e,0x93,0x113,s_VERDANA8_fnt_00563e98,DAT_00581088);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x44e,0);
    Window_GadgetNotify_Text_SetLayout(this,0x44e,2,0x50,0,0);
  }
  iVar1 = FUN_0052f850(this,0x44f,0x2f,0x113,s_VERDANA8_fnt_00563e98,DAT_00582e00);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x44f,0);
    Window_GadgetNotify_Text_SetLayout(this,0x44f,2,0x50,0,0);
  }
  iVar1 = FUN_0052f850(this,0x450,0x93,0x12e,s_VERDANA8_fnt_00563e98,DAT_00582588);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x450,0);
    Window_GadgetNotify_Text_SetLayout(this,0x450,2,0x50,0,0);
  }
  iVar1 = FUN_0052f850(this,0x451,0x2f,0x12e,s_VERDANA8_fnt_00563e98,DAT_00582a18);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x451,0);
    Window_GadgetNotify_Text_SetLayout(this,0x451,2,0x50,0,0);
  }
  iVar1 = FUN_0052f850(this,0x452,0x48,0x48,s_VERDANA10_fnt_00563e64,&DAT_00565330);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x452,0);
    Window_GadgetNotify_Text_SetLayout(this,0x452,1,0x1e,0,0);
  }
  iVar1 = FUN_0052f850(this,0x453,0x48,0x5e,s_VERDANA10_fnt_00563e64,&DAT_00565330);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x453,0);
    Window_GadgetNotify_Text_SetLayout(this,0x453,1,0x1e,0,0);
  }
  iVar1 = FUN_0052f850(this,0x454,0x48,0x74,s_VERDANA10_fnt_00563e64,&DAT_00565330);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x454,0);
    Window_GadgetNotify_Text_SetLayout(this,0x454,1,0x1e,0,0);
  }
  iVar1 = FUN_0052f850(this,0x455,0x48,0x8a,s_VERDANA10_fnt_00563e64,&DAT_00565330);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x455,0);
    Window_GadgetNotify_Text_SetLayout(this,0x455,1,0x1e,0,0);
  }
  iVar1 = FUN_0052f850(this,0x456,0x48,0xa0,s_VERDANA10_fnt_00563e64,&DAT_00565330);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x456,0);
    Window_GadgetNotify_Text_SetLayout(this,0x456,1,0x1e,0,0);
  }
  iVar1 = FUN_0052f850(this,0x457,0x48,0xb6,s_VERDANA10_fnt_00563e64,&DAT_00565330);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x457,0);
    Window_GadgetNotify_Text_SetLayout(this,0x457,1,0x1e,0,0);
  }
  iVar1 = FUN_0052f850(this,0x458,0x49,0xcc,s_VERDANA10_fnt_00563e64,&DAT_00565330);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x458,0);
    Window_GadgetNotify_Text_SetLayout(this,0x458,1,0x1e,0,0);
  }
  iVar1 = FUN_0052f850(this,0x459,0x49,0xe2,s_VERDANA10_fnt_00563e64,&DAT_00565330);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x459,0);
    Window_GadgetNotify_Text_SetLayout(this,0x459,1,0x1e,0,0);
  }
  FUN_00531c60(this,0x463,0x68,0x45,0x82,0x15,0x10);
  FUN_00531c60(this,0x464,0x68,0x5b,0x82,0x15,0x10);
  FUN_00531c60(this,0x465,0x68,0x87,0x82,0x15,0x10);
  FUN_00531c60(this,0x466,0x68,0x71,0x82,0x15,0x10);
  FUN_00531c60(this,0x467,0x68,0xdf,0x82,0x15,0x10);
  FUN_00531c60(this,0x468,0x68,0xc9,0x82,0x15,0x10);
  FUN_00531c60(this,0x469,0x68,0x9d,0x82,0x15,0x10);
  FUN_00531c60(this,0x46a,0x68,0xb3,0x82,0x15,0x10);
  FUN_0052f5b0(this,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  iVar1 = FUN_0052f850(this,0x1f4a,0x2e,0x22,s_VERDANA10_fnt_00563e64,DAT_00582dc8);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f4a,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f4a,0,0x96,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x1f4b,0xb2,0x22,s_VERDANA10_fnt_00563e64,&DAT_00565328);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f4b,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f4b,1,0x32,0,0);
  }
  FUN_00531850(this,0x1f4c,0x31,0xb3,s_M_BONZEN_spr_00565318);
  FUN_00531850(this,0x1f4d,0x31,0x45,s_M_KIDS_spr_0056530c);
  FUN_00531850(this,0x1f4e,0x31,0x87,s_M_PROLLS_spr_005652fc);
  FUN_00531850(this,0x1f4f,0x31,0x71,s_M_STUDIES_spr_005652ec);
  FUN_00531850(this,0x1f50,0x31,0x5b,s_M_TEENS_spr_005652e0);
  FUN_00531850(this,0x1f51,0x31,0xdf,s_M_TOURIES_spr_005652d0);
  FUN_00531850(this,0x1f52,0x31,0x9d,s_M_YUPPIES_spr_005652c0);
  FUN_00531850(this,0x1f53,0x31,0xc9,s_M_GRUFTIES_spr_005652b0);
  return this;
}

