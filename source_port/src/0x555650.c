// FUN_00555650: ported from Pizza Connection 2 at 0x555650.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x555650
#include "pc2_port.h"

uint32_t __cdecl FUN_00555650(uint32_t arg1)

{
  uint32_t uvalue1;
  uint32_t uvalue2;
  
  uvalue1 = 0;
  if ((arg1 & 1) != 0) {
    uvalue1 = 0x10;
  }
  if ((arg1 & 4) != 0) {
    uvalue1 = uvalue1 | 8;
  }
  if ((arg1 & 8) != 0) {
    uvalue1 = uvalue1 | 4;
  }
  if ((arg1 & 0x10) != 0) {
    uvalue1 = uvalue1 | 2;
  }
  if ((arg1 & 0x20) != 0) {
    uvalue1 = uvalue1 | 1;
  }
  if ((arg1 & 2) != 0) {
    uvalue1 = uvalue1 | 0x80000;
  }
  uvalue2 = arg1 & 0xc00;
  if (uvalue2 != 0) {
    if (uvalue2 == 0x400) {
      uvalue1 = uvalue1 | 0x100;
    }
    else if (uvalue2 == 0x800) {
      uvalue1 = uvalue1 | 0x200;
    }
    else if (uvalue2 == 0xc00) {
      uvalue1 = uvalue1 | 0x300;
    }
  }
  if ((arg1 & 0x300) == 0) {
    uvalue1 = uvalue1 | 0x20000;
  }
  else if ((arg1 & 0x300) == 0x200) {
    uvalue1 = uvalue1 | 0x10000;
  }
  if ((arg1 & 0x1000) != 0) {
    uvalue1 = uvalue1 | 0x40000;
  }
  return uvalue1;
}
