// Surface_ApplyWaterDistortion: ported from Pizza Connection 2 at 0x5283b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5283b0
#include "pc2_port.h"

int64_t __fastcall Surface_ApplyWaterDistortion(int arg1,uint32_t arg2,int arg3,int arg4)

{
  uint16_t uvalue1;
  uint16_t uvalue2;
  int value3;
  float fVar4;
  uint32_t uvalue5;
  int value6;
  int value7;
  uint32_t uvalue8;
  uint32_t uvalue9;
  uint32_t *uptr10;
  uint32_t *uptr11;
  uint32_t *uptr12;
  int64_t lvalue13;
  int local_654;
  uint32_t local_640 [400];
  
  uvalue1 = *(uint16_t *)(arg3 + 0x1c);
  value3 = *(int *)(arg3 + 0x28);
  uvalue2 = *(uint16_t *)(arg3 + 0x1a);
  uvalue9 = (uint32_t)uvalue2;
  if (uvalue1 < 2) {
    return (uint64_t)arg2 << 0x20;
  }
  fVar4 = (float)arg4 * *(float *)(arg1 + 8) + *(float *)(arg1 + 0xc);
  *(float *)(arg1 + 0xc) = fVar4;
  if ((512.0 < fVar4) && (0.0 < *(float *)(arg1 + 8))) {
    *(float *)(arg1 + 0xc) = 512.0 - (fVar4 - 512.0);
    *(float *)(arg1 + 8) = -*(float *)(arg1 + 8);
  }
  lvalue13 = __ftol();
  local_654 = (intptr_t)lvalue13 >> 10;
  uvalue5 = uvalue9 * 2;
  uvalue8 = (uint32_t)((uint64_t)lvalue13 >> 0x20);
  if (0 < local_654) {
    do {
      value6 = _rand();
      value6 = value6 % (intptr_t)(uint32_t)uvalue1;
      do {
        value7 = _rand();
        value7 = value7 % (intptr_t)(uint32_t)uvalue1;
      } while (value7 == value6);
      uptr12 = (uint32_t *)(value3 + value6 * uvalue9 * 2);
      uptr10 = uptr12;
      uptr11 = local_640;
      for (uvalue8 = (uint32_t)(uvalue2 >> 1); uvalue8 != 0; uvalue8 = uvalue8 - 1) {
        *uptr11 = *uptr10;
        uptr10 = uptr10 + 1;
        uptr11 = uptr11 + 1;
      }
      for (uvalue8 = uvalue5 & 3; uvalue8 != 0; uvalue8 = uvalue8 - 1) {
        *(uint8_t *)uptr11 = *(uint8_t *)uptr10;
        uptr10 = (uint32_t *)((intptr_t)uptr10 + 1);
        uptr11 = (uint32_t *)((intptr_t)uptr11 + 1);
      }
      uptr10 = (uint32_t *)(value3 + value7 * uvalue9 * 2);
      uptr11 = uptr10;
      for (uvalue8 = (uint32_t)(uvalue2 >> 1); uvalue8 != 0; uvalue8 = uvalue8 - 1) {
        *uptr12 = *uptr11;
        uptr11 = uptr11 + 1;
        uptr12 = uptr12 + 1;
      }
      for (uvalue8 = uvalue5 & 3; uvalue8 != 0; uvalue8 = uvalue8 - 1) {
        *(uint8_t *)uptr12 = *(uint8_t *)uptr11;
        uptr11 = (uint32_t *)((intptr_t)uptr11 + 1);
        uptr12 = (uint32_t *)((intptr_t)uptr12 + 1);
      }
      uptr12 = local_640;
      for (uvalue8 = (uint32_t)(uvalue2 >> 1); uvalue8 != 0; uvalue8 = uvalue8 - 1) {
        *uptr10 = *uptr12;
        uptr12 = uptr12 + 1;
        uptr10 = uptr10 + 1;
      }
      local_654 = local_654 + -1;
      for (uvalue8 = uvalue5 & 3; uvalue8 != 0; uvalue8 = uvalue8 - 1) {
        *(uint8_t *)uptr10 = *(uint8_t *)uptr12;
        uptr12 = (uint32_t *)((intptr_t)uptr12 + 1);
        uptr10 = (uint32_t *)((intptr_t)uptr10 + 1);
      }
      uvalue8 = uvalue5;
    } while (local_654 != 0);
  }
  return CONCAT44(uvalue8,(uint32_t)(-1 < *(int *)(arg1 + 0x1c)));
}
