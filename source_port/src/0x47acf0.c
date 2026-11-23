// Product_ComputeFreshness: ported from Pizza Connection 2 at 0x47acf0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47acf0
#include "pc2_port.h"

int Product_ComputeFreshness(int arg1)

{
  int64_t lvalue1;
  
  Game_GetCurrentPlayerCompanyName(DAT_0057c670);
  if (*(double *)(arg1 + 0x70) == 14.1) {
    lvalue1 = __ftol();
    return 0x26 - (intptr_t)lvalue1;
  }
  if (*(double *)(arg1 + 0x70) == 15.5) {
    lvalue1 = __ftol();
    return 0x1e - (intptr_t)lvalue1;
  }
  if (*(double *)(arg1 + 0x70) == 16.9) {
    lvalue1 = __ftol();
    return 0x16 - (intptr_t)lvalue1;
  }
  if (*(double *)(arg1 + 0x70) == 6.5) {
    lvalue1 = __ftol();
    return 0x22 - (intptr_t)lvalue1;
  }
  if (*(double *)(arg1 + 0x70) == 7.5) {
    lvalue1 = __ftol();
    return 0x1b - (intptr_t)lvalue1;
  }
  if (*(double *)(arg1 + 0x70) == 8.6) {
    lvalue1 = __ftol();
    return 0x14 - (intptr_t)lvalue1;
  }
  if (*(double *)(arg1 + 0x70) == 2.5) {
    lvalue1 = __ftol();
    return 0x1e - (intptr_t)lvalue1;
  }
  if (*(double *)(arg1 + 0x70) == 2.9) {
    lvalue1 = __ftol();
    return 0x18 - (intptr_t)lvalue1;
  }
  if (*(double *)(arg1 + 0x70) == 3.6) {
    lvalue1 = __ftol();
    return 0x12 - (intptr_t)lvalue1;
  }
  if (*(double *)(arg1 + 0x70) == 1.0) {
    lvalue1 = __ftol();
    return 0x19 - (intptr_t)lvalue1;
  }
  if (*(double *)(arg1 + 0x70) == 1.2) {
    lvalue1 = __ftol();
    return 0x14 - (intptr_t)lvalue1;
  }
  if (*(double *)(arg1 + 0x70) == 1.6) {
    lvalue1 = __ftol();
    return 0xf - (intptr_t)lvalue1;
  }
  return 0;
}
