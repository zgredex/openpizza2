// GraphicsOptionsPage_Create: ported from Pizza Connection 2 at 0x425f30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x425f30
#include "pc2_port.h"


void * __cdecl GraphicsOptionsPage_Create(int *arg1)

{
  int value1;
  void *self;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
                    /* Creates the graphics settings page. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004a0840);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  value1 = UI_AddText(self,0x44f,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00581c1c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x44f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x44f,2,0xbe,0,0);
  }
  UI_AddImage(self,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  UI_AddSprite(self,0x1f50,0x27,0x10a,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddTextButton(self,0x1f51,0x30,0x15b,s_VERDANA8_fnt_00563e98,DAT_00582748,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x1f51,0,0,0);
    Gadget_SetButtonTextLayout(self,0x1f51,2,0xb4,0,0,0xfffe);
  }
  UI_CreateBitmapGadget(self,0x1f52,0x39,0x3a,0xaa,0xaa,0x10);
  value1 = UI_CreateSlider(self,0x1f53,0x51,0xf3,0x8c,s_SL02_00_spr_005642d0,0,0);
  if (value1 != 0) {
    local_10 = 0xffff;
    local_c = 0xf300;
    local_8 = 0xff;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x1f53,&local_10);
  }
  value1 = UI_AddText(self,0x1f54,0x33,0x2a,s_VERDANA8_fnt_00563e98,DAT_00582ac4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f54,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f54,2,0xb4,0,0);
  }
  value1 = UI_AddText(self,0x1f5d,0x44,0x118,s_VERDANA8_fnt_00563e98,DAT_00581028);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f5d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f5d,2,0x96,0,0);
  }
  UI_AddSprite(self,0x1f5f,0x27,0x14c,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x1f60,0x45,0x137,s_VERDANA8_fnt_00563e98,s_vordammt_hoch_00564d38);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f60,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f60,2,0x96,0,0);
  }
  value1 = UI_CreateSlider(self,0x1f5e,0x4b,0x12f,0x8c,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xf300;
    local_c = 0xffff;
    local_8 = 0xff;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x1f5e,&local_10);
  }
  return self;
}
