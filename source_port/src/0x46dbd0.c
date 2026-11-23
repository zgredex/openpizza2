// Screen_CharacterSelect: ported from Pizza Connection 2 at 0x46dbd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x46dbd0
#include "pc2_port.h"


void * __cdecl Screen_CharacterSelect(int *arg1)

{
  int value1;
  void *self;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
  value1 = Window_CreatePictureWindow(DAT_0057c5e0,s_Pe_Charakterauswahl_tga_00567240,&LAB_004c75a0);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddImage(self,0x3ee,0x42,0x8c,s_PB22_00_spr_00564174,0,0);
  UI_AddImage(self,0x3ef,0xad,0x8c,s_PB24_00_spr_00564144,0,0);
  UI_AddImage(self,0x3f0,0x42,0xab,s_PB22_00_spr_00564174,0,0);
  UI_AddImage(self,0x3f1,0xad,0xab,s_PB24_00_spr_00564144,0,0);
  UI_AddImage(self,0x3f2,0x42,0xce,s_PB22_00_spr_00564174,0,0);
  UI_AddImage(self,0x3f3,0xad,0xce,s_PB24_00_spr_00564144,0,0);
  UI_AddImage(self,0x3f4,0x42,0xee,s_PB22_00_spr_00564174,0,0);
  UI_AddImage(self,0x3f5,0xad,0xee,s_PB24_00_spr_00564144,0,0);
  UI_AddImage(self,0x3f6,0x276,0xd0,s_PB22_00_spr_00564174,0,0);
  UI_AddImage(self,0x3f7,0x2e1,0xd0,s_PB24_00_spr_00564144,0,0);
  UI_AddImage(self,0x3f8,0x276,0xef,s_PB22_00_spr_00564174,0,0);
  UI_AddImage(self,0x3f9,0x2e1,0xef,s_PB24_00_spr_00564144,0,0);
  UI_AddImage(self,0x3fa,299,0x8c,s_PB26_00_spr_00564610,0,0);
  UI_AddImage(self,0x3fb,0x1c7,0x8c,s_PB27_00_spr_005645fc,0,0);
  UI_AddImage(self,0x3fc,299,0xac,s_PB26_00_spr_00564610,0,0);
  UI_AddImage(self,0x3fd,0x1c7,0xac,s_PB27_00_spr_005645fc,0,0);
  UI_AddImage(self,0x3fe,299,0xce,s_PB26_00_spr_00564610,0,0);
  UI_AddImage(self,0x3ff,0x1c7,0xce,s_PB27_00_spr_005645fc,0,0);
  UI_AddImage(self,0x400,299,0xef,s_PB26_00_spr_00564610,0,0);
  UI_AddImage(self,0x401,0x1c7,0xef,s_PB27_00_spr_005645fc,0,0);
  UI_AddImage(self,0x402,299,0x111,s_PB26_00_spr_00564610,0,0);
  UI_AddImage(self,0x403,0x1c7,0x111,s_PB27_00_spr_005645fc,0,0);
  UI_AddImage(self,0x404,299,0x130,s_PB26_00_spr_00564610,0,0);
  UI_AddImage(self,0x405,0x1c7,0x130,s_PB27_00_spr_005645fc,0,0);
  value1 = UI_AddText(self,0x406,0x261,0x1a9,s_TIMESFONT_fnt_00563ea8,DAT_00581e20);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x406,0);
    Window_GadgetNotify_Text_SetLayout(self,0x406,2,0xb4,0,0);
  }
  value1 = UI_CreateSlider(self,0x407,0x269,0x1cd,0xaf,s_SL02_00_spr_005642d0,0,0);
  if (value1 != 0) {
    local_10 = 0xaa00;
    local_c = 0xffff;
    local_8 = 0xff;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x407,&local_10);
  }
  value1 = UI_AddText(self,0x408,0x261,0x1de,s_VERDANA10_fnt_00563e64,DAT_00582bb8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x408,0);
    Window_GadgetNotify_Text_SetLayout(self,0x408,2,0xb4,0,0);
  }
  value1 = UI_AddText(self,0x409,0x261,0x130,s_TIMESFONT_fnt_00563ea8,DAT_00582b00);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x409,0);
    Window_GadgetNotify_Text_SetLayout(self,0x409,2,0xb4,0,0);
  }
  value1 = UI_AddText(self,0x40b,0x2c,0x130,s_TIMESFONT_fnt_00563ea8,DAT_005824c8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x40b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x40b,2,0xb4,0,0);
  }
  value1 = UI_AddText(self,0x40d,0x5b,0xef,s_TIMESFONT_fnt_00563ea8,DAT_00580fa0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x40d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x40d,2,0x53,0,0);
  }
  value1 = UI_AddText(self,0x40e,0x5b,0xce,s_TIMESFONT_fnt_00563ea8,DAT_00581bb4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x40e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x40e,2,0x53,0,0);
  }
  value1 = UI_AddText(self,0x40f,0x5b,0xac,s_TIMESFONT_fnt_00563ea8,DAT_00581728);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x40f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x40f,2,0x53,0,0);
  }
  value1 = UI_AddText(self,0x410,0x5b,0x8c,s_TIMESFONT_fnt_00563ea8,DAT_00582a50);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x410,0);
    Window_GadgetNotify_Text_SetLayout(self,0x410,2,0x53,0,0);
  }
  value1 = UI_AddText(self,0x411,0x143,0x8c,s_TIMESFONT_fnt_00563ea8,DAT_00581fa0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x411,0);
    Window_GadgetNotify_Text_SetLayout(self,0x411,2,0x85,0,0);
  }
  value1 = UI_AddText(self,0x412,0x143,0xad,s_TIMESFONT_fnt_00563ea8,DAT_00582474);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x412,0);
    Window_GadgetNotify_Text_SetLayout(self,0x412,2,0x85,0,0);
  }
  value1 = UI_AddText(self,0x413,0x143,0xcf,s_TIMESFONT_fnt_00563ea8,DAT_00581070);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x413,0);
    Window_GadgetNotify_Text_SetLayout(self,0x413,2,0x85,0,0);
  }
  value1 = UI_AddText(self,0x414,0x143,0xef,s_TIMESFONT_fnt_00563ea8,DAT_00581138);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x414,0);
    Window_GadgetNotify_Text_SetLayout(self,0x414,2,0x85,0,0);
  }
  value1 = UI_AddText(self,0x415,0x143,0x111,s_TIMESFONT_fnt_00563ea8,DAT_005826d0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x415,0);
    Window_GadgetNotify_Text_SetLayout(self,0x415,2,0x85,0,0);
  }
  value1 = UI_AddText(self,0x416,0x143,0x131,s_TIMESFONT_fnt_00563ea8,DAT_00582ebc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x416,0);
    Window_GadgetNotify_Text_SetLayout(self,0x416,2,0x85,0,0);
  }
  value1 = UI_AddText(self,0x418,0x1f5,0x8c,s_TIMESFONT_fnt_00563ea8,&DAT_00564538);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x418,0);
    Window_GadgetNotify_Text_SetLayout(self,0x418,2,0x28,0,0);
  }
  value1 = UI_AddText(self,0x419,0x1f5,0xad,s_TIMESFONT_fnt_00563ea8,&DAT_00565288);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x419,0);
    Window_GadgetNotify_Text_SetLayout(self,0x419,2,0x28,0,0);
  }
  value1 = UI_AddText(self,0x41a,0x1f5,0xcf,s_TIMESFONT_fnt_00563ea8,&DAT_00564538);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x41a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x41a,2,0x28,0,0);
  }
  value1 = UI_AddText(self,0x41b,0x1f5,0xef,s_TIMESFONT_fnt_00563ea8,&DAT_0056723c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x41b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x41b,2,0x28,0,0);
  }
  value1 = UI_AddText(self,0x41c,0x1f5,0x111,s_TIMESFONT_fnt_00563ea8,&DAT_005650b0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x41c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x41c,2,0x28,0,0);
  }
  value1 = UI_AddText(self,0x41d,0x1f5,0x131,s_TIMESFONT_fnt_00563ea8,&DAT_00564538);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x41d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x41d,2,0x28,0,0);
  }
  value1 = UI_AddText(self,0x41e,0x1f5,0x168,s_TIMESFONT_fnt_00563ea8,&DAT_00565288);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x41e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x41e,2,0x28,0,0);
  }
  value1 = UI_AddText(self,0x41f,0x103,0x4d,s_TIMESFONT_fnt_00563ea8,DAT_00582990);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x41f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x41f,2,0x136,0,0);
  }
  value1 = UI_AddText(self,0x420,0xd,5,s_TIMESFONT_fnt_00563ea8,DAT_005815b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x420,0);
    Window_GadgetNotify_Text_SetLayout(self,0x420,2,0x230,0,0);
  }
  value1 = UI_AddText(self,0x422,0x260,5,s_TIMESFONT_fnt_00563ea8,DAT_00582e50);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x422,0);
    Window_GadgetNotify_Text_SetLayout(self,0x422,2,0xb4,0,0);
  }
  value1 = UI_AddText(self,0x423,0x28f,0xd0,s_TIMESFONT_fnt_00563ea8,DAT_00582940);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x423,0);
    Window_GadgetNotify_Text_SetLayout(self,0x423,2,0x53,0,0);
  }
  value1 = UI_AddText(self,0x424,0x28f,0xf0,s_TIMESFONT_fnt_00563ea8,DAT_00582940);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x424,0);
    Window_GadgetNotify_Text_SetLayout(self,0x424,2,0x53,0,0);
  }
  value1 = UI_AddText(self,0x429,0xe0,0x1ff,s_VERDANA8_fnt_00563e98,
                     s__Online_Hilfetext_2_3_4_5_6_00567220);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x429,0);
    Window_GadgetNotify_Text_SetLayout(self,0x429,0,0x159,0x50,0);
  }
  UI_AddSprite(self,0x431,100,0x39,s_FOTORAHMEN00_spr_00564310);
  UI_AddSprite(self,0x433,0x69,0x3e,s_FOTODUMMY00_spr_00564300);
  value1 = UI_AddTextButton(self,0x434,0x253,0x1fd,s_TIMESFONT_fnt_00563ea8,DAT_00582d40,0,
                           s_TEXTPBTRANSPGELB_00_spr_00567208);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x434,0,0,0);
    Gadget_SetButtonTextLayout(self,0x434,2,0xcc,0,0,0);
  }
  value1 = UI_AddTextButton(self,0x435,0x253,0x227,s_TIMESFONT_fnt_00563ea8,DAT_00581338,0,
                           s_TEXTPBTRANSPGRUEN_00_spr_005671ec);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x435,0,0,0);
    Gadget_SetButtonTextLayout(self,0x435,2,0xcc,0,0,0);
  }
  UI_CreateBitmapGadget(self,0x436,0x279,0x3e,0x80,0x7f,0x10);
  UI_CreateBitmapGadget(self,0x437,0x279,0x3e,0x80,0x7f,0x10);
  UI_AddImage(self,0x43a,0x47,0x4a,s_GESCHLECHT_M_00_spr_005671d8,1,0);
  UI_AddImage(self,0x43b,0xae,0x47,s_GESCHLECHT_W_00_spr_005671c4,1,0);
  UI_AddSprite(self,0x43c,0x279,0x3d,s_PLAYLOG_2_01_00_spr_005671b0);
  UI_AddSprite(self,0x43e,0x272,0x36,s_LOGOFENSTER_spr_005671a0);
  UI_AddImage(self,0x43f,0x2a,0x157,s_LEUCHTFELD_00_00_spr_00567188,0,0);
  UI_AddImage(self,0x440,0x25c,0x157,s_LEUCHTFELD_00_00_spr_00567188,0,0);
  value1 = UI_AddInputField(self,0x40a,0x268,0x15b,s_TIMES14_fnt_00564788,
                           s__Unternehmensname_00564ac4,0xaa);
  if (value1 != 0) {
    Window_GadgetNotify_Input_SetNormalColor(self,0x40a,0);
    Window_GadgetNotify_Input_SetEditingColor(self,0x40a,0);
    Window_GadgetNotify_Input_SetFocusColor(self,0x40a,0x868686);
    Window_GadgetNotify_Input_SetSelectionColor(self,0x40a,0xff);
  }
  value1 = UI_AddInputField(self,0x40c,0x33,0x15b,s_TIMES14_fnt_00564788,s__Spielername_00567178,0xaa
                          );
  if (value1 != 0) {
    Window_GadgetNotify_Input_SetNormalColor(self,0x40c,0);
    Window_GadgetNotify_Input_SetEditingColor(self,0x40c,0);
    Window_GadgetNotify_Input_SetFocusColor(self,0x40c,0x868686);
    Window_GadgetNotify_Input_SetSelectionColor(self,0x40c,0xff);
  }
  return self;
}
