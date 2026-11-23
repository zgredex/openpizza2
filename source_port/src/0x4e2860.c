// Game_FindAssignedSubrecord: ported from Pizza Connection 2 at 0x4e2860.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e2860
#include "pc2_port.h"

int * __thiscall Game_FindAssignedSubrecord(void *self,int arg1,int arg2)

{
  int value1;
  int *ptr2;
  int value3;
  int value4;
  
  value1 = *(int *)((intptr_t)self + 0x1cc);
  value4 = 0;
  if (0 < value1) {
    do {
      ptr2 = (int *)IDMap_Lookup((void *)((intptr_t)self + 0x1b8),value4,(int *)0x0);
      if (ptr2[1] == 0x17) {
        value3 = IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),*ptr2,(int *)0x0);
        if (((*(int *)(value3 + 0x74) == arg2) && (*(int *)(value3 + 0xa4) == 0x12)) &&
           (*(int *)(value3 + 0x10c) == *(int *)(arg1 + 0x3c))) {
          return ptr2;
        }
      }
      value4 = value4 + 1;
    } while (value4 < value1);
  }
  return (int *)0x0;
}
