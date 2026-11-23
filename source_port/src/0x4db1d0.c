// Game_SelectRandomPlayerCompany: ported from Pizza Connection 2 at 0x4db1d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4db1d0
#include "pc2_port.h"

void __thiscall Game_SelectRandomPlayerCompany(void *self,int arg1)

{
  int value1;
  uint32_t uvalue2;
  int *ptr3;
  int *ptr4;
  int value5;
  
  value5 = 0;
  if (arg1 == -1) {
    uvalue2 = Random_RangeFast(0,5);
  }
  else {
    value1 = Game_GetPlayerBySlot(DAT_0057c670,arg1);
    uvalue2 = City_GetTopProductCategory(value1);
  }
  ptr4 = (int *)((intptr_t)self + 200);
  value1 = 6;
  ptr3 = ptr4;
  do {
    if (*ptr3 == 1) {
      value5 = value5 + 1;
    }
    ptr3 = ptr3 + 1;
    value1 = value1 + -1;
  } while (value1 != 0);
  if (1 < value5) {
    value5 = 0;
    while (*ptr4 != 1) {
      value5 = value5 + 1;
      ptr4 = ptr4 + 1;
      if (5 < value5) {
        *(uint32_t *)((intptr_t)self + uvalue2 * 4 + 200) = 1;
        return;
      }
    }
    *(uint32_t *)((intptr_t)self + value5 * 4 + 200) = 0;
  }
  *(uint32_t *)((intptr_t)self + uvalue2 * 4 + 200) = 1;
  return;
}
