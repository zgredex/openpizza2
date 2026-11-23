// Surface_BlitRLESkipToRGB: ported from Pizza Connection 2 at 0x53bf00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53bf00
#include "pc2_port.h"

void __thiscall
Surface_BlitRLESkipToRGB
          (void *self,int arg1,uint32_t *arg2,uint8_t *arg3,uint32_t arg4,int arg5)

{
  uint8_t flag1;
  uint8_t flag2;
  short svalue3;
  bool flag4;
  uint32_t uvalue5;
  int value6;
  uint32_t uvalue7;
  int value8;
  int value9;
  int value10;
  uint32_t uvalue11;
  int value12;
  uint8_t *bptr13;
  uint8_t *bptr14;
  int value15;
  uint32_t *local_2c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  Object_GetPair4(arg2,&local_c,&local_10);
  if ((*(uint8_t *)((intptr_t)self + 4) & 4) != 0) {
    arg4 = arg4 + (intptr_t)*(short *)((intptr_t)self + 10);
    arg5 = arg5 + *(short *)((intptr_t)self + 0xc);
  }
  value10 = (intptr_t)*(short *)((intptr_t)self + 8);
  local_14 = 0;
  local_18 = 0;
  value8 = (intptr_t)*(short *)((intptr_t)self + 6);
  if ((intptr_t)arg4 < 0) {
    value8 = value8 + arg4;
    local_14 = -arg4;
    if (value8 < 1) {
      return;
    }
    arg4 = 0;
  }
  if (arg5 < 0) {
    value10 = value10 + arg5;
    local_18 = -arg5;
    if (value10 < 1) {
      return;
    }
    arg5 = 0;
  }
  if ((((intptr_t)(arg4 + value8) < local_c) || (value8 = local_c - arg4, 0 < value8)) &&
     ((arg5 + value10 < local_10 || (value10 = local_10 - arg5, 0 < value10)))) {
    uvalue5 = arg4 + value8;
    value9 = *(int *)(arg1 + 0x20) * arg5 + *(int *)(arg1 + 0x28);
    value6 = Object_GetPair10(arg2,&local_8);
    value8 = *(int *)(arg1 + 0x20);
    svalue3 = *(short *)((intptr_t)self + 6);
    arg2 = (uint32_t *)(value6 + local_8 * arg5 * 2);
    if (*(char *)((intptr_t)self + 5) == '\b') {
      flag1 = *(uint8_t *)((intptr_t)self + 0x1c);
      do {
        local_2c = arg2;
        arg2 = (uint32_t *)((intptr_t)arg2 + local_8 * 2);
        for (; local_18 != 0; local_18 = local_18 + -1) {
          value6 = (intptr_t)svalue3;
          do {
            while (*arg3 == flag1) {
              bptr14 = arg3 + 1;
              arg3 = arg3 + 2;
              value15 = value6 - (uint32_t)*bptr14;
              flag4 = (intptr_t)(uint32_t)*bptr14 <= value6;
              value6 = value15;
              if (!(value15 != 0 && flag4)) goto LAB_0053c055;
            }
            arg3 = arg3 + 1;
            value6 = value6 + -1;
          } while (value6 != 0);
LAB_0053c055:
        }
LAB_0053c05d:
        uvalue11 = *local_2c;
        local_2c = local_2c + 1;
        uvalue7 = uvalue11 & 0xffff;
        if (uvalue7 != 0xffff) {
          uvalue11 = uvalue11 >> 0x10;
          if ((intptr_t)arg4 < (intptr_t)uvalue11) {
            if ((intptr_t)uvalue5 <= (intptr_t)uvalue7) goto LAB_0053c110;
            if ((intptr_t)uvalue5 <= (intptr_t)uvalue11) {
              uvalue11 = uvalue5;
            }
            if ((intptr_t)uvalue7 <= (intptr_t)arg4) {
              uvalue7 = arg4;
            }
            value15 = value9 + uvalue7 * 3;
            value6 = (uvalue7 - arg4) + local_14;
            bptr14 = arg3;
            while( true ) {
              value12 = uvalue11 - uvalue7;
              if (value6 == 0) break;
              while (bptr13 = bptr14 + 1, *bptr14 == flag1) {
                bptr14 = bptr14 + 2;
                value6 = value6 - (uint32_t)*bptr13;
                if (value6 < 1) {
                  value12 = (uvalue11 - uvalue7) + value6;
                  value15 = value15 + value6 * -3;
                  if (0 < value12) goto LAB_0053c0db;
                  goto LAB_0053c05d;
                }
              }
              value6 = value6 + -1;
              bptr14 = bptr13;
            }
LAB_0053c0db:
            do {
              flag2 = *bptr14;
              if (flag2 == flag1) {
                uvalue11 = (uint32_t)bptr14[1];
                bptr14 = bptr14 + 2;
                value15 = value15 + uvalue11 * 3;
                value6 = value12 - uvalue11;
                flag4 = (intptr_t)uvalue11 <= value12;
                value12 = value6;
                if (!(value6 != 0 && flag4)) break;
                goto LAB_0053c0db;
              }
              if (*(uint8_t *)(value15 + 2) <= flag2) {
                *(uint8_t *)(value15 + 2) = flag2;
              }
              value15 = value15 + 3;
              value12 = value12 + -1;
              bptr14 = bptr14 + 1;
            } while (value12 != 0);
          }
          goto LAB_0053c05d;
        }
LAB_0053c110:
        value9 = value9 + value8;
        local_18 = 1;
        value10 = value10 + -1;
      } while (value10 != 0);
    }
  }
  return;
}
