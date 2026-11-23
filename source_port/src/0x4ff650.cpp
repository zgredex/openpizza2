// Math_CompareRounded: ported from Pizza Connection 2 at 0x4ff650.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ff650
#include "pc2_port.h"

bool Math_CompareRounded(void)

{
  int64_t lvalue1;
  int64_t lvalue2;
  
  __ftol();
  lvalue1 = __ftol();
  lvalue2 = __ftol();
  return (intptr_t)lvalue1 < (intptr_t)lvalue2;
}
