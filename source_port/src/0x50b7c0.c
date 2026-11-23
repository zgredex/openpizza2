// Object_FindNearbyCustomer: ported from Pizza Connection 2 at 0x50b7c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50b7c0
#include "pc2_port.h"

int __thiscall Object_FindNearbyCustomer(void *self,void *arg1)

{
  int value1;
  int value2;
  uint32_t *this_00;
  void *this_01;
  int value3;
  int value4;
  int value5;
  int local_14;
  int local_10;
  int local_c;
  
  local_c = 0;
  value5 = 99999999;
  value1 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  value2 = Array_GetRecord28(*(void **)(value1 + 0xfa8),1,*(int *)(*(int *)((intptr_t)self + 0xfc) + 0x54))
  ;
  value1 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)((intptr_t)self + 0x28),(int *)0x0);
  this_00 = Map_CollectObjectsOnFlaggedTiles(value1);
  local_10 = 0;
  value1 = 0;
  if (0 < (intptr_t)this_00[5]) {
    do {
      this_01 = (void *)IDMap_Lookup(this_00,local_10,(int *)0x0);
      if (this_01 != (void *)0x0) {
        value1 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
        value1 = Array_GetRecord28(*(void **)(value1 + 0xfa8),1,*(int *)((intptr_t)this_01 + 0x54));
        local_14 = 0;
        if (0 < *(int *)((intptr_t)this_01 + 0x8c)) {
          do {
            value3 = Game_MapRecordToGlobal(this_01,local_14);
            if (((value3 != 0) && (*(int *)(value3 + 0x38) == 0x1a)) &&
               (value4 = Branch_GetMenuRating(arg1,*(int *)(value3 + 0x34)),
               *(int *)(value3 + 0x2c) <= value4)) {
              value4 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),
                                   (int *)0x0);
              value4 = Object_Compare(*(void **)(value4 + 0xfa8),value2,value1);
              if (value4 < value5) {
                value5 = value4;
                local_c = value3;
              }
            }
            local_14 = local_14 + 1;
          } while (local_14 < *(int *)((intptr_t)this_01 + 0x8c));
        }
      }
      local_10 = local_10 + 1;
    } while (local_10 < (intptr_t)this_00[5]);
    value1 = local_c;
  }
  if (this_00 != (uint32_t *)0x0) {
    (**(code **)*this_00)(1);
  }
  return value1;
}
