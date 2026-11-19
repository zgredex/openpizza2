// rea decompile_all
// name: FUN_00468bd0
// address: 0x468bd0
// body: available
// range: 0x468bd0-0x469e2a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl FUN_00468bd0(int *param_1)

{
  int iVar1;
  void *this;
  
  iVar1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004c5230);
  *param_1 = iVar1;
  this = (void *)UI_FindWindowByID(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(this,0x507,99,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x508,99,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x509,99,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x50a,99,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x50b,99,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x50c,99,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x50d,99,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x50e,99,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x50f,99,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x510,99,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x511,99,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x512,99,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x513,99,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x514,99,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x515,99,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x516,99,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x517,99,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x518,0x95,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x519,0x95,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x51a,0x95,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x51b,0x95,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x51c,0x95,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x51d,0x95,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x51e,0x95,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x51f,0x95,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x520,0x95,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x521,0x95,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x522,0x95,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x523,0x95,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x524,0x95,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x525,0x95,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x526,0x95,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x527,0x95,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x528,0x95,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x529,199,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x52a,199,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x52b,199,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x52c,199,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x52d,199,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x52e,199,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x52f,199,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x530,199,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x531,199,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x532,199,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x533,199,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x534,199,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x535,199,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x536,199,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x537,199,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x538,199,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x539,199,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x53a,0x31,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x53b,0x31,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x53c,0x31,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x53d,0x31,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x53e,0x31,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x53f,0x31,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x540,0x31,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x541,0x31,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x542,0x31,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x543,0x31,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x544,0x31,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x545,0x31,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x546,0x31,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x547,0x31,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x548,0x31,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x549,0x31,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x54a,0x31,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x54b,99,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x54c,99,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x54d,99,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x54e,99,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x54f,99,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x550,99,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x551,99,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x552,99,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x553,99,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x554,99,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x555,99,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x556,99,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x557,99,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x558,99,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x559,99,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x55a,99,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x55b,99,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x55c,0x95,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x55d,0x95,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x55e,0x95,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x55f,0x95,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x560,0x95,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x561,0x95,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x562,0x95,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x563,0x95,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x564,0x95,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x565,0x95,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x566,0x95,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x567,0x95,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x568,0x95,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x569,0x95,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x56a,0x95,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x56b,0x95,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x56c,0x95,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x56d,199,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x56e,199,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x56f,199,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x570,199,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x571,199,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x572,199,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x573,199,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x574,199,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x575,199,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x576,199,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x577,199,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x578,199,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x579,199,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x57a,199,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x57b,199,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x57c,199,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x57d,199,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x57e,0x31,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x57f,0x31,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x580,0x31,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x581,0x31,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x582,0x31,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x583,0x31,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x584,0x31,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x585,0x31,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x586,0x31,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x587,0x31,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x588,0x31,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x589,0x31,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x58a,0x31,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x58b,0x31,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x58c,0x31,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x58d,0x31,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x58e,0x31,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  iVar1 = UI_AddText(this,0x58f,0x27,0x130,s_VERDANA7_fnt_00563ec8,DAT_00580bec);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x58f,0);
    FUN_0052f9d0(this,0x58f,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x590,0x58,0x130,s_VERDANA7_fnt_00563ec8,DAT_005816d4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x590,0);
    FUN_0052f9d0(this,0x590,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x591,0x8a,0x130,s_VERDANA7_fnt_00563ec8,DAT_00582974);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x591,0);
    FUN_0052f9d0(this,0x591,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x592,0xbc,0x130,s_VERDANA7_fnt_00563ec8,DAT_0058234c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x592,0);
    FUN_0052f9d0(this,0x592,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x593,0x27,0x154,s_VERDANA7_fnt_00563ec8,DAT_00580e64);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x593,0);
    FUN_0052f9d0(this,0x593,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x594,0x58,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582e08);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x594,0);
    FUN_0052f9d0(this,0x594,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x595,0x89,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582770);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x595,0);
    FUN_0052f9d0(this,0x595,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x596,0xba,0x154,s_VERDANA7_fnt_00563ec8,DAT_005810a4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x596,0);
    FUN_0052f9d0(this,0x596,2,0x32,0,0);
  }
  UI_AddSprite(this,0x1f41,0x27,0x129,s_TRENNZEILE_spr_00563eb8);
  iVar1 = UI_AddText(this,0x1f42,0x2c,7,s_TIMESFONT_fnt_00563ea8,DAT_00582a58);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f42,0);
    FUN_0052f9d0(this,0x1f42,2,0xbe,0,0);
  }
  UI_AddSprite(this,0x1f43,0x27,0xf2,s_TRENNZEILE_spr_00563eb8);
  iVar1 = UI_AddText(this,0x1f44,0x2e,0xfa,s_VERDANA10_fnt_00563e64,DAT_005828b4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f44,0);
    FUN_0052f9d0(this,0x1f44,0,0xb4,0,0);
  }
  iVar1 = UI_AddText(this,0x1f45,0x2d,0x11a,s_VERDANA8_fnt_00563e98,s__4_Quartal_2043_00566b1c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f45,0);
    FUN_0052f9d0(this,0x1f45,0,0xb1,0,0);
  }
  iVar1 = UI_AddText(this,0x1f46,0x9f,0x11a,s_VERDANA8_fnt_00563e98,DAT_00580ffc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f46,0);
    FUN_0052f9d0(this,0x1f46,0,0x28,0,0);
  }
  iVar1 = UI_AddText(this,0x1f47,0xbc,0x11a,s_VERDANA8_fnt_00563e98,s__19_00_00566b14);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f47,0);
    FUN_0052f9d0(this,0x1f47,1,0x2d,0,0);
  }
  iVar1 = UI_AddText(this,0x1f49,0x31,0x7c,s_VERDANA10_fnt_00563e64,DAT_00581094);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f49,0);
    FUN_0052f9d0(this,0x1f49,0,100,0,0);
  }
  UI_AddSprite(this,0x1f4a,0x36,0x90,s_TAB08_spr_00566b08);
  UI_AddImage(this,0x1f4c,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  UI_AddSprite(this,0x1f55,0x5e,0x2f,s_MG_H_PIZZ_B7_spr_00563e38);
  iVar1 = UI_AddText(this,0x1f56,0x2d,0x10a,s_VERDANA8_fnt_00563e98,
                     s__New_Teens_on_the_Block_00566af0);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f56,0);
    FUN_0052f9d0(this,0x1f56,0,0xbe,0,0);
  }
  return this;
}

