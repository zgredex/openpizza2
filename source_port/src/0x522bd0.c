// UI_MeasureTextExtent: ported from Pizza Connection 2 at 0x522bd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x522bd0
#include "pc2_port.h"

void __fastcall UI_MeasureTextExtent(int arg1,int arg2,uint32_t arg3,int arg4)

{
  uint8_t uvalue1;
  uint32_t extraout_var;
  uint32_t extraout_var_00;
  int value2;
  uint32_t extraout_var_01;
  int extraout_ECX;
  int value3;
  
  if (*(int *)(arg1 + 0x88) == -999) {
    value3 = 0;
    *(uint32_t *)(arg1 + 0x88) = arg3;
    value2 = arg1;
    if (0 < *(int *)(arg1 + 0x80)) {
      do {
        uvalue1 = Font_GetCharWidth(*(void **)(arg1 + 0x54),
                                  CONCAT31((int3)((uint32_t)arg2 >> 8),
                                           *(uint8_t *)(value3 + *(int *)(arg1 + 0x6c))));
        arg2 = *(int *)(arg1 + 0x88) + CONCAT31(extraout_var,uvalue1);
        value3 = value3 + 1;
        *(int *)(arg1 + 0x88) = arg2;
        value2 = extraout_ECX;
      } while (value3 < *(int *)(arg1 + 0x80));
    }
    if (*(int *)(arg1 + 0x7c) != 0) {
      value2 = *(int *)(arg1 + 0x88);
      *(int *)(arg1 + 0x88) = value2 + -1;
      *(int *)(arg1 + 0x90) = value2 + 1;
      *(int *)(arg1 + 0x8c) = arg4;
      *(int *)(arg1 + 0x94) = *(int *)(*(int *)(arg1 + 0x54) + 0x9b4) + arg4;
      return;
    }
    uvalue1 = Font_GetCharWidth(*(void **)(arg1 + 0x54),
                              CONCAT31((int3)((uint32_t)value2 >> 8),
                                       *(uint8_t *)(*(int *)(arg1 + 0x6c) + value3)));
    value2 = CONCAT31(extraout_var_00,uvalue1);
    if (value2 == 0) {
      uvalue1 = UI_GetFirstEnabledIndex(*(int *)(arg1 + 0x54));
      value2 = CONCAT31(extraout_var_01,uvalue1);
    }
    *(int *)(arg1 + 0x90) = *(int *)(arg1 + 0x88) + value2;
    value2 = *(int *)(*(int *)(arg1 + 0x54) + 0x9b4) + arg4;
    *(int *)(arg1 + 0x8c) = value2;
    *(int *)(arg1 + 0x94) = value2 + 2;
  }
  return;
}
