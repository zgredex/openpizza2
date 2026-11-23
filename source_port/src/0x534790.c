// Record_GetScreenOffset: ported from Pizza Connection 2 at 0x534790.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x534790
#include "pc2_port.h"

void __thiscall Record_GetScreenOffset(void *self,int arg1,int *arg2,int *arg3)

{
  uint16_t uvalue1;
  int value2;
  int value3;
  int64_t lvalue4;
  
  if ((-1 < arg1) && (arg1 < *(int *)((intptr_t)self + 0x48))) {
    value2 = arg1 * 0x48;
    if (*(int *)(*(int *)((intptr_t)self + 0x4c) + value2) != -1) {
      value3 = *(short *)(*(int *)((intptr_t)self + 0x4c) + value2 + 0x32) * 2;
      lvalue4 = __ftol();
      *arg2 = (intptr_t)lvalue4 + ((intptr_t)*(short *)(*(int *)((intptr_t)self + 0x20) + value3) >> 2) +
                 (uint32_t)*(uint16_t *)(*(int *)((intptr_t)self + 0x28) + value3);
      uvalue1 = *(uint16_t *)
               (*(int *)((intptr_t)self + 0x2c) +
               *(short *)(*(int *)((intptr_t)self + 0x4c) + value2 + 0x32) * 2);
      lvalue4 = __ftol();
      *arg3 = (uint32_t)uvalue1 + (intptr_t)lvalue4;
    }
  }
  return;
}
