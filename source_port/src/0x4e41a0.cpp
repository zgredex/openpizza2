// Game_CountGroupSlots: ported from Pizza Connection 2 at 0x4e41a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e41a0
#include "pc2_port.h"

void __thiscall Game_CountGroupSlots(void *self,int arg1)

{
  int value1;
  short *psVar2;
  
  value1 = 0;
  psVar2 = (short *)((intptr_t)self + (arg1 * 3 + 0x1e) * 4);
  do {
    if (*psVar2 == -1) {
      return;
    }
    value1 = value1 + 1;
    psVar2 = psVar2 + 1;
  } while (value1 < 6);
  return;
}
