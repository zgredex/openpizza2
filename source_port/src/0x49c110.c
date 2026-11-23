// Game_ResizeGlobalArray: ported from Pizza Connection 2 at 0x49c110.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49c110
#include "pc2_port.h"

void __cdecl Game_ResizeGlobalArray(uint32_t *arg1)

{
  if (DAT_0057ca94 != (LPVOID)0x0) {
    Mem_Free(DAT_0057ca94);
    DAT_0057ca94 = (LPVOID)0x0;
  }
  if (0 < (intptr_t)arg1) {
    DAT_0057ca94 = operator_new((intptr_t)arg1 * 4);
  }
  if (DAT_005689f0 == '\0') {
    Stats_SortCompanyIndexArray(arg1);
    return;
  }
  Ranking_SortRecordIndices(arg1);
  return;
}
