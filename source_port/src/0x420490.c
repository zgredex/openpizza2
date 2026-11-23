// SubMenu_BuildPizzaContest: ported from Pizza Connection 2 at 0x420490.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x420490
#include "pc2_port.h"


void * __cdecl SubMenu_BuildPizzaContest(int *arg1)

{
  int value1;
  void *self;
  
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_0049d190);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  value1 = UI_AddText(self,1000,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_005816b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,1000,0);
    Window_GadgetNotify_Text_SetLayout(self,1000,2,0xbe,0xffff,0);
  }
  UI_AddSprite(self,0x3e9,0x27,0xb6,s_TRENNZEILE_spr_00563eb8);
  UI_AddSprite(self,0x3f1,0xcc,0xcd,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x3f2,0xcc,0xcd,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x3f3,0xcc,0xcd,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x3f4,0xcc,0xcd,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x3f5,0xcc,0xcd,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x3f6,0xcc,0xcd,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x3f7,0xcc,0xcd,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x3f8,0xcc,0xcd,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x3f9,0xcc,0xcd,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x3fa,0xcc,0xcd,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x3fb,0xcc,0xcd,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x3fc,0xcc,0xcd,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x3fd,0xcc,0xcd,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x3fe,0xcc,0xcd,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x3ff,0xcc,0xcd,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x400,0xcc,0xcd,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x401,0xcc,0xcd,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddImage(self,0x402,0x30,0xee,s_PB33_00_spr_00564ba0,1,0);
  UI_AddSprite(self,0x403,0xcc,0xeb,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x404,0xcc,0xeb,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x405,0xcc,0xeb,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x406,0xcc,0xeb,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x407,0xcc,0xeb,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x408,0xcc,0xeb,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x409,0xcc,0xeb,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x40a,0xcc,0xeb,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x40b,0xcc,0xeb,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x40c,0xcc,0xeb,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x40d,0xcc,0xeb,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x40e,0xcc,0xeb,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x40f,0xcc,0xeb,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x410,0xcc,0xeb,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x411,0xcc,0xeb,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x412,0xcc,0xeb,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x413,0xcc,0xeb,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddImage(self,0x414,0x30,0x10a,s_PB33_00_spr_00564ba0,1,0);
  UI_AddSprite(self,0x415,0xcc,0x107,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x416,0xcc,0x107,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x417,0xcc,0x107,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x418,0xcc,0x107,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x419,0xcc,0x107,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x41a,0xcc,0x107,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x41b,0xcc,0x107,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x41c,0xcc,0x107,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x41d,0xcc,0x107,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x41e,0xcc,0x107,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x41f,0xcc,0x107,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x420,0xcc,0x107,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x421,0xcc,0x107,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x422,0xcc,0x107,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x423,0xcc,0x107,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x424,0xcc,0x107,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x425,0xcc,0x107,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddImage(self,0x426,0x30,0x126,s_PB33_00_spr_00564ba0,1,0);
  UI_AddSprite(self,0x427,0xcc,0x123,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x428,0xcc,0x123,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x429,0xcc,0x123,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x42a,0xcc,0x123,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x42b,0xcc,0x123,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x42c,0xcc,0x123,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x42d,0xcc,0x123,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x42e,0xcc,0x123,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x42f,0xcc,0x123,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x430,0xcc,0x123,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x431,0xcc,0x123,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x432,0xcc,0x123,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x433,0xcc,0x123,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x434,0xcc,0x123,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x435,0xcc,0x123,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x436,0xcc,0x123,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x437,0xcc,0x123,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddImage(self,0x438,0x30,0x142,s_PB33_00_spr_00564ba0,1,0);
  UI_AddSprite(self,0x439,0xcc,0x13f,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x43a,0xcc,0x13f,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x43b,0xcc,0x13f,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x43c,0xcc,0x13f,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x43d,0xcc,0x13f,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x43e,0xcc,0x13f,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x43f,0xcc,0x13f,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x440,0xcc,0x13f,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x441,0xcc,0x13f,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x442,0xcc,0x13f,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x443,0xcc,0x13f,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x444,0xcc,0x13f,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x445,0xcc,0x13f,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x446,0xcc,0x13f,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x447,0xcc,0x13f,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x448,0xcc,0x13f,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x449,0xcc,0x13f,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddImage(self,0x44a,0x30,0x15e,s_PB33_00_spr_00564ba0,1,0);
  UI_AddSprite(self,1099,0xcc,0x15b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x44c,0xcc,0x15b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x44d,0xcc,0x15b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x44e,0xcc,0x15b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x44f,0xcc,0x15b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x450,0xcc,0x15b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x451,0xcc,0x15b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x452,0xcc,0x15b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x453,0xcc,0x15b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x454,0xcc,0x15b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x455,0xcc,0x15b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x456,0xcc,0x15b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x457,0xcc,0x15b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x458,0xcc,0x15b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x459,0xcc,0x15b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x45a,0xcc,0x15b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x45b,0xcc,0x15b,s_BEWERTUNG__16_spr_00563ed8);
  value1 = UI_AddText(self,0x45c,0x31,0x25,s_VERDANA10_fnt_00563e64,DAT_0058156c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x45c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x45c,0,0xaa,0xffff,0);
  }
  value1 = UI_AddText(self,0x45d,0x31,0x37,s_VERDANA8_fnt_00563e98,&DAT_00564ad8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x45d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x45d,0,0xb4,0x80,3);
  }
  value1 = UI_AddText(self,0x45e,0x31,0xbd,s_VERDANA8_fnt_00563e98,DAT_0058208c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x45e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x45e,0,0xaa,0xffff,0);
  }
  value1 = UI_AddText(self,0x45f,0x48,0xd4,s_VERDANA7_fnt_00563ec8,s__Unternehmensname_00564ac4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x45f,0xff);
    Window_GadgetNotify_Text_SetLayout(self,0x45f,2,0x87,0xffff,0);
  }
  value1 = UI_AddText(self,0x460,0x48,0xf2,s_VERDANA7_fnt_00563ec8,s__Unternehmensname_00564ac4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x460,0xff0000);
    Window_GadgetNotify_Text_SetLayout(self,0x460,2,0x87,0xffff,0);
  }
  value1 = UI_AddText(self,0x461,0x48,0x10e,s_VERDANA7_fnt_00563ec8,s__Unternehmensname_00564ac4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x461,0xaeae);
    Window_GadgetNotify_Text_SetLayout(self,0x461,2,0x87,0xffff,0);
  }
  value1 = UI_AddText(self,0x462,0x48,0x12a,s_VERDANA7_fnt_00563ec8,s__Unternehmensname_00564ac4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x462,0x8e00);
    Window_GadgetNotify_Text_SetLayout(self,0x462,2,0x87,0xffff,0);
  }
  value1 = UI_AddText(self,0x463,0x48,0x146,s_VERDANA7_fnt_00563ec8,s__Unternehmensname_00564ac4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x463,0xff00ff);
    Window_GadgetNotify_Text_SetLayout(self,0x463,2,0x87,0xffff,0);
  }
  value1 = UI_AddText(self,0x464,0x48,0x162,s_VERDANA7_fnt_00563ec8,s__Unternehmensname_00564ac4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x464,0xffaa00);
    Window_GadgetNotify_Text_SetLayout(self,0x464,2,0x87,0xffff,0);
  }
  value1 = UI_AddText(self,0x465,0x6f,0xa5,s_VERDANA8_fnt_00563e98,s__5_h_36_min_00564ab8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x465,0);
    Window_GadgetNotify_Text_SetLayout(self,0x465,1,0x78,0xffff,0);
  }
  UI_AddImage(self,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  UI_AddImage(self,0x1f41,0x30,0xd1,s_PB33_00_spr_00564ba0,1,0);
  return self;
}
