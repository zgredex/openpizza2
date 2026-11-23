// SubMenu_BuildGuardHiring: ported from Pizza Connection 2 at 0x453760.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x453760
#include "pc2_port.h"


void * __cdecl SubMenu_BuildGuardHiring(int *arg1)

{
  int value1;
  void *self;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
                    /* Builds the guard hiring page. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004bd4d0);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  value1 = UI_AddText(self,0x479,0x2a,5,s_TIMESFONT_fnt_00563ea8,DAT_00582ebc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x479,0);
    Window_GadgetNotify_Text_SetLayout(self,0x479,2,0xbe,0,0);
  }
  UI_AddImage(self,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  UI_AddSprite(self,0x1f46,0x27,0xb6,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x1f4a,0x2f,0x82,s_VERDANA10_fnt_00563e64,DAT_005825f4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f4a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f4a,0,0x46,0,0);
  }
  value1 = UI_AddTextButton(self,0x1f4d,0x8e,0x112,s_VERDANA8_fnt_00563e98,DAT_0058229c,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x1f4d,0,0,0);
    Gadget_SetButtonTextLayout(self,0x1f4d,2,0x54,0,0,0xfffe);
  }
  value1 = UI_AddText(self,0x1f4e,0x4e,0x33,s_VEDANA11_fnt_00564090,DAT_00582ebc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f4e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f4e,2,0x78,0,0);
  }
  value1 = UI_CreateSlider(self,0x1f4f,0x3e,0x69,0xa0,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xf700;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x1f4f,&local_10);
  }
  value1 = UI_AddText(self,0x1f50,0x34,0x56,s_VERDANA8_fnt_00563e98,DAT_00582b0c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f50,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f50,2,0xaa,0,0);
  }
  UI_AddSprite(self,0x1f51,0x27,0x79,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x1f52,0x2f,0x95,s_VERDANA10_fnt_00563e64,DAT_00582608);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f52,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f52,0,0xb4,0x23,0);
  }
  value1 = UI_AddText(self,0x1f54,0xb5,0x167,s_VERDANA8_fnt_00563e98,&DAT_005644f4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f54,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f54,2,0x2d,0,0);
  }
  UI_AddSprite(self,0x1f57,0x27,0x12a,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x1f58,0x33,0xe9,s_VERDANA8_fnt_00563e98,DAT_00582750);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f58,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f58,0,100,0,0);
  }
  value1 = UI_AddText(self,0x1f59,0x83,0xe9,s_VERDANA8_fnt_00563e98,&DAT_005650ac);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f59,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f59,1,100,0,0);
  }
  value1 = UI_AddText(self,0x1f67,0x74,0x168,s_VERDANA8_fnt_00563e98,&DAT_00564508);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f67,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f67,2,0x2d,0,0);
  }
  value1 = UI_AddText(self,0x1f68,0x36,0x168,s_VERDANA8_fnt_00563e98,&DAT_00564538);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f68,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f68,2,0x2d,0,0);
  }
  value1 = UI_AddText(self,0x1f73,0x33,0xcd,s_VERDANA8_fnt_00563e98,DAT_005828f8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f73,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f73,0,100,0,0);
  }
  value1 = UI_AddText(self,0x1f74,0x83,0xcd,s_VERDANA8_fnt_00563e98,s__2000__00565158);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f74,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f74,1,100,0,0);
  }
  value1 = UI_AddText(self,0x1f75,0x33,0x134,s_VERDANA8_fnt_00563e98,DAT_00580fec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f75,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f75,0,0x82,0,0);
  }
  value1 = UI_AddText(self,0x1f76,0x83,0x135,s_VERDANA8_fnt_00563e98,s__Stufe_1_0056452c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f76,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f76,1,100,0,0);
  }
  value1 = UI_AddText(self,0x1f77,0x33,0xdb,s_VERDANA8_fnt_00563e98,DAT_005829f8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f77,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f77,0,100,0,0);
  }
  value1 = UI_AddText(self,0x1f78,0x83,0xdb,s_VERDANA8_fnt_00563e98,s__100_000__00565098);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f78,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f78,1,100,0,0);
  }
  value1 = UI_AddText(self,0x1f79,0x33,0xc0,s_VERDANA8_fnt_00563e98,DAT_00582574);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f79,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f79,0,0x82,0,0);
  }
  value1 = UI_AddText(self,0x1f7a,0x83,0xc0,s_VERDANA8_fnt_00563e98,&DAT_00565154);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f7a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f7a,1,100,0,0);
  }
  value1 = UI_AddText(self,0x1f7b,0x33,0x103,s_VERDANA8_fnt_00563e98,DAT_00582db0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f7b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f7b,0,0xa0,0,0);
  }
  value1 = UI_AddText(self,0x1f7c,0x83,0x103,s_VERDANA8_fnt_00563e98,&DAT_005650bc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f7c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f7c,1,100,0,0);
  }
  UI_AddImage(self,0x1f7d,0x4c,0x31,s_PB22_00_spr_00564174,0,0);
  UI_AddImage(self,0x1f7e,0xaf,0x31,s_PB24_00_spr_00564144,0,0);
  UI_AddSprite(self,0x1f7f,0x80,0x14f,&DAT_0056450c);
  UI_AddSprite(self,0x1f80,0x42,0x14f,s_SCHLAGKRAFT_spr_0056451c);
  UI_AddSprite(self,0x1f81,0xc1,0x14f,s_PANZERUNG_spr_005644f8);
  UI_AddSprite(self,0x1f82,0x2b,0x2c,s_WACHE_spr_00566664);
  return self;
}
