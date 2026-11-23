// Record_SetDoubles48: ported from Pizza Connection 2 at 0x5342e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5342e0
#include "pc2_port.h"

uint32_t __thiscall Record_SetDoubles48(void *self,int arg1,int arg2,int arg3)

{
  int *ptr1;
  
  if ((-1 < arg1) && (arg1 < *(int *)((intptr_t)self + 0x48))) {
    ptr1 = (int *)(*(int *)((intptr_t)self + 0x4c) + arg1 * 0x48);
    if (*ptr1 != -1) {
      *(double *)(ptr1 + 2) = (double)arg2;
      *(double *)(*(int *)((intptr_t)self + 0x4c) + 0x10 + arg1 * 0x48) = (double)arg3;
      return 1;
    }
  }
  return 0;
}
