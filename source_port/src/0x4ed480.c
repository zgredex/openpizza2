// Map_ComputeObjectDistance: ported from Pizza Connection 2 at 0x4ed480.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ed480
#include "pc2_port.h"

int __thiscall
Map_ComputeObjectDistance(void *self,int arg1,int arg2,int arg3,int arg4,int arg5)

{
  uint32_t uvalue1;
  uint32_t uvalue2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  
  if (arg5 < 0) {
    return 1000000;
  }
  if (*(int *)((intptr_t)self + 0x20) * *(int *)((intptr_t)self + 0x1c) < arg5) {
    return 1000000;
  }
  uvalue1 = ((((*(int *)((intptr_t)self + 0x10) >> 1) +
            *(int *)(*(int *)((intptr_t)self + 0x4c) + 4 + arg5 * 0xc)) - arg2) - arg4) +
          *(int *)((intptr_t)self + 0x10);
  uvalue3 = (intptr_t)uvalue1 >> 0x1f;
  uvalue2 = (((*(int *)((intptr_t)self + 0xc) >> 1) - arg1) - arg3) +
          *(int *)(*(int *)((intptr_t)self + 0x4c) + arg5 * 0xc);
  uvalue4 = (intptr_t)uvalue2 >> 0x1f;
  return ((uvalue2 ^ uvalue4) - uvalue4) * 3 + ((uvalue1 ^ uvalue3) - uvalue3) * 4;
}
