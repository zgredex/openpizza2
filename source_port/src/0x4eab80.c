// World_FindNameIndex: ported from Pizza Connection 2 at 0x4eab80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4eab80
#include "pc2_port.h"

uint32_t __thiscall World_FindNameIndex(void *self,uint32_t *arg1)

{
  uint8_t flag1;
  uint8_t *extraout_EAX;
  uint8_t *extraout_EAX_00;
  int value2;
  uint8_t *bptr3;
  uint32_t uvalue4;
  uint8_t *bptr5;
  uint32_t *uptr6;
  bool flag7;
  
  CRT_Strupr(arg1);
  value2 = *(int *)((intptr_t)self + 0x20);
  uvalue4 = 0;
  if (0 < value2) {
    uptr6 = (uint32_t *)((intptr_t)self + 0x25);
    do {
      CRT_Strupr(uptr6);
      bptr3 = extraout_EAX;
      bptr5 = extraout_EAX_00;
      do {
        flag1 = *bptr3;
        flag7 = flag1 < *bptr5;
        if (flag1 != *bptr5) {
LAB_004eabd6:
          value2 = (1 - (uint32_t)flag7) - (uint32_t)(flag7 != 0);
          goto LAB_004eabdb;
        }
        if (flag1 == 0) break;
        flag1 = bptr3[1];
        flag7 = flag1 < bptr5[1];
        if (flag1 != bptr5[1]) goto LAB_004eabd6;
        bptr3 = bptr3 + 2;
        bptr5 = bptr5 + 2;
      } while (flag1 != 0);
      value2 = 0;
LAB_004eabdb:
      if (value2 == 0) {
        return uvalue4 & 0xffff;
      }
      value2 = *(int *)((intptr_t)self + 0x20);
      uvalue4 = uvalue4 + 1;
      uptr6 = uptr6 + 0x12;
    } while ((intptr_t)uvalue4 < value2);
  }
  return CONCAT22((short)((uint32_t)value2 >> 0x10),0xffff);
}
