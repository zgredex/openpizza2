// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x546b10.c:112:41: error: member reference base type 'void' is not a structure or union
// Sound_StartStreamVoice: ported from Pizza Connection 2 at 0x546b10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x546b10
#include "pc2_port.h"

int Sound_StartStreamVoice(int arg1,int *arg2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *ptr1;
  LPCRITICAL_SECTION lpCriticalSection_00;
  int value2;
  int *ptr3;
  int value4;
  uint8_t flag5;
  code *cptr6;
  code *cptr7;
  uint32_t unaff_EDI;
  int unaff_retaddr;
  int *ptr8;
  void *local_c;
  uint8_t *puStack_8;
  int local_4;
  
  cptr6 = EnterCriticalSection_exref;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b828;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(arg1 + 0xa0);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  value2 = *(int *)(arg1 + 0x98);
  local_4 = 0;
  if (value2 < 0) {
    LeaveCriticalSection(lpCriticalSection);
  }
  else if (arg2 == (int *)0x0) {
    LeaveCriticalSection(lpCriticalSection);
    value2 = -0x7ff8fffa;
  }
  else {
    ptr1 = (int *)*arg2;
    lpCriticalSection_00 = (LPCRITICAL_SECTION)ptr1[0xe];
    EnterCriticalSection(lpCriticalSection_00);
    cptr7 = LeaveCriticalSection_exref;
    local_4 = (local_4 & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
    if (*(char *)((intptr_t)ptr1 + 0x53) == '\0') {
      local_4 = (uint32_t)((uint8_t)((local_4) >> 24)) << 8;
      LeaveCriticalSection(lpCriticalSection_00);
    }
    else {
      ptr8 = *(int **)(ptr1[10] + 0x48);
      if (ptr8 == (int *)0x0) {
        flag5 = 0;
      }
      else {
        arg2 = (int *)0x0;
        value2 = (**(code **)(*ptr8 + 0x24))(ptr8,&arg2);
        if (value2 < 0) {
          flag5 = 0;
        }
        else {
          flag5 = (uint8_t)arg2 & 1;
        }
      }
      cptr7 = LeaveCriticalSection_exref;
      local_4 = (uint32_t)((uint8_t)((local_4) >> 24)) << 8;
      LeaveCriticalSection(lpCriticalSection_00);
      if (flag5 != 0) {
        LeaveCriticalSection(lpCriticalSection);
        ExceptionList = local_c;
        return 1;
      }
      cptr6 = EnterCriticalSection_exref;
    }
    ptr8 = ptr1;
    (**(code **)*ptr1)(ptr1);
    value2 = unaff_retaddr + 0x30;
    (*cptr6)(value2);
    ptr3 = operator_new(0xc);
    if (ptr3 != (int *)0x0) {
      *ptr3 = (intptr_t)ptr1;
      value4 = List_Insert((void *)(local_4 + 0x20),(intptr_t)ptr3,'\0');
      if (value4 != 0) {
        (*cptr7)(value2);
        *(uint8_t *)(ptr1 + 0x14) = 1;
        value2 = ptr1[0xe];
        local_4 = value2;
        (*cptr6)(value2);
        *(uint8_t *)(ptr1 + 0x15) = 1;
        if ((char)local_4 == '\0') {
          *(uint8_t *)((intptr_t)ptr1 + 0x52) = 0;
        }
        else {
          *(uint8_t *)((intptr_t)ptr1 + 0x52) = 1;
        }
        if (*(char *)((intptr_t)ptr1 + 0x53) == '\0') {
          if (*(char *)((intptr_t)ptr1 + 0x51) == '\0') {
            (*cptr7)(value2);
            value4 = -0x7fffbffb;
          }
          else {
            (*cptr7)(value2);
            value4 = 0;
          }
        }
        else {
          *(char *)(ptr1[0xb] + 0x34) = (char)local_4;
          value4 = SoundBuffer_Configure(*(int **)(ptr1[10] + 0x48),'\x01');
          (*cptr7)(value2);
        }
        SetEvent(lpCriticalSection_00[3].DebugInfo);
        (*cptr7)(ptr8);
        ExceptionList = local_c;
        return value4;
      }
    }
    (*cptr7)(value2);
    (**(code **)(*ptr1 + 4))(ptr1);
    (*cptr7)(unaff_EDI);
    value2 = -0x7ff8fff2;
  }
  ExceptionList = local_c;
  return value2;
}
