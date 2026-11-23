// Object_GetBufferPair: ported from Pizza Connection 2 at 0x4f0850.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f0850
#include "pc2_port.h"

void __thiscall
Object_GetBufferPair
          (void *self,int arg1,int *arg2,int *arg3,uint32_t *arg4,uint32_t *arg5)

{
  if (arg1 == 0) {
    *arg2 = (intptr_t)self + 0xa0;
    *arg3 = (intptr_t)self + 0xa8;
    if (arg4 != (uint32_t *)0x0) {
      *arg4 = 0xa000;
    }
    if (arg5 != (uint32_t *)0x0) {
      *arg5 = 0xff;
    }
  }
  else {
    if (arg1 != 1) {
      NoOp_Stub();
      return;
    }
    *arg2 = (intptr_t)self + 0x9c;
    *arg3 = (intptr_t)self + 0xa4;
    if (arg4 != (uint32_t *)0x0) {
      *arg4 = 0xffff;
    }
    if (arg5 != (uint32_t *)0x0) {
      *arg5 = 0xffff;
      return;
    }
  }
  return;
}
