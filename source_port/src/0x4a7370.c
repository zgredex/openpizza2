// BuildingMarket_BuildSortedIndex: ported from Pizza Connection 2 at 0x4a7370.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a7370
#include "pc2_port.h"


void __cdecl BuildingMarket_BuildSortedIndex(uint32_t *arg1)

{
  int value1;
  
  if (DAT_0057d28c != (int *)0x0) {
    Mem_Free(DAT_0057d28c);
    DAT_0057d28c = (int *)0x0;
  }
  if (0 < (intptr_t)arg1) {
    DAT_0057d28c = operator_new((intptr_t)arg1 * 4);
    value1 = 0;
    if (0 < (intptr_t)arg1) {
      do {
        DAT_0057d28c[value1] = value1;
        value1 = value1 + 1;
      } while (value1 < (intptr_t)arg1);
    }
    CRT_QSort(DAT_0057d28c,arg1,4,&LAB_004a73e0);
  }
  return;
}
