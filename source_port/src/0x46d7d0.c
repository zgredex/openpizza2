// UI_CreateMessageBoxSubmenu: ported from Pizza Connection 2 at 0x46d7d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x46d7d0
#include "pc2_port.h"


void * __cdecl UI_CreateMessageBoxSubmenu(int *arg1)

{
  int value1;
  void *self;
  
                    /* Creates the small submenu message window and reply list. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004c6dd0);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(self,0x429,0x27,0x14c,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x42b,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00581644);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x42b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x42b,2,0xbe,0,0);
  }
  value1 = UI_AddText(self,0x42c,0x32,0x26,s_VEDANA11_fnt_00564090,s__Selbst_Schuld__00567104);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x42c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x42c,2,0xb4,0x122,2);
  }
  value1 = UI_AddTextButton(self,0x42e,0x8e,0x15b,s_VERDANA8_fnt_00563e98,DAT_00580b3c,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x42e,0,0,0);
    Gadget_SetButtonTextLayout(self,0x42e,2,0x54,0,0,0xfffe);
  }
  return self;
}
