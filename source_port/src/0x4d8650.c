// City_InitOfferSlots: ported from Pizza Connection 2 at 0x4d8650.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d8650
#include "pc2_port.h"

void __fastcall City_InitOfferSlots(void *arg1)

{
  int value1;
  uint32_t *self;
  int value2;
  uint32_t uvalue3;
  int *ptr4;
  int value5;
  int value6;
  int *ptr7;
  
  self = City_CollectBuildingsByType(arg1,0x13,0,'\0');
  value5 = 0;
  value1 = self[5];
  if (0 < value1) {
    ptr4 = (int *)((intptr_t)arg1 + 0xdcc);
    do {
      value2 = IDMap_Lookup(self,value5,(int *)0x0);
      value6 = *(int *)(value2 + 0x20) + -0x959 >> 2;
      uvalue3 = Random_RangeFast(0,0x46);
      ptr4[-1] = (uvalue3 - 0x46) + *(int *)(&DAT_0056c9d8 + value6 * 4);
      uvalue3 = Random_RangeFast(0,7);
      *ptr4 = (uvalue3 - 7) + *(int *)(&DAT_0056c9ec + value6 * 4);
      uvalue3 = Random_RangeFast(0,0xf);
      ptr4[1] = (intptr_t)((float)(intptr_t)(uvalue3 - 0xf) * 0.001 + *(float *)(&DAT_0056ca00 + value6 * 4));
      uvalue3 = Random_RangeFast(0,5);
      ptr4[2] = (intptr_t)((float)(intptr_t)uvalue3 * 0.01 + *(float *)(&DAT_0056ca14 + value6 * 4));
      ptr4[3] = *(int *)(value2 + 0x24);
      ptr7 = ptr4 + 4;
      for (value2 = 6; value2 != 0; value2 = value2 + -1) {
        *ptr7 = 0;
        ptr7 = ptr7 + 1;
      }
      ptr7 = ptr4 + 10;
      for (value2 = 6; value2 != 0; value2 = value2 + -1) {
        *ptr7 = 0;
        ptr7 = ptr7 + 1;
      }
      uvalue3 = Random_RangeFast(0,2);
      String_Format((uint8_t *)(ptr4 + 0x10),&DAT_005630d0,
                    *(uint32_t *)(&DAT_0058325c + (uvalue3 + value6 * 3) * 4));
      value5 = value5 + 1;
      ptr4 = ptr4 + 0x18;
    } while (value5 < value1);
  }
  if (self != (uint32_t *)0x0) {
    (**(code **)*self)(1);
  }
  return;
}
