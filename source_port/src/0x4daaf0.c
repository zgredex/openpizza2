// City_AddRandomBuilding: ported from Pizza Connection 2 at 0x4daaf0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4daaf0
#include "pc2_port.h"


void __thiscall City_AddRandomBuilding(void *self,int arg1,int arg2)

{
  int value1;
  uint32_t uvalue2;
  uint32_t *this_00;
  int *ptr3;
  void *pvVar4;
  int value5;
  void *pvVar6;
  int value7;
  uint32_t *uptr8;
  int *ptr9;
  int local_10;
  
                    /* Adds a random building to the city. */
  if (arg1 == -1) {
    uptr8 = City_CollectBuildingsByType(self,-1,0,'\x01');
    value1 = uptr8[5];
    do {
      ptr3 = (int *)0x0;
      uvalue2 = Random_RangeFast(0,value1 - 1);
      pvVar4 = (void *)IDMap_Lookup(uptr8,uvalue2,ptr3);
      pvVar6 = (void *)Game_PickRandomBuildingType(self,'\x01');
      value5 = Map_GetRandomBuildingOfType(self,(intptr_t)pvVar6,(intptr_t)pvVar4,'\0');
    } while (value5 == 0);
    value1 = *(int *)(value5 + 0x48);
    if ((-1 < value1) && (value1 < 4)) {
      value1 = *(int *)(&DAT_00568188 + value1 * 4);
    }
    value7 = *(int *)((intptr_t)pvVar4 + 0x48);
    if ((-1 < value7) && (value7 < 4)) {
      value7 = *(int *)(&DAT_00568188 + value7 * 4);
    }
    MapObject_SpawnByKind(self,pvVar4,5,-1,pvVar6,value7 + (*(int *)(value5 + 0x20) - value1));
    if (uptr8 != (uint32_t *)0x0) {
      (**(code **)*uptr8)(1);
    }
  }
  else {
    value1 = Game_GetPlayerBySlot(DAT_0057c670,arg1);
    if (*(int *)(value1 + 0x15c) != 0) {
      uvalue2 = Random_RangeFast(0,*(int *)(value1 + 0x15c) - 1);
      value1 = IDMap_Lookup((void *)(value1 + 0x148),uvalue2,(int *)0x0);
      value1 = Array_GetRecord28(*(void **)((intptr_t)self + 0xfa8),1,
                                *(int *)(*(int *)(value1 + 0x16f0) + 0x54));
      this_00 = City_FindFreePlotsNearPoint(self,*(uint32_t *)((intptr_t)self + 0xfa8),-1,value1,0xb4,1)
      ;
      uptr8 = (uint32_t *)this_00[5];
      if (uptr8 == (uint32_t *)0x0) {
        if (this_00 != (uint32_t *)0x0) {
          (**(code **)*this_00)(1);
          return;
        }
      }
      else {
        DAT_0057dfb8 = operator_new((intptr_t)uptr8 * 4);
        ptr3 = operator_new((intptr_t)uptr8 * 4);
        value1 = 0;
        if (0 < (intptr_t)uptr8) {
          do {
            value1 = value1 + 1;
            *(uint32_t *)((intptr_t)DAT_0057dfb8 + value1 * 4 + -4) = 0;
          } while (value1 < (intptr_t)uptr8);
        }
        value1 = 0;
        if (0 < (intptr_t)uptr8) {
          ptr9 = ptr3;
          do {
            *ptr9 = value1;
            value1 = value1 + 1;
            ptr9 = ptr9 + 1;
          } while (value1 < (intptr_t)uptr8);
        }
        local_10 = 0;
        if (0 < *(int *)((intptr_t)DAT_0057c670 + 0x50)) {
          do {
            pvVar4 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 0x3c),local_10,(int *)0x0);
            if ((*(int *)((intptr_t)pvVar4 + 0x30) < 8) && (value1 = 0, 0 < (intptr_t)uptr8)) {
              do {
                value5 = IDMap_Lookup(this_00,value1,(int *)0x0);
                ptr9 = (int *)((intptr_t)DAT_0057dfb8 + value1 * 4);
                value5 = Object_CountMatchingSlots(pvVar4,value5);
                value1 = value1 + 1;
                *ptr9 = *ptr9 + value5;
              } while (value1 < (intptr_t)uptr8);
            }
            local_10 = local_10 + 1;
          } while (local_10 < *(int *)((intptr_t)DAT_0057c670 + 0x50));
        }
        if (arg2 == 0) {
          CRT_QSort(ptr3,uptr8,4,&LAB_004dae30);
          pvVar4 = (void *)IDMap_Lookup(this_00,*ptr3,(int *)0x0);
          value5 = Map_GetRandomBuildingOfType(self,0,0,'\0');
          value1 = *(int *)(value5 + 0x48);
          if ((-1 < value1) && (value1 < 4)) {
            value1 = *(int *)(&DAT_00568188 + value1 * 4);
          }
          value7 = *(int *)((intptr_t)pvVar4 + 0x48);
          if ((-1 < value7) && (value7 < 4)) {
            value7 = *(int *)(&DAT_00568188 + value7 * 4);
          }
          MapObject_SpawnByKind
                    (self,pvVar4,5,-1,(void *)0x0,value7 + (*(int *)(value5 + 0x20) - value1));
          ptr9 = (int *)((intptr_t)self + arg1 * 4 + 0xd28);
          *ptr9 = *ptr9 + 1;
        }
        else {
          CRT_QSort(ptr3,uptr8,4,&LAB_004dae60);
          pvVar4 = (void *)IDMap_Lookup(this_00,*ptr3,(int *)0x0);
          pvVar6 = (void *)Game_PickRandomBuildingType(self,'\0');
          value5 = Map_GetRandomBuildingOfType(self,(intptr_t)pvVar6,0,'\0');
          value1 = *(int *)(value5 + 0x48);
          if ((-1 < value1) && (value1 < 4)) {
            value1 = *(int *)(&DAT_00568188 + value1 * 4);
          }
          value7 = *(int *)((intptr_t)pvVar4 + 0x48);
          if ((-1 < value7) && (value7 < 4)) {
            value7 = *(int *)(&DAT_00568188 + value7 * 4);
          }
          MapObject_SpawnByKind(self,pvVar4,5,-1,pvVar6,value7 + (*(int *)(value5 + 0x20) - value1));
          ptr9 = (int *)((intptr_t)self + arg1 * 4 + 0xd28);
          *ptr9 = *ptr9 + 1;
        }
        Mem_Free(ptr3);
        Mem_Free(DAT_0057dfb8);
        if (this_00 != (uint32_t *)0x0) {
          (**(code **)*this_00)(1);
          return;
        }
      }
    }
  }
  return;
}
