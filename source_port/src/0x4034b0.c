// Random_Mod: ported from Pizza Connection 2 at 0x4034b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4034b0
#include "pc2_port.h"

uint32_t __cdecl Random_Mod(uint32_t arg1)

{
  uint32_t uvalue1;
  
  if (arg1 == 0) {
    return 0;
  }
  uvalue1 = _rand();
  return uvalue1 % arg1;
}
