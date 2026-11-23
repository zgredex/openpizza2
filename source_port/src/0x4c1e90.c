// Game_ResizeGlobalArray2: ported from Pizza Connection 2 at 0x4c1e90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c1e90
#include "pc2_port.h"

void __cdecl Game_ResizeGlobalArray2(uint32_t *arg1)

{
  if (DAT_0057d72c != (LPVOID)0x0) {
    Mem_Free(DAT_0057d72c);
    DAT_0057d72c = (LPVOID)0x0;
  }
  if (0 < (intptr_t)arg1) {
    DAT_0057d72c = operator_new((intptr_t)arg1 * 4);
  }
  if (DAT_0057d728 == 0) {
    PlayerRecordPanel_SortIndices(arg1);
    return;
  }
  City_RebuildProductSortIndex(arg1);
  return;
}
