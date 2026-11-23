// Game_RefreshDaylightCurve: ported from Pizza Connection 2 at 0x485700.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x485700
#include "pc2_port.h"

uint32_t __thiscall Game_RefreshDaylightCurve(void *self,uint32_t arg1)

{
  int value1;
  uint32_t *uptr2;
  int64_t lvalue3;
  
  DAT_0057ba00 = arg1;
  uptr2 = (uint32_t *)((intptr_t)self + 0x2db0);
  value1 = 0x19;
  do {
    lvalue3 = __ftol();
    *uptr2 = (intptr_t)lvalue3;
    uptr2 = uptr2 + 1;
    value1 = value1 + -1;
  } while (value1 != 0);
  if (*(int *)((intptr_t)self + 0x2fc) != 0) {
    *(uint32_t *)(*(int *)((intptr_t)self + 0x2fc) + 0xf4) = 1;
  }
  return 1;
}
