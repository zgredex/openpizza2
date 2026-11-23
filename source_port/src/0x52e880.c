// Window_GetRect: ported from Pizza Connection 2 at 0x52e880.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52e880
#include "pc2_port.h"

void __thiscall Window_GetRect(void *self,uint32_t *arg1)

{
  *arg1 = *(uint32_t *)((intptr_t)self + 0xc);
  arg1[1] = *(uint32_t *)((intptr_t)self + 0x10);
  arg1[2] = *(int *)((intptr_t)self + 4) + *(int *)((intptr_t)self + 0xc);
  arg1[3] = *(int *)((intptr_t)self + 8) + *(int *)((intptr_t)self + 0x10);
  return;
}
