// Sprite_FillRectColor: ported from Pizza Connection 2 at 0x5219a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5219a0
#include "pc2_port.h"

void __thiscall
Sprite_FillRectColor(void *self,int arg1,int arg2,int arg3,int arg4,uint32_t arg5)

{
  uint16_t uvalue1;
  int value2;
  uint32_t *uptr3;
  int local_8;
  int local_4;
  
  Sprite_GetSize(*(void **)((intptr_t)self + 0x60),&local_8,&local_4);
  uvalue1 = Color_RGBTo16FromDword(*(void **)((intptr_t)self + 0x68),arg5);
  if (arg1 < 0) {
    arg1 = 0;
  }
  if (arg2 < 0) {
    arg2 = 0;
  }
  if (local_8 <= arg3) {
    arg3 = local_8 + -1;
  }
  if (local_4 <= arg4) {
    arg4 = local_4 + -1;
  }
  value2 = Sprite_GetPixelBuffer(*(void **)((intptr_t)self + 0x60));
  uptr3 = (uint32_t *)(value2 + (local_8 * arg2 + arg1) * 2);
  if (arg2 <= arg4) {
    value2 = (arg4 - arg2) + 1;
    do {
      Mem_FillWord(uptr3,uvalue1,arg3 - arg1);
      value2 = value2 + -1;
      uptr3 = (uint32_t *)((intptr_t)uptr3 + local_8 * 2);
    } while (value2 != 0);
  }
  return;
}
