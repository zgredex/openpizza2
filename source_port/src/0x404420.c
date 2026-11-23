// SetScreenRects: ported from Pizza Connection 2 at 0x404420.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x404420
#include "pc2_port.h"

void SetScreenRects(void)

{
  SetRect((LPRECT)&DAT_00573d38,0,0,800,600);
  SetRect((LPRECT)&DAT_0057c1e8,800,0,0x35c,600);
  return;
}
