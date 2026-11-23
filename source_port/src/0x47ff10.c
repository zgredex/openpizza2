// Game_GetConstructionPriority: ported from Pizza Connection 2 at 0x47ff10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47ff10
#include "pc2_port.h"

uint32_t __fastcall Game_GetConstructionPriority(int arg1)

{
  void *self;
  int value1;
  int value2;
  
  self = *(void **)(arg1 + 0x16f0);
  value1 = Game_CountFreeBuildingsByType(self,0x1a);
  if (0 < value1) {
    return 2;
  }
  value1 = Game_CountFreeBuildingsByType(self,0x1b);
  if (0 < value1) {
    return 2;
  }
  value1 = Game_CountFreeBuildingsByType(self,0x1c);
  if (0 < value1) {
    return 2;
  }
  value1 = Rating_GetInverse100(arg1);
  if (value1 < 0x28) {
    return 3;
  }
  value1 = 0;
  if (0 < *(int *)(arg1 + 0x19ac)) {
    do {
      value2 = IDMap_Lookup((void *)(arg1 + 0x1998),value1,(int *)0x0);
      if (*(int *)(value2 + 4) < 10) {
        return 1;
      }
      value1 = value1 + 1;
    } while (value1 < *(int *)(arg1 + 0x19ac));
  }
  return 0;
}
