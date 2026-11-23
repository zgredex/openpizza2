// SoundOptionsPage_Create: ported from Pizza Connection 2 at 0x426840.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x426840
#include "pc2_port.h"


void * __cdecl SoundOptionsPage_Create(int *arg1)

{
  int value1;
  void *self;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
                    /* Creates the sound settings page. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004a1250);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  value1 = UI_AddText(self,0x44f,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00581060);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x44f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x44f,2,0xbe,0,0);
  }
  value1 = UI_AddText(self,0x450,0x41,0x47,s_VERDANA8_fnt_00563e98,DAT_00581df0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x450,0);
    Window_GadgetNotify_Text_SetLayout(self,0x450,2,0x96,0,0);
  }
  value1 = UI_AddText(self,0x451,0x41,0x84,s_VERDANA8_fnt_00563e98,DAT_00582ee0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x451,0);
    Window_GadgetNotify_Text_SetLayout(self,0x451,2,0x96,0,0);
  }
  value1 = UI_AddText(self,0x452,0x41,0xa7,s_VERDANA8_fnt_00563e98,DAT_00580e94);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x452,0);
    Window_GadgetNotify_Text_SetLayout(self,0x452,2,0x96,0,0);
  }
  value1 = UI_CreateSlider(self,0x43a,0x4a,0x5d,0x8c,s_SL02_00_spr_005642d0,0,0);
  if (value1 != 0) {
    local_10 = 0xffff;
    local_c = 0xf300;
    local_8 = 0xff;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x43a,&local_10);
  }
  value1 = UI_CreateSlider(self,0x43b,0x4a,0x9a,0x8c,s_SL02_00_spr_005642d0,0,0);
  if (value1 != 0) {
    local_10 = 0xffff;
    local_c = 0xf300;
    local_8 = 0xff;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x43b,&local_10);
  }
  value1 = UI_CreateSlider(self,0x43c,0x4a,0xbd,0x8c,s_SL02_00_spr_005642d0,0,0);
  if (value1 != 0) {
    local_10 = 0xffff;
    local_c = 0xf300;
    local_8 = 0xff;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x43c,&local_10);
  }
  UI_AddImage(self,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  value1 = UI_AddText(self,0x1f41,0x2b,0x25,s_VERDANA14_fnt_00564d8c,DAT_0058128c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f41,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f41,2,0xbe,0,0);
  }
  UI_AddSprite(self,0x1f50,0x27,0x14c,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddTextButton(self,0x1f51,0x30,0x15b,s_VERDANA8_fnt_00563e98,DAT_00582748,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x1f51,0,0,0);
    Gadget_SetButtonTextLayout(self,0x1f51,2,0xb4,0,0,0xfffe);
  }
  UI_AddSprite(self,0x1f52,0x27,0xf2,s_TRENNZEILE_spr_00563eb8);
  UI_AddImage(self,0x1f53,0x3c,0x125,s_PB14_00_spr_005642c4,1,0);
  value1 = UI_AddText(self,0x1f54,0x56,0x123,s_VERDANA8_fnt_00563e98,DAT_00581c08);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f54,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f54,0,0x8c,0x1e,0);
  }
  value1 = UI_AddText(self,0x1f55,0x2b,0xff,s_VERDANA14_fnt_00564d8c,DAT_00581878);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f55,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f55,2,0xbe,0,0);
  }
  return self;
}
