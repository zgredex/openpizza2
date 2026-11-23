// Surface_Clear: ported from Pizza Connection 2 at 0x5374b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5374b0
#include "pc2_port.h"

void __fastcall Surface_Clear(int arg1)

{
  uint32_t uvalue1;
  uint32_t uvalue2;
  uint32_t *uptr3;
  
  uvalue1 = (uint32_t)(*(uint8_t *)(arg1 + 0x10) >> 3) * *(int *)(arg1 + 8) * *(int *)(arg1 + 4);
  uptr3 = *(uint32_t **)(arg1 + 0x18);
  for (uvalue2 = uvalue1 >> 2; uvalue2 != 0; uvalue2 = uvalue2 - 1) {
    *uptr3 = 0;
    uptr3 = uptr3 + 1;
  }
  for (uvalue1 = uvalue1 & 3; uvalue1 != 0; uvalue1 = uvalue1 - 1) {
    *(uint8_t *)uptr3 = 0;
    uptr3 = (uint32_t *)((intptr_t)uptr3 + 1);
  }
  return;
}
