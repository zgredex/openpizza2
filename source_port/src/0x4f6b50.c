// Game_CompleteMissionStage: ported from Pizza Connection 2 at 0x4f6b50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f6b50
#include "pc2_port.h"

void Game_CompleteMissionStage(void)

{
  DAT_0057c5c0 = (-(uint32_t)(DAT_0057bb20 != '\0') & 2) + 3;
  UI_QueueChildCommand(DAT_0057c5e0,-0x18684,0);
  return;
}
