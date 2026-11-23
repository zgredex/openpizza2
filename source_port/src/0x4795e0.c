// Stats_GetAverageValue: ported from Pizza Connection 2 at 0x4795e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4795e0
#include "pc2_port.h"

void __thiscall Stats_GetAverageValue(void *self,int arg1)

{
  int value1;
  int value2;
  
  value1 = Map_CountEdgeMatchedTiles(self,arg1);
  value2 = Game_CountPlayersByByte(self,2);
  if (value2 < 1) {
    *(uint32_t *)((intptr_t)self + 0x1864) = 0;
    return;
  }
  *(int *)((intptr_t)self + 0x1864) = value1 / value2;
  return;
}
