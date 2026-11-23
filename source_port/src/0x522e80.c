// Array_Construct: ported from Pizza Connection 2 at 0x522e80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x522e80
#include "pc2_port.h"

uint32_t * __thiscall Array_Construct(void *self,int arg1)

{
  void *pvVar1;
  
  *(uint8_t ***)self = &PTR_Array_Delete_0055c774;
  if (arg1 == 0) {
    *(uint32_t *)((intptr_t)self + 4) = 0;
    *(uint32_t *)((intptr_t)self + 0xc) = 0;
    *(uint32_t *)((intptr_t)self + 8) = 0;
    *(uint32_t *)((intptr_t)self + 0x10) = 0;
    return self;
  }
  pvVar1 = operator_new(arg1 * 4);
  *(void **)((intptr_t)self + 4) = pvVar1;
  *(int *)((intptr_t)self + 0xc) = arg1;
  *(uint32_t *)((intptr_t)self + 8) = 0;
  *(uint32_t *)((intptr_t)self + 0x10) = 0;
  return self;
}
