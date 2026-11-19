// rea decompile_all
// name: FUN_00410740
// address: 0x410740
// body: available
// range: 0x410740-0x411b8e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl FUN_00410740(int *param_1)

{
  int iVar1;
  void *this;
  
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_00492480);
  *param_1 = iVar1;
  this = (void *)FUN_00528040(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  FUN_00531850(this,0x46b,99,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x46c,99,0x13b,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x46d,99,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x46e,99,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x46f,99,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x470,99,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x471,99,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x472,99,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x473,99,0x13b,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x474,99,0x13b,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x475,99,0x13b,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x476,99,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x477,99,0x13b,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x478,99,0x13b,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x479,99,0x13b,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x47a,99,0x13b,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x47b,99,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x47c,0x95,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x47d,0x95,0x13b,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x47e,0x95,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x47f,0x95,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x480,0x95,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x481,0x95,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x482,0x95,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x483,0x95,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x484,0x95,0x13b,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x485,0x95,0x13b,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x486,0x95,0x13b,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x487,0x95,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x488,0x95,0x13b,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x489,0x95,0x13b,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x48a,0x95,0x13b,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x48b,0x95,0x13b,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x48c,0x95,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x48d,199,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x48e,199,0x13b,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x48f,199,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x490,199,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x491,199,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x492,199,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x493,199,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x494,199,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x495,199,0x13b,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x496,199,0x13b,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x497,199,0x13b,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x498,199,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x499,199,0x13b,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x49a,199,0x13b,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x49b,199,0x13b,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x49c,199,0x13b,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x49d,199,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x49e,0x31,0x15e,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x49f,0x31,0x15e,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x4a0,0x31,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x4a1,0x31,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x4a2,0x31,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x4a3,0x31,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x4a4,0x31,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x4a5,0x31,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x4a6,0x31,0x15e,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x4a7,0x31,0x15e,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x4a8,0x31,0x15e,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x4a9,0x31,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x4aa,0x31,0x15e,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x4ab,0x31,0x15e,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x4ac,0x31,0x15e,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x4ad,0x31,0x15e,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x4ae,0x31,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x4af,99,0x15e,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x4b0,99,0x15e,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x4b1,99,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x4b2,99,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x4b3,99,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x4b4,99,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x4b5,99,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x4b6,99,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x4b7,99,0x15e,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x4b8,99,0x15e,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x4b9,99,0x15e,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x4ba,99,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x4bb,99,0x15e,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x4bc,99,0x15e,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x4bd,99,0x15e,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x4be,99,0x15e,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x4bf,99,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x4c0,0x95,0x15e,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x4c1,0x95,0x15e,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x4c2,0x95,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x4c3,0x95,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x4c4,0x95,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x4c5,0x95,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x4c6,0x95,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x4c7,0x95,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x4c8,0x95,0x15e,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x4c9,0x95,0x15e,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x4ca,0x95,0x15e,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x4cb,0x95,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x4cc,0x95,0x15e,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x4cd,0x95,0x15e,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x4ce,0x95,0x15e,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x4cf,0x95,0x15e,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x4d0,0x95,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x4d1,199,0x15e,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x4d2,199,0x15e,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x4d3,199,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x4d4,199,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x4d5,199,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x4d6,199,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x4d7,199,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x4d8,199,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x4d9,199,0x15e,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x4da,199,0x15e,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x4db,199,0x15e,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x4dc,199,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x4dd,199,0x15e,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x4de,199,0x15e,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x4df,199,0x15e,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x4e0,199,0x15e,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x4e1,199,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x4e2,0x31,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x4e3,0x31,0x13b,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x4e4,0x31,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x4e5,0x31,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x4e6,0x31,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x4e7,0x31,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x4e8,0x31,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x4e9,0x31,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x4ea,0x31,0x13b,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x4eb,0x31,0x13b,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x4ec,0x31,0x13b,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x4ed,0x31,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x4ee,0x31,0x13b,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x4ef,0x31,0x13b,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x4f0,0x31,0x13b,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x4f1,0x31,0x13b,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x4f2,0x31,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  iVar1 = FUN_0052f850(this,0x4f3,0x27,0x130,s_VERDANA7_fnt_00563ec8,DAT_00580bec);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4f3,0);
    FUN_0052f9d0(this,0x4f3,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4f4,0x58,0x130,s_VERDANA7_fnt_00563ec8,DAT_005816d4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4f4,0);
    FUN_0052f9d0(this,0x4f4,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4f5,0x8a,0x130,s_VERDANA7_fnt_00563ec8,DAT_00582974);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4f5,0);
    FUN_0052f9d0(this,0x4f5,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4f6,0xbc,0x130,s_VERDANA7_fnt_00563ec8,DAT_0058234c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4f6,0);
    FUN_0052f9d0(this,0x4f6,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4f7,0x27,0x154,s_VERDANA7_fnt_00563ec8,DAT_00580e64);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4f7,0);
    FUN_0052f9d0(this,0x4f7,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4f8,0x58,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582e08);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4f8,0);
    FUN_0052f9d0(this,0x4f8,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4f9,0x89,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582770);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4f9,0);
    FUN_0052f9d0(this,0x4f9,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4fa,0xba,0x154,s_VERDANA7_fnt_00563ec8,DAT_005810a4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4fa,0);
    FUN_0052f9d0(this,0x4fa,2,0x32,0,0);
  }
  FUN_00531850(this,0x408,0x27,0x129,s_TRENNZEILE_spr_00563eb8);
  FUN_00531850(this,0x409,0x27,0xf2,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x445,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00582840);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x445,0);
    FUN_0052f9d0(this,0x445,2,0xbe,0,0);
  }
  iVar1 = FUN_0052f850(this,0x446,0x33,0x25,s_VERDANA10_fnt_00563e64,DAT_00581008);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x446,0);
    FUN_0052f9d0(this,0x446,0,0xb4,0,0);
  }
  iVar1 = FUN_0052f850(this,0x448,0x44,0xd3,s_VERDANA10_fnt_00563e64,DAT_00581d84);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x448,0);
    FUN_0052f9d0(this,0x448,0,0x5f,0,0);
  }
  FUN_0052f5b0(this,0x404,0x93,0xd1,s_PB22_00_spr_00564174,0,0);
  iVar1 = FUN_0052f690(this,0x4fd,0xa7,0xd2,s_VERDANA8_fnt_00563e98,&DAT_00579aec,0,
                       s_TEXTPB05__00_spr_00564160);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x4fd,0,0,0);
    FUN_0052f7a0(this,0x4fd,2,0x2c,0,0,0xfffe);
  }
  FUN_0052f5b0(this,0x405,0xcd,0xd1,s_PB24_00_spr_00564144,0,0);
  FUN_00531c60(this,0x4ff,0xac,0xd6,0x21,0xc,0x10);
  FUN_0052f5b0(this,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  FUN_0052f5b0(this,0x1f44,0x2d,0x89,s_PB22_00_spr_00564174,0,0);
  iVar1 = FUN_0052f690(this,0x1f45,0x41,0x8a,s_VERDANA8_fnt_00563e98,s__Rustikal_00564294,0,
                       s_TEXTPB05__00_spr_00564160);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x1f45,0,0,0);
    FUN_0052f7a0(this,0x1f45,2,0x93,0,0,0xfffe);
  }
  FUN_0052f5b0(this,0x1f46,0xce,0x89,s_PB24_00_spr_00564144,0,0);
  FUN_0052f5b0(this,0x1f47,0x2d,0xad,s_PB22_00_spr_00564174,0,0);
  iVar1 = FUN_0052f690(this,0x1f48,0x41,0xae,s_VERDANA8_fnt_00563e98,&DAT_00564284,0,
                       s_TEXTPB05__00_spr_00564160);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x1f48,0,0,0);
    FUN_0052f7a0(this,0x1f48,2,0x93,0,0,0xfffe);
  }
  FUN_0052f5b0(this,0x1f49,0xce,0xad,s_PB24_00_spr_00564144,0,0);
  FUN_0052f5b0(this,0x1f4a,0x47,0x38,s_RB07_00_spr_00564278,1,0);
  FUN_0052f5b0(this,0x1f4b,0x78,0x38,s_RB08_00_spr_0056426c,1,0);
  FUN_0052f5b0(this,0x1f4c,0xa9,0x38,s_RB09_00_spr_00564260,1,0);
  iVar1 = FUN_0052f850(this,0x1f4d,0x33,0x70,s_VERDANA10_fnt_00563e64,DAT_005829cc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f4d,0);
    FUN_0052f9d0(this,0x1f4d,0,0xb4,0,0);
  }
  iVar1 = FUN_0052f690(this,0x1f4e,0x31,0x110,s_VERDANA8_fnt_00563e98,DAT_0058178c,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x1f4e,0,0,0);
    FUN_0052f7a0(this,0x1f4e,2,0xb2,0,0,0xfffe);
  }
  iVar1 = FUN_0052f850(this,0x1f4f,0x32,0xfd,s_VERDANA8_fnt_00563e98,DAT_00581b68);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f4f,0);
    FUN_0052f9d0(this,0x1f4f,0,0,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f50,0x9d,0xfd,s_VERDANA8_fnt_00563e98,s__500000__00564254);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f50,0);
    FUN_0052f9d0(this,0x1f50,1,0x46,0,0);
  }
  return this;
}

