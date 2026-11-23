// Game_GetPlayerCity: ported from Pizza Connection 2 at 0x4ddcc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ddcc0
#include "pc2_port.h"

uint32_t __fastcall Game_GetPlayerCity(int arg1)

{
  return *(uint32_t *)(DAT_0057c670 + 0x224 + *(int *)(arg1 + 0x4c) * 4);
}
