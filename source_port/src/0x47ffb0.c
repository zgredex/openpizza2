// Game_GetBuildingConditionCode: ported from Pizza Connection 2 at 0x47ffb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47ffb0
#include "pc2_port.h"

uint32_t __fastcall Game_GetBuildingConditionCode(void *arg1)

{
  int value1;
  int *ptr2;
  int value3;
  int value4;
  
  value4 = 0;
  value1 = Game_CountObjectsByType(arg1,0xffffffff);
  if (0 < value1) {
    do {
      ptr2 = (int *)IDMap_Lookup((void *)((intptr_t)arg1 + 0x1500),value4,(int *)0x0);
      value1 = *ptr2;
      value3 = Rating_AdjustB(value1);
      if (value3 < 0x14) {
        return 5;
      }
      if (*(int *)(value1 + 0xc) < 0x14) {
        return 4;
      }
      value4 = value4 + 1;
      value1 = Game_CountObjectsByType(arg1,0xffffffff);
    } while (value4 < value1);
  }
  return 0;
}
