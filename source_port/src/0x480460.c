// Game_FindNearestRecordAndAngle: ported from Pizza Connection 2 at 0x480460.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x480460
#include "pc2_port.h"

int __thiscall Game_FindNearestRecordAndAngle(void *self,int arg1,int *arg2,uint32_t *arg3)

{
  int value1;
  int value2;
  int value3;
  int value4;
  int value5;
  int64_t lvalue6;
  float local_32c;
  int local_328;
  
  value5 = 0;
  local_328 = 0;
  local_32c = 0.0;
  value1 = Get_Field19F4((intptr_t)self);
  value2 = 0;
  if (0 < value1) {
    do {
      value2 = IDMap_Lookup((void *)((intptr_t)self + 0x19e0),value5,(int *)0x0);
      value2 = *(int *)(value2 + 0x20);
      value3 = Array_GetRecord28(*(void **)((intptr_t)self + 0x14e0),1,
                                (intptr_t)*(short *)(*(int *)(*(int *)((intptr_t)*(void **)((intptr_t)self + 0x14e0
                                                                                 ) + 0x4c) +
                                                         value2 * 0xc + 8) + 0x24));
      value4 = Map_FindShortestPath();
      if ((value5 == 0) || (value4 < (intptr_t)local_32c)) {
        *arg2 = value2;
        local_32c = (float)value4;
        local_328 = value3;
      }
      value5 = value5 + 1;
    } while (value5 < value1);
    value2 = local_328;
    if (local_328 != 0) {
      local_32c = (float)(*(int *)(local_328 + 0x10) - *(int *)(arg1 + 0x10));
      if (local_32c == 0.0) {
        local_32c = 1.0;
      }
      fpatan((double)(*(int *)(local_328 + 0xc) - *(int *)(arg1 + 0xc)) / (double)local_32c,
             (double)1);
      lvalue6 = __ftol();
      *arg3 = -(-(intptr_t)lvalue6 - 1U & 7) & 7;
    }
  }
  return value2;
}
