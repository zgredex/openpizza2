// rea decompile_all
// name: FUN_00444ee0
// address: 0x444ee0
// body: available
// range: 0x444ee0-0x445c70 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl FUN_00444ee0(int *param_1)

{
  int iVar1;
  void *this;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004b7b10);
  *param_1 = iVar1;
  this = (void *)FUN_00528040(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  iVar1 = FUN_0052f850(this,0x429,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00581cd4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x429,0);
    Window_GadgetNotify_Text_SetLayout(this,0x429,2,0xbe,0,0);
  }
  FUN_0052f5b0(this,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  iVar1 = FUN_0052f850(this,0x1f43,0x31,0x24,s_VERDANA10_fnt_00563e64,DAT_00581894);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f43,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f43,0,0xb4,0,0);
  }
  iVar1 = FUN_0052f690(this,0x1f59,0x32,0xd2,s_VERDANA8_fnt_00563e98,DAT_00581b08,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x1f59,0x9a,0,0);
    Gadget_SetButtonTextLayout(this,0x1f59,2,0x54,0,0,0xfffe);
  }
  FUN_00531850(this,0x1f64,0x27,0xb6,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x1f65,0x31,0xc0,s_VERDANA10_fnt_00563e64,DAT_00581760);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f65,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f65,0,0xb4,0,0);
  }
  iVar1 = FUN_0052f690(this,0x1f67,0x8e,0xd2,s_VERDANA8_fnt_00563e98,DAT_00582948,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x1f67,0,0,0);
    Gadget_SetButtonTextLayout(this,0x1f67,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f850(this,0x1f6d,0x90,0xe7,s_VERDANA7_fnt_00563ec8,DAT_00581fc0);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f6d,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f6d,0,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f6e,0xbb,0xe7,s_VERDANA7_fnt_00563ec8,s__5000__00566308);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f6e,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f6e,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f75,0x90,0xf1,s_VERDANA7_fnt_00563ec8,DAT_00582a40);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f75,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f75,0,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f76,0xbb,0xf1,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f76,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f76,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f77,0x90,0xfb,s_VERDANA7_fnt_00563ec8,DAT_005811ec);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f77,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f77,0,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f78,0xbb,0xfb,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f78,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f78,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fac,0x38,0x36,s_VERDANA10_fnt_00563e64,s__500000__00564254);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fac,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1fac,1,0x50,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fad,0x2e,0x57,s_VERDANA7_fnt_00563ec8,DAT_00582ed4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fad,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1fad,2,0x28,0,0);
  }
  iVar1 = FUN_0052fc00(this,0x1fae,0x47,0x50,0x8c,s_SL02_00_spr_005642d0,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1fae,&local_10);
  }
  iVar1 = FUN_0052f850(this,0x1faf,0xa6,0x58,s_VERDANA7_fnt_00563ec8,DAT_00582820);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1faf,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1faf,1,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fb0,0x90,0xa6,s_VERDANA7_fnt_00563ec8,DAT_005826ec);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fb0,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1fb0,0,0x46,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fb1,0xbb,0xa6,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fb1,0xff);
    Window_GadgetNotify_Text_SetLayout(this,0x1fb1,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fb3,0x31,0xe7,s_VERDANA7_fnt_00563ec8,DAT_00581fc0);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fb3,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1fb3,0,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fb4,0x55,0xe7,s_VERDANA7_fnt_00563ec8,s__300_000__00566378);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fb4,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1fb4,1,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fb5,0x31,0xf1,s_VERDANA7_fnt_00563ec8,DAT_00582a40);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fb5,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1fb5,0,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fb6,0x5f,0xf1,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fb6,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1fb6,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fb7,0x31,0xfb,s_VERDANA7_fnt_00563ec8,DAT_005811ec);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fb7,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1fb7,0,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fb8,0x5f,0xfb,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fb8,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1fb8,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fb9,0x31,0x121,s_VERDANA10_fnt_00563e64,DAT_005821d4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fb9,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1fb9,0,0xb4,0,0);
  }
  iVar1 = FUN_0052f690(this,0x1fba,0x8e,0x133,s_VERDANA8_fnt_00563e98,DAT_00582948,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x1fba,0,0,0);
    Gadget_SetButtonTextLayout(this,0x1fba,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f850(this,0x1fbb,0x90,0x148,s_VERDANA7_fnt_00563ec8,DAT_00581fc0);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fbb,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1fbb,0,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fbc,0xbb,0x148,s_VERDANA7_fnt_00563ec8,s__5000__00566308);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fbc,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1fbc,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fbd,0x90,0x152,s_VERDANA7_fnt_00563ec8,DAT_00582a40);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fbd,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1fbd,0,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fbe,0xbb,0x152,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fbe,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1fbe,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fbf,0x90,0x15c,s_VERDANA7_fnt_00563ec8,DAT_005811ec);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fbf,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1fbf,0,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fc0,0xbb,0x15c,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fc0,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1fc0,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fc3,0x8f,0x16a,s_VERDANA7_fnt_00563ec8,DAT_005826ec);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fc3,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1fc3,0,0x46,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fc4,0xbb,0x16a,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fc4,0xff);
    Window_GadgetNotify_Text_SetLayout(this,0x1fc4,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fc5,0x90,0x109,s_VERDANA7_fnt_00563ec8,DAT_00582c60);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fc5,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1fc5,0,0x46,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fc6,0xbb,0x109,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fc6,0xff);
    Window_GadgetNotify_Text_SetLayout(this,0x1fc6,1,0x28,0,0);
  }
  iVar1 = FUN_0052f690(this,0x1fcb,0x8e,0x70,s_VERDANA8_fnt_00563e98,s__Fordern_0056636c,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x1fcb,0,0,0);
    Gadget_SetButtonTextLayout(this,0x1fcb,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f850(this,0x1fcc,0x90,0x85,s_VERDANA7_fnt_00563ec8,s__Seit__00566364);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fcc,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1fcc,0,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fcd,0xbb,0x85,s_VERDANA7_fnt_00563ec8,s__16_h_0056635c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fcd,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1fcd,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fce,0x90,0x8f,s_VERDANA7_fnt_00563ec8,DAT_00582a40);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fce,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1fce,0,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fcf,0xbb,0x8f,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fcf,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1fcf,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fd0,0x90,0x99,s_VERDANA7_fnt_00563ec8,DAT_005811ec);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fd0,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1fd0,0,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fd1,0xbb,0x99,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fd1,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1fd1,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fd2,0x8d,0x36,s_VERDANA10_fnt_00563e64,DAT_00581ad8);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fd2,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1fd2,0,0x5a,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fd3,0x34,0x62,s_VERDANA7_fnt_00563ec8,
                       s__Bezahlt_bis_jetzt_nicht__00566340);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fd3,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1fd3,0,0xa0,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fd4,0x92,0x62,s_VERDANA7_fnt_00563ec8,s__1000000___00565528);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fd4,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1fd4,1,0x50,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fd5,0x31,0x109,s_VERDANA7_fnt_00563ec8,DAT_00581834);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fd5,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1fd5,0,0x46,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1fd6,0x5f,0x109,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1fd6,0xff);
    Window_GadgetNotify_Text_SetLayout(this,0x1fd6,1,0x28,0,0);
  }
  return this;
}

