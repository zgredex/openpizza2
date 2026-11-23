// City_SendResidentsToVenue: ported from Pizza Connection 2 at 0x48c400.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48c400
#include "pc2_port.h"


void __thiscall City_SendResidentsToVenue(void *self,uint32_t *arg1,int arg2,int arg3)

{
  uint32_t *uptr1;
  int *ptr2;
  int value3;
  void *pvVar4;
  void *pvVar5;
  int *ptr6;
  
                    /* Sends free residents to a random venue. */
  DAT_0057c638 = arg2;
  DAT_0057c63c = City_CollectVacantLots((intptr_t)self);
  uptr1 = (uint32_t *)DAT_0057c63c[5];
  if ((intptr_t)uptr1 < (intptr_t)arg1) {
    arg1 = uptr1;
  }
  ptr2 = operator_new((intptr_t)uptr1 * 4);
  value3 = 0;
  if (0 < (intptr_t)uptr1) {
    ptr6 = ptr2;
    do {
      *ptr6 = value3;
      value3 = value3 + 1;
      ptr6 = ptr6 + 1;
    } while (value3 < (intptr_t)uptr1);
  }
  if (arg2 == -1) {
    CRT_QSort(ptr2,uptr1,4,&LAB_0048c670);
    ptr6 = ptr2;
    if (0 < (intptr_t)arg1) {
      do {
        pvVar4 = (void *)IDMap_Lookup(DAT_0057c63c,*ptr6,(int *)0x0);
        if (*(int *)((intptr_t)pvVar4 + 0x74) == 0) {
          pvVar5 = (void *)IDMap_Lookup((void *)((intptr_t)self + 4),*(int *)((intptr_t)self + 0x2f4),
                                        (int *)0x0);
          value3 = Map_GetRandomBuildingOfType(pvVar5,0x22,0,'\0');
          Object_SetDestinationAndTarget(pvVar4,7,value3);
          UI_SetChildState(pvVar4,0xffff);
        }
        else {
          *(uint8_t *)((intptr_t)pvVar4 + 0x81) = 1;
          Object_SetFieldA4Locked(pvVar4,0x13);
        }
        ptr6 = ptr6 + 1;
        arg1 = (uint32_t *)((intptr_t)arg1 + -1);
      } while (arg1 != (uint32_t *)0x0);
    }
  }
  else {
    CRT_QSort(ptr2,uptr1,4,&LAB_0048c610);
    if (arg3 < 0) {
      ptr6 = ptr2;
      if (0 < (intptr_t)arg1) {
        do {
          pvVar4 = (void *)IDMap_Lookup(DAT_0057c63c,*ptr6,(int *)0x0);
          if (*(int *)((intptr_t)pvVar4 + 0x74) == 0) {
            pvVar5 = (void *)IDMap_Lookup((void *)((intptr_t)self + 4),*(int *)((intptr_t)self + 0x2f4),
                                          (int *)0x0);
            value3 = Map_GetRandomBuildingOfType(pvVar5,0x22,0,'\0');
            Object_SetDestinationAndTarget(pvVar4,7,value3);
            UI_SetChildState(pvVar4,0xffff);
          }
          else {
            *(uint8_t *)((intptr_t)pvVar4 + 0x81) = 1;
            Object_SetFieldA4Locked(pvVar4,0x13);
          }
          ptr6 = ptr6 + 1;
          arg1 = (uint32_t *)((intptr_t)arg1 + -1);
        } while (arg1 != (uint32_t *)0x0);
      }
    }
    else {
      value3 = (intptr_t)uptr1 + -1;
      if ((intptr_t)uptr1 + -0xb < value3) {
        ptr6 = ptr2 + value3;
        arg2 = value3 - ((intptr_t)uptr1 + -0xb);
        do {
          pvVar4 = (void *)IDMap_Lookup(DAT_0057c63c,*ptr6,(int *)0x0);
          if (*(int *)((intptr_t)pvVar4 + 0x74) == 0) {
            pvVar5 = (void *)IDMap_Lookup((void *)((intptr_t)self + 4),*(int *)((intptr_t)self + 0x2f4),
                                          (int *)0x0);
            value3 = Map_GetRandomBuildingOfType(pvVar5,0x22,0,'\0');
            Object_SetDestinationAndTarget(pvVar4,7,value3);
            UI_SetChildState(pvVar4,0xffff);
          }
          else {
            *(uint8_t *)((intptr_t)pvVar4 + 0x81) = 1;
            Object_SetFieldA4Locked(pvVar4,0x13);
          }
          ptr6 = ptr6 + -1;
          arg2 = arg2 + -1;
        } while (arg2 != 0);
      }
    }
  }
  Mem_Free(ptr2);
  if (DAT_0057c63c != (uint32_t *)0x0) {
    (**(code **)*DAT_0057c63c)(1);
  }
  return;
}
