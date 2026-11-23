// Sound_CreateVoice: ported from Pizza Connection 2 at 0x545100.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x545100
#include "pc2_port.h"

int Sound_CreateVoice(int arg1,char *arg2,uint32_t arg3,uint32_t *arg4)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int value1;
  void *self;
  uint32_t uvalue2;
  int *ptr3;
  int value4;
  uint32_t *uptr5;
  uint32_t uvalue6;
  void *local_c;
  uint8_t *puStack_8;
  int local_4;
  
  value1 = arg1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b593;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(arg1 + 0xa0);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  value4 = *(int *)(value1 + 0x98);
  local_4 = 0;
  arg1 = 0;
  if (value4 < 0) {
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    *arg4 = 0;
    (**(code **)**(uint32_t **)(value1 + 0x9c))(*(uint32_t **)(value1 + 0x9c));
    self = operator_new(0xa0);
    local_4 = (local_4 & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
    if (self == (void *)0x0) {
      ptr3 = (int *)0x0;
    }
    else {
      value4 = *(int *)(value1 + 0x94);
      if ((value4 == 0) || ((value4 != 1 && (value4 != 2)))) {
        uvalue6 = 8;
      }
      else {
        uvalue6 = 4;
      }
      ptr3 = *(int **)(value1 + 0xc);
      if (ptr3 == (int *)0x0) {
        uvalue2 = 0;
      }
      else {
        (**(code **)(*ptr3 + 4))(ptr3);
        uvalue2 = *(uint32_t *)(value1 + 0xc);
      }
      ptr3 = SoundVoice_Construct
                         (self,uvalue2,uvalue6,*(uint32_t *)(value1 + 0x9c),arg2,(char)arg3,
                          value1 + 0x30,&arg1);
    }
    local_4 = (uint32_t)((uint8_t)((local_4) >> 24)) << 8;
    if (ptr3 == (int *)0x0) {
      LeaveCriticalSection(lpCriticalSection);
      value4 = -0x7ff8fff2;
    }
    else {
      if (arg1 < 0) {
        (**(code **)(*ptr3 + 4))(ptr3);
      }
      else {
        uptr5 = operator_new(0xc);
        if (uptr5 == (uint32_t *)0x0) {
          (**(code **)(*ptr3 + 4))(ptr3);
          LeaveCriticalSection(lpCriticalSection);
          ExceptionList = local_c;
          return -0x7ff8fff2;
        }
        *uptr5 = ptr3;
        uptr5[2] = 0;
        uptr5[1] = *(uint32_t *)(value1 + 100);
        if (*(int *)(value1 + 100) != 0) {
          *(uint32_t **)(*(int *)(value1 + 100) + 8) = uptr5;
        }
        if (*(int *)(value1 + 0x6c) == *(int *)(value1 + 100)) {
          *(uint32_t **)(value1 + 0x6c) = uptr5;
        }
        *(uint32_t **)(value1 + 100) = uptr5;
        if (*(int *)(value1 + 0x68) == 0) {
          *(uint32_t **)(value1 + 0x68) = uptr5;
        }
        *(int *)(value1 + 0x70) = *(int *)(value1 + 0x70) + 1;
        *arg4 = uptr5;
      }
      value4 = arg1;
      LeaveCriticalSection(lpCriticalSection);
    }
  }
  ExceptionList = local_c;
  return value4;
}
