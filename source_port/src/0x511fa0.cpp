// Math_TruncateDouble: ported from Pizza Connection 2 at 0x511fa0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x511fa0
#include "pc2_port.h"

int64_t Math_TruncateDouble(void)

{
  int64_t lvalue1;
  
  lvalue1 = __ftol();
  return lvalue1;
}
