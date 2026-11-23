// Game_GetDateFields: ported from Pizza Connection 2 at 0x48b3c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48b3c0
#include "pc2_port.h"

void __thiscall Game_GetDateFields(void *self,uint32_t *arg1,int *arg2)

{
  *arg1 = (uint32_t)*(uint8_t *)(*(int *)((intptr_t)self + 0x94) + 7);
  *arg2 = (uint32_t)*(uint8_t *)(*(int *)((intptr_t)self + 0x94) + 6) * 5;
  return;
}
