// FUN_005556e2: ported from Pizza Connection 2 at 0x5556e2.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5556e2
#include "pc2_port.h"

uint32_t __cdecl FUN_005556e2(uint32_t arg1)

{
  uint32_t uvalue1;
  uint32_t uvalue2;
  
  uvalue1 = (uint32_t)((arg1 & 0x10) != 0);
  if ((arg1 & 8) != 0) {
    uvalue1 = uvalue1 | 4;
  }
  if ((arg1 & 4) != 0) {
    uvalue1 = uvalue1 | 8;
  }
  if ((arg1 & 2) != 0) {
    uvalue1 = uvalue1 | 0x10;
  }
  if ((arg1 & 1) != 0) {
    uvalue1 = uvalue1 | 0x20;
  }
  if ((arg1 & 0x80000) != 0) {
    uvalue1 = uvalue1 | 2;
  }
  uvalue2 = arg1 & 0x300;
  if (uvalue2 != 0) {
    if (uvalue2 == 0x100) {
      uvalue1 = uvalue1 | 0x400;
    }
    else if (uvalue2 == 0x200) {
      uvalue1 = uvalue1 | 0x800;
    }
    else if (uvalue2 == 0x300) {
      uvalue1 = uvalue1 | 0xc00;
    }
  }
  if ((arg1 & 0x30000) == 0) {
    uvalue1 = uvalue1 | 0x300;
  }
  else if ((arg1 & 0x30000) == 0x10000) {
    uvalue1 = uvalue1 | 0x200;
  }
  if ((arg1 & 0x40000) != 0) {
    uvalue1 = uvalue1 | 0x1000;
  }
  return uvalue1;
}
