// City_TrySendPoliceToDistrict: ported from Pizza Connection 2 at 0x4da000.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4da000
#include "pc2_port.h"

uint32_t __thiscall City_TrySendPoliceToDistrict(void *self,void *arg1)

{
  int *ptr1;
  int value2;
  uint32_t *this_00;
  void *pvVar3;
  int value4;
  int value5;
  int local_c;
  int local_8;
  int local_4;
  
  value5 = 0;
  value4 = 0;
  ptr1 = (int *)((intptr_t)self + 0x10d4);
  do {
    if ((*(char *)((intptr_t)ptr1 + 0x11) != '\0') && (*ptr1 == *(int *)((intptr_t)arg1 + 0x3c))) {
      return 0;
    }
    value4 = value4 + 1;
    ptr1 = ptr1 + 6;
  } while (value4 < 5);
  value4 = 0;
  ptr1 = (int *)((intptr_t)self + 0x10d0);
  do {
    if ((*(char *)((intptr_t)ptr1 + 0x15) != '\0') && (*ptr1 == -1)) break;
    value4 = value4 + 1;
    ptr1 = ptr1 + 6;
  } while (value4 < 5);
  if (value4 == 5) {
    return 0;
  }
  *(uint32_t *)((intptr_t)self + value4 * 0x18 + 0x10d0) = 1;
  *(uint32_t *)((intptr_t)self + value4 * 0x18 + 0x10d4) = *(uint32_t *)((intptr_t)arg1 + 0x3c);
  value2 = Game_ComputeCompanyValue(self,&local_4,&local_8,&local_c);
  *(int *)((intptr_t)self + value4 * 0x18 + 0x10d8) = value2;
  *(uint8_t *)((intptr_t)self + value4 * 0x18 + 0x10e4) = 0;
  *(uint32_t *)((intptr_t)self + (value4 * 3 + 0x21c) * 8) = 0;
  *(uint32_t *)((intptr_t)self + value4 * 0x18 + 0x10dc) = 0;
  this_00 = City_CollectBuildingsByType(self,0x11,0,'\0');
  if ((intptr_t)this_00[5] < 1) {
    pvVar3 = arg1;
  }
  else {
    do {
      pvVar3 = (void *)IDMap_Lookup(this_00,value5,(int *)0x0);
      if (*(int *)((intptr_t)pvVar3 + 0xc) == value4) break;
      value5 = value5 + 1;
    } while (value5 < (intptr_t)this_00[5]);
  }
  City_SendPoliceUnits(self,0x17,pvVar3,*(uint32_t *)((intptr_t)arg1 + 0x16f0),value4);
  if (this_00 != (uint32_t *)0x0) {
    (**(code **)*this_00)(1);
  }
  return 1;
}
