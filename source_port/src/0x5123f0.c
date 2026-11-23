// Screen_AccumulateColorHistogram: ported from Pizza Connection 2 at 0x5123f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5123f0
#include "pc2_port.h"

/* WARNING: Type propagation algorithm not settling */

void __thiscall Screen_AccumulateColorHistogram(void *self,int arg1,int arg2)

{
  uint8_t flag1;
  int value2;
  int *ptr3;
  int value4;
  int value5;
  int value6;
  int *ptr7;
  int value8;
  int64_t lvalue9;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_70;
  int local_64 [25];
  
  ptr7 = local_64;
  for (value4 = 0x18; ptr7 = ptr7 + 1, value4 != 0; value4 = value4 + -1) {
    *ptr7 = 0;
  }
  value2 = *(int *)(arg1 + 0x14);
  value8 = *(int *)(DAT_0057c670 + 0xa8 + (uint32_t)*(uint8_t *)(arg1 + 4) * 4);
  local_78 = *(int *)(arg1 + 0x18);
  local_80 = 0;
  value4 = (uint32_t)*(uint8_t *)(arg1 + 0x10) + (uint32_t)*(uint8_t *)(arg1 + 6) * 8;
  value5 = (intptr_t)*(short *)(value8 + 8 + value4 * 2);
  local_7c = (intptr_t)*(short *)(value8 + 0x48 + value4 * 2);
  if (value5 <= local_7c) {
    local_7c = value5;
  }
  if (0 < local_7c) {
    local_84 = 0;
    if (local_78 < 0) {
      local_84 = -local_78;
    }
    if (599 < local_78) {
      local_84 = local_78 + -599;
    }
    if (local_84 < local_7c) {
      local_70 = local_84 + local_78;
      local_78 = local_78 - local_84;
      value8 = local_70 * 800 + arg2;
      value4 = local_78 * 800 + arg2;
      do {
        if ((599 < local_70) && (local_78 < 0)) break;
        __ftol();
        lvalue9 = __ftol();
        value5 = (intptr_t)lvalue9;
        if ((local_70 < 599) && (-1 < local_70)) {
          for (value6 = value2 - value5; value6 < value5 + value2; value6 = value6 + 1) {
            if ((((-1 < value6) && (value6 < 799)) && (flag1 = *(uint8_t *)(value8 + value6), flag1 != 0))
               && (flag1 != 0xff)) {
              local_80 = local_80 + 1;
              local_64[flag1] = local_64[flag1] + 1;
            }
          }
        }
        if ((local_78 < 599) && (-1 < local_78)) {
          for (value6 = value2 - value5; value6 < value2 + value5; value6 = value6 + 1) {
            if (((-1 < value6) && (value6 < 799)) &&
               ((flag1 = *(uint8_t *)(value4 + value6), flag1 != 0 && (flag1 != 0xff)))) {
              local_80 = local_80 + 1;
              local_64[flag1] = local_64[flag1] + 1;
            }
          }
        }
        local_84 = local_84 + 1;
        value8 = value8 + 800;
        local_70 = local_70 + 1;
        value4 = value4 + -800;
        local_78 = local_78 + -1;
      } while (local_84 < local_7c);
      if (0 < local_80) {
        ptr7 = local_64;
        ptr3 = (int *)((intptr_t)self + 0x1e0);
        value4 = 0x18;
        do {
          ptr7 = ptr7 + 1;
          *ptr3 = *ptr3 + *ptr7;
          ptr3 = ptr3 + 1;
          value4 = value4 + -1;
        } while (value4 != 0);
      }
    }
  }
  return;
}
