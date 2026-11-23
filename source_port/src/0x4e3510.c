// Game_FindPlanByTarget: ported from Pizza Connection 2 at 0x4e3510.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e3510
#include "pc2_port.h"

int __thiscall Game_FindPlanByTarget(void *self,int arg1)

{
  int value1;
  int value2;
  int value3;
  
  value1 = *(int *)((intptr_t)self + 0x140);
  value3 = 0;
  if (0 < value1) {
    do {
      value2 = IDMap_Lookup((void *)((intptr_t)self + 300),value3,(int *)0x0);
      if ((*(int *)(value2 + 8) == 3) && (*(int *)(value2 + 0x2c) == *(int *)(arg1 + 0x24))) {
        return value2;
      }
      value3 = value3 + 1;
    } while (value3 < value1);
  }
  return 0;
}
