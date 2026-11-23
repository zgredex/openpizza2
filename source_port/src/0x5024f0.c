// AI_SelectRandomAction: ported from Pizza Connection 2 at 0x5024f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5024f0
#include "pc2_port.h"

uint32_t __fastcall AI_SelectRandomAction(int arg1)

{
  int value1;
  int value2;
  int value3;
  int value4;
  uint32_t uvalue5;
  uint32_t local_8;
  
  uvalue5 = 0;
  local_8 = 2;
  value2 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                       (int *)0x0);
  value3 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  if (*(int *)(value2 + 0xc20 + value3 * 4) == 6) {
    if (*(int *)(arg1 + 0x44) != 0) goto LAB_0050258d;
    *(uint32_t *)(arg1 + 0x44) = 1;
  }
  if (*(int *)(arg1 + 0x44) == 0) {
    value2 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                         (int *)0x0);
    uvalue5 = (uint32_t)(4 < *(int *)(value2 + 0x10c4));
    if (*(int *)(*(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200) +
                0x1d8) != 0) {
      local_8 = 1;
    }
  }
LAB_0050258d:
  if (*(int *)(arg1 + 0x44) == 2) {
    uvalue5 = 1;
    value2 = 0;
    do {
      value3 = Game_GetPlayerBySlot(DAT_0057c670,value2);
      if (((value3 != 0) &&
          (value1 = *(int *)(value3 + 0x48),
          value4 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670), value1 != value4)) &&
         (0 < *(int *)(value3 + 0x194))) goto LAB_005025d8;
      value2 = value2 + 1;
    } while (value2 < 6);
    uvalue5 = 1;
  }
LAB_005025d8:
  Random_RangeFast(uvalue5,local_8);
  uvalue5 = Random_RangeFast(uvalue5,local_8);
  value2 = (*(int *)(arg1 + 0x44) + uvalue5 * 4) * 4;
  *(uint32_t *)(arg1 + 0x4c) = *(uint32_t *)(&DAT_0057270c + value2);
  return *(uint32_t *)(&DAT_005726dc + value2);
}
