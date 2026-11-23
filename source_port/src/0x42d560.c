// Screen_BranchList: ported from Pizza Connection 2 at 0x42d560.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x42d560
#include "pc2_port.h"


void * __cdecl Screen_BranchList(int *arg1)

{
  int value1;
  void *self;
  
                    /* Builds the branch/warehouse list screen. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004a7510);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(self,0x408,0x27,0x129,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x441,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00581270);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x441,0);
    Window_GadgetNotify_Text_SetLayout(self,0x441,2,0xbe,0,0);
  }
  value1 = UI_AddTextButton(self,0x44f,0x8e,0x112,s_VERDANA8_fnt_00563e98,DAT_0058292c,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x44f,0,0,0);
    Gadget_SetButtonTextLayout(self,0x44f,2,0x54,0,0,0xfffe);
  }
  UI_AddImage(self,0x4ef,99,0x7e,s_SKFILIALE_00_spr_005654fc,1,0);
  UI_AddImage(self,0x4f0,0x8d,0x7e,s_SKLAGER_00_spr_005654ec,1,0);
  UI_AddSprite(self,0x4f3,0x27,0xf2,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x4f4,0x31,0x7e,s_VERDANA8_fnt_00563e98,DAT_005829e4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4f4,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4f4,0,0x32,0,0);
  }
  value1 = UI_AddText(self,0x4f5,0xb4,0x7e,s_VERDANA8_fnt_00563e98,DAT_0058106c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4f5,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4f5,0,0x32,0,0);
  }
  value1 = UI_AddText(self,0x4f6,0x31,0x95,s_VERDANA8_fnt_00563e98,s__Mittel_005654e4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4f6,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4f6,0,0x32,0,0);
  }
  value1 = UI_AddText(self,0x4f8,0x31,0xfd,s_VERDANA8_fnt_00563e98,DAT_00582b30);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4f8,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4f8,0,0x8c,0,0);
  }
  value1 = UI_AddText(self,0x4f9,0xa7,0xfd,s_VERDANA8_fnt_00563e98,s__34555__005654dc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4f9,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4f9,1,0x41,0,0);
  }
  value1 = UI_AddText(self,0x4fa,0x4e,0x112,s_TIMESFONT_fnt_00563ea8,&DAT_00564774);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4fa,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4fa,2,0x19,0,0);
  }
  UI_AddImage(self,0x4fb,0x32,0x111,s_PB26_00_spr_00564610,0,0);
  UI_AddImage(self,0x4fc,0x69,0x111,s_PB27_00_spr_005645fc,0,0);
  UI_AddImage(self,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  value1 = UI_AddText(self,0x1f41,0xb4,0x95,s_VERDANA8_fnt_00563e98,s__Mittel_005654e4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f41,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f41,0,0x32,0,0);
  }
  value1 = UI_AddText(self,0x1f42,0x2c,0x12f,s_VERDANA7_fnt_00563ec8,DAT_00581898);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f42,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f42,2,0xbe,0,0);
  }
  UI_AddSprite(self,0x1f43,0x2f,0x13a,s_TAB01xxx_spr_00565234);
  value1 = UI_AddText(self,0x1f4d,0x33,0xa9,s_VERDANA7_fnt_00563ec8,DAT_00580ff4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f4d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f4d,0,0xb4,0x4b,0);
  }
  UI_AddSprite(self,0x1f57,0x5d,0x2b,s_MG_H_LAGER_C7_spr_005654c8);
  return self;
}
