// Person_RefreshShopChoices: ported from Pizza Connection 2 at 0x4dcd00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dcd00
#include "pc2_port.h"

void __fastcall Person_RefreshShopChoices(void *arg1)

{
  uint32_t *self;
  int value1;
  uint32_t uvalue2;
  uint32_t *this_00;
  int *ptr3;
  int value4;
  int local_8;
  int local_4;
  
  self = City_CollectVacantLots(DAT_0057c670);
  local_4 = 0;
  if (0 < (intptr_t)self[5]) {
    do {
      value1 = IDMap_Lookup(self,local_4,(int *)0x0);
      uvalue2 = Random_RangeFast(1,100);
      if (0x50 < (intptr_t)uvalue2) {
        ptr3 = (int *)(value1 + 0xd4);
        local_8 = 7;
        do {
          value1 = *ptr3;
          if (*(int *)(value1 + 4) != 0) {
            if ((*(int *)(value1 + 4) == 0xc) && (uvalue2 = Random_RangeFast(1,100), 0x32 < (intptr_t)uvalue2)
               ) {
              value4 = 3;
            }
            else {
              value4 = *(int *)(value1 + 4);
            }
            this_00 = City_CollectBuildingsByType(arg1,value4,value1,'\0');
            if (0 < (intptr_t)this_00[5]) {
              uvalue2 = Random_RangeFast(0,this_00[5] - 1);
              value1 = IDMap_Lookup(this_00,uvalue2,(int *)0x0);
              if (value1 != 0) {
                *ptr3 = value1;
              }
            }
            if (this_00 != (uint32_t *)0x0) {
              (**(code **)*this_00)(1);
            }
          }
          ptr3 = ptr3 + 1;
          local_8 = local_8 + -1;
        } while (local_8 != 0);
      }
      local_4 = local_4 + 1;
    } while (local_4 < (intptr_t)self[5]);
  }
  if (self != (uint32_t *)0x0) {
    (**(code **)*self)(1);
  }
  return;
}
