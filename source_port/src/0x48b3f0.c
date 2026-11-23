// Game_GetYearAndWeekday: ported from Pizza Connection 2 at 0x48b3f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48b3f0
#include "pc2_port.h"

void __thiscall Game_GetYearAndWeekday(void *self,uint32_t *arg1,uint32_t *arg2)

{
  *arg1 = (uint32_t)*(uint8_t *)(*(int *)((intptr_t)self + 0x94) + 8);
  *arg2 = (uint32_t)*(uint16_t *)(*(int *)((intptr_t)self + 0x94) + 4);
  return;
}
