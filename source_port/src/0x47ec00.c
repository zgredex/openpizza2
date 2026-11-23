// Game_RemoveTrackedRecord: ported from Pizza Connection 2 at 0x47ec00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47ec00
#include "pc2_port.h"

void __thiscall Game_RemoveTrackedRecord(void *self,int arg1)

{
  int value1;
  
  value1 = Game_FindRecordByField10(self,*(int *)(arg1 + 0x164));
  if (value1 != 0) {
    IDMap_RemoveByKey((void *)((intptr_t)self + 0x19c4),value1);
  }
  return;
}
