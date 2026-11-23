// Screen_BranchDetails: ported from Pizza Connection 2 at 0x451dd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x451dd0
#include "pc2_port.h"


void * __cdecl Screen_BranchDetails(int *arg1)

{
  int value1;
  void *self;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
                    /* Builds the own-branch restaurant detail page. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004bc860);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(self,0x408,0x27,0x129,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x501,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00581670);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x501,0);
    Window_GadgetNotify_Text_SetLayout(self,0x501,2,0xbe,0,0);
  }
  value1 = UI_AddText(self,0x502,0x30,0x75,s_VERDANA7_fnt_00563ec8,DAT_00581b18);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x502,0);
    Window_GadgetNotify_Text_SetLayout(self,0x502,2,0x5a,0,0);
  }
  value1 = UI_AddText(self,0x503,0x30,0x8c,s_VERDANA7_fnt_00563ec8,DAT_00581000);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x503,0);
    Window_GadgetNotify_Text_SetLayout(self,0x503,2,0x5a,0,0);
  }
  value1 = UI_AddText(self,0x504,0x30,0xa3,s_VERDANA7_fnt_00563ec8,DAT_00581784);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x504,0);
    Window_GadgetNotify_Text_SetLayout(self,0x504,2,0x5a,0,0);
  }
  value1 = UI_AddText(self,0x505,0x30,0xba,s_VERDANA7_fnt_00563ec8,DAT_005818c4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x505,0);
    Window_GadgetNotify_Text_SetLayout(self,0x505,2,0x5a,0,0);
  }
  value1 = UI_AddTextButton(self,0x50c,0x8e,0x62,s_VERDANA8_fnt_00563e98,DAT_005814b4,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x50c,0,0,0);
    Gadget_SetButtonTextLayout(self,0x50c,2,0x54,0,0,0xfffe);
  }
  value1 = UI_AddTextButton(self,0x50d,0x8e,0x7b,s_VERDANA8_fnt_00563e98,DAT_005820b4,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x50d,0,0,0);
    Gadget_SetButtonTextLayout(self,0x50d,2,0x54,0,0,0xfffe);
  }
  value1 = UI_AddTextButton(self,0x50e,0x8e,0x92,s_VERDANA8_fnt_00563e98,DAT_005820b4,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x50e,0,0,0);
    Gadget_SetButtonTextLayout(self,0x50e,2,0x54,0,0,0xfffe);
  }
  value1 = UI_AddTextButton(self,0x50f,0x8e,0xa9,s_VERDANA8_fnt_00563e98,DAT_005820b4,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x50f,0,0,0);
    Gadget_SetButtonTextLayout(self,0x50f,2,0x54,0,0,0xfffe);
  }
  value1 = UI_AddTextButton(self,0x510,0x8e,0xc0,s_VERDANA8_fnt_00563e98,DAT_005810a8,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x510,0,0,0);
    Gadget_SetButtonTextLayout(self,0x510,2,0x54,0,0,0xfffe);
  }
  value1 = UI_AddText(self,0x511,0x7e,0x47,s_VERDANA8_fnt_00563e98,DAT_00581ba8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x511,0);
    Window_GadgetNotify_Text_SetLayout(self,0x511,0,0x46,0,0);
  }
  value1 = UI_AddText(self,0x512,0x7e,0x53,s_VERDANA8_fnt_00563e98,DAT_0058293c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x512,0);
    Window_GadgetNotify_Text_SetLayout(self,0x512,0,0x37,0,0);
  }
  value1 = UI_AddText(self,0x513,0xa9,0x53,s_VERDANA8_fnt_00563e98,s__5656__0056447c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x513,0);
    Window_GadgetNotify_Text_SetLayout(self,0x513,1,0x37,0,0);
  }
  value1 = UI_AddText(self,0x514,0xb7,0x47,s_VERDANA8_fnt_00563e98,&DAT_00564478);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x514,0);
    Window_GadgetNotify_Text_SetLayout(self,0x514,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x515,0x7e,0x25,s_VERDANA8_fnt_00563e98,s__Carlos_Estarda_00564468);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x515,0);
    Window_GadgetNotify_Text_SetLayout(self,0x515,0,0x6c,0,0);
  }
  value1 = UI_AddText(self,0x516,0x7e,0x31,s_VERDANA8_fnt_00563e98,DAT_00581228);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x516,0);
    Window_GadgetNotify_Text_SetLayout(self,0x516,0,0x32,0,0);
  }
  value1 = UI_AddText(self,0x517,0x7e,0x3c,s_VERDANA8_fnt_00563e98,s__Koch_00564460);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x517,0);
    Window_GadgetNotify_Text_SetLayout(self,0x517,0,0x6c,0,0);
  }
  value1 = UI_AddText(self,0x518,0xb7,0x31,s_VERDANA8_fnt_00563e98,&DAT_0056445c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x518,0);
    Window_GadgetNotify_Text_SetLayout(self,0x518,1,0x28,0,0);
  }
  UI_AddSprite(self,0x519,0x27,0xf2,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x51a,0x2d,0xfd,s_VERDANA8_fnt_00563e98,DAT_0058281c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x51a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x51a,0,0x5a,0,0);
  }
  value1 = UI_AddText(self,0x51b,0x2d,0x116,s_VERDANA8_fnt_00563e98,s__Pizza_Tingeltangel_0056510c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x51b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x51b,0,0x87,0,0);
  }
  UI_AddSprite(self,0x51c,0xb5,0x104,s_LOGORAHMEN_00_spr_005650f8);
  UI_CreateBitmapGadget(self,0x51f,0xb7,0x106,0x2c,0x1d,0x10);
  UI_AddSprite(self,0x520,99,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x521,99,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x522,99,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x523,99,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x524,99,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x525,99,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x526,99,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x527,99,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x528,99,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x529,99,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x52a,99,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x52b,99,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x52c,99,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x52d,99,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x52e,99,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x52f,99,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x530,99,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x531,0x95,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x532,0x95,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x533,0x95,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x534,0x95,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x535,0x95,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x536,0x95,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x537,0x95,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x538,0x95,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x539,0x95,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x53a,0x95,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x53b,0x95,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x53c,0x95,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x53d,0x95,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x53e,0x95,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x53f,0x95,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x540,0x95,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x541,0x95,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x542,199,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x543,199,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x544,199,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x545,199,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x546,199,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x547,199,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x548,199,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x549,199,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x54a,199,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x54b,199,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x54c,199,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x54d,199,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x54e,199,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x54f,199,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x550,199,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x551,199,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x552,199,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x553,0x31,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x554,0x31,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x555,0x31,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x556,0x31,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x557,0x31,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x558,0x31,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x559,0x31,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x55a,0x31,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x55b,0x31,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x55c,0x31,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x55d,0x31,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x55e,0x31,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x55f,0x31,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x560,0x31,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x561,0x31,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x562,0x31,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x563,0x31,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x564,99,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x565,99,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x566,99,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x567,99,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x568,99,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x569,99,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x56a,99,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x56b,99,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x56c,99,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x56d,99,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x56e,99,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x56f,99,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x570,99,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x571,99,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x572,99,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x573,99,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x574,99,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x575,0x95,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x576,0x95,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x577,0x95,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x578,0x95,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x579,0x95,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x57a,0x95,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x57b,0x95,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x57c,0x95,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x57d,0x95,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x57e,0x95,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x57f,0x95,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x580,0x95,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x581,0x95,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x582,0x95,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x583,0x95,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x584,0x95,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x585,0x95,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x586,199,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x587,199,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x588,199,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x589,199,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x58a,199,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x58b,199,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x58c,199,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x58d,199,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x58e,199,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x58f,199,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x590,199,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x591,199,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x592,199,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x593,199,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x594,199,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x595,199,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x596,199,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x597,0x31,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x598,0x31,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x599,0x31,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x59a,0x31,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x59b,0x31,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x59c,0x31,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x59d,0x31,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x59e,0x31,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x59f,0x31,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x5a0,0x31,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x5a1,0x31,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x5a2,0x31,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x5a3,0x31,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x5a4,0x31,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x5a5,0x31,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x5a6,0x31,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x5a7,0x31,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  value1 = UI_AddText(self,0x5a8,0x27,0x130,s_VERDANA7_fnt_00563ec8,DAT_00580bec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5a8,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5a8,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x5a9,0x58,0x130,s_VERDANA7_fnt_00563ec8,DAT_005816d4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5a9,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5a9,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x5aa,0x8a,0x130,s_VERDANA7_fnt_00563ec8,DAT_00582974);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5aa,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5aa,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x5ab,0xbc,0x130,s_VERDANA7_fnt_00563ec8,DAT_0058234c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5ab,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5ab,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x5ac,0x27,0x154,s_VERDANA7_fnt_00563ec8,DAT_00580e64);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5ac,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5ac,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x5ad,0x58,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582e08);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5ad,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5ad,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x5ae,0x89,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582770);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5ae,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5ae,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x5af,0xba,0x154,s_VERDANA7_fnt_00563ec8,DAT_005810a4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5af,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5af,2,0x32,0,0);
  }
  UI_AddImage(self,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  value1 = UI_AddText(self,0x1f41,0x89,0xdf,s_VERDANA8_fnt_00563e98,s__Pizzeria_00566640);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f41,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f41,1,0x5a,0,0);
  }
  value1 = UI_AddText(self,0x1f42,0x33,0xdf,s_VERDANA8_fnt_00563e98,DAT_00582c18);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f42,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f42,0,0x5a,0,0);
  }
  value1 = UI_CreateSlider(self,9000,0x32,0x86,0x5f,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xffc600;
    local_c = 0xffc600;
    local_8 = 0xffc600;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,9000,&local_10);
  }
  value1 = UI_CreateSlider(self,0x2329,0x32,0x86,0x5f,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x2329,&local_10);
  }
  value1 = UI_CreateSlider(self,0x232a,0x32,0x9d,0x5f,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xffc600;
    local_c = 0xffc600;
    local_8 = 0xffc600;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x232a,&local_10);
  }
  value1 = UI_CreateSlider(self,0x232b,0x32,0x9d,0x5f,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x232b,&local_10);
  }
  value1 = UI_CreateSlider(self,0x232c,0x32,0xb4,0x5f,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xffc600;
    local_c = 0xffc600;
    local_8 = 0xffc600;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x232c,&local_10);
  }
  value1 = UI_CreateSlider(self,0x232d,0x32,0xb4,0x5f,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x232d,&local_10);
  }
  value1 = UI_CreateSlider(self,0x232e,0x32,0xcb,0x5f,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xffc600;
    local_c = 0xffc600;
    local_8 = 0xffc600;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x232e,&local_10);
  }
  value1 = UI_CreateSlider(self,0x232f,0x32,0xcb,0x5f,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x232f,&local_10);
  }
  value1 = UI_AddTextButton(self,0x2330,0x32,0x62,s_VERDANA8_fnt_00563e98,DAT_005814dc,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x2330,0,0,0);
    Gadget_SetButtonTextLayout(self,0x2330,2,0x54,0,0,0xfffe);
  }
  UI_AddSprite(self,0x2331,0x34,0x25,s_FOTORAHMEN00_spr_00564310);
  UI_AddSprite(self,0x2333,0x39,0x2a,s_FOTODUMMY00_spr_00564300);
  UI_AddSprite(self,0x2334,0xb7,0x106,s_PLAYLOG_8_01_02_spr_00564744);
  return self;
}
