// SubMenu_BuildGuardOverview: ported from Pizza Connection 2 at 0x46a390.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x46a390
#include "pc2_port.h"


void * __cdecl SubMenu_BuildGuardOverview(int *arg1)

{
  int value1;
  void *self;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
                    /* Builds the guard management overview page. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004c5720);
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
  UI_AddSprite(self,0x1f46,0x27,0xb7,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x1f4a,0x2f,0x80,s_VERDANA10_fnt_00563e64,DAT_00582d58);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f4a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f4a,0,0xb4,0,0);
  }
  value1 = UI_AddTextButton(self,0x1f4c,0x30,0x112,s_VERDANA8_fnt_00563e98,DAT_0058276c,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x1f4c,0,0,0);
    Gadget_SetButtonTextLayout(self,0x1f4c,2,0x54,0,0,0xfffe);
  }
  value1 = UI_AddTextButton(self,0x1f4d,0x8e,0x112,s_VERDANA8_fnt_00563e98,DAT_0058202c,0,
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
  value1 = UI_AddText(self,0x1f52,0x2f,0x90,s_VERDANA10_fnt_00563e64,s__Filiale_Romana_00565068);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f52,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f52,0,0xb4,0xffff,0);
  }
  value1 = UI_AddText(self,0x1f54,0xb5,0x167,s_VERDANA8_fnt_00563e98,&DAT_005644f4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f54,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f54,2,0x2d,0,0);
  }
  UI_AddSprite(self,0x1f57,0x27,0x12a,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,7000,0x33,0xfd,s_VERDANA8_fnt_00563e98,DAT_00581acc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,7000,0);
    Window_GadgetNotify_Text_SetLayout(self,7000,0,100,0,0);
  }
  value1 = UI_AddText(self,0x1b59,0x83,0xfd,s_VERDANA8_fnt_00563e98,s__10000__00566300);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1b59,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1b59,1,100,0,0);
  }
  value1 = UI_AddText(self,0x1b5a,0x2f,0xc0,s_VERDANA10_fnt_00563e64,DAT_00581350);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1b5a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1b5a,0,100,0,0);
  }
  value1 = UI_AddText(self,0x1b5b,0x33,0xd1,s_VERDANA7_fnt_00563ec8,DAT_00581b38);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1b5b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1b5b,0,0x32,0,0);
  }
  value1 = UI_AddText(self,0x1b5c,0x33,0xdb,s_VERDANA7_fnt_00563ec8,DAT_00580c48);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1b5c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1b5c,0,0x3c,0,0);
  }
  value1 = UI_AddText(self,0x1b5d,0x65,0xd2,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1b5d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1b5d,1,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x1b5e,0x65,0xdc,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1b5e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1b5e,1,0x1e,0,0);
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
  value1 = UI_AddText(self,0x1b5f,0x8e,0xd1,s_VERDANA7_fnt_00563ec8,DAT_00582fb4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1b5f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1b5f,0,0x32,0,0);
  }
  value1 = UI_AddText(self,0x1b60,0x8e,0xdb,s_VERDANA7_fnt_00563ec8,DAT_00582e58);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1b60,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1b60,0,0x3c,0,0);
  }
  value1 = UI_AddText(self,0x1b61,0xc0,0xd2,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1b61,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1b61,1,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x1b62,0xc0,0xdc,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1b62,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1b62,1,0x1e,0,0);
  }
  UI_AddSprite(self,0x1f6d,0x27,0x10b,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x1b63,0x6f,0xc0,s_VERDANA10_fnt_00563e64,s__Filiale_Romana_00565068);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1b63,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1b63,1,0x78,0,0);
  }
  value1 = UI_AddText(self,0x1b64,0x33,0xf0,s_VERDANA8_fnt_00563e98,DAT_00581900);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1b64,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1b64,0,100,0,0);
  }
  value1 = UI_AddText(self,0x1b65,0x83,0xf0,s_VERDANA8_fnt_00563e98,s__2000__00565158);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1b65,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1b65,1,100,0,0);
  }
  value1 = UI_AddText(self,0x1f75,0x33,0x134,s_VERDANA8_fnt_00563e98,DAT_00581b48);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f75,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f75,0,100,0,0);
  }
  value1 = UI_AddText(self,0x1f76,0x83,0x134,s_VERDANA8_fnt_00563e98,s__Stufe_1_0056452c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f76,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f76,1,100,0,0);
  }
  UI_AddSprite(self,0x1f79,0x80,0x14f,&DAT_0056450c);
  UI_AddSprite(self,0x1f7a,0x42,0x14f,s_SCHLAGKRAFT_spr_0056451c);
  UI_AddSprite(self,0x1f7b,0xc1,0x14f,s_PANZERUNG_spr_005644f8);
  UI_AddSprite(self,0x1f7c,0x2b,0x2c,s_WACHE_spr_00566664);
  value1 = UI_AddTextButton(self,0x1f7d,0x30,0xa0,s_VERDANA8_fnt_00563e98,DAT_00581c60,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x1f7d,0,0,0);
    Gadget_SetButtonTextLayout(self,0x1f7d,2,0xb2,0,0,0xfffe);
  }
  return self;
}
