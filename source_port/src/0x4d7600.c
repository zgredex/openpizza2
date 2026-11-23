// Game_FindRecordByField24: ported from Pizza Connection 2 at 0x4d7600.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d7600
#include "pc2_port.h"

int __thiscall Game_FindRecordByField24(void *self,int arg1)

{
  int value1;
  int value2;
  
  value2 = 0;
  if (0 < *(int *)((intptr_t)self + 0xfc0)) {
    do {
      value1 = IDMap_Lookup((void *)((intptr_t)self + 0xfac),value2,(int *)0x0);
      if (*(int *)(value1 + 0x24) == arg1) {
        return value1;
      }
      value2 = value2 + 1;
    } while (value2 < *(int *)((intptr_t)self + 0xfc0));
  }
  return 0;
}
