// List_Add: ported from Pizza Connection 2 at 0x4014b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4014b0
#include "pc2_port.h"

int __thiscall List_Add(void *self,uint32_t arg1)

{
  void *pvVar1;
  uint32_t *uptr2;
  uint32_t *uptr3;
  uint32_t uvalue4;
  int value5;
  uint32_t *uptr6;
  uint32_t *uptr7;
  
  CS_Enter(0x579af0);
  if (*(int *)((intptr_t)self + 0x10) <= *(int *)((intptr_t)self + 0xc)) {
    if (*(int *)((intptr_t)self + 4) == 0) {
      pvVar1 = operator_new(0x50);
      *(void **)((intptr_t)self + 4) = pvVar1;
      pvVar1 = operator_new(0x50);
      *(void **)((intptr_t)self + 8) = pvVar1;
    }
    else {
      uptr2 = operator_new(*(int *)((intptr_t)self + 0x10) * 4 + 0x50);
      uptr6 = *(uint32_t **)((intptr_t)self + 4);
      uptr7 = uptr2;
      for (uvalue4 = *(uint32_t *)((intptr_t)self + 0x10) & 0x3fffffff; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
        *uptr7 = *uptr6;
        uptr6 = uptr6 + 1;
        uptr7 = uptr7 + 1;
      }
      for (value5 = 0; value5 != 0; value5 = value5 + -1) {
        *(uint8_t *)uptr7 = *(uint8_t *)uptr6;
        uptr6 = (uint32_t *)((intptr_t)uptr6 + 1);
        uptr7 = (uint32_t *)((intptr_t)uptr7 + 1);
      }
      uptr3 = operator_new(*(int *)((intptr_t)self + 0x10) * 4 + 0x50);
      uptr6 = *(uint32_t **)((intptr_t)self + 8);
      uptr7 = uptr3;
      for (uvalue4 = *(uint32_t *)((intptr_t)self + 0x10) & 0x3fffffff; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
        *uptr7 = *uptr6;
        uptr6 = uptr6 + 1;
        uptr7 = uptr7 + 1;
      }
      for (value5 = 0; value5 != 0; value5 = value5 + -1) {
        *(uint8_t *)uptr7 = *(uint8_t *)uptr6;
        uptr6 = (uint32_t *)((intptr_t)uptr6 + 1);
        uptr7 = (uint32_t *)((intptr_t)uptr7 + 1);
      }
      Mem_Free(*(LPVOID *)((intptr_t)self + 4));
      *(uint32_t **)((intptr_t)self + 4) = uptr2;
      Mem_Free(*(LPVOID *)((intptr_t)self + 8));
      *(uint32_t **)((intptr_t)self + 8) = uptr3;
    }
    *(int *)((intptr_t)self + 0x10) = *(int *)((intptr_t)self + 0x10) + 0x14;
  }
  *(uint32_t *)(*(int *)((intptr_t)self + 4) + *(int *)((intptr_t)self + 0xc) * 4) = arg1;
  *(uint32_t *)(*(int *)((intptr_t)self + 8) + *(int *)((intptr_t)self + 0xc) * 4) =
       *(uint32_t *)((intptr_t)self + 0x18);
  *(int *)((intptr_t)self + 0x18) = *(int *)((intptr_t)self + 0x18) + 1;
  *(int *)((intptr_t)self + 0xc) = *(int *)((intptr_t)self + 0xc) + 1;
  *(int *)((intptr_t)self + 0x14) = *(int *)((intptr_t)self + 0x14) + 1;
  CS_Leave(0x579af0);
  return *(int *)((intptr_t)self + 0x18) + -1;
}
