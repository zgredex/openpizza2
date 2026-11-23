// SubMenu_BuildEndResult: ported from Pizza Connection 2 at 0x46ee80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x46ee80
#include "pc2_port.h"


void * __cdecl SubMenu_BuildEndResult(int *arg1)

{
  int value1;
  void *self;
  
                    /* Creates the end-of-game result screen. */
  value1 = Window_CreatePictureWindow
                    (DAT_0057c5e0,s_Pe_Endergebnis_Grafik_TGA_005672cc,&LAB_004c8ab0);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  value1 = UI_AddText(self,0x420,0xd,5,s_TIMESFONT_fnt_00563ea8,DAT_00580d88);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x420,0);
    Window_GadgetNotify_Text_SetLayout(self,0x420,2,0x230,0,0);
  }
  value1 = UI_AddText(self,0x422,0x260,5,s_TIMESFONT_fnt_00563ea8,DAT_0058245c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x422,0);
    Window_GadgetNotify_Text_SetLayout(self,0x422,2,0xb4,0,0);
  }
  value1 = UI_AddText(self,0x429,0xe0,0x1fe,s_VERDANA8_fnt_00563e98,s__Online_Hilfetext_005672b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x429,0);
    Window_GadgetNotify_Text_SetLayout(self,0x429,0,0x159,0x50,0);
  }
  value1 = UI_AddText(self,0x4a9,0x25f,0x7e,s_TIMES14_fnt_00564788,DAT_00582844);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4a9,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4a9,2,0xb4,0,0);
  }
  UI_AddImage(self,0x4aa,0x2ea,0xce,s_SKBEWERTUNG_00_spr_00566174,1,0);
  UI_AddImage(self,0x4ab,0x2ea,0xa2,s_SKBILANZ_00_spr_00565ad4,1,0);
  UI_AddImage(self,0x4ac,0x266,0xa2,s_SKFILIALE_00_spr_005654fc,1,0);
  UI_AddImage(self,0x4ae,0x2be,0xa2,s_SKPERSO_00_spr_00566154,1,0);
  UI_AddImage(self,0x4af,0x2be,0xce,s_SKSYNDICATE_00_spr_00566140,1,0);
  UI_AddImage(self,0x4b0,0x266,0xcf,s_SKWERBUNG_00_spr_0056612c,1,0);
  UI_AddImage(self,0x4b1,0x292,0xce,s_SKREZEPT_00_spr_0056611c,1,0);
  UI_AddImage(self,0x59b,0x292,0xa2,s_SKSTERN_00_spr_00566164,1,0);
  UI_AddImage(self,0x4b8,0x260,0x123,s_PB14_00_spr_005642c4,1,0);
  UI_AddImage(self,0x4b9,0x260,0x146,s_PB14_00_spr_005642c4,1,0);
  UI_AddImage(self,0x4ba,0x260,0x169,s_PB14_00_spr_005642c4,1,0);
  UI_AddImage(self,0x4bb,0x260,0x18c,s_PB14_00_spr_005642c4,1,0);
  UI_AddImage(self,0x4bc,0x260,0x1af,s_PB14_00_spr_005642c4,1,0);
  UI_AddImage(self,0x4bd,0x260,0x1d2,s_PB14_00_spr_005642c4,1,0);
  value1 = UI_AddText(self,0x4be,0x277,0x122,s_VERDANA8_fnt_00563e98,s__Unternehmensname_00564ac4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4be,0xff);
    Window_GadgetNotify_Text_SetLayout(self,0x4be,0,0x8c,0xffff,0);
  }
  value1 = UI_AddText(self,0x4bf,0x277,0x12e,s_VERDANA8_fnt_00563e98,DAT_00582edc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4bf,0xff);
    Window_GadgetNotify_Text_SetLayout(self,0x4bf,0,0x37,0xffff,0);
  }
  value1 = UI_AddText(self,0x4c0,0x2ae,0x12e,s_VERDANA8_fnt_00563e98,s__16_000_000_00566110);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4c0,0xff);
    Window_GadgetNotify_Text_SetLayout(self,0x4c0,1,0x55,0xffff,0);
  }
  value1 = UI_AddText(self,0x4c1,0x277,0x145,s_VERDANA8_fnt_00563e98,s__Unternehmensname_00564ac4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4c1,0xff00a2);
    Window_GadgetNotify_Text_SetLayout(self,0x4c1,0,0x8c,0xffff,0);
  }
  value1 = UI_AddText(self,0x4c2,0x277,0x151,s_VERDANA8_fnt_00563e98,DAT_00582edc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4c2,0xff00a2);
    Window_GadgetNotify_Text_SetLayout(self,0x4c2,0,0x37,0xffff,0);
  }
  value1 = UI_AddText(self,0x4c3,0x2ae,0x151,s_VERDANA8_fnt_00563e98,s__16_000_000_00566110);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4c3,0xff00a2);
    Window_GadgetNotify_Text_SetLayout(self,0x4c3,1,0x55,0xffff,0);
  }
  value1 = UI_AddText(self,0x4c4,0x277,0x168,s_VERDANA8_fnt_00563e98,s__Unternehmensname_00564ac4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4c4,0xb29e);
    Window_GadgetNotify_Text_SetLayout(self,0x4c4,0,0x8c,0xffff,0);
  }
  value1 = UI_AddText(self,0x4c5,0x277,0x174,s_VERDANA8_fnt_00563e98,DAT_00582edc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4c5,0xb29e);
    Window_GadgetNotify_Text_SetLayout(self,0x4c5,0,0x37,0xffff,0);
  }
  value1 = UI_AddText(self,0x4c6,0x2ae,0x174,s_VERDANA8_fnt_00563e98,s__16_000_000_00566110);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4c6,0xb29e);
    Window_GadgetNotify_Text_SetLayout(self,0x4c6,1,0x55,0xffff,0);
  }
  value1 = UI_AddText(self,0x4c7,0x277,0x18b,s_VERDANA8_fnt_00563e98,s__Unternehmensname_00564ac4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4c7,0x9a00);
    Window_GadgetNotify_Text_SetLayout(self,0x4c7,0,0x8c,0xffff,0);
  }
  value1 = UI_AddText(self,0x4c8,0x277,0x197,s_VERDANA8_fnt_00563e98,DAT_00582edc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4c8,0x9a00);
    Window_GadgetNotify_Text_SetLayout(self,0x4c8,0,0x37,0xffff,0);
  }
  value1 = UI_AddText(self,0x4c9,0x2ae,0x197,s_VERDANA8_fnt_00563e98,s__16_000_000_00566110);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4c9,0x9a00);
    Window_GadgetNotify_Text_SetLayout(self,0x4c9,1,0x55,0xffff,0);
  }
  value1 = UI_AddText(self,0x4ca,0x277,0x1ae,s_VERDANA8_fnt_00563e98,s__Unternehmensname_00564ac4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4ca,0xce00df);
    Window_GadgetNotify_Text_SetLayout(self,0x4ca,0,0x8c,0xffff,0);
  }
  value1 = UI_AddText(self,0x4cb,0x277,0x1ba,s_VERDANA8_fnt_00563e98,DAT_00582edc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4cb,0xce00df);
    Window_GadgetNotify_Text_SetLayout(self,0x4cb,0,0x37,0xffff,0);
  }
  value1 = UI_AddText(self,0x4cc,0x2ae,0x1ba,s_VERDANA8_fnt_00563e98,s__16_000_000_00566110);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4cc,0xce00df);
    Window_GadgetNotify_Text_SetLayout(self,0x4cc,1,0x55,0xffff,0);
  }
  value1 = UI_AddText(self,0x4cd,0x277,0x1d1,s_VERDANA8_fnt_00563e98,s__Unternehmensname_00564ac4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4cd,0xe6e600);
    Window_GadgetNotify_Text_SetLayout(self,0x4cd,0,0x8c,0xffff,0);
  }
  value1 = UI_AddText(self,0x4ce,0x277,0x1dd,s_VERDANA8_fnt_00563e98,DAT_00582edc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4ce,0xe6e600);
    Window_GadgetNotify_Text_SetLayout(self,0x4ce,0,0x37,0xffff,0);
  }
  value1 = UI_AddText(self,0x4cf,0x2ae,0x1dd,s_VERDANA8_fnt_00563e98,s__16_000_000_00566110);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4cf,0xe6e600);
    Window_GadgetNotify_Text_SetLayout(self,0x4cf,1,0x55,0xffff,0);
  }
  value1 = UI_AddTextButton(self,0x4d0,0x265,0xfb,s_VERDANA8_fnt_00563e98,DAT_00580bcc,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x4d0,0,0,0);
    Gadget_SetButtonTextLayout(self,0x4d0,2,0xa9,0,0,0xfffe);
  }
  UI_CreateBitmapGadget(self,0x581,0x2a,0x47,0x1ec,400,0x10);
  value1 = UI_AddText(self,0x582,0x1b,0x2a,s_VERDANA8_fnt_00563e98,s__23000__00566108);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x582,0);
    Window_GadgetNotify_Text_SetLayout(self,0x582,0,0x78,0xffff,0);
  }
  value1 = UI_AddText(self,0x583,0x196,0x1e1,s_VERDANA8_fnt_00563e98,s__Aktuelles_Quartal_005660f4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x583,0);
    Window_GadgetNotify_Text_SetLayout(self,0x583,1,0x96,0xffff,0);
  }
  UI_AddSprite(self,0x58f,0x2ff,0x11d,s_LOGOS__07_spr_00564f20);
  UI_AddSprite(self,0x590,0x2ff,0x141,s_LOGOS__01_spr_00564f10);
  UI_AddSprite(self,0x591,0x2ff,0x164,s_LOGOS__02_spr_00564f00);
  UI_AddSprite(self,0x592,0x2ff,0x185,s_LOGOS__05_spr_00564ef0);
  UI_AddSprite(self,0x593,0x2ff,0x1ab,s_LOGOS__06_spr_00564ee0);
  UI_AddSprite(self,0x594,0x300,0x1ce,s_LOGOS__08_spr_00564ed0);
  value1 = UI_AddTextButton(self,0x597,0x253,0x1fd,s_TIMESFONT_fnt_00563ea8,DAT_00582a88,0,
                           s_TEXTPBTRANSPGELB_00_spr_00567208);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x597,0,0,0);
    Gadget_SetButtonTextLayout(self,0x597,2,0xcc,0,0,0);
  }
  value1 = UI_AddTextButton(self,0x598,0x253,0x227,s_TIMES14_fnt_00564788,DAT_00581b2c,0,
                           s_TEXTPBTRANSPGRUEN_00_spr_005671ec);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x598,0,0,0);
    Gadget_SetButtonTextLayout(self,0x598,2,0xcc,0,0,0);
  }
  value1 = UI_AddTextButton(self,0x599,0x253,0x4e,s_TIMESFONT_fnt_00563ea8,DAT_00581750,0,
                           s_TEXTPBTRANSPGELB_00_spr_00567208);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x599,0,0,0);
    Gadget_SetButtonTextLayout(self,0x599,2,0xcc,0,0,0);
  }
  value1 = UI_AddTextButton(self,0x59a,0x253,0x24,s_TIMESFONT_fnt_00563ea8,DAT_00580b38,0,
                           s_TEXTPBTRANSPGELB_00_spr_00567208);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x59a,0,0,0);
    Gadget_SetButtonTextLayout(self,0x59a,2,0xcc,0,0,0);
  }
  return self;
}
