// CompanyBuildingList_SortIndices: ported from Pizza Connection 2 at 0x49e680.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49e680
#include "pc2_port.h"


void __cdecl CompanyBuildingList_SortIndices(uint32_t *arg1)

{
  if (0 < (intptr_t)arg1) {
    CRT_QSort(&DAT_0057cadc,arg1,4,&LAB_0049e6a0);
  }
  return;
}
