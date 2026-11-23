// Pak_FindEntry: ported from Pizza Connection 2 at 0x402060.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x402060
#include "pc2_port.h"

uint32_t __thiscall Pak_FindEntry(void *self,uint8_t *arg1,int *arg2,int *arg3)

{
  uint8_t flag1;
  int value2;
  uint8_t *bptr3;
  int value4;
  int value5;
  int value6;
  int value7;
  uint8_t *bptr8;
  bool flag9;
  
  *arg2 = 0;
  if (0 < *(int *)((intptr_t)self + 0x1684)) {
    do {
      value6 = 0;
      value2 = *arg2 * 0x120;
      value5 = **(int **)((intptr_t)self + value2 + 0x110);
      value7 = value5 + -1;
      if (0 < value5 + -2) {
        value5 = value7;
        do {
          value7 = value6 + value5 >> 1;
          bptr3 = *(uint8_t **)(*(int *)((intptr_t)self + value2 + 0x114) + 0x10 + value7 * 0x14);
          bptr8 = arg1;
          do {
            flag1 = *bptr3;
            flag9 = flag1 < *bptr8;
            if (flag1 != *bptr8) {
LAB_004020e7:
              value4 = (1 - (uint32_t)flag9) - (uint32_t)(flag9 != 0);
              goto LAB_004020ec;
            }
            if (flag1 == 0) break;
            flag1 = bptr3[1];
            flag9 = flag1 < bptr8[1];
            if (flag1 != bptr8[1]) goto LAB_004020e7;
            bptr3 = bptr3 + 2;
            bptr8 = bptr8 + 2;
          } while (flag1 != 0);
          value4 = 0;
LAB_004020ec:
          if (value4 == 0) {
            *arg3 = value7;
            return 1;
          }
          if (value4 < 0) {
            value6 = value7;
            value7 = value5;
          }
          value5 = value7;
        } while (value6 < value7 + -1);
      }
      value5 = *(int *)((intptr_t)self + value2 + 0x114);
      bptr3 = *(uint8_t **)(value5 + 0x10 + value6 * 0x14);
      bptr8 = arg1;
      do {
        flag1 = *bptr3;
        flag9 = flag1 < *bptr8;
        if (flag1 != *bptr8) {
LAB_0040213c:
          value2 = (1 - (uint32_t)flag9) - (uint32_t)(flag9 != 0);
          goto LAB_00402141;
        }
        if (flag1 == 0) break;
        flag1 = bptr3[1];
        flag9 = flag1 < bptr8[1];
        if (flag1 != bptr8[1]) goto LAB_0040213c;
        bptr3 = bptr3 + 2;
        bptr8 = bptr8 + 2;
      } while (flag1 != 0);
      value2 = 0;
LAB_00402141:
      if (value2 == 0) {
        *arg3 = value6;
        return 1;
      }
      bptr3 = *(uint8_t **)(value5 + 0x10 + value7 * 0x14);
      bptr8 = arg1;
      do {
        flag1 = *bptr3;
        flag9 = flag1 < *bptr8;
        if (flag1 != *bptr8) {
LAB_00402179:
          value5 = (1 - (uint32_t)flag9) - (uint32_t)(flag9 != 0);
          goto LAB_0040217e;
        }
        if (flag1 == 0) break;
        flag1 = bptr3[1];
        flag9 = flag1 < bptr8[1];
        if (flag1 != bptr8[1]) goto LAB_00402179;
        bptr3 = bptr3 + 2;
        bptr8 = bptr8 + 2;
      } while (flag1 != 0);
      value5 = 0;
LAB_0040217e:
      if (value5 == 0) {
        *arg3 = value7;
        return 1;
      }
      value5 = *arg2;
      *arg2 = value5 + 1;
    } while (value5 + 1 < *(int *)((intptr_t)self + 0x1684));
  }
  return 0;
}
