// Animation_SetPointPairs: ported from Pizza Connection 2 at 0x534b30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x534b30
#include "pc2_port.h"

void __thiscall
Animation_SetPointPairs
          (void *self,int arg1,uint32_t *arg2,uint32_t *arg3,uint32_t *arg4,
          uint32_t *arg5)

{
  int value1;
  
  if (arg2 != (uint32_t *)0x0) {
    value1 = *(int *)((intptr_t)self + 0x50);
    *(uint32_t *)(value1 + 0x70 + arg1 * 0x98) = *arg2;
    *(uint32_t *)(value1 + 0x74 + arg1 * 0x98) = arg2[1];
  }
  if (arg3 != (uint32_t *)0x0) {
    value1 = *(int *)((intptr_t)self + 0x50);
    *(uint32_t *)(value1 + 0x78 + arg1 * 0x98) = *arg3;
    *(uint32_t *)(value1 + 0x7c + arg1 * 0x98) = arg3[1];
  }
  if (arg4 != (uint32_t *)0x0) {
    value1 = *(int *)((intptr_t)self + 0x50);
    *(uint32_t *)(value1 + 0x60 + arg1 * 0x98) = *arg4;
    *(uint32_t *)(value1 + 100 + arg1 * 0x98) = arg4[1];
  }
  if (arg5 != (uint32_t *)0x0) {
    value1 = *(int *)((intptr_t)self + 0x50);
    *(uint32_t *)(value1 + 0x68 + arg1 * 0x98) = *arg5;
    *(uint32_t *)(value1 + 0x6c + arg1 * 0x98) = arg5[1];
  }
  return;
}
