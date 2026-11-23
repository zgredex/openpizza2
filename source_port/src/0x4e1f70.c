// Game_FindSubrecordByObject: ported from Pizza Connection 2 at 0x4e1f70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e1f70
#include "pc2_port.h"

int * __thiscall Game_FindSubrecordByObject(void *self,int arg1)

{
  int *ptr1;
  int value2;
  int value3;
  
  value3 = 0;
  if (0 < *(int *)((intptr_t)self + 0x1cc)) {
    do {
      ptr1 = (int *)IDMap_Lookup((void *)((intptr_t)self + 0x1b8),value3,(int *)0x0);
      value2 = IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),*ptr1,(int *)0x0);
      if (value2 == arg1) {
        return ptr1;
      }
      value3 = value3 + 1;
    } while (value3 < *(int *)((intptr_t)self + 0x1cc));
  }
  return (int *)0x0;
}
