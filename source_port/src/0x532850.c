// UI_PurgeChildFromLists: ported from Pizza Connection 2 at 0x532850.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x532850
#include "pc2_port.h"

void __thiscall UI_PurgeChildFromLists(void *self,int arg1)

{
  int value1;
  int value2;
  int value3;
  
  value1 = *(int *)((intptr_t)self + 0x158);
  value3 = 0;
  if (0 < value1) {
    do {
      value2 = Array_GetPtr((void *)((intptr_t)self + 0x148),value3);
      Array_RemoveValueLocked((void *)(value2 + 4),arg1);
      value3 = value3 + 1;
    } while (value3 < value1);
  }
  return;
}
