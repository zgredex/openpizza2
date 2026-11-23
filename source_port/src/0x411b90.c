// Window_BuildBranchPriceSettingsPage: ported from Pizza Connection 2 at 0x411b90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x411b90
#include "pc2_port.h"


void * __cdecl Window_BuildBranchPriceSettingsPage(int *arg1)

{
  int value1;
  void *self;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
                    /* Builds the branch price-settings page. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_00492d90);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(self,0x439,0x2e,0x23,s_UEBMANA_spr_005642dc);
  UI_AddSprite(self,0x468,99,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x469,99,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x46a,99,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x46b,99,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x46c,99,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x46d,99,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x46e,99,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x46f,99,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x470,99,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x471,99,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x472,99,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x473,99,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x474,99,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x475,99,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x476,99,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x477,99,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x478,99,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x479,0x95,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x47a,0x95,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x47b,0x95,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x47c,0x95,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x47d,0x95,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x47e,0x95,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x47f,0x95,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x480,0x95,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x481,0x95,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x482,0x95,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x483,0x95,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x484,0x95,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x485,0x95,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x486,0x95,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x487,0x95,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x488,0x95,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x489,0x95,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x48a,199,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x48b,199,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x48c,199,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x48d,199,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x48e,199,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x48f,199,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x490,199,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x491,199,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x492,199,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x493,199,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x494,199,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x495,199,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x496,199,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x497,199,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x498,199,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x499,199,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x49a,199,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x49b,0x31,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x49c,0x31,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x49d,0x31,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x49e,0x31,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x49f,0x31,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x4a0,0x31,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x4a1,0x31,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x4a2,0x31,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x4a3,0x31,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x4a4,0x31,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x4a5,0x31,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x4a6,0x31,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x4a7,0x31,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x4a8,0x31,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x4a9,0x31,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x4aa,0x31,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x4ab,0x31,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x4ac,99,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x4ad,99,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x4ae,99,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x4af,99,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x4b0,99,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x4b1,99,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x4b2,99,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x4b3,99,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x4b4,99,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x4b5,99,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x4b6,99,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x4b7,99,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x4b8,99,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x4b9,99,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x4ba,99,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x4bb,99,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x4bc,99,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x4bd,0x95,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x4be,0x95,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x4bf,0x95,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x4c0,0x95,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x4c1,0x95,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x4c2,0x95,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x4c3,0x95,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x4c4,0x95,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x4c5,0x95,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x4c6,0x95,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x4c7,0x95,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x4c8,0x95,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x4c9,0x95,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x4ca,0x95,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x4cb,0x95,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x4cc,0x95,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x4cd,0x95,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x4ce,199,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x4cf,199,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x4d0,199,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x4d1,199,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x4d2,199,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x4d3,199,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x4d4,199,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x4d5,199,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x4d6,199,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x4d7,199,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x4d8,199,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x4d9,199,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x4da,199,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x4db,199,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x4dc,199,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x4dd,199,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x4de,199,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x4df,0x31,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x4e0,0x31,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x4e1,0x31,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x4e2,0x31,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x4e3,0x31,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x4e4,0x31,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x4e5,0x31,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x4e6,0x31,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x4e7,0x31,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x4e8,0x31,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x4e9,0x31,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x4ea,0x31,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x4eb,0x31,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x4ec,0x31,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x4ed,0x31,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x4ee,0x31,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x4ef,0x31,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  value1 = UI_AddText(self,0x4f0,0x27,0x130,s_VERDANA7_fnt_00563ec8,DAT_00580bec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4f0,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4f0,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x4f1,0x58,0x130,s_VERDANA7_fnt_00563ec8,DAT_005816d4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4f1,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4f1,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x4f2,0x8a,0x130,s_VERDANA7_fnt_00563ec8,DAT_00582974);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4f2,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4f2,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x4f3,0xbc,0x130,s_VERDANA7_fnt_00563ec8,DAT_0058234c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4f3,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4f3,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x4f4,0x27,0x154,s_VERDANA7_fnt_00563ec8,DAT_00580e64);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4f4,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4f4,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x4f5,0x58,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582e08);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4f5,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4f5,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x4f6,0x89,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582770);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4f6,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4f6,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x4f7,0xba,0x154,s_VERDANA7_fnt_00563ec8,DAT_005810a4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4f7,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4f7,2,0x32,0,0);
  }
  UI_AddSprite(self,0x408,0x27,0x129,s_TRENNZEILE_spr_00563eb8);
  UI_AddSprite(self,0x409,0x27,0xf2,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x44f,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00581d30);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x44f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x44f,2,0xbe,0,0);
  }
  value1 = UI_AddText(self,0x450,0x41,0x45,s_VERDANA8_fnt_00563e98,DAT_00582f78);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x450,0);
    Window_GadgetNotify_Text_SetLayout(self,0x450,2,0x96,0,0);
  }
  value1 = UI_AddText(self,0x451,0x41,0x61,s_VERDANA8_fnt_00563e98,DAT_00580b34);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x451,0);
    Window_GadgetNotify_Text_SetLayout(self,0x451,2,0x96,0,0);
  }
  value1 = UI_AddText(self,0x452,0x41,0x7d,s_VERDANA8_fnt_00563e98,DAT_005820bc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x452,0);
    Window_GadgetNotify_Text_SetLayout(self,0x452,2,0x96,0,0);
  }
  value1 = UI_AddText(self,0x453,0x41,0x99,s_VERDANA8_fnt_00563e98,DAT_00582754);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x453,0);
    Window_GadgetNotify_Text_SetLayout(self,0x453,2,0x96,0,0);
  }
  value1 = UI_AddText(self,0x455,0x30,0xd0,s_VERDANA7_fnt_00563ec8,DAT_00582a48);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x455,0);
    Window_GadgetNotify_Text_SetLayout(self,0x455,0,0x8c,0,0);
  }
  value1 = UI_AddText(self,0x456,0x30,0xda,s_VERDANA7_fnt_00563ec8,DAT_00582240);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x456,0);
    Window_GadgetNotify_Text_SetLayout(self,0x456,0,0x8c,0,0);
  }
  value1 = UI_AddText(self,0x457,0x30,0xe5,s_VERDANA7_fnt_00563ec8,DAT_005818f4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x457,0);
    Window_GadgetNotify_Text_SetLayout(self,0x457,0,0x8c,0,0);
  }
  value1 = UI_AddText(self,0x458,0x53,0xf9,s_VERDANA10_fnt_00563e64,DAT_005817c4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x458,0);
    Window_GadgetNotify_Text_SetLayout(self,0x458,2,0x78,0,0);
  }
  value1 = UI_AddText(self,0x45a,0x3d,0x111,s_VERDANA7_fnt_00563ec8,DAT_00582a9c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x45a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x45a,0,0x2d,0,0);
  }
  value1 = UI_AddText(self,0x45c,0xa3,0x111,s_VERDANA7_fnt_00563ec8,DAT_00581544);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x45c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x45c,0,0x20,0,0);
  }
  value1 = UI_CreateSlider(self,3000,0x4a,0x3b,0x8c,s_SL02_00_spr_005642d0,0,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,3000,&local_10);
  }
  value1 = UI_CreateSlider(self,0x43a,0x4a,0x57,0x8c,s_SL02_00_spr_005642d0,0,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x43a,&local_10);
  }
  value1 = UI_CreateSlider(self,0x43b,0x4a,0x73,0x8c,s_SL02_00_spr_005642d0,0,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x43b,&local_10);
  }
  value1 = UI_CreateSlider(self,0x43c,0x4a,0x8f,0x8c,s_SL02_00_spr_005642d0,0,0);
  if (value1 != 0) {
    local_10 = 0xffff;
    local_c = 0x9aff;
    local_8 = 0xff;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x43c,&local_10);
  }
  value1 = UI_CreateSlider(self,0x43d,0x4a,0xab,0x8c,s_SL02_00_spr_005642d0,0,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x43d,&local_10);
  }
  UI_AddImage(self,0x436,0x69,0x10d,s_PB14_00_spr_005642c4,1,0);
  UI_AddImage(self,0x438,0xc3,0x10d,s_PB14_00_spr_005642c4,1,0);
  value1 = UI_AddText(self,0x4f8,0xa1,0xd0,s_VERDANA7_fnt_00563ec8,s__213213__005642b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4f8,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4f8,1,0x46,0,0);
  }
  value1 = UI_AddText(self,0x4f9,0xa1,0xda,s_VERDANA7_fnt_00563ec8,s__213213__005642b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4f9,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4f9,1,0x46,0,0);
  }
  value1 = UI_AddText(self,0x4fa,0xa1,0xe5,s_VERDANA7_fnt_00563ec8,s__213213__005642b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4fa,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4fa,1,0x46,0,0);
  }
  UI_AddImage(self,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  value1 = UI_AddText(self,0x1f42,0x30,0xc5,s_VERDANA7_fnt_00563ec8,DAT_00582dfc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f42,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f42,0,0x8c,0,0);
  }
  value1 = UI_AddText(self,0x1f43,0xa1,0xc5,s_VERDANA7_fnt_00563ec8,s__213213__005642b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f43,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f43,1,0x46,0,0);
  }
  value1 = UI_AddText(self,0x1f44,0x30,0xb6,s_VERDANA8_fnt_00563e98,DAT_00582f84);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f44,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f44,0,0xb4,0,0);
  }
  value1 = UI_AddText(self,0x1f45,0x41,0x29,s_VERDANA8_fnt_00563e98,DAT_00582c0c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f45,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f45,2,0x96,0,0);
  }
  return self;
}
