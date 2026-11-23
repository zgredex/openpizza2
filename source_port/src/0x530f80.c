// UI_EnsureObjectArray: ported from Pizza Connection 2 at 0x530f80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x530f80
#include "pc2_port.h"

void __thiscall UI_EnsureObjectArray(void *self,int arg1,int arg2)

{
  void *pvVar1;
  uint32_t *uptr2;
  int value3;
  uint32_t *uptr4;
  uint32_t uvalue5;
  uint32_t *uptr6;
  
  CS_Enter(*(int *)(*(int *)((intptr_t)self + 0x134) + 0x1c8));
  if (*(int *)((intptr_t)self + 0xf4) <= *(int *)((intptr_t)self + 0xf0)) {
    if (*(int *)((intptr_t)self + 0xe8) == 0) {
      pvVar1 = operator_new(0x140);
      *(void **)((intptr_t)self + 0xe8) = pvVar1;
      pvVar1 = operator_new(0x140);
      *(void **)((intptr_t)self + 0xec) = pvVar1;
      uvalue5 = *(int *)((intptr_t)self + 0xf4) + 0x28;
      *(uint32_t *)((intptr_t)self + 0xf4) = uvalue5;
      uptr4 = *(uint32_t **)((intptr_t)self + 0xe8);
      for (value3 = (uvalue5 & 0x1fffffff) << 1; value3 != 0; value3 = value3 + -1) {
        *uptr4 = 0;
        uptr4 = uptr4 + 1;
      }
      for (value3 = 0; value3 != 0; value3 = value3 + -1) {
        *(uint8_t *)uptr4 = 0;
        uptr4 = (uint32_t *)((intptr_t)uptr4 + 1);
      }
      uptr4 = *(uint32_t **)((intptr_t)self + 0xec);
      for (value3 = (*(uint32_t *)((intptr_t)self + 0xf4) & 0x1fffffff) << 1; value3 != 0; value3 = value3 + -1)
      {
        *uptr4 = 0;
        uptr4 = uptr4 + 1;
      }
      for (value3 = 0; value3 != 0; value3 = value3 + -1) {
        *(uint8_t *)uptr4 = 0;
        uptr4 = (uint32_t *)((intptr_t)uptr4 + 1);
      }
    }
    else {
      uptr2 = operator_new(*(int *)((intptr_t)self + 0xf4) * 8 + 0x140);
      uptr4 = *(uint32_t **)((intptr_t)self + 0xe8);
      uptr6 = uptr2;
      for (value3 = (*(uint32_t *)((intptr_t)self + 0xf4) & 0x1fffffff) << 1; value3 != 0; value3 = value3 + -1)
      {
        *uptr6 = *uptr4;
        uptr4 = uptr4 + 1;
        uptr6 = uptr6 + 1;
      }
      for (value3 = 0; value3 != 0; value3 = value3 + -1) {
        *(uint8_t *)uptr6 = *(uint8_t *)uptr4;
        uptr4 = (uint32_t *)((intptr_t)uptr4 + 1);
        uptr6 = (uint32_t *)((intptr_t)uptr6 + 1);
      }
      uptr4 = uptr2 + *(int *)((intptr_t)self + 0xf4) * 2;
      for (value3 = 0x50; value3 != 0; value3 = value3 + -1) {
        *uptr4 = 0;
        uptr4 = uptr4 + 1;
      }
      Mem_Free(*(LPVOID *)((intptr_t)self + 0xe8));
      *(uint32_t **)((intptr_t)self + 0xe8) = uptr2;
      uptr2 = operator_new(*(int *)((intptr_t)self + 0xf4) * 8 + 0x140);
      uptr4 = *(uint32_t **)((intptr_t)self + 0xec);
      uptr6 = uptr2;
      for (value3 = (*(uint32_t *)((intptr_t)self + 0xf4) & 0x1fffffff) << 1; value3 != 0; value3 = value3 + -1)
      {
        *uptr6 = *uptr4;
        uptr4 = uptr4 + 1;
        uptr6 = uptr6 + 1;
      }
      for (value3 = 0; value3 != 0; value3 = value3 + -1) {
        *(uint8_t *)uptr6 = *(uint8_t *)uptr4;
        uptr4 = (uint32_t *)((intptr_t)uptr4 + 1);
        uptr6 = (uint32_t *)((intptr_t)uptr6 + 1);
      }
      uptr4 = uptr2 + *(int *)((intptr_t)self + 0xf4) * 2;
      for (value3 = 0x50; value3 != 0; value3 = value3 + -1) {
        *uptr4 = 0;
        uptr4 = uptr4 + 1;
      }
      Mem_Free(*(LPVOID *)((intptr_t)self + 0xec));
      *(uint32_t **)((intptr_t)self + 0xec) = uptr2;
      *(int *)((intptr_t)self + 0xf4) = *(int *)((intptr_t)self + 0xf4) + 0x28;
    }
  }
  value3 = BinarySearch8(self,arg2,'\x01');
  uvalue5 = (*(int *)((intptr_t)self + 0xf0) - value3) * 8;
  if (0 < (intptr_t)uvalue5) {
    _memmove((uint32_t *)(*(int *)((intptr_t)self + 0xe8) + 8 + value3 * 8),
             (uint32_t *)(*(int *)((intptr_t)self + 0xe8) + value3 * 8),uvalue5);
  }
  *(int *)(*(int *)((intptr_t)self + 0xe8) + value3 * 8) = arg1;
  *(int *)(*(int *)((intptr_t)self + 0xe8) + 4 + value3 * 8) = arg2;
  *(int *)(*(int *)((intptr_t)self + 0xec) + *(int *)((intptr_t)self + 0xf0) * 8) = arg1;
  *(int *)(*(int *)((intptr_t)self + 0xec) + 4 + *(int *)((intptr_t)self + 0xf0) * 8) = arg2;
  *(int *)((intptr_t)self + 0xf0) = *(int *)((intptr_t)self + 0xf0) + 1;
  if (*(int *)((intptr_t)self + 0x298) != 0) {
    Array_InsertGrow((void *)(*(int *)((intptr_t)self + 0x298) + 4),*(uint32_t *)(arg1 + 4));
  }
  CS_Leave(*(int *)(*(int *)((intptr_t)self + 0x134) + 0x1c8));
  UI_ClipChildRect(arg1);
  return;
}
