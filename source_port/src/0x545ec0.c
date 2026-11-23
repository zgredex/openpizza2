// Sound_CreateAndRegisterBuffer: ported from Pizza Connection 2 at 0x545ec0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x545ec0
#include "pc2_port.h"

int Sound_CreateAndRegisterBuffer(int arg1,int *arg2,int *arg3)

{
  int *ptr1;
  LPCRITICAL_SECTION lpCriticalSection;
  int *self;
  DWORD DVar2;
  int value3;
  uint32_t *uptr4;
  int *ptr5;
  int value6;
  int *ptr7;
  uint8_t uStack00000000;
  int local_18;
  void *local_c;
  uint8_t *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b6cb;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(arg1 + 0xa0);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  local_18 = *(int *)(arg1 + 0x98);
  local_4 = 0;
  if (-1 < local_18) {
    if (arg2 == (int *)0x0) {
      LeaveCriticalSection(lpCriticalSection);
      ExceptionList = local_c;
      return -0x7ff8fffa;
    }
    local_18 = 0;
    *arg3 = 0;
    self = operator_new(0xac);
    local_4 = (local_4 & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
    if (self == (int *)0x0) {
      self = (int *)0x0;
    }
    else {
      ptr5 = *(int **)(arg1 + 0xc);
      if (ptr5 == (int *)0x0) {
        ptr5 = (int *)0x0;
      }
      else {
        (**(code **)(*ptr5 + 4))(ptr5);
        ptr5 = *(int **)(arg1 + 0xc);
      }
      SoundBuffer_Init(self,ptr5,*arg2);
      ptr5 = self + 0x17;
      self[0x13] = 0;
      self[0x14] = 0;
      self[0x15] = 0;
      self[0x16] = 0;
      local_4 = (local_4 & ~(0x0u << 8)) | (((2) & 0x0u) << 8);
      *ptr5 = 0;
      *(uint8_t *)(self + 0x28) = 0;
      *(uint8_t *)((intptr_t)self + 0xa1) = 0;
      DVar2 = timeGetTime();
      self[0x29] = DVar2;
      self[0x2a] = DVar2;
      *self = (intptr_t)&PTR_LAB_0055c8c8;
      value3 = (*(code *)**(uint32_t **)self[0x12])((uint32_t *)self[0x12],&DAT_0055cb88,ptr5);
      if (value3 < 0) {
        *ptr5 = 0;
      }
      else {
        ptr1 = self + 0x18;
        ptr7 = ptr1;
        for (value6 = 0x10; value6 != 0; value6 = value6 + -1) {
          *ptr7 = 0;
          ptr7 = ptr7 + 1;
        }
        *ptr1 = 0x40;
        (**(code **)(*(int *)*ptr5 + 0xc))((int *)*ptr5,ptr1);
      }
      self[0x14] = self[0x14] | 3;
      if (&uStack00000000 != (uint8_t *)0x18) {
        local_18 = value3;
      }
    }
    local_4 = (uint32_t)((uint8_t)((local_4) >> 24)) << 8;
    if (-1 < local_18) {
      uptr4 = operator_new(0xc);
      if (uptr4 != (uint32_t *)0x0) {
        *uptr4 = self;
        value3 = List_Insert((void *)(arg1 + 0x54),(intptr_t)uptr4,'\0');
        if (value3 != 0) {
          *arg3 = value3;
          goto LAB_00546073;
        }
      }
      (**(code **)(*self + 4))(self);
      LeaveCriticalSection(lpCriticalSection);
      ExceptionList = local_c;
      return -0x7ff8fff2;
    }
    (**(code **)(*self + 4))(self);
  }
LAB_00546073:
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = local_c;
  return local_18;
}
