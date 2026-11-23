// SoundStream_CreateEntry: ported from Pizza Connection 2 at 0x545d70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x545d70
#include "pc2_port.h"

/* WARNING: Removing unreachable block (ram,0x00545e30) */

int SoundStream_CreateEntry(int arg1,int *arg2,uint32_t *arg3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int value1;
  void *self;
  int *ptr2;
  uint32_t *uptr3;
  void *local_c;
  uint8_t *puStack_8;
  int local_4;
  
  value1 = arg1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b6a3;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(arg1 + 0xa0);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  arg1 = *(int *)(arg1 + 0x98);
  local_4 = 0;
  if (arg1 < 0) {
    LeaveCriticalSection(lpCriticalSection);
  }
  else if (arg2 == (int *)0x0) {
    LeaveCriticalSection(lpCriticalSection);
    arg1 = -0x7ff8fffa;
  }
  else {
    arg1 = 0;
    *arg3 = 0;
    self = operator_new(0x4c);
    local_4 = (local_4 & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
    if (self == (void *)0x0) {
      ptr2 = (int *)0x0;
    }
    else {
      ptr2 = *(int **)(value1 + 0xc);
      if (ptr2 == (int *)0x0) {
        ptr2 = (int *)0x0;
      }
      else {
        (**(code **)(*ptr2 + 4))(ptr2);
        ptr2 = *(int **)(value1 + 0xc);
      }
      ptr2 = SoundBuffer_Init(self,ptr2,*arg2);
    }
    local_4 = (uint32_t)((uint8_t)((local_4) >> 24)) << 8;
    uptr3 = operator_new(0xc);
    if (uptr3 == (uint32_t *)0x0) {
      (**(code **)(*ptr2 + 4))(ptr2);
      LeaveCriticalSection(lpCriticalSection);
      arg1 = -0x7ff8fff2;
    }
    else {
      *uptr3 = ptr2;
      uptr3[2] = 0;
      uptr3[1] = *(uint32_t *)(value1 + 0x54);
      if (*(int *)(value1 + 0x54) != 0) {
        *(uint32_t **)(*(int *)(value1 + 0x54) + 8) = uptr3;
      }
      if (*(int *)(value1 + 0x5c) == *(int *)(value1 + 0x54)) {
        *(uint32_t **)(value1 + 0x5c) = uptr3;
      }
      *(uint32_t **)(value1 + 0x54) = uptr3;
      if (*(int *)(value1 + 0x58) == 0) {
        *(uint32_t **)(value1 + 0x58) = uptr3;
      }
      *(int *)(value1 + 0x60) = *(int *)(value1 + 0x60) + 1;
      *arg3 = uptr3;
      LeaveCriticalSection(lpCriticalSection);
    }
  }
  ExceptionList = local_c;
  return arg1;
}
