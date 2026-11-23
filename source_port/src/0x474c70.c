// LoadingScreen_Create: ported from Pizza Connection 2 at 0x474c70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x474c70
#include "pc2_port.h"


void * __cdecl LoadingScreen_Create(int *arg1)

{
  int value1;
  void *self;
  
                    /* Creates the modal loading screen. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0xbb,0xf8,s_PE_RQ_LOADING_spr_00566d34,&LAB_004cda70);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  value1 = UI_AddText(self,0x3e9,0x10,0xf,s_VERDANA8_fnt_00563e98,DAT_005828f0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3e9,0);
    Window_GadgetNotify_Text_SetLayout(self,0x3e9,2,400,0x31,2);
  }
  value1 = UI_AddTextButton(self,0x3f8,0x90,0x46,s_VERDANA8_fnt_00563e98,s__textbutton_0056744c,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x3f8,0,0,0);
    Gadget_SetButtonTextLayout(self,0x3f8,2,0x8c,0,0,0xfffe);
  }
  value1 = UI_AddTextButton(self,0x3f9,0x3d,0x46,s_VERDANA8_fnt_00563e98,s__textbutton_0056744c,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x3f9,0,0,0);
    Gadget_SetButtonTextLayout(self,0x3f9,2,0x8c,0,0,0xfffe);
  }
  value1 = UI_AddTextButton(self,0x3fa,0xdf,0x46,s_VERDANA8_fnt_00563e98,s__textbutton_0056744c,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x3fa,0,0,0);
    Gadget_SetButtonTextLayout(self,0x3fa,2,0x8c,0,0,0xfffe);
  }
  return self;
}
