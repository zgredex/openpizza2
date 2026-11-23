// Game_FindRecordByPair: ported from Pizza Connection 2 at 0x47cd30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47cd30
#include "pc2_port.h"

int __thiscall Game_FindRecordByPair(void *self,int arg1,int arg2)

{
  int value1;
  int value2;
  
  value2 = 0;
  if (0 < *(int *)((intptr_t)self + 0x170c)) {
    do {
      value1 = IDMap_Lookup((void *)((intptr_t)self + 0x16f8),value2,(int *)0x0);
      if ((*(int *)(value1 + 0x18) == arg1) && (*(int *)(value1 + 0x1c) == arg2)) {
        return value1;
      }
      value2 = value2 + 1;
    } while (value2 < *(int *)((intptr_t)self + 0x170c));
  }
  return 0;
}
