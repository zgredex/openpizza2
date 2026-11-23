// Stats_FillCompanyCategoryLeaders: ported from Pizza Connection 2 at 0x4df200.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4df200
#include "pc2_port.h"

void __thiscall Stats_FillCompanyCategoryLeaders(void *self,int *arg1)

{
  void *pvVar1;
  int value2;
  int value3;
  int value4;
  int value5;
  int local_38;
  int local_30;
  int local_2c;
  int local_28;
  int local_20;
  int local_1c;
  int local_18;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  value3 = 0;
  value5 = 0;
  value4 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_38 = 0;
  if (0 < *(int *)((intptr_t)self + 0x15c)) {
    do {
      pvVar1 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x148),local_38,(int *)0x0);
      value2 = Game_CountObjectsByType(pvVar1,0);
      local_30 = local_30 + value2;
      if (value4 < value2) {
        value4 = value2;
        local_20 = value2;
      }
      value2 = Game_CountObjectsByType(pvVar1,2);
      local_2c = local_2c + value2;
      if (local_1c < value2) {
        local_1c = value2;
      }
      value2 = Game_CountObjectsByType(pvVar1,1);
      value5 = value5 + value2;
      if (value3 < value2) {
        value3 = value2;
      }
      value2 = Game_CountObjectsByType(pvVar1,3);
      local_28 = local_28 + value2;
      if (local_18 < value2) {
        local_18 = value2;
      }
      local_38 = local_38 + 1;
    } while (local_38 < *(int *)((intptr_t)self + 0x15c));
  }
  local_38 = 0;
  *(int *)(*arg1 + 0x40) = local_30;
  *(int *)(*arg1 + 0x44) = value4;
  *(int *)(*arg1 + 0x48) = local_2c;
  *(int *)(*arg1 + 0x4c) = local_1c;
  *(int *)(*arg1 + 0x50) = local_28;
  *(int *)(*arg1 + 0x54) = local_18;
  *(int *)(*arg1 + 0x58) = value5;
  local_10 = 1;
  local_c = 1;
  *(int *)(*arg1 + 0x5c) = value3;
  local_8 = 1;
  local_4 = 1;
  do {
    pvVar1 = (void *)Game_GetPlayerBySlot(DAT_0057c670,local_38);
    if ((pvVar1 != (void *)0x0) && (pvVar1 != self)) {
      value4 = Player_CountObjectsByType(pvVar1,0);
      if (local_20 <= value4) {
        local_10 = 0;
      }
      value4 = Player_CountObjectsByType(pvVar1,2);
      if (local_1c <= value4) {
        local_c = 0;
      }
      value4 = Player_CountObjectsByType(pvVar1,1);
      if (value3 <= value4) {
        local_4 = 0;
      }
      value4 = Player_CountObjectsByType(pvVar1,3);
      if (local_18 <= value4) {
        local_8 = 0;
      }
    }
    local_38 = local_38 + 1;
  } while (local_38 < 6);
  if (local_30 == 0) {
    local_10 = 0;
  }
  if (local_2c == 0) {
    local_c = 0;
  }
  if (local_28 == 0) {
    local_8 = 0;
  }
  if (value5 == 0) {
    local_4 = 0;
  }
  *(int *)(*arg1 + 0x140) = (local_30 + local_10 * 0x19) * 200;
  *(int *)(*arg1 + 0x144) = (local_2c + local_c * 0x19) * 200;
  *(int *)(*arg1 + 0x148) = (local_28 + local_8 * 0x19) * 200;
  *(int *)(*arg1 + 0x14c) = (value5 + local_4 * 0x19) * 200;
  return;
}
