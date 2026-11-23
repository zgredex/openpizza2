// MapObject_SetRecordFrame: ported from Pizza Connection 2 at 0x5090a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5090a0
#include "pc2_port.h"

void __thiscall MapObject_SetRecordFrame(void *self,int arg1)

{
  int *ptr1;
  
  ptr1 = *(int **)((intptr_t)self + 200);
  if (((ptr1 != (int *)0x0) && ((void *)ptr1[0x16] != (void *)0x0)) && (arg1 != -1)) {
    Record_ApplyVariantState((void *)ptr1[0x16],*ptr1,arg1,1);
    if (*(int *)((intptr_t)self + 200) != 0) {
      *(int *)(*(int *)((intptr_t)self + 200) + 0xc) = arg1;
    }
  }
  return;
}
