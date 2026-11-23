// SubMenu_BuildRatingComparison: ported from Pizza Connection 2 at 0x448650.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x448650
#include "pc2_port.h"


void * __cdecl SubMenu_BuildRatingComparison(int *arg1)

{
  int value1;
  void *self;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
                    /* Builds the competitor rating comparison page. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004b89c0);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(self,0x505,0x2e,0x23,s_UEBMANA_spr_005642dc);
  UI_AddSprite(self,0x408,0x27,0x129,s_TRENNZEILE_spr_00563eb8);
  UI_AddSprite(self,0x409,0x27,0xf2,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x45c,0x41,0x45,s_VERDANA8_fnt_00563e98,DAT_0058168c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x45c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x45c,2,0x98,0,0);
  }
  value1 = UI_AddText(self,0x45d,0x41,0x61,s_VERDANA8_fnt_00563e98,DAT_00581f04);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x45d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x45d,2,0x98,0,0);
  }
  value1 = UI_AddText(self,0x45e,0x41,0x7d,s_VERDANA8_fnt_00563e98,DAT_005820bc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x45e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x45e,2,0x98,0,0);
  }
  value1 = UI_AddText(self,0x45f,0x41,0x99,s_VERDANA8_fnt_00563e98,DAT_00582754);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x45f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x45f,2,0x98,0,0);
  }
  value1 = UI_AddText(self,0x465,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_005825c0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x465,0);
    Window_GadgetNotify_Text_SetLayout(self,0x465,2,0xbe,0,0);
  }
  value1 = UI_CreateSlider(self,0x441,0x49,0x3c,0x8c,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x441,&local_10);
  }
  value1 = UI_CreateSlider(self,0x442,0x49,0x58,0x8c,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x442,&local_10);
  }
  value1 = UI_CreateSlider(self,0x443,0x49,0x74,0x8c,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xf300;
    local_c = 0xffff;
    local_8 = 0xff;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x443,&local_10);
  }
  value1 = UI_CreateSlider(self,0x444,0x49,0x90,0x8c,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x444,&local_10);
  }
  value1 = UI_AddText(self,0x500,0x2d,0xfd,s_VERDANA8_fnt_00563e98,DAT_0058281c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x500,0);
    Window_GadgetNotify_Text_SetLayout(self,0x500,0,0x5a,0,0);
  }
  value1 = UI_AddText(self,0x501,0x2d,0x116,s_VERDANA8_fnt_00563e98,s__Pizza_Tingeltangel_0056510c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x501,0);
    Window_GadgetNotify_Text_SetLayout(self,0x501,0,0x87,0,0);
  }
  UI_AddSprite(self,0x502,0xb5,0x104,s_LOGORAHMEN_00_spr_005650f8);
  UI_CreateBitmapGadget(self,0x506,0xb7,0x106,0x2c,0x1d,0x10);
  UI_AddSprite(self,0x507,99,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x508,99,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x509,99,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x50a,99,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x50b,99,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x50c,99,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x50d,99,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x50e,99,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x50f,99,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x510,99,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x511,99,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x512,99,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x513,99,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x514,99,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x515,99,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x516,99,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x517,99,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x518,0x95,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x519,0x95,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x51a,0x95,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x51b,0x95,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x51c,0x95,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x51d,0x95,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x51e,0x95,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x51f,0x95,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x520,0x95,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x521,0x95,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x522,0x95,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x523,0x95,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x524,0x95,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x525,0x95,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x526,0x95,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x527,0x95,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x528,0x95,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x529,199,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x52a,199,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x52b,199,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x52c,199,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x52d,199,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x52e,199,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x52f,199,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x530,199,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x531,199,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x532,199,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x533,199,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x534,199,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x535,199,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x536,199,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x537,199,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x538,199,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x539,199,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x53a,0x31,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x53b,0x31,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x53c,0x31,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x53d,0x31,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x53e,0x31,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x53f,0x31,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x540,0x31,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x541,0x31,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x542,0x31,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x543,0x31,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x544,0x31,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x545,0x31,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x546,0x31,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x547,0x31,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x548,0x31,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x549,0x31,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x54a,0x31,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x54b,99,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x54c,99,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x54d,99,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x54e,99,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x54f,99,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x550,99,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x551,99,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x552,99,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x553,99,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x554,99,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x555,99,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x556,99,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x557,99,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x558,99,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x559,99,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x55a,99,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x55b,99,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x55c,0x95,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x55d,0x95,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x55e,0x95,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x55f,0x95,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x560,0x95,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x561,0x95,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x562,0x95,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x563,0x95,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x564,0x95,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x565,0x95,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x566,0x95,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x567,0x95,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x568,0x95,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x569,0x95,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x56a,0x95,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x56b,0x95,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x56c,0x95,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x56d,199,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x56e,199,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x56f,199,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x570,199,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x571,199,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x572,199,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x573,199,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x574,199,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x575,199,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x576,199,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x577,199,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x578,199,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x579,199,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x57a,199,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x57b,199,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x57c,199,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x57d,199,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x57e,0x31,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x57f,0x31,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x580,0x31,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x581,0x31,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x582,0x31,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x583,0x31,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x584,0x31,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x585,0x31,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x586,0x31,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x587,0x31,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x588,0x31,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x589,0x31,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x58a,0x31,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x58b,0x31,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x58c,0x31,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x58d,0x31,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x58e,0x31,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  value1 = UI_AddText(self,0x58f,0x27,0x130,s_VERDANA7_fnt_00563ec8,DAT_00580bec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x58f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x58f,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x590,0x58,0x130,s_VERDANA7_fnt_00563ec8,DAT_005816d4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x590,0);
    Window_GadgetNotify_Text_SetLayout(self,0x590,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x591,0x8a,0x130,s_VERDANA7_fnt_00563ec8,DAT_00582974);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x591,0);
    Window_GadgetNotify_Text_SetLayout(self,0x591,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x592,0xbc,0x130,s_VERDANA7_fnt_00563ec8,DAT_0058234c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x592,0);
    Window_GadgetNotify_Text_SetLayout(self,0x592,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x593,0x27,0x154,s_VERDANA7_fnt_00563ec8,DAT_00580e64);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x593,0);
    Window_GadgetNotify_Text_SetLayout(self,0x593,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x594,0x58,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582e08);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x594,0);
    Window_GadgetNotify_Text_SetLayout(self,0x594,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x595,0x89,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582770);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x595,0);
    Window_GadgetNotify_Text_SetLayout(self,0x595,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x596,0xba,0x154,s_VERDANA7_fnt_00563ec8,DAT_005810a4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x596,0);
    Window_GadgetNotify_Text_SetLayout(self,0x596,2,0x32,0,0);
  }
  UI_AddImage(self,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  UI_AddSprite(self,0x1f41,0xb7,0x106,s_PLAYLOG_8_01_02_spr_00564744);
  value1 = UI_CreateSlider(self,3000,0x49,0xac,0x8c,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,3000,&local_10);
  }
  value1 = UI_AddText(self,0x1f42,0x41,0x29,s_VERDANA8_fnt_00563e98,DAT_00582c0c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f42,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f42,2,0x96,0,0);
  }
  return self;
}
