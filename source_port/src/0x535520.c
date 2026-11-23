// Text_SetMetrics: ported from Pizza Connection 2 at 0x535520.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x535520
#include "pc2_port.h"

void __thiscall Text_SetMetrics(void *self,uint32_t arg1,int arg2,uint32_t arg3)

{
  int value1;
  
  *(uint32_t *)((intptr_t)self + 0x9a0) = arg1;
  *(uint32_t *)((intptr_t)self + 0x9bc) = arg1;
  *(uint32_t *)((intptr_t)self + 0x9a8) = arg1;
  value1 = arg2 - *(int *)((intptr_t)self + 0x9b4);
  *(int *)((intptr_t)self + 0x9a4) = value1;
  *(int *)((intptr_t)self + 0x9c0) = value1;
  *(int *)((intptr_t)self + 0x9ac) = value1;
  *(uint32_t *)((intptr_t)self + 0x9c4) = arg3;
  return;
}
