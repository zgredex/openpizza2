// Game_IncrementVisitCounter: ported from Pizza Connection 2 at 0x47fd50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47fd50
#include "pc2_port.h"

void __thiscall Game_IncrementVisitCounter(void *self,int arg1)

{
  short *psVar1;
  
  *(short *)((intptr_t)self + 0x16c0) = *(short *)((intptr_t)self + 0x16c0) + 1;
  if ((-1 < arg1) && (arg1 < 8)) {
    psVar1 = (short *)((intptr_t)self + arg1 * 2 + 0x16c2);
    *psVar1 = *psVar1 + 1;
  }
  return;
}
