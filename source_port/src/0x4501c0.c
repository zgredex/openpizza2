// SubMenu_BuildCourierMission: ported from Pizza Connection 2 at 0x4501c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4501c0
#include "pc2_port.h"


void * __cdecl SubMenu_BuildCourierMission(int *arg1)

{
  int value1;
  void *self;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
                    /* Builds the criminal courier mission page. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004bbdb0);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  value1 = UI_AddText(self,0x472,0x2a,5,s_TIMESFONT_fnt_00563ea8,DAT_00582808);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x472,0);
    Window_GadgetNotify_Text_SetLayout(self,0x472,2,0xbe,0,0);
  }
  value1 = UI_AddText(self,0x476,0x2f,0x82,s_VERDANA10_fnt_00563e64,DAT_005825f4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x476,0);
    Window_GadgetNotify_Text_SetLayout(self,0x476,0,0x46,0,0);
  }
  value1 = UI_AddText(self,0x48f,0x4e,0x33,s_VEDANA11_fnt_00564090,s__Kurier_005665e0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x48f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x48f,2,0x78,0,0);
  }
  UI_AddImage(self,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  value1 = UI_CreateSlider(self,0x1f41,0x3e,0x69,0xa0,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xf700;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x1f41,&local_10);
  }
  value1 = UI_AddText(self,0x1f42,0x34,0x56,s_VERDANA8_fnt_00563e98,DAT_00582b0c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f42,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f42,2,0xaa,0,0);
  }
  UI_AddSprite(self,0x1f43,0x27,0x79,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x1f44,0x2f,0x95,s_VERDANA10_fnt_00563e64,
                     s__Eine_Lieferung_Ratten_005665c8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f44,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f44,0,0xb4,0x23,0);
  }
  value1 = UI_AddText(self,0x1f46,0x74,0x168,s_VERDANA8_fnt_00563e98,&DAT_00565088);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f46,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f46,2,0x2d,0,0);
  }
  value1 = UI_AddText(self,0x1f47,0x36,0x168,s_VERDANA8_fnt_00563e98,&DAT_00565094);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f47,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f47,2,0x2d,0,0);
  }
  value1 = UI_AddText(self,0x1f48,0xb5,0x167,s_VERDANA8_fnt_00563e98,&DAT_00565088);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f48,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f48,2,0x2d,0,0);
  }
  UI_AddSprite(self,0x1f4b,0x27,0x12a,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x1f5a,0x2d,0xfd,s_VERDANA8_fnt_00563e98,DAT_00582758);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f5a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f5a,0,0x5a,0,0);
  }
  value1 = UI_AddText(self,0x1f5b,0x2d,0x116,s_VERDANA8_fnt_00563e98,s__Pizza_Tingeltangel_0056510c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f5b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f5b,0,0x87,0,0);
  }
  UI_AddSprite(self,0x1f5c,0xb5,0x104,s_LOGORAHMEN_00_spr_005650f8);
  UI_CreateBitmapGadget(self,0x1f5d,0xb7,0x106,0x2c,0x1d,0x10);
  UI_AddSprite(self,0x1f5f,0x27,0xf2,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x1f60,0x33,0x134,s_VERDANA8_fnt_00563e98,DAT_00580fec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f60,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f60,0,0x82,0,0);
  }
  value1 = UI_AddText(self,0x1f61,0x83,0x134,s_VERDANA8_fnt_00563e98,s__Stufe_1_0056452c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f61,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f61,1,100,0,0);
  }
  UI_AddSprite(self,0x1f62,0x80,0x14f,&DAT_0056450c);
  UI_AddSprite(self,0x1f63,0x42,0x14f,s_SCHLAGKRAFT_spr_0056451c);
  UI_AddSprite(self,0x1f64,0xc1,0x14f,s_PANZERUNG_spr_005644f8);
  UI_AddSprite(self,0x1f65,0x29,0x2c,s_MASCHINENGEWEHRICON_spr_005665b0);
  UI_AddSprite(self,0x1f66,0x30,0x2b,s_SCHLAEGERICON_spr_0056659c);
  UI_AddSprite(self,0x1f67,0x2b,0x2c,s_LIEFERANT_spr_0056658c);
  value1 = UI_AddTextButton(self,0x1f68,0x8e,0xc5,s_VERDANA8_fnt_00563e98,DAT_00582ae0,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x1f68,0,0,0);
    Gadget_SetButtonTextLayout(self,0x1f68,2,0x54,0,0,0xfffe);
  }
  value1 = UI_AddText(self,0x1f69,0x90,0xda,s_VERDANA7_fnt_00563ec8,DAT_00581fc0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f69,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f69,0,0x32,0,0);
  }
  value1 = UI_AddText(self,0x1f6a,0xbb,0xda,s_VERDANA7_fnt_00563ec8,s__1000__00566320);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f6a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f6a,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1f6b,0xbb,0xe4,s_VERDANA7_fnt_00563ec8,&DAT_00566318);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f6b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f6b,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1f6c,0x90,0xe4,s_VERDANA7_fnt_00563ec8,DAT_00582af4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f6c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f6c,0,0x3c,0,0);
  }
  value1 = UI_AddText(self,0x1f6d,0x31,0xc9,s_VERDANA8_fnt_00563e98,DAT_00581bf8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f6d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f6d,0,0x5f,0,0);
  }
  UI_AddSprite(self,0x1f6e,0xb7,0x106,s_PLAYLOG_8_01_02_spr_00564744);
  UI_AddSprite(self,0x1f6f,0x29,0x2c,s_PUNKICON_spr_0056657c);
  return self;
}
