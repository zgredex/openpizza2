// rea decompile_all
// name: FUN_004240a0
// address: 0x4240a0
// body: available
// range: 0x4240a0-0x4258be inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl FUN_004240a0(int *param_1)

{
  int iVar1;
  void *this;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_0049ef10);
  *param_1 = iVar1;
  this = (void *)UI_FindWindowByID(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  FUN_00531850(this,0x460,99,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x461,99,0x13b,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x462,99,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x463,99,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x464,99,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x465,99,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x466,99,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x467,99,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x468,99,0x13b,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x469,99,0x13b,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x46a,99,0x13b,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x46b,99,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x46c,99,0x13b,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x46d,99,0x13b,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x46e,99,0x13b,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x46f,99,0x13b,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x470,99,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x471,0x95,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x472,0x95,0x13b,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x473,0x95,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x474,0x95,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x475,0x95,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x476,0x95,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x477,0x95,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x478,0x95,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x479,0x95,0x13b,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x47a,0x95,0x13b,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x47b,0x95,0x13b,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x47c,0x95,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x47d,0x95,0x13b,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x47e,0x95,0x13b,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x47f,0x95,0x13b,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x480,0x95,0x13b,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x481,0x95,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x482,199,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x483,199,0x13b,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x484,199,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x485,199,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x486,199,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x487,199,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x488,199,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x489,199,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x48a,199,0x13b,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x48b,199,0x13b,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x48c,199,0x13b,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x48d,199,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x48e,199,0x13b,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x48f,199,0x13b,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x490,199,0x13b,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x491,199,0x13b,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x492,199,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x493,0x31,0x15e,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x494,0x31,0x15e,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x495,0x31,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x496,0x31,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x497,0x31,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x498,0x31,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x499,0x31,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x49a,0x31,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x49b,0x31,0x15e,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x49c,0x31,0x15e,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x49d,0x31,0x15e,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x49e,0x31,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x49f,0x31,0x15e,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x4a0,0x31,0x15e,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x4a1,0x31,0x15e,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x4a2,0x31,0x15e,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x4a3,0x31,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x4a4,99,0x15e,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x4a5,99,0x15e,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x4a6,99,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x4a7,99,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x4a8,99,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x4a9,99,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x4aa,99,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x4ab,99,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x4ac,99,0x15e,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x4ad,99,0x15e,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x4ae,99,0x15e,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x4af,99,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x4b0,99,0x15e,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x4b1,99,0x15e,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x4b2,99,0x15e,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x4b3,99,0x15e,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x4b4,99,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x4b5,0x95,0x15e,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x4b6,0x95,0x15e,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x4b7,0x95,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x4b8,0x95,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x4b9,0x95,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x4ba,0x95,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x4bb,0x95,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x4bc,0x95,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x4bd,0x95,0x15e,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x4be,0x95,0x15e,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x4bf,0x95,0x15e,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x4c0,0x95,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x4c1,0x95,0x15e,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x4c2,0x95,0x15e,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x4c3,0x95,0x15e,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x4c4,0x95,0x15e,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x4c5,0x95,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x4c6,199,0x15e,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x4c7,199,0x15e,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x4c8,199,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x4c9,199,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x4ca,199,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x4cb,199,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x4cc,199,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x4cd,199,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x4ce,199,0x15e,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x4cf,199,0x15e,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x4d0,199,0x15e,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x4d1,199,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x4d2,199,0x15e,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x4d3,199,0x15e,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x4d4,199,0x15e,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x4d5,199,0x15e,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x4d6,199,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x4d7,0x31,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x4d8,0x31,0x13b,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x4d9,0x31,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x4da,0x31,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x4db,0x31,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x4dc,0x31,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x4dd,0x31,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x4de,0x31,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x4df,0x31,0x13b,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x4e0,0x31,0x13b,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x4e1,0x31,0x13b,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x4e2,0x31,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x4e3,0x31,0x13b,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x4e4,0x31,0x13b,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x4e5,0x31,0x13b,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x4e6,0x31,0x13b,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x4e7,0x31,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  iVar1 = FUN_0052f850(this,0x4e8,0x27,0x130,s_VERDANA7_fnt_00563ec8,DAT_00580bec);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4e8,0);
    FUN_0052f9d0(this,0x4e8,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4e9,0x58,0x130,s_VERDANA7_fnt_00563ec8,DAT_005816d4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4e9,0);
    FUN_0052f9d0(this,0x4e9,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4ea,0x8a,0x130,s_VERDANA7_fnt_00563ec8,DAT_00582974);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4ea,0);
    FUN_0052f9d0(this,0x4ea,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4eb,0xbc,0x130,s_VERDANA7_fnt_00563ec8,DAT_0058234c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4eb,0);
    FUN_0052f9d0(this,0x4eb,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4ec,0x27,0x154,s_VERDANA7_fnt_00563ec8,DAT_00580e64);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4ec,0);
    FUN_0052f9d0(this,0x4ec,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4ed,0x58,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582e08);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4ed,0);
    FUN_0052f9d0(this,0x4ed,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4ee,0x89,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582770);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4ee,0);
    FUN_0052f9d0(this,0x4ee,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4ef,0xba,0x154,s_VERDANA7_fnt_00563ec8,DAT_005810a4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4ef,0);
    FUN_0052f9d0(this,0x4ef,2,0x32,0,0);
  }
  FUN_00531850(this,0x440,0x2f,0x1e,s_RAHMEN03_spr_00564bf8);
  FUN_00531850(this,0x408,0x27,0x129,s_TRENNZEILE_spr_00563eb8);
  FUN_00531850(this,0x409,0x27,0xf2,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x451,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_0058162c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x451,0);
    FUN_0052f9d0(this,0x451,2,0xbe,0,0);
  }
  iVar1 = FUN_0052fc00(this,0x428,0xdd,0x2a,0xc6,s_SL01_00_spr_0056448c,0,1);
  if (iVar1 != 0) {
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    FUN_0052fcc0(this,0x428,&local_10);
  }
  iVar1 = FUN_0052f850(this,0x4f1,0x34,0x24,s_VERDANA10_fnt_00563e64,s__Tomaten_00564be4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4f1,0);
    FUN_0052f9d0(this,0x4f1,0,0x73,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4f2,0x93,0x24,s_VERDANA10_fnt_00563e64,&DAT_00564bdc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4f2,0);
    FUN_0052f9d0(this,0x4f2,1,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4f3,0x93,0x37,s_VERDANA10_fnt_00563e64,&DAT_00564bdc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4f3,0);
    FUN_0052f9d0(this,0x4f3,1,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4f4,0x34,0x37,s_VERDANA10_fnt_00563e64,s__Tomaten_00564be4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4f4,0);
    FUN_0052f9d0(this,0x4f4,0,0x73,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4f5,0x93,0x5d,s_VERDANA10_fnt_00563e64,&DAT_00564bdc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4f5,0);
    FUN_0052f9d0(this,0x4f5,1,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4f6,0x34,0x5d,s_VERDANA10_fnt_00563e64,s__Tomaten_00564be4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4f6,0);
    FUN_0052f9d0(this,0x4f6,0,0x73,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4f7,0x34,0x4a,s_VERDANA10_fnt_00563e64,s__Tomaten_00564be4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4f7,0);
    FUN_0052f9d0(this,0x4f7,0,0x73,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4f8,0x93,0x4a,s_VERDANA10_fnt_00563e64,&DAT_00564bdc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4f8,0);
    FUN_0052f9d0(this,0x4f8,1,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4f9,0x34,0xa9,s_VERDANA10_fnt_00563e64,s__Tomaten_00564be4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4f9,0);
    FUN_0052f9d0(this,0x4f9,0,0x73,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4fa,0x93,0xa9,s_VERDANA10_fnt_00563e64,&DAT_00564bdc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4fa,0);
    FUN_0052f9d0(this,0x4fa,1,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4fb,0x93,0x96,s_VERDANA10_fnt_00563e64,&DAT_00564bdc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4fb,0);
    FUN_0052f9d0(this,0x4fb,1,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4fc,0x34,0x96,s_VERDANA10_fnt_00563e64,s__Tomaten_00564be4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4fc,0);
    FUN_0052f9d0(this,0x4fc,0,0x73,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4fd,0x34,0x83,s_VERDANA10_fnt_00563e64,s__Tomaten_00564be4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4fd,0);
    FUN_0052f9d0(this,0x4fd,0,0x73,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4fe,0x93,0x83,s_VERDANA10_fnt_00563e64,&DAT_00564bdc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4fe,0);
    FUN_0052f9d0(this,0x4fe,1,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4ff,0x93,0x70,s_VERDANA10_fnt_00563e64,&DAT_00564bdc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4ff,0);
    FUN_0052f9d0(this,0x4ff,1,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x500,0x34,0x70,s_VERDANA10_fnt_00563e64,s__Tomaten_00564be4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x500,0);
    FUN_0052f9d0(this,0x500,0,0x73,0,0);
  }
  iVar1 = FUN_0052f850(this,0x501,0x34,0xbc,s_VERDANA10_fnt_00563e64,s__Tomaten_00564be4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x501,0);
    FUN_0052f9d0(this,0x501,0,0x73,0,0);
  }
  iVar1 = FUN_0052f850(this,0x502,0x93,0xbc,s_VERDANA10_fnt_00563e64,&DAT_00564bdc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x502,0);
    FUN_0052f9d0(this,0x502,1,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x503,0x93,0xcf,s_VERDANA10_fnt_00563e64,&DAT_00564bdc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x503,0);
    FUN_0052f9d0(this,0x503,1,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x504,0x93,0xe2,s_VERDANA10_fnt_00563e64,&DAT_00564bdc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x504,0);
    FUN_0052f9d0(this,0x504,1,0x3c,0,0);
  }
  iVar1 = FUN_0052f850(this,0x505,0x34,0xe2,s_VERDANA10_fnt_00563e64,s__Tomaten_00564be4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x505,0);
    FUN_0052f9d0(this,0x505,0,0x73,0,0);
  }
  iVar1 = FUN_0052f850(this,0x506,0x34,0xcf,s_VERDANA10_fnt_00563e64,s__Tomaten_00564be4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x506,0);
    FUN_0052f9d0(this,0x506,0,0x73,0,0);
  }
  iVar1 = FUN_0052f690(this,0x507,0x8e,0xfc,s_VERDANA8_fnt_00563e98,DAT_00580e38,0,
                       s_TEXTPB04__00_spr_00564928);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x507,0,0,0);
    FUN_0052f7a0(this,0x507,2,0x54,0,0,0xfffe);
  }
  FUN_0052f5b0(this,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  iVar1 = FUN_0052f850(this,0x1f41,0x32,0xfa,s_VERDANA7_fnt_00563ec8,DAT_00580eac);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f41,0);
    FUN_0052f9d0(this,0x1f41,0,0x50,0xffff,0);
  }
  iVar1 = FUN_0052f850(this,0x1f42,0x51,0x105,s_VERDANA7_fnt_00563ec8,s__3243__00564bf0);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f42,0);
    FUN_0052f9d0(this,0x1f42,1,0x32,0,0);
  }
  FUN_0052f5b0(this,0x1f43,0x30,0x113,s_PB05x__00_spr_00564630,1,0);
  FUN_0052f5b0(this,0x1f44,0x82,0x113,s_PB05x__00_spr_00564630,1,0);
  iVar1 = FUN_0052f850(this,0x1f45,0x49,0x117,s_VERDANA7_fnt_00563ec8,DAT_0058219c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f45,0);
    FUN_0052f9d0(this,0x1f45,0,0x37,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f46,0x9b,0x117,s_VERDANA7_fnt_00563ec8,DAT_00580eac);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f46,0);
    FUN_0052f9d0(this,0x1f46,0,0x4b,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f47,0x32,0x105,s_VERDANA7_fnt_00563ec8,DAT_00581874);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f47,0);
    FUN_0052f9d0(this,0x1f47,0,0x32,0xffff,0);
  }
  return this;
}

