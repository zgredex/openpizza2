// SubMenu_BuildPizzaContestInvitation: ported from Pizza Connection 2 at 0x44cc90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x44cc90
#include "pc2_port.h"


void * __cdecl SubMenu_BuildPizzaContestInvitation(int *arg1)

{
  int value1;
  void *self;
  
                    /* Builds the pizza contest invitation page. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004b9ea0);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  value1 = UI_AddText(self,1000,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_005816b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,1000,0);
    Window_GadgetNotify_Text_SetLayout(self,1000,2,0xbe,0xffff,0);
  }
  UI_AddSprite(self,0x3e9,0x27,0x5c,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x3ea,0x2d,0x23,s_VERDANA7_fnt_00563ec8,DAT_00581524);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3ea,0);
    Window_GadgetNotify_Text_SetLayout(self,0x3ea,0,0xbe,0x37,0);
  }
  value1 = UI_AddText(self,0x3eb,0x2c,0x65,s_VERDANA8_fnt_00563e98,DAT_00582438);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3eb,0);
    Window_GadgetNotify_Text_SetLayout(self,0x3eb,0,0xbe,0xffff,0);
  }
  UI_AddSprite(self,0x3ec,0x27,0x14c,s_TRENNZEILE_spr_00563eb8);
  UI_AddImage(self,0x3ed,0x2d,0x7c,s_PB14_00_spr_005642c4,1,0);
  UI_AddImage(self,0x3ee,0x2d,0x9f,s_PB14_00_spr_005642c4,1,0);
  UI_AddImage(self,0x3ef,0x2d,0xc2,s_PB14_00_spr_005642c4,1,0);
  UI_AddImage(self,0x3f0,0x2d,0xe5,s_PB14_00_spr_005642c4,1,0);
  UI_AddImage(self,0x3f1,0x2d,0x108,s_PB14_00_spr_005642c4,1,0);
  UI_AddImage(self,0x3f2,0x2d,299,s_PB14_00_spr_005642c4,1,0);
  UI_AddSprite(self,0x3f3,0xcd,0x76,s_LOGOS__01_spr_00564f10);
  UI_AddSprite(self,0x3f4,0xcd,0x99,s_LOGOS__02_spr_00564f00);
  UI_AddSprite(self,0x3f5,0xcd,0xbc,s_LOGOS__06_spr_00564ee0);
  UI_AddSprite(self,0x3f6,0xce,0xdf,s_LOGOS__05_spr_00564ef0);
  UI_AddSprite(self,0x3f7,0xce,0x103,s_LOGOS__04_spr_005664bc);
  UI_AddSprite(self,0x3f8,0xcd,0x126,s_LOGOS__07_spr_00564f20);
  value1 = UI_AddTextButton(self,0x3f9,0x30,0x159,s_VERDANA8_fnt_00563e98,DAT_00581ba0,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x3f9,0,0,0);
    Gadget_SetButtonTextLayout(self,0x3f9,2,0xb4,0,0,0xfffe);
  }
  value1 = UI_AddText(self,0x3fa,0x46,0x7a,s_VERDANA8_fnt_00563e98,s__Unternehmensname_00564ac4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3fa,0xff);
    Window_GadgetNotify_Text_SetLayout(self,0x3fa,0,0x8c,0xffff,0);
  }
  value1 = UI_AddText(self,0x400,0x46,0x87,s_VERDANA8_fnt_00563e98,DAT_00582080);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x400,0xff);
    Window_GadgetNotify_Text_SetLayout(self,0x400,0,100,0xffff,0);
  }
  value1 = UI_AddText(self,0x401,0x9f,0x87,s_VERDANA8_fnt_00563e98,&DAT_005664b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x401,0xff);
    Window_GadgetNotify_Text_SetLayout(self,0x401,1,0x32,0xffff,0);
  }
  value1 = UI_AddText(self,0x402,0x46,0x9d,s_VERDANA8_fnt_00563e98,s__Unternehmensname_00564ac4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x402,0xff0055);
    Window_GadgetNotify_Text_SetLayout(self,0x402,0,0x8c,0xffff,0);
  }
  value1 = UI_AddText(self,0x403,0x46,0xaa,s_VERDANA8_fnt_00563e98,DAT_00582080);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x403,0xff0055);
    Window_GadgetNotify_Text_SetLayout(self,0x403,0,100,0xffff,0);
  }
  value1 = UI_AddText(self,0x404,0x9f,0xaa,s_VERDANA8_fnt_00563e98,&DAT_005664b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x404,0xff0055);
    Window_GadgetNotify_Text_SetLayout(self,0x404,1,0x32,0xffff,0);
  }
  value1 = UI_AddText(self,0x405,0x46,0xc0,s_VERDANA8_fnt_00563e98,s__Unternehmensname_00564ac4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x405,0xa0a0);
    Window_GadgetNotify_Text_SetLayout(self,0x405,0,0x8c,0xffff,0);
  }
  value1 = UI_AddText(self,0x406,0x46,0xcd,s_VERDANA8_fnt_00563e98,DAT_00582080);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x406,0xa0a0);
    Window_GadgetNotify_Text_SetLayout(self,0x406,0,100,0xffff,0);
  }
  value1 = UI_AddText(self,0x407,0x9f,0xcd,s_VERDANA8_fnt_00563e98,&DAT_005664b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x407,0xa0a0);
    Window_GadgetNotify_Text_SetLayout(self,0x407,1,0x32,0xffff,0);
  }
  value1 = UI_AddText(self,0x408,0x46,0xe3,s_VERDANA8_fnt_00563e98,s__Unternehmensname_00564ac4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x408,0xae00);
    Window_GadgetNotify_Text_SetLayout(self,0x408,0,0x8c,0xffff,0);
  }
  value1 = UI_AddText(self,0x409,0x46,0xf0,s_VERDANA8_fnt_00563e98,DAT_00582080);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x409,0xae00);
    Window_GadgetNotify_Text_SetLayout(self,0x409,0,100,0xffff,0);
  }
  value1 = UI_AddText(self,0x40a,0x9f,0xf0,s_VERDANA8_fnt_00563e98,&DAT_005664b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x40a,0xae00);
    Window_GadgetNotify_Text_SetLayout(self,0x40a,1,0x32,0xffff,0);
  }
  value1 = UI_AddText(self,0x40b,0x46,0x106,s_VERDANA8_fnt_00563e98,s__Unternehmensname_00564ac4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x40b,0xff00ff);
    Window_GadgetNotify_Text_SetLayout(self,0x40b,0,0x8c,0xffff,0);
  }
  value1 = UI_AddText(self,0x40c,0x46,0x113,s_VERDANA8_fnt_00563e98,DAT_00582080);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x40c,0xff00ff);
    Window_GadgetNotify_Text_SetLayout(self,0x40c,0,100,0xffff,0);
  }
  value1 = UI_AddText(self,0x40d,0x9f,0x113,s_VERDANA8_fnt_00563e98,&DAT_005664b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x40d,0xff00ff);
    Window_GadgetNotify_Text_SetLayout(self,0x40d,1,0x32,0xffff,0);
  }
  value1 = UI_AddText(self,0x40e,0x46,0x129,s_VERDANA8_fnt_00563e98,s__Unternehmensname_00564ac4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x40e,0xffaa00);
    Window_GadgetNotify_Text_SetLayout(self,0x40e,0,0x8c,0xffff,0);
  }
  value1 = UI_AddText(self,0x40f,0x46,0x136,s_VERDANA8_fnt_00563e98,DAT_00582080);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x40f,0xffaa00);
    Window_GadgetNotify_Text_SetLayout(self,0x40f,0,100,0xffff,0);
  }
  value1 = UI_AddText(self,0x410,0x9f,0x136,s_VERDANA8_fnt_00563e98,&DAT_005664b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x410,0xffaa00);
    Window_GadgetNotify_Text_SetLayout(self,0x410,1,0x32,0xffff,0);
  }
  UI_AddImage(self,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  return self;
}
