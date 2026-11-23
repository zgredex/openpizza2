// StringList_Find: ported from Pizza Connection 2 at 0x527400.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x527400
#include "pc2_port.h"

uint32_t __thiscall StringList_Find(void *self,uint8_t *arg1,int *arg2)

{
  uint8_t flag1;
  int value2;
  uint8_t *bptr3;
  int value4;
  int value5;
  int value6;
  uint8_t *bptr7;
  int value8;
  bool flag9;
  
  value5 = *(int *)((intptr_t)self + 0x82f8);
  if ((value5 == 0) || (*(int *)((intptr_t)self + 0x82fc) == 0)) {
    *arg2 = 0;
    return 0;
  }
  value6 = 0;
  value4 = *(int *)((intptr_t)self + 0x82fc) + -1;
  value2 = value4;
  while (1 < value4) {
    value8 = value6 + value2 >> 1;
    bptr3 = (uint8_t *)(value5 + value8 * 0x48);
    bptr7 = arg1;
    do {
      flag1 = *bptr3;
      flag9 = flag1 < *bptr7;
      if (flag1 != *bptr7) {
LAB_00527462:
        value4 = (1 - (uint32_t)flag9) - (uint32_t)(flag9 != 0);
        goto LAB_00527467;
      }
      if (flag1 == 0) break;
      flag1 = bptr3[1];
      flag9 = flag1 < bptr7[1];
      if (flag1 != bptr7[1]) goto LAB_00527462;
      bptr3 = bptr3 + 2;
      bptr7 = bptr7 + 2;
    } while (flag1 != 0);
    value4 = 0;
LAB_00527467:
    if (value4 == 0) {
      *arg2 = value8;
      return 1;
    }
    if (value4 == -1) {
      value6 = value8;
      value8 = value2;
    }
    value2 = value8;
    value4 = value8 - value6;
  }
  bptr3 = (uint8_t *)(value5 + value6 * 0x48);
  bptr7 = arg1;
  do {
    flag1 = *bptr3;
    flag9 = flag1 < *bptr7;
    if (flag1 != *bptr7) {
LAB_005274c4:
      value4 = (1 - (uint32_t)flag9) - (uint32_t)(flag9 != 0);
      goto LAB_005274c9;
    }
    if (flag1 == 0) break;
    flag1 = bptr3[1];
    flag9 = flag1 < bptr7[1];
    if (flag1 != bptr7[1]) goto LAB_005274c4;
    bptr3 = bptr3 + 2;
    bptr7 = bptr7 + 2;
  } while (flag1 != 0);
  value4 = 0;
LAB_005274c9:
  if (value4 == 0) {
    *arg2 = value6;
    return 1;
  }
  bptr3 = (uint8_t *)(value5 + value2 * 0x48);
  do {
    flag1 = *bptr3;
    flag9 = flag1 < *arg1;
    if (flag1 != *arg1) {
LAB_00527513:
      value5 = (1 - (uint32_t)flag9) - (uint32_t)(flag9 != 0);
      goto LAB_00527518;
    }
    if (flag1 == 0) break;
    flag1 = bptr3[1];
    flag9 = flag1 < arg1[1];
    if (flag1 != arg1[1]) goto LAB_00527513;
    bptr3 = bptr3 + 2;
    arg1 = arg1 + 2;
  } while (flag1 != 0);
  value5 = 0;
LAB_00527518:
  if (value5 == 0) {
    *arg2 = value2;
    return 1;
  }
  if (value5 == -1) {
    *arg2 = value2 + 1;
    return 0;
  }
  if (value4 == -1) {
    *arg2 = value6 + 1;
    return 0;
  }
  *arg2 = value6;
  return 0;
}
