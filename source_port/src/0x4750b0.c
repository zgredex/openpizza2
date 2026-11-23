// Screen_SubStartMenu_A: ported from Pizza Connection 2 at 0x4750b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4750b0
#include "pc2_port.h"


void * __cdecl Screen_SubStartMenu_A(int *arg1)

{
  int value1;
  void *self;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
  value1 = UI_CreateWindow(DAT_0057c5e0,0,0,s_PE_SUB_STARTSCREEN_spr_00567288,&LAB_004ce090);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddImage(self,0x444,0x265,0x113,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x445,0x265,0x128,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x446,0x265,0x13d,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x447,0x265,0x152,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x448,0x265,0x167,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x449,0x265,0x17c,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x44a,0x265,0x191,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,1099,0x265,0x1a6,s_TABPB01__00_spr_00564670,1,0);
  value1 = UI_AddText(self,0x440,0x25d,0xe0,s_TIMESFONT_fnt_00563ea8,DAT_00582470);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x440,0);
    Window_GadgetNotify_Text_SetLayout(self,0x440,2,0xbe,0,0);
  }
  value1 = UI_AddText(self,0x441,0x264,0x102,s_VERDANA8_fnt_00563e98,DAT_00581db8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x441,0);
    Window_GadgetNotify_Text_SetLayout(self,0x441,0,0xb4,0,0);
  }
  UI_AddImage(self,0x44c,0x265,0x1bb,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x44d,0x265,0x1d0,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x44e,0x265,0x1e5,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x44f,0x265,0x1fa,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x450,0x265,0x20f,s_TABPB01__00_spr_00564670,1,0);
  value1 = UI_AddText(self,0x453,0x26a,0x117,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x453,0);
    Window_GadgetNotify_Text_SetLayout(self,0x453,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x454,0x26a,300,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x454,0);
    Window_GadgetNotify_Text_SetLayout(self,0x454,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x455,0x26a,0x141,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x455,0);
    Window_GadgetNotify_Text_SetLayout(self,0x455,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x456,0x26a,0x156,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x456,0);
    Window_GadgetNotify_Text_SetLayout(self,0x456,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x457,0x26a,0x16b,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x457,0);
    Window_GadgetNotify_Text_SetLayout(self,0x457,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x458,0x26a,0x180,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x458,0);
    Window_GadgetNotify_Text_SetLayout(self,0x458,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x459,0x26a,0x195,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x459,0);
    Window_GadgetNotify_Text_SetLayout(self,0x459,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x45a,0x26a,0x1aa,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x45a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x45a,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x45b,0x26a,0x1bf,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x45b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x45b,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x45c,0x26a,0x1d4,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x45c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x45c,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x45d,0x26a,0x1e9,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x45d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x45d,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x45e,0x26a,0x1fe,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x45e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x45e,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x45f,0x26a,0x213,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x45f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x45f,0,0x96,0,0);
  }
  value1 = UI_CreateSlider(self,0x462,0x30f,0x119,0x10e,s_SL01_00_spr_0056448c,0,1);
  if (value1 != 0) {
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x462,&local_10);
  }
  return self;
}
