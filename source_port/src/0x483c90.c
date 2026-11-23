// Game_FindFreeObjectByOwner: ported from Pizza Connection 2 at 0x483c90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x483c90
#include "pc2_port.h"

int __thiscall Game_FindFreeObjectByOwner(void *self,int arg1,char arg2)

{
  int value1;
  int value2;
  int value3;
  int value4;
  int value5;
  
  value1 = *(int *)((intptr_t)self + 0x50);
  value5 = 0;
  if (0 < value1) {
    do {
      value3 = IDMap_Lookup((void *)((intptr_t)self + 0x3c),value5,(int *)0x0);
      if (*(int *)(value3 + 0x30) == arg1) {
        if (arg2 == '\0') {
          return value3;
        }
        value2 = *(int *)(value3 + 0x110);
        value4 = State_Is2DOr2E(value3);
        if (((value2 == -1) && (value4 != 1)) && (*(int *)(value3 + 0x74) == 0)) {
          return value3;
        }
      }
      value5 = value5 + 1;
    } while (value5 < value1);
  }
  return 0;
}
