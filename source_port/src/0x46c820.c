// RequestDialog_Create: ported from Pizza Connection 2 at 0x46c820.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x46c820
#include "pc2_port.h"


void * __cdecl RequestDialog_Create(int *arg1)

{
  int value1;
  void *self;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
                    /* Creates the amount-request dialog. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004c6640);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(self,0x42d,0x39,0xde,s_RAHMEN01_spr_00566790);
  UI_AddSprite(self,0x429,0x27,0x14c,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x42f,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_0058159c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x42f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x42f,2,0xbe,0,0);
  }
  value1 = UI_AddText(self,0x431,0x32,0x26,s_VERDANA10_fnt_00563e64,
                     s__Geben_Sie_den_Betrag_ein__00566da8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x431,0);
    Window_GadgetNotify_Text_SetLayout(self,0x431,2,0xb4,0x7d,2);
  }
  value1 = UI_CreateSlider(self,0x42e,0x42,0xbf,0x96,s_SLHOR01_00_spr_00564660,0,0);
  if (value1 != 0) {
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x42e,&local_10);
  }
  value1 = UI_AddTextButton(self,0x434,0x30,0x15b,s_VERDANA8_fnt_00563e98,DAT_00582ae4,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x434,0,0,0);
    Gadget_SetButtonTextLayout(self,0x434,2,0x54,0,0,0xfffe);
  }
  value1 = UI_AddTextButton(self,0x435,0x8e,0x15b,s_VERDANA8_fnt_00563e98,DAT_00580b3c,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x435,0,0,0);
    Gadget_SetButtonTextLayout(self,0x435,2,0x54,0,0,0xfffe);
  }
  value1 = UI_AddInputField(self,0x436,0x3d,0xe8,s_VERDANA10_fnt_00563e64,s__hgjghjghjghjghj_00566d94
                           ,0xa0);
  if (value1 != 0) {
    Window_GadgetNotify_Input_SetNormalColor(self,0x436,0);
    Window_GadgetNotify_Input_SetEditingColor(self,0x436,0);
    Window_GadgetNotify_Input_SetFocusColor(self,0x436,0x868686);
    Window_GadgetNotify_Input_SetSelectionColor(self,0x436,0xff);
  }
  value1 = UI_AddInputField(self,0x437,0x5b,0xe9,s_VERDANA10_fnt_00563e64,s__hgjghjghjghjghj_00566d94
                           ,100);
  if (value1 != 0) {
    Window_GadgetNotify_Input_SetNormalColor(self,0x437,0);
    Window_GadgetNotify_Input_SetEditingColor(self,0x437,0);
    Window_GadgetNotify_Input_SetFocusColor(self,0x437,0x868686);
    Window_GadgetNotify_Input_SetSelectionColor(self,0x437,0xff);
  }
  return self;
}
