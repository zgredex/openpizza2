// HelpTopicDialog_Create: ported from Pizza Connection 2 at 0x46cad0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x46cad0
#include "pc2_port.h"


void * __cdecl HelpTopicDialog_Create(int *arg1)

{
  int value1;
  void *self;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
                    /* Creates the help-topic dialog. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004c6730);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(self,0x429,0x27,0x14c,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x42b,0x2b,5,s_TIMESFONT_fnt_00563ea8,s__Hilfethema_00566e24);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x42b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x42b,2,0xbe,0,0);
  }
  value1 = UI_AddText(self,0x42c,0x32,0x26,s_VERDANA7_fnt_00563ec8,
                     s__Hilfetext__26_Zeichen_je_Zeile__00566df8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x42c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x42c,0,0xa0,0x122,3);
  }
  value1 = UI_AddTextButton(self,0x42e,0x8e,0x15b,s_VERDANA8_fnt_00563e98,DAT_00581adc,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x42e,0,0,0);
    Gadget_SetButtonTextLayout(self,0x42e,2,0x54,0,0,0xfffe);
  }
  UI_AddImage(self,0x1f41,0xb,-1,s_HILFEBUTTONOFFSNIP_00_spr_00566ddc,1,0);
  value1 = UI_CreateSlider(self,0x1f42,0xdc,0x40,0x109,s_SL01_00_spr_0056448c,0,1);
  if (value1 != 0) {
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x1f42,&local_10);
  }
  return self;
}
