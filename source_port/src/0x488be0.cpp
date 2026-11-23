// Game_GetPlayerBySlot: ported from Pizza Connection 2 at 0x488be0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x488be0
#include "pc2_port.h"

uint32_t __thiscall Game_GetPlayerBySlot(void *self,int arg1)

{
  if ((arg1 < 0) || (5 < arg1)) {
    return 0;
  }
  return *(uint32_t *)((intptr_t)self + arg1 * 4 + 0x200);
}
