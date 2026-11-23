// Game_FindRecordByField4: ported from Pizza Connection 2 at 0x4ddce0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ddce0
#include "pc2_port.h"

int __thiscall Game_FindRecordByField4(void *self,int arg1)

{
  int value1;
  int value2;
  int value3;
  
  value1 = *(int *)((intptr_t)self + 0x178);
  value3 = 0;
  if (0 < value1) {
    do {
      value2 = IDMap_Lookup((void *)((intptr_t)self + 0x164),value3,(int *)0x0);
      if (*(int *)(value2 + 4) == arg1) {
        return value2;
      }
      value3 = value3 + 1;
    } while (value3 < value1);
  }
  return 0;
}
