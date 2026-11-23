// IsMenuId351Or355: ported from Pizza Connection 2 at 0x4f2a80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f2a80
#include "pc2_port.h"

uint32_t IsMenuId351Or355(int arg1)

{
  if ((arg1 == 0x355) || (arg1 == 0x351)) {
    return 1;
  }
  return 0;
}
