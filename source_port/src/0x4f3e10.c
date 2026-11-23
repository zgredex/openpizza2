// Grid_GetNeighborCell: ported from Pizza Connection 2 at 0x4f3e10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f3e10
#include "pc2_port.h"

int __thiscall Grid_GetNeighborCell(void *self,int arg1,uint32_t arg2)

{
  int value1;
  int value2;
  
  value2 = **(int **)(arg1 + 8) % *(int *)((intptr_t)self + 0x1c);
  value1 = **(int **)(arg1 + 8) / *(int *)((intptr_t)self + 0x1c);
  switch(arg2) {
  case 0:
    value1 = Grid_GetCell(self,value2,value1 + 1);
    return value1;
  case 2:
    value1 = Grid_GetCell(self,value2,value1 + -1);
    return value1;
  case 4:
    value1 = Grid_GetCell(self,value2 + 1,value1 + 1);
    return value1;
  case 5:
    value1 = value1 + -1;
  case 1:
    value1 = Grid_GetCell(self,value2 + 1,value1);
    return value1;
  case 6:
    value1 = Grid_GetCell(self,value2 + -1,value1 + -1);
    return value1;
  case 7:
    value1 = value1 + 1;
  case 3:
    value1 = Grid_GetCell(self,value2 + -1,value1);
    return value1;
  default:
    return arg1;
  }
}
