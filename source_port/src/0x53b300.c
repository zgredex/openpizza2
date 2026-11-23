// Sprite_BlitAlphaRLE: ported from Pizza Connection 2 at 0x53b300.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53b300
#include "pc2_port.h"

void __thiscall
Sprite_BlitAlphaRLE(void *self,uint32_t *arg1,void *arg2,uint16_t *arg3,int arg4,uint32_t *arg5
                   ,int arg6,uint8_t arg7)

{
  uint8_t flag1;
  uint8_t flag2;
  uint16_t uvalue3;
  uint16_t uvalue4;
  uint16_t uvalue5;
  uint32_t uvalue6;
  bool flag7;
  uint32_t uvalue8;
  int value9;
  uint32_t *uptr10;
  int value11;
  int value12;
  int value13;
  int value14;
  uint32_t uvalue15;
  uint32_t uvalue16;
  uint32_t uvalue17;
  uint32_t uvalue18;
  int value19;
  uint8_t *bptr20;
  uint16_t *uptr21;
  uint16_t *uptr22;
  uint16_t *uptr23;
  uint16_t *uptr24;
  int local_1c;
  uint32_t *local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  Object_GetPair4(arg2,&local_c,&local_10);
  if ((*(uint8_t *)((intptr_t)self + 4) & 4) == 0) {
    local_18 = arg5;
  }
  else {
    arg6 = arg6 + *(short *)((intptr_t)self + 0xc);
    local_18 = (uint32_t *)((intptr_t)arg5 + (intptr_t)*(short *)((intptr_t)self + 10));
  }
  value19 = (intptr_t)*(short *)((intptr_t)self + 6);
  value14 = (intptr_t)*(short *)((intptr_t)self + 8);
  local_14 = 0;
  local_1c = 0;
  arg5 = (uint32_t *)arg6;
  if ((intptr_t)local_18 < 0) {
    value19 = value19 + (intptr_t)local_18;
    local_14 = -(intptr_t)local_18;
    if (value19 < 1) {
      return;
    }
    local_18 = (uint32_t *)0x0;
  }
  if (arg6 < 0) {
    value14 = value14 + arg6;
    local_1c = -arg6;
    if (value14 < 1) {
      return;
    }
    arg5 = (uint32_t *)0x0;
  }
  if ((((intptr_t)local_18 + value19 < local_c) || (value19 = local_c - (intptr_t)local_18, 0 < value19)) &&
     (((intptr_t)arg5 + value14 < local_10 || (value14 = local_10 - (intptr_t)arg5, 0 < value14)))) {
    uvalue8 = (intptr_t)local_18 + value19;
    value11 = arg1[8] * (intptr_t)arg5 + arg1[10];
    value9 = Object_GetPair10(arg2,&local_8);
    uvalue6 = arg1[8];
    value12 = (intptr_t)*(short *)((intptr_t)self + 6);
    arg5 = (uint32_t *)(value9 + local_8 * (intptr_t)arg5 * 2);
    if ((value19 != 0) && (value14 != 0)) {
      if ((*(uint8_t *)((intptr_t)self + 4) & 1) == 0) {
        if (*(char *)((intptr_t)self + 5) == '\b') {
          flag1 = *(uint8_t *)((intptr_t)self + 0x1c);
          value19 = value12 * local_1c + local_14 + (intptr_t)arg3;
          do {
            arg1 = arg5;
            arg5 = (uint32_t *)((intptr_t)arg5 + local_8 * 2);
            while( true ) {
              uvalue15 = *arg1;
              arg1 = arg1 + 1;
              uptr10 = (uint32_t *)(uvalue15 & 0xffff);
              if (uptr10 == (uint32_t *)0xffff) break;
              uvalue15 = uvalue15 >> 0x10;
              if ((intptr_t)local_18 < (intptr_t)uvalue15) {
                if ((intptr_t)uvalue8 <= (intptr_t)uptr10) break;
                if ((intptr_t)uvalue8 <= (intptr_t)uvalue15) {
                  uvalue15 = uvalue8;
                }
                if ((intptr_t)uptr10 <= (intptr_t)local_18) {
                  uptr10 = local_18;
                }
                uptr23 = (uint16_t *)(value11 + (intptr_t)uptr10 * 3);
                value9 = uvalue15 - (intptr_t)uptr10;
                bptr20 = (uint8_t *)((intptr_t)uptr10 + (value19 - (intptr_t)local_18));
                do {
                  flag2 = *bptr20;
                  if (flag2 != flag1) {
                    *(uint8_t *)(uptr23 + 1) = arg7;
                    *uptr23 = *(uint16_t *)(arg4 + (uint32_t)flag2 * 2);
                  }
                  uptr23 = (uint16_t *)((intptr_t)uptr23 + 3);
                  value9 = value9 + -1;
                  bptr20 = bptr20 + 1;
                } while (value9 != 0);
              }
            }
            value11 = value11 + uvalue6;
            value19 = value19 + value12;
            value14 = value14 + -1;
            if (value14 == 0) {
              return;
            }
          } while( true );
        }
      }
      else if (*(char *)((intptr_t)self + 5) == '\b') {
        flag1 = *(uint8_t *)((intptr_t)self + 0x1c);
        if ((*(uint8_t *)((intptr_t)self + 4) & 0x10) != 0) {
          uvalue15 = arg1[6];
LAB_0053b521:
          arg1 = arg5;
          arg5 = (uint32_t *)((intptr_t)arg5 + local_8 * 2);
          for (; local_1c != 0; local_1c = local_1c + -1) {
            value19 = value12;
            uptr24 = arg3;
            do {
              while( true ) {
                arg3 = uptr24 + 1;
                uvalue3 = *uptr24;
                uptr24 = arg3;
                if (((uvalue3 & 0xff) == 0) || ((uint8_t)uvalue3 == flag1)) break;
                value19 = value19 + -1;
                if (value19 == 0) goto LAB_0053b55b;
              }
              value9 = value19 - (uint32_t)(uvalue3 >> 8);
              flag7 = (intptr_t)(uint32_t)(uvalue3 >> 8) <= value19;
              value19 = value9;
            } while (value9 != 0 && flag7);
LAB_0053b55b:
          }
LAB_0053b566:
          do {
            uvalue16 = *arg1;
            arg1 = arg1 + 1;
            uptr10 = (uint32_t *)(uvalue16 & 0xffff);
            if (uptr10 == (uint32_t *)0xffff) goto LAB_0053b7ab;
            uvalue16 = uvalue16 >> 0x10;
            if ((intptr_t)local_18 < (intptr_t)uvalue16) {
              if ((intptr_t)uvalue8 <= (intptr_t)uptr10) goto LAB_0053b7ab;
              if ((intptr_t)uvalue8 <= (intptr_t)uvalue16) {
                uvalue16 = uvalue8;
              }
              if ((intptr_t)uptr10 <= (intptr_t)local_18) {
                uptr10 = local_18;
              }
              uptr24 = (uint16_t *)(value11 + (intptr_t)uptr10 * 3);
              value19 = uvalue16 - (intptr_t)uptr10;
              value9 = (intptr_t)uptr10 + (local_14 - (intptr_t)local_18);
              uptr21 = arg3;
              uptr22 = arg3;
              if (value9 != 0) {
                do {
                  while( true ) {
                    uptr22 = uptr21 + 1;
                    if ((*uptr21 & 0xff) == 0) break;
                    value9 = value9 + -1;
                    uptr21 = uptr22;
                    if (value9 == 0) goto LAB_0053b5ea;
                  }
                  uvalue16 = (uint32_t)(*uptr21 >> 8);
                  value13 = value9 - uvalue16;
                  flag7 = (intptr_t)uvalue16 <= value9;
                  value9 = value13;
                  uptr21 = uptr22;
                } while (value13 != 0 && flag7);
                value19 = value19 + value13;
                uptr24 = (uint16_t *)((intptr_t)uptr24 + value13 * -3);
                if (value19 < 1) goto LAB_0053b566;
              }
LAB_0053b5ea:
              if ((char)uvalue15 == '\0') {
                do {
                  while( true ) {
                    uvalue3 = *uptr22;
                    if ((uvalue3 & 0xff) == 0) break;
                    if ((char)uvalue3 == '<') {
                      *uptr24 = (uint16_t)*(uint32_t *)(arg4 + (uint32_t)(uvalue3 >> 8) * 2);
                      *(uint8_t *)(uptr24 + 1) = arg7;
                    }
                    else {
                      uvalue4 = *uptr24;
                      uvalue5 = *(uint16_t *)(arg4 + (uint32_t)(uint8_t)(uvalue3 >> 8) * 2);
                      value9 = (uvalue3 & 0xff) * 0x40 + 0x584594;
                      uvalue16 = (uvalue4 & 0xf800) >> 10;
                      uvalue17 = uvalue4 >> 5 & 0x1f;
                      uvalue18 = uvalue4 & 0x1f;
                      *uptr24 = (((short)uvalue16 +
                                  (short)*(uint32_t *)
                                          (value9 + ((uvalue5 >> 10 & 0x1f) - uvalue16) * 4)) * 0x20 +
                                  (short)uvalue17 +
                                 (short)*(uint32_t *)
                                         (value9 + (((uvalue5 & 0x3e0) >> 5) - uvalue17) * 4)) * 0x20 +
                                 (short)uvalue18 +
                                 (short)*(uint32_t *)(value9 + ((uvalue5 & 0x1f) - uvalue18) * 4);
                      *(uint8_t *)(uptr24 + 1) = arg7;
                    }
                    value19 = value19 + -1;
                    uptr24 = (uint16_t *)((intptr_t)uptr24 + 3);
                    uptr22 = uptr22 + 1;
                    if (value19 == 0) goto LAB_0053b566;
                  }
                  uptr24 = (uint16_t *)((intptr_t)uptr24 + (uint32_t)(uvalue3 >> 8) * 3);
                  value19 = value19 - (uint32_t)(uvalue3 >> 8);
                  uptr22 = uptr22 + 1;
                } while (0 < value19);
              }
              else {
                do {
                  while( true ) {
                    uvalue3 = *uptr22;
                    if ((uvalue3 & 0xff) == 0) break;
                    if ((char)uvalue3 == '<') {
                      uvalue3 = (uint16_t)*(uint32_t *)(arg4 + (uint32_t)(uvalue3 >> 8) * 2);
                      *uptr24 = uvalue3 + (uvalue3 & 0x7fe0);
                      *(uint8_t *)(uptr24 + 1) = arg7;
                    }
                    else {
                      uvalue4 = *uptr24;
                      uvalue5 = *(uint16_t *)(arg4 + (uint32_t)(uint8_t)(uvalue3 >> 8) * 2);
                      value9 = (uvalue3 & 0xff) * 0x40 + 0x584594;
                      uvalue16 = uvalue4 >> 6 & 0x1f;
                      *uptr24 = (((uvalue4 >> 0xb) +
                                  (short)*(uint32_t *)
                                          (value9 + ((uvalue5 >> 10 & 0x1f) - (uint32_t)(uvalue4 >> 0xb)) * 4
                                          )) * 0x20 + (short)uvalue16 +
                                 (short)*(uint32_t *)
                                         (value9 + (((uvalue5 & 0x3e0) >> 5) - uvalue16) * 4)) * 0x40 +
                                 (short)(uvalue4 & 0x1f) +
                                 (short)*(uint32_t *)
                                         (value9 + ((uvalue5 & 0x1f) - (uvalue4 & 0x1f)) * 4);
                      *(uint8_t *)(uptr24 + 1) = arg7;
                    }
                    value19 = value19 + -1;
                    uptr24 = (uint16_t *)((intptr_t)uptr24 + 3);
                    uptr22 = uptr22 + 1;
                    if (value19 == 0) goto LAB_0053b566;
                  }
                  uptr24 = (uint16_t *)((intptr_t)uptr24 + (uint32_t)(uvalue3 >> 8) * 3);
                  value19 = value19 - (uint32_t)(uvalue3 >> 8);
                  uptr22 = uptr22 + 1;
                } while (0 < value19);
              }
            }
          } while( true );
        }
        do {
          arg1 = arg5;
          arg5 = (uint32_t *)((intptr_t)arg5 + local_8 * 2);
          for (; local_1c != 0; local_1c = local_1c + -1) {
            value19 = value12;
            do {
              while ((uint8_t)*arg3 == flag1) {
                bptr20 = (uint8_t *)((intptr_t)arg3 + 1);
                arg3 = arg3 + 1;
                value9 = value19 - (uint32_t)*bptr20;
                flag7 = (intptr_t)(uint32_t)*bptr20 <= value19;
                value19 = value9;
                if (!(value9 != 0 && flag7)) goto LAB_0053b804;
              }
              arg3 = (uint16_t *)((intptr_t)arg3 + 1);
              value19 = value19 + -1;
            } while (value19 != 0);
LAB_0053b804:
          }
LAB_0053b80f:
          uvalue15 = *arg1;
          arg1 = arg1 + 1;
          uptr10 = (uint32_t *)(uvalue15 & 0xffff);
          if (uptr10 != (uint32_t *)0xffff) {
            uvalue15 = uvalue15 >> 0x10;
            if ((intptr_t)local_18 < (intptr_t)uvalue15) {
              if ((intptr_t)uvalue8 <= (intptr_t)uptr10) goto LAB_0053b8c6;
              if ((intptr_t)uvalue8 <= (intptr_t)uvalue15) {
                uvalue15 = uvalue8;
              }
              if ((intptr_t)uptr10 <= (intptr_t)local_18) {
                uptr10 = local_18;
              }
              uptr23 = (uint16_t *)(value11 + (intptr_t)uptr10 * 3);
              value9 = uvalue15 - (intptr_t)uptr10;
              uptr24 = arg3;
              for (value19 = (intptr_t)uptr10 + (local_14 - (intptr_t)local_18); value19 != 0;
                  value19 = value19 + -1) {
                while (uptr22 = (uint16_t *)((intptr_t)uptr24 + 1), (uint8_t)*uptr24 == flag1) {
                  uptr24 = uptr24 + 1;
                  value19 = value19 - (uint32_t)*(uint8_t *)uptr22;
                  if (value19 < 1) {
                    value9 = value9 + value19;
                    uptr23 = (uint16_t *)((intptr_t)uptr23 + value19 * -3);
                    if (0 < value9) goto LAB_0053b890;
                    goto LAB_0053b80f;
                  }
                }
                uptr24 = uptr22;
              }
LAB_0053b890:
              do {
                uvalue3 = *uptr24;
                if ((uint8_t)uvalue3 != flag1) {
                  *(uint8_t *)(uptr23 + 1) = arg7;
                  *uptr23 = *(uint16_t *)(arg4 + (uint32_t)(uint8_t)uvalue3 * 2);
                  value9 = value9 + -1;
                  uptr24 = (uint16_t *)((intptr_t)uptr24 + 1);
                  uptr23 = (uint16_t *)((intptr_t)uptr23 + 3);
                  if (value9 == 0) break;
                  goto LAB_0053b890;
                }
                uvalue15 = (uint32_t)*(uint8_t *)((intptr_t)uptr24 + 1);
                uptr24 = uptr24 + 1;
                uptr23 = (uint16_t *)((intptr_t)uptr23 + uvalue15 * 3);
                value19 = value9 - uvalue15;
                flag7 = value9 < (intptr_t)uvalue15;
                value9 = value19;
              } while (!(value19 == 0 || flag7));
            }
            goto LAB_0053b80f;
          }
LAB_0053b8c6:
          value11 = value11 + uvalue6;
          local_1c = 1;
          value14 = value14 + -1;
        } while (value14 != 0);
      }
    }
  }
  return;
LAB_0053b7ab:
  value11 = value11 + uvalue6;
  local_1c = 1;
  value14 = value14 + -1;
  if (value14 == 0) {
    return;
  }
  goto LAB_0053b521;
}
