// Surface_ClearRows: ported from Pizza Connection 2 at 0x539550.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x539550
#include "pc2_port.h"

void __fastcall Surface_ClearRows(int arg1)

{
  uint16_t uvalue1;
  uint32_t uvalue2;
  int value3;
  int value4;
  uint32_t *uptr5;
  uint32_t *uptr6;
  
  uptr5 = *(uint32_t **)(arg1 + 0x28);
  if ((uptr5 != (uint32_t *)0x0) && (value4 = 0, *(short *)(arg1 + 0x1c) != 0)) {
    do {
      uvalue1 = *(uint16_t *)(arg1 + 0x1a);
      uptr6 = uptr5;
      for (uvalue2 = (uint32_t)(uvalue1 >> 1); uvalue2 != 0; uvalue2 = uvalue2 - 1) {
        *uptr6 = 0;
        uptr6 = uptr6 + 1;
      }
      value4 = value4 + 1;
      for (value3 = (uvalue1 & 1) << 1; value3 != 0; value3 = value3 + -1) {
        *(uint8_t *)uptr6 = 0;
        uptr6 = (uint32_t *)((intptr_t)uptr6 + 1);
      }
      uptr5 = (uint32_t *)((intptr_t)uptr5 + *(int *)(arg1 + 0x20) * 2);
    } while (value4 < (intptr_t)(uint32_t)*(uint16_t *)(arg1 + 0x1c));
  }
  return;
}
