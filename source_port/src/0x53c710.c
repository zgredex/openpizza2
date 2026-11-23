// Sprite_CreateRaw: ported from Pizza Connection 2 at 0x53c710.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53c710
#include "pc2_port.h"


uint32_t * __thiscall
Sprite_CreateRaw(void *self,uint32_t arg1,int arg2,uint32_t arg3,int arg4,
                uint8_t arg5)

{
  uint32_t uvalue1;
  void *pvVar2;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055ad58;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  SpriteBase_Construct(self);
  *(uint8_t ***)self = &PTR_Sprite_ScalarDeletingDestructor_0055c82c;
  local_4 = 0;
  *(uint8_t *)((intptr_t)self + 0x38) = 0;
  *(uint8_t *)((intptr_t)self + 0x39) = 1;
  *(uint32_t *)((intptr_t)self + 0x3c) = 0;
  Sprite_InitFormat(self,(short)arg1,(short)arg2,arg3,arg4,2,0,0);
  uvalue1 = (arg1 * arg2 + (arg1 & 1)) * (arg4 >> 3);
  *(uint32_t *)((intptr_t)self + 0x20) = 0;
  *(uint32_t *)((intptr_t)self + 0x24) = 0;
  *(uint8_t *)((intptr_t)self + 0x34) = 1;
  *(uint16_t *)((intptr_t)self + 0xe) = 0;
  *(uint16_t *)((intptr_t)self + 0x10) = 0;
  *(uint8_t *)((intptr_t)self + 4) = arg5;
  *(uint32_t *)((intptr_t)self + 0x30) = 0;
  *(uint32_t *)((intptr_t)self + 0x18) = uvalue1;
  pvVar2 = operator_new(uvalue1);
  *(void **)((intptr_t)self + 0x2c) = pvVar2;
  *(uint32_t *)((intptr_t)self + 0x28) = 0;
  *(uint8_t *)((intptr_t)self + 0x36) = 0xff;
  ExceptionList = local_c;
  return self;
}
