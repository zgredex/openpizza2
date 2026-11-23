// Record_GetTwoFloats48: ported from Pizza Connection 2 at 0x534370.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x534370
#include "pc2_port.h"

uint64_t __thiscall
Record_GetTwoFloats48(void *self,int arg1,uint32_t *arg2,uint32_t *arg3)

{
  uint32_t in_EDX;
  int64_t lvalue1;
  
  if (((arg1 < 0) || (*(int *)((intptr_t)self + 0x48) <= arg1)) ||
     (*(int *)(*(int *)((intptr_t)self + 0x4c) + arg1 * 0x48) == -1)) {
    return (uint64_t)in_EDX << 0x20;
  }
  lvalue1 = __ftol();
  *arg2 = (intptr_t)lvalue1;
  lvalue1 = __ftol();
  *arg3 = (intptr_t)lvalue1;
  return CONCAT44((intptr_t)((uint64_t)lvalue1 >> 0x20),1);
}
