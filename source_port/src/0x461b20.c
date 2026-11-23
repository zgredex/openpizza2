// SubMenu_BuildKitchen: ported from Pizza Connection 2 at 0x461b20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x461b20
#include "pc2_port.h"


void * __cdecl SubMenu_BuildKitchen(int *arg1)

{
  int value1;
  void *self;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
                    /* Builds the kitchen management page. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004c36f0);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(self,0x4d2,99,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x4d3,99,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x585,0x2f,0x83,s_MOEBELRAHMEN_spr_00566960);
  UI_AddSprite(self,0x4d4,99,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x4d5,99,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x4d6,99,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x4d7,99,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x4d8,99,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x4d9,99,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x4da,99,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x4db,99,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x4dc,99,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x4dd,99,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x4de,99,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x4df,99,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x4e0,99,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x4e1,99,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x4e2,99,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x4e3,0x95,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x4e4,0x95,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x4e5,0x95,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x4e6,0x95,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x4e7,0x95,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x4e8,0x95,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x4e9,0x95,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x4ea,0x95,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x4eb,0x95,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x4ec,0x95,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x4ed,0x95,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x4ee,0x95,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x4ef,0x95,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x4f0,0x95,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x4f1,0x95,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x4f2,0x95,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x4f3,0x95,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x4f4,199,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x4f5,199,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x4f6,199,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x4f7,199,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x4f8,199,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x4f9,199,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x4fa,199,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x4fb,199,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x4fc,199,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x4fd,199,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x4fe,199,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x4ff,199,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x500,199,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x501,199,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x502,199,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x503,199,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x504,199,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x505,0x31,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x506,0x31,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x507,0x31,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x508,0x31,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x509,0x31,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x50a,0x31,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x50b,0x31,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x50c,0x31,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x50d,0x31,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x50e,0x31,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x50f,0x31,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x510,0x31,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x511,0x31,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x512,0x31,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x513,0x31,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x514,0x31,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x515,0x31,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x516,99,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x517,99,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x518,99,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x519,99,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x51a,99,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x51b,99,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x51c,99,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x51d,99,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x51e,99,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x51f,99,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x520,99,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x521,99,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x522,99,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x523,99,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x524,99,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x525,99,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x526,99,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x527,0x95,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x528,0x95,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x529,0x95,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x52a,0x95,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x52b,0x95,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x52c,0x95,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x52d,0x95,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x52e,0x95,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x52f,0x95,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x530,0x95,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x531,0x95,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x532,0x95,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x533,0x95,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x534,0x95,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x535,0x95,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x536,0x95,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x537,0x95,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x538,199,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x539,199,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x53a,199,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x53b,199,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x53c,199,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x53d,199,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x53e,199,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x53f,199,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x540,199,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x541,199,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x542,199,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x543,199,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x544,199,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x545,199,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x546,199,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x547,199,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x548,199,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x549,0x31,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x54a,0x31,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x54b,0x31,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x54c,0x31,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x54d,0x31,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x54e,0x31,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x54f,0x31,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x550,0x31,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x551,0x31,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x552,0x31,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x553,0x31,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x554,0x31,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x555,0x31,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x556,0x31,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x557,0x31,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x558,0x31,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x559,0x31,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  value1 = UI_AddText(self,0x55a,0x27,0x130,s_VERDANA7_fnt_00563ec8,DAT_00580bec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x55a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x55a,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x55b,0x58,0x130,s_VERDANA7_fnt_00563ec8,DAT_005816d4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x55b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x55b,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x55c,0x8a,0x130,s_VERDANA7_fnt_00563ec8,DAT_00582974);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x55c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x55c,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x55d,0xbc,0x130,s_VERDANA7_fnt_00563ec8,DAT_0058234c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x55d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x55d,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x55e,0x27,0x154,s_VERDANA7_fnt_00563ec8,DAT_00580e64);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x55e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x55e,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x55f,0x58,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582e08);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x55f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x55f,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x560,0x89,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582770);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x560,0);
    Window_GadgetNotify_Text_SetLayout(self,0x560,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x561,0xba,0x154,s_VERDANA7_fnt_00563ec8,DAT_005810a4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x561,0);
    Window_GadgetNotify_Text_SetLayout(self,0x561,2,0x32,0,0);
  }
  UI_AddSprite(self,0x408,0x27,0x129,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x428,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00582b04);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x428,0);
    Window_GadgetNotify_Text_SetLayout(self,0x428,2,0xbe,0,0);
  }
  UI_AddImage(self,0x404,0x2d,0xbc,s_PB22_00_spr_00564174,0,0);
  UI_AddImage(self,0x405,0x5d,0xbc,s_PB24_00_spr_00564144,0,0);
  value1 = UI_CreateSlider(self,0x586,0x31,0xe2,0x53,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xaa00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x586,&local_10);
  }
  value1 = UI_AddText(self,0x588,0x2a,0xd0,s_VERDANA7_fnt_00563ec8,DAT_00580f0c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x588,0);
    Window_GadgetNotify_Text_SetLayout(self,0x588,2,0x5a,0,0);
  }
  value1 = UI_AddText(self,0x589,0x75,0x83,s_VERDANA7_fnt_00563ec8,DAT_00580cfc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x589,0);
    Window_GadgetNotify_Text_SetLayout(self,0x589,0,0x32,0,0);
  }
  value1 = UI_AddText(self,0x58a,0x75,0x8f,s_VERDANA7_fnt_00563ec8,DAT_00580fd4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x58a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x58a,0,0x50,0,0);
  }
  value1 = UI_AddText(self,0x58b,0xc9,0x8f,s_VERDANA7_fnt_00563ec8,&DAT_005669b0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x58b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x58b,1,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x58c,0x75,0x9b,s_VERDANA7_fnt_00563ec8,DAT_00580c00);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x58c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x58c,0,0x50,0,0);
  }
  value1 = UI_AddText(self,0x58d,0xca,0x9b,s_VERDANA7_fnt_00563ec8,&DAT_005669b0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x58d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x58d,1,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x58e,0x75,0xa7,s_VERDANA7_fnt_00563ec8,DAT_00582e38);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x58e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x58e,0,0x41,0,0);
  }
  value1 = UI_AddText(self,0x58f,0xad,0xa7,s_VERDANA7_fnt_00563ec8,s__99_000__0056694c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x58f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x58f,1,0x3c,0,0);
  }
  value1 = UI_AddText(self,0x590,0x75,0xb3,s_VERDANA7_fnt_00563ec8,DAT_005816c0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x590,0);
    Window_GadgetNotify_Text_SetLayout(self,0x590,0,0x37,0,0);
  }
  value1 = UI_AddText(self,0x591,0xad,0xb3,s_VERDANA7_fnt_00563ec8,s__99_000__0056694c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x591,0);
    Window_GadgetNotify_Text_SetLayout(self,0x591,1,0x3c,0,0);
  }
  value1 = UI_AddTextButton(self,0x592,0x8e,0xbf,s_VERDANA8_fnt_00563e98,DAT_0058269c,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x592,0,0,0);
    Gadget_SetButtonTextLayout(self,0x592,2,0x54,0,0,0xfffe);
  }
  value1 = UI_AddTextButton(self,0x593,0x8e,0xd6,s_VERDANA8_fnt_00563e98,DAT_0058249c,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x593,0,0,0);
    Gadget_SetButtonTextLayout(self,0x593,2,0x54,0,0,0xfffe);
  }
  value1 = UI_AddText(self,0x594,0x6b,0xef,s_VERDANA8_fnt_00563e98,DAT_00581fc0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x594,0);
    Window_GadgetNotify_Text_SetLayout(self,0x594,0,0x3c,0,0);
  }
  value1 = UI_AddText(self,0x595,0x99,0xef,s_VERDANA8_fnt_00563e98,s__99_000__0056694c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x595,0);
    Window_GadgetNotify_Text_SetLayout(self,0x595,1,0x50,0,0);
  }
  value1 = UI_CreateSlider(self,0x5c6,0x31,0x10e,0x53,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xaa00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x5c6,&local_10);
  }
  value1 = UI_AddText(self,0x5c7,0x2a,0xfc,s_VERDANA7_fnt_00563ec8,DAT_00582ef0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5c7,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5c7,2,0x5a,0,0);
  }
  value1 = UI_AddTextButton(self,0x5c8,0x8e,0x102,s_VERDANA8_fnt_00563e98,DAT_0058249c,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x5c8,0,0,0);
    Gadget_SetButtonTextLayout(self,0x5c8,2,0x54,0,0,0xfffe);
  }
  value1 = UI_AddText(self,0x5c9,0x6b,0x11b,s_VERDANA8_fnt_00563e98,DAT_00581fc0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5c9,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5c9,0,0x3c,0,0);
  }
  value1 = UI_AddText(self,0x5ca,0x99,0x11b,s_VERDANA8_fnt_00563e98,s__99_000__0056694c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5ca,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5ca,1,0x50,0,0);
  }
  UI_AddSprite(self,0x5cb,0x27,0x79,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x5cc,0x42,0x2a,s_VERDANA8_fnt_00563e98,DAT_00582c70);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5cc,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5cc,2,0x98,0,0);
  }
  value1 = UI_AddText(self,0x5cd,0x41,0x53,s_VERDANA8_fnt_00563e98,DAT_0058294c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5cd,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5cd,2,0x98,0,0);
  }
  value1 = UI_CreateSlider(self,0x5ce,0x4a,0x40,0x8c,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xaa00;
    local_8 = 0xff;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x5ce,&local_10);
  }
  value1 = UI_CreateSlider(self,0x5cf,0x4a,0x68,0x8c,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x5cf,&local_10);
  }
  value1 = UI_AddText(self,0x5d2,0xb6,0x83,s_VERDANA7_fnt_00563ec8,&DAT_005669a4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5d2,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5d2,1,0x32,0,0);
  }
  UI_AddImage(self,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  UI_AddSprite(self,0x1f41,0x3d,0x8f,s_MENU_OFEN_MODE05_spr_0056698c);
  return self;
}
