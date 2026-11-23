// Text_SetMetrics2: ported from Pizza Connection 2 at 0x535570.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x535570
#include "pc2_port.h"

void __thiscall
Text_SetMetrics2(void *self,uint32_t arg1,uint32_t arg2,uint32_t arg3)

{
  *(uint32_t *)((intptr_t)self + 0x9a0) = arg1;
  *(uint32_t *)((intptr_t)self + 0x9bc) = arg1;
  *(uint32_t *)((intptr_t)self + 0x9a8) = arg1;
  *(uint32_t *)((intptr_t)self + 0x9a4) = arg2;
  *(uint32_t *)((intptr_t)self + 0x9c0) = arg2;
  *(uint32_t *)((intptr_t)self + 0x9ac) = arg2;
  *(uint32_t *)((intptr_t)self + 0x9c4) = arg3;
  return;
}
