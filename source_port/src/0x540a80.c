// SoundBuffer_LockSample: ported from Pizza Connection 2 at 0x540a80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x540a80
#include "pc2_port.h"

uint32_t __thiscall SoundBuffer_LockSample(void *self,int arg1,int arg2)

{
  uint32_t *uptr1;
  uint32_t *uptr2;
  int value3;
  int *ptr4;
  int *ptr5;
  uint32_t uvalue6;
  
  uptr1 = (uint32_t *)((intptr_t)self + 0x2c);
  if (*(int *)((intptr_t)self + 0x2c) != 0) {
    return 0;
  }
  if (*(uint32_t *)((intptr_t)self + 0x10) < (uint32_t)(arg2 + arg1)) {
    return 0;
  }
  ptr5 = *(int **)((intptr_t)self + 0x48);
  uptr2 = (uint32_t *)((intptr_t)self + 0x30);
  uvalue6 = 0;
  value3 = (**(code **)(*ptr5 + 0x2c))(ptr5,arg1,arg2,uptr1,uptr2,0,0,0);
  do {
    if (-1 < value3) {
LAB_00540afd:
      return *uptr1;
    }
    if (value3 != -0x7787ff6a) {
      if (value3 < 0) {
        *uptr1 = 0;
        *uptr2 = 0;
        Sound_SetLastError(&DAT_00585578,s_locking_sample__00574f98,value3,ptr5);
        return 0;
      }
      goto LAB_00540afd;
    }
    ptr4 = *(int **)((intptr_t)self + 0x48);
    value3 = (**(code **)(*ptr4 + 0x50))();
    if (value3 < 0) {
      Sound_SetLastError(&DAT_00585578,s_restoring_sample_buffer__00574fa8,value3,ptr4);
      return 0;
    }
    value3 = (**(code **)(**(int **)((intptr_t)self + 0x48) + 0x2c))
                      (*(int **)((intptr_t)self + 0x48),arg1,uvalue6,uptr1,uptr2,0,0,0);
  } while( true );
}
