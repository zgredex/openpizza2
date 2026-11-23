// PestMenu_CreateWindow: ported from Pizza Connection 2 at 0x469e30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x469e30
#include "pc2_port.h"


void * __cdecl PestMenu_CreateWindow(int *arg1)

{
  int value1;
  void *self;
  
                    /* Creates the pest-control submenu window. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004c5340);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(self,0x409,0x28,0x5d,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x44f,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_005827cc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x44f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x44f,2,0xbe,0,0);
  }
  value1 = UI_AddText(self,0x458,0x42,0xc1,s_VERDANA10_fnt_00563e64,DAT_005829b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x458,0);
    Window_GadgetNotify_Text_SetLayout(self,0x458,2,0x96,0xffff,0);
  }
  UI_AddImage(self,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  value1 = UI_AddText(self,0x1f43,0x34,0x25,s_VERDANA8_fnt_00563e98,DAT_005826b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f43,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f43,0,0xb4,0x37,0);
  }
  value1 = UI_AddText(self,0x1f4e,0x55,0xfd,s_VERDANA8_fnt_00563e98,DAT_005814d8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f4e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f4e,0,0x3c,0,0);
  }
  value1 = UI_AddText(self,0x1f4f,0x6c,0xfd,s_VERDANA8_fnt_00563e98,s__10000__00566300);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f4f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f4f,1,0x5a,0,0);
  }
  UI_AddSprite(self,0x1f50,0x28,0x12a,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddTextButton(self,0x1f51,0x61,0x110,s_VERDANA8_fnt_00563e98,s__Anfordern_00566b74,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x1f51,0,0,0);
    Gadget_SetButtonTextLayout(self,0x1f51,2,0x54,0,0,0xfffe);
  }
  UI_AddSprite(self,0x1f52,0xa5,0x14c,s_KAKERLAKE_spr_00566b64);
  UI_AddSprite(self,0x1f53,0x2b,0x14d,s_RATTE_spr_00566b58);
  UI_AddSprite(self,0x1f54,0x69,0x14b,s_WURM_spr_00566b4c);
  value1 = UI_AddText(self,0x1f55,0x48,0x167,s_VERDANA8_fnt_00563e98,&DAT_00566b44);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f55,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f55,1,0x23,0,0);
  }
  value1 = UI_AddText(self,0x1f5c,0x82,0x167,s_VERDANA8_fnt_00563e98,&DAT_00566b44);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f5c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f5c,1,0x23,0,0);
  }
  value1 = UI_AddText(self,0x1f5d,0xc2,0x167,s_VERDANA8_fnt_00563e98,&DAT_00566b44);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f5d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f5d,1,0x23,0,0);
  }
  UI_AddSprite(self,0x1f68,0x28,0xb7,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x1f72,0x42,0xdd,s_VERDANA8_fnt_00563e98,DAT_00582f90);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f72,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f72,2,0x96,0x23,0);
  }
  value1 = UI_AddText(self,0x1f73,0x42,0x66,s_VERDANA10_fnt_00563e64,DAT_005829b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f73,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f73,2,0x96,0xffff,0);
  }
  value1 = UI_AddText(self,0x1f74,0x55,0x8c,s_VERDANA8_fnt_00563e98,DAT_005814d8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f74,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f74,0,0x3c,0,0);
  }
  value1 = UI_AddText(self,0x1f75,0x6c,0x8c,s_VERDANA8_fnt_00563e98,s__1000__00566320);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f75,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f75,1,0x5a,0,0);
  }
  value1 = UI_AddTextButton(self,0x1f76,0x61,0x9e,s_VERDANA8_fnt_00563e98,s__Anfordern_00566b74,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x1f76,0,0,0);
    Gadget_SetButtonTextLayout(self,0x1f76,2,0x54,0,0,0xfffe);
  }
  value1 = UI_AddText(self,0x1f77,0x42,0x7c,s_VERDANA8_fnt_00563e98,DAT_00582dec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f77,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f77,2,0x96,0xffff,0);
  }
  value1 = UI_AddText(self,0x1f78,0x31,0x134,s_VERDANA8_fnt_00563e98,DAT_00580ef0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f78,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f78,2,0xb4,0x1e,0);
  }
  return self;
}
