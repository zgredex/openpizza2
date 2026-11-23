// Stats_GetCombinedValue: ported from Pizza Connection 2 at 0x4d6390.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d6390
#include "pc2_port.h"

int64_t Stats_GetCombinedValue(int arg1,int arg2)

{
  int64_t lvalue1;
  
  if (arg1 == 1) {
    if ((arg2 != 0) && (arg2 == 1)) {
      lvalue1 = __ftol();
      return lvalue1;
    }
  }
  else if (arg1 == 3) {
    if (arg2 == 0) {
      lvalue1 = __ftol();
      return lvalue1;
    }
  }
  else if (arg1 == 4) {
    switch(arg2) {
    case 1:
      lvalue1 = __ftol();
      return lvalue1;
    case 2:
      lvalue1 = __ftol();
      return lvalue1;
    case 3:
      lvalue1 = __ftol();
      return lvalue1;
    case 4:
      lvalue1 = __ftol();
      return lvalue1;
    case 5:
      lvalue1 = __ftol();
      return lvalue1;
    }
  }
  lvalue1 = __ftol();
  return lvalue1;
}
