// SubMenu_BuildConstructionInfo: ported from Pizza Connection 2 at 0x458f50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x458f50
#include "pc2_port.h"


void * __cdecl SubMenu_BuildConstructionInfo(int *arg1)

{
  int value1;
  void *self;
  
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004c0750);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(self,0x408,0x27,0x129,s_TRENNZEILE_spr_00563eb8);
  UI_AddSprite(self,0x409,0x27,0xf2,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x40a,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00582bbc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x40a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x40a,2,0xbe,0,0);
  }
  value1 = UI_AddText(self,0x40b,0x2f,0xae,s_VERDANA10_fnt_00563e64,DAT_00582c38);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x40b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x40b,0,0x78,0,0);
  }
  value1 = UI_AddText(self,0x40c,0x2f,0xd0,s_VERDANA10_fnt_00563e64,DAT_005819e4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x40c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x40c,0,100,0,0);
  }
  value1 = UI_AddText(self,0x40f,0x2f,0xfe,s_VERDANA10_fnt_00563e64,DAT_00581fc0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x40f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x40f,0,0x6e,0,0);
  }
  value1 = UI_AddText(self,0x410,0x2f,0x114,s_VERDANA10_fnt_00563e64,DAT_00582400);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x410,0);
    Window_GadgetNotify_Text_SetLayout(self,0x410,0,0x5a,0,0);
  }
  value1 = UI_AddText(self,0x418,0xa5,0x114,s_VERDANA10_fnt_00563e64,&DAT_00566814);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x418,0);
    Window_GadgetNotify_Text_SetLayout(self,0x418,1,0x3c,0,0);
  }
  value1 = UI_AddText(self,0x419,0x92,0xfe,s_VERDANA10_fnt_00563e64,s__4565__0056680c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x419,0);
    Window_GadgetNotify_Text_SetLayout(self,0x419,1,0x50,0,0);
  }
  value1 = UI_AddText(self,0x41a,0x96,0xae,s_VERDANA10_fnt_00563e64,s__20_3_99_00566800);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x41a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x41a,1,0x50,0,0);
  }
  value1 = UI_AddText(self,0x41b,0x71,0xd0,s_VERDANA10_fnt_00563e64,s__Pizza_Pasta_005667f0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x41b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x41b,2,0x78,0,0);
  }
  UI_AddImage(self,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  value1 = UI_AddText(self,0x1f41,0x2c,0x12f,s_VERDANA7_fnt_00563ec8,DAT_00581860);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f41,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f41,2,0xbe,0,0);
  }
  UI_AddSprite(self,0x1f42,0x2f,0x13a,s_TAB01xxx_spr_00565234);
  UI_AddSprite(self,0x1f54,0x5e,0x2f,s_MG_H_PIZZ_B7_spr_00563e38);
  value1 = UI_AddText(self,0x1f55,0x2f,0x7f,s_VERDANA10_fnt_00563e64,
                     s__Hauptquartier_Stufe_5_00565bac);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f55,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f55,2,0xb4,0x28,0);
  }
  return self;
}
