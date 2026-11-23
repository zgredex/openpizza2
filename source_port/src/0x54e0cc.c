// CRT_Atoi: ported from Pizza Connection 2 at 0x54e0cc.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54e0cc
#include "pc2_port.h"

int __thiscall CRT_Atoi(void *self,uint8_t *arg1)

{
  uint32_t uvalue1;
  uint32_t uvalue2;
  int value3;
  uint32_t uvalue4;
  uint8_t *bptr5;
  uint8_t *uptr6;
  
  while( true ) {
    if (DAT_00576cf0 < 2) {
      uvalue1 = (uint8_t)PTR_DAT_00576ae4[(uint32_t)*arg1 * 2] & 8;
      self = PTR_DAT_00576ae4;
    }
    else {
      uptr6 = (uint8_t *)0x8;
      uvalue1 = CRT_Mbtowc(self,(uint32_t)*arg1,8);
      self = uptr6;
    }
    if (uvalue1 == 0) break;
    arg1 = arg1 + 1;
  }
  uvalue1 = (uint32_t)*arg1;
  bptr5 = arg1 + 1;
  if ((uvalue1 == 0x2d) || (uvalue4 = uvalue1, uvalue1 == 0x2b)) {
    uvalue4 = (uint32_t)*bptr5;
    bptr5 = arg1 + 2;
  }
  value3 = 0;
  while( true ) {
    if (DAT_00576cf0 < 2) {
      uvalue2 = (uint8_t)PTR_DAT_00576ae4[uvalue4 * 2] & 4;
    }
    else {
      uptr6 = (uint8_t *)0x4;
      uvalue2 = CRT_Mbtowc(self,uvalue4,4);
      self = uptr6;
    }
    if (uvalue2 == 0) break;
    value3 = (uvalue4 - 0x30) + value3 * 10;
    uvalue4 = (uint32_t)*bptr5;
    bptr5 = bptr5 + 1;
  }
  if (uvalue1 == 0x2d) {
    value3 = -value3;
  }
  return value3;
}
