// Surface_FillClippedRect: ported from Pizza Connection 2 at 0x5395a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5395a0
#include "pc2_port.h"

void __thiscall Surface_FillClippedRect(void *self,int *arg1,uint32_t arg2,int arg3)

{
  int value1;
  uint16_t uvalue2;
  int value3;
  int value4;
  uint32_t uvalue5;
  uint32_t uvalue6;
  int value7;
  uint32_t *uptr8;
  int value9;
  uint32_t *uptr10;
  
  if (arg3 != 0) {
    arg2 = Color_RGBTo16FromDword(self,arg2);
  }
  value7 = *arg1;
  if (*arg1 < *(int *)((intptr_t)self + 4)) {
    value7 = *(int *)((intptr_t)self + 4);
  }
  value3 = *(int *)((intptr_t)self + 8);
  if (value7 < value3) {
    value9 = arg1[1];
    if (arg1[1] < *(int *)((intptr_t)self + 0xc)) {
      value9 = *(int *)((intptr_t)self + 0xc);
    }
    value1 = *(int *)((intptr_t)self + 0x10);
    if (value9 < value1) {
      value4 = arg1[2];
      if (value3 <= arg1[2]) {
        value4 = value3;
      }
      value3 = arg1[3];
      if (value1 <= arg1[3]) {
        value3 = value1;
      }
      uvalue5 = value4 - value7;
      arg3 = value3 - value9;
      if (((0 < (intptr_t)uvalue5) && (0 < arg3)) &&
         (uptr8 = (uint32_t *)
                   (*(int *)((intptr_t)self + 0x28) + (*(int *)((intptr_t)self + 0x20) * value9 + value7) * 2),
         0 < arg3)) {
        do {
          if (0 < (intptr_t)uvalue5) {
            uvalue2 = (uint16_t)arg2;
            uptr10 = uptr8;
            for (uvalue6 = uvalue5 >> 1; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
              *uptr10 = CONCAT22(uvalue2,uvalue2);
              uptr10 = uptr10 + 1;
            }
            for (uvalue6 = (uint32_t)((uvalue5 & 1) != 0); uvalue6 != 0; uvalue6 = uvalue6 - 1) {
              *(uint16_t *)uptr10 = uvalue2;
              uptr10 = (uint32_t *)((intptr_t)uptr10 + 2);
            }
          }
          uptr8 = (uint32_t *)((intptr_t)uptr8 + *(int *)((intptr_t)self + 0x20) * 2);
          arg3 = arg3 + -1;
        } while (arg3 != 0);
      }
    }
  }
  return;
}
