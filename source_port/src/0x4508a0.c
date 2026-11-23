// SubMenu_BuildBranchOverview: ported from Pizza Connection 2 at 0x4508a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4508a0
#include "pc2_port.h"


void * __cdecl SubMenu_BuildBranchOverview(int *arg1)

{
  int value1;
  void *self;
  
                    /* Builds the branch-overview page. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004bc190);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(self,0x408,0x27,0x129,s_TRENNZEILE_spr_00563eb8);
  UI_AddSprite(self,0x537,99,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x538,99,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x539,99,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x53a,99,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x53b,99,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x53c,99,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x53d,99,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x53e,99,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x53f,99,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x540,99,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x541,99,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x542,99,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x543,99,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x544,99,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x545,99,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x546,99,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x547,99,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x548,0x95,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x549,0x95,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x54a,0x95,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x54b,0x95,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x54c,0x95,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x54d,0x95,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x54e,0x95,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x54f,0x95,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x550,0x95,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x551,0x95,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x552,0x95,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x553,0x95,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x554,0x95,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x555,0x95,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x556,0x95,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x557,0x95,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x558,0x95,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x559,199,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x55a,199,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x55b,199,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x55c,199,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x55d,199,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x55e,199,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x55f,199,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x560,199,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x561,199,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x562,199,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x563,199,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x564,199,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x565,199,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x566,199,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x567,199,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x568,199,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x569,199,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x56a,0x31,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x56b,0x31,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x56c,0x31,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x56d,0x31,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x56e,0x31,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x56f,0x31,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x570,0x31,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x571,0x31,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x572,0x31,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x573,0x31,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x574,0x31,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x575,0x31,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x576,0x31,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x577,0x31,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x578,0x31,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x579,0x31,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x57a,0x31,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x57b,99,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x57c,99,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x57d,99,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x57e,99,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x57f,99,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x580,99,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x581,99,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x582,99,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x583,99,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x584,99,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x585,99,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x586,99,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x587,99,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x588,99,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x589,99,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x58a,99,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x58b,99,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x58c,0x95,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x58d,0x95,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x58e,0x95,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x58f,0x95,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x590,0x95,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x591,0x95,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x592,0x95,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x593,0x95,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x594,0x95,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x595,0x95,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x596,0x95,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x597,0x95,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x598,0x95,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x599,0x95,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x59a,0x95,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x59b,0x95,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x59c,0x95,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x59d,199,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x59e,199,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x59f,199,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x5a0,199,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x5a1,199,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x5a2,199,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x5a3,199,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x5a4,199,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x5a5,199,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x5a6,199,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x5a7,199,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x5a8,199,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x5a9,199,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x5aa,199,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x5ab,199,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x5ac,199,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x5ad,199,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x5ae,0x31,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x5af,0x31,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x5b0,0x31,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x5b1,0x31,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x5b2,0x31,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x5b3,0x31,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x5b4,0x31,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x5b5,0x31,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x5b6,0x31,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x5b7,0x31,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x5b8,0x31,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x5b9,0x31,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x5ba,0x31,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x5bb,0x31,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x5bc,0x31,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x5bd,0x31,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x5be,0x31,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  value1 = UI_AddText(self,0x5bf,0x27,0x130,s_VERDANA7_fnt_00563ec8,DAT_00580bec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5bf,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5bf,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x5c0,0x58,0x130,s_VERDANA7_fnt_00563ec8,DAT_005816d4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5c0,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5c0,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x5c1,0x8a,0x130,s_VERDANA7_fnt_00563ec8,DAT_00582974);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5c1,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5c1,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x5c2,0xbc,0x130,s_VERDANA7_fnt_00563ec8,DAT_0058234c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5c2,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5c2,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x5c3,0x27,0x154,s_VERDANA7_fnt_00563ec8,DAT_00580e64);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5c3,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5c3,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x5c4,0x58,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582e08);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5c4,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5c4,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x5c5,0x89,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582770);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5c5,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5c5,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x5c6,0xba,0x154,s_VERDANA7_fnt_00563ec8,DAT_005810a4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5c6,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5c6,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x1f41,0x2c,5,s_TIMESFONT_fnt_00563ea8,s__Filiale_0056661c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f41,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f41,2,0xbe,0,0);
  }
  UI_AddSprite(self,0x1f42,0x27,0xf2,s_TRENNZEILE_spr_00563eb8);
  UI_AddImage(self,0x1f43,0x2c,0xf9,s_PB22_00_spr_00564174,0,0);
  value1 = UI_AddTextButton(self,0x1f44,0x40,0xfa,s_VERDANA8_fnt_00563e98,s__Filialname_005644d4,0,
                           s_TEXTPB05__00_spr_00564160);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x1f44,0,0,0);
    Gadget_SetButtonTextLayout(self,0x1f44,2,0x93,0,0,0xfffe);
  }
  UI_AddImage(self,0x1f45,0xcd,0xf9,s_PB24_00_spr_00564144,0,0);
  UI_AddImage(self,0x1f46,0xd0,0x112,s_PB33_00_spr_00564ba0,0,0);
  UI_AddSprite(self,0x1f49,0x31,0x31,s_TAB04_spr_00564230);
  UI_AddSprite(self,0x1f4a,0x41,0xc1,s_TAB05_spr_00564224);
  value1 = UI_AddText(self,0x1f4b,0x4d,0x21,s_VERDANA10_fnt_00563e64,DAT_0058248c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f4b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f4b,2,0x78,0,0);
  }
  value1 = UI_AddText(self,0x1f4c,0x4d,0xa8,s_VERDANA10_fnt_00563e64,DAT_00582d20);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f4c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f4c,2,0x78,0,0);
  }
  value1 = UI_AddText(self,0x1f4d,0x3f,0xb6,s_VERDANA7_fnt_00563ec8,&DAT_00564220);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f4d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f4d,0,0,0,0);
  }
  value1 = UI_AddText(self,0x1f4e,0x52,0xb6,s_VERDANA7_fnt_00563ec8,&DAT_0056421c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f4e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f4e,0,0,0,0);
  }
  value1 = UI_AddText(self,0x1f4f,0x67,0xb6,s_VERDANA7_fnt_00563ec8,&DAT_00564218);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f4f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f4f,0,0,0,0);
  }
  value1 = UI_AddText(self,0x1f50,0x7a,0xb6,s_VERDANA7_fnt_00563ec8,&DAT_00564214);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f50,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f50,0,0,0,0);
  }
  value1 = UI_AddText(self,0x1f51,0x8b,0xb6,s_VERDANA7_fnt_00563ec8,&DAT_00564210);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f51,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f51,0,0,0,0);
  }
  value1 = UI_AddText(self,0x1f52,0x9f,0xb6,s_VERDANA7_fnt_00563ec8,&DAT_0056420c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f52,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f52,0,0,0,0);
  }
  value1 = UI_AddText(self,0x1f53,0xb3,0xb6,s_VERDANA7_fnt_00563ec8,&DAT_00564208);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f53,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f53,0,0,0,0);
  }
  value1 = UI_AddText(self,0x1f54,199,0xb6,s_VERDANA7_fnt_00563ec8,&DAT_00564204);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f54,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f54,0,0,0,0);
  }
  value1 = UI_AddText(self,0x1f55,0xda,0xb6,s_VERDANA7_fnt_00563ec8,&DAT_00564200);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f55,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f55,0,0,0,0);
  }
  UI_AddImage(self,0x1f56,0x2e,0xb6,s_PB54_00_spr_005641f4,1,0);
  UI_AddImage(self,0x1f57,0x2e,0xc5,s_PB55_00_spr_005641e8,1,0);
  UI_AddImage(self,0x1f58,0x2e,0xd4,s_PB56_00_spr_005641dc,1,0);
  UI_AddImage(self,0x1f59,0x2e,0xe3,s_PB57_00_spr_005641d0,1,0);
  UI_CreateBitmapGadget(self,0x1f5a,0x41,0xc0,0xa1,0x32,0x10);
  UI_AddImage(self,0x1f63,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  value1 = UI_AddText(self,0x1f64,0x2f,0x116,s_VERDANA7_fnt_00563ec8,
                     s__Noch_kein_Lager_zugewiesen_00566600);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f64,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f64,0,0xa3,0,0);
  }
  return self;
}
