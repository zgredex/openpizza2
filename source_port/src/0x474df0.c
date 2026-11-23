// Screen_MissionBriefing: ported from Pizza Connection 2 at 0x474df0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x474df0
#include "pc2_port.h"


void * __cdecl Screen_MissionBriefing(int *arg1)

{
  int value1;
  void *self;
  char *cptr2;
  uint32_t local_50;
  uint32_t local_4c;
  uint32_t local_48;
  uint32_t local_44;
  char local_40 [64];
  
  value1 = IDMap_Lookup(&DAT_0057c590,DAT_0057bb40,(int *)0x0);
  if (value1 == 0) {
    value1 = 0;
    cptr2 = s_PE_MISSIONSBRIEFING_LON_tga_00567488;
  }
  else {
    cptr2 = s_PE_MISSIONSBRIEFING__s_tga_005674a4;
  }
  String_Format(local_40,(uint8_t *)cptr2,value1);
  value1 = Window_CreatePictureWindow(DAT_0057c5e0,local_40,&LAB_004cdcb0);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  value1 = UI_AddText(self,0x422,0x260,5,s_TIMESFONT_fnt_00563ea8,DAT_00582b08);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x422,0);
    Window_GadgetNotify_Text_SetLayout(self,0x422,2,0xb4,0,0);
  }
  value1 = UI_AddText(self,0x429,0xe0,0x1fe,s_VERDANA8_fnt_00563e98,s__Online_Hilfetext_005672b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x429,0);
    Window_GadgetNotify_Text_SetLayout(self,0x429,0,0x159,0x50,0);
  }
  value1 = UI_AddText(self,0x42c,0x263,0xcb,s_VERDANA8_fnt_00563e98,s__Missionsbeschreibung_00567470)
  ;
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x42c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x42c,0,0x9b,0x124,0);
  }
  value1 = UI_AddText(self,0x42d,0x260,0x21,s_TIMESFONT_fnt_00563ea8,s__Paris_00565798);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x42d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x42d,2,0xb4,0,0);
  }
  value1 = UI_CreateSlider(self,0x42e,0x30c,0xd4,0x11d,s_SL01_00_spr_0056448c,0,1);
  if (value1 != 0) {
    local_50 = 0;
    local_4c = 0;
    local_48 = 0;
    local_44 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x42e,&local_50);
  }
  value1 = UI_AddTextButton(self,0x433,0x253,0x1fd,s_TIMESFONT_fnt_00563ea8,DAT_00581adc,0,
                           s_TEXTPBTRANSPGELB_00_spr_00567208);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x433,0,0,0x330000);
    Gadget_SetButtonTextLayout(self,0x433,2,0xcc,0,0,0);
  }
  value1 = UI_AddTextButton(self,0x434,0x253,0x226,s_TIMESFONT_fnt_00563ea8,DAT_00580eb8,0,
                           s_TEXTPBTRANSPGRUEN_00_spr_005671ec);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x434,0,0,0);
    Gadget_SetButtonTextLayout(self,0x434,2,0xcc,0,0,0);
  }
  UI_CreateBitmapGadget(self,0x435,0x279,0x3e,0x80,0x7f,0x10);
  UI_AddSprite(self,0x436,0x272,0x36,s_LOGOFENSTER_spr_005671a0);
  return self;
}
