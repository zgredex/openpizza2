// Player_InitSlotFlags: ported from Pizza Connection 2 at 0x4e3dd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e3dd0
#include "pc2_port.h"

void __thiscall Player_InitSlotFlags(void *self,int arg1)

{
  *(uint8_t *)(arg1 + 0xac + (intptr_t)self) = 1;
  *(uint32_t *)((intptr_t)self + arg1 * 4 + 0xcc) = 0;
  *(uint32_t *)((intptr_t)self + arg1 * 4 + 0xb4) = 0;
  return;
}
