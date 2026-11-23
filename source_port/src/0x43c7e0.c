// Glossary_BuildHeadSymbolsPage: ported from Pizza Connection 2 at 0x43c7e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x43c7e0
#include "pc2_port.h"


void * __cdecl Glossary_BuildHeadSymbolsPage(int *arg1)

{
  int value1;
  void *self;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
                    /* Builds the glossary head-symbols page. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0,0,s_STATISTIKBACKSPRITENEUTRAL_spr_00565d44,&LAB_004af470);
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
  value1 = UI_AddText(self,0x3fc,0xe9,0x39,s_VERDANA16_fnt_00565788,DAT_00581a3c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3fc,0);
    Window_GadgetNotify_Text_SetLayout(self,0x3fc,2,0x78,0xffff,0);
  }
  value1 = UI_AddText(self,0x3fd,0xa5,0x57,s_VEDANA11_fnt_00564090,s__Baustelle_00565cec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3fd,0);
    Window_GadgetNotify_Text_SetLayout(self,0x3fd,0,0x181,0xffff,0);
  }
  value1 = UI_AddText(self,0x3fe,0xa5,0x70,s_VERDANA8_fnt_00563e98,
                     s__Blablablablablablablabla_00565cd0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3fe,0);
    Window_GadgetNotify_Text_SetLayout(self,0x3fe,0,0x186,0xb4,0);
  }
  value1 = UI_AddText(self,0x3ff,0x11e,0x136,s_VEDANA11_fnt_00564090,DAT_00582830);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3ff,0);
    Window_GadgetNotify_Text_SetLayout(self,0x3ff,0,0xfa,0xffff,0);
  }
  value1 = UI_AddText(self,0x400,0x11e,0x155,s_VERDANA8_fnt_00563e98,
                     s__Blablablablablablablablablablab_00565e84);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x400,0);
    Window_GadgetNotify_Text_SetLayout(self,0x400,0,0x104,0xb9,0);
  }
  UI_AddImage(self,0x42c,0x26a,0x109,s_ZUTABPB__00_spr_00564180,1,0);
  UI_AddImage(self,0x42d,0x29f,0x109,s_ZUTABPB__00_spr_00564180,1,0);
  UI_AddImage(self,0x42e,0x2d4,0x109,s_ZUTABPB__00_spr_00564180,1,0);
  UI_AddImage(self,0x42f,0x26a,0x135,s_ZUTABPB__00_spr_00564180,1,0);
  UI_AddImage(self,0x430,0x29f,0x135,s_ZUTABPB__00_spr_00564180,1,0);
  UI_AddImage(self,0x431,0x2d4,0x135,s_ZUTABPB__00_spr_00564180,1,0);
  UI_AddImage(self,0x432,0x26a,0x161,s_ZUTABPB__00_spr_00564180,1,0);
  UI_AddImage(self,0x433,0x29f,0x161,s_ZUTABPB__00_spr_00564180,1,0);
  UI_AddImage(self,0x434,0x2d4,0x161,s_ZUTABPB__00_spr_00564180,1,0);
  UI_AddImage(self,0x435,0x26a,0x18d,s_ZUTABPB__00_spr_00564180,1,0);
  UI_AddImage(self,0x436,0x29f,0x18d,s_ZUTABPB__00_spr_00564180,1,0);
  UI_AddImage(self,0x437,0x2d4,0x18d,s_ZUTABPB__00_spr_00564180,1,0);
  UI_AddImage(self,0x438,0x26a,0x1b9,s_ZUTABPB__00_spr_00564180,1,0);
  UI_AddImage(self,0x439,0x29f,0x1b9,s_ZUTABPB__00_spr_00564180,1,0);
  UI_AddImage(self,0x43a,0x2d4,0x1b9,s_ZUTABPB__00_spr_00564180,1,0);
  UI_AddImage(self,0x43b,0x26a,0x1e5,s_ZUTABPB__00_spr_00564180,1,0);
  UI_AddImage(self,0x43c,0x29f,0x1e5,s_ZUTABPB__00_spr_00564180,1,0);
  UI_AddImage(self,0x43d,0x2d4,0x1e5,s_ZUTABPB__00_spr_00564180,1,0);
  UI_AddImage(self,8000,0x23c,0xd9,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  UI_AddSprite(self,0x1f42,0x29,0x50,s_BLASE_spr_00565e78);
  UI_CreateAnimationWindow(self,4000,0x274,0x10f,s_KOPFICON_ani_00565e68);
  UI_CreateAnimationWindow(self,0xfa1,0x2a9,0x10f,s_KOPFICON_ani_00565e68);
  UI_CreateAnimationWindow(self,0xfa2,0x2de,0x10f,s_KOPFICON_ani_00565e68);
  UI_CreateAnimationWindow(self,0xfa3,0x275,0x13b,s_KOPFICON_ani_00565e68);
  UI_CreateAnimationWindow(self,0xfa4,0x2aa,0x13b,s_KOPFICON_ani_00565e68);
  UI_CreateAnimationWindow(self,0xfa5,0x2df,0x13b,s_KOPFICON_ani_00565e68);
  UI_CreateAnimationWindow(self,0xfa9,0x275,0x193,s_KOPFICON_ani_00565e68);
  UI_CreateAnimationWindow(self,0xfaa,0x2aa,0x193,s_KOPFICON_ani_00565e68);
  UI_CreateAnimationWindow(self,0xfab,0x2df,0x193,s_KOPFICON_ani_00565e68);
  UI_CreateAnimationWindow(self,0xfa6,0x274,0x167,s_KOPFICON_ani_00565e68);
  UI_CreateAnimationWindow(self,0xfa7,0x2a9,0x167,s_KOPFICON_ani_00565e68);
  UI_CreateAnimationWindow(self,0xfa8,0x2de,0x167,s_KOPFICON_ani_00565e68);
  UI_CreateAnimationWindow(self,0xfaf,0x275,0x1eb,s_KOPFICON_ani_00565e68);
  UI_CreateAnimationWindow(self,0xfb0,0x2aa,0x1eb,s_KOPFICON_ani_00565e68);
  UI_CreateAnimationWindow(self,0xfb1,0x2df,0x1eb,s_KOPFICON_ani_00565e68);
  UI_CreateAnimationWindow(self,0xfac,0x274,0x1bf,s_KOPFICON_ani_00565e68);
  UI_CreateAnimationWindow(self,0xfad,0x2a9,0x1bf,s_KOPFICON_ani_00565e68);
  UI_CreateAnimationWindow(self,0xfae,0x2de,0x1bf,s_KOPFICON_ani_00565e68);
  UI_CreateAnimationWindow(self,0x1f55,0x51,0x69,s_KOPFIBIG_ani_00565e58);
  return self;
}
