// Person_UpdateStreetBehavior: ported from Pizza Connection 2 at 0x40b110.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x40b110
#include "pc2_port.h"

void __thiscall Person_UpdateStreetBehavior(void *self,void *arg1,int arg2)

{
  int value1;
  int value2;
  void *pvVar3;
  uint8_t uvalue4;
  uint32_t extraout_var;
  int value5;
  uint32_t uvalue6;
  void *pvVar7;
  void *this_00;
  uint32_t uvalue8;
  uint32_t *this_01;
  uint32_t extraout_EDX;
  
                    /* Updates a person or vehicle outside any building. */
  uvalue4 = Object_IsVisibleThisFrame((intptr_t)arg1);
  value5 = *(int *)((intptr_t)arg1 + 0x90);
  value1 = *(int *)((intptr_t)arg1 + 0x4c);
  value2 = *(int *)((intptr_t)arg1 + 0x54);
  Person_UpdateWaitAndHunger(arg1);
  if (CONCAT31(extraout_var,uvalue4) == 0) {
    if (value5 != 0) {
      if (*(int *)((intptr_t)arg1 + 200) == 0) {
        value5 = 0;
      }
      else {
        value5 = *(int *)(*(int *)((intptr_t)arg1 + 200) + 0x20);
      }
      if (*(int *)((intptr_t)arg1 + 0xf8) == value5) {
        value5 = *(int *)((intptr_t)arg1 + 0x90);
        *(uint32_t *)((intptr_t)arg1 + 0x90) = 0;
        if (value5 == 1) {
          if (*(int *)((intptr_t)arg1 + 0xfc) == 0) {
            return;
          }
          value5 = *(int *)((intptr_t)arg1 + 0x30);
          if (((value5 == 0xb) || (value5 == 0xf)) || (value5 == 0x21)) {
            Object_ActionActivate(arg1,extraout_EDX);
            return;
          }
          return;
        }
        if (value5 != 7) {
          if (value5 == 0xd) {
            Object_ActivateAndSetState(arg1);
            return;
          }
          return;
        }
        do {
          uvalue6 = Random_RangeFast(0,7);
        } while (uvalue6 == *(uint32_t *)((intptr_t)arg1 + 0x34));
        pvVar3 = *(void **)((intptr_t)self + 0x21c);
        Object_SetFlag104(arg1,1);
        Object_SetState(arg1,0x2e);
        pvVar7 = (void *)IDMap_Lookup((void *)((intptr_t)self + 4),*(int *)((intptr_t)self + 0x2f4),(int *)0x0
                                     );
        pvVar7 = (void *)Map_GetRandomBuildingOfType(pvVar7,0x22,0,'\0');
        this_00 = (void *)IDMap_Lookup((void *)((intptr_t)self + 4),*(int *)((intptr_t)self + 0x2f4),
                                       (int *)0x0);
        uvalue8 = Random_RangeFast(0,1);
        this_01 = City_CreateObjectsOfType(this_00,(uint32_t *)0x1,uvalue6,uvalue8);
        Object_AttachToParent(this_01,pvVar7,1);
        if (pvVar3 == arg1) {
          *(uint32_t **)((intptr_t)self + 0x21c) = this_01;
          *(uint32_t *)((intptr_t)self + 0x2da8) = 1;
          return;
        }
        return;
      }
    }
    if (((value2 != 0) && (*(int *)((intptr_t)arg1 + 0xfc) != 0)) &&
       (*(int *)(*(int *)((intptr_t)arg1 + 0xfc) + 4) == 0xf)) {
      Object_ActionActivate(arg1,extraout_EDX);
      return;
    }
    switch(*(uint32_t *)((intptr_t)arg1 + 0x38)) {
    case 1:
      MapObject_StepToRandomCell(arg1);
      return;
    case 2:
      pvVar3 = *(void **)((intptr_t)arg1 + 0xd0);
      if ((pvVar3 != (void *)0x0) && (*(int *)((intptr_t)pvVar3 + 4) != 0x1a)) {
        Object_Activate(arg1,pvVar3);
        Person_DecideWaitOrLeaveHouse(arg1);
        return;
      }
      break;
    case 3:
      value5 = Person_SelectRouteStopForTimeSlot(arg1,arg2);
      if (value5 == 0) {
        Person_WanderToRandomTile(arg1);
        return;
      }
      break;
    case 4:
      if (*(int *)((intptr_t)arg1 + 0x168) == 0) {
        Person_ReturnToHomeBase(arg1);
        return;
      }
      Person_SelectRouteStopForTimeSlot(arg1,arg2);
      return;
    case 0x1d:
      Object_Deactivate(arg1,*(void **)((intptr_t)arg1 + 0xfc));
      Object_SetState(arg1,3);
      return;
    }
  }
  else {
    if (value1 != 0) {
      Person_FindNearbyBranchToVisit(arg1);
      return;
    }
    Person_SelectRouteStopForTimeSlot(arg1,arg2);
  }
  return;
}
