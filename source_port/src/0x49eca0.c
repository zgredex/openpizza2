// Stats_SortActiveProductIndices: ported from Pizza Connection 2 at 0x49eca0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49eca0
#include "pc2_port.h"


void __cdecl Stats_SortActiveProductIndices(uint32_t *arg1)

{
  if (0 < (intptr_t)arg1) {
    CRT_QSort(&DAT_0057cc40,arg1,4,&LAB_0049ecc0);
  }
  return;
}
