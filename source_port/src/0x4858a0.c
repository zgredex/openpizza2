// Game_SetLockedField2FC: ported from Pizza Connection 2 at 0x4858a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4858a0
#include "pc2_port.h"

void __thiscall Game_SetLockedField2FC(void *self,uint32_t arg1)

{
  CS_Enter(*(int *)((intptr_t)self + 0x240));
  *(uint32_t *)((intptr_t)self + 0x2fc) = arg1;
  CS_Leave(*(int *)((intptr_t)self + 0x240));
  return;
}
