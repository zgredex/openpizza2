// Dialog_SetResult: ported from Pizza Connection 2 at 0x526850.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x526850
#include "pc2_port.h"

void __thiscall Dialog_SetResult(void *self,uint32_t arg1)

{
  *(uint32_t *)((intptr_t)self + 0x280) = 1;
  *(uint32_t *)((intptr_t)self + 0x27c) = arg1;
  return;
}
