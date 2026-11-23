// Game_GetBuildingQualityBand: ported from Pizza Connection 2 at 0x502030.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x502030
#include "pc2_port.h"

uint32_t Game_GetBuildingQualityBand(void)

{
  int value1;
  int value2;
  int value3;
  void *self;
  int value4;
  int *ptr5;
  int value6;
  int value7;
  int value8;
  int local_14;
  int local_10;
  
  local_10 = 0;
  local_14 = 0;
  value1 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  value2 = *(int *)(value1 + 0x15c);
  if (0 < value2) {
    do {
      self = (void *)IDMap_Lookup((void *)(value1 + 0x148),local_14,(int *)0x0);
      value4 = Game_CountObjectsByType(self,0xffffffff);
      value7 = 0;
      value8 = 0;
      if (0 < value4) {
        do {
          ptr5 = (int *)IDMap_Lookup((void *)((intptr_t)self + 0x1500),value8,(int *)0x0);
          value3 = *(int *)(*ptr5 + 0xc);
          value6 = Rating_AdjustB(*ptr5);
          value7 = value7 + value6 + value3;
          value8 = value8 + 1;
        } while (value8 < value4);
      }
      if (value4 == 0) {
        value7 = 0;
      }
      else {
        value7 = value7 / (value4 * 2);
      }
      if (local_10 < value7) {
        local_10 = value7;
      }
      local_14 = local_14 + 1;
    } while (local_14 < value2);
    if (0x50 < local_10) {
      return 3;
    }
    if (0x3b < local_10) {
      return 2;
    }
    if (0x28 < local_10) {
      return 1;
    }
  }
  return 0;
}
