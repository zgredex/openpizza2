// RecipeSelectPopup_CreateWindow: ported from Pizza Connection 2 at 0x46d910.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x46d910
#include "pc2_port.h"


void * __cdecl RecipeSelectPopup_CreateWindow(int *arg1)

{
  int value1;
  void *self;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
                    /* Creates the five-row recipe selection popup. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0x256,0,s_STADTUEBERL01_spr_0056714c,&LAB_004c6e10);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  value1 = UI_CreateSlider(self,1000,0xb8,0x41,0x4b,s_SL01_00_spr_0056448c,0,1);
  if (value1 != 0) {
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,1000,&local_10);
  }
  value1 = UI_AddText(self,0x3e9,0x17,3,s_TIMESFONT_fnt_00563ea8,DAT_00581680);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3e9,0);
    Window_GadgetNotify_Text_SetLayout(self,0x3e9,2,0xa0,0,0);
  }
  value1 = UI_AddText(self,0x3ea,0x13,0x22,s_VERDANA8_fnt_00563e98,DAT_00582038);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3ea,0);
    Window_GadgetNotify_Text_SetLayout(self,0x3ea,2,0xa0,0,0);
  }
  UI_AddImage(self,0x3eb,0x27,0x33,s_TABPB02__00_spr_0056713c,1,0);
  UI_AddImage(self,0x3ec,0x27,0x48,s_TABPB02__00_spr_0056713c,1,0);
  UI_AddImage(self,0x3ed,0x27,0x72,s_TABPB02__00_spr_0056713c,1,0);
  UI_AddImage(self,0x3ee,0x27,0x5d,s_TABPB02__00_spr_0056713c,1,0);
  UI_AddImage(self,0x3ef,0x27,0x87,s_TABPB02__00_spr_0056713c,1,0);
  value1 = UI_AddText(self,0x3f0,0x2c,0x36,s_VERDANA8_fnt_00563e98,s__Blablablabla_0056712c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3f0,0);
    Window_GadgetNotify_Text_SetLayout(self,0x3f0,0,0x78,0,0);
  }
  value1 = UI_AddText(self,0x3f1,0x2c,0x4b,s_VERDANA8_fnt_00563e98,s__Blablablabla_0056712c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3f1,0);
    Window_GadgetNotify_Text_SetLayout(self,0x3f1,0,0x78,0,0);
  }
  value1 = UI_AddText(self,0x3f2,0x2c,0x60,s_VERDANA8_fnt_00563e98,s__Blablablabla_0056712c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3f2,0);
    Window_GadgetNotify_Text_SetLayout(self,0x3f2,0,0x78,0,0);
  }
  value1 = UI_AddText(self,0x3f3,0x2c,0x75,s_VERDANA8_fnt_00563e98,s__Blablablabla_0056712c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3f3,0);
    Window_GadgetNotify_Text_SetLayout(self,0x3f3,0,0x78,0,0);
  }
  value1 = UI_AddText(self,0x3f4,0x2c,0x8a,s_VERDANA8_fnt_00563e98,s__Blablablabla_0056712c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3f4,0);
    Window_GadgetNotify_Text_SetLayout(self,0x3f4,0,0x78,0,0);
  }
  return self;
}
