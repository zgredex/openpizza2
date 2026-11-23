// Dialog_Confirm: ported from Pizza Connection 2 at 0x46c690.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x46c690
#include "pc2_port.h"


void * __cdecl Dialog_Confirm(int *arg1)

{
  int value1;
  void *self;
  
                    /* Builds the generic confirmation dialog. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004c6420);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(self,0x429,0x27,0x14c,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x42d,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00582748);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x42d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x42d,2,0xbe,0,0);
  }
  value1 = UI_AddText(self,0x42f,0x32,0x26,s_VEDANA12_fnt_00566d60,s__Wollen__00566d70);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x42f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x42f,2,0xb4,0x122,2);
  }
  value1 = UI_AddTextButton(self,0x430,0x30,0x15b,s_VERDANA8_fnt_00563e98,DAT_00582ae4,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x430,0,0,0);
    Gadget_SetButtonTextLayout(self,0x430,2,0x54,0,0,0xfffe);
  }
  value1 = UI_AddTextButton(self,0x431,0x8e,0x15b,s_VERDANA8_fnt_00563e98,DAT_00580b3c,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x431,0,0,0);
    Gadget_SetButtonTextLayout(self,0x431,2,0x54,0,0,0xfffe);
  }
  return self;
}
