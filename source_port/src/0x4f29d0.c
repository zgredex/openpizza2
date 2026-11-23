// IsMenuIdRange: ported from Pizza Connection 2 at 0x4f29d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f29d0
#include "pc2_port.h"

uint32_t IsMenuIdRange(int arg1)

{
  if ((((((arg1 == 0x34e) || (arg1 == 0x34d)) || (arg1 == 0x34f)) ||
       ((arg1 == 0x352 || (arg1 == 0x353)))) ||
      ((arg1 == 0x354 || ((arg1 == 0x350 || (arg1 == 0x355)))))) || (arg1 == 0x351)) {
    return 1;
  }
  return 0;
}
