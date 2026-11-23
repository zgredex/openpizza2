// SubMenu_BuildLoadSavegame: ported from Pizza Connection 2 at 0x426200.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x426200
#include "pc2_port.h"


void * __cdecl SubMenu_BuildLoadSavegame(int *arg1)

{
  int value1;
  void *self;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
                    /* Builds the load-savegame page. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004a0da0);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddImage(self,0x444,0x34,0x38,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x445,0x34,0x4d,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x446,0x34,0x62,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x447,0x34,0x77,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x448,0x34,0x8c,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x449,0x34,0xa1,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x44a,0x34,0xb6,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,1099,0x34,0xcb,s_TABPB01__00_spr_00564670,1,0);
  value1 = UI_AddText(self,0x440,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00582470);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x440,0);
    Window_GadgetNotify_Text_SetLayout(self,0x440,2,0xbe,0,0);
  }
  value1 = UI_AddText(self,0x441,0x33,0x27,s_VERDANA8_fnt_00563e98,DAT_00581db8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x441,0);
    Window_GadgetNotify_Text_SetLayout(self,0x441,0,0xb4,0,0);
  }
  UI_AddImage(self,0x44c,0x34,0xe0,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x44d,0x34,0xf5,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x44e,0x34,0x10a,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x44f,0x34,0x11f,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x450,0x34,0x134,s_TABPB01__00_spr_00564670,1,0);
  value1 = UI_AddText(self,0x453,0x39,0x3c,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x453,0);
    Window_GadgetNotify_Text_SetLayout(self,0x453,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x454,0x39,0x51,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x454,0);
    Window_GadgetNotify_Text_SetLayout(self,0x454,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x455,0x39,0x66,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x455,0);
    Window_GadgetNotify_Text_SetLayout(self,0x455,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x456,0x39,0x7b,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x456,0);
    Window_GadgetNotify_Text_SetLayout(self,0x456,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x457,0x39,0x90,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x457,0);
    Window_GadgetNotify_Text_SetLayout(self,0x457,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x458,0x39,0xa5,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x458,0);
    Window_GadgetNotify_Text_SetLayout(self,0x458,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x459,0x39,0xba,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x459,0);
    Window_GadgetNotify_Text_SetLayout(self,0x459,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x45a,0x39,0xcf,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x45a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x45a,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x45b,0x39,0xe4,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x45b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x45b,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x45c,0x39,0xf9,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x45c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x45c,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x45d,0x39,0x10e,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x45d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x45d,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x45e,0x39,0x123,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x45e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x45e,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0x45f,0x39,0x138,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x45f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x45f,0,0x96,0,0);
  }
  value1 = UI_CreateSlider(self,0x462,0xde,0x3e,0x109,s_SL01_00_spr_0056448c,0,1);
  if (value1 != 0) {
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x462,&local_10);
  }
  UI_AddImage(self,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  UI_AddSprite(self,0x1f41,0x27,0x14c,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddTextButton(self,0x1f42,0x30,0x15b,s_VERDANA8_fnt_00563e98,DAT_00582748,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x1f42,0,0,0);
    Gadget_SetButtonTextLayout(self,0x1f42,2,0xb4,0,0,0xfffe);
  }
  return self;
}
