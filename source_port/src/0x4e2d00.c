// Player_ComputeAverageRating: ported from Pizza Connection 2 at 0x4e2d00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e2d00
#include "pc2_port.h"

int __fastcall Player_ComputeAverageRating(int arg1)

{
  void *self;
  int value1;
  int *ptr2;
  int value3;
  int value4;
  int value5;
  int value6;
  int local_10;
  int local_c;
  
  value5 = 0;
  local_c = 0;
  local_10 = 0;
  if (0 < *(int *)(arg1 + 0x15c)) {
    do {
      self = (void *)IDMap_Lookup((void *)(arg1 + 0x148),local_10,(int *)0x0);
      value1 = Game_CountObjectsByType(self,0xffffffff);
      local_c = local_c + value1;
      value6 = 0;
      if (0 < value1) {
        do {
          ptr2 = (int *)IDMap_Lookup((void *)((intptr_t)self + 0x1500),value6,(int *)0x0);
          value3 = Rating_ClampAdjusted(*ptr2);
          value4 = Rating_AdjustA(*ptr2);
          value5 = value5 + value3 + value4;
          value6 = value6 + 1;
        } while (value6 < value1);
      }
      local_10 = local_10 + 1;
    } while (local_10 < *(int *)(arg1 + 0x15c));
    if ((value5 != 0) && (local_c != 0)) {
      return value5 / local_c;
    }
  }
  return 0;
}
