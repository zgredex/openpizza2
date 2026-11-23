// Object_FindRecordAtOffset: ported from Pizza Connection 2 at 0x4f0bd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f0bd0
#include "pc2_port.h"

int __thiscall Object_FindRecordAtOffset(void *self,int *arg1,int arg2,int arg3)

{
  int *ptr1;
  int value2;
  int *local_8 [2];
  
  Object_GetBufferPair
            (self,(intptr_t)arg1,(int *)local_8,(int *)&arg1,(uint32_t *)0x0,(uint32_t *)0x0);
  value2 = 0;
  if (0 < *arg1) {
    ptr1 = (int *)(*local_8[0] + 0x10);
    do {
      if ((ptr1[-1] - *(int *)((intptr_t)self + 0x24) == arg2) &&
         (*ptr1 - *(int *)((intptr_t)self + 0x28) == arg3)) {
        return *local_8[0] + value2 * 0x28;
      }
      value2 = value2 + 1;
      ptr1 = ptr1 + 10;
    } while (value2 < *arg1);
  }
  return 0;
}
