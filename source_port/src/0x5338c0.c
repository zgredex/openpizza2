// RecordList_FindFreeSlot: ported from Pizza Connection 2 at 0x5338c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5338c0
#include "pc2_port.h"

int __thiscall RecordList_FindFreeSlot(void *self,int arg1)

{
  int *ptr1;
  void *pvVar2;
  int value3;
  uint32_t *uptr4;
  uint32_t *uptr5;
  uint32_t uvalue6;
  int value7;
  uint32_t *uptr8;
  
  CS_Enter(0x5842a0);
  if (arg1 == -1) {
    value7 = 0;
    arg1 = 0;
    if (0 < *(int *)((intptr_t)self + 0x48)) {
      ptr1 = *(int **)((intptr_t)self + 0x4c);
      do {
        if (*ptr1 == -1) break;
        value7 = value7 + 1;
        ptr1 = ptr1 + 0x12;
      } while (value7 < *(int *)((intptr_t)self + 0x48));
      arg1 = value7;
    }
  }
  if (*(int *)((intptr_t)self + 0x48) <= arg1) {
    if (*(int *)((intptr_t)self + 0x4c) == 0) {
      value7 = arg1 + 0x14;
      *(int *)((intptr_t)self + 0x48) = arg1;
      pvVar2 = operator_new(value7 * 0x48);
      *(void **)((intptr_t)self + 0x4c) = pvVar2;
      if (0 < value7) {
        value3 = 0;
        do {
          value3 = value3 + 0x48;
          value7 = value7 + -1;
          *(uint32_t *)(*(int *)((intptr_t)self + 0x4c) + -0x48 + value3) = 0xffffffff;
        } while (value7 != 0);
      }
    }
    else {
      value7 = arg1 + 0x14;
      uptr4 = operator_new(value7 * 0x48);
      uptr5 = *(uint32_t **)((intptr_t)self + 0x4c);
      uptr8 = uptr4;
      for (uvalue6 = (uint32_t)(*(int *)((intptr_t)self + 0x48) * 0x48) >> 2; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
        *uptr8 = *uptr5;
        uptr5 = uptr5 + 1;
        uptr8 = uptr8 + 1;
      }
      for (value3 = 0; value3 != 0; value3 = value3 + -1) {
        *(uint8_t *)uptr8 = *(uint8_t *)uptr5;
        uptr5 = (uint32_t *)((intptr_t)uptr5 + 1);
        uptr8 = (uint32_t *)((intptr_t)uptr8 + 1);
      }
      value3 = *(int *)((intptr_t)self + 0x48);
      if (value3 < value7) {
        value7 = value7 - value3;
        uptr5 = uptr4 + value3 * 0x12;
        do {
          *uptr5 = 0xffffffff;
          uptr5 = uptr5 + 0x12;
          value7 = value7 + -1;
        } while (value7 != 0);
      }
      *(int *)((intptr_t)self + 0x48) = arg1;
      Mem_Free(*(LPVOID *)((intptr_t)self + 0x4c));
      *(uint32_t **)((intptr_t)self + 0x4c) = uptr4;
    }
    if (*(int *)((intptr_t)self + 0x4c) == 0) {
      NoOp_Stub();
    }
    *(int *)((intptr_t)self + 0x48) = *(int *)((intptr_t)self + 0x48) + 0x14;
  }
  value3 = arg1 * 0x48;
  uptr5 = (uint32_t *)(*(int *)((intptr_t)self + 0x4c) + value3);
  for (value7 = 0x12; value7 != 0; value7 = value7 + -1) {
    *uptr5 = 0;
    uptr5 = uptr5 + 1;
  }
  *(uint8_t *)(*(int *)((intptr_t)self + 0x4c) + 0x3c + value3) = 0;
  *(uint8_t *)(*(int *)((intptr_t)self + 0x4c) + 0x3e + value3) = 0;
  *(uint8_t *)(*(int *)((intptr_t)self + 0x4c) + 0x38 + value3) = 1;
  value7 = *(int *)((intptr_t)self + 0x4c);
  *(uint32_t *)(value7 + 0x18 + value3) = 0;
  *(uint32_t *)(value7 + 0x1c + value3) = 0;
  value7 = *(int *)((intptr_t)self + 0x4c);
  *(uint32_t *)(value7 + 0x20 + value3) = 0;
  *(uint32_t *)(value7 + 0x24 + value3) = 0;
  value7 = *(int *)((intptr_t)self + 0x4c);
  *(uint32_t *)(value7 + 0x28 + value3) = 0;
  *(uint32_t *)(value7 + 0x2c + value3) = 0x3ff00000;
  *(uint16_t *)(*(int *)((intptr_t)self + 0x4c) + 0x32 + value3) = 0;
  *(uint16_t *)(*(int *)((intptr_t)self + 0x4c) + 0x30 + value3) = 0;
  CS_Leave(0x5842a0);
  return arg1;
}
