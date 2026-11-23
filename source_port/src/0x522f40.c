// Array_InsertGrow: ported from Pizza Connection 2 at 0x522f40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x522f40
#include "pc2_port.h"

int __thiscall Array_InsertGrow(void *self,uint32_t arg1)

{
  void *pvVar1;
  uint32_t *uptr2;
  uint32_t uvalue3;
  int value4;
  uint32_t *uptr5;
  uint32_t *uptr6;
  
  CS_Enter(0x584180);
  if (*(int *)((intptr_t)self + 0xc) <= *(int *)((intptr_t)self + 8)) {
    if (*(int *)((intptr_t)self + 4) == 0) {
      pvVar1 = operator_new(0x50);
      *(void **)((intptr_t)self + 4) = pvVar1;
    }
    else {
      uptr2 = operator_new(*(int *)((intptr_t)self + 0xc) * 4 + 0x50);
      uptr5 = *(uint32_t **)((intptr_t)self + 4);
      uptr6 = uptr2;
      for (uvalue3 = *(uint32_t *)((intptr_t)self + 0xc) & 0x3fffffff; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
        *uptr6 = *uptr5;
        uptr5 = uptr5 + 1;
        uptr6 = uptr6 + 1;
      }
      for (value4 = 0; value4 != 0; value4 = value4 + -1) {
        *(uint8_t *)uptr6 = *(uint8_t *)uptr5;
        uptr5 = (uint32_t *)((intptr_t)uptr5 + 1);
        uptr6 = (uint32_t *)((intptr_t)uptr6 + 1);
      }
      Mem_Free(*(LPVOID *)((intptr_t)self + 4));
      *(uint32_t **)((intptr_t)self + 4) = uptr2;
    }
    *(int *)((intptr_t)self + 0xc) = *(int *)((intptr_t)self + 0xc) + 0x14;
  }
  *(uint32_t *)(*(int *)((intptr_t)self + 4) + *(int *)((intptr_t)self + 8) * 4) = arg1;
  *(int *)((intptr_t)self + 8) = *(int *)((intptr_t)self + 8) + 1;
  *(int *)((intptr_t)self + 0x10) = *(int *)((intptr_t)self + 0x10) + 1;
  CS_Leave(0x584180);
  return *(int *)((intptr_t)self + 8) + -1;
}
