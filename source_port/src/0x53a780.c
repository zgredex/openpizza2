// Sprite_BlitAlphaRLEAlt: ported from Pizza Connection 2 at 0x53a780.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53a780
#include "pc2_port.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

uint32_t * __thiscall
Sprite_BlitAlphaRLEAlt
          (void *self,int arg1,uint32_t *arg2,int arg3,uint32_t *arg4,int arg5,uint8_t *arg6,
          int arg7)

{
  uint64_t uvalue1;
  uint8_t flag2;
  uint8_t flag3;
  char cVar4;
  uint16_t uvalue5;
  uint16_t uvalue6;
  uint16_t uvalue7;
  bool flag8;
  uint32_t *uptr9;
  int value10;
  uint32_t *uptr11;
  int value12;
  uint32_t *uptr13;
  uint32_t *uptr14;
  uint32_t *uptr15;
  uint32_t uvalue16;
  uint32_t uvalue17;
  uint32_t uvalue18;
  uint32_t uvalue19;
  uint64_t *uptr20;
  int *ptr21;
  int *ptr22;
  uint32_t *uptr23;
  uint64_t *uptr24;
  uint64_t *uptr25;
  uint64_t *uptr26;
  uint64_t *uptr27;
  uint64_t uvalue28;
  int64_t lvalue29;
  int local_18;
  int local_c;
  uint32_t *local_8;
  
  uptr13 = arg2;
  if ((arg2 != (uint32_t *)0x0) && (*(int *)(arg1 + 0x28) != 0)) {
    if (arg6 == (uint8_t *)0xffffffff) {
      arg6 = (uint8_t *)(intptr_t)*(short *)((intptr_t)self + 6);
    }
    if (arg7 == -1) {
      arg7 = (intptr_t)*(short *)((intptr_t)self + 8);
    }
    flag2 = *(uint8_t *)((intptr_t)self + 5);
    uptr14 = (uint32_t *)((intptr_t)arg6 >> 1);
    local_8 = (uint32_t *)arg6;
    if (8 < flag2) {
      local_8 = uptr14;
    }
    flag3 = *(uint8_t *)((intptr_t)self + 4);
    if ((flag3 & 4) == 0) {
      uptr13 = arg4;
    }
    else {
      arg5 = arg5 + *(short *)((intptr_t)self + 0xc);
      uptr13 = (uint32_t *)((intptr_t)arg4 + (intptr_t)*(short *)((intptr_t)self + 10));
    }
    local_18 = 0;
    arg4 = (uint32_t *)0x0;
    uptr15 = *(uint32_t **)(arg1 + 4);
    if ((intptr_t)uptr13 < (intptr_t)uptr15) {
      local_8 = (uint32_t *)((intptr_t)local_8 + ((intptr_t)uptr13 - (intptr_t)uptr15));
      arg4 = (uint32_t *)((intptr_t)uptr15 - (intptr_t)uptr13);
      uptr13 = uptr15;
    }
    if (*(int *)(arg1 + 8) < (intptr_t)local_8 + (intptr_t)uptr13) {
      local_8 = (uint32_t *)(*(int *)(arg1 + 8) - (intptr_t)uptr13);
    }
    value12 = arg5;
    local_c = arg7;
    if (arg5 < *(int *)(arg1 + 0xc)) {
      local_c = arg7 + (arg5 - *(int *)(arg1 + 0xc));
      value12 = *(int *)(arg1 + 0xc);
      local_18 = value12 - arg5;
    }
    if (*(int *)(arg1 + 0x10) < local_c + value12) {
      local_c = *(int *)(arg1 + 0x10) - value12;
    }
    if ((0 < (intptr_t)local_8) && (0 < local_c)) {
      value10 = *(int *)(arg1 + 0x20) * 2;
      uptr25 = (uint64_t *)
                (*(int *)(arg1 + 0x28) +
                (intptr_t)(*(int *)(arg1 + 0x20) * value12 + (intptr_t)uptr13) * 2);
      uptr15 = *(uint32_t **)((intptr_t)self + 0x1c);
      lvalue29 = __allmul((uint32_t)uptr15,(intptr_t)uptr15 >> 0x1f,0x10001,0x10001);
      if ((flag3 & 0x10) != 0) {
        if (flag2 != 8) {
          cVar4 = *(char *)(arg1 + 0x18);
          for (; uptr13 = arg4, local_18 != 0; local_18 = local_18 + -1) {
            uptr13 = uptr14;
            do {
              while( true ) {
                uvalue16 = *arg2;
                arg2 = arg2 + 1;
                if ((uvalue16 & 0xffff) == 0) break;
                uptr13 = (uint32_t *)((intptr_t)uptr13 + -1);
                if (uptr13 == (uint32_t *)0x0) goto LAB_0053ab79;
              }
              uptr13 = (uint32_t *)((intptr_t)uptr13 - (uvalue16 >> 0x10));
            } while (uptr13 != (uint32_t *)0x0);
LAB_0053ab79:
          }
joined_r0x0053ab89:
          do {
            uptr15 = local_8;
            uptr24 = uptr25;
            if (uptr13 == (uint32_t *)0x0) {
LAB_0053abb2:
              uptr13 = uptr15;
              if (cVar4 == '\0') {
                do {
                  while( true ) {
                    uvalue16 = *arg2;
                    arg2 = arg2 + 1;
                    if ((uvalue16 & 0xffff) == 0) break;
                    if ((char)(uvalue16 >> 8) == '<') {
                      uptr9 = (uint32_t *)(uvalue16 >> 0x10 & 0x7fff);
                      *(short *)uptr24 = (short)uptr9;
                      uptr13 = (uint32_t *)((intptr_t)uptr13 + -1);
                      uptr24 = (uint64_t *)((intptr_t)uptr24 + 2);
                      if (uptr13 == (uint32_t *)0x0) {
                        uptr15 = (uint32_t *)0x0;
                        goto LAB_0053ad3a;
                      }
                    }
                    else {
                      uvalue17 = (uint32_t)*uptr24;
                      uptr9 = (uint32_t *)((uvalue16 & 0xffff) >> 2);
                      uvalue18 = (uvalue17 & 0x7c00) >> 10;
                      uvalue19 = uvalue17 >> 5 & 0x1f;
                      *(short *)uptr24 =
                           (((short)uvalue18 +
                            (short)uptr9[((uvalue16 >> 0x1a & 0x1f) - uvalue18) + 0x161165]) * 0x20 +
                            (short)uvalue19 +
                           (short)uptr9[(((uvalue16 >> 0x10 & 0x3e0) >> 5) - uvalue19) + 0x161165]) *
                           0x20 + (short)(uvalue17 & 0x1f) +
                           (short)uptr9[((uvalue16 >> 0x10 & 0x1f) - (uvalue17 & 0x1f)) + 0x161165];
                      uptr24 = (uint64_t *)((intptr_t)uptr24 + 2);
                      uptr13 = (uint32_t *)((intptr_t)uptr13 + -1);
                      uptr15 = (uint32_t *)0x0;
                      if (uptr13 == (uint32_t *)0x0) goto LAB_0053ad3a;
                    }
                  }
                  uptr9 = (uint32_t *)(uvalue16 >> 0x10);
                  uptr24 = (uint64_t *)((intptr_t)uptr24 + (intptr_t)uptr9 * 2);
                  uptr15 = (uint32_t *)((intptr_t)uptr13 - (intptr_t)uptr9);
                  uptr13 = uptr15;
                } while (0 < (intptr_t)uptr15);
              }
              else {
                do {
                  while( true ) {
                    uvalue16 = *arg2;
                    arg2 = arg2 + 1;
                    if ((uvalue16 & 0xffff) == 0) break;
                    if ((char)(uvalue16 >> 8) == '<') {
                      uptr9 = (uint32_t *)((uvalue16 >> 0x10 & 0xffe0) + (uvalue16 >> 0x10));
                      *(short *)uptr24 = (short)uptr9;
                      uptr15 = (uint32_t *)((intptr_t)uptr15 + -1);
                      uptr24 = (uint64_t *)((intptr_t)uptr24 + 2);
                      if (uptr15 == (uint32_t *)0x0) {
                        uptr15 = (uint32_t *)0x0;
                        goto LAB_0053ad3a;
                      }
                    }
                    else {
                      uvalue17 = (uint32_t)*uptr24;
                      uptr9 = (uint32_t *)((uvalue16 & 0xffff) >> 2);
                      uvalue18 = (uvalue17 & 0xf800) >> 0xb;
                      uvalue19 = uvalue17 >> 6 & 0x1f;
                      *(short *)uptr24 =
                           (((short)uvalue18 +
                            (short)uptr9[((uvalue16 >> 0x1a & 0x1f) - uvalue18) + 0x161165]) * 0x20 +
                            (short)uvalue19 +
                           (short)uptr9[(((uvalue16 >> 0x10 & 0x3e0) >> 5) - uvalue19) + 0x161165]) *
                           0x40 + (short)(uvalue17 & 0x1f) +
                           (short)uptr9[((uvalue16 >> 0x10 & 0x1f) - (uvalue17 & 0x1f)) + 0x161165];
                      uptr24 = (uint64_t *)((intptr_t)uptr24 + 2);
                      uptr15 = (uint32_t *)((intptr_t)uptr15 + -1);
                      if (uptr15 == (uint32_t *)0x0) {
                        uptr15 = (uint32_t *)0x0;
                        goto LAB_0053ad3a;
                      }
                    }
                  }
                  uptr9 = (uint32_t *)(uvalue16 >> 0x10);
                  uptr24 = (uint64_t *)((intptr_t)uptr24 + (intptr_t)uptr9 * 2);
                  uptr15 = (uint32_t *)((intptr_t)uptr15 - (intptr_t)uptr9);
                } while (0 < (intptr_t)uptr15);
              }
            }
            else {
              do {
                uvalue16 = *arg2;
                arg2 = arg2 + 1;
                if ((uvalue16 & 0xffff) != 0) {
                  uptr13 = (uint32_t *)((intptr_t)uptr13 + -1);
                  goto joined_r0x0053ab89;
                }
                uptr9 = (uint32_t *)(uvalue16 >> 0x10);
                uptr11 = (uint32_t *)((intptr_t)uptr13 - (intptr_t)uptr9);
                flag8 = (intptr_t)uptr9 <= (intptr_t)uptr13;
                uptr13 = uptr11;
              } while (uptr11 != (uint32_t *)0x0 && flag8);
              uptr15 = (uint32_t *)((intptr_t)local_8 + (intptr_t)uptr11);
              uptr24 = (uint64_t *)((intptr_t)uptr25 + (intptr_t)uptr11 * -2);
              if (0 < (intptr_t)uptr15) goto LAB_0053abb2;
            }
LAB_0053ad3a:
            for (value12 = (intptr_t)uptr14 + (-(intptr_t)local_8 - (intptr_t)arg4) + (intptr_t)uptr15; value12 != 0;
                value12 = value12 - (intptr_t)uptr9) {
              while( true ) {
                uptr9 = (uint32_t *)*arg2;
                arg2 = arg2 + 1;
                if (((uint32_t)uptr9 & 0xffff) == 0) break;
                value12 = value12 + -1;
                if (value12 == 0) goto LAB_0053ad5b;
              }
              uptr9 = (uint32_t *)((uint32_t)uptr9 >> 0x10);
            }
LAB_0053ad5b:
            uptr25 = (uint64_t *)((intptr_t)uptr25 + value10);
            local_c = local_c + -1;
            uptr13 = arg4;
            if (local_c == 0) {
              return uptr9;
            }
          } while( true );
        }
        cVar4 = *(char *)(arg1 + 0x18);
        for (; uptr13 = arg4, local_18 != 0; local_18 = local_18 + -1) {
          uptr13 = (uint32_t *)arg6;
          uptr14 = arg2;
          do {
            while( true ) {
              arg2 = (uint32_t *)((intptr_t)uptr14 + 2);
              if (((uint16_t)*uptr14 & 0xff) == 0) break;
              uptr13 = (uint32_t *)((intptr_t)uptr13 + -1);
              uptr14 = arg2;
              if (uptr13 == (uint32_t *)0x0) goto LAB_0053a91a;
            }
            uptr13 = (uint32_t *)((intptr_t)uptr13 - (uint32_t)(uint16_t)((uint16_t)*uptr14 >> 8));
            uptr14 = arg2;
          } while (uptr13 != (uint32_t *)0x0);
LAB_0053a91a:
        }
joined_r0x0053a92a:
        do {
          uptr14 = local_8;
          uptr15 = arg2;
          uptr24 = uptr25;
          if (uptr13 == (uint32_t *)0x0) {
LAB_0053a957:
            uptr13 = uptr14;
            if (cVar4 == '\0') {
              do {
                while( true ) {
                  arg2 = (uint32_t *)((intptr_t)uptr15 + 2);
                  uvalue16 = *uptr15;
                  uvalue7 = (uint16_t)uvalue16;
                  uptr15 = arg2;
                  if ((uvalue7 & 0xff) == 0) break;
                  if ((char)uvalue16 == '<') {
                    uptr9 = *(uint32_t **)(arg3 + (uint32_t)(uvalue7 >> 8) * 2);
                    *(short *)uptr24 = (short)uptr9;
                    uptr24 = (uint64_t *)((intptr_t)uptr24 + 2);
                    uptr13 = (uint32_t *)((intptr_t)uptr13 + -1);
                    if (uptr13 == (uint32_t *)0x0) {
                      uptr14 = (uint32_t *)0x0;
                      goto LAB_0053aaf6;
                    }
                  }
                  else {
                    uvalue5 = (uint16_t)*uptr24;
                    uvalue6 = *(uint16_t *)(arg3 + (uint32_t)(uint8_t)(uvalue16 >> 8) * 2);
                    uptr9 = (uint32_t *)((uvalue7 & 0xff) * 0x40);
                    uvalue16 = (uvalue5 & 0xf800) >> 10;
                    uvalue17 = uvalue5 >> 5 & 0x1f;
                    uvalue18 = uvalue5 & 0x1f;
                    *(short *)uptr24 =
                         (((short)uvalue16 + (short)uptr9[((uvalue6 >> 10 & 0x1f) - uvalue16) + 0x161165]
                          ) * 0x20 + (short)uvalue17 +
                         (short)uptr9[(((uvalue6 & 0x3e0) >> 5) - uvalue17) + 0x161165]) * 0x20 +
                         (short)uvalue18 + (short)uptr9[((uvalue6 & 0x1f) - uvalue18) + 0x161165];
                    uptr24 = (uint64_t *)((intptr_t)uptr24 + 2);
                    uptr13 = (uint32_t *)((intptr_t)uptr13 + -1);
                    uptr14 = (uint32_t *)0x0;
                    if (uptr13 == (uint32_t *)0x0) goto LAB_0053aaf6;
                  }
                }
                uptr9 = (uint32_t *)(uint32_t)(uvalue7 >> 8);
                uptr24 = (uint64_t *)((intptr_t)uptr24 + (intptr_t)uptr9 * 2);
                uptr14 = (uint32_t *)((intptr_t)uptr13 - (intptr_t)uptr9);
                uptr13 = uptr14;
              } while (0 < (intptr_t)uptr14);
            }
            else {
              do {
                while( true ) {
                  arg2 = (uint32_t *)((intptr_t)uptr15 + 2);
                  uvalue16 = *uptr15;
                  uvalue7 = (uint16_t)uvalue16;
                  uptr15 = arg2;
                  if ((uvalue7 & 0xff) == 0) break;
                  if ((char)uvalue16 == '<') {
                    uvalue16 = *(uint32_t *)(arg3 + (uint32_t)(uvalue7 >> 8) * 2);
                    uptr9 = (uint32_t *)(uvalue16 + (uvalue16 & 0x7fe0));
                    *(short *)uptr24 = (short)uptr9;
                    uptr24 = (uint64_t *)((intptr_t)uptr24 + 2);
                    uptr14 = (uint32_t *)((intptr_t)uptr14 + -1);
                    if (uptr14 == (uint32_t *)0x0) {
                      uptr14 = (uint32_t *)0x0;
                      goto LAB_0053aaf6;
                    }
                  }
                  else {
                    uvalue5 = (uint16_t)*uptr24;
                    uvalue6 = *(uint16_t *)(arg3 + (uint32_t)(uint8_t)(uvalue16 >> 8) * 2);
                    uptr9 = (uint32_t *)((uvalue7 & 0xff) * 0x40);
                    uvalue16 = uvalue5 >> 6 & 0x1f;
                    *(uint16_t *)uptr24 =
                         (((uvalue5 >> 0xb) +
                          (short)uptr9[((uvalue6 >> 10 & 0x1f) - (uint32_t)(uvalue5 >> 0xb)) + 0x161165]) *
                          0x20 + (short)uvalue16 +
                         (short)uptr9[(((uvalue6 & 0x3e0) >> 5) - uvalue16) + 0x161165]) * 0x40 +
                         (short)(uvalue5 & 0x1f) +
                         (short)uptr9[((uvalue6 & 0x1f) - (uvalue5 & 0x1f)) + 0x161165];
                    uptr24 = (uint64_t *)((intptr_t)uptr24 + 2);
                    uptr14 = (uint32_t *)((intptr_t)uptr14 + -1);
                    if (uptr14 == (uint32_t *)0x0) {
                      uptr14 = (uint32_t *)0x0;
                      goto LAB_0053aaf6;
                    }
                  }
                }
                uptr9 = (uint32_t *)(uint32_t)(uvalue7 >> 8);
                uptr24 = (uint64_t *)((intptr_t)uptr24 + (intptr_t)uptr9 * 2);
                uptr14 = (uint32_t *)((intptr_t)uptr14 - (intptr_t)uptr9);
              } while (0 < (intptr_t)uptr14);
            }
          }
          else {
            do {
              arg2 = (uint32_t *)((intptr_t)uptr15 + 2);
              if (((uint16_t)*uptr15 & 0xff) != 0) {
                uptr13 = (uint32_t *)((intptr_t)uptr13 + -1);
                goto joined_r0x0053a92a;
              }
              uptr9 = (uint32_t *)(uint32_t)(uint16_t)((uint16_t)*uptr15 >> 8);
              uptr11 = (uint32_t *)((intptr_t)uptr13 - (intptr_t)uptr9);
              flag8 = (intptr_t)uptr9 <= (intptr_t)uptr13;
              uptr13 = uptr11;
              uptr15 = arg2;
            } while (uptr11 != (uint32_t *)0x0 && flag8);
            uptr14 = (uint32_t *)((intptr_t)local_8 + (intptr_t)uptr11);
            uptr24 = (uint64_t *)((intptr_t)uptr25 + (intptr_t)uptr11 * -2);
            if (0 < (intptr_t)uptr14) goto LAB_0053a957;
          }
LAB_0053aaf6:
          for (value12 = (intptr_t)arg6 + (-(intptr_t)local_8 - (intptr_t)arg4) + (intptr_t)uptr14;
              uptr13 = arg2, value12 != 0; value12 = value12 - (intptr_t)uptr9) {
            while( true ) {
              arg2 = (uint32_t *)((intptr_t)uptr13 + 2);
              uvalue7 = (uint16_t)*uptr13;
              uptr9 = (uint32_t *)(uint32_t)uvalue7;
              if ((uvalue7 & 0xff) == 0) break;
              value12 = value12 + -1;
              uptr13 = arg2;
              if (value12 == 0) goto LAB_0053ab1b;
            }
            uptr9 = (uint32_t *)(uint32_t)(uvalue7 >> 8);
          }
LAB_0053ab1b:
          uptr25 = (uint64_t *)((intptr_t)uptr25 + value10);
          local_c = local_c + -1;
          uptr13 = arg4;
          if (local_c == 0) {
            return uptr9;
          }
        } while( true );
      }
      if ((flag3 & 1) == 0) {
        if ((flag3 & 2) != 0) {
          if (flag2 < 9) {
            uptr13 = (uint32_t *)((intptr_t)arg2 + (intptr_t)(local_18 * (intptr_t)arg6 + (intptr_t)arg4));
            do {
              uptr9 = (uint32_t *)((uint32_t)uptr13 & 3);
              uptr14 = local_8;
              uptr11 = uptr13;
              uptr24 = uptr25;
              for (uvalue16 = 4U - (intptr_t)uptr9 & 3; uptr23 = uptr11, uvalue16 != 0;
                  uvalue16 = uvalue16 - 1) {
                uptr23 = (uint32_t *)((intptr_t)uptr11 + 1);
                uptr9 = (uint32_t *)(uint32_t)(uint8_t)*uptr11;
                if (uptr9 != uptr15) {
                  uvalue7 = *(uint16_t *)(arg3 + (intptr_t)uptr9 * 2);
                  uptr9 = (uint32_t *)(uint32_t)uvalue7;
                  *(uint16_t *)uptr24 = uvalue7;
                }
                uptr24 = (uint64_t *)((intptr_t)uptr24 + 2);
                uptr14 = (uint32_t *)((intptr_t)uptr14 + -1);
                if (uptr14 == (uint32_t *)0x0) break;
                uptr11 = uptr23;
              }
              uvalue16 = (uint32_t)uptr14 >> 2;
              uptr11 = (uint32_t *)0x0;
              if (uvalue16 != 0) {
                do {
                  uvalue17 = *uptr23;
                  uptr23 = uptr23 + 1;
                  if ((uint32_t *)(uvalue17 & 0xff) != uptr15) {
                    *(uint16_t *)uptr24 = *(uint16_t *)(arg3 + (intptr_t)(uvalue17 & 0xff) * 2);
                  }
                  uptr9 = (uint32_t *)(uvalue17 >> 8 & 0xff);
                  if (uptr9 != uptr15) {
                    *(uint16_t *)((intptr_t)uptr24 + 2) = *(uint16_t *)(arg3 + (intptr_t)uptr9 * 2);
                  }
                  uptr9 = (uint32_t *)(uvalue17 >> 0x10 & 0xff);
                  if (uptr9 != uptr15) {
                    uvalue7 = *(uint16_t *)(arg3 + (intptr_t)uptr9 * 2);
                    uptr9 = (uint32_t *)(uint32_t)uvalue7;
                    *(uint16_t *)((intptr_t)uptr24 + 4) = uvalue7;
                  }
                  if ((uint32_t *)(uvalue17 >> 0x18) != uptr15) {
                    uvalue7 = *(uint16_t *)(arg3 + (intptr_t)(uvalue17 >> 0x18) * 2);
                    uptr9 = (uint32_t *)(uint32_t)uvalue7;
                    *(uint16_t *)((intptr_t)uptr24 + 6) = uvalue7;
                  }
                  uptr24 = uptr24 + 1;
                  uvalue16 = uvalue16 - 1;
                } while (uvalue16 != 0);
                uptr11 = uptr14;
              }
              for (uvalue16 = (uint32_t)uptr11 & 3; uvalue16 != 0; uvalue16 = uvalue16 - 1) {
                uptr9 = (uint32_t *)(uint32_t)(uint8_t)*uptr23;
                uptr23 = (uint32_t *)((intptr_t)uptr23 + 1);
                if (uptr9 != uptr15) {
                  uvalue7 = *(uint16_t *)(arg3 + (intptr_t)uptr9 * 2);
                  uptr9 = (uint32_t *)(uint32_t)uvalue7;
                  *(uint16_t *)uptr24 = uvalue7;
                }
                uptr24 = (uint64_t *)((intptr_t)uptr24 + 2);
              }
              uptr13 = (uint32_t *)((intptr_t)uptr13 + (intptr_t)arg6);
              uptr25 = (uint64_t *)((intptr_t)uptr25 + value10);
              local_c = local_c + -1;
              if (local_c == 0) {
                return uptr9;
              }
            } while( true );
          }
          if ((*(int *)(arg1 + 0x14) != 0) || (*(int *)(arg1 + 0x74) == 0)) {
            uptr13 = (uint32_t *)(local_18 * (intptr_t)arg6 + (intptr_t)arg4 * 2);
            uptr14 = (uint32_t *)((intptr_t)arg2 + (intptr_t)uptr13);
            do {
              uptr11 = local_8;
              uptr9 = uptr14;
              uptr24 = uptr25;
              do {
                uptr20 = uptr24;
                if (((uint32_t)uptr11 & 1) == 0) break;
                uvalue7 = (uint16_t)*uptr9;
                uptr13 = (uint32_t *)CONCAT22((short)((uint32_t)uptr13 >> 0x10),uvalue7);
                uptr20 = (uint64_t *)((intptr_t)uptr24 + 2);
                if (uvalue7 != (uint16_t)uptr15) {
                  *(uint16_t *)uptr24 = uvalue7;
                }
                uptr9 = (uint32_t *)((intptr_t)uptr9 + 2);
                uptr11 = (uint32_t *)(((uint32_t)uptr11 & 1) - 1);
                uptr24 = uptr20;
              } while (uptr11 != (uint32_t *)0x0);
              for (uvalue16 = (uint32_t)local_8 >> 1; uvalue16 != 0; uvalue16 = uvalue16 - 1) {
                uvalue17 = *uptr9;
                uptr9 = uptr9 + 1;
                uptr13 = (uint32_t *)(uvalue17 >> 0x10);
                if ((uint32_t *)(uvalue17 & 0xffff) != uptr15) {
                  *(short *)uptr20 = (short)uvalue17;
                }
                if (uptr13 != uptr15) {
                  *(short *)((intptr_t)uptr20 + 2) = (short)(uvalue17 >> 0x10);
                }
                uptr20 = (uint64_t *)((intptr_t)uptr20 + 4);
              }
              uptr14 = (uint32_t *)((intptr_t)uptr14 + (intptr_t)arg6);
              uptr25 = (uint64_t *)((intptr_t)uptr25 + value10);
              local_c = local_c + -1;
              if (local_c == 0) {
                return uptr13;
              }
            } while( true );
          }
          uptr24 = (uint64_t *)((intptr_t)arg2 + local_18 * (intptr_t)arg6 + (intptr_t)arg4 * 2);
          do {
            uptr14 = (uint32_t *)0x0;
            uptr13 = local_8;
            uptr20 = uptr24;
            uptr27 = uptr25;
            do {
              uptr26 = uptr27;
              if (((uint32_t)uptr13 & 3) == 0) break;
              uptr14 = (uint32_t *)(uint32_t)(uint16_t)*uptr20;
              uptr26 = (uint64_t *)((intptr_t)uptr27 + 2);
              if (uptr14 != uptr15) {
                *(uint16_t *)uptr27 = (uint16_t)*uptr20;
              }
              uptr20 = (uint64_t *)((intptr_t)uptr20 + 2);
              uptr13 = (uint32_t *)(((uint32_t)uptr13 & 3) - 1);
              uptr27 = uptr26;
            } while (uptr13 != (uint32_t *)0x0);
            for (uvalue16 = (uint32_t)local_8 >> 2; uvalue16 != 0; uvalue16 = uvalue16 - 1) {
              uvalue1 = *uptr20;
              uptr20 = uptr20 + 1;
              uvalue28 = CONCAT26(-(uint16_t)((short)(uvalue1 >> 0x30) ==
                                         (short)((uint64_t)lvalue29 >> 0x30)),
                                CONCAT24(-(uint16_t)((short)(uvalue1 >> 0x20) ==
                                                  (short)((uint64_t)lvalue29 >> 0x20)),
                                         CONCAT22(-(uint16_t)((short)(uvalue1 >> 0x10) ==
                                                           (short)((uint64_t)lvalue29 >> 0x10)),
                                                  -(uint16_t)((short)uvalue1 == (short)lvalue29))));
              *uptr26 = uvalue1 & (uvalue28 ^ 0xffffffffffffffff) | *uptr26 & uvalue28;
              uptr26 = uptr26 + 1;
            }
            uptr24 = (uint64_t *)((intptr_t)uptr24 + (intptr_t)arg6);
            uptr25 = (uint64_t *)((intptr_t)uptr25 + value10);
            local_c = local_c + -1;
            if (local_c == 0) {
              return uptr14;
            }
          } while( true );
        }
        if (flag2 < 9) {
          uptr13 = (uint32_t *)((intptr_t)arg2 + (intptr_t)(local_18 * (intptr_t)arg6 + (intptr_t)arg4));
          do {
            uptr15 = (uint32_t *)((uint32_t)uptr13 & 3);
            uptr14 = local_8;
            uptr9 = uptr13;
            uptr24 = uptr25;
            for (uvalue16 = 4U - (intptr_t)uptr15 & 3; uvalue16 != 0; uvalue16 = uvalue16 - 1) {
              uvalue17 = *uptr9;
              uptr9 = (uint32_t *)((intptr_t)uptr9 + 1);
              uvalue7 = *(uint16_t *)(arg3 + (uint32_t)(uint8_t)uvalue17 * 2);
              uptr15 = (uint32_t *)(uint32_t)uvalue7;
              *(uint16_t *)uptr24 = uvalue7;
              uptr24 = (uint64_t *)((intptr_t)uptr24 + 2);
              uptr14 = (uint32_t *)((intptr_t)uptr14 + -1);
              if (uptr14 == (uint32_t *)0x0) break;
            }
            uvalue16 = (uint32_t)uptr14 >> 2;
            uptr11 = (uint32_t *)0x0;
            if (uvalue16 != 0) {
              do {
                uvalue17 = *uptr9;
                uptr9 = uptr9 + 1;
                *(uint32_t *)uptr24 =
                     *(uint32_t *)(arg3 + (uvalue17 & 0xff) * 2) & 0xffff |
                     *(int *)(arg3 + (uvalue17 >> 8 & 0xff) * 2) << 0x10;
                uptr15 = (uint32_t *)(*(int *)(arg3 + (uvalue17 >> 0x18) * 2) << 0x10 |
                                  *(uint32_t *)(arg3 + (uvalue17 >> 0x10 & 0xff) * 2) & 0xffff);
                *(uint32_t **)((intptr_t)uptr24 + 4) = uptr15;
                uptr24 = uptr24 + 1;
                uvalue16 = uvalue16 - 1;
              } while (uvalue16 != 0);
              uptr11 = uptr14;
            }
            for (uvalue16 = (uint32_t)uptr11 & 3; uvalue16 != 0; uvalue16 = uvalue16 - 1) {
              uvalue17 = *uptr9;
              uptr9 = (uint32_t *)((intptr_t)uptr9 + 1);
              uvalue7 = *(uint16_t *)(arg3 + (uint32_t)(uint8_t)uvalue17 * 2);
              uptr15 = (uint32_t *)(uint32_t)uvalue7;
              *(uint16_t *)uptr24 = uvalue7;
              uptr24 = (uint64_t *)((intptr_t)uptr24 + 2);
            }
            uptr13 = (uint32_t *)((intptr_t)uptr13 + (intptr_t)arg6);
            uptr25 = (uint64_t *)((intptr_t)uptr25 + value10);
            local_c = local_c + -1;
            if (local_c == 0) {
              return uptr15;
            }
          } while( true );
        }
        if (*(int *)(arg1 + 0x74) == 0) {
          uptr13 = (uint32_t *)(local_18 * (intptr_t)arg6 + (intptr_t)arg4 * 2);
          ptr21 = (int *)((intptr_t)arg2 + (intptr_t)uptr13);
          do {
            ptr22 = ptr21;
            uptr24 = uptr25;
            if (((uint32_t)local_8 & 1) != 0) {
              uptr13 = (uint32_t *)CONCAT22((short)((uint32_t)uptr13 >> 0x10),(short)*ptr21);
              uptr24 = (uint64_t *)((intptr_t)uptr25 + 2);
              *(short *)uptr25 = (short)*ptr21;
              ptr22 = (int *)((intptr_t)ptr21 + 2);
            }
            for (uvalue16 = (uint32_t)local_8 >> 1; uvalue16 != 0; uvalue16 = uvalue16 - 1) {
              uptr13 = (uint32_t *)*ptr22;
              *(uint32_t **)uptr24 = uptr13;
              ptr22 = ptr22 + 1;
              uptr24 = (uint64_t *)((intptr_t)uptr24 + 4);
            }
            ptr21 = (int *)((intptr_t)ptr21 + (intptr_t)arg6);
            uptr25 = (uint64_t *)((intptr_t)uptr25 + value10);
            local_c = local_c + -1;
          } while (local_c != 0);
          return uptr13;
        }
        uptr13 = (uint32_t *)(local_18 * (intptr_t)arg6 + (intptr_t)arg4 * 2);
        uptr24 = (uint64_t *)((intptr_t)arg2 + (intptr_t)uptr13);
        do {
          uptr14 = local_8;
          uptr20 = uptr24;
          uptr27 = uptr25;
          do {
            uptr26 = uptr27;
            if (((uint32_t)uptr14 & 3) == 0) break;
            uptr13 = (uint32_t *)CONCAT22((short)((uint32_t)uptr13 >> 0x10),(short)*uptr20);
            uptr26 = (uint64_t *)((intptr_t)uptr27 + 2);
            *(short *)uptr27 = (short)*uptr20;
            uptr20 = (uint64_t *)((intptr_t)uptr20 + 2);
            uptr14 = (uint32_t *)(((uint32_t)uptr14 & 3) - 1);
            uptr27 = uptr26;
          } while (uptr14 != (uint32_t *)0x0);
          for (uvalue16 = (uint32_t)local_8 >> 2; uvalue16 != 0; uvalue16 = uvalue16 - 1) {
            *uptr26 = *uptr20;
            uptr20 = uptr20 + 1;
            uptr26 = uptr26 + 1;
          }
          uptr24 = (uint64_t *)((intptr_t)uptr24 + (intptr_t)arg6);
          uptr25 = (uint64_t *)((intptr_t)uptr25 + value10);
          local_c = local_c + -1;
          if (local_c == 0) {
            return uptr13;
          }
        } while( true );
      }
      if (8 < flag2) {
        uptr13 = local_8;
        for (; uptr9 = arg4, local_18 != 0; local_18 = local_18 + -1) {
          uptr13 = uptr14;
          uptr9 = arg2;
          do {
            while (arg2 = (uint32_t *)((intptr_t)uptr9 + 2), (uint32_t *)(uint32_t)(uint16_t)*uptr9 != uptr15) {
              uptr13 = (uint32_t *)((intptr_t)uptr13 + -1);
              uptr9 = arg2;
              if (uptr13 == (uint32_t *)0x0) goto LAB_0053b175;
            }
            uptr9 = uptr9 + 1;
            uptr13 = (uint32_t *)((intptr_t)uptr13 - (uint32_t)*(uint16_t *)arg2);
            arg2 = uptr9;
          } while (uptr13 != (uint32_t *)0x0);
LAB_0053b175:
          uptr13 = (uint32_t *)0x0;
        }
joined_r0x0053b188:
        do {
          uptr11 = local_8;
          uptr24 = uptr25;
          if (uptr9 == (uint32_t *)0x0) goto LAB_0053b1b8;
          do {
            uptr13 = (uint32_t *)(uint32_t)(uint16_t)*arg2;
            if (uptr13 != uptr15) {
              arg2 = (uint32_t *)((intptr_t)arg2 + 2);
              uptr9 = (uint32_t *)((intptr_t)uptr9 + -1);
              goto joined_r0x0053b188;
            }
            uptr23 = arg2 + 1;
            uptr13 = (uint32_t *)(uint32_t)*(uint16_t *)((intptr_t)arg2 + 2);
            uptr11 = (uint32_t *)((intptr_t)uptr9 - (intptr_t)uptr13);
            flag8 = (intptr_t)uptr13 <= (intptr_t)uptr9;
            uptr9 = uptr11;
            arg2 = uptr23;
          } while (uptr11 != (uint32_t *)0x0 && flag8);
          uptr24 = (uint64_t *)((intptr_t)uptr25 + (intptr_t)uptr11 * -2);
          for (uptr11 = (uint32_t *)((intptr_t)local_8 + (intptr_t)uptr11); arg2 = uptr23, 0 < (intptr_t)uptr11;
              uptr11 = (uint32_t *)((intptr_t)uptr11 - (intptr_t)uptr13)) {
LAB_0053b1b8:
            while( true ) {
              uvalue7 = (uint16_t)*arg2;
              uptr13 = (uint32_t *)CONCAT22((short)((uint32_t)uptr13 >> 0x10),uvalue7);
              uptr23 = (uint32_t *)((intptr_t)arg2 + 2);
              if (uvalue7 == (uint16_t)uptr15) break;
              *(uint16_t *)uptr24 = uvalue7;
              uptr11 = (uint32_t *)((intptr_t)uptr11 + -1);
              arg2 = uptr23;
              uptr24 = (uint64_t *)((intptr_t)uptr24 + 2);
              if (uptr11 == (uint32_t *)0x0) {
                uptr11 = (uint32_t *)0x0;
                goto LAB_0053b1e2;
              }
            }
            uptr23 = arg2 + 1;
            uptr13 = (uint32_t *)(uint32_t)*(uint16_t *)((intptr_t)arg2 + 2);
            uptr24 = (uint64_t *)((intptr_t)uptr24 + (intptr_t)uptr13 * 2);
          }
LAB_0053b1e2:
          value12 = (intptr_t)uptr14 + (-(intptr_t)local_8 - (intptr_t)arg4) + (intptr_t)uptr11;
          uptr9 = uptr23;
          if (0 < value12) {
            do {
              while( true ) {
                uptr23 = (uint32_t *)((intptr_t)uptr9 + 2);
                uptr13 = (uint32_t *)(uint32_t)(uint16_t)*uptr9;
                if (uptr13 == uptr15) break;
                value12 = value12 + -1;
                uptr9 = uptr23;
                if (value12 == 0) goto LAB_0053b20e;
              }
              uptr23 = uptr9 + 1;
              uptr13 = (uint32_t *)(uint32_t)*(uint16_t *)((intptr_t)uptr9 + 2);
              value12 = value12 - (intptr_t)uptr13;
              uptr9 = uptr23;
            } while (value12 != 0);
          }
LAB_0053b20e:
          uptr25 = (uint64_t *)((intptr_t)uptr25 + value10);
          local_c = local_c + -1;
          arg2 = uptr23;
          uptr9 = arg4;
          if (local_c == 0) {
            return uptr13;
          }
        } while( true );
      }
      for (; uptr14 = arg4, local_18 != 0; local_18 = local_18 + -1) {
        uptr13 = (uint32_t *)arg6;
        uptr14 = arg2;
        do {
          while (arg2 = (uint32_t *)((intptr_t)uptr14 + 1), (uint32_t *)(uint32_t)(uint8_t)*uptr14 == uptr15) {
            uptr14 = (uint32_t *)((intptr_t)uptr14 + 2);
            uptr13 = (uint32_t *)((intptr_t)uptr13 - (uint32_t)*(uint8_t *)arg2);
            arg2 = uptr14;
            if (uptr13 == (uint32_t *)0x0) goto LAB_0053b257;
          }
          uptr13 = (uint32_t *)((intptr_t)uptr13 + -1);
          uptr14 = arg2;
        } while (uptr13 != (uint32_t *)0x0);
LAB_0053b257:
      }
      do {
        for (; uptr9 = local_8, uptr24 = uptr25, uptr14 != (uint32_t *)0x0;
            uptr14 = (uint32_t *)((intptr_t)uptr14 + -1)) {
          while ((uint8_t)*arg2 == (uint8_t)lvalue29) {
            uptr11 = (uint32_t *)((intptr_t)arg2 + 2);
            uptr13 = (uint32_t *)(uint32_t)*(uint8_t *)((intptr_t)arg2 + 1);
            uptr9 = (uint32_t *)((intptr_t)uptr14 - (intptr_t)uptr13);
            flag8 = (intptr_t)uptr14 < (intptr_t)uptr13;
            uptr14 = uptr9;
            arg2 = uptr11;
            if (uptr9 == (uint32_t *)0x0 || flag8) {
              uptr24 = (uint64_t *)((intptr_t)uptr25 + (intptr_t)uptr9 * -2);
              uptr9 = (uint32_t *)((intptr_t)local_8 + (intptr_t)uptr9);
              goto joined_r0x0053b292;
            }
          }
          arg2 = (uint32_t *)((intptr_t)arg2 + 1);
        }
        do {
          while( true ) {
            uptr11 = (uint32_t *)((intptr_t)arg2 + 1);
            if ((uint32_t *)(uint32_t)(uint8_t)*arg2 == uptr15) break;
            uvalue7 = *(uint16_t *)(arg3 + (intptr_t)(uint32_t)(uint8_t)*arg2 * 2);
            uptr13 = (uint32_t *)(uint32_t)uvalue7;
            *(uint16_t *)uptr24 = uvalue7;
            uptr9 = (uint32_t *)((intptr_t)uptr9 + -1);
            arg2 = uptr11;
            uptr24 = (uint64_t *)((intptr_t)uptr24 + 2);
            if (uptr9 == (uint32_t *)0x0) {
              uptr9 = (uint32_t *)0x0;
              goto LAB_0053b2c2;
            }
          }
          uptr11 = (uint32_t *)((intptr_t)arg2 + 2);
          uptr13 = (uint32_t *)(uint32_t)*(uint8_t *)((intptr_t)arg2 + 1);
          uptr24 = (uint64_t *)((intptr_t)uptr24 + (intptr_t)uptr13 * 2);
          uptr9 = (uint32_t *)((intptr_t)uptr9 - (intptr_t)uptr13);
joined_r0x0053b292:
          arg2 = uptr11;
        } while (0 < (intptr_t)uptr9);
LAB_0053b2c2:
        for (value12 = (intptr_t)arg6 + (-(intptr_t)local_8 - (intptr_t)arg4) + (intptr_t)uptr9; uptr14 = uptr11
            , value12 != 0; value12 = value12 - (intptr_t)uptr13) {
          while( true ) {
            uptr11 = (uint32_t *)((intptr_t)uptr14 + 1);
            uptr13 = (uint32_t *)(uint32_t)(uint8_t)*uptr14;
            if ((uint8_t)*uptr14 == (uint8_t)lvalue29) break;
            value12 = value12 + -1;
            uptr14 = uptr11;
            if (value12 == 0) goto LAB_0053b2e5;
          }
          uptr11 = (uint32_t *)((intptr_t)uptr14 + 2);
          uptr13 = (uint32_t *)(uint32_t)*(uint8_t *)((intptr_t)uptr14 + 1);
        }
LAB_0053b2e5:
        uptr25 = (uint64_t *)((intptr_t)uptr25 + value10);
        local_c = local_c + -1;
        arg2 = uptr11;
        uptr14 = arg4;
      } while (local_c != 0);
    }
  }
  return uptr13;
}
