// Map_UpdateVisibleTiles: ported from Pizza Connection 2 at 0x4f7320.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f7320
#include "pc2_port.h"

void Map_UpdateVisibleTiles(int arg1)

{
  void *self;
  int value1;
  int value2;
  int value3;
  int value4;
  int *ptr5;
  int *local_124;
  int *local_120;
  int local_11c;
  int local_110 [68];
  
  self = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(arg1 + 0x34),(int *)0x0);
  Game_FillNearbyTypeCompanyMatrix(arg1,local_110 + 4);
  local_120 = local_110 + 4;
  local_110[0] = 0;
  local_110[1] = 0;
  local_11c = 8;
  local_110[2] = 0;
  local_110[3] = 0;
  do {
    value3 = 0;
    local_124 = local_120;
    do {
      value2 = *local_124;
      value4 = 0;
      ptr5 = local_110;
      do {
        value1 = Game_GetPlayerQuarterStat(self,value3,value4);
        value4 = value4 + 1;
        *ptr5 = *ptr5 + value1 * value2;
        ptr5 = ptr5 + 1;
      } while (value4 < 4);
      value3 = value3 + 1;
      local_124 = local_124 + 8;
    } while (value3 < 8);
    local_120 = local_120 + 1;
    local_11c = local_11c + -1;
  } while (local_11c != 0);
  value3 = 0;
  value2 = 1;
  ptr5 = local_110;
  do {
    ptr5 = ptr5 + 1;
    if (local_110[0] < *ptr5) {
      local_110[0] = *ptr5;
      value3 = value2;
    }
    value2 = value2 + 1;
  } while (value2 < 4);
  *(int *)(arg1 + 0x24) = value3;
  return;
}
