// UI_GetOuterRect: ported from Pizza Connection 2 at 0x5288b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5288b0
#include "pc2_port.h"

void __thiscall UI_GetOuterRect(void *self,uint32_t *arg1)

{
  *arg1 = *(uint32_t *)((intptr_t)self + 0x38);
  arg1[1] = *(uint32_t *)((intptr_t)self + 0x3c);
  arg1[2] = *(int *)((intptr_t)self + 0x28) + *(int *)((intptr_t)self + 0x30) * 2 +
               *(int *)((intptr_t)self + 0x38);
  arg1[3] = *(int *)((intptr_t)self + 0x2c) + *(int *)((intptr_t)self + 0x34) * 2 +
               *(int *)((intptr_t)self + 0x3c);
  return;
}
