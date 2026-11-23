// Text_GetPosition: ported from Pizza Connection 2 at 0x5355b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5355b0
#include "pc2_port.h"

void __thiscall Text_GetPosition(void *self,uint32_t *arg1,uint32_t *arg2)

{
  *arg1 = *(uint32_t *)((intptr_t)self + 0x9a0);
  *arg2 = *(uint32_t *)((intptr_t)self + 0x9a4);
  return;
}
