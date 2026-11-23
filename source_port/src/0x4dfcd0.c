// Game_FillCompanyRankingStats: ported from Pizza Connection 2 at 0x4dfcd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dfcd0
#include "pc2_port.h"

void __thiscall Game_FillCompanyRankingStats(void *self,int *arg1)

{
  int value1;
  int value2;
  int value3;
  uint32_t uvalue4;
  int value5;
  int value6;
  int value7;
  int value8;
  int local_10;
  
  value6 = 1;
  value1 = *(int *)((intptr_t)self + 0x70);
  value2 = *(int *)((intptr_t)self + 0x74);
  value3 = *(int *)((intptr_t)self + 0x8c);
  value8 = 1;
  value7 = 1;
  local_10 = 0;
  do {
    value5 = Game_GetPlayerBySlot(DAT_0057c670,local_10);
    if (value5 != 0) {
      if (value1 < *(int *)(value5 + 0x70)) {
        value6 = 0;
      }
      if (value2 < *(int *)(value5 + 0x74)) {
        value8 = 0;
      }
      if (*(int *)(value5 + 0x8c) < value3) {
        value7 = 0;
      }
    }
    local_10 = local_10 + 1;
  } while (local_10 < 6);
  if (value1 == 0) {
    value6 = 0;
  }
  if (value2 == 0) {
    value8 = 0;
  }
  if (value3 == 0) {
    value7 = 0;
  }
  *(int *)(*arg1 + 0xbc) = value1;
  *(int *)(*arg1 + 0xc0) = value6;
  *(int *)(*arg1 + 0x180) = (value1 + value6 * 0x32) * 100;
  *(int *)(*arg1 + 0xc4) = value2;
  *(int *)(*arg1 + 200) = value8;
  *(int *)(*arg1 + 0x184) = (value2 + value8 * 0x32) * 100;
  *(int *)(*arg1 + 0xcc) = value3;
  *(int *)(*arg1 + 0xd0) = value7;
  *(int *)(*arg1 + 0x188) = (value3 + value7 * 0x32) * 100;
  value1 = *(int *)((intptr_t)self + 0x88);
  uvalue4 = *(uint32_t *)((intptr_t)self + 0x90);
  *(int *)(*arg1 + 0xd4) = value1;
  *(uint32_t *)(*arg1 + 0xd8) = uvalue4;
  *(int *)(*arg1 + 0x18c) = value1 * 10000;
  return;
}
