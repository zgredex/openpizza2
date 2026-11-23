// UI_SetModalHandler: ported from Pizza Connection 2 at 0x527cc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x527cc0
#include "pc2_port.h"

void __thiscall UI_SetModalHandler(void *self,uint32_t arg1,int *arg2)

{
  *(uint32_t *)((intptr_t)self + 0x8338) = arg1;
  *(uint32_t *)((intptr_t)self + 0x8348) = *(uint32_t *)((intptr_t)self + 0x8340);
  *(int **)((intptr_t)self + 0x833c) = arg2;
  (**(code **)(*arg2 + 0xc))(0x3c,0,0);
  return;
}
