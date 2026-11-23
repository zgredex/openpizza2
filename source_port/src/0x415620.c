// Screen_PersonnelOverview: ported from Pizza Connection 2 at 0x415620.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x415620
#include "pc2_port.h"


void * __cdecl Screen_PersonnelOverview(int *arg1)

{
  int value1;
  void *self;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
                    /* Builds the branch personnel overview page. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_00495560);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(self,0x46a,0x35,0xf2,s_PERSOUEBER_00_spr_005645d0);
  UI_AddSprite(self,0x46b,0x61,0xf2,s_PERSOUEBER_01_spr_005645bc);
  UI_AddSprite(self,0x46c,0x8d,0xf2,s_PERSOUEBER_02_spr_005645a8);
  UI_AddSprite(self,0x46d,0xb9,0xf2,s_PERSOUEBER_03_spr_00564594);
  UI_AddSprite(self,0x408,0x27,0x129,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x487,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_005827dc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x487,0);
    Window_GadgetNotify_Text_SetLayout(self,0x487,2,0xbe,0,0);
  }
  value1 = UI_AddText(self,0x488,0x35,0xb9,s_VERDANA7_fnt_00563ec8,DAT_005818c4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x488,0);
    Window_GadgetNotify_Text_SetLayout(self,0x488,2,0x46,0,0);
  }
  value1 = UI_AddText(self,0x489,0x98,0xb9,s_VERDANA7_fnt_00563ec8,DAT_00581784);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x489,0);
    Window_GadgetNotify_Text_SetLayout(self,0x489,2,0x46,0,0);
  }
  value1 = UI_AddText(self,0x48a,0x35,0xa3,s_VERDANA7_fnt_00563ec8,DAT_00581b18);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x48a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x48a,2,0x46,0,0);
  }
  value1 = UI_AddText(self,0x48b,0x88,0xa3,s_VERDANA7_fnt_00563ec8,DAT_00581000);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x48b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x48b,2,100,0,0);
  }
  value1 = UI_CreateSlider(self,0x465,0x34,0xca,0x50,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x465,&local_10);
  }
  value1 = UI_CreateSlider(self,0x466,0x34,0xb4,0x50,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x466,&local_10);
  }
  value1 = UI_CreateSlider(self,0x468,0x97,0xb4,0x50,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x468,&local_10);
  }
  value1 = UI_CreateSlider(self,0x469,0x97,0xca,0x50,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x469,&local_10);
  }
  UI_AddImage(self,0x460,0x35,0x5f,s_PB22_00_spr_00564174,0,0);
  UI_AddImage(self,0x461,0x5d,0x5f,s_PB24_00_spr_00564144,0,0);
  value1 = UI_AddTextButton(self,0x48e,0x8f,100,s_VERDANA8_fnt_00563e98,DAT_0058229c,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x48e,0,0,0);
    Gadget_SetButtonTextLayout(self,0x48e,2,0x54,0,0,0xfffe);
  }
  UI_AddSprite(self,0x528,99,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x529,99,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x52a,99,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x52b,99,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x52c,99,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x52d,99,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x52e,99,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x52f,99,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x530,99,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x531,99,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x532,99,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x533,99,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x534,99,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x535,99,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x536,99,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x537,99,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x538,99,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x539,0x95,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x53a,0x95,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x53b,0x95,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x53c,0x95,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x53d,0x95,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x53e,0x95,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x53f,0x95,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x540,0x95,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x541,0x95,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x542,0x95,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x543,0x95,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x544,0x95,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x545,0x95,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x546,0x95,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x547,0x95,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x548,0x95,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x549,0x95,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x54a,199,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x54b,199,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x54c,199,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x54d,199,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x54e,199,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x54f,199,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x550,199,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x551,199,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x552,199,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x553,199,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x554,199,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x555,199,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x556,199,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x557,199,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x558,199,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x559,199,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x55a,199,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x55b,0x31,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x55c,0x31,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x55d,0x31,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x55e,0x31,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x55f,0x31,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x560,0x31,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x561,0x31,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x562,0x31,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x563,0x31,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x564,0x31,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x565,0x31,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x566,0x31,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x567,0x31,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x568,0x31,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x569,0x31,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x56a,0x31,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x56b,0x31,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x56c,99,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x56d,99,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x56e,99,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x56f,99,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x570,99,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x571,99,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x572,99,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x573,99,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x574,99,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x575,99,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x576,99,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x577,99,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x578,99,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x579,99,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x57a,99,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x57b,99,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x57c,99,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x57d,0x95,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x57e,0x95,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x57f,0x95,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x580,0x95,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x581,0x95,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x582,0x95,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x583,0x95,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x584,0x95,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x585,0x95,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x586,0x95,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x587,0x95,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x588,0x95,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x589,0x95,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x58a,0x95,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x58b,0x95,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x58c,0x95,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x58d,0x95,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x58e,199,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x58f,199,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x590,199,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x591,199,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x592,199,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x593,199,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x594,199,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x595,199,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x596,199,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x597,199,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x598,199,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x599,199,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x59a,199,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x59b,199,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x59c,199,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x59d,199,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x59e,199,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x59f,0x31,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x5a0,0x31,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x5a1,0x31,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x5a2,0x31,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x5a3,0x31,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x5a4,0x31,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x5a5,0x31,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x5a6,0x31,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x5a7,0x31,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x5a8,0x31,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x5a9,0x31,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x5aa,0x31,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x5ab,0x31,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x5ac,0x31,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x5ad,0x31,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x5ae,0x31,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x5af,0x31,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  value1 = UI_AddText(self,0x5b0,0x27,0x130,s_VERDANA7_fnt_00563ec8,DAT_00580bec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5b0,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5b0,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x5b1,0x58,0x130,s_VERDANA7_fnt_00563ec8,DAT_005816d4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5b1,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5b1,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x5b2,0x8a,0x130,s_VERDANA7_fnt_00563ec8,DAT_00582974);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5b2,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5b2,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x5b3,0xbc,0x130,s_VERDANA7_fnt_00563ec8,DAT_0058234c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5b3,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5b3,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x5b4,0x27,0x154,s_VERDANA7_fnt_00563ec8,DAT_00580e64);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5b4,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5b4,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x5b5,0x58,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582e08);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5b5,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5b5,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x5b6,0x89,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582770);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5b6,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5b6,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x5b7,0xba,0x154,s_VERDANA7_fnt_00563ec8,DAT_005810a4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5b7,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5b7,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x5c0,0x7f,0x48,s_VERDANA8_fnt_00563e98,DAT_00581ba8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5c0,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5c0,0,0x46,0,0);
  }
  value1 = UI_AddText(self,0x5c1,0x7f,0x54,s_VERDANA8_fnt_00563e98,DAT_0058293c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5c1,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5c1,0,0x37,0,0);
  }
  value1 = UI_AddText(self,0x5c2,0xab,0x54,s_VERDANA8_fnt_00563e98,s__56456__0056458c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5c2,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5c2,1,0x3c,0,0);
  }
  value1 = UI_AddText(self,0x5c3,0xbe,0x48,s_VERDANA8_fnt_00563e98,&DAT_00564478);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5c3,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5c3,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x5c4,0x7f,0x26,s_VERDANA8_fnt_00563e98,s__Carlos_Estarda_00564468);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5c4,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5c4,0,0x6c,0,0);
  }
  value1 = UI_AddText(self,0x5c5,0x7f,0x32,s_VERDANA8_fnt_00563e98,DAT_00581228);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5c5,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5c5,0,0x32,0,0);
  }
  value1 = UI_AddText(self,0x5c6,0x7f,0x3d,s_VERDANA8_fnt_00563e98,s__Koch_00564460);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5c6,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5c6,0,0x6c,0,0);
  }
  value1 = UI_AddText(self,0x5c7,0xbe,0x32,s_VERDANA8_fnt_00563e98,&DAT_0056445c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5c7,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5c7,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x5c9,0x40,0xf6,s_VERDANA7_fnt_00563ec8,&DAT_0056445c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5c9,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5c9,1,0x19,0,0);
  }
  value1 = UI_AddText(self,0x5ca,0x6d,0xf6,s_VERDANA7_fnt_00563ec8,&DAT_0056445c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5ca,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5ca,1,0x19,0,0);
  }
  value1 = UI_AddText(self,0x5cb,0x97,0xf6,s_VERDANA7_fnt_00563ec8,&DAT_0056445c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5cb,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5cb,1,0x19,0,0);
  }
  value1 = UI_AddText(self,0x5cc,0xc4,0xf6,s_VERDANA7_fnt_00563ec8,&DAT_0056445c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x5cc,0);
    Window_GadgetNotify_Text_SetLayout(self,0x5cc,1,0x19,0,0);
  }
  UI_AddImage(self,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  UI_AddSprite(self,0x1f42,0x34,0x25,s_FOTORAHMEN00_spr_00564310);
  UI_AddSprite(self,0x1f43,0x39,0x2a,s_FOTODUMMY00_spr_00564300);
  value1 = UI_AddTextButton(self,0x1f45,0x8e,0x112,s_VERDANA8_fnt_00563e98,DAT_00581adc,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x1f45,0,0,0);
    Gadget_SetButtonTextLayout(self,0x1f45,2,0x54,0,0,0xfffe);
  }
  UI_AddSprite(self,0x1f46,0x27,0x10b,s_TRENNZEILE_spr_00563eb8);
  UI_AddSprite(self,0x1f48,0x39,0xe0,s_PERSOPLANLIGHT_spr_00564498);
  value1 = UI_AddText(self,0x1f49,0x38,0xd5,s_VERDANA7_fnt_00563ec8,&DAT_00564220);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f49,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f49,0,0,0,0);
  }
  value1 = UI_AddText(self,0x1f4a,0x4b,0xd5,s_VERDANA7_fnt_00563ec8,&DAT_0056421c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f4a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f4a,0,0,0,0);
  }
  value1 = UI_AddText(self,0x1f4b,0x60,0xd5,s_VERDANA7_fnt_00563ec8,&DAT_00564218);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f4b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f4b,0,0,0,0);
  }
  value1 = UI_AddText(self,0x1f4c,0x73,0xd5,s_VERDANA7_fnt_00563ec8,&DAT_00564214);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f4c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f4c,0,0,0,0);
  }
  value1 = UI_AddText(self,0x1f4d,0x84,0xd5,s_VERDANA7_fnt_00563ec8,&DAT_00564210);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f4d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f4d,0,0,0,0);
  }
  value1 = UI_AddText(self,0x1f4e,0x98,0xd5,s_VERDANA7_fnt_00563ec8,&DAT_0056420c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f4e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f4e,0,0,0,0);
  }
  value1 = UI_AddText(self,0x1f4f,0xac,0xd5,s_VERDANA7_fnt_00563ec8,&DAT_00564208);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f4f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f4f,0,0,0,0);
  }
  value1 = UI_AddText(self,0x1f50,0xc0,0xd5,s_VERDANA7_fnt_00563ec8,&DAT_00564204);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f50,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f50,0,0,0,0);
  }
  value1 = UI_AddText(self,0x1f51,0xd3,0xd5,s_VERDANA7_fnt_00563ec8,&DAT_00564200);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f51,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f51,0,0,0,0);
  }
  value1 = UI_CreateSlider(self,0x1f53,0x3a,0xe7,0x8c,s_PERSOSLIDERBLUE_00_spr_0056443c,0,0);
  if (value1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x1f53,&local_10);
  }
  value1 = UI_CreateSlider(self,0x1f54,0x3a,0xe7,0x8c,s_PERSOSLIDERGREEN_00_spr_00564424,0,0);
  if (value1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x1f54,&local_10);
  }
  value1 = UI_CreateSlider(self,0x1f55,0x3a,0xe7,0x8c,s_PERSOSLIDERRED_00_spr_0056440c,0,0);
  if (value1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x1f55,&local_10);
  }
  value1 = UI_CreateSlider(self,0x1f56,0x3a,0xe7,0x8c,s_PERSOSLIDERYELLOW_00_spr_005643f0,0,0);
  if (value1 != 0) {
    local_10 = 0xff00;
    local_c = 0xff00;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x1f56,&local_10);
  }
  UI_AddImage(self,0x1fa4,0x30,0x7c,s_PB16_ONOFF_00_spr_00564578,1,0);
  UI_AddImage(self,0x1fa6,0x78,0x7c,s_PB18_ONOFF_00_spr_00564564,1,0);
  UI_AddImage(self,0x1fa7,0x9c,0x7c,s_PB23_ONOFF_00_spr_00564550,1,0);
  UI_AddImage(self,0x1fa5,0x54,0x7c,s_PB21_ONOFF_00_spr_0056453c,1,0);
  UI_AddSprite(self,0x1f5b,0x27,9,s_PERSOSLIDERBLAU_00_spr_005643d8);
  UI_AddSprite(self,0x1f5c,0x4a,9,s_PERSOSLIDERBLAU_01_spr_005643c0);
  UI_AddSprite(self,0x1f5d,0x28,0x14,s_PERSOSLIDERGELB_00_spr_005643a8);
  UI_AddSprite(self,0x1f5e,0x47,0x14,s_PERSOSLIDERGELB_01_spr_00564390);
  UI_AddSprite(self,0x1f5f,0xac,6,s_PERSOSLIDERGRUEN_00_spr_00564378);
  UI_AddSprite(self,0x1f60,200,6,s_PERSOSLIDERGRUEN_01_spr_00564360);
  UI_AddSprite(self,0x1f61,0xa7,0x12,s_PERSOSLIDERROT_00_spr_00564348);
  UI_AddSprite(self,0x1f62,0xc6,0x10,s_PERSOSLIDERROT_01_spr_00564330);
  value1 = UI_AddText(self,0x1f63,0x31,0xba,s_VERDANA7_fnt_00563ec8,DAT_00582c14);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f63,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f63,0,0x3c,0,0);
  }
  value1 = UI_AddText(self,0x1f64,0x71,0xb9,s_VERDANA8_fnt_00563e98,&DAT_00564538);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f64,0xff);
    Window_GadgetNotify_Text_SetLayout(self,0x1f64,1,0x14,0,0);
  }
  value1 = UI_AddTextButton(self,0x1f67,0x30,0xa3,s_VERDANA8_fnt_00563e98,DAT_00581738,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x1f67,0,0,0);
    Gadget_SetButtonTextLayout(self,0x1f67,2,0x54,0,0,0xfffe);
  }
  value1 = UI_AddTextButton(self,0x1f68,0x8e,0xa3,s_VERDANA8_fnt_00563e98,DAT_0058229c,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x1f68,0,0,0);
    Gadget_SetButtonTextLayout(self,0x1f68,2,0x54,0,0,0xfffe);
  }
  value1 = UI_AddText(self,0x1f69,0x8e,0xba,s_VERDANA7_fnt_00563ec8,DAT_0058272c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f69,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f69,0,0x4b,0,0);
  }
  value1 = UI_AddText(self,0x1f6a,0xd2,0xb9,s_VERDANA8_fnt_00563e98,&DAT_00564538);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f6a,0xff);
    Window_GadgetNotify_Text_SetLayout(self,0x1f6a,1,0x14,0,0);
  }
  value1 = UI_AddText(self,0x1f6b,0x33,0xcd,s_VERDANA8_fnt_00563e98,DAT_00580fec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f6b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f6b,0,0x82,0,0);
  }
  value1 = UI_AddText(self,0x1f6c,0x83,0xcd,s_VERDANA8_fnt_00563e98,s__Stufe_1_0056452c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f6c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f6c,1,100,0,0);
  }
  UI_AddSprite(self,0x1f6d,0x42,0xe1,s_SCHLAGKRAFT_spr_0056451c);
  value1 = UI_AddText(self,0x1f6e,0x36,0xfa,s_VERDANA8_fnt_00563e98,&DAT_00564538);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f6e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f6e,2,0x2d,0,0);
  }
  UI_AddSprite(self,0x1f6f,0x80,0xe1,&DAT_0056450c);
  value1 = UI_AddText(self,0x1f70,0x74,0xfa,s_VERDANA8_fnt_00563e98,&DAT_00564508);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f70,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f70,2,0x2d,0,0);
  }
  UI_AddSprite(self,0x1f71,0xc1,0xe1,s_PANZERUNG_spr_005644f8);
  value1 = UI_AddText(self,0x1f72,0xb5,0xf9,s_VERDANA8_fnt_00563e98,&DAT_005644f4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f72,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f72,2,0x2d,0,0);
  }
  UI_AddImage(self,0x1fa8,0xc0,0x7c,s_PB70_ONOFF_00_spr_005644e0,1,0);
  UI_AddImage(self,0x1f77,0x2e,0x113,s_PB22_00_spr_00564174,0,0);
  value1 = UI_AddTextButton(self,0x1f78,0x42,0x114,s_VERDANA8_fnt_00563e98,s__Filialname_005644d4,0,
                           s_TEXTPB05__00_spr_00564160);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x1f78,0,0,0);
    Gadget_SetButtonTextLayout(self,0x1f78,2,0x93,0,0,0xfffe);
  }
  UI_AddImage(self,0x1f79,0xcf,0x113,s_PB24_00_spr_00564144,0,0);
  return self;
}
