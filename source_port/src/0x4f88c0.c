// AI_FindCheapestShop: ported from Pizza Connection 2 at 0x4f88c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f88c0
#include "pc2_port.h"

int AI_FindCheapestShop(int arg1,void *arg2,int arg3)

{
  int value1;
  uint32_t *self;
  uint32_t uvalue2;
  int value3;
  uint32_t uvalue4;
  int value5;
  int value6;
  int *ptr7;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  self = City_CollectBuildingsByType(arg2,-1,0,'\x01');
  value1 = self[5];
  local_14 = 0;
  do {
    value6 = 0;
    if (local_14 == 8) {
      arg3 = 0;
    }
    value5 = 0;
    local_10 = 0;
    if (0 < value1 >> 3) {
      uvalue4 = 8;
      do {
        ptr7 = (int *)0x0;
        uvalue2 = Random_RangeFast(value6 * 8,uvalue4);
        value3 = IDMap_Lookup(self,uvalue2,ptr7);
        if (((value3 != 0) &&
            (((Game_ComputeTradeOffers(arg2,value3,1,&local_4,&local_8,arg1,&local_c),
              arg3 == 0 || (local_c != 0)) && (local_8 != 0)))) &&
           ((value5 == 0 || (local_8 < value5)))) {
          value5 = local_8;
          local_10 = value3;
        }
        value6 = value6 + 1;
        uvalue4 = uvalue4 + 8;
      } while (value6 < value1 >> 3);
      if (value5 != 0) break;
    }
    local_14 = local_14 + 1;
  } while (local_14 < 10);
  if (self != (uint32_t *)0x0) {
    (**(code **)*self)(1);
  }
  if (value5 == 0) {
    return 0;
  }
  return local_10;
}
