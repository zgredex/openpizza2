// EndResults_RefreshScreen: ported from Pizza Connection 2 at 0x4ca880.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ca880
#include "pc2_port.h"

void __cdecl EndResults_RefreshScreen(void *arg1)

{
  int value1;
  int value2;
  int value3;
  uint32_t uvalue4;
  int value5;
  int value6;
  int value7;
  int local_10c;
  int local_108;
  int *local_104;
  char local_100 [256];
  
  Game_BuildPlayerRankingData(DAT_0057c670,&DAT_0057de18);
  value5 = 0x4be;
  local_104 = &DAT_0057de18;
  local_108 = 0x4fa;
  value6 = 0x5a8;
  do {
    value2 = Game_GetPlayerBySlot(DAT_0057c670,value6 + -0x5a8);
    if (value2 == 0) {
      UI_RemoveObjectByKey(arg1,value6);
      UI_RemoveObjectByKey(arg1,value6 + -0xb);
      local_10c = 6;
      value2 = local_108 + -0x24;
      do {
        UI_RemoveObjectByKey(arg1,value2);
        value2 = value2 + 1;
        local_10c = local_10c + -1;
      } while (local_10c != 0);
      local_10c = 6;
      value2 = local_108;
      do {
        UI_RemoveObjectByKey(arg1,value2);
        value2 = value2 + 1;
        local_10c = local_10c + -1;
      } while (local_10c != 0);
      local_10c = 6;
      value2 = local_108 + 0x24;
      do {
        UI_RemoveObjectByKey(arg1,value2);
        value2 = value2 + 1;
        local_10c = local_10c + -1;
      } while (local_10c != 0);
      local_10c = 6;
      value2 = local_108 + 0x48;
      do {
        UI_RemoveObjectByKey(arg1,value2);
        value2 = value2 + 1;
        local_10c = local_10c + -1;
      } while (local_10c != 0);
      *local_104 = 0;
      UI_RemoveObjectByKey(arg1,value5 + 1);
      Window_GadgetNotify_Text_SetText(arg1,value5,DAT_00582e4c);
      Window_GadgetNotify_Text_SetText(arg1,value5 + 2,DAT_00582e4c);
      UI_RemoveObjectByKey(arg1,value6 + -0x1f);
    }
    else {
      Window_GadgetNotify_Text_SetText(arg1,value5,value2 + 8);
      Gadget_SetTextf(arg1,value5 + 2,&DAT_005686f4,*(uint32_t *)(*local_104 + 0x11c));
      value1 = *(int *)(value2 + 0x1e0);
      value7 = value6;
      value3 = Game_FindCityIndex(value2);
      UI_SetPlayerLogoSprite(arg1,value1,value3,value7);
      String_Format(local_100,(uint8_t *)s_LOGOS__0_d_spr_00568eb8,*(int *)(value2 + 0x1e0) + 1);
      UI_SetButtonSpriteByName(arg1,value6 + -0x1f,local_100);
      Window_GadgetNotify_Text_SetTextColor(arg1,value5,*(uint32_t *)(value2 + 0x1dc));
      Window_GadgetNotify_Text_SetTextColor(arg1,value5 + 1,*(uint32_t *)(value2 + 0x1dc));
      Window_GadgetNotify_Text_SetTextColor(arg1,value5 + 2,*(uint32_t *)(value2 + 0x1dc));
    }
    local_108 = local_108 + 6;
    local_104 = local_104 + 1;
    value5 = value5 + 3;
    value2 = value6 + -0x5a7;
    value6 = value6 + 1;
  } while (value2 < 6);
  UI_ShowPanel(arg1);
  Window_GadgetNotify_Text_SetText(arg1,0x429,DAT_00582e4c);
  Gadget_SetButtonState(arg1,0x5a6,1);
  Array_SetField14ByKey(arg1,0x5a6,0);
  switch(DAT_0057c5c0) {
  case 1:
    Gadget_SetText(arg1,0x5a3,DAT_00581838);
    uvalue4 = DAT_00581010;
    break;
  case 2:
    Gadget_SetText(arg1,0x5a3,DAT_00581bfc);
    uvalue4 = DAT_00582848;
    break;
  default:
    goto switchD_004caad2_caseD_3;
  case 4:
    uvalue4 = DAT_00582ea4;
    goto LAB_004cab38;
  case 5:
    Gadget_SetText(arg1,0x5a3,DAT_00582ea4);
    uvalue4 = DAT_00581010;
    goto LAB_004cab66;
  case 6:
    uvalue4 = DAT_00581838;
LAB_004cab38:
    Gadget_SetText(arg1,0x5a3,uvalue4);
    uvalue4 = DAT_00581010;
    break;
  case 7:
    Gadget_SetText(arg1,0x5a3,DAT_00581990);
    uvalue4 = DAT_00581074;
LAB_004cab66:
  }
  Gadget_SetText(arg1,0x5a4,uvalue4);
switchD_004caad2_caseD_3:
  if (DAT_0056b270 == -1) {
    Gadget_SetButtonState(arg1,0x4d0,1);
    EndResultPoints_FillOverview(arg1);
    return;
  }
  Window_GadgetNotify_Button_SetState(arg1,(&DAT_0056b274)[DAT_0056b270],1);
  switch(DAT_0056b270) {
  case 0:
    EndResultPoints_FillBuildingTable(arg1);
    return;
  case 1:
    EndResultPoints_FillMissionTable(arg1);
    return;
  case 2:
    EndResultPoints_FillPersonnelTable(arg1);
    return;
  case 3:
    EndResults_FillBalancePage(arg1);
    return;
  case 4:
    EndResults_FillAdvertisingPage(arg1);
    return;
  case 5:
    EndResults_FillRecipePage(arg1);
    return;
  case 6:
    EndResults_FillSyndicatePage(arg1);
    return;
  case 7:
    EndResults_FillRatingPage(arg1);
  }
  return;
}
