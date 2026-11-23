// SubMenu_BuildWarehouse: ported from Pizza Connection 2 at 0x45aad0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x45aad0
#include "pc2_port.h"


void * __cdecl SubMenu_BuildWarehouse(int *arg1)

{
  int value1;
  void *self;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
                    /* Builds the warehouse management page. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004c1060);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(self,0x408,0x27,0x129,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x454,0x27,0x130,s_VERDANA7_fnt_00563ec8,DAT_00580bec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x454,0);
    Window_GadgetNotify_Text_SetLayout(self,0x454,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x455,0x58,0x130,s_VERDANA7_fnt_00563ec8,DAT_005816d4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x455,0);
    Window_GadgetNotify_Text_SetLayout(self,0x455,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x456,0x8a,0x130,s_VERDANA7_fnt_00563ec8,DAT_00582974);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x456,0);
    Window_GadgetNotify_Text_SetLayout(self,0x456,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x457,0xbc,0x130,s_VERDANA7_fnt_00563ec8,DAT_0058234c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x457,0);
    Window_GadgetNotify_Text_SetLayout(self,0x457,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x458,0x27,0x154,s_VERDANA7_fnt_00563ec8,DAT_00580e64);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x458,0);
    Window_GadgetNotify_Text_SetLayout(self,0x458,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x459,0x58,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582e08);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x459,0);
    Window_GadgetNotify_Text_SetLayout(self,0x459,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x45a,0x89,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582770);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x45a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x45a,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x45b,0xba,0x154,s_VERDANA7_fnt_00563ec8,DAT_005810a4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x45b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x45b,2,0x32,0,0);
  }
  UI_AddSprite(self,0x53a,0x27,0xf2,s_TRENNZEILE_spr_00563eb8);
  UI_AddImage(self,0x53b,0x2c,0xf9,s_PB22_00_spr_00564174,0,0);
  value1 = UI_AddTextButton(self,0x53c,0x40,0xfa,s_VERDANA8_fnt_00563e98,s__Lagername_00566880,0,
                           s_TEXTPB05__00_spr_00564160);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x53c,0,0,0);
    Gadget_SetButtonTextLayout(self,0x53c,2,0x93,0,0,0xfffe);
  }
  UI_AddImage(self,0x53d,0xcd,0xf9,s_PB24_00_spr_00564144,0,0);
  value1 = UI_AddText(self,0x53f,0x2e,0x117,s_VERDANA7_fnt_00563ec8,DAT_005828c4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x53f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x53f,0,0x28,0,0);
  }
  value1 = UI_AddText(self,0x540,0x49,0x117,s_VERDANA7_fnt_00563ec8,s__1_000_00__00566874);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x540,0);
    Window_GadgetNotify_Text_SetLayout(self,0x540,1,0x46,0,0);
  }
  value1 = UI_AddTextButton(self,0x541,0x8e,0x112,s_VERDANA8_fnt_00563e98,&DAT_005641c4,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x541,0,0,0);
    Gadget_SetButtonTextLayout(self,0x541,2,0x54,0,0,0xfffe);
  }
  value1 = UI_AddText(self,0x542,0x41,0x23,s_VERDANA8_fnt_00563e98,DAT_00581d34);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x542,0);
    Window_GadgetNotify_Text_SetLayout(self,0x542,2,0x98,0,0);
  }
  value1 = UI_AddText(self,0x543,0x41,0x3f,s_VERDANA8_fnt_00563e98,DAT_00582e28);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x543,0);
    Window_GadgetNotify_Text_SetLayout(self,0x543,2,0x98,0,0);
  }
  value1 = UI_CreateSlider(self,0x544,0x4a,0x36,0x8c,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xaa00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x544,&local_10);
  }
  value1 = UI_CreateSlider(self,0x545,0x4a,0x52,0x8c,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xaa00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x545,&local_10);
  }
  value1 = UI_AddText(self,0x546,0x41,0x5b,s_VERDANA8_fnt_00563e98,DAT_00580b80);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x546,0);
    Window_GadgetNotify_Text_SetLayout(self,0x546,2,0x98,0,0);
  }
  value1 = UI_AddText(self,0x547,0x41,0x77,s_VERDANA8_fnt_00563e98,DAT_00582ca0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x547,0);
    Window_GadgetNotify_Text_SetLayout(self,0x547,2,0x98,0,0);
  }
  value1 = UI_CreateSlider(self,0x548,0x4a,0x6e,0x8c,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xaa00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x548,&local_10);
  }
  value1 = UI_CreateSlider(self,0x549,0x4a,0x8a,0x8c,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xaa00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x549,&local_10);
  }
  UI_AddSprite(self,0x54a,0x27,0x93,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddTextButton(self,0x54c,0x31,0xd8,s_VERDANA8_fnt_00563e98,DAT_00580adc,0,
                           s_TEXTPB05__00_spr_00564160);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x54c,0,0,0);
    Gadget_SetButtonTextLayout(self,0x54c,2,0xb2,0,0,0xfffe);
  }
  value1 = UI_CreateSlider(self,0x54e,0x34,0xcc,0x5a,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xaa00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x54e,&local_10);
  }
  value1 = UI_CreateSlider(self,0x54f,0x8f,0xcc,0x5a,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xaa00;
    local_c = 0xffff;
    local_8 = 0xff;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x54f,&local_10);
  }
  value1 = UI_AddText(self,0x550,0x32,0xba,s_VERDANA7_fnt_00563ec8,DAT_00582a18);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x550,0);
    Window_GadgetNotify_Text_SetLayout(self,0x550,2,0x5a,0,0);
  }
  value1 = UI_AddText(self,0x551,0x8c,0xba,s_VERDANA7_fnt_00563ec8,DAT_00581580);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x551,0);
    Window_GadgetNotify_Text_SetLayout(self,0x551,2,0x5a,0,0);
  }
  value1 = UI_AddText(self,0x552,0x2f,0x9b,s_VERDANA8_fnt_00563e98,DAT_00580c38);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x552,0);
    Window_GadgetNotify_Text_SetLayout(self,0x552,0,0x91,0,0);
  }
  UI_AddImage(self,0x553,0xd1,0x9b,s_PB33_00_spr_00564ba0,0,0);
  value1 = UI_AddText(self,0x554,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00581af8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x554,0);
    Window_GadgetNotify_Text_SetLayout(self,0x554,2,0xbe,0,0);
  }
  UI_AddImage(self,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  value1 = UI_AddText(self,0x1f41,0x3b,0xa8,s_VERDANA8_fnt_00563e98,s___Lieferant_00566868);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f41,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f41,1,0x91,0,0);
  }
  UI_AddSprite(self,9000,99,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x2329,99,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x232a,99,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x232b,99,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x232c,99,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x232d,99,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x232e,99,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x232f,99,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x2330,99,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x2331,99,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x2332,99,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x2333,99,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x2334,99,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x2335,99,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x2336,99,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x2337,99,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x2338,99,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x2339,0x95,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x233a,0x95,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x233b,0x95,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x233c,0x95,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x233d,0x95,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x233e,0x95,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x233f,0x95,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x2340,0x95,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x2341,0x95,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x2342,0x95,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x2343,0x95,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x2344,0x95,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x2345,0x95,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x2346,0x95,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x2347,0x95,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x2348,0x95,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x2349,0x95,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x234a,199,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x234b,199,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x234c,199,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x234d,199,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x234e,199,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x234f,199,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x2350,199,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x2351,199,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x2352,199,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x2353,199,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x2354,199,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x2355,199,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x2356,199,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x2357,199,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x2358,199,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x2359,199,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x235a,199,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x239f,0x31,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x23a0,0x31,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x23a1,0x31,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x23a2,0x31,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x23a3,0x31,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x23a4,0x31,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x23a5,0x31,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x23a6,0x31,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x23a7,0x31,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x23a8,0x31,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x23a9,0x31,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x23aa,0x31,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x23ab,0x31,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x23ac,0x31,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x23ad,0x31,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x23ae,0x31,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x23af,0x31,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x236c,99,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x236d,99,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x236e,99,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x236f,99,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x2370,99,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x235b,0x31,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x235c,0x31,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x235d,0x31,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x235e,0x31,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x235f,0x31,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x2360,0x31,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x2361,0x31,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x2362,0x31,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x2363,0x31,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x2364,0x31,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x2365,0x31,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x2366,0x31,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x2367,0x31,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x2368,0x31,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x2369,0x31,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x236a,0x31,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x236b,0x31,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x2371,99,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x2372,99,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x2373,99,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x2374,99,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x2375,99,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x2376,99,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x2377,99,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x2378,99,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x2379,99,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x237a,99,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x237b,99,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x237c,99,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x237d,0x95,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x237e,0x95,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x237f,0x95,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x2380,0x95,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x2381,0x95,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x2382,0x95,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x2383,0x95,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x2384,0x95,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x2385,0x95,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x2386,0x95,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x2387,0x95,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x2388,0x95,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x2389,0x95,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x238a,0x95,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x238b,0x95,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x238c,0x95,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x238d,0x95,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x238e,199,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x238f,199,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x2390,199,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x2391,199,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x2392,199,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x2393,199,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x2394,199,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x2395,199,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x2396,199,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x2397,199,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x2398,199,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x2399,199,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x239a,199,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x239b,199,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x239c,199,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x239d,199,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x239e,199,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  return self;
}
