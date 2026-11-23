// SoundBuffer_SetVolumeClamped: ported from Pizza Connection 2 at 0x543c00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x543c00
#include "pc2_port.h"


int SoundBuffer_SetVolumeClamped(int arg1,int *arg2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *ptr1;
  uint32_t uvalue2;
  int value3;
  int value4;
  int64_t lvalue5;
  uint32_t local_20;
  uint32_t uStack_1c;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b278;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(arg1 + 0xa0);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  value4 = *(int *)(arg1 + 0x98);
  local_4 = 0;
  if (-1 < value4) {
    if (arg2 == (int *)0x0) {
      LeaveCriticalSection(lpCriticalSection);
      ExceptionList = local_c;
      return -0x7ff8fffa;
    }
    value4 = *arg2;
    lvalue5 = __ftol();
    uvalue2 = (uint32_t)lvalue5;
    ptr1 = *(int **)(value4 + 0x48);
    local_20 = 0x14;
    value3 = (**(code **)(*ptr1 + 0xc))(ptr1,&local_20);
    if ((value3 < 0) || ((uStack_1c & 0xc) != 4)) {
      if ((uvalue2 < 100) || (100000 < uvalue2)) goto LAB_00543ccb;
    }
    else {
      if (uvalue2 < *(uint32_t *)(arg1 + 0x8c)) {
LAB_00543ccb:
        LeaveCriticalSection(lpCriticalSection);
        ExceptionList = local_c;
        return -0x7ff8ffa9;
      }
      if (*(uint32_t *)(arg1 + 0x90) < uvalue2) {
        LeaveCriticalSection(lpCriticalSection);
        ExceptionList = local_c;
        return -0x7ff8ffa9;
      }
    }
    value4 = SoundBuffer_SetVolume(value4);
  }
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = local_c;
  return value4;
}
