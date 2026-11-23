// Game_GetGlobalTableValue: ported from Pizza Connection 2 at 0x482710.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x482710
#include "pc2_port.h"

uint32_t Game_GetGlobalTableValue(int arg1)

{
  return *(uint32_t *)(&DAT_00567d4c + arg1 * 4);
}
