// Record_SetVariant: ported from Pizza Connection 2 at 0x533b90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x533b90
#include "pc2_port.h"

void __thiscall Record_SetVariant(void *self,int arg1,int arg2)

{
  uint16_t *uptr1;
  int value2;
  int value3;
  int64_t lvalue4;
  
  value3 = arg1 * 0x48;
  uptr1 = (uint16_t *)
           (*(int *)((intptr_t)self + 0x50) + *(int *)(*(int *)((intptr_t)self + 0x4c) + value3) * 0x98 +
           arg2 * 6);
  if ((char)uptr1[2] == -1) {
    Record_ClearFlags48(self,arg1);
    return;
  }
  *(uint16_t *)(*(int *)((intptr_t)self + 0x4c) + value3 + 0x32) = *uptr1;
  *(uint16_t *)(*(int *)((intptr_t)self + 0x4c) + 0x36 + value3) = 0;
  *(short *)(*(int *)((intptr_t)self + 0x4c) + 0x34 + value3) = (short)arg2;
  value2 = *(int *)((intptr_t)self + 0x4c);
  lvalue4 = __ftol();
  *(short *)(value2 + value3 + 0x3a) = (short)lvalue4;
  if (uptr1[1] < *uptr1) {
    *(uint8_t *)(*(int *)((intptr_t)self + 0x4c) + 0x38 + value3) = 0xff;
    return;
  }
  *(uint8_t *)(*(int *)((intptr_t)self + 0x4c) + 0x38 + value3) = 1;
  return;
}
