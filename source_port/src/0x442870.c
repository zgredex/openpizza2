// StatisticsRecipes_CreateWindow: ported from Pizza Connection 2 at 0x442870.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x442870
#include "pc2_port.h"


void * __cdecl StatisticsRecipes_CreateWindow(int *arg1)

{
  int value1;
  void *self;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
                    /* Creates the recipe statistics tab and comparison table. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0,0,s_STATISTIKBACKSPRITE_spr_00566188,&LAB_004b4c10);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  value1 = UI_AddText(self,1000,0x25d,0xdf,s_TIMESFONT_fnt_00563ea8,DAT_00582c78);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,1000,0);
    Window_GadgetNotify_Text_SetLayout(self,1000,2,0xbe,0xffff,0);
  }
  UI_AddSprite(self,0x3ea,0x262,0x105,s_RAHMEN06_spr_00565144);
  UI_AddSprite(self,0x3eb,0x262,0x118,s_RAHMEN06_spr_00565144);
  UI_AddSprite(self,0x3ec,0x262,299,s_RAHMEN06_spr_00565144);
  UI_AddSprite(self,0x3ed,0x262,0x13e,s_RAHMEN06_spr_00565144);
  UI_AddSprite(self,0x3ee,0x262,0x151,s_RAHMEN06_spr_00565144);
  UI_AddSprite(self,0x3ef,0x262,0x164,s_RAHMEN06_spr_00565144);
  UI_AddSprite(self,0x3f0,0x262,0x177,s_RAHMEN06_spr_00565144);
  UI_AddSprite(self,0x3f1,0x262,0x18a,s_RAHMEN06_spr_00565144);
  value1 = UI_CreateSlider(self,0x3f2,0x30e,0x10c,0x90,s_SL01_00_spr_0056448c,0,1);
  if (value1 != 0) {
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x3f2,&local_10);
  }
  UI_AddSprite(self,0x3f4,600,0x1a8,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x3f5,0x25f,0x1b0,s_VERDANA8_fnt_00563e98,DAT_005829c4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3f5,0);
    Window_GadgetNotify_Text_SetLayout(self,0x3f5,0,0xb4,0xffff,0);
  }
  value1 = UI_AddTextButton(self,0x3f6,0x262,0x1be,s_VERDANA8_fnt_00563e98,s__Alle_Filialen_00566258,
                           0,s_TEXTPB05__00_spr_00564160);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x3f6,0,0,0);
    Gadget_SetButtonTextLayout(self,0x3f6,2,0xb4,0,0,0xfffe);
  }
  value1 = UI_AddText(self,0x3f7,0x25f,0x1d4,s_VERDANA8_fnt_00563e98,DAT_00581bb0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3f7,0);
    Window_GadgetNotify_Text_SetLayout(self,0x3f7,0,0xb4,0xffff,0);
  }
  UI_AddImage(self,0x3f8,0x26c,0x1e3,s_SKPIZUMSATZ_00_spr_00566244,1,0);
  UI_AddImage(self,0x3f9,0x2a7,0x1e3,s_SKBILANZ_00_spr_00565ad4,1,0);
  UI_AddImage(self,0x3fa,0x2e2,0x1e3,s_SKBEWERTUNG_00_spr_00566174,1,0);
  UI_AddImage(self,0x3fb,0x285,0x20c,s_PB14_00_spr_005642c4,1,0);
  UI_AddImage(self,0x3fc,0x285,0x223,s_PB14_00_spr_005642c4,1,0);
  UI_AddImage(self,0x3fd,0x285,0x23a,s_PB14_00_spr_005642c4,1,0);
  UI_AddImage(self,0x3fe,0x2c4,0x20c,s_PB14_00_spr_005642c4,1,0);
  UI_AddImage(self,0x3ff,0x2c4,0x223,s_PB14_00_spr_005642c4,1,0);
  UI_AddImage(self,0x400,0x2c4,0x23a,s_PB14_00_spr_005642c4,1,0);
  UI_AddImage(self,0x401,0x303,0x20c,s_PB14_00_spr_005642c4,1,0);
  UI_AddImage(self,0x402,0x303,0x223,s_PB14_00_spr_005642c4,1,0);
  UI_AddImage(self,0x403,0x303,0x23a,s_PB14_00_spr_005642c4,1,0);
  value1 = UI_AddText(self,0x404,0x25d,0x210,s_VERDANA7_fnt_00563ec8,DAT_00580bec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x404,0);
    Window_GadgetNotify_Text_SetLayout(self,0x404,1,0x29,0xffff,0);
  }
  value1 = UI_AddText(self,0x405,0x25d,0x227,s_VERDANA7_fnt_00563ec8,DAT_0058234c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x405,0);
    Window_GadgetNotify_Text_SetLayout(self,0x405,1,0x29,0xffff,0);
  }
  value1 = UI_AddText(self,0x406,0x25d,0x23e,s_VERDANA7_fnt_00563ec8,DAT_00582770);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x406,0);
    Window_GadgetNotify_Text_SetLayout(self,0x406,1,0x29,0xffff,0);
  }
  value1 = UI_AddText(self,0x407,0x29c,0x210,s_VERDANA7_fnt_00563ec8,DAT_005816d4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x407,0);
    Window_GadgetNotify_Text_SetLayout(self,0x407,1,0x29,0xffff,0);
  }
  value1 = UI_AddText(self,0x408,0x29c,0x227,s_VERDANA7_fnt_00563ec8,DAT_00580e64);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x408,0);
    Window_GadgetNotify_Text_SetLayout(self,0x408,1,0x29,0xffff,0);
  }
  value1 = UI_AddText(self,0x409,0x29c,0x23e,s_VERDANA7_fnt_00563ec8,DAT_0058275c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x409,0);
    Window_GadgetNotify_Text_SetLayout(self,0x409,1,0x29,0xffff,0);
  }
  value1 = UI_AddText(self,0x40a,0x2db,0x210,s_VERDANA7_fnt_00563ec8,DAT_00582974);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x40a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x40a,1,0x29,0xffff,0);
  }
  value1 = UI_AddText(self,0x40b,0x2db,0x227,s_VERDANA7_fnt_00563ec8,DAT_00582e08);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x40b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x40b,1,0x29,0xffff,0);
  }
  value1 = UI_AddText(self,0x40c,0x2db,0x23e,s_VERDANA7_fnt_00563ec8,DAT_005829dc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x40c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x40c,1,0x29,0xffff,0);
  }
  value1 = UI_AddText(self,0x40d,0x27a,0x109,s_VERDANA7_fnt_00563ec8,s__Rezeptname_00566238);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x40d,0xff);
    Window_GadgetNotify_Text_SetLayout(self,0x40d,0,0x55,0xffff,0);
  }
  value1 = UI_AddText(self,0x40e,0x27a,0x11c,s_VERDANA7_fnt_00563ec8,s__Rezeptname_00566238);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x40e,0xff00ff);
    Window_GadgetNotify_Text_SetLayout(self,0x40e,0,0x55,0xffff,0);
  }
  value1 = UI_AddText(self,0x40f,0x27a,0x12f,s_VERDANA7_fnt_00563ec8,s__Rezeptname_00566238);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x40f,0x820082);
    Window_GadgetNotify_Text_SetLayout(self,0x40f,0,0x55,0xffff,0);
  }
  value1 = UI_AddText(self,0x410,0x27a,0x142,s_VERDANA7_fnt_00563ec8,s__Rezeptname_00566238);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x410,0xff0000);
    Window_GadgetNotify_Text_SetLayout(self,0x410,0,0x55,0xffff,0);
  }
  value1 = UI_AddText(self,0x411,0x27a,0x155,s_VERDANA7_fnt_00563ec8,s__Rezeptname_00566238);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x411,0xffd200);
    Window_GadgetNotify_Text_SetLayout(self,0x411,0,0x55,0xffff,0);
  }
  value1 = UI_AddText(self,0x412,0x27a,0x168,s_VERDANA7_fnt_00563ec8,s__Rezeptname_00566238);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x412,0x6d6d);
    Window_GadgetNotify_Text_SetLayout(self,0x412,0,0x55,0xffff,0);
  }
  value1 = UI_AddText(self,0x413,0x27a,0x17b,s_VERDANA7_fnt_00563ec8,s__Rezeptname_00566238);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x413,0xdb00);
    Window_GadgetNotify_Text_SetLayout(self,0x413,0,0x55,0xffff,0);
  }
  value1 = UI_AddText(self,0x414,0x27a,0x18e,s_VERDANA7_fnt_00563ec8,s__Rezeptname_00566238);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x414,0xa6a6);
    Window_GadgetNotify_Text_SetLayout(self,0x414,0,0x55,0xffff,0);
  }
  value1 = UI_AddText(self,0x415,0x2c7,0x109,s_VERDANA7_fnt_00563ec8,s__23000__00566108);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x415,0xff);
    Window_GadgetNotify_Text_SetLayout(self,0x415,1,0x39,0xffff,0);
  }
  value1 = UI_AddText(self,0x416,0x2c7,0x11c,s_VERDANA7_fnt_00563ec8,s__23000__00566108);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x416,0xff00ff);
    Window_GadgetNotify_Text_SetLayout(self,0x416,1,0x39,0xffff,0);
  }
  value1 = UI_AddText(self,0x417,0x2c7,0x141,s_VERDANA7_fnt_00563ec8,s__23000__00566108);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x417,0xff0000);
    Window_GadgetNotify_Text_SetLayout(self,0x417,1,0x39,0xffff,0);
  }
  value1 = UI_AddText(self,0x418,0x2c7,0x12e,s_VERDANA7_fnt_00563ec8,s__23000__00566108);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x418,0x820082);
    Window_GadgetNotify_Text_SetLayout(self,0x418,1,0x39,0xffff,0);
  }
  value1 = UI_AddText(self,0x419,0x2c7,0x18d,s_VERDANA7_fnt_00563ec8,s__23000__00566108);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x419,0xa6a6);
    Window_GadgetNotify_Text_SetLayout(self,0x419,1,0x39,0xffff,0);
  }
  value1 = UI_AddText(self,0x41a,0x2c7,0x17a,s_VERDANA7_fnt_00563ec8,s__23000__00566108);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x41a,0xdb00);
    Window_GadgetNotify_Text_SetLayout(self,0x41a,1,0x39,0xffff,0);
  }
  value1 = UI_AddText(self,0x41b,0x2c7,0x168,s_VERDANA7_fnt_00563ec8,s__23000__00566108);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x41b,0x6d6d);
    Window_GadgetNotify_Text_SetLayout(self,0x41b,1,0x39,0xffff,0);
  }
  value1 = UI_AddText(self,0x41c,0x2c7,0x155,s_VERDANA7_fnt_00563ec8,s__23000__00566108);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x41c,0xffd200);
    Window_GadgetNotify_Text_SetLayout(self,0x41c,1,0x39,0xffff,0);
  }
  UI_CreateBitmapGadget(self,0x41d,0x35,0x5b,0x1ea,0x1a4,0x10);
  value1 = UI_AddText(self,0x41e,0x193,0x204,s_VERDANA8_fnt_00563e98,s__Aktuelles_Quartal_005660f4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x41e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x41e,1,0x96,0xffff,0);
  }
  value1 = UI_AddText(self,0x41f,0x20,0x42,s_VERDANA8_fnt_00563e98,s__23000__00566108);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x41f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x41f,0,0x78,0xffff,0);
  }
  UI_AddImage(self,8000,0x23c,0xd9,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  UI_AddImage(self,0x1f41,0x261,0x104,s_PB14_00_spr_005642c4,1,0);
  UI_AddImage(self,0x1f42,0x261,0x117,s_PB14_00_spr_005642c4,1,0);
  UI_AddImage(self,0x1f43,0x261,0x12a,s_PB14_00_spr_005642c4,1,0);
  UI_AddImage(self,0x1f44,0x261,0x13d,s_PB14_00_spr_005642c4,1,0);
  UI_AddImage(self,0x1f45,0x261,0x150,s_PB14_00_spr_005642c4,1,0);
  UI_AddImage(self,0x1f46,0x261,0x163,s_PB14_00_spr_005642c4,1,0);
  UI_AddImage(self,0x1f47,0x261,0x176,s_PB14_00_spr_005642c4,1,0);
  UI_AddImage(self,0x1f48,0x261,0x189,s_PB14_00_spr_005642c4,1,0);
  return self;
}
