// CityView_IsCarSpawnCellFree: ported from Pizza Connection 2 at 0x4f5cd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f5cd0
#include "pc2_port.h"

uint32_t __thiscall CityView_IsCarSpawnCellFree(void *self,int arg1)

{
  int value1;
  int value2;
  int value3;
  uint32_t uvalue4;
  
  value2 = Array_CountValid8(arg1);
  if ((value2 == 1) &&
     (value2 = *(int *)(arg1 + 8), value1 = *(int *)((intptr_t)self + 0x4c),
     *(int *)(*(int *)(value1 + 8 + value2 * 0xc) + 0x38) == 0)) {
    value3 = Map_GetFirstLinkedCell(self,arg1);
    uvalue4 = Grid_GetDirectionBetweenNodes(arg1,value3);
    value2 = Grid_GetNeighborCell(self,value1 + value2 * 0xc,uvalue4);
    if (*(int *)(*(int *)(value2 + 8) + 0x38) == 0) {
      return 1;
    }
  }
  return 0;
}
