// Game_SumPlayerAssetValue: ported from Pizza Connection 2 at 0x4f7a50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f7a50
#include "pc2_port.h"

int Game_SumPlayerAssetValue(int arg1)

{
  int value1;
  int value2;
  void *self;
  int value3;
  int *ptr4;
  int value5;
  int value6;
  int local_14;
  int local_10;
  
  value2 = Game_GetPlayerBySlot(DAT_0057c670,arg1);
  value1 = *(int *)(value2 + 0x15c);
  arg1 = 0;
  local_10 = 0;
  local_14 = 0;
  if (0 < value1) {
    do {
      self = (void *)IDMap_Lookup((void *)(value2 + 0x148),local_14,(int *)0x0);
      if (self != (void *)0x0) {
        value3 = Game_CountObjectsByType(self,0xffffffff);
        value6 = 0;
        if (0 < value3) {
          do {
            ptr4 = (int *)IDMap_Lookup((void *)((intptr_t)self + 0x1500),value6,(int *)0x0);
            if (*ptr4 != 0) {
              arg1 = arg1 + *(int *)(*ptr4 + 0x3c);
            }
            value6 = value6 + 1;
          } while (value6 < value3);
        }
        local_10 = *(int *)((intptr_t)self + 0x14b0);
      }
      local_14 = local_14 + 1;
    } while (local_14 < value1);
  }
  value6 = 0;
  value1 = *(int *)(value2 + 0x194);
  value3 = 0;
  if (0 < value1) {
    do {
      value5 = IDMap_Lookup((void *)(value2 + 0x180),value3,(int *)0x0);
      if ((value5 != 0) && (*(char *)(value5 + 0x3c) == '\0')) {
        value6 = value6 + *(int *)(value5 + 0x40);
      }
      value3 = value3 + 1;
    } while (value3 < value1);
  }
  return local_10 + value6 + arg1;
}
