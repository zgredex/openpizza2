// Window_UpdateWarehousePage: ported from Pizza Connection 2 at 0x4c16e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c16e0
#include "pc2_port.h"

void __cdecl Window_UpdateWarehousePage(void *arg1)

{
  void *self;
  int value1;
  int value2;
  int value3;
  int value4;
  int64_t lvalue5;
  
                    /* Updates the warehouse page's rating-derived value. */
  value3 = *(int *)((intptr_t)DAT_0057c670 + 0x218);
  self = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)(value3 + 0x28),(int *)0x0);
  value1 = IDMap_Lookup((void *)(*(int *)((intptr_t)DAT_0057c670 +
                                        *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200) + 0x180),
                       *(int *)(value3 + 0x2c),(int *)0x0);
  value2 = Array_GetStride60(self,*(int *)(value1 + 0x30));
  value3 = Get_Field2C(value1);
  lvalue5 = Stats_GetCombinedValue(3,value3);
  value4 = (intptr_t)lvalue5;
  value3 = *(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8);
  if (*(int *)(value3 + 0x11c) == 0) {
    if (*(int *)(value3 + 0x200) != 0) {
      value4 = (value4 * 0xf) / 10;
    }
  }
  else {
    value4 = (value4 * 5) / 10;
  }
  Gadget_SetTextf(arg1,0x4ee,&DAT_005683a4,value4);
  value3 = Get_Field2C(value1);
  if ((value3 == 0) || (value3 == 1)) {
    Gadget_SetTextf(arg1,0x4eb,(uint8_t *)s__d__s_00568324,3);
  }
  value3 = Stats_GetAverageRecordValue(value1);
  value4 = 0;
  do {
    if (value2 == 0) {
      value1 = 0;
    }
    else {
      value1 = Game_GetRatingPercent(DAT_0057c670,value4,value3);
    }
    Rating_UpdateBarByKey(arg1,0x4e2,value4,value1,DAT_00581048);
    value4 = value4 + 1;
  } while (value4 < 8);
  return;
}
