// Map_AssignObjectToCell: ported from Pizza Connection 2 at 0x4d2280.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d2280
#include "pc2_port.h"

void __thiscall Map_AssignObjectToCell(void *self,int arg1)

{
  IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)((intptr_t)self + 0x28),(int *)0x0);
  *(uint32_t *)((intptr_t)self + 0x54) = (uint32_t)*(uint16_t *)(arg1 + 4);
  if (arg1 != 0) {
    if (*(int *)((intptr_t)self + 4) == 0x20) {
      *(uint8_t *)(arg1 + 6) = 2;
      return;
    }
    *(uint8_t *)(arg1 + 6) = 1;
  }
  return;
}
