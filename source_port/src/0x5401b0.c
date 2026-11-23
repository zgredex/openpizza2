// SoundPakStream_Read: ported from Pizza Connection 2 at 0x5401b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5401b0
#include "pc2_port.h"

uint32_t __thiscall SoundPakStream_Read(void *self,char *arg1,uint32_t arg2,int arg3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int value1;
  uint32_t uvalue2;
  char *cptr3;
  
  lpCriticalSection = (LPCRITICAL_SECTION)((intptr_t)self + 0x23c);
  EnterCriticalSection(lpCriticalSection);
  value1 = *(int *)(arg3 + 0x10);
  if (*(uint32_t *)(arg3 + 8) <= value1 + arg2) {
    arg2 = *(uint32_t *)(arg3 + 8) - value1;
  }
  if ((intptr_t)arg2 < 0) {
    LeaveCriticalSection(lpCriticalSection);
    return 0;
  }
  if (*(int *)(arg3 + 0x1c) == 2) {
    cptr3 = (char *)(*(int *)(arg3 + 0x20) + *(int *)(arg3 + 0xc) + value1);
    for (uvalue2 = arg2 >> 2; uvalue2 != 0; uvalue2 = uvalue2 - 1) {
      *(uint32_t *)arg1 = *(uint32_t *)cptr3;
      cptr3 = cptr3 + 4;
      arg1 = arg1 + 4;
    }
    for (uvalue2 = arg2 & 3; uvalue2 != 0; uvalue2 = uvalue2 - 1) {
      *arg1 = *cptr3;
      cptr3 = cptr3 + 1;
      arg1 = arg1 + 1;
    }
  }
  else {
    CRT_Fseek(*(int **)(arg3 + 0x18),*(int *)(arg3 + 0xc) + value1,0);
    arg2 = CRT_FreadLocked(arg1,1,arg2,*(int **)(arg3 + 0x18));
  }
  *(uint32_t *)(arg3 + 0x10) = *(int *)(arg3 + 0x10) + arg2;
  LeaveCriticalSection(lpCriticalSection);
  return arg2;
}
