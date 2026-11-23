// Building_MapSubtypeToState: ported from Pizza Connection 2 at 0x508fb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x508fb0
#include "pc2_port.h"

uint32_t Building_MapSubtypeToState(uint32_t arg1)

{
  uint32_t uvalue1;
  
  uvalue1 = 0xffffffff;
  switch(arg1) {
  case 0:
    return 6;
  case 1:
    uvalue1 = 0;
    break;
  case 2:
    return 2;
  case 3:
    return 4;
  }
  return uvalue1;
}
