// AdvertisingPage_FillCampaign: ported from Pizza Connection 2 at 0x4c5a60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c5a60
#include "pc2_port.h"


void __cdecl AdvertisingPage_FillCampaign(void *arg1)

{
  uint32_t uvalue1;
  int value2;
  void *self;
  uint32_t uvalue3;
  int value4;
  int value5;
  char *cptr6;
  char local_100 [256];
  
                    /* Fills the advertising page from the active campaign. */
  UI_SetPosition(arg1,&LAB_004c58d0,0);
  DAT_0057dcfc = *(int *)((intptr_t)DAT_0057c670 + 0x21c);
  Sound_ProcessEvent(DAT_0057ba0c,*(int *)(DAT_0057dcfc + 0x30),0,*(int *)(DAT_0057dcfc + 0x24) == 0
                    );
  Window_GadgetNotify_Text_SetText(arg1,0x4bf,DAT_0057dcfc + 4);
  value4 = 0x4c0;
  do {
    Window_GadgetNotify_Slider_SetRange(arg1,value4,100,0,0);
    value4 = value4 + 2;
  } while (value4 < 0x4cc);
  value4 = *(int *)(DAT_0057dcfc + 0x30);
  if (value4 == 0xb) {
    uvalue3 = DAT_005812a4;
LAB_004c5b24:
  }
  else {
    uvalue3 = DAT_005820e8;
    if ((value4 != 0xf) && (value4 != 0x21)) {
      uvalue3 = (&DAT_005834d4)[*(int *)(DAT_0057dcfc + 0x34)];
      goto LAB_004c5b24;
    }
  }
  Window_GadgetNotify_Text_SetText(arg1,0x469,uvalue3);
  BranchWindow_InitCompetitorRows(arg1);
  uvalue1 = Game_GetTimeSegment((intptr_t)DAT_0057c670);
  value4 = uvalue1 - 1;
  if (value4 < 0) {
    value4 = 7;
  }
  value4 = *(int *)(DAT_0057dcfc + 0xd4 + value4 * 4);
  if (value4 != 0) {
    Submenu_SetObjectPicture(arg1,*(int *)(value4 + 0x20),2,0x1f4f,-1,value4);
  }
  uvalue1 = Game_GetTimeSegment((intptr_t)DAT_0057c670);
  value4 = *(int *)(DAT_0057dcfc + 0xd4 + uvalue1 * 4);
  if (value4 != 0) {
    Submenu_SetObjectPicture(arg1,*(int *)(value4 + 0x20),2,0x1f50,-1,value4);
  }
  value4 = *(int *)(DAT_0057dcfc + 0x30);
  if (value4 == 0xb) {
    cptr6 = s_fatman_0056b090;
  }
  else if (value4 == 0xf) {
    cptr6 = s_promi_0056b088;
  }
  else {
    if (value4 == 0x21) {
      String_Format(local_100,(uint8_t *)s_M__s_spr_0056b05c,s_wissenschaftler_0056b068);
      goto LAB_004c5c20;
    }
    cptr6 = (&PTR_DAT_0056b000)[*(int *)(DAT_0057dcfc + 0x34)];
  }
  String_Format(local_100,(uint8_t *)s_M__s__s01_spr_0056b078,cptr6);
LAB_004c5c20:
  UI_SetButtonSpriteByName(arg1,0x1f51,local_100);
  value5 = 0;
  value4 = 0x4c1;
  do {
    value2 = Game_GetPlayerBySlot(DAT_0057c670,value5);
    if (value2 == 0) {
      UI_RemoveObjectByKey(arg1,value5 + 0x1f49);
      UI_RemoveObjectByKey(arg1,value4 + -1);
      UI_RemoveObjectByKey(arg1,value4);
      UI_RemoveObjectByKey(arg1,(&DAT_0056afb8)[value5]);
      UI_RemoveObjectByKey(arg1,(&DAT_0056afd0)[value5]);
    }
    else {
      String_Format(local_100,(uint8_t *)s_LOGOS__0_d_spr_00568eb8,*(int *)(value2 + 0x1e0) + 1);
      UI_SetButtonSpriteByName(arg1,value5 + 0x1f49,local_100);
    }
    value4 = value4 + 2;
    value5 = value5 + 1;
  } while (value4 < 0x4cd);
  if (*(int *)(DAT_0057dcfc + 0x74) == 0) {
    Rating_UpdateBarByKey(arg1,0x47a,-1,0,0);
    Rating_UpdateBarByKey(arg1,0x48b,-1,0,0);
    Rating_UpdateBarByKey(arg1,0x49c,-1,0,0);
    Rating_UpdateBarByKey(arg1,0x4ad,-1,0,0);
    return;
  }
  value4 = *(int *)(*(int *)(DAT_0057dcfc + 0xf4) + 0x2c);
  value5 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(*(int *)(DAT_0057dcfc + 0xf4) + 8));
  self = (void *)IDMap_Lookup((void *)(value5 + 0x148),value4,(int *)0x0);
  value4 = Stats_GetAverage8(self,*(int *)(DAT_0057dcfc + 0x34));
  Rating_UpdateBarByKey(arg1,0x47a,-1,value4,DAT_005826d8);
  value4 = Branch_ComputeBuildingRating(self,DAT_0057dcfc,*(int *)(DAT_0057dcfc + 0x34));
  Rating_UpdateBarByKey(arg1,0x48b,-1,value4,DAT_00582320);
  value4 = Branch_GetMenuRating(self,*(int *)(DAT_0057dcfc + 0x34));
  Rating_UpdateBarByKey(arg1,0x49c,-1,value4,DAT_0058271c);
  value4 = Branch_GetPriceRating(self,*(int *)(DAT_0057dcfc + 0x34));
  Rating_UpdateBarByKey(arg1,0x4ad,-1,value4,DAT_005827b8);
  return;
}
