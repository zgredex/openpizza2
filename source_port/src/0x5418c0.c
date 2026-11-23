// Stream_RequestBlock: ported from Pizza Connection 2 at 0x5418c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5418c0
#include "pc2_port.h"

uint32_t __thiscall
Stream_RequestBlock(void *self,int arg1,int arg2,int *arg3,uint32_t *arg4)

{
  int value1;
  
  *arg3 = arg2;
  *arg4 = arg1 + arg2;
  if ((*(uint8_t *)self & 1) != 0) {
    return 1;
  }
  if ((uint32_t)(arg1 + arg2) < *(uint32_t *)((intptr_t)self + 0x10)) {
    return 0;
  }
  *arg3 = *(uint32_t *)((intptr_t)self + 0x10) - arg1;
  *arg4 = *(uint32_t *)((intptr_t)self + 0xc);
  if (((*(uint32_t *)self & 2) == 0) &&
     (value1 = *(int *)((intptr_t)self + 4) + -1, *(int *)((intptr_t)self + 4) = value1, value1 == 0)) {
    *(uint32_t *)self = *(uint32_t *)self | 1;
    *(uint32_t *)((intptr_t)self + 4) = *(uint32_t *)((intptr_t)self + 0x14);
  }
  return 2;
}
