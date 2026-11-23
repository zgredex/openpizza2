// Map_RecordPointToGridCell: ported from Pizza Connection 2 at 0x4edaf0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4edaf0
#include "pc2_port.h"

int __thiscall Map_RecordPointToGridCell(void *self,int arg1,int *arg2,int *arg3)

{
  int value1;
  int value2;
  
  value2 = Map_ComputeBlitRect(self,*(int *)(arg1 + 8),*(int *)(arg1 + 4),(int *)0x1,0);
  if (value2 == 0) {
    value2 = Map_ComputeBlitRect(self,*(int *)(arg1 + 8) - *(int *)((intptr_t)self + 0xdc),
                                *(int *)((intptr_t)self + 0xe0) + *(int *)(arg1 + 4),(int *)0x1,0);
    if (value2 == 0) {
      NoOp_Stub();
    }
  }
  *arg3 = **(int **)(value2 + 8) / *(int *)((intptr_t)self + 0x1c);
  value2 = **(int **)(value2 + 8);
  value1 = *(int *)((intptr_t)self + 0x1c);
  *arg2 = value2 % value1;
  return value2 / value1;
}
