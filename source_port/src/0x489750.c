// Game_FindRecordByTripleKey: ported from Pizza Connection 2 at 0x489750.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x489750
#include "pc2_port.h"

int __thiscall
Game_FindRecordByTripleKey(void *self,int arg1,int arg2,uint32_t arg3,int *arg4)

{
  int value1;
  int value2;
  
  value2 = 0;
  if (0 < *(int *)((intptr_t)self + 0x88)) {
    do {
      value1 = IDMap_Lookup((void *)((intptr_t)self + 0x74),value2,(int *)0x0);
      if (((*(int *)(value1 + 8) == arg1) && (*(int *)(value1 + 0x10) == arg2)) &&
         (*(uint8_t *)(value1 + 0x14) == arg3)) {
        if (arg4 == (int *)0x0) {
          return value1;
        }
        *arg4 = value2;
        return value1;
      }
      value2 = value2 + 1;
    } while (value2 < *(int *)((intptr_t)self + 0x88));
  }
  return 0;
}
