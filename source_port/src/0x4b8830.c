// CompanyProfile_UpdateRatingBars: ported from Pizza Connection 2 at 0x4b8830.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4b8830
#include "pc2_port.h"

void __cdecl CompanyProfile_UpdateRatingBars(void *arg1)

{
  void *self;
  int value1;
  int value2;
  int value3;
  
                    /* Fills the company-profile rating bars. */
  self = *(void **)(DAT_0057c670 + 0x9c);
  value2 = 0;
  do {
    value3 = DAT_005826d8;
    value1 = Stats_GetAverage8(self,value2);
    Rating_UpdateBarByKey(arg1,0x58e,value2,value1,value3);
    value2 = value2 + 1;
  } while (value2 < 8);
  return;
}
