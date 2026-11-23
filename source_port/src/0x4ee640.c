// Map_GetObjectNeighborCell: ported from Pizza Connection 2 at 0x4ee640.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ee640
#include "pc2_port.h"

void __thiscall Map_GetObjectNeighborCell(void *self,int arg1,int arg2)

{
  int value1;
  int value2;
  
  value1 = **(int **)(*(int *)((intptr_t)self + 0x4c) + arg2 * 0xc + 8);
  value2 = value1 % *(int *)((intptr_t)self + 0x1c);
  value1 = value1 / *(int *)((intptr_t)self + 0x1c);
  switch(*(uint32_t *)(arg1 + 0xc)) {
  case 0x14:
    Grid_GetCell(self,value2 + 1,value1 + 4);
    return;
  case 0x15:
    Grid_GetCell(self,value2 + 4,value1 + 1);
    return;
  case 0x16:
    Grid_GetCell(self,value2 + 1,value1 + -2);
    return;
  case 0x17:
    value2 = value2 + -2;
    value1 = value1 + 1;
  }
  Grid_GetCell(self,value2,value1);
  return;
}
