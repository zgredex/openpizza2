// Record_SetIndex48: ported from Pizza Connection 2 at 0x534990.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x534990
#include "pc2_port.h"

void __thiscall Record_SetIndex48(void *self,int arg1,int arg2)

{
  int *ptr1;
  
  if ((((-1 < arg1) && (arg1 < *(int *)((intptr_t)self + 0x48))) &&
      (ptr1 = (int *)(*(int *)((intptr_t)self + 0x4c) + arg1 * 0x48), *ptr1 != -1)) &&
     ((-1 < arg2 && (arg2 < *(int *)((intptr_t)self + 0x68))))) {
    *(short *)((intptr_t)ptr1 + 0x32) = (short)arg2;
  }
  return;
}
