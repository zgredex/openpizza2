// AI_FindBranchPlotNearOwn: ported from Pizza Connection 2 at 0x4f8510.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f8510
#include "pc2_port.h"

int __thiscall AI_FindBranchPlotNearOwn(void *self,int arg1,void *arg2)

{
  int value1;
  uint32_t *this_00;
  uint32_t uvalue2;
  int value3;
  int value4;
  int value5;
  int value6;
  int value7;
  int value8;
  int64_t lvalue9;
  int *ptr10;
  int local_58;
  int local_54;
  uint32_t local_48;
  int local_44;
  int local_40;
  int local_38;
  int local_34;
  int local_20;
  int local_1c;
  int local_18 [5];
  
  local_34 = 0;
  value1 = *(int *)((intptr_t)self + arg1 * 0x168 + 0x70);
  this_00 = City_CollectBuildingsByType(arg2,0,0,'\x01');
  local_44 = 0;
  local_38 = 0;
  value8 = (intptr_t)this_00[5] >> 3;
  local_1c = value8;
  do {
    local_40 = 0;
    if (0 < value8) {
      local_48 = 8;
      do {
        ptr10 = (int *)0x0;
        uvalue2 = Random_RangeFast(local_40 * 8,local_48);
        value3 = IDMap_Lookup(this_00,uvalue2,ptr10);
        if (value3 != 0) {
          local_58 = 0;
          local_54 = 0;
          if (0 < *(int *)(value1 + 0x15c)) {
            do {
              value4 = IDMap_Lookup((void *)(value1 + 0x148),local_54,(int *)0x0);
              value8 = *(int *)(value4 + 0x16f0);
              value5 = Game_GetObjectCenterY(value3);
              value6 = Game_GetObjectCenterY(value8);
              value7 = Game_GetObjectBottom(value3);
              value8 = Game_GetObjectBottom(value8);
              if (SQRT((double)((value8 - value7) * (value8 - value7) +
                               (value6 - value5) * (value6 - value5))) < 400.0) {
                AI_ComputePlanScores(value4,&local_20,local_18,4);
                lvalue9 = __ftol();
                local_58 = local_58 + 1000 + (intptr_t)lvalue9;
              }
              local_54 = local_54 + 1;
            } while (local_54 < *(int *)(value1 + 0x15c));
            value8 = local_1c;
          }
          if (local_44 < local_58) {
            local_44 = local_58;
            local_34 = value3;
          }
        }
        local_40 = local_40 + 1;
        local_48 = local_48 + 8;
      } while (local_40 < value8);
    }
  } while ((local_58 < 1) && (local_38 = local_38 + 1, local_38 < 10));
  if (this_00 != (uint32_t *)0x0) {
    (**(code **)*this_00)(1);
  }
  if (local_44 < 1) {
    return 0;
  }
  return local_34;
}
