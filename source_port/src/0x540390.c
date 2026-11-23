// ResourceTable_FindEntry: ported from Pizza Connection 2 at 0x540390.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x540390
#include "pc2_port.h"

uint32_t __thiscall ResourceTable_FindEntry(void *self,uint8_t *arg1,int *arg2,int *arg3)

{
  uint8_t flag1;
  uint8_t *bptr2;
  int value3;
  int value4;
  int value5;
  uint32_t uvalue6;
  int value7;
  int value8;
  uint8_t *bptr9;
  bool flag10;
  
  *arg2 = 0;
  uvalue6 = *(uint32_t *)((intptr_t)self + 0x238);
  if (0 < (intptr_t)uvalue6) {
    do {
      value7 = 0;
      value5 = *arg2 * 0x1c;
      value4 = **(int **)((intptr_t)self + value5 + 0x10);
      value8 = value4 + -1;
      if (0 < value4 + -2) {
        value4 = value8;
        do {
          value8 = value7 + value4 >> 1;
          bptr2 = *(uint8_t **)(*(int *)((intptr_t)self + value5 + 0x14) + 0x10 + value8 * 0x14);
          bptr9 = arg1;
          do {
            flag1 = *bptr2;
            flag10 = flag1 < *bptr9;
            if (flag1 != *bptr9) {
LAB_00540414:
              value3 = (1 - (uint32_t)flag10) - (uint32_t)(flag10 != 0);
              goto LAB_00540419;
            }
            if (flag1 == 0) break;
            flag1 = bptr2[1];
            flag10 = flag1 < bptr9[1];
            if (flag1 != bptr9[1]) goto LAB_00540414;
            bptr2 = bptr2 + 2;
            bptr9 = bptr9 + 2;
          } while (flag1 != 0);
          value3 = 0;
LAB_00540419:
          if (value3 == 0) {
            *arg3 = value8;
            return 1;
          }
          if (value3 < 0) {
            value7 = value8;
            value8 = value4;
          }
          value4 = value8;
        } while (value7 < value8 + -1);
      }
      value5 = *(int *)((intptr_t)self + value5 + 0x14);
      bptr2 = *(uint8_t **)(value5 + 0x10 + value7 * 0x14);
      bptr9 = arg1;
      do {
        flag1 = *bptr2;
        flag10 = flag1 < *bptr9;
        if (flag1 != *bptr9) {
LAB_00540466:
          value4 = (1 - (uint32_t)flag10) - (uint32_t)(flag10 != 0);
          goto LAB_0054046b;
        }
        if (flag1 == 0) break;
        flag1 = bptr2[1];
        flag10 = flag1 < bptr9[1];
        if (flag1 != bptr9[1]) goto LAB_00540466;
        bptr2 = bptr2 + 2;
        bptr9 = bptr9 + 2;
      } while (flag1 != 0);
      value4 = 0;
LAB_0054046b:
      if (value4 == 0) {
        *arg3 = value7;
        return CONCAT31((int3)((uint32_t)arg3 >> 8),1);
      }
      bptr2 = *(uint8_t **)(value5 + 0x10 + value8 * 0x14);
      bptr9 = arg1;
      do {
        flag1 = *bptr2;
        flag10 = flag1 < *bptr9;
        if (flag1 != *bptr9) {
LAB_005404a3:
          value5 = (1 - (uint32_t)flag10) - (uint32_t)(flag10 != 0);
          goto LAB_005404a8;
        }
        if (flag1 == 0) break;
        flag1 = bptr2[1];
        flag10 = flag1 < bptr9[1];
        if (flag1 != bptr9[1]) goto LAB_005404a3;
        bptr2 = bptr2 + 2;
        bptr9 = bptr9 + 2;
      } while (flag1 != 0);
      value5 = 0;
LAB_005404a8:
      if (value5 == 0) {
        *arg3 = value8;
        return 1;
      }
      uvalue6 = *arg2 + 1;
      *arg2 = uvalue6;
    } while ((intptr_t)uvalue6 < *(int *)((intptr_t)self + 0x238));
  }
  return uvalue6 & 0xffffff00;
}
