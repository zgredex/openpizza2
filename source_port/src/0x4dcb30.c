// Game_IncrementPlayerCounterC20: ported from Pizza Connection 2 at 0x4dcb30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dcb30
#include "pc2_port.h"

void __thiscall Game_IncrementPlayerCounterC20(void *self,int arg1)

{
  uint16_t uvalue1;
  int value2;
  
  *(int *)((intptr_t)self + arg1 * 4 + 0xc20) = *(int *)((intptr_t)self + arg1 * 4 + 0xc20) + 1;
  uvalue1 = *(uint16_t *)(*(int *)((intptr_t)DAT_0057c670 + 0x94) + 10);
  value2 = Game_GetPlayerBySlot(DAT_0057c670,arg1);
  *(uint32_t *)(value2 + 0x60) = (uint32_t)uvalue1;
  return;
}
