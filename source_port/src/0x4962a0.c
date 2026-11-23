// CompareScreen_UpdateMenuRatingBars: ported from Pizza Connection 2 at 0x4962a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4962a0
#include "pc2_port.h"

void __cdecl CompareScreen_UpdateMenuRatingBars(void *arg1,void *arg2)

{
  int value1;
  int value2;
  int value3;
  
                    /* Fills the comparison menu-rating bars. */
  value2 = 0;
  do {
    value3 = DAT_0058271c;
    value1 = Branch_GetMenuRating(arg2,value2);
    Rating_UpdateBarByKey(arg1,0x4e8,value2,value1,value3);
    value2 = value2 + 1;
  } while (value2 < 8);
  return;
}
