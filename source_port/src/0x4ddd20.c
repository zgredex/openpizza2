// Company_InvalidateAllBranchRatings: ported from Pizza Connection 2 at 0x4ddd20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ddd20
#include "pc2_port.h"

void __fastcall Company_InvalidateAllBranchRatings(int arg1)

{
  int value1;
  int value2;
  
  value2 = 0;
  if (0 < *(int *)(arg1 + 0x15c)) {
    do {
      value1 = IDMap_Lookup((void *)(arg1 + 0x148),value2,(int *)0x0);
      Branch_InvalidateRatingCache(value1);
      value2 = value2 + 1;
    } while (value2 < *(int *)(arg1 + 0x15c));
  }
  return;
}
