// Branch_CancelConstructionAt: ported from Pizza Connection 2 at 0x47e8c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47e8c0
#include "pc2_port.h"

void __thiscall Branch_CancelConstructionAt(void *self,int arg1)

{
  int value1;
  
  *(uint32_t *)(arg1 + 0x1c) = 0;
  value1 = Grid_GetCell(*(void **)((intptr_t)self + 0x14e0),*(int *)(arg1 + 0x14),
                       *(int *)(arg1 + 0x18));
  Map_SetTileFieldWithDefault(*(void **)((intptr_t)self + 0x14e0),value1,-1,1);
  *(uint32_t *)(*(int *)((intptr_t)self + 0x14e0) + 0xf4) = 1;
  value1 = Game_FindRecordByPair(self,*(int *)(arg1 + 0x14),*(int *)(arg1 + 0x18));
  if (value1 != 0) {
    Branch_RemoveConstructionOrder(self,value1);
  }
  return;
}
