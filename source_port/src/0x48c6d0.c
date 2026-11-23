// Game_RedirectPersonDestination: ported from Pizza Connection 2 at 0x48c6d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48c6d0
#include "pc2_port.h"

void __thiscall Game_RedirectPersonDestination(void *self,int arg1)

{
  int value1;
  void *this_00;
  uint32_t *this_01;
  uint32_t uvalue2;
  int value3;
  int value4;
  int *ptr5;
  int value6;
  int value7;
  int local_10;
  
  value1 = *(int *)(arg1 + 0x30);
  this_00 = (void *)IDMap_Lookup((void *)((intptr_t)self + 4),*(int *)((intptr_t)self + 0x2f4),(int *)0x0);
  this_01 = City_CollectBuildingsByType(this_00,value1,arg1,'\0');
  value1 = this_01[5];
  uvalue2 = Random_RangeFast(1,value1 + 1);
  local_10 = 0;
  if (0 < *(int *)((intptr_t)self + 0x50)) {
    do {
      value3 = IDMap_Lookup((void *)((intptr_t)self + 0x3c),local_10,(int *)0x0);
      value7 = 0;
      if (0 < value1) {
        do {
          value4 = IDMap_Lookup(this_01,value7,(int *)0x0);
          value6 = 8;
          ptr5 = (int *)(value3 + 0xd4);
          do {
            if ((*ptr5 == value4) && (uvalue2 = uvalue2 - 1, uvalue2 == 0)) {
              uvalue2 = value1 + 1;
              *ptr5 = arg1;
            }
            ptr5 = ptr5 + 1;
            value6 = value6 + -1;
          } while (value6 != 0);
          value7 = value7 + 1;
        } while (value7 < value1);
      }
      local_10 = local_10 + 1;
    } while (local_10 < *(int *)((intptr_t)self + 0x50));
  }
  if (this_01 != (uint32_t *)0x0) {
    (**(code **)*this_01)(1);
  }
  return;
}
