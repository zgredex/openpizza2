// CRT_Filbuf: ported from Pizza Connection 2 at 0x552b98.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x552b98
#include "pc2_port.h"

uint32_t __cdecl CRT_Filbuf(uint32_t *arg1)

{
  uint8_t flag1;
  uint32_t uvalue2;
  int value3;
  uint8_t *uptr4;
  
  uvalue2 = arg1[3];
  if (((uvalue2 & 0x83) != 0) && ((uvalue2 & 0x40) == 0)) {
    if ((uvalue2 & 2) == 0) {
      arg1[3] = uvalue2 | 1;
      if ((uvalue2 & 0x10c) == 0) {
        CRT_StreamAllocBuffer(arg1);
      }
      else {
        *arg1 = arg1[2];
      }
      value3 = CRT_Read(arg1[4],(char *)arg1[2],(char *)arg1[6]);
      arg1[1] = value3;
      if ((value3 != 0) && (value3 != -1)) {
        if ((arg1[3] & 0x82) == 0) {
          uvalue2 = arg1[4];
          if (uvalue2 == 0xffffffff) {
            uptr4 = &DAT_00576760;
          }
          else {
            uptr4 = (uint8_t *)((&DAT_00586c20)[(intptr_t)uvalue2 >> 5] + (uvalue2 & 0x1f) * 0x24);
          }
          if ((uptr4[4] & 0x82) == 0x82) {
            arg1[3] = arg1[3] | 0x2000;
          }
        }
        if (((arg1[6] == 0x200) && ((arg1[3] & 8) != 0)) && ((arg1[3] & 0x400) == 0)) {
          arg1[6] = 0x1000;
        }
        arg1[1] = value3 + -1;
        flag1 = *(uint8_t *)*arg1;
        *arg1 = (uint8_t *)*arg1 + 1;
        return (uint32_t)flag1;
      }
      arg1[3] = arg1[3] | (-(uint32_t)(value3 != 0) & 0x10) + 0x10;
      arg1[1] = 0;
    }
    else {
      arg1[3] = uvalue2 | 0x20;
    }
  }
  return 0xffffffff;
}
