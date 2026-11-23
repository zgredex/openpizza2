// Array_RemoveAt: ported from Pizza Connection 2 at 0x522fe0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x522fe0
#include "pc2_port.h"

uint32_t __thiscall Array_RemoveAt(void *self,int arg1)

{
  int value1;
  
  if ((arg1 < 0) || (*(int *)((intptr_t)self + 0xc) <= arg1)) {
    return 0;
  }
  CS_Enter(0x584180);
  *(int *)((intptr_t)self + 8) = *(int *)((intptr_t)self + 8) + -1;
  *(int *)((intptr_t)self + 0x10) = *(int *)((intptr_t)self + 0x10) + -1;
  value1 = (*(int *)((intptr_t)self + 0xc) - arg1) + -1;
  if (0 < value1) {
    _memmove((uint32_t *)(*(int *)((intptr_t)self + 4) + arg1 * 4),
             (uint32_t *)(*(int *)((intptr_t)self + 4) + 4 + arg1 * 4),value1 * 4);
  }
  CS_Leave(0x584180);
  return 1;
}
