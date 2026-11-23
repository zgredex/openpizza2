// Sound_ConvertVolumeSetting: ported from Pizza Connection 2 at 0x547a00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x547a00
#include "pc2_port.h"

uint32_t Sound_ConvertVolumeSetting(uint32_t arg1)

{
  uint32_t uvalue1;
  uint32_t uvalue2;
  int64_t lvalue3;
  int64_t lvalue4;
  
  if (arg1 < 0x1389) {
    lvalue3 = __ftol();
    uvalue2 = (uint32_t)lvalue3;
  }
  else {
    lvalue3 = __ftol();
    lvalue4 = __ftol();
    uvalue2 = (intptr_t)lvalue3 + (intptr_t)lvalue4;
  }
  uvalue1 = 10000;
  if (uvalue2 < 0x2711) {
    uvalue1 = uvalue2;
  }
  return uvalue1;
}
