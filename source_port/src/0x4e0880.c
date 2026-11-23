// Game_FindDailyStatRecord: ported from Pizza Connection 2 at 0x4e0880.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e0880
#include "pc2_port.h"

int __thiscall Game_FindDailyStatRecord(void *self,int arg1,uint32_t arg2,int arg3)

{
  int value1;
  int value2;
  int value3;
  
  value1 = *(int *)((intptr_t)self + 0x178);
  if (arg3 == -1) {
    if (arg2 == *(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 4)) {
      arg3 = (uint32_t)*(uint8_t *)(*(int *)(DAT_0057c670 + 0x94) + 8) + (arg2 - DAT_0057dfbc) * 4;
    }
    else {
      arg3 = (arg2 - DAT_0057dfbc) * 4 + 3;
    }
  }
  value3 = 0;
  if (0 < value1) {
    do {
      value2 = IDMap_Lookup((void *)((intptr_t)self + 0x164),value3,(int *)0x0);
      if ((*(uint32_t *)(value2 + 8) == arg2) && (arg3 == *(int *)(value2 + 4))) {
        return arg1 * 0x20 + 0xdc + value2;
      }
      value3 = value3 + 1;
    } while (value3 < value1);
  }
  return 0;
}
