// Sprite_BlitRLEOpaque: ported from Pizza Connection 2 at 0x53b8f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53b8f0
#include "pc2_port.h"

void __thiscall
Sprite_BlitRLEOpaque
          (char *self,char *arg1,uint8_t *arg2,int arg3,int arg4,int arg5,
          uint32_t arg6,uint32_t arg7)

{
  uint8_t flag1;
  short *psVar2;
  bool flag3;
  int *ptr4;
  int value5;
  uint32_t uvalue6;
  uint32_t uvalue7;
  int value8;
  int value9;
  uint32_t uvalue10;
  uint32_t uvalue11;
  short svalue12;
  uint8_t *bptr13;
  uint8_t *bptr14;
  short *psVar15;
  short *psVar16;
  int local_228 [128];
  uint32_t local_28;
  int *local_24;
  short *local_20;
  uint32_t local_1c;
  int local_18;
  uint32_t local_14;
  int local_10;
  short *local_c;
  int local_8;
  
  local_24 = local_228;
  local_20 = (short *)0x0;
  if (arg2 != (uint8_t *)0x0) {
    local_28 = Color_RGBTo16FromDword(arg1,arg7);
    if (*(int *)((intptr_t)arg1 + 0x28) != 0) {
      local_8 = (intptr_t)*(short *)((intptr_t)self + 8);
      local_14 = (uint32_t)*(short *)((intptr_t)self + 6);
      local_10 = *(int *)((intptr_t)arg1 + 0x20);
      if (8 < *(uint8_t *)((intptr_t)self + 5)) {
        local_14 = (intptr_t)local_14 >> 1;
      }
      if ((*(uint8_t *)((intptr_t)self + 4) & 4) == 0) {
        value9 = arg4;
        value8 = arg5;
      }
      else {
        value9 = arg4 + *(short *)((intptr_t)self + 10);
        value8 = arg5 + *(short *)((intptr_t)self + 0xc);
      }
      arg4 = 0;
      arg5 = 0;
      arg7 = local_14;
      if (value9 < *(int *)((intptr_t)arg1 + 4)) {
        arg7 = local_14 + (value9 - *(int *)((intptr_t)arg1 + 4));
        arg5 = *(int *)((intptr_t)arg1 + 4) - value9;
        value9 = *(int *)((intptr_t)arg1 + 4);
      }
      if (*(int *)((intptr_t)arg1 + 8) < (intptr_t)(arg7 + value9)) {
        arg7 = *(int *)((intptr_t)arg1 + 8) - value9;
      }
      value5 = value8;
      if (value8 < *(int *)((intptr_t)arg1 + 0xc)) {
        local_8 = local_8 + (value8 - *(int *)((intptr_t)arg1 + 0xc));
        value5 = *(int *)((intptr_t)arg1 + 0xc);
        arg4 = value5 - value8;
      }
      if (*(int *)((intptr_t)arg1 + 0x10) < local_8 + value5) {
        local_8 = *(int *)((intptr_t)arg1 + 0x10) - value5;
      }
      if ((0 < (intptr_t)arg7) && (0 < local_8)) {
        local_c = (short *)(*(int *)((intptr_t)arg1 + 0x28) + value9 * 3 + local_10 * value5);
        uvalue11 = *(uint32_t *)((intptr_t)self + 0x1c);
        local_18 = (local_14 - arg5) - arg7;
        arg1 = ((intptr_t)(arg1) & ~(0xffffffu << 8)) | ((((intptr_t)((uint8_t)uvalue11)) & 0xffffffu) << 8);
        switch((intptr_t)arg6) {
        case 0:
          for (; value9 = arg5, arg4 != 0; arg4 = arg4 + -1) {
            uvalue10 = local_14;
            bptr13 = arg2;
            do {
              while (arg2 = bptr13 + 1, *bptr13 == uvalue11) {
                bptr13 = bptr13 + 2;
                uvalue10 = uvalue10 - *arg2;
                arg2 = bptr13;
                if (uvalue10 == 0) goto LAB_0053ba67;
              }
              uvalue10 = uvalue10 - 1;
              bptr13 = arg2;
            } while (uvalue10 != 0);
LAB_0053ba67:
          }
          do {
            for (; uvalue11 = arg7, psVar16 = local_c, value9 != 0; value9 = value9 + -1) {
              while (*arg2 == ((uint64_t)(((intptr_t)arg1) >> 8))) {
                bptr13 = arg2 + 2;
                value8 = value9 - (uint32_t)arg2[1];
                flag3 = value9 < (intptr_t)(uint32_t)arg2[1];
                value9 = value8;
                arg2 = bptr13;
                if (value8 == 0 || flag3) {
                  psVar16 = (short *)((intptr_t)local_c + value8 * -3);
                  uvalue11 = arg7 + value8;
                  goto joined_r0x0053baa6;
                }
              }
              arg2 = arg2 + 1;
            }
            do {
              while (bptr13 = arg2 + 1, *arg2 == ((uint64_t)(((intptr_t)arg1) >> 8))) {
                bptr13 = arg2 + 2;
                psVar16 = (short *)((intptr_t)psVar16 + (uint32_t)arg2[1] * 3);
                uvalue11 = uvalue11 - arg2[1];
joined_r0x0053baa6:
                arg2 = bptr13;
                if ((intptr_t)uvalue11 < 1) goto LAB_0053bad5;
              }
              *psVar16 = -1;
              uvalue11 = uvalue11 - 1;
              arg2 = bptr13;
              psVar16 = (short *)((intptr_t)psVar16 + 3);
            } while (uvalue11 != 0);
            uvalue11 = 0;
LAB_0053bad5:
            for (value9 = local_18 + uvalue11; bptr14 = bptr13, value9 != 0;
                value9 = value9 - (uint32_t)bptr14[1]) {
              while (bptr13 = bptr14 + 1, *bptr14 != ((uint64_t)(((intptr_t)arg1) >> 8))) {
                value9 = value9 + -1;
                bptr14 = bptr13;
                if (value9 == 0) goto LAB_0053baf8;
              }
              bptr13 = bptr14 + 2;
            }
LAB_0053baf8:
            local_c = (short *)((intptr_t)local_c + local_10);
            local_8 = local_8 + -1;
            arg2 = bptr13;
            value9 = arg5;
            if (local_8 == 0) {
              return;
            }
          } while( true );
        case 1:
          ptr4 = local_228;
          local_1c = uvalue11;
          for (value9 = 0x80; value9 != 0; value9 = value9 + -1) {
            *ptr4 = 0;
            ptr4 = ptr4 + 1;
          }
          for (; value9 = arg5, psVar16 = local_c, value8 = local_8, arg4 != 0;
              arg4 = arg4 + -1) {
            uvalue10 = local_14;
            bptr13 = arg2;
            do {
              while (arg2 = bptr13 + 1, *bptr13 == local_1c) {
                bptr13 = bptr13 + 2;
                uvalue10 = uvalue10 - *arg2;
                arg2 = bptr13;
                if (uvalue10 == 0) goto LAB_0053bb40;
              }
              uvalue10 = uvalue10 - 1;
              bptr13 = arg2;
            } while (uvalue10 != 0);
LAB_0053bb40:
          }
joined_r0x0053bb56:
          do {
            uvalue10 = arg7;
            bptr13 = arg2;
            psVar15 = psVar16;
            if (value9 == 0) {
LAB_0053bb83:
              uvalue6 = uvalue11 & 0xff;
              ptr4 = local_24;
              bptr13 = arg2;
              do {
                while( true ) {
                  psVar2 = local_20;
                  arg2 = bptr13 + 1;
                  svalue12 = (short)local_28;
                  if (*bptr13 == (uint8_t)uvalue6) break;
                  if (*psVar15 == -1) {
                    local_20 = (short *)0x0;
                    *ptr4 = (intptr_t)psVar15;
                  }
                  else {
                    value9 = *ptr4;
                    *ptr4 = (intptr_t)psVar15;
                    if (value9 == 0) {
                      uvalue6 = uvalue6 & 0xfffeffff;
                    }
                    local_20 = psVar15;
                    if ((uvalue6 & 0x10000) == 0) {
                      *psVar15 = svalue12;
                    }
                  }
                  psVar2 = local_20;
                  ptr4 = ptr4 + 1;
                  uvalue6 = uvalue6 | 0x10000;
                  psVar15 = (short *)((intptr_t)psVar15 + 3);
                  uvalue10 = uvalue10 - 1;
                  bptr13 = arg2;
                  if (uvalue10 == 0) {
                    uvalue10 = 0;
                    if (local_20 != (short *)0x0) {
                      local_20 = (short *)0x0;
                      *psVar2 = svalue12;
                    }
                    goto LAB_0053bc41;
                  }
                }
                if (((uvalue6 & 0x10000) != 0) &&
                   (uvalue6 = uvalue6 & 0xfffeffff, local_20 != (short *)0x0)) {
                  local_20 = (short *)0x0;
                  *psVar2 = svalue12;
                }
                arg2 = bptr13 + 2;
                uvalue7 = (uint32_t)bptr13[1];
                uvalue10 = uvalue10 - uvalue7;
                psVar15 = (short *)((intptr_t)psVar15 + uvalue7 * 3);
                do {
                  psVar2 = (short *)*ptr4;
                  if ((psVar2 != (short *)0x0) && (*ptr4 = 0, *psVar2 != -1)) {
                    *psVar2 = svalue12;
                  }
                  ptr4 = ptr4 + 1;
                  uvalue7 = uvalue7 - 1;
                } while (uvalue7 != 0);
                bptr13 = arg2;
              } while (0 < (intptr_t)uvalue10);
            }
            else {
              do {
                arg2 = bptr13 + 1;
                if (*bptr13 != ((uint64_t)(((intptr_t)arg1) >> 8))) {
                  value9 = value9 + -1;
                  goto joined_r0x0053bb56;
                }
                arg2 = bptr13 + 2;
                value5 = value9 - (uint32_t)bptr13[1];
                flag3 = (intptr_t)(uint32_t)bptr13[1] <= value9;
                value9 = value5;
                bptr13 = arg2;
              } while (value5 != 0 && flag3);
              psVar15 = (short *)((intptr_t)psVar16 + value5 * -3);
              uvalue10 = arg7 + value5;
              if (0 < (intptr_t)uvalue10) goto LAB_0053bb83;
            }
LAB_0053bc41:
            for (value9 = local_18 + uvalue10; bptr13 = arg2, value9 != 0;
                value9 = value9 - (uint32_t)bptr13[1]) {
              while (arg2 = bptr13 + 1, *bptr13 != ((uint64_t)(((intptr_t)arg1) >> 8))) {
                value9 = value9 + -1;
                bptr13 = arg2;
                if (value9 == 0) goto LAB_0053bc64;
              }
              arg2 = bptr13 + 2;
            }
LAB_0053bc64:
            value8 = value8 + -1;
            value9 = arg5;
            psVar16 = (short *)((intptr_t)psVar16 + local_10);
            if (value8 == 0) {
              return;
            }
          } while( true );
        case 2:
          for (; value9 = arg5, arg4 != 0; arg4 = arg4 + -1) {
            uvalue10 = local_14;
            bptr13 = arg2;
            do {
              while (arg2 = bptr13 + 1, *bptr13 == uvalue11) {
                bptr13 = bptr13 + 2;
                uvalue10 = uvalue10 - *arg2;
                arg2 = bptr13;
                if (uvalue10 == 0) goto LAB_0053bc9d;
              }
              uvalue10 = uvalue10 - 1;
              bptr13 = arg2;
            } while (uvalue10 != 0);
LAB_0053bc9d:
          }
          do {
            for (; uvalue11 = arg7, psVar16 = local_c, value9 != 0; value9 = value9 + -1) {
              while (*arg2 == ((uint64_t)(((intptr_t)arg1) >> 8))) {
                bptr13 = arg2 + 2;
                value8 = value9 - (uint32_t)arg2[1];
                flag3 = value9 < (intptr_t)(uint32_t)arg2[1];
                value9 = value8;
                arg2 = bptr13;
                if (value8 == 0 || flag3) {
                  psVar16 = (short *)((intptr_t)local_c + value8 * -3);
                  uvalue11 = arg7 + value8;
                  goto joined_r0x0053bcda;
                }
              }
              arg2 = arg2 + 1;
            }
            do {
              while( true ) {
                bptr13 = arg2 + 1;
                if (*arg2 != ((uint64_t)(((intptr_t)arg1) >> 8))) break;
                bptr13 = arg2 + 2;
                psVar16 = (short *)((intptr_t)psVar16 + (uint32_t)arg2[1] * 3);
                uvalue11 = uvalue11 - arg2[1];
joined_r0x0053bcda:
                arg2 = bptr13;
                if ((intptr_t)uvalue11 < 1) goto LAB_0053bd13;
              }
              if (*psVar16 == -1) {
                *psVar16 = *(short *)(arg3 + (uint32_t)*arg2 * 2);
              }
              uvalue11 = uvalue11 - 1;
              arg2 = bptr13;
              psVar16 = (short *)((intptr_t)psVar16 + 3);
            } while (uvalue11 != 0);
            uvalue11 = 0;
LAB_0053bd13:
            for (value9 = local_18 + uvalue11; bptr14 = bptr13, value9 != 0;
                value9 = value9 - (uint32_t)bptr14[1]) {
              while (bptr13 = bptr14 + 1, *bptr14 != ((uint64_t)(((intptr_t)arg1) >> 8))) {
                value9 = value9 + -1;
                bptr14 = bptr13;
                if (value9 == 0) goto LAB_0053bd36;
              }
              bptr13 = bptr14 + 2;
            }
LAB_0053bd36:
            local_c = (short *)((intptr_t)local_c + local_10);
            local_8 = local_8 + -1;
            arg2 = bptr13;
            value9 = arg5;
            if (local_8 == 0) {
              return;
            }
          } while( true );
        case 0xfffffffe:
          for (; value9 = arg5, arg4 != 0; arg4 = arg4 + -1) {
            uvalue10 = local_14;
            bptr13 = arg2;
            do {
              while (arg2 = bptr13 + 1, *bptr13 == uvalue11) {
                bptr13 = bptr13 + 2;
                uvalue10 = uvalue10 - *arg2;
                arg2 = bptr13;
                if (uvalue10 == 0) goto LAB_0053bd6f;
              }
              uvalue10 = uvalue10 - 1;
              bptr13 = arg2;
            } while (uvalue10 != 0);
LAB_0053bd6f:
          }
          do {
            for (; uvalue11 = arg7, psVar16 = local_c, value9 != 0; value9 = value9 + -1) {
              while (*arg2 == ((uint64_t)(((intptr_t)arg1) >> 8))) {
                bptr13 = arg2 + 2;
                value8 = value9 - (uint32_t)arg2[1];
                flag3 = value9 < (intptr_t)(uint32_t)arg2[1];
                value9 = value8;
                arg2 = bptr13;
                if (value8 == 0 || flag3) {
                  psVar16 = (short *)((intptr_t)local_c + value8 * -3);
                  uvalue11 = arg7 + value8;
                  goto joined_r0x0053bdac;
                }
              }
              arg2 = arg2 + 1;
            }
            do {
              while( true ) {
                bptr13 = arg2 + 1;
                flag1 = *arg2;
                if (flag1 != ((uint64_t)(((intptr_t)arg1) >> 8))) break;
                bptr13 = arg2 + 2;
                psVar16 = (short *)((intptr_t)psVar16 + (uint32_t)arg2[1] * 3);
                uvalue11 = uvalue11 - arg2[1];
joined_r0x0053bdac:
                arg2 = bptr13;
                if ((intptr_t)uvalue11 < 1) goto LAB_0053bde6;
              }
              if ((*psVar16 != -1) && (flag1 < *(uint8_t *)(psVar16 + 1))) {
                *(uint8_t *)(psVar16 + 1) = flag1;
              }
              uvalue11 = uvalue11 - 1;
              arg2 = bptr13;
              psVar16 = (short *)((intptr_t)psVar16 + 3);
            } while (uvalue11 != 0);
            uvalue11 = 0;
LAB_0053bde6:
            for (value9 = local_18 + uvalue11; bptr14 = bptr13, value9 != 0;
                value9 = value9 - (uint32_t)bptr14[1]) {
              while (bptr13 = bptr14 + 1, *bptr14 != ((uint64_t)(((intptr_t)arg1) >> 8))) {
                value9 = value9 + -1;
                bptr14 = bptr13;
                if (value9 == 0) goto LAB_0053be09;
              }
              bptr13 = bptr14 + 2;
            }
LAB_0053be09:
            local_c = (short *)((intptr_t)local_c + local_10);
            local_8 = local_8 + -1;
            arg2 = bptr13;
            value9 = arg5;
            if (local_8 == 0) {
              return;
            }
          } while( true );
        case 0xffffffff:
          for (; value9 = arg5, arg4 != 0; arg4 = arg4 + -1) {
            uvalue10 = local_14;
            bptr13 = arg2;
            do {
              while (arg2 = bptr13 + 1, *bptr13 == uvalue11) {
                bptr13 = bptr13 + 2;
                uvalue10 = uvalue10 - *arg2;
                arg2 = bptr13;
                if (uvalue10 == 0) goto LAB_0053be42;
              }
              uvalue10 = uvalue10 - 1;
              bptr13 = arg2;
            } while (uvalue10 != 0);
LAB_0053be42:
          }
          do {
            for (; uvalue11 = arg7, psVar16 = local_c, value9 != 0; value9 = value9 + -1) {
              while (*arg2 == ((uint64_t)(((intptr_t)arg1) >> 8))) {
                bptr13 = arg2 + 2;
                value8 = value9 - (uint32_t)arg2[1];
                flag3 = value9 < (intptr_t)(uint32_t)arg2[1];
                value9 = value8;
                arg2 = bptr13;
                if (value8 == 0 || flag3) {
                  psVar16 = (short *)((intptr_t)local_c + value8 * -3);
                  uvalue11 = arg7 + value8;
                  goto joined_r0x0053be7f;
                }
              }
              arg2 = arg2 + 1;
            }
            do {
              while( true ) {
                bptr13 = arg2 + 1;
                if (*arg2 != ((uint64_t)(((intptr_t)arg1) >> 8))) break;
                bptr13 = arg2 + 2;
                psVar16 = (short *)((intptr_t)psVar16 + (uint32_t)arg2[1] * 3);
                uvalue11 = uvalue11 - arg2[1];
joined_r0x0053be7f:
                arg2 = bptr13;
                if ((intptr_t)uvalue11 < 1) goto LAB_0053beb2;
              }
              *psVar16 = *(short *)(arg3 + (uint32_t)*arg2 * 2);
              uvalue11 = uvalue11 - 1;
              arg2 = bptr13;
              psVar16 = (short *)((intptr_t)psVar16 + 3);
            } while (uvalue11 != 0);
            uvalue11 = 0;
LAB_0053beb2:
            for (value9 = local_18 + uvalue11; bptr14 = bptr13, value9 != 0;
                value9 = value9 - (uint32_t)bptr14[1]) {
              while (bptr13 = bptr14 + 1, *bptr14 != ((uint64_t)(((intptr_t)arg1) >> 8))) {
                value9 = value9 + -1;
                bptr14 = bptr13;
                if (value9 == 0) goto LAB_0053bed5;
              }
              bptr13 = bptr14 + 2;
            }
LAB_0053bed5:
            local_c = (short *)((intptr_t)local_c + local_10);
            local_8 = local_8 + -1;
            arg2 = bptr13;
            value9 = arg5;
          } while (local_8 != 0);
        }
      }
    }
  }
  return;
}
