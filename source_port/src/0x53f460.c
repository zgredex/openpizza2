// SoundSample_Construct: ported from Pizza Connection 2 at 0x53f460.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53f460
#include "pc2_port.h"


uint32_t * __thiscall SoundSample_Construct(void *self,void *arg1,char *arg2,int *arg3)

{
  char cVar1;
  char *cptr2;
  int *ptr3;
  int value4;
  uint32_t uvalue5;
  uint32_t uvalue6;
  char *cptr7;
  char *cptr8;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  puStack_8 = &LAB_0055ae28;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(uint32_t *)((intptr_t)self + 4) = 1;
  *(void **)((intptr_t)self + 8) = arg1;
  local_4 = 0;
  *(uint32_t *)((intptr_t)self + 0xc) = 0;
  *(uint32_t *)((intptr_t)self + 0x10) = 0;
  *(uint32_t *)((intptr_t)self + 0x28) = 0;
  *(uint32_t *)((intptr_t)self + 0x2c) = 0;
  *(uint32_t *)((intptr_t)self + 0x30) = 0;
  *(uint8_t *)((intptr_t)self + 0x34) = 0;
  *(uint32_t *)((intptr_t)self + 0x38) = 0;
  *(uint32_t *)((intptr_t)self + 0x3c) = 0;
  *(uint8_t *)((intptr_t)self + 0x48) = 0;
  *(uint8_t ***)self = &PTR_LAB_0055c850;
  if (arg3 != (int *)0x0) {
    *arg3 = 0;
  }
  uvalue5 = 0xffffffff;
  cptr2 = arg2;
  do {
    if (uvalue5 == 0) break;
    uvalue5 = uvalue5 - 1;
    cVar1 = *cptr2;
    cptr2 = cptr2 + 1;
  } while (cVar1 != '\0');
  cptr2 = operator_new(~uvalue5);
  *(char **)((intptr_t)self + 0x10) = cptr2;
  if (cptr2 == (char *)0x0) {
    if (arg3 != (int *)0x0) {
      *arg3 = -0x7ff8fff2;
    }
  }
  else {
    uvalue5 = 0xffffffff;
    cptr7 = arg2;
    do {
      cptr8 = cptr7;
      if (uvalue5 == 0) break;
      uvalue5 = uvalue5 - 1;
      cptr8 = cptr7 + 1;
      cVar1 = *cptr7;
      cptr7 = cptr8;
    } while (cVar1 != '\0');
    uvalue5 = ~uvalue5;
    cptr7 = cptr8 + -uvalue5;
    for (uvalue6 = uvalue5 >> 2; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
      *(uint32_t *)cptr2 = *(uint32_t *)cptr7;
      cptr7 = cptr7 + 4;
      cptr2 = cptr2 + 4;
    }
    for (uvalue5 = uvalue5 & 3; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
      *cptr2 = *cptr7;
      cptr7 = cptr7 + 1;
      cptr2 = cptr2 + 1;
    }
    ptr3 = SoundPakManager_OpenStream(arg1,arg2);
    *(int **)((intptr_t)self + 0xc) = ptr3;
    if (ptr3 == (int *)0x0) {
      NoOp_Stub();
      if (arg3 != (int *)0x0) {
        *arg3 = -0x7fffbffb;
      }
    }
    else {
      value4 = SoundSample_ParseWavFormat((intptr_t)self);
      if (value4 < 0) {
        if (value4 == -0x7fffbffb) {
          NoOp_Stub();
        }
        if (arg3 != (int *)0x0) {
          *arg3 = value4;
        }
      }
      else {
        SoundBuffer_SeekSample(self,0);
      }
    }
  }
  ExceptionList = local_c;
  return self;
}
