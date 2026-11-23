// Math_RoundFloat: ported from Pizza Connection 2 at 0x403850.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x403850
#include "pc2_port.h"

int64_t Math_RoundFloat(float arg1)

{
  int64_t lvalue1;
  
  if (0.0 <= arg1) {
    lvalue1 = __ftol();
    return lvalue1;
  }
  lvalue1 = __ftol();
  return lvalue1;
}
