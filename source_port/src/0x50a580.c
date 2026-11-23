// Object_ActionRemove: ported from Pizza Connection 2 at 0x50a580.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50a580
#include "pc2_port.h"

void __fastcall Object_ActionRemove(void *arg1)

{
  void *pvVar1;
  int value2;
  int value3;
  void *self;
  void *this_00;
  void *this_01;
  uint32_t extraout_EDX;
  uint32_t unaff_EDI;
  void *local_4;
  
                    /* Removes an object from its parent and evacuates a branch. */
  local_4 = (void *)0x0;
  pvVar1 = *(void **)((intptr_t)arg1 + 0xfc);
  Object_Activate(arg1,pvVar1);
  if (*(int *)(*(int *)((intptr_t)arg1 + 0xfc) + 0x94) != 0) {
    Person_CancelVisitAtOccupiedBuilding(arg1,extraout_EDX,0);
    return;
  }
  value2 = State_IsMenuState((intptr_t)arg1);
  if (value2 != 0) {
    Object_Reset108((intptr_t)arg1);
  }
  if (*(int *)((intptr_t)arg1 + 0x30) == 0x1d) {
    Object_SetState(arg1,0x3a);
    value2 = *(int *)((intptr_t)pvVar1 + 8);
    value3 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
    if ((value2 == value3) &&
       (value2 = Game_HasKeyedRecordEntry(DAT_0057c670,7,(intptr_t)pvVar1), value2 == 0)) {
      value2 = UI_Briefing_Printf((intptr_t)DAT_0057c670,4,4,2,10,(intptr_t)pvVar1,DAT_005828a8,DAT_00582188,
                                 unaff_EDI);
      Game_SetMessageField34(DAT_0057c670,value2,7);
    }
  }
  value2 = 0;
  if (*(int *)((intptr_t)pvVar1 + 0x8c) < 1) {
    self = local_4;
  }
  else {
    do {
      self = (void *)Game_MapRecordToGlobal(pvVar1,value2);
      value3 = State_IsMenuState((intptr_t)self);
      if ((((value3 != 0) && (*(int *)((intptr_t)self + 0x38) != 0x3a)) &&
          (value3 = State_Is2DOr2E((intptr_t)self), value3 == 0)) &&
         (local_4 = (void *)((intptr_t)local_4 + 1), *(int *)((intptr_t)arg1 + 0x30) == 0x1d)) {
        Object_SetState(self,0x3b);
      }
      value2 = value2 + 1;
    } while (value2 < *(int *)((intptr_t)pvVar1 + 0x8c));
  }
  if (*(int *)((intptr_t)arg1 + 0x30) == 0x1f) {
    this_00 = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)arg1 + 0x110));
    if (0 < (intptr_t)local_4) {
      Object_SetState(arg1,0x2e);
      *(uint32_t *)((intptr_t)DAT_0057c670 + 0x368) = 1;
      Game_UnlinkBuildingObject(this_00,*(int *)((intptr_t)arg1 + 0x164));
      Game_RemoveObjectFromList(pvVar1,arg1,0);
      *(int *)((intptr_t)this_00 + 0x90) = *(int *)((intptr_t)this_00 + 0x90) + 1;
      value2 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)pvVar1 + 8));
      value2 = Game_GetPlayerCity(value2);
      *(int *)(value2 + 0x38) = *(int *)(value2 + 0x38) + 1;
      return;
    }
    pvVar1 = *(void **)((intptr_t)arg1 + 0xfc);
    this_01 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),
                                   *(int *)((intptr_t)DAT_0057c670 + 0x2f4),(int *)0x0);
    City_CreateExplosionEffect(this_01,2,0x2e,pvVar1);
    Game_AbortOrdersTargetingObject(*(int *)((intptr_t)self + 0xfc),1,arg1);
    *(int *)((intptr_t)arg1 + 0xcc) = *(int *)((intptr_t)arg1 + 0xfc);
    *(uint32_t *)(*(int *)((intptr_t)arg1 + 0xfc) + 0x94) = 1;
    *(uint32_t *)(*(int *)((intptr_t)arg1 + 0xfc) + 0xc) = 0x12378d6;
    Person_SetRouteToBuilding(arg1,*(int *)((intptr_t)this_00 + 0x1d8));
    Object_SetChildField2C(arg1,0);
    *(int *)((intptr_t)this_00 + 0x88) = *(int *)((intptr_t)this_00 + 0x88) + 1;
    value2 = *(int *)((intptr_t)arg1 + 0x110);
    value3 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
    if (value2 == value3) {
      pvVar1 = *(void **)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xac);
      Array_SearchSet(pvVar1,0x14);
      Array_SearchSet(pvVar1,0x1d);
    }
  }
  return;
}
