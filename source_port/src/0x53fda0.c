// SoundPakManager_AddArchive: ported from Pizza Connection 2 at 0x53fda0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53fda0
#include "pc2_port.h"


uint32_t __thiscall SoundPakManager_AddArchive(void *self,LPCSTR arg1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  uint32_t *uptr1;
  char cVar2;
  uint32_t extraout_EAX;
  int *ptr3;
  uint32_t extraout_EAX_00;
  int value4;
  uint32_t extraout_EAX_01;
  uint32_t extraout_EAX_02;
  char *cptr5;
  uint32_t extraout_EAX_03;
  uint32_t uvalue6;
  int value7;
  char local_78 [96];
  uint32_t local_18;
  int local_14;
  int local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055ae88;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)((intptr_t)self + 0x23c);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  local_4 = 0;
  if (*(int *)((intptr_t)self + 0x238) < 0x14) {
    uptr1 = (uint32_t *)((intptr_t)self + *(int *)((intptr_t)self + 0x238) * 0x1c + 8);
    ptr3 = (int *)CRT_Fopen(arg1,&DAT_00563184);
    *uptr1 = ptr3;
    if (ptr3 == (int *)0x0) {
      LeaveCriticalSection(lpCriticalSection);
      uvalue6 = extraout_EAX_00 & 0xffffff00;
    }
    else {
      uptr1[6] = 1;
      CRT_FreadLocked(local_78,1,0x6c,ptr3);
      uvalue6 = 0xffffffff;
      cptr5 = s_ResourceFile_ID_7654_0056316c;
      do {
        if (uvalue6 == 0) break;
        uvalue6 = uvalue6 - 1;
        cVar2 = *cptr5;
        cptr5 = cptr5 + 1;
      } while (cVar2 != '\0');
      value4 = _strncmp(local_78,s_ResourceFile_ID_7654_0056316c,~uvalue6 - 1);
      if (value4 == 0) {
        if (local_14 < 0x65) {
          cptr5 = operator_new(local_18);
          uptr1[1] = cptr5;
          CRT_FreadLocked(cptr5,1,local_18,(int *)*uptr1);
          if (local_10 != 0) {
            Pak_DecodeIndex(uptr1[1],local_18);
            ptr3 = (int *)uptr1[1];
            uptr1[2] = ptr3;
            uptr1[3] = ptr3 + 1;
            uptr1[4] = ptr3 + *ptr3 * 5 + 1;
          }
          value4 = 0;
          if (0 < *(int *)uptr1[2]) {
            value7 = 0;
            do {
              value4 = value4 + 1;
              *(int *)(uptr1[3] + 0x10 + value7) = *(int *)(uptr1[3] + 0x10 + value7) + uptr1[4];
              value7 = value7 + 0x14;
            } while (value4 < *(int *)uptr1[2]);
          }
          Pak_SortEmbeddedEntries((int *)uptr1[3],*(uint32_t **)uptr1[2]);
          *(int *)((intptr_t)self + 0x238) = *(int *)((intptr_t)self + 0x238) + 1;
          LeaveCriticalSection(lpCriticalSection);
          uvalue6 = CONCAT31((int3)((uint32_t)extraout_EAX_03 >> 8),1);
        }
        else {
          CRT_Fclose((FILE *)*uptr1);
          NoOp_Stub();
          LeaveCriticalSection(lpCriticalSection);
          uvalue6 = extraout_EAX_02 & 0xffffff00;
        }
      }
      else {
        CRT_Fclose((FILE *)*uptr1);
        LeaveCriticalSection(lpCriticalSection);
        uvalue6 = extraout_EAX_01 & 0xffffff00;
      }
    }
  }
  else {
    LeaveCriticalSection(lpCriticalSection);
    uvalue6 = extraout_EAX & 0xffffff00;
  }
  ExceptionList = local_c;
  return uvalue6;
}
