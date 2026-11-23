// TakeoverScreen_UpdateRatingBars: ported from Pizza Connection 2 at 0x492ae0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x492ae0
#include "pc2_port.h"

void __cdecl TakeoverScreen_UpdateRatingBars(void *arg1)

{
  int value1;
  int value2;
  int value3;
  
                    /* Fills the takeover screen's company rating bars. */
  value2 = 0;
  do {
    value3 = DAT_005826d8;
    value1 = Stats_GetAverage8(DAT_0057c6cc,value2);
    Rating_UpdateBarByKey(arg1,0x4ef,value2,value1,value3);
    value2 = value2 + 1;
  } while (value2 < 8);
  return;
}
