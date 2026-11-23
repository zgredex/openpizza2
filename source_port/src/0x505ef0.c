// MapObject_GetScreenPosition: ported from Pizza Connection 2 at 0x505ef0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x505ef0
#include "pc2_port.h"

void __thiscall MapObject_GetScreenPosition(void *self,uint32_t arg1,int *arg2,int *arg3)

{
  int *ptr1;
  int local_8;
  int local_4;
  
  ptr1 = *(int **)((intptr_t)self + 200);
  if (ptr1 != (int *)0x0) {
    Record_GetTwoFloats48((void *)ptr1[0x16],*ptr1,&local_8,&local_4);
    *arg2 = local_8 + 0xa0;
    *arg3 = local_4 + 0xd0;
  }
  return;
}
