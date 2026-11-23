// Sprite_Blit24BitClipped: ported from Pizza Connection 2 at 0x5376b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5376b0
#include "pc2_port.h"

void __thiscall
Sprite_Blit24BitClipped
          (void *self,int arg1,uint32_t *arg2,int arg3,int arg4,int arg5,int arg6)

{
  uint8_t flag1;
  int value2;
  int value3;
  uint8_t uvalue4;
  int value5;
  uint32_t uvalue6;
  int value7;
  int value8;
  int value9;
  uint32_t uvalue10;
  int value11;
  uint8_t *bptr12;
  uint16_t *uptr13;
  uint32_t *local_1c;
  int local_10;
  int local_c;
  int local_8;
  
  value5 = arg3;
  Object_GetPair4(arg2,&local_8,&local_10);
  value7 = *(int *)((intptr_t)self + 4) - arg3;
  arg3 = local_8;
  if (value7 <= local_8) {
    arg3 = value7;
  }
  value8 = *(int *)((intptr_t)self + 8) - arg4;
  value7 = local_10;
  if (value8 <= local_10) {
    value7 = value8;
  }
  value5 = *(int *)((intptr_t)self + 4) * arg4 + *(int *)((intptr_t)self + 0x18) + value5;
  value9 = arg6 * *(int *)(arg1 + 0x20) + *(int *)(arg1 + 0x28) + arg5 * 3;
  arg2 = (uint32_t *)Object_GetPair10(arg2,&local_c);
  uvalue4 = (uint8_t)DAT_00585518;
  value8 = *(int *)(arg1 + 0x20);
  value2 = *(int *)((intptr_t)self + 4);
  value3 = *(int *)((intptr_t)self + 0x14);
  do {
    local_1c = arg2;
    arg2 = (uint32_t *)((intptr_t)arg2 + local_c * 2);
    while( true ) {
      uvalue10 = *local_1c;
      local_1c = local_1c + 1;
      uvalue6 = uvalue10 & 0xffff;
      if (uvalue6 == 0xffff) break;
      bptr12 = (uint8_t *)(value5 + uvalue6);
      uptr13 = (uint16_t *)(value9 + uvalue6 * 3);
      uvalue10 = uvalue10 >> 0x10;
      if (arg3 < (intptr_t)uvalue10) {
        value11 = arg3 - uvalue6;
        if (value11 == 0 || arg3 < (intptr_t)uvalue6) break;
      }
      else {
        value11 = uvalue10 - uvalue6;
      }
      do {
        flag1 = *bptr12;
        *(uint8_t *)(uptr13 + 1) = uvalue4;
        *uptr13 = *(uint16_t *)(value3 + 4 + (uint32_t)flag1 * 2);
        value11 = value11 + -1;
        bptr12 = bptr12 + 1;
        uptr13 = (uint16_t *)((intptr_t)uptr13 + 3);
      } while (value11 != 0);
    }
    value9 = value9 + value8;
    value5 = value5 + value2;
    value7 = value7 + -1;
    if (value7 == 0) {
      return;
    }
  } while( true );
}
