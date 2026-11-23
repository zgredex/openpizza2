// SubMenu_BuildMenuPlan: ported from Pizza Connection 2 at 0x41ed20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x41ed20
#include "pc2_port.h"


void * __cdecl SubMenu_BuildMenuPlan(int *arg1)

{
  int value1;
  void *self;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
                    /* Builds the menu-planning page. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_0049c670);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(self,0x46e,99,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x46f,99,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x470,99,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x471,99,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x472,99,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x473,99,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x474,99,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x475,99,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x476,99,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x477,99,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x478,99,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x479,99,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x47a,99,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x47b,99,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x47c,99,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x47d,99,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x47e,99,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x47f,0x95,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x480,0x95,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x481,0x95,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x482,0x95,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x483,0x95,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x484,0x95,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x485,0x95,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x486,0x95,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x487,0x95,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x488,0x95,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x489,0x95,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x48a,0x95,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x48b,0x95,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x48c,0x95,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x48d,0x95,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x48e,0x95,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x48f,0x95,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x490,199,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x491,199,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x492,199,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x493,199,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x494,199,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x495,199,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x496,199,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x497,199,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x498,199,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x499,199,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x49a,199,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x49b,199,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x49c,199,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x49d,199,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x49e,199,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x49f,199,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x4a0,199,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x4a1,0x31,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x4a2,0x31,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x4a3,0x31,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x4a4,0x31,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x4a5,0x31,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x4a6,0x31,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x4a7,0x31,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x4a8,0x31,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x4a9,0x31,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x4aa,0x31,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x4ab,0x31,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x4ac,0x31,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x4ad,0x31,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x4ae,0x31,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x4af,0x31,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x4b0,0x31,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x4b1,0x31,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x4b2,99,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x4b3,99,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x4b4,99,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x4b5,99,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x4b6,99,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x4b7,99,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x4b8,99,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x4b9,99,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x4ba,99,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x4bb,99,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x4bc,99,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x4bd,99,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x4be,99,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x4bf,99,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x4c0,99,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x4c1,99,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x4c2,99,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x4c3,0x95,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x4c4,0x95,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x4c5,0x95,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x4c6,0x95,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x4c7,0x95,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x4c8,0x95,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x4c9,0x95,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x4ca,0x95,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x4cb,0x95,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x4cc,0x95,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x4cd,0x95,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x4ce,0x95,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x4cf,0x95,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x4d0,0x95,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x4d1,0x95,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x4d2,0x95,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x4d3,0x95,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x4d4,199,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x4d5,199,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x4d6,199,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x4d7,199,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x4d8,199,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x4d9,199,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x4da,199,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x4db,199,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x4dc,199,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x4dd,199,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x4de,199,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x4df,199,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x4e0,199,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x4e1,199,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x4e2,199,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x4e3,199,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x4e4,199,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x4e5,0x31,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x4e6,0x31,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x4e7,0x31,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x4e8,0x31,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x4e9,0x31,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x4ea,0x31,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x4eb,0x31,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x4ec,0x31,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x4ed,0x31,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x4ee,0x31,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x4ef,0x31,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x4f0,0x31,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x4f1,0x31,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x4f2,0x31,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x4f3,0x31,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x4f4,0x31,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x4f5,0x31,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  value1 = UI_AddText(self,0x4f6,0x27,0x130,s_VERDANA7_fnt_00563ec8,DAT_00580bec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4f6,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4f6,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x4f7,0x58,0x130,s_VERDANA7_fnt_00563ec8,DAT_005816d4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4f7,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4f7,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x4f8,0x8a,0x130,s_VERDANA7_fnt_00563ec8,DAT_00582974);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4f8,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4f8,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x4f9,0xbc,0x130,s_VERDANA7_fnt_00563ec8,DAT_0058234c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4f9,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4f9,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x4fa,0x27,0x154,s_VERDANA7_fnt_00563ec8,DAT_00580e64);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4fa,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4fa,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x4fb,0x58,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582e08);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4fb,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4fb,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x4fc,0x89,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582770);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4fc,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4fc,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x4fd,0xba,0x154,s_VERDANA7_fnt_00563ec8,DAT_005810a4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4fd,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4fd,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x44d,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_0058274c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x44d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x44d,2,0xbe,0,0);
  }
  UI_AddSprite(self,0x408,0x27,0x129,s_TRENNZEILE_spr_00563eb8);
  UI_AddSprite(self,0x437,0x27,0x10b,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_CreateSlider(self,0x428,0xdc,0x2c,0x9e,s_SL01_00_spr_0056448c,0,1);
  if (value1 != 0) {
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x428,&local_10);
  }
  value1 = UI_AddTextButton(self,0x453,0x30,0x112,s_VERDANA8_fnt_00563e98,DAT_00581194,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x453,0,0,0);
    Gadget_SetButtonTextLayout(self,0x453,2,0x54,0,0,0xfffe);
  }
  value1 = UI_AddTextButton(self,0x454,0x8e,0x112,s_VERDANA8_fnt_00563e98,DAT_005825ec,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x454,0,0,0);
    Gadget_SetButtonTextLayout(self,0x454,2,0x54,0,0,0xfffe);
  }
  UI_AddImage(self,0x467,0x31,0x24,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x468,0x31,0x39,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x469,0x31,0x4e,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x46a,0x31,99,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x46b,0x31,0x78,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x46c,0x31,0x8d,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x46d,0x31,0xa2,s_TABPB01__00_spr_00564670,1,0);
  value1 = UI_AddTextButton(self,0x503,0x30,0xf3,s_VERDANA8_fnt_00563e98,DAT_00580f20,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x503,0,0,0);
    Gadget_SetButtonTextLayout(self,0x503,2,0x54,0,0,0xfffe);
  }
  value1 = UI_AddTextButton(self,0x504,0x8e,0xf3,s_VERDANA8_fnt_00563e98,DAT_00580e38,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x504,0,0,0);
    Gadget_SetButtonTextLayout(self,0x504,2,0x54,0,0,0xfffe);
  }
  UI_AddImage(self,0x505,0x31,0xb7,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x50c,0x30,0xd5,s_PB05x__00_spr_00564630,1,0);
  UI_AddImage(self,0x50d,0x82,0xd5,s_PB05x__00_spr_00564630,1,0);
  value1 = UI_AddText(self,0x50f,0x49,0xd9,s_VERDANA7_fnt_00563ec8,DAT_00582950);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x50f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x50f,0,0x41,0,0);
  }
  value1 = UI_AddText(self,0x510,0x9b,0xd9,s_VERDANA7_fnt_00563ec8,DAT_00580eac);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x510,0);
    Window_GadgetNotify_Text_SetLayout(self,0x510,0,0x4b,0,0);
  }
  value1 = UI_AddText(self,0x514,0x34,0xba,s_VERDANA8_fnt_00563e98,s__Margerita_00564624);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x514,0);
    Window_GadgetNotify_Text_SetLayout(self,0x514,0,0x6e,0,0);
  }
  value1 = UI_AddText(self,0x515,0x34,0xa5,s_VERDANA8_fnt_00563e98,s__Margerita_00564624);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x515,0);
    Window_GadgetNotify_Text_SetLayout(self,0x515,0,0x6e,0,0);
  }
  value1 = UI_AddText(self,0x516,0x34,0x90,s_VERDANA8_fnt_00563e98,s__Margerita_00564624);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x516,0);
    Window_GadgetNotify_Text_SetLayout(self,0x516,0,0x6e,0,0);
  }
  value1 = UI_AddText(self,0x517,0x34,0x7b,s_VERDANA8_fnt_00563e98,s__Margerita_00564624);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x517,0);
    Window_GadgetNotify_Text_SetLayout(self,0x517,0,0x6e,0,0);
  }
  value1 = UI_AddText(self,0x518,0x34,0x66,s_VERDANA8_fnt_00563e98,s__Margerita_00564624);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x518,0);
    Window_GadgetNotify_Text_SetLayout(self,0x518,0,0x6e,0,0);
  }
  value1 = UI_AddText(self,0x519,0x34,0x51,s_VERDANA8_fnt_00563e98,s__Margerita_00564624);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x519,0);
    Window_GadgetNotify_Text_SetLayout(self,0x519,0,0x6e,0,0);
  }
  value1 = UI_AddText(self,0x51a,0x34,0x3c,s_VERDANA8_fnt_00563e98,s__Margerita_00564624);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x51a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x51a,0,0x6e,0,0);
  }
  value1 = UI_AddText(self,0x51b,0x34,0x27,s_VERDANA8_fnt_00563e98,s__Margerita_00564624);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x51b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x51b,0,0x6e,0,0);
  }
  value1 = UI_AddText(self,0x51c,0x88,0x7b,s_VERDANA8_fnt_00563e98,&DAT_0056461c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x51c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x51c,1,0x46,0,0);
  }
  value1 = UI_AddText(self,0x51d,0x88,0x90,s_VERDANA8_fnt_00563e98,&DAT_0056461c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x51d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x51d,1,0x46,0,0);
  }
  value1 = UI_AddText(self,0x51e,0x88,0xa5,s_VERDANA8_fnt_00563e98,&DAT_0056461c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x51e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x51e,1,0x46,0,0);
  }
  value1 = UI_AddText(self,0x51f,0x88,0xba,s_VERDANA8_fnt_00563e98,&DAT_0056461c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x51f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x51f,1,0x46,0,0);
  }
  value1 = UI_AddText(self,0x520,0x88,0x27,s_VERDANA8_fnt_00563e98,&DAT_0056461c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x520,0);
    Window_GadgetNotify_Text_SetLayout(self,0x520,1,0x46,0,0);
  }
  value1 = UI_AddText(self,0x521,0x88,0x3c,s_VERDANA8_fnt_00563e98,&DAT_0056461c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x521,0);
    Window_GadgetNotify_Text_SetLayout(self,0x521,1,0x46,0,0);
  }
  value1 = UI_AddText(self,0x522,0x88,0x51,s_VERDANA8_fnt_00563e98,&DAT_0056461c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x522,0);
    Window_GadgetNotify_Text_SetLayout(self,0x522,1,0x46,0,0);
  }
  value1 = UI_AddText(self,0x523,0x88,0x66,s_VERDANA8_fnt_00563e98,&DAT_0056461c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x523,0);
    Window_GadgetNotify_Text_SetLayout(self,0x523,1,0x46,0,0);
  }
  UI_AddImage(self,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  return self;
}
