// Screen_StatisticsBalance: ported from Pizza Connection 2 at 0x430fd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x430fd0
#include "pc2_port.h"


void * __cdecl Screen_StatisticsBalance(int *arg1)

{
  int value1;
  void *self;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
  value1 = UI_CreateWindow(DAT_0057c5e0,0,0,s_STATISTIKBILANZBACK_spr_005658cc,&LAB_004abba0);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(self,0x4c7,0x264,0x117,s_TAB09_spr_005658c0);
  UI_AddSprite(self,0x4bf,0x264,0x136,s_TAB09_spr_005658c0);
  UI_AddSprite(self,0x4c0,0x264,0x14b,s_TAB09_spr_005658c0);
  UI_AddSprite(self,0x4c1,0x264,0x160,s_TAB09_spr_005658c0);
  UI_AddSprite(self,0x4c2,0x264,0x175,s_TAB09_spr_005658c0);
  UI_AddSprite(self,0x4c3,0x264,0x18a,s_TAB09_spr_005658c0);
  UI_AddSprite(self,0x4c4,0x264,0x19f,s_TAB09_spr_005658c0);
  UI_AddSprite(self,0x4c5,0x264,0x1b4,s_TAB09_spr_005658c0);
  UI_AddSprite(self,0x4c6,0x264,0x1c9,s_TAB09_spr_005658c0);
  value1 = UI_AddText(self,1000,0x25d,0xdf,s_TIMESFONT_fnt_00563ea8,DAT_00582c84);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,1000,0);
    Window_GadgetNotify_Text_SetLayout(self,1000,2,0xbe,0xffff,0);
  }
  UI_AddImage(self,0x3e9,0x263,0x116,s_TABPB01__00_spr_00564670,0,0);
  UI_AddImage(self,0x3ea,0x263,0x135,s_TABPB01__00_spr_00564670,0,0);
  UI_AddImage(self,0x3eb,0x263,0x14a,s_TABPB01__00_spr_00564670,0,0);
  UI_AddImage(self,0x3ec,0x263,0x15f,s_TABPB01__00_spr_00564670,0,0);
  UI_AddImage(self,0x3ed,0x263,0x174,s_TABPB01__00_spr_00564670,0,0);
  UI_AddImage(self,0x3ee,0x263,0x1c8,s_TABPB01__00_spr_00564670,0,0);
  UI_AddImage(self,0x3ef,0x263,0x1b3,s_TABPB01__00_spr_00564670,0,0);
  UI_AddImage(self,0x3f0,0x263,0x19e,s_TABPB01__00_spr_00564670,0,0);
  UI_AddImage(self,0x3f1,0x263,0x189,s_TABPB01__00_spr_00564670,0,0);
  value1 = UI_CreateSlider(self,0x3f2,0x30e,0x13c,0xa0,s_SL01_00_spr_0056448c,0,1);
  if (value1 != 0) {
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x3f2,&local_10);
  }
  UI_AddSprite(self,0x3f3,600,0x1e5,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x3fb,0x29d,0x11b,s_VERDANA7_fnt_00563ec8,s___1_00_000_000__005658b0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3fb,0);
    Window_GadgetNotify_Text_SetLayout(self,0x3fb,1,100,0xffff,0);
  }
  value1 = UI_AddText(self,0x3f8,0x266,0x11a,s_VERDANA7_fnt_00563ec8,DAT_00581874);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3f8,0);
    Window_GadgetNotify_Text_SetLayout(self,0x3f8,0,0x3c,0xffff,0);
  }
  value1 = UI_AddText(self,0x3f9,0x266,0x13a,s_VERDANA7_fnt_00563ec8,s__Filialname_005644d4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3f9,0);
    Window_GadgetNotify_Text_SetLayout(self,0x3f9,0,0x55,0xffff,0);
  }
  value1 = UI_AddText(self,0x3fa,0x2b8,0x13a,s_VERDANA7_fnt_00563ec8,s___1_000_000__005658a0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3fa,0);
    Window_GadgetNotify_Text_SetLayout(self,0x3fa,1,0x48,0xffff,0);
  }
  value1 = UI_AddText(self,0x3fc,0x266,0x14f,s_VERDANA7_fnt_00563ec8,s__Filialname_005644d4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3fc,0);
    Window_GadgetNotify_Text_SetLayout(self,0x3fc,0,0x55,0xffff,0);
  }
  value1 = UI_AddText(self,0x3fd,0x2b8,0x14f,s_VERDANA7_fnt_00563ec8,s___1_000_000__005658a0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3fd,0);
    Window_GadgetNotify_Text_SetLayout(self,0x3fd,1,0x48,0xffff,0);
  }
  value1 = UI_AddText(self,0x3fe,0x266,0x164,s_VERDANA7_fnt_00563ec8,s__Filialname_005644d4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3fe,0);
    Window_GadgetNotify_Text_SetLayout(self,0x3fe,0,0x55,0xffff,0);
  }
  value1 = UI_AddText(self,0x3ff,0x2b8,0x164,s_VERDANA7_fnt_00563ec8,s___1_000_000__005658a0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3ff,0);
    Window_GadgetNotify_Text_SetLayout(self,0x3ff,1,0x48,0xffff,0);
  }
  value1 = UI_AddText(self,0x400,0x266,0x179,s_VERDANA7_fnt_00563ec8,s__Filialname_005644d4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x400,0);
    Window_GadgetNotify_Text_SetLayout(self,0x400,0,0x55,0xffff,0);
  }
  value1 = UI_AddText(self,0x401,0x2b8,0x179,s_VERDANA7_fnt_00563ec8,s___1_000_000__005658a0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x401,0);
    Window_GadgetNotify_Text_SetLayout(self,0x401,1,0x48,0xffff,0);
  }
  value1 = UI_AddText(self,0x402,0x266,0x18e,s_VERDANA7_fnt_00563ec8,s__Filialname_005644d4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x402,0);
    Window_GadgetNotify_Text_SetLayout(self,0x402,0,0x55,0xffff,0);
  }
  value1 = UI_AddText(self,0x403,0x2b8,0x18e,s_VERDANA7_fnt_00563ec8,s___1_000_000__005658a0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x403,0);
    Window_GadgetNotify_Text_SetLayout(self,0x403,1,0x48,0xffff,0);
  }
  value1 = UI_AddText(self,0x404,0x266,0x1a3,s_VERDANA7_fnt_00563ec8,s__Filialname_005644d4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x404,0);
    Window_GadgetNotify_Text_SetLayout(self,0x404,0,0x55,0xffff,0);
  }
  value1 = UI_AddText(self,0x405,0x2b8,0x1a3,s_VERDANA7_fnt_00563ec8,s___1_000_000__005658a0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x405,0);
    Window_GadgetNotify_Text_SetLayout(self,0x405,1,0x48,0xffff,0);
  }
  value1 = UI_AddText(self,0x406,0x266,0x1b8,s_VERDANA7_fnt_00563ec8,s__Filialname_005644d4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x406,0);
    Window_GadgetNotify_Text_SetLayout(self,0x406,0,0x55,0xffff,0);
  }
  value1 = UI_AddText(self,0x407,0x2b9,0x1b8,s_VERDANA7_fnt_00563ec8,s___1_000_000__005658a0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x407,0);
    Window_GadgetNotify_Text_SetLayout(self,0x407,1,0x48,0xffff,0);
  }
  value1 = UI_AddText(self,0x408,0x266,0x1cd,s_VERDANA7_fnt_00563ec8,s__Filialname_005644d4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x408,0);
    Window_GadgetNotify_Text_SetLayout(self,0x408,0,0x55,0xffff,0);
  }
  value1 = UI_AddText(self,0x409,0x2b8,0x1cd,s_VERDANA7_fnt_00563ec8,s___1_000_000__005658a0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x409,0);
    Window_GadgetNotify_Text_SetLayout(self,0x409,1,0x48,0xffff,0);
  }
  value1 = UI_AddText(self,0x40a,0x261,0x1f2,s_VERDANA8_fnt_00563e98,DAT_00582d08);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x40a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x40a,0,0xaa,0xffff,0);
  }
  value1 = UI_AddText(self,0x40b,0x261,0x102,s_VERDANA8_fnt_00563e98,DAT_005829c4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x40b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x40b,0,0xaa,0xffff,0);
  }
  value1 = UI_AddText(self,0x40f,0xc4,0x3c,s_TIMESFONT_fnt_00563ea8,DAT_00582c84);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x40f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x40f,2,0xbe,0xffff,0);
  }
  value1 = UI_AddText(self,0x410,0x2b,0x42,s_VEDANA11_fnt_00564090,DAT_00582cf8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x410,0);
    Window_GadgetNotify_Text_SetLayout(self,0x410,0,100,0xffff,0);
  }
  value1 = UI_AddText(self,0x411,0x1c8,0x42,s_VEDANA11_fnt_00564090,DAT_00580d4c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x411,0);
    Window_GadgetNotify_Text_SetLayout(self,0x411,0,100,0xffff,0);
  }
  value1 = UI_AddText(self,0x412,0xc9,0x5a,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x412,0);
    Window_GadgetNotify_Text_SetLayout(self,0x412,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x413,0x2e,0x5a,s_VERDANA8_fnt_00563e98,DAT_00582a90);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x413,0);
    Window_GadgetNotify_Text_SetLayout(self,0x413,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x414,0x2e,0x67,s_VERDANA8_fnt_00563e98,DAT_00581e3c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x414,0);
    Window_GadgetNotify_Text_SetLayout(self,0x414,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x415,0xc9,0x67,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x415,0);
    Window_GadgetNotify_Text_SetLayout(self,0x415,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x416,0xc9,0x74,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x416,0);
    Window_GadgetNotify_Text_SetLayout(self,0x416,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x417,0x2e,0x74,s_VERDANA8_fnt_00563e98,DAT_00580b64);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x417,0);
    Window_GadgetNotify_Text_SetLayout(self,0x417,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x418,0x2e,0x81,s_VERDANA8_fnt_00563e98,DAT_00582be0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x418,0);
    Window_GadgetNotify_Text_SetLayout(self,0x418,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x419,0xc9,0x81,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x419,0);
    Window_GadgetNotify_Text_SetLayout(self,0x419,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x41a,0xc9,0x8e,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x41a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x41a,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x41b,0x2e,0x8e,s_VERDANA8_fnt_00563e98,DAT_00582a10);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x41b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x41b,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x41c,0x2e,0x9b,s_VERDANA8_fnt_00563e98,DAT_00580e90);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x41c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x41c,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x41d,0xc9,0x9b,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x41d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x41d,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x41e,0xc9,0x104,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x41e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x41e,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x41f,0x2e,0x104,s_VERDANA8_fnt_00563e98,DAT_00582df4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x41f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x41f,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x420,0x2e,0x111,s_VERDANA8_fnt_00563e98,DAT_00582cf4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x420,0);
    Window_GadgetNotify_Text_SetLayout(self,0x420,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x421,0xc9,0x111,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x421,0);
    Window_GadgetNotify_Text_SetLayout(self,0x421,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x422,0xc9,0x16e,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x422,0);
    Window_GadgetNotify_Text_SetLayout(self,0x422,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x423,0x2e,0x16e,s_VERDANA8_fnt_00563e98,DAT_00581d68);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x423,0);
    Window_GadgetNotify_Text_SetLayout(self,0x423,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x424,0x2e,0x11e,s_VERDANA8_fnt_00563e98,DAT_00582d90);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x424,0);
    Window_GadgetNotify_Text_SetLayout(self,0x424,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x425,0xc9,0x11e,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x425,0);
    Window_GadgetNotify_Text_SetLayout(self,0x425,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x426,0xc9,0xae,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x426,0);
    Window_GadgetNotify_Text_SetLayout(self,0x426,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x427,0x2e,0xae,s_VERDANA8_fnt_00563e98,DAT_00582908);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x427,0);
    Window_GadgetNotify_Text_SetLayout(self,0x427,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x428,0x2e,0xbb,s_VERDANA8_fnt_00563e98,DAT_005816d8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x428,0);
    Window_GadgetNotify_Text_SetLayout(self,0x428,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x429,0xc9,0xbb,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x429,0);
    Window_GadgetNotify_Text_SetLayout(self,0x429,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x42a,0xc9,200,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x42a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x42a,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x42b,0x2e,200,s_VERDANA8_fnt_00563e98,DAT_00581d30);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x42b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x42b,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x42c,0x2e,0xd5,s_VERDANA8_fnt_00563e98,DAT_00582744);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x42c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x42c,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x42d,0xc9,0xd5,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x42d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x42d,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x42e,0xc9,0xe2,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x42e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x42e,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x42f,0x2e,0xe2,s_VERDANA8_fnt_00563e98,DAT_00582300);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x42f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x42f,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x430,0x2e,0xef,s_VERDANA8_fnt_00563e98,DAT_00580c80);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x430,0);
    Window_GadgetNotify_Text_SetLayout(self,0x430,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x431,0xc9,0xef,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x431,0);
    Window_GadgetNotify_Text_SetLayout(self,0x431,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x432,0x2e,0x134,s_VERDANA8_fnt_00563e98,DAT_00582a20);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x432,0);
    Window_GadgetNotify_Text_SetLayout(self,0x432,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x433,0xc9,0x134,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x433,0);
    Window_GadgetNotify_Text_SetLayout(self,0x433,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x434,0xc9,0x141,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x434,0);
    Window_GadgetNotify_Text_SetLayout(self,0x434,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x435,0x2e,0x141,s_VERDANA8_fnt_00563e98,DAT_0058240c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x435,0);
    Window_GadgetNotify_Text_SetLayout(self,0x435,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x436,0x2e,0x14e,s_VERDANA8_fnt_00563e98,DAT_00581658);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x436,0);
    Window_GadgetNotify_Text_SetLayout(self,0x436,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x437,0xc9,0x14e,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x437,0);
    Window_GadgetNotify_Text_SetLayout(self,0x437,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x438,0xc9,0x17b,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x438,0);
    Window_GadgetNotify_Text_SetLayout(self,0x438,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x439,0x2e,0x17b,s_VERDANA8_fnt_00563e98,DAT_00581084);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x439,0);
    Window_GadgetNotify_Text_SetLayout(self,0x439,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x43a,0x2e,0x188,s_VERDANA8_fnt_00563e98,DAT_00581d20);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x43a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x43a,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x43b,0xc9,0x188,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x43b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x43b,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x43c,0xc9,0x195,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x43c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x43c,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x43d,0x2e,0x195,s_VERDANA8_fnt_00563e98,DAT_00582ae0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x43d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x43d,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x43e,0x2e,0x1c1,s_VERDANA8_fnt_00563e98,DAT_00582014);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x43e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x43e,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x43f,0xc9,0x1c1,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x43f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x43f,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x440,0x2e,0x1d2,s_VERDANA14_fnt_00564d8c,DAT_00582d38);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x440,0);
    Window_GadgetNotify_Text_SetLayout(self,0x440,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x441,0x9a,0x1d6,s_VERDANA10_fnt_00563e64,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x441,0);
    Window_GadgetNotify_Text_SetLayout(self,0x441,1,0x87,0xffff,0);
  }
  value1 = UI_AddText(self,0x472,0x1c7,0x5a,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x472,0);
    Window_GadgetNotify_Text_SetLayout(self,0x472,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x473,300,0x5a,s_VERDANA8_fnt_00563e98,s__Pizzeria_Dummy_00565890);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x473,0);
    Window_GadgetNotify_Text_SetLayout(self,0x473,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x474,300,0x67,s_VERDANA8_fnt_00563e98,s__Pizzeria_Dummy_00565890);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x474,0);
    Window_GadgetNotify_Text_SetLayout(self,0x474,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x475,0x1c7,0x67,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x475,0);
    Window_GadgetNotify_Text_SetLayout(self,0x475,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x476,0x1c7,0x74,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x476,0);
    Window_GadgetNotify_Text_SetLayout(self,0x476,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x477,300,0x74,s_VERDANA8_fnt_00563e98,s__Pizzeria_Dummy_00565890);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x477,0);
    Window_GadgetNotify_Text_SetLayout(self,0x477,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x478,300,0x81,s_VERDANA8_fnt_00563e98,s__Pizzeria_Dummy_00565890);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x478,0);
    Window_GadgetNotify_Text_SetLayout(self,0x478,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x479,0x1c7,0x81,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x479,0);
    Window_GadgetNotify_Text_SetLayout(self,0x479,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x47a,0x1c7,0x8e,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x47a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x47a,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x47b,300,0x8e,s_VERDANA8_fnt_00563e98,s__Pizzeria_Dummy_00565890);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x47b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x47b,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x47c,300,0x9b,s_VERDANA8_fnt_00563e98,s__Pizzeria_Dummy_00565890);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x47c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x47c,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x47d,0x1c7,0x9b,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x47d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x47d,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x47e,0x1c7,0xa8,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x47e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x47e,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x47f,300,0xa8,s_VERDANA8_fnt_00563e98,s__Pizzeria_Dummy_00565890);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x47f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x47f,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x480,300,0xb5,s_VERDANA8_fnt_00563e98,s__Pizzeria_Dummy_00565890);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x480,0);
    Window_GadgetNotify_Text_SetLayout(self,0x480,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x481,0x1c7,0xb5,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x481,0);
    Window_GadgetNotify_Text_SetLayout(self,0x481,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x482,0x1c7,0xc2,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x482,0);
    Window_GadgetNotify_Text_SetLayout(self,0x482,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x483,300,0xc2,s_VERDANA8_fnt_00563e98,s__Pizzeria_Dummy_00565890);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x483,0);
    Window_GadgetNotify_Text_SetLayout(self,0x483,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x484,300,0xcf,s_VERDANA8_fnt_00563e98,s__Pizzeria_Dummy_00565890);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x484,0);
    Window_GadgetNotify_Text_SetLayout(self,0x484,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x485,0x1c7,0xcf,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x485,0);
    Window_GadgetNotify_Text_SetLayout(self,0x485,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x486,0x1c7,0xdc,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x486,0);
    Window_GadgetNotify_Text_SetLayout(self,0x486,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x487,300,0xdc,s_VERDANA8_fnt_00563e98,s__Pizzeria_Dummy_00565890);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x487,0);
    Window_GadgetNotify_Text_SetLayout(self,0x487,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x488,300,0xe9,s_VERDANA8_fnt_00563e98,s__Pizzeria_Dummy_00565890);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x488,0);
    Window_GadgetNotify_Text_SetLayout(self,0x488,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x489,0x1c7,0xe9,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x489,0);
    Window_GadgetNotify_Text_SetLayout(self,0x489,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x48a,0x1c7,0xf6,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x48a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x48a,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x48b,300,0xf6,s_VERDANA8_fnt_00563e98,s__Pizzeria_Dummy_00565890);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x48b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x48b,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x48c,300,0x103,s_VERDANA8_fnt_00563e98,s__Pizzeria_Dummy_00565890);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x48c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x48c,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x48d,0x1c7,0x103,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x48d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x48d,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x48e,0x1c7,0x110,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x48e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x48e,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x48f,300,0x110,s_VERDANA8_fnt_00563e98,s__Pizzeria_Dummy_00565890);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x48f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x48f,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x490,300,0x11d,s_VERDANA8_fnt_00563e98,s__Pizzeria_Dummy_00565890);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x490,0);
    Window_GadgetNotify_Text_SetLayout(self,0x490,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x491,0x1c7,0x11d,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x491,0);
    Window_GadgetNotify_Text_SetLayout(self,0x491,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x492,0x1c7,0x12a,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x492,0);
    Window_GadgetNotify_Text_SetLayout(self,0x492,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x493,300,0x12a,s_VERDANA8_fnt_00563e98,s__Pizzeria_Dummy_00565890);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x493,0);
    Window_GadgetNotify_Text_SetLayout(self,0x493,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x494,300,0x137,s_VERDANA8_fnt_00563e98,s__Pizzeria_Dummy_00565890);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x494,0);
    Window_GadgetNotify_Text_SetLayout(self,0x494,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x495,0x1c7,0x137,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x495,0);
    Window_GadgetNotify_Text_SetLayout(self,0x495,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x496,0x1c7,0x144,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x496,0);
    Window_GadgetNotify_Text_SetLayout(self,0x496,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x497,300,0x144,s_VERDANA8_fnt_00563e98,s__Pizzeria_Dummy_00565890);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x497,0);
    Window_GadgetNotify_Text_SetLayout(self,0x497,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x498,300,0x151,s_VERDANA8_fnt_00563e98,s__Pizzeria_Dummy_00565890);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x498,0);
    Window_GadgetNotify_Text_SetLayout(self,0x498,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x499,0x1c7,0x151,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x499,0);
    Window_GadgetNotify_Text_SetLayout(self,0x499,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x4a2,0x1c7,0x17c,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4a2,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4a2,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x4a3,300,0x17c,s_VERDANA8_fnt_00563e98,DAT_00581d68);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4a3,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4a3,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x4a4,300,0x1a2,s_VERDANA8_fnt_00563e98,DAT_00582458);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4a4,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4a4,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x4a5,0x1c7,0x1a2,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4a5,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4a5,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x4a6,0x1c7,0x1b4,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4a6,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4a6,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x4a7,300,0x1b4,s_VERDANA8_fnt_00563e98,DAT_005811d8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4a7,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4a7,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x4aa,300,0x1d2,s_VERDANA14_fnt_00564d8c,DAT_00581e88);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4aa,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4aa,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x4ab,0x199,0x1d6,s_VERDANA10_fnt_00563e64,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4ab,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4ab,1,0x87,0xffff,0);
  }
  value1 = UI_AddText(self,0x4ac,300,0x18a,s_VERDANA8_fnt_00563e98,DAT_00581084);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4ac,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4ac,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x4ad,0x1c7,0x18a,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4ad,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4ad,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x4ae,300,0x1f9,s_VERDANA8_fnt_00563e98,DAT_00581ff4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4ae,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4ae,0,0x91,0xffff,0);
  }
  value1 = UI_AddText(self,0x4af,0x19b,0x1f9,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4af,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4af,1,0x78,0xffff,0);
  }
  value1 = UI_AddText(self,0x4b0,0x2e,0x1f9,s_VERDANA8_fnt_00563e98,DAT_00581ff4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4b0,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4b0,0,0x78,0xffff,0);
  }
  value1 = UI_AddText(self,0x4b1,0xab,0x1f9,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4b1,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4b1,1,0x78,0xffff,0);
  }
  UI_AddImage(self,0x4b2,0x301,0xff,s_PB33_00_spr_00564ba0,0,0);
  UI_AddImage(self,0x4b3,0x25e,0x207,s_PB22_00_spr_00564174,0,0);
  value1 = UI_AddTextButton(self,0x4b4,0x272,0x208,s_VERDANA8_fnt_00563e98,s__Alle_Quartale_00565880,
                           0,s_TEXTPB05__00_spr_00564160);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x4b4,0,0,0);
    Gadget_SetButtonTextLayout(self,0x4b4,2,0x93,0,0,0xfffe);
  }
  UI_AddImage(self,0x4b5,0x2ff,0x207,s_PB24_00_spr_00564144,0,0);
  UI_AddImage(self,0x4b6,0x25e,0x22b,s_PB22_00_spr_00564174,0,0);
  value1 = UI_AddTextButton(self,0x4b7,0x272,0x22c,s_VERDANA8_fnt_00563e98,s__Jahr__2010_00565870,0,
                           s_TEXTPB05__00_spr_00564160);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x4b7,0,0,0);
    Gadget_SetButtonTextLayout(self,0x4b7,2,0x93,0,0,0xfffe);
  }
  UI_AddImage(self,0x4b8,0x2ff,0x22b,s_PB24_00_spr_00564144,0,0);
  value1 = UI_AddText(self,0x4b9,300,0x15f,s_VERDANA8_fnt_00563e98,DAT_00582200);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4b9,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4b9,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x4ba,0x1c7,0x15f,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4ba,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4ba,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x4bd,300,0x16d,s_VERDANA8_fnt_00563e98,DAT_00582a38);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4bd,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4bd,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x4be,0x1c7,0x16d,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4be,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4be,1,0x5a,0xffff,0);
  }
  UI_AddImage(self,8000,0x23c,0xd9,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  value1 = UI_AddText(self,0x1f42,0x2e,0x1b2,s_VERDANA8_fnt_00563e98,DAT_00582c00);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f42,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f42,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x1f43,0xc9,0x1b2,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f43,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f43,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x1f44,0x2d,0x1a2,s_VERDANA8_fnt_00563e98,DAT_00582458);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f44,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f44,0,0xa0,0xffff,0);
  }
  value1 = UI_AddText(self,0x1f45,200,0x1a2,s_VERDANA8_fnt_00563e98,s__1_000_000__005650ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f45,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f45,1,0x5a,0xffff,0);
  }
  return self;
}
