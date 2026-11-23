// UI_CreateScrollListWindow: ported from Pizza Connection 2 at 0x46cc70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x46cc70
#include "pc2_port.h"

void * __cdecl UI_CreateScrollListWindow(int *arg1)

{
  int value1;
  void *self;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
                    /* Creates the reusable scroll-list picker window. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,IngredientMenu_HandleInput
                         );
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddImage(self,0x444,0x2f,0x38,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x445,0x2f,0x4d,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x446,0x2f,0x62,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x447,0x2f,0x77,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x448,0x2f,0x8c,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x449,0x2f,0xa1,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x44a,0x2f,0xb6,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,1099,0x2f,0xcb,s_TABPB01__00_spr_00564670,1,0);
  UI_AddSprite(self,0x429,0x27,0x14c,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x440,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00582f58);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x440,0);
    Window_GadgetNotify_Text_SetLayout(self,0x440,2,0xbe,0,0);
  }
  value1 = UI_AddText(self,0x441,0x32,0x26,s_VERDANA10_fnt_00563e64,s__Zutaten_aussuchen__00566e48);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x441,0);
    Window_GadgetNotify_Text_SetLayout(self,0x441,0,0xb4,0,0);
  }
  value1 = UI_CreateSlider(self,0x42d,0xdc,0x40,0x109,s_SL01_00_spr_0056448c,0,1);
  if (value1 != 0) {
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x42d,&local_10);
  }
  value1 = UI_AddTextButton(self,0x443,0x30,0x15b,s_VERDANA8_fnt_00563e98,DAT_00582ae4,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x443,0,0,0);
    Gadget_SetButtonTextLayout(self,0x443,2,0x54,0,0,0xfffe);
  }
  UI_AddImage(self,0x44c,0x2f,0xe0,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x44d,0x2f,0xf5,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x44e,0x2f,0x10a,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x44f,0x2f,0x11f,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x450,0x2f,0x134,s_TABPB01__00_spr_00564670,1,0);
  value1 = UI_AddText(self,0x451,0x32,0x3b,s_VERDANA10_fnt_00563e64,s__Tomaten_00564be4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x451,0);
    Window_GadgetNotify_Text_SetLayout(self,0x451,0,0x9b,0,0);
  }
  value1 = UI_AddText(self,0x452,0x32,0x50,s_VERDANA10_fnt_00563e64,s__Tomaten_00564be4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x452,0);
    Window_GadgetNotify_Text_SetLayout(self,0x452,0,0x9b,0,0);
  }
  value1 = UI_AddText(self,0x453,0x32,0x65,s_VERDANA10_fnt_00563e64,s__Tomaten_00564be4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x453,0);
    Window_GadgetNotify_Text_SetLayout(self,0x453,0,0x9b,0,0);
  }
  value1 = UI_AddText(self,0x454,0x32,0x7a,s_VERDANA10_fnt_00563e64,s__Tomaten_00564be4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x454,0);
    Window_GadgetNotify_Text_SetLayout(self,0x454,0,0x9b,0,0);
  }
  value1 = UI_AddText(self,0x455,0x32,0x8f,s_VERDANA10_fnt_00563e64,s__Tomaten_00564be4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x455,0);
    Window_GadgetNotify_Text_SetLayout(self,0x455,0,0x9b,0,0);
  }
  value1 = UI_AddText(self,0x456,0x32,0xa4,s_VERDANA10_fnt_00563e64,s__Tomaten_00564be4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x456,0);
    Window_GadgetNotify_Text_SetLayout(self,0x456,0,0x9b,0,0);
  }
  value1 = UI_AddText(self,0x457,0x32,0xb9,s_VERDANA10_fnt_00563e64,s__Tomaten_00564be4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x457,0);
    Window_GadgetNotify_Text_SetLayout(self,0x457,0,0x9b,0,0);
  }
  value1 = UI_AddText(self,0x458,0x32,0xce,s_VERDANA10_fnt_00563e64,s__Tomaten_00564be4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x458,0);
    Window_GadgetNotify_Text_SetLayout(self,0x458,0,0x9b,0,0);
  }
  value1 = UI_AddText(self,0x459,0x32,0xe3,s_VERDANA10_fnt_00563e64,s__Tomaten_00564be4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x459,0);
    Window_GadgetNotify_Text_SetLayout(self,0x459,0,0x9b,0,0);
  }
  value1 = UI_AddText(self,0x45a,0x32,0xf8,s_VERDANA10_fnt_00563e64,s__Tomaten_00564be4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x45a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x45a,0,0x9b,0,0);
  }
  value1 = UI_AddText(self,0x45b,0x32,0x10d,s_VERDANA10_fnt_00563e64,s__Tomaten_00564be4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x45b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x45b,0,0x9b,0,0);
  }
  value1 = UI_AddText(self,0x45c,0x32,0x122,s_VERDANA10_fnt_00563e64,s__Tomaten_00564be4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x45c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x45c,0,0x9b,0,0);
  }
  value1 = UI_AddText(self,0x45d,0x32,0x137,s_VERDANA10_fnt_00563e64,s__Tomaten_00564be4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x45d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x45d,0,0x9b,0,0);
  }
  return self;
}
