// SubMenu_BuildCompetitorBranchInfo: ported from Pizza Connection 2 at 0x447310.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x447310
#include "pc2_port.h"


void * __cdecl SubMenu_BuildCompetitorBranchInfo(int *arg1)

{
  int value1;
  void *self;
  
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004b87a0);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(self,1000,99,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x3e9,99,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x3ea,99,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x3eb,99,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x3ec,99,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x3ed,99,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x3ee,99,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x3ef,99,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x3f0,99,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x3f1,99,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x3f2,99,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x3f3,99,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x3f4,99,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x3f5,99,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x3f6,99,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x3f7,99,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x3f8,99,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x3f9,0x95,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x3fa,0x95,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x3fb,0x95,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x3fc,0x95,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x3fd,0x95,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x3fe,0x95,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x3ff,0x95,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x400,0x95,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x401,0x95,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x402,0x95,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x403,0x95,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x404,0x95,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x405,0x95,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x406,0x95,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x407,0x95,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x408,0x95,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x409,0x95,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x40a,199,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x40b,199,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x40c,199,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x40d,199,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x40e,199,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x40f,199,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x410,199,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x411,199,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x412,199,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x413,199,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x414,199,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x415,199,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x416,199,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x417,199,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x418,199,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x419,199,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x41a,199,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x41b,0x31,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x41c,0x31,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x41d,0x31,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x41e,0x31,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x41f,0x31,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x420,0x31,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x421,0x31,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x422,0x31,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x423,0x31,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x424,0x31,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x425,0x31,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x426,0x31,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x427,0x31,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x428,0x31,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x429,0x31,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x42a,0x31,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x42b,0x31,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x42c,99,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x42d,99,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x42e,99,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x42f,99,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x430,99,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x431,99,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x432,99,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x433,99,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x434,99,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x435,99,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x436,99,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x437,99,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x438,99,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x439,99,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x43a,99,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x43b,99,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x43c,99,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x43d,0x95,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x43e,0x95,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x43f,0x95,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x440,0x95,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x441,0x95,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x442,0x95,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x443,0x95,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x444,0x95,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x445,0x95,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x446,0x95,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x447,0x95,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x448,0x95,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x449,0x95,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x44a,0x95,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,1099,0x95,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x44c,0x95,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x44d,0x95,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x44e,199,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x44f,199,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x450,199,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x451,199,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x452,199,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x453,199,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x454,199,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x455,199,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x456,199,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x457,199,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x458,199,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x459,199,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x45a,199,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x45b,199,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x45c,199,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x45d,199,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x45e,199,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x45f,0x31,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x460,0x31,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x461,0x31,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x462,0x31,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x463,0x31,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x464,0x31,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x465,0x31,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x466,0x31,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x467,0x31,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x468,0x31,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x469,0x31,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x46a,0x31,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x46b,0x31,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x46c,0x31,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x46d,0x31,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x46e,0x31,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x46f,0x31,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  value1 = UI_AddText(self,0x470,0x27,0x130,s_VERDANA7_fnt_00563ec8,DAT_00580bec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x470,0);
    Window_GadgetNotify_Text_SetLayout(self,0x470,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x471,0x58,0x130,s_VERDANA7_fnt_00563ec8,DAT_005816d4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x471,0);
    Window_GadgetNotify_Text_SetLayout(self,0x471,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x472,0x8a,0x130,s_VERDANA7_fnt_00563ec8,DAT_00582974);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x472,0);
    Window_GadgetNotify_Text_SetLayout(self,0x472,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x473,0xbc,0x130,s_VERDANA7_fnt_00563ec8,DAT_0058234c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x473,0);
    Window_GadgetNotify_Text_SetLayout(self,0x473,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x474,0x27,0x154,s_VERDANA7_fnt_00563ec8,DAT_00580e64);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x474,0);
    Window_GadgetNotify_Text_SetLayout(self,0x474,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x475,0x58,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582e08);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x475,0);
    Window_GadgetNotify_Text_SetLayout(self,0x475,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x476,0x89,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582770);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x476,0);
    Window_GadgetNotify_Text_SetLayout(self,0x476,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x477,0xba,0x154,s_VERDANA7_fnt_00563ec8,DAT_005810a4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x477,0);
    Window_GadgetNotify_Text_SetLayout(self,0x477,2,0x32,0,0);
  }
  UI_AddSprite(self,0x481,0x27,0xf2,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x483,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_005825cc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x483,0);
    Window_GadgetNotify_Text_SetLayout(self,0x483,2,0xbe,0xffff,0);
  }
  value1 = UI_AddText(self,0x487,0x2d,0xfd,s_VERDANA8_fnt_00563e98,DAT_0058281c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x487,0);
    Window_GadgetNotify_Text_SetLayout(self,0x487,0,0x5a,0,0);
  }
  value1 = UI_AddText(self,0x488,0x2d,0x116,s_VERDANA8_fnt_00563e98,s__Pizza_Tingeltangel_0056510c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x488,0);
    Window_GadgetNotify_Text_SetLayout(self,0x488,0,0x87,0,0);
  }
  UI_AddSprite(self,0x48e,0xb5,0x104,s_LOGORAHMEN_00_spr_005650f8);
  UI_AddSprite(self,0x491,0x27,0x129,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x492,0x2d,0xaf,s_VERDANA10_fnt_00563e64,DAT_00582a60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x492,0);
    Window_GadgetNotify_Text_SetLayout(self,0x492,2,0xb4,0,0);
  }
  value1 = UI_AddText(self,0x493,0x2d,0xc4,s_VERDANA8_fnt_00563e98,DAT_00582450);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x493,0);
    Window_GadgetNotify_Text_SetLayout(self,0x493,0,0x3c,0,0);
  }
  value1 = UI_AddText(self,0x494,0x2d,0xd3,s_VERDANA8_fnt_00563e98,DAT_005811c4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x494,0);
    Window_GadgetNotify_Text_SetLayout(self,0x494,0,0x3c,0,0);
  }
  value1 = UI_AddText(self,0x495,0x6b,0xc4,s_VERDANA8_fnt_00563e98,s__Sportlich_0056644c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x495,0);
    Window_GadgetNotify_Text_SetLayout(self,0x495,0,0x7d,0,0);
  }
  value1 = UI_AddText(self,0x496,0x6b,0xd3,s_VERDANA8_fnt_00563e98,&DAT_0056643c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x496,0);
    Window_GadgetNotify_Text_SetLayout(self,0x496,0,0x7d,0xffff,0);
  }
  UI_AddSprite(self,0x4a0,0x31,0x31,s_TAB04_spr_00564230);
  value1 = UI_AddText(self,0x4a1,0x4d,0x21,s_VERDANA10_fnt_00563e64,DAT_0058248c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4a1,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4a1,2,0x78,0,0);
  }
  value1 = UI_AddText(self,0x4aa,0x6b,0xe2,s_VERDANA8_fnt_00563e98,s__Einrichtung_Preis_00566428);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4aa,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4aa,0,0x7d,0xffff,0);
  }
  UI_AddImage(self,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  UI_AddSprite(self,0x1f51,0xb7,0x106,s_PLAYLOG_8_01_02_spr_00564744);
  return self;
}
