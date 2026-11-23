// UI_CreateWindowFromRect: ported from Pizza Connection 2 at 0x521bc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x521bc0
#include "pc2_port.h"


uint32_t * __thiscall UI_CreateWindowFromRect(void *self,uint32_t arg1,uint32_t arg2)

{
  int value1;
  uint32_t *uptr2;
  int value3;
  void *this_00;
  int value4;
  uint16_t *uptr5;
  int value6;
  uint32_t uvalue7;
  uint32_t *this_01;
  double extraout_ST0;
  double extraout_ST1;
  int64_t lvalue8;
  short svalue9;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a5eb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  value1 = Color_RGBTo16FromDword(*(void **)((intptr_t)self + 0x68),arg1);
  if ((intptr_t)arg2 < 1) {
    uptr2 = (uint32_t *)0x0;
  }
  else {
    value3 = Color_RGBTo16FromDword(*(void **)((intptr_t)self + 0x68),0xff00);
    this_00 = operator_new(0x50);
    this_01 = (uint32_t *)0x0;
    local_4 = 0;
    if (this_00 != (void *)0x0) {
      this_01 = Sprite_CreateRaw(this_00,arg2,arg2,value3,0x10,4);
    }
    local_4 = 0xffffffff;
    Sprite_FillTransparentColor(this_01,value3);
    Sprite_SetColorKey(this_01,value3);
    uptr2 = operator_new(0xc);
    uptr2[1] = this_01;
    *uptr2 = 1;
    value3 = Sprite_GetPixelBuffer(this_01);
    if (arg2 == 1) {
      Sprite_FillTransparentColor(this_01,value1);
    }
    else {
      value4 = (intptr_t)arg2 >> 1;
      if ((arg2 & 1) == 0) {
        svalue9 = -(short)value4;
        Sprite_SetHotspot(this_01,svalue9,svalue9);
        arg1 = value3 + (arg2 + 1) * value4 * 2;
        uvalue7 = value3 + ((value4 + -1) * arg2 + value4) * 2;
      }
      else {
        svalue9 = -(short)value4;
        uvalue7 = value3 + (arg2 + 1) * value4 * 2;
        Sprite_SetHotspot(this_01,svalue9,svalue9);
        arg1 = uvalue7;
      }
      if (0.0 <= (float)value4) {
        do {
          lvalue8 = __ftol();
          value3 = (intptr_t)lvalue8;
          if (value3 == 0) {
            value3 = 1;
          }
          value6 = (arg2 & 1) + value3;
          if (-value3 < value6) {
            uptr5 = (uint16_t *)(uvalue7 + value3 * -2);
            value6 = value6 + value3;
            do {
              *(short *)((arg1 - uvalue7) + (intptr_t)uptr5) = (short)value1;
              *uptr5 = (short)value1;
              uptr5 = uptr5 + 1;
              value6 = value6 + -1;
            } while (value6 != 0);
          }
          arg1 = arg1 + arg2 * 2;
          uvalue7 = uvalue7 + arg2 * -2;
        } while (extraout_ST0 + extraout_ST1 <= (double)value4);
      }
    }
  }
  ExceptionList = local_c;
  return uptr2;
}
