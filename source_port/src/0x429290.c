// SubMenu_BuildCompanyComparison: ported from Pizza Connection 2 at 0x429290.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x429290
#include "pc2_port.h"


void * __cdecl SubMenu_BuildCompanyComparison(int *arg1)

{
  int value1;
  void *self;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
                    /* Builds the company comparison page. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004a41e0);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(self,0x408,0x27,0x129,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x501,0x2b,5,s_TIMESFONT_fnt_00563ea8,DAT_00582be0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x501,0);
    Window_GadgetNotify_Text_SetLayout(self,0x501,2,0xbe,0,0);
  }
  UI_AddSprite(self,0x519,0x27,0xf3,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x51a,0x30,0xfd,s_VERDANA8_fnt_00563e98,DAT_00582e50);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x51a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x51a,0,100,0,0);
  }
  value1 = UI_AddText(self,0x51b,0x30,0x116,s_VERDANA8_fnt_00563e98,s__Pizza_Tingeltangel_0056510c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x51b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x51b,0,0x87,0,0);
  }
  UI_AddSprite(self,0x51c,0xb5,0x104,s_LOGORAHMEN_00_spr_005650f8);
  UI_CreateBitmapGadget(self,0x51f,0xb7,0x106,0x2c,0x1d,0x10);
  UI_AddImage(self,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  UI_AddSprite(self,0x2355,0x27,0x93,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x2373,0x31,0xc0,s_VERDANA7_fnt_00563ec8,DAT_00582df8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x2373,0);
    Window_GadgetNotify_Text_SetLayout(self,0x2373,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x2374,0xbc,0xc0,s_VERDANA7_fnt_00563ec8,&DAT_005650ac);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x2374,0);
    Window_GadgetNotify_Text_SetLayout(self,0x2374,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x2376,0x31,0x9a,s_VERDANA7_fnt_00563ec8,DAT_00582600);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x2376,0);
    Window_GadgetNotify_Text_SetLayout(self,0x2376,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x2377,0x31,0xb0,s_VERDANA7_fnt_00563ec8,DAT_00580cdc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x2377,0);
    Window_GadgetNotify_Text_SetLayout(self,0x2377,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x2379,0xbc,0x9a,s_VERDANA7_fnt_00563ec8,&DAT_005650ac);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x2379,0);
    Window_GadgetNotify_Text_SetLayout(self,0x2379,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x237a,0x81,0xb0,s_VERDANA7_fnt_00563ec8,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x237a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x237a,1,100,0,0);
  }
  value1 = UI_AddText(self,0x237b,0x31,0xcb,s_VERDANA7_fnt_00563ec8,DAT_00582224);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x237b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x237b,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x237c,0x9a,0xcc,s_VERDANA7_fnt_00563ec8,DAT_00582300);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x237c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x237c,0,0x37,0,0);
  }
  value1 = UI_AddText(self,0x237e,0x9a,0xd9,s_VERDANA7_fnt_00563ec8,DAT_00582544);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x237e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x237e,0,0x37,0,0);
  }
  value1 = UI_AddText(self,0x237f,0x9a,0xe5,s_VERDANA7_fnt_00563ec8,DAT_00582474);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x237f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x237f,0,0x37,0,0);
  }
  value1 = UI_AddText(self,0x2380,0xc6,0xcc,s_VERDANA7_fnt_00563ec8,&DAT_005650b4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x2380,0);
    Window_GadgetNotify_Text_SetLayout(self,0x2380,1,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x2382,0xc6,0xd9,s_VERDANA7_fnt_00563ec8,&DAT_005650b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x2382,0);
    Window_GadgetNotify_Text_SetLayout(self,0x2382,1,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x2383,0xc6,0xe5,s_VERDANA7_fnt_00563ec8,&DAT_005650b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x2383,0);
    Window_GadgetNotify_Text_SetLayout(self,0x2383,1,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x2384,0x30,0x21,s_VERDANA10_fnt_00563e64,DAT_00581b78);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x2384,0);
    Window_GadgetNotify_Text_SetLayout(self,0x2384,0,0xbe,0,0);
  }
  UI_AddImage(self,0x238a,0x2c,0x32,s_PB14_00_spr_005642c4,1,0);
  value1 = UI_AddText(self,0x2396,0x47,0x32,s_VERDANA7_fnt_00563ec8,s__Unternehmensname_00564ac4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x2396,0xff);
    Window_GadgetNotify_Text_SetLayout(self,0x2396,0,0x73,0xffff,0);
  }
  value1 = UI_AddText(self,0x2397,0x47,0x3b,s_VERDANA7_fnt_00563ec8,DAT_005825e4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x2397,0);
    Window_GadgetNotify_Text_SetLayout(self,0x2397,0,100,0xffff,0);
  }
  value1 = UI_AddText(self,0x2398,0x52,0x3c,s_VERDANA7_fnt_00563ec8,s__100_000__00565098);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x2398,0);
    Window_GadgetNotify_Text_SetLayout(self,0x2398,1,100,0xffff,0);
  }
  UI_AddImage(self,0x23a8,0x2c,0x4b,s_PB14_00_spr_005642c4,1,0);
  value1 = UI_AddText(self,0x23a9,0x47,0x4b,s_VERDANA7_fnt_00563ec8,s__Unternehmensname_00564ac4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x23a9,0x6e00);
    Window_GadgetNotify_Text_SetLayout(self,0x23a9,0,0x73,0xffff,0);
  }
  value1 = UI_AddText(self,0x23aa,0x47,0x54,s_VERDANA7_fnt_00563ec8,DAT_005825e4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x23aa,0);
    Window_GadgetNotify_Text_SetLayout(self,0x23aa,0,100,0xffff,0);
  }
  value1 = UI_AddText(self,0x23ab,0x52,0x55,s_VERDANA7_fnt_00563ec8,s__100_000__00565098);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x23ab,0);
    Window_GadgetNotify_Text_SetLayout(self,0x23ab,1,100,0xffff,0);
  }
  UI_AddImage(self,0x23ac,0x2c,99,s_PB14_00_spr_005642c4,1,0);
  value1 = UI_AddText(self,0x23ad,0x47,99,s_VERDANA7_fnt_00563ec8,s__Unternehmensname_00564ac4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x23ad,0xff0000);
    Window_GadgetNotify_Text_SetLayout(self,0x23ad,0,0x73,0xffff,0);
  }
  value1 = UI_AddText(self,0x23ae,0x47,0x6c,s_VERDANA7_fnt_00563ec8,DAT_005825e4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x23ae,0);
    Window_GadgetNotify_Text_SetLayout(self,0x23ae,0,100,0xffff,0);
  }
  value1 = UI_AddText(self,0x23af,0x52,0x6d,s_VERDANA7_fnt_00563ec8,s__100_000__00565098);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x23af,0);
    Window_GadgetNotify_Text_SetLayout(self,0x23af,1,100,0xffff,0);
  }
  UI_AddImage(self,0x23b0,0x2c,0x7b,s_PB14_00_spr_005642c4,1,0);
  value1 = UI_AddText(self,0x23b1,0x47,0x7b,s_VERDANA7_fnt_00563ec8,s__Unternehmensname_00564ac4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x23b1,0x5db2);
    Window_GadgetNotify_Text_SetLayout(self,0x23b1,0,0x73,0xffff,0);
  }
  value1 = UI_AddText(self,0x23b2,0x47,0x84,s_VERDANA7_fnt_00563ec8,DAT_005825e4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x23b2,0);
    Window_GadgetNotify_Text_SetLayout(self,0x23b2,0,100,0xffff,0);
  }
  value1 = UI_AddText(self,0x23b3,0x52,0x85,s_VERDANA7_fnt_00563ec8,s__100_000__00565098);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x23b3,0);
    Window_GadgetNotify_Text_SetLayout(self,0x23b3,1,100,0xffff,0);
  }
  value1 = UI_CreateSlider(self,0x23b4,0xdd,0x3c,0x55,s_SL01_00_spr_0056448c,0,1);
  if (value1 != 0) {
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x23b4,&local_10);
  }
  value1 = UI_AddText(self,0x23e0,0x31,0x131,s_VERDANA7_fnt_00563ec8,DAT_00582f74);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x23e0,0);
    Window_GadgetNotify_Text_SetLayout(self,0x23e0,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x23e1,0x31,0x13d,s_VERDANA7_fnt_00563ec8,DAT_0058263c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x23e1,0);
    Window_GadgetNotify_Text_SetLayout(self,0x23e1,0,0xa0,0,0);
  }
  value1 = UI_AddText(self,0x23e2,0xbc,0x131,s_VERDANA7_fnt_00563ec8,&DAT_005650ac);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x23e2,0);
    Window_GadgetNotify_Text_SetLayout(self,0x23e2,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x23e3,0x80,0x13d,s_VERDANA7_fnt_00563ec8,&DAT_005650ac);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x23e3,0);
    Window_GadgetNotify_Text_SetLayout(self,0x23e3,1,100,0,0);
  }
  value1 = UI_AddText(self,0x23e8,0x31,0x148,s_VERDANA7_fnt_00563ec8,DAT_00582e18);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x23e8,0);
    Window_GadgetNotify_Text_SetLayout(self,0x23e8,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x23e9,0x31,0x153,s_VERDANA7_fnt_00563ec8,DAT_005829e0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x23e9,0);
    Window_GadgetNotify_Text_SetLayout(self,0x23e9,0,0xa0,0,0);
  }
  value1 = UI_AddText(self,0x23ea,0xbc,0x148,s_VERDANA7_fnt_00563ec8,&DAT_005650ac);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x23ea,0);
    Window_GadgetNotify_Text_SetLayout(self,0x23ea,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x23eb,0x81,0x153,s_VERDANA7_fnt_00563ec8,&DAT_005650e8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x23eb,0);
    Window_GadgetNotify_Text_SetLayout(self,0x23eb,1,100,0,0);
  }
  value1 = UI_AddText(self,0x23ec,0x31,0x15f,s_VERDANA7_fnt_00563ec8,DAT_00582898);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x23ec,0);
    Window_GadgetNotify_Text_SetLayout(self,0x23ec,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x23ed,0x31,0x16a,s_VERDANA7_fnt_00563ec8,DAT_00581a54);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x23ed,0);
    Window_GadgetNotify_Text_SetLayout(self,0x23ed,0,0xa0,0,0);
  }
  value1 = UI_AddText(self,0x23ee,0xbc,0x15f,s_VERDANA7_fnt_00563ec8,&DAT_005650ac);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x23ee,0);
    Window_GadgetNotify_Text_SetLayout(self,0x23ee,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x23ef,0x81,0x16a,s_VERDANA7_fnt_00563ec8,&DAT_0056508c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x23ef,0);
    Window_GadgetNotify_Text_SetLayout(self,0x23ef,1,100,0,0);
  }
  UI_AddSprite(self,0x23f0,0xb7,0x106,s_PLAYLOG_8_01_02_spr_00564744);
  UI_AddSprite(self,0x23f1,0xb5,0x2e,s_LOGOS__05_spr_00564ef0);
  UI_AddSprite(self,0x23f2,0xb5,0x46,s_LOGOS__01_spr_00564f10);
  UI_AddSprite(self,0x23f3,0xb6,0x5e,s_LOGOS__02_spr_00564f00);
  UI_AddSprite(self,0x23f4,0xb7,0x76,s_LOGOS__03_spr_005650d8);
  value1 = UI_AddText(self,0x23f5,0x31,0xa5,s_VERDANA7_fnt_00563ec8,DAT_00582c44);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x23f5,0);
    Window_GadgetNotify_Text_SetLayout(self,0x23f5,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x23f6,0xbc,0xa5,s_VERDANA7_fnt_00563ec8,&DAT_005650ac);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x23f6,0);
    Window_GadgetNotify_Text_SetLayout(self,0x23f6,1,0x28,0,0);
  }
  return self;
}
