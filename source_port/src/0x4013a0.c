// List_Construct: ported from Pizza Connection 2 at 0x4013a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4013a0
#include "pc2_port.h"

uint32_t * __thiscall List_Construct(void *self,uint32_t arg1)

{
  void *pvVar1;
  uint32_t *uptr2;
  uint32_t uvalue3;
  int value4;
  
  *(uint8_t ***)self = &PTR_List_Node_Delete_0055c2ec;
  if (arg1 == 0) {
    *(uint32_t *)((intptr_t)self + 4) = 0;
    *(uint32_t *)((intptr_t)self + 8) = 0;
    *(uint32_t *)((intptr_t)self + 0x10) = 0;
    *(uint32_t *)((intptr_t)self + 0xc) = 0;
    *(uint32_t *)((intptr_t)self + 0x14) = 0;
    *(uint32_t *)((intptr_t)self + 0x18) = 100000;
    return self;
  }
  pvVar1 = operator_new(arg1 * 4);
  *(void **)((intptr_t)self + 4) = pvVar1;
  uptr2 = operator_new(arg1 * 4);
  uvalue3 = arg1 & 0x3fffffff;
  *(uint32_t **)((intptr_t)self + 8) = uptr2;
  for (; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  for (value4 = 0; value4 != 0; value4 = value4 + -1) {
    *(uint8_t *)uptr2 = 0;
    uptr2 = (uint32_t *)((intptr_t)uptr2 + 1);
  }
  *(uint32_t *)((intptr_t)self + 0xc) = 0;
  *(uint32_t *)((intptr_t)self + 0x14) = 0;
  *(uint32_t *)((intptr_t)self + 0x10) = arg1;
  *(uint32_t *)((intptr_t)self + 0x18) = 100000;
  return self;
}
