// BranchInfo_UpdateRatingBars: ported from Pizza Connection 2 at 0x48f860.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48f860
#include "pc2_port.h"

void __cdecl BranchInfo_UpdateRatingBars(void *arg1)

{
  int value1;
  int value2;
  int value3;
  
                    /* Updates the branch header and building-rating bars. */
  CompanyRating_InitHeaderRow(arg1);
  value2 = 0;
  do {
    value3 = DAT_00582320;
    value1 = Branch_ComputeBuildingRating(*(void **)(DAT_0057c670 + 0x9c),DAT_00582320,value2);
    Rating_UpdateBarByKey(arg1,0x4e2,value2,value1,value3);
    value2 = value2 + 1;
  } while (value2 < 8);
  return;
}
