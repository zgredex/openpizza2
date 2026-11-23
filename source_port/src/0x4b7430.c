// AttacksPage_FillProtectionMoney: ported from Pizza Connection 2 at 0x4b7430.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4b7430
#include "pc2_port.h"

void __cdecl AttacksPage_FillProtectionMoney(void *arg1)

{
  void *self;
  int value1;
  int value2;
  int value3;
  int value4;
  int value5;
  uint32_t uvalue6;
  
                    /* Fills the attacks tab's protection-money contract and costs. */
  value5 = *(int *)((intptr_t)DAT_0057c670 + 0x9c);
  self = *(void **)(*(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200) +
                   0x1d8);
  value2 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(value5 + 0x30));
  value1 = *(int *)(value2 + 0x48);
  uvalue6 = 100000;
  value3 = *(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8);
  if (*(int *)(value3 + 0x158) == 0) {
    if (*(int *)(value3 + 0x23c) != 0) {
      uvalue6 = 150000;
    }
  }
  else {
    uvalue6 = 0;
  }
  Gadget_SetTextf(arg1,0x1fb4,&DAT_005683a4,uvalue6);
  if (self == (void *)0x0) {
    value3 = 0;
    uvalue6 = 0xff;
  }
  else {
    value3 = Game_CountFreeBuildingsByType(self,0x1f);
    if (value3 == 0) {
      uvalue6 = 0xff;
    }
    else {
      uvalue6 = 0;
    }
  }
  Window_GadgetNotify_Text_SetTextColor(arg1,0x1fd6,uvalue6);
  Gadget_SetTextf(arg1,0x1fd6,&DAT_005686f4,value3);
  value3 = Game_CountPlayerObjectsByType
                    (*(void **)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200)
                     ,value5,0x1f,0x11);
  Gadget_SetTextf(arg1,0x1fb8,&DAT_005686f4,value3);
  value3 = *(int *)(value5 + 0x16f0);
  value4 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  value3 = Game_CountFilteredObjects(DAT_0057c670,0x11,0x1f,value3,value4);
  Gadget_SetTextf(arg1,0x1fb6,&DAT_005686f4,value3);
  Game_CountPlayerObjectsByType
            (*(void **)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200),value5,
             0x1d,0x19);
  value3 = Game_CountPlayerObjectsByType
                    (*(void **)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200)
                     ,value5,0x1d,0x1a);
  Gadget_SetTextf(arg1,0x1fd1,&DAT_005686f4,value3);
  value3 = *(int *)(value5 + 0x16f0);
  value4 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  Game_CountFilteredObjects(DAT_0057c670,0x19,0x1d,value3,value4);
  value3 = *(int *)(value5 + 0x16f0);
  value4 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  value3 = Game_CountFilteredObjects(DAT_0057c670,0x1a,0x1d,value3,value4);
  Gadget_SetTextf(arg1,0x1fcf,&DAT_005686f4,value3);
  if (self == (void *)0x0) {
    value3 = 0;
    uvalue6 = 0xff;
  }
  else {
    value3 = Game_CountFreeBuildingsByType(self,0x1d);
    if (value3 == 0) {
      uvalue6 = 0xff;
    }
    else {
      uvalue6 = 0;
    }
  }
  Window_GadgetNotify_Text_SetTextColor(arg1,0x1fb1,uvalue6);
  Gadget_SetTextf(arg1,0x1fb1,&DAT_005686f4,value3);
  uvalue6 = 5000;
  value3 = *(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8);
  if (*(int *)(value3 + 0x134) == 0) {
    if (*(int *)(value3 + 0x98) == 0) {
      if ((*(int *)(value3 + 0x218) != 0) || (*(int *)(value3 + 0x17c) != 0)) {
        uvalue6 = 0x1d4c;
      }
    }
    else {
      uvalue6 = 0x9c4;
    }
  }
  else {
    uvalue6 = 0;
  }
  Gadget_SetTextf(arg1,0x1fbc,&DAT_0056a850,uvalue6);
  if (self == (void *)0x0) {
    value3 = 0;
    uvalue6 = 0xff;
  }
  else {
    value3 = Game_CountFreeBuildingsByType(self,0x1d);
    if (value3 == 0) {
      uvalue6 = 0xff;
    }
    else {
      uvalue6 = 0;
    }
  }
  Window_GadgetNotify_Text_SetTextColor(arg1,0x1fc4,uvalue6);
  Gadget_SetTextf(arg1,0x1fc4,&DAT_005686f4,value3);
  value3 = Game_CountPlayerObjectsByType
                    (*(void **)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200)
                     ,value5,0x1d,-1);
  Gadget_SetTextf(arg1,0x1fc0,&DAT_005686f4,value3);
  value3 = *(int *)(value5 + 0x16f0);
  value4 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  value3 = Game_CountFilteredObjects(DAT_0057c670,0x10,0x1d,value3,value4);
  Gadget_SetTextf(arg1,0x1fbe,&DAT_005686f4,value3);
  uvalue6 = 5000;
  value3 = *(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8);
  if (*(int *)(value3 + 0x130) == 0) {
    if (*(int *)(value3 + 0x98) == 0) {
      if ((*(int *)(value3 + 0x214) != 0) || (*(int *)(value3 + 0x17c) != 0)) {
        uvalue6 = 0x1d4c;
      }
    }
    else {
      uvalue6 = 0x9c4;
    }
  }
  else {
    uvalue6 = 0;
  }
  Gadget_SetTextf(arg1,0x1f6e,&DAT_0056a850,uvalue6);
  if (self == (void *)0x0) {
    value3 = 0;
    uvalue6 = 0xff;
  }
  else {
    value3 = Game_CountFreeBuildingsByType(self,0x1e);
    if (value3 == 0) {
      uvalue6 = 0xff;
    }
    else {
      uvalue6 = 0;
    }
  }
  Window_GadgetNotify_Text_SetTextColor(arg1,0x1fc6,uvalue6);
  Gadget_SetTextf(arg1,0x1fc6,&DAT_005686f4,value3);
  value3 = Game_CountPlayerObjectsByType
                    (*(void **)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200)
                     ,value5,0x1e,-1);
  Gadget_SetTextf(arg1,0x1f78,&DAT_005686f4,value3);
  value5 = *(int *)(value5 + 0x16f0);
  value3 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  value5 = Game_CountFilteredObjects(DAT_0057c670,0xf,0x1e,value5,value3);
  Gadget_SetTextf(arg1,0x1f76,&DAT_005686f4,value5);
  value5 = *(int *)(*(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200) +
                   0x94 + value1 * 4);
  if (value5 < 1) {
    Gadget_SetText(arg1,0x1fcb,DAT_00582cc0);
    UI_RemoveObjectByKey(arg1,0x1fd3);
    UI_RemoveObjectByKey(arg1,0x1fd4);
  }
  else {
    Gadget_SetTextf(arg1,0x1fac,&DAT_005683a4,value5);
    Gadget_SetText(arg1,0x1fcb,DAT_005829d8);
    UI_ShowChildByID(arg1,0x1fd3);
    UI_ShowChildByID(arg1,0x1fd4);
  }
  if (*(char *)(*(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200) + 0xac
               + *(int *)(value2 + 0x48)) == '\0') {
    Window_GadgetNotify_Text_SetText(arg1,0x1fd3,DAT_005824d0);
    UI_RemoveObjectByKey(arg1,0x1fd4);
    UI_RemoveObjectByKey(arg1,0x1fcc);
    UI_RemoveObjectByKey(arg1,0x1fcd);
    return;
  }
  UI_ShowChildByID(arg1,0x1fcc);
  UI_ShowChildByID(arg1,0x1fcd);
  Window_GadgetNotify_Text_SetText(arg1,0x1fd3,DAT_005816a4);
  Gadget_SetTextf(arg1,0x1fd4,&DAT_005683a4,
                  *(uint32_t *)
                   (*(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200) +
                    0xb4 + value1 * 4));
  Gadget_SetTextf(arg1,0x1fcd,&DAT_0056a848,
                  *(uint32_t *)
                   (*(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200) +
                    0xcc + value1 * 4));
  Window_GadgetNotify_Text_SetText(arg1,0x1fcc,DAT_00582620);
  return;
}
