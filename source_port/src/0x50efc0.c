// Player_ResetAiState: ported from Pizza Connection 2 at 0x50efc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50efc0
#include "pc2_port.h"

void __fastcall Player_ResetAiState(int arg1)

{
  *(uint32_t *)(arg1 + 0x84) = 1;
  *(uint32_t *)(arg1 + 0x88) = 0;
  return;
}
