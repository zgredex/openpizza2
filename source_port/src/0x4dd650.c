// Game_SetGlobalWord16: ported from Pizza Connection 2 at 0x4dd650.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dd650
#include "pc2_port.h"

void __thiscall Game_SetGlobalWord16(void *self,uint16_t arg1)

{
  *(uint16_t *)((intptr_t)self + 4) = arg1;
  DAT_0057dfbc = (uint32_t)arg1;
  return;
}
