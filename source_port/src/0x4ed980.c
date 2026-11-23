// Map_ComputeVisibleTileRange: ported from Pizza Connection 2 at 0x4ed980.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ed980
#include "pc2_port.h"

void __thiscall
Map_ComputeVisibleTileRange
          (void *self,int *arg1,int *arg2,int *arg3,int *arg4,int *arg5,
          uint32_t *arg6)

{
  int *ptr1;
  int value2;
  int value3;
  
  *arg6 = 0;
  Map_ScreenToTileCoords(self,arg1,arg2,arg3);
  Map_RecordPointToGridCell(self,(intptr_t)arg1,arg4,arg5);
  ptr1 = (int *)Grid_GetCell(self,*arg2 + 1,*arg3);
  if ((ptr1 != (int *)0x0) && (*arg1 < *ptr1)) {
    *arg2 = *arg2 + -1;
  }
  value2 = Grid_GetCell(self,*arg2 + 1,*arg3);
  if ((value2 != 0) && (arg1[1] <= *(int *)(value2 + 4) + *(int *)((intptr_t)self + 0x10))) {
    *arg2 = *arg2 + -1;
    *arg5 = *arg5 + -1;
    *arg6 = 1;
  }
  while( true ) {
    value2 = Grid_GetCell(self,*arg2,*arg3);
    value3 = Grid_GetCell(self,*arg4,*arg5);
    if (((value2 == 0) || (value3 == 0)) || (*(int *)(value3 + 4) <= *(int *)(value2 + 4))) break;
    *arg5 = *arg5 + -1;
  }
  return;
}
