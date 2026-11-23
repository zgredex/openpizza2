// Save_LoadOrInit2: ported from Pizza Connection 2 at 0x49ec70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49ec70
#include "pc2_port.h"

void __cdecl Save_LoadOrInit2(uint32_t *arg1)

{
  if (DAT_00568bdc == 0) {
    Stats_SortActiveProductIndices(arg1);
    return;
  }
  Ranking_SortCompanyIndices(arg1);
  return;
}
