// Gfx_InitBlendTable: ported from Pizza Connection 2 at 0x53a1b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53a1b0
#include "pc2_port.h"

void Gfx_InitBlendTable(void)

{
  Gfx_BuildBlendTable(0x584518);
  return;
}
