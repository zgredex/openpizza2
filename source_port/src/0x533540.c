// Get_WidthHeight: ported from Pizza Connection 2 at 0x533540.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x533540
#include "pc2_port.h"

void __thiscall Get_WidthHeight(void *self,uint32_t *arg1,uint32_t *arg2)

{
  *arg1 = (uint32_t)*(uint16_t *)((intptr_t)self + 0x12);
  *arg2 = (uint32_t)*(uint16_t *)((intptr_t)self + 0x14);
  return;
}
