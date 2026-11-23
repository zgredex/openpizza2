// Sound_QueryStatusLocked: ported from Pizza Connection 2 at 0x5448c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5448c0
#include "pc2_port.h"


int Sound_QueryStatusLocked(int arg1,int *arg2,uint8_t *arg3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *ptr1;
  uint8_t flag2;
  int value3;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  value3 = arg1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b3b8;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(arg1 + 0xa0);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  value3 = *(int *)(value3 + 0x98);
  local_4 = 0;
  if (value3 < 0) {
    LeaveCriticalSection(lpCriticalSection);
    ExceptionList = local_c;
    return value3;
  }
  if (arg2 == (int *)0x0) {
    LeaveCriticalSection(lpCriticalSection);
    ExceptionList = local_c;
    return -0x7ff8fffa;
  }
  ptr1 = *(int **)(*arg2 + 0x48);
  if (ptr1 == (int *)0x0) {
    flag2 = 0;
  }
  else {
    arg1 = 0;
    value3 = (**(code **)(*ptr1 + 0x24))(ptr1,&arg1);
    if (value3 < 0) {
      flag2 = 0;
    }
    else {
      flag2 = (uint8_t)arg1 & 1;
    }
  }
  *arg3 = flag2;
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = local_c;
  return 0;
}
