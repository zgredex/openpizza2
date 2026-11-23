// Company_FillStatisticsBlock: ported from Pizza Connection 2 at 0x4defd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4defd0
#include "pc2_port.h"

void __thiscall Company_FillStatisticsBlock(void *self,int *arg1)

{
  int *ptr1;
  int value2;
  int value3;
  int value4;
  void *pvVar5;
  int value6;
  int local_c;
  int local_8;
  
  ptr1 = arg1;
  local_8 = 0;
  value2 = Game_GetPlayerCity((intptr_t)self);
  value4 = *(int *)(value2 + 0xa0);
  value3 = *(int *)(value2 + 0x68) + *(int *)(value2 + 100) + *(int *)(value2 + 0x60) +
          *(int *)(value2 + 0x5c) + *(int *)(value2 + 0x58) + *(int *)(value2 + 0x54);
  *(int *)(*arg1 + 0x20) = value3;
  *(int *)(*arg1 + 0x24) = value4;
  *(int *)(*arg1 + 0x130) = (value4 + value3 * 10) * 100;
  *(uint32_t *)(*arg1 + 0x134) = 0;
  value4 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                       (int *)0x0);
  value4 = Game_GetMostAdvancedCompany(value4);
  if (value4 == *(int *)((intptr_t)self + 0x48)) {
    *(uint32_t *)(*arg1 + 0x134) = 10000;
    *(uint32_t *)(*arg1 + 0x28) = 1;
  }
  else {
    *(uint32_t *)(*arg1 + 0x28) = 0;
  }
  local_c = 0;
  arg1 = (int *)0x0;
  do {
    pvVar5 = (void *)Game_GetPlayerBySlot(DAT_0057c670,(intptr_t)arg1);
    if (pvVar5 != (void *)0x0) {
      value4 = *(int *)((intptr_t)pvVar5 + 0x48);
      value3 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                           (int *)0x0);
      local_c = local_c + *(int *)(value3 + 0xdac + value4 * 4);
      if (pvVar5 == self) {
        value4 = *(int *)((intptr_t)pvVar5 + 0x48);
        value3 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                             (int *)0x0);
        local_8 = *(int *)(value3 + 0xdac + value4 * 4);
      }
    }
    arg1 = (int *)((intptr_t)arg1 + 1);
  } while ((intptr_t)arg1 < 6);
  *(int *)(*ptr1 + 0x2c) = local_8;
  if (local_c != 0) {
    *(int *)(*ptr1 + 0x134) = *(int *)(*ptr1 + 0x134) + ((local_8 * 100) / local_c) * 100;
  }
  value6 = 0;
  value4 = *(int *)((intptr_t)self + 0xfc);
  value3 = *(int *)((intptr_t)self + 0x100);
  *(int *)(*ptr1 + 0x30) = value4;
  *(int *)(*ptr1 + 0x34) = value3;
  value4 = (value4 * 2 - value3) * 500;
  if (value4 < 0) {
    value4 = 0;
  }
  *(int *)(*ptr1 + 0x138) = value4;
  value4 = *(int *)(value2 + 0xac);
  *(uint32_t *)(*ptr1 + 0x38) = 0;
  *(uint32_t *)(*ptr1 + 0x3c) = 0;
  *(uint32_t *)(*ptr1 + 0x13c) = 0;
  if (value4 != 0) {
    value2 = 0;
    do {
      if (*(char *)(value4 + 0xc4 + value2) != '\0') {
        value6 = value6 + 1;
      }
      value2 = value2 + 1;
    } while (value2 < 3);
    if (1 < value6) {
      *(uint32_t *)(*ptr1 + 0x38) = 1;
      *(uint32_t *)(*ptr1 + 0x3c) = 1;
      if (value6 == 2) {
        *(uint32_t *)(*ptr1 + 0x13c) = 15000;
        return;
      }
      *(uint32_t *)(*ptr1 + 0x13c) = 30000;
      return;
    }
    if (value6 == 1) {
      *(uint32_t *)(*ptr1 + 0x38) = 1;
      *(uint32_t *)(*ptr1 + 0x13c) = 5000;
    }
  }
  return;
}
