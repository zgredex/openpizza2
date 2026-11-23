// SubMenu_BuildSyndicate: ported from Pizza Connection 2 at 0x4281e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4281e0
#include "pc2_port.h"


void * __cdecl SubMenu_BuildSyndicate(int *arg1)

{
  int value1;
  void *self;
  
                    /* Builds the syndicate management page. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004a3720);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(self,0x45f,0x27,0xf2,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x472,0x2a,5,s_TIMESFONT_fnt_00563ea8,DAT_00581850);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x472,0);
    Window_GadgetNotify_Text_SetLayout(self,0x472,2,0xbe,0,0);
  }
  value1 = UI_AddText(self,0x476,0x2f,0x82,s_VERDANA10_fnt_00563e64,DAT_005822d0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x476,0);
    Window_GadgetNotify_Text_SetLayout(self,0x476,0,0x46,0,0);
  }
  UI_AddImage(self,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  UI_AddSprite(self,0x1f43,0x27,0x79,s_TRENNZEILE_spr_00563eb8);
  UI_AddSprite(self,0x1f4b,0x27,0x12a,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x1f4e,0x2f,0x24,s_VERDANA10_fnt_00563e64,DAT_00581664);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f4e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f4e,0,0x8c,0,0);
  }
  value1 = UI_AddText(self,0x1f4f,0x4e,0x37,s_VERDANA7_fnt_00563ec8,DAT_0058260c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f4f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f4f,1,0x32,0,0);
  }
  value1 = UI_AddText(self,0x1f50,0x8a,0x43,s_VERDANA7_fnt_00563ec8,&DAT_005650bc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f50,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f50,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1f51,0x76,0x37,s_VERDANA7_fnt_00563ec8,DAT_00582544);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f51,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f51,1,0x3c,0,0);
  }
  value1 = UI_AddText(self,0x1f52,0x8a,0x4d,s_VERDANA7_fnt_00563ec8,&DAT_005650b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f52,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f52,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1f53,0xa9,0x37,s_VERDANA7_fnt_00563ec8,DAT_00582474);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f53,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f53,1,0x3c,0,0);
  }
  value1 = UI_AddText(self,0x1f54,0x8a,0x58,s_VERDANA7_fnt_00563ec8,&DAT_005650b4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f54,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f54,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1f55,0x30,0x43,s_VERDANA7_fnt_00563ec8,DAT_00582a40);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f55,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f55,0,0x3c,0,0);
  }
  value1 = UI_AddText(self,0x1f56,0x30,0x4d,s_VERDANA7_fnt_00563ec8,DAT_005828d0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f56,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f56,0,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1f57,0x58,0x43,s_VERDANA7_fnt_00563ec8,&DAT_005650b0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f57,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f57,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1f58,0x58,0x4d,s_VERDANA7_fnt_00563ec8,&DAT_005650bc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f58,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f58,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1f59,0x58,0x58,s_VERDANA7_fnt_00563ec8,&DAT_005650ac);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f59,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f59,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1f5a,0x88,0x83,s_VERDANA10_fnt_00563e64,&DAT_005650a4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f5a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f5a,2,0x32,0,0);
  }
  UI_AddImage(self,0x1f5b,0xb4,0x80,s_PB24_00_spr_00564144,0,0);
  UI_AddImage(self,0x1f5c,0x74,0x80,s_PB22_00_spr_00564174,0,0);
  UI_AddImage(self,0x1f5d,0xd0,0x80,s_PB33_00_spr_00564ba0,0,0);
  value1 = UI_AddText(self,0x1f64,0x31,0xd1,s_VERDANA7_fnt_00563ec8,DAT_00582fb4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f64,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f64,0,0x32,0,0);
  }
  value1 = UI_AddText(self,0x1f65,0xbb,0xd2,s_VERDANA7_fnt_00563ec8,&DAT_005650bc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f65,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f65,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1f66,0x31,0xdb,s_VERDANA7_fnt_00563ec8,DAT_00581ebc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f66,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f66,0,0x3c,0,0);
  }
  value1 = UI_AddText(self,0x1f67,0xbb,0xdc,s_VERDANA7_fnt_00563ec8,&DAT_005650b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f67,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f67,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1f68,0x31,0xe5,s_VERDANA7_fnt_00563ec8,DAT_00582e58);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f68,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f68,0,0x3c,0,0);
  }
  value1 = UI_AddText(self,0x1f69,0xbb,0xe6,s_VERDANA7_fnt_00563ec8,&DAT_005650b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f69,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f69,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1f6a,0x71,0xbd,s_VERDANA7_fnt_00563ec8,DAT_00580cac);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f6a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f6a,1,0x3c,0,0);
  }
  value1 = UI_AddText(self,0x1f6b,0xa8,0xbd,s_VERDANA7_fnt_00563ec8,DAT_00582780);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f6b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f6b,1,0x3c,0,0);
  }
  value1 = UI_AddText(self,0x1f6c,0x84,0xd2,s_VERDANA7_fnt_00563ec8,&DAT_005650b4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f6c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f6c,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1f6d,0x84,0xdc,s_VERDANA7_fnt_00563ec8,&DAT_005650b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f6d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f6d,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1f6e,0x84,0xe6,s_VERDANA7_fnt_00563ec8,&DAT_005650b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f6e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f6e,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1f6f,0x31,199,s_VERDANA7_fnt_00563ec8,DAT_00581b38);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f6f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f6f,0,0x32,0,0);
  }
  value1 = UI_AddText(self,0x1f70,0xbb,200,s_VERDANA7_fnt_00563ec8,&DAT_005650b0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f70,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f70,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1f71,0x84,200,s_VERDANA7_fnt_00563ec8,&DAT_005650b0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f71,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f71,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1f72,0x30,0x112,s_VERDANA7_fnt_00563ec8,DAT_00582724);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f72,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f72,0,0x5f,0,0);
  }
  value1 = UI_AddText(self,0x1f73,0x31,0x11c,s_VERDANA8_fnt_00563e98,s__100_000__00565098);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f73,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f73,0,0x50,0,0);
  }
  value1 = UI_AddTextButton(self,0x1f74,0x8e,0x111,s_VERDANA8_fnt_00563e98,DAT_00581518,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x1f74,0,0,0);
    Gadget_SetButtonTextLayout(self,0x1f74,2,0x54,0,0,0xfffe);
  }
  value1 = UI_AddText(self,0x1f76,0xa2,0x158,s_VERDANA8_fnt_00563e98,&DAT_00564538);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f76,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f76,2,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x1f77,0x82,0x158,s_VERDANA8_fnt_00563e98,&DAT_00565094);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f77,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f77,2,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x1f78,0xc4,0x158,s_VERDANA8_fnt_00563e98,&DAT_00565090);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f78,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f78,2,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x1f7b,0x32,0x157,s_VERDANA8_fnt_00563e98,DAT_00581ebc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f7b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f7b,0,0x50,0,0);
  }
  value1 = UI_AddText(self,0x1f7c,0xa2,0x166,s_VERDANA8_fnt_00563e98,&DAT_0056508c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f7c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f7c,2,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x1f7d,0x82,0x166,s_VERDANA8_fnt_00563e98,&DAT_00564538);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f7d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f7d,2,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x1f7e,0xc4,0x166,s_VERDANA8_fnt_00563e98,&DAT_00565088);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f7e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f7e,2,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x1f7f,0x32,0x165,s_VERDANA8_fnt_00563e98,DAT_00582e58);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f7f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f7f,0,0x50,0,0);
  }
  value1 = UI_AddText(self,0x1f84,0x30,0xfa,s_VERDANA7_fnt_00563ec8,DAT_005828e0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f84,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f84,0,0x5f,0,0);
  }
  value1 = UI_AddText(self,0x1f85,0x31,0x104,s_VERDANA8_fnt_00563e98,s__100_000__00565098);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f85,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f85,0,0x50,0,0);
  }
  value1 = UI_AddTextButton(self,0x1f86,0x8e,0xf9,s_VERDANA8_fnt_00563e98,DAT_00581518,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x1f86,0,0,0);
    Gadget_SetButtonTextLayout(self,0x1f86,2,0x54,0,0,0xfffe);
  }
  value1 = UI_AddText(self,0x1f87,0x32,0x132,s_VERDANA10_fnt_00563e64,DAT_00581b48);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f87,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f87,0,0x73,0,0);
  }
  value1 = UI_AddText(self,0x1f8c,0xbb,0x43,s_VERDANA7_fnt_00563ec8,&DAT_005650b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f8c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f8c,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1f8d,0xbb,0x4d,s_VERDANA7_fnt_00563ec8,&DAT_005650b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f8d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f8d,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1f8e,0xbb,0x58,s_VERDANA7_fnt_00563ec8,&DAT_005650b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f8e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f8e,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1f8f,0x31,0x58,s_VERDANA7_fnt_00563ec8,DAT_005827f0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f8f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f8f,0,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1f93,0x31,0x68,s_VERDANA7_fnt_00563ec8,s__max__HQ4__0056507c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f93,0xff);
    Window_GadgetNotify_Text_SetLayout(self,0x1f93,0,0x3c,0,0);
  }
  value1 = UI_AddText(self,0x1f94,0x8a,0x68,s_VERDANA7_fnt_00563ec8,&DAT_00565078);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f94,0xff);
    Window_GadgetNotify_Text_SetLayout(self,0x1f94,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1f95,0x58,0x68,s_VERDANA7_fnt_00563ec8,&DAT_0056508c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f95,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f95,1,0x28,0,0);
  }
  value1 = UI_AddText(self,0x1f96,0xbb,0x68,s_VERDANA7_fnt_00563ec8,&DAT_00564538);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f96,0xff);
    Window_GadgetNotify_Text_SetLayout(self,0x1f96,1,0x28,0,0);
  }
  UI_AddSprite(self,0x1f97,0xa8,0x142,&DAT_0056450c);
  UI_AddSprite(self,0x1f98,0x87,0x142,s_SCHLAGKRAFT_spr_0056451c);
  UI_AddSprite(self,0x1f99,0xc9,0x142,s_PANZERUNG_spr_005644f8);
  value1 = UI_AddText(self,0x1f9b,0x2f,0x98,s_VERDANA7_fnt_00563ec8,DAT_005817b0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f9b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f9b,0,0x32,0,0);
  }
  value1 = UI_AddText(self,0x1f9c,0x2f,0xa3,s_VERDANA7_fnt_00563ec8,DAT_00580cb4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f9c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f9c,0,0x32,0,0);
  }
  value1 = UI_AddText(self,0x1f9d,0x62,0x98,s_VERDANA7_fnt_00563ec8,s__Filiale_Romana_00565068);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f9d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f9d,0,0x87,0,0);
  }
  value1 = UI_AddText(self,0x1f9e,0x62,0xa3,s_VERDANA7_fnt_00563ec8,&DAT_00565034);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f9e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f9e,0,0x87,0x1a,0);
  }
  value1 = UI_AddTextButton(self,0x1f9f,0xbe,0x22,s_VERDANA8_fnt_00563e98,DAT_00581460,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x1f9f,0,0,0);
    Gadget_SetButtonTextLayout(self,0x1f9f,2,0x28,0,0,0xfffe);
  }
  return self;
}
