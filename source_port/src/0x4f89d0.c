// AI_FindNearestHouse: ported from Pizza Connection 2 at 0x4f89d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f89d0
#include "pc2_port.h"

int AI_FindNearestHouse(int arg1,void *arg2)

{
  uint32_t *self;
  int value1;
  int value2;
  int value3;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  value2 = 0;
  self = City_CollectBuildingsByType(arg2,0x1d,0,'\0');
  value3 = 0;
  local_10 = 0;
  local_8 = self[5];
  if (0 < local_8) {
    do {
      value1 = IDMap_Lookup(self,value2,(int *)0x0);
      if ((value1 != 0) &&
         (Game_ComputeTradeOffers(arg2,value1,3,&local_14,&local_4,arg1,&local_c),
         local_14 != 0)) {
        if (local_c != 0) {
          local_14 = local_14 >> 1;
        }
        if ((value3 == 0) || (local_14 < value3)) {
          value3 = local_14;
          local_10 = value1;
        }
      }
      value2 = value2 + 1;
    } while (value2 < local_8);
  }
  if (self != (uint32_t *)0x0) {
    (**(code **)*self)(1);
  }
  if (value3 == 0) {
    return 0;
  }
  return local_10;
}
