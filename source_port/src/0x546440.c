// Sound_UnlinkAndFreeBuffer: ported from Pizza Connection 2 at 0x546440.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x546440
#include "pc2_port.h"

int Sound_UnlinkAndFreeBuffer(int arg1,int *arg2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *ptr1;
  LPCRITICAL_SECTION lpCriticalSection_00;
  void *self;
  int *ptr2;
  int value3;
  void *local_c;
  uint8_t *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b760;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(arg1 + 0xa0);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  value3 = *(int *)(arg1 + 0x98);
  local_4 = 0;
  if (value3 < 0) {
    LeaveCriticalSection(lpCriticalSection);
  }
  else if (arg2 == (int *)0x0) {
    LeaveCriticalSection(lpCriticalSection);
    value3 = -0x7ff8fffa;
  }
  else {
    ptr1 = (int *)*arg2;
    lpCriticalSection_00 = (LPCRITICAL_SECTION)ptr1[0xe];
    EnterCriticalSection(lpCriticalSection_00);
    *(uint8_t *)(ptr1 + 0x15) = 0;
    local_4 = (local_4 & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
    if (*(char *)((intptr_t)ptr1 + 0x53) != '\0') {
      *(uint8_t *)((intptr_t)ptr1 + 0x53) = 0;
      ptr1[0x21] = 0;
      *(uint8_t *)(ptr1 + 0x22) = 1;
      if ((char)ptr1[0x16] != '\0') {
        *(uint8_t *)((intptr_t)ptr1 + 0x57) = 1;
      }
      self = (void *)ptr1[10];
      ptr2 = *(int **)((intptr_t)self + 0x48);
      if (ptr2 != (int *)0x0) {
        value3 = (**(code **)(*ptr2 + 0x48))(ptr2);
        if (-1 < value3) {
          if (*(char *)((intptr_t)self + 0x34) != '\0') {
            List_DestroyObjects((intptr_t)self);
          }
          Sound_RewindBuffer(self,0);
        }
      }
    }
    local_4 = (uint32_t)((uint8_t)((local_4) >> 24)) << 8;
    LeaveCriticalSection(lpCriticalSection_00);
    (**(code **)(*ptr1 + 4))(ptr1);
    SetEvent(*(HANDLE *)(arg1 + 0x48));
    if (*(int **)(arg1 + 0x6c) == arg2) {
      *(int *)(arg1 + 0x6c) = (*(int **)(arg1 + 0x6c))[1];
    }
    if (arg2[2] == 0) {
      *(int *)(arg1 + 100) = arg2[1];
    }
    else {
      *(int *)(arg2[2] + 4) = arg2[1];
    }
    if (arg2 == *(int **)(arg1 + 0x68)) {
      *(int *)(arg1 + 0x68) = arg2[2];
    }
    if (arg2[1] != 0) {
      *(int *)(arg2[1] + 8) = arg2[2];
    }
    *(int *)(arg1 + 0x70) = *(int *)(arg1 + 0x70) + -1;
    Mem_Free(arg2);
    LeaveCriticalSection(lpCriticalSection);
    value3 = 0;
  }
  ExceptionList = local_c;
  return value3;
}
