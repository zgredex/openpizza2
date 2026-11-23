// CompanyRating_InitCompanyList: ported from Pizza Connection 2 at 0x49cf90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49cf90
#include "pc2_port.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl CompanyRating_InitCompanyList(void *arg1)

{
  int value1;
  int value2;
  int *ptr3;
  int value4;
  uint8_t local_100 [256];
  
                    /* Populates the company rating rows and selected score. */
  value1 = Game_GetPlayerBySlot(DAT_0057c670,DAT_0057cab4);
  _DAT_0057ca98 = *(int *)(value1 + 0x1d4);
  UI_QueueControlCommand(*(void **)((intptr_t)DAT_0057c670 + 0x25c),-0x18670,0x23,_DAT_0057ca98);
  UI_Group_ClearAll((intptr_t)arg1);
  UI_Group_Create(arg1,0,6,0x1f41);
  Window_GadgetNotify_Button_SetState(arg1,0x1f41,1);
  value1 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                       (int *)0x0);
  String_Format(local_100,DAT_00582e3c,(&DAT_005834d4)[*(int *)(value1 + 0x1148)]);
  Window_GadgetNotify_Text_SetText(arg1,0x45d,local_100);
  value1 = 0;
  ptr3 = &DAT_0057ca9c;
  do {
    value2 = Game_GetPlayerBySlot(DAT_0057c670,value1);
    if ((value2 != 0) && (*(int *)(value2 + 0x50) == 0)) {
      *ptr3 = value2;
      ptr3 = ptr3 + 1;
    }
    value1 = value1 + 1;
  } while (value1 < 6);
  value2 = 0;
  value1 = 0x45f;
  do {
    if (*(int *)((intptr_t)&DAT_0057ca9c + value2) == 0) {
      UI_RemoveObjectByKey(arg1,value1);
      UI_RemoveObjectByKey(arg1,*(int *)((intptr_t)&DAT_00568aac + value2));
      value4 = 0;
      do {
        UI_RemoveObjectByKey(arg1,*(int *)((intptr_t)&DAT_00568a94 + value2) + value4);
        value4 = value4 + 1;
      } while (value4 < 0x12);
    }
    else {
      UI_ShowChildByID(arg1,value1);
      Window_GadgetNotify_Text_SetTextColor
                (arg1,value1,*(uint32_t *)(*(int *)((intptr_t)&DAT_0057ca9c + value2) + 0x1dc));
      Window_GadgetNotify_Text_SetText(arg1,value1,*(int *)((intptr_t)&DAT_0057ca9c + value2) + 8);
      UI_ShowChildByID(arg1,*(int *)((intptr_t)&DAT_00568aac + value2));
      value4 = 0;
      do {
        UI_RemoveObjectByKey(arg1,*(int *)((intptr_t)&DAT_00568a94 + value2) + value4);
        value4 = value4 + 1;
      } while (value4 < 0x12);
    }
    value2 = value2 + 4;
    value4 = value1 + -0x45e;
    value1 = value1 + 1;
  } while (value4 < 6);
  CompanyRating_UpdateScoreText(arg1);
  return;
}
