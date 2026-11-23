// GameOptionsPage_Create: ported from Pizza Connection 2 at 0x427270.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x427270
#include "pc2_port.h"


void * __cdecl GameOptionsPage_Create(int *arg1)

{
  int value1;
  void *self;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
                    /* Creates the game settings page. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004a22b0);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  value1 = UI_AddText(self,0x44f,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00581470);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x44f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x44f,2,0xbe,0,0);
  }
  UI_AddImage(self,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  UI_AddSprite(self,0x1f50,0x27,0x14c,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddTextButton(self,0x1f51,0x30,0x15b,s_VERDANA8_fnt_00563e98,DAT_00582748,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x1f51,0,0,0);
    Gadget_SetButtonTextLayout(self,0x1f51,2,0xb4,0,0,0xfffe);
  }
  value1 = UI_AddText(self,0x1f55,0x41,0x2b,s_VERDANA8_fnt_00563e98,DAT_00580be8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f55,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f55,2,0x96,0,0);
  }
  value1 = UI_AddText(self,0x1f56,0x40,0x67,s_VERDANA8_fnt_00563e98,DAT_00582040);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f56,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f56,2,0x96,0,0);
  }
  value1 = UI_CreateSlider(self,0x1f57,0x4c,0x41,0x8c,s_SL02_00_spr_005642d0,0,0);
  if (value1 != 0) {
    local_10 = 0xffff;
    local_c = 0xf300;
    local_8 = 0xff;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x1f57,&local_10);
  }
  UI_AddImage(self,0x1f5a,0x5d,0x75,s_PB26_00_spr_00564610,0,0);
  value1 = UI_AddText(self,0x1f5b,0x76,0x76,s_TIMES14_fnt_00564788,&DAT_00564dcc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f5b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f5b,2,0x2d,0,3);
  }
  UI_AddImage(self,0x1f5c,0xa2,0x75,s_PB27_00_spr_005645fc,0,0);
  UI_AddImage(self,0x1f5d,0x3d,0xad,s_PB14_00_spr_005642c4,1,0);
  value1 = UI_AddText(self,0x1f5e,0x56,0xaa,s_VERDANA8_fnt_00563e98,DAT_0058225c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f5e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f5e,0,0x8c,0x1f,0);
  }
  UI_AddSprite(self,0x1f5f,0x27,0x94,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x1f60,0x4b,0x47,s_VERDANA8_fnt_00563e98,DAT_00582e68);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f60,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f60,2,0x84,0,3);
  }
  return self;
}
