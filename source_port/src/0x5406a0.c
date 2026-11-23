// SoundBuffer_CreateDSBuffer: ported from Pizza Connection 2 at 0x5406a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5406a0
#include "pc2_port.h"


uint32_t * __thiscall
SoundBuffer_CreateDSBuffer
          (void *self,int *arg1,uint32_t *arg2,uint32_t arg3,uint32_t *arg4)

{
  uint16_t uvalue1;
  int value2;
  int *unaff_retaddr;
  void *local_24;
  uint32_t uStack_20;
  uint32_t uStack_1c;
  uint32_t uStack_18;
  uint32_t *puStack_14;
  void *pvStack_10;
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  puStack_8 = &LAB_0055aed3;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *(uint32_t *)((intptr_t)self + 4) = 1;
  *(uint8_t ***)self = &PTR_LAB_0055c840;
  *(uint32_t *)((intptr_t)self + 8) = 0;
  *(uint32_t *)((intptr_t)self + 0xc) = 0;
  *(uint32_t *)((intptr_t)self + 0x10) = arg3;
  *(uint32_t *)((intptr_t)self + 0x14) = arg2[1];
  *(uint32_t *)((intptr_t)self + 0x18) = *arg2;
  *(uint32_t *)((intptr_t)self + 0x1c) = arg2[1];
  *(uint32_t *)((intptr_t)self + 0x20) = arg2[2];
  *(uint32_t *)((intptr_t)self + 0x24) = arg2[3];
  uvalue1 = *(uint16_t *)(arg2 + 4);
  *(uint32_t *)((intptr_t)self + 0x2c) = 0;
  *(uint16_t *)((intptr_t)self + 0x28) = uvalue1;
  *(uint32_t *)((intptr_t)self + 0x30) = 0;
  *(uint8_t *)((intptr_t)self + 0x34) = (uint8_t)((uint32_t)arg4 >> 1) & 1;
  *(uint32_t *)((intptr_t)self + 0x38) = 0;
  *(uint32_t *)((intptr_t)self + 0x3c) = 0;
  *(uint32_t *)((intptr_t)self + 0x40) = 0;
  *(uint32_t *)((intptr_t)self + 0x44) = 0;
  *(uint8_t ***)self = &PTR_LAB_0055c874;
  local_4 = 1;
  local_24 = self;
  (**(code **)(*arg1 + 8))();
  local_24 = (void *)0x14;
  uStack_1c = arg3;
  uStack_18 = 0;
  puStack_14 = arg2;
  if (((uint32_t)arg4 & 0x10) == 0) {
    uStack_20 = (uint32_t)arg4 | 0x80c0;
  }
  else {
    uStack_20 = (uint32_t)arg4 | 0x28080;
  }
  do {
    value2 = (**(code **)(*unaff_retaddr + 0xc))
                      (unaff_retaddr,&local_24,(uint32_t *)((intptr_t)self + 0x48),0);
    if (-1 < value2) {
LAB_00540863:
      if (arg4 != (uint32_t *)0x0) {
        *arg4 = arg2;
      }
      ExceptionList = pvStack_10;
      return self;
    }
    if (((uStack_20 & 4) == 0) ||
       ((((value2 != -0x7787fff6 && (value2 != -0x7ff8fff2)) && (value2 != -0x7787ffce)) &&
        (value2 != -0x7787ffe2)))) {
      Sound_SetLastError(&DAT_00585578,s_creating_sound_buffer__00574f80,value2,arg1);
      if (value2 < -0x7ffbfeef) {
        if (value2 == -0x7ffbfef0) {
          arg2 = (uint32_t *)0x80040110;
        }
        else if (value2 == -0x7fffbfff) {
          arg2 = (uint32_t *)0x80004001;
        }
        else if (value2 == -0x7fffbffe) {
          arg2 = (uint32_t *)0x80004002;
        }
        else {
          if (value2 != -0x7fffbffb) goto LAB_00540841;
          arg2 = (uint32_t *)0x80004005;
        }
      }
      else if (value2 == -0x7ff8fff2) {
        arg2 = (uint32_t *)0x8007000e;
      }
      else if (value2 == -0x7ff8ffa9) {
        arg2 = (uint32_t *)0x80070057;
      }
      else {
LAB_00540841:
        arg2 = (uint32_t *)0x8000ffff;
      }
      *(uint32_t *)((intptr_t)self + 0x48) = 0;
      goto LAB_00540863;
    }
    uStack_20 = uStack_20 & 0xfffffffb | 8;
  } while( true );
}
