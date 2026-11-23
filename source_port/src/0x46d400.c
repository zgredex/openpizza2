// MissionOfferDialog_Create: ported from Pizza Connection 2 at 0x46d400.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x46d400
#include "pc2_port.h"


void * __cdecl MissionOfferDialog_Create(int *arg1)

{
  int value1;
  void *self;
  
                    /* Creates the mission-offer dialog. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004c6cf0);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(self,0x429,0x27,0x14c,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x42d,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00582d44);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x42d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x42d,2,0xbe,0,0);
  }
  value1 = UI_AddText(self,0x42f,0x32,0x26,s_VERDANA7_fnt_00563ec8,&DAT_00566fe4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x42f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x42f,0,0xb4,100,3);
  }
  value1 = UI_AddTextButton(self,0x430,0x30,0x15b,s_VERDANA8_fnt_00563e98,DAT_005821a0,0,
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
  value1 = UI_AddText(self,0x432,0x32,0x8d,s_VERDANA7_fnt_00563ec8,DAT_00580ae4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x432,0xce0000);
    Window_GadgetNotify_Text_SetLayout(self,0x432,0,0xb4,0xffff,3);
  }
  value1 = UI_AddText(self,0x433,0x32,0xcd,s_VERDANA7_fnt_00563ec8,DAT_00581b94);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x433,0xce0000);
    Window_GadgetNotify_Text_SetLayout(self,0x433,0,0xb4,0xffff,3);
  }
  value1 = UI_AddText(self,0x434,0x32,0x10d,s_VERDANA7_fnt_00563ec8,DAT_00581508);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x434,0xce0000);
    Window_GadgetNotify_Text_SetLayout(self,0x434,0,0xb4,0xffff,3);
  }
  value1 = UI_AddText(self,0x435,0x32,0x13a,s_VERDANA7_fnt_00563ec8,DAT_0058189c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x435,0);
    Window_GadgetNotify_Text_SetLayout(self,0x435,0,0xb4,0xffff,3);
  }
  value1 = UI_AddText(self,0x436,0x3e,0x9a,s_VERDANA7_fnt_00563ec8,&DAT_00566f64);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x436,0);
    Window_GadgetNotify_Text_SetLayout(self,0x436,0,0xaa,0x32,3);
  }
  value1 = UI_AddText(self,0x437,0x3e,0xda,s_VERDANA7_fnt_00563ec8,&DAT_00566ef8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x437,0);
    Window_GadgetNotify_Text_SetLayout(self,0x437,0,0xaa,0x32,3);
  }
  value1 = UI_AddText(self,0x438,0x3e,0x119,s_VERDANA7_fnt_00563ec8,DAT_00582aa0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x438,0);
    Window_GadgetNotify_Text_SetLayout(self,0x438,0,0xaa,0xffff,3);
  }
  value1 = UI_AddText(self,0x439,0x3d,0x126,s_VERDANA7_fnt_00563ec8,
                     s__1__Quartal_2001_16_00_Uhr_00566edc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x439,0xff);
    Window_GadgetNotify_Text_SetLayout(self,0x439,1,0xaa,0xffff,3);
  }
  return self;
}
