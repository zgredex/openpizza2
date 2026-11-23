// UI_SetChildRecordVariant: ported from Pizza Connection 2 at 0x509060.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x509060
#include "pc2_port.h"

void __thiscall UI_SetChildRecordVariant(void *self,int arg1)

{
  int *ptr1;
  
                    /* Sets the animation variant of a child's record. */
  if (((arg1 != -1) && (ptr1 = *(int **)((intptr_t)self + 200), ptr1 != (int *)0x0)) &&
     ((void *)ptr1[0x16] != (void *)0x0)) {
    Record_SelectVariant((void *)ptr1[0x16],*ptr1,arg1);
    if (*(int *)((intptr_t)self + 200) != 0) {
      *(int *)(*(int *)((intptr_t)self + 200) + 0xc) = arg1;
    }
  }
  return;
}
