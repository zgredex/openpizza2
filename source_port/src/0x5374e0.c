// Sprite_Blit24Bit: ported from Pizza Connection 2 at 0x5374e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5374e0
#include "pc2_port.h"

void __thiscall
Sprite_Blit24Bit(void *self,int arg1,int arg2,int arg3,int arg4,int arg5,int arg6,
                int arg7)

{
  uint8_t *bptr1;
  int value2;
  uint32_t *uptr3;
  int value4;
  int value5;
  uint32_t *uptr6;
  
  if (arg6 < 0) {
    arg2 = arg2 - arg6;
    arg6 = 0;
  }
  if (arg7 < 0) {
    arg3 = arg3 - arg7;
    arg7 = 0;
  }
  value4 = *(int *)((intptr_t)self + 4);
  if (arg4 < 0) {
    arg4 = value4 - arg6;
    arg5 = *(int *)((intptr_t)self + 8) - arg7;
  }
  else {
    if (value4 - arg6 < arg4) {
      arg4 = value4 - arg6;
    }
    value5 = *(int *)((intptr_t)self + 8) - arg7;
    if (value5 < arg5) {
      arg5 = value5;
    }
  }
  value5 = *(int *)(arg1 + 4);
  if (arg2 < value5) {
    arg6 = value5 - arg2;
    arg4 = arg4 - arg6;
    arg2 = value5;
  }
  if (*(int *)(arg1 + 8) < arg2 + arg4) {
    arg4 = *(int *)(arg1 + 8) - arg2;
  }
  value5 = *(int *)(arg1 + 0xc);
  if (arg3 < value5) {
    arg7 = value5 - arg3;
    arg5 = arg5 - arg7;
    arg3 = value5;
  }
  if (*(int *)(arg1 + 0x10) < arg3 + arg5) {
    arg5 = *(int *)(arg1 + 0x10) - arg3;
  }
  if ((0 < arg4) && (0 < arg5)) {
    uptr6 = (uint32_t *)
             (*(int *)(arg1 + 0x28) + (*(int *)(arg1 + 0x20) * arg3 + arg2) * 2);
    if (*(uint8_t *)((intptr_t)self + 0x10) == 8) {
      value5 = *(int *)((intptr_t)self + 0x14);
      value4 = *(int *)((intptr_t)self + 0x18) + value4 * arg7 + arg6;
      if (0 < arg5) {
        arg2 = arg5;
        do {
          value2 = 0;
          if (0 < arg4) {
            uptr3 = uptr6;
            do {
              bptr1 = (uint8_t *)(value2 + value4);
              value2 = value2 + 1;
              *(uint16_t *)uptr3 = *(uint16_t *)(value5 + 4 + (uint32_t)*bptr1 * 2);
              uptr3 = (uint32_t *)((intptr_t)uptr3 + 2);
            } while (value2 < arg4);
          }
          value4 = value4 + *(int *)((intptr_t)self + 4);
          uptr6 = (uint32_t *)((intptr_t)uptr6 + *(int *)(arg1 + 0x20) * 2);
          arg2 = arg2 + -1;
        } while (arg2 != 0);
        return;
      }
    }
    else if ((*(uint8_t *)((intptr_t)self + 0x10) < 0x11) &&
            (uptr3 = (uint32_t *)(*(int *)((intptr_t)self + 0x18) + (value4 * arg7 + arg6) * 2),
            0 < arg5)) {
      do {
        Memory_Fill16(uptr6,uptr3,arg4 * 2,0);
        arg5 = arg5 + -1;
        uptr6 = (uint32_t *)((intptr_t)uptr6 + *(int *)(arg1 + 0x20) * 2);
        uptr3 = (uint32_t *)((intptr_t)uptr3 + *(int *)((intptr_t)self + 4) * 2);
      } while (arg5 != 0);
    }
  }
  return;
}
