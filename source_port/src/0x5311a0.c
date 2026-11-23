// UI_RemoveObject: ported from Pizza Connection 2 at 0x5311a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5311a0
#include "pc2_port.h"

int __thiscall UI_RemoveObject(void *self,int arg1)

{
  uint32_t uvalue1;
  int value2;
  int *ptr3;
  uint32_t *uptr4;
  int value5;
  int *ptr6;
  int value7;
  
  CS_Enter(*(int *)(*(int *)((intptr_t)self + 0x134) + 0x1c8));
  UI_PurgeChildFromLists(self,arg1);
  value5 = BinarySearch8(self,arg1,'\0');
  if (value5 == -1) {
    CS_Leave(*(int *)(*(int *)((intptr_t)self + 0x134) + 0x1c8));
  }
  else {
    UI_ClearDestroyedObjectReferences
              (*(void **)((intptr_t)self + 0x134),*(int *)(*(int *)((intptr_t)self + 0xe8) + value5 * 8));
    value2 = *(int *)((intptr_t)self + 0xf0);
    value7 = 0;
    if (0 < value2) {
      ptr3 = *(int **)((intptr_t)self + 0xec);
      ptr6 = ptr3;
      do {
        if (*ptr6 == *(int *)(*(int *)((intptr_t)self + 0xe8) + value5 * 8)) {
          uvalue1 = (value2 - value7) * 8 - 8;
          if (0 < (intptr_t)uvalue1) {
            _memmove(ptr3 + value7 * 2,ptr3 + value7 * 2 + 2,uvalue1);
          }
          break;
        }
        value7 = value7 + 1;
        ptr6 = ptr6 + 2;
      } while (value7 < value2);
    }
    UI_ClipChildRect(*(int *)(*(int *)((intptr_t)self + 0xe8) + value5 * 8));
    uptr4 = *(uint32_t **)(*(int *)((intptr_t)self + 0xe8) + value5 * 8);
    if (uptr4 != (uint32_t *)0x0) {
      (**(code **)*uptr4)(1);
    }
    uvalue1 = (*(int *)((intptr_t)self + 0xf0) - value5) * 8 - 8;
    if (0 < (intptr_t)uvalue1) {
      _memmove((uint32_t *)(*(int *)((intptr_t)self + 0xe8) + value5 * 8),
               (uint32_t *)(*(int *)((intptr_t)self + 0xe8) + 8 + value5 * 8),uvalue1);
    }
    *(uint32_t *)((intptr_t)self + 0xe0) = 1;
    *(int *)((intptr_t)self + 0xf0) = *(int *)((intptr_t)self + 0xf0) + -1;
    CS_Leave(*(int *)(*(int *)((intptr_t)self + 0x134) + 0x1c8));
    if (value7 <= *(int *)((intptr_t)self + 0xf0)) {
      return value7;
    }
  }
  return -1;
}
