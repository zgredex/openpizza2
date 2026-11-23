// Record_ClearFlags48: ported from Pizza Connection 2 at 0x533a70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x533a70
#include "pc2_port.h"

void __thiscall Record_ClearFlags48(void *self,int arg1)

{
  int *ptr1;
  
  if ((-1 < arg1) && (arg1 < *(int *)((intptr_t)self + 0x48))) {
    ptr1 = (int *)(*(int *)((intptr_t)self + 0x4c) + arg1 * 0x48);
    if (*ptr1 != -1) {
      *(uint8_t *)((intptr_t)ptr1 + 0x3e) = 0;
      *(uint8_t *)(*(int *)((intptr_t)self + 0x4c) + 0x3c + arg1 * 0x48) = 0;
    }
  }
  return;
}
