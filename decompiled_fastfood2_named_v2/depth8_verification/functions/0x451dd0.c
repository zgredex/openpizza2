// rea decompile_all
// name: FUN_00451dd0
// address: 0x451dd0
// body: available
// range: 0x451dd0-0x45375e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl FUN_00451dd0(int *param_1)

{
  int iVar1;
  void *this;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004bc860);
  *param_1 = iVar1;
  this = (void *)FUN_00528040(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  FUN_00531850(this,0x408,0x27,0x129,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x501,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00581670);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x501,0);
    FUN_0052f9d0(this,0x501,2,0xbe,0,0);
  }
  iVar1 = FUN_0052f850(this,0x502,0x30,0x75,s_VERDANA7_fnt_00563ec8,DAT_00581b18);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x502,0);
    FUN_0052f9d0(this,0x502,2,0x5a,0,0);
  }
  iVar1 = FUN_0052f850(this,0x503,0x30,0x8c,s_VERDANA7_fnt_00563ec8,DAT_00581000);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x503,0);
    FUN_0052f9d0(this,0x503,2,0x5a,0,0);
  }
  iVar1 = FUN_0052f850(this,0x504,0x30,0xa3,s_VERDANA7_fnt_00563ec8,DAT_00581784);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x504,0);
    FUN_0052f9d0(this,0x504,2,0x5a,0,0);
  }
  iVar1 = FUN_0052f850(this,0x505,0x30,0xba,s_VERDANA7_fnt_00563ec8,DAT_005818c4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x505,0);
    FUN_0052f9d0(this,0x505,2,0x5a,0,0);
  }
  iVar1 = FUN_0052f690(this,0x50c,0x8e,0x62,s_VERDANA8_fnt_00563e98,DAT_005814b4,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x50c,0,0,0);
    FUN_0052f7a0(this,0x50c,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f690(this,0x50d,0x8e,0x7b,s_VERDANA8_fnt_00563e98,DAT_005820b4,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x50d,0,0,0);
    FUN_0052f7a0(this,0x50d,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f690(this,0x50e,0x8e,0x92,s_VERDANA8_fnt_00563e98,DAT_005820b4,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x50e,0,0,0);
    FUN_0052f7a0(this,0x50e,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f690(this,0x50f,0x8e,0xa9,s_VERDANA8_fnt_00563e98,DAT_005820b4,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x50f,0,0,0);
    FUN_0052f7a0(this,0x50f,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f690(this,0x510,0x8e,0xc0,s_VERDANA8_fnt_00563e98,DAT_005810a8,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x510,0,0,0);
    FUN_0052f7a0(this,0x510,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f850(this,0x511,0x7e,0x47,s_VERDANA8_fnt_00563e98,DAT_00581ba8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x511,0);
    FUN_0052f9d0(this,0x511,0,0x46,0,0);
  }
  iVar1 = FUN_0052f850(this,0x512,0x7e,0x53,s_VERDANA8_fnt_00563e98,DAT_0058293c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x512,0);
    FUN_0052f9d0(this,0x512,0,0x37,0,0);
  }
  iVar1 = FUN_0052f850(this,0x513,0xa9,0x53,s_VERDANA8_fnt_00563e98,s__5656__0056447c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x513,0);
    FUN_0052f9d0(this,0x513,1,0x37,0,0);
  }
  iVar1 = FUN_0052f850(this,0x514,0xb7,0x47,s_VERDANA8_fnt_00563e98,&DAT_00564478);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x514,0);
    FUN_0052f9d0(this,0x514,1,0x28,0,0);
  }
  iVar1 = FUN_0052f850(this,0x515,0x7e,0x25,s_VERDANA8_fnt_00563e98,s__Carlos_Estarda_00564468);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x515,0);
    FUN_0052f9d0(this,0x515,0,0x6c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x516,0x7e,0x31,s_VERDANA8_fnt_00563e98,DAT_00581228);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x516,0);
    FUN_0052f9d0(this,0x516,0,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x517,0x7e,0x3c,s_VERDANA8_fnt_00563e98,s__Koch_00564460);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x517,0);
    FUN_0052f9d0(this,0x517,0,0x6c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x518,0xb7,0x31,s_VERDANA8_fnt_00563e98,&DAT_0056445c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x518,0);
    FUN_0052f9d0(this,0x518,1,0x28,0,0);
  }
  FUN_00531850(this,0x519,0x27,0xf2,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x51a,0x2d,0xfd,s_VERDANA8_fnt_00563e98,DAT_0058281c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x51a,0);
    FUN_0052f9d0(this,0x51a,0,0x5a,0,0);
  }
  iVar1 = FUN_0052f850(this,0x51b,0x2d,0x116,s_VERDANA8_fnt_00563e98,s__Pizza_Tingeltangel_0056510c)
  ;
  if (iVar1 != 0) {
    FUN_0052f910(this,0x51b,0);
    FUN_0052f9d0(this,0x51b,0,0x87,0,0);
  }
  FUN_00531850(this,0x51c,0xb5,0x104,s_LOGORAHMEN_00_spr_005650f8);
  FUN_00531c60(this,0x51f,0xb7,0x106,0x2c,0x1d,0x10);
  FUN_00531850(this,0x520,99,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x521,99,0x13b,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x522,99,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x523,99,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x524,99,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x525,99,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x526,99,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x527,99,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x528,99,0x13b,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x529,99,0x13b,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x52a,99,0x13b,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x52b,99,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x52c,99,0x13b,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x52d,99,0x13b,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x52e,99,0x13b,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x52f,99,0x13b,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x530,99,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x531,0x95,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x532,0x95,0x13b,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x533,0x95,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x534,0x95,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x535,0x95,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x536,0x95,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x537,0x95,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x538,0x95,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x539,0x95,0x13b,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x53a,0x95,0x13b,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x53b,0x95,0x13b,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x53c,0x95,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x53d,0x95,0x13b,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x53e,0x95,0x13b,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x53f,0x95,0x13b,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x540,0x95,0x13b,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x541,0x95,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x542,199,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x543,199,0x13b,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x544,199,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x545,199,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x546,199,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x547,199,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x548,199,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x549,199,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x54a,199,0x13b,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x54b,199,0x13b,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x54c,199,0x13b,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x54d,199,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x54e,199,0x13b,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x54f,199,0x13b,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x550,199,0x13b,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x551,199,0x13b,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x552,199,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x553,0x31,0x15e,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x554,0x31,0x15e,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x555,0x31,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x556,0x31,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x557,0x31,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x558,0x31,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x559,0x31,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x55a,0x31,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x55b,0x31,0x15e,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x55c,0x31,0x15e,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x55d,0x31,0x15e,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x55e,0x31,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x55f,0x31,0x15e,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x560,0x31,0x15e,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x561,0x31,0x15e,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x562,0x31,0x15e,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x563,0x31,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x564,99,0x15e,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x565,99,0x15e,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x566,99,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x567,99,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x568,99,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x569,99,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x56a,99,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x56b,99,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x56c,99,0x15e,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x56d,99,0x15e,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x56e,99,0x15e,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x56f,99,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x570,99,0x15e,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x571,99,0x15e,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x572,99,0x15e,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x573,99,0x15e,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x574,99,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x575,0x95,0x15e,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x576,0x95,0x15e,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x577,0x95,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x578,0x95,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x579,0x95,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x57a,0x95,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x57b,0x95,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x57c,0x95,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x57d,0x95,0x15e,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x57e,0x95,0x15e,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x57f,0x95,0x15e,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x580,0x95,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x581,0x95,0x15e,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x582,0x95,0x15e,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x583,0x95,0x15e,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x584,0x95,0x15e,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x585,0x95,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x586,199,0x15e,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x587,199,0x15e,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x588,199,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x589,199,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x58a,199,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x58b,199,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x58c,199,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x58d,199,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x58e,199,0x15e,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x58f,199,0x15e,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x590,199,0x15e,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x591,199,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x592,199,0x15e,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x593,199,0x15e,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x594,199,0x15e,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x595,199,0x15e,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x596,199,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x597,0x31,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x598,0x31,0x13b,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x599,0x31,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x59a,0x31,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x59b,0x31,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x59c,0x31,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x59d,0x31,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x59e,0x31,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x59f,0x31,0x13b,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x5a0,0x31,0x13b,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x5a1,0x31,0x13b,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x5a2,0x31,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x5a3,0x31,0x13b,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x5a4,0x31,0x13b,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x5a5,0x31,0x13b,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x5a6,0x31,0x13b,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x5a7,0x31,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  iVar1 = FUN_0052f850(this,0x5a8,0x27,0x130,s_VERDANA7_fnt_00563ec8,DAT_00580bec);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x5a8,0);
    FUN_0052f9d0(this,0x5a8,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x5a9,0x58,0x130,s_VERDANA7_fnt_00563ec8,DAT_005816d4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x5a9,0);
    FUN_0052f9d0(this,0x5a9,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x5aa,0x8a,0x130,s_VERDANA7_fnt_00563ec8,DAT_00582974);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x5aa,0);
    FUN_0052f9d0(this,0x5aa,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x5ab,0xbc,0x130,s_VERDANA7_fnt_00563ec8,DAT_0058234c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x5ab,0);
    FUN_0052f9d0(this,0x5ab,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x5ac,0x27,0x154,s_VERDANA7_fnt_00563ec8,DAT_00580e64);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x5ac,0);
    FUN_0052f9d0(this,0x5ac,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x5ad,0x58,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582e08);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x5ad,0);
    FUN_0052f9d0(this,0x5ad,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x5ae,0x89,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582770);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x5ae,0);
    FUN_0052f9d0(this,0x5ae,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x5af,0xba,0x154,s_VERDANA7_fnt_00563ec8,DAT_005810a4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x5af,0);
    FUN_0052f9d0(this,0x5af,2,0x32,0,0);
  }
  FUN_0052f5b0(this,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  iVar1 = FUN_0052f850(this,0x1f41,0x89,0xdf,s_VERDANA8_fnt_00563e98,s__Pizzeria_00566640);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f41,0);
    FUN_0052f9d0(this,0x1f41,1,0x5a,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f42,0x33,0xdf,s_VERDANA8_fnt_00563e98,DAT_00582c18);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f42,0);
    FUN_0052f9d0(this,0x1f42,0,0x5a,0,0);
  }
  iVar1 = FUN_0052fc00(this,9000,0x32,0x86,0x5f,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xffc600;
    local_c = 0xffc600;
    local_8 = 0xffc600;
    local_4 = 0;
    FUN_0052fcc0(this,9000,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x2329,0x32,0x86,0x5f,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    FUN_0052fcc0(this,0x2329,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x232a,0x32,0x9d,0x5f,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xffc600;
    local_c = 0xffc600;
    local_8 = 0xffc600;
    local_4 = 0;
    FUN_0052fcc0(this,0x232a,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x232b,0x32,0x9d,0x5f,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    FUN_0052fcc0(this,0x232b,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x232c,0x32,0xb4,0x5f,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xffc600;
    local_c = 0xffc600;
    local_8 = 0xffc600;
    local_4 = 0;
    FUN_0052fcc0(this,0x232c,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x232d,0x32,0xb4,0x5f,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    FUN_0052fcc0(this,0x232d,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x232e,0x32,0xcb,0x5f,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xffc600;
    local_c = 0xffc600;
    local_8 = 0xffc600;
    local_4 = 0;
    FUN_0052fcc0(this,0x232e,&local_10);
  }
  iVar1 = FUN_0052fc00(this,0x232f,0x32,0xcb,0x5f,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    FUN_0052fcc0(this,0x232f,&local_10);
  }
  iVar1 = FUN_0052f690(this,0x2330,0x32,0x62,s_VERDANA8_fnt_00563e98,DAT_005814dc,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x2330,0,0,0);
    FUN_0052f7a0(this,0x2330,2,0x54,0,0,0xfffe);
  }
  FUN_00531850(this,0x2331,0x34,0x25,s_FOTORAHMEN00_spr_00564310);
  FUN_00531850(this,0x2333,0x39,0x2a,s_FOTODUMMY00_spr_00564300);
  FUN_00531850(this,0x2334,0xb7,0x106,s_PLAYLOG_8_01_02_spr_00564744);
  return this;
}

