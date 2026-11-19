// rea decompile_all
// name: FUN_0040f1d0
// address: 0x40f1d0
// body: available
// range: 0x40f1d0-0x410731 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl FUN_0040f1d0(int *param_1)

{
  int iVar1;
  void *this;
  
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_00491ef0);
  *param_1 = iVar1;
  this = (void *)FUN_00528040(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  FUN_00531850(this,0x45b,99,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x45c,99,0x13b,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x45d,99,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x45e,99,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x45f,99,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x460,99,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x461,99,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x462,99,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x463,99,0x13b,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x464,99,0x13b,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x465,99,0x13b,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x466,99,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x467,99,0x13b,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x468,99,0x13b,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x469,99,0x13b,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x46a,99,0x13b,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x46b,99,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x46c,0x95,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x46d,0x95,0x13b,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x46e,0x95,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x46f,0x95,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x470,0x95,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x471,0x95,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x472,0x95,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x473,0x95,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x474,0x95,0x13b,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x475,0x95,0x13b,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x476,0x95,0x13b,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x477,0x95,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x478,0x95,0x13b,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x479,0x95,0x13b,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x47a,0x95,0x13b,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x47b,0x95,0x13b,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x47c,0x95,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x47d,199,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x47e,199,0x13b,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x47f,199,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x480,199,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x481,199,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x482,199,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x483,199,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x484,199,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x485,199,0x13b,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x486,199,0x13b,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x487,199,0x13b,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x488,199,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x489,199,0x13b,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x48a,199,0x13b,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x48b,199,0x13b,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x48c,199,0x13b,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x48d,199,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x48e,0x31,0x15e,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x48f,0x31,0x15e,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x490,0x31,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x491,0x31,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x492,0x31,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x493,0x31,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x494,0x31,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x495,0x31,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x496,0x31,0x15e,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x497,0x31,0x15e,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x498,0x31,0x15e,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x499,0x31,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x49a,0x31,0x15e,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x49b,0x31,0x15e,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x49c,0x31,0x15e,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x49d,0x31,0x15e,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x49e,0x31,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x49f,99,0x15e,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x4a0,99,0x15e,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x4a1,99,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x4a2,99,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x4a3,99,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x4a4,99,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x4a5,99,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x4a6,99,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x4a7,99,0x15e,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x4a8,99,0x15e,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x4a9,99,0x15e,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x4aa,99,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x4ab,99,0x15e,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x4ac,99,0x15e,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x4ad,99,0x15e,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x4ae,99,0x15e,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x4af,99,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x4b0,0x95,0x15e,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x4b1,0x95,0x15e,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x4b2,0x95,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x4b3,0x95,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x4b4,0x95,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x4b5,0x95,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x4b6,0x95,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x4b7,0x95,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x4b8,0x95,0x15e,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x4b9,0x95,0x15e,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x4ba,0x95,0x15e,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x4bb,0x95,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x4bc,0x95,0x15e,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x4bd,0x95,0x15e,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x4be,0x95,0x15e,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x4bf,0x95,0x15e,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x4c0,0x95,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x4c1,199,0x15e,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x4c2,199,0x15e,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x4c3,199,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x4c4,199,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x4c5,199,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x4c6,199,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x4c7,199,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x4c8,199,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x4c9,199,0x15e,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x4ca,199,0x15e,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x4cb,199,0x15e,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x4cc,199,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x4cd,199,0x15e,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x4ce,199,0x15e,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x4cf,199,0x15e,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x4d0,199,0x15e,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x4d1,199,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  FUN_00531850(this,0x4d2,0x31,0x13b,s_BEWERTUNG__00_spr_00564018);
  FUN_00531850(this,0x4d3,0x31,0x13b,s_BEWERTUNG__01_spr_00564004);
  FUN_00531850(this,0x4d4,0x31,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  FUN_00531850(this,0x4d5,0x31,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  FUN_00531850(this,0x4d6,0x31,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  FUN_00531850(this,0x4d7,0x31,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  FUN_00531850(this,0x4d8,0x31,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  FUN_00531850(this,0x4d9,0x31,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  FUN_00531850(this,0x4da,0x31,0x13b,s_BEWERTUNG__08_spr_00563f78);
  FUN_00531850(this,0x4db,0x31,0x13b,s_BEWERTUNG__09_spr_00563f64);
  FUN_00531850(this,0x4dc,0x31,0x13b,s_BEWERTUNG__10_spr_00563f50);
  FUN_00531850(this,0x4dd,0x31,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  FUN_00531850(this,0x4de,0x31,0x13b,s_BEWERTUNG__12_spr_00563f28);
  FUN_00531850(this,0x4df,0x31,0x13b,s_BEWERTUNG__13_spr_00563f14);
  FUN_00531850(this,0x4e0,0x31,0x13b,s_BEWERTUNG__14_spr_00563f00);
  FUN_00531850(this,0x4e1,0x31,0x13b,s_BEWERTUNG__15_spr_00563eec);
  FUN_00531850(this,0x4e2,0x31,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  iVar1 = FUN_0052f850(this,0x4e3,0x27,0x130,s_VERDANA7_fnt_00563ec8,DAT_00580bec);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4e3,0);
    FUN_0052f9d0(this,0x4e3,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4e4,0x58,0x130,s_VERDANA7_fnt_00563ec8,DAT_005816d4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4e4,0);
    FUN_0052f9d0(this,0x4e4,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4e5,0x8a,0x130,s_VERDANA7_fnt_00563ec8,DAT_00582974);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4e5,0);
    FUN_0052f9d0(this,0x4e5,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4e6,0xbc,0x130,s_VERDANA7_fnt_00563ec8,DAT_0058234c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4e6,0);
    FUN_0052f9d0(this,0x4e6,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4e7,0x27,0x154,s_VERDANA7_fnt_00563ec8,DAT_00580e64);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4e7,0);
    FUN_0052f9d0(this,0x4e7,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4e8,0x58,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582e08);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4e8,0);
    FUN_0052f9d0(this,0x4e8,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4e9,0x89,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582770);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4e9,0);
    FUN_0052f9d0(this,0x4e9,2,0x32,0,0);
  }
  iVar1 = FUN_0052f850(this,0x4ea,0xba,0x154,s_VERDANA7_fnt_00563ec8,DAT_005810a4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4ea,0);
    FUN_0052f9d0(this,0x4ea,2,0x32,0,0);
  }
  FUN_00531850(this,0x408,0x27,0x129,s_TRENNZEILE_spr_00563eb8);
  FUN_00531850(this,0x409,0x27,0xf2,s_TRENNZEILE_spr_00563eb8);
  FUN_00531850(this,0x429,0x31,0x31,s_TAB04_spr_00564230);
  FUN_00531850(this,0x42b,0x41,0xc1,s_TAB05_spr_00564224);
  iVar1 = FUN_0052f850(this,0x441,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_005825cc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x441,0);
    FUN_0052f9d0(this,0x441,2,0xbe,0,0);
  }
  iVar1 = FUN_0052f850(this,0x442,0x4d,0x21,s_VERDANA10_fnt_00563e64,DAT_0058248c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x442,0);
    FUN_0052f9d0(this,0x442,2,0x78,0,0);
  }
  iVar1 = FUN_0052f850(this,0x443,0x4d,0xa8,s_VERDANA10_fnt_00563e64,DAT_00582d20);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x443,0);
    FUN_0052f9d0(this,0x443,2,0x78,0,0);
  }
  iVar1 = FUN_0052f850(this,0x444,0x3f,0xb6,s_VERDANA7_fnt_00563ec8,&DAT_00564220);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x444,0);
    FUN_0052f9d0(this,0x444,0,0,0,0);
  }
  iVar1 = FUN_0052f850(this,0x445,0x52,0xb6,s_VERDANA7_fnt_00563ec8,&DAT_0056421c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x445,0);
    FUN_0052f9d0(this,0x445,0,0,0,0);
  }
  iVar1 = FUN_0052f850(this,0x446,0x67,0xb6,s_VERDANA7_fnt_00563ec8,&DAT_00564218);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x446,0);
    FUN_0052f9d0(this,0x446,0,0,0,0);
  }
  iVar1 = FUN_0052f850(this,0x447,0x7a,0xb6,s_VERDANA7_fnt_00563ec8,&DAT_00564214);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x447,0);
    FUN_0052f9d0(this,0x447,0,0,0,0);
  }
  iVar1 = FUN_0052f850(this,0x448,0x8b,0xb6,s_VERDANA7_fnt_00563ec8,&DAT_00564210);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x448,0);
    FUN_0052f9d0(this,0x448,0,0,0,0);
  }
  iVar1 = FUN_0052f850(this,0x449,0x9f,0xb6,s_VERDANA7_fnt_00563ec8,&DAT_0056420c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x449,0);
    FUN_0052f9d0(this,0x449,0,0,0,0);
  }
  iVar1 = FUN_0052f850(this,0x44a,0xb3,0xb6,s_VERDANA7_fnt_00563ec8,&DAT_00564208);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x44a,0);
    FUN_0052f9d0(this,0x44a,0,0,0,0);
  }
  iVar1 = FUN_0052f850(this,1099,199,0xb6,s_VERDANA7_fnt_00563ec8,&DAT_00564204);
  if (iVar1 != 0) {
    FUN_0052f910(this,1099,0);
    FUN_0052f9d0(this,1099,0,0,0,0);
  }
  iVar1 = FUN_0052f850(this,0x44c,0xda,0xb6,s_VERDANA7_fnt_00563ec8,&DAT_00564200);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x44c,0);
    FUN_0052f9d0(this,0x44c,0,0,0,0);
  }
  iVar1 = FUN_0052f850(this,0x44d,0x2f,0x117,s_VERDANA8_fnt_00563e98,DAT_005828c4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x44d,0);
    FUN_0052f9d0(this,0x44d,0,0x2d,0,0);
  }
  FUN_0052f5b0(this,0x42c,0x2e,0xb6,s_PB54_00_spr_005641f4,1,0);
  FUN_0052f5b0(this,0x42d,0x2e,0xc5,s_PB55_00_spr_005641e8,1,0);
  FUN_0052f5b0(this,0x42e,0x2e,0xd4,s_PB56_00_spr_005641dc,1,0);
  FUN_0052f5b0(this,0x42f,0x2e,0xe3,s_PB57_00_spr_005641d0,1,0);
  iVar1 = FUN_0052f690(this,0x44f,0x8e,0x112,s_VERDANA8_fnt_00563e98,&DAT_005641c4,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x44f,0,0,0);
    FUN_0052f7a0(this,0x44f,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f850(this,0x4eb,0x57,0x117,s_VERDANA8_fnt_00563e98,s__1232__005641bc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4eb,0);
    FUN_0052f9d0(this,0x4eb,1,0x37,0,0);
  }
  iVar1 = FUN_0052f690(this,0x4ec,0x31,0xfb,s_VERDANA8_fnt_00563e98,&DAT_005641a8,0,
                       s_TEXTPB05__00_spr_00564160);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x4ec,0,0,0);
    FUN_0052f7a0(this,0x4ec,2,0xb4,0,0,0xfffe);
  }
  FUN_00531c60(this,0x4ed,0x41,0xc0,0xa1,0x32,0x10);
  FUN_0052f5b0(this,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  return this;
}

