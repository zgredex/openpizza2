// SubMenu_BuildGuardAssignment: ported from Pizza Connection 2 at 0x4556f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4556f0
#include "pc2_port.h"


void * __cdecl SubMenu_BuildGuardAssignment(int *arg1)

{
  int value1;
  void *self;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
                    /* Builds the guard assignment page. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004be980);
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
  value1 = UI_AddText(self,0x1f4a,0x2f,0x82,s_VERDANA10_fnt_00563e64,DAT_005825f4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f4a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f4a,0,0x46,0,0);
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
  value1 = UI_AddText(self,0x1f52,0x2f,0x95,s_VERDANA10_fnt_00563e64,
                     s__Filiale_Romana_bewachen_005666d8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f52,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f52,0,0xb4,0x23,0);
  }
  value1 = UI_AddText(self,0x1f54,0xb5,0x167,s_VERDANA8_fnt_00563e98,&DAT_00565088);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f54,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f54,2,0x2d,0,0);
  }
  UI_AddSprite(self,0x1f57,0x27,0x12a,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x1f67,0x74,0x168,s_VERDANA8_fnt_00563e98,&DAT_00565088);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f67,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f67,2,0x2d,0,0);
  }
  value1 = UI_AddText(self,0x1f68,0x36,0x168,s_VERDANA8_fnt_00563e98,&DAT_00565094);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f68,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f68,2,0x2d,0,0);
  }
  value1 = UI_AddText(self,0x1f77,0x2d,0xfd,s_VERDANA8_fnt_00563e98,DAT_00582758);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f77,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f77,0,0x5a,0,0);
  }
  value1 = UI_AddText(self,0x1f78,0x2d,0x116,s_VERDANA8_fnt_00563e98,s__Pizza_Tingeltangel_0056510c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f78,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f78,0,0x87,0,0);
  }
  UI_AddSprite(self,0x1f79,0xb5,0x104,s_LOGORAHMEN_00_spr_005650f8);
  UI_CreateBitmapGadget(self,0x1f7a,0xb7,0x106,0x2c,0x1d,0x10);
  UI_AddSprite(self,0x1f7c,0x27,0xf2,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x1f7d,0x33,0x134,s_VERDANA8_fnt_00563e98,DAT_00580fec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f7d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f7d,0,0x82,0,0);
  }
  value1 = UI_AddText(self,0x1f7e,0x83,0x134,s_VERDANA8_fnt_00563e98,s__Stufe_1_0056452c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f7e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f7e,1,100,0,0);
  }
  UI_AddSprite(self,0x1f7f,0x80,0x14f,&DAT_0056450c);
  UI_AddSprite(self,0x1f80,0x42,0x14f,s_SCHLAGKRAFT_spr_0056451c);
  UI_AddSprite(self,0x1f81,0xc1,0x14f,s_PANZERUNG_spr_005644f8);
  UI_AddSprite(self,0x1f82,0x2b,0x2c,s_WACHE_spr_00566664);
  UI_AddSprite(self,0x1f83,0xb7,0x106,s_PLAYLOG_8_01_02_spr_00564744);
  return self;
}
