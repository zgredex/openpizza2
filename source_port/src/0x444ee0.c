// SubMenu_BuildAttacks: ported from Pizza Connection 2 at 0x444ee0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x444ee0
#include "pc2_port.h"


void * __cdecl SubMenu_BuildAttacks(int *arg1)

{
  int value1;
  void *self;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
                    /* Builds the attacks submenu page. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004b7b10);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  value1 = UI_AddText(self,0x429,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00581cd4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x429,0);
    Window_GadgetNotify_Text_SetLayout(self,0x429,2,0xbe,0,0);
  }
  UI_AddImage(self,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  value1 = UI_AddText(self,0x1f43,0x31,0x24,s_VERDANA10_fnt_00563e64,DAT_00581894);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f43,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f43,0,0xb4,0,0);
  }
  value1 = UI_AddTextButton(self,0x1f59,0x32,0xd2,s_VERDANA8_fnt_00563e98,DAT_00581b08,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x1f59,0x9a,0,0);
    Gadget_SetButtonTextLayout(self,0x1f59,2,0x54,0,0,0xfffe);
  }
  UI_AddSprite(self,0x1f64,0x27,0xb6,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x1f65,0x31,0xc0,s_VERDANA10_fnt_00563e64,DAT_00581760);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f65,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f65,0,0xb4,0,0);
  }
  value1 = UI_AddTextButton(self,0x1f67,0x8e,0xd2,s_VERDANA8_fnt_00563e98,DAT_00582948,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x1f67,0,0,0);
    Gadget_SetButtonTextLayout(self,0x1f67,2,0x54,0,0,0xfffe);
  }
  value1 = UI_AddText(self,0x1f6d,0x90,0xe7,s_VERDANA7_fnt_00563ec8,DAT_00581fc0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f6d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f6d,0,0x32,0,0);
  }
  value1 = UI_AddText(self,0x1f6e,0xbb,0xe7,s_VERDANA7_fnt_00563ec8,s__5000__00566308);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f6e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f6e,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1f75,0x90,0xf1,s_VERDANA7_fnt_00563ec8,DAT_00582a40);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f75,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f75,0,0x3c,0,0);
  }
  value1 = UI_AddText(self,0x1f76,0xbb,0xf1,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f76,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f76,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1f77,0x90,0xfb,s_VERDANA7_fnt_00563ec8,DAT_005811ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f77,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f77,0,0x3c,0,0);
  }
  value1 = UI_AddText(self,0x1f78,0xbb,0xfb,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f78,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f78,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1fac,0x38,0x36,s_VERDANA10_fnt_00563e64,s__500000__00564254);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fac,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fac,1,0x50,0,0);
  }
  value1 = UI_AddText(self,0x1fad,0x2e,0x57,s_VERDANA7_fnt_00563ec8,DAT_00582ed4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fad,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fad,2,0x28,0,0);
  }
  value1 = UI_CreateSlider(self,0x1fae,0x47,0x50,0x8c,s_SL02_00_spr_005642d0,0,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x1fae,&local_10);
  }
  value1 = UI_AddText(self,0x1faf,0xa6,0x58,s_VERDANA7_fnt_00563ec8,DAT_00582820);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1faf,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1faf,1,0x3c,0,0);
  }
  value1 = UI_AddText(self,0x1fb0,0x90,0xa6,s_VERDANA7_fnt_00563ec8,DAT_005826ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fb0,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fb0,0,0x46,0,0);
  }
  value1 = UI_AddText(self,0x1fb1,0xbb,0xa6,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fb1,0xff);
    Window_GadgetNotify_Text_SetLayout(self,0x1fb1,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1fb3,0x31,0xe7,s_VERDANA7_fnt_00563ec8,DAT_00581fc0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fb3,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fb3,0,0x32,0,0);
  }
  value1 = UI_AddText(self,0x1fb4,0x55,0xe7,s_VERDANA7_fnt_00563ec8,s__300_000__00566378);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fb4,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fb4,1,0x32,0,0);
  }
  value1 = UI_AddText(self,0x1fb5,0x31,0xf1,s_VERDANA7_fnt_00563ec8,DAT_00582a40);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fb5,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fb5,0,0x3c,0,0);
  }
  value1 = UI_AddText(self,0x1fb6,0x5f,0xf1,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fb6,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fb6,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1fb7,0x31,0xfb,s_VERDANA7_fnt_00563ec8,DAT_005811ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fb7,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fb7,0,0x3c,0,0);
  }
  value1 = UI_AddText(self,0x1fb8,0x5f,0xfb,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fb8,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fb8,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1fb9,0x31,0x121,s_VERDANA10_fnt_00563e64,DAT_005821d4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fb9,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fb9,0,0xb4,0,0);
  }
  value1 = UI_AddTextButton(self,0x1fba,0x8e,0x133,s_VERDANA8_fnt_00563e98,DAT_00582948,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x1fba,0,0,0);
    Gadget_SetButtonTextLayout(self,0x1fba,2,0x54,0,0,0xfffe);
  }
  value1 = UI_AddText(self,0x1fbb,0x90,0x148,s_VERDANA7_fnt_00563ec8,DAT_00581fc0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fbb,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fbb,0,0x32,0,0);
  }
  value1 = UI_AddText(self,0x1fbc,0xbb,0x148,s_VERDANA7_fnt_00563ec8,s__5000__00566308);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fbc,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fbc,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1fbd,0x90,0x152,s_VERDANA7_fnt_00563ec8,DAT_00582a40);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fbd,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fbd,0,0x3c,0,0);
  }
  value1 = UI_AddText(self,0x1fbe,0xbb,0x152,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fbe,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fbe,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1fbf,0x90,0x15c,s_VERDANA7_fnt_00563ec8,DAT_005811ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fbf,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fbf,0,0x3c,0,0);
  }
  value1 = UI_AddText(self,0x1fc0,0xbb,0x15c,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fc0,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fc0,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1fc3,0x8f,0x16a,s_VERDANA7_fnt_00563ec8,DAT_005826ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fc3,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fc3,0,0x46,0,0);
  }
  value1 = UI_AddText(self,0x1fc4,0xbb,0x16a,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fc4,0xff);
    Window_GadgetNotify_Text_SetLayout(self,0x1fc4,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1fc5,0x90,0x109,s_VERDANA7_fnt_00563ec8,DAT_00582c60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fc5,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fc5,0,0x46,0,0);
  }
  value1 = UI_AddText(self,0x1fc6,0xbb,0x109,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fc6,0xff);
    Window_GadgetNotify_Text_SetLayout(self,0x1fc6,1,0x28,0,0);
  }
  value1 = UI_AddTextButton(self,0x1fcb,0x8e,0x70,s_VERDANA8_fnt_00563e98,s__Fordern_0056636c,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x1fcb,0,0,0);
    Gadget_SetButtonTextLayout(self,0x1fcb,2,0x54,0,0,0xfffe);
  }
  value1 = UI_AddText(self,0x1fcc,0x90,0x85,s_VERDANA7_fnt_00563ec8,s__Seit__00566364);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fcc,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fcc,0,0x32,0,0);
  }
  value1 = UI_AddText(self,0x1fcd,0xbb,0x85,s_VERDANA7_fnt_00563ec8,s__16_h_0056635c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fcd,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fcd,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1fce,0x90,0x8f,s_VERDANA7_fnt_00563ec8,DAT_00582a40);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fce,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fce,0,0x3c,0,0);
  }
  value1 = UI_AddText(self,0x1fcf,0xbb,0x8f,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fcf,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fcf,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1fd0,0x90,0x99,s_VERDANA7_fnt_00563ec8,DAT_005811ec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fd0,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fd0,0,0x3c,0,0);
  }
  value1 = UI_AddText(self,0x1fd1,0xbb,0x99,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fd1,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fd1,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1fd2,0x8d,0x36,s_VERDANA10_fnt_00563e64,DAT_00581ad8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fd2,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fd2,0,0x5a,0,0);
  }
  value1 = UI_AddText(self,0x1fd3,0x34,0x62,s_VERDANA7_fnt_00563ec8,
                     s__Bezahlt_bis_jetzt_nicht__00566340);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fd3,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fd3,0,0xa0,0,0);
  }
  value1 = UI_AddText(self,0x1fd4,0x92,0x62,s_VERDANA7_fnt_00563ec8,s__1000000___00565528);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fd4,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fd4,1,0x50,0,0);
  }
  value1 = UI_AddText(self,0x1fd5,0x31,0x109,s_VERDANA7_fnt_00563ec8,DAT_00581834);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fd5,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fd5,0,0x46,0,0);
  }
  value1 = UI_AddText(self,0x1fd6,0x5f,0x109,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fd6,0xff);
    Window_GadgetNotify_Text_SetLayout(self,0x1fd6,1,0x28,0,0);
  }
  return self;
}
