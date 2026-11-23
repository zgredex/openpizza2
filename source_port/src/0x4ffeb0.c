// Game_AdjustPlayerObjectPercent: ported from Pizza Connection 2 at 0x4ffeb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ffeb0
#include "pc2_port.h"

void __thiscall Game_AdjustPlayerObjectPercent(void *self,int arg1,short arg2)

{
  int value1;
  
  value1 = Game_GetPlayerBySlot(DAT_0057c670,arg1);
  if ((value1 != 0) && (*(int *)((intptr_t)self + *(int *)(value1 + 0x4c) * 0x168 + 0x114) != 0)) {
    Object_AdjustShortPercent(self,*(int *)(value1 + 0x4c),arg2);
  }
  return;
}
