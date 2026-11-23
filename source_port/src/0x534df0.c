// Surface_FillFF: ported from Pizza Connection 2 at 0x534df0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x534df0
#include "pc2_port.h"

void __fastcall Surface_FillFF(int arg1)

{
  uint32_t uvalue1;
  uint32_t uvalue2;
  uint32_t *uptr3;
  
  uvalue1 = *(int *)(arg1 + 0x10) * *(int *)(arg1 + 8);
  uptr3 = *(uint32_t **)(arg1 + 0x14);
  for (uvalue2 = (uvalue1 & 0x7fffffff) >> 1; uvalue2 != 0; uvalue2 = uvalue2 - 1) {
    *uptr3 = 0xffffffff;
    uptr3 = uptr3 + 1;
  }
  for (uvalue1 = uvalue1 * 2 & 3; uvalue1 != 0; uvalue1 = uvalue1 - 1) {
    *(uint8_t *)uptr3 = 0xff;
    uptr3 = (uint32_t *)((intptr_t)uptr3 + 1);
  }
  return;
}
