// AI_FindBestBranchSite: ported from Pizza Connection 2 at 0x4f8240.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f8240
#include "pc2_port.h"

int __thiscall AI_FindBestBranchSite(void *self,int arg1,void *arg2,int arg3,int *arg4)

{
  int value1;
  double dVar2;
  int value3;
  uint32_t uvalue4;
  int value5;
  int value6;
  int value7;
  int value8;
  int value9;
  int value10;
  int value11;
  int64_t lvalue12;
  int *ptr13;
  int local_34;
  uint32_t *local_30;
  uint32_t local_28;
  int local_20;
  int local_1c;
  uint32_t local_18;
  int local_14;
  
  *arg4 = 0;
  local_14 = 0;
  if (arg3 == 0) {
    local_30 = City_CollectBranchBuildings((intptr_t)arg2);
    value3 = local_30[5];
  }
  else {
    local_30 = City_CollectBuildingsByType(arg2,-1,0,'\x01');
    value3 = (intptr_t)local_30[5] >> 4;
  }
  value1 = *(int *)((intptr_t)arg2 + 0xc1c);
  local_18 = 0;
  if (0 < value3) {
    local_28 = 0x10;
    do {
      ptr13 = (int *)0x0;
      if (arg3 == 0) {
        uvalue4 = local_18;
      }
      else {
        uvalue4 = Random_RangeFast(local_18 << 4,local_28);
      }
      value5 = IDMap_Lookup(local_30,uvalue4,ptr13);
      if (value5 != 0) {
        value11 = arg1 * 0x168;
        if (*(int *)(value11 + 0x118 + (intptr_t)self) != 0) {
          value6 = Array_FindIndexByPtr(arg2,value5);
          value10 = 0;
          ptr13 = (int *)(value1 * 0x10 + value11 + 0x138 + (intptr_t)self);
          do {
            if (*ptr13 == value6) {
              if (value10 < 4) goto LAB_004f84b1;
              break;
            }
            value10 = value10 + 1;
            ptr13 = ptr13 + 1;
          } while (value10 < 4);
        }
        local_34 = Game_ComputeAreaAttraction(arg2,value5,0x8c);
        local_1c = 0;
        do {
          value6 = Game_GetPlayerBySlot(DAT_0057c670,local_1c);
          if ((value6 != 0) && (local_20 = 0, 0 < *(int *)(value6 + 0x15c))) {
            do {
              value10 = IDMap_Lookup((void *)(value6 + 0x148),local_20,(int *)0x0);
              if (value10 != 0) {
                value9 = *(int *)(value10 + 0x16f0);
                value7 = Game_GetObjectCenterY(value5);
                value8 = Game_GetObjectCenterY(value9);
                value8 = value8 - value7 >> 1;
                value7 = Game_GetObjectBottom(value5);
                value9 = Game_GetObjectBottom(value9);
                dVar2 = SQRT((double)((value9 - value7) * (value9 - value7) + value8 * value8));
                if (dVar2 < 400.0) {
                  if (*(int *)(value10 + 0x30) == *(int *)(value11 + 0x40 + (intptr_t)self)) {
                    lvalue12 = __ftol();
                    local_34 = (intptr_t)lvalue12;
                  }
                  else {
                    value10 = *(int *)(*(int *)(value11 + 0x70 + (intptr_t)self) + 0x15c);
                    if (value10 < 2) {
                      local_34 = local_34 >> 3;
                    }
                    else if (dVar2 < (double)((0x14 - value10) * 0x14)) {
                      local_34 = local_34 >> 3;
                    }
                  }
                }
              }
              local_20 = local_20 + 1;
            } while (local_20 < *(int *)(value6 + 0x15c));
          }
          local_1c = local_1c + 1;
        } while (local_1c < 6);
        if (*arg4 < local_34) {
          *arg4 = local_34;
          local_14 = value5;
        }
      }
LAB_004f84b1:
      local_18 = local_18 + 1;
      local_28 = local_28 + 0x10;
    } while ((intptr_t)local_18 < value3);
  }
  if (local_30 != (uint32_t *)0x0) {
    (**(code **)*local_30)(1);
  }
  if (*arg4 < 1) {
    *arg4 = 0;
    return 0;
  }
  return local_14;
}
