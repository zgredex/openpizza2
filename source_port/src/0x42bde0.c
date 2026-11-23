// Window_BuildCompanyProfilePage: ported from Pizza Connection 2 at 0x42bde0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x42bde0
#include "pc2_port.h"


void * __cdecl Window_BuildCompanyProfilePage(int *arg1)

{
  int value1;
  void *self;
  
                    /* Builds the company-profile page. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004a6bd0);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(self,0x408,0x27,0x129,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x501,0x2b,5,s_TIMESFONT_fnt_00563ea8,DAT_00581d38);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x501,0);
    Window_GadgetNotify_Text_SetLayout(self,0x501,2,0xbe,0,0);
  }
  value1 = UI_AddText(self,0x511,0x7d,0x3d,s_VERDANA8_fnt_00563e98,DAT_0058173c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x511,0);
    Window_GadgetNotify_Text_SetLayout(self,0x511,0,0x4b,0,0);
  }
  value1 = UI_AddText(self,0x512,0x7d,0x49,s_VERDANA8_fnt_00563e98,DAT_00581a44);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x512,0);
    Window_GadgetNotify_Text_SetLayout(self,0x512,0,0x41,0,0);
  }
  value1 = UI_AddText(self,0x513,0xae,0x49,s_VERDANA8_fnt_00563e98,&DAT_00564478);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x513,0);
    Window_GadgetNotify_Text_SetLayout(self,0x513,1,0x37,0,0);
  }
  value1 = UI_AddText(self,0x514,0xb3,0x3d,s_VERDANA8_fnt_00563e98,&DAT_00565290);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x514,0);
    Window_GadgetNotify_Text_SetLayout(self,0x514,1,0x32,0,0);
  }
  value1 = UI_AddText(self,0x515,0x7d,0x25,s_VERDANA8_fnt_00563e98,s__Carlos_Estarda_00564468);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x515,0);
    Window_GadgetNotify_Text_SetLayout(self,0x515,0,0x6c,0,0);
  }
  UI_AddSprite(self,0x519,0x27,0xf2,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x51a,0x2d,0xfd,s_VERDANA8_fnt_00563e98,DAT_00582e50);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x51a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x51a,0,0x5a,0,0);
  }
  value1 = UI_AddText(self,0x51b,0x2d,0x116,s_VERDANA8_fnt_00563e98,s__Pizza_Tingeltangel_0056510c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x51b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x51b,0,0x87,0,0);
  }
  UI_AddSprite(self,0x51c,0xb5,0x104,s_LOGORAHMEN_00_spr_005650f8);
  UI_CreateBitmapGadget(self,0x51f,0xb7,0x106,0x2c,0x1d,0x10);
  UI_AddImage(self,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  value1 = UI_AddText(self,0x2330,0x7d,0x54,s_VERDANA8_fnt_00563e98,DAT_00581730);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x2330,0);
    Window_GadgetNotify_Text_SetLayout(self,0x2330,0,0x50,0,0);
  }
  value1 = UI_AddText(self,0x2331,0xae,0x54,s_VERDANA8_fnt_00563e98,&DAT_00565078);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x2331,0);
    Window_GadgetNotify_Text_SetLayout(self,0x2331,1,0x37,0,0);
  }
  value1 = UI_AddText(self,0x2332,0x33,0x93,s_VERDANA8_fnt_00563e98,DAT_00581fa0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x2332,0);
    Window_GadgetNotify_Text_SetLayout(self,0x2332,0,0x50,0,0);
  }
  value1 = UI_AddText(self,0x2333,0x33,0xa2,s_VERDANA8_fnt_00563e98,DAT_00582474);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x2333,0);
    Window_GadgetNotify_Text_SetLayout(self,0x2333,0,0x50,0,0);
  }
  value1 = UI_AddText(self,0x2334,0x33,0xb1,s_VERDANA8_fnt_00563e98,DAT_00581070);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x2334,0);
    Window_GadgetNotify_Text_SetLayout(self,0x2334,0,0x50,0,0);
  }
  value1 = UI_AddText(self,0x2335,0x33,0xc0,s_VERDANA8_fnt_00563e98,DAT_00581138);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x2335,0);
    Window_GadgetNotify_Text_SetLayout(self,0x2335,0,0x50,0,0);
  }
  value1 = UI_AddText(self,0x2336,0x33,0xcf,s_VERDANA8_fnt_00563e98,DAT_005826d0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x2336,0);
    Window_GadgetNotify_Text_SetLayout(self,0x2336,0,0x50,0,0);
  }
  value1 = UI_AddText(self,0x2337,0x33,0xde,s_VERDANA8_fnt_00563e98,DAT_00582ebc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x2337,0);
    Window_GadgetNotify_Text_SetLayout(self,0x2337,0,0x50,0,0);
  }
  value1 = UI_AddText(self,0x2338,0x33,0x6d,s_VEDANA11_fnt_00564090,DAT_00582abc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x2338,0);
    Window_GadgetNotify_Text_SetLayout(self,0x2338,0,0xb4,0,0);
  }
  value1 = UI_AddText(self,0x2339,0x5e,0x86,s_VERDANA7_fnt_00563ec8,DAT_005828e8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x2339,0);
    Window_GadgetNotify_Text_SetLayout(self,0x2339,1,0x32,0,0);
  }
  value1 = UI_AddText(self,0x233a,0x8a,0x86,s_VERDANA7_fnt_00563ec8,DAT_00582ab0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x233a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x233a,1,0x32,0,0);
  }
  value1 = UI_AddText(self,0x233b,0xb4,0x86,s_VERDANA7_fnt_00563ec8,DAT_005828a0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x233b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x233b,1,0x32,0,0);
  }
  value1 = UI_AddText(self,0x233c,0x71,0x93,s_VERDANA8_fnt_00563e98,&DAT_0056528c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x233c,0x6e00);
    Window_GadgetNotify_Text_SetLayout(self,0x233c,1,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x233d,0x71,0xa2,s_VERDANA8_fnt_00563e98,&DAT_005650b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x233d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x233d,1,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x233e,0x71,0xb1,s_VERDANA8_fnt_00563e98,&DAT_00565288);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x233e,0xff);
    Window_GadgetNotify_Text_SetLayout(self,0x233e,1,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x233f,0x71,0xc0,s_VERDANA8_fnt_00563e98,&DAT_00565284);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x233f,0xff);
    Window_GadgetNotify_Text_SetLayout(self,0x233f,1,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x2340,0x71,0xcf,s_VERDANA8_fnt_00563e98,&DAT_005650b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x2340,0);
    Window_GadgetNotify_Text_SetLayout(self,0x2340,1,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x2341,0x71,0xde,s_VERDANA8_fnt_00563e98,&DAT_005650b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x2341,0);
    Window_GadgetNotify_Text_SetLayout(self,0x2341,1,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x2342,0x9b,0x93,s_VERDANA8_fnt_00563e98,&DAT_005650b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x2342,0);
    Window_GadgetNotify_Text_SetLayout(self,0x2342,1,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x2343,0x9b,0xa2,s_VERDANA8_fnt_00563e98,&DAT_00565284);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x2343,0x6e00);
    Window_GadgetNotify_Text_SetLayout(self,0x2343,1,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x2344,0x9b,0xb1,s_VERDANA8_fnt_00563e98,&DAT_005650b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x2344,0);
    Window_GadgetNotify_Text_SetLayout(self,0x2344,1,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x2345,0x9b,0xc0,s_VERDANA8_fnt_00563e98,&DAT_00565284);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x2345,0x6e00);
    Window_GadgetNotify_Text_SetLayout(self,0x2345,1,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x2346,0x9b,0xcf,s_VERDANA8_fnt_00563e98,&DAT_005650b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x2346,0);
    Window_GadgetNotify_Text_SetLayout(self,0x2346,1,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x2347,0x9b,0xde,s_VERDANA8_fnt_00563e98,&DAT_005650b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x2347,0);
    Window_GadgetNotify_Text_SetLayout(self,0x2347,1,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x2348,0xc5,0x93,s_VERDANA8_fnt_00563e98,&DAT_0056528c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x2348,0x6e00);
    Window_GadgetNotify_Text_SetLayout(self,0x2348,1,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x2349,0xc5,0xa2,s_VERDANA8_fnt_00563e98,&DAT_00565284);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x2349,0x6e00);
    Window_GadgetNotify_Text_SetLayout(self,0x2349,1,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x234a,0xc5,0xb1,s_VERDANA8_fnt_00563e98,&DAT_00565288);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x234a,0xff);
    Window_GadgetNotify_Text_SetLayout(self,0x234a,1,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x234b,0xc5,0xc0,s_VERDANA8_fnt_00563e98,&DAT_005650b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x234b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x234b,1,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x234c,0xc5,0xcf,s_VERDANA8_fnt_00563e98,&DAT_005650b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x234c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x234c,1,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x234d,0xc5,0xde,s_VERDANA8_fnt_00563e98,&DAT_005650b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x234d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x234d,1,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x234e,0x33,0x132,s_VEDANA11_fnt_00564090,DAT_00582448);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x234e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x234e,0,0xb4,0,0);
  }
  UI_CreateBitmapGadget(self,0x234f,0x30,0x146,0xa0,0x10,0x10);
  UI_CreateBitmapGadget(self,0x2350,0x30,0x155,0xa0,0x10,0x10);
  UI_CreateBitmapGadget(self,0x2351,0x30,0x164,0xa0,0x10,0x10);
  value1 = UI_AddText(self,0x2352,0xc5,0x148,s_VERDANA8_fnt_00563e98,&DAT_005650b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x2352,0);
    Window_GadgetNotify_Text_SetLayout(self,0x2352,1,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x2353,0xc5,0x157,s_VERDANA8_fnt_00563e98,&DAT_00565078);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x2353,0);
    Window_GadgetNotify_Text_SetLayout(self,0x2353,1,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x2354,0xc5,0x166,s_VERDANA8_fnt_00563e98,&DAT_005650b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x2354,0);
    Window_GadgetNotify_Text_SetLayout(self,0x2354,1,0x1e,0,0);
  }
  UI_AddSprite(self,0x2356,0x34,0x25,s_FOTORAHMEN00_spr_00564310);
  UI_AddSprite(self,0x2357,0x39,0x2a,s_FOTODUMMY00_spr_00564300);
  UI_AddSprite(self,0x2358,0xb7,0x106,s_PLAYLOG_8_01_02_spr_00564744);
  return self;
}
