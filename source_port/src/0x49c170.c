// Ranking_SortRecordIndices: ported from Pizza Connection 2 at 0x49c170.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49c170
#include "pc2_port.h"


void __cdecl Ranking_SortRecordIndices(uint32_t *arg1)

{
  int value1;
  
  if (0 < (intptr_t)arg1) {
    value1 = 0;
    if (0 < (intptr_t)arg1) {
      do {
        DAT_0057ca94[value1] = value1;
        value1 = value1 + 1;
      } while (value1 < (intptr_t)arg1);
    }
    CRT_QSort(DAT_0057ca94,arg1,4,&LAB_0049c1b0);
  }
  return;
}
