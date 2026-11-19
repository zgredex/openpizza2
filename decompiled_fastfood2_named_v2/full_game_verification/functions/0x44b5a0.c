// rea decompile_all
// name: Window_BuildBranchProductsPage
// address: 0x44b5a0
// body: available
// range: 0x44b5a0-0x44cc8f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl Window_BuildBranchProductsPage(int *param_1)

{
  int iVar1;
  void *this;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
                    /* Builds the branch-products page. */
  iVar1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004b9b40);
  *param_1 = iVar1;
  this = (void *)UI_FindWindowByID(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(this,0x408,0x27,0x129,s_TRENNZEILE_spr_00563eb8);
  UI_AddSprite(this,0x500,0x27,0xf2,s_TRENNZEILE_spr_00563eb8);
  iVar1 = UI_AddText(this,0x501,0x2d,0xfd,s_VERDANA8_fnt_00563e98,DAT_0058281c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x501,0);
    Window_GadgetNotify_Text_SetLayout(this,0x501,0,0x5a,0,0);
  }
  iVar1 = UI_AddText(this,0x502,0x2d,0x116,s_VERDANA8_fnt_00563e98,s__Pizza_Tingeltangel_0056510c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x502,0);
    Window_GadgetNotify_Text_SetLayout(this,0x502,0,0x87,0,0);
  }
  UI_AddSprite(this,0x503,0xb5,0x104,s_LOGORAHMEN_00_spr_005650f8);
  UI_CreateBitmapGadget(this,0x524,0xb7,0x106,0x2c,0x1d,0x10);
  UI_AddImage(this,0x506,0x31,0x26,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(this,0x507,0x31,0x3b,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(this,0x508,0x31,0x50,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(this,0x509,0x31,0x65,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(this,0x50a,0x31,0x7a,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(this,0x50b,0x31,0x8f,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(this,0x50c,0x31,0xa4,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(this,0x50d,0x31,0xb9,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(this,0x50e,0x31,0xce,s_TABPB01__00_spr_00564670,1,0);
  iVar1 = UI_CreateSlider(this,0x50f,0xdd,0x2d,0xb4,s_SL01_00_spr_0056448c,0,1);
  if (iVar1 != 0) {
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(this,0x50f,&local_10);
  }
  iVar1 = UI_AddText(this,0x511,0x35,0x28,s_VERDANA10_fnt_00563e64,s__Margerita_00564624);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x511,0);
    Window_GadgetNotify_Text_SetLayout(this,0x511,0,100,0,0);
  }
  iVar1 = UI_AddText(this,0x512,0x34,0x3d,s_VERDANA10_fnt_00563e64,s__Margerita_00564624);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x512,0);
    Window_GadgetNotify_Text_SetLayout(this,0x512,0,100,0,0);
  }
  iVar1 = UI_AddText(this,0x513,0x34,0x52,s_VERDANA10_fnt_00563e64,s__Margerita_00564624);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x513,0);
    Window_GadgetNotify_Text_SetLayout(this,0x513,0,100,0,0);
  }
  iVar1 = UI_AddText(this,0x514,0x34,0x67,s_VERDANA10_fnt_00563e64,s__Margerita_00564624);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x514,0);
    Window_GadgetNotify_Text_SetLayout(this,0x514,0,100,0,0);
  }
  iVar1 = UI_AddText(this,0x515,0x34,0x7c,s_VERDANA10_fnt_00563e64,s__Margerita_00564624);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x515,0);
    Window_GadgetNotify_Text_SetLayout(this,0x515,0,100,0,0);
  }
  iVar1 = UI_AddText(this,0x516,0x34,0x91,s_VERDANA10_fnt_00563e64,s__Margerita_00564624);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x516,0);
    Window_GadgetNotify_Text_SetLayout(this,0x516,0,100,0,0);
  }
  iVar1 = UI_AddText(this,0x517,0x34,0xa6,s_VERDANA10_fnt_00563e64,s__Margerita_00564624);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x517,0);
    Window_GadgetNotify_Text_SetLayout(this,0x517,0,100,0,0);
  }
  iVar1 = UI_AddText(this,0x518,0x34,0xbb,s_VERDANA10_fnt_00563e64,s__Margerita_00564624);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x518,0);
    Window_GadgetNotify_Text_SetLayout(this,0x518,0,100,0,0);
  }
  iVar1 = UI_AddText(this,0x519,0x34,0xd0,s_VERDANA10_fnt_00563e64,s__Margerita_00564624);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x519,0);
    Window_GadgetNotify_Text_SetLayout(this,0x519,0,100,0,0);
  }
  iVar1 = UI_AddText(this,0x51a,0x98,0x28,s_VERDANA10_fnt_00563e64,&DAT_0056461c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x51a,0);
    Window_GadgetNotify_Text_SetLayout(this,0x51a,1,0x37,0,0);
  }
  iVar1 = UI_AddText(this,0x51b,0x97,0x3d,s_VERDANA10_fnt_00563e64,&DAT_0056461c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x51b,0);
    Window_GadgetNotify_Text_SetLayout(this,0x51b,1,0x37,0,0);
  }
  iVar1 = UI_AddText(this,0x51c,0x97,0x52,s_VERDANA10_fnt_00563e64,&DAT_0056461c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x51c,0);
    Window_GadgetNotify_Text_SetLayout(this,0x51c,1,0x37,0,0);
  }
  iVar1 = UI_AddText(this,0x51d,0x97,0x67,s_VERDANA10_fnt_00563e64,&DAT_0056461c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x51d,0);
    Window_GadgetNotify_Text_SetLayout(this,0x51d,1,0x37,0,0);
  }
  iVar1 = UI_AddText(this,0x51e,0x97,0x7c,s_VERDANA10_fnt_00563e64,&DAT_0056461c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x51e,0);
    Window_GadgetNotify_Text_SetLayout(this,0x51e,1,0x37,0,0);
  }
  iVar1 = UI_AddText(this,0x51f,0x97,0x91,s_VERDANA10_fnt_00563e64,&DAT_0056461c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x51f,0);
    Window_GadgetNotify_Text_SetLayout(this,0x51f,1,0x37,0,0);
  }
  iVar1 = UI_AddText(this,0x520,0x97,0xa6,s_VERDANA10_fnt_00563e64,&DAT_0056461c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x520,0);
    Window_GadgetNotify_Text_SetLayout(this,0x520,1,0x37,0,0);
  }
  iVar1 = UI_AddText(this,0x521,0x97,0xbb,s_VERDANA10_fnt_00563e64,&DAT_0056461c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x521,0);
    Window_GadgetNotify_Text_SetLayout(this,0x521,1,0x37,0,0);
  }
  iVar1 = UI_AddText(this,0x522,0x97,0xd0,s_VERDANA10_fnt_00563e64,&DAT_0056461c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x522,0);
    Window_GadgetNotify_Text_SetLayout(this,0x522,1,0x37,0,0);
  }
  iVar1 = UI_AddText(this,0x523,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_0058274c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x523,0);
    Window_GadgetNotify_Text_SetLayout(this,0x523,2,0xbe,0,0);
  }
  UI_AddSprite(this,0x525,99,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x526,99,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x527,99,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x528,99,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x529,99,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x52a,99,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x52b,99,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x52c,99,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x52d,99,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x52e,99,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x52f,99,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x530,99,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x531,99,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x532,99,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x533,99,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x534,99,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x535,99,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x536,0x95,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x537,0x95,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x538,0x95,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x539,0x95,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x53a,0x95,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x53b,0x95,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x53c,0x95,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x53d,0x95,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x53e,0x95,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x53f,0x95,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x540,0x95,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x541,0x95,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x542,0x95,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x543,0x95,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x544,0x95,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x545,0x95,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x546,0x95,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x547,199,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x548,199,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x549,199,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x54a,199,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x54b,199,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x54c,199,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x54d,199,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x54e,199,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x54f,199,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x550,199,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x551,199,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x552,199,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x553,199,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x554,199,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x555,199,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x556,199,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x557,199,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x558,0x31,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x559,0x31,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x55a,0x31,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x55b,0x31,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x55c,0x31,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x55d,0x31,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x55e,0x31,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x55f,0x31,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x560,0x31,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x561,0x31,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x562,0x31,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x563,0x31,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x564,0x31,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x565,0x31,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x566,0x31,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x567,0x31,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x568,0x31,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x569,99,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x56a,99,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x56b,99,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x56c,99,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x56d,99,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x56e,99,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x56f,99,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x570,99,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x571,99,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x572,99,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x573,99,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x574,99,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x575,99,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x576,99,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x577,99,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x578,99,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x579,99,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x57a,0x95,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x57b,0x95,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x57c,0x95,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x57d,0x95,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x57e,0x95,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x57f,0x95,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x580,0x95,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x581,0x95,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x582,0x95,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x583,0x95,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x584,0x95,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x585,0x95,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x586,0x95,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x587,0x95,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x588,0x95,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x589,0x95,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x58a,0x95,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x58b,199,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x58c,199,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x58d,199,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x58e,199,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x58f,199,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x590,199,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x591,199,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x592,199,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x593,199,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x594,199,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x595,199,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x596,199,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x597,199,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x598,199,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x599,199,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x59a,199,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x59b,199,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(this,0x59c,0x31,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(this,0x59d,0x31,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(this,0x59e,0x31,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(this,0x59f,0x31,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(this,0x5a0,0x31,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(this,0x5a1,0x31,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(this,0x5a2,0x31,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(this,0x5a3,0x31,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(this,0x5a4,0x31,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(this,0x5a5,0x31,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(this,0x5a6,0x31,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(this,0x5a7,0x31,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(this,0x5a8,0x31,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(this,0x5a9,0x31,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(this,0x5aa,0x31,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(this,0x5ab,0x31,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(this,0x5ac,0x31,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  iVar1 = UI_AddText(this,0x5ad,0x27,0x130,s_VERDANA7_fnt_00563ec8,DAT_00580bec);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x5ad,0);
    Window_GadgetNotify_Text_SetLayout(this,0x5ad,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x5ae,0x58,0x130,s_VERDANA7_fnt_00563ec8,DAT_005816d4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x5ae,0);
    Window_GadgetNotify_Text_SetLayout(this,0x5ae,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x5af,0x8a,0x130,s_VERDANA7_fnt_00563ec8,DAT_00582974);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x5af,0);
    Window_GadgetNotify_Text_SetLayout(this,0x5af,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x5b0,0xbc,0x130,s_VERDANA7_fnt_00563ec8,DAT_0058234c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x5b0,0);
    Window_GadgetNotify_Text_SetLayout(this,0x5b0,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x5b1,0x27,0x154,s_VERDANA7_fnt_00563ec8,DAT_00580e64);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x5b1,0);
    Window_GadgetNotify_Text_SetLayout(this,0x5b1,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x5b2,0x58,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582e08);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x5b2,0);
    Window_GadgetNotify_Text_SetLayout(this,0x5b2,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x5b3,0x89,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582770);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x5b3,0);
    Window_GadgetNotify_Text_SetLayout(this,0x5b3,2,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x5b4,0xba,0x154,s_VERDANA7_fnt_00563ec8,DAT_005810a4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x5b4,0);
    Window_GadgetNotify_Text_SetLayout(this,0x5b4,2,0x32,0,0);
  }
  UI_AddImage(this,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  UI_AddSprite(this,0x1f41,0xb7,0x106,s_PLAYLOG_8_01_02_spr_00564744);
  return this;
}

