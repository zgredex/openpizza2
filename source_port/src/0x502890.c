// Game_AnyBuildingRatingAbove: ported from Pizza Connection 2 at 0x502890.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x502890
#include "pc2_port.h"

uint32_t Game_AnyBuildingRatingAbove(int arg1)

{
  uint32_t uvalue1;
  uint32_t uvalue2;
  void *pvVar3;
  int value4;
  uint32_t uvalue5;
  uint32_t extraout_EDX;
  uint32_t uvalue6;
  uint32_t extraout_EDX_00;
  int value7;
  int value8;
  
  value7 = 0;
  uvalue1 = *(uint32_t *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  uvalue2 = *(uint32_t *)(uvalue1 + 0x15c);
  uvalue5 = uvalue1;
  if (0 < (intptr_t)uvalue2) {
    do {
      pvVar3 = (void *)IDMap_Lookup((void *)(uvalue1 + 0x148),value7,(int *)0x0);
      value8 = 0;
      uvalue6 = extraout_EDX;
      do {
        value4 = Branch_ComputeBuildingRating(pvVar3,uvalue6,value8);
        if (arg1 < value4) {
          return CONCAT31((int3)((uint32_t)value4 >> 8),1);
        }
        value8 = value8 + 1;
        uvalue6 = extraout_EDX_00;
      } while (value8 < 8);
      value7 = value7 + 1;
      uvalue5 = uvalue2;
    } while (value7 < (intptr_t)uvalue2);
  }
  return uvalue5 & 0xffffff00;
}
