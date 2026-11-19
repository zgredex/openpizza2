// rea decompile_all
// name: FUN_004132a0
// address: 0x4132a0
// body: available
// range: 0x4132a0-0x415618 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl FUN_004132a0(int *param_1)

{
  int iVar1;
  void *this;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,FUN_004936a0);
  *param_1 = iVar1;
  this = (void *)FUN_00528040(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  FUN_00531850(this,0x45a,0x30,0xe0,s_PERSOPLAN_spr_005644ac);
  FUN_00531850(this,0x1794,0x31,0xe1,s_PERSOPLANLIGHT_spr_00564498);
  FUN_00531850(this,0x1795,0x31,0xeb,s_PERSOPLANLIGHT_spr_00564498);
  FUN_00531850(this,0x1796,0x31,0xf5,s_PERSOPLANLIGHT_spr_00564498);
  FUN_00531850(this,0x1797,0x31,0xff,s_PERSOPLANLIGHT_spr_00564498);
  FUN_00531850(this,0x1798,0x31,0x109,s_PERSOPLANLIGHT_spr_00564498);
  FUN_00531850(this,0x1799,0x31,0x113,s_PERSOPLANLIGHT_spr_00564498);
  FUN_00531850(this,0x179a,0x31,0x11d,s_PERSOPLANLIGHT_spr_00564498);
  FUN_00531850(this,0x491,99,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x492,99,0x13b,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x493,99,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x494,99,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x495,99,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x496,99,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x497,99,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x498,99,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x499,99,0x13b,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x49a,99,0x13b,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x49b,99,0x13b,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x49c,99,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x49d,99,0x13b,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x49e,99,0x13b,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x49f,99,0x13b,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x4a0,99,0x13b,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x4a1,99,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x4a2,0x95,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x4a3,0x95,0x13b,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x4a4,0x95,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x4a5,0x95,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x4a6,0x95,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x4a7,0x95,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x4a8,0x95,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x4a9,0x95,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x4aa,0x95,0x13b,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x4ab,0x95,0x13b,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x4ac,0x95,0x13b,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x4ad,0x95,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x4ae,0x95,0x13b,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x4af,0x95,0x13b,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x4b0,0x95,0x13b,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x4b1,0x95,0x13b,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x4b2,0x95,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x4b3,199,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x4b4,199,0x13b,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x4b5,199,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x4b6,199,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x4b7,199,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x4b8,199,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x4b9,199,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x4ba,199,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x4bb,199,0x13b,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x4bc,199,0x13b,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x4bd,199,0x13b,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x4be,199,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x4bf,199,0x13b,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x4c0,199,0x13b,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x4c1,199,0x13b,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x4c2,199,0x13b,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x4c3,199,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x4c4,0x31,0x15e,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x4c5,0x31,0x15e,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x4c6,0x31,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x4c7,0x31,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x4c8,0x31,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x4c9,0x31,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x4ca,0x31,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x4cb,0x31,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x4cc,0x31,0x15e,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x4cd,0x31,0x15e,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x4ce,0x31,0x15e,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x4cf,0x31,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x4d0,0x31,0x15e,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x4d1,0x31,0x15e,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x4d2,0x31,0x15e,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x4d3,0x31,0x15e,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x4d4,0x31,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x4d5,99,0x15e,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x4d6,99,0x15e,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x4d7,99,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x4d8,99,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x4d9,99,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x4da,99,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x4db,99,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x4dc,99,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x4dd,99,0x15e,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x4de,99,0x15e,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x4df,99,0x15e,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x4e0,99,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x4e1,99,0x15e,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x4e2,99,0x15e,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x4e3,99,0x15e,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x4e4,99,0x15e,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x4e5,99,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x4e6,0x95,0x15e,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x4e7,0x95,0x15e,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x4e8,0x95,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x4e9,0x95,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x4ea,0x95,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x4eb,0x95,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x4ec,0x95,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x4ed,0x95,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x4ee,0x95,0x15e,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x4ef,0x95,0x15e,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x4f0,0x95,0x15e,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x4f1,0x95,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x4f2,0x95,0x15e,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x4f3,0x95,0x15e,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x4f4,0x95,0x15e,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x4f5,0x95,0x15e,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x4f6,0x95,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x4f7,199,0x15e,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x4f8,199,0x15e,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x4f9,199,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x4fa,199,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x4fb,199,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x4fc,199,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x4fd,199,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x4fe,199,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x4ff,199,0x15e,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x500,199,0x15e,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x501,199,0x15e,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x502,199,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x503,199,0x15e,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x504,199,0x15e,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x505,199,0x15e,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x506,199,0x15e,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x507,199,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x508,0x31,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x509,0x31,0x13b,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x50a,0x31,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x50b,0x31,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x50c,0x31,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x50d,0x31,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x50e,0x31,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x50f,0x31,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x510,0x31,0x13b,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x511,0x31,0x13b,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x512,0x31,0x13b,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x513,0x31,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x514,0x31,0x13b,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x515,0x31,0x13b,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x516,0x31,0x13b,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x517,0x31,0x13b,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x518,0x31,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  iVar1 = FUN_0052f850(this,0x519,0x27,0x130,s_VERDANA7_fnt_00563ec8,DAT_00580bec);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x519,0);
    Window_GadgetNotify_Text_SetLayout(this,0x519,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x51a,0x58,0x130,s_VERDANA7_fnt_00563ec8,DAT_005816d4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x51a,0);
    Window_GadgetNotify_Text_SetLayout(this,0x51a,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x51b,0x8a,0x130,s_VERDANA7_fnt_00563ec8,DAT_00582974);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x51b,0);
    Window_GadgetNotify_Text_SetLayout(this,0x51b,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x51c,0xbc,0x130,s_VERDANA7_fnt_00563ec8,DAT_0058234c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x51c,0);
    Window_GadgetNotify_Text_SetLayout(this,0x51c,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x51d,0x27,0x154,s_VERDANA7_fnt_00563ec8,DAT_00580e64);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x51d,0);
    Window_GadgetNotify_Text_SetLayout(this,0x51d,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x51e,0x58,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582e08);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x51e,0);
    Window_GadgetNotify_Text_SetLayout(this,0x51e,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x51f,0x89,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582770);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x51f,0);
    Window_GadgetNotify_Text_SetLayout(this,0x51f,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x520,0xba,0x154,s_VERDANA7_fnt_00563ec8,DAT_005810a4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x520,0);
    Window_GadgetNotify_Text_SetLayout(this,0x520,2,0x32,0,0);
  }
  FUN_00531850(this,0x408,0x27,0x129,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x46f,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00582a9c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x46f,0);
    Window_GadgetNotify_Text_SetLayout(this,0x46f,2,0xbe,0,0);
  }
  iVar1 = FUN_0052f850(this,0x472,0x30,0x75,s_VERDANA7_fnt_00563ec8,DAT_00581b18);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x472,0);
    Window_GadgetNotify_Text_SetLayout(this,0x472,2,0x5a,0,0);
  }
  iVar1 = FUN_0052f850(this,0x473,0x30,0x8c,s_VERDANA7_fnt_00563ec8,DAT_00581000);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x473,0);
    Window_GadgetNotify_Text_SetLayout(this,0x473,2,0x5a,0,0);
  }
  iVar1 = FUN_0052f850(this,0x474,0x30,0xa3,s_VERDANA7_fnt_00563ec8,DAT_00581784);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x474,0);
    Window_GadgetNotify_Text_SetLayout(this,0x474,2,0x5a,0,0);
  }
  iVar1 = FUN_0052f850(this,0x475,0x30,0xba,s_VERDANA7_fnt_00563ec8,DAT_005818c4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x475,0);
    Window_GadgetNotify_Text_SetLayout(this,0x475,2,0x5a,0,0);
  }
  iVar1 = FUN_0052f850(this,0x476,0x30,0xd6,s_VERDANA7_fnt_00563ec8,&DAT_00564220);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x476,0);
    Window_GadgetNotify_Text_SetLayout(this,0x476,0,0,0,0);
  }
  iVar1 = FUN_0052f850(this,0x477,0x43,0xd6,s_VERDANA7_fnt_00563ec8,&DAT_0056421c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x477,0);
    Window_GadgetNotify_Text_SetLayout(this,0x477,0,0,0,0);
  }
  iVar1 = FUN_0052f850(this,0x478,0x58,0xd6,s_VERDANA7_fnt_00563ec8,&DAT_00564218);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x478,0);
    Window_GadgetNotify_Text_SetLayout(this,0x478,0,0,0,0);
  }
  iVar1 = FUN_0052f850(this,0x479,0x6b,0xd6,s_VERDANA7_fnt_00563ec8,&DAT_00564214);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x479,0);
    Window_GadgetNotify_Text_SetLayout(this,0x479,0,0,0,0);
  }
  iVar1 = FUN_0052f850(this,0x47a,0x7c,0xd6,s_VERDANA7_fnt_00563ec8,&DAT_00564210);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x47a,0);
    Window_GadgetNotify_Text_SetLayout(this,0x47a,0,0,0,0);
  }
  iVar1 = FUN_0052f850(this,0x47b,0x90,0xd6,s_VERDANA7_fnt_00563ec8,&DAT_0056420c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x47b,0);
    Window_GadgetNotify_Text_SetLayout(this,0x47b,0,0,0,0);
  }
  iVar1 = FUN_0052f850(this,0x47c,0xa4,0xd6,s_VERDANA7_fnt_00563ec8,&DAT_00564208);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x47c,0);
    Window_GadgetNotify_Text_SetLayout(this,0x47c,0,0,0,0);
  }
  iVar1 = FUN_0052f850(this,0x47d,0xb8,0xd6,s_VERDANA7_fnt_00563ec8,&DAT_00564204);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x47d,0);
    Window_GadgetNotify_Text_SetLayout(this,0x47d,0,0,0,0);
  }
  iVar1 = FUN_0052f850(this,0x47e,0xcb,0xd6,s_VERDANA7_fnt_00563ec8,&DAT_00564200);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x47e,0);
    Window_GadgetNotify_Text_SetLayout(this,0x47e,0,0,0,0);
  }
  iVar1 = FUN_0052fc00(this,0x451,0xde,0xed,0x3c,s_SL01_00_spr_0056448c,0,1);
  if (iVar1 != 0) {
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x451,&local_10);
  }
  FUN_0052f5b0(this,0x44f,0x2f,0x5f,s_PB22_00_spr_00564174,0,0);
  FUN_0052f5b0(this,0x450,0x6f,0x5f,s_PB24_00_spr_00564144,0,0);
  iVar1 = FUN_0052f690(this,0x47f,0x8f,100,s_VERDANA8_fnt_00563e98,DAT_0058202c,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x47f,0,0,0);
    Gadget_SetButtonTextLayout(this,0x47f,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f690(this,0x480,0x8f,0x7b,s_VERDANA8_fnt_00563e98,DAT_00581518,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x480,0,0,0);
    Gadget_SetButtonTextLayout(this,0x480,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f690(this,0x483,0x8f,0x92,s_VERDANA8_fnt_00563e98,DAT_00581518,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x483,0,0,0);
    Gadget_SetButtonTextLayout(this,0x483,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f690(this,0x484,0x8f,0xa9,s_VERDANA8_fnt_00563e98,s__100__00564484,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x484,0,0,0);
    Gadget_SetButtonTextLayout(this,0x484,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f690(this,0x485,0x8f,0xc0,s_VERDANA8_fnt_00563e98,DAT_00582d00,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x485,0,0,0);
    Gadget_SetButtonTextLayout(this,0x485,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f850(this,0x527,0x7e,0x47,s_VERDANA8_fnt_00563e98,DAT_00581ba8);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x527,0);
    Window_GadgetNotify_Text_SetLayout(this,0x527,0,0x46,0,0);
  }
  iVar1 = FUN_0052f850(this,0x528,0x7e,0x53,s_VERDANA8_fnt_00563e98,DAT_0058293c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x528,0);
    Window_GadgetNotify_Text_SetLayout(this,0x528,0,0x37,0,0);
  }
  iVar1 = FUN_0052f850(this,0x529,0xa9,0x53,s_VERDANA8_fnt_00563e98,s__5656__0056447c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x529,0);
    Window_GadgetNotify_Text_SetLayout(this,0x529,1,0x37,0,0);
  }
  iVar1 = FUN_0052f850(this,0x52a,0xb7,0x47,s_VERDANA8_fnt_00563e98,&DAT_00564478);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x52a,0);
    Window_GadgetNotify_Text_SetLayout(this,0x52a,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x52b,0x7e,0x25,s_VERDANA8_fnt_00563e98,s__Carlos_Estarda_00564468);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x52b,0);
    Window_GadgetNotify_Text_SetLayout(this,0x52b,0,0x6c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x52c,0x7e,0x31,s_VERDANA8_fnt_00563e98,DAT_00581228);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x52c,0);
    Window_GadgetNotify_Text_SetLayout(this,0x52c,0,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x52d,0x7e,0x3c,s_VERDANA8_fnt_00563e98,s__Koch_00564460);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x52d,0);
    Window_GadgetNotify_Text_SetLayout(this,0x52d,0,0x6c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x52e,0xb7,0x31,s_VERDANA8_fnt_00563e98,&DAT_0056445c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x52e,0);
    Window_GadgetNotify_Text_SetLayout(this,0x52e,1,0x28,0,0);
  }
  FUN_0052f5b0(this,5000,0x90,0x7b,s_PB14_00_spr_005642c4,1,0);
  iVar1 = FUN_0052f850(this,0x1389,0xa5,0x7f,s_VERDANA8_fnt_00563e98,s__aktiv_00564454);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1389,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1389,0,0x41,0,0);
  }
  iVar1 = FUN_0052fc00(this,6000,0x31,0xe8,0x8c,s_PERSOSLIDERBLUE_00_spr_0056443c,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,6000,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x1771,0x31,0xe8,0x8c,s_PERSOSLIDERGREEN_00_spr_00564424,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1771,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x1772,0x31,0xe8,0x8c,s_PERSOSLIDERRED_00_spr_0056440c,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1772,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x1773,0x31,0xe8,0x8c,s_PERSOSLIDERYELLOW_00_spr_005643f0,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1773,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x1774,0x31,0xf2,0x8c,s_PERSOSLIDERBLUE_00_spr_0056443c,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1774,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x1775,0x31,0xf2,0x8c,s_PERSOSLIDERGREEN_00_spr_00564424,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1775,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x1776,0x31,0xf2,0x8c,s_PERSOSLIDERRED_00_spr_0056440c,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1776,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x1777,0x31,0xf2,0x8c,s_PERSOSLIDERYELLOW_00_spr_005643f0,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1777,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x1778,0x31,0xfc,0x8c,s_PERSOSLIDERBLUE_00_spr_0056443c,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1778,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x1779,0x31,0xfc,0x8c,s_PERSOSLIDERGREEN_00_spr_00564424,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1779,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x177a,0x31,0xfc,0x8c,s_PERSOSLIDERRED_00_spr_0056440c,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x177a,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x177b,0x31,0xfc,0x8c,s_PERSOSLIDERYELLOW_00_spr_005643f0,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x177b,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x177c,0x31,0x106,0x8c,s_PERSOSLIDERBLUE_00_spr_0056443c,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x177c,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x177d,0x31,0x106,0x8c,s_PERSOSLIDERGREEN_00_spr_00564424,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x177d,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x177e,0x31,0x106,0x8c,s_PERSOSLIDERRED_00_spr_0056440c,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x177e,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x177f,0x31,0x106,0x8c,s_PERSOSLIDERYELLOW_00_spr_005643f0,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x177f,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x1780,0x31,0x110,0x8c,s_PERSOSLIDERBLUE_00_spr_0056443c,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1780,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x1781,0x31,0x110,0x8c,s_PERSOSLIDERGREEN_00_spr_00564424,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1781,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x1782,0x31,0x110,0x8c,s_PERSOSLIDERRED_00_spr_0056440c,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1782,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x1783,0x31,0x110,0x8c,s_PERSOSLIDERYELLOW_00_spr_005643f0,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1783,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x1784,0x31,0x11a,0x8c,s_PERSOSLIDERBLUE_00_spr_0056443c,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1784,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x1785,0x31,0x11a,0x8c,s_PERSOSLIDERGREEN_00_spr_00564424,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1785,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x1786,0x31,0x11a,0x8c,s_PERSOSLIDERRED_00_spr_0056440c,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1786,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x1787,0x31,0x11a,0x8c,s_PERSOSLIDERYELLOW_00_spr_005643f0,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1787,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x1788,0x31,0x124,0x8c,s_PERSOSLIDERBLUE_00_spr_0056443c,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1788,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x1789,0x31,0x124,0x8c,s_PERSOSLIDERGREEN_00_spr_00564424,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1789,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x178a,0x31,0x124,0x8c,s_PERSOSLIDERRED_00_spr_0056440c,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x178a,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x178b,0x31,0x124,0x8c,s_PERSOSLIDERYELLOW_00_spr_005643f0,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x178b,&local_10);
  }
  FUN_00531850(this,0x178c,0x27,9,s_PERSOSLIDERBLAU_00_spr_005643d8);
  FUN_00531850(this,0x178d,0x4a,9,s_PERSOSLIDERBLAU_01_spr_005643c0);
  FUN_00531850(this,0x178e,0x28,0x14,s_PERSOSLIDERGELB_00_spr_005643a8);
  FUN_00531850(this,0x178f,0x47,0x14,s_PERSOSLIDERGELB_01_spr_00564390);
  FUN_00531850(this,0x1790,0xac,6,s_PERSOSLIDERGRUEN_00_spr_00564378);
  FUN_00531850(this,0x1791,200,6,s_PERSOSLIDERGRUEN_01_spr_00564360);
  FUN_00531850(this,0x1792,0xa7,0x12,s_PERSOSLIDERROT_00_spr_00564348);
  FUN_00531850(this,0x1793,0xc6,0x10,s_PERSOSLIDERROT_01_spr_00564330);
  FUN_0052f5b0(this,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  iVar1 = FUN_0052fc00(this,9000,0x32,0x86,0x5f,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xffc600;
    local_c = 0xffc600;
    local_8 = 0xffc600;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,9000,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x2329,0x32,0x86,0x5f,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x2329,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x232a,0x32,0x9d,0x5f,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xffc600;
    local_c = 0xffc600;
    local_8 = 0xffc600;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x232a,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x232b,0x32,0x9d,0x5f,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x232b,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x232c,0x32,0xb4,0x5f,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xffc600;
    local_c = 0xffc600;
    local_8 = 0xffc600;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x232c,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x232d,0x32,0xb4,0x5f,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x232d,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x232e,0x32,0xcb,0x5f,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xffc600;
    local_c = 0xffc600;
    local_8 = 0xffc600;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x232e,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x232f,0x32,0xcb,0x5f,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x232f,&local_10);
  }
  FUN_00531850(this,0x2331,0x34,0x25,s_FOTORAHMEN00_spr_00564310);
  FUN_00531850(this,0x2332,0x39,0x2a,s_FOTODUMMY00_spr_00564300);
  iVar1 = FUN_0052f690(this,0x2333,0x48,0x5f,s_VERDANA8_fnt_00563e98,DAT_00581460,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x2333,0,0,0);
    Gadget_SetButtonTextLayout(this,0x2333,2,0x28,0,0,0xfffe);
  }
  return this;
}

