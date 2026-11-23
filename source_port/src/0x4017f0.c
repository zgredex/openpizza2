// IDMap_Lookup: ported from Pizza Connection 2 at 0x4017f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4017f0
#include "pc2_port.h"

uint32_t __thiscall IDMap_Lookup(void *self,int arg1,int *arg2)

{
  int value1;
  int value2;
  int value3;
  int value4;
  
  if (arg1 < 100000) {
    if ((-1 < arg1) && (arg1 < *(int *)((intptr_t)self + 0xc))) {
      if (arg2 != (int *)0x0) {
        *arg2 = *(int *)(*(int *)((intptr_t)self + 8) + arg1 * 4);
      }
      return *(uint32_t *)(*(int *)((intptr_t)self + 4) + arg1 * 4);
    }
  }
  else {
    value4 = *(int *)((intptr_t)self + 0xc);
    if (value4 != 0) {
      value2 = value4 + -1;
      value3 = 0;
      if (0 < value4 + -2) {
        value4 = value3;
        do {
          value3 = value2 + value4 >> 1;
          value1 = *(int *)(*(int *)((intptr_t)self + 8) + value3 * 4);
          if (value1 == arg1) {
            if (arg2 != (int *)0x0) {
              *arg2 = value3;
            }
            return *(uint32_t *)(*(int *)((intptr_t)self + 4) + value3 * 4);
          }
          if (arg1 < value1) {
            value2 = value3;
            value3 = value4;
          }
          value4 = value3;
        } while (value3 < value2 + -1);
      }
      if (*(int *)(*(int *)((intptr_t)self + 8) + value3 * 4) == arg1) {
        if (arg2 != (int *)0x0) {
          *arg2 = value3;
        }
        return *(uint32_t *)(*(int *)((intptr_t)self + 4) + value3 * 4);
      }
      if (*(int *)(*(int *)((intptr_t)self + 8) + value2 * 4) == arg1) {
        if (arg2 != (int *)0x0) {
          *arg2 = value2;
        }
        return *(uint32_t *)(*(int *)((intptr_t)self + 4) + value2 * 4);
      }
    }
  }
  return 0;
}
