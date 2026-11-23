// Save_LoadOrInit: ported from Pizza Connection 2 at 0x49e5b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49e5b0
#include "pc2_port.h"

void __cdecl Save_LoadOrInit(uint32_t *arg1)

{
  if (DAT_00568b48 == 0) {
    Stats_SortCategoryIndexArray(arg1);
    return;
  }
  CompanyBuildingList_SortIndices(arg1);
  return;
}
