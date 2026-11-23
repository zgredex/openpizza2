// UI_SetChildPosition: ported from Pizza Connection 2 at 0x5237e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5237e0
#include "pc2_port.h"

void __thiscall UI_SetChildPosition(void *self,uint32_t arg1,uint32_t arg2)

{
  int value1;
  
  value1 = *(int *)((intptr_t)self + 0x240);
  if (value1 != 0) {
    *(uint32_t *)(value1 + 0x5c) = arg1;
    *(uint32_t *)(value1 + 0x60) = arg2;
  }
  return;
}
