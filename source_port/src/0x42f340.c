// SubMenu_BuildTownAdministration: ported from Pizza Connection 2 at 0x42f340.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x42f340
#include "pc2_port.h"


void * __cdecl SubMenu_BuildTownAdministration(int *arg1)

{
  int value1;
  void *self;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
                    /* Builds the town administration page. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004aa540);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  value1 = UI_AddText(self,0x44f,0x2b,5,s_TIMESFONT_fnt_00563ea8,DAT_00581974);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x44f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x44f,2,0xbe,0,0);
  }
  UI_AddImage(self,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  value1 = UI_CreateSlider(self,0x1fa8,0x3e,0x3c,0xa0,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xf700;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x1fa8,&local_10);
  }
  value1 = UI_AddText(self,0x1fa9,0x34,0x28,s_VERDANA8_fnt_00563e98,DAT_005812b4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fa9,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fa9,2,0xaa,0,0);
  }
  UI_AddSprite(self,0x1faa,0x27,0xb6,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x1fab,0x32,0x48,s_VERDANA7_fnt_00563ec8,DAT_00581284);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fab,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fab,0,0x8c,0,0);
  }
  value1 = UI_AddText(self,0x1fac,0xaf,0x48,s_VERDANA7_fnt_00563ec8,&DAT_00565650);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fac,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fac,1,0x32,0,0);
  }
  value1 = UI_AddText(self,0x1faf,0x32,0x53,s_VERDANA7_fnt_00563ec8,DAT_0058291c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1faf,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1faf,0,0x8c,0,0);
  }
  value1 = UI_AddText(self,0x1fb0,0xaf,0x53,s_VERDANA7_fnt_00563ec8,s___10__00565648);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fb0,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fb0,1,0x32,0,0);
  }
  value1 = UI_AddText(self,0x1fb1,0x67,0x82,s_VERDANA7_fnt_00563ec8,DAT_00582a5c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fb1,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fb1,1,0x3c,0,0);
  }
  value1 = UI_AddText(self,0x1fb2,0x96,0x8f,s_VERDANA7_fnt_00563ec8,&DAT_005650bc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fb2,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fb2,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1fb3,0x82,0x82,s_VERDANA7_fnt_00563ec8,DAT_00582928);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fb3,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fb3,1,0x3c,0,0);
  }
  value1 = UI_AddText(self,0x1fb4,0x96,0x9a,s_VERDANA7_fnt_00563ec8,&DAT_005650b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fb4,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fb4,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1fb5,0xa9,0x82,s_VERDANA7_fnt_00563ec8,DAT_00581ca8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fb5,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fb5,1,0x3c,0,0);
  }
  value1 = UI_AddText(self,0x1fb6,0x96,0xa5,s_VERDANA7_fnt_00563ec8,&DAT_005650b4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fb6,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fb6,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1fb7,0x31,0x8f,s_VERDANA7_fnt_00563ec8,DAT_00581abc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fb7,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fb7,0,0x5a,0,0);
  }
  value1 = UI_AddText(self,0x1fb8,0x31,0x9a,s_VERDANA7_fnt_00563ec8,DAT_00580f3c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fb8,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fb8,0,0x5a,0,0);
  }
  value1 = UI_AddText(self,0x1fb9,0x71,0x8f,s_VERDANA7_fnt_00563ec8,&DAT_005650b0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fb9,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fb9,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1fba,0x71,0x9a,s_VERDANA7_fnt_00563ec8,&DAT_005650bc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fba,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fba,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1fbb,0x71,0xa5,s_VERDANA7_fnt_00563ec8,&DAT_005650ac);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fbb,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fbb,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1fbc,0xbb,0x8f,s_VERDANA7_fnt_00563ec8,&DAT_005650b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fbc,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fbc,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1fbd,0xbb,0x9a,s_VERDANA7_fnt_00563ec8,&DAT_005650b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fbd,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fbd,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1fbe,0xbb,0xa5,s_VERDANA7_fnt_00563ec8,&DAT_005650b4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fbe,0xff);
    Window_GadgetNotify_Text_SetLayout(self,0x1fbe,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1fbf,0x32,0xa5,s_VERDANA7_fnt_00563ec8,DAT_00582b14);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fbf,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fbf,0,0x5a,0,0);
  }
  value1 = UI_AddText(self,0x1fc0,0x32,0x6d,s_VERDANA10_fnt_00563e64,DAT_00580c98);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fc0,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fc0,0,0x69,0,0);
  }
  value1 = UI_AddText(self,0x1fc1,0x32,0xc1,s_VERDANA10_fnt_00563e64,DAT_00580b0c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fc1,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fc1,0,0xa0,0,0);
  }
  value1 = UI_AddText(self,0x1fc2,0x34,0xd3,s_VERDANA8_fnt_00563e98,DAT_00580fe8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fc2,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fc2,2,0xaa,0,0);
  }
  value1 = UI_CreateSlider(self,0x1fc3,0x3e,0xe7,0xa0,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xf700;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x1fc3,&local_10);
  }
  value1 = UI_AddText(self,0x1fc4,0x33,0xf2,s_VERDANA7_fnt_00563ec8,DAT_00580b60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fc4,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fc4,0,0x8c,0,0);
  }
  value1 = UI_AddText(self,0x1fc5,0xaf,0xf2,s_VERDANA7_fnt_00563ec8,s___20__00565640);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fc5,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fc5,1,0x32,0,0);
  }
  value1 = UI_AddText(self,0x1fc6,0x33,0xfd,s_VERDANA7_fnt_00563ec8,DAT_005828cc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fc6,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fc6,0,0xa0,0,0);
  }
  value1 = UI_AddText(self,0x1fc7,0xcd,0xfd,s_VERDANA7_fnt_00563ec8,&DAT_0056563c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fc7,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fc7,1,0x14,0,0);
  }
  value1 = UI_AddText(self,0x1fc8,0x31,0x117,s_VERDANA8_fnt_00563e98,DAT_00580d6c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fc8,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fc8,0,0x82,0xffff,0);
  }
  value1 = UI_AddText(self,0x1fc9,0x31,0x125,s_VERDANA8_fnt_00563e98,s__Pizza_Tingeltangel_0056510c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fc9,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fc9,0,0x87,0,0);
  }
  UI_AddSprite(self,0x1fca,0xb5,0x115,s_LOGORAHMEN_00_spr_005650f8);
  UI_CreateBitmapGadget(self,0x1fcb,0xb7,0x117,0x2c,0x1d,0x10);
  value1 = UI_AddTextButton(self,0x1fce,0x30,0x13d,s_VERDANA8_fnt_00563e98,DAT_00580e6c,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x1fce,0,0,0);
    Gadget_SetButtonTextLayout(self,0x1fce,2,0x54,0,0,0xfffe);
  }
  value1 = UI_AddTextButton(self,0x1fcf,0x8e,0x13d,s_VERDANA8_fnt_00563e98,s___5000__00565634,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x1fcf,0,0,0);
    Gadget_SetButtonTextLayout(self,0x1fcf,2,0x54,0,0,0xfffe);
  }
  value1 = UI_AddText(self,0x1fd2,0x31,0x158,s_VERDANA8_fnt_00563e98,DAT_005818a0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fd2,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fd2,0,0x87,0x1e,0);
  }
  value1 = UI_AddText(self,0x1fd3,0x88,0x165,s_VERDANA8_fnt_00563e98,s__100_000__00565098);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fd3,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fd3,1,0x5a,0xffff,0);
  }
  UI_AddSprite(self,0x1fd4,0xb7,0x117,s_PLAYLOG_8_01_02_spr_00564744);
  return self;
}
