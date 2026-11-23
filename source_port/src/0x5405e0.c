// SoundPakManager_BuildArchivePath: ported from Pizza Connection 2 at 0x5405e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5405e0
#include "pc2_port.h"

void __thiscall SoundPakManager_BuildArchivePath(void *self,char *arg1,uint32_t *arg2)

{
  char cVar1;
  char *cptr2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  int value5;
  uint32_t *uptr6;
  uint32_t *uptr7;
  char *cptr8;
  
  if (arg1[1] != ':') {
    cptr2 = _strrchr(arg1,0x2e);
    if (cptr2 != (char *)0x0) {
      cptr2 = (char *)SoundPakManager_FindExtensionEntry(self,cptr2 + 1);
      if (cptr2 != (char *)0x0) {
        uvalue3 = 0xffffffff;
        do {
          cptr8 = cptr2;
          if (uvalue3 == 0) break;
          uvalue3 = uvalue3 - 1;
          cptr8 = cptr2 + 1;
          cVar1 = *cptr2;
          cptr2 = cptr8;
        } while (cVar1 != '\0');
        uvalue3 = ~uvalue3;
        uptr6 = (uint32_t *)(cptr8 + -uvalue3);
        uptr7 = arg2;
        for (uvalue4 = uvalue3 >> 2; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
          *uptr7 = *uptr6;
          uptr6 = uptr6 + 1;
          uptr7 = uptr7 + 1;
        }
        for (uvalue3 = uvalue3 & 3; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
          *(char *)uptr7 = (char)*uptr6;
          uptr6 = (uint32_t *)((intptr_t)uptr6 + 1);
          uptr7 = (uint32_t *)((intptr_t)uptr7 + 1);
        }
        uvalue3 = 0xffffffff;
        do {
          cptr2 = arg1;
          if (uvalue3 == 0) break;
          uvalue3 = uvalue3 - 1;
          cptr2 = arg1 + 1;
          cVar1 = *arg1;
          arg1 = cptr2;
        } while (cVar1 != '\0');
        uvalue3 = ~uvalue3;
        value5 = -1;
        uptr6 = arg2;
        do {
          uptr7 = uptr6;
          if (value5 == 0) break;
          value5 = value5 + -1;
          uptr7 = (uint32_t *)((intptr_t)uptr6 + 1);
          uvalue4 = *uptr6;
          uptr6 = uptr7;
        } while ((char)uvalue4 != '\0');
        cptr2 = cptr2 + -uvalue3;
        cptr8 = (char *)((intptr_t)uptr7 + -1);
        for (uvalue4 = uvalue3 >> 2; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
          *(uint32_t *)cptr8 = *(uint32_t *)cptr2;
          cptr2 = cptr2 + 4;
          cptr8 = cptr8 + 4;
        }
        for (uvalue3 = uvalue3 & 3; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
          *cptr8 = *cptr2;
          cptr2 = cptr2 + 1;
          cptr8 = cptr8 + 1;
        }
        CRT_Strlwr(arg2);
        return;
      }
    }
  }
  uvalue3 = 0xffffffff;
  do {
    cptr2 = arg1;
    if (uvalue3 == 0) break;
    uvalue3 = uvalue3 - 1;
    cptr2 = arg1 + 1;
    cVar1 = *arg1;
    arg1 = cptr2;
  } while (cVar1 != '\0');
  uvalue3 = ~uvalue3;
  uptr6 = (uint32_t *)(cptr2 + -uvalue3);
  uptr7 = arg2;
  for (uvalue4 = uvalue3 >> 2; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
    *uptr7 = *uptr6;
    uptr6 = uptr6 + 1;
    uptr7 = uptr7 + 1;
  }
  for (uvalue3 = uvalue3 & 3; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
    *(char *)uptr7 = (char)*uptr6;
    uptr6 = (uint32_t *)((intptr_t)uptr6 + 1);
    uptr7 = (uint32_t *)((intptr_t)uptr7 + 1);
  }
  CRT_Strlwr(arg2);
  return;
}
