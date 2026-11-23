// SoundVoice_Construct: ported from Pizza Connection 2 at 0x541d50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x541d50
#include "pc2_port.h"


uint32_t * __thiscall
SoundVoice_Construct
          (void *self,uint32_t arg1,uint32_t arg2,uint32_t arg3,char *arg4,
          char arg5,uint32_t arg6,int *arg7)

{
  char cVar1;
  char *cptr2;
  DWORD DVar3;
  uint32_t uvalue4;
  uint32_t uvalue5;
  int value6;
  char *cptr7;
  uint32_t *uptr8;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  puStack_8 = &LAB_0055aff3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(uint32_t *)((intptr_t)self + 4) = 1;
  *(uint8_t ***)self = &PTR_LAB_0055c840;
  *(uint32_t *)((intptr_t)self + 8) = 0;
  *(uint32_t *)((intptr_t)self + 0xc) = 0;
  *(uint32_t *)((intptr_t)self + 0x10) = 0;
  local_4 = 0;
  *(uint32_t *)((intptr_t)self + 0x14) = 0;
  *(uint32_t *)((intptr_t)self + 0x18) = 0;
  *(uint32_t *)((intptr_t)self + 0x1c) = 0;
  *(uint32_t *)((intptr_t)self + 0x20) = 0;
  *(uint32_t *)((intptr_t)self + 0x24) = 0;
  *(uint32_t *)((intptr_t)self + 0x34) = arg1;
  *(uint32_t *)((intptr_t)self + 0x28) = 0;
  *(uint32_t *)((intptr_t)self + 0x2c) = 0;
  *(uint32_t *)((intptr_t)self + 0x30) = arg3;
  *(uint32_t *)((intptr_t)self + 0x38) = arg6;
  *(uint8_t *)((intptr_t)self + 0x3c) = 0;
  *(uint32_t *)((intptr_t)self + 0x40) = 0;
  *(uint32_t *)((intptr_t)self + 0x44) = 0;
  *(uint32_t *)((intptr_t)self + 0x48) = 0;
  *(uint32_t *)((intptr_t)self + 0x4c) = 0;
  if ((arg7 == (int *)0x0) || (-1 < *arg7)) {
    uvalue4 = 0xffffffff;
    cptr2 = arg4;
    do {
      if (uvalue4 == 0) break;
      uvalue4 = uvalue4 - 1;
      cVar1 = *cptr2;
      cptr2 = cptr2 + 1;
    } while (cVar1 != '\0');
    cptr2 = operator_new(~uvalue4);
    *(char **)((intptr_t)self + 0x44) = cptr2;
    if (cptr2 == (char *)0x0) {
      if (arg7 != (int *)0x0) {
        *arg7 = -0x7ff8fff2;
      }
    }
    else {
      uvalue4 = 0xffffffff;
      do {
        cptr7 = arg4;
        if (uvalue4 == 0) break;
        uvalue4 = uvalue4 - 1;
        cptr7 = arg4 + 1;
        cVar1 = *arg4;
        arg4 = cptr7;
      } while (cVar1 != '\0');
      uvalue4 = ~uvalue4;
      cptr7 = cptr7 + -uvalue4;
      for (uvalue5 = uvalue4 >> 2; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
        *(uint32_t *)cptr2 = *(uint32_t *)cptr7;
        cptr7 = cptr7 + 4;
        cptr2 = cptr2 + 4;
      }
      for (uvalue4 = uvalue4 & 3; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
        *cptr2 = *cptr7;
        cptr7 = cptr7 + 1;
        cptr2 = cptr2 + 1;
      }
      cptr2 = *(char **)((intptr_t)self + 0x44);
      *(uint32_t *)((intptr_t)self + 0x40) = 1;
      cVar1 = *cptr2;
      while (cVar1 != '\0') {
        if (cVar1 == ',') {
          *(int *)((intptr_t)self + 0x40) = *(int *)((intptr_t)self + 0x40) + 1;
        }
        cptr7 = cptr2 + 1;
        cptr2 = cptr2 + 1;
        cVar1 = *cptr7;
      }
    }
  }
  uptr8 = (uint32_t *)((intptr_t)self + 0x50);
  for (value6 = 8; value6 != 0; value6 = value6 + -1) {
    *uptr8 = 0;
    uptr8 = uptr8 + 1;
  }
  local_4 = CONCAT31(((uint8_t)((local_4) >> 24)),1);
  *(uint8_t *)((intptr_t)self + 0x70) = 0;
  *(uint32_t *)((intptr_t)self + 0x74) = arg2;
  *(uint32_t *)((intptr_t)self + 0x78) = 10000;
  *(uint32_t *)((intptr_t)self + 0x7c) = 0;
  *(uint32_t *)((intptr_t)self + 0x80) = 0x3f800000;
  *(uint32_t *)((intptr_t)self + 0x84) = 0;
  *(uint8_t *)((intptr_t)self + 0x88) = 0;
  *(uint32_t *)((intptr_t)self + 0x8c) = 0;
  DVar3 = timeGetTime();
  *(DWORD *)((intptr_t)self + 0x90) = DVar3;
  *(DWORD *)((intptr_t)self + 0x94) = DVar3;
  *(uint32_t *)((intptr_t)self + 0x98) = 0;
  *(uint32_t *)((intptr_t)self + 0x9c) = 10000;
  *(uint8_t ***)self = &PTR_LAB_0055c8e0;
  *(uint8_t *)((intptr_t)self + 0x55) = 1;
  if (arg5 == '\0') {
    *(uint8_t *)((intptr_t)self + 0x51) = 0;
  }
  else {
    *(uint8_t *)((intptr_t)self + 0x51) = 1;
  }
  if ((arg7 == (int *)0x0) || (-1 < *arg7)) {
    value6 = 0;
    if (arg5 == '\0') {
      value6 = SoundVoice_Open(self);
    }
    else {
      *(uint8_t *)((intptr_t)self + 0x53) = 0;
    }
    if (arg7 != (int *)0x0) {
      *arg7 = value6;
    }
  }
  ExceptionList = local_c;
  return self;
}
