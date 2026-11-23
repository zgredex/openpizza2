// FUN_00555d41: ported from Pizza Connection 2 at 0x555d41.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x555d41
#include "pc2_port.h"

uint32_t __cdecl FUN_00555d41(uint32_t arg1)

{
  int value1;
  
  if (DAT_005858f4 != (code *)0x0) {
    value1 = (*DAT_005858f4)(arg1);
    if (value1 != 0) {
      return 1;
    }
  }
  return 0;
}
