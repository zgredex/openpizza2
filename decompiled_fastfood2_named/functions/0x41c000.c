// rea decompile_all
// name: FUN_0041c000
// address: 0x41c000
// body: available
// range: 0x41c000-0x41d60d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl FUN_0041c000(int *param_1)

{
  int iVar1;
  void *this;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_0049a1c0);
  *param_1 = iVar1;
  this = (void *)UI_FindWindowByID(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(this,0x458,99,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x459,99,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x45a,99,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x45b,99,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x45c,99,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x45d,99,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x45e,99,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x45f,99,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x460,99,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x461,99,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x462,99,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x463,99,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x464,99,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x465,99,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x466,99,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x467,99,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x468,99,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x469,0x95,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x46a,0x95,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x46b,0x95,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x46c,0x95,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x46d,0x95,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x46e,0x95,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x46f,0x95,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x470,0x95,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x471,0x95,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x472,0x95,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x473,0x95,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x474,0x95,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x475,0x95,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x476,0x95,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x477,0x95,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x478,0x95,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x479,0x95,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x47a,199,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x47b,199,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x47c,199,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x47d,199,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x47e,199,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x47f,199,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x480,199,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x481,199,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x482,199,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x483,199,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x484,199,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x485,199,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x486,199,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x487,199,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x488,199,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x489,199,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x48a,199,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x48b,0x31,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x48c,0x31,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x48d,0x31,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x48e,0x31,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x48f,0x31,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x490,0x31,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x491,0x31,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x492,0x31,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x493,0x31,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x494,0x31,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x495,0x31,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x496,0x31,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x497,0x31,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x498,0x31,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x499,0x31,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x49a,0x31,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x49b,0x31,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x49c,99,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x49d,99,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x49e,99,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x49f,99,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x4a0,99,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x4a1,99,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x4a2,99,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x4a3,99,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x4a4,99,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x4a5,99,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x4a6,99,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x4a7,99,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x4a8,99,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x4a9,99,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x4aa,99,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x4ab,99,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x4ac,99,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x4ad,0x95,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x4ae,0x95,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x4af,0x95,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x4b0,0x95,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x4b1,0x95,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x4b2,0x95,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x4b3,0x95,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x4b4,0x95,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x4b5,0x95,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x4b6,0x95,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x4b7,0x95,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x4b8,0x95,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x4b9,0x95,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x4ba,0x95,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x4bb,0x95,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x4bc,0x95,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x4bd,0x95,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x4be,199,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x4bf,199,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x4c0,199,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x4c1,199,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x4c2,199,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x4c3,199,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x4c4,199,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x4c5,199,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x4c6,199,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x4c7,199,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x4c8,199,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x4c9,199,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x4ca,199,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x4cb,199,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x4cc,199,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x4cd,199,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x4ce,199,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x4cf,0x31,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x4d0,0x31,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x4d1,0x31,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x4d2,0x31,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x4d3,0x31,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x4d4,0x31,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x4d5,0x31,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x4d6,0x31,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x4d7,0x31,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x4d8,0x31,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x4d9,0x31,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x4da,0x31,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x4db,0x31,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x4dc,0x31,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x4dd,0x31,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x4de,0x31,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x4df,0x31,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  iVar1 = UI_AddText(this,0x4e0,0x27,0x130,s_VERDANA7_fnt_00563ec8,DAT_00580bec);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4e0,0);
    FUN_0052f9d0(this,0x4e0,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x4e1,0x58,0x130,s_VERDANA7_fnt_00563ec8,DAT_005816d4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4e1,0);
    FUN_0052f9d0(this,0x4e1,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x4e2,0x8a,0x130,s_VERDANA7_fnt_00563ec8,DAT_00582974);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4e2,0);
    FUN_0052f9d0(this,0x4e2,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x4e3,0xbc,0x130,s_VERDANA7_fnt_00563ec8,DAT_0058234c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4e3,0);
    FUN_0052f9d0(this,0x4e3,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x4e4,0x27,0x154,s_VERDANA7_fnt_00563ec8,DAT_00580e64);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4e4,0);
    FUN_0052f9d0(this,0x4e4,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x4e5,0x58,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582e08);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4e5,0);
    FUN_0052f9d0(this,0x4e5,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x4e6,0x89,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582770);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4e6,0);
    FUN_0052f9d0(this,0x4e6,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x4e7,0xba,0x154,s_VERDANA7_fnt_00563ec8,DAT_005810a4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4e7,0);
    FUN_0052f9d0(this,0x4e7,2,0x32,0,0);
  }
  UI_AddSprite(this,0x408,0x27,0x129,s_TRENNZEILE_spr_00563eb8);
  iVar1 = UI_AddText(this,0x448,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00582e5c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x448,0);
    FUN_0052f9d0(this,0x448,2,0xbe,0,0);
  }
  iVar1 = UI_AddText(this,0x449,0x37,0xe3,s_VERDANA8_fnt_00563e98,DAT_005814d8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x449,0);
    FUN_0052f9d0(this,0x449,0,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x44c,0x37,0xee,s_VERDANA8_fnt_00563e98,DAT_00580f34);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x44c,0);
    FUN_0052f9d0(this,0x44c,0,0x46,0,0);
  }
  iVar1 = FUN_0052fc00(this,0x428,0xdc,0x4b,0x8c,s_SL01_00_spr_0056448c,0,1);
  if (iVar1 != 0) {
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    FUN_0052fcc0(this,0x428,&local_10);
  }
  UI_AddImage(this,0x431,0x6c,0x23,s_PB06_00_spr_00564a5c,1,0);
  UI_AddImage(this,0x433,0x8b,0x23,s_PB07_00_spr_00564a50,1,0);
  UI_AddImage(this,0x434,0xc9,0x23,s_PB11_00_spr_00564a44,1,0);
  UI_AddImage(this,0x4eb,0x2e,0x23,s_PB07x__00_spr_00564a34,1,0);
  UI_AddImage(this,0x4ec,0x4d,0x23,s_PB07y__00_spr_00564a24,1,0);
  UI_AddImage(this,0x435,0xaa,0x23,s_PB09_00_spr_00564a18,1,0);
  iVar1 = FUN_0052f690(this,0x4e8,0x31,0xfb,s_VERDANA8_fnt_00563e98,&DAT_00564a04,0,
                       s_TEXTPB05__00_spr_00564160);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x4e8,0,0,0);
    FUN_0052f7a0(this,0x4e8,2,0xb2,0,0,0xfffe);
  }
  iVar1 = UI_AddText(this,0x4e9,0x95,0xe3,s_VERDANA8_fnt_00563e98,s__34234__005649fc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4e9,0);
    FUN_0052f9d0(this,0x4e9,1,0x4b,0,0);
  }
  iVar1 = UI_AddText(this,0x4ea,0x94,0xee,s_VERDANA8_fnt_00563e98,&DAT_005649f4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4ea,0);
    FUN_0052f9d0(this,0x4ea,1,0x4b,0,0);
  }
  UI_AddImage(this,0x4ed,0x3e,0x44,s_ZUTABPB__00_spr_00564180,1,0);
  UI_AddImage(this,0x4ee,0x6e,0x44,s_ZUTABPB__00_spr_00564180,1,0);
  UI_AddImage(this,0x4ef,0x9e,0x44,s_ZUTABPB__00_spr_00564180,1,0);
  UI_AddImage(this,0x4f0,0x3e,0x6a,s_ZUTABPB__00_spr_00564180,1,0);
  UI_AddImage(this,0x4f1,0x6e,0x6a,s_ZUTABPB__00_spr_00564180,1,0);
  UI_AddImage(this,0x4f2,0x9e,0x6a,s_ZUTABPB__00_spr_00564180,1,0);
  UI_AddImage(this,0x4f3,0x3e,0x90,s_ZUTABPB__00_spr_00564180,1,0);
  UI_AddImage(this,0x4f4,0x6e,0x90,s_ZUTABPB__00_spr_00564180,1,0);
  UI_AddImage(this,0x4f5,0x9e,0x90,s_ZUTABPB__00_spr_00564180,1,0);
  UI_AddImage(this,0x4f6,0x3e,0xb6,s_ZUTABPB__00_spr_00564180,1,0);
  UI_AddImage(this,0x4f8,0x9e,0xb6,s_ZUTABPB__00_spr_00564180,1,0);
  iVar1 = UI_AddText(this,0x4f9,0x8f,0xd8,s_VERDANA8_fnt_00563e98,s__Normal_005649ec);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4f9,0);
    FUN_0052f9d0(this,0x4f9,1,0x50,0xffff,0);
  }
  iVar1 = UI_AddText(this,0x4fa,0x37,0xd8,s_VERDANA8_fnt_00563e98,s__Tomate_005649e4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x4fa,0);
    FUN_0052f9d0(this,0x4fa,0,0x73,0xffff,0);
  }
  iVar1 = FUN_0052f690(this,0x507,0x30,0x112,s_VERDANA8_fnt_00563e98,DAT_005825ec,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x507,0,0,0);
    FUN_0052f7a0(this,0x507,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f690(this,0x508,0x8e,0x112,s_VERDANA8_fnt_00563e98,DAT_00581460,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x508,0,0,0);
    FUN_0052f7a0(this,0x508,2,0x54,0,0,0xfffe);
  }
  UI_AddImage(this,0x4f7,0x6e,0xb6,s_ZUTABPB__00_spr_00564180,1,0);
  UI_AddSprite(this,0x509,0x3e,0x44,s_ZMI_13_spr_005649d8);
  UI_AddSprite(this,0x50a,0x6d,0x45,s_ZMI_14_spr_005649cc);
  UI_AddSprite(this,0x50b,0x9e,0x45,s_ZMI_15_spr_005649c0);
  UI_AddSprite(this,0x50c,0x3d,0x6b,s_ZMI_06_spr_005649b4);
  UI_AddSprite(this,0x50d,0x6d,0x6a,s_ZMI_07_spr_005649a8);
  UI_AddSprite(this,0x50e,0x9d,0x6b,s_ZMI_08_spr_0056499c);
  UI_AddSprite(this,0x50f,0x3d,0x90,s_ZMI_03_spr_00564990);
  UI_AddSprite(this,0x510,0x6e,0x91,s_ZMI_01_spr_00564984);
  UI_AddSprite(this,0x511,0x9e,0x92,s_ZMI_02_spr_00564978);
  UI_AddSprite(this,0x512,0x3e,0xb7,s_ZMI_10_spr_0056496c);
  UI_AddSprite(this,0x513,0x6d,0xb7,s_ZMI_09_spr_00564960);
  UI_AddSprite(this,0x514,0x9e,0xb6,s_ZMI_17_spr_00564954);
  UI_AddImage(this,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  return this;
}

