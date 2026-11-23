// Object_TryNeighborPlacement: ported from Pizza Connection 2 at 0x4f1e10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f1e10
#include "pc2_port.h"

bool __thiscall Object_TryNeighborPlacement(void *self,int *arg1,int arg2,int arg3)

{
  bool flag1;
  bool flag2;
  int value3;
  int value4;
  int value5;
  
  if (*(int *)((intptr_t)self + 0xc) == 0x10) {
    return false;
  }
  if (arg2 == -1000000) {
    Record_GetTwoFloats48((void *)arg1[0x16],*arg1,&arg2,&arg3);
  }
  value3 = Enum_MapDirection((intptr_t)arg1);
  if (arg1[1] == -1) {
    value4 = Map_ComputeBlitRect(self,arg2 + 0xa0,arg3 + 0xd0,(int *)0x1,0);
    flag1 = 0 < (*(int **)(value4 + 8))[0xd];
    if (flag1) {
      arg1[0xe] = **(int **)(value4 + 8);
    }
    value5 = Object_CanAssignSlot(value4,(intptr_t)arg1,arg1 + 0x13,(uint32_t *)0x0);
    value3 = Grid_GetNeighborCell(self,value4,value3);
    flag2 = 0 < (*(int **)(value3 + 8))[0xd];
    if (flag2) {
      arg1[0xf] = **(int **)(value3 + 8);
    }
    flag2 = flag2 || (value5 != 0 || flag1);
    value3 = Object_CanAssignSlot(value3,(intptr_t)arg1,arg1 + 0x13,(uint32_t *)0x0);
    if (value3 != 0) {
      return true;
    }
  }
  else {
    value4 = Map_ComputeBlitRect(self,*(int *)((intptr_t)self + 0xf8) + arg2,
                                *(int *)((intptr_t)self + 0xfc) + arg3,(int *)0x1,0);
    flag2 = 0 < (*(int **)(value4 + 8))[0xc];
    if (flag2) {
      arg1[0xe] = **(int **)(value4 + 8);
    }
    if (value3 != -1) {
      value3 = Grid_GetNeighborCell(self,value4,value3);
      if (0 < (*(int **)(value3 + 8))[0xc]) {
        flag2 = true;
        arg1[0xf] = **(int **)(value3 + 8);
      }
    }
  }
  return flag2;
}
