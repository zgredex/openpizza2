// CompanyList_InitCompanyRows: ported from Pizza Connection 2 at 0x4b9c90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4b9c90
#include "pc2_port.h"

void __cdecl CompanyList_InitCompanyRows(void *arg1)

{
  void *pvVar1;
  int value2;
  int value3;
  int value4;
  int value5;
  uint32_t uvalue6;
  int value7;
  int local_44;
  char local_3c [28];
  uint8_t local_20 [32];
  
                    /* Fills company-list rows with logos, names, and values. */
  value2 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x9c) + 0x30));
  local_44 = 0x401;
  value7 = 0;
  value5 = 0x3f3;
  do {
    value3 = Game_GetPlayerBySlot(DAT_0057c670,value5 + -0x3f3);
    if (value3 == 0) {
LAB_004b9de2:
      uvalue6 = DAT_00582e4c;
      *(uint32_t *)((intptr_t)&DAT_0057d6d0 + value7) = 0;
      Window_GadgetNotify_Text_SetText(arg1,*(int *)((intptr_t)&DAT_0056a950 + value7),uvalue6);
      Window_GadgetNotify_Text_SetText(arg1,local_44,DAT_00582e4c);
      Window_GadgetNotify_Text_SetText(arg1,local_44 + -1,DAT_00582e4c);
      UI_RemoveObjectByKey(arg1,value5 + -6);
      UI_RemoveObjectByKey(arg1,value5);
    }
    else {
      value4 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
      if (value5 + -0x3f3 == value4) goto LAB_004b9de2;
      if (value5 + -0x3f3 == *(int *)(value2 + 0x48)) {
        *(uint32_t *)((intptr_t)&DAT_0057d6d0 + value7) = 1;
      }
      else {
        *(uint32_t *)((intptr_t)&DAT_0057d6d0 + value7) = 0;
      }
      Window_GadgetNotify_Text_SetText(arg1,*(int *)((intptr_t)&DAT_0056a950 + value7),value3 + 8);
      Window_GadgetNotify_Text_SetTextColor
                (arg1,*(int *)((intptr_t)&DAT_0056a950 + value7),*(uint32_t *)(value3 + 0x1dc));
      String_Format(local_20,&DAT_0056a968,*(uint32_t *)(value3 + 0x54));
      Window_GadgetNotify_Text_SetText(arg1,local_44,local_20);
      Window_GadgetNotify_Text_SetTextColor(arg1,local_44,*(uint32_t *)(value3 + 0x1dc));
      Window_GadgetNotify_Text_SetTextColor(arg1,local_44 + -1,*(uint32_t *)(value3 + 0x1dc));
      UI_ShowChildByID(arg1,value5 + -6);
      UI_ShowChildByID(arg1,value5);
      String_Format(local_3c,(uint8_t *)s_LOGOS__0_d_spr_00568eb8,*(int *)(value3 + 0x1e0) + 1);
      UI_SetButtonSpriteByName(arg1,value5,local_3c);
      Window_GadgetNotify_Button_SetState
                (arg1,value5 + -6,(uint32_t)(*(int *)((intptr_t)&DAT_0057d6d0 + value7) == 1));
    }
    value7 = value7 + 4;
    local_44 = local_44 + 3;
    value3 = value5 + -0x3f2;
    value5 = value5 + 1;
    if (5 < value3) {
      value5 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
      pvVar1 = DAT_0057c670;
      (&DAT_0057d6d0)[value5] = 1;
      uvalue6 = Game_HasIdleOtherPlayer(pvVar1);
      if ((char)uvalue6 == '\0') {
        UI_ShowChildByID(arg1,0x3f9);
        return;
      }
      UI_RemoveObjectByKey(arg1,0x3f9);
      return;
    }
  } while( true );
}
