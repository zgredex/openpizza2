// Game_FillNearbyTypeCompanyMatrix: ported from Pizza Connection 2 at 0x4f7a00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f7a00
#include "pc2_port.h"

void Game_FillNearbyTypeCompanyMatrix(int arg1,uint32_t *arg2)

{
  void *self;
  int value1;
  uint32_t *uptr2;
  
  uptr2 = arg2;
  for (value1 = 0x40; value1 != 0; value1 = value1 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  self = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(arg1 + 0x34),(int *)0x0);
  if ((self != (void *)0x0) && (*(int *)(arg1 + 0x16f0) != 0)) {
    Game_CountNearbyObjectTypes(self,*(int *)(arg1 + 0x16f0),arg2);
  }
  return;
}
