// Map_GenerateRandomTiles: ported from Pizza Connection 2 at 0x51fb50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x51fb50
#include "pc2_port.h"

/* WARNING: Variable defined which should be unmapped: arg3 */

uint32_t * __thiscall Map_GenerateRandomTiles(int arg1,uint32_t *arg2,uint32_t *arg3,uint32_t arg4)

{
  int value1;
  uint32_t uvalue2;
  int value3;
  int value4;
  uint32_t uvalue5;
  uint32_t *uptr6;
  int value7;
  int value8;
  uint32_t *uptr9;
  int local_8;
  
  uptr6 = arg3;
  value1 = _rand();
  *(int *)(arg1 + 0x18) = value1 % 10;
  uvalue2 = _rand();
  if ((uvalue2 & 1) == 0) {
    value1 = _rand();
    value7 = (intptr_t)arg3 * arg4;
    if (0 < value7) {
      for (; value7 != 0; value7 = value7 + -1) {
        *arg2 = value1 % 10;
        arg2 = arg2 + 1;
      }
    }
  }
  else if (((*(int *)(arg1 + 0x18) == 8) || (*(int *)(arg1 + 0x18) == 9)) &&
          (uvalue2 = _rand(), (uvalue2 & 1) != 0)) {
    uvalue2 = _rand();
    value1 = (intptr_t)arg3 >> 1;
    if ((uvalue2 & 1) == 0) {
      value7 = 0;
      if (0 < (intptr_t)arg4) {
        arg3 = arg2;
        do {
          value8 = 0;
          if (0 < (intptr_t)uptr6) {
            value3 = value7 - ((intptr_t)arg4 >> 1);
            uptr9 = arg3;
            do {
              value4 = value8 - value1;
              if ((value3 < 1) || (value4 < 1)) {
                if (value3 < 0) {
                  if (value4 < 0) {
                    *uptr9 = 5;
                  }
                  else {
                    if (value4 < 1) goto LAB_0051fcc7;
                    *uptr9 = 6;
                  }
                }
                else {
LAB_0051fcc7:
                  if ((value3 < 1) || (-1 < value4)) {
                    *uptr9 = 9;
                  }
                  else {
                    *uptr9 = 7;
                  }
                }
              }
              else {
                *uptr9 = 4;
              }
              value8 = value8 + 1;
              uptr9 = uptr9 + 1;
            } while (value8 < (intptr_t)uptr6);
          }
          value7 = value7 + 1;
          arg3 = arg3 + (intptr_t)uptr6;
          if ((intptr_t)arg4 <= value7) {
            return arg3;
          }
        } while( true );
      }
    }
    else {
      local_8 = 0;
      if (0 < (intptr_t)arg4) {
        do {
          value7 = 0;
          if (0 < (intptr_t)arg3) {
            uvalue2 = local_8 - ((intptr_t)arg4 >> 1);
            value8 = (uvalue2 ^ (intptr_t)uvalue2 >> 0x1f) - ((intptr_t)uvalue2 >> 0x1f);
            uptr6 = arg2;
            do {
              uvalue5 = value7 - value1;
              value3 = (uvalue5 ^ (intptr_t)uvalue5 >> 0x1f) - ((intptr_t)uvalue5 >> 0x1f);
              if (((intptr_t)uvalue2 < 1) || (value8 < value3)) {
                if (((intptr_t)uvalue2 < 0) && (value3 <= value8)) {
                  *uptr6 = 1;
                }
                else if (((intptr_t)uvalue5 < 0) && (value8 < value3)) {
                  *uptr6 = 3;
                }
                else if (((intptr_t)uvalue5 < 1) || (value3 <= value8)) {
                  *uptr6 = 8;
                }
                else {
                  *uptr6 = 2;
                }
              }
              else {
                *uptr6 = 0;
              }
              value7 = value7 + 1;
              uptr6 = uptr6 + 1;
            } while (value7 < (intptr_t)arg3);
          }
          local_8 = local_8 + 1;
          arg2 = arg2 + (intptr_t)arg3;
        } while (local_8 < (intptr_t)arg4);
        return arg3;
      }
    }
  }
  else {
    value1 = _rand();
    value1 = value1 % 3;
    if (value1 == 0) {
      uptr9 = (uint32_t *)0x0;
      uptr6 = (uint32_t *)0x3;
    }
    else if (value1 == 1) {
      uptr9 = (uint32_t *)0x4;
      uptr6 = (uint32_t *)0x3;
    }
    else if (value1 == 2) {
      uptr6 = (uint32_t *)0x7;
      uptr9 = (uint32_t *)0x0;
    }
    else {
      uptr9 = arg3;
    }
    value1 = (intptr_t)arg3 * arg4;
    if (0 < value1) {
      do {
        uvalue2 = _rand();
        value1 = value1 + -1;
        *arg2 = (uvalue2 & (uint32_t)uptr6) + (intptr_t)uptr9;
        arg2 = arg2 + 1;
      } while (value1 != 0);
      return arg3;
    }
  }
  return arg3;
}
