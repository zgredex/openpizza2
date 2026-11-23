// Game_GetMaxIndex4: ported from Pizza Connection 2 at 0x4e47e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e47e0
#include "pc2_port.h"

uint8_t __fastcall Game_GetMaxIndex4(int arg1)

{
  uint8_t uvalue1;
  uint32_t uvalue2;
  int value3;
  int value4;
  
  uvalue1 = 0;
  value4 = -1000;
  uvalue2 = 0;
  do {
    value3 = (intptr_t)*(char *)((uvalue2 & 0xff) + 200 + arg1);
    if (value4 <= value3) {
      uvalue1 = (uint8_t)uvalue2;
      value4 = value3;
    }
    uvalue2 = uvalue2 + 1;
  } while ((intptr_t)uvalue2 < 4);
  return uvalue1;
}
