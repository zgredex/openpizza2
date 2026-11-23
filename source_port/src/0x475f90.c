// MissionFailedScreen_Create: ported from Pizza Connection 2 at 0x475f90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x475f90
#include "pc2_port.h"


void * __cdecl MissionFailedScreen_Create(int *arg1)

{
  int value1;
  void *self;
  
                    /* Creates the mission-failed screen. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0,0,s_BG004_spr_00567520,&LAB_004ce770);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  value1 = UI_AddTextButton(self,1000,0x73,0x212,s_TIMESFONT_fnt_00563ea8,DAT_00582748,0,
                           s_TEXTPBTRANSPGELB_00_spr_00567208);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,1000,0,0,0);
    Gadget_SetButtonTextLayout(self,1000,2,0xcc,0,0,0);
  }
  value1 = UI_AddTextButton(self,0x3e9,0x1df,0x212,s_TIMESFONT_fnt_00563ea8,DAT_00581b24,0,
                           s_TEXTPBTRANSPGELB_00_spr_00567208);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x3e9,0,0,0);
    Gadget_SetButtonTextLayout(self,0x3e9,2,0xcc,0,0,0);
  }
  value1 = UI_AddText(self,0x3ec,0,0x14,s_VERDANA16_fnt_00565788,DAT_00582664);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3ec,0);
    Window_GadgetNotify_Text_SetLayout(self,0x3ec,2,800,0xffff,0);
  }
  value1 = UI_AddText(self,0x3ed,0,0x37,s_TIMES14_fnt_00564788,DAT_00581d28);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3ed,0);
    Window_GadgetNotify_Text_SetLayout(self,0x3ed,2,800,0xffff,0);
  }
  return self;
}
