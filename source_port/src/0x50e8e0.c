// Player_Construct: ported from Pizza Connection 2 at 0x50e8e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50e8e0
#include "pc2_port.h"


uint32_t * __thiscall Player_Construct(void *self,int *arg1)

{
  int value1;
  uint32_t *uptr2;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a35e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  List_Construct((void *)((intptr_t)self + 0x8c),0);
  local_4 = 0;
  *(uint8_t ***)self = &PTR_Player_Delete_0055c684;
  if (arg1 != (int *)0x0) {
    Player_Load(self,arg1);
    ExceptionList = local_c;
    return self;
  }
  *(uint32_t *)((intptr_t)self + 0x84) = 1;
  *(uint32_t *)((intptr_t)self + 0x88) = 1;
  *(uint32_t *)((intptr_t)self + 8) = 0xffffffff;
  *(uint32_t *)((intptr_t)self + 0x3c) = 0;
  *(uint32_t *)((intptr_t)self + 0x40) = 0;
  *(uint32_t *)((intptr_t)self + 0x44) = 0;
  *(uint32_t *)((intptr_t)self + 0x48) = 0;
  *(uint32_t *)((intptr_t)self + 0x4c) = 0;
  *(uint32_t *)((intptr_t)self + 0x50) = 0;
  *(uint32_t *)((intptr_t)self + 0x54) = 0;
  *(uint32_t *)((intptr_t)self + 0x58) = 0;
  *(uint32_t *)((intptr_t)self + 0x5c) = 0;
  *(uint32_t *)((intptr_t)self + 0x60) = 0;
  *(uint32_t *)((intptr_t)self + 100) = 0;
  *(uint32_t *)((intptr_t)self + 0x68) = 0;
  *(uint32_t *)((intptr_t)self + 0x2c) = 0;
  *(uint32_t *)((intptr_t)self + 0x30) = 0;
  uptr2 = (uint32_t *)((intptr_t)self + 0x6c);
  for (value1 = 6; value1 != 0; value1 = value1 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  *(uint32_t *)((intptr_t)self + 0x34) = 0;
  *(uint32_t *)((intptr_t)self + 0x38) = 0;
  *(uint32_t *)((intptr_t)self + 0xa8) = 0;
  *(uint32_t *)((intptr_t)self + 0xac) = 0;
  ExceptionList = local_c;
  return self;
}
