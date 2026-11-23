// CityView_ReserveCarCell: ported from Pizza Connection 2 at 0x4f5d40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f5d40
#include "pc2_port.h"

void __thiscall CityView_ReserveCarCell(void *self,int arg1,int arg2)

{
  int value1;
  int value2;
  uint32_t uvalue3;
  
  value1 = CityView_IsCarSpawnCellFree(self,arg1);
  if (value1 != 0) {
    value1 = *(int *)((intptr_t)self + 0x4c) + *(int *)(arg1 + 8) * 0xc;
    value2 = Map_GetFirstLinkedCell(self,arg1);
    uvalue3 = Grid_GetDirectionBetweenNodes(arg1,value2);
    value2 = Grid_GetNeighborCell(self,value1,uvalue3);
    *(uint32_t *)(*(int *)(value1 + 8) + 0x38) = 1;
    *(uint32_t *)(*(int *)(value2 + 8) + 0x38) = 1;
    *(uint32_t *)(arg2 + 0x44) = **(uint32_t **)(value1 + 8);
    *(uint32_t *)(arg2 + 0x48) = **(uint32_t **)(value2 + 8);
    *(uint32_t *)(arg2 + 0x4c) = 0xffffffff;
    *(uint32_t *)(arg2 + 0x50) = 0xffffffff;
  }
  return;
}
