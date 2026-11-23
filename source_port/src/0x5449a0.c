// Media_QueryFlagLocked: ported from Pizza Connection 2 at 0x5449a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5449a0
#include "pc2_port.h"

struct pc2_obj_0x5449a0_arg2 { intptr_t DebugInfo; };
struct pc2_obj_0x5449a0_ProcessLocksList { intptr_t Flink[1]; };
struct pc2_obj_0x5449a0_p_Var2 { intptr_t Flink[1]; };
int Media_QueryFlagLocked(int arg1,struct pc2_obj_0x5449a0_arg2 *arg2,uint8_t *arg3)

{
  struct pc2_obj_0x5449a0_p_Var2 *p_Var2;
  struct pc2_obj_0x5449a0_ProcessLocksList *ProcessLocksList;
  LPCRITICAL_SECTION lpCriticalSection;
  PRTL_CRITICAL_SECTION_DEBUG p_Var1;
  LPCRITICAL_SECTION lpCriticalSection_00;
  int value3;
  uint8_t flag4;
  code *cptr5;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  value3 = arg1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b3e0;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(arg1 + 0xa0);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  value3 = *(int *)(value3 + 0x98);
  local_4 = 0;
  if (value3 < 0) {
    LeaveCriticalSection(lpCriticalSection);
    ExceptionList = local_c;
    return value3;
  }
  if (arg2 == (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(lpCriticalSection);
    ExceptionList = local_c;
    return -0x7ff8fffa;
  }
  p_Var1 = arg2->DebugInfo;
  lpCriticalSection_00 = (LPCRITICAL_SECTION)p_Var1[1].Flags;
  arg2 = lpCriticalSection_00;
  EnterCriticalSection(lpCriticalSection_00);
  cptr5 = LeaveCriticalSection_exref;
  local_4 = CONCAT31(((uint8_t)((local_4) >> 24)),1);
  if (*(char *)((intptr_t)&p_Var1[2].EntryCount + 3) == '\0') {
    LeaveCriticalSection(lpCriticalSection_00);
    flag4 = 0;
  }
  else {
    p_Var2 = p_Var1[1].ProcessLocksList.Flink[9].Flink;
    if (p_Var2 == (_LIST_ENTRY *)0x0) {
      flag4 = 0;
    }
    else {
      arg1 = 0;
      value3 = ((code)p_Var2->Flink[4])(p_Var2,&arg1);
      if (value3 < 0) {
        flag4 = 0;
      }
      else {
        flag4 = (uint8_t)arg1 & 1;
      }
    }
    cptr5 = LeaveCriticalSection_exref;
    LeaveCriticalSection(lpCriticalSection_00);
  }
  *arg3 = flag4;
  (*cptr5)(lpCriticalSection);
  ExceptionList = lpCriticalSection;
  return 0;
}
