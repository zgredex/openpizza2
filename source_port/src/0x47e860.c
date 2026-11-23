// AI_StepToNeighborCell: ported from Pizza Connection 2 at 0x47e860.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47e860
#include "pc2_port.h"

void __thiscall AI_StepToNeighborCell(void *self,int arg1)

{
  uint32_t uvalue1;
  int value2;
  int value3;
  bool flag4;
  
  uvalue1 = Map_LookupLinear((void *)((intptr_t)self + 0x1998),arg1);
  uvalue1 = uvalue1 & 0x80000001;
  flag4 = uvalue1 == 0;
  if ((intptr_t)uvalue1 < 0) {
    flag4 = (uvalue1 - 1 | 0xfffffffe) == 0xffffffff;
  }
  if (flag4) {
    value2 = *(int *)(arg1 + 0x18);
    value3 = *(int *)(arg1 + 0x14) + 3;
  }
  else {
    value2 = *(int *)(arg1 + 0x18);
    value3 = *(int *)(arg1 + 0x14) + -3;
  }
  value2 = Grid_GetCell(*(void **)((intptr_t)self + 0x14e0),value3,value2);
  Array_GetRecord28(*(void **)((intptr_t)self + 0x14e0),1,(intptr_t)*(short *)(*(int *)(value2 + 8) + 0x24));
  return;
}
