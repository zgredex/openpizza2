// Stats_ComputeCompanyRatingStats: ported from Pizza Connection 2 at 0x4dfe40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dfe40
#include "pc2_port.h"

void __thiscall Stats_ComputeCompanyRatingStats(void *self,int *arg1)

{
  int value1;
  void *this_00;
  int value2;
  uint32_t extraout_EDX;
  uint32_t extraout_EDX_00;
  int value3;
  int value4;
  int value5;
  int local_2c;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_8;
  int local_4;
  
  value1 = *(int *)((intptr_t)self + 0x15c);
  value3 = 0;
  value4 = 0;
  local_8 = 0;
  local_4 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_2c = 0;
  value5 = 0;
  value2 = 0;
  if (0 < value1) {
    do {
      this_00 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x148),local_2c,(int *)0x0);
      value5 = 0;
      do {
        value2 = Stats_GetAverage8(this_00,value5);
        if (local_20 < value2) {
          local_20 = value2;
        }
        value2 = Branch_ComputeBuildingRating(this_00,extraout_EDX,value5);
        if (local_1c < value2) {
          local_1c = value2;
        }
        value2 = Branch_GetMenuRating(this_00,value5);
        if (local_18 < value2) {
          local_18 = value2;
        }
        value2 = Branch_GetCustomerGroupRating(this_00,value5,0);
        if (local_14 < value2) {
          local_14 = value2;
        }
        value5 = value5 + 1;
      } while (value5 < 8);
      value5 = Stats_GetAverage8(this_00,-1);
      value3 = value3 + value5;
      value5 = Branch_ComputeBuildingRating(this_00,extraout_EDX_00,-1);
      value4 = value4 + value5;
      value5 = Branch_GetMenuRating(this_00,-1);
      local_8 = local_8 + value5;
      value5 = Branch_GetCustomerGroupRating(this_00,-1,0);
      local_4 = local_4 + value5;
      local_2c = local_2c + 1;
    } while (local_2c < value1);
    if (0 < value1) {
      value3 = value3 / value1;
      value4 = value4 / value1;
      local_8 = local_8 / value1;
      local_4 = local_4 / value1;
    }
    value5 = local_8;
    value2 = local_4;
  }
  *(int *)(*arg1 + 0xdc) = value3;
  *(int *)(*arg1 + 0xe0) = local_20;
  *(int *)(*arg1 + 0xe4) = value4;
  *(int *)(*arg1 + 0xe8) = local_1c;
  *(int *)(*arg1 + 0xec) = value5;
  *(int *)(*arg1 + 0xf0) = local_18;
  *(int *)(*arg1 + 0xf4) = value2;
  *(int *)(*arg1 + 0xf8) = local_14;
  *(int *)(*arg1 + 0x150) = value3 * 200;
  *(int *)(*arg1 + 0x154) = value4 * 200;
  *(int *)(*arg1 + 0x158) = value5 * 200;
  *(int *)(*arg1 + 0x15c) = value2 * 200;
  return;
}
