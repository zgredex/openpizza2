// Map_ScreenToGridCell: ported from Pizza Connection 2 at 0x4f4e90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f4e90
#include "pc2_port.h"

void __thiscall
Map_ScreenToGridCell(void *self,int arg1,int arg2,int *arg3,int *arg4,int *arg5)

{
  int value1;
  
  value1 = Map_ComputeBlitRect(self,arg1,arg2,arg5,0);
  *arg3 = **(int **)(value1 + 8) % *(int *)((intptr_t)self + 0x1c);
  *arg4 = **(int **)(value1 + 8) / *(int *)((intptr_t)self + 0x1c);
  return;
}
