// Storage_Construct: ported from Pizza Connection 2 at 0x513c90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x513c90
#include "pc2_port.h"


uint32_t * __thiscall Storage_Construct(void *self,void *arg1)

{
  int value1;
  uint32_t *uptr2;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a4fb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  List_Construct((void *)((intptr_t)self + 0x44),0);
  local_4 = 0;
  *(uint8_t ***)self = &PTR_Storage_Delete_0055c700;
  if (arg1 != (void *)0x0) {
    Storage_LoadRecord(self,arg1);
    ExceptionList = local_c;
    return self;
  }
  *(uint32_t *)((intptr_t)self + 0x24) = 0xffffffff;
  *(uint32_t *)((intptr_t)self + 0x28) = 0xffffffff;
  *(uint32_t *)((intptr_t)self + 0x2c) = 1;
  *(uint32_t *)((intptr_t)self + 0x38) = 0;
  *(uint32_t *)((intptr_t)self + 0x34) = 0;
  *(uint8_t *)((intptr_t)self + 0x3c) = 1;
  *(uint32_t *)((intptr_t)self + 0x40) = 0;
  *(uint32_t *)((intptr_t)self + 0x30) = 0xffffffff;
  uptr2 = (uint32_t *)((intptr_t)self + 0x60);
  for (value1 = 0x3c; value1 != 0; value1 = value1 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  ExceptionList = local_c;
  return self;
}
