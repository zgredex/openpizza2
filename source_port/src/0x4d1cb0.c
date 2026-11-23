// MapObject_Construct: ported from Pizza Connection 2 at 0x4d1cb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d1cb0
#include "pc2_port.h"


uint32_t * __thiscall MapObject_Construct(void *self,void *arg1)

{
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558d16;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  List_Construct((void *)((intptr_t)self + 0x58),0);
  local_4 = 0;
  List_Construct((void *)((intptr_t)self + 0x78),0);
  local_4 = CONCAT31(((uint8_t)((local_4) >> 24)),1);
  *(uint8_t ***)self = &PTR_MapObject_Delete_0055c4ec;
  if (arg1 == (void *)0x0) {
    *(uint32_t *)((intptr_t)self + 4) = 0xffffffff;
    *(uint32_t *)((intptr_t)self + 8) = 0xffffffff;
    SetRect((LPRECT)((intptr_t)self + 0x10),0,0,0,0);
    *(uint32_t *)((intptr_t)self + 0x20) = 0xffffffff;
    *(uint32_t *)((intptr_t)self + 0x24) = 0xffffffff;
    *(uint32_t *)((intptr_t)self + 0x28) = 0xffffffff;
    *(uint32_t *)((intptr_t)self + 0x54) = 0xffffffff;
    *(uint32_t *)((intptr_t)self + 0x2c) = 0xffffffff;
    *(uint32_t *)((intptr_t)self + 0x48) = 0xffffffff;
    *(uint32_t *)((intptr_t)self + 0xc) = 0xffffffff;
    *(uint32_t *)((intptr_t)self + 0x30) = 0xffffffff;
    *(uint32_t *)((intptr_t)self + 0x34) = 0xffffffff;
    *(uint32_t *)((intptr_t)self + 0x4c) = 0;
    *(uint32_t *)((intptr_t)self + 0x50) = 0;
    *(uint32_t *)((intptr_t)self + 0x74) = 0;
    *(uint32_t *)((intptr_t)self + 0x38) = 0;
    *(uint32_t *)((intptr_t)self + 0x40) = 0;
    *(uint32_t *)((intptr_t)self + 0x44) = 0;
    *(uint32_t *)((intptr_t)self + 0x3c) = 0;
    *(uint32_t *)((intptr_t)self + 0x94) = 0;
    ExceptionList = local_c;
    return self;
  }
  MapObject_Load(self,arg1);
  ExceptionList = local_c;
  return self;
}
