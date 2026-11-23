// Object_MoveToMapCell: ported from Pizza Connection 2 at 0x4f2020.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f2020
#include "pc2_port.h"

void __thiscall Object_MoveToMapCell(void *self,int *arg1,int arg2,int arg3)

{
  int value1;
  int *ptr2;
  int value3;
  uint32_t uvalue4;
  
  Object_UpdateState(self,(intptr_t)arg1);
  if (*(int *)((intptr_t)self + 0xc) != 0x10) {
    if (arg2 == -1000000) {
      Record_GetTwoFloats48((void *)arg1[0x16],*arg1,&arg2,&arg3);
    }
    value3 = arg1[0xc];
    if (arg1[1] == -1) {
      if (value3 != -1) {
        value3 = *(int *)(*(int *)((intptr_t)self + 0x4c) + value3 * 0xc + 8);
        value1 = *(int *)(value3 + 0x30);
        if (0 < value1) {
          *(int *)(value3 + 0x30) = value1 + -1;
        }
      }
      if (arg1[0xd] != -1) {
        value3 = *(int *)(*(int *)((intptr_t)self + 0x4c) + arg1[0xd] * 0xc + 8);
        value1 = *(int *)(value3 + 0x30);
        if (0 < value1) {
          *(int *)(value3 + 0x30) = value1 + -1;
        }
      }
      value3 = Map_ComputeBlitRect(self,arg2 + 0xa0,arg3 + 0xd0,(int *)0x1,0);
      Object_ClearSlotRefs(self,(intptr_t)arg1);
      Object_EnsureFirstChild(value3,arg1,arg1 + 0x11);
      ptr2 = *(int **)(value3 + 8);
      if ((ptr2[0xd] == 0) && (-1 < ptr2[0xc])) {
        arg1[0xc] = *ptr2;
        ptr2 = (int *)(*(int *)(value3 + 8) + 0x30);
        *ptr2 = *ptr2 + 1;
      }
      uvalue4 = Enum_MapDirection((intptr_t)arg1);
      value3 = Grid_GetNeighborCell(self,value3,uvalue4);
      Object_EnsureFirstChild(value3,arg1,arg1 + 0x12);
      ptr2 = *(int **)(value3 + 8);
      if ((ptr2[0xd] == 0) && (-1 < ptr2[0xc])) {
        arg1[0xd] = *ptr2;
        *(int *)(*(int *)(value3 + 8) + 0x30) = *(int *)(*(int *)(value3 + 8) + 0x30) + 1;
        return;
      }
    }
    else {
      if (value3 != -1) {
        ptr2 = (int *)(*(int *)(*(int *)((intptr_t)self + 0x4c) + 8 + value3 * 0xc) + 0x34);
        *ptr2 = *ptr2 + -1;
      }
      if (arg1[0xd] != -1) {
        ptr2 = (int *)(*(int *)(*(int *)((intptr_t)self + 0x4c) + 8 + arg1[0xd] * 0xc) + 0x34);
        *ptr2 = *ptr2 + -1;
      }
      value3 = Map_ComputeBlitRect(self,*(int *)((intptr_t)self + 0xf8) + arg2,
                                  *(int *)((intptr_t)self + 0xfc) + arg3,(int *)0x1,0);
      if ((*(int **)(value3 + 8))[0xc] == 0) {
        arg1[0xc] = **(int **)(value3 + 8);
        ptr2 = (int *)(*(int *)(value3 + 8) + 0x34);
        *ptr2 = *ptr2 + 1;
      }
      uvalue4 = Enum_MapDirection((intptr_t)arg1);
      value3 = Grid_GetNeighborCell(self,value3,uvalue4);
      if ((*(int **)(value3 + 8))[0xc] == 0) {
        arg1[0xd] = **(int **)(value3 + 8);
        ptr2 = (int *)(*(int *)(value3 + 8) + 0x34);
        *ptr2 = *ptr2 + 1;
      }
    }
  }
  return;
}
