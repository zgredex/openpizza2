// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x557291.c:90:22: error: invalid operands to binary expression ('int *' and 'unsigned int')
// FUN_00557291: ported from Pizza Connection 2 at 0x557291.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557291
#include "pc2_port.h"

void __cdecl FUN_00557291(int *arg1,int *arg2)

{
  int *ptr1;
  short svalue2;
  int value3;
  int *ptr4;
  int *ptr5;
  uint16_t uvalue6;
  uint32_t uvalue7;
  int value8;
  uint16_t uvalue9;
  uint32_t uvalue10;
  uint16_t uvalue11;
  uint8_t local_28;
  uint8_t uStack_27;
  uint16_t uStack_26;
  short local_24;
  uint16_t uStack_22;
  uint16_t local_20;
  uint8_t uStack_1e;
  uint8_t bStack_1d;
  int *local_1c;
  int local_18;
  int local_14;
  uint16_t *local_10;
  uint16_t *local_c;
  short *local_8;
  
  ptr5 = arg2;
  ptr4 = arg1;
  local_18 = 0;
  local_28 = 0;
  uStack_27 = 0;
  uStack_26 = 0;
  local_24 = 0;
  uStack_22 = 0;
  local_20 = 0;
  uStack_1e = 0;
  bStack_1d = 0;
  uvalue7 = *(uint16_t *)((intptr_t)arg1 + 10) & 0x7fff;
  uvalue10 = *(uint16_t *)((intptr_t)arg2 + 10) & 0x7fff;
  uvalue11 = (*(uint16_t *)((intptr_t)arg2 + 10) ^ *(uint16_t *)((intptr_t)arg1 + 10)) & 0x8000;
  uvalue6 = (uint16_t)uvalue7;
  ptr1 = (int *)(uvalue10 + uvalue7);
  if (((uvalue6 < 0x7fff) && (uvalue9 = (uint16_t)uvalue10, uvalue9 < 0x7fff)) && ((uint16_t)ptr1 < 0xbffe)) {
    if ((uint16_t)ptr1 < 0x3fc0) {
LAB_00557334:
      ptr4[2] = 0;
      ptr4[1] = 0;
      *ptr4 = 0;
      return;
    }
    if (((uvalue6 != 0) || (ptr1 = (int *)((intptr_t)ptr1 + 1), (arg1[2] & 0x7fffffffU) != 0)) ||
       ((uvalue6 = 0, arg1[1] != 0 || (*arg1 != 0)))) {
      arg1 = ptr1;
      if (((uvalue9 == 0) && (arg1 = (int *)((intptr_t)arg1 + 1), (arg2[2] & 0x7fffffffU) == 0))
         && ((arg2[1] == 0 && (*arg2 == 0)))) goto LAB_00557334;
      local_14 = 0;
      local_8 = &local_24;
      arg2 = (int *)0x5;
      do {
        if (0 < (intptr_t)arg2) {
          local_c = (uint16_t *)(local_14 * 2 + (intptr_t)ptr4);
          local_10 = (uint16_t *)(ptr5 + 2);
          local_1c = arg2;
          do {
            value8 = FUN_00556bdd(*(uint32_t *)(local_8 + -2),(uint32_t)*local_c * (uint32_t)*local_10,
                                 (uint32_t *)(local_8 + -2));
            if (value8 != 0) {
              *local_8 = *local_8 + 1;
            }
            local_c = local_c + 1;
            local_10 = local_10 + -1;
            local_1c = (int *)((intptr_t)local_1c + -1);
          } while (local_1c != (int *)0x0);
        }
        local_8 = local_8 + 1;
        local_14 = local_14 + 1;
        arg2 = (int *)((intptr_t)arg2 + -1);
      } while (0 < (intptr_t)arg2);
      arg1 = (int *)((intptr_t)arg1 + 0xc002);
      if ((short)(uint16_t)arg1 < 1) {
LAB_005573e8:
        arg1 = (arg1 & ~(0x0u << 16)) | ((((uint16_t)arg1 - 1) & 0x0u) << 16);
        if ((short)(uint16_t)arg1 < 0) {
          value8 = -(intptr_t)(short)(uint16_t)arg1;
          arg1 = (arg1 & ~(0x0u << 16)) | ((((uint16_t)arg1 + (short)value8) & 0x0u) << 16);
          do {
            if ((local_28 & 1) != 0) {
              local_18 = local_18 + 1;
            }
            FUN_00556c8a((uint32_t *)&local_28);
            value8 = value8 + -1;
          } while (value8 != 0);
          if (local_18 != 0) {
            local_28 = local_28 | 1;
          }
        }
      }
      else {
        do {
          if ((bStack_1d & 0x80) != 0) break;
          FUN_00556c5c((uint32_t *)&local_28);
          arg1 = (int *)((intptr_t)arg1 + 0xffff);
        } while (0 < (short)(uint16_t)arg1);
        if ((short)(uint16_t)arg1 < 1) goto LAB_005573e8;
      }
      if ((0x8000 < CONCAT11(uStack_27,local_28)) ||
         (svalue2 = CONCAT11(bStack_1d,uStack_1e), value3 = CONCAT22(local_20,uStack_22),
         value8 = CONCAT22(local_24,uStack_26),
         (CONCAT22(uStack_26,CONCAT11(uStack_27,local_28)) & 0x1ffff) == 0x18000)) {
        if (CONCAT22(local_24,uStack_26) == -1) {
          value8 = 0;
          if (CONCAT22(local_20,uStack_22) == -1) {
            if (CONCAT11(bStack_1d,uStack_1e) == -1) {
              arg1 = (arg1 & ~(0x0u << 16)) | ((((uint16_t)arg1 + 1) & 0x0u) << 16);
              svalue2 = -0x8000;
              value3 = 0;
              value8 = 0;
            }
            else {
              svalue2 = CONCAT11(bStack_1d,uStack_1e) + 1;
              value3 = 0;
              value8 = 0;
            }
          }
          else {
            svalue2 = CONCAT11(bStack_1d,uStack_1e);
            value3 = CONCAT22(local_20,uStack_22) + 1;
          }
        }
        else {
          value8 = CONCAT22(local_24,uStack_26) + 1;
          svalue2 = CONCAT11(bStack_1d,uStack_1e);
          value3 = CONCAT22(local_20,uStack_22);
        }
      }
      local_24 = (short)((uint32_t)value8 >> 0x10);
      uStack_26 = (uint16_t)value8;
      local_20 = (uint16_t)((uint32_t)value3 >> 0x10);
      uStack_22 = (uint16_t)value3;
      bStack_1d = (uint8_t)((uint16_t)svalue2 >> 8);
      uStack_1e = (uint8_t)svalue2;
      if (0x7ffe < (uint16_t)arg1) goto LAB_00557491;
      uvalue6 = (uint16_t)arg1 | uvalue11;
      *(uint16_t *)ptr4 = uStack_26;
      *(uint32_t *)((intptr_t)ptr4 + 2) = CONCAT22(uStack_22,local_24);
      *(uint32_t *)((intptr_t)ptr4 + 6) = CONCAT13(bStack_1d,CONCAT12(uStack_1e,local_20));
    }
    *(uint16_t *)((intptr_t)ptr4 + 10) = uvalue6;
  }
  else {
LAB_00557491:
    ptr4[1] = 0;
    *ptr4 = 0;
    ptr4[2] = (-(uint32_t)(uvalue11 != 0) & 0x80000000) + 0x7fff8000;
  }
  return;
}
