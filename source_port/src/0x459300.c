// SubMenu_BuildBranchStorerooms: ported from Pizza Connection 2 at 0x459300.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x459300
#include "pc2_port.h"


void * __cdecl SubMenu_BuildBranchStorerooms(int *arg1)

{
  int value1;
  void *self;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
                    /* Builds the branch-storerooms page. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004c0b80);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(self,0x408,0x27,0x129,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x45d,0x41,0x3f,s_VERDANA8_fnt_00563e98,DAT_00582e28);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x45d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x45d,2,0x98,0,0);
  }
  value1 = UI_AddText(self,0x45e,0x41,0x5b,s_VERDANA8_fnt_00563e98,DAT_00580b80);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x45e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x45e,2,0x98,0,0);
  }
  value1 = UI_AddText(self,0x465,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00582de0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x465,0);
    Window_GadgetNotify_Text_SetLayout(self,0x465,2,0xbe,0,0);
  }
  value1 = UI_CreateSlider(self,0x443,0x4a,0x52,0x8c,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xaa00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x443,&local_10);
  }
  value1 = UI_CreateSlider(self,0x444,0x4a,0x6e,0x8c,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xaa00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x444,&local_10);
  }
  UI_AddSprite(self,0x506,0x27,0xb6,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x510,0x42,0x25,s_VERDANA8_fnt_00563e98,DAT_00581d34);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x510,0);
    Window_GadgetNotify_Text_SetLayout(self,0x510,2,0x98,0,0);
  }
  value1 = UI_CreateSlider(self,0x511,0x4b,0x38,0x8c,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_8 = 0xaa00;
    local_10 = 0xff;
    local_c = 0xffff;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x511,&local_10);
  }
  value1 = UI_AddText(self,0x512,0x2f,0xbe,s_VERDANA8_fnt_00563e98,DAT_00581bc8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x512,0);
    Window_GadgetNotify_Text_SetLayout(self,0x512,0,0x91,0xffff,0);
  }
  value1 = UI_AddText(self,0x515,0x33,0x7c,s_VERDANA7_fnt_00563ec8,DAT_00581170);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x515,0);
    Window_GadgetNotify_Text_SetLayout(self,0x515,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x516,0x33,0x8a,s_VERDANA7_fnt_00563ec8,DAT_00582878);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x516,0);
    Window_GadgetNotify_Text_SetLayout(self,0x516,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x517,0x33,0x98,s_VERDANA7_fnt_00563ec8,DAT_00582b18);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x517,0);
    Window_GadgetNotify_Text_SetLayout(self,0x517,0,0x8c,0,0);
  }
  value1 = UI_AddText(self,0x518,0x33,0xa6,s_VERDANA7_fnt_00563ec8,DAT_00582a2c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x518,0);
    Window_GadgetNotify_Text_SetLayout(self,0x518,0,0x8c,0,0);
  }
  value1 = UI_AddText(self,0x519,0x88,0xbf,s_VERDANA7_fnt_00563ec8,s__Paris_1_00566844);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x519,0);
    Window_GadgetNotify_Text_SetLayout(self,0x519,1,0x46,0,0);
  }
  value1 = UI_AddText(self,0x521,0xbe,0x7c,s_VERDANA7_fnt_00563ec8,&DAT_005650bc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x521,0);
    Window_GadgetNotify_Text_SetLayout(self,0x521,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x522,0xbe,0x8a,s_VERDANA7_fnt_00563ec8,&DAT_005650b4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x522,0);
    Window_GadgetNotify_Text_SetLayout(self,0x522,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x523,0xbe,0x98,s_VERDANA7_fnt_00563ec8,s__100__0056683c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x523,0);
    Window_GadgetNotify_Text_SetLayout(self,0x523,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x524,0xbe,0xa6,s_VERDANA7_fnt_00563ec8,&DAT_00566834);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x524,0);
    Window_GadgetNotify_Text_SetLayout(self,0x524,1,0x28,0,0);
  }
  UI_AddImage(self,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  UI_AddImage(self,0x1f42,0xd1,0xbf,s_PB33_00_spr_00564ba0,0,0);
  UI_AddSprite(self,0x1f4b,0x27,0xf2,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x1f4c,0x30,0xf9,s_VERDANA8_fnt_00563e98,DAT_00582d94);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f4c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f4c,0,0,0,0);
  }
  value1 = UI_AddText(self,0x1f4d,0x33,0x106,s_VERDANA7_fnt_00563ec8,DAT_00582578);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f4d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f4d,0,0,0xffff,0);
  }
  value1 = UI_CreateSlider(self,0x1f4f,0x37,0x11e,0x4b,s_SLHOR01_00_spr_00564660,0,0);
  if (value1 != 0) {
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x1f4f,&local_10);
  }
  value1 = UI_AddText(self,0x1f51,0xb7,0x106,s_VERDANA7_fnt_00563ec8,s___53__005646a4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f51,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f51,1,0x2d,0,0);
  }
  value1 = UI_AddTextButton(self,0x1f52,0x8e,0x112,s_VERDANA8_fnt_00563e98,DAT_00582a78,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x1f52,0,0,0);
    Gadget_SetButtonTextLayout(self,0x1f52,2,0x54,0,0,0xfffe);
  }
  value1 = UI_AddText(self,0x1f61,0x2f,0xd8,s_VERDANA8_fnt_00563e98,DAT_00581bf4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f61,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f61,0,0x91,0,0);
  }
  UI_AddImage(self,0x1f62,0xd1,0xd9,s_PB33_00_spr_00564ba0,0,0);
  value1 = UI_AddText(self,0x1f69,0x33,0xe4,s_VERDANA7_fnt_00563ec8,DAT_005810b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f69,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f69,0,0,0xffff,0);
  }
  value1 = UI_AddText(self,0x1f6a,0xa9,0xe3,s_VERDANA7_fnt_00563ec8,&DAT_00565614);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f6a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f6a,1,0x23,0,0);
  }
  value1 = UI_AddText(self,0x1f6b,0x33,0xca,s_VERDANA7_fnt_00563ec8,DAT_00582a2c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f6b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f6b,0,0,0xffff,0);
  }
  value1 = UI_AddText(self,0x1f6c,0xa9,0xca,s_VERDANA7_fnt_00563ec8,&DAT_00565614);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f6c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f6c,1,0x23,0,0);
  }
  UI_AddSprite(self,0x1ff5,99,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x1ff6,99,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x1ff7,99,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x1ff8,99,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x1ff9,99,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x1ffa,99,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x1ffb,99,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x1ffc,99,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x1ffd,99,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x1ffe,99,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x1fff,99,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x2000,99,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x2001,99,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x2002,99,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x2003,99,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x2004,99,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x2005,99,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x2006,0x95,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x2007,0x95,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x2008,0x95,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x2009,0x95,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x200a,0x95,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x200b,0x95,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x200c,0x95,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x200d,0x95,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x200e,0x95,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x200f,0x95,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x2010,0x95,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x2011,0x95,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x2012,0x95,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x2013,0x95,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x2014,0x95,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x2015,0x95,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x2016,0x95,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x2017,199,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x2018,199,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x2019,199,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x201a,199,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x201b,199,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x201c,199,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x201d,199,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x201e,199,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x201f,199,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x2020,199,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x2021,199,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x2022,199,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x2023,199,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x2024,199,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x2025,199,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x2026,199,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x2027,199,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x2028,0x31,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x2029,0x31,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x202a,0x31,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x202b,0x31,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x202c,0x31,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x202d,0x31,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x202e,0x31,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x202f,0x31,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x2030,0x31,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x2031,0x31,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x2032,0x31,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x2033,0x31,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x2034,0x31,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x2035,0x31,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x2036,0x31,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x2037,0x31,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x2038,0x31,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x2039,99,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x203a,99,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x203b,99,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x203c,99,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x203d,99,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x203e,99,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x203f,99,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x2040,99,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x2041,99,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x2042,99,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x2043,99,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x2044,99,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x2045,99,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x2046,99,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x2047,99,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x2048,99,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x2049,99,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x204a,0x95,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x204b,0x95,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x204c,0x95,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x204d,0x95,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x204e,0x95,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x204f,0x95,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x2050,0x95,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x2051,0x95,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x2052,0x95,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x2053,0x95,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x2054,0x95,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x2055,0x95,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x2056,0x95,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x2057,0x95,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x2058,0x95,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x2059,0x95,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x205a,0x95,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x205b,199,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x205c,199,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x205d,199,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x205e,199,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x205f,199,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x2060,199,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x2061,199,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x2062,199,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x2063,199,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x2064,199,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x2065,199,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x2066,199,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x2067,199,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x2068,199,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x2069,199,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x206a,199,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x206b,199,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x206c,0x31,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x206d,0x31,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x206e,0x31,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x206f,0x31,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x2070,0x31,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x2071,0x31,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x2072,0x31,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x2073,0x31,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x2074,0x31,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x2075,0x31,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x2076,0x31,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x2077,0x31,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x2078,0x31,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x2079,0x31,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x207a,0x31,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x207b,0x31,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x207c,0x31,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  value1 = UI_AddText(self,0x207d,0x27,0x130,s_VERDANA7_fnt_00563ec8,DAT_00580bec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x207d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x207d,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x207e,0x58,0x130,s_VERDANA7_fnt_00563ec8,DAT_005816d4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x207e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x207e,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x207f,0x8a,0x130,s_VERDANA7_fnt_00563ec8,DAT_00582974);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x207f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x207f,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x2080,0xbc,0x130,s_VERDANA7_fnt_00563ec8,DAT_0058234c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x2080,0);
    Window_GadgetNotify_Text_SetLayout(self,0x2080,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x2081,0x27,0x154,s_VERDANA7_fnt_00563ec8,DAT_00580e64);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x2081,0);
    Window_GadgetNotify_Text_SetLayout(self,0x2081,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x2082,0x58,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582e08);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x2082,0);
    Window_GadgetNotify_Text_SetLayout(self,0x2082,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x2083,0x89,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582770);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x2083,0);
    Window_GadgetNotify_Text_SetLayout(self,0x2083,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x2084,0xba,0x154,s_VERDANA7_fnt_00563ec8,DAT_005810a4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x2084,0);
    Window_GadgetNotify_Text_SetLayout(self,0x2084,2,0x32,0,0);
  }
  return self;
}
