// SoundPakManager_OpenStream: ported from Pizza Connection 2 at 0x540040.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x540040
#include "pc2_port.h"


int * __thiscall SoundPakManager_OpenStream(void *self,char *arg1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int value1;
  int *ptr2;
  uint32_t uvalue3;
  int local_11c;
  int local_118;
  LPCRITICAL_SECTION local_114;
  uint32_t local_110 [65];
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055aeab;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)((intptr_t)self + 0x23c);
  ExceptionList = &local_c;
  local_114 = lpCriticalSection;
  EnterCriticalSection(lpCriticalSection);
  local_4 = 0;
  SoundPakManager_BuildArchivePath(self,arg1,local_110);
  ptr2 = (int *)Sound_AllocVoice((intptr_t)self);
  if (ptr2 == (int *)0x0) {
    NoOp_Stub();
    LeaveCriticalSection(lpCriticalSection);
    ptr2 = (int *)0x0;
  }
  else {
    local_118 = 0;
    local_11c = 0;
    uvalue3 = ResourceTable_FindEntry(self,(uint8_t *)local_110,&local_118,&local_11c);
    if ((char)uvalue3 == '\0') {
      ptr2[5] = 0;
      LeaveCriticalSection(lpCriticalSection);
      ptr2 = (int *)0x0;
    }
    else {
      ptr2[2] = *(int *)(*(int *)((intptr_t)self + local_118 * 0x1c + 0x14) + 8 + local_11c * 0x14);
      ptr2[3] = *(int *)(*(int *)((intptr_t)self + local_118 * 0x1c + 0x14) + 0xc + local_11c * 0x14) +
                  0x6c;
      *ptr2 = local_118;
      ptr2[1] = local_11c;
      ptr2[4] = 0;
      if (*(int *)((intptr_t)self + local_118 * 0x1c + 0x20) == 0) {
        ptr2[6] = 0;
        ptr2[7] = 2;
        ptr2[8] = *(int *)((intptr_t)self + (local_118 + 1) * 0x1c);
      }
      else {
        value1 = *(int *)((intptr_t)self + local_118 * 0x1c + 8);
        ptr2[7] = 0;
        ptr2[6] = value1;
        ptr2[8] = 0;
      }
      LeaveCriticalSection(lpCriticalSection);
    }
  }
  ExceptionList = local_c;
  return ptr2;
}
