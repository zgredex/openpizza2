// Game_FindIdleObjectByClass: ported from Pizza Connection 2 at 0x48b960.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48b960
#include "pc2_port.h"

int __thiscall Game_FindIdleObjectByClass(void *self,int arg1)

{
  int value1;
  int value2;
  
  value2 = 0;
  if (0 < *(int *)((intptr_t)self + 0x50)) {
    do {
      value1 = IDMap_Lookup((void *)((intptr_t)self + 0x3c),value2,(int *)0x0);
      if ((((*(int *)(value1 + 0x30) == 10) && (*(int *)(value1 + 0x10c) == arg1)) &&
          (*(int *)(value1 + 0xa4) == -1)) && (*(int *)(value1 + 0x74) == 0)) {
        return value1;
      }
      value2 = value2 + 1;
    } while (value2 < *(int *)((intptr_t)self + 0x50));
  }
  return 0;
}
