// rea decompile_all
// name: FUN_00461b20
// address: 0x461b20
// body: available
// range: 0x461b20-0x4632b6 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl FUN_00461b20(int *param_1)

{
  int iVar1;
  void *this;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004c36f0);
  *param_1 = iVar1;
  this = (void *)FUN_00528040(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  FUN_00531850(this,0x4d2,99,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x4d3,99,0x13b,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x585,0x2f,0x83,s_MOEBELRAHMEN_spr_00566960);
  FUN_00531850(this,0x4d4,99,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x4d5,99,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x4d6,99,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x4d7,99,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x4d8,99,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x4d9,99,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x4da,99,0x13b,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x4db,99,0x13b,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x4dc,99,0x13b,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x4dd,99,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x4de,99,0x13b,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x4df,99,0x13b,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x4e0,99,0x13b,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x4e1,99,0x13b,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x4e2,99,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x4e3,0x95,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x4e4,0x95,0x13b,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x4e5,0x95,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x4e6,0x95,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x4e7,0x95,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x4e8,0x95,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x4e9,0x95,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x4ea,0x95,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x4eb,0x95,0x13b,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x4ec,0x95,0x13b,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x4ed,0x95,0x13b,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x4ee,0x95,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x4ef,0x95,0x13b,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x4f0,0x95,0x13b,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x4f1,0x95,0x13b,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x4f2,0x95,0x13b,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x4f3,0x95,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x4f4,199,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x4f5,199,0x13b,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x4f6,199,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x4f7,199,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x4f8,199,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x4f9,199,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x4fa,199,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x4fb,199,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x4fc,199,0x13b,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x4fd,199,0x13b,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x4fe,199,0x13b,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x4ff,199,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x500,199,0x13b,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x501,199,0x13b,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x502,199,0x13b,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x503,199,0x13b,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x504,199,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x505,0x31,0x15e,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x506,0x31,0x15e,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x507,0x31,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x508,0x31,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x509,0x31,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x50a,0x31,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x50b,0x31,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x50c,0x31,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x50d,0x31,0x15e,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x50e,0x31,0x15e,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x50f,0x31,0x15e,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x510,0x31,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x511,0x31,0x15e,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x512,0x31,0x15e,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x513,0x31,0x15e,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x514,0x31,0x15e,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x515,0x31,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x516,99,0x15e,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x517,99,0x15e,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x518,99,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x519,99,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x51a,99,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x51b,99,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x51c,99,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x51d,99,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x51e,99,0x15e,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x51f,99,0x15e,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x520,99,0x15e,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x521,99,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x522,99,0x15e,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x523,99,0x15e,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x524,99,0x15e,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x525,99,0x15e,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x526,99,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x527,0x95,0x15e,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x528,0x95,0x15e,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x529,0x95,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x52a,0x95,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x52b,0x95,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x52c,0x95,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x52d,0x95,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x52e,0x95,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x52f,0x95,0x15e,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x530,0x95,0x15e,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x531,0x95,0x15e,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x532,0x95,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x533,0x95,0x15e,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x534,0x95,0x15e,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x535,0x95,0x15e,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x536,0x95,0x15e,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x537,0x95,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x538,199,0x15e,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x539,199,0x15e,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x53a,199,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x53b,199,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x53c,199,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x53d,199,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x53e,199,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x53f,199,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x540,199,0x15e,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x541,199,0x15e,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x542,199,0x15e,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x543,199,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x544,199,0x15e,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x545,199,0x15e,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x546,199,0x15e,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x547,199,0x15e,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x548,199,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x549,0x31,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x54a,0x31,0x13b,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x54b,0x31,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x54c,0x31,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x54d,0x31,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x54e,0x31,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x54f,0x31,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x550,0x31,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x551,0x31,0x13b,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x552,0x31,0x13b,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x553,0x31,0x13b,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x554,0x31,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x555,0x31,0x13b,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x556,0x31,0x13b,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x557,0x31,0x13b,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x558,0x31,0x13b,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x559,0x31,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  iVar1 = FUN_0052f850(this,0x55a,0x27,0x130,s_VERDANA7_fnt_00563ec8,DAT_00580bec);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x55a,0);
    Window_GadgetNotify_Text_SetLayout(this,0x55a,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x55b,0x58,0x130,s_VERDANA7_fnt_00563ec8,DAT_005816d4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x55b,0);
    Window_GadgetNotify_Text_SetLayout(this,0x55b,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x55c,0x8a,0x130,s_VERDANA7_fnt_00563ec8,DAT_00582974);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x55c,0);
    Window_GadgetNotify_Text_SetLayout(this,0x55c,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x55d,0xbc,0x130,s_VERDANA7_fnt_00563ec8,DAT_0058234c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x55d,0);
    Window_GadgetNotify_Text_SetLayout(this,0x55d,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x55e,0x27,0x154,s_VERDANA7_fnt_00563ec8,DAT_00580e64);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x55e,0);
    Window_GadgetNotify_Text_SetLayout(this,0x55e,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x55f,0x58,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582e08);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x55f,0);
    Window_GadgetNotify_Text_SetLayout(this,0x55f,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x560,0x89,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582770);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x560,0);
    Window_GadgetNotify_Text_SetLayout(this,0x560,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x561,0xba,0x154,s_VERDANA7_fnt_00563ec8,DAT_005810a4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x561,0);
    Window_GadgetNotify_Text_SetLayout(this,0x561,2,0x32,0,0);
  }
  FUN_00531850(this,0x408,0x27,0x129,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x428,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00582b04);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x428,0);
    Window_GadgetNotify_Text_SetLayout(this,0x428,2,0xbe,0,0);
  }
  FUN_0052f5b0(this,0x404,0x2d,0xbc,s_PB22_00_spr_00564174,0,0);
  FUN_0052f5b0(this,0x405,0x5d,0xbc,s_PB24_00_spr_00564144,0,0);
  iVar1 = FUN_0052fc00(this,0x586,0x31,0xe2,0x53,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xaa00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x586,&local_10);
  }
  iVar1 = FUN_0052f850(this,0x588,0x2a,0xd0,s_VERDANA7_fnt_00563ec8,DAT_00580f0c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x588,0);
    Window_GadgetNotify_Text_SetLayout(this,0x588,2,0x5a,0,0);
  }
  iVar1 = FUN_0052f850(this,0x589,0x75,0x83,s_VERDANA7_fnt_00563ec8,DAT_00580cfc);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x589,0);
    Window_GadgetNotify_Text_SetLayout(this,0x589,0,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x58a,0x75,0x8f,s_VERDANA7_fnt_00563ec8,DAT_00580fd4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x58a,0);
    Window_GadgetNotify_Text_SetLayout(this,0x58a,0,0x50,0,0);
  }
  iVar1 = FUN_0052f850(this,0x58b,0xc9,0x8f,s_VERDANA7_fnt_00563ec8,&DAT_005669b0);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x58b,0);
    Window_GadgetNotify_Text_SetLayout(this,0x58b,1,0x1e,0,0);
  }
  iVar1 = FUN_0052f850(this,0x58c,0x75,0x9b,s_VERDANA7_fnt_00563ec8,DAT_00580c00);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x58c,0);
    Window_GadgetNotify_Text_SetLayout(this,0x58c,0,0x50,0,0);
  }
  iVar1 = FUN_0052f850(this,0x58d,0xca,0x9b,s_VERDANA7_fnt_00563ec8,&DAT_005669b0);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x58d,0);
    Window_GadgetNotify_Text_SetLayout(this,0x58d,1,0x1e,0,0);
  }
  iVar1 = FUN_0052f850(this,0x58e,0x75,0xa7,s_VERDANA7_fnt_00563ec8,DAT_00582e38);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x58e,0);
    Window_GadgetNotify_Text_SetLayout(this,0x58e,0,0x41,0,0);
  }
  iVar1 = FUN_0052f850(this,0x58f,0xad,0xa7,s_VERDANA7_fnt_00563ec8,s__99_000__0056694c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x58f,0);
    Window_GadgetNotify_Text_SetLayout(this,0x58f,1,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x590,0x75,0xb3,s_VERDANA7_fnt_00563ec8,DAT_005816c0);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x590,0);
    Window_GadgetNotify_Text_SetLayout(this,0x590,0,0x37,0,0);
  }
  iVar1 = FUN_0052f850(this,0x591,0xad,0xb3,s_VERDANA7_fnt_00563ec8,s__99_000__0056694c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x591,0);
    Window_GadgetNotify_Text_SetLayout(this,0x591,1,0x3c,0,0);
  }
  iVar1 = FUN_0052f690(this,0x592,0x8e,0xbf,s_VERDANA8_fnt_00563e98,DAT_0058269c,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x592,0,0,0);
    Gadget_SetButtonTextLayout(this,0x592,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f690(this,0x593,0x8e,0xd6,s_VERDANA8_fnt_00563e98,DAT_0058249c,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x593,0,0,0);
    Gadget_SetButtonTextLayout(this,0x593,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f850(this,0x594,0x6b,0xef,s_VERDANA8_fnt_00563e98,DAT_00581fc0);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x594,0);
    Window_GadgetNotify_Text_SetLayout(this,0x594,0,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x595,0x99,0xef,s_VERDANA8_fnt_00563e98,s__99_000__0056694c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x595,0);
    Window_GadgetNotify_Text_SetLayout(this,0x595,1,0x50,0,0);
  }
  iVar1 = FUN_0052fc00(this,0x5c6,0x31,0x10e,0x53,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xaa00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x5c6,&local_10);
  }
  iVar1 = FUN_0052f850(this,0x5c7,0x2a,0xfc,s_VERDANA7_fnt_00563ec8,DAT_00582ef0);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x5c7,0);
    Window_GadgetNotify_Text_SetLayout(this,0x5c7,2,0x5a,0,0);
  }
  iVar1 = FUN_0052f690(this,0x5c8,0x8e,0x102,s_VERDANA8_fnt_00563e98,DAT_0058249c,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x5c8,0,0,0);
    Gadget_SetButtonTextLayout(this,0x5c8,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f850(this,0x5c9,0x6b,0x11b,s_VERDANA8_fnt_00563e98,DAT_00581fc0);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x5c9,0);
    Window_GadgetNotify_Text_SetLayout(this,0x5c9,0,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x5ca,0x99,0x11b,s_VERDANA8_fnt_00563e98,s__99_000__0056694c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x5ca,0);
    Window_GadgetNotify_Text_SetLayout(this,0x5ca,1,0x50,0,0);
  }
  FUN_00531850(this,0x5cb,0x27,0x79,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x5cc,0x42,0x2a,s_VERDANA8_fnt_00563e98,DAT_00582c70);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x5cc,0);
    Window_GadgetNotify_Text_SetLayout(this,0x5cc,2,0x98,0,0);
  }
  iVar1 = FUN_0052f850(this,0x5cd,0x41,0x53,s_VERDANA8_fnt_00563e98,DAT_0058294c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x5cd,0);
    Window_GadgetNotify_Text_SetLayout(this,0x5cd,2,0x98,0,0);
  }
  iVar1 = FUN_0052fc00(this,0x5ce,0x4a,0x40,0x8c,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xaa00;
    local_8 = 0xff;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x5ce,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x5cf,0x4a,0x68,0x8c,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x5cf,&local_10);
  }
  iVar1 = FUN_0052f850(this,0x5d2,0xb6,0x83,s_VERDANA7_fnt_00563ec8,&DAT_005669a4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x5d2,0);
    Window_GadgetNotify_Text_SetLayout(this,0x5d2,1,0x32,0,0);
  }
  FUN_0052f5b0(this,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  FUN_00531850(this,0x1f41,0x3d,0x8f,s_MENU_OFEN_MODE05_spr_0056698c);
  return this;
}

