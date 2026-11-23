// Game_CountRecordsByPair: ported from Pizza Connection 2 at 0x47cc70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47cc70
#include "pc2_port.h"

int __thiscall Game_CountRecordsByPair(void *self,int arg1,int arg2)

{
  int value1;
  int value2;
  int value3;
  
  value2 = 0;
  value3 = 0;
  if (*(int *)((intptr_t)self + 0x170c) < 1) {
    return 0;
  }
  do {
    value1 = IDMap_Lookup((void *)((intptr_t)self + 0x16f8),value3,(int *)0x0);
    if (((value1 != 0) && (*(int *)(value1 + 4) == arg1)) && (*(int *)(value1 + 8) == arg2)) {
      value2 = value2 + 1;
    }
    value3 = value3 + 1;
  } while (value3 < *(int *)((intptr_t)self + 0x170c));
  return value2;
}
