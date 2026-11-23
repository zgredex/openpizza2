// Building_HasAdjacentTile: ported from Pizza Connection 2 at 0x4f1450.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f1450
#include "pc2_port.h"

uint32_t __thiscall Building_HasAdjacentTile(void *self,int arg1,int arg2,int arg3)

{
  int value1;
  short *psVar2;
  int value3;
  
  value3 = 0;
  psVar2 = (short *)(arg2 + 0x14);
  do {
    if (*psVar2 != -1) {
      value1 = Array_GetRecord28(self,arg1,(intptr_t)*psVar2);
      if (value1 == arg3) {
        return 1;
      }
    }
    value3 = value3 + 1;
    psVar2 = psVar2 + 1;
  } while (value3 < 8);
  return 0;
}
