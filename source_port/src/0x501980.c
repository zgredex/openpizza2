// Game_GetRandomPlayerRecordValue: ported from Pizza Connection 2 at 0x501980.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x501980
#include "pc2_port.h"

uint32_t __thiscall Game_GetRandomPlayerRecordValue(void *self,int arg1)

{
  uint32_t uvalue1;
  int value2;
  
  uvalue1 = *(uint32_t *)(*(int *)((intptr_t)self + arg1 * 0x168 + 0x70) + 0x15c);
  if (uvalue1 == 0) {
    return 0xffffffff;
  }
  uvalue1 = Random_Mod(uvalue1);
  value2 = IDMap_Lookup((void *)(*(int *)((intptr_t)self + arg1 * 0x168 + 0x70) + 0x148),uvalue1,
                       (int *)0x0);
  return *(uint32_t *)(value2 + 0x3c);
}
