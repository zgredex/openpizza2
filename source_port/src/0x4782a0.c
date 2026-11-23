// Stats_GetAverageSpend: ported from Pizza Connection 2 at 0x4782a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4782a0
#include "pc2_port.h"

int64_t __thiscall Stats_GetAverageSpend(void *self,uint32_t arg1)

{
  int value1;
  int64_t lvalue2;
  
  value1 = (*(uint8_t *)(*(int *)(DAT_0057c670 + 0x94) + 7) / 3 - 1 & 7) * 0x34;
  if ((*(short *)((intptr_t)self + arg1 * 2 + value1 + 0x1544) == 0) ||
     (*(short *)((intptr_t)self + value1 + 0x154c) == 0)) {
    return (uint64_t)arg1 << 0x20;
  }
  lvalue2 = __ftol();
  return lvalue2;
}
