// IsMenuId34EOr350: ported from Pizza Connection 2 at 0x4f2aa0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f2aa0
#include "pc2_port.h"

uint32_t IsMenuId34EOr350(int arg1)

{
  if ((arg1 == 0x34e) || (arg1 == 0x350)) {
    return 1;
  }
  return 0;
}
