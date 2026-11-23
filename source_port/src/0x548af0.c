// Sound_UpdateProximityGain: ported from Pizza Connection 2 at 0x548af0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x548af0
#include "pc2_port.h"

void __fastcall Sound_UpdateProximityGain(void *arg1)

{
  void *self;
  int value1;
  int value2;
  int value3;
  int *ptr4;
  int value5;
  int value6;
  int value7;
  int value8;
  uint64_t uvalue9;
  int64_t lvalue10;
  float local_24;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint32_t uStack_8;
  int local_4;
  
  local_4 = (intptr_t)arg1 + 0x178;
  CS_Enter(local_4);
  if (*(char *)((intptr_t)arg1 + 0x169) != '\0') {
    value5 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
    local_24 = 0.0;
    self = *(void **)(DAT_0057c5cc + 0x2c3d4);
    value1 = *(int *)(*(int *)(value5 + 0xfa8) + 0xe8);
    local_c = *(int *)(DAT_0057c670 + 0x2da0);
    value5 = *(int *)(*(int *)(value5 + 0xfa8) + 0xec);
    local_10 = 0x2c41c;
    value8 = local_c * 0xc;
    value2 = *(int *)(&DAT_005752d8 + value8);
    value3 = *(int *)(&DAT_005752dc + value8);
    do {
      value6 = *(int *)(local_10 + DAT_0057c5cc);
      if (((-1 < value6) && (value6 < *(int *)((intptr_t)self + 0x48))) &&
         (*(char *)(*(int *)((intptr_t)self + 0x4c) + 0x3e + value6 * 0x48) != '\0')) {
        local_18 = 0;
        local_14 = 0;
        uvalue9 = Record_GetTwoFloats48(self,value6,&local_18,&local_14);
        if ((intptr_t)uvalue9 != 0) {
          value7 = (local_14 + 0x100) - (value3 + value5);
          value6 = (local_18 + 0x100) - (value2 + value1);
          local_14 = value7 * value7 + value6 * value6;
          lvalue10 = __ftol();
          local_14 = (intptr_t)lvalue10;
          local_18 = *(int *)(&DAT_005752e0 + value8);
          if (local_14 <= local_18) {
            local_24 = (0.33333334 - ((float)local_14 / (float)local_18) * 0.33333334) + local_24;
          }
        }
      }
      local_10 = local_10 + 4;
    } while (local_10 < 0x2c434);
    if (0.0 < local_24) {
      if (*(char *)((intptr_t)arg1 + 0x140) == '\0') {
        Sound_SetPosition(arg1,*(uint32_t *)((intptr_t)arg1 + 0x80));
        *(uint8_t *)((intptr_t)arg1 + 0x140) = 1;
        CS_Leave(local_4);
        return;
      }
      local_c = *(uint32_t *)((intptr_t)arg1 + 0x1d0);
      uStack_8 = 0;
      ptr4 = *(int **)((intptr_t)arg1 + 8);
      value1 = *ptr4;
      lvalue10 = __ftol();
      (**(code **)(value1 + 0x7c))(ptr4,*(uint32_t *)((intptr_t)arg1 + 0x80),(intptr_t)lvalue10);
      CS_Leave(local_10);
      return;
    }
    if (*(char *)((intptr_t)arg1 + 0x140) != '\0') {
      (**(code **)(**(int **)((intptr_t)arg1 + 8) + 0x68))
                (*(int **)((intptr_t)arg1 + 8),*(uint32_t *)((intptr_t)arg1 + 0x80));
      *(uint8_t *)((intptr_t)arg1 + 0x140) = 0;
    }
  }
  CS_Leave(local_4);
  return;
}
