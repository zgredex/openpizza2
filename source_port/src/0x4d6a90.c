// Map_FindRecordByFirstField: ported from Pizza Connection 2 at 0x4d6a90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d6a90
#include "pc2_port.h"

int * __thiscall Map_FindRecordByFirstField(void *self,int arg1)

{
  int *ptr1;
  int value2;
  
  value2 = 0;
  if (0 < *(int *)((intptr_t)self + 0xfdc)) {
    do {
      ptr1 = (int *)IDMap_Lookup((void *)((intptr_t)self + 0xfc8),value2,(int *)0x0);
      if (*ptr1 == arg1) {
        return ptr1;
      }
      value2 = value2 + 1;
    } while (value2 < *(int *)((intptr_t)self + 0xfdc));
  }
  return (int *)0x0;
}
