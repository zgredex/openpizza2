// UI_SetAbsolutePosition: ported from Pizza Connection 2 at 0x520b40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x520b40
#include "pc2_port.h"

void __thiscall UI_SetAbsolutePosition(void *self,int arg1,int arg2)

{
  *(int *)((intptr_t)self + 0x30) = *(int *)((intptr_t)self + 0x28) + arg1;
  *(int *)((intptr_t)self + 0x34) = *(int *)((intptr_t)self + 0x2c) + arg2;
  return;
}
