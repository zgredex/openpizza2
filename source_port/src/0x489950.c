// Game_CountPlayerRecordsByField34: ported from Pizza Connection 2 at 0x489950.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x489950
#include "pc2_port.h"

int __thiscall Game_CountPlayerRecordsByField34(void *self,int arg1)

{
  int value1;
  int value2;
  int value3;
  int value4;
  int local_c;
  int local_8;
  
  local_c = 0;
  local_8 = 0;
  do {
    value2 = Game_GetPlayerBySlot(self,local_8);
    if (value2 != 0) {
      value1 = *(int *)(value2 + 0x15c);
      value4 = 0;
      if (0 < value1) {
        do {
          value3 = IDMap_Lookup((void *)(value2 + 0x148),value4,(int *)0x0);
          if (*(int *)(value3 + 0x34) == *(int *)(arg1 + 0xc1c)) {
            local_c = local_c + 1;
          }
          value4 = value4 + 1;
        } while (value4 < value1);
      }
    }
    local_8 = local_8 + 1;
  } while (local_8 < 6);
  return local_c;
}
