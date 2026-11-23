// SoundSample_ReadPCM: ported from Pizza Connection 2 at 0x53f650.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53f650
#include "pc2_port.h"

int __thiscall SoundSample_ReadPCM(void *self,char *arg1,uint32_t arg2)

{
  bool flag1;
  int value2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  int local_8;
  int local_4;
  
  if (*(short *)((intptr_t)self + 0x14) != 1) {
    value2 = SoundSample_ReadADPCM(self,(uint32_t *)arg1,arg2);
    return value2;
  }
  uvalue3 = 0;
  local_8 = 0;
  if (*(int *)((intptr_t)self + 0xc) == 0) {
    return -0x7ff8fffa;
  }
  local_4 = 0;
  do {
    flag1 = *(uint32_t *)((intptr_t)self + 0x28) < *(int *)((intptr_t)self + 0x30) + arg2;
    if (flag1) {
      uvalue4 = *(uint32_t *)((intptr_t)self + 0x28) - *(int *)((intptr_t)self + 0x30);
    }
    else {
      uvalue4 = arg2;
    }
    if (uvalue4 != 0) {
      uvalue3 = SoundPakStream_Read(*(void **)((intptr_t)self + 8),arg1,uvalue4,*(int *)((intptr_t)self + 0xc))
      ;
      arg2 = arg2 - uvalue3;
      arg1 = arg1 + uvalue3;
      *(uint32_t *)((intptr_t)self + 0x30) = *(int *)((intptr_t)self + 0x30) + uvalue3;
    }
    if (flag1) {
      if (*(char *)((intptr_t)self + 0x34) == '\0') {
        for (uvalue3 = arg2 >> 2; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
          arg1[0] = '\0';
          arg1[1] = '\0';
          arg1[2] = '\0';
          arg1[3] = '\0';
          arg1 = arg1 + 4;
        }
        local_8 = 1;
        for (uvalue3 = arg2 & 3; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
          *arg1 = '\0';
          arg1 = arg1 + 1;
        }
LAB_0053f767:
        if (1 < local_4) {
          local_8 = 1;
        }
        return local_8;
      }
      local_8 = SoundBuffer_SeekSample(self,0);
      if (local_8 < 0) goto LAB_0053f767;
    }
    if (uvalue3 < uvalue4) {
      NoOp_Stub();
      local_8 = -0x7fffbffb;
      goto LAB_0053f767;
    }
    local_4 = local_4 + 1;
    if (!flag1) goto LAB_0053f767;
  } while( true );
}
