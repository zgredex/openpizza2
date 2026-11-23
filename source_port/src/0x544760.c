// Sound_GetPlayPosition: ported from Pizza Connection 2 at 0x544760.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x544760
#include "pc2_port.h"


int Sound_GetPlayPosition(uint32_t arg1,int *arg2,uint32_t *arg3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int value1;
  int *ptr2;
  uint32_t *uptr3;
  int value4;
  uint32_t uvalue5;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  uvalue5 = arg1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b398;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(arg1 + 0xa0);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  uptr3 = arg3;
  local_4 = 0;
  *arg3 = 0;
  value1 = *(int *)(uvalue5 + 0x98);
  if (value1 < 0) {
    LeaveCriticalSection(lpCriticalSection);
    ExceptionList = local_c;
    return value1;
  }
  if (arg2 == (int *)0x0) {
    LeaveCriticalSection(lpCriticalSection);
    ExceptionList = local_c;
    return -0x7ff8fffa;
  }
  value1 = *arg2;
  ptr2 = *(int **)(value1 + 0x48);
  uvalue5 = 0;
  if (ptr2 != (int *)0x0) {
    value4 = (**(code **)(*ptr2 + 0x10))(ptr2,&arg1,&arg3);
    uvalue5 = arg1 & (value4 < 0) - 1;
  }
  *uptr3 = uvalue5 / *(uint16_t *)(value1 + 0x24);
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = local_c;
  return 0;
}
