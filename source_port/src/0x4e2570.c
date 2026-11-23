// Game_CollectObjectsByOwner: ported from Pizza Connection 2 at 0x4e2570.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e2570
#include "pc2_port.h"

void __thiscall Game_CollectObjectsByOwner(void *self,void *arg1,int arg2)

{
  int value1;
  int value2;
  int value3;
  
  value1 = *(int *)((intptr_t)self + 0x194);
  value3 = 0;
  if (0 < value1) {
    do {
      value2 = IDMap_Lookup((void *)((intptr_t)self + 0x180),value3,(int *)0x0);
      if (*(int *)(value2 + 0x30) == arg2) {
        List_Add(arg1,value2);
      }
      value3 = value3 + 1;
    } while (value3 < value1);
  }
  return;
}
