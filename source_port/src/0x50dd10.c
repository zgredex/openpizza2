// Person_UpdateFightAction: ported from Pizza Connection 2 at 0x50dd10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50dd10
#include "pc2_port.h"

void __fastcall Person_UpdateFightAction(void *arg1)

{
  bool flag1;
  void *pvVar2;
  int value3;
  uint32_t extraout_var;
  uint32_t uvalue4;
  int value5;
  void *self;
  
                    /* Updates a person's fight action and resolves duels. */
  value3 = *(int *)((intptr_t)arg1 + 0x108);
  if (value3 == 4) {
    *(uint32_t *)((intptr_t)arg1 + 0x108) = 0xffffffff;
    return;
  }
  if (value3 == 5) {
    *(uint32_t *)((intptr_t)arg1 + 0x108) = 0xffffffff;
    return;
  }
  if (value3 != 3) {
    value3 = Object_FindOpposingTarget((intptr_t)arg1);
    if (value3 != 0) {
      *(uint32_t *)((intptr_t)arg1 + 0x108) = 3;
      Object_PlayStateSound((intptr_t)arg1);
      return;
    }
    Object_SetFieldA4Locked(arg1,0xffffffff);
    if (*(int *)((intptr_t)arg1 + 0x38) == 0x3a) {
      value3 = *(int *)((intptr_t)arg1 + 0x110);
      value5 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
      if (value3 == value5) {
        MissionGoal_HandleEvent(*(void **)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8),0xb,-1,-1);
      }
      pvVar2 = *(void **)((intptr_t)arg1 + 0xfc);
      value3 = 0;
      if (0 < *(int *)((intptr_t)pvVar2 + 0x8c)) {
        do {
          pvVar2 = (void *)Game_MapRecordToGlobal(pvVar2,value3);
          if (*(int *)((intptr_t)pvVar2 + 0x30) == 0x1f) {
            Object_SetState(pvVar2,0x2e);
            *(uint32_t *)((intptr_t)DAT_0057c670 + 0x368) = 1;
            self = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)pvVar2 + 0x110));
            Game_UnlinkBuildingObject(self,*(int *)((intptr_t)pvVar2 + 0x164));
            Game_RemoveObjectFromList(*(void **)((intptr_t)arg1 + 0xfc),pvVar2,0);
          }
          pvVar2 = *(void **)((intptr_t)arg1 + 0xfc);
          value3 = value3 + 1;
        } while (value3 < *(int *)((intptr_t)pvVar2 + 0x8c));
      }
      value3 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)arg1 + 0x110));
      if (value3 != 0) {
        Person_SetRouteToBuilding(arg1,*(int *)(value3 + 0x1d8));
        Person_DecideWaitOrLeaveHouse(arg1);
        return;
      }
    }
    else if (*(int *)((intptr_t)arg1 + 0x38) == 0x3b) {
      Person_DecideWaitOrLeaveHouse(arg1);
    }
    return;
  }
  *(uint32_t *)((intptr_t)arg1 + 0x108) = 0xffffffff;
  pvVar2 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 0x3c),*(int *)((intptr_t)arg1 + 0x8c),
                                (int *)0x0);
  if ((pvVar2 == (void *)0x0) || (value3 = State_Is2DOr2E((intptr_t)pvVar2), value3 != 0)) {
    *(uint32_t *)((intptr_t)arg1 + 0x8c) = 0xffffffff;
    return;
  }
  flag1 = AI_TestActionChance(arg1,(intptr_t)pvVar2,1);
  if (CONCAT31(extraout_var,flag1) == 0) {
    if (*(int *)((intptr_t)arg1 + 0x30) == 0x1e) {
      return;
    }
    uvalue4 = Random_RangeFast(1,100);
    if ((intptr_t)uvalue4 < 0x32) {
      *(uint32_t *)((intptr_t)arg1 + 0x108) = 5;
      return;
    }
    return;
  }
  *(uint32_t *)((intptr_t)pvVar2 + 0x108) = 4;
  UI_UpdateValueBar(pvVar2,arg1,1);
  if (*(int *)((intptr_t)pvVar2 + 0xa8) < 1) {
    Character_OnArriveAtDestination(pvVar2,(float)(intptr_t)(arg1),1);
    return;
  }
  if (*(int *)((intptr_t)arg1 + 0x30) == 0x1e) {
    return;
  }
  *(uint32_t *)((intptr_t)arg1 + 0x108) = 5;
  return;
}
