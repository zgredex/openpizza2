// City_RebuildProductSortIndex: ported from Pizza Connection 2 at 0x4c1f30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c1f30
#include "pc2_port.h"


void __cdecl City_RebuildProductSortIndex(uint32_t *arg1)

{
  int value1;
  
  if (0 < (intptr_t)arg1) {
    value1 = 0;
    if (0 < (intptr_t)arg1) {
      do {
        DAT_0057d72c[value1] = value1;
        value1 = value1 + 1;
      } while (value1 < (intptr_t)arg1);
    }
    CRT_QSort(DAT_0057d72c,arg1,4,&LAB_004c1f70);
  }
  return;
}
