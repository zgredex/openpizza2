// Person_SetMotivation: ported from Pizza Connection 2 at 0x4d4120.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d4120
#include "pc2_port.h"

void __thiscall Person_SetMotivation(void *self,uint32_t arg1)

{
  *(uint32_t *)((intptr_t)self + 0xc) = arg1;
  Game_ResetPlayerStatsByCity((intptr_t)self);
  return;
}
