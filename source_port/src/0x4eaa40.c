// Map_FindNameIndex: ported from Pizza Connection 2 at 0x4eaa40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4eaa40
#include "pc2_port.h"

int __thiscall Map_FindNameIndex(void *self,uint8_t *arg1)

{
  uint8_t flag1;
  uint8_t *bptr2;
  int value3;
  int value4;
  uint8_t *bptr5;
  uint8_t *bptr6;
  bool flag7;
  
  value4 = 0;
  bptr6 = (uint8_t *)((intptr_t)self + 0x25);
  do {
    bptr2 = arg1;
    bptr5 = bptr6;
    do {
      flag1 = *bptr2;
      flag7 = flag1 < *bptr5;
      if (flag1 != *bptr5) {
LAB_004eaa75:
        value3 = (1 - (uint32_t)flag7) - (uint32_t)(flag7 != 0);
        goto LAB_004eaa7a;
      }
      if (flag1 == 0) break;
      flag1 = bptr2[1];
      flag7 = flag1 < bptr5[1];
      if (flag1 != bptr5[1]) goto LAB_004eaa75;
      bptr2 = bptr2 + 2;
      bptr5 = bptr5 + 2;
    } while (flag1 != 0);
    value3 = 0;
LAB_004eaa7a:
    if (value3 == 0) {
      return value4;
    }
    value4 = value4 + 1;
    bptr6 = bptr6 + 0x48;
    if (0x9c3 < value4) {
      return -1;
    }
  } while( true );
}
