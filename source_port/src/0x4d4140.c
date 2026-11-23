// Person_SetSpeed: ported from Pizza Connection 2 at 0x4d4140.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d4140
#include "pc2_port.h"

void __thiscall Person_SetSpeed(void *self,uint32_t arg1)

{
  *(uint32_t *)((intptr_t)self + 8) = arg1;
  Game_ResetPlayerStatsByCity((intptr_t)self);
  return;
}
