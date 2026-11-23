// Game_PickRandomBuildingType: ported from Pizza Connection 2 at 0x4da880.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4da880
#include "pc2_port.h"

int __thiscall Game_PickRandomBuildingType(void *self,char arg1)

{
  uint32_t uvalue1;
  uint32_t uvalue2;
  int value3;
  int value4;
  int value5;
  uint32_t local_90;
  int local_88 [34];
  
  local_88[4] = 10;
  local_88[0xe] = 10;
  local_88[0] = 0x21;
  local_88[1] = 4;
  local_88[2] = 8;
  local_88[3] = 1;
  local_88[5] = 0xc;
  local_88[6] = 1;
  local_88[7] = 3;
  local_88[8] = 5;
  local_88[9] = 3;
  local_88[10] = 4;
  local_88[0xb] = 4;
  local_88[0xc] = 8;
  local_88[0xd] = 2;
  local_88[0xf] = 0xc;
  local_88[0x10] = 1;
  local_88[0x11] = 9;
  local_88[0x12] = 0xd;
  local_88[0x13] = 0xe;
  local_88[0x14] = 4;
  local_88[0x15] = 0;
  local_88[0x16] = 0x21;
  local_88[0x17] = 5;
  local_88[0x18] = 6;
  local_88[0x19] = 4;
  local_88[0x1a] = 4;
  local_88[0x1b] = 3;
  local_88[0x1c] = 4;
  local_88[0x1d] = 4;
  local_88[0x1e] = 4;
  local_88[0x1f] = 3;
  local_88[0x20] = 0x14;
  local_88[0x21] = 1;
  if (arg1 == '\0') {
    local_90 = Random_RangeFast(3,6);
    if (0 < (intptr_t)local_90) {
      do {
        uvalue1 = Random_RangeFast(0,3);
        value5 = local_88[uvalue1];
        value4 = local_88[uvalue1 + 6];
        uvalue2 = Random_RangeFast(0,3);
        local_88[uvalue1] = local_88[uvalue2];
        local_88[uvalue2] = value5;
        local_88[uvalue1 + 6] = local_88[uvalue2 + 6];
        local_88[uvalue2 + 6] = value4;
        local_90 = local_90 - 1;
      } while (local_90 != 0);
    }
    value5 = 6;
  }
  else {
    local_90 = Random_RangeFast(4,7);
    if (0 < (intptr_t)local_90) {
      do {
        uvalue1 = Random_RangeFast(0,8);
        value5 = local_88[uvalue1 + 0xc];
        value4 = local_88[uvalue1 + 0x17];
        uvalue2 = Random_RangeFast(0,8);
        local_88[uvalue1 + 0xc] = local_88[uvalue2 + 0xc];
        local_88[uvalue2 + 0xc] = value5;
        local_88[uvalue1 + 0x17] = local_88[uvalue2 + 0x17];
        local_88[uvalue2 + 0x17] = value4;
        local_90 = local_90 - 1;
      } while (local_90 != 0);
    }
    value5 = 0xb;
  }
  value4 = 0;
  if (value5 != 0) {
    do {
      if (arg1 == '\0') {
        value3 = Game_CountRecordsByOwner(self,local_88[value4]);
        if (value3 < local_88[value4 + 6]) {
          return local_88[value4];
        }
      }
      else {
        value3 = Game_CountRecordsByOwner(self,local_88[value4 + 0xc]);
        if (value3 < local_88[value4 + 0x17]) {
          return local_88[value4 + 0xc];
        }
      }
      value4 = value4 + 1;
    } while (value4 < value5);
  }
  if (arg1 == '\0') {
    uvalue1 = Random_RangeFast(0,value5 - 1);
    return local_88[uvalue1];
  }
  uvalue1 = Random_RangeFast(0,value5 - 1);
  return local_88[uvalue1 + 0xc];
}
