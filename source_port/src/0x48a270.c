// Game_FindFreeObjectByType: ported from Pizza Connection 2 at 0x48a270.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48a270
#include "pc2_port.h"

int __thiscall Game_FindFreeObjectByType(void *self,int arg1)

{
  int value1;
  int value2;
  int value3;
  
  value3 = 0;
  if (0 < *(int *)((intptr_t)self + 0x50)) {
    do {
      value1 = IDMap_Lookup((void *)((intptr_t)self + 0x3c),value3,(int *)0x0);
      value2 = State_Is2DOr2E(value1);
      if ((((value2 == 0) && (*(int *)(value1 + 0x30) == arg1)) && (*(int *)(value1 + 0x74) == 0))
         && (*(int *)(value1 + 0x110) == -1)) {
        return value1;
      }
      value3 = value3 + 1;
    } while (value3 < *(int *)((intptr_t)self + 0x50));
  }
  return 0;
}
