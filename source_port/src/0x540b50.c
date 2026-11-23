// SoundBuffer_UnlockSample: ported from Pizza Connection 2 at 0x540b50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x540b50
#include "pc2_port.h"

uint32_t __fastcall SoundBuffer_UnlockSample(int arg1)

{
  int value1;
  uint32_t uvalue2;
  int *ptr3;
  
  uvalue2 = 0;
  if (*(int *)(arg1 + 0x2c) == 0) {
    return 0x8000ffff;
  }
  ptr3 = *(int **)(arg1 + 0x48);
  value1 = (**(code **)(*ptr3 + 0x4c))
                    (ptr3,*(int *)(arg1 + 0x2c),*(uint32_t *)(arg1 + 0x30),0,0);
  if (-1 < value1) {
LAB_00540c5f:
    *(uint32_t *)(arg1 + 0x2c) = 0;
    *(uint32_t *)(arg1 + 0x30) = 0;
    return uvalue2;
  }
  Sound_SetLastError(&DAT_00585578,s_unlocking_sample__00574fc4,value1,ptr3);
  if (value1 < -0x7ffbfeef) {
    if (value1 == -0x7ffbfef0) {
      *(uint32_t *)(arg1 + 0x2c) = 0;
      *(uint32_t *)(arg1 + 0x30) = 0;
      return 0x80040110;
    }
    if (value1 == -0x7fffbfff) {
      *(uint32_t *)(arg1 + 0x2c) = 0;
      *(uint32_t *)(arg1 + 0x30) = 0;
      return 0x80004001;
    }
    if (value1 == -0x7fffbffe) {
      *(uint32_t *)(arg1 + 0x2c) = 0;
      *(uint32_t *)(arg1 + 0x30) = 0;
      return 0x80004002;
    }
    if (value1 == -0x7fffbffb) {
      *(uint32_t *)(arg1 + 0x2c) = 0;
      *(uint32_t *)(arg1 + 0x30) = 0;
      return 0x80004005;
    }
  }
  else {
    if (value1 == -0x7ff8fff2) {
      uvalue2 = 0x8007000e;
      goto LAB_00540c5f;
    }
    if (value1 == -0x7ff8ffa9) {
      *(uint32_t *)(arg1 + 0x2c) = 0;
      *(uint32_t *)(arg1 + 0x30) = 0;
      return 0x80070057;
    }
  }
  *(uint32_t *)(arg1 + 0x2c) = 0;
  *(uint32_t *)(arg1 + 0x30) = 0;
  return 0x8000ffff;
}
