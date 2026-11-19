// rea decompile_all
// name: SubMenu_BuildBranchAdvertising
// address: 0x418d60
// body: available
// range: 0x418d60-0x41a2a3 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl SubMenu_BuildBranchAdvertising(int *param_1)

{
  int iVar1;
  void *this;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
                    /* Builds the branch advertising page. */
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_00497410);
  *param_1 = iVar1;
  this = (void *)FUN_00528040(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  FUN_00531850(this,0x492,99,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x493,99,0x13b,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x494,99,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x495,99,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x496,99,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x497,99,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x498,99,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x499,99,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x49a,99,0x13b,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x49b,99,0x13b,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x49c,99,0x13b,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x49d,99,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x49e,99,0x13b,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x49f,99,0x13b,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x4a0,99,0x13b,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x4a1,99,0x13b,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x4a2,99,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x4a3,0x95,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x4a4,0x95,0x13b,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x4a5,0x95,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x4a6,0x95,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x4a7,0x95,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x4a8,0x95,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x4a9,0x95,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x4aa,0x95,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x4ab,0x95,0x13b,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x4ac,0x95,0x13b,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x4ad,0x95,0x13b,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x4ae,0x95,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x4af,0x95,0x13b,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x4b0,0x95,0x13b,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x4b1,0x95,0x13b,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x4b2,0x95,0x13b,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x4b3,0x95,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x4b4,199,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x4b5,199,0x13b,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x4b6,199,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x4b7,199,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x4b8,199,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x4b9,199,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x4ba,199,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x4bb,199,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x4bc,199,0x13b,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x4bd,199,0x13b,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x4be,199,0x13b,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x4bf,199,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x4c0,199,0x13b,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x4c1,199,0x13b,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x4c2,199,0x13b,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x4c3,199,0x13b,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x4c4,199,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x4c5,0x31,0x15e,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x4c6,0x31,0x15e,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x4c7,0x31,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x4c8,0x31,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x4c9,0x31,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x4ca,0x31,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x4cb,0x31,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x4cc,0x31,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x4cd,0x31,0x15e,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x4ce,0x31,0x15e,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x4cf,0x31,0x15e,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x4d0,0x31,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x4d1,0x31,0x15e,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x4d2,0x31,0x15e,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x4d3,0x31,0x15e,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x4d4,0x31,0x15e,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x4d5,0x31,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x4d6,99,0x15e,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x4d7,99,0x15e,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x4d8,99,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x4d9,99,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x4da,99,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x4db,99,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x4dc,99,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x4dd,99,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x4de,99,0x15e,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x4df,99,0x15e,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x4e0,99,0x15e,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x4e1,99,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x4e2,99,0x15e,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x4e3,99,0x15e,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x4e4,99,0x15e,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x4e5,99,0x15e,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x4e6,99,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x4e7,0x95,0x15e,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x4e8,0x95,0x15e,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x4e9,0x95,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x4ea,0x95,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x4eb,0x95,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x4ec,0x95,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x4ed,0x95,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x4ee,0x95,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x4ef,0x95,0x15e,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x4f0,0x95,0x15e,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x4f1,0x95,0x15e,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x4f2,0x95,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x4f3,0x95,0x15e,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x4f4,0x95,0x15e,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x4f5,0x95,0x15e,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x4f6,0x95,0x15e,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x4f7,0x95,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x4f8,199,0x15e,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x4f9,199,0x15e,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x4fa,199,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x4fb,199,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x4fc,199,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x4fd,199,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x4fe,199,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x4ff,199,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x500,199,0x15e,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x501,199,0x15e,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x502,199,0x15e,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x503,199,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x504,199,0x15e,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x505,199,0x15e,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x506,199,0x15e,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x507,199,0x15e,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x508,199,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x509,0x31,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x50a,0x31,0x13b,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x50b,0x31,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x50c,0x31,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x50d,0x31,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x50e,0x31,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x50f,0x31,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x510,0x31,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x511,0x31,0x13b,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x512,0x31,0x13b,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x513,0x31,0x13b,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x514,0x31,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x515,0x31,0x13b,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x516,0x31,0x13b,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x517,0x31,0x13b,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x518,0x31,0x13b,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x519,0x31,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  iVar1 = FUN_0052f850(this,0x51a,0x27,0x130,s_VERDANA7_fnt_00563ec8,DAT_00580bec);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x51a,0);
    FUN_0052f9d0(this,0x51a,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x51b,0x58,0x130,s_VERDANA7_fnt_00563ec8,DAT_005816d4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x51b,0);
    FUN_0052f9d0(this,0x51b,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x51c,0x8a,0x130,s_VERDANA7_fnt_00563ec8,DAT_00582974);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x51c,0);
    FUN_0052f9d0(this,0x51c,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x51d,0xbc,0x130,s_VERDANA7_fnt_00563ec8,DAT_0058234c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x51d,0);
    FUN_0052f9d0(this,0x51d,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x51e,0x27,0x154,s_VERDANA7_fnt_00563ec8,DAT_00580e64);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x51e,0);
    FUN_0052f9d0(this,0x51e,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x51f,0x58,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582e08);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x51f,0);
    FUN_0052f9d0(this,0x51f,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x520,0x89,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582770);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x520,0);
    FUN_0052f9d0(this,0x520,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x521,0xba,0x154,s_VERDANA7_fnt_00563ec8,DAT_005810a4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x521,0);
    FUN_0052f9d0(this,0x521,2,0x32,0,0);
  }
  FUN_00531850(this,0x408,0x27,0x129,s_TRENNZEILE_spr_00563eb8);
  FUN_00531850(this,0x409,0x27,0xf2,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x46e,0x2a,5,s_TIMESFONT_fnt_00563ea8,DAT_0058240c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x46e,0);
    FUN_0052f9d0(this,0x46e,2,0xbe,0,0);
  }
  iVar1 = FUN_0052f850(this,0x46f,0x2e,0x26,s_VERDANA10_fnt_00563e64,DAT_00580da8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x46f,0);
    FUN_0052f9d0(this,0x46f,0,0xbe,0,0);
  }
  iVar1 = FUN_0052f850(this,0x470,0x2e,0x55,s_VERDANA10_fnt_00563e64,DAT_00582b90);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x470,0);
    FUN_0052f9d0(this,0x470,0,0xbe,0,0);
  }
  iVar1 = FUN_0052f850(this,0x471,0x2e,0x94,s_VERDANA10_fnt_00563e64,DAT_005812f8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x471,0);
    FUN_0052f9d0(this,0x471,0,0xbe,0,0);
  }
  iVar1 = FUN_0052f850(this,0x472,0x2e,0xca,s_VERDANA8_fnt_00563e98,DAT_00582e54);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x472,0);
    FUN_0052f9d0(this,0x472,0,0xbe,0,0);
  }
  FUN_0052f5b0(this,0x43a,0x36,0x66,s_PB25_00_spr_005646e8,1,0);
  FUN_0052f5b0(this,0x43b,0x62,0x66,s_PB28_00_spr_005646dc,1,0);
  FUN_0052f5b0(this,0x43c,0x8e,0x66,s_PB30_00_spr_005646d0,1,0);
  FUN_0052f5b0(this,0x43d,0xba,0x66,s_PB32_00_spr_005646c4,1,0);
  FUN_0052f5b0(this,0x442,0x2c,0x36,s_PB22_00_spr_00564174,0,0);
  iVar1 = UI_AddTextButton(this,0x482,0x40,0x37,s_VERDANA8_fnt_00563e98,
                           s__textbutton_default_005646b0,0,s_TEXTPB05__00_spr_00564160);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x482,0,0,0);
    FUN_0052f7a0(this,0x482,2,0x93,0,0,0xfffe);
  }
  FUN_0052f5b0(this,0x444,0xcd,0x36,s_PB24_00_spr_00564144,0,0);
  FUN_0052f5b0(this,0x48a,0x2c,0xa4,s_PB22_00_spr_00564174,0,0);
  iVar1 = UI_AddTextButton(this,0x48b,0x40,0xa5,s_VERDANA8_fnt_00563e98,
                           s__textbutton_default_005646b0,0,s_TEXTPB05__00_spr_00564160);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x48b,0,0,0);
    FUN_0052f7a0(this,0x48b,2,0x93,0,0,0xfffe);
  }
  FUN_0052f5b0(this,0x48c,0xcd,0xa4,s_PB24_00_spr_00564144,0,0);
  FUN_0052f5b0(this,0x48d,0x2c,0xd7,s_PB22_00_spr_00564174,0,0);
  iVar1 = UI_AddTextButton(this,0x48e,0x40,0xd8,s_VERDANA8_fnt_00563e98,
                           s__textbutton_default_005646b0,0,s_TEXTPB05__00_spr_00564160);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x48e,0,0,0);
    FUN_0052f7a0(this,0x48e,2,0x93,0,0,0xfffe);
  }
  FUN_0052f5b0(this,0x48f,0xcd,0xd7,s_PB24_00_spr_00564144,0,0);
  FUN_0052f5b0(this,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  iVar1 = FUN_0052f850(this,0x1f41,0x32,0xf9,s_VERDANA8_fnt_00563e98,DAT_00582a94);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f41,0);
    FUN_0052f9d0(this,0x1f41,0,0,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f42,0x32,0x106,s_VERDANA8_fnt_00563e98,DAT_005812e4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f42,0);
    FUN_0052f9d0(this,0x1f42,0,0,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f43,0x85,0x115,s_VERDANA10_fnt_00563e64,&DAT_005646ac);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f43,0);
    FUN_0052f9d0(this,0x1f43,0,0,0,0);
  }
  iVar1 = UI_CreateSlider(this,0x1f44,0x37,0x11e,0x4b,s_SLHOR01_00_spr_00564660,0,0);
  if (iVar1 != 0) {
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    FUN_0052fcc0(this,0x1f44,&local_10);
  }
  iVar1 = FUN_0052f850(this,0x1f45,0x9d,0xf9,s_VERDANA8_fnt_00563e98,s__500000__00564254);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f45,0);
    FUN_0052f9d0(this,0x1f45,1,0x46,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f46,0xb5,0x106,s_VERDANA8_fnt_00563e98,s___53__005646a4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f46,0);
    FUN_0052f9d0(this,0x1f46,1,0x2d,0,0);
  }
  iVar1 = UI_AddTextButton(this,0x1f47,0x8e,0x112,s_VERDANA8_fnt_00563e98,s__Starten_00564698,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x1f47,0,0,0);
    FUN_0052f7a0(this,0x1f47,2,0x54,0,0,0xfffe);
  }
  return this;
}

