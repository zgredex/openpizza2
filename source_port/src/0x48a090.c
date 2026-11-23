// Game_CountFilteredObjects2: ported from Pizza Connection 2 at 0x48a090.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48a090
#include "pc2_port.h"

int __thiscall
Game_CountFilteredObjects2(void *self,int arg1,int arg2,int arg3,int arg4)

{
  int value1;
  int value2;
  int value3;
  int local_8;
  
  value3 = 0;
  local_8 = 0;
  value1 = 0;
  if (0 < *(int *)((intptr_t)self + 0x50)) {
    do {
      value1 = IDMap_Lookup((void *)((intptr_t)self + 0x3c),value3,(int *)0x0);
      if ((((*(int *)(value1 + 0xa4) == arg1) || (arg1 == -1)) &&
          (*(int *)(value1 + 0x30) == arg2)) && (*(char *)(value1 + 0x104) != '\0')) {
        value2 = State_Is2DOr2E(value1);
        if (((value2 == 0) && ((*(int *)(value1 + 0x110) == arg4 || (arg4 == -1)))) &&
           ((arg3 == 0 || (*(int *)(value1 + 0xfc) == arg3)))) {
          local_8 = local_8 + 1;
        }
      }
      value3 = value3 + 1;
    } while (value3 < *(int *)((intptr_t)self + 0x50));
    value1 = local_8;
  }
  return value1;
}
