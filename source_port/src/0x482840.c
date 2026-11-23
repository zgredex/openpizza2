// Game_GetPlayerField8: ported from Pizza Connection 2 at 0x482840.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x482840
#include "pc2_port.h"

uint32_t __thiscall Game_GetPlayerField8(void *self,int arg1)

{
  int value1;
  
  value1 = *(int *)((intptr_t)self + arg1 * 4 + 0x224);
  if (value1 == 0) {
    return 0xffffffff;
  }
  return *(uint32_t *)(value1 + 8);
}
