// EventQueue_SetEntryState22: ported from Pizza Connection 2 at 0x525b70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x525b70
#include "pc2_port.h"

void __thiscall EventQueue_SetEntryState22(void *self,int arg1)

{
  uint32_t uvalue1;
  
  uvalue1 = *(uint32_t *)((intptr_t)self + 0x82bc);
  if (uvalue1 != *(uint32_t *)((intptr_t)self + 0x82c0)) {
    do {
      if (*(int *)((intptr_t)self + uvalue1 * 0x14 + 0x32c0) == arg1) {
        *(uint32_t *)((intptr_t)self + (uvalue1 * 5 + 0xcb2) * 4) = 0x22;
      }
      uvalue1 = uvalue1 + 1 & 0x3ff;
    } while (uvalue1 != *(uint32_t *)((intptr_t)self + 0x82c0));
  }
  return;
}
