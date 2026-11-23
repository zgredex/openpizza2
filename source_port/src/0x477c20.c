// Stats_FindRecordByType: ported from Pizza Connection 2 at 0x477c20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x477c20
#include "pc2_port.h"

void __thiscall Stats_FindRecordByType(void *self,int arg1)

{
  int value1;
  int value2;
  int value3;
  
  value1 = *(int *)((intptr_t)self + 0x14f8);
  if (arg1 == -1) {
    IDMap_Lookup((void *)((intptr_t)self + 0x14e4),value1 + -1,(int *)0x0);
    return;
  }
  value3 = 0;
  if (0 < value1) {
    do {
      value2 = IDMap_Lookup((void *)((intptr_t)self + 0x14e4),value3,(int *)0x0);
      if (*(int *)(value2 + 4) == arg1) {
        return;
      }
      value3 = value3 + 1;
    } while (value3 < value1);
  }
  return;
}
