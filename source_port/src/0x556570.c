// FUN_00556570: ported from Pizza Connection 2 at 0x556570.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x556570
#include "pc2_port.h"

uint32_t __cdecl FUN_00556570(uint8_t arg1,uint32_t arg2,uint8_t arg3)

{
  uint32_t uvalue1;
  
  if ((*(uint8_t *)((intptr_t)&DAT_00585ac0 + arg1 + 1) & arg3) == 0) {
    if (arg2 == 0) {
      uvalue1 = 0;
    }
    else {
      uvalue1 = *(uint16_t *)(&DAT_00576aee + (uint32_t)arg1 * 2) & arg2;
    }
    if (uvalue1 == 0) {
      return 0;
    }
  }
  return 1;
}
