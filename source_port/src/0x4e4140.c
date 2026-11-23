// Game_GetCityData: ported from Pizza Connection 2 at 0x4e4140.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e4140
#include "pc2_port.h"

uint32_t __cdecl Game_GetCityData(int arg1)

{
  if ((arg1 < 0) || (0x9c3 < arg1)) {
    return 0;
  }
  return (&DAT_0057dfdc)[arg1];
}
