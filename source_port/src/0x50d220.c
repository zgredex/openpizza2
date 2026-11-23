// Object_IsWithinServiceRange: ported from Pizza Connection 2 at 0x50d220.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50d220
#include "pc2_port.h"

uint32_t __thiscall Object_IsWithinServiceRange(void *self,uint32_t arg1,int arg2)

{
  int *ptr1;
  int value2;
  void *this_00;
  int local_c;
  int local_8;
  int local_4;
  
  value2 = IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),arg2,(int *)0x0);
  ptr1 = *(int **)((intptr_t)self + 200);
  if (ptr1 != (int *)0x0) {
    Record_GetTwoFloats48((void *)ptr1[0x16],*ptr1,&arg2,&local_8);
    ptr1 = *(int **)(value2 + 200);
    if (ptr1 == (int *)0x0) {
      value2 = -1;
      this_00 = (void *)0x0;
    }
    else {
      value2 = *ptr1;
      this_00 = (void *)ptr1[0x16];
    }
    Record_GetTwoFloats48(this_00,value2,&local_c,&local_4);
    switch(*(uint32_t *)((intptr_t)self + 0x30)) {
    case 0xd:
    case 0x17:
    case 0x1d:
      return 1;
    case 0x1e:
      if ((arg2 - local_c) * (arg2 - local_c) + (local_8 - local_4) * (local_8 - local_4) * 4
          < 0xe10) {
        return 1;
      }
    }
  }
  return 0;
}
