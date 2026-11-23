// Grid_CollectType351: ported from Pizza Connection 2 at 0x4f55e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f55e0
#include "pc2_port.h"

void __thiscall Grid_CollectType351(void *self,int arg1)

{
  int value1;
  int value2;
  int *ptr3;
  int value4;
  int value5;
  int value6;
  int local_4;
  
  value2 = 0;
  value4 = 0;
  local_4 = 0;
  if (0 < *(int *)((intptr_t)self + 0x20)) {
    do {
      value5 = 0;
      if (0 < *(int *)((intptr_t)self + 0x1c)) {
        value6 = value4 * 0xc;
        ptr3 = (int *)(arg1 + value2 * 8);
        do {
          value1 = *(int *)(value6 + 8 + *(int *)((intptr_t)self + 0x4c));
          if ((value1 != 0) && (*(int *)(value1 + 4) == 0x351)) {
            *ptr3 = value5;
            ptr3[1] = local_4;
            value2 = value2 + 1;
            ptr3 = ptr3 + 2;
            if (0x50 < value2) {
              return;
            }
          }
          value4 = value4 + 1;
          value6 = value6 + 0xc;
          value5 = value5 + 1;
        } while (value5 < *(int *)((intptr_t)self + 0x1c));
      }
      local_4 = local_4 + 1;
    } while (local_4 < *(int *)((intptr_t)self + 0x20));
  }
  return;
}
