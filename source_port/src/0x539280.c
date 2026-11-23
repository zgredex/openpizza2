// Surface_Configure: ported from Pizza Connection 2 at 0x539280.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x539280
#include "pc2_port.h"

void __thiscall
Surface_Configure(void *self,uint32_t arg1,uint16_t arg2,uint16_t arg3,int arg4)

{
  Surface_Release((intptr_t)self);
  *(uint32_t *)((intptr_t)self + 0x28) = arg1;
  *(uint16_t *)((intptr_t)self + 0x1c) = arg3;
  *(uint16_t *)((intptr_t)self + 0x1a) = arg2;
  *(uint32_t *)((intptr_t)self + 0xc) = 0;
  *(uint32_t *)((intptr_t)self + 4) = 0;
  *(uint32_t *)((intptr_t)self + 8) = (uint32_t)arg2;
  *(uint32_t *)((intptr_t)self + 0x10) = (uint32_t)arg3;
  *(int *)((intptr_t)self + 0x20) = arg4 >> 1;
  *(uint32_t *)((intptr_t)self + 0x14) = 0;
  SetRect((LPRECT)((intptr_t)self + 100),0,0,(uint32_t)arg2,(uint32_t)arg3);
  return;
}
