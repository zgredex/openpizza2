// Branch_InvalidateRatingCache: ported from Pizza Connection 2 at 0x47ee50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47ee50
#include "pc2_port.h"

void __fastcall Branch_InvalidateRatingCache(int arg1)

{
  *(uint32_t *)(arg1 + 0x1714) = 0;
  Game_ClearObjectFlag20(arg1);
  return;
}
