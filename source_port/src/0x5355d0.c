// Text_SetCursor: ported from Pizza Connection 2 at 0x5355d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5355d0
#include "pc2_port.h"

void __thiscall Text_SetCursor(void *self,uint32_t arg1,uint32_t arg2)

{
  *(uint32_t *)((intptr_t)self + 0x9a0) = arg1;
  *(uint32_t *)((intptr_t)self + 0x9a4) = arg2;
  return;
}
