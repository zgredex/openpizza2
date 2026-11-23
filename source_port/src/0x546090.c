// Sound_CreateAndEnqueueBuffer: ported from Pizza Connection 2 at 0x546090.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x546090
#include "pc2_port.h"

int Sound_CreateAndEnqueueBuffer(int arg1,int *arg2,uint32_t *arg3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *ptr1;
  int *ptr2;
  int *ptr3;
  int value4;
  uint32_t *uptr5;
  int value6;
  uint8_t uStack00000000;
  void *local_c;
  uint8_t *puStack_8;
  int local_4;
  
  value6 = arg1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b6fb;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(arg1 + 0xa0);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  ptr1 = arg2;
  local_4 = 0;
  if (*(int *)(value6 + 0x98) < 0) {
    value6 = *(int *)(value6 + 0x98);
  }
  else {
    if (arg2 == (int *)0x0) {
      LeaveCriticalSection(lpCriticalSection);
      ExceptionList = local_c;
      return -0x7ff8fffa;
    }
    arg1 = 0;
    *arg3 = 0;
    ptr2 = operator_new(0xb4);
    local_4 = (local_4 & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
    arg2 = ptr2;
    if (ptr2 == (int *)0x0) {
      ptr2 = (int *)0x0;
    }
    else {
      ptr3 = *(int **)(value6 + 0xc);
      if (ptr3 == (int *)0x0) {
        ptr3 = (int *)0x0;
      }
      else {
        (**(code **)(*ptr3 + 4))(ptr3);
        ptr3 = *(int **)(value6 + 0xc);
      }
      value4 = *ptr1;
      SoundBuffer_Construct(ptr2,ptr3,value4,&arg1);
      local_4 = (local_4 & ~(0x0u << 8)) | (((2) & 0x0u) << 8);
      ptr2[0x2b] = 0;
      ptr2[0x2c] = *(int *)(value4 + 0xb0);
      *ptr2 = (intptr_t)&PTR_LAB_0055c8b0;
      if (((-1 < arg1) &&
          (value4 = (*(code *)**(uint32_t **)ptr2[0x17])
                             ((uint32_t *)ptr2[0x17],&DAT_0055cb78,ptr2 + 0x2b), value4 < 0))
         && (&uStack00000000 != (uint8_t *)0xfffffffc)) {
        arg1 = value4;
      }
    }
    local_4 = (uint32_t)((uint8_t)((local_4) >> 24)) << 8;
    if (arg1 < 0) {
      (**(code **)(*ptr2 + 4))(ptr2);
    }
    else {
      uptr5 = operator_new(0xc);
      if (uptr5 == (uint32_t *)0x0) {
        (**(code **)(*ptr2 + 4))(ptr2);
        LeaveCriticalSection(lpCriticalSection);
        ExceptionList = local_c;
        return -0x7ff8fff2;
      }
      *uptr5 = ptr2;
      uptr5[2] = 0;
      uptr5[1] = *(uint32_t *)(value6 + 0x54);
      if (*(int *)(value6 + 0x54) != 0) {
        *(uint32_t **)(*(int *)(value6 + 0x54) + 8) = uptr5;
      }
      if (*(int *)(value6 + 0x5c) == *(int *)(value6 + 0x54)) {
        *(uint32_t **)(value6 + 0x5c) = uptr5;
      }
      *(uint32_t **)(value6 + 0x54) = uptr5;
      if (*(int *)(value6 + 0x58) == 0) {
        *(uint32_t **)(value6 + 0x58) = uptr5;
      }
      *(int *)(value6 + 0x60) = *(int *)(value6 + 0x60) + 1;
      *arg3 = uptr5;
    }
    value6 = arg1;
  }
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = local_c;
  return value6;
}
