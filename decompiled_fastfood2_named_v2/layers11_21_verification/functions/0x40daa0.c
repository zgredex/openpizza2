// rea decompile_all
// name: FUN_0040daa0
// address: 0x40daa0
// body: available
// range: 0x40daa0-0x40f1cb inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl FUN_0040daa0(int *param_1)

{
  int iVar1;
  void *this;
  
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_00490e90);
  *param_1 = iVar1;
  this = (void *)FUN_00528040(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  FUN_0052f5b0(this,0x596,0x5b,0x44,s_ZUTABPB__00_spr_00564180,1,0);
  FUN_0052f5b0(this,0x597,0x8b,0x44,s_ZUTABPB__00_spr_00564180,1,0);
  FUN_0052f5b0(this,0x598,0xbb,0x44,s_ZUTABPB__00_spr_00564180,1,0);
  FUN_0052f5b0(this,0x599,0x5b,0x6a,s_ZUTABPB__00_spr_00564180,1,0);
  FUN_0052f5b0(this,0x59a,0x8b,0x6a,s_ZUTABPB__00_spr_00564180,1,0);
  FUN_0052f5b0(this,0x59b,0xbb,0x6a,s_ZUTABPB__00_spr_00564180,1,0);
  FUN_0052f5b0(this,0x59c,0x5b,0x90,s_ZUTABPB__00_spr_00564180,1,0);
  FUN_0052f5b0(this,0x59d,0x8b,0x90,s_ZUTABPB__00_spr_00564180,1,0);
  FUN_0052f5b0(this,0x59e,0xbb,0x90,s_ZUTABPB__00_spr_00564180,1,0);
  FUN_0052f5b0(this,0x59f,0x5b,0xb6,s_ZUTABPB__00_spr_00564180,1,0);
  FUN_0052f5b0(this,0x5a0,0x8b,0xb6,s_ZUTABPB__00_spr_00564180,1,0);
  FUN_0052f5b0(this,0x5a1,0xbb,0xb6,s_ZUTABPB__00_spr_00564180,1,0);
  FUN_00531850(this,0x4d2,99,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x4d3,99,0x13b,s_BEWERTUNG__01_spr_00564004);
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
  iVar1 = FUN_0052f850(this,0x428,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00582728);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x428,0);
    Window_GadgetNotify_Text_SetLayout(this,0x428,2,0xbe,0,0);
  }
  iVar1 = FUN_0052f850(this,0x42a,0x30,0x45,s_VERDANA7_fnt_00563ec8,DAT_00580cb0);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x42a,0);
    Window_GadgetNotify_Text_SetLayout(this,0x42a,0,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x42b,0x30,0x6b,s_VERDANA7_fnt_00563ec8,DAT_0058157c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x42b,0);
    Window_GadgetNotify_Text_SetLayout(this,0x42b,0,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x42d,0x30,0xb7,s_VERDANA7_fnt_00563ec8,DAT_00582618);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x42d,0);
    Window_GadgetNotify_Text_SetLayout(this,0x42d,0,0x3c,0,0);
  }
  FUN_0052f5b0(this,0x41c,0x2d,0x112,s_PB22_00_spr_00564174,0,0);
  iVar1 = FUN_0052f690(this,0x4d1,0x41,0x113,s_VERDANA8_fnt_00563e98,s__Keine_Musik_00564150,0,
                       s_TEXTPB05__00_spr_00564160);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x4d1,0,0,0);
    Gadget_SetButtonTextLayout(this,0x4d1,2,0x93,0,0,0xfffe);
  }
  FUN_0052f5b0(this,0x41f,0xce,0x112,s_PB24_00_spr_00564144,0,0);
  FUN_0052f5b0(this,0x3f4,0x2e,0x22,s_PB13_00_spr_00564138,1,0);
  FUN_0052f5b0(this,0x3f5,0x4c,0x22,s_PB15_00_spr_0056412c,1,0);
  FUN_0052f5b0(this,0x3f6,0x6a,0x22,s_PB17_00_spr_00564120,1,0);
  FUN_0052f5b0(this,0x3f7,0x88,0x22,s_PB19_00_spr_00564114,1,0);
  FUN_0052f5b0(this,0x3f8,0xa6,0x22,s_PB20_00_spr_00564108,1,0);
  FUN_0052f5b0(this,0x404,0x94,0xf6,s_PB22_00_spr_00564174,0,0);
  iVar1 = FUN_0052f850(this,0x562,0x38,0xfa,s_VERDANA10_fnt_00563e64,s__5751143__005640fc);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x562,0);
    Window_GadgetNotify_Text_SetLayout(this,0x562,0,100,0,0);
  }
  iVar1 = FUN_0052f850(this,0x42c,0x30,0x91,s_VERDANA7_fnt_00563ec8,DAT_00582b4c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x42c,0);
    Window_GadgetNotify_Text_SetLayout(this,0x42c,0,0x3c,0,0);
  }
  FUN_0052f5b0(this,0x586,0xcb,0x22,s_PBHERD__00_spr_005640ec,1,0);
  iVar1 = FUN_0052f690(this,0x587,0xa8,0xf7,s_VERDANA8_fnt_00563e98,&DAT_00579aec,0,
                       s_TEXTPB05__00_spr_00564160);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x587,0,0,0);
    Gadget_SetButtonTextLayout(this,0x587,2,0x2c,0,0,0xfffe);
  }
  FUN_0052f5b0(this,0x405,0xce,0xf6,s_PB24_00_spr_00564144,0,0);
  FUN_00531c60(this,0x589,0xad,0xfb,0x21,0xc,0x10);
  iVar1 = FUN_0052f850(this,0x5a2,0x38,0xdb,s_VERDANA8_fnt_00563e98,s__Stuhl_005640e4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x5a2,0);
    Window_GadgetNotify_Text_SetLayout(this,0x5a2,0,0x50,0,0);
  }
  iVar1 = FUN_0052f850(this,0x5a3,0x99,0xdb,s_VERDANA8_fnt_00563e98,s__einfach_005640d8);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x5a3,0);
    Window_GadgetNotify_Text_SetLayout(this,0x5a3,0,0x50,0,0);
  }
  iVar1 = FUN_0052f850(this,0x5a4,0x83,0xe9,s_VERDANA8_fnt_00563e98,s__250__005640d0);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x5a4,0);
    Window_GadgetNotify_Text_SetLayout(this,0x5a4,1,0x50,0,0);
  }
  iVar1 = FUN_0052f850(this,0x5a5,0x38,0xe9,s_VERDANA8_fnt_00563e98,DAT_005814d8);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x5a5,0);
    Window_GadgetNotify_Text_SetLayout(this,0x5a5,0,0x50,0,0);
  }
  FUN_0052f5b0(this,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  FUN_00531850(this,0x1f59,0x5b,0x44,s_MENU_STUHL_EINF03_F_spr_005640b8);
  FUN_00531850(this,0x1f5a,0x8b,0x44,s_MENU_STUHL_EINF03_F_spr_005640b8);
  FUN_00531850(this,0x1f5b,0xbb,0x44,s_MENU_STUHL_EINF03_F_spr_005640b8);
  FUN_00531850(this,0x1f5c,0x5b,0x6a,s_MENU_STUHL_EINF03_F_spr_005640b8);
  FUN_00531850(this,0x1f5d,0x8b,0x6a,s_MENU_STUHL_EINF03_F_spr_005640b8);
  FUN_00531850(this,0x1f5e,0xbb,0x6a,s_MENU_STUHL_EINF03_F_spr_005640b8);
  FUN_00531850(this,0x1f5f,0x5b,0xb6,s_MENU_STUHL_EINF03_F_spr_005640b8);
  FUN_00531850(this,0x1f60,0x8b,0xb6,s_MENU_STUHL_EINF03_F_spr_005640b8);
  FUN_00531850(this,0x1f61,0xbb,0xb6,s_MENU_STUHL_EINF03_F_spr_005640b8);
  FUN_00531850(this,0x1f62,0xbb,0x90,s_MENU_STUHL_EINF03_F_spr_005640b8);
  FUN_00531850(this,0x1f63,0x8b,0x90,s_MENU_STUHL_EINF03_F_spr_005640b8);
  FUN_00531850(this,0x1f64,0x5b,0x90,s_MENU_STUHL_EINF03_F_spr_005640b8);
  return this;
}

