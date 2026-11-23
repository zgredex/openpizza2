// EndResultGraph_Fill: ported from Pizza Connection 2 at 0x4c86f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c86f0
#include "pc2_port.h"

void __cdecl EndResultGraph_Fill(void *arg1)

{
  int value1;
  uint32_t uvalue2;
  int value3;
  int value4;
  int *local_108;
  char local_100 [256];
  
  Game_BuildPlayerRankingData(DAT_0057c670,&DAT_0057de00);
  value4 = 0x4be;
  local_108 = &DAT_0057de00;
  value3 = 0x58f;
  do {
    value1 = Game_GetPlayerBySlot(DAT_0057c670,value3 + -0x58f);
    if (value1 == 0) {
      Window_GadgetNotify_Text_SetText(arg1,value4,DAT_00582e4c);
      Window_GadgetNotify_Text_SetText(arg1,value4 + 2,DAT_00582e4c);
      UI_RemoveObjectByKey(arg1,value3);
      UI_RemoveObjectByKey(arg1,value4 + 1);
      UI_RemoveObjectByKey(arg1,value3 + -0xd7);
      *local_108 = 0;
    }
    else {
      Window_GadgetNotify_Text_SetText(arg1,value4,value1 + 8);
      Gadget_SetTextf(arg1,value4 + 2,&DAT_005686f4,*(uint32_t *)(*local_108 + 0x11c));
      String_Format(local_100,(uint8_t *)s_LOGOS__0_d_spr_00568eb8,*(int *)(value1 + 0x1e0) + 1);
      UI_SetButtonSpriteByName(arg1,value3,local_100);
      Window_GadgetNotify_Button_SetState
                (arg1,value3 + -0xd7,(uint32_t)(uint8_t)s__s__s_d_0056acc0[value3 + 1]);
      Window_GadgetNotify_Text_SetTextColor(arg1,value4,*(uint32_t *)(value1 + 0x1dc));
      Window_GadgetNotify_Text_SetTextColor(arg1,value4 + 1,*(uint32_t *)(value1 + 0x1dc));
      Window_GadgetNotify_Text_SetTextColor(arg1,value4 + 2,*(uint32_t *)(value1 + 0x1dc));
    }
    value4 = value4 + 3;
    local_108 = local_108 + 1;
    value1 = value3 + -0x58e;
    value3 = value3 + 1;
  } while (value1 < 6);
  UI_ShowDialog(arg1);
  Window_GadgetNotify_Text_SetText(arg1,0x429,DAT_00582e4c);
  Gadget_SetButtonState(arg1,0x599,1);
  Array_SetField14ByKey(arg1,0x599,0);
  switch(DAT_0057c5c0) {
  case 1:
    Gadget_SetText(arg1,0x597,DAT_00581838);
    uvalue2 = DAT_00581010;
    break;
  case 2:
    Gadget_SetText(arg1,0x597,DAT_00581bfc);
    uvalue2 = DAT_00582848;
    break;
  default:
    goto switchD_004c8892_caseD_3;
  case 4:
    Gadget_SetText(arg1,0x597,DAT_00582ea4);
    uvalue2 = DAT_00581010;
    break;
  case 5:
    Gadget_SetText(arg1,0x597,DAT_00582ea4);
    uvalue2 = DAT_00581010;
    goto LAB_004c893c;
  case 6:
    Gadget_SetText(arg1,0x597,DAT_00581838);
    uvalue2 = DAT_00581010;
    break;
  case 7:
    Gadget_SetText(arg1,0x597,DAT_00581990);
    uvalue2 = DAT_00581074;
LAB_004c893c:
  }
  Gadget_SetText(arg1,0x598,uvalue2);
switchD_004c8892_caseD_3:
  EndResultGraph_SelectCategory(arg1);
  Gadget_SetTextf(arg1,0x583,(uint8_t *)s__d__d_00568ef8,
                  (uint32_t)*(uint8_t *)(*(int *)((intptr_t)DAT_0057c670 + 0x94) + 8));
  return;
}
