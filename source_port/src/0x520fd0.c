// UI_DispatchCallback: ported from Pizza Connection 2 at 0x520fd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x520fd0
#include "pc2_port.h"

void __thiscall UI_DispatchCallback(void *self,uint32_t arg1)

{
  UI_InvokeCallback(*(void **)(*(int *)((intptr_t)self + 8) + 0x134),*(int *)((intptr_t)self + 8),
                    *(uint32_t *)((intptr_t)self + 4),*(uint32_t *)((intptr_t)self + 0x40),arg1);
  return;
}
