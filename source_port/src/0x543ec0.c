// SoundStream_ScheduleRefill: ported from Pizza Connection 2 at 0x543ec0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x543ec0
#include "pc2_port.h"

int SoundStream_ScheduleRefill(int arg1,int *arg2,uint32_t arg3,char arg4)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LPCRITICAL_SECTION lpCriticalSection_00;
  uint32_t uvalue1;
  DWORD DVar2;
  uint32_t uvalue3;
  code *cptr4;
  int value5;
  uint64_t uvalue6;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b2d0;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(arg1 + 0xa0);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  value5 = *(int *)(arg1 + 0x98);
  local_4 = 0;
  if (value5 < 0) {
    LeaveCriticalSection(lpCriticalSection);
    ExceptionList = local_c;
    return value5;
  }
  if (arg2 == (int *)0x0) {
    LeaveCriticalSection(lpCriticalSection);
    ExceptionList = local_c;
    return -0x7ff8fffa;
  }
  value5 = *arg2;
  lpCriticalSection_00 = *(LPCRITICAL_SECTION *)(value5 + 0x38);
  EnterCriticalSection(lpCriticalSection_00);
  local_4 = CONCAT31(((uint8_t)((local_4) >> 24)),1);
  if (arg4 != '\0') {
    if (*(char *)(value5 + 0x53) != '\0') {
      Sound_SetBufferVolume(*(void **)(value5 + 0x28),0);
    }
    *(uint32_t *)(value5 + 0x9c) = 0;
  }
  cptr4 = LeaveCriticalSection_exref;
  if (*(uint32_t *)(value5 + 0x9c) < *(uint32_t *)(value5 + 0x78)) {
    uvalue1 = *(uint32_t *)(value5 + 0x78) - *(uint32_t *)(value5 + 0x9c);
    *(uint32_t *)(value5 + 0x8c) = 1;
    uvalue3 = (intptr_t)uvalue1 >> 0x1f;
    uvalue1 = (intptr_t)((uvalue1 ^ uvalue3) - uvalue3) / 100;
    if (uvalue1 == 0) {
      *(uint32_t *)(value5 + 0x98) = 1;
    }
    else {
      uvalue6 = __ftol();
      *(int *)(value5 + 0x98) = (intptr_t)((uvalue6 & 0xffffffff) / (uint64_t)uvalue1);
    }
    DVar2 = timeGetTime();
    *(DWORD *)(value5 + 0x90) = DVar2;
    *(DWORD *)(value5 + 0x94) = DVar2;
    cptr4 = LeaveCriticalSection_exref;
    LeaveCriticalSection(lpCriticalSection_00);
    value5 = 0;
  }
  else {
    LeaveCriticalSection(lpCriticalSection_00);
    value5 = 1;
  }
  SetEvent(*(HANDLE *)(arg1 + 0x48));
  (*cptr4)(lpCriticalSection);
  ExceptionList = lpCriticalSection;
  return value5;
}
