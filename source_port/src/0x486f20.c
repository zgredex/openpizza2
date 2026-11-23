// Game_MarkObjectsDirtyType6: ported from Pizza Connection 2 at 0x486f20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x486f20
#include "pc2_port.h"

void Game_MarkObjectsDirtyType6(void *arg1)

{
  Game_MarkAllObjectsDirty(arg1,6);
  return;
}
