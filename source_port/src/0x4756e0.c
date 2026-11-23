// FreePlaySubMenu_BuildLoadSavegame: ported from Pizza Connection 2 at 0x4756e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4756e0
#include "pc2_port.h"


void * __cdecl FreePlaySubMenu_BuildLoadSavegame(int *arg1)

{
  int value1;
  void *self;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
                    /* Builds the free-play load-savegame list page. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0,0,s_PE_SUB_FREIES_SPIEL_spr_005674f0,&LAB_004ce610);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddImage(self,0x834,0x265,0x39,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x835,0x265,0x4e,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x836,0x265,99,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x837,0x265,0x78,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x838,0x265,0x8d,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x839,0x265,0xa2,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x83a,0x265,0xb7,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x83b,0x265,0xcc,s_TABPB01__00_spr_00564670,1,0);
  value1 = UI_AddText(self,0x440,0x25d,5,s_TIMESFONT_fnt_00563ea8,DAT_00582470);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x440,0);
    Window_GadgetNotify_Text_SetLayout(self,0x440,2,0xbe,0,0);
  }
  value1 = UI_AddText(self,0x441,0x264,0x28,s_VERDANA8_fnt_00563e98,DAT_00581db8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x441,0);
    Window_GadgetNotify_Text_SetLayout(self,0x441,0,0xb4,0,0);
  }
  UI_AddImage(self,0x83c,0x265,0xe1,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x83d,0x265,0xf6,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x83e,0x265,0x10b,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x83f,0x265,0x120,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x840,0x265,0x135,s_TABPB01__00_spr_00564670,1,0);
  value1 = UI_AddText(self,2000,0x26a,0x3d,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,2000,0);
    Window_GadgetNotify_Text_SetLayout(self,2000,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x7d1,0x26a,0x52,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x7d1,0);
    Window_GadgetNotify_Text_SetLayout(self,0x7d1,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x7d2,0x26a,0x67,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x7d2,0);
    Window_GadgetNotify_Text_SetLayout(self,0x7d2,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x7d3,0x26a,0x7c,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x7d3,0);
    Window_GadgetNotify_Text_SetLayout(self,0x7d3,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x7d4,0x26a,0x91,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x7d4,0);
    Window_GadgetNotify_Text_SetLayout(self,0x7d4,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x7d5,0x26a,0xa6,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x7d5,0);
    Window_GadgetNotify_Text_SetLayout(self,0x7d5,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x7d6,0x26a,0xbb,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x7d6,0);
    Window_GadgetNotify_Text_SetLayout(self,0x7d6,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x7d7,0x26a,0xd0,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x7d7,0);
    Window_GadgetNotify_Text_SetLayout(self,0x7d7,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x7d8,0x26a,0xe5,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x7d8,0);
    Window_GadgetNotify_Text_SetLayout(self,0x7d8,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x7d9,0x26a,0xfa,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x7d9,0);
    Window_GadgetNotify_Text_SetLayout(self,0x7d9,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x7da,0x26a,0x10f,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x7da,0);
    Window_GadgetNotify_Text_SetLayout(self,0x7da,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x7db,0x26a,0x124,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x7db,0);
    Window_GadgetNotify_Text_SetLayout(self,0x7db,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x7dc,0x26a,0x139,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x7dc,0);
    Window_GadgetNotify_Text_SetLayout(self,0x7dc,0,0x96,0,0);
  }
  value1 = UI_CreateSlider(self,0x462,0x30f,0x3f,0x18b,s_SL01_00_spr_0056448c,0,1);
  if (value1 != 0) {
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x462,&local_10);
  }
  UI_AddImage(self,0x841,0x265,0x149,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x842,0x265,0x15e,s_TABPB01__00_spr_00564670,1,0);
  value1 = UI_AddText(self,0x7dd,0x26a,0x14d,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x7dd,0);
    Window_GadgetNotify_Text_SetLayout(self,0x7dd,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x7de,0x26a,0x162,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x7de,0);
    Window_GadgetNotify_Text_SetLayout(self,0x7de,0,0x96,0,0);
  }
  value1 = UI_AddTextButton(self,0x463,0x2bd,0x1d5,s_VERDANA8_fnt_00563e98,DAT_00582ae4,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x463,0,0,0);
    Gadget_SetButtonTextLayout(self,0x463,2,0x54,0,0,0xfffe);
  }
  UI_AddImage(self,0x843,0x265,0x173,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x844,0x265,0x188,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x845,0x265,0x19d,s_TABPB01__00_spr_00564670,1,0);
  value1 = UI_AddText(self,0x7df,0x26a,0x177,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x7df,0);
    Window_GadgetNotify_Text_SetLayout(self,0x7df,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x7e0,0x26a,0x18c,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x7e0,0);
    Window_GadgetNotify_Text_SetLayout(self,0x7e0,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x7e1,0x26a,0x1a1,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x7e1,0);
    Window_GadgetNotify_Text_SetLayout(self,0x7e1,0,0x96,0,0);
  }
  UI_AddImage(self,0x846,0x265,0x1b1,s_TABPB01__00_spr_00564670,1,0);
  value1 = UI_AddText(self,0x7e2,0x26a,0x1b5,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x7e2,0);
    Window_GadgetNotify_Text_SetLayout(self,0x7e2,0,0x96,0,0);
  }
  return self;
}
