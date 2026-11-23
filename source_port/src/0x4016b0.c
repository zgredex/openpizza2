// IDMap_RemoveRecursive: ported from Pizza Connection 2 at 0x4016b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4016b0
#include "pc2_port.h"

uint32_t __thiscall IDMap_RemoveRecursive(void *self,int arg1)

{
  uint32_t uvalue1;
  int value2;
  int *ptr3;
  
  if (99999 < arg1) {
    CS_Enter(0x579af0);
    value2 = 0;
    if (0 < *(int *)((intptr_t)self + 0xc)) {
      ptr3 = *(int **)((intptr_t)self + 8);
      do {
        if (*ptr3 == arg1) {
          IDMap_RemoveRecursive(self,value2);
          CS_Leave(0x579af0);
          return 1;
        }
        value2 = value2 + 1;
        ptr3 = ptr3 + 1;
      } while (value2 < *(int *)((intptr_t)self + 0xc));
    }
    CS_Leave(0x579af0);
    return 0;
  }
  if ((arg1 < 0) || (*(int *)((intptr_t)self + 0x10) <= arg1)) {
    return 0;
  }
  CS_Enter(0x579af0);
  *(int *)((intptr_t)self + 0x14) = *(int *)((intptr_t)self + 0x14) + -1;
  *(int *)((intptr_t)self + 0xc) = *(int *)((intptr_t)self + 0xc) + -1;
  value2 = (*(int *)((intptr_t)self + 0x10) - arg1) + -1;
  if (0 < value2) {
    uvalue1 = value2 * 4;
    _memmove((uint32_t *)(*(int *)((intptr_t)self + 8) + arg1 * 4),
             (uint32_t *)(*(int *)((intptr_t)self + 8) + 4 + arg1 * 4),uvalue1);
    _memmove((uint32_t *)(*(int *)((intptr_t)self + 4) + arg1 * 4),
             (uint32_t *)(*(int *)((intptr_t)self + 4) + 4 + arg1 * 4),uvalue1);
  }
  CS_Leave(0x579af0);
  return 1;
}
