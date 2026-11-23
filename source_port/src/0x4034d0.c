// Random_RangeFast: ported from Pizza Connection 2 at 0x4034d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4034d0
#include "pc2_port.h"

uint32_t __cdecl Random_RangeFast(int arg1,uint32_t arg2)

{
  int value1;
  uint32_t uvalue2;
  
  value1 = _rand();
  uvalue2 = (value1 * ((arg2 - arg1) + 1)) / 0x7fff + arg1;
  if (arg2 < uvalue2) {
    uvalue2 = arg2;
  }
  return uvalue2;
}
