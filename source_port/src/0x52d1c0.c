// Surface_DrawFilledCircle: ported from Pizza Connection 2 at 0x52d1c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52d1c0
#include "pc2_port.h"

void Surface_DrawFilledCircle(void *arg1,int arg2,int arg3,int arg4,uint32_t arg5)

{
  int value1;
  int value2;
  int value3;
  int value4;
  int value5;
  uint16_t uvalue6;
  int value7;
  int value8;
  uint16_t *uptr9;
  int value10;
  int value11;
  int64_t lvalue12;
  int local_1c;
  
  uvalue6 = Color_RGBTo16FromDword(arg1,arg5);
  if (0 < arg4) {
    value1 = *(int *)((intptr_t)arg1 + 8);
    value2 = *(int *)((intptr_t)arg1 + 4);
    value3 = *(int *)((intptr_t)arg1 + 0x10);
    value4 = *(int *)((intptr_t)arg1 + 0xc);
    value11 = 0;
    value5 = *(int *)((intptr_t)arg1 + 0x20);
    if (arg3 < value4) {
      value11 = value4 - arg3;
    }
    if (value3 < arg3) {
      value11 = arg3 - value3;
    }
    if (value11 < arg4) {
      arg5 = value11 + arg3;
      arg3 = arg3 - value11;
      value10 = arg5 * value5 * 2;
      local_1c = arg3 * value5 * 2;
      do {
        if ((value3 < (intptr_t)arg5) && (arg3 < value4)) {
          return;
        }
        lvalue12 = __ftol();
        value7 = (intptr_t)lvalue12;
        if (((intptr_t)arg5 < value3) && (value4 <= (intptr_t)arg5)) {
          value8 = arg2 - value7;
          if (value8 < arg2 + value7) {
            uptr9 = (uint16_t *)(*(int *)((intptr_t)arg1 + 0x28) + value10 + value8 * 2);
            do {
              if ((value2 <= value8) && (value8 < value1)) {
                *uptr9 = uvalue6;
              }
              value8 = value8 + 1;
              uptr9 = uptr9 + 1;
            } while (value8 < arg2 + value7);
          }
        }
        if ((arg3 < value3) && (value4 <= arg3)) {
          value8 = arg2 - value7;
          if (value8 < value7 + arg2) {
            uptr9 = (uint16_t *)(*(int *)((intptr_t)arg1 + 0x28) + local_1c + value8 * 2);
            do {
              if ((value2 <= value8) && (value8 < value1)) {
                *uptr9 = uvalue6;
              }
              value8 = value8 + 1;
              uptr9 = uptr9 + 1;
            } while (value8 < value7 + arg2);
          }
        }
        value10 = value10 + value5 * 2;
        value11 = value11 + 1;
        local_1c = local_1c + value5 * -2;
        arg5 = arg5 + 1;
        arg3 = arg3 + -1;
      } while (value11 < arg4);
    }
  }
  return;
}
