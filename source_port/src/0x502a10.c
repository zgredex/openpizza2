// Game_AllBuildingCategoryRatingsAbove: ported from Pizza Connection 2 at 0x502a10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x502a10
#include "pc2_port.h"

uint32_t Game_AllBuildingCategoryRatingsAbove(int arg1)

{
  int value1;
  int value2;
  void *self;
  uint32_t uvalue3;
  int value4;
  int value5;
  
  value4 = 0;
  value1 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  value2 = *(int *)(value1 + 0x15c);
  value5 = value1;
  if (0 < value2) {
    do {
      self = (void *)IDMap_Lookup((void *)(value1 + 0x148),value4,(int *)0x0);
      value5 = 0;
      do {
        uvalue3 = Branch_GetCustomerGroupRating(self,value5,1);
        if ((intptr_t)uvalue3 < arg1) {
          return uvalue3 & 0xffffff00;
        }
        value5 = value5 + 1;
      } while (value5 < 8);
      value4 = value4 + 1;
      value5 = value2;
    } while (value4 < value2);
  }
  return CONCAT31((int3)((uint32_t)value5 >> 8),1);
}
