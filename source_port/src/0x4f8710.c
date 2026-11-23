// AI_PickInitialBranchPlot: ported from Pizza Connection 2 at 0x4f8710.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f8710
#include "pc2_port.h"

int AI_PickInitialBranchPlot(void *arg1)

{
  int value1;
  uint32_t *self;
  uint32_t *this_00;
  uint32_t uvalue2;
  int value3;
  int value4;
  int value5;
  int64_t lvalue6;
  int *ptr7;
  uint32_t local_20;
  void *local_1c;
  int local_18;
  int local_10;
  int local_c;
  
  local_c = 0;
  self = City_CollectBuildingsByType(arg1,0,0,'\x01');
  this_00 = City_CollectBuildingsByType(arg1,0x11,0,'\0');
  value1 = self[5];
  local_1c = (void *)0x0;
  local_10 = 0;
  do {
    local_18 = 0;
    if (0 < value1 >> 3) {
      local_20 = 8;
      do {
        ptr7 = (int *)0x0;
        uvalue2 = Random_RangeFast(local_18 * 8,local_20);
        value3 = IDMap_Lookup(self,uvalue2,ptr7);
        if (value3 != 0) {
          uvalue2 = _rand();
          arg1 = (void *)((uvalue2 & 0x3f) + 4000);
          value5 = 0;
          if (0 < (intptr_t)this_00[5]) {
            do {
              value4 = IDMap_Lookup(this_00,value5,(int *)0x0);
              Game_GetObjectCenterY(value3);
              Game_GetObjectCenterY(value4);
              Game_GetObjectBottom(value3);
              Game_GetObjectBottom(value4);
              lvalue6 = __ftol();
              if ((intptr_t)lvalue6 < 1000) {
                arg1 = (void *)((intptr_t)arg1 + (intptr_t)lvalue6 + -1000);
              }
              value5 = value5 + 1;
            } while (value5 < (intptr_t)this_00[5]);
          }
          if ((intptr_t)local_1c < (intptr_t)arg1) {
            local_1c = arg1;
            local_c = value3;
          }
        }
        local_18 = local_18 + 1;
        local_20 = local_20 + 8;
      } while (local_18 < value1 >> 3);
    }
  } while (((intptr_t)arg1 < 1) && (local_10 = local_10 + 1, local_10 < 10));
  if (self != (uint32_t *)0x0) {
    (**(code **)*self)(1);
  }
  if (this_00 != (uint32_t *)0x0) {
    (**(code **)*this_00)(1);
  }
  if ((intptr_t)local_1c < 1) {
    return 0;
  }
  return local_c;
}
