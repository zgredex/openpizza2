// Game_CountUnassignedObjectsByClass: ported from Pizza Connection 2 at 0x486b80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x486b80
#include "pc2_port.h"

int __thiscall Game_CountUnassignedObjectsByClass(void *self,int arg1,char arg2)

{
  int value1;
  int value2;
  int value3;
  int value4;
  int local_4;
  
  value1 = *(int *)((intptr_t)self + 0x50);
  value4 = 0;
  local_4 = 0;
  value2 = 0;
  if (0 < value1) {
    do {
      value2 = IDMap_Lookup((void *)((intptr_t)self + 0x3c),value4,(int *)0x0);
      value3 = State_Is2DOr2E(value2);
      if (((value3 == 0) && (arg1 == *(int *)(value2 + 0x30))) &&
         ((arg2 == '\0' || (*(int *)(value2 + 0x110) == -1)))) {
        local_4 = local_4 + 1;
      }
      value4 = value4 + 1;
    } while (value4 < value1);
    value2 = local_4;
  }
  return value2;
}
