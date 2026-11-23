// Game_CountObjectsByState: ported from Pizza Connection 2 at 0x486910.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x486910
#include "pc2_port.h"

int __thiscall Game_CountObjectsByState(void *self,int arg1)

{
  int value1;
  int value2;
  int value3;
  int local_4;
  
  value1 = *(int *)((intptr_t)self + 0x50);
  value3 = 0;
  local_4 = 0;
  value2 = 0;
  if (0 < value1) {
    do {
      value2 = IDMap_Lookup((void *)((intptr_t)self + 0x3c),value3,(int *)0x0);
      if ((arg1 == -1) || (arg1 == *(int *)(value2 + 0x30))) {
        local_4 = local_4 + 1;
      }
      value3 = value3 + 1;
    } while (value3 < value1);
    value2 = local_4;
  }
  return value2;
}
