// Game_GetBestBuildingRatingBand: ported from Pizza Connection 2 at 0x501f90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x501f90
#include "pc2_port.h"

uint32_t Game_GetBestBuildingRatingBand(void)

{
  int value1;
  int value2;
  void *self;
  int value3;
  int value4;
  int value5;
  int value6;
  
  value6 = 0;
  value4 = 0;
  value1 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  value2 = *(int *)(value1 + 0x15c);
  if (0 < value2) {
    do {
      self = (void *)IDMap_Lookup((void *)(value1 + 0x148),value4,(int *)0x0);
      value5 = 0;
      do {
        value3 = Branch_GetCustomerGroupRating(self,value5,1);
        if (value6 < value3) {
          value6 = value3;
        }
        value5 = value5 + 1;
      } while (value5 < 8);
      value4 = value4 + 1;
    } while (value4 < value2);
    if (0x50 < value6) {
      return 3;
    }
    if (0x3b < value6) {
      return 2;
    }
    if (0x28 < value6) {
      return 1;
    }
  }
  return 0;
}
