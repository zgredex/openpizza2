// Game_FindGroupSlot: ported from Pizza Connection 2 at 0x4e42c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e42c0
#include "pc2_port.h"

int __thiscall Game_FindGroupSlot(void *self,int arg1,int arg2)

{
  int value1;
  short *psVar2;
  
  value1 = 0;
  psVar2 = (short *)((intptr_t)self + (arg2 * 3 + 0x1e) * 4);
  do {
    if (arg1 == *psVar2) {
      return value1;
    }
    value1 = value1 + 1;
    psVar2 = psVar2 + 1;
  } while (value1 < 6);
  return -1;
}
