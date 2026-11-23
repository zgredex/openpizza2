// Screen_MissionGoals: ported from Pizza Connection 2 at 0x42d990.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x42d990
#include "pc2_port.h"


void * __cdecl Screen_MissionGoals(int *arg1)

{
  int value1;
  void *self;
  
                    /* Builds the mission-goals screen. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004a7f80);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  value1 = UI_AddText(self,0x429,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00580e70);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x429,0);
    Window_GadgetNotify_Text_SetLayout(self,0x429,2,0xbe,0,0);
  }
  value1 = UI_AddText(self,0x42b,0x2f,0x25,s_VERDANA7_fnt_00563ec8,&DAT_005655bc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x42b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x42b,0,0xb9,0xa0,0);
  }
  UI_AddImage(self,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  UI_AddSprite(self,0x1f41,0x27,0x14c,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddTextButton(self,0x1f42,0x30,0x15b,s_VERDANA8_fnt_00563e98,DAT_00582ef4,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x1f42,0,0,0);
    Gadget_SetButtonTextLayout(self,0x1f42,2,0xb4,0,0,0xfffe);
  }
  value1 = UI_AddText(self,0x1f43,0x2f,200,s_VERDANA7_fnt_00563ec8,DAT_00582c58);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f43,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f43,0,0xb9,0xffff,0);
  }
  value1 = UI_AddText(self,0x1f44,0x48,0xd6,s_VERDANA7_fnt_00563ec8,s__Retten_Sie_die_Welt__005655a4)
  ;
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f44,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f44,0,0xa0,0x19,0);
  }
  value1 = UI_AddText(self,0x1f45,0x48,0xf0,s_VERDANA7_fnt_00563ec8,&DAT_00565574);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f45,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f45,0,0xa0,0x19,0);
  }
  value1 = UI_AddText(self,0x1f46,0x48,0x10b,s_VERDANA7_fnt_00563ec8,
                     s__Achten_Sie_auf_eine_gesunde_Umw_0056554c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f46,0xaa00);
    Window_GadgetNotify_Text_SetLayout(self,0x1f46,0,0xa0,0x19,0);
  }
  value1 = UI_AddText(self,0x1f47,0x3b,0xd6,s_VERDANA7_fnt_00563ec8,&DAT_00565548);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f47,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f47,0,0xf,0x19,0);
  }
  value1 = UI_AddText(self,0x1f48,0x3b,0xf0,s_VERDANA7_fnt_00563ec8,&DAT_00565544);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f48,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f48,0,0xf,0x19,0);
  }
  value1 = UI_AddText(self,0x1f49,0x3b,0x10b,s_VERDANA7_fnt_00563ec8,&DAT_00565540);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f49,0xaa00);
    Window_GadgetNotify_Text_SetLayout(self,0x1f49,0,0xf,0x19,0);
  }
  value1 = UI_AddText(self,0x1f4a,0x2f,0x131,s_VERDANA7_fnt_00563ec8,DAT_00581578);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f4a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f4a,0,0xb9,0x19,0);
  }
  value1 = UI_AddText(self,0x1f4b,0x8c,0x13d,s_VERDANA7_fnt_00563ec8,s__2_Jahre_00565534);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f4b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f4b,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x1f4c,0x2f,0x125,s_VERDANA7_fnt_00563ec8,DAT_00582dac);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f4c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f4c,0,0x78,0xffff,0);
  }
  value1 = UI_AddText(self,0x1f4d,0x8c,0x125,s_VERDANA7_fnt_00563ec8,s__1000000___00565528);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f4d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f4d,1,0x5a,0xffff,0);
  }
  return self;
}
