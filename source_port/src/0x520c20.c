// UI_MoveChildToPosition: ported from Pizza Connection 2 at 0x520c20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x520c20
#include "pc2_port.h"

void __thiscall UI_MoveChildToPosition(void *self,int arg1,int arg2)

{
  int *ptr1;
  int value2;
  int value3;
  int value4;
  int value5;
  
  if ((*(int *)((intptr_t)self + 0x38) != arg1) || (*(int *)((intptr_t)self + 0x3c) != arg2)) {
    ptr1 = (int *)((intptr_t)self + 0x28);
    UI_ClipRect(*(void **)((intptr_t)self + 8),ptr1,1);
    value4 = *ptr1;
    value2 = *(int *)((intptr_t)self + 0x2c);
    value3 = (value4 - *(int *)((intptr_t)self + 0x38)) + arg1;
    value5 = (value2 - *(int *)((intptr_t)self + 0x3c)) + arg2;
    *ptr1 = value3;
    *(int *)((intptr_t)self + 0x2c) = value5;
    *(int *)((intptr_t)self + 0x30) = value3 + (*(int *)((intptr_t)self + 0x30) - value4);
    *(int *)((intptr_t)self + 0x34) = value5 + (*(int *)((intptr_t)self + 0x34) - value2);
    *(int *)((intptr_t)self + 0x3c) = arg2;
    *(int *)((intptr_t)self + 0x38) = arg1;
    if (*(int *)((intptr_t)self + 0x50) != 0) {
      value4 = *(int *)(*(int *)((intptr_t)self + 8) + 0x134);
      value4 = UI_IsValidSize(self,*(int *)(value4 + 0x248),*(int *)(value4 + 0x24c));
      if (value4 == 0) {
        (**(code **)(*(int *)self + 0xc))(5,0,0);
      }
    }
    UI_ClipRect(*(void **)((intptr_t)self + 8),ptr1,1);
  }
  return;
}
