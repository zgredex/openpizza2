// Glossary_BuildTargetGroupsPage: ported from Pizza Connection 2 at 0x43cee0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x43cee0
#include "pc2_port.h"


void * __cdecl Glossary_BuildTargetGroupsPage(int *arg1)

{
  int value1;
  void *self;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
                    /* Builds the glossary target-groups page. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0,0,s_STATISTIKBACKSPRITENEUTRAL_spr_00565d44,&LAB_004afe70);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  value1 = UI_AddText(self,1000,0x25d,0xdf,s_TIMESFONT_fnt_00563ea8,DAT_00582db4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,1000,0);
    Window_GadgetNotify_Text_SetLayout(self,1000,2,0xbe,0xffff,0);
  }
  UI_AddImage(self,0x3e9,0x263,0xff,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x3ea,0x263,0x114,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x3eb,0x263,0x129,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x3ec,0x263,0x13e,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x3ed,0x263,0x153,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x3ee,0x263,0x168,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x3ef,0x263,0x17d,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x3f0,0x263,0x192,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x3f1,0x263,0x1a7,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x3f2,0x263,0x1bc,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x3f3,0x263,0x1d1,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x3f4,0x263,0x1e6,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x3f5,0x263,0x1fb,s_TABPB01__00_spr_00564670,1,0);
  value1 = UI_CreateSlider(self,0x3f6,0x30f,0x105,0x109,s_SL01_00_spr_0056448c,0,1);
  if (value1 != 0) {
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x3f6,&local_10);
  }
  UI_AddImage(self,0x3f7,700,0x220,s_SKBAUEN_00_spr_00565d34,1,0);
  UI_AddImage(self,0x3f8,0x28f,0x220,s_SKFILIALE_00_spr_005654fc,1,0);
  UI_AddImage(self,0x3f9,0x262,0x220,s_SKPEOPLE_00_spr_00565d24,1,0);
  UI_AddImage(self,0x3fa,0x2e9,0x220,s_SKSMILEY_00_spr_00565d14,1,0);
  value1 = UI_AddText(self,0x3fc,0xe9,0x39,s_VERDANA16_fnt_00565788,DAT_00582a24);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3fc,0);
    Window_GadgetNotify_Text_SetLayout(self,0x3fc,2,0x78,0xffff,0);
  }
  value1 = UI_AddText(self,0x3fd,0xa5,0x57,s_VEDANA11_fnt_00564090,s__Yuppie_005660d4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3fd,0);
    Window_GadgetNotify_Text_SetLayout(self,0x3fd,0,0x96,0xffff,0);
  }
  value1 = UI_AddText(self,0x3fe,0xa5,0x70,s_VERDANA8_fnt_00563e98,
                     s__Blablablablablablablabla_00565cd0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3fe,0);
    Window_GadgetNotify_Text_SetLayout(self,0x3fe,0,0x186,0x94,0);
  }
  value1 = UI_AddText(self,0x41f,0x266,0x103,s_VERDANA8_fnt_00563e98,s__Kids_005660cc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x41f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x41f,0,0x9b,0xffff,0);
  }
  value1 = UI_AddText(self,0x420,0x266,0x118,s_VERDANA8_fnt_00563e98,s__Teens_005660c4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x420,0);
    Window_GadgetNotify_Text_SetLayout(self,0x420,0,0x9b,0xffff,0);
  }
  value1 = UI_AddText(self,0x421,0x266,0x12d,s_VERDANA8_fnt_00563e98,s__Studies_005660b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x421,0);
    Window_GadgetNotify_Text_SetLayout(self,0x421,0,0x9b,0xffff,0);
  }
  value1 = UI_AddText(self,0x422,0x266,0x142,s_VERDANA8_fnt_00563e98,s__Prolls_005660b0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x422,0);
    Window_GadgetNotify_Text_SetLayout(self,0x422,0,0x9b,0xffff,0);
  }
  value1 = UI_AddText(self,0x423,0x266,0x157,s_VERDANA8_fnt_00563e98,s__Yuppies_005660a4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x423,0);
    Window_GadgetNotify_Text_SetLayout(self,0x423,0,0x9b,0xffff,0);
  }
  value1 = UI_AddText(self,0x424,0x266,0x16c,s_VERDANA8_fnt_00563e98,s__Bonzen_0056609c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x424,0);
    Window_GadgetNotify_Text_SetLayout(self,0x424,0,0x9b,0xffff,0);
  }
  value1 = UI_AddText(self,0x425,0x266,0x181,s_VERDANA8_fnt_00563e98,s__Grufties_00566090);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x425,0);
    Window_GadgetNotify_Text_SetLayout(self,0x425,0,0x9b,0xffff,0);
  }
  value1 = UI_AddText(self,0x426,0x266,0x196,s_VERDANA8_fnt_00563e98,s__Touries_00566084);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x426,0);
    Window_GadgetNotify_Text_SetLayout(self,0x426,0,0x9b,0xffff,0);
  }
  value1 = UI_AddText(self,0x427,0x266,0x1ab,s_VERDANA8_fnt_00563e98,s__Reinigungskraft_00566070);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x427,0);
    Window_GadgetNotify_Text_SetLayout(self,0x427,0,0x9b,0xffff,0);
  }
  value1 = UI_AddText(self,0x428,0x266,0x1c0,s_VERDANA8_fnt_00563e98,&DAT_00566060);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x428,0);
    Window_GadgetNotify_Text_SetLayout(self,0x428,0,0x9b,0xffff,0);
  }
  value1 = UI_AddText(self,0x429,0x266,0x1d5,s_VERDANA8_fnt_00563e98,s__Beamter_00566054);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x429,0);
    Window_GadgetNotify_Text_SetLayout(self,0x429,0,0x9b,0xffff,0);
  }
  value1 = UI_AddText(self,0x42a,0x266,0x1ea,s_VERDANA8_fnt_00563e98,s__Wache_0056604c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x42a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x42a,0,0x9b,0xffff,0);
  }
  value1 = UI_AddText(self,0x42b,0x266,0x1ff,s_VERDANA8_fnt_00563e98,s__Gangster_00566040);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x42b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x42b,0,0x9b,0xffff,0);
  }
  UI_AddSprite(self,0x42d,0x136,0x116,s_TAB07_spr_00565d7c);
  UI_AddSprite(self,0x42e,0x13e,0x128,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x42f,0x1d6,0xcf,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x430,0x1bd,0xd0,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x431,0x1a6,0xcf,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x432,0x18e,0xce,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x433,0x173,0xcf,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x434,0x158,0xd0,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x435,0x13b,0xcf,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x436,0x11c,0xce,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x437,0xfe,0xcb,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x438,0xdc,0xce,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x439,0xbd,0xce,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x43a,0xa0,0xce,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x43b,0x82,0xce,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x43c,0x5f,0xcd,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x43d,0x3d,0xcb,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x43e,0x1c,0xca,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x43f,0x15a,0x128,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x4b6,0x13e,0x144,s_BEWERTUNG__00_spr_00564018);
  value1 = UI_AddText(self,0x86e,0xfa,0x11b,s_VERDANA8_fnt_00563e98,DAT_00581e38);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x86e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x86e,1,0x3c,0xffff,0);
  }
  value1 = UI_AddText(self,0x86f,0xde,0x12f,s_VERDANA7_fnt_00563ec8,&DAT_00566030);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x86f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x86f,1,0x5f,0xffff,0);
  }
  value1 = UI_AddText(self,0x870,0xde,0x14b,s_VERDANA7_fnt_00563ec8,&DAT_00566030);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x870,0);
    Window_GadgetNotify_Text_SetLayout(self,0x870,1,0x5f,0xffff,0);
  }
  value1 = UI_AddText(self,0x871,0xde,0x167,s_VERDANA7_fnt_00563ec8,&DAT_00566030);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x871,0);
    Window_GadgetNotify_Text_SetLayout(self,0x871,1,0x5f,0xffff,0);
  }
  value1 = UI_AddText(self,0x872,0xde,0x183,s_VERDANA7_fnt_00563ec8,&DAT_00566030);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x872,0);
    Window_GadgetNotify_Text_SetLayout(self,0x872,1,0x5f,0xffff,0);
  }
  value1 = UI_AddText(self,0x873,0xde,0x1a0,s_VERDANA7_fnt_00563ec8,&DAT_00566030);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x873,0);
    Window_GadgetNotify_Text_SetLayout(self,0x873,1,0x5f,0xffff,0);
  }
  value1 = UI_AddText(self,0x874,0xde,0x1bc,s_VERDANA7_fnt_00563ec8,&DAT_00566030);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x874,0);
    Window_GadgetNotify_Text_SetLayout(self,0x874,1,0x5f,0xffff,0);
  }
  value1 = UI_AddText(self,0x875,0xde,0x1d9,s_VERDANA7_fnt_00563ec8,&DAT_00566030);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x875,0);
    Window_GadgetNotify_Text_SetLayout(self,0x875,1,0x5f,0xffff,0);
  }
  value1 = UI_AddText(self,0x876,0xde,0x1f5,s_VERDANA7_fnt_00563ec8,&DAT_00566030);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x876,0);
    Window_GadgetNotify_Text_SetLayout(self,0x876,1,0x5f,0xffff,0);
  }
  value1 = UI_AddText(self,0x877,0x139,0x106,s_VERDANA10_fnt_00563e64,DAT_005826a8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x877,0);
    Window_GadgetNotify_Text_SetLayout(self,0x877,0,0xeb,0xffff,0);
  }
  value1 = UI_AddText(self,0x878,0x13b,0x11b,s_VERDANA8_fnt_00563e98,&DAT_00564220);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x878,0);
    Window_GadgetNotify_Text_SetLayout(self,0x878,0,0x14,0xffff,0);
  }
  value1 = UI_AddText(self,0x879,0x157,0x11b,s_VERDANA8_fnt_00563e98,&DAT_0056421c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x879,0);
    Window_GadgetNotify_Text_SetLayout(self,0x879,0,0x14,0xffff,0);
  }
  value1 = UI_AddText(self,0x87a,0x173,0x11b,s_VERDANA8_fnt_00563e98,&DAT_00564218);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x87a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x87a,0,0x14,0xffff,0);
  }
  value1 = UI_AddText(self,0x87b,399,0x11b,s_VERDANA8_fnt_00563e98,&DAT_00564214);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x87b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x87b,0,0x14,0xffff,0);
  }
  value1 = UI_AddText(self,0x87c,0x1a7,0x11b,s_VERDANA8_fnt_00563e98,&DAT_00564210);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x87c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x87c,0,0x14,0xffff,0);
  }
  value1 = UI_AddText(self,0x87d,0x1c3,0x11b,s_VERDANA8_fnt_00563e98,&DAT_0056420c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x87d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x87d,0,0x14,0xffff,0);
  }
  value1 = UI_AddText(self,0x87e,0x1df,0x11b,s_VERDANA8_fnt_00563e98,&DAT_00564208);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x87e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x87e,0,0x14,0xffff,0);
  }
  value1 = UI_AddText(self,0x87f,0x1fb,0x11b,s_VERDANA8_fnt_00563e98,&DAT_00564204);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x87f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x87f,0,0x14,0xffff,0);
  }
  value1 = UI_AddText(self,0x880,0x217,0x11b,s_VERDANA8_fnt_00563e98,&DAT_00564200);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x880,0);
    Window_GadgetNotify_Text_SetLayout(self,0x880,0,0x14,0xffff,0);
  }
  UI_AddSprite(self,0x881,0x37,0x5a,s_GLOSSAR_PERSONENDUMMY_spr_00566014);
  value1 = UI_AddText(self,0x9b4,0x19,0x112,s_VERDANA7_fnt_00563ec8,DAT_005824f8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x9b4,0);
    Window_GadgetNotify_Text_SetLayout(self,0x9b4,1,0x50,0xffff,0);
  }
  value1 = UI_AddText(self,0x9b5,0xa2,0x113,s_VERDANA7_fnt_00563ec8,DAT_005817b4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x9b5,0);
    Window_GadgetNotify_Text_SetLayout(self,0x9b5,0,0x41,0xffff,0);
  }
  value1 = UI_AddText(self,0x9b6,0xa2,0x12f,s_VERDANA7_fnt_00563ec8,DAT_00582f8c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x9b6,0);
    Window_GadgetNotify_Text_SetLayout(self,0x9b6,0,0x41,0xffff,0);
  }
  value1 = UI_AddText(self,0x9b7,0x19,0x12e,s_VERDANA7_fnt_00563ec8,DAT_005825f0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x9b7,0);
    Window_GadgetNotify_Text_SetLayout(self,0x9b7,1,0x50,0xffff,0);
  }
  value1 = UI_AddText(self,0x9b8,0x19,0x14a,s_VERDANA7_fnt_00563ec8,DAT_00582d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x9b8,0);
    Window_GadgetNotify_Text_SetLayout(self,0x9b8,1,0x50,0xffff,0);
  }
  value1 = UI_AddText(self,0x9b9,0x19,0x166,s_VERDANA7_fnt_00563ec8,DAT_00582c98);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x9b9,0);
    Window_GadgetNotify_Text_SetLayout(self,0x9b9,1,0x50,0xffff,0);
  }
  value1 = UI_AddText(self,0x9ba,0xa3,0x14b,s_VERDANA7_fnt_00563ec8,DAT_00581e8c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x9ba,0);
    Window_GadgetNotify_Text_SetLayout(self,0x9ba,0,0x41,0xffff,0);
  }
  value1 = UI_AddText(self,0x9bb,0xa2,0x167,s_VERDANA7_fnt_00563ec8,DAT_00581428);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x9bb,0);
    Window_GadgetNotify_Text_SetLayout(self,0x9bb,0,0x41,0xffff,0);
  }
  value1 = UI_AddText(self,0x9bc,0xa2,0x1d9,s_VERDANA7_fnt_00563ec8,DAT_00582bc8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x9bc,0);
    Window_GadgetNotify_Text_SetLayout(self,0x9bc,0,0x41,0xffff,0);
  }
  value1 = UI_AddText(self,0x9bd,0xa3,0x1bc,s_VERDANA7_fnt_00563ec8,DAT_00580f98);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x9bd,0);
    Window_GadgetNotify_Text_SetLayout(self,0x9bd,0,0x41,0xffff,0);
  }
  value1 = UI_AddText(self,0x9be,0xa2,0x1a0,s_VERDANA7_fnt_00563ec8,DAT_00582e34);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x9be,0);
    Window_GadgetNotify_Text_SetLayout(self,0x9be,0,0x41,0xffff,0);
  }
  value1 = UI_AddText(self,0x9bf,0xa3,0x183,s_VERDANA7_fnt_00563ec8,DAT_005819bc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x9bf,0);
    Window_GadgetNotify_Text_SetLayout(self,0x9bf,0,0x41,0xffff,0);
  }
  value1 = UI_AddText(self,0x9c0,0x19,0x182,s_VERDANA7_fnt_00563ec8,DAT_00582f68);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x9c0,0);
    Window_GadgetNotify_Text_SetLayout(self,0x9c0,1,0x50,0xffff,0);
  }
  value1 = UI_AddText(self,0x9c1,0x19,0x19f,s_VERDANA7_fnt_00563ec8,DAT_00581b7c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x9c1,0);
    Window_GadgetNotify_Text_SetLayout(self,0x9c1,1,0x50,0xffff,0);
  }
  value1 = UI_AddText(self,0x9c2,0x19,0x1bb,s_VERDANA7_fnt_00563ec8,DAT_00582a34);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x9c2,0);
    Window_GadgetNotify_Text_SetLayout(self,0x9c2,1,0x50,0xffff,0);
  }
  value1 = UI_AddText(self,0x9c3,0x19,0x1d8,s_VERDANA7_fnt_00563ec8,DAT_00581318);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x9c3,0);
    Window_GadgetNotify_Text_SetLayout(self,0x9c3,1,0x50,0xffff,0);
  }
  value1 = UI_AddText(self,0x9c4,0x19,500,s_VERDANA7_fnt_00563ec8,DAT_005827b4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x9c4,0);
    Window_GadgetNotify_Text_SetLayout(self,0x9c4,1,0x50,0xffff,0);
  }
  value1 = UI_AddText(self,0x9c5,0xa2,0x1f5,s_VERDANA7_fnt_00563ec8,DAT_00580f24);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x9c5,0);
    Window_GadgetNotify_Text_SetLayout(self,0x9c5,0,0x41,0xffff,0);
  }
  UI_AddImage(self,8000,0x23c,0xd9,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  UI_AddSprite(self,0x1f41,0x31,0x55,s_GLOSSARRAHMEN_00_spr_00565b6c);
  UI_AddSprite(self,0x1f5d,0x69,0x10b,s_BEWERTUNG2__00_spr_00566000);
  UI_AddSprite(self,0x1f5e,0x1d8,0xe1,s_BEWERTUNG2__01_spr_00565fec);
  UI_AddSprite(self,0x1f5f,0x1c2,0xe5,s_BEWERTUNG2__02_spr_00565fd8);
  UI_AddSprite(self,0x1f60,0x1a5,0xe2,s_BEWERTUNG2__03_spr_00565fc4);
  UI_AddSprite(self,0x1f61,0x18c,0xe0,s_BEWERTUNG2__04_spr_00565fb0);
  UI_AddSprite(self,0x1f62,0x172,0xe0,s_BEWERTUNG2__05_spr_00565f9c);
  UI_AddSprite(self,0x1f63,0x15c,0xe4,s_BEWERTUNG2__06_spr_00565f88);
  UI_AddSprite(self,0x1f64,0x13d,0xe3,s_BEWERTUNG2__07_spr_00565f74);
  UI_AddSprite(self,0x1f65,0x11e,0xe2,s_BEWERTUNG2__08_spr_00565f60);
  UI_AddSprite(self,0x1f66,0xfd,0xe2,s_BEWERTUNG2__09_spr_00565f4c);
  UI_AddSprite(self,0x1f67,0xde,0xdf,s_BEWERTUNG2__10_spr_00565f38);
  UI_AddSprite(self,0x1f68,0xbf,0xe2,s_BEWERTUNG2__11_spr_00565f24);
  UI_AddSprite(self,0x1f69,0xa2,0xe0,s_BEWERTUNG2__12_spr_00565f10);
  UI_AddSprite(self,0x1f6a,0x82,0xe0,s_BEWERTUNG2__13_spr_00565efc);
  UI_AddSprite(self,0x1f6b,0x60,0xdf,s_BEWERTUNG2__14_spr_00565ee8);
  UI_AddSprite(self,0x1f6c,0x40,0xde,s_BEWERTUNG2__15_spr_00565ed4);
  UI_AddSprite(self,0x1f6d,0x1d,0xdd,s_BEWERTUNG2__16_spr_00565ec0);
  UI_AddSprite(self,0x1f6e,0x84,0x10b,s_BEWERTUNG2__00_spr_00566000);
  UI_AddSprite(self,0x1f6f,0x6a,0x127,s_BEWERTUNG2__00_spr_00566000);
  return self;
}
