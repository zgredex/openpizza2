// Sound_StopStreamVoice: ported from Pizza Connection 2 at 0x546300.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x546300
#include "pc2_port.h"

int Sound_StopStreamVoice(int arg1,int *arg2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LPCRITICAL_SECTION lpCriticalSection_00;
  uint32_t *uptr1;
  int value2;
  int value3;
  LPVOID pvVar4;
  void *local_c;
  uint8_t *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b740;
  local_c = ExceptionList;
  lpCriticalSection_00 = (LPCRITICAL_SECTION)(arg1 + 0xa0);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection_00);
  value3 = *(int *)(arg1 + 0x98);
  local_4 = 0;
  if (value3 < 0) {
    LeaveCriticalSection(lpCriticalSection_00);
  }
  else if (arg2 == (int *)0x0) {
    LeaveCriticalSection(lpCriticalSection_00);
    value3 = -0x7ff8fffa;
  }
  else {
    value3 = *arg2;
    if ((*(int *)(value3 + 8) != 0) &&
       (uptr1 = *(uint32_t **)(value3 + 0xc), uptr1 != (uint32_t *)0x0)) {
      value2 = *(int *)(value3 + 8);
      lpCriticalSection = (LPCRITICAL_SECTION)(value2 + 0x18);
      EnterCriticalSection(lpCriticalSection);
      local_4 = (local_4 & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
      if (uptr1 != (uint32_t *)0x0) {
        (**(code **)(*(int *)*uptr1 + 4))((int *)*uptr1);
        pvVar4 = (LPVOID)List_Remove((void *)(value2 + 8),(intptr_t)uptr1);
        Mem_Free(pvVar4);
      }
      local_4 = (uint32_t)((uint8_t)((local_4) >> 24)) << 8;
      LeaveCriticalSection(lpCriticalSection);
      *(uint32_t *)(value3 + 8) = 0;
      *(uint32_t *)(value3 + 0xc) = 0;
    }
    (**(code **)(*(int *)*arg2 + 4))((int *)*arg2);
    if (*(int **)(arg1 + 0x5c) == arg2) {
      *(int *)(arg1 + 0x5c) = (*(int **)(arg1 + 0x5c))[1];
    }
    if (arg2[2] == 0) {
      *(int *)(arg1 + 0x54) = arg2[1];
    }
    else {
      *(int *)(arg2[2] + 4) = arg2[1];
    }
    if (arg2 == *(int **)(arg1 + 0x58)) {
      *(int *)(arg1 + 0x58) = arg2[2];
    }
    if (arg2[1] != 0) {
      *(int *)(arg2[1] + 8) = arg2[2];
    }
    *(int *)(arg1 + 0x60) = *(int *)(arg1 + 0x60) + -1;
    Mem_Free(arg2);
    LeaveCriticalSection(lpCriticalSection_00);
    value3 = 0;
  }
  ExceptionList = local_c;
  return value3;
}
