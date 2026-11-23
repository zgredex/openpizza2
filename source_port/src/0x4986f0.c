// Game_ResizeGlobalArray3: ported from Pizza Connection 2 at 0x4986f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4986f0
#include "pc2_port.h"

void __cdecl Game_ResizeGlobalArray3(uint32_t *arg1)

{
  if (DAT_0057ca08 != (LPVOID)0x0) {
    Mem_Free(DAT_0057ca08);
    DAT_0057ca08 = (LPVOID)0x0;
  }
  if (0 < (intptr_t)arg1) {
    DAT_0057ca08 = operator_new((intptr_t)arg1 * 4);
  }
  City_RebuildBuildingRatingIndex(arg1);
  return;
}
