// Game_FindRecordByField20: ported from Pizza Connection 2 at 0x47e180.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47e180
#include "pc2_port.h"

int __thiscall Game_FindRecordByField20(void *self,int arg1)

{
  int value1;
  int value2;
  
  value2 = 0;
  if (0 < *(int *)((intptr_t)self + 0x170c)) {
    do {
      value1 = IDMap_Lookup((void *)((intptr_t)self + 0x16f8),value2,(int *)0x0);
      if ((value1 != 0) && (*(int *)(value1 + 0x20) == arg1)) {
        return value1;
      }
      value2 = value2 + 1;
    } while (value2 < *(int *)((intptr_t)self + 0x170c));
  }
  return 0;
}
