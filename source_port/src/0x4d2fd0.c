// Game_CanShowObject: ported from Pizza Connection 2 at 0x4d2fd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d2fd0
#include "pc2_port.h"

uint32_t __fastcall Game_CanShowObject(int arg1)

{
  void *self;
  int value1;
  
  self = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(arg1 + 0x28),(int *)0x0);
  value1 = Game_CountRecordsByOwner(self,*(int *)(arg1 + 4));
  if (*(int *)(arg1 + 4) == 0x23) {
    return 1;
  }
  if ((*(int *)(arg1 + 0x50) == 0) || (value1 < 2)) {
    return 0;
  }
  return 1;
}
