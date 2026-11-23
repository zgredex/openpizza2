// Sound_SetAllVoicesVolume: ported from Pizza Connection 2 at 0x544300.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x544300
#include "pc2_port.h"

uint32_t Sound_SetAllVoicesVolume(uint32_t arg1,int *arg2,int arg3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int value1;
  int *ptr2;
  int value3;
  int value4;
  LPCRITICAL_SECTION lpCriticalSection_00;
  uint32_t uvalue5;
  uint32_t uvalue6;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b338;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(arg1 + 0xa0);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  uvalue5 = *(uint32_t *)(arg1 + 0x98);
  local_4 = 0;
  if ((intptr_t)uvalue5 < 0) {
    LeaveCriticalSection(lpCriticalSection);
    arg1 = uvalue5;
  }
  else if (arg2 == (int *)0x0) {
    LeaveCriticalSection(lpCriticalSection);
    arg1 = 0x80070006;
  }
  else {
    value1 = *arg2;
    uvalue5 = (uint32_t)(arg3 * 10000) / *(uint32_t *)(arg1 + 0x84);
    EnterCriticalSection((LPCRITICAL_SECTION)(value1 + 0x18));
    local_4 = (local_4 & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
    arg1 = 0;
    *(uint32_t *)(value1 + 0x10) = *(uint32_t *)(value1 + 8);
LAB_005443a6:
    ptr2 = *(int **)(value1 + 0x10);
    if (ptr2 != (int *)0x0) {
      *(int *)(value1 + 0x10) = ptr2[1];
      value3 = *ptr2;
      value4 = *(int *)(value3 + 0xc);
      if ((value4 != 0) && (value4 != 1)) goto code_r0x005443c4;
      uvalue6 = Sound_SetBufferVolume(*(void **)(value3 + 8),uvalue5);
      goto LAB_00544429;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(value1 + 0x18));
    LeaveCriticalSection(lpCriticalSection);
  }
  ExceptionList = local_c;
  return arg1;
code_r0x005443c4:
  if (value4 == 2) {
    value3 = *(int *)(value3 + 8);
    lpCriticalSection_00 = *(LPCRITICAL_SECTION *)(value3 + 0x38);
    EnterCriticalSection(lpCriticalSection_00);
    local_4 = (local_4 & ~(0x0u << 8)) | (((2) & 0x0u) << 8);
    *(uint32_t *)(value3 + 0x78) = uvalue5;
    if (*(int *)(value3 + 0x8c) == 0) {
      *(uint32_t *)(value3 + 0x9c) = uvalue5;
    }
    if (*(char *)(value3 + 0x53) == '\0') {
      local_4 = (local_4 & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
      LeaveCriticalSection(lpCriticalSection_00);
    }
    else {
      uvalue6 = Sound_SetBufferVolume(*(void **)(value3 + 0x28),uvalue5);
      local_4 = (local_4 & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
      LeaveCriticalSection(lpCriticalSection_00);
LAB_00544429:
      if (((intptr_t)uvalue6 < 0) && (-1 < (intptr_t)arg1)) {
        arg1 = uvalue6;
      }
    }
  }
  goto LAB_005443a6;
}
