// AI_DebugStatusWindow_Create: ported from Pizza Connection 2 at 0x46bfa0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x46bfa0
#include "pc2_port.h"


void * __cdecl AI_DebugStatusWindow_Create(int *arg1)

{
  int value1;
  void *self;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
                    /* Creates the debug AI status window. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004c6000);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(self,0x429,0x27,0x14c,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x449,0x2c,5,s_TIMESFONT_fnt_00563ea8,s_KI_Status_00566d10);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x449,0);
    Window_GadgetNotify_Text_SetLayout(self,0x449,2,0xbe,0,0);
  }
  value1 = UI_AddText(self,0x1f4c,0x45,0x4f,s_VERDANA8_fnt_00563e98,s_dffkmls_00566d08);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f4c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f4c,2,0x87,0,0);
  }
  UI_AddSprite(self,0x1f4d,0x70,0x2b,s_LOGORAHMEN_00_spr_005650f8);
  UI_AddSprite(self,0x1f4f,0x72,0x2d,s_PLAYLOG_8_01_02_spr_00564744);
  UI_AddImage(self,0x1f50,0x54,0x2f,s_PB22_00_spr_00564174,0,0);
  UI_AddImage(self,0x1f51,0xa0,0x2f,s_PB24_00_spr_00564144,0,0);
  value1 = UI_AddText(self,0x1f52,0x5d,0x8c,s_VERDANA8_fnt_00563e98,s_ki_active_00566cfc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f52,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f52,0,0,0xffff,0);
  }
  UI_AddImage(self,0x1f53,0x41,0x87,s_PB14_00_spr_005642c4,1,0);
  value1 = UI_AddText(self,0x1f54,0x3f,0xdf,s_VERDANA8_fnt_00563e98,s_aggressive_00566cf0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f54,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f54,2,0x96,0,0);
  }
  value1 = UI_CreateSlider(self,0x1f55,0x4d,0xf3,0x8c,s_SL02_00_spr_005642d0,0,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x1f55,&local_10);
  }
  value1 = UI_AddInputField(self,0x1f56,99,0xc1,s_VERDANA8_fnt_00563e98,s_1000000_00566ce8,0x4b);
  if (value1 != 0) {
    Window_GadgetNotify_Input_SetNormalColor(self,0x1f56,0x505050);
    Window_GadgetNotify_Input_SetEditingColor(self,0x1f56,0xff);
    Window_GadgetNotify_Input_SetFocusColor(self,0x1f56,0xffff);
    Window_GadgetNotify_Input_SetSelectionColor(self,0x1f56,0x6d0000);
  }
  UI_AddImage(self,0x1f57,0x44,0xbb,s_PB22_00_spr_00564174,0,0);
  UI_AddImage(self,0x1f58,0xae,0xbc,s_PB24_00_spr_00564144,0,0);
  value1 = UI_AddText(self,0x1f59,0x45,0xaf,s_VERDANA8_fnt_00563e98,s_money_00566ce0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f59,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f59,0,0xffff,0xffff,0);
  }
  value1 = UI_AddTextButton(self,0x1f5a,0x34,0x131,s_VERDANA8_fnt_00563e98,&DAT_00566cd8,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x1f5a,0,0,0);
    Gadget_SetButtonTextLayout(self,0x1f5a,2,0x54,0,0,0xfffe);
  }
  value1 = UI_AddTextButton(self,0x1f5b,0x91,0x132,s_VERDANA8_fnt_00563e98,s_take_over_00566ccc,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x1f5b,0,0,0);
    Gadget_SetButtonTextLayout(self,0x1f5b,2,0x54,0,0,0xfffe);
  }
  value1 = UI_AddText(self,0x1f5c,0x3c,0x62,s_VERDANA8_fnt_00563e98,s_player_number_00566cbc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f5c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f5c,0,0,0xffff,0);
  }
  value1 = UI_AddText(self,0x1f5d,0x3c,0x72,s_VERDANA8_fnt_00563e98,s_company_number_00566cac);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f5d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f5d,0,0,0xffff,0);
  }
  value1 = UI_AddText(self,0x1f5e,0xb3,99,s_VERDANA8_fnt_00563e98,&DAT_00564214);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f5e,0xff);
    Window_GadgetNotify_Text_SetLayout(self,0x1f5e,0,0x14,0xffff,0);
  }
  value1 = UI_AddText(self,0x1f5f,0xb3,0x72,s_VERDANA8_fnt_00563e98,&DAT_00564214);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f5f,0xff);
    Window_GadgetNotify_Text_SetLayout(self,0x1f5f,0,0x14,0xffff,0);
  }
  value1 = UI_AddTextButton(self,0x1f60,99,0x15a,s_VERDANA8_fnt_00563e98,s_close_00566ca4,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x1f60,0,0,0);
    Gadget_SetButtonTextLayout(self,0x1f60,2,0x54,0,0,0xfffe);
  }
  value1 = UI_AddText(self,0x1f61,0x42,0x104,s_VERDANA8_fnt_00563e98,s_rage_level_00566c98);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f61,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f61,2,0x96,0,0);
  }
  value1 = UI_CreateSlider(self,0x1f62,0x50,0x118,0x8c,s_SL02_00_spr_005642d0,0,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x1f62,&local_10);
  }
  return self;
}
