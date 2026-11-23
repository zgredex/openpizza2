// Game_MarkObjectsDirtyForState: ported from Pizza Connection 2 at 0x4f78e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f78e0
#include "pc2_port.h"

void Game_MarkObjectsDirtyForState(void *arg1,int arg2)

{
  if (arg2 == 6) {
    Array_SetSlot(*(void **)(*(int *)(DAT_0057c670 + 0x224) + 0xac),7,1);
  }
  Game_MarkAllObjectsDirty(arg1,arg2);
  return;
}
