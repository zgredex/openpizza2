// Map_ComputeBlitRect: ported from Pizza Connection 2 at 0x4ed5a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ed5a0
#include "pc2_port.h"

int __thiscall Map_ComputeBlitRect(void *self,int arg1,int arg2,int *arg3,int arg4)

{
  int value1;
  uint32_t uvalue2;
  int value3;
  int value4;
  uint32_t uvalue5;
  uint32_t uvalue6;
  int value7;
  int value8;
  bool flag9;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  uint32_t local_10;
  int local_c;
  int local_8;
  int local_4;
  
  local_18 = *(int *)((intptr_t)self + 0x1c);
  value7 = *(int *)((intptr_t)self + 0x28);
  local_c = -1 - local_18;
  local_1c = local_18 + 1;
  local_14 = local_18 + -1;
  local_34 = *(int *)((intptr_t)self + 0x24);
  local_4 = 1 - local_18;
  local_20 = 1;
  local_8 = -local_18;
  local_10 = 0xffffffff;
  if (arg3 != (int *)0x0) {
    local_34 = 0;
    value7 = 0;
  }
  value8 = *(int *)((intptr_t)self + 0x20) * local_18;
  value3 = *(int *)((intptr_t)self + 0x10) >> 1;
  value4 = (((value7 - *(int *)((intptr_t)self + 0x10)) + arg2) / value3) * local_18;
  if ((value4 < value8) ||
     (value4 = (value8 - local_18) + 1,
     value4 = value4 + (((value7 - *(int *)(*(int *)((intptr_t)self + 0x4c) + 4 + value4 * 0xc)) -
                      *(int *)((intptr_t)self + 0x10)) + arg2) / value3, value4 <= value8)) {
    value3 = (local_34 - *(int *)(*(int *)((intptr_t)self + 0x4c) + value4 * 0xc)) + arg1;
    if (-1 < value3) {
      value4 = value4 - (value3 / *(int *)((intptr_t)self + 0xc)) * local_14;
      local_30 = Map_ComputeObjectDistance(self,local_34,value7,arg1,arg2,value4);
      arg3 = &local_20;
      local_2c = 8;
      local_28 = value4;
      do {
        value3 = *arg3;
        value1 = Map_ComputeObjectDistance(self,local_34,value7,arg1,arg2,value4 + value3);
        if (value1 < local_30) {
          local_30 = value1;
          local_28 = value4 + value3;
        }
        arg3 = arg3 + 1;
        local_2c = local_2c + -1;
      } while (local_2c != 0);
      if (((-1 < local_28) && (local_28 != -1)) && (local_28 <= value8)) {
        if (arg4 == 0) {
          return *(int *)((intptr_t)self + 0x4c) + local_28 * 0xc;
        }
        value7 = *(int *)((intptr_t)self + 0x1c);
        uvalue5 = local_28 % value7;
        uvalue2 = local_28 / value7;
        uvalue6 = uvalue5 & 0x80000001;
        flag9 = uvalue6 == 0;
        if ((intptr_t)uvalue6 < 0) {
          flag9 = (uvalue6 - 1 | 0xfffffffe) == 0xffffffff;
        }
        if (!flag9) {
          uvalue5 = uvalue5 - 1;
        }
        uvalue6 = uvalue2 & 0x80000001;
        flag9 = uvalue6 == 0;
        if ((intptr_t)uvalue6 < 0) {
          flag9 = (uvalue6 - 1 | 0xfffffffe) == 0xffffffff;
        }
        if (!flag9) {
          uvalue2 = uvalue2 - 1;
        }
        return *(int *)((intptr_t)self + 0x4c) + (value7 * uvalue2 + uvalue5) * 0xc;
      }
    }
  }
  return 0;
}
