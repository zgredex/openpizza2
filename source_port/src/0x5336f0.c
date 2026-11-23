// Sprite_DrawMasked: ported from Pizza Connection 2 at 0x5336f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5336f0
#include "pc2_port.h"

void __thiscall
Sprite_DrawMasked(void *self,int *arg1,int *arg2,uint32_t *arg3,uint32_t *arg4)

{
  short svalue1;
  uint16_t uvalue2;
  int value3;
  uint16_t *uptr4;
  int value5;
  uint32_t uvalue6;
  uint16_t *local_10;
  short *local_c;
  short *local_8;
  int local_4;
  
  if (*(int *)((intptr_t)self + 0x54) == -999) {
    local_4 = *(int *)((intptr_t)self + 0x68);
    for (value5 = 0;
        ((value5 < local_4 && (*(short *)(*(int *)((intptr_t)self + 0x20) + value5 * 2) == 0)) ||
        (*(short *)(*(int *)((intptr_t)self + 0x24) + value5 * 2) == 0)); value5 = value5 + 1) {
    }
    if (local_4 <= value5) {
      *arg4 = 0;
      *arg3 = 0;
      *arg2 = 0;
      *arg1 = 0;
      return;
    }
    uptr4 = (uint16_t *)(*(int *)((intptr_t)self + 0x28) + value5 * 2);
    local_10 = (uint16_t *)(*(int *)((intptr_t)self + 0x2c) + value5 * 2);
    *(uint32_t *)((intptr_t)self + 0x54) = (uint32_t)*uptr4;
    *(uint32_t *)((intptr_t)self + 0x58) = (uint32_t)*local_10;
    local_c = (short *)(*(int *)((intptr_t)self + 0x20) + value5 * 2);
    if (*(char *)((intptr_t)self + 5) == '\b') {
      *(uint32_t *)((intptr_t)self + 0x5c) = (uint32_t)*uptr4 + (intptr_t)*local_c;
    }
    else {
      *(uint32_t *)((intptr_t)self + 0x5c) = (intptr_t)*local_c / 2 + (uint32_t)*uptr4;
    }
    local_8 = (short *)(*(int *)((intptr_t)self + 0x24) + value5 * 2);
    local_4 = local_4 - value5;
    *(uint32_t *)((intptr_t)self + 0x60) =
         (uint32_t)*local_10 + (intptr_t)*(short *)(*(int *)((intptr_t)self + 0x24) + value5 * 2);
    do {
      svalue1 = *local_c;
      if ((svalue1 != 0) && (*local_8 != 0)) {
        if (*(char *)((intptr_t)self + 5) == '\b') {
          uvalue2 = *uptr4;
          value5 = (intptr_t)svalue1;
        }
        else {
          uvalue2 = *uptr4;
          value5 = (intptr_t)svalue1 / 2;
        }
        uvalue6 = (uint32_t)uvalue2;
        value3 = (uint32_t)*local_10 + (intptr_t)*local_8;
        if ((intptr_t)uvalue6 < *(int *)((intptr_t)self + 0x54)) {
          *(uint32_t *)((intptr_t)self + 0x54) = uvalue6;
        }
        if ((intptr_t)(uint32_t)*local_10 < *(int *)((intptr_t)self + 0x58)) {
          *(uint32_t *)((intptr_t)self + 0x58) = (uint32_t)*local_10;
        }
        if (*(int *)((intptr_t)self + 0x5c) < (intptr_t)(value5 + uvalue6)) {
          *(uint32_t *)((intptr_t)self + 0x5c) = value5 + uvalue6;
        }
        if (*(int *)((intptr_t)self + 0x60) < value3) {
          *(int *)((intptr_t)self + 0x60) = value3;
        }
      }
      local_c = local_c + 1;
      local_8 = local_8 + 1;
      uptr4 = uptr4 + 1;
      local_10 = local_10 + 1;
      local_4 = local_4 + -1;
    } while (local_4 != 0);
  }
  *arg3 = *(uint32_t *)((intptr_t)self + 0x54);
  *arg4 = *(uint32_t *)((intptr_t)self + 0x58);
  *arg1 = *(int *)((intptr_t)self + 0x5c) - *(int *)((intptr_t)self + 0x54);
  *arg2 = *(int *)((intptr_t)self + 0x60) - *(int *)((intptr_t)self + 0x58);
  return;
}
