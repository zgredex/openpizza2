// UI_MoveElementToIndex: ported from Pizza Connection 2 at 0x531d10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x531d10
#include "pc2_port.h"

void __thiscall UI_MoveElementToIndex(void *self,int arg1,int arg2)

{
  int value1;
  int value2;
  int value3;
  int *ptr4;
  uint32_t uvalue5;
  uint32_t *uptr6;
  uint32_t *uptr7;
  
  value2 = BinarySearch8(self,arg1,'\x01');
  value1 = *(int *)((intptr_t)self + 0xf0);
  value3 = 0;
  if (0 < value1) {
    ptr4 = *(int **)((intptr_t)self + 0xec);
    do {
      if (*ptr4 == *(int *)(*(int *)((intptr_t)self + 0xe8) + value2 * 8)) break;
      value3 = value3 + 1;
      ptr4 = ptr4 + 2;
    } while (value3 < value1);
  }
  if (value3 == value1) {
    return;
  }
  if (arg2 == value3) {
    return;
  }
  if (value3 < arg2) {
    uvalue5 = (arg2 - value3) * 8;
    if ((intptr_t)uvalue5 < 1) goto LAB_00531d96;
    uptr7 = (uint32_t *)(*(int *)((intptr_t)self + 0xec) + 8 + value3 * 8);
    uptr6 = (uint32_t *)(*(int *)((intptr_t)self + 0xec) + value3 * 8);
  }
  else {
    uvalue5 = (value3 - arg2) * 8;
    if ((intptr_t)uvalue5 < 1) goto LAB_00531d96;
    uptr7 = (uint32_t *)(*(int *)((intptr_t)self + 0xec) + arg2 * 8);
    uptr6 = (uint32_t *)(*(int *)((intptr_t)self + 0xec) + 8 + arg2 * 8);
  }
  _memmove(uptr6,uptr7,uvalue5);
LAB_00531d96:
  *(uint32_t *)(*(int *)((intptr_t)self + 0xec) + arg2 * 8) =
       *(uint32_t *)(*(int *)((intptr_t)self + 0xe8) + value2 * 8);
  *(uint32_t *)(*(int *)((intptr_t)self + 0xec) + 4 + arg2 * 8) =
       *(uint32_t *)(*(int *)((intptr_t)self + 0xe8) + 4 + value2 * 8);
  return;
}
