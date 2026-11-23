// SoundStreamBuffer_Construct: ported from Pizza Connection 2 at 0x541520.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x541520
#include "pc2_port.h"


uint32_t * __thiscall
SoundStreamBuffer_Construct
          (void *self,int *arg1,uint32_t *arg2,uint32_t arg3,uint32_t arg4,uint32_t *arg5
          )

{
  uint32_t *uptr1;
  uint32_t *uptr2;
  DWORD DVar3;
  uint32_t uvalue4;
  int value5;
  uint32_t *uptr6;
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055af30;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  SoundBuffer_CreateDSBuffer(self,arg1,arg2,arg3,(uint32_t *)(arg4 | 0x14));
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
  if (-1 < (intptr_t)*arg5) {
    uvalue4 = (**(code **)**(uint32_t **)((intptr_t)self + 0x48))
                      (*(uint32_t **)((intptr_t)self + 0x48),&DAT_0055cb88,uptr1);
    if ((intptr_t)uvalue4 < 0) {
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
    if (arg5 != (uint32_t *)0x0) {
      *arg5 = uvalue4;
    }
  }
  *(uint32_t *)((intptr_t)self + 0xb0) = 0;
  *(uint8_t ***)self = &PTR_LAB_0055c8b0;
  local_4 = 1;
  *(uint32_t *)((intptr_t)self + 0xac) = 0;
  if (-1 < (intptr_t)*arg5) {
    uvalue4 = (*(code *)**(uint32_t **)*uptr1)
                      ((uint32_t *)*uptr1,&DAT_0055cb78,(uint32_t *)((intptr_t)self + 0xac));
    if (-1 < (intptr_t)uvalue4) {
      uvalue4 = Sound_QueryFormatFlags((intptr_t)self);
    }
    if (arg5 != (uint32_t *)0x0) {
      *arg5 = uvalue4;
    }
  }
  ExceptionList = pvStack_c;
  return self;
}
