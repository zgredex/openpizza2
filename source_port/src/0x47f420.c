// Game_MarkAllObjectsDirty: ported from Pizza Connection 2 at 0x47f420.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47f420
#include "pc2_port.h"

uint32_t __thiscall Game_MarkAllObjectsDirty(void *self,int arg1)

{
  int value1;
  int value2;
  int value3;
  
  value1 = Game_SetStageIfHigher(self,arg1);
  if (value1 == 0) {
    return 0;
  }
  value1 = *(int *)(*(int *)((intptr_t)self + 0x16f0) + 0x8c);
  if ((0 < value1) && (value3 = 0, 0 < value1)) {
    do {
      value2 = Game_MapRecordToGlobal(*(void **)((intptr_t)self + 0x16f0),value3);
      value3 = value3 + 1;
      *(uint8_t *)(value2 + 0x81) = 1;
    } while (value3 < value1);
  }
  return 1;
}
