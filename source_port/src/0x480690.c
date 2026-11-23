// Game_UpdateObjectRatingScales: ported from Pizza Connection 2 at 0x480690.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x480690
#include "pc2_port.h"

void __fastcall Game_UpdateObjectRatingScales(int arg1)

{
  int value1;
  int *ptr2;
  void *self;
  int value3;
  int value4;
  double fVar5;
  
  CS_Enter(*(int *)(DAT_0057c670 + 0x240));
  value1 = *(int *)(arg1 + 0x1514);
  value4 = 0;
  if (0 < value1) {
    do {
      ptr2 = (int *)IDMap_Lookup((void *)(arg1 + 0x1500),value4,(int *)0x0);
      if (ptr2 != (int *)0x0) {
        value3 = *ptr2;
        self = (void *)Game_GetRecordByField814(value3);
        if (*(int *)((intptr_t)self + 0x74) != 0) {
          value3 = Rating_AdjustA(value3);
          fVar5 = Game_GetRatingMultiplier(arg1);
          UI_SetChildScale(self,(double)(fVar5 * (double)value3));
        }
      }
      value4 = value4 + 1;
    } while (value4 < value1);
  }
  CS_Leave(*(int *)(DAT_0057c670 + 0x240));
  return;
}
