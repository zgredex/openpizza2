// Screen_SubStartMenu_B: ported from Pizza Connection 2 at 0x46e960.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x46e960
#include "pc2_port.h"


void * __cdecl Screen_SubStartMenu_B(int *arg1)

{
  int value1;
  void *self;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
  value1 = UI_CreateWindow(DAT_0057c5e0,0,0,s_PE_SUB_STARTSCREEN_spr_00567288,&LAB_004c7f30);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  value1 = UI_AddText(self,0x440,0x25d,0xe0,s_TIMESFONT_fnt_00563ea8,DAT_00581878);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x440,0);
    Window_GadgetNotify_Text_SetLayout(self,0x440,2,0xbe,0,0);
  }
  value1 = UI_AddText(self,0x46e,0x272,0x113,s_VERDANA8_fnt_00563e98,DAT_00581df0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x46e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x46e,2,0x96,0,0);
  }
  value1 = UI_AddText(self,0x514,0x272,0x133,s_VERDANA8_fnt_00563e98,DAT_00582ee0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x514,0);
    Window_GadgetNotify_Text_SetLayout(self,0x514,2,0x96,0,0);
  }
  value1 = UI_AddText(self,0x470,0x272,0x152,s_VERDANA8_fnt_00563e98,DAT_00580e94);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x470,0);
    Window_GadgetNotify_Text_SetLayout(self,0x470,2,0x96,0,0);
  }
  value1 = UI_CreateSlider(self,8000,0x27b,0x129,0x8c,s_SL02_00_spr_005642d0,0,0);
  if (value1 != 0) {
    local_10 = 0xffff;
    local_c = 0xf300;
    local_8 = 0xff;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,8000,&local_10);
  }
  value1 = UI_CreateSlider(self,0x1f41,0x27b,0x147,0x8c,s_SL02_00_spr_005642d0,0,0);
  if (value1 != 0) {
    local_10 = 0xffff;
    local_c = 0xf300;
    local_8 = 0xff;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x1f41,&local_10);
  }
  value1 = UI_CreateSlider(self,0x1f42,0x27b,0x166,0x8c,s_SL02_00_spr_005642d0,0,0);
  if (value1 != 0) {
    local_10 = 0xffff;
    local_c = 0xf300;
    local_8 = 0xff;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x1f42,&local_10);
  }
  value1 = UI_AddText(self,0x474,0x25c,0xff,s_VERDANA10_fnt_00563e64,DAT_0058128c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x474,0);
    Window_GadgetNotify_Text_SetLayout(self,0x474,2,0xbe,0,0);
  }
  UI_AddSprite(self,0x475,600,0x178,s_TRENNZEILE_spr_00563eb8);
  UI_AddImage(self,0x1f44,0x26d,0x19c,s_PB14_00_spr_005642c4,1,0);
  value1 = UI_AddText(self,0x477,0x287,0x19a,s_VERDANA8_fnt_00563e98,DAT_005824d8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x477,0);
    Window_GadgetNotify_Text_SetLayout(self,0x477,0,0x8c,0x1e,0);
  }
  value1 = UI_AddText(self,0x478,0x25c,0x183,s_VERDANA10_fnt_00563e64,DAT_00581878);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x478,0);
    Window_GadgetNotify_Text_SetLayout(self,0x478,2,0xbe,0,0);
  }
  value1 = UI_AddText(self,0x479,0x273,0x1c4,s_VERDANA8_fnt_00563e98,DAT_00581a30);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x479,0);
    Window_GadgetNotify_Text_SetLayout(self,0x479,2,0x96,0,0);
  }
  value1 = UI_CreateSlider(self,0x1f45,0x27e,0x1d9,0x8c,s_SL02_00_spr_005642d0,0,0);
  if (value1 != 0) {
    local_10 = 0xffff;
    local_c = 0xf300;
    local_8 = 0xff;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x1f45,&local_10);
  }
  value1 = UI_AddText(self,0x1f46,0x274,0x1df,s_VERDANA8_fnt_00563e98,DAT_00580fb4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f46,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f46,2,0x96,0,0);
  }
  value1 = UI_AddText(self,0x47c,0x274,0x1fc,s_VERDANA8_fnt_00563e98,DAT_00580be8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x47c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x47c,2,0x96,0,0);
  }
  value1 = UI_CreateSlider(self,0x1f47,0x27f,0x211,0x8c,s_SL02_00_spr_005642d0,0,0);
  if (value1 != 0) {
    local_10 = 0xffff;
    local_c = 0xf300;
    local_8 = 0xff;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x1f47,&local_10);
  }
  value1 = UI_AddText(self,0x1f48,0x27e,0x216,s_VERDANA8_fnt_00563e98,DAT_00582e68);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f48,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f48,2,0x84,0,3);
  }
  return self;
}
