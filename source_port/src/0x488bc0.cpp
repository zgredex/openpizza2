// Game_FindPlayerSlot: ported from Pizza Connection 2 at 0x488bc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x488bc0
#include "pc2_port.h"

int __thiscall Game_FindPlayerSlot(void *self,int arg1)

{
  int value1;
  int *ptr2;
  
  value1 = 0;
  ptr2 = (int *)((intptr_t)self + 0x200);
  do {
    if (*ptr2 == arg1) {
      return value1;
    }
    value1 = value1 + 1;
    ptr2 = ptr2 + 1;
  } while (value1 < 6);
  return -1;
}
