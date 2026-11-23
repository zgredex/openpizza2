// Rating_ComputeEightCategories: ported from Pizza Connection 2 at 0x478ae0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x478ae0
#include "pc2_port.h"

void Rating_ComputeEightCategories(int *arg1,int *arg2)

{
  int value1;
  uint32_t uvalue2;
  int value3;
  int value4;
  uint32_t uvalue5;
  int value6;
  int *ptr7;
  int *ptr8;
  int local_14;
  int local_10;
  int local_c;
  uint32_t local_8;
  uint32_t local_4;
  
  local_10 = 0;
  local_14 = arg1[1];
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  local_10 = Rating_AdjustA((intptr_t)arg1);
  local_c = arg1[3];
  Rating_AdjustB((intptr_t)arg1);
  value1 = arg1[0xe];
  ptr8 = arg2;
  for (value3 = 8; value3 != 0; value3 = value3 + -1) {
    *ptr8 = 0;
    ptr8 = ptr8 + 1;
  }
  arg1 = &local_14;
  ptr8 = &DAT_005676d8;
  do {
    value6 = 8;
    value3 = *arg1;
    ptr7 = arg2;
    do {
      value4 = value3 - *ptr8;
      if (value4 < 0) {
        value4 = value4 >> 2;
      }
      else {
        value4 = value4 / 5;
      }
      ptr8 = ptr8 + 1;
      *ptr7 = *ptr7 + value4 + 0x19;
      ptr7 = ptr7 + 1;
      value6 = value6 + -1;
    } while (value6 != 0);
    arg1 = arg1 + 1;
  } while ((intptr_t)ptr8 < 0x567758);
  value3 = (intptr_t)&DAT_00567758 - (intptr_t)arg2;
  value6 = 8;
  do {
    uvalue2 = value1 - *(int *)(value3 + (intptr_t)arg2);
    uvalue5 = (intptr_t)uvalue2 >> 0x1f;
    value4 = *arg2 - ((uvalue2 ^ uvalue5) - uvalue5);
    *arg2 = value4;
    if (value4 < 0) {
      *arg2 = 0;
    }
    if (100 < *arg2) {
      *arg2 = 100;
    }
    arg2 = arg2 + 1;
    value6 = value6 + -1;
  } while (value6 != 0);
  return;
}
