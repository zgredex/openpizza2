// Game_UpdateAmbientLight: ported from Pizza Connection 2 at 0x485820.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x485820
#include "pc2_port.h"

uint32_t __thiscall Game_UpdateAmbientLight(void *self,int arg1)

{
  uint32_t uvalue1;
  uint32_t uvalue2;
  int value3;
  
  uvalue1 = (uint32_t)*(uint8_t *)(*(int *)((intptr_t)self + 0x94) + 7);
  uvalue2 = (uint32_t)*(uint8_t *)(*(int *)((intptr_t)self + 0x94) + 6);
  if (*(int *)(arg1 + 0xc) == 0x10) {
    value3 = 0xf8;
  }
  else {
    value3 = (intptr_t)(*(int *)((intptr_t)self + uvalue1 * 4 + 0x2db0) * (uvalue2 * -5 + 0x3c) +
                 *(int *)((intptr_t)self + uvalue1 * 4 + 0x2db4) * uvalue2 * 5) / 0x3c;
  }
  if (DAT_00585518 == value3) {
    return 0;
  }
  DAT_00585518 = value3;
  return 1;
}
