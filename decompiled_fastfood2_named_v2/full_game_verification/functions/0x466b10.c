// rea decompile_all
// name: SubMenu_BuildPosterAdvertisingStatus
// address: 0x466b10
// body: available
// range: 0x466b10-0x468088 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl SubMenu_BuildPosterAdvertisingStatus(int *param_1)

{
  int iVar1;
  void *this;
  
                    /* Builds the poster-advertising status page. */
  iVar1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004c4ad0);
  *param_1 = iVar1;
  this = (void *)UI_FindWindowByID(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(this,0x427,99,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x428,99,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x429,99,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x42a,99,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x42b,99,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x42c,99,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x42d,99,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x42e,99,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x42f,99,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x430,99,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x431,99,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x432,99,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x433,99,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x434,99,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x435,99,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x436,99,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x437,99,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x438,0x95,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x439,0x95,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x43a,0x95,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x43b,0x95,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x43c,0x95,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x43d,0x95,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x43e,0x95,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x43f,0x95,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x440,0x95,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x441,0x95,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x442,0x95,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x443,0x95,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x444,0x95,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x445,0x95,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x446,0x95,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x447,0x95,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x448,0x95,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x449,199,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x44a,199,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,1099,199,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x44c,199,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x44d,199,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x44e,199,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x44f,199,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x450,199,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x451,199,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x452,199,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x453,199,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x454,199,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x455,199,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x456,199,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x457,199,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x458,199,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x459,199,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x45a,0x31,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x45b,0x31,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x45c,0x31,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x45d,0x31,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x45e,0x31,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x45f,0x31,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x460,0x31,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x461,0x31,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x462,0x31,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x463,0x31,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x464,0x31,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x465,0x31,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x466,0x31,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x467,0x31,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x468,0x31,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x469,0x31,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x46a,0x31,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x46b,99,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x46c,99,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x46d,99,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x46e,99,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x46f,99,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x470,99,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x471,99,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x472,99,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x473,99,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x474,99,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x475,99,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x476,99,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x477,99,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x478,99,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x479,99,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x47a,99,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x47b,99,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x47c,0x95,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x47d,0x95,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x47e,0x95,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x47f,0x95,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x480,0x95,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x481,0x95,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x482,0x95,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x483,0x95,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x484,0x95,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x485,0x95,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x486,0x95,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x487,0x95,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x488,0x95,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x489,0x95,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x48a,0x95,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x48b,0x95,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x48c,0x95,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x48d,199,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x48e,199,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x48f,199,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x490,199,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x491,199,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x492,199,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x493,199,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x494,199,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x495,199,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x496,199,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x497,199,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x498,199,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x499,199,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x49a,199,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x49b,199,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x49c,199,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x49d,199,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x49e,0x31,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x49f,0x31,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x4a0,0x31,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x4a1,0x31,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x4a2,0x31,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x4a3,0x31,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x4a4,0x31,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x4a5,0x31,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x4a6,0x31,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x4a7,0x31,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x4a8,0x31,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x4a9,0x31,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x4aa,0x31,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x4ab,0x31,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x4ac,0x31,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x4ad,0x31,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x4ae,0x31,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  iVar1 = UI_AddText(this,0x4af,0x27,0x130,s_VERDANA7_fnt_00563ec8,DAT_00580bec);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x4af,0);
    Window_GadgetNotify_Text_SetLayout(this,0x4af,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x4b0,0x58,0x130,s_VERDANA7_fnt_00563ec8,DAT_005816d4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x4b0,0);
    Window_GadgetNotify_Text_SetLayout(this,0x4b0,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x4b1,0x8a,0x130,s_VERDANA7_fnt_00563ec8,DAT_00582974);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x4b1,0);
    Window_GadgetNotify_Text_SetLayout(this,0x4b1,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x4b2,0xbc,0x130,s_VERDANA7_fnt_00563ec8,DAT_0058234c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x4b2,0);
    Window_GadgetNotify_Text_SetLayout(this,0x4b2,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x4b3,0x27,0x154,s_VERDANA7_fnt_00563ec8,DAT_00580e64);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x4b3,0);
    Window_GadgetNotify_Text_SetLayout(this,0x4b3,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x4b4,0x58,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582e08);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x4b4,0);
    Window_GadgetNotify_Text_SetLayout(this,0x4b4,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x4b5,0x89,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582770);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x4b5,0);
    Window_GadgetNotify_Text_SetLayout(this,0x4b5,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x4b6,0xba,0x154,s_VERDANA7_fnt_00563ec8,DAT_005810a4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x4b6,0);
    Window_GadgetNotify_Text_SetLayout(this,0x4b6,2,0x32,0,0);
  }
  UI_AddSprite(this,0x408,0x27,0x129,s_TRENNZEILE_spr_00563eb8);
  UI_AddSprite(this,0x409,0x27,0xf2,s_TRENNZEILE_spr_00563eb8);
  iVar1 = UI_AddText(this,0x40a,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00581658);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x40a,0);
    Window_GadgetNotify_Text_SetLayout(this,0x40a,2,0xbe,0,0);
  }
  iVar1 = UI_AddTextButton(this,0x417,0x8e,0x112,s_VERDANA8_fnt_00563e98,DAT_005820b4,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x417,0,0,0);
    Gadget_SetButtonTextLayout(this,0x417,2,0x54,0,0,0xfffe);
  }
  iVar1 = UI_AddText(this,0x41a,0x34,0x24,s_VERDANA7_fnt_00563ec8,DAT_00582aa8);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x41a,0);
    Window_GadgetNotify_Text_SetLayout(this,0x41a,0,0xb4,0,0);
  }
  iVar1 = UI_AddText(this,0x41b,0x36,0x2f,s_VERDANA8_fnt_00563e98,s__Pizza_Pasta_005667f0);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x41b,0);
    Window_GadgetNotify_Text_SetLayout(this,0x41b,0,0xaf,0,0);
  }
  iVar1 = UI_AddText(this,0x41c,0x34,0x75,s_VERDANA7_fnt_00563ec8,DAT_00581df4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x41c,0);
    Window_GadgetNotify_Text_SetLayout(this,0x41c,0,0xb4,0,0);
  }
  iVar1 = UI_AddText(this,0x41d,0x36,0x81,s_VERDANA8_fnt_00563e98,s__Gutes_Personal_00566aa4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x41d,0);
    Window_GadgetNotify_Text_SetLayout(this,0x41d,0,0xaf,0,0);
  }
  iVar1 = UI_AddText(this,0x41e,0x36,0x8f,s_VERDANA8_fnt_00563e98,&DAT_00566a90);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x41e,0);
    Window_GadgetNotify_Text_SetLayout(this,0x41e,0,0xaf,0,0);
  }
  iVar1 = UI_AddText(this,0x41f,0x36,0x9d,s_VERDANA8_fnt_00563e98,s__Schmackhafte_Rezepte_00566a78);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x41f,0);
    Window_GadgetNotify_Text_SetLayout(this,0x41f,0,0xb4,0,0);
  }
  iVar1 = UI_AddText(this,0x420,0x36,0xaa,s_VERDANA8_fnt_00563e98,&DAT_00566a64);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x420,0);
    Window_GadgetNotify_Text_SetLayout(this,0x420,0,0xaf,0,0);
  }
  iVar1 = UI_AddText(this,0x421,0x34,0xbb,s_VERDANA7_fnt_00563ec8,DAT_00581fc4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x421,0);
    Window_GadgetNotify_Text_SetLayout(this,0x421,0,0xb4,0,0);
  }
  iVar1 = UI_AddText(this,0x422,0x36,0xc6,s_VERDANA8_fnt_00563e98,s__Salami_00566a5c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x422,0);
    Window_GadgetNotify_Text_SetLayout(this,0x422,0,0xaf,0,0);
  }
  iVar1 = UI_AddText(this,0x423,0x34,0xd6,s_VERDANA7_fnt_00563ec8,DAT_00580f94);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x423,0);
    Window_GadgetNotify_Text_SetLayout(this,0x423,0,0xb4,0,0);
  }
  iVar1 = UI_AddText(this,0x424,0x36,0xe0,s_VERDANA8_fnt_00563e98,s__Pizza_Feuerstein_00566a48);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x424,0);
    Window_GadgetNotify_Text_SetLayout(this,0x424,0,0xaf,0,0);
  }
  iVar1 = UI_AddText(this,0x425,0x36,0xfd,s_VERDANA8_fnt_00563e98,DAT_005810bc);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x425,0);
    Window_GadgetNotify_Text_SetLayout(this,0x425,0,0xb4,0,0);
  }
  iVar1 = UI_AddText(this,0x426,0x32,0x114,s_VEDANA11_fnt_00564090,s__35000__00566a40);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x426,0);
    Window_GadgetNotify_Text_SetLayout(this,0x426,1,0x5a,0,0);
  }
  iVar1 = UI_AddText(this,0x4b7,0x34,0x5a,s_VERDANA7_fnt_00563ec8,DAT_00581498);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x4b7,0);
    Window_GadgetNotify_Text_SetLayout(this,0x4b7,0,0xb4,0,0);
  }
  iVar1 = UI_AddText(this,0x4b8,0x36,0x65,s_VERDANA8_fnt_00563e98,s__Jugendlich_00566a34);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x4b8,0);
    Window_GadgetNotify_Text_SetLayout(this,0x4b8,0,0xaf,0,0);
  }
  UI_AddImage(this,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  iVar1 = UI_AddText(this,0x1f41,0x34,0x3e,s_VERDANA7_fnt_00563ec8,DAT_00581bdc);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f41,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f41,0,0xb4,0,0);
  }
  iVar1 = UI_AddText(this,0x1f42,0x36,0x49,s_VERDANA8_fnt_00563e98,s__Filialname_005644d4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f42,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f42,0,0xaf,0,0);
  }
  return this;
}

