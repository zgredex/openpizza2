// SoundBuffer_Construct: ported from Pizza Connection 2 at 0x546220.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x546220
#include "pc2_port.h"


uint32_t * __thiscall SoundBuffer_Construct(void *self,int *arg1,int arg2,int *arg3)

{
  uint32_t *uptr1;
  uint32_t *uptr2;
  DWORD DVar3;
  int value4;
  int value5;
  uint32_t *uptr6;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b718;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  SoundBuffer_Init(self,arg1,arg2);
  uptr1 = (uint32_t *)((intptr_t)self + 0x5c);
  *(uint32_t *)((intptr_t)self + 0x4c) = 0;
  *(uint32_t *)((intptr_t)self + 0x50) = 0;
  *(uint32_t *)((intptr_t)self + 0x54) = 0;
  *(uint32_t *)((intptr_t)self + 0x58) = 0;
  local_4 = 0;
  *uptr1 = 0;
  *(uint8_t *)((intptr_t)self + 0xa0) = 0;
  *(uint8_t *)((intptr_t)self + 0xa1) = 0;
  DVar3 = timeGetTime();
  *(DWORD *)((intptr_t)self + 0xa4) = DVar3;
  *(DWORD *)((intptr_t)self + 0xa8) = DVar3;
  *(uint8_t ***)self = &PTR_LAB_0055c8c8;
  if (-1 < *arg3) {
    value4 = (**(code **)**(uint32_t **)((intptr_t)self + 0x48))
                      (*(uint32_t **)((intptr_t)self + 0x48),&DAT_0055cb88,uptr1);
    if (value4 < 0) {
      *uptr1 = 0;
    }
    else {
      uptr2 = (uint32_t *)((intptr_t)self + 0x60);
      uptr6 = uptr2;
      for (value5 = 0x10; value5 != 0; value5 = value5 + -1) {
        *uptr6 = 0;
        uptr6 = uptr6 + 1;
      }
      *uptr2 = 0x40;
      (**(code **)(*(int *)*uptr1 + 0xc))((int *)*uptr1,uptr2);
    }
    *(uint32_t *)((intptr_t)self + 0x50) = *(uint32_t *)((intptr_t)self + 0x50) | 3;
    if (arg3 != (int *)0x0) {
      *arg3 = value4;
    }
  }
  ExceptionList = local_c;
  return self;
}
