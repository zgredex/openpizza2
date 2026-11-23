// Game_SetChildField94: ported from Pizza Connection 2 at 0x4808a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4808a0
#include "pc2_port.h"

void __thiscall Game_SetChildField94(void *self,uint32_t arg1)

{
  *(uint32_t *)(*(int *)((intptr_t)self + 0x16f0) + 0x94) = arg1;
  return;
}
