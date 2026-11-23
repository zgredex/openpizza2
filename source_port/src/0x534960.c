// Record_GetValue48: ported from Pizza Connection 2 at 0x534960.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x534960
#include "pc2_port.h"

int __thiscall Record_GetValue48(void *self,int arg1)

{
  int *ptr1;
  
  if (((arg1 < 0) || (*(int *)((intptr_t)self + 0x48) <= arg1)) ||
     (ptr1 = (int *)(*(int *)((intptr_t)self + 0x4c) + arg1 * 0x48), *ptr1 == -1)) {
    return 0;
  }
  return (intptr_t)*(short *)((intptr_t)ptr1 + 0x32);
}
