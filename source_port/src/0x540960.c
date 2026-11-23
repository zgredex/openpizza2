// SoundBuffer_Init: ported from Pizza Connection 2 at 0x540960.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x540960
#include "pc2_port.h"


uint32_t * __thiscall SoundBuffer_Init(void *self,int *arg1,int arg2)

{
  uint16_t uvalue1;
  int value2;
  void *unaff_ESI;
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t *local_4;
  
  puStack_8 = &LAB_0055af13;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *(uint32_t *)((intptr_t)self + 4) = 1;
  *(uint8_t ***)self = &PTR_LAB_0055c840;
  *(uint32_t *)((intptr_t)self + 8) = 0;
  *(uint32_t *)((intptr_t)self + 0xc) = 0;
  *(uint32_t *)((intptr_t)self + 0x10) = *(uint32_t *)(arg2 + 0x10);
  *(uint32_t *)((intptr_t)self + 0x14) = *(uint32_t *)(arg2 + 0x14);
  *(uint32_t *)((intptr_t)self + 0x18) = *(uint32_t *)(arg2 + 0x18);
  *(uint32_t *)((intptr_t)self + 0x1c) = *(uint32_t *)(arg2 + 0x1c);
  *(uint32_t *)((intptr_t)self + 0x20) = *(uint32_t *)(arg2 + 0x20);
  *(uint32_t *)((intptr_t)self + 0x24) = *(uint32_t *)(arg2 + 0x24);
  uvalue1 = *(uint16_t *)(arg2 + 0x28);
  *(uint32_t *)((intptr_t)self + 0x2c) = 0;
  *(uint16_t *)((intptr_t)self + 0x28) = uvalue1;
  *(uint32_t *)((intptr_t)self + 0x30) = 0;
  *(uint8_t *)((intptr_t)self + 0x34) = *(uint8_t *)(arg2 + 0x34);
  *(uint32_t *)((intptr_t)self + 0x38) = 0;
  *(uint32_t *)((intptr_t)self + 0x3c) = 0;
  *(uint32_t *)((intptr_t)self + 0x40) = 0;
  *(uint32_t *)((intptr_t)self + 0x44) = 0;
  local_4 = (uint32_t *)0x1;
  *(uint8_t ***)self = &PTR_LAB_0055c874;
  (**(code **)(*arg1 + 8))(arg1);
  value2 = (**(code **)(*arg1 + 0x14))(arg1,*(uint32_t *)(arg2 + 0x48),(intptr_t)self + 0x48);
  if ((-1 < value2) && (local_4 != (uint32_t *)0x0)) {
    *local_4 = 0;
  }
  ExceptionList = unaff_ESI;
  return self;
}
