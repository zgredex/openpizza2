// City_FindListContainingValue: ported from Pizza Connection 2 at 0x4f9c90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f9c90
#include "pc2_port.h"

void City_FindListContainingValue(int arg1,int *arg2,int *arg3)

{
  void *self;
  void *pvVar1;
  int value2;
  short *psVar3;
  int value4;
  int value5;
  int local_4;
  
  *arg2 = -1;
  self = (void *)Game_GetCityData(arg1);
  if (self != (void *)0x0) {
    value4 = 0;
    local_4 = 0;
    if (0 < *(int *)(DAT_0057c670 + 0x88)) {
      do {
        pvVar1 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 0x74),value4,(int *)0x0);
        if (pvVar1 == self) break;
        value4 = value4 + 1;
      } while (value4 < *(int *)(DAT_0057c670 + 0x88));
      local_4 = value4;
    }
    value5 = 0;
    value4 = Array_FindEmptySlot8((intptr_t)self);
    if (0 < value4) {
      value4 = 0;
      psVar3 = (short *)((intptr_t)self + 0x78);
      do {
        value2 = Game_CountGroupSlots(self,value5);
        if ((*psVar3 <= arg1) && (arg1 <= *(short *)((intptr_t)self + (value2 + value4) * 2 + 0x76)))
        {
          *arg2 = local_4;
          *arg3 = value5;
        }
        value5 = value5 + 1;
        psVar3 = psVar3 + 6;
        value4 = value4 + 6;
        value2 = Array_FindEmptySlot8((intptr_t)self);
      } while (value5 < value2);
    }
  }
  return;
}
