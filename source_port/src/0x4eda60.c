// Map_ScreenToTileCoords: ported from Pizza Connection 2 at 0x4eda60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4eda60
#include "pc2_port.h"

void __thiscall Map_ScreenToTileCoords(void *self,int *arg1,int *arg2,int *arg3)

{
  int value1;
  int value2;
  
  value2 = Map_ComputeBlitRect(self,*arg1,arg1[1],(int *)0x1,0);
  if (value2 == 0) {
    for (value2 = Map_ComputeBlitRect(self,*(int *)((intptr_t)self + 0xd8) + *arg1,
                                     *(int *)((intptr_t)self + 0xe0) + arg1[1],(int *)0x1,0);
        value2 == 0; value2 = Map_ComputeBlitRect(self,value2 + 1,value1 + 1,(int *)0x1,0)) {
      value2 = *arg1;
      value1 = arg1[1];
      arg1[1] = value1 + 1;
      *arg1 = value2 + 1;
    }
  }
  *arg2 = **(int **)(value2 + 8) % *(int *)((intptr_t)self + 0x1c);
  *arg3 = **(int **)(value2 + 8) / *(int *)((intptr_t)self + 0x1c);
  return;
}
