// Game_CountFreeSlots: ported from Pizza Connection 2 at 0x48a200.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48a200
#include "pc2_port.h"

int __thiscall Game_CountFreeSlots(void *self,int arg1)

{
  int value1;
  int value2;
  int value3;
  int local_4;
  
  value3 = 0;
  local_4 = 0;
  value1 = 0;
  if (0 < *(int *)((intptr_t)self + 0x50)) {
    do {
      value1 = IDMap_Lookup((void *)((intptr_t)self + 0x3c),value3,(int *)0x0);
      value2 = State_Is2DOr2E(value1);
      if ((((value2 == 0) && (*(int *)(value1 + 0x30) == arg1)) && (*(int *)(value1 + 0x74) == 0))
         && (*(int *)(value1 + 0x110) == -1)) {
        local_4 = local_4 + 1;
      }
      value3 = value3 + 1;
    } while (value3 < *(int *)((intptr_t)self + 0x50));
    value1 = local_4;
  }
  return value1;
}
