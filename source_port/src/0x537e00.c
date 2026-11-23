// Surface_InitPixelFormat: ported from Pizza Connection 2 at 0x537e00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x537e00
#include "pc2_port.h"

void __thiscall Surface_InitPixelFormat(void *self,int *arg1,int arg2)

{
  int *ptr1;
  int value2;
  uint32_t *uptr3;
  uint32_t local_20 [4];
  uint32_t uStack_10;
  
  *arg1 = 0;
  if ((arg2 != 0) && (DirectDraw_Init((intptr_t)self), *arg1 != 0)) {
    return;
  }
  uptr3 = local_20;
  for (value2 = 8; value2 != 0; value2 = value2 + -1) {
    *uptr3 = 0;
    uptr3 = uptr3 + 1;
  }
  local_20[0] = 0x20;
  ptr1 = *(int **)(*(int *)((intptr_t)self + 0x40) + 4);
  value2 = (**(code **)(*ptr1 + 0x54))(ptr1,local_20);
  if (value2 != 0) {
    if (value2 == -0x7ff8ffa9) {
      *arg1 = 0x106;
      return;
    }
    if (value2 == -0x7789ff7e) {
      *arg1 = 0x105;
      return;
    }
    *arg1 = (-(uint32_t)(value2 != -0x7789fdb0) & 0xfc) + 0x107;
    return;
  }
  *arg1 = 0;
  if (local_20[2] == 0xf800) {
    *(uint8_t *)((intptr_t)self + 0x18) = 1;
  }
  else {
    *(uint8_t *)((intptr_t)self + 0x18) = 0;
  }
  local_20[1] = local_20[1] & 0xff;
  *(uint32_t *)((intptr_t)self + 0x24) = local_20[1];
  if ((local_20[1] == 0xf) || (local_20[1] == 0x10)) {
    *(uint32_t *)((intptr_t)self + 0x34) = uStack_10;
    *(uint32_t *)((intptr_t)self + 0x38) = local_20[3];
    *(uint32_t *)((intptr_t)self + 0x3c) = local_20[2];
    return;
  }
  *(uint32_t *)((intptr_t)self + 0x34) = 0x1f;
  *(uint32_t *)((intptr_t)self + 0x38) = 0x3e0;
  *(uint32_t *)((intptr_t)self + 0x3c) = 0x7c00;
  return;
}
