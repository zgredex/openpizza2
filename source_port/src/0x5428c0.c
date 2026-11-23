// SoundVoiceThread_Run: ported from Pizza Connection 2 at 0x5428c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5428c0
#include "pc2_port.h"

void __cdecl SoundVoiceThread_Run(int arg1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  uint32_t *uptr1;
  int *ptr2;
  char cVar3;
  uint32_t uvalue4;
  LPVOID pvVar5;
  DWORD DVar6;
  int value7;
  uint32_t *self;
  int local_c;
  uint32_t local_8;
  uint32_t local_4;
  
  do {
    local_8 = 0xffffffff;
    local_c = 0;
    lpCriticalSection = (LPCRITICAL_SECTION)(arg1 + 0x14);
    EnterCriticalSection(lpCriticalSection);
    self = (uint32_t *)(arg1 + 4);
    *(uint32_t *)(arg1 + 0xc) = *(uint32_t *)(arg1 + 4);
    LeaveCriticalSection(lpCriticalSection);
    while( true ) {
      EnterCriticalSection(lpCriticalSection);
      uptr1 = *(uint32_t **)(arg1 + 0xc);
      if (uptr1 != (uint32_t *)0x0) {
        *(uint32_t *)(arg1 + 0xc) = uptr1[1];
      }
      LeaveCriticalSection(lpCriticalSection);
      if (uptr1 == (uint32_t *)0x0) break;
      ptr2 = (int *)*uptr1;
      if ((((*(char *)((intptr_t)ptr2 + 0x57) == '\0') || ((char)ptr2[0x16] == '\0')) ||
          (*(char *)((intptr_t)ptr2 + 0x53) == '\0')) ||
         (uvalue4 = Sound_QueryBufferFlag(ptr2[10]), (char)uvalue4 != '\0')) {
        local_4 = 0;
        cVar3 = Sound_GetStreamRefillSize(ptr2,&local_4);
        if (cVar3 == '\0') {
          local_c = local_c + 1;
          *(uint8_t *)((intptr_t)ptr2 + 0x56) = 1;
          Sound_UpdateBufferFade((intptr_t)ptr2);
        }
        else {
          if (local_4 < local_8) {
            local_8 = local_4;
          }
          Sound_UpdateBufferFade((intptr_t)ptr2);
        }
      }
      else {
        EnterCriticalSection(lpCriticalSection);
        pvVar5 = (LPVOID)List_Remove(self,(intptr_t)uptr1);
        Mem_Free(pvVar5);
        LeaveCriticalSection(lpCriticalSection);
        *(uint8_t *)(ptr2 + 0x14) = 0;
        if ((ptr2[8] != 0) && ((uint32_t *)ptr2[9] != (uint32_t *)0x0)) {
          List_UnlinkNode((void *)ptr2[8],(uint32_t *)ptr2[9]);
          ptr2[8] = 0;
          ptr2[9] = 0;
        }
        (**(code **)(*ptr2 + 4))(ptr2);
      }
    }
    if (local_c == 0) {
      DVar6 = WaitForSingleObject(*(HANDLE *)(arg1 + 0x2c),local_8);
      if (DVar6 == 0xffffffff) {
        return;
      }
    }
    else {
      EnterCriticalSection(lpCriticalSection);
      *(uint32_t *)(arg1 + 0xc) = *self;
      LeaveCriticalSection(lpCriticalSection);
      while( true ) {
        EnterCriticalSection(lpCriticalSection);
        uptr1 = *(uint32_t **)(arg1 + 0xc);
        if (uptr1 != (uint32_t *)0x0) {
          *(uint32_t *)(arg1 + 0xc) = uptr1[1];
        }
        LeaveCriticalSection(lpCriticalSection);
        if (uptr1 == (uint32_t *)0x0) break;
        ptr2 = (int *)*uptr1;
        value7 = SoundVoice_ServiceStream(ptr2);
        if ((value7 < 0) || ((value7 == 1 && ((char)ptr2[0x16] == '\0')))) {
          EnterCriticalSection(lpCriticalSection);
          if (*(uint32_t **)(arg1 + 0xc) == uptr1) {
            *(uint32_t *)(arg1 + 0xc) = (*(uint32_t **)(arg1 + 0xc))[1];
          }
          if (uptr1[2] == 0) {
            *self = uptr1[1];
          }
          else {
            *(uint32_t *)(uptr1[2] + 4) = uptr1[1];
          }
          if (uptr1 == *(uint32_t **)(arg1 + 8)) {
            *(uint32_t *)(arg1 + 8) = uptr1[2];
          }
          if (uptr1[1] != 0) {
            *(uint32_t *)(uptr1[1] + 8) = uptr1[2];
          }
          *(int *)(arg1 + 0x10) = *(int *)(arg1 + 0x10) + -1;
          Mem_Free(uptr1);
          LeaveCriticalSection(lpCriticalSection);
          *(uint8_t *)(ptr2 + 0x14) = 0;
          (**(code **)(*ptr2 + 4))(ptr2);
        }
      }
    }
  } while (*(char *)(arg1 + 0x34) == '\0');
  return;
}
