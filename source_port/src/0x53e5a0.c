// Gfx_DrawFilledEllipse: ported from Pizza Connection 2 at 0x53e5a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53e5a0
#include "pc2_port.h"

void __cdecl
Gfx_DrawFilledEllipse(int arg1,int arg2,uint32_t arg3,int arg4,uint16_t arg5)

{
  int value1;
  int value2;
  int value3;
  int value4;
  int value5;
  uint32_t uvalue6;
  uint16_t *uptr7;
  int value8;
  int value9;
  int value10;
  uint32_t uvalue11;
  int value12;
  uint32_t uvalue13;
  int64_t lvalue14;
  uint32_t local_34;
  uint32_t local_30;
  int local_2c;
  int local_28;
  uint32_t local_24;
  int local_1c;
  int local_14;
  int local_10;
  
  if (0 < arg4) {
    value10 = -9999;
    value1 = *(int *)(arg1 + 4);
    local_2c = -9999;
    value2 = *(int *)(arg1 + 8);
    value3 = *(int *)(arg1 + 0xc);
    value4 = *(int *)(arg1 + 0x10);
    value5 = *(int *)(arg1 + 0x20);
    local_30 = 0xffffd8f1;
    local_28 = -9999;
    uvalue11 = 0xffffd8f1;
    local_1c = 0;
    if (0 < arg4) {
      local_14 = value5 * arg3 * 2;
      local_34 = arg3;
      local_24 = arg3;
      local_10 = local_14;
      do {
        if ((value4 < (intptr_t)local_34) && ((intptr_t)local_24 < value3)) {
          if (local_1c < arg4) {
            return;
          }
          break;
        }
        lvalue14 = __ftol();
        value8 = (intptr_t)lvalue14;
        if (((intptr_t)local_34 < value4) && (value3 <= (intptr_t)local_34)) {
          value12 = *(int *)(arg1 + 0x28) + local_14;
          if ((uvalue11 == 0xffffd8f1) || (uvalue13 = arg2 - value8, uvalue11 == uvalue13)) {
            uvalue11 = arg2 - value8;
            uvalue13 = uvalue11;
            if ((value1 <= (intptr_t)uvalue11) && ((intptr_t)uvalue11 < value2)) {
              *(uint16_t *)(value12 + uvalue11 * 2) = arg5;
            }
          }
          else if ((intptr_t)uvalue11 < (intptr_t)uvalue13) {
            uptr7 = (uint16_t *)(value12 + uvalue11 * 2);
            do {
              uvalue11 = uvalue11 + 1;
              uptr7 = uptr7 + 1;
              if ((value1 <= (intptr_t)uvalue11) && ((intptr_t)uvalue11 < value2)) {
                *uptr7 = arg5;
              }
            } while ((intptr_t)uvalue11 < (intptr_t)uvalue13);
          }
          if ((value10 == -9999) || (value9 = arg2 + value8, value10 == value9)) {
            value10 = arg2 + value8;
            local_28 = value10;
            if ((value1 <= value10) && (value10 < value2)) {
              *(uint16_t *)(value12 + value10 * 2) = arg5;
            }
          }
          else if (value9 < value10) {
            uptr7 = (uint16_t *)(value12 + value10 * 2);
            do {
              value10 = value10 + -1;
              uptr7 = uptr7 + -1;
              if ((value1 <= value10) && (value10 < value2)) {
                *uptr7 = arg5;
              }
            } while (value9 < value10);
            local_28 = value10;
          }
          if ((local_34 & 1) != 0) {
            uvalue6 = uvalue13;
            if ((uvalue13 & 1) != 0) {
              uvalue6 = uvalue13 ^ 1;
            }
            if ((local_34 & 2) == 0) {
              uvalue6 = uvalue6 | 2;
            }
            else if ((uvalue6 & 2) != 0) {
              uvalue6 = uvalue6 ^ 2;
            }
            if ((intptr_t)uvalue6 < (intptr_t)uvalue13) {
              uvalue6 = uvalue6 + 4;
            }
            if ((intptr_t)uvalue6 < arg2 + value8) {
              uptr7 = (uint16_t *)(value12 + uvalue6 * 2);
              do {
                if ((value1 <= (intptr_t)uvalue6) && ((intptr_t)uvalue6 < value2)) {
                  *uptr7 = arg5;
                }
                uvalue6 = uvalue6 + 4;
                uptr7 = uptr7 + 4;
              } while ((intptr_t)uvalue6 < arg2 + value8);
            }
          }
        }
        else {
          value10 = value8 + arg2;
          uvalue11 = arg2 - value8;
          uvalue13 = uvalue11;
          local_28 = value10;
        }
        value8 = arg2 + value8;
        if (((intptr_t)local_24 < value4) && (value3 <= (intptr_t)local_24)) {
          value12 = *(int *)(arg1 + 0x28) + local_10;
          if ((local_30 == 0xffffd8f1) || (local_30 == uvalue13)) {
            local_30 = uvalue13;
            if ((value1 <= (intptr_t)uvalue13) && ((intptr_t)uvalue13 < value2)) {
              *(uint16_t *)(value12 + uvalue13 * 2) = arg5;
            }
          }
          else if ((intptr_t)local_30 < (intptr_t)uvalue13) {
            uptr7 = (uint16_t *)(value12 + local_30 * 2);
            do {
              local_30 = local_30 + 1;
              uptr7 = uptr7 + 1;
              if ((value1 <= (intptr_t)local_30) && ((intptr_t)local_30 < value2)) {
                *uptr7 = arg5;
              }
            } while ((intptr_t)local_30 < (intptr_t)uvalue13);
            value10 = local_28;
          }
          if ((local_2c == -9999) || (local_2c == value8)) {
            local_2c = value8;
            if ((value1 <= value8) && (value8 < value2)) {
              *(uint16_t *)(value12 + value8 * 2) = arg5;
            }
          }
          else if (value8 < local_2c) {
            uptr7 = (uint16_t *)(value12 + local_2c * 2);
            do {
              local_2c = local_2c + -1;
              uptr7 = uptr7 + -1;
              if ((value1 <= local_2c) && (local_2c < value2)) {
                *uptr7 = arg5;
              }
            } while (value8 < local_2c);
            value10 = local_28;
          }
          if ((local_24 & 1) != 0) {
            uvalue6 = uvalue13;
            if ((uvalue13 & 1) != 0) {
              uvalue6 = uvalue13 ^ 1;
            }
            if ((local_24 & 2) == 0) {
              uvalue6 = uvalue6 | 2;
            }
            else if ((uvalue6 & 2) != 0) {
              uvalue6 = uvalue6 ^ 2;
            }
            if ((intptr_t)uvalue6 < (intptr_t)uvalue13) {
              uvalue6 = uvalue6 + 4;
            }
            if ((intptr_t)uvalue6 < value8) {
              uptr7 = (uint16_t *)(value12 + uvalue6 * 2);
              do {
                if ((value1 <= (intptr_t)uvalue6) && ((intptr_t)uvalue6 < value2)) {
                  *uptr7 = arg5;
                }
                uvalue6 = uvalue6 + 4;
                uptr7 = uptr7 + 4;
              } while ((intptr_t)uvalue6 < value8);
            }
          }
        }
        else {
          local_30 = uvalue13;
          local_2c = value8;
        }
        local_14 = local_14 + value5 * 2;
        local_1c = local_1c + 1;
        local_10 = local_10 + value5 * -2;
        local_34 = local_34 + 1;
        local_24 = local_24 - 1;
      } while (local_1c < arg4);
      if ((((uvalue11 != 0xffffd8f1) && (value10 != -9999)) &&
          (value8 = arg3 + arg4, value3 <= value8)) &&
         ((value8 < value4 && ((intptr_t)uvalue11 < value10)))) {
        uptr7 = (uint16_t *)(*(int *)(arg1 + 0x28) + value8 * value5 * 2 + uvalue11 * 2);
        do {
          uvalue11 = uvalue11 + 1;
          uptr7 = uptr7 + 1;
          if ((value1 <= (intptr_t)uvalue11) && ((intptr_t)uvalue11 < value2)) {
            *uptr7 = arg5;
          }
        } while ((intptr_t)uvalue11 < value10);
      }
      if ((((local_30 != 0xffffd8f1) && (local_2c != -9999)) &&
          (value10 = arg3 - arg4, value3 <= value10)) &&
         ((value10 < value4 && ((intptr_t)local_30 < local_2c)))) {
        uptr7 = (uint16_t *)(*(int *)(arg1 + 0x28) + value10 * value5 * 2 + local_30 * 2);
        do {
          local_30 = local_30 + 1;
          uptr7 = uptr7 + 1;
          if ((value1 <= (intptr_t)local_30) && ((intptr_t)local_30 < value2)) {
            *uptr7 = arg5;
          }
        } while ((intptr_t)local_30 < local_2c);
      }
    }
  }
  return;
}
