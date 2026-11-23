// Screen_MainMenu: ported from Pizza Connection 2 at 0x476920.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x476920
#include "pc2_port.h"


void * __cdecl Screen_MainMenu(int *arg1)

{
  int value1;
  void *self;
  
  value1 = Window_CreatePictureWindow(DAT_0057c5e0,s_Pe_Startscreen_TGA_00567574,&LAB_004ceb80);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  value1 = UI_AddTextButton(self,0x3ee,0x253,6,s_TIMESFONT_fnt_00563ea8,DAT_00581740,0,
                           s_TEXTPBTRANSPGELB_00_spr_00567208);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x3ee,0,0,0);
    Gadget_SetButtonTextLayout(self,0x3ee,2,0xcc,0,0,0);
  }
  value1 = UI_AddTextButton(self,0x3ef,0x253,0x30,s_TIMESFONT_fnt_00563ea8,DAT_00582468,0,
                           s_TEXTPBTRANSPGELB_00_spr_00567208);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x3ef,0,0,0);
    Gadget_SetButtonTextLayout(self,0x3ef,2,0xcc,0,0,0);
  }
  value1 = UI_AddTextButton(self,0x3f0,0x253,0x5b,s_TIMESFONT_fnt_00563ea8,DAT_00582d5c,0,
                           s_TEXTPBTRANSPGELB_00_spr_00567208);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x3f0,0,0,0);
    Gadget_SetButtonTextLayout(self,0x3f0,2,0xcc,0,0,0);
  }
  value1 = UI_AddTextButton(self,0x3f1,0x253,0x85,s_TIMESFONT_fnt_00563ea8,DAT_00581878,0,
                           s_TEXTPBTRANSPGELB_00_spr_00567208);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x3f1,0,0,0);
    Gadget_SetButtonTextLayout(self,0x3f1,2,0xcc,0,0,0);
  }
  value1 = UI_AddTextButton(self,0x3f6,0x253,0x230,s_TIMESFONT_fnt_00563ea8,DAT_00581c70,0,
                           s_TEXTPBTRANSPGELB_00_spr_00567208);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x3f6,0,0,0);
    Gadget_SetButtonTextLayout(self,0x3f6,2,0xcc,0,0,0);
  }
  value1 = UI_AddTextButton(self,0x3f7,0x253,0xaf,s_TIMESFONT_fnt_00563ea8,DAT_00581904,0,
                           s_TEXTPBTRANSPGELB_00_spr_00567208);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x3f7,0,0,0);
    Gadget_SetButtonTextLayout(self,0x3f7,2,0xcc,0,0,0);
  }
  return self;
}
