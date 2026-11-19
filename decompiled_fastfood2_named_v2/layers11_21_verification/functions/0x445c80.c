// rea decompile_all
// name: FUN_00445c80
// address: 0x445c80
// body: available
// range: 0x445c80-0x447304 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl FUN_00445c80(int *param_1)

{
  int iVar1;
  void *this;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004b83a0);
  *param_1 = iVar1;
  this = (void *)FUN_00528040(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  FUN_00531850(this,0x408,0x27,0x129,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x501,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00582728);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x501,0);
    Window_GadgetNotify_Text_SetLayout(this,0x501,2,0xbe,0,0);
  }
  FUN_00531850(this,0x519,0x27,0xf2,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x51a,0x2d,0xfd,s_VERDANA8_fnt_00563e98,DAT_0058281c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x51a,0);
    Window_GadgetNotify_Text_SetLayout(this,0x51a,0,0x5a,0,0);
  }
  iVar1 = FUN_0052f850(this,0x51b,0x2d,0x116,s_VERDANA8_fnt_00563e98,s__Pizza_Tingeltangel_0056510c)
  ;
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x51b,0);
    Window_GadgetNotify_Text_SetLayout(this,0x51b,0,0x87,0,0);
  }
  FUN_00531850(this,0x51c,0xb5,0x104,s_LOGORAHMEN_00_spr_005650f8);
  FUN_00531c60(this,0x536,0xb7,0x104,0x2c,0x1d,0x10);
  FUN_00531850(this,0x51f,0x27,0x93,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x520,0x2e,0x9e,s_VERDANA8_fnt_00563e98,DAT_005810c0);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x520,0);
    Window_GadgetNotify_Text_SetLayout(this,0x520,0,0x5a,0,0);
  }
  iVar1 = FUN_0052f850(this,0x521,0x53,0xa8,s_VERDANA8_fnt_00563e98,DAT_00582ee8);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x521,0);
    Window_GadgetNotify_Text_SetLayout(this,0x521,1,0x5a,0,0);
  }
  iVar1 = FUN_0052f850(this,0x522,0x53,0xb7,s_VERDANA8_fnt_00563e98,DAT_00582b20);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x522,0);
    Window_GadgetNotify_Text_SetLayout(this,0x522,1,0x5a,0,0);
  }
  iVar1 = FUN_0052f850(this,0x523,0x54,199,s_VERDANA8_fnt_00563e98,DAT_00582424);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x523,0);
    Window_GadgetNotify_Text_SetLayout(this,0x523,1,0x5a,0,0);
  }
  iVar1 = FUN_0052f850(this,0x524,0xb5,0xa8,s_VERDANA8_fnt_00563e98,&DAT_00566408);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x524,0);
    Window_GadgetNotify_Text_SetLayout(this,0x524,1,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x525,0xb5,0xb7,s_VERDANA8_fnt_00563e98,&DAT_00566408);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x525,0);
    Window_GadgetNotify_Text_SetLayout(this,0x525,1,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x526,0xb5,199,s_VERDANA8_fnt_00563e98,&DAT_00566408);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x526,0);
    Window_GadgetNotify_Text_SetLayout(this,0x526,1,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x527,0x2f,0x84,s_VERDANA8_fnt_00563e98,DAT_00580f14);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x527,0);
    Window_GadgetNotify_Text_SetLayout(this,0x527,0,0x5a,0,0);
  }
  iVar1 = FUN_0052f850(this,0x528,0x8d,0x84,s_VERDANA8_fnt_00563e98,s__Meditativ_005663fc);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x528,0);
    Window_GadgetNotify_Text_SetLayout(this,0x528,1,0x5a,0,0);
  }
  iVar1 = FUN_0052fc00(this,0x529,0x3e,0x3c,0x50,s_SCSPEZIAL1_00_spr_00565ac0,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xaa00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x529,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x52a,0x89,0x3c,0x50,s_SCSPEZIAL2_00_spr_00565aac,1,0);
  if (iVar1 != 0) {
    local_10 = 0xaa00;
    local_c = 0xffff;
    local_8 = 0xff;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x52a,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x52b,0x3e,0x5a,0xa0,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xf700;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x52b,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x52c,0x3e,0x77,0xa0,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xf700;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x52c,&local_10);
  }
  iVar1 = FUN_0052f850(this,0x52d,0x48,0x27,s_VERDANA8_fnt_00563e98,DAT_00581910);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x52d,0);
    Window_GadgetNotify_Text_SetLayout(this,0x52d,2,0x82,0,0);
  }
  iVar1 = FUN_0052f850(this,0x52e,0x48,0x47,s_VERDANA8_fnt_00563e98,DAT_0058294c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x52e,0);
    Window_GadgetNotify_Text_SetLayout(this,0x52e,2,0x82,0,0);
  }
  iVar1 = FUN_0052f850(this,0x52f,0x48,100,s_VERDANA8_fnt_00563e98,DAT_00582c0c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x52f,0);
    Window_GadgetNotify_Text_SetLayout(this,0x52f,2,0x82,0,0);
  }
  FUN_00531850(this,0x530,0x2e,0x36,s_FF_ICONS_00_spr_005663ec);
  FUN_00531850(this,0x531,0xd9,0x33,s_FF_ICONS_01_spr_005663dc);
  FUN_00531850(this,0x532,0x2a,0x51,s_FF_ICONS_02_spr_005663cc);
  FUN_00531850(this,0x533,0xda,0x51,s_FF_ICONS_03_spr_005663bc);
  FUN_00531850(this,0x534,0x2f,0x70,s_FF_ICONS_04_spr_005663ac);
  FUN_00531850(this,0x535,0xda,0x6b,s_FF_ICONS_05_spr_0056639c);
  FUN_00531850(this,0x537,99,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x538,99,0x13b,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x539,99,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x53a,99,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x53b,99,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x53c,99,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x53d,99,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x53e,99,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x53f,99,0x13b,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x540,99,0x13b,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x541,99,0x13b,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x542,99,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x543,99,0x13b,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x544,99,0x13b,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x545,99,0x13b,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x546,99,0x13b,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x547,99,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x548,0x95,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x549,0x95,0x13b,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x54a,0x95,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x54b,0x95,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x54c,0x95,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x54d,0x95,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x54e,0x95,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x54f,0x95,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x550,0x95,0x13b,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x551,0x95,0x13b,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x552,0x95,0x13b,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x553,0x95,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x554,0x95,0x13b,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x555,0x95,0x13b,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x556,0x95,0x13b,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x557,0x95,0x13b,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x558,0x95,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x559,199,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x55a,199,0x13b,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x55b,199,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x55c,199,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x55d,199,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x55e,199,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x55f,199,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x560,199,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x561,199,0x13b,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x562,199,0x13b,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x563,199,0x13b,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x564,199,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x565,199,0x13b,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x566,199,0x13b,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x567,199,0x13b,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x568,199,0x13b,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x569,199,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x56a,0x31,0x15e,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x56b,0x31,0x15e,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x56c,0x31,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x56d,0x31,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x56e,0x31,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x56f,0x31,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x570,0x31,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x571,0x31,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x572,0x31,0x15e,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x573,0x31,0x15e,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x574,0x31,0x15e,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x575,0x31,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x576,0x31,0x15e,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x577,0x31,0x15e,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x578,0x31,0x15e,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x579,0x31,0x15e,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x57a,0x31,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x57b,99,0x15e,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x57c,99,0x15e,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x57d,99,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x57e,99,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x57f,99,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x580,99,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x581,99,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x582,99,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x583,99,0x15e,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x584,99,0x15e,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x585,99,0x15e,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x586,99,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x587,99,0x15e,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x588,99,0x15e,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x589,99,0x15e,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x58a,99,0x15e,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x58b,99,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x58c,0x95,0x15e,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x58d,0x95,0x15e,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x58e,0x95,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x58f,0x95,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x590,0x95,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x591,0x95,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x592,0x95,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x593,0x95,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x594,0x95,0x15e,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x595,0x95,0x15e,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x596,0x95,0x15e,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x597,0x95,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x598,0x95,0x15e,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x599,0x95,0x15e,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x59a,0x95,0x15e,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x59b,0x95,0x15e,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x59c,0x95,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x59d,199,0x15e,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x59e,199,0x15e,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x59f,199,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x5a0,199,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x5a1,199,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x5a2,199,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x5a3,199,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x5a4,199,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x5a5,199,0x15e,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x5a6,199,0x15e,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x5a7,199,0x15e,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x5a8,199,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x5a9,199,0x15e,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x5aa,199,0x15e,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x5ab,199,0x15e,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x5ac,199,0x15e,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x5ad,199,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x5ae,0x31,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x5af,0x31,0x13b,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x5b0,0x31,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x5b1,0x31,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x5b2,0x31,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x5b3,0x31,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x5b4,0x31,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x5b5,0x31,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x5b6,0x31,0x13b,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x5b7,0x31,0x13b,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x5b8,0x31,0x13b,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x5b9,0x31,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x5ba,0x31,0x13b,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x5bb,0x31,0x13b,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x5bc,0x31,0x13b,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x5bd,0x31,0x13b,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x5be,0x31,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  iVar1 = FUN_0052f850(this,0x5bf,0x27,0x130,s_VERDANA7_fnt_00563ec8,DAT_00580bec);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x5bf,0);
    Window_GadgetNotify_Text_SetLayout(this,0x5bf,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x5c0,0x58,0x130,s_VERDANA7_fnt_00563ec8,DAT_005816d4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x5c0,0);
    Window_GadgetNotify_Text_SetLayout(this,0x5c0,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x5c1,0x8a,0x130,s_VERDANA7_fnt_00563ec8,DAT_00582974);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x5c1,0);
    Window_GadgetNotify_Text_SetLayout(this,0x5c1,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x5c2,0xbc,0x130,s_VERDANA7_fnt_00563ec8,DAT_0058234c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x5c2,0);
    Window_GadgetNotify_Text_SetLayout(this,0x5c2,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x5c3,0x27,0x154,s_VERDANA7_fnt_00563ec8,DAT_00580e64);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x5c3,0);
    Window_GadgetNotify_Text_SetLayout(this,0x5c3,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x5c4,0x58,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582e08);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x5c4,0);
    Window_GadgetNotify_Text_SetLayout(this,0x5c4,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x5c5,0x89,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582770);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x5c5,0);
    Window_GadgetNotify_Text_SetLayout(this,0x5c5,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x5c6,0xba,0x154,s_VERDANA7_fnt_00563ec8,DAT_005810a4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x5c6,0);
    Window_GadgetNotify_Text_SetLayout(this,0x5c6,2,0x32,0,0);
  }
  FUN_0052f5b0(this,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  FUN_00531850(this,0x1f42,0xb7,0x104,s_PLAYLOG_8_01_02_spr_00564744);
  return this;
}

