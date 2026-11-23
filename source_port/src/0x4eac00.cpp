// Game_GetRecordChild14: ported from Pizza Connection 2 at 0x4eac00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4eac00
#include "pc2_port.h"

uint32_t __thiscall Game_GetRecordChild14(void *self,int arg1)

{
  int value1;
  
  if (arg1 < 0) {
    return 0;
  }
  value1 = *(int *)((intptr_t)self + arg1 * 0x48 + 0x68);
  if (value1 == 0) {
    return 0;
  }
  return *(uint32_t *)(value1 + 0x14);
}
