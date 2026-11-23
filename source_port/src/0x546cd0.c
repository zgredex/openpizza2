// SoundStream_CompleteRequest: ported from Pizza Connection 2 at 0x546cd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x546cd0
#include "pc2_port.h"

int SoundStream_CompleteRequest(int arg1,int *arg2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *ptr1;
  LPCRITICAL_SECTION p_Var2;
  int value3;
  int *ptr4;
  int *ptr5;
  int value6;
  void *local_c;
  uint8_t *puStack_8;
  int local_4;
  
  value3 = arg1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b858;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(arg1 + 0xa0);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  ptr4 = arg2;
  value6 = *(int *)(arg1 + 0x98);
  local_4 = 0;
  if (value6 < 0) {
LAB_00546edc:
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    if (arg2 == (int *)0x0) {
      LeaveCriticalSection(lpCriticalSection);
      ExceptionList = local_c;
      return -0x7ff8fffa;
    }
    ptr1 = (int *)*arg2;
    p_Var2 = (LPCRITICAL_SECTION)ptr1[0xe];
    EnterCriticalSection(p_Var2);
    local_4 = (local_4 & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
    if (*(char *)((intptr_t)ptr1 + 0x53) == '\0') {
      local_4 = (uint32_t)((uint8_t)((local_4) >> 24)) << 8;
      LeaveCriticalSection(p_Var2);
    }
    else {
      ptr5 = *(int **)(ptr1[10] + 0x48);
      if (ptr5 == (int *)0x0) {
        arg1 = (arg1 & ~(0x0u << 8)) | (((0) & 0x0u) << 8);
      }
      else {
        arg2 = (int *)0x0;
        value6 = (**(code **)(*ptr5 + 0x24))(ptr5,&arg2);
        if (value6 < 0) {
          arg1 = (arg1 & ~(0x0u << 8)) | (((0) & 0x0u) << 8);
        }
        else {
          arg1 = (arg1 & ~(0x0u << 8)) | ((((uint8_t)arg2 & 1) & 0x0u) << 8);
        }
      }
      local_4 = (uint32_t)((uint8_t)((local_4) >> 24)) << 8;
      LeaveCriticalSection(p_Var2);
      if ((uint8_t)arg1 != 0) {
        LeaveCriticalSection(lpCriticalSection);
        ExceptionList = local_c;
        return 1;
      }
    }
    *(uint8_t *)(ptr1 + 0x16) = 1;
    (**(code **)*ptr1)(ptr1);
    p_Var2 = (LPCRITICAL_SECTION)(value3 + 0x30);
    EnterCriticalSection(p_Var2);
    ptr5 = operator_new(0xc);
    if (ptr5 != (int *)0x0) {
      *ptr5 = (intptr_t)ptr1;
      value6 = List_Insert((void *)(value3 + 0x20),(intptr_t)ptr5,'\0');
      if (value6 != 0) {
        LeaveCriticalSection(p_Var2);
        *(uint8_t *)(ptr1 + 0x14) = 1;
        (**(code **)(*ptr1 + 4))(ptr1);
        if (*(int **)(value3 + 0x6c) == ptr4) {
          *(int *)(value3 + 0x6c) = (*(int **)(value3 + 0x6c))[1];
        }
        if (ptr4[2] == 0) {
          *(int *)(value3 + 100) = ptr4[1];
        }
        else {
          *(int *)(ptr4[2] + 4) = ptr4[1];
        }
        if (ptr4 == *(int **)(value3 + 0x68)) {
          *(int *)(value3 + 0x68) = ptr4[2];
        }
        if (ptr4[1] != 0) {
          *(int *)(ptr4[1] + 8) = ptr4[2];
        }
        *(int *)(value3 + 0x70) = *(int *)(value3 + 0x70) + -1;
        Mem_Free(ptr4);
        p_Var2 = (LPCRITICAL_SECTION)ptr1[0xe];
        EnterCriticalSection(p_Var2);
        *(uint8_t *)(ptr1 + 0x15) = 1;
        *(uint8_t *)((intptr_t)ptr1 + 0x52) = 0;
        local_4 = CONCAT31(((uint8_t)((local_4) >> 24)),2);
        if (*(char *)((intptr_t)ptr1 + 0x53) == '\0') {
          if (*(char *)((intptr_t)ptr1 + 0x51) == '\0') {
            LeaveCriticalSection(p_Var2);
            value6 = -0x7fffbffb;
          }
          else {
            LeaveCriticalSection(p_Var2);
            value6 = 0;
          }
        }
        else {
          *(uint8_t *)(ptr1[0xb] + 0x34) = 0;
          value6 = SoundBuffer_Configure(*(int **)(ptr1[10] + 0x48),'\x01');
          LeaveCriticalSection(p_Var2);
        }
        SetEvent(*(HANDLE *)(value3 + 0x48));
        goto LAB_00546edc;
      }
    }
    LeaveCriticalSection(p_Var2);
    (**(code **)(*ptr1 + 4))(ptr1);
    LeaveCriticalSection(lpCriticalSection);
    value6 = -0x7ff8fff2;
  }
  ExceptionList = local_c;
  return value6;
}
