// Ranking_SortCompanyIndices: ported from Pizza Connection 2 at 0x49ed40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49ed40
#include "pc2_port.h"


void __cdecl Ranking_SortCompanyIndices(uint32_t *arg1)

{
  if (0 < (intptr_t)arg1) {
    CRT_QSort(&DAT_0057cc40,arg1,4,&LAB_0049ed60);
  }
  return;
}
