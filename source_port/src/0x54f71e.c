// CRT_Atof: ported from Pizza Connection 2 at 0x54f71e.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54f71e
#include "pc2_port.h"

double __thiscall CRT_Atof(uint8_t *arg1,uint8_t *arg2)

{
  uint32_t uvalue1;
  int value2;
  uint8_t *self;
  uint8_t *uptr3;
  uint32_t local_1c [6];
  
  while( true ) {
    if (DAT_00576cf0 < 2) {
      uvalue1 = (uint8_t)PTR_DAT_00576ae4[(uint32_t)*arg2 * 2] & 8;
      arg1 = PTR_DAT_00576ae4;
    }
    else {
      uptr3 = (uint8_t *)0x8;
      uvalue1 = CRT_Mbtowc(arg1,(uint32_t)*arg2,8);
      arg1 = uptr3;
    }
    if (uvalue1 == 0) break;
    arg2 = arg2 + 1;
  }
  self = arg2;
  _strlen((char *)arg2);
  value2 = CRT_StrToDouble(self,local_1c,arg2);
  return (double)*(double *)(value2 + 0x10);
}
