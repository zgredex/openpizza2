// UI_InvokeCallback: ported from Pizza Connection 2 at 0x5281c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5281c0
#include "pc2_port.h"

void __thiscall
UI_InvokeCallback(void *self,uint32_t arg1,uint32_t arg2,uint32_t arg3,
                 uint32_t arg4)

{
  if (*(code **)((intptr_t)self + 0x8308) != (code *)0x0) {
    (**(code **)((intptr_t)self + 0x8308))(arg1,arg2,arg3,arg4);
  }
  return;
}
