// Branch_AutoTunePrice: ported from Pizza Connection 2 at 0x4ff6e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ff6e0
#include "pc2_port.h"

uint32_t Branch_AutoTunePrice(void *arg1)

{
  uint32_t uvalue1;
  int value2;
  int *ptr3;
  int value4;
  int value5;
  short *psVar6;
  short *psVar7;
  int *ptr8;
  int value9;
  uint32_t local_1d0;
  int local_1cc;
  int local_1c8;
  int local_1c0 [8];
  uint32_t local_1a0;
  short local_19a [205];
  
  local_1cc = *(int *)((intptr_t)arg1 + 0x14ac);
  if ((*(int *)((intptr_t)arg1 + 0x14a8) < 0x32) || (0x96 < *(int *)((intptr_t)arg1 + 0x14a8))) {
    uvalue1 = Random_RangeFast(0x32,0x96);
    *(uint32_t *)((intptr_t)arg1 + 0x14a8) = uvalue1;
    *(uint32_t *)((intptr_t)arg1 + 0x1714) = 0;
  }
  Array_Copy68(arg1,&local_1a0);
  value2 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)((intptr_t)arg1 + 0x34),(int *)0x0);
  ptr3 = (int *)(value2 + 0x4c);
  ptr8 = local_1c0;
  for (value5 = 8; value5 != 0; value5 = value5 + -1) {
    *ptr8 = *ptr3;
    ptr3 = ptr3 + 1;
    ptr8 = ptr8 + 1;
  }
  psVar7 = local_19a;
  value2 = 8;
  do {
    ptr3 = local_1c0;
    value5 = 8;
    psVar6 = psVar7;
    do {
      *ptr3 = *ptr3 + (intptr_t)*psVar6;
      psVar6 = psVar6 + 1;
      ptr3 = ptr3 + 1;
      value5 = value5 + -1;
    } while (value5 != 0);
    psVar7 = psVar7 + 0x1a;
    value2 = value2 + -1;
  } while (value2 != 0);
  value2 = 0;
  ptr3 = local_1c0;
  value5 = 8;
  do {
    value9 = *ptr3;
    ptr3 = ptr3 + 1;
    value2 = value2 + value9;
    value5 = value5 + -1;
  } while (value5 != 0);
  value2 = (value2 * 4) / 5;
  local_1d0 = 0x10;
  local_1c8 = 0;
  while( true ) {
    value5 = 0;
    value9 = 0;
    ptr3 = local_1c0;
    do {
      value4 = Branch_GetCustomerGroupRating(arg1,value9,0);
      if (value4 < 0x32) {
        if (0x1e < value4) {
          value5 = value5 + ((value4 + -0x1e) * *ptr3) / 0x14;
        }
      }
      else {
        value5 = value5 + *ptr3;
      }
      value9 = value9 + 1;
      ptr3 = ptr3 + 1;
    } while (value9 < 8);
    if (value2 < value5) {
      if (local_1c8 == -1) {
        local_1d0 = (intptr_t)local_1d0 >> 1;
      }
      local_1c8 = 1;
      uvalue1 = local_1d0;
    }
    else {
      if (value2 <= value5) {
        return 1;
      }
      if (local_1c8 == 1) {
        local_1d0 = (intptr_t)local_1d0 >> 1;
      }
      uvalue1 = -local_1d0;
      local_1c8 = -1;
    }
    local_1cc = local_1cc + uvalue1;
    if ((local_1cc < 0) || (99 < local_1cc)) break;
    *(int *)((intptr_t)arg1 + 0x14ac) = local_1cc;
    *(uint32_t *)((intptr_t)arg1 + 0x1714) = 0;
    if (local_1d0 < 2) {
      return 1;
    }
  }
  *(uint32_t *)((intptr_t)arg1 + 0x14ac) = 10;
  *(uint32_t *)((intptr_t)arg1 + 0x1714) = 0;
  return 1;
}
