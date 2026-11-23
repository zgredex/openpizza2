// Game_CountFreeResidentialBuildings: ported from Pizza Connection 2 at 0x47fed0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47fed0
#include "pc2_port.h"

int __fastcall Game_CountFreeResidentialBuildings(int arg1)

{
  void *self;
  int value1;
  int value2;
  int value3;
  
  self = *(void **)(arg1 + 0x16f0);
  if (self == (void *)0x0) {
    return 0;
  }
  value1 = Game_CountFreeBuildingsByType(self,0x1c);
  value2 = Game_CountFreeBuildingsByType(self,0x1b);
  value3 = Game_CountFreeBuildingsByType(self,0x1a);
  return value3 + value1 + value2;
}
