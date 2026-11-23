// Font_DrawGlyphClipped: ported from Pizza Connection 2 at 0x5358d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5358d0
#include "pc2_port.h"

void __thiscall
Font_DrawGlyphClipped
          (void *self,void *arg1,uint8_t *arg2,int arg3,int arg4,int arg5,int arg6)

{
  char cVar1;
  uint8_t flag2;
  uint16_t uvalue3;
  int value4;
  bool flag5;
  uint16_t uvalue6;
  int value7;
  uint32_t uvalue8;
  uint32_t uvalue9;
  int value10;
  uint32_t uvalue11;
  int value12;
  uint32_t uvalue13;
  uint32_t uvalue14;
  uint32_t uvalue15;
  int value16;
  uint8_t *bptr17;
  uint16_t *uptr18;
  uint16_t *uptr19;
  int local_c;
  
  value16 = arg3;
  if (((arg3 != 0) && (arg4 != 0)) && (*(int *)((intptr_t)arg1 + 0x28) != 0)) {
    value4 = *(int *)((intptr_t)arg1 + 0x20);
    arg3 = arg4;
    value10 = *(int *)((intptr_t)self + 0x9a0) + arg5;
    value7 = *(int *)((intptr_t)self + 0x9a4) + arg6;
    value16 = value16 >> 1;
    arg6 = 0;
    arg5 = 0;
    value12 = *(int *)((intptr_t)arg1 + 4);
    local_c = value16;
    if (value10 < value12) {
      arg5 = value12 - value10;
      local_c = (value10 - value12) + value16;
      if (local_c < 1) {
        return;
      }
      value10 = value12;
    }
    if ((value10 + local_c <= *(int *)((intptr_t)arg1 + 8)) ||
       (local_c = *(int *)((intptr_t)arg1 + 8) - value10, 0 < local_c)) {
      if (value7 < *(int *)((intptr_t)arg1 + 0xc)) {
        arg3 = (value7 - *(int *)((intptr_t)arg1 + 0xc)) + arg4;
        arg6 = *(int *)((intptr_t)arg1 + 0xc) - value7;
        value7 = *(int *)((intptr_t)arg1 + 0xc);
        if (arg3 < 1) {
          return;
        }
      }
      if ((arg3 + value7 <= *(int *)((intptr_t)arg1 + 0x10)) ||
         (arg3 = *(int *)((intptr_t)arg1 + 0x10) - value7, 0 < arg3)) {
        uptr19 = (uint16_t *)(*(int *)((intptr_t)arg1 + 0x28) + (value7 * value4 + value10) * 2);
        uvalue13 = *(uint32_t *)((intptr_t)self + 0x9b8);
        uvalue8 = uvalue13 >> 3 & 0x1f;
        uvalue9 = uvalue13 >> 0x13 & 0x1f;
        uvalue11 = uvalue13 >> 0xb & 0x1f;
        uvalue6 = Color_RGBTo16FromDword(arg1,uvalue13);
        cVar1 = *(char *)((intptr_t)arg1 + 0x18);
        for (; value12 = arg5, arg6 != 0; arg6 = arg6 + -1) {
          value12 = value16;
          bptr17 = arg2;
          do {
            while (arg2 = bptr17 + 1, *bptr17 == 0) {
              bptr17 = bptr17 + 2;
              value12 = value12 - (uint32_t)*arg2;
              arg2 = bptr17;
              if (value12 == 0) goto LAB_00535a52;
            }
            value12 = value12 + -1;
            bptr17 = arg2;
          } while (value12 != 0);
LAB_00535a52:
        }
joined_r0x00535a62:
        do {
          value7 = local_c;
          uptr18 = uptr19;
          if (value12 == 0) {
LAB_00535a8c:
            value12 = value7;
            bptr17 = arg2;
            if (cVar1 == '\0') {
              do {
                while( true ) {
                  arg2 = bptr17 + 1;
                  flag2 = *bptr17;
                  if (flag2 == 0) break;
                  bptr17 = arg2;
                  if (flag2 == 0xf) {
                    *uptr18 = uvalue6;
                    uptr18 = uptr18 + 1;
                    value12 = value12 + -1;
                    if (value12 == 0) {
                      value7 = 0;
                      goto LAB_00535bcf;
                    }
                  }
                  else {
                    uvalue3 = *uptr18;
                    value7 = (uint32_t)flag2 * 0x100 + 0x584594;
                    uvalue13 = (uvalue3 & 0x7e00) >> 10;
                    uvalue14 = uvalue3 >> 5 & 0x1f;
                    uvalue15 = uvalue3 & 0x1f;
                    *uptr18 = (((short)uvalue13 +
                                (short)*(uint32_t *)(value7 + (uvalue8 - uvalue13) * 4)) * 0x20 +
                                (short)uvalue14 +
                               (short)*(uint32_t *)(value7 + (uvalue11 - uvalue14) * 4)) * 0x20 +
                               (short)uvalue15 + (short)*(uint32_t *)(value7 + (uvalue9 - uvalue15) * 4);
                    uptr18 = uptr18 + 1;
                    value12 = value12 + -1;
                    value7 = 0;
                    if (value12 == 0) goto LAB_00535bcf;
                  }
                }
                flag2 = *arg2;
                arg2 = bptr17 + 2;
                uptr18 = uptr18 + flag2;
                value7 = value12 - (uint32_t)flag2;
                value12 = value7;
                bptr17 = arg2;
              } while (0 < value7);
            }
            else {
              do {
                while( true ) {
                  bptr17 = arg2 + 1;
                  flag2 = *arg2;
                  if (flag2 == 0) break;
                  arg2 = bptr17;
                  if (flag2 == 0xf) {
                    *uptr18 = uvalue6;
                    uptr18 = uptr18 + 1;
                    value7 = value7 + -1;
                    if (value7 == 0) {
                      value7 = 0;
                      goto LAB_00535bcf;
                    }
                  }
                  else {
                    uvalue3 = *uptr18;
                    value12 = (uint32_t)flag2 * 0x100 + 0x584594;
                    uvalue13 = uvalue3 >> 6 & 0x1f;
                    *uptr18 = (((uvalue3 >> 0xb) +
                                (short)*(uint32_t *)(value12 + (uvalue8 - (uvalue3 >> 0xb)) * 4)) *
                                0x20 + (short)uvalue13 +
                               (short)*(uint32_t *)(value12 + (uvalue11 - uvalue13) * 4)) * 0x40 +
                               (short)(uvalue3 & 0x1f) +
                               (short)*(uint32_t *)(value12 + (uvalue9 - (uvalue3 & 0x1f)) * 4);
                    uptr18 = uptr18 + 1;
                    value7 = value7 + -1;
                    if (value7 == 0) {
                      value7 = 0;
                      goto LAB_00535bcf;
                    }
                  }
                }
                arg2 = arg2 + 2;
                uptr18 = uptr18 + *bptr17;
                value7 = value7 - (uint32_t)*bptr17;
              } while (0 < value7);
            }
          }
          else {
            do {
              if (*arg2 != 0) {
                arg2 = arg2 + 1;
                value12 = value12 + -1;
                goto joined_r0x00535a62;
              }
              uvalue13 = (uint32_t)arg2[1];
              arg2 = arg2 + 2;
              value10 = value12 - uvalue13;
              flag5 = (intptr_t)uvalue13 <= value12;
              value12 = value10;
            } while (value10 != 0 && flag5);
            value7 = local_c + value10;
            uptr18 = uptr19 + -value10;
            if (0 < value7) goto LAB_00535a8c;
          }
LAB_00535bcf:
          for (value7 = ((value16 - arg5) - local_c) + value7; bptr17 = arg2, value7 != 0;
              value7 = value7 - (uint32_t)flag2) {
            while (arg2 = bptr17 + 1, *bptr17 != 0) {
              value7 = value7 + -1;
              bptr17 = arg2;
              if (value7 == 0) goto LAB_00535bf1;
            }
            flag2 = *arg2;
            arg2 = bptr17 + 2;
          }
LAB_00535bf1:
          uptr19 = uptr19 + value4;
          arg3 = arg3 + -1;
          value12 = arg5;
        } while (arg3 != 0);
      }
    }
  }
  return;
}
