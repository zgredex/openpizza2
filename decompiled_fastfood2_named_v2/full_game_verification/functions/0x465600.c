// rea decompile_all
// name: SubMenu_BuildPosterAdvertisingSetup
// address: 0x465600
// body: available
// range: 0x465600-0x466b00 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl SubMenu_BuildPosterAdvertisingSetup(int *param_1)

{
  int iVar1;
  void *this;
  
                    /* Builds the poster-advertising setup page. */
  iVar1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004c3c90);
  *param_1 = iVar1;
  this = (void *)UI_FindWindowByID(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(this,0x482,99,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x483,99,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x484,99,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x485,99,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x486,99,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x487,99,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x488,99,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x489,99,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x48a,99,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x48b,99,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x48c,99,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x48d,99,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x48e,99,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x48f,99,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x490,99,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x491,99,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x492,99,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x493,0x95,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x494,0x95,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x495,0x95,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x496,0x95,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x497,0x95,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x498,0x95,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x499,0x95,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x49a,0x95,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x49b,0x95,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x49c,0x95,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x49d,0x95,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x49e,0x95,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x49f,0x95,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x4a0,0x95,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x4a1,0x95,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x4a2,0x95,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x4a3,0x95,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x4a4,199,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x4a5,199,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x4a6,199,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x4a7,199,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x4a8,199,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x4a9,199,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x4aa,199,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x4ab,199,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x4ac,199,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x4ad,199,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x4ae,199,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x4af,199,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x4b0,199,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x4b1,199,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x4b2,199,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x4b3,199,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x4b4,199,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x4b5,0x31,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x4b6,0x31,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x4b7,0x31,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x4b8,0x31,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x4b9,0x31,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x4ba,0x31,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x4bb,0x31,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x4bc,0x31,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x4bd,0x31,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x4be,0x31,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x4bf,0x31,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x4c0,0x31,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x4c1,0x31,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x4c2,0x31,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x4c3,0x31,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x4c4,0x31,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x4c5,0x31,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x4c6,99,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x4c7,99,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x4c8,99,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x4c9,99,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x4ca,99,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x4cb,99,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x4cc,99,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x4cd,99,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x4ce,99,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x4cf,99,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x4d0,99,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x4d1,99,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x4d2,99,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x4d3,99,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x4d4,99,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x4d5,99,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x4d6,99,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x4d7,0x95,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x4d8,0x95,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x4d9,0x95,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x4da,0x95,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x4db,0x95,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x4dc,0x95,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x4dd,0x95,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x4de,0x95,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x4df,0x95,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x4e0,0x95,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x4e1,0x95,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x4e2,0x95,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x4e3,0x95,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x4e4,0x95,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x4e5,0x95,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x4e6,0x95,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x4e7,0x95,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x4e8,199,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x4e9,199,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x4ea,199,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x4eb,199,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x4ec,199,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x4ed,199,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x4ee,199,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x4ef,199,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x4f0,199,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x4f1,199,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x4f2,199,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x4f3,199,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x4f4,199,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x4f5,199,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x4f6,199,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x4f7,199,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x4f8,199,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x4f9,0x31,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x4fa,0x31,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x4fb,0x31,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x4fc,0x31,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x4fd,0x31,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x4fe,0x31,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x4ff,0x31,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x500,0x31,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x501,0x31,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x502,0x31,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x503,0x31,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x504,0x31,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x505,0x31,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x506,0x31,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x507,0x31,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x508,0x31,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x509,0x31,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  iVar1 = UI_AddText(this,0x50a,0x27,0x130,s_VERDANA7_fnt_00563ec8,DAT_00580bec);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x50a,0);
    Window_GadgetNotify_Text_SetLayout(this,0x50a,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x50b,0x58,0x130,s_VERDANA7_fnt_00563ec8,DAT_005816d4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x50b,0);
    Window_GadgetNotify_Text_SetLayout(this,0x50b,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x50c,0x8a,0x130,s_VERDANA7_fnt_00563ec8,DAT_00582974);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x50c,0);
    Window_GadgetNotify_Text_SetLayout(this,0x50c,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x50d,0xbc,0x130,s_VERDANA7_fnt_00563ec8,DAT_0058234c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x50d,0);
    Window_GadgetNotify_Text_SetLayout(this,0x50d,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x50e,0x27,0x154,s_VERDANA7_fnt_00563ec8,DAT_00580e64);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x50e,0);
    Window_GadgetNotify_Text_SetLayout(this,0x50e,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x50f,0x58,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582e08);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x50f,0);
    Window_GadgetNotify_Text_SetLayout(this,0x50f,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x510,0x89,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582770);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x510,0);
    Window_GadgetNotify_Text_SetLayout(this,0x510,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x511,0xba,0x154,s_VERDANA7_fnt_00563ec8,DAT_005810a4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x511,0);
    Window_GadgetNotify_Text_SetLayout(this,0x511,2,0x32,0,0);
  }
  UI_AddSprite(this,0x408,0x27,0x129,s_TRENNZEILE_spr_00563eb8);
  iVar1 = UI_AddText(this,0x46e,0x2a,5,s_TIMESFONT_fnt_00563ea8,DAT_00581658);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x46e,0);
    Window_GadgetNotify_Text_SetLayout(this,0x46e,2,0xbe,0,0);
  }
  iVar1 = UI_AddText(this,0x46f,0x2e,0x26,s_VERDANA10_fnt_00563e64,DAT_00580da8);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x46f,0);
    Window_GadgetNotify_Text_SetLayout(this,0x46f,0,0xb9,0,0);
  }
  iVar1 = UI_AddText(this,0x470,0x2e,0x55,s_VERDANA10_fnt_00563e64,DAT_00582b90);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x470,0);
    Window_GadgetNotify_Text_SetLayout(this,0x470,0,0xb9,0,0);
  }
  iVar1 = UI_AddText(this,0x471,0x2e,0x94,s_VERDANA10_fnt_00563e64,DAT_005812f8);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x471,0);
    Window_GadgetNotify_Text_SetLayout(this,0x471,0,0xb9,0,0);
  }
  iVar1 = UI_AddText(this,0x472,0x2e,0xca,s_VERDANA8_fnt_00563e98,DAT_00582e54);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x472,0);
    Window_GadgetNotify_Text_SetLayout(this,0x472,0,0xb9,0,0);
  }
  UI_AddImage(this,0x43a,0x36,0x66,s_PB25_00_spr_005646e8,1,0);
  UI_AddImage(this,0x43b,0x62,0x66,s_PB28_00_spr_005646dc,1,0);
  UI_AddImage(this,0x43c,0x8e,0x66,s_PB30_00_spr_005646d0,1,0);
  UI_AddImage(this,0x442,0x2c,0x36,s_PB22_00_spr_00564174,0,0);
  iVar1 = UI_AddTextButton(this,0x512,0x40,0x37,s_VERDANA8_fnt_00563e98,s__Kein_Image_00566a10,0,
                           s_TEXTPB05__00_spr_00564160);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x512,0,0,0);
    Gadget_SetButtonTextLayout(this,0x512,2,0x93,0,0,0xfffe);
  }
  UI_AddImage(this,0x43d,0xba,0x66,s_PB32_00_spr_005646c4,1,0);
  UI_AddImage(this,0x444,0xcd,0x36,s_PB24_00_spr_00564144,0,0);
  UI_AddImage(this,0x513,0x2c,0xa4,s_PB22_00_spr_00564174,0,0);
  iVar1 = UI_AddTextButton(this,0x514,0x40,0xa5,s_VERDANA8_fnt_00563e98,s__Keine_Zutat_00566a00,0,
                           s_TEXTPB05__00_spr_00564160);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x514,0,0,0);
    Gadget_SetButtonTextLayout(this,0x514,2,0x93,0,0,0xfffe);
  }
  UI_AddImage(this,0x515,0xcd,0xa4,s_PB24_00_spr_00564144,0,0);
  UI_AddImage(this,0x516,0x2c,0xd7,s_PB22_00_spr_00564174,0,0);
  iVar1 = UI_AddTextButton(this,0x517,0x40,0xd8,s_VERDANA8_fnt_00563e98,s__Kein_Vergleich_005669f0,0
                           ,s_TEXTPB05__00_spr_00564160);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x517,0,0,0);
    Gadget_SetButtonTextLayout(this,0x517,2,0x93,0,0,0xfffe);
  }
  UI_AddImage(this,0x518,0xcd,0xd7,s_PB24_00_spr_00564144,0,0);
  iVar1 = UI_AddTextButton(this,0x519,0x8e,0x112,s_VERDANA8_fnt_00563e98,DAT_00582e44,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x519,0,0,0);
    Gadget_SetButtonTextLayout(this,0x519,2,0x54,0,0,0xfffe);
  }
  iVar1 = UI_AddText(this,0x51a,0x33,0x110,s_VERDANA8_fnt_00563e98,DAT_00582548);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x51a,0);
    Window_GadgetNotify_Text_SetLayout(this,0x51a,0,0x55,0,0);
  }
  iVar1 = UI_AddText(this,0x51b,0x33,0x11c,s_VERDANA8_fnt_00563e98,s__3500__005669e8);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x51b,0);
    Window_GadgetNotify_Text_SetLayout(this,0x51b,1,0x5a,0,0);
  }
  UI_AddImage(this,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  UI_AddImage(this,0x1f43,0x2c,0xf4,s_PB22_00_spr_00564174,0,0);
  iVar1 = UI_AddTextButton(this,0x1f44,0x40,0xf5,s_VERDANA8_fnt_00563e98,s__Filialname_005644d4,0,
                           s_TEXTPB05__00_spr_00564160);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x1f44,0,0,0);
    Gadget_SetButtonTextLayout(this,0x1f44,2,0x93,0,0,0xfffe);
  }
  UI_AddImage(this,0x1f45,0xcd,0xf4,s_PB24_00_spr_00564144,0,0);
  return this;
}

