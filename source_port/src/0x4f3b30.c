// Object_GetRect100: ported from Pizza Connection 2 at 0x4f3b30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f3b30
#include "pc2_port.h"

void __thiscall
Object_GetRect100(void *self,uint32_t *arg1,uint32_t *arg2,uint32_t *arg3,
                 uint32_t *arg4)

{
  *arg1 = *(uint32_t *)((intptr_t)self + 0x100);
  *arg2 = *(uint32_t *)((intptr_t)self + 0x108);
  *arg3 = *(uint32_t *)((intptr_t)self + 0x104);
  *arg4 = *(uint32_t *)((intptr_t)self + 0x10c);
  return;
}
