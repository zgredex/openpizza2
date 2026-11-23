// SoundBuffer_StopPlaybackLocked: ported from Pizza Connection 2 at 0x544620.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x544620
#include "pc2_port.h"


uint32_t __fastcall SoundBuffer_StopPlaybackLocked(int arg1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *ptr1;
  int value2;
  int value3;
  uint32_t uvalue4;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b378;
  local_c = ExceptionList;
  lpCriticalSection = *(LPCRITICAL_SECTION *)(arg1 + 0x38);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  *(uint8_t *)(arg1 + 0x54) = 0;
  local_4 = 0;
  if (*(char *)(arg1 + 0x53) == '\0') {
    LeaveCriticalSection(lpCriticalSection);
    ExceptionList = local_c;
    return 1;
  }
  *(uint8_t *)(arg1 + 0x53) = 0;
  *(uint32_t *)(arg1 + 0x84) = 0;
  *(uint8_t *)(arg1 + 0x88) = 1;
  if (*(char *)(arg1 + 0x58) != '\0') {
    *(uint8_t *)(arg1 + 0x57) = 1;
  }
  value3 = *(int *)(arg1 + 0x28);
  ptr1 = *(int **)(value3 + 0x48);
  if (ptr1 == (int *)0x0) {
    uvalue4 = 0x80070006;
  }
  else {
    value2 = (**(code **)(*ptr1 + 0x48))(ptr1);
    if (value2 < 0) {
      uvalue4 = 0x80004005;
    }
    else {
      if (*(char *)(value3 + 0x34) != '\0') {
        List_DestroyObjects(value3);
      }
      value3 = (**(code **)(**(int **)(value3 + 0x48) + 0x34))(*(int **)(value3 + 0x48),0);
      uvalue4 = (-1 < value3) - 1 & 0x80004005;
    }
  }
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = local_c;
  return uvalue4;
}
