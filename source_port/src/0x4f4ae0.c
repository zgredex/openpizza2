// Sprite_BlitRLEMasked: ported from Pizza Connection 2 at 0x4f4ae0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f4ae0
#include "pc2_port.h"

void __thiscall Sprite_BlitRLEMasked(void *self,void *arg1,int arg2,int arg3)

{
  uint8_t flag1;
  int value2;
  bool flag3;
  int value4;
  uint8_t flag5;
  uint8_t *bptr6;
  uint32_t uvalue7;
  int value8;
  int value9;
  int value10;
  uint8_t *bptr11;
  uint8_t *bptr12;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  uint8_t *local_14;
  int local_10;
  int local_c;
  int local_8;
  
  bptr6 = (uint8_t *)Sprite_GetPixelBuffer(arg1);
  local_14 = *(uint8_t **)(*(int *)((intptr_t)self + 8) + 0x28);
  if ((local_14 != (uint8_t *)0x0) && (bptr6 != (uint8_t *)0x0)) {
    value2 = *(int *)(*(int *)((intptr_t)self + 8) + 0x20);
    Sprite_GetSize(arg1,&local_10,&local_18);
    local_8 = local_10;
    local_c = local_18;
    flag5 = Sprite_GetFormat((intptr_t)arg1);
    if (((flag5 & 1) != 0) && (*(uint8_t *)((intptr_t)arg1 + 5) < 9)) {
      if ((flag5 & 4) == 0) {
        value9 = arg2;
      }
      else {
        Sprite_GetHotspot(arg1,&local_1c,&local_20);
        arg3 = arg3 + local_20;
        value9 = arg2 + local_1c;
      }
      value10 = *(int *)((intptr_t)self + 8);
      local_24 = 0;
      arg2 = 0;
      value8 = *(int *)(value10 + 4);
      if (value9 < value8) {
        local_8 = local_8 + (value9 - value8);
        arg2 = value8 - value9;
        value9 = value8;
      }
      if (*(int *)(value10 + 8) < local_8 + value9) {
        local_8 = *(int *)(value10 + 8) - value9;
      }
      value4 = local_8;
      value8 = arg3;
      if (arg3 < *(int *)(value10 + 0xc)) {
        local_c = local_c + (arg3 - *(int *)(value10 + 0xc));
        value8 = *(int *)(value10 + 0xc);
        local_24 = value8 - arg3;
      }
      if (*(int *)(value10 + 0x10) < local_c + value8) {
        local_c = *(int *)(value10 + 0x10) - value8;
      }
      if ((0 < local_8) && (0 < local_c)) {
        local_14 = (uint8_t *)((intptr_t)local_14 + value2 * value8 + value9);
        uvalue7 = Sprite_GetColorKey((intptr_t)arg1);
        flag5 = (uint8_t)uvalue7;
        for (; value9 = arg2, local_24 != 0; local_24 = local_24 + -1) {
          value9 = local_10;
          bptr12 = bptr6;
          do {
            while (bptr6 = bptr12 + 1, *bptr12 != uvalue7) {
              value9 = value9 + -1;
              bptr12 = bptr6;
              if (value9 == 0) goto LAB_004f4c4a;
            }
            bptr12 = bptr12 + 2;
            value9 = value9 - (uint32_t)*bptr6;
            bptr6 = bptr12;
          } while (value9 != 0);
LAB_004f4c4a:
        }
        do {
          for (; value10 = local_8, bptr12 = local_14, value9 != 0; value9 = value9 + -1) {
            while (*bptr6 == flag5) {
              bptr11 = bptr6 + 2;
              value10 = value9 - (uint32_t)bptr6[1];
              flag3 = value9 < (intptr_t)(uint32_t)bptr6[1];
              value9 = value10;
              bptr6 = bptr11;
              if (value10 == 0 || flag3) {
                bptr12 = local_14 + -value10;
                value10 = local_8 + value10;
                goto joined_r0x004f4c7e;
              }
            }
            bptr6 = bptr6 + 1;
          }
          do {
            while( true ) {
              bptr11 = bptr6 + 1;
              flag1 = *bptr6;
              if (flag1 == flag5) break;
              if (flag1 < *bptr12) {
                *bptr12 = flag1;
              }
              value10 = value10 + -1;
              bptr6 = bptr11;
              bptr12 = bptr12 + 1;
              if (value10 == 0) {
                value10 = 0;
                goto LAB_004f4caa;
              }
            }
            bptr11 = bptr6 + 2;
            bptr12 = bptr12 + bptr6[1];
            value10 = value10 - (uint32_t)bptr6[1];
joined_r0x004f4c7e:
            bptr6 = bptr11;
          } while (0 < value10);
LAB_004f4caa:
          for (value10 = ((local_10 - arg2) - value4) + value10; bptr6 = bptr11, value10 != 0;
              value10 = value10 - (uint32_t)bptr6[1]) {
            while (bptr11 = bptr6 + 1, *bptr6 != flag5) {
              value10 = value10 + -1;
              bptr6 = bptr11;
              if (value10 == 0) goto LAB_004f4ccd;
            }
            bptr11 = bptr6 + 2;
          }
LAB_004f4ccd:
          local_14 = local_14 + value2;
          local_c = local_c + -1;
          bptr6 = bptr11;
          value9 = arg2;
        } while (local_c != 0);
      }
    }
  }
  return;
}
