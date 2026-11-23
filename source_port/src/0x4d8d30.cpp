// Player_SetSlotFlag18: ported from Pizza Connection 2 at 0x4d8d30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d8d30
#include "pc2_port.h"

void __thiscall Player_SetSlotFlag18(void *self,int arg1)

{
  *(uint8_t *)((intptr_t)self + arg1 * 0x18 + 0x10e5) = 1;
  return;
}
