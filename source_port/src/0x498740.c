// City_RebuildBuildingRatingIndex: ported from Pizza Connection 2 at 0x498740.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x498740
#include "pc2_port.h"


void __cdecl City_RebuildBuildingRatingIndex(uint32_t *arg1)

{
  int value1;
  
  if (0 < (intptr_t)arg1) {
    value1 = 0;
    if (0 < (intptr_t)arg1) {
      do {
        DAT_0057ca08[value1] = value1;
        value1 = value1 + 1;
      } while (value1 < (intptr_t)arg1);
    }
    CRT_QSort(DAT_0057ca08,arg1,4,&LAB_00498370);
  }
  return;
}
