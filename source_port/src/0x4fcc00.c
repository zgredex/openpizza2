// Game_AdjustPlayerPercentByKey: ported from Pizza Connection 2 at 0x4fcc00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fcc00
#include "pc2_port.h"

void __thiscall Game_AdjustPlayerPercentByKey(void *self,int arg1)

{
  int value1;
  int *ptr2;
  
  value1 = 0;
  ptr2 = (int *)((intptr_t)self + 0x40);
  do {
    if (*ptr2 == arg1) {
      Object_AdjustShortPercent(self,value1,5);
      return;
    }
    value1 = value1 + 1;
    ptr2 = ptr2 + 0x5a;
  } while (value1 < 6);
  return;
}
