// Game_FindFreeStaffRecord: ported from Pizza Connection 2 at 0x4e1e40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e1e40
#include "pc2_port.h"

int * __thiscall Game_FindFreeStaffRecord(void *self,int arg1)

{
  int *ptr1;
  int value2;
  int value3;
  int value4;
  
  value4 = 0;
  if (0 < *(int *)((intptr_t)self + 0x1cc)) {
    do {
      ptr1 = (int *)IDMap_Lookup((void *)((intptr_t)self + 0x1b8),value4,(int *)0x0);
      value2 = IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),*ptr1,(int *)0x0);
      value3 = State_Is2DOr2E(value2);
      if ((((value3 == 0) && (ptr1[1] == arg1)) && (*(int *)(value2 + 0xa4) == -1)) &&
         (((*(int *)(value2 + 0xfc) != 0 && (*(char *)(value2 + 0x104) != '\0')) &&
          (*(int *)(value2 + 0x74) == 0)))) {
        return ptr1;
      }
      value4 = value4 + 1;
    } while (value4 < *(int *)((intptr_t)self + 0x1cc));
  }
  return (int *)0x0;
}
