// Building_ResetInventory: ported from Pizza Connection 2 at 0x4ff9e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ff9e0
#include "pc2_port.h"

void __thiscall Building_ResetInventory(void *self,int arg1)

{
  int value1;
  uint32_t *uptr2;
  int value3;
  
  value1 = *(int *)(arg1 + 0x4c);
  value3 = 10;
  uptr2 = (uint32_t *)((intptr_t)self + value1 * 0x168 + 0x74);
  *(double *)(arg1 + 0x108) =
       (double)(((&DAT_0057bcd8)[*(int *)((intptr_t)self + value1 * 0x168 + 0x40) * 0x30] * 50000) / 100);
  do {
    uptr2[3] = 0;
    *uptr2 = 0xffffffff;
    uptr2 = uptr2 + 4;
    value3 = value3 + -1;
  } while (value3 != 0);
  *(uint32_t *)((intptr_t)self + value1 * 0x168 + 300) = 3;
  return;
}
