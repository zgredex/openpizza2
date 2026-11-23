// Sound_SetSampleFormat: ported from Pizza Connection 2 at 0x542f10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x542f10
#include "pc2_port.h"


int Sound_SetSampleFormat(int arg1,uint32_t arg2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *ptr1;
  int value2;
  uint32_t local_20;
  int local_1c;
  int local_18;
  uint16_t local_14;
  uint16_t uStack_12;
  uint16_t local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b0f8;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(arg1 + 0xa0);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  value2 = *(int *)(arg1 + 0x98);
  local_4 = 0;
  if (value2 < 0) {
    LeaveCriticalSection(lpCriticalSection);
    ExceptionList = local_c;
    return value2;
  }
  ptr1 = *(int **)(arg1 + 0x18);
  if (ptr1 == (int *)0x0) {
    value2 = -0x7ff8fffa;
    goto LAB_00543040;
  }
  local_20 = 0x20001;
  local_10 = 0;
  switch(arg2) {
  default:
    local_1c = 0xac44;
    goto LAB_00542ffe;
  case 1:
    local_1c = 0x5622;
    goto LAB_00542ffe;
  case 2:
    local_1c = 0x2b11;
LAB_00542ffe:
    uStack_12 = 0x10;
    break;
  case 3:
    uStack_12 = 8;
    local_1c = 0xac44;
    break;
  case 4:
    uStack_12 = 8;
    local_1c = 0x5622;
    break;
  case 5:
    uStack_12 = 8;
    local_1c = 0x2b11;
  }
  local_18 = (intptr_t)((uint32_t)uStack_12 * 2) >> 3;
  local_14 = (uint16_t)local_18;
  local_18 = local_18 * local_1c;
  (**(code **)(*ptr1 + 0x38))(ptr1,&local_20);
  value2 = 0;
LAB_00543040:
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = local_c;
  return value2;
}
