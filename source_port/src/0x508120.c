// Person_FindNearbyBranchToVisit: ported from Pizza Connection 2 at 0x508120.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x508120
#include "pc2_port.h"

void __fastcall Person_FindNearbyBranchToVisit(void *arg1)

{
  bool flag1;
  void *pvVar2;
  uint32_t *self;
  int value3;
  int value4;
  int value5;
  void *pvVar6;
  int value7;
  int local_c;
  int local_8;
  void *local_4;
  
                    /* Finds a nearby branch for a person to visit. */
  pvVar2 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)arg1 + 0x28),
                                (int *)0x0);
  local_4 = pvVar2;
  MapObject_GetScreenPosition(arg1,(uint32_t)(*(int *)((intptr_t)arg1 + 0x74) != 0),&local_8,&local_c);
  self = City_CollectBranchesNearPoint(pvVar2,*(int *)((intptr_t)arg1 + 0x34),local_8,local_c);
  value7 = 0;
  value5 = self[5];
  if (0 < value5) {
    do {
      value3 = IDMap_Lookup(self,value7,(int *)0x0);
      value4 = Map_LookupLinear((void *)((intptr_t)arg1 + 0x130),value3);
      if (value4 == -1) {
        List_Add((void *)((intptr_t)arg1 + 0x130),value3);
      }
      value7 = value7 + 1;
    } while (value7 < value5);
  }
  if (value5 == 0) {
    if (self != (uint32_t *)0x0) {
      (**(code **)*self)(1);
    }
  }
  else if (value5 == 1) {
    if (((((*(int *)((intptr_t)arg1 + 0x54) == 0) &&
          (value5 = IDMap_Lookup(self,0,(int *)0x0), *(int *)(value5 + 4) == 0xf)) &&
         (value7 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(value5 + 8)), value7 != 0)) &&
        ((pvVar2 = (void *)IDMap_Lookup((void *)(value7 + 0x148),*(int *)(value5 + 0x2c),(int *)0x0),
         pvVar2 != (void *)0x0 && (flag1 = Object_IsSiteRatingSufficient(arg1,pvVar2), flag1))))
       && ((*(int *)((intptr_t)arg1 + 0x58) == -1 ||
           (*(int *)((intptr_t)arg1 + 0x58) == *(int *)(value5 + 8))))) {
      *(uint32_t *)((intptr_t)arg1 + 0x54) = 1;
      *(int *)((intptr_t)arg1 + 0xf4) = value5;
      Object_SetDestinationAndTarget(arg1,1,value5);
    }
    if (self != (uint32_t *)0x0) {
      (**(code **)*self)(1);
      return;
    }
  }
  else {
    pvVar2 = Game_PickBestScoredRecord((intptr_t)arg1,self);
    value5 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)pvVar2 + 8));
    pvVar6 = (void *)IDMap_Lookup((void *)(value5 + 0x148),*(int *)((intptr_t)pvVar2 + 0x2c),(int *)0x0);
    flag1 = Object_IsSiteRatingSufficient(arg1,pvVar6);
    if (((flag1) &&
        ((*(int *)((intptr_t)arg1 + 0x54) == 0 ||
         ((*(void **)((intptr_t)arg1 + 0xf4) != pvVar2 &&
          ((*(int *)((intptr_t)arg1 + 0x54) == 0 ||
           (*(int *)((intptr_t)*(void **)((intptr_t)arg1 + 0xf4) + 8) != *(int *)((intptr_t)pvVar2 + 8)))))))))
       && ((*(int *)((intptr_t)arg1 + 0x58) == -1 ||
           (*(int *)((intptr_t)arg1 + 0x58) == *(int *)((intptr_t)pvVar2 + 8))))) {
      *(uint32_t *)((intptr_t)arg1 + 0x54) = 1;
      *(void **)((intptr_t)arg1 + 0xf4) = pvVar2;
      Object_SetDestinationAndTarget(arg1,1,(intptr_t)pvVar2);
    }
    if (self != (uint32_t *)0x0) {
      (**(code **)*self)(1);
      return;
    }
  }
  return;
}
