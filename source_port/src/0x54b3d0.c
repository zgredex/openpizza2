// Array_Grow: ported from Pizza Connection 2 at 0x54b3d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54b3d0
#include "pc2_port.h"

int __thiscall Array_Grow(void *self,uint32_t arg1)

{
  uint32_t *uptr1;
  uint32_t uvalue2;
  int value3;
  uint32_t *uptr4;
  uint32_t *uptr5;
  
  if (*(int *)((intptr_t)self + 8) <= *(int *)((intptr_t)self + 4)) {
    uptr1 = operator_new(*(int *)((intptr_t)self + 8) * 4 + 0x50);
    uptr4 = *(uint32_t **)self;
    uptr5 = uptr1;
    for (uvalue2 = *(uint32_t *)((intptr_t)self + 4) & 0x3fffffff; uvalue2 != 0; uvalue2 = uvalue2 - 1) {
      *uptr5 = *uptr4;
      uptr4 = uptr4 + 1;
      uptr5 = uptr5 + 1;
    }
    for (value3 = 0; value3 != 0; value3 = value3 + -1) {
      *(uint8_t *)uptr5 = *(uint8_t *)uptr4;
      uptr4 = (uint32_t *)((intptr_t)uptr4 + 1);
      uptr5 = (uint32_t *)((intptr_t)uptr5 + 1);
    }
    Mem_Free(*(LPVOID *)self);
    *(uint32_t **)self = uptr1;
    *(int *)((intptr_t)self + 8) = *(int *)((intptr_t)self + 8) + 0x14;
  }
  *(uint32_t *)(*(int *)self + *(int *)((intptr_t)self + 4) * 4) = arg1;
  value3 = *(int *)((intptr_t)self + 4);
  *(int *)((intptr_t)self + 4) = value3 + 1;
  return value3;
}
