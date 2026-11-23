// HeadquartersExpansionPage_Create: ported from Pizza Connection 2 at 0x427bb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x427bb0
#include "pc2_port.h"


void * __cdecl HeadquartersExpansionPage_Create(int *arg1)

{
  int value1;
  void *self;
  
                    /* Creates the headquarters expansion page. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004a3060);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(self,0x43c,0x32,0x4b,s_NEWAERGERN_spr_0056500c);
  UI_AddSprite(self,0x43d,0x32,0x6c,s_NEWANGREIFEN_spr_00564ff8);
  UI_AddSprite(self,0x43e,0x32,0x8d,s_NEWBILANZ_spr_00564fe8);
  UI_AddSprite(self,0x43f,0x32,0xae,s_NEWGANGSTER_spr_00564fd8);
  UI_AddSprite(self,0x440,0x32,0xcf,s_NEWINNENARCHI_spr_00564fc4);
  UI_AddSprite(self,0x441,0x32,0x4b,s_NEWKONKURENT_spr_00564fb0);
  UI_AddSprite(self,0x442,0x32,0xae,s_NEWMANAGER_spr_00564fa0);
  UI_AddSprite(self,0x443,0x32,0x6c,s_NEWPOLIZEI_spr_00564f90);
  UI_AddSprite(self,0x444,0x32,0xcf,s_NEWREZEPTAUTO_spr_00564f7c);
  UI_AddSprite(self,0x445,0x32,0x8d,s_NEWSCHUTZ_spr_00564f6c);
  UI_AddSprite(self,0x446,0x32,0x6c,s_NEWWERBUNG_spr_00564f5c);
  UI_AddSprite(self,0x447,0x32,0x4b,s_NEWWETTBEWERB_spr_00564f48);
  UI_AddSprite(self,0x43b,0x2c,0x12a,s_TABHQ_spr_00564f3c);
  UI_AddSprite(self,0x408,0x27,0x129,s_TRENNZEILE_spr_00563eb8);
  UI_AddSprite(self,0x409,0x27,0xf2,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x448,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00582be0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x448,0);
    Window_GadgetNotify_Text_SetLayout(self,0x448,2,0xbe,0,0);
  }
  value1 = UI_AddText(self,0x449,0x2f,0xfe,s_VERDANA8_fnt_00563e98,DAT_00581fc0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x449,0);
    Window_GadgetNotify_Text_SetLayout(self,0x449,0,0x3c,0,0);
  }
  value1 = UI_AddText(self,0x44a,0x2f,0x116,s_VERDANA8_fnt_00563e98,DAT_0058176c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x44a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x44a,0,0x37,0,0);
  }
  value1 = UI_AddText(self,1099,0x2f,0x23,s_VERDANA10_fnt_00563e64,DAT_00582e6c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,1099,0);
    Window_GadgetNotify_Text_SetLayout(self,1099,2,0xb4,0x23,0);
  }
  value1 = UI_AddTextButton(self,0x44d,0x8e,0x112,s_VERDANA8_fnt_00563e98,DAT_00582d84,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x44d,0,0,0);
    Gadget_SetButtonTextLayout(self,0x44d,2,0x54,0,0,0xfffe);
  }
  value1 = UI_AddText(self,0x44f,0x61,0xfe,s_VERDANA8_fnt_00563e98,s__3424__00564f34);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x44f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x44f,1,0x50,0,0);
  }
  value1 = UI_AddText(self,0x450,0x5d,0x116,s_VERDANA8_fnt_00563e98,s__3Tage_00563e7c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x450,0);
    Window_GadgetNotify_Text_SetLayout(self,0x450,1,0x32,0,0);
  }
  value1 = UI_AddText(self,0x451,0x55,0x4b,s_VERDANA8_fnt_00563e98,&DAT_00564f30);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x451,0);
    Window_GadgetNotify_Text_SetLayout(self,0x451,0,0x91,0x21,0);
  }
  value1 = UI_AddText(self,0x456,0x55,0x6d,s_VERDANA8_fnt_00563e98,&DAT_00564f30);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x456,0);
    Window_GadgetNotify_Text_SetLayout(self,0x456,0,0x91,0x21,0);
  }
  value1 = UI_AddText(self,0x457,0x55,0xae,s_VERDANA8_fnt_00563e98,&DAT_00564f30);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x457,0);
    Window_GadgetNotify_Text_SetLayout(self,0x457,0,0x91,0x21,0);
  }
  value1 = UI_AddText(self,0x458,0x55,0x8c,s_VERDANA8_fnt_00563e98,&DAT_00564f30);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x458,0);
    Window_GadgetNotify_Text_SetLayout(self,0x458,0,0x91,0x21,0);
  }
  value1 = UI_AddText(self,0x459,0x54,0xcf,s_VERDANA8_fnt_00563e98,&DAT_00564f30);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x459,0);
    Window_GadgetNotify_Text_SetLayout(self,0x459,0,0x91,0x21,0);
  }
  UI_CreateBitmapGadget(self,0x45a,0x50,0x130,0xf,0x37,0x10);
  UI_CreateBitmapGadget(self,0x45b,0x6a,0x130,0xf,0x37,0x10);
  UI_CreateBitmapGadget(self,0x45c,0x83,0x130,0xf,0x37,0x10);
  UI_CreateBitmapGadget(self,0x45d,0x9d,0x130,0xf,0x37,0x10);
  UI_CreateBitmapGadget(self,0x45e,0xb8,0x130,0xf,0x37,0x10);
  UI_CreateBitmapGadget(self,0x45f,0xd3,0x130,0xf,0x37,0x10);
  UI_AddImage(self,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  UI_AddSprite(self,0x1f41,0x48,0x15d,s_LOGOS__07_spr_00564f20);
  UI_AddSprite(self,0x1f42,0x62,0x15e,s_LOGOS__01_spr_00564f10);
  UI_AddSprite(self,0x1f43,0x7d,0x15d,s_LOGOS__02_spr_00564f00);
  UI_AddSprite(self,0x1f44,0xcc,0x15d,s_LOGOS__05_spr_00564ef0);
  UI_AddSprite(self,0x1f45,0x95,0x15e,s_LOGOS__06_spr_00564ee0);
  UI_AddSprite(self,0x1f46,0xb1,0x15e,s_LOGOS__08_spr_00564ed0);
  return self;
}
