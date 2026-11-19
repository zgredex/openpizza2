// rea decompile_all
// name: Screen_StatisticsPersonnel
// address: 0x43edb0
// body: available
// range: 0x43edb0-0x44286c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl Screen_StatisticsPersonnel(int *param_1)

{
  int iVar1;
  void *this;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
                    /* Builds the personnel statistics page. */
  iVar1 = UI_CreateWindow(DAT_0057c5e0,0,0,s_SK_PERSONAL_spr_00566210,&LAB_004b2850);
  *param_1 = iVar1;
  this = (void *)UI_FindWindowByID(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(this,0x45a,0x261,0x1ba,s_PERSOPLAN_spr_005644ac);
  UI_AddSprite(this,0x1794,0x261,0x1ba,s_PERSOPLANLIGHT_spr_00564498);
  UI_AddSprite(this,0x1795,0x261,0x1c4,s_PERSOPLANLIGHT_spr_00564498);
  UI_AddSprite(this,0x1796,0x261,0x1ce,s_PERSOPLANLIGHT_spr_00564498);
  UI_AddSprite(this,0x1797,0x261,0x1d8,s_PERSOPLANLIGHT_spr_00564498);
  UI_AddSprite(this,0x1798,0x261,0x1e2,s_PERSOPLANLIGHT_spr_00564498);
  UI_AddSprite(this,0x1799,0x261,0x1ec,s_PERSOPLANLIGHT_spr_00564498);
  UI_AddSprite(this,0x179a,0x261,0x1f6,s_PERSOPLANLIGHT_spr_00564498);
  UI_AddImage(this,0x57e,0x22,0x79,s_LEUCHTFELD_SK_00_spr_005661f8,1,0);
  UI_AddImage(this,0x57f,0x22,0xb7,s_LEUCHTFELD_SK_00_spr_005661f8,1,0);
  UI_AddImage(this,0x580,0x22,0xf5,s_LEUCHTFELD_SK_00_spr_005661f8,1,0);
  UI_AddImage(this,0x581,0x22,0x133,s_LEUCHTFELD_SK_00_spr_005661f8,1,0);
  UI_AddImage(this,0x582,0x22,0x171,s_LEUCHTFELD_SK_00_spr_005661f8,1,0);
  UI_AddImage(this,0x583,0x22,0x1af,s_LEUCHTFELD_SK_00_spr_005661f8,1,0);
  UI_AddImage(this,0x57d,0x22,0x3c,s_LEUCHTFELD_SK_00_spr_005661f8,1,0);
  UI_CreateBitmapGadget(this,0x584,0xf9,0x43,0x127,0x32,0x10);
  UI_CreateBitmapGadget(this,0x585,0xf9,0x81,0x127,0x32,0x10);
  UI_CreateBitmapGadget(this,0x586,0xf9,0xfd,0x127,0x32,0x10);
  UI_CreateBitmapGadget(this,0x587,0xf9,0xbf,0x127,0x32,0x10);
  UI_CreateBitmapGadget(this,0x588,0xf9,0x1b7,0x127,0x32,0x10);
  UI_CreateBitmapGadget(this,0x589,0xf9,0x179,0x127,0x32,0x10);
  UI_CreateBitmapGadget(this,0x58a,0xf9,0x13b,0x127,0x32,0x10);
  UI_AddSprite(this,0x491,0x294,0x215,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x492,0x294,0x215,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x493,0x294,0x215,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x494,0x294,0x215,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x495,0x294,0x215,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x496,0x294,0x215,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x497,0x294,0x215,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x498,0x294,0x215,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x499,0x294,0x215,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x49a,0x294,0x215,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x49b,0x294,0x215,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x49c,0x294,0x215,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x49d,0x294,0x215,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x49e,0x294,0x215,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x49f,0x294,0x215,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x4a0,0x294,0x215,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x4a1,0x294,0x215,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x4a2,0x2c6,0x215,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x4a3,0x2c6,0x215,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x4a4,0x2c6,0x215,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x4a5,0x2c6,0x215,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x4a6,0x2c6,0x215,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x4a7,0x2c6,0x215,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x4a8,0x2c6,0x215,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x4a9,0x2c6,0x215,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x4aa,0x2c6,0x215,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x4ab,0x2c6,0x215,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x4ac,0x2c6,0x215,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x4ad,0x2c6,0x215,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x4ae,0x2c6,0x215,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x4af,0x2c6,0x215,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x4b0,0x2c6,0x215,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x4b1,0x2c6,0x215,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x4b2,0x2c6,0x215,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x4b3,0x2f8,0x215,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x4b4,0x2f8,0x215,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x4b5,0x2f8,0x215,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x4b6,0x2f8,0x215,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x4b7,0x2f8,0x215,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x4b8,0x2f8,0x215,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x4b9,0x2f8,0x215,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x4ba,0x2f8,0x215,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x4bb,0x2f8,0x215,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x4bc,0x2f8,0x215,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x4bd,0x2f8,0x215,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x4be,0x2f8,0x215,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x4bf,0x2f8,0x215,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x4c0,0x2f8,0x215,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x4c1,0x2f8,0x215,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x4c2,0x2f8,0x215,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x4c3,0x2f8,0x215,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x4c4,0x262,0x238,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x4c5,0x262,0x238,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x4c6,0x262,0x238,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x4c7,0x262,0x238,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x4c8,0x262,0x238,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x4c9,0x262,0x238,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x4ca,0x262,0x238,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x4cb,0x262,0x238,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x4cc,0x262,0x238,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x4cd,0x262,0x238,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x4ce,0x262,0x238,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x4cf,0x262,0x238,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x4d0,0x262,0x238,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x4d1,0x262,0x238,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x4d2,0x262,0x238,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x4d3,0x262,0x238,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x4d4,0x262,0x238,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x4d5,0x294,0x238,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x4d6,0x294,0x238,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x4d7,0x294,0x238,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x4d8,0x294,0x238,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x4d9,0x294,0x238,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x4da,0x294,0x238,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x4db,0x294,0x238,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x4dc,0x294,0x238,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x4dd,0x294,0x238,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x4de,0x294,0x238,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x4df,0x294,0x238,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x4e0,0x294,0x238,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x4e1,0x294,0x238,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x4e2,0x294,0x238,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x4e3,0x294,0x238,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x4e4,0x294,0x238,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x4e5,0x294,0x238,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x4e6,0x2c6,0x238,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x4e7,0x2c6,0x238,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x4e8,0x2c6,0x238,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x4e9,0x2c6,0x238,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x4ea,0x2c6,0x238,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x4eb,0x2c6,0x238,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x4ec,0x2c6,0x238,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x4ed,0x2c6,0x238,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x4ee,0x2c6,0x238,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x4ef,0x2c6,0x238,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x4f0,0x2c6,0x238,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x4f1,0x2c6,0x238,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x4f2,0x2c6,0x238,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x4f3,0x2c6,0x238,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x4f4,0x2c6,0x238,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x4f5,0x2c6,0x238,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x4f6,0x2c6,0x238,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x4f7,0x2f8,0x238,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x4f8,0x2f8,0x238,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x4f9,0x2f8,0x238,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x4fa,0x2f8,0x238,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x4fb,0x2f8,0x238,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x4fc,0x2f8,0x238,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x4fd,0x2f8,0x238,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x4fe,0x2f8,0x238,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x4ff,0x2f8,0x238,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x500,0x2f8,0x238,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x501,0x2f8,0x238,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x502,0x2f8,0x238,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x503,0x2f8,0x238,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x504,0x2f8,0x238,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x505,0x2f8,0x238,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x506,0x2f8,0x238,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x507,0x2f8,0x238,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x508,0x262,0x215,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x509,0x262,0x215,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x50a,0x262,0x215,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x50b,0x262,0x215,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x50c,0x262,0x215,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x50d,0x262,0x215,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x50e,0x262,0x215,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x50f,0x262,0x215,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x510,0x262,0x215,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x511,0x262,0x215,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x512,0x262,0x215,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x513,0x262,0x215,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x514,0x262,0x215,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x515,0x262,0x215,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x516,0x262,0x215,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x517,0x262,0x215,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x518,0x262,0x215,s_BEWERTUNG__16_spr_00563ed8);
  iVar1 = UI_AddText(this,0x519,600,0x20a,s_VERDANA7_fnt_00563ec8,DAT_00580bec);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x519,0);
    Window_GadgetNotify_Text_SetLayout(this,0x519,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x51a,0x289,0x20a,s_VERDANA7_fnt_00563ec8,DAT_005816d4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x51a,0);
    Window_GadgetNotify_Text_SetLayout(this,0x51a,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x51b,699,0x20a,s_VERDANA7_fnt_00563ec8,DAT_00582974);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x51b,0);
    Window_GadgetNotify_Text_SetLayout(this,0x51b,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x51c,0x2ed,0x20a,s_VERDANA7_fnt_00563ec8,DAT_0058234c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x51c,0);
    Window_GadgetNotify_Text_SetLayout(this,0x51c,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x51d,600,0x22e,s_VERDANA7_fnt_00563ec8,DAT_00580e64);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x51d,0);
    Window_GadgetNotify_Text_SetLayout(this,0x51d,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x51e,0x289,0x22e,s_VERDANA7_fnt_00563ec8,DAT_00582e08);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x51e,0);
    Window_GadgetNotify_Text_SetLayout(this,0x51e,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x51f,0x2ba,0x22e,s_VERDANA7_fnt_00563ec8,DAT_00582770);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x51f,0);
    Window_GadgetNotify_Text_SetLayout(this,0x51f,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x520,0x2eb,0x22e,s_VERDANA7_fnt_00563ec8,DAT_005810a4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x520,0);
    Window_GadgetNotify_Text_SetLayout(this,0x520,2,0x32,0,0);
  }
  UI_AddSprite(this,0x408,600,0x203,s_TRENNZEILE_spr_00563eb8);
  iVar1 = UI_AddText(this,0x46f,0x25d,0xdf,s_TIMESFONT_fnt_00563ea8,DAT_00582a9c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x46f,0);
    Window_GadgetNotify_Text_SetLayout(this,0x46f,2,0xbe,0,0);
  }
  iVar1 = UI_AddText(this,0x472,0x261,0x14f,s_VERDANA7_fnt_00563ec8,s__Kochen_005661f0);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x472,0);
    Window_GadgetNotify_Text_SetLayout(this,0x472,2,0x5a,0,0);
  }
  iVar1 = UI_AddText(this,0x473,0x261,0x166,s_VERDANA7_fnt_00563ec8,DAT_00581000);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x473,0);
    Window_GadgetNotify_Text_SetLayout(this,0x473,2,0x5a,0,0);
  }
  iVar1 = UI_AddText(this,0x474,0x261,0x17d,s_VERDANA7_fnt_00563ec8,DAT_00581784);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x474,0);
    Window_GadgetNotify_Text_SetLayout(this,0x474,2,0x5a,0,0);
  }
  iVar1 = UI_AddText(this,0x475,0x261,0x194,s_VERDANA7_fnt_00563ec8,DAT_005818c4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x475,0);
    Window_GadgetNotify_Text_SetLayout(this,0x475,2,0x5a,0,0);
  }
  iVar1 = UI_AddText(this,0x476,0x261,0x1b0,s_VERDANA7_fnt_00563ec8,&DAT_00564220);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x476,0);
    Window_GadgetNotify_Text_SetLayout(this,0x476,0,0,0,0);
  }
  iVar1 = UI_AddText(this,0x477,0x274,0x1b0,s_VERDANA7_fnt_00563ec8,&DAT_0056421c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x477,0);
    Window_GadgetNotify_Text_SetLayout(this,0x477,0,0,0,0);
  }
  iVar1 = UI_AddText(this,0x478,0x289,0x1b0,s_VERDANA7_fnt_00563ec8,&DAT_00564218);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x478,0);
    Window_GadgetNotify_Text_SetLayout(this,0x478,0,0,0,0);
  }
  iVar1 = UI_AddText(this,0x479,0x29c,0x1b0,s_VERDANA7_fnt_00563ec8,&DAT_00564214);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x479,0);
    Window_GadgetNotify_Text_SetLayout(this,0x479,0,0,0,0);
  }
  iVar1 = UI_AddText(this,0x47a,0x2ad,0x1b0,s_VERDANA7_fnt_00563ec8,&DAT_00564210);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x47a,0);
    Window_GadgetNotify_Text_SetLayout(this,0x47a,0,0,0,0);
  }
  iVar1 = UI_AddText(this,0x47b,0x2c1,0x1b0,s_VERDANA7_fnt_00563ec8,&DAT_0056420c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x47b,0);
    Window_GadgetNotify_Text_SetLayout(this,0x47b,0,0,0,0);
  }
  iVar1 = UI_AddText(this,0x47c,0x2d5,0x1b0,s_VERDANA7_fnt_00563ec8,&DAT_00564208);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x47c,0);
    Window_GadgetNotify_Text_SetLayout(this,0x47c,0,0,0,0);
  }
  iVar1 = UI_AddText(this,0x47d,0x2e9,0x1b0,s_VERDANA7_fnt_00563ec8,&DAT_00564204);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x47d,0);
    Window_GadgetNotify_Text_SetLayout(this,0x47d,0,0,0,0);
  }
  iVar1 = UI_AddText(this,0x47e,0x2fc,0x1b0,s_VERDANA7_fnt_00563ec8,&DAT_00564200);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x47e,0);
    Window_GadgetNotify_Text_SetLayout(this,0x47e,0,0,0,0);
  }
  iVar1 = UI_CreateSlider(this,0x451,0x30f,0x1c7,0x3c,s_SL01_00_spr_0056448c,0,1);
  if (iVar1 != 0) {
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x451,&local_10);
  }
  UI_AddImage(this,0x44f,0x266,0x139,s_PB22_00_spr_00564174,0,0);
  UI_AddImage(this,0x450,0x28e,0x139,s_PB24_00_spr_00564144,0,0);
  iVar1 = UI_AddTextButton(this,0x47f,0x2c0,0x13e,s_VERDANA8_fnt_00563e98,DAT_0058202c,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x47f,0,0,0);
    Gadget_SetButtonTextLayout(this,0x47f,2,0x54,0,0,0xfffe);
  }
  iVar1 = UI_AddTextButton(this,0x480,0x2bf,0x155,s_VERDANA8_fnt_00563e98,DAT_00581518,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x480,0,0,0);
    Gadget_SetButtonTextLayout(this,0x480,2,0x54,0,0,0xfffe);
  }
  iVar1 = UI_AddTextButton(this,0x483,0x2bf,0x16c,s_VERDANA8_fnt_00563e98,DAT_00581518,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x483,0,0,0);
    Gadget_SetButtonTextLayout(this,0x483,2,0x54,0,0,0xfffe);
  }
  iVar1 = UI_AddTextButton(this,0x484,0x2bf,0x183,s_VERDANA8_fnt_00563e98,s__100__00564484,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x484,0,0,0);
    Gadget_SetButtonTextLayout(this,0x484,2,0x54,0,0,0xfffe);
  }
  iVar1 = UI_AddTextButton(this,0x485,0x2bf,0x19a,s_VERDANA8_fnt_00563e98,DAT_00582d00,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x485,0,0,0);
    Gadget_SetButtonTextLayout(this,0x485,2,0x54,0,0,0xfffe);
  }
  iVar1 = UI_AddText(this,0x530,0x74,0x61,s_VERDANA8_fnt_00563e98,DAT_00581ba8);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x530,0);
    Window_GadgetNotify_Text_SetLayout(this,0x530,0,0x46,0,0);
  }
  iVar1 = UI_AddText(this,0x531,0x74,0x6d,s_VERDANA8_fnt_00563e98,DAT_0058293c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x531,0);
    Window_GadgetNotify_Text_SetLayout(this,0x531,0,0x37,0,0);
  }
  iVar1 = UI_AddText(this,0x532,0x9f,0x6d,s_VERDANA8_fnt_00563e98,s__5656__0056447c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x532,0);
    Window_GadgetNotify_Text_SetLayout(this,0x532,1,0x37,0,0);
  }
  iVar1 = UI_AddText(this,0x533,0xad,0x61,s_VERDANA8_fnt_00563e98,&DAT_00564478);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x533,0);
    Window_GadgetNotify_Text_SetLayout(this,0x533,1,0x28,0,0);
  }
  iVar1 = UI_AddText(this,0x534,0x74,0x3f,s_VERDANA8_fnt_00563e98,s__Carlos_Estarda_00564468);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x534,0);
    Window_GadgetNotify_Text_SetLayout(this,0x534,0,0x6c,0,0);
  }
  iVar1 = UI_AddText(this,0x535,0x74,0x4b,s_VERDANA8_fnt_00563e98,DAT_00581228);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x535,0);
    Window_GadgetNotify_Text_SetLayout(this,0x535,0,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x536,0x74,0x56,s_VERDANA8_fnt_00563e98,s__Koch_00564460);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x536,0);
    Window_GadgetNotify_Text_SetLayout(this,0x536,0,0x6c,0,0);
  }
  iVar1 = UI_AddText(this,0x537,0xad,0x4b,s_VERDANA8_fnt_00563e98,&DAT_0056445c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x537,0);
    Window_GadgetNotify_Text_SetLayout(this,0x537,1,0x28,0,0);
  }
  iVar1 = UI_AddText(this,0x539,0x74,0x9f,s_VERDANA8_fnt_00563e98,DAT_00581ba8);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x539,0);
    Window_GadgetNotify_Text_SetLayout(this,0x539,0,0x46,0,0);
  }
  iVar1 = UI_AddText(this,0x53a,0x74,0xab,s_VERDANA8_fnt_00563e98,DAT_0058293c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x53a,0);
    Window_GadgetNotify_Text_SetLayout(this,0x53a,0,0x37,0,0);
  }
  iVar1 = UI_AddText(this,0x53b,0x9f,0xab,s_VERDANA8_fnt_00563e98,s__5656__0056447c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x53b,0);
    Window_GadgetNotify_Text_SetLayout(this,0x53b,1,0x37,0,0);
  }
  iVar1 = UI_AddText(this,0x53c,0xad,0x9f,s_VERDANA8_fnt_00563e98,&DAT_00564478);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x53c,0);
    Window_GadgetNotify_Text_SetLayout(this,0x53c,1,0x28,0,0);
  }
  iVar1 = UI_AddText(this,0x53d,0x74,0x7d,s_VERDANA8_fnt_00563e98,s__Carlos_Estarda_00564468);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x53d,0);
    Window_GadgetNotify_Text_SetLayout(this,0x53d,0,0x6c,0,0);
  }
  iVar1 = UI_AddText(this,0x53e,0x74,0x89,s_VERDANA8_fnt_00563e98,DAT_00581228);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x53e,0);
    Window_GadgetNotify_Text_SetLayout(this,0x53e,0,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x53f,0x74,0x94,s_VERDANA8_fnt_00563e98,s__Koch_00564460);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x53f,0);
    Window_GadgetNotify_Text_SetLayout(this,0x53f,0,0x6c,0,0);
  }
  iVar1 = UI_AddText(this,0x540,0xad,0x89,s_VERDANA8_fnt_00563e98,&DAT_0056445c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x540,0);
    Window_GadgetNotify_Text_SetLayout(this,0x540,1,0x28,0,0);
  }
  iVar1 = UI_AddText(this,0x542,0x74,0xdd,s_VERDANA8_fnt_00563e98,DAT_00581ba8);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x542,0);
    Window_GadgetNotify_Text_SetLayout(this,0x542,0,0x46,0,0);
  }
  iVar1 = UI_AddText(this,0x543,0x74,0xe9,s_VERDANA8_fnt_00563e98,DAT_0058293c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x543,0);
    Window_GadgetNotify_Text_SetLayout(this,0x543,0,0x37,0,0);
  }
  iVar1 = UI_AddText(this,0x544,0x9f,0xe9,s_VERDANA8_fnt_00563e98,s__5656__0056447c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x544,0);
    Window_GadgetNotify_Text_SetLayout(this,0x544,1,0x37,0,0);
  }
  iVar1 = UI_AddText(this,0x545,0xad,0xdd,s_VERDANA8_fnt_00563e98,&DAT_00564478);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x545,0);
    Window_GadgetNotify_Text_SetLayout(this,0x545,1,0x28,0,0);
  }
  iVar1 = UI_AddText(this,0x546,0x74,0xbb,s_VERDANA8_fnt_00563e98,s__Carlos_Estarda_00564468);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x546,0);
    Window_GadgetNotify_Text_SetLayout(this,0x546,0,0x6c,0,0);
  }
  iVar1 = UI_AddText(this,0x547,0x74,199,s_VERDANA8_fnt_00563e98,DAT_00581228);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x547,0);
    Window_GadgetNotify_Text_SetLayout(this,0x547,0,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x548,0x74,0xd2,s_VERDANA8_fnt_00563e98,s__Koch_00564460);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x548,0);
    Window_GadgetNotify_Text_SetLayout(this,0x548,0,0x6c,0,0);
  }
  iVar1 = UI_AddText(this,0x549,0xad,199,s_VERDANA8_fnt_00563e98,&DAT_0056445c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x549,0);
    Window_GadgetNotify_Text_SetLayout(this,0x549,1,0x28,0,0);
  }
  iVar1 = UI_AddText(this,0x54b,0x74,0x11b,s_VERDANA8_fnt_00563e98,DAT_00581ba8);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x54b,0);
    Window_GadgetNotify_Text_SetLayout(this,0x54b,0,0x46,0,0);
  }
  iVar1 = UI_AddText(this,0x54c,0x74,0x127,s_VERDANA8_fnt_00563e98,DAT_0058293c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x54c,0);
    Window_GadgetNotify_Text_SetLayout(this,0x54c,0,0x37,0,0);
  }
  iVar1 = UI_AddText(this,0x54d,0x9f,0x127,s_VERDANA8_fnt_00563e98,s__5656__0056447c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x54d,0);
    Window_GadgetNotify_Text_SetLayout(this,0x54d,1,0x37,0,0);
  }
  iVar1 = UI_AddText(this,0x54e,0xad,0x11b,s_VERDANA8_fnt_00563e98,&DAT_00564478);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x54e,0);
    Window_GadgetNotify_Text_SetLayout(this,0x54e,1,0x28,0,0);
  }
  iVar1 = UI_AddText(this,0x54f,0x74,0xf9,s_VERDANA8_fnt_00563e98,s__Carlos_Estarda_00564468);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x54f,0);
    Window_GadgetNotify_Text_SetLayout(this,0x54f,0,0x6c,0,0);
  }
  iVar1 = UI_AddText(this,0x550,0x74,0x105,s_VERDANA8_fnt_00563e98,DAT_00581228);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x550,0);
    Window_GadgetNotify_Text_SetLayout(this,0x550,0,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x551,0x74,0x110,s_VERDANA8_fnt_00563e98,s__Koch_00564460);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x551,0);
    Window_GadgetNotify_Text_SetLayout(this,0x551,0,0x6c,0,0);
  }
  iVar1 = UI_AddText(this,0x552,0xad,0x105,s_VERDANA8_fnt_00563e98,&DAT_0056445c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x552,0);
    Window_GadgetNotify_Text_SetLayout(this,0x552,1,0x28,0,0);
  }
  iVar1 = UI_AddText(this,0x554,0x74,0x159,s_VERDANA8_fnt_00563e98,DAT_00581ba8);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x554,0);
    Window_GadgetNotify_Text_SetLayout(this,0x554,0,0x46,0,0);
  }
  iVar1 = UI_AddText(this,0x555,0x74,0x165,s_VERDANA8_fnt_00563e98,DAT_0058293c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x555,0);
    Window_GadgetNotify_Text_SetLayout(this,0x555,0,0x37,0,0);
  }
  iVar1 = UI_AddText(this,0x556,0x9f,0x165,s_VERDANA8_fnt_00563e98,s__5656__0056447c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x556,0);
    Window_GadgetNotify_Text_SetLayout(this,0x556,1,0x37,0,0);
  }
  iVar1 = UI_AddText(this,0x557,0xad,0x159,s_VERDANA8_fnt_00563e98,&DAT_00564478);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x557,0);
    Window_GadgetNotify_Text_SetLayout(this,0x557,1,0x28,0,0);
  }
  iVar1 = UI_AddText(this,0x558,0x74,0x137,s_VERDANA8_fnt_00563e98,s__Carlos_Estarda_00564468);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x558,0);
    Window_GadgetNotify_Text_SetLayout(this,0x558,0,0x6c,0,0);
  }
  iVar1 = UI_AddText(this,0x559,0x74,0x143,s_VERDANA8_fnt_00563e98,DAT_00581228);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x559,0);
    Window_GadgetNotify_Text_SetLayout(this,0x559,0,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x55a,0x74,0x14e,s_VERDANA8_fnt_00563e98,s__Koch_00564460);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x55a,0);
    Window_GadgetNotify_Text_SetLayout(this,0x55a,0,0x6c,0,0);
  }
  iVar1 = UI_AddText(this,0x55b,0xad,0x143,s_VERDANA8_fnt_00563e98,&DAT_0056445c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x55b,0);
    Window_GadgetNotify_Text_SetLayout(this,0x55b,1,0x28,0,0);
  }
  iVar1 = UI_AddText(this,0x55d,0x74,0x197,s_VERDANA8_fnt_00563e98,DAT_00581ba8);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x55d,0);
    Window_GadgetNotify_Text_SetLayout(this,0x55d,0,0x46,0,0);
  }
  iVar1 = UI_AddText(this,0x55e,0x74,0x1a3,s_VERDANA8_fnt_00563e98,DAT_0058293c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x55e,0);
    Window_GadgetNotify_Text_SetLayout(this,0x55e,0,0x37,0,0);
  }
  iVar1 = UI_AddText(this,0x55f,0x9f,0x1a3,s_VERDANA8_fnt_00563e98,s__5656__0056447c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x55f,0);
    Window_GadgetNotify_Text_SetLayout(this,0x55f,1,0x37,0,0);
  }
  iVar1 = UI_AddText(this,0x560,0xad,0x197,s_VERDANA8_fnt_00563e98,&DAT_00564478);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x560,0);
    Window_GadgetNotify_Text_SetLayout(this,0x560,1,0x28,0,0);
  }
  iVar1 = UI_AddText(this,0x561,0x74,0x175,s_VERDANA8_fnt_00563e98,s__Carlos_Estarda_00564468);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x561,0);
    Window_GadgetNotify_Text_SetLayout(this,0x561,0,0x6c,0,0);
  }
  iVar1 = UI_AddText(this,0x562,0x74,0x181,s_VERDANA8_fnt_00563e98,DAT_00581228);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x562,0);
    Window_GadgetNotify_Text_SetLayout(this,0x562,0,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x563,0x74,0x18c,s_VERDANA8_fnt_00563e98,s__Koch_00564460);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x563,0);
    Window_GadgetNotify_Text_SetLayout(this,0x563,0,0x6c,0,0);
  }
  iVar1 = UI_AddText(this,0x564,0xad,0x181,s_VERDANA8_fnt_00563e98,&DAT_0056445c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x564,0);
    Window_GadgetNotify_Text_SetLayout(this,0x564,1,0x28,0,0);
  }
  iVar1 = UI_AddText(this,0x566,0x74,0x1d5,s_VERDANA8_fnt_00563e98,DAT_00581ba8);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x566,0);
    Window_GadgetNotify_Text_SetLayout(this,0x566,0,0x46,0,0);
  }
  iVar1 = UI_AddText(this,0x567,0x74,0x1e1,s_VERDANA8_fnt_00563e98,DAT_0058293c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x567,0);
    Window_GadgetNotify_Text_SetLayout(this,0x567,0,0x37,0,0);
  }
  iVar1 = UI_AddText(this,0x568,0x9f,0x1e1,s_VERDANA8_fnt_00563e98,s__5656__0056447c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x568,0);
    Window_GadgetNotify_Text_SetLayout(this,0x568,1,0x37,0,0);
  }
  iVar1 = UI_AddText(this,0x569,0xad,0x1d5,s_VERDANA8_fnt_00563e98,&DAT_00564478);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x569,0);
    Window_GadgetNotify_Text_SetLayout(this,0x569,1,0x28,0,0);
  }
  iVar1 = UI_AddText(this,0x56a,0x74,0x1b3,s_VERDANA8_fnt_00563e98,s__Carlos_Estarda_00564468);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x56a,0);
    Window_GadgetNotify_Text_SetLayout(this,0x56a,0,0x6c,0,0);
  }
  iVar1 = UI_AddText(this,0x56b,0x74,0x1bf,s_VERDANA8_fnt_00563e98,DAT_00581228);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x56b,0);
    Window_GadgetNotify_Text_SetLayout(this,0x56b,0,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x56c,0x74,0x1ca,s_VERDANA8_fnt_00563e98,s__Koch_00564460);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x56c,0);
    Window_GadgetNotify_Text_SetLayout(this,0x56c,0,0x6c,0,0);
  }
  iVar1 = UI_AddText(this,0x56d,0xad,0x1bf,s_VERDANA8_fnt_00563e98,&DAT_0056445c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x56d,0);
    Window_GadgetNotify_Text_SetLayout(this,0x56d,1,0x28,0,0);
  }
  UI_AddSprite(this,0x56e,0x20,0x40,s_FOTORAHMEN_spr_005661e0);
  UI_AddSprite(this,0x56f,0x20,0x7e,s_FOTORAHMEN_spr_005661e0);
  UI_AddSprite(this,0x570,0x20,0xfa,s_FOTORAHMEN_spr_005661e0);
  UI_AddSprite(this,0x571,0x20,0xbc,s_FOTORAHMEN_spr_005661e0);
  UI_AddSprite(this,0x574,0x20,0x176,s_FOTORAHMEN_spr_005661e0);
  UI_AddSprite(this,0x575,0x20,0x138,s_FOTORAHMEN_spr_005661e0);
  UI_AddSprite(this,0x576,0x20,0x1b4,s_FOTORAHMEN_spr_005661e0);
  iVar1 = UI_AddText(this,0x577,0x1e,0x1f9,s_VERDANA7_fnt_00563ec8,DAT_00581ba8);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x577,0);
    Window_GadgetNotify_Text_SetLayout(this,0x577,0,0x3c,0,0);
  }
  iVar1 = UI_AddText(this,0x578,0x79,0x1f9,s_VERDANA7_fnt_00563ec8,s__Qualifikation_005661d0);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x578,0);
    Window_GadgetNotify_Text_SetLayout(this,0x578,0,0x50,0,0);
  }
  iVar1 = UI_AddText(this,0x579,0xe9,0x1f9,s_VERDANA7_fnt_00563ec8,DAT_00581000);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x579,0);
    Window_GadgetNotify_Text_SetLayout(this,0x579,0,0x55,0,0);
  }
  iVar1 = UI_AddText(this,0x57a,0x15b,0x1f9,s_VERDANA7_fnt_00563ec8,DAT_00581784);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x57a,0);
    Window_GadgetNotify_Text_SetLayout(this,0x57a,0,0x55,0,0);
  }
  iVar1 = UI_AddText(this,0x57b,0x1c9,0x1f9,s_VERDANA7_fnt_00563ec8,DAT_005818c4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x57b,0);
    Window_GadgetNotify_Text_SetLayout(this,0x57b,0,0x55,0,0);
  }
  iVar1 = UI_AddText(this,0x58b,0xe1,0x37,s_VERDANA7_fnt_00563ec8,s__Blablalbla_005661c4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x58b,0);
    Window_GadgetNotify_Text_SetLayout(this,0x58b,0,0x3c,0,0);
  }
  iVar1 = UI_AddText(this,0x58c,0x1da,0x76,s_VERDANA7_fnt_00563ec8,s__Blablalbla_005661c4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x58c,0);
    Window_GadgetNotify_Text_SetLayout(this,0x58c,0,0x3c,0,0);
  }
  iVar1 = UI_AddText(this,0x58d,0xe1,0x75,s_VERDANA7_fnt_00563ec8,s__Blablalbla_005661c4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x58d,0);
    Window_GadgetNotify_Text_SetLayout(this,0x58d,0,0x3c,0,0);
  }
  iVar1 = UI_AddText(this,0x58e,0x1da,0xb4,s_VERDANA7_fnt_00563ec8,s__Blablalbla_005661c4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x58e,0);
    Window_GadgetNotify_Text_SetLayout(this,0x58e,0,0x3c,0,0);
  }
  iVar1 = UI_AddText(this,0x58f,0xe1,0xb3,s_VERDANA7_fnt_00563ec8,s__Blablalbla_005661c4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x58f,0);
    Window_GadgetNotify_Text_SetLayout(this,0x58f,0,0x3c,0,0);
  }
  iVar1 = UI_AddText(this,0x590,0xe1,0xf1,s_VERDANA7_fnt_00563ec8,s__Blablalbla_005661c4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x590,0);
    Window_GadgetNotify_Text_SetLayout(this,0x590,0,0x3c,0,0);
  }
  iVar1 = UI_AddText(this,0x591,0x1da,0xf2,s_VERDANA7_fnt_00563ec8,s__Blablalbla_005661c4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x591,0);
    Window_GadgetNotify_Text_SetLayout(this,0x591,0,0x3c,0,0);
  }
  iVar1 = UI_AddText(this,0x592,0x1da,0x130,s_VERDANA7_fnt_00563ec8,s__Blablalbla_005661c4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x592,0);
    Window_GadgetNotify_Text_SetLayout(this,0x592,0,0x3c,0,0);
  }
  iVar1 = UI_AddText(this,0x593,0xe1,0x12f,s_VERDANA7_fnt_00563ec8,s__Blablalbla_005661c4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x593,0);
    Window_GadgetNotify_Text_SetLayout(this,0x593,0,0x3c,0,0);
  }
  iVar1 = UI_AddText(this,0x594,0xe1,0x16d,s_VERDANA7_fnt_00563ec8,s__Blablalbla_005661c4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x594,0);
    Window_GadgetNotify_Text_SetLayout(this,0x594,0,0x3c,0,0);
  }
  iVar1 = UI_AddText(this,0x595,0x1da,0x16e,s_VERDANA7_fnt_00563ec8,s__Blablalbla_005661c4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x595,0);
    Window_GadgetNotify_Text_SetLayout(this,0x595,0,0x3c,0,0);
  }
  iVar1 = UI_AddText(this,0x596,0x1da,0x1ac,s_VERDANA7_fnt_00563ec8,s__Blablalbla_005661c4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x596,0);
    Window_GadgetNotify_Text_SetLayout(this,0x596,0,0x3c,0,0);
  }
  iVar1 = UI_AddText(this,0x597,0xe1,0x1ab,s_VERDANA7_fnt_00563ec8,s__Blablalbla_005661c4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x597,0);
    Window_GadgetNotify_Text_SetLayout(this,0x597,0,0x3c,0,0);
  }
  iVar1 = UI_AddText(this,0x598,0x1da,0x1eb,s_VERDANA7_fnt_00563ec8,s__Blablalbla_005661c4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x598,0);
    Window_GadgetNotify_Text_SetLayout(this,0x598,0,0x3c,0,0);
  }
  UI_AddSprite(this,0x599,0x5d,0x1f7,s_TABELLENCOLOURS_04_spr_00565970);
  UI_AddSprite(this,0x59a,0xcb,0x1f7,s_TABELLENCOLOURS_02_spr_005659a0);
  UI_AddSprite(this,0x59b,0x142,0x1f7,s_TABELLENCOLOURS_05_spr_00565958);
  UI_AddSprite(this,0x59c,0x1af,0x1f7,s_TABELLENCOLOURS_00_spr_005659d0);
  UI_AddSprite(this,0x59d,0x21a,0x1f7,s_TABELLENCOLOURS_06_spr_00565940);
  UI_AddImage(this,5000,0x2c0,0x155,s_PB14_00_spr_005642c4,1,0);
  iVar1 = UI_AddText(this,0x1389,0x2d6,0x159,s_VERDANA8_fnt_00563e98,s__blablabla_005661b8);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1389,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1389,0,0x41,0,0);
  }
  iVar1 = UI_CreateSlider(this,6000,0x262,0x1c2,0x8c,s_PERSOSLIDERBLUE_00_spr_0056443c,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,6000,&local_10);
  }
  iVar1 = UI_CreateSlider(this,0x1771,0x262,0x1c2,0x8c,s_PERSOSLIDERGREEN_00_spr_00564424,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1771,&local_10);
  }
  iVar1 = UI_CreateSlider(this,0x1772,0x262,0x1c2,0x8c,s_PERSOSLIDERRED_00_spr_0056440c,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1772,&local_10);
  }
  iVar1 = UI_CreateSlider(this,0x1773,0x262,0x1c2,0x8c,s_PERSOSLIDERYELLOW_00_spr_005643f0,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1773,&local_10);
  }
  iVar1 = UI_CreateSlider(this,0x1774,0x262,0x1cc,0x8c,s_PERSOSLIDERBLUE_00_spr_0056443c,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1774,&local_10);
  }
  iVar1 = UI_CreateSlider(this,0x1775,0x262,0x1cc,0x8c,s_PERSOSLIDERGREEN_00_spr_00564424,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1775,&local_10);
  }
  iVar1 = UI_CreateSlider(this,0x1776,0x262,0x1cc,0x8c,s_PERSOSLIDERRED_00_spr_0056440c,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1776,&local_10);
  }
  iVar1 = UI_CreateSlider(this,0x1777,0x262,0x1cc,0x8c,s_PERSOSLIDERYELLOW_00_spr_005643f0,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1777,&local_10);
  }
  iVar1 = UI_CreateSlider(this,0x1778,0x262,0x1d6,0x8c,s_PERSOSLIDERBLUE_00_spr_0056443c,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1778,&local_10);
  }
  iVar1 = UI_CreateSlider(this,0x1779,0x262,0x1d6,0x8c,s_PERSOSLIDERGREEN_00_spr_00564424,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1779,&local_10);
  }
  iVar1 = UI_CreateSlider(this,0x177a,0x262,0x1d6,0x8c,s_PERSOSLIDERRED_00_spr_0056440c,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x177a,&local_10);
  }
  iVar1 = UI_CreateSlider(this,0x177b,0x262,0x1d6,0x8c,s_PERSOSLIDERYELLOW_00_spr_005643f0,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x177b,&local_10);
  }
  iVar1 = UI_CreateSlider(this,0x177c,0x262,0x1e0,0x8c,s_PERSOSLIDERBLUE_00_spr_0056443c,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x177c,&local_10);
  }
  iVar1 = UI_CreateSlider(this,0x177d,0x262,0x1e0,0x8c,s_PERSOSLIDERGREEN_00_spr_00564424,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x177d,&local_10);
  }
  iVar1 = UI_CreateSlider(this,0x177e,0x262,0x1e0,0x8c,s_PERSOSLIDERRED_00_spr_0056440c,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x177e,&local_10);
  }
  iVar1 = UI_CreateSlider(this,0x177f,0x262,0x1e0,0x8c,s_PERSOSLIDERYELLOW_00_spr_005643f0,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x177f,&local_10);
  }
  iVar1 = UI_CreateSlider(this,0x1780,0x262,0x1ea,0x8c,s_PERSOSLIDERBLUE_00_spr_0056443c,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1780,&local_10);
  }
  iVar1 = UI_CreateSlider(this,0x1781,0x262,0x1ea,0x8c,s_PERSOSLIDERGREEN_00_spr_00564424,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1781,&local_10);
  }
  iVar1 = UI_CreateSlider(this,0x1782,0x262,0x1ea,0x8c,s_PERSOSLIDERRED_00_spr_0056440c,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1782,&local_10);
  }
  iVar1 = UI_CreateSlider(this,0x1783,0x262,0x1ea,0x8c,s_PERSOSLIDERYELLOW_00_spr_005643f0,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1783,&local_10);
  }
  iVar1 = UI_CreateSlider(this,0x1784,0x262,500,0x8c,s_PERSOSLIDERBLUE_00_spr_0056443c,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1784,&local_10);
  }
  iVar1 = UI_CreateSlider(this,0x1785,0x262,500,0x8c,s_PERSOSLIDERGREEN_00_spr_00564424,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1785,&local_10);
  }
  iVar1 = UI_CreateSlider(this,0x1786,0x262,500,0x8c,s_PERSOSLIDERRED_00_spr_0056440c,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1786,&local_10);
  }
  iVar1 = UI_CreateSlider(this,0x1787,0x262,500,0x8c,s_PERSOSLIDERYELLOW_00_spr_005643f0,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1787,&local_10);
  }
  iVar1 = UI_CreateSlider(this,0x1788,0x262,0x1fe,0x8c,s_PERSOSLIDERBLUE_00_spr_0056443c,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1788,&local_10);
  }
  iVar1 = UI_CreateSlider(this,0x1789,0x262,0x1fe,0x8c,s_PERSOSLIDERGREEN_00_spr_00564424,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x1789,&local_10);
  }
  iVar1 = UI_CreateSlider(this,0x178a,0x262,0x1fe,0x8c,s_PERSOSLIDERRED_00_spr_0056440c,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x178a,&local_10);
  }
  iVar1 = UI_CreateSlider(this,0x178b,0x262,0x1fe,0x8c,s_PERSOSLIDERYELLOW_00_spr_005643f0,0,0);
  if (iVar1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x178b,&local_10);
  }
  UI_AddSprite(this,0x178c,600,0xe3,s_PERSOSLIDERBLAU_00_spr_005643d8);
  UI_AddSprite(this,0x178d,0x27b,0xe3,s_PERSOSLIDERBLAU_01_spr_005643c0);
  UI_AddSprite(this,0x178e,0x259,0xee,s_PERSOSLIDERGELB_00_spr_005643a8);
  UI_AddSprite(this,0x178f,0x278,0xee,s_PERSOSLIDERGELB_01_spr_00564390);
  UI_AddSprite(this,0x1790,0x2dd,0xe0,s_PERSOSLIDERGRUEN_00_spr_00564378);
  UI_AddSprite(this,0x1791,0x2f9,0xe0,s_PERSOSLIDERGRUEN_01_spr_00564360);
  UI_AddSprite(this,0x1792,0x2d8,0xec,s_PERSOSLIDERROT_00_spr_00564348);
  UI_AddSprite(this,0x1793,0x2f7,0xea,s_PERSOSLIDERROT_01_spr_00564330);
  UI_AddImage(this,8000,0x23c,0xd9,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  UI_AddSprite(this,0x1f42,0x1f,0x3f,s_FOTORAHMEN00_spr_00564310);
  UI_AddSprite(this,0x1f46,0x1f,0x7d,s_FOTORAHMEN00_spr_00564310);
  UI_AddSprite(this,0x1f48,0x1f,0xbb,s_FOTORAHMEN00_spr_00564310);
  UI_AddSprite(this,0x1f4a,0x1f,0xf9,s_FOTORAHMEN00_spr_00564310);
  UI_AddSprite(this,0x1f4c,0x1f,0x137,s_FOTORAHMEN00_spr_00564310);
  UI_AddSprite(this,0x1f4e,0x1f,0x175,s_FOTORAHMEN00_spr_00564310);
  UI_AddSprite(this,0x1f50,0x1f,0x1b3,s_FOTORAHMEN00_spr_00564310);
  UI_AddSprite(this,0x1f52,0x265,0xff,s_FOTORAHMEN00_spr_00564310);
  UI_AddSprite(this,0x1f53,0x26a,0x104,s_FOTODUMMY00_spr_00564300);
  UI_AddSprite(this,0x1f54,0x24,0x44,s_FOTODUMMY00_spr_00564300);
  UI_AddSprite(this,0x1f55,0x24,0x82,s_FOTODUMMY00_spr_00564300);
  UI_AddSprite(this,0x1f56,0x24,0xfe,s_FOTODUMMY00_spr_00564300);
  UI_AddSprite(this,0x1f57,0x24,0xc0,s_FOTODUMMY00_spr_00564300);
  UI_AddSprite(this,0x1f58,0x24,0x17a,s_FOTODUMMY00_spr_00564300);
  UI_AddSprite(this,0x1f59,0x24,0x13c,s_FOTODUMMY00_spr_00564300);
  UI_AddSprite(this,0x1f5a,0x24,0x1b8,s_FOTODUMMY00_spr_00564300);
  UI_AddImage(this,0x1f5e,0x2bf,0x113,s_PB22_00_spr_00564174,0,0);
  iVar1 = UI_AddTextButton(this,0x1f5f,0x2b0,0xff,s_VERDANA8_fnt_00563e98,s__Filialname_005644d4,0,
                           s_TEXTPB05__00_spr_00564160);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x1f5f,0,0,0);
    Gadget_SetButtonTextLayout(this,0x1f5f,2,100,0,0,0xfffe);
  }
  UI_AddImage(this,0x1f60,0x2de,0x113,s_PB24_00_spr_00564144,0,0);
  UI_AddImage(this,0x1f62,0x2fc,0x114,s_PB33_00_spr_00564ba0,0,0);
  iVar1 = UI_CreateSlider(this,0x452,0x263,0x160,0x5f,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xffc600;
    local_c = 0xffc600;
    local_8 = 0xffc600;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x452,&local_10);
  }
  iVar1 = UI_CreateSlider(this,0x453,0x263,0x160,0x5f,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x453,&local_10);
  }
  iVar1 = UI_CreateSlider(this,0x454,0x263,0x177,0x5f,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xffc600;
    local_c = 0xffc600;
    local_8 = 0xffc600;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x454,&local_10);
  }
  iVar1 = UI_CreateSlider(this,0x455,0x263,0x177,0x5f,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x455,&local_10);
  }
  iVar1 = UI_CreateSlider(this,0x456,0x263,0x18e,0x5f,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xffc600;
    local_c = 0xffc600;
    local_8 = 0xffc600;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x456,&local_10);
  }
  iVar1 = UI_CreateSlider(this,0x457,0x263,0x18e,0x5f,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x457,&local_10);
  }
  iVar1 = UI_CreateSlider(this,0x458,0x263,0x1a5,0x5f,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xffc600;
    local_c = 0xffc600;
    local_8 = 0xffc600;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x458,&local_10);
  }
  iVar1 = UI_CreateSlider(this,0x459,0x263,0x1a5,0x5f,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x459,&local_10);
  }
  return this;
}

