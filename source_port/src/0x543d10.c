// SoundBuffer_CommitVolume: ported from Pizza Connection 2 at 0x543d10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x543d10
#include "pc2_port.h"

int SoundBuffer_CommitVolume(int arg1,int *arg2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LPCRITICAL_SECTION lpCriticalSection_00;
  uint32_t uvalue1;
  int value2;
  uint32_t uvalue3;
  int value4;
  code *cptr5;
  uint32_t unaff_EBP;
  code *cptr6;
  int64_t lvalue7;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  cptr5 = EnterCriticalSection_exref;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b2a8;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(arg1 + 0xa0);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  value4 = *(int *)(arg1 + 0x98);
  local_4 = 0;
  if (value4 < 0) {
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    if (arg2 == (int *)0x0) {
      LeaveCriticalSection(lpCriticalSection);
      ExceptionList = local_c;
      return -0x7ff8fffa;
    }
    value4 = *arg2;
    lpCriticalSection_00 = *(LPCRITICAL_SECTION *)(value4 + 0x38);
    EnterCriticalSection(lpCriticalSection_00);
    cptr6 = LeaveCriticalSection_exref;
    local_4 = CONCAT31(((uint8_t)((local_4) >> 24)),1);
    if (*(char *)(value4 + 0x53) == '\0') {
      LeaveCriticalSection(lpCriticalSection_00);
    }
    else {
      value2 = Sound_QueryFormatType(*(int *)(value4 + 0x28));
      cptr6 = LeaveCriticalSection_exref;
      local_4 = local_4 & 0xffffff00;
      LeaveCriticalSection(lpCriticalSection_00);
      lvalue7 = __ftol();
      uvalue3 = (uint32_t)lvalue7;
      if (value2 == 4) {
        if (uvalue3 < *(uint32_t *)(arg1 + 0x8c)) {
LAB_00543e13:
          LeaveCriticalSection(lpCriticalSection);
          ExceptionList = local_c;
          return -0x7ff8ffa9;
        }
        if (*(uint32_t *)(arg1 + 0x90) < uvalue3) {
          LeaveCriticalSection(lpCriticalSection);
          ExceptionList = local_c;
          return -0x7ff8ffa9;
        }
      }
      else if ((uvalue3 < 100) || (100000 < uvalue3)) goto LAB_00543e13;
      cptr5 = EnterCriticalSection_exref;
    }
    uvalue1 = *(uint32_t *)(value4 + 0x38);
    (*cptr5)(uvalue1);
    puStack_8 = (uint8_t *)CONCAT31(((uint8_t)(((intptr_t)puStack_8) >> 24)),2);
    *(uint32_t *)(value4 + 0x80) = uvalue1;
    if (*(char *)(value4 + 0x53) == '\0') {
      (*cptr6)(uvalue1);
      value4 = 0;
    }
    else {
      value4 = SoundBuffer_SetVolume(*(int *)(value4 + 0x28));
      (*cptr6)(uvalue1);
    }
    SetEvent(*(HANDLE *)(local_4 + 0x48));
    (*cptr6)(unaff_EBP);
  }
  ExceptionList = local_c;
  return value4;
}
