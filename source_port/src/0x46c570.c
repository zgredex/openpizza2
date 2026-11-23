// Dialog_Loading: ported from Pizza Connection 2 at 0x46c570.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x46c570
#include "pc2_port.h"


void * __cdecl Dialog_Loading(int *arg1)

{
  int value1;
  void *self;
  
                    /* Builds the generic loading/progress dialog. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0xbb,0xf8,s_PE_RQ_LOADING_spr_00566d34,&LAB_004c6390);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  value1 = UI_AddText(self,0x3e9,0xe,0x1b,s_VERDANA16_fnt_00565788,DAT_0058203c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3e9,0);
    Window_GadgetNotify_Text_SetLayout(self,0x3e9,2,400,0,0);
  }
  value1 = UI_AddTextButton(self,0x3f8,0xac,0x44,s_VERDANA8_fnt_00563e98,DAT_005827ac,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x3f8,0,0,0);
    Gadget_SetButtonTextLayout(self,0x3f8,2,0x54,0,0,0xfffe);
  }
  value1 = UI_AddText(self,0x3f9,0x10,0xd,s_VERDANA10_fnt_00563e64,DAT_00582140);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3f9,0);
    Window_GadgetNotify_Text_SetLayout(self,0x3f9,2,400,0x36,2);
  }
  return self;
}
