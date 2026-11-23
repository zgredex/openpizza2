// Thread_SetGlobalFlag: ported from Pizza Connection 2 at 0x4fc7a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fc7a0
#include "pc2_port.h"

void __thiscall Thread_SetGlobalFlag(void *self,int arg1)

{
  DWORD DVar1;
  
  DVar1 = GetCurrentThreadId();
  if (DVar1 == *(DWORD *)((intptr_t)self + 0x10)) {
    *(uint32_t *)(DAT_0057c670 + 0x250) = (uint32_t)(arg1 == 0);
  }
  return;
}
