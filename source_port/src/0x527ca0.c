// UI_ClearField230: ported from Pizza Connection 2 at 0x527ca0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x527ca0
#include "pc2_port.h"

void __thiscall UI_ClearField230(void *self,int arg1)

{
  if (*(int *)((intptr_t)self + 0x230) == arg1) {
    *(uint32_t *)((intptr_t)self + 0x230) = 0;
  }
  return;
}
