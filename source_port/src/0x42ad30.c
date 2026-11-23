// BauenPage_Create: ported from Pizza Connection 2 at 0x42ad30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x42ad30
#include "pc2_port.h"


void * __cdecl BauenPage_Create(int *arg1)

{
  int value1;
  void *self;
  
                    /* Creates the construct-buildings page. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004a54c0);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(self,0x408,0x27,0x129,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x430,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00581058);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x430,0);
    Window_GadgetNotify_Text_SetLayout(self,0x430,2,0xbe,0,0);
  }
  value1 = UI_AddText(self,0x431,0x2c,0x12e,s_VERDANA7_fnt_00563ec8,DAT_00581098);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x431,0);
    Window_GadgetNotify_Text_SetLayout(self,0x431,2,0xbe,0,0);
  }
  value1 = UI_AddText(self,0x433,0x33,0xf8,s_VERDANA7_fnt_00563ec8,DAT_00580ffc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x433,0);
    Window_GadgetNotify_Text_SetLayout(self,0x433,0,0x23,0,0);
  }
  value1 = UI_AddTextButton(self,0x437,0x8e,0x112,s_VERDANA8_fnt_00563e98,DAT_00582ae4,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x437,0,0,0);
    Gadget_SetButtonTextLayout(self,0x437,2,0x54,0,0,0xfffe);
  }
  value1 = UI_AddText(self,0x439,0x94,0xe8,s_VERDANA8_fnt_00563e98,s__21321__0056524c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x439,0);
    Window_GadgetNotify_Text_SetLayout(self,0x439,1,0x50,0,0);
  }
  value1 = UI_AddText(self,0x43a,0x46,0xf8,s_VERDANA7_fnt_00563ec8,s__21Tage_00565244);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x43a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x43a,1,0x37,0,0);
  }
  UI_AddSprite(self,0x43f,0x2f,0x13a,s_TAB01xxx_spr_00565234);
  UI_AddImage(self,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  UI_AddImage(self,0x1f68,0x31,0x26,s_BAUENPB__00_spr_00565224,0,0);
  UI_AddImage(self,0x1f69,0x8b,0x26,s_BAUENPB__00_spr_00565224,0,0);
  UI_AddImage(self,0x1f6a,0x31,0x70,s_BAUENPB__00_spr_00565224,0,0);
  UI_AddImage(self,0x1f6b,0x8b,0x70,s_BAUENPB__00_spr_00565224,0,0);
  value1 = UI_AddText(self,0x1f61,0x96,0xf8,s_VERDANA7_fnt_00563ec8,DAT_00581c54);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f61,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f61,0,0x23,0,0);
  }
  value1 = UI_AddText(self,0x1f62,0x33,0x103,s_VERDANA7_fnt_00563ec8,DAT_005824b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f62,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f62,0,0x82,0,0);
  }
  value1 = UI_AddText(self,0x1f63,0xad,0xf8,s_VERDANA7_fnt_00563ec8,s__21321__0056524c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f63,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f63,1,0x37,0,0);
  }
  value1 = UI_AddText(self,0x1f64,0xad,0x103,s_VERDANA7_fnt_00563ec8,s__20000__0056521c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f64,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f64,1,0x37,0,0);
  }
  value1 = UI_AddText(self,0x1f65,0x33,0xe8,s_VERDANA8_fnt_00563e98,DAT_005816a8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f65,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f65,0,0x6e,0,0);
  }
  value1 = UI_AddText(self,0x1f66,0x33,0xec,s_VERDANA7_fnt_00563ec8,
                     s__________________________________005651dc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f66,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f66,0,0xb1,0,0);
  }
  value1 = UI_AddText(self,0x1f67,0x33,0xba,s_VERDANA7_fnt_00563ec8,&DAT_005651c4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f67,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f67,0,0xb4,0x28,0);
  }
  UI_AddSprite(self,0x1f79,0x8b,0x71,s_MG_H_POLIZEI_spr_005651b0);
  UI_AddSprite(self,0x1f7a,0x31,0x26,s_MG_H_PIZZ_A7_spr_0056519c);
  UI_AddSprite(self,0x1f7b,0x8b,0x25,s_MG_H_LAGER_A7_spr_00565188);
  UI_AddSprite(self,0x1f7c,0x32,0x71,s_MG_H_HQ_A7_spr_00565178);
  return self;
}
