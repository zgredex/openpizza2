// Thread_SetField8Locked: ported from Pizza Connection 2 at 0x54cd63.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54cd63
#include "pc2_port.h"

void __thiscall Thread_SetField8Locked(void *self,uint32_t arg1)

{
  if (*(int *)((intptr_t)self + 0x34) < 0) {
    CS_EnterRaw((LPCRITICAL_SECTION)((intptr_t)self + 0x38));
  }
  *(uint32_t *)((intptr_t)self + 8) = arg1;
  if (*(int *)((intptr_t)self + 0x34) < 0) {
    CS_LeaveRaw((LPCRITICAL_SECTION)((intptr_t)self + 0x38));
  }
  return;
}
