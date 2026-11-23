// SubMenu_BuildStockInformation: ported from Pizza Connection 2 at 0x454ee0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x454ee0
#include "pc2_port.h"


void * __cdecl SubMenu_BuildStockInformation(int *arg1)

{
  int value1;
  void *self;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
                    /* Builds the stock information page. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004be530);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(self,0x409,0x27,0xce,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x45c,0x3d,0x25,s_VERDANA10_fnt_00563e64,DAT_00582e20);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x45c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x45c,2,0x98,0,0);
  }
  value1 = UI_AddText(self,0x45d,0x41,0x36,s_VERDANA8_fnt_00563e98,DAT_00582ca0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x45d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x45d,2,0x98,0,0);
  }
  value1 = UI_AddText(self,0x45e,0x41,0x52,s_VERDANA8_fnt_00563e98,DAT_00582e28);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x45e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x45e,2,0x98,0,0);
  }
  value1 = UI_AddText(self,0x465,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00582088);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x465,0);
    Window_GadgetNotify_Text_SetLayout(self,0x465,2,0xbe,0,0);
  }
  value1 = UI_CreateSlider(self,0x441,0x34,0xc3,0x5a,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x441,&local_10);
  }
  value1 = UI_CreateSlider(self,0x442,0x8f,0xc3,0x5a,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x442,&local_10);
  }
  value1 = UI_CreateSlider(self,0x443,0x4a,0x49,0x8c,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x443,&local_10);
  }
  value1 = UI_CreateSlider(self,0x444,0x4a,0x65,0x8c,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x444,&local_10);
  }
  value1 = UI_AddText(self,0x500,0x2d,0xde,s_VERDANA8_fnt_00563e98,DAT_0058281c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x500,0);
    Window_GadgetNotify_Text_SetLayout(self,0x500,0,0x5a,0,0);
  }
  value1 = UI_AddText(self,0x501,0x2d,0xf7,s_VERDANA8_fnt_00563e98,s__Pizza_Tingeltangel_0056510c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x501,0);
    Window_GadgetNotify_Text_SetLayout(self,0x501,0,0x87,0,0);
  }
  UI_AddSprite(self,0x502,0xb5,0xe5,s_LOGORAHMEN_00_spr_005650f8);
  UI_CreateBitmapGadget(self,0x510,0xb7,0xe7,0x2c,0x1d,0x10);
  UI_AddSprite(self,0x506,0x27,0x79,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x507,0x32,0xb0,s_VERDANA8_fnt_00563e98,DAT_00582a18);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x507,0);
    Window_GadgetNotify_Text_SetLayout(self,0x507,2,0x5a,0,0);
  }
  value1 = UI_AddText(self,0x508,0x8c,0xb0,s_VERDANA8_fnt_00563e98,DAT_00581580);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x508,0);
    Window_GadgetNotify_Text_SetLayout(self,0x508,2,0x5a,0,0);
  }
  value1 = UI_AddText(self,0x509,0x2f,0x83,s_VERDANA8_fnt_00563e98,DAT_00581bf4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x509,0);
    Window_GadgetNotify_Text_SetLayout(self,0x509,0,100,0,0);
  }
  value1 = UI_AddText(self,0x50b,0x30,0x6d,s_VERDANA8_fnt_00563e98,DAT_00581a6c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x50b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x50b,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x50d,0xaa,0x6d,s_VERDANA7_fnt_00563ec8,&DAT_00565078);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x50d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x50d,1,0x3c,0,0);
  }
  value1 = UI_AddText(self,0x50e,0x30,0x97,s_VEDANA11_fnt_00564090,&DAT_005666ac);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x50e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x50e,2,0xb4,0,0);
  }
  UI_AddImage(self,0x50f,0xd1,0x7f,s_PB33_00_spr_00564ba0,0,0);
  UI_AddImage(self,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  UI_AddSprite(self,0x1f42,0x27,0x10b,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddTextButton(self,0x1f44,0x8e,0x129,s_VERDANA8_fnt_00563e98,DAT_00581b08,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x1f44,0x9a,0,0);
    Gadget_SetButtonTextLayout(self,0x1f44,2,0x54,0,0,0xfffe);
  }
  value1 = UI_AddText(self,0x1f4b,0xbd,0x169,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f4b,0xff);
    Window_GadgetNotify_Text_SetLayout(self,0x1f4b,1,0x28,0,0);
  }
  UI_AddSprite(self,0x1f4d,0xb7,0xe7,s_PLAYLOG_8_01_02_spr_00564744);
  value1 = UI_AddText(self,0x1f54,0x33,0x168,s_VERDANA7_fnt_00563ec8,DAT_00582c30);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f54,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f54,0,0xa0,0,0);
  }
  value1 = UI_AddText(self,0x1f55,0xbd,0x153,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f55,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f55,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1f58,0x8a,0x149,s_VERDANA7_fnt_00563ec8,DAT_00582a40);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f58,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f58,0,0x3c,0,0);
  }
  value1 = UI_AddText(self,0x1f59,0x8a,0x153,s_VERDANA7_fnt_00563ec8,DAT_00580f10);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f59,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f59,0,0x3c,0,0);
  }
  value1 = UI_AddText(self,0x1f5b,0xbd,0x149,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f5b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f5b,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1f5d,0x8b,0x13f,s_VERDANA7_fnt_00563ec8,DAT_00581fc0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f5d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f5d,0,0x32,0,0);
  }
  value1 = UI_AddText(self,0x1f5e,0xb3,0x13f,s_VERDANA7_fnt_00563ec8,s__300000__00566688);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f5e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f5e,1,0x32,0,0);
  }
  value1 = UI_AddText(self,0x1f5f,0x31,0x114,s_VERDANA10_fnt_00563e64,DAT_005816fc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f5f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f5f,0,0xb4,0,0);
  }
  return self;
}
