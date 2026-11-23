// Object_AdjustShortPercent: ported from Pizza Connection 2 at 0x4fcc30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fcc30
#include "pc2_port.h"

void __thiscall Object_AdjustShortPercent(void *self,int arg1,short arg2)

{
  short *psVar1;
  int value2;
  
  value2 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  if (value2 == 0) {
    value2 = 0;
  }
  else {
    value2 = value2 + 4;
  }
  value2 = *(int *)(value2 + 0x33c);
  if ((DAT_0057bb20 != '\0') || (((value2 != 4 && (value2 != 6)) && (value2 != 9)))) {
    psVar1 = (short *)((intptr_t)self + arg1 * 0x168 + 0x130);
    *psVar1 = *psVar1 + arg2;
    psVar1 = (short *)((intptr_t)self + arg1 * 0x168 + 0x130);
    if (*(short *)((intptr_t)self + arg1 * 0x168 + 0x130) < 0) {
      *psVar1 = 0;
    }
    if (100 < *psVar1) {
      *psVar1 = 100;
    }
  }
  return;
}
