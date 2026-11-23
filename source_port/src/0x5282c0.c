// UI_FillFadeRect: ported from Pizza Connection 2 at 0x5282c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5282c0
#include "pc2_port.h"

uint32_t __thiscall UI_FillFadeRect(void *self,int arg1,int arg2)

{
  uint16_t uvalue1;
  uint16_t uvalue2;
  float fVar3;
  int value4;
  uint32_t uvalue5;
  short *psVar6;
  int64_t lvalue7;
  int64_t lvalue8;
  int64_t lvalue9;
  uint32_t local_4;
  
  uvalue1 = *(uint16_t *)(arg1 + 0x1a);
  uvalue2 = *(uint16_t *)(arg1 + 0x1c);
  psVar6 = *(short **)(arg1 + 0x28);
  uvalue5 = 1;
  local_4 = 1;
  if (*(int *)((intptr_t)self + 0xc) == 0x42000000) {
    uvalue5 = 0;
    local_4 = 0;
  }
  else {
    fVar3 = (float)arg2 * *(float *)((intptr_t)self + 8) + *(float *)((intptr_t)self + 0xc);
    *(float *)((intptr_t)self + 0xc) = fVar3;
    if (32.0 < fVar3) {
      *(uint32_t *)((intptr_t)self + 0xc) = 0x42000000;
    }
  }
  value4 = (uint32_t)uvalue2 * (uint32_t)uvalue1;
  if (value4 < 1) {
    return uvalue5;
  }
  do {
    lvalue7 = __ftol();
    lvalue8 = __ftol();
    lvalue9 = __ftol();
    value4 = value4 + -1;
    *psVar6 = (((uint16_t)lvalue7 & 0x1f) * 0x20 + ((uint16_t)lvalue8 & 0x1f)) * 0x40 +
              ((uint16_t)lvalue9 & 0x1f);
    psVar6 = psVar6 + 1;
  } while (value4 != 0);
  return local_4;
}
