// Record_ApplyVariantState: ported from Pizza Connection 2 at 0x533af0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x533af0
#include "pc2_port.h"

uint32_t __thiscall
Record_ApplyVariantState(void *self,int arg1,int arg2,uint8_t arg3)

{
  int value1;
  int value2;
  
  if ((-1 < arg1) && (arg1 < *(int *)((intptr_t)self + 0x48))) {
    value2 = arg1 * 0x48;
    value1 = *(int *)(*(int *)((intptr_t)self + 0x4c) + value2);
    if ((value1 != -1) &&
       (((-1 < arg2 && (arg2 < 0x10)) &&
        (*(short *)(*(int *)((intptr_t)self + 0x50) + value1 * 0x98 + arg2 * 6) != -1)))) {
      *(uint8_t *)(*(int *)((intptr_t)self + 0x4c) + value2 + 0x3e) = 1;
      *(uint8_t *)(*(int *)((intptr_t)self + 0x4c) + 0x3c + value2) = 0;
      *(uint8_t *)(*(int *)((intptr_t)self + 0x4c) + 0x3d + value2) = 0;
      *(uint8_t *)(*(int *)((intptr_t)self + 0x4c) + 0x40 + value2) = 0;
      *(uint8_t *)(*(int *)((intptr_t)self + 0x4c) + 0x3f + value2) = 0;
      Record_SetVariant(self,arg1,arg2);
      *(uint8_t *)(*(int *)((intptr_t)self + 0x4c) + 0x3d + value2) = arg3;
      return 1;
    }
  }
  return 0;
}
